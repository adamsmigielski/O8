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
* @file Asset_importer_ASSIMP.cpp
**/

#include "PCH.hpp"

#include "Asset_importer_ASSIMP.hpp"

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

#include <O8\RS\Model.hpp>

namespace O8
{
    namespace Asset
    {
        Importer_ASSIMP::Importer_ASSIMP()
        {
        }

        Importer_ASSIMP::~Importer_ASSIMP()
        {
        }

        int32 Importer_ASSIMP::Init()
        {
            return Utilities::Success;
        }

        int32 Importer_ASSIMP::Get_asset(
            const std::string & file_path,
            Utility::Binary_data & out_data,
            Type::Types & out_type)
        {
            Assimp::Importer importer;

            // And have it read the given file with some example postprocessing
            // Usually - if speed is not the most important aspect for you - you'll 
            // propably to request more postprocessing than we do in this example.
            const aiScene* scene = importer.ReadFile(file_path,
                aiProcess_CalcTangentSpace |
                aiProcess_Triangulate |
                aiProcess_JoinIdenticalVertices |
                aiProcess_SortByPType);

            if (nullptr == scene)
            {
                return Failed_to_load_model;
            }

            RS::Model::Definition model;

            auto root_node = scene->mRootNode;
            const size_t n_nodes = get_number_of_children(root_node) + 1;

            model.m_Bones.resize(n_nodes);

            return Utilities::Success;
        }

        size_t Importer_ASSIMP::get_number_of_children(const aiNode * node)
        {
            const size_t n_children = node->mNumChildren;
            size_t sum = 0;

            for (size_t i = 0; i < n_children; ++i)
            {
                auto child = node->mChildren[i];
                sum += get_number_of_children(child);
            }

            sum += n_children;

            return sum;
        }
    }
}

O8::Asset::Importer * Create_importer()
{
    return new O8::Asset::Importer_ASSIMP;
}

