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
        namespace Vertex
        {
            enum Attribute
            {
                Bone_ids = 0,
                Bone_weights,
                Position,
                Texture_coordinate,

                /*  */
                n_Attributes
            };

            class Data_descriptor
            {
            public:
                Attribute m_Attribute;
                uint64 m_Offset;
                Type m_Type;
            };

            class Definition : public IntrusiveList::Node < Definition >
            {
            public:
                /* Types */
                typedef IntrusiveList::List<Definition> List;

                Definition();
                virtual ~Definition();

                Attribute m_Attribute;
                GI::Buffer::Reference m_Buffer;
                uint64 m_Offset;
                Type m_Type;
            };
        }

        namespace Mesh
        {
            class Data_descriptor
            {
            public:
                uint32 m_n_Vertices;
                uint32 m_n_Attributes;
            };

            class Definition : public IntrusiveList::Node<Definition>
            {
            public:
                /* Types */
                typedef IntrusiveList::List<Definition> List;

                /* Ctr & Dtr */
                Definition();
                virtual ~Definition();

                Vertex::Definition::List m_Attributes;
                uint32 m_n_Vertices;
                GI::Vertex_attributes * m_Vertex_attributes;
            };
        }
    }
}

#endif O8_RS_MESH_HPP
