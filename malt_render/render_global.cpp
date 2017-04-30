//
// Created by fatih on 4/30/17.
//

#include "render_global.hpp"
#include "render_ctx.hpp"
#include <GLFW/glfw3.h>

static render_mod* inst;

namespace malt
{
namespace input
{
    bool get_key(int keycode)
    {
        return inst->w->get_key(keycode);
    }

    bool get_key_up(int keycode)
    {
        return inst->w->get_key_up(keycode);
    }

    bool get_key_down(int keycode)
    {
        return inst->w->get_key_down(keycode);
    }

    glm::vec2 get_cursor()
    {
        return inst->w->get_mouse();
    }
}
}

void render_mod::init()
{
    using namespace rtk::literals;
    w = new rtk::window({800_px, 600_px}, "malt");
    inst = this;
}

void render_mod::destruct()
{
    delete w;
}

void render_mod::update()
{
    if (w->should_close())
    {
        malt::terminate();
        return;
    }
    w->begin_draw();
    render_ctx ctx;
    malt::broadcast(render{}, ctx);
    w->end_draw();
}
