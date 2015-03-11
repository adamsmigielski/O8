/** License
*
* Copyright (c) 2014 Adam Śmigielski
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
* @file Context.hpp
**/

#ifndef O8_OPENGL_CONTEXT_HPP
#define O8_OPENGL_CONTEXT_HPP

#include "gl.hpp"

namespace O8
{
    namespace OpenGL
    {
        class Context
        {
            friend void LoadGL(Context & context);

        public:
            virtual ~Context();

            virtual void Make_current() = 0;
            virtual void Swap() = 0;

            virtual void * Get_proc_address(const char * name) = 0;

            const OpenGL::Functions & Functions() const;

        protected:
            Context();

        private:
            OpenGL::Functions m_gl_functions;
        };
    }
}

#endif /* O8_OPENGL_CONTEXT_HPP */
