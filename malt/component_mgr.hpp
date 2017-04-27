//
// Created by fatih on 4/27/17.
//

#pragma once

#include <malt/malt_fwd.hpp>
#include <memory>

namespace malt
{
    template <class CompT>
    class comp_mgr_priv;

    template <class CompT>
    class component_mgr
    {
        std::unique_ptr<comp_mgr_priv<CompT>> priv;
    public:
        component_mgr();
        ~component_mgr();
        CompT* get_component(entity_id id);
        CompT* add_component(entity_id id);
    };
}

