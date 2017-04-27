//
// Created by fatih on 4/27/17.
//

#pragma once

#include <malt/malt_fwd.hpp>
#include <malt/entity.hpp>

namespace malt
{
    class component
    {
        entity e;

        template <class T>
        friend class game;

        template <class T>
        friend class component_mgr;


    public:
        component() = default;
        entity get_entity() const;
    };

    template <class T>
    struct component_traits;
}

