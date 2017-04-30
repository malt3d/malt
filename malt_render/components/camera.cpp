//
// Created by musti on 30.04.2017.
//

#include <glm/gtc/matrix_transform.hpp>
#include "camera.hpp"

void camera::Update(malt::update)
{
    
    if (m_update_projection_matrix)
    {
        m_projection_matrix = glm::perspective(m_fov, m_aspect_ratio, m_near_plane, m_far_plane);
        m_update_projection_matrix = false;
    }
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