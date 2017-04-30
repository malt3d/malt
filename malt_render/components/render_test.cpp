//
// Created by musti on 30.04.2017.
//

#include "render_test.h"
#include "material.hpp"
#include <rtk/gl/mesh.hpp>
#include <malt/component_mgr.cpp>
#include "mesh_renderer.hpp"
#include <rtk/asset/mesh_import.hpp>
#include <rtk/mesh_ops.hpp>

void render_test::Handle(malt::start)
{
    auto phong_material = get_entity().add_component<material>();
    phong_material->set_ambient(glm::vec3(0.1f, 0.1f, 0.1f));
    phong_material->set_diffuse(glm::vec3(0.2f, 0.4f, 0.6f));
    phong_material->set_specular(glm::vec3(0.5f, 0.5f, 0.5f));
    phong_material->set_phong_exponent(32.0f);

    auto mesh_rend = get_entity().add_component<mesh_renderer>();
    auto meshes = rtk::assets::load_meshes("/home/musti/rtk/assets/teapot.obj");
    auto m = new rtk::gl::mesh(meshes[0]);
    m->add_vertex_data<glm::vec3>(1, rtk::geometry::generate_normals(meshes[0]));

    mesh_rend->set_mesh(*m);

    malt::destroy(this);
}

MALT_IMPLEMENT_COMP(render_test)