//
// Created by fatih on 4/29/17.
//

#pragma once

#include <malt/malt_fwd.hpp>
#include <utility>

namespace malt
{
    namespace impl
    {
        template <class CompT>
        struct component_adapter
        {
            static component_mgr<CompT>& get_mgr();
            static void destroy(CompT*);
        };

        template <class MsgT, class... Args> struct msg_delivery;

        template <class MsgT, class... Args>
        struct msg_delivery<MsgT(Args...)>
        {
            static void deliver(malt::entity_id id, MsgT, const Args&... args);
            static void broadcast(MsgT, const Args&... args);
        };

        entity create_entity();

        void post_frame();
    }

    template <class MsgT, class... Args>
    void broadcast(MsgT, Args&&... args) {
        impl::msg_delivery<MsgT(Args...)>::broadcast(MsgT{}, std::forward<Args>(args)...);
    };

    inline entity create_entity() {
        return impl::create_entity();
    }

    template <class CompT>
    void destroy(CompT comp)
    {
        using elem_t = typename std::iterator_traits<CompT>::value_type;
        impl::component_adapter<elem_t>::destroy(&(*comp));
    }
}

