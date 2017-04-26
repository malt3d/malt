//
// Created by fatih on 4/27/17.
//

#include "module.hpp"

namespace malt
{
    template <class T>
    template<class CompT>
    CompT* module<T>::get_component(int id)
    {
        return nullptr;
    }
}

#define MALT_IMPLEMENT_MODULE(MODULET) \
    template class malt::module<MODULET>;
