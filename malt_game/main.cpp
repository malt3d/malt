#include <iostream>
#include <malt/entity.hpp>
#include <malt/component_mgr.hpp>
#include <malt/component.hpp>

#include <sample/components/test.hpp>
#include <sample/components/simple.hpp>
#include <malt_basic/components/transform.hpp>

#include <malt_geometry/mesh.hpp>
#include <rtk/rtk_fwd.hpp>
#include <rtk/gl/mesh.hpp>
#include <rtk/window.hpp>
#include <rtk/rtk_init.hpp>
#include <chrono>
#include <malt_render/messages.hpp>
#include <malt_render/components/mesh_renderer.hpp>
#include <malt_render/components/material.hpp>

int main()
{
    using namespace rtk::literals;

    rtk::rtk_init init;
    rtk::window w({800_px, 600_px}, "malt");

    malt::entity e = malt::create_entity();
    malt::entity another = malt::create_entity();
    malt::entity last = malt::create_entity();

    auto mat = e.add_component<material>();

    rtk::geometry::mesh m;
    m.set_vertices(std::vector<glm::vec3>{ {-0.5, -0.5, -0.5}, {-0.5, 0.5, -0.5}, {0.5, 0.5, -0.5} });
    m.set_faces(std::vector<uint32_t>{0, 1, 2});
    rtk::gl::mesh gl_m(m);

    e.add_component<mesh_renderer>()->set_mesh(gl_m);

    auto b = std::chrono::high_resolution_clock::now();
    int f = 0;
    while (!w.should_close())
    {
        w.begin_draw();
        malt::broadcast(render{});
        w.end_draw();
        malt::impl::post_frame();
        f++;
    }
    std::cout << float(f) / (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - b).count() / 1000.f)  << '\n';

    return 0;
}
