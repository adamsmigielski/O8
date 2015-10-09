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
* @file RS.hpp
**/

#ifndef O8_RS_RS_HPP
#define O8_RS_RS_HPP

#include "Material.hpp"
#include "Model.hpp"

namespace O8
{
    namespace GI
    {
        class Presentation;
        class RI;
    }

    namespace RS
    {
        class Renderer;

        class RS
        {
        public:
            RS();
            ~RS();

            Platform::int32 Init(
                GI::RI * ri);
            void Release();

            const Material::List & Get_material_list() const;
            //const Mesh::List & Get_mesh_list() const;
            //const Model::List & Get_model_list() const;

            Material * Create_material();
            //Mesh * Create_mesh();
            //Model * Create_model();

        private:
            void release();

            Material::List m_materials;
            //Mesh::List m_meshes;
            //Model::List m_models;

            GI::RI * m_ri;
        };
    }
}

#endif O8_RS_RS_HPP
