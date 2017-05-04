cmake_minimum_required(VERSION 3.5)
project(malt_tooling)

function(get_sources name)
    get_target_property(test malt_render SOURCES)
    return(test)
endfunction()
