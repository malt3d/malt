//
// Created by fatih on 4/30/17.
//

#include "mesh_renderer.hpp"
#include "material.hpp"
#include <rtk/gl/mesh.hpp>
#include <malt/component_mgr.cpp>

void mesh_renderer::Handle(render)
{
    mesh->draw(get_entity().get_component<material>()->p);
}

void mesh_renderer::set_mesh(rtk::gl::mesh& m)
{
    mesh = &m;
}

MALT_IMPLEMENT_COMP(mesh_renderer)