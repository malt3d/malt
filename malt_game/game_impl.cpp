/*
 * DO NOT EDIT MANUALLY
 */

#include <malt/game.cpp>
#include <malt_game/game_impl.hpp>
#include <sample/components/test.hpp>
#include <sample/sample_module.hpp>

MALT_IMPLEMENT_GAME(game_config);

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

