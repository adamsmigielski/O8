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
* @file Renderer.hpp
**/

#ifndef O8_RS_RENDERER_HPP
#define O8_RS_RENDERER_HPP

#include <Utilities\math\FloatTypes.hpp>

namespace O8
{
    namespace GI
    {
        class Presentation;
        class RI;
    }

    namespace RS
    {
        class POV;
        class RS;

        struct Entity
        {
            Math::float4 m_Position;
            Math::float4 m_Orientation;
        };

        class Renderer_data
        {
        public:
            virtual ~Renderer_data();

        protected:
            Renderer_data();
        };

        class Renderer
        {
        public:
            virtual ~Renderer();

            virtual Platform::int32 Init(
                RS * rs,
                GI::RI * ri);

            virtual Renderer_data * Create_renderer_data() = 0;

            virtual Platform::int32 Render(
                Renderer_data * renderer_data,
                GI::Presentation * presentation,
                POV * pov) = 0;

        protected:
            Renderer();

            GI::Presentation * m_presentation;
        };
    }
}

#endif O8_RS_RENDERER_HPP
