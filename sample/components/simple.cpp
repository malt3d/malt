//
// Created by fatih on 4/27/17.
//

#include "simple.hpp"
#include <malt/detail/component_mgr_impl.hpp>
#include <iostream>

void simple::Handle(malt::init)
{
    std::cout << "hello world\n";
}

void simple::Handle(malt::start)
{
    std::cout << "hello next frame\n";
}

void simple::Handle(malt::update)
{
    std::cout << "hello update\n";
}

void simple::Handle(malt::destruct)
{
    std::cout << "bye cruel world\n";
}

MALT_IMPLEMENT_COMP(simple)
