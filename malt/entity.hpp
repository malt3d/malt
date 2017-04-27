//
// Created by fatih on 4/27/17.
//

#pragma once

#include <malt/malt_fwd.hpp>
#include <utility>
#include <malt/component_mgr.hpp>

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
    namespace detail {
        entity_id get_id(const entity& e);
    }

    class entity
    {
        entity_id id;

        template <class T>
        friend class game;

        friend entity_id detail::get_id(const entity& e);

    public:
        entity() : id(0){}
        explicit entity(entity_id id) : id(id) {}

        template <class T>
        T* get_component()
        {
            using module_t = typename T::module_t;
            return module_t:: template get_mgr<T>().get_component(id);
        }

        template <class T>
        T* add_component()
        {
            using module_t = typename T::module_t;
            return module_t:: template get_mgr<T>().add_component(id);
        }

        template <class MsgT, class... ArgTs>
        void deliver_message(MsgT, ArgTs&&... args){
            malt::impl::msg_delivery<MsgT(ArgTs...)>::deliver(id, MsgT{}, std::forward<ArgTs>(args)...);
        }
    };

    namespace detail
    {
        inline entity_id get_id(const entity& e)
        {
            return e.id;
        }
    }
}
