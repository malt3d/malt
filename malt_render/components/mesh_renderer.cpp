//
// Created by fatih on 4/30/17.
//

#include "mesh_renderer.hpp"
#include "material.hpp"
#include <rtk/gl/mesh.hpp>
#include <malt/component_mgr.cpp>

void mesh_renderer::Handle(render)
{
    m_mesh->draw(get_entity().get_component<material>()->get_program());
}

void mesh_renderer::set_mesh(rtk::gl::mesh& m)
{
    m_mesh = &m;
}

MALT_IMPLEMENT_COMP(mesh_renderer)