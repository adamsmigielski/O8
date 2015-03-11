/** License
*
* Copyright (c) 2014 Adam Œmigielski
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
* @file File.cpp
**/

#include "PCH.hpp"

#include "File.hpp"

#include <fstream>

#include <O8\Templates\MemoryAccess.hpp>

namespace O8
{
    namespace Asset
    {
        bool check_endianess(
            std::fstream & file);
        bool check_magic(
            std::fstream & file);
        int32 get_version(
            std::fstream & file,
            bool swap_endianess,
            uint32 & out_version);
        int32 get_descriptor(
            std::fstream & file,
            uint64 offset,
            bool swap_endianess,
            File_descriptor & out_desc);
        int32 write_endianess(
            std::fstream & file);
        int32 write_magic(
            std::fstream & file);
        int32 write_version(
            std::fstream & file,
            uint32 & out_version);
        int32 write_descriptor(
            std::fstream & file,
            uint64 offset,
            File_descriptor & out_desc);

        static const uint64 desc_id_offset_size = 8;
        static const uint64 desc_data_offset_size = 8;
        static const uint64 desc_data_size_offset_size = 8;
        static const uint64 desc_size =
            desc_id_offset_size +
            sizeof(uint32) + /* Type id */
            desc_data_offset_size +
            desc_data_size_offset_size;
        static const uint32 endianess_magic = 0x01020304;
        static const uint64 endianess_size = sizeof(endianess_magic);
        static const char   magic[] = "O8_asset";
        static const uint64 magic_size = 8;
        static const uint32 ver_1 = 1;
        static const uint64 version_size = sizeof(ver_1);
        static const uint64 preamble_size = magic_size + endianess_size + version_size;

        File_descriptor::File_descriptor()
            : m_Offset(0)
            , m_Size(0)
            , m_Type(Type::Unknown)
        {
            /* Nothing to be done here */
        }

        File_descriptor::~File_descriptor()
        {
            /* Nothing to be done here */
        }

        File::File()
        {
            /* Nothing to be done here */
        }

        File::~File()
        {
            /* Nothing to be done here */
        }

        Asset * File::Get_asset(const File_descriptor & desc) const
        {
            Utility::Binary_data data;
            std::fstream file;

            if (this != desc.Parent())
            {
                return nullptr;
            }

            file.open(m_file_name.c_str(), std::fstream::in);
            if (false == file.is_open())
            {
                ERRLOG("Failed to open file: " << m_file_name);
                ASSERT(0);
                return nullptr;
            }

            auto ptr = new uint8[desc.m_Size];
            if (nullptr == ptr)
            {
                ERRLOG("Failed to allocate memory");
                ASSERT(0);
                return nullptr;
            }
            data.Reset(ptr, desc.m_Size);

            if (Success != MemoryAccess::Read(
                file,
                desc.m_Offset,
                desc.m_Size,
                ptr))
            {
                ERRLOG("File corrupted");
                ASSERT(0);

                return nullptr;
            }

            file.close();

            Asset * asset = new Asset;
            if (nullptr == asset)
            {
                ERRLOG("Failed to allocate memory");
                ASSERT(0);
                return nullptr;
            }

            asset->m_ID = desc.m_ID;
            asset->m_Type = desc.m_Type;
            asset->m_Data.Take(data);

            return asset;
        }

        const File_descriptor * File::Get_descriptor(const std::string & id) const
        {
            return Search(Descriptor::Get_id, id);
        }

        int32 File::Load(const std::string & file_name)
        {
            std::fstream file;
            bool swap_endianess;
            uint32 version = 0;
            uint32 n_descriptors = 0;

            file.open(file_name.c_str(), std::fstream::in);

            if (false == file.is_open())
            {
                ERRLOG("Failed to open file: " << file_name);
                ASSERT(0);
                return Failure;
            }

            if (false == check_magic(file))
            {
                ERRLOG("File is not valid archive file for O8");
                ASSERT(0);
                return Failure;
            }

            swap_endianess = check_endianess(file);
            if (Success != get_version(file, swap_endianess, version))
            {
                ERRLOG("Failed to get file version. File corrupted");
                ASSERT(0);
                return Failure;
            }

            if (Success != MemoryAccess::Read(
                file,
                preamble_size,
                swap_endianess,
                n_descriptors))
            {
                ERRLOG("Failed to get descriptors number. File corrupted");
                ASSERT(0);
                return Failure;
            }

            for (uint32 i = 0; i < n_descriptors; ++i)
            {
                File_descriptor * desc = new File_descriptor;
                if (nullptr == desc)
                {
                    ERRLOG("Memory allocaton failure");
                    ASSERT(0);
                    return Failure;
                }

                const uint64 offset =
                    preamble_size +
                    sizeof(n_descriptors) +
                    desc_size * i;

                if (Success != get_descriptor(
                    file,
                    offset,
                    swap_endianess,
                    *desc))
                {
                    ERRLOG("Failed to load descriptor: " << i);
                    ASSERT(0);
                    delete desc;
                    return Failure;
                }

                Attach(desc);
            }

            file.close();

            m_file_name = file_name;

            return Success;
        }

        bool check_endianess(
            std::fstream & file)
        {
            uint32 endianess = 0;

            if (Success != MemoryAccess::Read(
                file,
                magic_size,
                endianess))
            {
                ERRLOG("File_corrupted");
                ASSERT(0);
            }

            return (endianess_magic != endianess);
        }

        bool check_magic(
            std::fstream & file)
        {
            char buffer[16];

            file.seekg(0, std::fstream::beg);
            file.read(buffer, magic_size);

            if (false == file.good())
            {
                ERRLOG("File corrupted");
                ASSERT(0);
            }

            buffer[magic_size] = 0;

            return (0 == strcmp(magic, buffer));
        }

        int32 get_version(
            std::fstream & file,
            bool swap_endianess,
            uint32 & out_version)
        {
            return MemoryAccess::Read(
                file,
                magic_size + endianess_size,
                swap_endianess,
                out_version);
        }
        
        int32 get_descriptor(
            std::fstream & file,
            uint64 offset,
            bool swap_endianess,
            File_descriptor & out_desc)
        {
            uint64 id_offset;
            uint32 type_id;

            if (Success != MemoryAccess::Read(
                file,
                offset + 0 * sizeof(uint64),
                swap_endianess,
                id_offset))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Failure;
            }

            if (Success != MemoryAccess::Read(
                file,
                offset + 1 * sizeof(uint64),
                swap_endianess,
                out_desc.m_Offset))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Failure;
            }

            if (Success != MemoryAccess::Read(
                file,
                offset + 2 * sizeof(uint64),
                swap_endianess,
                out_desc.m_Size))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Failure;
            }

            if (Success != MemoryAccess::Read(
                file,
                offset + 3 * sizeof(uint64),
                swap_endianess,
                type_id))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Failure;
            }

            out_desc.m_Type = Type::Get_by_id(type_id);

            if (Success != MemoryAccess::Read(
                file,
                id_offset,
                swap_endianess,
                out_desc.m_ID))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Failure;
            }

            return Success;
        }

        int32 write_descriptor(
            std::fstream & file,
            uint64 off_desc,
            const std::string & id,
            uint64 off_id,
            Type::Types type,
            const Utility::Binary_data & data,
            uint64 off_data)
        {
            uint32 type_id = Type::Get_id(type);

            if (Success != MemoryAccess::Write(
                file,
                off_desc + 0 * sizeof(uint64),
                off_id))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Failure;
            }

            if (Success != MemoryAccess::Write(
                file,
                off_desc + 1 * sizeof(uint64),
                off_data))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Failure;
            }

            if (Success != MemoryAccess::Write(
                file,
                off_desc + 2 * sizeof(uint64),
                data.Size()))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Failure;
            }

            if (Success != MemoryAccess::Write(
                file,
                off_desc + 3 * sizeof(uint64),
                type_id))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Failure;
            }

            if (Success != MemoryAccess::Write(
                file,
                off_id,
                id))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Failure;
            }

            if (Success != MemoryAccess::Write(
                file,
                off_data,
                data.Data(),
                data.Size()))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Failure;
            }

            return Success;
        }
    }
}

O8::Asset::File * Create_file()
{
    return new O8::Asset::File;
}

O8::int32 Store_file(
    const std::string & file_name,
    const O8::Asset::Asset::List & assets)
{
    std::fstream file;
    O8::uint64 mem_req_for_descriptors = 0;
    O8::uint64 mem_req_for_ids = 0;
    O8::uint64 off_desc = O8::Asset::preamble_size;
    O8::uint64 off_id = 0;
    O8::uint64 off_data = 0;

    file.open(file_name.c_str(), std::fstream::out | std::fstream::trunc);

    if (false == file.is_open())
    {
        ERRLOG("Failed to open file: " << file_name);
        ASSERT(0);
        return O8::Failure;
    }

    for (auto it = assets.First(); nullptr != it; it = it->Next())
    {
        mem_req_for_descriptors += O8::Asset::desc_size;
        mem_req_for_ids += it->m_ID.length() + sizeof(O8::uint32);
    }

    off_id = off_desc + mem_req_for_descriptors;
    off_data = off_id + mem_req_for_ids;

    for (auto it = assets.First(); nullptr != it; it = it->Next())
    {
        if (O8::Success != O8::Asset::write_descriptor(
            file,
            off_desc,
            it->m_ID,
            off_id,
            it->m_Type,
            it->m_Data,
            off_data))
        {
            ERRLOG("Failed to store archive in file.");
            ASSERT(0);
            return O8::Failure;
        }

        off_desc += O8::Asset::desc_size;
        off_id += it->m_ID.length() + sizeof(O8::uint32);
        off_data += it->m_Data.Size();
    }

    file.close();

    return O8::Success;
}
