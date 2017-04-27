#include <iostream>
#include "malt/component_mgr.hpp"
#include "malt/component.hpp"

#include <malt/component_mgr.cpp>
#include <sample/components/simple.hpp>
#include <sample/components/test.hpp>
#include <sample/sample_module.hpp>
#include <malt/game.cpp>

malt::component_mgr<test_component> test_mgr;
malt::component_mgr<simple> simple_mgr;

template <class...> struct list;

class game_config
{
    using modules = list<sample_module>;
};

MALT_IMPLEMENT_GAME(game_config);

class my_component : public malt::component
{
public:
    void Handle(int, int a) {}
};

malt::game<game_config> g;
namespace malt
{
    namespace impl
    {
        template <class MsgT, class... Args>
        void msg_delivery<MsgT(Args...)>::deliver(malt::entity_id id, MsgT, Args&&... args)
        {
            g.deliver(id, MsgT{}, std::forward<Args>(args)...);
        };

        template struct msg_delivery<int(int)>;
        template struct msg_delivery<render(float)>;
        template struct msg_delivery<render(float, double)>;
    }
}

int main()
{
    malt::entity e = g.create_entity();
    std::cout << e.get_component<simple>() << '\n';
    e.get_component<test_component>()->Handle(3);
    e.deliver_message(int{}, 3);
    e.deliver_message(render{}, 1.66f, 12.3);

    test_mgr.get_component(3);
    simple_mgr.get_component(0);
    return 0;
}