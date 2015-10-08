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
* @file Model.cpp
**/

#include "PCH.hpp"

#include "Model.hpp"

#include <Utilities\memory\Access.hpp>

namespace O8
{
    namespace RS
    {
        namespace Vertex
        {
            int32 Definition::Prepare(
                Descriptor & attribute_desc,
                Buffer::Descriptor & buffer_desc,
                Utility::Binary_data & data,
                uint32 n_vertices)
            {
                m_Attribute = attribute_desc.m_Attribute;
                m_Buffer = buffer_desc;

                auto ret = m_Data.Copy_range(
                    data,
                    attribute_desc.m_Offset,
                    Type::Get_size(attribute_desc.m_Type) * n_vertices);

                if (Utilities::Success != ret)
                {
                    return ret;
                }

                m_Type = attribute_desc.m_Type;

                return Utilities::Success;
            }
        }

        namespace Mesh
        {
            void Definition::Drop_data()
            {
                m_Indices_data.Release();

                for (size_t i = 0; i < Vertex::n_Attributes; ++i)
                {
                    m_Attributes[i].m_Data.Release();
                }
            }

            int32 Definition::Prepare(
                Vertex::Descriptor * attributes_desc,
                Utility::Binary_data & data,
                Mesh::Descriptor & mesh_desc,
                Setup & setup)
            {
                /* Set indices */
                m_Indices = setup.m_Indices;
                m_n_Indices = mesh_desc.m_n_Indices;
                m_Indices_data.Copy_range(
                    data,
                    mesh_desc.m_Indices_offset,
                    m_n_Indices * sizeof(uint32));

                /* Set attributes */
                for (size_t i = 0; i < Vertex::n_Attributes; ++i)
                {
                    Vertex::Descriptor & attr = attributes_desc[i];

                    auto ret = m_Attributes[i].Prepare(
                        attr,
                        setup.m_Attributes[i],
                        data,
                        mesh_desc.m_n_Vertices);

                    if (Utilities::Success != ret)
                    {
                        return ret;
                    }
                }

                /* Set vertex number */
                m_n_Vertices = mesh_desc.m_n_Vertices;

                return Utilities::Success;
            }
        }

        namespace Model
        {
            const size_t Definition::s_off_model_descriptor = 0;
            const uint32 Definition::s_root_parent_id = -1;

            void Definition::Drop_data()
            {
                for (auto mesh = m_Meshes.begin();
                    m_Meshes.end() != mesh;
                    ++mesh)
                {
                    mesh->Drop_data();
                }
            }

            void Definition::Drop_descriptors()
            {
                m_attributes_descriptors.clear();
                m_bone_descriptors.clear();
                m_mesh_descriptors.clear();

                m_data.Release();
            }

            int32 Definition::Load_descriptors(Utility::Binary_data && data)
            {
                int32 ret = 0;

                Release();

                m_data = data;

                /* Get descriptor */
                Descriptor desc;
                ret = MemoryAccess::Read(m_data, s_off_model_descriptor, desc);
                if (Utilities::Success != ret)
                {
                    DEBUGLOG("Failed to load Model::Descriptor");
                    return ret;
                }

                /* Read attributes */
                ret = load_attributes_descriptors(desc.m_n_Meshes, desc.m_Offset_attributes);
                if (Utilities::Success != ret)
                {
                    return ret;
                }

                /* Read bones */
                ret = load_bone_descriptors(desc.m_n_Bones, desc.m_Offset_bones);
                if (Utilities::Success != ret)
                {
                    return ret;
                }

                /* Read meshes */
                ret = load_mesh_descriptors(desc.m_n_Meshes, desc.m_Offset_meshes);
                if (Utilities::Success != ret)
                {
                    return ret;
                }

                return Utilities::Success;
            }

            int32 Definition::Prepare_definition(Mesh::Setup & setup)
            {
                if (0 == m_mesh_descriptors.size())
                {
                    return Invalid_object;
                }

                int32 ret = parse_bone_descriptors();
                if (Utilities::Success != ret)
                {
                    return ret;
                }

                ret = parse_mesh_descriptors(setup);
                if (Utilities::Success != ret)
                {
                    return ret;
                }

                return Utilities::Success;
            }

            int32 Definition::Prepare_descriptors()
            {
                Descriptor desc;

                /* Bones */
                auto ret = prepare_bone_descriptors(desc);
                if (Utilities::Success != ret)
                {
                    Drop_descriptors();
                    return ret;
                }

                /* Meshes */
                ret = prepare_mesh_descriptors(desc);
                if (Utilities::Success != ret)
                {
                    Drop_descriptors();
                    return ret;
                }

                auto data = new uint8[desc.m_Offset_animations];
                if (nullptr == data)
                {
                    Drop_descriptors();

                    return Failed_to_allocate_memory;
                }
                
                m_data.Reset(data, desc.m_Offset_animations);
                ret = MemoryAccess::Write(
                    m_data,
                    s_off_model_descriptor,
                    desc);

                if (Utilities::Success != ret)
                {
                    Drop_descriptors();
                }

                return ret;
            }

            int32 Definition::Store_descriptors()
            {
                if (0 == m_data.Size())
                {
                    return Invalid_object;
                }

                Descriptor desc;
                auto ret = MemoryAccess::Read(
                    m_data,
                    s_off_model_descriptor,
                    desc);

                if (Utilities::Success != ret)
                {
                    return ret;
                }

                ret = MemoryAccess::Write(
                    m_data,
                    desc.m_Offset_bones,
                    m_bone_descriptors.data(),
                    m_bone_descriptors.size() * sizeof(Bone::Descriptor));
                if (Utilities::Success != ret)
                {
                    return ret;
                }

                ret = MemoryAccess::Write(
                    m_data,
                    desc.m_Offset_meshes,
                    m_mesh_descriptors.data(),
                    m_mesh_descriptors.size() * sizeof(Mesh::Descriptor));
                if (Utilities::Success != ret)
                {
                    return ret;
                }

                ret = MemoryAccess::Write(
                    m_data,
                    desc.m_Offset_attributes,
                    m_attributes_descriptors.data(),
                    m_attributes_descriptors.size() * sizeof(Vertex::Descriptor));
                if (Utilities::Success != ret)
                {
                    return ret;
                }

                for (uint32 i = 0; i < m_Meshes.size(); ++i)
                {
                    auto attr_desc = &m_attributes_descriptors[i * 4];
                    auto mesh = &m_Meshes[i];
                    auto mesh_desc = &m_mesh_descriptors[i];

                    ret = MemoryAccess::Write(
                        m_data,
                        mesh_desc->m_Indices_offset,
                        mesh->m_Indices_data.Data(),
                        mesh->m_Indices_data.Size());
                    if (Utilities::Success != ret)
                    {
                        return ret;
                    }

                    for (uint32 j = 0; j < Vertex::n_Attributes; ++j)
                    {
                        ret = MemoryAccess::Write(
                            m_data,
                            attr_desc[i].m_Offset,
                            mesh->m_Attributes[j].m_Data.Data(),
                            mesh->m_Attributes[j].m_Data.Size());
                        if (Utilities::Success != ret)
                        {
                            return ret;
                        }
                    }
                }

                return Utilities::Success;
            }

            int32 Definition::Get_buffer_requirements(Requirements & info)
            {
                if (0 == m_mesh_descriptors.size())
                {
                    return Invalid_object;
                }

                info.m_Posture = m_bone_descriptors.size() * Type::Get_size(Type::mat3x4);

                info.m_Index_buffer = 0;
                
                for (uint32 i = 0; i < Vertex::n_Attributes; ++i)
                {
                    info.m_Attributes[i] = 0;
                }

                for (size_t i = 0; i < m_mesh_descriptors.size(); ++i)
                {
                    Mesh::Descriptor & mesh = m_mesh_descriptors[i];

                    info.m_Index_buffer += mesh.m_n_Indices * sizeof(uint32);

                    for (uint32 j = 0; j < Vertex::n_Attributes; ++j)
                    {
                        Vertex::Descriptor & attr = m_attributes_descriptors[i * 4 + j];

                        info.m_Attributes[j] +=
                            mesh.m_n_Vertices * Type::Get_size(attr.m_Type);
                    }
                }

                return Utilities::Success;
            }

            int32 Definition::load_attributes_descriptors(
                uint32 n_meshes,
                uint64 offset)
            {
                const int32 n_attributes = n_meshes * Vertex::n_Attributes;

                /* Allocate storage */
                m_attributes_descriptors.resize(n_attributes);

                if (0 == m_attributes_descriptors.size())
                {
                    return Failed_to_allocate_memory;
                }

                /* Read descriptors */
                int32 ret = MemoryAccess::Read(
                    m_data,
                    offset,
                    n_attributes * sizeof(Vertex::Descriptor),
                    m_attributes_descriptors.data());

                if (Utilities::Success != ret)
                {
                    DEBUGLOG("Failed to load Vertex::Descriptor[" << n_attributes << "]");
                }

                return ret;
            }

            int32 Definition::load_bone_descriptors(
                uint32 n_bones,
                uint64 offset)
            {
                /* Allocate storage */
                m_bone_descriptors.resize(n_bones);

                if (0 == m_bone_descriptors.size())
                {
                    return Failed_to_allocate_memory;
                }

                /* Read descriptors */
                int32 ret = MemoryAccess::Read(
                    m_data,
                    offset,
                    n_bones * sizeof(Bone::Descriptor),
                    m_bone_descriptors.data());

                if (Utilities::Success != ret)
                {
                    DEBUGLOG("Failed to load Bone::Descriptor[" << n_bones << "]");
                }

                return ret;
            }

            int32 Definition::load_mesh_descriptors(
                uint32 n_meshes,
                uint64 offset)
            {
                /* Allocate storage */
                m_mesh_descriptors.resize(n_meshes);

                if (0 == m_mesh_descriptors.capacity())
                {
                    return Failed_to_allocate_memory;
                }

                /* Read descriptors */
                int32 ret = MemoryAccess::Read(
                    m_data,
                    offset,
                    n_meshes * sizeof(Mesh::Descriptor),
                    m_mesh_descriptors.data());
                if (Utilities::Success != ret)
                {
                    DEBUGLOG("Failed to load Mesh::Descriptor[" << n_meshes << "]");
                }

                return ret;
            }

            int32 Definition::parse_bone_descriptors()
            {
                const size_t n_bones = m_bone_descriptors.size();

                /* Allocate storage */
                m_Bones.resize(n_bones);

                if (0 == m_Bones.capacity())
                {
                    return Failed_to_allocate_memory;
                }

                /* Parse descriptors */
                for (size_t i = 0; i < n_bones; ++i)
                {
                    auto bone = &m_Bones[i];
                    Bone::Descriptor & bone_desc = m_bone_descriptors[i];

                    /* Set id */
                    bone->m_Parent_id = bone_desc.m_Parent_id;

                    /* Set parent */
                    const auto parent_id = bone_desc.m_Parent_id;
                }

                return Utilities::Success;
            }

            int32 Definition::parse_mesh_descriptors(Mesh::Setup & setup)
            {
                const size_t n_meshes = m_mesh_descriptors.size();

                /* Allocate storage */
                m_Meshes.resize(n_meshes);

                if (0 == m_Meshes.capacity())
                {
                    return Failed_to_allocate_memory;
                }

                /* Parse descriptors */
                for (size_t i = 0; i < n_meshes; ++i)
                {
                    Vertex::Descriptor * attributes_desc = &m_attributes_descriptors[i * Vertex::n_Attributes];
                    auto mesh = m_Meshes[i];
                    Mesh::Descriptor & mesh_desc = m_mesh_descriptors[i];

                    auto ret = mesh.Prepare(
                        attributes_desc,
                        m_data,
                        mesh_desc,
                        setup);
                    if (Utilities::Success != ret)
                    {
                        return ret;
                    }
                }

                return Utilities::Success;
            }

            int32 Definition::prepare_bone_descriptors(Descriptor & desc)
            {
                size_t n_bones = m_Bones.size();
                if (0 == n_bones)
                {
                    return Invalid_object;
                }

                desc.m_n_Bones = (uint32) n_bones;
                desc.m_Offset_bones = sizeof(Descriptor);
                desc.m_Offset_meshes =
                    desc.m_Offset_bones + sizeof(Bone::Descriptor) * n_bones;

                m_bone_descriptors.resize(n_bones);
                if (n_bones != m_bone_descriptors.size())
                {
                    return Failed_to_allocate_memory;
                }

                for (size_t i = 0; i < n_bones; ++i)
                {
                    m_bone_descriptors[i].m_Parent_id = m_Bones[i].m_Parent_id;
                }

                return Utilities::Success;
            }

            int32 Definition::prepare_mesh_descriptors(Descriptor & desc)
            {
                size_t n_meshes = m_Meshes.size();
                if (0 == n_meshes)
                {
                    return Invalid_object;
                }

                desc.m_n_Meshes = (uint32)n_meshes;
                const uint64 end_of_descriptors =
                    desc.m_Offset_meshes + sizeof(Mesh::Descriptor) * n_meshes;
                uint64 next_offset = end_of_descriptors;

                m_mesh_descriptors.resize(n_meshes);
                if (n_meshes != m_mesh_descriptors.size())
                {
                    return Failed_to_allocate_memory;
                }

                m_attributes_descriptors.resize(n_meshes * Vertex::n_Attributes);
                if (n_meshes * Vertex::n_Attributes != m_attributes_descriptors.size())
                {
                    return Failed_to_allocate_memory;
                }

                /* Prpeare index offsets */
                for (size_t i = 0; i < n_meshes; ++i)
                {
                    auto mesh = &m_Meshes[i];
                    auto mesh_desc = &m_mesh_descriptors[i];

                    /* Indices */
                    mesh_desc->m_Indices_offset = next_offset;

                    next_offset += mesh->m_n_Indices * sizeof(uint32);
                }

                desc.m_Offset_attributes = next_offset;

                for (size_t i = 0; i < n_meshes; ++i)
                {
                    Vertex::Descriptor * attributes_desc = &m_attributes_descriptors[i * Vertex::n_Attributes];
                    auto mesh = &m_Meshes[i];
                    auto mesh_desc = &m_mesh_descriptors[i];

                    for (uint32 i = 0; i < Vertex::n_Attributes; ++i)
                    {
                        attributes_desc[i].m_Attribute = mesh->m_Attributes[i].m_Attribute;
                        attributes_desc[i].m_Offset = next_offset;
                        attributes_desc[i].m_Type = mesh->m_Attributes[i].m_Type;

                        next_offset += mesh->m_n_Vertices * Type::Get_size(mesh->m_Attributes[i].m_Type);
                    }
                }

                desc.m_Offset_animations = next_offset;

                return Utilities::Success;
            }
        }
    }
}
