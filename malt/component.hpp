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
    public:
        entity get_entity() const;
    };
}

