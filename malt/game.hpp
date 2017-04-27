//
// Created by Mehmet Fatih BAKIR on 27/04/2017.
//

#pragma once

#include "malt_fwd.hpp"
#include <malt/entity.hpp>

namespace malt
{
    template <class GameConfig>
    class game
    {
        entity_id next = 1;
    public:
        template <class MsgT, class... Args>
        void deliver(malt::entity_id id, MsgT, Args&&...);

        entity create_entity();
    };
}
