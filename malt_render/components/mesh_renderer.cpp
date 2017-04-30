//
// Created by fatih on 4/30/17.
//

#include "mesh_renderer.hpp"
#include "material.hpp"
#include <rtk/gl/mesh.hpp>
#include <malt/component_mgr.cpp>
#include <malt_basic/components/transform.hpp>

void mesh_renderer::Handle(render)
{
    auto mat = get_entity().get_component<material>();
    auto& prog = mat->get_program();
    prog.set_variable("model", get_component<malt::transform>()->get_mat4());
    m_mesh->draw(prog);
}

void mesh_renderer::set_mesh(rtk::gl::mesh& m)
{
    m_mesh = &m;
}

MALT_IMPLEMENT_COMP(mesh_renderer)