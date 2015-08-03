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

namespace O8
{
    namespace Scene
    {
        /* **** Interfaces **** */
        /**
         * Represents entry of scene
         **/
        class Node
        {
        public:
            /* **** Dtr **** */
            virtual ~Node();


            /* **** Methods **** */
            virtual Node * Get_parent() = 0;
        };


        /* **** Routines **** */
        /**
         * Creates new root node of given scene type
         * @param Type Type of scene. Supported types can be queried with Enumerate_types
         * @return New node or nullptr
         **/
        typedef Node * (O8_API * PFN_CREATE_ROOT_NODE)(
            const char * Type);
        extern PFN_CREATE_ROOT_NODE Create_root_node;

        /**
         * Returns number of supported scene types. See Enumerate_types
         * @return Number of supported types
         **/
        typedef uint32 (O8_API * PFN_GET_SUPPORTED_TYPES_NUMBER)();
        extern PFN_GET_SUPPORTED_TYPES_NUMBER Get_supported_types_number;

        /**
         * Returns name of scene type at given index
         * @param index Index of queried type
         * @return Name of type or nullptr
         **/
        typedef const char * (O8_API * PFN_ENUMERATE_TYPES)(
            uint32 index);
        extern PFN_ENUMERATE_TYPES Enumerate_types;


        /* **** Static routines for DL loading and linking **** */
        int  LoadDL(const char * file_path);
        void UnloadDL();
        void Link_scene(
            PFN_CREATE_ROOT_NODE,
            PFN_GET_SUPPORTED_TYPES_NUMBER,
            PFN_ENUMERATE_TYPES)
    } /* namespace Scene */
} /* namespace O8 */
