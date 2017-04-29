//
// Created by fatih on 4/27/17.
//

#include "test.hpp"
#include <iostream>
#include <malt/component_mgr.cpp>

void test_component::Handle(int)
{
    get_entity().deliver_message(render{}, 16.6f);
    get_entity().deliver_message(render{}, 16.6f, 3.2);
    get_entity().deliver_message(int{}, 8);
    std::cout << "hello world" << data << "\n";
}

MALT_IMPLEMENT_COMP(test_component)
