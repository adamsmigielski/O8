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
* @file Asset_importer_FreeType.cpp
**/

#include "PCH.hpp"

#include "Asset_importer_FreeType.hpp"

#include <Utilities\text\Font.hpp>

#include <fstream>

namespace O8
{
    namespace Asset
    {
        Importer_FreeType::Importer_FreeType()
        {
        }

        Importer_FreeType::~Importer_FreeType()
        {
            FT_Done_FreeType(m_library);
        }

        Platform::int32 Importer_FreeType::Init()
        {
            auto err = FT_Init_FreeType(&m_library);
            if (0 != err)
            {
                ERRLOG("Failed to initialize freetype library");
                ASSERT(0);
                return Utilities::Failure;
            }

            return Utilities::Success;
        }

        Platform::int32 get_glyph(
            FT_Face face,
            FT_UInt glyph_index,
            Text::Font::character_t character,
            Text::Font & font)
        {
            Text::Glyph::Descriptor descriptor;
            Memory::Binary_data image;

            auto err = FT_Load_Glyph(
                face,
                glyph_index,
                FT_LOAD_DEFAULT);
            if (0 != err)
            {
                ERRLOG("Failed to load glyph: " << glyph_index);
                ASSERT(0);
                return Utilities::Failed_to_load_model;
            }

            err = FT_Render_Glyph(
                face->glyph,
                FT_RENDER_MODE_NORMAL);
            if (0 != err)
            {
                ERRLOG("Failed to render glyph: " << glyph_index);
                ASSERT(0);
                return Utilities::Failure;
            }

            /* Get descriptor */
            descriptor.m_bottom = (face->glyph->metrics.horiBearingY - face->glyph->metrics.height) >> 6;
            descriptor.m_height = (face->glyph->face->glyph->metrics.height) >> 6;
            descriptor.m_horizontal_advance = (face->glyph->metrics.horiAdvance) >> 6;
            descriptor.m_left = (face->glyph->metrics.horiBearingX) >> 6;
            descriptor.m_right = (face->glyph->metrics.horiBearingX + face->glyph->metrics.width) >> 6;
            descriptor.m_top = (face->glyph->face->glyph->metrics.horiBearingY) >> 6;
            descriptor.m_vertical_advance = (face->glyph->metrics.vertAdvance) >> 6;
            descriptor.m_width = (face->glyph->metrics.width) >> 6;

            /* Get image */
            const size_t img_width = face->glyph->bitmap.width;
            const size_t img_pitch = face->glyph->bitmap.pitch;
            const size_t img_height = face->glyph->bitmap.rows;

            const size_t img_req_mem = img_width * img_height;
            auto img_data = new Platform::uint8[img_req_mem];

            if (nullptr == img_data)
            {
                ASSERT(0);
                return Utilities::Failed_to_allocate_memory;
            }

            image.Reset(img_data, img_req_mem);

            for (size_t row = 0; row < img_height; ++row)
            {
                const auto * src = face->glyph->bitmap.buffer + row * img_pitch;
                auto * dst = img_data + row * img_width;

                memcpy(dst, src, img_width);
            }

            /* Store glyph  */
            auto ret = font.Add_glyph(
                character,
                descriptor,
                std::move(image));
            if (Utilities::Success != ret)
            {
                ASSERT(0);
                return ret;
            }

            /* Done */
            return Utilities::Success;
        }

        Platform::int32 Importer_FreeType::Get_asset(
            const std::string & file_path,
            Memory::Binary_data & out_data,
            Type::Types & out_type)
        {
            FT_Long index = 0;
            FT_Face face = 0;

            /* Parse file_path */
            std::string font_path;
            std::string char_set_path;
            Platform::uint32 dpiX = 0;
            Platform::uint32 dpiY = 0;
            {
                size_t delim[3] = { 0, 0, 0 };
                size_t pos = 0;

                for (size_t i = 0; i < 3; ++i,++pos)
                {
                    pos = file_path.find('|', pos);
                            
                    if (pos == std::string::npos)
                    {
                        ERRLOG("Font resource must contain font_path:char_set_path:dpiX:dpiY. Got " << file_path);
                        return Utilities::Invalid_parameter;
                    }

                    delim[i] = pos;
                }

                const size_t len_font_path(delim[0]);
                const size_t len_char_set_path(delim[1] - delim[0] - 1);

                const char * c_str_font_path = file_path.c_str();
                const char * c_str_char_set_path = file_path.c_str() + delim[0] + 1;
                const char * c_str_dpiX = file_path.c_str() + delim[1] + 1;
                const char * c_str_dpiY = file_path.c_str() + delim[2] + 1;

                dpiY = atoi(c_str_dpiY);
                dpiX = atoi(c_str_dpiX);
                char_set_path = std::string(c_str_char_set_path, len_char_set_path);
                font_path = std::string(c_str_font_path, len_font_path);
            }

            /* Open char set */
            std::fstream char_set_file;
            char_set_file.open(char_set_path, std::fstream::in);
            if (false == char_set_file.is_open())
            {
                ERRLOG("Failed to open char set file: " << char_set_path);
                ASSERT(0);
                return Utilities::Invalid_parameter;
            }

            /* Load face */
            auto err = FT_New_Face(
                m_library,
                font_path.c_str(),
                index,
                &face);
            if (0 != err)
            {
                ERRLOG("Failed to load font: " << font_path);
                ASSERT(0);
                return Utilities::Failure;
            }

            /* Set size */
            err = FT_Set_Char_Size(
                face,
                4608, /*width */
                4608, /* height */
                dpiX,
                dpiY);
            if (0 != err)
            {
                FT_Done_Face(face);

                ERRLOG("Failed to set font size: " << dpiX << "x" << dpiY);
                ASSERT(0);
                return Utilities::Failure;
            }

            /* Load font for selected characters */
            bool is_zero_done = false;
            Text::Font font;
            auto ret = font.Init();
            if (Utilities::Success != ret)
            {
                FT_Done_Face(face);

                ASSERT(0);
                return ret;
            }

            while (false == char_set_file.eof())
            {
                FT_ULong character = 0;

                char_set_file >> character;

                FT_UInt char_index = FT_Get_Char_Index(face, character);

                ret = get_glyph(
                    face,
                    char_index,
                    character,
                    font);
                if (Utilities::Success != ret)
                {
                    FT_Done_Face(face);

                    ASSERT(0);
                    return ret;
                }

                if (0 == character)
                {
                    is_zero_done = true;
                }
            }

            /* Make character 0 available if possible */
            if (false == is_zero_done)
            {
                get_glyph(
                    face,
                    0 /* char_index */,
                    0 /* character */,
                    font);
            }

            /* Store font */
            ret = font.Store(out_data);
            if (Utilities::Success != ret)
            {
                ASSERT(0);
                return ret;
            }
            out_type = O8::Asset::Type::Font;

            /* Done */
            return Utilities::Success;
        }
    }
}

O8::Asset::Importer * Create_importer()
{
    return new O8::Asset::Importer_FreeType;
}

