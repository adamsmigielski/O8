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
* @file Actor.hpp
**/

#ifndef O8_ENGINE_ACTOR_HPP
#define O8_ENGINE_ACTOR_HPP

#include <O8\Math\FloatTypes.hpp>
#include <O8\RS\Model.hpp>
#include <O8\Utility\Binary_data.hpp>

namespace O8
{
    namespace Engine
    {
        class Actor
        {
        public:
            Actor();
            virtual ~Actor();

            uint64 m_Index;
        };

        class Actor_data
        {
        public:
            Actor_data();
            ~Actor_data();

            static inline size_t Get_offset_position(const Actor & actor)
            {
                return sizeof(Math::float4) * actor.m_Index;
            }

            inline Math::float4 & Position(const Actor & actor)
            {
                const size_t offset = Get_offset_position(actor);
                auto result = (Math::float4 *) (m_Positions.Data() + offset);

                return *result;
            }

            static inline size_t Get_offset_orientation(const Actor & actor)
            {
                return sizeof(Math::float4) * actor.m_Index;
            }

            inline Math::float4 & Orientation(const Actor & actor)
            {
                const size_t offset = Get_offset_orientation(actor);
                auto result = (Math::float4 *) (m_Orientations.Data() + offset);

                return *result;
            }

            Utility::Binary_data m_Positions;
            Utility::Binary_data m_Orientations;
            RS::Model::Reference * m_Graphics_models;

            uint64 m_Number_of_actors;
        };
    }
}

#endif O8_ENGINE_ACTOR_HPP
