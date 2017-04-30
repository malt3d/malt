//
// Created by musti on 30.04.2017.
//

#include <malt/component_mgr.cpp>
#include <glm/gtc/matrix_transform.hpp>
#include <malt_basic/components/transform.hpp>
#include "camera.hpp"

void camera::Handle(malt::update)
{
    auto camera_transform = get_component<malt::transform>();
    auto right = camera_transform->get_right();
    auto up = camera_transform->get_up();
    auto forward = camera_transform->get_forward();
    auto& position = camera_transform->get_pos();

    m_view_matrix = glm::lookAt(position, position + forward, up);

    if (m_update_projection_matrix)
    {
        m_projection_matrix = glm::perspective(m_fov, m_aspect_ratio, m_near_plane, m_far_plane);
        m_update_projection_matrix = false;
    }

    m_vp_matrix = m_projection_matrix * m_view_matrix;
}

void camera::set_fov(float fov)
{
    m_fov = fov;
    m_update_projection_matrix = true;
}

void camera::set_aspect_ratio(float aspect_ratio)
{
    m_aspect_ratio = aspect_ratio;
    m_update_projection_matrix = true;
}

void camera::set_near_plane(float near_plane)
{
    m_near_plane = near_plane;
    m_update_projection_matrix = true;
}

void camera::set_far_plane(float far_plane)
{
    m_far_plane = far_plane;
    m_update_projection_matrix = true;
}

glm::mat4 &camera::get_vp_matrix()
{
    return m_vp_matrix;
}

const glm::mat4 &camera::get_vp_matrix() const
{
    return m_vp_matrix;
}

MALT_IMPLEMENT_COMP(camera)