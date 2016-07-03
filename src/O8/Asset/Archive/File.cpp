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
* @file File.cpp
**/

#include "PCH.hpp"

#include "File.hpp"

#include <cstring>
#include <fstream>

#include <Utilities\helpers\Hash_string.hpp>
#include <Utilities\memory\MemoryAccess.hpp>

namespace O8
{
    namespace Asset
    {
        bool check_endianess(
            std::fstream & file);
        bool check_magic(
            std::fstream & file);
        Platform::int32 get_version(
            std::fstream & file,
            bool swap_endianess,
            Platform::uint32 & out_version);
        Platform::int32 get_descriptor(
            std::fstream & file,
            Platform::uint64 offset,
            bool swap_endianess,
            File_descriptor & out_desc);
        Platform::int32 write_endianess(
            std::fstream & file);
        Platform::int32 write_magic(
            std::fstream & file);
        Platform::int32 write_version(
            std::fstream & file,
            const Platform::uint32 version);
        Platform::int32 write_descriptor(
            std::fstream & file,
            size_t off_desc,
            const std::string & id,
            size_t off_id,
            Type::Types type,
            const Platform::uint8 * data_ptr,
            size_t data_size,
            size_t off_data);

        static const Platform::uint64 desc_id_offset_size = 8;
        static const Platform::uint64 desc_data_offset_size = 8;
        static const Platform::uint64 desc_data_size_offset_size = 8;
        static const Platform::uint64 desc_size =
            desc_id_offset_size +
            sizeof(Platform::uint32) + /* Type id */
            desc_data_offset_size +
            desc_data_size_offset_size;
        static const Platform::uint32 endianess_magic = 0x01020304;
        static const Platform::uint64 endianess_size = sizeof(endianess_magic);
        static const char   magic[] = "O8_asset";
        static const Platform::uint64 magic_size = 8;
        static const Platform::uint32 ver_1 = 1;
        static const Platform::uint64 version_size = sizeof(ver_1);
        static const Platform::uint64 preamble_size = magic_size + endianess_size + version_size;

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

        Memory::Binary_data File::Get_asset(const File_descriptor & desc) const
        {
            Memory::Binary_data data;
            Memory::Binary_data result;
            std::fstream file;

            if (this != desc.Parent())
            {
                return result;
            }

            file.open(m_file_name.c_str(), std::fstream::in);
            if (false == file.is_open())
            {
                ERRLOG("Failed to open file: " << m_file_name);
                ASSERT(0);
                return result;
            }

            auto ptr = new Platform::uint8[desc.m_Size];
            if (nullptr == ptr)
            {
                ERRLOG("Failed to allocate memory");
                ASSERT(0);
                return result;
            }
            data.Reset(ptr, desc.m_Size);

            if (Utilities::Success != Memory::Access::Read(
                file,
                desc.m_Offset,
                desc.m_Size,
                ptr))
            {
                ERRLOG("File corrupted");
                ASSERT(0);

                return result;
            }

            file.close();

            result = std::move(data);

            return result;
        }

        const File_descriptor * File::Get_descriptor(const std::string & id) const
        {
            Helpers::Name_predicate<File_descriptor> pred(id);

            return Search(pred);
        }

        Platform::int32 File::Load(const std::string & file_name)
        {
            std::fstream file;
            bool swap_endianess;
            Platform::uint32 version = 0;
            Platform::uint32 n_descriptors = 0;

            file.open(file_name.c_str(), std::fstream::in);

            if (false == file.is_open())
            {
                ERRLOG("Failed to open file: " << file_name);
                ASSERT(0);
                return Utilities::Failure;
            }

            if (false == check_magic(file))
            {
                ERRLOG("File is not valid archive file for O8");
                ASSERT(0);
                return Utilities::Failure;
            }

            swap_endianess = check_endianess(file);
            if (Utilities::Success != get_version(file, swap_endianess, version))
            {
                ERRLOG("Failed to get file version. File corrupted");
                ASSERT(0);
                return Utilities::Failure;
            }
            m_is_endianess_swapped = swap_endianess;

            if (Utilities::Success != Memory::Access::Read(
                file,
                preamble_size,
                swap_endianess,
                n_descriptors))
            {
                ERRLOG("Failed to get descriptors number. File corrupted");
                ASSERT(0);
                return Utilities::Failure;
            }

            for (Platform::uint32 i = 0; i < n_descriptors; ++i)
            {
                File_descriptor * desc = new File_descriptor;
                if (nullptr == desc)
                {
                    ERRLOG("Memory allocaton failure");
                    ASSERT(0);
                    return Utilities::Failure;
                }

                const Platform::uint64 offset =
                    preamble_size +
                    sizeof(n_descriptors) +
                    desc_size * i;

                if (Utilities::Success != get_descriptor(
                    file,
                    offset,
                    swap_endianess,
                    *desc))
                {
                    ERRLOG("Failed to load descriptor: " << i);
                    ASSERT(0);
                    delete desc;
                    return Utilities::Failure;
                }

                Attach(desc);
            }

            file.close();

            m_file_name = file_name;

            return Utilities::Success;
        }

        bool File::Is_endianess_swapped() const
        {
            return m_is_endianess_swapped;
        }

        Platform::int32 File::Store_file(
            const std::string & file_name,
            const Asset_descriptor * first,
            const Asset_descriptor * end)
        {
            std::fstream file;
            Platform::uint64 mem_req_for_descriptors = 0;
            Platform::uint64 mem_req_for_ids = 0;
            Platform::uint32 n_descriptors = 0;
            Platform::uint64 off_desc = O8::Asset::preamble_size;
            Platform::uint64 off_id = 0;
            Platform::uint64 off_data = 0;

            file.open(file_name.c_str(), std::fstream::out | std::fstream::trunc);

            if (false == file.is_open())
            {
                ERRLOG("Failed to open file: " << file_name);
                ASSERT(0);
                return Utilities::Failure;
            }

            for (auto it = first; end != it; it = it->Next())
            {
                mem_req_for_descriptors += O8::Asset::desc_size;
                mem_req_for_ids += it->Get_name().length() + sizeof(Platform::uint32);
                n_descriptors += 1;
            }

            off_id = off_desc + mem_req_for_descriptors;
            off_data = off_id + mem_req_for_ids;

            auto ret = write_magic(file);
            if (Utilities::Success != ret)
            {
                ASSERT(0);
                return ret;
            }

            ret = write_endianess(file);
            if (Utilities::Success != ret)
            {
                ASSERT(0);
                return ret;
            }

            ret = write_version(file, ver_1);
            if (Utilities::Success != ret)
            {
                ASSERT(0);
                return ret;
            }

            if (Utilities::Success != Memory::Access::Write(
                file,
                preamble_size,
                n_descriptors))
            {
                ASSERT(0);
                return Utilities::Failure;
            }

            for (auto it = first; end != it; it = it->Next())
            {
                Memory::Binary_data data;
                Type::Types type;

                const std::string & name = it->Get_name();
                if (Utilities::Success != it->Get_details(data, type))
                {
                    ERRLOG("Failed to import asset: " << name);
                }

                if (Utilities::Success != O8::Asset::write_descriptor(
                    file,
                    off_desc,
                    name,
                    off_id,
                    type,
                    data.Data(),
                    data.Size(),
                    off_data))
                {
                    ERRLOG("Failed to store archive in file.");
                    ASSERT(0);
                    return Utilities::Failure;
                }

                off_desc += O8::Asset::desc_size;
                off_id += name.length() + sizeof(Platform::uint32);
                off_data += data.Size();
            }

            file.close();

            return Utilities::Success;
        }

        bool check_endianess(
            std::fstream & file)
        {
            Platform::uint32 endianess = 0;

            if (Utilities::Success != Memory::Access::Read(
                file,
                magic_size,
                endianess))
            {
                ERRLOG("File_corrupted");
                ASSERT(0);
            }

            return (endianess_magic != endianess);
        }

        Platform::int32 write_endianess(
            std::fstream & file)
        {
            return Memory::Access::Write(
                file,
                magic_size,
                endianess_magic);
        }

        bool check_magic(
            std::fstream & file)
        {
            char buffer[16];

            file.seekg(0, std::fstream::beg);
            file.read(buffer, magic_size);

            if (false == file.good())
            {
                ASSERT(0);
                return false;
            }

            buffer[magic_size] = 0;

            return (0 == strcmp(magic, buffer));
        }

        Platform::int32 write_magic(
            std::fstream & file)
        {
            file.seekp(0, std::fstream::beg);
            file.write(magic, magic_size);

            if (false == file.good())
            {
                ASSERT(0);
                return Utilities::Failure;
            }

            return Utilities::Success;
        }

        Platform::int32 get_version(
            std::fstream & file,
            bool swap_endianess,
            Platform::uint32 & out_version)
        {
            return Memory::Access::Read(
                file,
                magic_size + endianess_size,
                swap_endianess,
                out_version);
        }

        Platform::int32 write_version(
            std::fstream & file,
            const Platform::uint32 version)
        {
            return Memory::Access::Write(
                file,
                magic_size + endianess_size,
                version);
        }

        Platform::int32 get_descriptor(
            std::fstream & file,
            Platform::uint64 offset,
            bool swap_endianess,
            File_descriptor & out_desc)
        {
            Platform::uint64 id_offset;
            Platform::uint32 type_id;
            std::string id;

            if (Utilities::Success != Memory::Access::Read(
                file,
                offset + 0 * sizeof(Platform::uint64),
                swap_endianess,
                id_offset))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Utilities::Failure;
            }

            if (Utilities::Success != Memory::Access::Read(
                file,
                offset + 1 * sizeof(Platform::uint64),
                swap_endianess,
                out_desc.m_Offset))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Utilities::Failure;
            }

            if (Utilities::Success != Memory::Access::Read(
                file,
                offset + 2 * sizeof(Platform::uint64),
                swap_endianess,
                out_desc.m_Size))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Utilities::Failure;
            }

            if (Utilities::Success != Memory::Access::Read(
                file,
                offset + 3 * sizeof(Platform::uint64),
                swap_endianess,
                type_id))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Utilities::Failure;
            }

            out_desc.m_Type = Type::Get_by_id(type_id);

            if (Utilities::Success != Memory::Access::Read(
                file,
                id_offset,
                swap_endianess,
                id))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Utilities::Failure;
            }

            out_desc.m_Name(id);

            return Utilities::Success;
        }

        Platform::int32 write_descriptor(
            std::fstream & file,
            size_t off_desc,
            const std::string & id,
            size_t off_id,
            Type::Types type,
            const Platform::uint8 * data_ptr,
            size_t data_size,
            size_t off_data)
        {
            Platform::uint32 type_id = Type::Get_id(type);

            if (Utilities::Success != Memory::Access::Write(
                file,
                off_desc + 0 * sizeof(Platform::uint64),
                off_id))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Utilities::Failure;
            }

            if (Utilities::Success != Memory::Access::Write(
                file,
                off_desc + 1 * sizeof(Platform::uint64),
                off_data))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Utilities::Failure;
            }

            if (Utilities::Success != Memory::Access::Write(
                file,
                off_desc + 2 * sizeof(Platform::uint64),
                data_size))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Utilities::Failure;
            }

            if (Utilities::Success != Memory::Access::Write(
                file,
                off_desc + 3 * sizeof(Platform::uint64),
                type_id))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Utilities::Failure;
            }

            if (Utilities::Success != Memory::Access::Write(
                file,
                off_id,
                id))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Utilities::Failure;
            }

            if (Utilities::Success != Memory::Access::Write(
                file,
                off_data,
                data_ptr,
                data_size))
            {
                ERRLOG("File corrupted");
                ASSERT(0);
                return Utilities::Failure;
            }

            return Utilities::Success;
        }
    }
}
