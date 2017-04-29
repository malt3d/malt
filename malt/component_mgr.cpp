//
// Created by fatih on 4/27/17.
//

#include <malt/component_mgr.hpp>
#include <vector>
#include <algorithm>
#include <malt/entity.hpp>
#include <iostream>

namespace malt
{
    template <class CompT>
    class comp_mgr_priv
    {
    public:
    };

    template <class CompT>
    component_mgr<CompT>::component_mgr() :
        priv(std::make_unique<comp_mgr_priv<CompT>>())
    {}

    template <class CompT>
    CompT* component_mgr<CompT>::add_component(entity_id id)
    {
        comps.emplace_back();
        comps.back().e = entity(id);
        auto res = &comps.back();
        return res;
    }

    template <class CompT>
    CompT* component_mgr<CompT>::get_component(entity_id id)
    {
        auto res = std::find_if(comps.begin(), comps.end(), [&id](const CompT& c)
        {
            return detail::get_id(c.e) == id;
        });

        return res != comps.end() ? &(*res) : nullptr;
    }

    template <class CompT>
    component_mgr<CompT>::~component_mgr() = default;
}

#define MALT_IMPLEMENT_COMP(COMPT) \
    template class malt::component_mgr<COMPT>;
