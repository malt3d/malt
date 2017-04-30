/*
 * DO NOT EDIT MANUALLY
 */

#include <malt/game.cpp>
#include <malt_game/game_impl.hpp>

#include <sample/sample_module.hpp>
#include <sample/components/test.hpp>
#include <sample/components/simple.hpp>

#include <malt_basic/basic_module.hpp>
#include <malt_basic/components/transform.hpp>
#include <malt_basic/components/fps_control.hpp>

#include <malt_render/render_module.hpp>
#include <malt_render/components/mesh_renderer.hpp>
#include <malt_render/components/material.hpp>
#include <malt_render/components/lights/directional_light.hpp>
#include <malt_render/components/lights/point_light.hpp>
#include <malt_render/components/render_test.h>
#include <malt_render/components/camera.hpp>

MALT_IMPLEMENT_GAME(game_config)

malt::game<game_config> g;
namespace malt
{
    namespace impl
    {
        template <class MsgT, class... Args>
        void msg_delivery<MsgT(Args...)>::deliver(malt::entity_id id, MsgT, const Args&... args)
        {
            g.deliver(id, MsgT{}, args...);
        };

        template <class MsgT, class... Args>
        void msg_delivery<MsgT(Args...)>::broadcast(MsgT, const Args& ... args)
        {
            g.broadcast(MsgT{}, args...);
        }

        template <class CompT>
        component_mgr<CompT>& component_adapter<CompT>::get_mgr()
        {
            return g.get_mgr<CompT>();
        }

        template <class CompT>
        void component_adapter<CompT>::destroy(CompT* c)
        {
            g.destroy_comp(c);
        }

        template <class CompT>
        void component_adapter<CompT>::for_components(std::function<void(CompT*)> fun)
        {
            auto& mgr = g.get_mgr<CompT>();
            mgr.for_each(fun);
        }

        entity create_entity()
        {
            return g.create_entity();
        }

        void post_frame()
        {
            g.synchronize();
        }

        bool running = true;

        void terminate()
        {
            running = false;
        }

        bool is_terminated()
        {
            return !running;
        }

        template struct msg_delivery<int()>;
        template struct msg_delivery<int(int)>;
        template struct msg_delivery<render(render_ctx)>;
        template struct msg_delivery<malt::init()>;
        template struct msg_delivery<malt::update()>;

        template struct component_adapter<simple>;
        template struct component_adapter<test_component>;

        template struct component_adapter<malt::transform>;
        template struct component_adapter<fps_control>;

        template struct component_adapter<mesh_renderer>;
        template struct component_adapter<material>;
        template struct component_adapter<render_test>;
        template struct component_adapter<directional_light>;
        template struct component_adapter<point_light>;
        template struct component_adapter<camera>;
    }
}

