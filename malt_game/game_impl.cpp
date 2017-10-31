/*
 * DO NOT EDIT MANUALLY
 */

#include <game_impl.hpp>
#include <core_module.hpp>
#include <malt/detail/game_impl.hpp>

#include <malt_basic/basic_module.hpp>
#include <malt_basic/components/transform.hpp>
#include <malt_basic/components/fps_control.hpp>
#include <malt_basic/components/rotate_comp.hpp>

#include <malt_asset/asset_mgr.hpp>
#include <malt_asset/assets.hpp>
#include <malt_asset/text_asset.hpp>

#include <malt_render/module.hpp>

#include <malt_render/components/mesh_renderer.hpp>
#include <malt_render/components/material.hpp>
#include <malt_render/components/lights/directional_light.hpp>
#include <malt_render/components/lights/point_light.hpp>
#include <malt_render/components/render_test.hpp>
#include <malt_render/components/camera.hpp>
#include <malt_render/shader_loader.hpp>
#include <malt_render/mesh_loader.hpp>
#include <malt_render/texture_loader.hpp>
#include <rtk/texture/tex2d.hpp>
#include <malt/detail/component_mgr_impl.hpp>

MALT_IMPLEMENT_GAME(game_config)

malt::game<game_config> g;
malt::asset::detail::asset_mgr<malt::txt_loader, malt::shader_loader, malt::mesh_loader, malt::texture_loader> asset_mgr;

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
        void component_adapter<CompT>::destroy(CompT* c)
        {
            g.destroy_comp(c);
        }

        template <class CompT>
        erased_range<CompT, component> component_adapter<CompT>::get_components()
        {
            return g.get_components(meta::type<CompT>{});
        }

        template <class AssetT>
        asset::asset_ptr<AssetT> asset_adapter<AssetT>::load(const char* path)
        {
            return asset_mgr.load<AssetT>(path);
        }

        entity create_entity()
        {
            return g.create_entity();
        }

        erased_range<entity_id, entity_id>
        get_entities()
        {
            return g.get_entities();
        };

        template <class FunT>
        void for_each_component(entity id, const FunT& fun)
        {
            auto res = g.get_component_map(id);
            constexpr auto len = g.get_component_type_count();
            for (int i = 0; i < len; ++i)
            {
                if (res.test(i)) {
                    fun(g.erased_get_component(i, detail::get_id(id)));
                }
            }
        }

        void destroy(entity e)
        {
            for_each_component(e, [e_id = detail::get_id(e)](component* comp){
                auto id = dynamic_reflect(comp)->get_index();
                g.erased_destory_component(id, e_id);
            });

            g.destroy_entity(e);
        }

        entity find_entity(const std::string& name)
        {
            return entity{g.find_entity(name)};
        }

        const std::string&
        get_name(entity_id id)
        {
            return g.get_name(id);
        }

        void set_name(entity_id id, std::string name)
        {
            g.set_name(id, std::move(name));
        }

        template <class CompT>
        CompT* component_adapter<CompT>::add_component(entity_id id)
        {
            g.notify_add_comp<CompT>(id);
            return g.get_mgr(meta::type<CompT>{}).add_component(id);
        }

        template <class CompT>
        CompT* component_adapter<CompT>::get_component(entity_id id)
        {
            return g.get_mgr(meta::type<CompT>{}).get_component(id);
        }

        std::vector<malt::component*> components_of(entity id)
        {
            auto res = g.get_component_map(id);

            constexpr auto len = g.get_component_type_count();

            std::vector<malt::component*> result;
            result.reserve(res.count());

            for (int i = 0; i < len; ++i)
            {
                if (res.test(i)) {
                    result.push_back(g.erased_get_component(i, detail::get_id(id)));
                }
            }

            return result;
        }

        void print_diagnostics()
        {
            g.diagnostics();
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

        malt::component* add_component(size_t comp_hash, entity e)
        {
            return g.hash_add_component(comp_hash, detail::get_id(e));
        }

        malt::component* get_component(size_t comp_hash, entity e)
        {
            return g.hash_get_component(comp_hash, detail::get_id(e));
        }

        // malt_core
        template struct component_adapter<malt::component>;
        template struct msg_delivery<malt::init()>;
        template struct msg_delivery<malt::update()>;

        // malt_basic
        template struct component_adapter<malt::transform>;
        template struct component_adapter<fps_control>;
        template struct component_adapter<rotate_comp>;

        // malt_asset
        template struct asset_adapter<malt::text_asset>;
        template struct asset_adapter<YAML::Node>;

        // malt_render
        template struct msg_delivery<render(render_ctx)>;

        template struct asset_adapter<rtk::gl::program>;
        template struct asset_adapter<rtk::geometry::mesh>;
        template struct asset_adapter<rtk::gl::mesh>;
        template struct asset_adapter<rtk::graphics::texture2d>;
        template struct asset_adapter<rtk::gl::texture2d>;

        template struct component_adapter<mesh_renderer>;
        template struct component_adapter<material>;
        template struct component_adapter<render_test>;
        template struct component_adapter<directional_light>;
        template struct component_adapter<point_light>;
        template struct component_adapter<camera>;
    }
}

