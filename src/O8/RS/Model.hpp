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

#include <O8\Templates\IntrusiveList.hpp>
#include <O8\Templates\ReferenceCounted.hpp>
#include <O8\Utility\Name.hpp>
#include "Material.hpp"
#include "Mesh.hpp"


namespace O8
{
    namespace RS
    {
        class Model_element : public IntrusiveList::Node<Model_element>
        {
        public:
            /* Types */
            typedef IntrusiveList::List<Model_element> List;

            /* Ctr & Dtr */
            Model_element();
            ~Model_element();

            List m_Children;
            Material::Reference m_Material;
            Mesh::Reference m_Mesh;
        };

        class Model
            : public IntrusiveList::Node<Model>
            , ReferenceCounted::Resource
        {
        public:
            /* Types */
            typedef IntrusiveList::List<Model> List;
            typedef ReferenceCounted::Reference<Model> Reference;

            /* Ctr & Dtr */
            Model();
            virtual ~Model();

            /* Name */
            Utility::Name m_Name;

            Model_element::List m_Elements;
        };
    }
}

#endif O8_RS_MODEL_HPP
