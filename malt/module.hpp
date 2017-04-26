//
// Created by fatih on 4/27/17.
//

namespace malt
{
    /*
     * struct module_def
     * {
     *     using public_comps = ...;
     *     using internal_comps = ...;
     * }
     */

    template <class T>
    class module
    {
    public:
        template <class CompT>
        CompT* get_component(int id);
    };
}

