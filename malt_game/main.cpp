#include <iostream>
#include "malt/component_mgr.hpp"
#include "malt/component.hpp"

#include <malt/component_mgr.cpp>
#include <sample/components/simple.hpp>
#include <sample/components/test.hpp>

malt::component_mgr<test_component> test_mgr;
malt::component_mgr<simple> simple_mgr;

int main()
{
    malt::entity e;
    std::cout << e.get_component<simple>() << '\n';
    e.get_component<test_component>()->Handle(3);

    test_mgr.get_component(3);
    simple_mgr.get_component(0);
    return 0;
}