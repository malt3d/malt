#include <malt_asset/text_asset.hpp>
#include <iostream>

#include <malt/entity.hpp>
#include <malt/component_mgr.hpp>
#include <malt/component.hpp>

#include <malt_basic/components/transform.hpp>

#include <rtk/gl/mesh.hpp>
#include <chrono>

#include <malt_basic/input.hpp>
#include <malt_basic/components/fps_control.hpp>

#include <malt_render/messages.hpp>
#include <malt_render/components/mesh_renderer.hpp>
#include <malt_render/components/material.hpp>
#include <malt_render/render_global.hpp>
#include <malt_render/components/render_test.hpp>
#include <malt_render/components/lights/directional_light.hpp>
#include <malt_render/components/camera.hpp>
#include <rtk/texture/tex2d.hpp>
#include <rtk/framebuffer.hpp>
#include <malt_asset/assets.hpp>
#include <malt_basic/components/rotate_comp.hpp>

static std::chrono::milliseconds dt;

namespace malt
{
namespace impl
{
    float get_delta_time()
    {
        return dt.count() / 1000.f;
    }

    void print_diagnostics();
}
}

int main()
{
    std::cout << "Initializing...\n";
    using namespace rtk;
    using namespace malt;
    using namespace std::chrono_literals;
    using namespace rtk::literals;
    render_mod mod;
    mod.init();

    std::cout << "Asset loading...\n";
    auto res = malt::asset::load<malt::text_asset>("hello.txt");
    std::cout << res.c_str() << '\n';

    malt::impl::print_diagnostics();

    std::cout << "Loading texture...\n";
    auto img = malt::asset::load<rtk::graphics::texture2d>("test.jpg");
    std::cout << "Loading GL texture...\n";
    auto gl_img = malt::asset::load<rtk::gl::texture2d>("test.jpg");

    std::cout << "Creating entity...\n";
    auto main_cam = malt::create_entity();
    main_cam.add_component<malt::transform>();
    main_cam.add_component<camera>();
    main_cam.add_component<fps_control>();

    std::cout << "##########\n";
    for (auto& comp : malt::get_components<malt::component>())
    {
        std::cout << "yay\n";
    }
    std::cout << "##########\n";

    auto render_t = gl::create_texture({800_px, 600_px}, graphics::pixel_format::rgba_byte);
    auto fb = gl::framebuffer(render_t);

    auto light = malt::create_entity();
    light.add_component<malt::transform>();
    light.add_component<directional_light>();

    auto e = malt::create_entity();
    e.add_component<malt::transform>();
    e.add_component<render_test>();
    e.add_component<rotate_comp>();

    auto child = malt::create_entity();
    auto c_trans = child.add_component<malt::transform>();
    c_trans->set_scale(glm::vec3{0.25, 0.25, 0.25});
    c_trans->translate(glm::vec3{0, 5, 0});
    c_trans->set_parent(e.get_component<malt::transform>());
    child.add_component<render_test>();

    using clock = std::chrono::high_resolution_clock;

    auto b = clock::now();
    auto prev_frame = clock::now() - 16ms;

    std::cout << "Starting loop...\n";
    int f = 0;
    while (!malt::is_terminated())
    {
        dt = std::chrono::duration_cast<std::chrono::milliseconds>(clock::now() - prev_frame);
        prev_frame = clock::now();
        malt::broadcast(malt::update{});
        mod.update();
        malt::impl::post_frame();
        f++;
    }

    mod.destruct();

    std::cout << float(f) / (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - b).count() / 1000.f)  << '\n';

    return 0;
}
