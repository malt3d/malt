//
// Created by Mehmet Fatih BAKIR on 27/04/2017.
//

#include <malt/game.hpp>

namespace malt
{
    template <class T>
    template<class MsgT, class... Args>
    void game<T>::deliver(entity_id id, MsgT, Args&& ...)
    {

    }

    template <class T>
    entity game<T>::create_entity()
    {
        return entity(next++);
    }
}

#define MALT_IMPLEMENT_GAME(GAME_T) \
    template class malt::game<GAME_T>;
