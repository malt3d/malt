#include <malt_asset/text_asset.hpp>
#include <iostream>

#include <malt/entity.hpp>
#include <malt/detail/component_mgr.hpp>
#include <malt/component.hpp>

#include <malt_basic/components/transform.hpp>

#include <rtk/gl/mesh.hpp>
#include <chrono>

#include <malt_basic/input.hpp>
#include <malt_basic/components/fps_control.hpp>

#include <malt_render/render_global.hpp>
#include <malt_render/components/render_test.hpp>
#include <malt_render/components/lights/directional_light.hpp>
#include <malt_render/components/camera.hpp>

#include <malt_asset/assets.hpp>
#include <malt_basic/components/rotate_comp.hpp>

#include <yaml-cpp/yaml.h>
#include <malt/serialization.hpp>
#include <malt_basic/scene.hpp>

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
    using namespace std::chrono_literals;

    render_mod mod;
    mod.init();

    malt::impl::print_diagnostics();

    auto scn = malt::asset::load<YAML::Node>("scene.maltscene");
    malt::load_scene(scn);

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
