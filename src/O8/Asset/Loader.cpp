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
* @file Loader.cpp
**/

#include "PCH.hpp"

#include "Loader.hpp"

#include <O8\Common\ErrorCodes.hpp>
#include <O8\DL\DL.hpp>

namespace O8
{
    namespace Asset
    {
        /* Library in use */
        static DL::DL * g_asset_archive_library = nullptr;
        static DL::DL * g_asset_registry_library = nullptr;

        /* DL entry points */
        PFN_CREATE_FILE Create_file;
        PFN_CREATE_REGISTRY Create_registry;
        PFN_CREATE_REGISTRY_ENTRY Create_registry_entry;
        PFN_STORE_FILE Store_file;

        /* Static routines */
        int32 Load_asset_archive(const char * library_path)
        {
            /* Load library */
            auto dl = DL::Load(library_path);

            if (nullptr == dl)
            {
                return Failed_to_load_library;
            }

            /* Load functions */
            Create_file = (PFN_CREATE_FILE) dl->GetFunctionAddress("Create_file");
            Store_file = (PFN_STORE_FILE) dl->GetFunctionAddress("Store_file");

            /* Verify */
            if ((nullptr == Create_file) ||
                (nullptr == Store_file) )
            {
                delete dl;
                return Failed_to_load_function;
            }

            /* Save DL */
            g_asset_archive_library = dl;

            /* Done */
            return Success;
        }

        int32 Load_asset_registry(const char * library_path)
        {
            /* Load library */
            auto dl = DL::Load(library_path);

            if (nullptr == dl)
            {
                return Failed_to_load_library;
            }

            /* Load functions */
            Create_registry = (PFN_CREATE_REGISTRY) dl->GetFunctionAddress("Create_registry");
            Create_registry_entry = (PFN_CREATE_REGISTRY_ENTRY) dl->GetFunctionAddress("Create_registry_entry");

            /* Verify */
            if ((nullptr == Create_registry) ||
                (nullptr == Create_registry_entry) )
            {
                delete dl;
                return Failed_to_load_function;
            }

            /* Save DL */
            g_asset_registry_library = dl;

            /* Done */
            return Success;
        }

        void Unload_asset_archive()
        {
            delete g_asset_archive_library;
            g_asset_archive_library = nullptr;

            Create_file = nullptr;
            Store_file = nullptr;
        }

        void Unload_asset_registry()
        {
            delete g_asset_registry_library;
            g_asset_registry_library = nullptr;

            Create_registry = nullptr;
            Create_registry_entry = nullptr;
        }
    }
}
