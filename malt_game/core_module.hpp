//
// Created by fatih on 6/2/17.
//

#pragma once

#include <malt/list.hpp>

namespace malt
{
    class component;
}

struct core_module_def
{
    using components = malt::meta::list<class malt::component>;
};


