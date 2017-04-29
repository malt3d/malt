#include <iostream>
#include <malt/entity.hpp>
#include <malt/component_mgr.hpp>
#include <malt/component.hpp>

#include <sample/components/test.hpp>
#include <sample/components/simple.hpp>
#include <malt_basic/components/transform.hpp>

int main()
{
    malt::entity e = malt::create_entity();
    malt::entity another = malt::create_entity();
    malt::entity last = malt::create_entity();

    e.add_component<simple>();
    another.add_component<simple>();

    malt::destroy(e.get_component<simple>());

    malt::impl::post_frame();

    e.add_component<test_component>()->data = 5;

    e.add_component<transform>()->x = 3;
    e.get_component<transform>()->translate(1, 2, 3);

    another.add_component<test_component>()->data = 10;

    malt::broadcast(int{});

    return 0;
}
