#include <iostream>
#include <malt/component_mgr.hpp>
#include <malt/component.hpp>
#include <malt_game/game_impl.hpp>

#include <sample/components/test.hpp>
#include <sample/components/simple.hpp>
#include <malt_basic/components/transform.hpp>

int main()
{
    malt::entity e = g.create_entity();
    //std::cout << e.get_component<simple>() << '\n';
    e.add_component<simple>();

    e.add_component<test_component>()->data = 5;

    e.add_component<transform>();

    e.get_component<transform>()->x = 3;
    e.get_component<transform>()->translate(1, 2, 3);

    std::cout << e.get_component<transform>()->x << '\n';

    e.deliver_message(int{});

    return 0;
}