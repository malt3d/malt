//
// Created by fatih on 4/27/17.
//

#pragma once

#include <malt/malt_fwd.hpp>

namespace malt
{
    template <class T> T* get_component(entity_id id);

    class entity
    {
        entity_id id;
    public:
        template <class T>
        T* get_component()
        {
            return malt::get_component<T>(id);
        }
    };
}
