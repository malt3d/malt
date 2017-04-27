//
// Created by Mehmet Fatih BAKIR on 27/04/2017.
//

#include <malt/game.hpp>
#include <iostream>

namespace malt
{
    void print() {}
    template <class T, class... Ts>
    void print(const T& a, const Ts&...)
    {
        std::cout << a << '\n';
    };

    template <class T>
    template <class MsgT, class... Args>
    void game<T>::deliver(entity_id id, MsgT, const Args& ... args)
    {
        print(args...);
        mp::for_each(module_ts{}, [id, &args...](auto* module)
        {
            using module_t = std::remove_pointer_t<decltype(module)>;
            mp::for_each(typename module_t::component_ts{}, [id, &args...](auto* comp)
            {
                using comp_t = std::remove_pointer_t<decltype(comp)>;
                module_t:: template get_mgr<comp_t>().deliver(id, MsgT{}, args...);
            });
        });
    }

    template <class T>
    entity game<T>::create_entity()
    {
        return entity(next++);
    }
}

#define MALT_IMPLEMENT_GAME(GAME_T) \
    template class malt::game<GAME_T>;
