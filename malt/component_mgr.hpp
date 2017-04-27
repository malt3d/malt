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

    template<class...>
    using void_t = void;

    template<class, template<class> class, class = void_t<>>
    struct detect : std::false_type { };

    template<class T, template<class> class Operation>
    struct detect<T, Operation, void_t<Operation<T>>> : std::true_type { };

    template <class U, class... Args>
    struct can_handle
    {
        template<class T>
        using hard_decay = std::remove_cv_t<std::remove_reference_t<std::remove_pointer_t<T>>>;

        template<class T>
        using Value = decltype(std::declval<T>().Handle(std::declval<U>(), std::declval<Args>()...));

        template <class T>
        static constexpr auto value()
        {
            return detect<T, Value>();
        }
    };

    template <class CompT>
    class component_mgr
    {
        std::unique_ptr<comp_mgr_priv<CompT>> priv;

        template <class>
        friend class game;

        template <class MsgT, class... Args>
        void deliver(std::true_type, entity_id id, MsgT, Args&&... args)
        {
            get_component(id)->Handle(MsgT{}, std::forward<Args>(args)...);
        };

        template <class MsgT, class... Args>
        void deliver(std::false_type, entity_id, MsgT, Args&&...){};

    public:
        component_mgr();
        ~component_mgr();
        CompT* get_component(entity_id id);
        CompT* add_component(entity_id id);

        template <class MsgT, class... Args>
        void deliver(entity_id id, MsgT, Args&&... args)
        {
            deliver(can_handle<MsgT, Args...>::value(), id, MsgT{}, std::forward<Args>(args)...);
        };
    };
}

