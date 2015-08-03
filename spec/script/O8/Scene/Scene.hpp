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
* @file Scene.hpp
**/

/* This file was generated */

#ifndef O8_SCENE_SCENE_HPP
#define O8_SCENE_SCENE_HPP

/* **** Include directives **** */
#include "Node.hpp"

/* **** Definitions **** */
namespace O8
{
    namespace Scene
    {
        /* **** Routines **** */
        extern PFN_CREATE_ROOT_NODE Create_root_node;
        extern PFN_GET_SUPPORTED_TYPES_NUMBER Get_supported_types_number;
        extern PFN_ENUMERATE_TYPES Enumerate_types;

        /* **** Static routines for DL loading and linking **** */
        int  Load_dl(const char * file_path);
        void Unload_dl();
        void Link_scene(
            PFN_CREATE_ROOT_NODE create_root_node,
            PFN_GET_SUPPORTED_TYPES_NUMBER get_supported_types_number,
            PFN_ENUMERATE_TYPES enumerate_types)
    } /* namespace Scene */

} /* namespace O8 */

#endif /* O8_SCENE_SCENE_HPP */

