//
// Created by fatih on 4/27/17.
//

#pragma once

#include <malt/malt_fwd.hpp>

namespace malt
{
    template <class CompT>
    class comp_mgr_priv;

    template <class CompT>
    class component_mgr
    {
    public:
        component_mgr();
        CompT* get_component(int id);
    };
}

