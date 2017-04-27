//
// Created by fatih on 4/27/17.
//

#pragma once

#include <malt/game.hpp>
#include <malt/list.hpp>

class game_config
{
    using module_defs = malt::mp::list<struct sample_module_def>;
    using modules = malt::mp::map_t<malt::mp::mapper<malt::module>, module_defs>;
};

extern malt::game<game_config> g;

