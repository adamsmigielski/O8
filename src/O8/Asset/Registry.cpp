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
* @file Registry.cpp
**/

#include "PCH.hpp"

#include "Registry.hpp"
#include "File.hpp"

#include <fstream>

namespace O8
{
    namespace Asset
    {
        Registry_descriptor::Registry_descriptor()
            : m_Path("")
            , m_Type(Type::Unknown)
        {
            /* Nothing to be done here */
        }

        Registry_descriptor::~Registry_descriptor()
        {
            /* Nothing to be done here */
        }

        Registry::Registry()
        {
            /* Nothing to be done here */
        }

        Registry::~Registry()
        {
            /* Nothing to be done here */
        }

        int32 Registry::Load(const std::string & file_name)
        {
            std::fstream file;

            file.open(file_name.c_str(), std::fstream::in);

            if (false == file.is_open())
            {
                ERRLOG("Failed to open file: " << file_name);
                ASSERT(0);
                return Failure;
            }

            while (1)
            {
                std::string id;
                std::string path;
                std::string type;

                file >> type;
                file >> id;
                file >> path;

                if (true == file.eof())
                {
                    break;
                }

                auto desc = new Registry_descriptor;
                desc->m_ID = id;
                desc->m_Type = Type::Get_by_name(type);
                desc->m_Path = path;

                Attach(desc);
            }

            file.close();

            return Success;
        }

        int32 Registry::Store(const std::string & file_name) const
        {
            std::fstream file;

            file.open(file_name.c_str(), std::fstream::out | std::fstream::trunc);

            if (false == file.is_open())
            {
                ERRLOG("Failed to open file: " << file_name);
                ASSERT(0);
                return Failure;
            }

            for (auto it = First(); nullptr != it; it = it->Next())
            {
                const std::string & type = Type::Get_name(it->m_Type);

                file << type;
                file << " ";
                file << it->m_ID;
                file << " ";
                file << it->m_Path;
                file << std::endl;
            }

            file.close();

            return Success;
        }
    }
}

O8::Asset::Registry * Create_registry()
{
    return new O8::Asset::Registry;
}
