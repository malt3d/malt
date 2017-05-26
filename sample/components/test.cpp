//
// Created by fatih on 4/27/17.
//

#include "test.hpp"
#include <iostream>
#include <malt/component_mgr_impl.hpp>

void test_component::Handle(int)
{
    get_entity().deliver_message(int{}, 8);
    std::cout << "hello world" << data << "\n";
}

MALT_IMPLEMENT_COMP(test_component)
