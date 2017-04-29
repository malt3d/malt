//
// Created by fatih on 4/27/17.
//

#pragma once

#include <malt/malt_fwd.hpp>
#include <malt/entity.hpp>
#include "message.hpp"

namespace malt
{
    class component
    {
        entity m_e;
        bool m_enabled;

        template <class T>
        friend class game;

        template <class T>
        friend class component_mgr;


    public:
        component() = default;
        entity get_entity() const;

        void Handle(init){}
        void Handle(start){}

        bool is_enabled() const { return m_enabled; }
        bool set_enabled(bool active) { m_enabled = active; }
    };

    template <class T>
    struct component_traits;

    template <class CompT, class MsgT, class... ArgT>
    bool dispatch(CompT* comp, MsgT, ArgT&&... args)
    {
        
    };
}

