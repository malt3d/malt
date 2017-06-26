//
// Created by fatih on 6/2/17.
//

#pragma once

#include <malt/meta.hpp>
#include <malt/module.hpp>
#include <malt/detail/game.hpp>

struct game_config
{
    using module_defs = malt::meta::list<struct basic_module_def, struct render_module_def, struct core_module_def>;
    using modules = malt::meta::map_t<malt::meta::mapper<malt::module>, module_defs>;
};

extern malt::game<game_config> g;
