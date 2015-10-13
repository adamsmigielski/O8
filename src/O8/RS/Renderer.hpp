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

#include <Utilities\containers\IntrusiveList.hpp>
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
        class Material;
        class Model;
        class POV;
        class RS;

        struct Entity
        {
            enum Type
            {
                UNKNOWN,
                RENDERABLE,
                LIGHT_SHADOWS,
                LIGHT_NO_SHADOWS,
            };

            Math::float4 m_Position;
            Math::float4 m_Orientation;
        };

        struct Renderable
        {
            Material * m_material;
            Model * m_model;
        };

        struct Light
        {
            
        };

        namespace Renderer_data
        {
            class Change : public Containers::IntrusiveList::Node< Change >
            {
            public:
                enum Type
                {
                    UNKNOWN,
                    ADD,
                    REMOVE,
                };

                Change();
                Change(
                    Type change_type,
                    Entity::Type entity_type, 
                    Entity * entity);

                Type m_change_type;
                Entity::Type m_entity_type;
                Entity * m_entity;
            };

            class Renderable_change : public Change
            {
            public:
                Renderable_change();
                Renderable_change(
                    Type change_type,
                    Entity * entity,
                    Material * material,
                    Model * model);

                Material * m_material;
                Model * m_model;
            };

            class Light_shadows_change : public Change
            {
            public:
                Light_shadows_change();
                Light_shadows_change(
                    );


            };
        }

        class Renderer_data
        {
        public:
            virtual ~Renderer_data();

            virtual Platform::int32 Add_renderable(Entity & entity) = 0;
            virtual Platform::int32 Remove_renderable(Entity & entity) = 0;

            virtual Platform::int32 Add_(Entity & entity) = 0;
            virtual Platform::int32 Remove(Entity & entity) = 0;

            virtual Platform::int32 Add(Entity & entity) = 0;
            virtual Platform::int32 Remove(Entity & entity) = 0;

        protected:
            Renderer_data();
        };

        class Renderer
        {
        public:
            virtual ~Renderer();

            virtual Platform::int32 Init(
                GI::RI * ri);

            virtual Renderer_data * Create_renderer_data() = 0;

            virtual Platform::int32 Render(
                Renderer_data * renderer_data,
                GI::Presentation * presentation,
                POV * pov) = 0;

        protected:
            Renderer();

            GI::RI * m_ri;
        };
    }
}

#endif O8_RS_RENDERER_HPP
