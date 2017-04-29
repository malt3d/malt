//
// Created by fatih on 4/30/17.
//

#ifndef MALT_MATERIAL_HPP
#define MALT_MATERIAL_HPP

#include <malt/component.hpp>
#include <rtk/gl/program.hpp>

class material : public malt::component
{
public:
    rtk::gl::program p;
};

#endif //MALT_MATERIAL_HPP
