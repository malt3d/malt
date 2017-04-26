//
// Created by fatih on 4/27/17.
//

#pragma once

template <class...>
struct list;

class sample_module
{
    using public_comps = list<class simple, class test_component>;
};
