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
* @file Type.cpp
**/

#include "PCH.hpp"

#include "Type.hpp"

namespace O8
{
    namespace Asset
    {
        static const uint32 g_id_bitmap   = -1;
        static const uint32 g_id_shader   = -2;
        static const uint32 g_id_material = -3;
        static const uint32 g_id_geometry = -4;
        static const uint32 g_id_skeleton = -5;
        static const uint32 g_id_model    = -6;

        Type::Types Type::Get_by_id(uint32 id)
        {
            Types type = Type::Unknown;

            switch (id)
            {
            case g_id_bitmap: type = Type::Bitmap; break;
            case g_id_shader: type = Type::Shader; break;
            case g_id_material: type = Type::Material; break;
            case g_id_geometry: type = Type::Geometry; break;
            case g_id_skeleton: type = Type::Skeleton; break;
            case g_id_model: type = Type::Model; break;
            default: type = Type::Unknown; break;
            }

            return type;
        }

        Type::Types Type::Get_by_name(const std::string & name)
        {
            Types type = Type::Unknown;

            if (0 == name.compare("Bitmap"))
            {
                type = Type::Bitmap;
            }
            else if (0 == name.compare("Shader"))
            {
                type = Type::Shader;
            }
            else if (0 == name.compare("Material"))
            {
                type = Type::Material;
            }
            else if (0 == name.compare("Geometry"))
            {
                type = Type::Geometry;
            }
            else if (0 == name.compare("Skeleton"))
            {
                type = Type::Skeleton;
            }
            else if (0 == name.compare("Model"))
            {
                type = Type::Model;
            }

            return type;
        }

        uint32 Type::Get_id(const Types & type)
        {
            uint32 id = 0;

            switch (type)
            {
            case Type::Bitmap:   id = g_id_bitmap; break;
            case Type::Shader:   id = g_id_shader; break;
            case Type::Material: id = g_id_material; break;
            case Type::Geometry: id = g_id_geometry; break;
            case Type::Skeleton: id = g_id_skeleton; break;
            case Type::Model:    id = g_id_model; break;
            default:             id = 0; break;
            }

            return id;
        }

        std::string Type::Get_name(const Types & type)
        {
            std::string name = "";

            switch (type)
            {
            case Type::Bitmap: name = "Bitmap"; break;
            case Type::Shader: name = "Shader"; break;
            case Type::Material: name = "Material"; break;
            case Type::Geometry: name = "Geometry"; break;
            case Type::Skeleton: name = "Skeleton"; break;
            case Type::Model: name = "Model"; break;
            default: name = "Unknown"; break;
            }

            return name;
        }
    }
}
