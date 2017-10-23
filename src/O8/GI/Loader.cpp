/** License
*
* Copyright (c) 2015 Adam �migielski
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
* @author Adam �migielski
* @file Loader.cpp
**/

#include "PCH.hpp"

#include "Loader.hpp"

#include <Utilities\basic\ErrorCodes.hpp>
#include <O8\DL\Library.hpp>

namespace O8
{
    namespace GI
    {
        /* Library in use */
        static DL::Library * g_gi_library = nullptr;


        /* DL entry points */
        PFN_CREATE_GI Create_GI;


        /* Static routines */
        int LoadDL(const char * library_path)
        {
            /* Load library */
            auto dl = DL::Load(library_path);

            if (nullptr == dl)
            {
                return Utilities::Failed_to_load_library;
            }

            /* Load functions */
            Create_GI = (PFN_CREATE_GI) dl->GetFunctionAddress("Create_GI");

            /* Verify */
            if (nullptr == Create_GI)
            {
                delete dl;
                return Utilities::Failed_to_load_function;
            }

            /* Save DL */
            g_gi_library = dl;

            /* Done */
            return Utilities::Success;
        }

        void UnloadDL()
        {
            Create_GI = nullptr;

            delete g_gi_library;
            g_gi_library = nullptr;
        }
    }
}