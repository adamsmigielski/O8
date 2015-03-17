/** License
*
* Copyright (c) 2015 Adam Œmigielski
*
*
*  Permission is hereby granted, free of charge, to any person obtaining a
*      copy of this software and associated documentation files (the
*      "Software"), to deal in the Software without restriction, including
*      without limitation the rights to use, copy, modify, merge, publish,
*      distribute, sublicense, and/or sell copies of the Software, and to
*      permit persons to whom the Software is furnished to do so, subject to
*      the following conditions: The above copyright notice and this permission
*      notice shall be included in all copies or substantial portions of the
*      Software.
*
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
*      OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
*      MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
*      IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
*      CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
*      TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
*      SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
**/

/**
* @author Adam Œmigielski
* @file Mesh.hpp
**/

#ifndef O8_RS_MESH_HPP
#define O8_RS_MESH_HPP

#include <O8\Templates\IntrusiveList.hpp>
#include <O8\GI\Buffer.hpp>
#include <O8\Utility\Name.hpp>

#include "Type.hpp"

namespace O8
{
    namespace GI
    {
        class Vertex_attributes;
    }

    namespace RS
    {
        class Vertex_attribute : public IntrusiveList::Node < Vertex_attribute >
        {
        public:
            enum Attribute
            {
                Position,
                Texture_coordinate,
                Bone_ids,
                Bone_weights,
            };

            Vertex_attribute();
            virtual ~Vertex_attribute();

            Attribute m_Attribute;
            GI::Buffer::Reference m_Buffer;
            uint64 m_Offset;
            uint64 m_Stride;
            Type m_Type;
        };

        class Vertex_definition : public IntrusiveList::List < Vertex_attribute >
        {
        public:
            Vertex_definition();
            virtual ~Vertex_definition();

            GI::Vertex_attributes * m_Vertex_attributes;
        };

        class Mesh
            : public IntrusiveList::Node<Mesh>
            , ReferenceCounted::Resource
        {
        public:
            /* Types*/
            typedef IntrusiveList::List<Mesh> List;
            typedef ReferenceCounted::Reference<Mesh> Reference;

            /* Ctr & Dtr */
            Mesh();
            virtual ~Mesh();

            /* Name */
            Utility::Name m_Name;

            virtual Vertex_definition * Get_vertex_definition();
        };
    }
}

#endif O8_RS_MESH_HPP
