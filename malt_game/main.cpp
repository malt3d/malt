#include <iostream>
#include <malt/component_mgr.hpp>
#include <malt/component.hpp>
#include <malt_game/game_impl.hpp>

#include <sample/components/test.hpp>
#include <sample/components/simple.hpp>

int main()
{
    malt::entity e = g.create_entity();
    std::cout << e.get_component<simple>() << '\n';
    e.add_component<simple>();
    e.add_component<test_component>()->data = 5;

    e.deliver_message(int{});

    return 0;
}