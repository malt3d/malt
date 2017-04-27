//
// Created by fatih on 4/27/17.
//

#pragma once

#include <malt/message.hpp>

template <class...>
struct list;

class sample_module
{
    using public_comps = list<class simple, class test_component>;
    using messages = list<malt::message<struct render()>>;
};
