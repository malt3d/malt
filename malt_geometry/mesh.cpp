//
// Created by fatih on 23.03.2017.
//

#include <malt_geometry/mesh.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>
#include <glm/gtx/euler_angles.hpp>

namespace rtk
{
namespace geometry
{
    mesh::mesh() /*: bbox({}, {})*/
    {
        faces_len = 0;
        vertices_len = 0;
    }

    void mesh::set_vertices(gsl::span<const glm::vec3> vrts) {
        vertices_len = vrts.size();
        vertices = std::shared_ptr<glm::vec3>(new glm::vec3[vertices_len]);

        std::cout << vertices_len << '\n';
        glm::vec3 min = vrts[0], max = vrts[0];
        auto v = vertices.get();

        for (auto i = vrts.begin(); i != vrts.end(); ++i, ++v)
        {
            *v = *i;
            min = glm::min(min, *i);
            max = glm::max(max, *i);
        }

        //bbox = physics::from_min_max(min, max);
    }

    void mesh::set_faces(gsl::span<const std::uint32_t> fcs) {
        faces_len = fcs.size();
        faces = std::shared_ptr<std::uint32_t>(new std::uint32_t[faces_len]);
        std::copy(fcs.begin(), fcs.end(), faces.get());
    }
}
}

