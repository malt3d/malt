//
// Created by fatih on 4/27/17.
//

#include "simple.hpp"
#include <malt/component_mgr.cpp>
#include <iostream>

void simple::Handle(render, float dt)
{
    std::cout << "dt is : " << dt << '\n';
}

MALT_IMPLEMENT_COMP(simple)
