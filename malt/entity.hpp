//
// Created by fatih on 4/27/17.
//

#pragma once

#include <malt/malt_fwd.hpp>

namespace malt
{
    namespace impl
    {
        template <class T> extern T* get_component(entity_id id) __attribute__((weak));
        template <class T> extern void  __attribute__((weak)) deliver_msg(T, entity_id id);
    }

    class entity
    {
        entity_id id;
    public:
        template <class T>
        T* get_component()
        {
            return malt::impl::get_component<T>(id);
        }

        template <class MsgT>
        void deliver_message(MsgT){
            malt::impl::deliver_msg(MsgT{}, id);
        }
    };
}
