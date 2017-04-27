#include <iostream>
#include <malt/component_mgr.hpp>
#include <malt/component.hpp>
#include <malt_game/game_impl.hpp>

#include <malt/component_mgr.cpp>
#include <sample/components/simple.hpp>
#include <sample/components/test.hpp>

int main()
{
    malt::entity e = g.create_entity();
    std::cout << e.get_component<simple>() << '\n';
    e.add_component<test_component>()->data = 5;
    e.get_component<test_component>()->Handle(0);

    e.deliver_message(int{}, 3);
    e.deliver_message(render{}, 1.66f, 12.3);

    return 0;
}