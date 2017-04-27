//
// Created by fatih on 4/28/17.
//

#pragma once

#include <malt/component.hpp>

class transform : public malt::component
{
public:

    float x, y, z;
    void translate(float dx, float dy, float dz);
};

