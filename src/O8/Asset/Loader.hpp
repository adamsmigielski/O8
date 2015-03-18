/** License
*
* Copyright (c) 2015 Adam Śmigielski
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
* @author Adam Śmigielski
* @file Loader.hpp
**/

#ifndef O8_ASSET_LOADER_HPP
#define O8_ASSET_LOADER_HPP

#include "File.hpp"
#include "Registry.hpp"

namespace O8
{
    namespace Asset
    {
        /* DL entry points */
        extern PFN_CREATE_FILE Create_file;
        extern PFN_CREATE_REGISTRY Create_registry;
        extern PFN_CREATE_REGISTRY_ENTRY Create_registry_entry;
        extern PFN_STORE_FILE Store_file;

        /* Static routines */
        int Load_asset_archive(const char * library_path);
        int Load_asset_registry(const char * library_path);
        void Unload_asset_archive();
        void Unload_asset_registry();
    }
}

#endif O8_ASSET_LOADER_HPP
