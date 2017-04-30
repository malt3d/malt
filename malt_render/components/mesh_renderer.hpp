//
// Created by fatih on 4/30/17.
//

#ifndef MALT_MESH_RENDERER_HPP
#define MALT_MESH_RENDERER_HPP

#include <malt_render/messages.hpp>
#include <malt/component.hpp>
#include <rtk/gl/mesh.hpp>

class mesh_renderer : public malt::component
{
private:
    rtk::gl::mesh* m_mesh;

public:
    void set_mesh(rtk::gl::mesh& m);
    void Handle(render);
};

#endif //MALT_MESH_RENDERER_HPP
