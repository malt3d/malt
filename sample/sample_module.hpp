//
// Created by fatih on 4/27/17.
//

#pragma once

#include <malt/list.hpp>
#include <malt/module.hpp>

struct render{};

struct sample_module_def
{
    using components = malt::mp::list<class simple, class test_component>;
};
