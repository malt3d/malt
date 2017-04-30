//
// Created by fatih on 4/30/17.
//

#include "render_global.hpp"

void render_mod::init()
{
    using namespace rtk::literals;
    w = new rtk::window({800_px, 600_px}, "malt");
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
    malt::broadcast(render{});
    w->end_draw();
}
