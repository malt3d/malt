//
// Created by Mehmet Fatih BAKIR on 30/04/2017.
//

#include "directional_light.hpp"
#include <malt/component_mgr.cpp>
#include <malt_basic/components/transform.hpp>

glm::vec3 directional_light::get_light_direction()
{
    return get_component<malt::transform>()->get_forward();
}

glm::vec3 directional_light::get_intensity()
{
    return m_intensity;
}

MALT_IMPLEMENT_COMP(directional_light)
