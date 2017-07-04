#include <iostream>
#include <chrono>

#include <malt/message.hpp>
#include <malt_asset/assets.hpp>
#include <malt_basic/scene.hpp>
#include <malt_render/render_global.hpp>

static std::chrono::milliseconds dt;

namespace malt
{
namespace impl
{
    float get_delta_time()
    {
        return dt.count() / 1000.f;
    }

    void print_diagnostics();
}
}

int main()
{
    std::cout << "Initializing...\n";
    using namespace std::chrono_literals;

    render_mod mod;
    mod.init();

    malt::impl::print_diagnostics();

    auto scn = malt::asset::load<YAML::Node>("scene.maltscene");
    malt::load_scene(*scn);

    using clock = std::chrono::high_resolution_clock;

    auto b = clock::now();
    auto prev_frame = clock::now() - 16ms;

    std::cout << "Starting loop...\n";
    int f = 0;
    while (!malt::is_terminated())
    {
        dt = std::chrono::duration_cast<std::chrono::milliseconds>(clock::now() - prev_frame);
        prev_frame = clock::now();
        malt::broadcast(malt::update{});
        mod.update();
        malt::impl::post_frame();
        f++;
    }

    mod.destruct();

    std::cout << float(f) / (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - b).count() / 1000.f)  << '\n';

    return 0;
}
