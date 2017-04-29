//
// Created by fatih on 23.03.2017.
//

#pragma once

#include <gsl/gsl>
#include <glm/vec3.hpp>
#include <boost/shared_array.hpp>

namespace rtk {
    namespace geometry {
        class mesh
        {
            std::size_t vertices_len;
            std::size_t faces_len;

            std::shared_ptr<glm::vec3> vertices;
            std::shared_ptr<std::uint32_t> faces;
            std::shared_ptr<glm::vec3> uvs;

            //physics::aabb bbox;
        public:
            mesh();

            void set_vertices(gsl::span<const glm::vec3>);

            void set_faces(gsl::span<const std::uint32_t>);

            gsl::span<const glm::vec3> get_vertices() const
            {
                return {vertices.get(), (long) vertices_len};
            }

            gsl::span<const std::uint32_t> get_faces() const
            {
                return {faces.get(), (long) faces_len};
            }

            /*physics::aabb get_bbox() const
            {
                return bbox;
            }*/
        };
    }

    namespace malt {
        namespace geometry = rtk::geometry;
    }
}

