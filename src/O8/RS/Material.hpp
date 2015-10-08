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
* @file Material.hpp
**/

#ifndef O8_RS_MATERIAL_HPP
#define O8_RS_MATERIAL_HPP

#include <Utilities\containers\IntrusiveList.hpp>
#include <Utilities\containers\ReferenceCounted.hpp>
#include <Utilities\helpers\Name.hpp>
#include <O8\GI\Texture.hpp>

namespace O8
{
    namespace RS
    {
        class Material_descriptor
        {
        public:
            Material_descriptor();
            ~Material_descriptor();

            /* Maps */
            std::string m_Diffuse_map_name;
        };

        class Material
            : public Containers::IntrusiveList::Node<Material>
            , public Containers::ReferenceCounted::Resource
        {
        public:
            /* Types */
            typedef Containers::IntrusiveList::List<Material> List;
            typedef Containers::ReferenceCounted::Reference<Material> Reference;

            /* Ctr & Dtr */
            Material();
            virtual ~Material();

            /* Name */
            Utility::Name m_Name;

            Material_descriptor m_Descriptor;
            GI::Texture::Reference m_Diffuse_map;
        };
    }
}

#endif O8_RS_MATERIAL_HPP
