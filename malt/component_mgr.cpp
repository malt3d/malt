//
// Created by fatih on 4/27/17.
//

#include <malt/component_mgr.hpp>

namespace malt
{
    template <class CompT>
    component_mgr<CompT>::component_mgr() {}

    template <class CompT>
    CompT* component_mgr<CompT>::get_component(int id)
    {
        return nullptr;
    }

    namespace impl
    {
        template <class CompT>
        CompT* get_component(malt::entity_id id){
            return (CompT*)3;
        }
    }
}

#define MALT_IMPLEMENT_COMP(COMPT) \
    template class malt::component_mgr<COMPT>; \
    template COMPT* malt::impl::get_component<COMPT>(malt::entity_id id);
