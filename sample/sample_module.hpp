//
// Created by fatih on 4/27/17.
//

#pragma once

#include <malt/meta.hpp>

struct sample_module_def
{
    using components = malt::meta::list<class simple, class test_component>;
};
