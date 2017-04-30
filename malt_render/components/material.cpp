//
// Created by fatih on 4/30/17.
//

#include "material.hpp"
#include <malt/component_mgr.cpp>
#include <fstream>
#include <malt_render/messages.hpp>
#include <rtk/gl/shader.hpp>

MALT_IMPLEMENT_COMP(material)

void material::Handle(malt::start)
{
    auto read_text_file = [](const std::string& path) -> std::string
    {
        std::ifstream f(path);
        return {std::istreambuf_iterator<char>(f), std::istreambuf_iterator<char>()};
    };

    rtk::gl::vertex_shader phong_vertex { read_text_file("../../malt_shaders/phong.vert").c_str() };
    rtk::gl::fragment_shader phong_fragment { read_text_file("../../malt_shaders/phong.frag").c_str() };

    m_program.attach(phong_vertex);
    m_program.attach(phong_fragment);
    m_program.link();

    m_program.set_variable("material.ambient", m_ambient);
    m_program.set_variable("material.diffuse", m_diffuse);
    m_program.set_variable("material.specular", m_specular);
    m_program.set_variable("material.phong_exponent", m_phong_exponent);
}

rtk::gl::program& material::get_program()
{
    return m_program;
}

const rtk::gl::program& material::get_program() const
{
    return m_program;
}

void material::set_ambient(const glm::vec3 &ambient)
{
    m_ambient = ambient;
}

void material::set_diffuse(const glm::vec3 &diffuse)
{
    m_diffuse = diffuse;
}

void material::set_specular(const glm::vec3 &specular)
{
    m_specular = specular;
}

void material::set_phong_exponent(float phong_exponent)
{
    m_phong_exponent = phong_exponent;
}