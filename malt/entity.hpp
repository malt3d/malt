//
// Created by fatih on 4/27/17.
//

#pragma once

#include <malt/malt_fwd.hpp>
#include <utility>

namespace malt
{
    namespace impl
    {
        template <class T> extern T* get_component(entity_id id);
        template <class T> T* add_component(entity_id id);

        template <class MsgT, class... Args> struct msg_delivery;

        template <class MsgT, class... Args>
        struct msg_delivery<MsgT(Args...)>
        {
            static void deliver(malt::entity_id id, MsgT, Args&&... args);
        };
    }

    class entity
    {
        entity_id id;

        template <class T>
        friend class game;

    public:
        entity() : id(0){}
        explicit entity(entity_id id) : id(id) {}

        template <class T>
        T* get_component()
        {
            return malt::impl::get_component<T>(id);
        }

        template <class T>
        T* add_component()
        {
            return malt::impl::add_component<T>(id);
        }

        template <class MsgT, class... ArgTs>
        void deliver_message(MsgT, ArgTs&&... args){
            malt::impl::msg_delivery<MsgT(ArgTs...)>::deliver(id, MsgT{}, std::forward<ArgTs>(args)...);
        }
    };
}
