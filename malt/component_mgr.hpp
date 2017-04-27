//
// Created by fatih on 4/27/17.
//

#pragma once

#include <malt/malt_fwd.hpp>
#include <memory>
#include <malt/component_traits.hpp>

namespace malt
{
    template <class CompT>
    class comp_mgr_priv;


    template <class CompT>
    class component_mgr
    {
        std::unique_ptr<comp_mgr_priv<CompT>> priv;

        template <class>
        friend class game;

        template <class MsgT, class... Args>
        void deliver(std::true_type, entity_id id, MsgT, Args&&... args)
        {
            auto cmp = get_component(id);
            cmp->Handle(MsgT{}, std::forward<Args>(args)...);
        };

        template <class MsgT, class... Args>
        void deliver(std::false_type, entity_id, MsgT, Args&&... args){};

    public:
        component_mgr();
        ~component_mgr();
        CompT* get_component(entity_id id);
        CompT* add_component(entity_id id);

        template <class MsgT, class... Args>
        void deliver(entity_id id, MsgT, Args&&... args)
        {
            deliver(can_handle<MsgT(Args...)>::template value<CompT>(), id, MsgT{}, std::forward<Args>(args)...);
        };
    };
}

