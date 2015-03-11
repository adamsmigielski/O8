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
* @file Type.hpp
**/

#ifndef O8_RS_TYPE_HPP
#define O8_RS_TYPE_HPP

namespace O8
{
    namespace RS
    {
        class Type
        {
        public:
            enum Basic_type
            {
                Unknown,
                Float,
                Integer,
                Unsigned_integer
            };

            uint32 m_N_columns;
            uint32 m_N_rows;

            static const Type _float;
            static const Type _int;
            static const Type _uint;
            static const Type mat2x2;
            static const Type mat2x3;
            static const Type mat2x4;
            static const Type mat3x2;
            static const Type mat3x3;
            static const Type mat3x4;
            static const Type mat4x2;
            static const Type mat4x3;
            static const Type mat4x4;
            static const Type vec2;
            static const Type vec3;
            static const Type vec4;
            static const Type ivec2;
            static const Type ivec3;
            static const Type ivec4;
            static const Type uvec2;
            static const Type uvec3;
            static const Type uvec4;
        };
    }
}

#endif O8_RS_TYPE_HPP
