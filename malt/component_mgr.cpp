//
// Created by fatih on 4/27/17.
//

#include <malt/component_mgr.hpp>
#include <vector>

namespace malt
{
    template <class CompT>
    class comp_mgr_priv
    {
    public:
        std::vector<CompT> components;
    };

    template <class CompT>
    component_mgr<CompT>::component_mgr() {}

    template <class CompT>
    CompT* component_mgr<CompT>::add_component(entity_id id)
    {
        priv->components.emplace_back();
        priv->components.back().e = entity(id);
        return &priv->components.back();
    }

    template <class CompT>
    CompT* component_mgr<CompT>::get_component(entity_id id)
    {
        return nullptr;
    }

    template <class CompT>
    component_mgr<CompT>::~component_mgr() = default;

    namespace impl
    {
        template <class CompT>
        CompT* get_component(malt::entity_id id){
            return nullptr;
        }
    }
}

#define MALT_IMPLEMENT_COMP(COMPT) \
    template class malt::component_mgr<COMPT>; \
    template COMPT* malt::impl::get_component<COMPT>(malt::entity_id id);
