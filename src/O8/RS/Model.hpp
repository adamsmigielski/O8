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
* @file Model.hpp
**/

#ifndef O8_RS_MODEL_HPP
#define O8_RS_MODEL_HPP

#include <O8\GI\Buffer.hpp>
#include <O8\Math\FloatTypes.hpp>
#include <Utilities\containers\IntrusiveList.hpp>
#include <O8\Templates\ReferenceCounted.hpp>
#include <O8\Utility\Binary_data.hpp>
#include <O8\Utility\Name.hpp>

#include "Material.hpp"
#include "Type.hpp"

#include <memory>


namespace O8
{
    namespace GI
    {
        class Vertex_attributes;
    }

    namespace RS
    {
        namespace Buffer
        {
            class Descriptor
            {
            public:
                GI::Buffer::Reference m_Buffer;
                uint64 m_Offset;
                uint64 m_Stride;
            };
        }

        namespace Posture
        {
            class Placement
            {
            public:
                Math::float4 m_Postion;
                Math::float4 m_Orientation;
            };

            class Frame
            {
            public:
                Placement * m_Placements;
            };

            class Animation
            {
            public:
                Frame * m_Frames;
                uint32 m_n_Frames;
                float m_FPS;
            };
        }

        namespace Bone
        {
            class Descriptor
            {
            public:
                uint32 m_Parent_id;
            };

            class Definition
            {
            public:
                uint32 m_Parent_id;
            };
        }

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

            class Descriptor
            {
            public:
                Attribute m_Attribute;
                uint64 m_Offset;
                Type m_Type;
            };

            class Definition
            {
            public:
                Definition();
                virtual ~Definition();

                int32 Prepare(
                    Descriptor & attribute_desc,
                    Buffer::Descriptor & buffer_desc,
                    Utility::Binary_data & data,
                    uint32 n_vertices);

                Attribute m_Attribute;
                Buffer::Descriptor m_Buffer;
                Utility::Binary_data m_Data;
                Type m_Type;
            };
        }

        namespace Mesh
        {
            class Setup
            {
            public:
                Buffer::Descriptor m_Attributes[Vertex::n_Attributes];
                Buffer::Descriptor m_Indices;
            };

            class Descriptor
            {
            public:
                uint64 m_Indices_offset;
                uint32 m_n_Indices;
                uint32 m_n_Vertices;
            };

            class Definition
            {
            public:
                /* Ctr & Dtr */
                Definition();
                virtual ~Definition();

                void Drop_data();
                int32 Prepare(
                    Vertex::Descriptor * attributes_desc,
                    Utility::Binary_data & data,
                    Mesh::Descriptor & mesh_desc,
                    Setup & setup);

                Vertex::Definition m_Attributes[Vertex::n_Attributes];
                Buffer::Descriptor m_Indices;
                Utility::Binary_data m_Indices_data;
                uint32 m_n_Indices;
                uint32 m_n_Vertices;
                GI::Vertex_attributes * m_Vertex_attributes;
            };
        }

        namespace Model
        {

            class Requirements
            {
            public:
                size_t m_Index_buffer;
                size_t m_Attributes[Vertex::n_Attributes];
                size_t m_Posture;
            };

            class Descriptor
            {
            public:
                uint32 m_n_Animations;
                uint32 m_n_Bones;
                uint32 m_n_Meshes;
                uint64 m_Offset_animations;
                uint64 m_Offset_attributes;
                uint64 m_Offset_bones;
                uint64 m_Offset_meshes;
            };

            class Definition
                : public IntrusiveList::Node < Definition >
                , ReferenceCounted::Resource
            {
            public:
                /* Types */
                typedef IntrusiveList::List<Definition> List;
                typedef ReferenceCounted::Reference<Definition> Reference;

                /* Ctr & Dtr */

                /* Init */
                void Drop_data();
                void Drop_descriptors();
                int32 Load_descriptors(Utility::Binary_data && data);
                int32 Prepare_definition(Mesh::Setup & setup);
                int32 Prepare_descriptors();
                void Release();
                int32 Store_descriptors();

                /*  */
                int32 Get_buffer_requirements(Requirements & info);

                std::vector<Bone::Definition> m_Bones;
                std::vector<Mesh::Definition> m_Meshes;
                Utility::Name m_Name;

            private:
                /* Methods */ 
                int32 load_attributes_descriptors(
                    uint32 n_meshes,
                    uint64 offset);
                int32 load_bone_descriptors(
                    uint32 n_bones,
                    uint64 offset);
                int32 load_mesh_descriptors(
                    uint32 n_meshes,
                    uint64 offset);
                int32 parse_bone_descriptors();
                int32 parse_mesh_descriptors(Mesh::Setup & setup);
                int32 prepare_bone_descriptors(Descriptor & desc);
                int32 prepare_mesh_descriptors(Descriptor & desc);

                /* Attributes */
                std::vector<Vertex::Descriptor> m_attributes_descriptors;
                std::vector<Bone::Descriptor> m_bone_descriptors;
                Utility::Binary_data m_data;
                std::vector<Mesh::Descriptor> m_mesh_descriptors;

                /* Constants */
                static const size_t s_off_model_descriptor;

                static const uint32 s_root_parent_id;
            };
        }
    }
}

#endif O8_RS_MODEL_HPP
