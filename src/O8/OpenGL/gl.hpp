/** License
 *
 * This file was generated from file gl.xml, which is copyrighted by Khronos Group Inc.
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

#ifndef O8_OPENGL_GL_HPP
#define O8_OPENGL_GL_HPP

namespace O8
{
    namespace OpenGL
    {
        /* Defines */
        #define OPEN_GL_API __stdcall

        /* End of defines */
        /* Typedefs */
        typedef void ( *GLDEBUGPROC)(uint32 source, uint32 type, uint32 id, uint32 severity, int32 length, const char *message, const void *userParam);
        typedef void ( *GLDEBUGPROCARB)(uint32 source, uint32 type, uint32 id, uint32 severity, int32 length, const char *message, const void *userParam);
        typedef void ( *GLDEBUGPROCKHR)(uint32 source, uint32 type, uint32 id, uint32 severity, int32 length, const char *message, const void *userParam);
        typedef void ( *GLDEBUGPROCAMD)(uint32 id, uint32 category, uint32 severity, int32 length, const char *message, void *userParam);

        /* End of typedefs */

        /* GLenums */
        #define GL_DEPTH_BUFFER_BIT                                           0x00000100
        #define GL_STENCIL_BUFFER_BIT                                         0x00000400
        #define GL_COLOR_BUFFER_BIT                                           0x00004000
        #define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT                        0x00000001
        #define GL_CONTEXT_FLAG_DEBUG_BIT                                     0x00000002
        #define GL_CONTEXT_CORE_PROFILE_BIT                                   0x00000001
        #define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT                          0x00000002
        #define GL_MAP_READ_BIT                                               0x0001
        #define GL_MAP_WRITE_BIT                                              0x0002
        #define GL_MAP_INVALIDATE_RANGE_BIT                                   0x0004
        #define GL_MAP_INVALIDATE_BUFFER_BIT                                  0x0008
        #define GL_MAP_FLUSH_EXPLICIT_BIT                                     0x0010
        #define GL_MAP_UNSYNCHRONIZED_BIT                                     0x0020
        #define GL_MAP_PERSISTENT_BIT                                         0x0040
        #define GL_MAP_COHERENT_BIT                                           0x0080
        #define GL_DYNAMIC_STORAGE_BIT                                        0x0100
        #define GL_CLIENT_STORAGE_BIT                                         0x0200
        #define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT                            0x00000001
        #define GL_ELEMENT_ARRAY_BARRIER_BIT                                  0x00000002
        #define GL_UNIFORM_BARRIER_BIT                                        0x00000004
        #define GL_TEXTURE_FETCH_BARRIER_BIT                                  0x00000008
        #define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT                            0x00000020
        #define GL_COMMAND_BARRIER_BIT                                        0x00000040
        #define GL_PIXEL_BUFFER_BARRIER_BIT                                   0x00000080
        #define GL_TEXTURE_UPDATE_BARRIER_BIT                                 0x00000100
        #define GL_BUFFER_UPDATE_BARRIER_BIT                                  0x00000200
        #define GL_FRAMEBUFFER_BARRIER_BIT                                    0x00000400
        #define GL_TRANSFORM_FEEDBACK_BARRIER_BIT                             0x00000800
        #define GL_ATOMIC_COUNTER_BARRIER_BIT                                 0x00001000
        #define GL_SHADER_STORAGE_BARRIER_BIT                                 0x00002000
        #define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT                           0x00004000
        #define GL_QUERY_BUFFER_BARRIER_BIT                                   0x00008000
        #define GL_ALL_BARRIER_BITS                                           0xFFFFFFFF
        #define GL_SYNC_FLUSH_COMMANDS_BIT                                    0x00000001
        #define GL_VERTEX_SHADER_BIT                                          0x00000001
        #define GL_FRAGMENT_SHADER_BIT                                        0x00000002
        #define GL_GEOMETRY_SHADER_BIT                                        0x00000004
        #define GL_TESS_CONTROL_SHADER_BIT                                    0x00000008
        #define GL_TESS_EVALUATION_SHADER_BIT                                 0x00000010
        #define GL_COMPUTE_SHADER_BIT                                         0x00000020
        #define GL_ALL_SHADER_BITS                                            0xFFFFFFFF
        #define GL_FALSE                                                      0
        #define GL_NO_ERROR                                                   0
        #define GL_ZERO                                                       0
        #define GL_NONE                                                       0
        #define GL_TRUE                                                       1
        #define GL_ONE                                                        1
        #define GL_INVALID_INDEX                                              0xFFFFFFFF
        #define GL_TIMEOUT_IGNORED                                            0xFFFFFFFFFFFFFFFF
        #define GL_POINTS                                                     0x0000
        #define GL_LINES                                                      0x0001
        #define GL_LINE_LOOP                                                  0x0002
        #define GL_LINE_STRIP                                                 0x0003
        #define GL_TRIANGLES                                                  0x0004
        #define GL_TRIANGLE_STRIP                                             0x0005
        #define GL_TRIANGLE_FAN                                               0x0006
        #define GL_QUADS                                                      0x0007
        #define GL_LINES_ADJACENCY                                            0x000A
        #define GL_LINE_STRIP_ADJACENCY                                       0x000B
        #define GL_TRIANGLES_ADJACENCY                                        0x000C
        #define GL_TRIANGLE_STRIP_ADJACENCY                                   0x000D
        #define GL_PATCHES                                                    0x000E
        #define GL_NEVER                                                      0x0200
        #define GL_LESS                                                       0x0201
        #define GL_EQUAL                                                      0x0202
        #define GL_LEQUAL                                                     0x0203
        #define GL_GREATER                                                    0x0204
        #define GL_NOTEQUAL                                                   0x0205
        #define GL_GEQUAL                                                     0x0206
        #define GL_ALWAYS                                                     0x0207
        #define GL_SRC_COLOR                                                  0x0300
        #define GL_ONE_MINUS_SRC_COLOR                                        0x0301
        #define GL_SRC_ALPHA                                                  0x0302
        #define GL_ONE_MINUS_SRC_ALPHA                                        0x0303
        #define GL_DST_ALPHA                                                  0x0304
        #define GL_ONE_MINUS_DST_ALPHA                                        0x0305
        #define GL_DST_COLOR                                                  0x0306
        #define GL_ONE_MINUS_DST_COLOR                                        0x0307
        #define GL_SRC_ALPHA_SATURATE                                         0x0308
        #define GL_FRONT_LEFT                                                 0x0400
        #define GL_FRONT_RIGHT                                                0x0401
        #define GL_BACK_LEFT                                                  0x0402
        #define GL_BACK_RIGHT                                                 0x0403
        #define GL_FRONT                                                      0x0404
        #define GL_BACK                                                       0x0405
        #define GL_LEFT                                                       0x0406
        #define GL_RIGHT                                                      0x0407
        #define GL_FRONT_AND_BACK                                             0x0408
        #define GL_INVALID_ENUM                                               0x0500
        #define GL_INVALID_VALUE                                              0x0501
        #define GL_INVALID_OPERATION                                          0x0502
        #define GL_STACK_OVERFLOW                                             0x0503
        #define GL_STACK_UNDERFLOW                                            0x0504
        #define GL_OUT_OF_MEMORY                                              0x0505
        #define GL_INVALID_FRAMEBUFFER_OPERATION                              0x0506
        #define GL_CW                                                         0x0900
        #define GL_CCW                                                        0x0901
        #define GL_POINT_SIZE                                                 0x0B11
        #define GL_POINT_SIZE_RANGE                                           0x0B12
        #define GL_SMOOTH_POINT_SIZE_RANGE                                    0x0B12
        #define GL_POINT_SIZE_GRANULARITY                                     0x0B13
        #define GL_SMOOTH_POINT_SIZE_GRANULARITY                              0x0B13
        #define GL_LINE_SMOOTH                                                0x0B20
        #define GL_LINE_WIDTH                                                 0x0B21
        #define GL_LINE_WIDTH_RANGE                                           0x0B22
        #define GL_SMOOTH_LINE_WIDTH_RANGE                                    0x0B22
        #define GL_LINE_WIDTH_GRANULARITY                                     0x0B23
        #define GL_SMOOTH_LINE_WIDTH_GRANULARITY                              0x0B23
        #define GL_POLYGON_MODE                                               0x0B40
        #define GL_POLYGON_SMOOTH                                             0x0B41
        #define GL_CULL_FACE                                                  0x0B44
        #define GL_CULL_FACE_MODE                                             0x0B45
        #define GL_FRONT_FACE                                                 0x0B46
        #define GL_DEPTH_RANGE                                                0x0B70
        #define GL_DEPTH_TEST                                                 0x0B71
        #define GL_DEPTH_WRITEMASK                                            0x0B72
        #define GL_DEPTH_CLEAR_VALUE                                          0x0B73
        #define GL_DEPTH_FUNC                                                 0x0B74
        #define GL_STENCIL_TEST                                               0x0B90
        #define GL_STENCIL_CLEAR_VALUE                                        0x0B91
        #define GL_STENCIL_FUNC                                               0x0B92
        #define GL_STENCIL_VALUE_MASK                                         0x0B93
        #define GL_STENCIL_FAIL                                               0x0B94
        #define GL_STENCIL_PASS_DEPTH_FAIL                                    0x0B95
        #define GL_STENCIL_PASS_DEPTH_PASS                                    0x0B96
        #define GL_STENCIL_REF                                                0x0B97
        #define GL_STENCIL_WRITEMASK                                          0x0B98
        #define GL_VIEWPORT                                                   0x0BA2
        #define GL_DITHER                                                     0x0BD0
        #define GL_BLEND_DST                                                  0x0BE0
        #define GL_BLEND_SRC                                                  0x0BE1
        #define GL_BLEND                                                      0x0BE2
        #define GL_LOGIC_OP_MODE                                              0x0BF0
        #define GL_COLOR_LOGIC_OP                                             0x0BF2
        #define GL_DRAW_BUFFER                                                0x0C01
        #define GL_READ_BUFFER                                                0x0C02
        #define GL_SCISSOR_BOX                                                0x0C10
        #define GL_SCISSOR_TEST                                               0x0C11
        #define GL_COLOR_CLEAR_VALUE                                          0x0C22
        #define GL_COLOR_WRITEMASK                                            0x0C23
        #define GL_DOUBLEBUFFER                                               0x0C32
        #define GL_STEREO                                                     0x0C33
        #define GL_LINE_SMOOTH_HINT                                           0x0C52
        #define GL_POLYGON_SMOOTH_HINT                                        0x0C53
        #define GL_UNPACK_SWAP_BYTES                                          0x0CF0
        #define GL_UNPACK_LSB_FIRST                                           0x0CF1
        #define GL_UNPACK_ROW_LENGTH                                          0x0CF2
        #define GL_UNPACK_SKIP_ROWS                                           0x0CF3
        #define GL_UNPACK_SKIP_PIXELS                                         0x0CF4
        #define GL_UNPACK_ALIGNMENT                                           0x0CF5
        #define GL_PACK_SWAP_BYTES                                            0x0D00
        #define GL_PACK_LSB_FIRST                                             0x0D01
        #define GL_PACK_ROW_LENGTH                                            0x0D02
        #define GL_PACK_SKIP_ROWS                                             0x0D03
        #define GL_PACK_SKIP_PIXELS                                           0x0D04
        #define GL_PACK_ALIGNMENT                                             0x0D05
        #define GL_MAX_CLIP_DISTANCES                                         0x0D32
        #define GL_MAX_TEXTURE_SIZE                                           0x0D33
        #define GL_MAX_VIEWPORT_DIMS                                          0x0D3A
        #define GL_SUBPIXEL_BITS                                              0x0D50
        #define GL_TEXTURE_1D                                                 0x0DE0
        #define GL_TEXTURE_2D                                                 0x0DE1
        #define GL_TEXTURE_WIDTH                                              0x1000
        #define GL_TEXTURE_HEIGHT                                             0x1001
        #define GL_TEXTURE_INTERNAL_FORMAT                                    0x1003
        #define GL_TEXTURE_BORDER_COLOR                                       0x1004
        #define GL_TEXTURE_TARGET                                             0x1006
        #define GL_DONT_CARE                                                  0x1100
        #define GL_FASTEST                                                    0x1101
        #define GL_NICEST                                                     0x1102
        #define GL_BYTE                                                       0x1400
        #define GL_UNSIGNED_BYTE                                              0x1401
        #define GL_SHORT                                                      0x1402
        #define GL_UNSIGNED_SHORT                                             0x1403
        #define GL_INT                                                        0x1404
        #define GL_UNSIGNED_INT                                               0x1405
        #define GL_FLOAT                                                      0x1406
        #define GL_DOUBLE                                                     0x140A
        #define GL_HALF_FLOAT                                                 0x140B
        #define GL_FIXED                                                      0x140C
        #define GL_CLEAR                                                      0x1500
        #define GL_AND                                                        0x1501
        #define GL_AND_REVERSE                                                0x1502
        #define GL_COPY                                                       0x1503
        #define GL_AND_INVERTED                                               0x1504
        #define GL_NOOP                                                       0x1505
        #define GL_XOR                                                        0x1506
        #define GL_OR                                                         0x1507
        #define GL_NOR                                                        0x1508
        #define GL_EQUIV                                                      0x1509
        #define GL_INVERT                                                     0x150A
        #define GL_OR_REVERSE                                                 0x150B
        #define GL_COPY_INVERTED                                              0x150C
        #define GL_OR_INVERTED                                                0x150D
        #define GL_NAND                                                       0x150E
        #define GL_SET                                                        0x150F
        #define GL_TEXTURE                                                    0x1702
        #define GL_COLOR                                                      0x1800
        #define GL_DEPTH                                                      0x1801
        #define GL_STENCIL                                                    0x1802
        #define GL_STENCIL_INDEX                                              0x1901
        #define GL_DEPTH_COMPONENT                                            0x1902
        #define GL_RED                                                        0x1903
        #define GL_GREEN                                                      0x1904
        #define GL_BLUE                                                       0x1905
        #define GL_ALPHA                                                      0x1906
        #define GL_RGB                                                        0x1907
        #define GL_RGBA                                                       0x1908
        #define GL_POINT                                                      0x1B00
        #define GL_LINE                                                       0x1B01
        #define GL_FILL                                                       0x1B02
        #define GL_KEEP                                                       0x1E00
        #define GL_REPLACE                                                    0x1E01
        #define GL_INCR                                                       0x1E02
        #define GL_DECR                                                       0x1E03
        #define GL_VENDOR                                                     0x1F00
        #define GL_RENDERER                                                   0x1F01
        #define GL_VERSION                                                    0x1F02
        #define GL_EXTENSIONS                                                 0x1F03
        #define GL_NEAREST                                                    0x2600
        #define GL_LINEAR                                                     0x2601
        #define GL_NEAREST_MIPMAP_NEAREST                                     0x2700
        #define GL_LINEAR_MIPMAP_NEAREST                                      0x2701
        #define GL_NEAREST_MIPMAP_LINEAR                                      0x2702
        #define GL_LINEAR_MIPMAP_LINEAR                                       0x2703
        #define GL_TEXTURE_MAG_FILTER                                         0x2800
        #define GL_TEXTURE_MIN_FILTER                                         0x2801
        #define GL_TEXTURE_WRAP_S                                             0x2802
        #define GL_TEXTURE_WRAP_T                                             0x2803
        #define GL_REPEAT                                                     0x2901
        #define GL_POLYGON_OFFSET_UNITS                                       0x2A00
        #define GL_POLYGON_OFFSET_POINT                                       0x2A01
        #define GL_POLYGON_OFFSET_LINE                                        0x2A02
        #define GL_R3_G3_B2                                                   0x2A10
        #define GL_CLIP_DISTANCE0                                             0x3000
        #define GL_CLIP_DISTANCE1                                             0x3001
        #define GL_CLIP_DISTANCE2                                             0x3002
        #define GL_CLIP_DISTANCE3                                             0x3003
        #define GL_CLIP_DISTANCE4                                             0x3004
        #define GL_CLIP_DISTANCE5                                             0x3005
        #define GL_CLIP_DISTANCE6                                             0x3006
        #define GL_CLIP_DISTANCE7                                             0x3007
        #define GL_CONSTANT_COLOR                                             0x8001
        #define GL_ONE_MINUS_CONSTANT_COLOR                                   0x8002
        #define GL_CONSTANT_ALPHA                                             0x8003
        #define GL_ONE_MINUS_CONSTANT_ALPHA                                   0x8004
        #define GL_FUNC_ADD                                                   0x8006
        #define GL_MIN                                                        0x8007
        #define GL_MAX                                                        0x8008
        #define GL_BLEND_EQUATION_RGB                                         0x8009
        #define GL_FUNC_SUBTRACT                                              0x800A
        #define GL_FUNC_REVERSE_SUBTRACT                                      0x800B
        #define GL_UNSIGNED_BYTE_3_3_2                                        0x8032
        #define GL_UNSIGNED_SHORT_4_4_4_4                                     0x8033
        #define GL_UNSIGNED_SHORT_5_5_5_1                                     0x8034
        #define GL_UNSIGNED_INT_8_8_8_8                                       0x8035
        #define GL_UNSIGNED_INT_10_10_10_2                                    0x8036
        #define GL_POLYGON_OFFSET_FILL                                        0x8037
        #define GL_POLYGON_OFFSET_FACTOR                                      0x8038
        #define GL_RGB4                                                       0x804F
        #define GL_RGB5                                                       0x8050
        #define GL_RGB8                                                       0x8051
        #define GL_RGB10                                                      0x8052
        #define GL_RGB12                                                      0x8053
        #define GL_RGB16                                                      0x8054
        #define GL_RGBA2                                                      0x8055
        #define GL_RGBA4                                                      0x8056
        #define GL_RGB5_A1                                                    0x8057
        #define GL_RGBA8                                                      0x8058
        #define GL_RGB10_A2                                                   0x8059
        #define GL_RGBA12                                                     0x805A
        #define GL_RGBA16                                                     0x805B
        #define GL_TEXTURE_RED_SIZE                                           0x805C
        #define GL_TEXTURE_GREEN_SIZE                                         0x805D
        #define GL_TEXTURE_BLUE_SIZE                                          0x805E
        #define GL_TEXTURE_ALPHA_SIZE                                         0x805F
        #define GL_PROXY_TEXTURE_1D                                           0x8063
        #define GL_PROXY_TEXTURE_2D                                           0x8064
        #define GL_TEXTURE_BINDING_1D                                         0x8068
        #define GL_TEXTURE_BINDING_2D                                         0x8069
        #define GL_TEXTURE_BINDING_3D                                         0x806A
        #define GL_PACK_SKIP_IMAGES                                           0x806B
        #define GL_PACK_IMAGE_HEIGHT                                          0x806C
        #define GL_UNPACK_SKIP_IMAGES                                         0x806D
        #define GL_UNPACK_IMAGE_HEIGHT                                        0x806E
        #define GL_TEXTURE_3D                                                 0x806F
        #define GL_PROXY_TEXTURE_3D                                           0x8070
        #define GL_TEXTURE_DEPTH                                              0x8071
        #define GL_TEXTURE_WRAP_R                                             0x8072
        #define GL_MAX_3D_TEXTURE_SIZE                                        0x8073
        #define GL_VERTEX_ARRAY                                               0x8074
        #define GL_MULTISAMPLE                                                0x809D
        #define GL_SAMPLE_ALPHA_TO_COVERAGE                                   0x809E
        #define GL_SAMPLE_ALPHA_TO_ONE                                        0x809F
        #define GL_SAMPLE_COVERAGE                                            0x80A0
        #define GL_SAMPLE_BUFFERS                                             0x80A8
        #define GL_SAMPLES                                                    0x80A9
        #define GL_SAMPLE_COVERAGE_VALUE                                      0x80AA
        #define GL_SAMPLE_COVERAGE_INVERT                                     0x80AB
        #define GL_BLEND_DST_RGB                                              0x80C8
        #define GL_BLEND_SRC_RGB                                              0x80C9
        #define GL_BLEND_DST_ALPHA                                            0x80CA
        #define GL_BLEND_SRC_ALPHA                                            0x80CB
        #define GL_BGR                                                        0x80E0
        #define GL_BGRA                                                       0x80E1
        #define GL_MAX_ELEMENTS_VERTICES                                      0x80E8
        #define GL_MAX_ELEMENTS_INDICES                                       0x80E9
        #define GL_POINT_FADE_THRESHOLD_SIZE                                  0x8128
        #define GL_CLAMP_TO_BORDER                                            0x812D
        #define GL_CLAMP_TO_EDGE                                              0x812F
        #define GL_TEXTURE_MIN_LOD                                            0x813A
        #define GL_TEXTURE_MAX_LOD                                            0x813B
        #define GL_TEXTURE_BASE_LEVEL                                         0x813C
        #define GL_TEXTURE_MAX_LEVEL                                          0x813D
        #define GL_DEPTH_COMPONENT16                                          0x81A5
        #define GL_DEPTH_COMPONENT24                                          0x81A6
        #define GL_DEPTH_COMPONENT32                                          0x81A7
        #define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING                      0x8210
        #define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE                      0x8211
        #define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE                            0x8212
        #define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE                          0x8213
        #define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE                           0x8214
        #define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE                          0x8215
        #define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE                          0x8216
        #define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE                        0x8217
        #define GL_FRAMEBUFFER_DEFAULT                                        0x8218
        #define GL_FRAMEBUFFER_UNDEFINED                                      0x8219
        #define GL_DEPTH_STENCIL_ATTACHMENT                                   0x821A
        #define GL_MAJOR_VERSION                                              0x821B
        #define GL_MINOR_VERSION                                              0x821C
        #define GL_NUM_EXTENSIONS                                             0x821D
        #define GL_CONTEXT_FLAGS                                              0x821E
        #define GL_BUFFER_IMMUTABLE_STORAGE                                   0x821F
        #define GL_BUFFER_STORAGE_FLAGS                                       0x8220
        #define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED                    0x8221
        #define GL_INDEX                                                      0x8222
        #define GL_COMPRESSED_RED                                             0x8225
        #define GL_COMPRESSED_RG                                              0x8226
        #define GL_RG                                                         0x8227
        #define GL_RG_INTEGER                                                 0x8228
        #define GL_R8                                                         0x8229
        #define GL_R16                                                        0x822A
        #define GL_RG8                                                        0x822B
        #define GL_RG16                                                       0x822C
        #define GL_R16F                                                       0x822D
        #define GL_R32F                                                       0x822E
        #define GL_RG16F                                                      0x822F
        #define GL_RG32F                                                      0x8230
        #define GL_R8I                                                        0x8231
        #define GL_R8UI                                                       0x8232
        #define GL_R16I                                                       0x8233
        #define GL_R16UI                                                      0x8234
        #define GL_R32I                                                       0x8235
        #define GL_R32UI                                                      0x8236
        #define GL_RG8I                                                       0x8237
        #define GL_RG8UI                                                      0x8238
        #define GL_RG16I                                                      0x8239
        #define GL_RG16UI                                                     0x823A
        #define GL_RG32I                                                      0x823B
        #define GL_RG32UI                                                     0x823C
        #define GL_DEBUG_OUTPUT_SYNCHRONOUS                                   0x8242
        #define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH                           0x8243
        #define GL_DEBUG_CALLBACK_FUNCTION                                    0x8244
        #define GL_DEBUG_CALLBACK_USER_PARAM                                  0x8245
        #define GL_DEBUG_SOURCE_API                                           0x8246
        #define GL_DEBUG_SOURCE_WINDOW_SYSTEM                                 0x8247
        #define GL_DEBUG_SOURCE_SHADER_COMPILER                               0x8248
        #define GL_DEBUG_SOURCE_THIRD_PARTY                                   0x8249
        #define GL_DEBUG_SOURCE_APPLICATION                                   0x824A
        #define GL_DEBUG_SOURCE_OTHER                                         0x824B
        #define GL_DEBUG_TYPE_ERROR                                           0x824C
        #define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR                             0x824D
        #define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR                              0x824E
        #define GL_DEBUG_TYPE_PORTABILITY                                     0x824F
        #define GL_DEBUG_TYPE_PERFORMANCE                                     0x8250
        #define GL_DEBUG_TYPE_OTHER                                           0x8251
        #define GL_PROGRAM_BINARY_RETRIEVABLE_HINT                            0x8257
        #define GL_PROGRAM_SEPARABLE                                          0x8258
        #define GL_ACTIVE_PROGRAM                                             0x8259
        #define GL_PROGRAM_PIPELINE_BINDING                                   0x825A
        #define GL_MAX_VIEWPORTS                                              0x825B
        #define GL_VIEWPORT_SUBPIXEL_BITS                                     0x825C
        #define GL_VIEWPORT_BOUNDS_RANGE                                      0x825D
        #define GL_LAYER_PROVOKING_VERTEX                                     0x825E
        #define GL_VIEWPORT_INDEX_PROVOKING_VERTEX                            0x825F
        #define GL_UNDEFINED_VERTEX                                           0x8260
        #define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE                             0x8262
        #define GL_MAX_COMPUTE_UNIFORM_COMPONENTS                             0x8263
        #define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS                         0x8264
        #define GL_MAX_COMPUTE_ATOMIC_COUNTERS                                0x8265
        #define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS                    0x8266
        #define GL_COMPUTE_WORK_GROUP_SIZE                                    0x8267
        #define GL_DEBUG_TYPE_MARKER                                          0x8268
        #define GL_DEBUG_TYPE_PUSH_GROUP                                      0x8269
        #define GL_DEBUG_TYPE_POP_GROUP                                       0x826A
        #define GL_DEBUG_SEVERITY_NOTIFICATION                                0x826B
        #define GL_MAX_DEBUG_GROUP_STACK_DEPTH                                0x826C
        #define GL_DEBUG_GROUP_STACK_DEPTH                                    0x826D
        #define GL_MAX_UNIFORM_LOCATIONS                                      0x826E
        #define GL_INTERNALFORMAT_SUPPORTED                                   0x826F
        #define GL_INTERNALFORMAT_PREFERRED                                   0x8270
        #define GL_INTERNALFORMAT_RED_SIZE                                    0x8271
        #define GL_INTERNALFORMAT_GREEN_SIZE                                  0x8272
        #define GL_INTERNALFORMAT_BLUE_SIZE                                   0x8273
        #define GL_INTERNALFORMAT_ALPHA_SIZE                                  0x8274
        #define GL_INTERNALFORMAT_DEPTH_SIZE                                  0x8275
        #define GL_INTERNALFORMAT_STENCIL_SIZE                                0x8276
        #define GL_INTERNALFORMAT_SHARED_SIZE                                 0x8277
        #define GL_INTERNALFORMAT_RED_TYPE                                    0x8278
        #define GL_INTERNALFORMAT_GREEN_TYPE                                  0x8279
        #define GL_INTERNALFORMAT_BLUE_TYPE                                   0x827A
        #define GL_INTERNALFORMAT_ALPHA_TYPE                                  0x827B
        #define GL_INTERNALFORMAT_DEPTH_TYPE                                  0x827C
        #define GL_INTERNALFORMAT_STENCIL_TYPE                                0x827D
        #define GL_MAX_WIDTH                                                  0x827E
        #define GL_MAX_HEIGHT                                                 0x827F
        #define GL_MAX_DEPTH                                                  0x8280
        #define GL_MAX_LAYERS                                                 0x8281
        #define GL_MAX_COMBINED_DIMENSIONS                                    0x8282
        #define GL_COLOR_COMPONENTS                                           0x8283
        #define GL_DEPTH_COMPONENTS                                           0x8284
        #define GL_STENCIL_COMPONENTS                                         0x8285
        #define GL_COLOR_RENDERABLE                                           0x8286
        #define GL_DEPTH_RENDERABLE                                           0x8287
        #define GL_STENCIL_RENDERABLE                                         0x8288
        #define GL_FRAMEBUFFER_RENDERABLE                                     0x8289
        #define GL_FRAMEBUFFER_RENDERABLE_LAYERED                             0x828A
        #define GL_FRAMEBUFFER_BLEND                                          0x828B
        #define GL_READ_PIXELS                                                0x828C
        #define GL_READ_PIXELS_FORMAT                                         0x828D
        #define GL_READ_PIXELS_TYPE                                           0x828E
        #define GL_TEXTURE_IMAGE_FORMAT                                       0x828F
        #define GL_TEXTURE_IMAGE_TYPE                                         0x8290
        #define GL_GET_TEXTURE_IMAGE_FORMAT                                   0x8291
        #define GL_GET_TEXTURE_IMAGE_TYPE                                     0x8292
        #define GL_MIPMAP                                                     0x8293
        #define GL_MANUAL_GENERATE_MIPMAP                                     0x8294
        #define GL_AUTO_GENERATE_MIPMAP                                       0x8295
        #define GL_COLOR_ENCODING                                             0x8296
        #define GL_SRGB_READ                                                  0x8297
        #define GL_SRGB_WRITE                                                 0x8298
        #define GL_FILTER                                                     0x829A
        #define GL_VERTEX_TEXTURE                                             0x829B
        #define GL_TESS_CONTROL_TEXTURE                                       0x829C
        #define GL_TESS_EVALUATION_TEXTURE                                    0x829D
        #define GL_GEOMETRY_TEXTURE                                           0x829E
        #define GL_FRAGMENT_TEXTURE                                           0x829F
        #define GL_COMPUTE_TEXTURE                                            0x82A0
        #define GL_TEXTURE_SHADOW                                             0x82A1
        #define GL_TEXTURE_GATHER                                             0x82A2
        #define GL_TEXTURE_GATHER_SHADOW                                      0x82A3
        #define GL_SHADER_IMAGE_LOAD                                          0x82A4
        #define GL_SHADER_IMAGE_STORE                                         0x82A5
        #define GL_SHADER_IMAGE_ATOMIC                                        0x82A6
        #define GL_IMAGE_TEXEL_SIZE                                           0x82A7
        #define GL_IMAGE_COMPATIBILITY_CLASS                                  0x82A8
        #define GL_IMAGE_PIXEL_FORMAT                                         0x82A9
        #define GL_IMAGE_PIXEL_TYPE                                           0x82AA
        #define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST                        0x82AC
        #define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST                      0x82AD
        #define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE                       0x82AE
        #define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE                     0x82AF
        #define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH                             0x82B1
        #define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT                            0x82B2
        #define GL_TEXTURE_COMPRESSED_BLOCK_SIZE                              0x82B3
        #define GL_CLEAR_BUFFER                                               0x82B4
        #define GL_TEXTURE_VIEW                                               0x82B5
        #define GL_VIEW_COMPATIBILITY_CLASS                                   0x82B6
        #define GL_FULL_SUPPORT                                               0x82B7
        #define GL_CAVEAT_SUPPORT                                             0x82B8
        #define GL_IMAGE_CLASS_4_X_32                                         0x82B9
        #define GL_IMAGE_CLASS_2_X_32                                         0x82BA
        #define GL_IMAGE_CLASS_1_X_32                                         0x82BB
        #define GL_IMAGE_CLASS_4_X_16                                         0x82BC
        #define GL_IMAGE_CLASS_2_X_16                                         0x82BD
        #define GL_IMAGE_CLASS_1_X_16                                         0x82BE
        #define GL_IMAGE_CLASS_4_X_8                                          0x82BF
        #define GL_IMAGE_CLASS_2_X_8                                          0x82C0
        #define GL_IMAGE_CLASS_1_X_8                                          0x82C1
        #define GL_IMAGE_CLASS_11_11_10                                       0x82C2
        #define GL_IMAGE_CLASS_10_10_10_2                                     0x82C3
        #define GL_VIEW_CLASS_128_BITS                                        0x82C4
        #define GL_VIEW_CLASS_96_BITS                                         0x82C5
        #define GL_VIEW_CLASS_64_BITS                                         0x82C6
        #define GL_VIEW_CLASS_48_BITS                                         0x82C7
        #define GL_VIEW_CLASS_32_BITS                                         0x82C8
        #define GL_VIEW_CLASS_24_BITS                                         0x82C9
        #define GL_VIEW_CLASS_16_BITS                                         0x82CA
        #define GL_VIEW_CLASS_8_BITS                                          0x82CB
        #define GL_VIEW_CLASS_S3TC_DXT1_RGB                                   0x82CC
        #define GL_VIEW_CLASS_S3TC_DXT1_RGBA                                  0x82CD
        #define GL_VIEW_CLASS_S3TC_DXT3_RGBA                                  0x82CE
        #define GL_VIEW_CLASS_S3TC_DXT5_RGBA                                  0x82CF
        #define GL_VIEW_CLASS_RGTC1_RED                                       0x82D0
        #define GL_VIEW_CLASS_RGTC2_RG                                        0x82D1
        #define GL_VIEW_CLASS_BPTC_UNORM                                      0x82D2
        #define GL_VIEW_CLASS_BPTC_FLOAT                                      0x82D3
        #define GL_VERTEX_ATTRIB_BINDING                                      0x82D4
        #define GL_VERTEX_ATTRIB_RELATIVE_OFFSET                              0x82D5
        #define GL_VERTEX_BINDING_DIVISOR                                     0x82D6
        #define GL_VERTEX_BINDING_OFFSET                                      0x82D7
        #define GL_VERTEX_BINDING_STRIDE                                      0x82D8
        #define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET                          0x82D9
        #define GL_MAX_VERTEX_ATTRIB_BINDINGS                                 0x82DA
        #define GL_TEXTURE_VIEW_MIN_LEVEL                                     0x82DB
        #define GL_TEXTURE_VIEW_NUM_LEVELS                                    0x82DC
        #define GL_TEXTURE_VIEW_MIN_LAYER                                     0x82DD
        #define GL_TEXTURE_VIEW_NUM_LAYERS                                    0x82DE
        #define GL_TEXTURE_IMMUTABLE_LEVELS                                   0x82DF
        #define GL_BUFFER                                                     0x82E0
        #define GL_SHADER                                                     0x82E1
        #define GL_PROGRAM                                                    0x82E2
        #define GL_QUERY                                                      0x82E3
        #define GL_PROGRAM_PIPELINE                                           0x82E4
        #define GL_MAX_VERTEX_ATTRIB_STRIDE                                   0x82E5
        #define GL_SAMPLER                                                    0x82E6
        #define GL_DISPLAY_LIST                                               0x82E7
        #define GL_MAX_LABEL_LENGTH                                           0x82E8
        #define GL_NUM_SHADING_LANGUAGE_VERSIONS                              0x82E9
        #define GL_QUERY_TARGET                                               0x82EA
        #define GL_TEXTURE_BINDING                                            0x82EB
        #define GL_UNSIGNED_BYTE_2_3_3_REV                                    0x8362
        #define GL_UNSIGNED_SHORT_5_6_5                                       0x8363
        #define GL_UNSIGNED_SHORT_5_6_5_REV                                   0x8364
        #define GL_UNSIGNED_SHORT_4_4_4_4_REV                                 0x8365
        #define GL_UNSIGNED_SHORT_1_5_5_5_REV                                 0x8366
        #define GL_UNSIGNED_INT_8_8_8_8_REV                                   0x8367
        #define GL_UNSIGNED_INT_2_10_10_10_REV                                0x8368
        #define GL_MIRRORED_REPEAT                                            0x8370
        #define GL_ALIASED_LINE_WIDTH_RANGE                                   0x846E
        #define GL_TEXTURE0                                                   0x84C0
        #define GL_TEXTURE1                                                   0x84C1
        #define GL_TEXTURE2                                                   0x84C2
        #define GL_TEXTURE3                                                   0x84C3
        #define GL_TEXTURE4                                                   0x84C4
        #define GL_TEXTURE5                                                   0x84C5
        #define GL_TEXTURE6                                                   0x84C6
        #define GL_TEXTURE7                                                   0x84C7
        #define GL_TEXTURE8                                                   0x84C8
        #define GL_TEXTURE9                                                   0x84C9
        #define GL_TEXTURE10                                                  0x84CA
        #define GL_TEXTURE11                                                  0x84CB
        #define GL_TEXTURE12                                                  0x84CC
        #define GL_TEXTURE13                                                  0x84CD
        #define GL_TEXTURE14                                                  0x84CE
        #define GL_TEXTURE15                                                  0x84CF
        #define GL_TEXTURE16                                                  0x84D0
        #define GL_TEXTURE17                                                  0x84D1
        #define GL_TEXTURE18                                                  0x84D2
        #define GL_TEXTURE19                                                  0x84D3
        #define GL_TEXTURE20                                                  0x84D4
        #define GL_TEXTURE21                                                  0x84D5
        #define GL_TEXTURE22                                                  0x84D6
        #define GL_TEXTURE23                                                  0x84D7
        #define GL_TEXTURE24                                                  0x84D8
        #define GL_TEXTURE25                                                  0x84D9
        #define GL_TEXTURE26                                                  0x84DA
        #define GL_TEXTURE27                                                  0x84DB
        #define GL_TEXTURE28                                                  0x84DC
        #define GL_TEXTURE29                                                  0x84DD
        #define GL_TEXTURE30                                                  0x84DE
        #define GL_TEXTURE31                                                  0x84DF
        #define GL_ACTIVE_TEXTURE                                             0x84E0
        #define GL_MAX_RENDERBUFFER_SIZE                                      0x84E8
        #define GL_COMPRESSED_RGB                                             0x84ED
        #define GL_COMPRESSED_RGBA                                            0x84EE
        #define GL_TEXTURE_COMPRESSION_HINT                                   0x84EF
        #define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER            0x84F0
        #define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER         0x84F1
        #define GL_TEXTURE_RECTANGLE                                          0x84F5
        #define GL_TEXTURE_BINDING_RECTANGLE                                  0x84F6
        #define GL_PROXY_TEXTURE_RECTANGLE                                    0x84F7
        #define GL_MAX_RECTANGLE_TEXTURE_SIZE                                 0x84F8
        #define GL_DEPTH_STENCIL                                              0x84F9
        #define GL_UNSIGNED_INT_24_8                                          0x84FA
        #define GL_MAX_TEXTURE_LOD_BIAS                                       0x84FD
        #define GL_TEXTURE_LOD_BIAS                                           0x8501
        #define GL_INCR_WRAP                                                  0x8507
        #define GL_DECR_WRAP                                                  0x8508
        #define GL_TEXTURE_CUBE_MAP                                           0x8513
        #define GL_TEXTURE_BINDING_CUBE_MAP                                   0x8514
        #define GL_TEXTURE_CUBE_MAP_POSITIVE_X                                0x8515
        #define GL_TEXTURE_CUBE_MAP_NEGATIVE_X                                0x8516
        #define GL_TEXTURE_CUBE_MAP_POSITIVE_Y                                0x8517
        #define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y                                0x8518
        #define GL_TEXTURE_CUBE_MAP_POSITIVE_Z                                0x8519
        #define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z                                0x851A
        #define GL_PROXY_TEXTURE_CUBE_MAP                                     0x851B
        #define GL_MAX_CUBE_MAP_TEXTURE_SIZE                                  0x851C
        #define GL_SRC1_ALPHA                                                 0x8589
        #define GL_VERTEX_ARRAY_BINDING                                       0x85B5
        #define GL_VERTEX_ATTRIB_ARRAY_ENABLED                                0x8622
        #define GL_VERTEX_ATTRIB_ARRAY_SIZE                                   0x8623
        #define GL_VERTEX_ATTRIB_ARRAY_STRIDE                                 0x8624
        #define GL_VERTEX_ATTRIB_ARRAY_TYPE                                   0x8625
        #define GL_CURRENT_VERTEX_ATTRIB                                      0x8626
        #define GL_VERTEX_PROGRAM_POINT_SIZE                                  0x8642
        #define GL_PROGRAM_POINT_SIZE                                         0x8642
        #define GL_VERTEX_ATTRIB_ARRAY_POINTER                                0x8645
        #define GL_DEPTH_CLAMP                                                0x864F
        #define GL_TEXTURE_COMPRESSED_IMAGE_SIZE                              0x86A0
        #define GL_TEXTURE_COMPRESSED                                         0x86A1
        #define GL_NUM_COMPRESSED_TEXTURE_FORMATS                             0x86A2
        #define GL_COMPRESSED_TEXTURE_FORMATS                                 0x86A3
        #define GL_PROGRAM_BINARY_LENGTH                                      0x8741
        #define GL_MIRROR_CLAMP_TO_EDGE                                       0x8743
        #define GL_VERTEX_ATTRIB_ARRAY_LONG                                   0x874E
        #define GL_BUFFER_SIZE                                                0x8764
        #define GL_BUFFER_USAGE                                               0x8765
        #define GL_NUM_PROGRAM_BINARY_FORMATS                                 0x87FE
        #define GL_PROGRAM_BINARY_FORMATS                                     0x87FF
        #define GL_STENCIL_BACK_FUNC                                          0x8800
        #define GL_STENCIL_BACK_FAIL                                          0x8801
        #define GL_STENCIL_BACK_PASS_DEPTH_FAIL                               0x8802
        #define GL_STENCIL_BACK_PASS_DEPTH_PASS                               0x8803
        #define GL_RGBA32F                                                    0x8814
        #define GL_RGB32F                                                     0x8815
        #define GL_RGBA16F                                                    0x881A
        #define GL_RGB16F                                                     0x881B
        #define GL_MAX_DRAW_BUFFERS                                           0x8824
        #define GL_DRAW_BUFFER0                                               0x8825
        #define GL_DRAW_BUFFER1                                               0x8826
        #define GL_DRAW_BUFFER2                                               0x8827
        #define GL_DRAW_BUFFER3                                               0x8828
        #define GL_DRAW_BUFFER4                                               0x8829
        #define GL_DRAW_BUFFER5                                               0x882A
        #define GL_DRAW_BUFFER6                                               0x882B
        #define GL_DRAW_BUFFER7                                               0x882C
        #define GL_DRAW_BUFFER8                                               0x882D
        #define GL_DRAW_BUFFER9                                               0x882E
        #define GL_DRAW_BUFFER10                                              0x882F
        #define GL_DRAW_BUFFER11                                              0x8830
        #define GL_DRAW_BUFFER12                                              0x8831
        #define GL_DRAW_BUFFER13                                              0x8832
        #define GL_DRAW_BUFFER14                                              0x8833
        #define GL_DRAW_BUFFER15                                              0x8834
        #define GL_BLEND_EQUATION_ALPHA                                       0x883D
        #define GL_TEXTURE_DEPTH_SIZE                                         0x884A
        #define GL_TEXTURE_COMPARE_MODE                                       0x884C
        #define GL_TEXTURE_COMPARE_FUNC                                       0x884D
        #define GL_COMPARE_REF_TO_TEXTURE                                     0x884E
        #define GL_TEXTURE_CUBE_MAP_SEAMLESS                                  0x884F
        #define GL_QUERY_COUNTER_BITS                                         0x8864
        #define GL_CURRENT_QUERY                                              0x8865
        #define GL_QUERY_RESULT                                               0x8866
        #define GL_QUERY_RESULT_AVAILABLE                                     0x8867
        #define GL_MAX_VERTEX_ATTRIBS                                         0x8869
        #define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED                             0x886A
        #define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS                          0x886C
        #define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS                       0x886D
        #define GL_MAX_TEXTURE_IMAGE_UNITS                                    0x8872
        #define GL_GEOMETRY_SHADER_INVOCATIONS                                0x887F
        #define GL_ARRAY_BUFFER                                               0x8892
        #define GL_ELEMENT_ARRAY_BUFFER                                       0x8893
        #define GL_ARRAY_BUFFER_BINDING                                       0x8894
        #define GL_ELEMENT_ARRAY_BUFFER_BINDING                               0x8895
        #define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING                         0x889F
        #define GL_READ_ONLY                                                  0x88B8
        #define GL_WRITE_ONLY                                                 0x88B9
        #define GL_READ_WRITE                                                 0x88BA
        #define GL_BUFFER_ACCESS                                              0x88BB
        #define GL_BUFFER_MAPPED                                              0x88BC
        #define GL_BUFFER_MAP_POINTER                                         0x88BD
        #define GL_TIME_ELAPSED                                               0x88BF
        #define GL_STREAM_DRAW                                                0x88E0
        #define GL_STREAM_READ                                                0x88E1
        #define GL_STREAM_COPY                                                0x88E2
        #define GL_STATIC_DRAW                                                0x88E4
        #define GL_STATIC_READ                                                0x88E5
        #define GL_STATIC_COPY                                                0x88E6
        #define GL_DYNAMIC_DRAW                                               0x88E8
        #define GL_DYNAMIC_READ                                               0x88E9
        #define GL_DYNAMIC_COPY                                               0x88EA
        #define GL_PIXEL_PACK_BUFFER                                          0x88EB
        #define GL_PIXEL_UNPACK_BUFFER                                        0x88EC
        #define GL_PIXEL_PACK_BUFFER_BINDING                                  0x88ED
        #define GL_PIXEL_UNPACK_BUFFER_BINDING                                0x88EF
        #define GL_DEPTH24_STENCIL8                                           0x88F0
        #define GL_TEXTURE_STENCIL_SIZE                                       0x88F1
        #define GL_SRC1_COLOR                                                 0x88F9
        #define GL_ONE_MINUS_SRC1_COLOR                                       0x88FA
        #define GL_ONE_MINUS_SRC1_ALPHA                                       0x88FB
        #define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS                               0x88FC
        #define GL_VERTEX_ATTRIB_ARRAY_INTEGER                                0x88FD
        #define GL_VERTEX_ATTRIB_ARRAY_DIVISOR                                0x88FE
        #define GL_MAX_ARRAY_TEXTURE_LAYERS                                   0x88FF
        #define GL_MIN_PROGRAM_TEXEL_OFFSET                                   0x8904
        #define GL_MAX_PROGRAM_TEXEL_OFFSET                                   0x8905
        #define GL_SAMPLES_PASSED                                             0x8914
        #define GL_GEOMETRY_VERTICES_OUT                                      0x8916
        #define GL_GEOMETRY_INPUT_TYPE                                        0x8917
        #define GL_GEOMETRY_OUTPUT_TYPE                                       0x8918
        #define GL_SAMPLER_BINDING                                            0x8919
        #define GL_CLAMP_READ_COLOR                                           0x891C
        #define GL_FIXED_ONLY                                                 0x891D
        #define GL_UNIFORM_BUFFER                                             0x8A11
        #define GL_UNIFORM_BUFFER_BINDING                                     0x8A28
        #define GL_UNIFORM_BUFFER_START                                       0x8A29
        #define GL_UNIFORM_BUFFER_SIZE                                        0x8A2A
        #define GL_MAX_VERTEX_UNIFORM_BLOCKS                                  0x8A2B
        #define GL_MAX_GEOMETRY_UNIFORM_BLOCKS                                0x8A2C
        #define GL_MAX_FRAGMENT_UNIFORM_BLOCKS                                0x8A2D
        #define GL_MAX_COMBINED_UNIFORM_BLOCKS                                0x8A2E
        #define GL_MAX_UNIFORM_BUFFER_BINDINGS                                0x8A2F
        #define GL_MAX_UNIFORM_BLOCK_SIZE                                     0x8A30
        #define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS                     0x8A31
        #define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS                   0x8A32
        #define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS                   0x8A33
        #define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT                            0x8A34
        #define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH                       0x8A35
        #define GL_ACTIVE_UNIFORM_BLOCKS                                      0x8A36
        #define GL_UNIFORM_TYPE                                               0x8A37
        #define GL_UNIFORM_SIZE                                               0x8A38
        #define GL_UNIFORM_NAME_LENGTH                                        0x8A39
        #define GL_UNIFORM_BLOCK_INDEX                                        0x8A3A
        #define GL_UNIFORM_OFFSET                                             0x8A3B
        #define GL_UNIFORM_ARRAY_STRIDE                                       0x8A3C
        #define GL_UNIFORM_MATRIX_STRIDE                                      0x8A3D
        #define GL_UNIFORM_IS_ROW_MAJOR                                       0x8A3E
        #define GL_UNIFORM_BLOCK_BINDING                                      0x8A3F
        #define GL_UNIFORM_BLOCK_DATA_SIZE                                    0x8A40
        #define GL_UNIFORM_BLOCK_NAME_LENGTH                                  0x8A41
        #define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS                              0x8A42
        #define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES                       0x8A43
        #define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER                  0x8A44
        #define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER                0x8A45
        #define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER                0x8A46
        #define GL_FRAGMENT_SHADER                                            0x8B30
        #define GL_VERTEX_SHADER                                              0x8B31
        #define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS                            0x8B49
        #define GL_MAX_VERTEX_UNIFORM_COMPONENTS                              0x8B4A
        #define GL_MAX_VARYING_FLOATS                                         0x8B4B
        #define GL_MAX_VARYING_COMPONENTS                                     0x8B4B
        #define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS                             0x8B4C
        #define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS                           0x8B4D
        #define GL_SHADER_TYPE                                                0x8B4F
        #define GL_FLOAT_VEC2                                                 0x8B50
        #define GL_FLOAT_VEC3                                                 0x8B51
        #define GL_FLOAT_VEC4                                                 0x8B52
        #define GL_INT_VEC2                                                   0x8B53
        #define GL_INT_VEC3                                                   0x8B54
        #define GL_INT_VEC4                                                   0x8B55
        #define GL_BOOL                                                       0x8B56
        #define GL_BOOL_VEC2                                                  0x8B57
        #define GL_BOOL_VEC3                                                  0x8B58
        #define GL_BOOL_VEC4                                                  0x8B59
        #define GL_FLOAT_MAT2                                                 0x8B5A
        #define GL_FLOAT_MAT3                                                 0x8B5B
        #define GL_FLOAT_MAT4                                                 0x8B5C
        #define GL_SAMPLER_1D                                                 0x8B5D
        #define GL_SAMPLER_2D                                                 0x8B5E
        #define GL_SAMPLER_3D                                                 0x8B5F
        #define GL_SAMPLER_CUBE                                               0x8B60
        #define GL_SAMPLER_1D_SHADOW                                          0x8B61
        #define GL_SAMPLER_2D_SHADOW                                          0x8B62
        #define GL_SAMPLER_2D_RECT                                            0x8B63
        #define GL_SAMPLER_2D_RECT_SHADOW                                     0x8B64
        #define GL_FLOAT_MAT2x3                                               0x8B65
        #define GL_FLOAT_MAT2x4                                               0x8B66
        #define GL_FLOAT_MAT3x2                                               0x8B67
        #define GL_FLOAT_MAT3x4                                               0x8B68
        #define GL_FLOAT_MAT4x2                                               0x8B69
        #define GL_FLOAT_MAT4x3                                               0x8B6A
        #define GL_DELETE_STATUS                                              0x8B80
        #define GL_COMPILE_STATUS                                             0x8B81
        #define GL_LINK_STATUS                                                0x8B82
        #define GL_VALIDATE_STATUS                                            0x8B83
        #define GL_INFO_LOG_LENGTH                                            0x8B84
        #define GL_ATTACHED_SHADERS                                           0x8B85
        #define GL_ACTIVE_UNIFORMS                                            0x8B86
        #define GL_ACTIVE_UNIFORM_MAX_LENGTH                                  0x8B87
        #define GL_SHADER_SOURCE_LENGTH                                       0x8B88
        #define GL_ACTIVE_ATTRIBUTES                                          0x8B89
        #define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH                                0x8B8A
        #define GL_FRAGMENT_SHADER_DERIVATIVE_HINT                            0x8B8B
        #define GL_SHADING_LANGUAGE_VERSION                                   0x8B8C
        #define GL_CURRENT_PROGRAM                                            0x8B8D
        #define GL_IMPLEMENTATION_COLOR_READ_TYPE                             0x8B9A
        #define GL_IMPLEMENTATION_COLOR_READ_FORMAT                           0x8B9B
        #define GL_TEXTURE_RED_TYPE                                           0x8C10
        #define GL_TEXTURE_GREEN_TYPE                                         0x8C11
        #define GL_TEXTURE_BLUE_TYPE                                          0x8C12
        #define GL_TEXTURE_ALPHA_TYPE                                         0x8C13
        #define GL_TEXTURE_DEPTH_TYPE                                         0x8C16
        #define GL_UNSIGNED_NORMALIZED                                        0x8C17
        #define GL_TEXTURE_1D_ARRAY                                           0x8C18
        #define GL_PROXY_TEXTURE_1D_ARRAY                                     0x8C19
        #define GL_TEXTURE_2D_ARRAY                                           0x8C1A
        #define GL_PROXY_TEXTURE_2D_ARRAY                                     0x8C1B
        #define GL_TEXTURE_BINDING_1D_ARRAY                                   0x8C1C
        #define GL_TEXTURE_BINDING_2D_ARRAY                                   0x8C1D
        #define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS                           0x8C29
        #define GL_TEXTURE_BUFFER                                             0x8C2A
        #define GL_TEXTURE_BUFFER_BINDING                                     0x8C2A
        #define GL_MAX_TEXTURE_BUFFER_SIZE                                    0x8C2B
        #define GL_TEXTURE_BINDING_BUFFER                                     0x8C2C
        #define GL_TEXTURE_BUFFER_DATA_STORE_BINDING                          0x8C2D
        #define GL_ANY_SAMPLES_PASSED                                         0x8C2F
        #define GL_SAMPLE_SHADING                                             0x8C36
        #define GL_MIN_SAMPLE_SHADING_VALUE                                   0x8C37
        #define GL_R11F_G11F_B10F                                             0x8C3A
        #define GL_UNSIGNED_INT_10F_11F_11F_REV                               0x8C3B
        #define GL_RGB9_E5                                                    0x8C3D
        #define GL_UNSIGNED_INT_5_9_9_9_REV                                   0x8C3E
        #define GL_TEXTURE_SHARED_SIZE                                        0x8C3F
        #define GL_SRGB                                                       0x8C40
        #define GL_SRGB8                                                      0x8C41
        #define GL_SRGB_ALPHA                                                 0x8C42
        #define GL_SRGB8_ALPHA8                                               0x8C43
        #define GL_COMPRESSED_SRGB                                            0x8C48
        #define GL_COMPRESSED_SRGB_ALPHA                                      0x8C49
        #define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH                      0x8C76
        #define GL_TRANSFORM_FEEDBACK_BUFFER_MODE                             0x8C7F
        #define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS                 0x8C80
        #define GL_TRANSFORM_FEEDBACK_VARYINGS                                0x8C83
        #define GL_TRANSFORM_FEEDBACK_BUFFER_START                            0x8C84
        #define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE                             0x8C85
        #define GL_PRIMITIVES_GENERATED                                       0x8C87
        #define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN                      0x8C88
        #define GL_RASTERIZER_DISCARD                                         0x8C89
        #define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS              0x8C8A
        #define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS                    0x8C8B
        #define GL_INTERLEAVED_ATTRIBS                                        0x8C8C
        #define GL_SEPARATE_ATTRIBS                                           0x8C8D
        #define GL_TRANSFORM_FEEDBACK_BUFFER                                  0x8C8E
        #define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING                          0x8C8F
        #define GL_POINT_SPRITE_COORD_ORIGIN                                  0x8CA0
        #define GL_LOWER_LEFT                                                 0x8CA1
        #define GL_UPPER_LEFT                                                 0x8CA2
        #define GL_STENCIL_BACK_REF                                           0x8CA3
        #define GL_STENCIL_BACK_VALUE_MASK                                    0x8CA4
        #define GL_STENCIL_BACK_WRITEMASK                                     0x8CA5
        #define GL_DRAW_FRAMEBUFFER_BINDING                                   0x8CA6
        #define GL_FRAMEBUFFER_BINDING                                        0x8CA6
        #define GL_RENDERBUFFER_BINDING                                       0x8CA7
        #define GL_READ_FRAMEBUFFER                                           0x8CA8
        #define GL_DRAW_FRAMEBUFFER                                           0x8CA9
        #define GL_READ_FRAMEBUFFER_BINDING                                   0x8CAA
        #define GL_RENDERBUFFER_SAMPLES                                       0x8CAB
        #define GL_DEPTH_COMPONENT32F                                         0x8CAC
        #define GL_DEPTH32F_STENCIL8                                          0x8CAD
        #define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE                         0x8CD0
        #define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME                         0x8CD1
        #define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL                       0x8CD2
        #define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE               0x8CD3
        #define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER                       0x8CD4
        #define GL_FRAMEBUFFER_COMPLETE                                       0x8CD5
        #define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT                          0x8CD6
        #define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT                  0x8CD7
        #define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER                         0x8CDB
        #define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER                         0x8CDC
        #define GL_FRAMEBUFFER_UNSUPPORTED                                    0x8CDD
        #define GL_MAX_COLOR_ATTACHMENTS                                      0x8CDF
        #define GL_COLOR_ATTACHMENT0                                          0x8CE0
        #define GL_COLOR_ATTACHMENT1                                          0x8CE1
        #define GL_COLOR_ATTACHMENT2                                          0x8CE2
        #define GL_COLOR_ATTACHMENT3                                          0x8CE3
        #define GL_COLOR_ATTACHMENT4                                          0x8CE4
        #define GL_COLOR_ATTACHMENT5                                          0x8CE5
        #define GL_COLOR_ATTACHMENT6                                          0x8CE6
        #define GL_COLOR_ATTACHMENT7                                          0x8CE7
        #define GL_COLOR_ATTACHMENT8                                          0x8CE8
        #define GL_COLOR_ATTACHMENT9                                          0x8CE9
        #define GL_COLOR_ATTACHMENT10                                         0x8CEA
        #define GL_COLOR_ATTACHMENT11                                         0x8CEB
        #define GL_COLOR_ATTACHMENT12                                         0x8CEC
        #define GL_COLOR_ATTACHMENT13                                         0x8CED
        #define GL_COLOR_ATTACHMENT14                                         0x8CEE
        #define GL_COLOR_ATTACHMENT15                                         0x8CEF
        #define GL_DEPTH_ATTACHMENT                                           0x8D00
        #define GL_STENCIL_ATTACHMENT                                         0x8D20
        #define GL_FRAMEBUFFER                                                0x8D40
        #define GL_RENDERBUFFER                                               0x8D41
        #define GL_RENDERBUFFER_WIDTH                                         0x8D42
        #define GL_RENDERBUFFER_HEIGHT                                        0x8D43
        #define GL_RENDERBUFFER_INTERNAL_FORMAT                               0x8D44
        #define GL_STENCIL_INDEX1                                             0x8D46
        #define GL_STENCIL_INDEX4                                             0x8D47
        #define GL_STENCIL_INDEX8                                             0x8D48
        #define GL_STENCIL_INDEX16                                            0x8D49
        #define GL_RENDERBUFFER_RED_SIZE                                      0x8D50
        #define GL_RENDERBUFFER_GREEN_SIZE                                    0x8D51
        #define GL_RENDERBUFFER_BLUE_SIZE                                     0x8D52
        #define GL_RENDERBUFFER_ALPHA_SIZE                                    0x8D53
        #define GL_RENDERBUFFER_DEPTH_SIZE                                    0x8D54
        #define GL_RENDERBUFFER_STENCIL_SIZE                                  0x8D55
        #define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE                         0x8D56
        #define GL_MAX_SAMPLES                                                0x8D57
        #define GL_RGB565                                                     0x8D62
        #define GL_PRIMITIVE_RESTART_FIXED_INDEX                              0x8D69
        #define GL_ANY_SAMPLES_PASSED_CONSERVATIVE                            0x8D6A
        #define GL_MAX_ELEMENT_INDEX                                          0x8D6B
        #define GL_RGBA32UI                                                   0x8D70
        #define GL_RGB32UI                                                    0x8D71
        #define GL_RGBA16UI                                                   0x8D76
        #define GL_RGB16UI                                                    0x8D77
        #define GL_RGBA8UI                                                    0x8D7C
        #define GL_RGB8UI                                                     0x8D7D
        #define GL_RGBA32I                                                    0x8D82
        #define GL_RGB32I                                                     0x8D83
        #define GL_RGBA16I                                                    0x8D88
        #define GL_RGB16I                                                     0x8D89
        #define GL_RGBA8I                                                     0x8D8E
        #define GL_RGB8I                                                      0x8D8F
        #define GL_RED_INTEGER                                                0x8D94
        #define GL_GREEN_INTEGER                                              0x8D95
        #define GL_BLUE_INTEGER                                               0x8D96
        #define GL_RGB_INTEGER                                                0x8D98
        #define GL_RGBA_INTEGER                                               0x8D99
        #define GL_BGR_INTEGER                                                0x8D9A
        #define GL_BGRA_INTEGER                                               0x8D9B
        #define GL_INT_2_10_10_10_REV                                         0x8D9F
        #define GL_FRAMEBUFFER_ATTACHMENT_LAYERED                             0x8DA7
        #define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS                       0x8DA8
        #define GL_FLOAT_32_UNSIGNED_INT_24_8_REV                             0x8DAD
        #define GL_FRAMEBUFFER_SRGB                                           0x8DB9
        #define GL_COMPRESSED_RED_RGTC1                                       0x8DBB
        #define GL_COMPRESSED_SIGNED_RED_RGTC1                                0x8DBC
        #define GL_COMPRESSED_RG_RGTC2                                        0x8DBD
        #define GL_COMPRESSED_SIGNED_RG_RGTC2                                 0x8DBE
        #define GL_SAMPLER_1D_ARRAY                                           0x8DC0
        #define GL_SAMPLER_2D_ARRAY                                           0x8DC1
        #define GL_SAMPLER_BUFFER                                             0x8DC2
        #define GL_SAMPLER_1D_ARRAY_SHADOW                                    0x8DC3
        #define GL_SAMPLER_2D_ARRAY_SHADOW                                    0x8DC4
        #define GL_SAMPLER_CUBE_SHADOW                                        0x8DC5
        #define GL_UNSIGNED_INT_VEC2                                          0x8DC6
        #define GL_UNSIGNED_INT_VEC3                                          0x8DC7
        #define GL_UNSIGNED_INT_VEC4                                          0x8DC8
        #define GL_INT_SAMPLER_1D                                             0x8DC9
        #define GL_INT_SAMPLER_2D                                             0x8DCA
        #define GL_INT_SAMPLER_3D                                             0x8DCB
        #define GL_INT_SAMPLER_CUBE                                           0x8DCC
        #define GL_INT_SAMPLER_2D_RECT                                        0x8DCD
        #define GL_INT_SAMPLER_1D_ARRAY                                       0x8DCE
        #define GL_INT_SAMPLER_2D_ARRAY                                       0x8DCF
        #define GL_INT_SAMPLER_BUFFER                                         0x8DD0
        #define GL_UNSIGNED_INT_SAMPLER_1D                                    0x8DD1
        #define GL_UNSIGNED_INT_SAMPLER_2D                                    0x8DD2
        #define GL_UNSIGNED_INT_SAMPLER_3D                                    0x8DD3
        #define GL_UNSIGNED_INT_SAMPLER_CUBE                                  0x8DD4
        #define GL_UNSIGNED_INT_SAMPLER_2D_RECT                               0x8DD5
        #define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY                              0x8DD6
        #define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY                              0x8DD7
        #define GL_UNSIGNED_INT_SAMPLER_BUFFER                                0x8DD8
        #define GL_GEOMETRY_SHADER                                            0x8DD9
        #define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS                            0x8DDF
        #define GL_MAX_GEOMETRY_OUTPUT_VERTICES                               0x8DE0
        #define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS                       0x8DE1
        #define GL_ACTIVE_SUBROUTINES                                         0x8DE5
        #define GL_ACTIVE_SUBROUTINE_UNIFORMS                                 0x8DE6
        #define GL_MAX_SUBROUTINES                                            0x8DE7
        #define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS                           0x8DE8
        #define GL_LOW_FLOAT                                                  0x8DF0
        #define GL_MEDIUM_FLOAT                                               0x8DF1
        #define GL_HIGH_FLOAT                                                 0x8DF2
        #define GL_LOW_INT                                                    0x8DF3
        #define GL_MEDIUM_INT                                                 0x8DF4
        #define GL_HIGH_INT                                                   0x8DF5
        #define GL_SHADER_BINARY_FORMATS                                      0x8DF8
        #define GL_NUM_SHADER_BINARY_FORMATS                                  0x8DF9
        #define GL_SHADER_COMPILER                                            0x8DFA
        #define GL_MAX_VERTEX_UNIFORM_VECTORS                                 0x8DFB
        #define GL_MAX_VARYING_VECTORS                                        0x8DFC
        #define GL_MAX_FRAGMENT_UNIFORM_VECTORS                               0x8DFD
        #define GL_QUERY_WAIT                                                 0x8E13
        #define GL_QUERY_NO_WAIT                                              0x8E14
        #define GL_QUERY_BY_REGION_WAIT                                       0x8E15
        #define GL_QUERY_BY_REGION_NO_WAIT                                    0x8E16
        #define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS               0x8E1E
        #define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS            0x8E1F
        #define GL_TRANSFORM_FEEDBACK                                         0x8E22
        #define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED                           0x8E23
        #define GL_TRANSFORM_FEEDBACK_PAUSED                                  0x8E23
        #define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE                           0x8E24
        #define GL_TRANSFORM_FEEDBACK_ACTIVE                                  0x8E24
        #define GL_TRANSFORM_FEEDBACK_BINDING                                 0x8E25
        #define GL_TIMESTAMP                                                  0x8E28
        #define GL_TEXTURE_SWIZZLE_R                                          0x8E42
        #define GL_TEXTURE_SWIZZLE_G                                          0x8E43
        #define GL_TEXTURE_SWIZZLE_B                                          0x8E44
        #define GL_TEXTURE_SWIZZLE_A                                          0x8E45
        #define GL_TEXTURE_SWIZZLE_RGBA                                       0x8E46
        #define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS                        0x8E47
        #define GL_ACTIVE_SUBROUTINE_MAX_LENGTH                               0x8E48
        #define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH                       0x8E49
        #define GL_NUM_COMPATIBLE_SUBROUTINES                                 0x8E4A
        #define GL_COMPATIBLE_SUBROUTINES                                     0x8E4B
        #define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION                   0x8E4C
        #define GL_FIRST_VERTEX_CONVENTION                                    0x8E4D
        #define GL_LAST_VERTEX_CONVENTION                                     0x8E4E
        #define GL_PROVOKING_VERTEX                                           0x8E4F
        #define GL_SAMPLE_POSITION                                            0x8E50
        #define GL_SAMPLE_MASK                                                0x8E51
        #define GL_SAMPLE_MASK_VALUE                                          0x8E52
        #define GL_MAX_SAMPLE_MASK_WORDS                                      0x8E59
        #define GL_MAX_GEOMETRY_SHADER_INVOCATIONS                            0x8E5A
        #define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET                          0x8E5B
        #define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET                          0x8E5C
        #define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS                         0x8E5D
        #define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET                          0x8E5E
        #define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET                          0x8E5F
        #define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS                             0x8E70
        #define GL_MAX_VERTEX_STREAMS                                         0x8E71
        #define GL_PATCH_VERTICES                                             0x8E72
        #define GL_PATCH_DEFAULT_INNER_LEVEL                                  0x8E73
        #define GL_PATCH_DEFAULT_OUTER_LEVEL                                  0x8E74
        #define GL_TESS_CONTROL_OUTPUT_VERTICES                               0x8E75
        #define GL_TESS_GEN_MODE                                              0x8E76
        #define GL_TESS_GEN_SPACING                                           0x8E77
        #define GL_TESS_GEN_VERTEX_ORDER                                      0x8E78
        #define GL_TESS_GEN_POINT_MODE                                        0x8E79
        #define GL_ISOLINES                                                   0x8E7A
        #define GL_FRACTIONAL_ODD                                             0x8E7B
        #define GL_FRACTIONAL_EVEN                                            0x8E7C
        #define GL_MAX_PATCH_VERTICES                                         0x8E7D
        #define GL_MAX_TESS_GEN_LEVEL                                         0x8E7E
        #define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS                        0x8E7F
        #define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS                     0x8E80
        #define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS                       0x8E81
        #define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS                    0x8E82
        #define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS                         0x8E83
        #define GL_MAX_TESS_PATCH_COMPONENTS                                  0x8E84
        #define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS                   0x8E85
        #define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS                      0x8E86
        #define GL_TESS_EVALUATION_SHADER                                     0x8E87
        #define GL_TESS_CONTROL_SHADER                                        0x8E88
        #define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS                            0x8E89
        #define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS                         0x8E8A
        #define GL_COMPRESSED_RGBA_BPTC_UNORM                                 0x8E8C
        #define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM                           0x8E8D
        #define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT                           0x8E8E
        #define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT                         0x8E8F
        #define GL_COPY_READ_BUFFER                                           0x8F36
        #define GL_COPY_READ_BUFFER_BINDING                                   0x8F36
        #define GL_COPY_WRITE_BUFFER                                          0x8F37
        #define GL_COPY_WRITE_BUFFER_BINDING                                  0x8F37
        #define GL_MAX_IMAGE_UNITS                                            0x8F38
        #define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS              0x8F39
        #define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES                       0x8F39
        #define GL_IMAGE_BINDING_NAME                                         0x8F3A
        #define GL_IMAGE_BINDING_LEVEL                                        0x8F3B
        #define GL_IMAGE_BINDING_LAYERED                                      0x8F3C
        #define GL_IMAGE_BINDING_LAYER                                        0x8F3D
        #define GL_IMAGE_BINDING_ACCESS                                       0x8F3E
        #define GL_DRAW_INDIRECT_BUFFER                                       0x8F3F
        #define GL_DRAW_INDIRECT_BUFFER_BINDING                               0x8F43
        #define GL_DOUBLE_MAT2                                                0x8F46
        #define GL_DOUBLE_MAT3                                                0x8F47
        #define GL_DOUBLE_MAT4                                                0x8F48
        #define GL_DOUBLE_MAT2x3                                              0x8F49
        #define GL_DOUBLE_MAT2x4                                              0x8F4A
        #define GL_DOUBLE_MAT3x2                                              0x8F4B
        #define GL_DOUBLE_MAT3x4                                              0x8F4C
        #define GL_DOUBLE_MAT4x2                                              0x8F4D
        #define GL_DOUBLE_MAT4x3                                              0x8F4E
        #define GL_VERTEX_BINDING_BUFFER                                      0x8F4F
        #define GL_R8_SNORM                                                   0x8F94
        #define GL_RG8_SNORM                                                  0x8F95
        #define GL_RGB8_SNORM                                                 0x8F96
        #define GL_RGBA8_SNORM                                                0x8F97
        #define GL_R16_SNORM                                                  0x8F98
        #define GL_RG16_SNORM                                                 0x8F99
        #define GL_RGB16_SNORM                                                0x8F9A
        #define GL_RGBA16_SNORM                                               0x8F9B
        #define GL_SIGNED_NORMALIZED                                          0x8F9C
        #define GL_PRIMITIVE_RESTART                                          0x8F9D
        #define GL_PRIMITIVE_RESTART_INDEX                                    0x8F9E
        #define GL_DOUBLE_VEC2                                                0x8FFC
        #define GL_DOUBLE_VEC3                                                0x8FFD
        #define GL_DOUBLE_VEC4                                                0x8FFE
        #define GL_TEXTURE_CUBE_MAP_ARRAY                                     0x9009
        #define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY                             0x900A
        #define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY                               0x900B
        #define GL_SAMPLER_CUBE_MAP_ARRAY                                     0x900C
        #define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW                              0x900D
        #define GL_INT_SAMPLER_CUBE_MAP_ARRAY                                 0x900E
        #define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY                        0x900F
        #define GL_IMAGE_1D                                                   0x904C
        #define GL_IMAGE_2D                                                   0x904D
        #define GL_IMAGE_3D                                                   0x904E
        #define GL_IMAGE_2D_RECT                                              0x904F
        #define GL_IMAGE_CUBE                                                 0x9050
        #define GL_IMAGE_BUFFER                                               0x9051
        #define GL_IMAGE_1D_ARRAY                                             0x9052
        #define GL_IMAGE_2D_ARRAY                                             0x9053
        #define GL_IMAGE_CUBE_MAP_ARRAY                                       0x9054
        #define GL_IMAGE_2D_MULTISAMPLE                                       0x9055
        #define GL_IMAGE_2D_MULTISAMPLE_ARRAY                                 0x9056
        #define GL_INT_IMAGE_1D                                               0x9057
        #define GL_INT_IMAGE_2D                                               0x9058
        #define GL_INT_IMAGE_3D                                               0x9059
        #define GL_INT_IMAGE_2D_RECT                                          0x905A
        #define GL_INT_IMAGE_CUBE                                             0x905B
        #define GL_INT_IMAGE_BUFFER                                           0x905C
        #define GL_INT_IMAGE_1D_ARRAY                                         0x905D
        #define GL_INT_IMAGE_2D_ARRAY                                         0x905E
        #define GL_INT_IMAGE_CUBE_MAP_ARRAY                                   0x905F
        #define GL_INT_IMAGE_2D_MULTISAMPLE                                   0x9060
        #define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY                             0x9061
        #define GL_UNSIGNED_INT_IMAGE_1D                                      0x9062
        #define GL_UNSIGNED_INT_IMAGE_2D                                      0x9063
        #define GL_UNSIGNED_INT_IMAGE_3D                                      0x9064
        #define GL_UNSIGNED_INT_IMAGE_2D_RECT                                 0x9065
        #define GL_UNSIGNED_INT_IMAGE_CUBE                                    0x9066
        #define GL_UNSIGNED_INT_IMAGE_BUFFER                                  0x9067
        #define GL_UNSIGNED_INT_IMAGE_1D_ARRAY                                0x9068
        #define GL_UNSIGNED_INT_IMAGE_2D_ARRAY                                0x9069
        #define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY                          0x906A
        #define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE                          0x906B
        #define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY                    0x906C
        #define GL_MAX_IMAGE_SAMPLES                                          0x906D
        #define GL_IMAGE_BINDING_FORMAT                                       0x906E
        #define GL_RGB10_A2UI                                                 0x906F
        #define GL_MIN_MAP_BUFFER_ALIGNMENT                                   0x90BC
        #define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE                            0x90C7
        #define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE                         0x90C8
        #define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS                        0x90C9
        #define GL_MAX_VERTEX_IMAGE_UNIFORMS                                  0x90CA
        #define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS                            0x90CB
        #define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS                         0x90CC
        #define GL_MAX_GEOMETRY_IMAGE_UNIFORMS                                0x90CD
        #define GL_MAX_FRAGMENT_IMAGE_UNIFORMS                                0x90CE
        #define GL_MAX_COMBINED_IMAGE_UNIFORMS                                0x90CF
        #define GL_SHADER_STORAGE_BUFFER                                      0x90D2
        #define GL_SHADER_STORAGE_BUFFER_BINDING                              0x90D3
        #define GL_SHADER_STORAGE_BUFFER_START                                0x90D4
        #define GL_SHADER_STORAGE_BUFFER_SIZE                                 0x90D5
        #define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS                           0x90D6
        #define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS                         0x90D7
        #define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS                     0x90D8
        #define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS                  0x90D9
        #define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS                         0x90DA
        #define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS                          0x90DB
        #define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS                         0x90DC
        #define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS                         0x90DD
        #define GL_MAX_SHADER_STORAGE_BLOCK_SIZE                              0x90DE
        #define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT                     0x90DF
        #define GL_DEPTH_STENCIL_TEXTURE_MODE                                 0x90EA
        #define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS                         0x90EB
        #define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER                 0x90EC
        #define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER         0x90ED
        #define GL_DISPATCH_INDIRECT_BUFFER                                   0x90EE
        #define GL_DISPATCH_INDIRECT_BUFFER_BINDING                           0x90EF
        #define GL_TEXTURE_2D_MULTISAMPLE                                     0x9100
        #define GL_PROXY_TEXTURE_2D_MULTISAMPLE                               0x9101
        #define GL_TEXTURE_2D_MULTISAMPLE_ARRAY                               0x9102
        #define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY                         0x9103
        #define GL_TEXTURE_BINDING_2D_MULTISAMPLE                             0x9104
        #define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY                       0x9105
        #define GL_TEXTURE_SAMPLES                                            0x9106
        #define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS                             0x9107
        #define GL_SAMPLER_2D_MULTISAMPLE                                     0x9108
        #define GL_INT_SAMPLER_2D_MULTISAMPLE                                 0x9109
        #define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE                        0x910A
        #define GL_SAMPLER_2D_MULTISAMPLE_ARRAY                               0x910B
        #define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY                           0x910C
        #define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY                  0x910D
        #define GL_MAX_COLOR_TEXTURE_SAMPLES                                  0x910E
        #define GL_MAX_DEPTH_TEXTURE_SAMPLES                                  0x910F
        #define GL_MAX_INTEGER_SAMPLES                                        0x9110
        #define GL_MAX_SERVER_WAIT_TIMEOUT                                    0x9111
        #define GL_OBJECT_TYPE                                                0x9112
        #define GL_SYNC_CONDITION                                             0x9113
        #define GL_SYNC_STATUS                                                0x9114
        #define GL_SYNC_FLAGS                                                 0x9115
        #define GL_SYNC_FENCE                                                 0x9116
        #define GL_SYNC_GPU_COMMANDS_COMPLETE                                 0x9117
        #define GL_UNSIGNALED                                                 0x9118
        #define GL_SIGNALED                                                   0x9119
        #define GL_ALREADY_SIGNALED                                           0x911A
        #define GL_TIMEOUT_EXPIRED                                            0x911B
        #define GL_CONDITION_SATISFIED                                        0x911C
        #define GL_WAIT_FAILED                                                0x911D
        #define GL_BUFFER_ACCESS_FLAGS                                        0x911F
        #define GL_BUFFER_MAP_LENGTH                                          0x9120
        #define GL_BUFFER_MAP_OFFSET                                          0x9121
        #define GL_MAX_VERTEX_OUTPUT_COMPONENTS                               0x9122
        #define GL_MAX_GEOMETRY_INPUT_COMPONENTS                              0x9123
        #define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS                             0x9124
        #define GL_MAX_FRAGMENT_INPUT_COMPONENTS                              0x9125
        #define GL_CONTEXT_PROFILE_MASK                                       0x9126
        #define GL_UNPACK_COMPRESSED_BLOCK_WIDTH                              0x9127
        #define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT                             0x9128
        #define GL_UNPACK_COMPRESSED_BLOCK_DEPTH                              0x9129
        #define GL_UNPACK_COMPRESSED_BLOCK_SIZE                               0x912A
        #define GL_PACK_COMPRESSED_BLOCK_WIDTH                                0x912B
        #define GL_PACK_COMPRESSED_BLOCK_HEIGHT                               0x912C
        #define GL_PACK_COMPRESSED_BLOCK_DEPTH                                0x912D
        #define GL_PACK_COMPRESSED_BLOCK_SIZE                                 0x912E
        #define GL_TEXTURE_IMMUTABLE_FORMAT                                   0x912F
        #define GL_MAX_DEBUG_MESSAGE_LENGTH                                   0x9143
        #define GL_MAX_DEBUG_LOGGED_MESSAGES                                  0x9144
        #define GL_DEBUG_LOGGED_MESSAGES                                      0x9145
        #define GL_DEBUG_SEVERITY_HIGH                                        0x9146
        #define GL_DEBUG_SEVERITY_MEDIUM                                      0x9147
        #define GL_DEBUG_SEVERITY_LOW                                         0x9148
        #define GL_QUERY_BUFFER                                               0x9192
        #define GL_QUERY_BUFFER_BINDING                                       0x9193
        #define GL_QUERY_RESULT_NO_WAIT                                       0x9194
        #define GL_TEXTURE_BUFFER_OFFSET                                      0x919D
        #define GL_TEXTURE_BUFFER_SIZE                                        0x919E
        #define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT                            0x919F
        #define GL_COMPUTE_SHADER                                             0x91B9
        #define GL_MAX_COMPUTE_UNIFORM_BLOCKS                                 0x91BB
        #define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS                            0x91BC
        #define GL_MAX_COMPUTE_IMAGE_UNIFORMS                                 0x91BD
        #define GL_MAX_COMPUTE_WORK_GROUP_COUNT                               0x91BE
        #define GL_MAX_COMPUTE_WORK_GROUP_SIZE                                0x91BF
        #define GL_COMPRESSED_R11_EAC                                         0x9270
        #define GL_COMPRESSED_SIGNED_R11_EAC                                  0x9271
        #define GL_COMPRESSED_RG11_EAC                                        0x9272
        #define GL_COMPRESSED_SIGNED_RG11_EAC                                 0x9273
        #define GL_COMPRESSED_RGB8_ETC2                                       0x9274
        #define GL_COMPRESSED_SRGB8_ETC2                                      0x9275
        #define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2                   0x9276
        #define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2                  0x9277
        #define GL_COMPRESSED_RGBA8_ETC2_EAC                                  0x9278
        #define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC                           0x9279
        #define GL_ATOMIC_COUNTER_BUFFER                                      0x92C0
        #define GL_ATOMIC_COUNTER_BUFFER_BINDING                              0x92C1
        #define GL_ATOMIC_COUNTER_BUFFER_START                                0x92C2
        #define GL_ATOMIC_COUNTER_BUFFER_SIZE                                 0x92C3
        #define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE                            0x92C4
        #define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS               0x92C5
        #define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES        0x92C6
        #define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER          0x92C7
        #define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER    0x92C8
        #define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
        #define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER        0x92CA
        #define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER        0x92CB
        #define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS                          0x92CC
        #define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS                    0x92CD
        #define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS                 0x92CE
        #define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS                        0x92CF
        #define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS                        0x92D0
        #define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS                        0x92D1
        #define GL_MAX_VERTEX_ATOMIC_COUNTERS                                 0x92D2
        #define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS                           0x92D3
        #define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS                        0x92D4
        #define GL_MAX_GEOMETRY_ATOMIC_COUNTERS                               0x92D5
        #define GL_MAX_FRAGMENT_ATOMIC_COUNTERS                               0x92D6
        #define GL_MAX_COMBINED_ATOMIC_COUNTERS                               0x92D7
        #define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE                             0x92D8
        #define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS                              0x92D9
        #define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX                        0x92DA
        #define GL_UNSIGNED_INT_ATOMIC_COUNTER                                0x92DB
        #define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS                         0x92DC
        #define GL_DEBUG_OUTPUT                                               0x92E0
        #define GL_UNIFORM                                                    0x92E1
        #define GL_UNIFORM_BLOCK                                              0x92E2
        #define GL_PROGRAM_INPUT                                              0x92E3
        #define GL_PROGRAM_OUTPUT                                             0x92E4
        #define GL_BUFFER_VARIABLE                                            0x92E5
        #define GL_SHADER_STORAGE_BLOCK                                       0x92E6
        #define GL_IS_PER_PATCH                                               0x92E7
        #define GL_VERTEX_SUBROUTINE                                          0x92E8
        #define GL_TESS_CONTROL_SUBROUTINE                                    0x92E9
        #define GL_TESS_EVALUATION_SUBROUTINE                                 0x92EA
        #define GL_GEOMETRY_SUBROUTINE                                        0x92EB
        #define GL_FRAGMENT_SUBROUTINE                                        0x92EC
        #define GL_COMPUTE_SUBROUTINE                                         0x92ED
        #define GL_VERTEX_SUBROUTINE_UNIFORM                                  0x92EE
        #define GL_TESS_CONTROL_SUBROUTINE_UNIFORM                            0x92EF
        #define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM                         0x92F0
        #define GL_GEOMETRY_SUBROUTINE_UNIFORM                                0x92F1
        #define GL_FRAGMENT_SUBROUTINE_UNIFORM                                0x92F2
        #define GL_COMPUTE_SUBROUTINE_UNIFORM                                 0x92F3
        #define GL_TRANSFORM_FEEDBACK_VARYING                                 0x92F4
        #define GL_ACTIVE_RESOURCES                                           0x92F5
        #define GL_MAX_NAME_LENGTH                                            0x92F6
        #define GL_MAX_NUM_ACTIVE_VARIABLES                                   0x92F7
        #define GL_MAX_NUM_COMPATIBLE_SUBROUTINES                             0x92F8
        #define GL_NAME_LENGTH                                                0x92F9
        #define GL_TYPE                                                       0x92FA
        #define GL_ARRAY_SIZE                                                 0x92FB
        #define GL_OFFSET                                                     0x92FC
        #define GL_BLOCK_INDEX                                                0x92FD
        #define GL_ARRAY_STRIDE                                               0x92FE
        #define GL_MATRIX_STRIDE                                              0x92FF
        #define GL_IS_ROW_MAJOR                                               0x9300
        #define GL_ATOMIC_COUNTER_BUFFER_INDEX                                0x9301
        #define GL_BUFFER_BINDING                                             0x9302
        #define GL_BUFFER_DATA_SIZE                                           0x9303
        #define GL_NUM_ACTIVE_VARIABLES                                       0x9304
        #define GL_ACTIVE_VARIABLES                                           0x9305
        #define GL_REFERENCED_BY_VERTEX_SHADER                                0x9306
        #define GL_REFERENCED_BY_TESS_CONTROL_SHADER                          0x9307
        #define GL_REFERENCED_BY_TESS_EVALUATION_SHADER                       0x9308
        #define GL_REFERENCED_BY_GEOMETRY_SHADER                              0x9309
        #define GL_REFERENCED_BY_FRAGMENT_SHADER                              0x930A
        #define GL_REFERENCED_BY_COMPUTE_SHADER                               0x930B
        #define GL_TOP_LEVEL_ARRAY_SIZE                                       0x930C
        #define GL_TOP_LEVEL_ARRAY_STRIDE                                     0x930D
        #define GL_LOCATION                                                   0x930E
        #define GL_LOCATION_INDEX                                             0x930F
        #define GL_FRAMEBUFFER_DEFAULT_WIDTH                                  0x9310
        #define GL_FRAMEBUFFER_DEFAULT_HEIGHT                                 0x9311
        #define GL_FRAMEBUFFER_DEFAULT_LAYERS                                 0x9312
        #define GL_FRAMEBUFFER_DEFAULT_SAMPLES                                0x9313
        #define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS                 0x9314
        #define GL_MAX_FRAMEBUFFER_WIDTH                                      0x9315
        #define GL_MAX_FRAMEBUFFER_HEIGHT                                     0x9316
        #define GL_MAX_FRAMEBUFFER_LAYERS                                     0x9317
        #define GL_MAX_FRAMEBUFFER_SAMPLES                                    0x9318
        #define GL_LOCATION_COMPONENT                                         0x934A
        #define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX                            0x934B
        #define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE                           0x934C
        #define GL_CLEAR_TEXTURE                                              0x9365
        #define GL_NUM_SAMPLE_COUNTS                                          0x9380

        /* End of GLenums */

        /* Prototypes */
        typedef void (OPEN_GL_API * PFN_GLACTIVESHADERPROGRAM)(
            uint32 pipeline,
            uint32 program);
        typedef void (OPEN_GL_API * PFN_GLACTIVETEXTURE)(
            uint32 texture);
        typedef void (OPEN_GL_API * PFN_GLATTACHSHADER)(
            uint32 program,
            uint32 shader);
        typedef void (OPEN_GL_API * PFN_GLBEGINCONDITIONALRENDER)(
            uint32 id,
            uint32 mode);
        typedef void (OPEN_GL_API * PFN_GLBEGINQUERY)(
            uint32 target,
            uint32 id);
        typedef void (OPEN_GL_API * PFN_GLBEGINQUERYINDEXED)(
            uint32 target,
            uint32 index,
            uint32 id);
        typedef void (OPEN_GL_API * PFN_GLBEGINTRANSFORMFEEDBACK)(
            uint32 primitiveMode);
        typedef void (OPEN_GL_API * PFN_GLBINDATTRIBLOCATION)(
            uint32 program,
            uint32 index,
            const char * name);
        typedef void (OPEN_GL_API * PFN_GLBINDBUFFER)(
            uint32 target,
            uint32 buffer);
        typedef void (OPEN_GL_API * PFN_GLBINDBUFFERBASE)(
            uint32 target,
            uint32 index,
            uint32 buffer);
        typedef void (OPEN_GL_API * PFN_GLBINDBUFFERRANGE)(
            uint32 target,
            uint32 index,
            uint32 buffer,
            ptrdiff_t offset,
            ptrdiff_t size);
        typedef void (OPEN_GL_API * PFN_GLBINDBUFFERSBASE)(
            uint32 target,
            uint32 first,
            int32 count,
            const uint32 * buffers);
        typedef void (OPEN_GL_API * PFN_GLBINDBUFFERSRANGE)(
            uint32 target,
            uint32 first,
            int32 count,
            const uint32 * buffers,
            const ptrdiff_t * offsets,
            const ptrdiff_t * sizes);
        typedef void (OPEN_GL_API * PFN_GLBINDFRAGDATALOCATION)(
            uint32 program,
            uint32 color,
            const char * name);
        typedef void (OPEN_GL_API * PFN_GLBINDFRAGDATALOCATIONINDEXED)(
            uint32 program,
            uint32 colorNumber,
            uint32 index,
            const char * name);
        typedef void (OPEN_GL_API * PFN_GLBINDFRAMEBUFFER)(
            uint32 target,
            uint32 framebuffer);
        typedef void (OPEN_GL_API * PFN_GLBINDIMAGETEXTURE)(
            uint32 unit,
            uint32 texture,
            int32 level,
            uint8 layered,
            int32 layer,
            uint32 access,
            uint32 format);
        typedef void (OPEN_GL_API * PFN_GLBINDIMAGETEXTURES)(
            uint32 first,
            int32 count,
            const uint32 * textures);
        typedef void (OPEN_GL_API * PFN_GLBINDPROGRAMPIPELINE)(
            uint32 pipeline);
        typedef void (OPEN_GL_API * PFN_GLBINDRENDERBUFFER)(
            uint32 target,
            uint32 renderbuffer);
        typedef void (OPEN_GL_API * PFN_GLBINDSAMPLER)(
            uint32 unit,
            uint32 sampler);
        typedef void (OPEN_GL_API * PFN_GLBINDSAMPLERS)(
            uint32 first,
            int32 count,
            const uint32 * samplers);
        typedef void (OPEN_GL_API * PFN_GLBINDTEXTURE)(
            uint32 target,
            uint32 texture);
        typedef void (OPEN_GL_API * PFN_GLBINDTEXTUREUNIT)(
            uint32 unit,
            uint32 texture);
        typedef void (OPEN_GL_API * PFN_GLBINDTEXTURES)(
            uint32 first,
            int32 count,
            const uint32 * textures);
        typedef void (OPEN_GL_API * PFN_GLBINDTRANSFORMFEEDBACK)(
            uint32 target,
            uint32 id);
        typedef void (OPEN_GL_API * PFN_GLBINDVERTEXARRAY)(
            uint32 array);
        typedef void (OPEN_GL_API * PFN_GLBINDVERTEXBUFFER)(
            uint32 bindingindex,
            uint32 buffer,
            ptrdiff_t offset,
            int32 stride);
        typedef void (OPEN_GL_API * PFN_GLBINDVERTEXBUFFERS)(
            uint32 first,
            int32 count,
            const uint32 * buffers,
            const ptrdiff_t * offsets,
            const int32 * strides);
        typedef void (OPEN_GL_API * PFN_GLBLENDCOLOR)(
            float red,
            float green,
            float blue,
            float alpha);
        typedef void (OPEN_GL_API * PFN_GLBLENDEQUATION)(
            uint32 mode);
        typedef void (OPEN_GL_API * PFN_GLBLENDEQUATIONSEPARATE)(
            uint32 modeRGB,
            uint32 modeAlpha);
        typedef void (OPEN_GL_API * PFN_GLBLENDEQUATIONSEPARATEI)(
            uint32 buf,
            uint32 modeRGB,
            uint32 modeAlpha);
        typedef void (OPEN_GL_API * PFN_GLBLENDEQUATIONI)(
            uint32 buf,
            uint32 mode);
        typedef void (OPEN_GL_API * PFN_GLBLENDFUNC)(
            uint32 sfactor,
            uint32 dfactor);
        typedef void (OPEN_GL_API * PFN_GLBLENDFUNCSEPARATE)(
            uint32 sfactorRGB,
            uint32 dfactorRGB,
            uint32 sfactorAlpha,
            uint32 dfactorAlpha);
        typedef void (OPEN_GL_API * PFN_GLBLENDFUNCSEPARATEI)(
            uint32 buf,
            uint32 srcRGB,
            uint32 dstRGB,
            uint32 srcAlpha,
            uint32 dstAlpha);
        typedef void (OPEN_GL_API * PFN_GLBLENDFUNCI)(
            uint32 buf,
            uint32 src,
            uint32 dst);
        typedef void (OPEN_GL_API * PFN_GLBLITFRAMEBUFFER)(
            int32 srcX0,
            int32 srcY0,
            int32 srcX1,
            int32 srcY1,
            int32 dstX0,
            int32 dstY0,
            int32 dstX1,
            int32 dstY1,
            uint32 mask,
            uint32 filter);
        typedef void (OPEN_GL_API * PFN_GLBLITNAMEDFRAMEBUFFER)(
            uint32 readFramebuffer,
            uint32 drawFramebuffer,
            int32 srcX0,
            int32 srcY0,
            int32 srcX1,
            int32 srcY1,
            int32 dstX0,
            int32 dstY0,
            int32 dstX1,
            int32 dstY1,
            uint32 mask,
            uint32 filter);
        typedef void (OPEN_GL_API * PFN_GLBUFFERDATA)(
            uint32 target,
            ptrdiff_t size,
            const void * data,
            uint32 usage);
        typedef void (OPEN_GL_API * PFN_GLBUFFERSTORAGE)(
            uint32 target,
            ptrdiff_t size,
            const void * data,
            uint32 flags);
        typedef void (OPEN_GL_API * PFN_GLBUFFERSUBDATA)(
            uint32 target,
            ptrdiff_t offset,
            ptrdiff_t size,
            const void * data);
        typedef uint32 (OPEN_GL_API * PFN_GLCHECKFRAMEBUFFERSTATUS)(
            uint32 target);
        typedef uint32 (OPEN_GL_API * PFN_GLCHECKNAMEDFRAMEBUFFERSTATUS)(
            uint32 framebuffer,
            uint32 target);
        typedef void (OPEN_GL_API * PFN_GLCLAMPCOLOR)(
            uint32 target,
            uint32 clamp);
        typedef void (OPEN_GL_API * PFN_GLCLEAR)(
            uint32 mask);
        typedef void (OPEN_GL_API * PFN_GLCLEARBUFFERDATA)(
            uint32 target,
            uint32 internalformat,
            uint32 format,
            uint32 type,
            const void * data);
        typedef void (OPEN_GL_API * PFN_GLCLEARBUFFERSUBDATA)(
            uint32 target,
            uint32 internalformat,
            ptrdiff_t offset,
            ptrdiff_t size,
            uint32 format,
            uint32 type,
            const void * data);
        typedef void (OPEN_GL_API * PFN_GLCLEARBUFFERFI)(
            uint32 buffer,
            int32 drawbuffer,
            float depth,
            int32 stencil);
        typedef void (OPEN_GL_API * PFN_GLCLEARBUFFERFV)(
            uint32 buffer,
            int32 drawbuffer,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLCLEARBUFFERIV)(
            uint32 buffer,
            int32 drawbuffer,
            const int32 * value);
        typedef void (OPEN_GL_API * PFN_GLCLEARBUFFERUIV)(
            uint32 buffer,
            int32 drawbuffer,
            const uint32 * value);
        typedef void (OPEN_GL_API * PFN_GLCLEARCOLOR)(
            float red,
            float green,
            float blue,
            float alpha);
        typedef void (OPEN_GL_API * PFN_GLCLEARDEPTH)(
            double depth);
        typedef void (OPEN_GL_API * PFN_GLCLEARDEPTHF)(
            float d);
        typedef void (OPEN_GL_API * PFN_GLCLEARNAMEDBUFFERDATA)(
            uint32 buffer,
            uint32 internalformat,
            uint32 format,
            uint32 type,
            const void * data);
        typedef void (OPEN_GL_API * PFN_GLCLEARNAMEDBUFFERSUBDATA)(
            uint32 buffer,
            uint32 internalformat,
            ptrdiff_t offset,
            int32 size,
            uint32 format,
            uint32 type,
            const void * data);
        typedef void (OPEN_GL_API * PFN_GLCLEARNAMEDFRAMEBUFFERFI)(
            uint32 framebuffer,
            uint32 buffer,
            const float depth,
            int32 stencil);
        typedef void (OPEN_GL_API * PFN_GLCLEARNAMEDFRAMEBUFFERFV)(
            uint32 framebuffer,
            uint32 buffer,
            int32 drawbuffer,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLCLEARNAMEDFRAMEBUFFERIV)(
            uint32 framebuffer,
            uint32 buffer,
            int32 drawbuffer,
            const int32 * value);
        typedef void (OPEN_GL_API * PFN_GLCLEARNAMEDFRAMEBUFFERUIV)(
            uint32 framebuffer,
            uint32 buffer,
            int32 drawbuffer,
            const uint32 * value);
        typedef void (OPEN_GL_API * PFN_GLCLEARSTENCIL)(
            int32 s);
        typedef void (OPEN_GL_API * PFN_GLCLEARTEXIMAGE)(
            uint32 texture,
            int32 level,
            uint32 format,
            uint32 type,
            const void * data);
        typedef void (OPEN_GL_API * PFN_GLCLEARTEXSUBIMAGE)(
            uint32 texture,
            int32 level,
            int32 xoffset,
            int32 yoffset,
            int32 zoffset,
            int32 width,
            int32 height,
            int32 depth,
            uint32 format,
            uint32 type,
            const void * data);
        typedef uint32 (OPEN_GL_API * PFN_GLCLIENTWAITSYNC)(
            void * sync,
            uint32 flags,
            uint64 timeout);
        typedef void (OPEN_GL_API * PFN_GLCOLORMASK)(
            uint8 red,
            uint8 green,
            uint8 blue,
            uint8 alpha);
        typedef void (OPEN_GL_API * PFN_GLCOLORMASKI)(
            uint32 index,
            uint8 r,
            uint8 g,
            uint8 b,
            uint8 a);
        typedef void (OPEN_GL_API * PFN_GLCOLORP3UI)(
            uint32 type,
            uint32 color);
        typedef void (OPEN_GL_API * PFN_GLCOLORP3UIV)(
            uint32 type,
            const uint32 * color);
        typedef void (OPEN_GL_API * PFN_GLCOLORP4UI)(
            uint32 type,
            uint32 color);
        typedef void (OPEN_GL_API * PFN_GLCOLORP4UIV)(
            uint32 type,
            const uint32 * color);
        typedef void (OPEN_GL_API * PFN_GLCOMPILESHADER)(
            uint32 shader);
        typedef void (OPEN_GL_API * PFN_GLCOMPRESSEDTEXIMAGE1D)(
            uint32 target,
            int32 level,
            uint32 internalformat,
            int32 width,
            int32 border,
            int32 imageSize,
            const void * data);
        typedef void (OPEN_GL_API * PFN_GLCOMPRESSEDTEXIMAGE2D)(
            uint32 target,
            int32 level,
            uint32 internalformat,
            int32 width,
            int32 height,
            int32 border,
            int32 imageSize,
            const void * data);
        typedef void (OPEN_GL_API * PFN_GLCOMPRESSEDTEXIMAGE3D)(
            uint32 target,
            int32 level,
            uint32 internalformat,
            int32 width,
            int32 height,
            int32 depth,
            int32 border,
            int32 imageSize,
            const void * data);
        typedef void (OPEN_GL_API * PFN_GLCOMPRESSEDTEXSUBIMAGE1D)(
            uint32 target,
            int32 level,
            int32 xoffset,
            int32 width,
            uint32 format,
            int32 imageSize,
            const void * data);
        typedef void (OPEN_GL_API * PFN_GLCOMPRESSEDTEXSUBIMAGE2D)(
            uint32 target,
            int32 level,
            int32 xoffset,
            int32 yoffset,
            int32 width,
            int32 height,
            uint32 format,
            int32 imageSize,
            const void * data);
        typedef void (OPEN_GL_API * PFN_GLCOMPRESSEDTEXSUBIMAGE3D)(
            uint32 target,
            int32 level,
            int32 xoffset,
            int32 yoffset,
            int32 zoffset,
            int32 width,
            int32 height,
            int32 depth,
            uint32 format,
            int32 imageSize,
            const void * data);
        typedef void (OPEN_GL_API * PFN_GLCOMPRESSEDTEXTURESUBIMAGE1D)(
            uint32 texture,
            int32 level,
            int32 xoffset,
            int32 width,
            uint32 format,
            int32 imageSize,
            const void * data);
        typedef void (OPEN_GL_API * PFN_GLCOMPRESSEDTEXTURESUBIMAGE2D)(
            uint32 texture,
            int32 level,
            int32 xoffset,
            int32 yoffset,
            int32 width,
            int32 height,
            uint32 format,
            int32 imageSize,
            const void * data);
        typedef void (OPEN_GL_API * PFN_GLCOMPRESSEDTEXTURESUBIMAGE3D)(
            uint32 texture,
            int32 level,
            int32 xoffset,
            int32 yoffset,
            int32 zoffset,
            int32 width,
            int32 height,
            int32 depth,
            uint32 format,
            int32 imageSize,
            const void * data);
        typedef void (OPEN_GL_API * PFN_GLCOPYBUFFERSUBDATA)(
            uint32 readTarget,
            uint32 writeTarget,
            ptrdiff_t readOffset,
            ptrdiff_t writeOffset,
            ptrdiff_t size);
        typedef void (OPEN_GL_API * PFN_GLCOPYIMAGESUBDATA)(
            uint32 srcName,
            uint32 srcTarget,
            int32 srcLevel,
            int32 srcX,
            int32 srcY,
            int32 srcZ,
            uint32 dstName,
            uint32 dstTarget,
            int32 dstLevel,
            int32 dstX,
            int32 dstY,
            int32 dstZ,
            int32 srcWidth,
            int32 srcHeight,
            int32 srcDepth);
        typedef void (OPEN_GL_API * PFN_GLCOPYNAMEDBUFFERSUBDATA)(
            uint32 readBuffer,
            uint32 writeBuffer,
            ptrdiff_t readOffset,
            ptrdiff_t writeOffset,
            int32 size);
        typedef void (OPEN_GL_API * PFN_GLCOPYTEXIMAGE1D)(
            uint32 target,
            int32 level,
            uint32 internalformat,
            int32 x,
            int32 y,
            int32 width,
            int32 border);
        typedef void (OPEN_GL_API * PFN_GLCOPYTEXIMAGE2D)(
            uint32 target,
            int32 level,
            uint32 internalformat,
            int32 x,
            int32 y,
            int32 width,
            int32 height,
            int32 border);
        typedef void (OPEN_GL_API * PFN_GLCOPYTEXSUBIMAGE1D)(
            uint32 target,
            int32 level,
            int32 xoffset,
            int32 x,
            int32 y,
            int32 width);
        typedef void (OPEN_GL_API * PFN_GLCOPYTEXSUBIMAGE2D)(
            uint32 target,
            int32 level,
            int32 xoffset,
            int32 yoffset,
            int32 x,
            int32 y,
            int32 width,
            int32 height);
        typedef void (OPEN_GL_API * PFN_GLCOPYTEXSUBIMAGE3D)(
            uint32 target,
            int32 level,
            int32 xoffset,
            int32 yoffset,
            int32 zoffset,
            int32 x,
            int32 y,
            int32 width,
            int32 height);
        typedef void (OPEN_GL_API * PFN_GLCOPYTEXTURESUBIMAGE1D)(
            uint32 texture,
            int32 level,
            int32 xoffset,
            int32 x,
            int32 y,
            int32 width);
        typedef void (OPEN_GL_API * PFN_GLCOPYTEXTURESUBIMAGE2D)(
            uint32 texture,
            int32 level,
            int32 xoffset,
            int32 yoffset,
            int32 x,
            int32 y,
            int32 width,
            int32 height);
        typedef void (OPEN_GL_API * PFN_GLCOPYTEXTURESUBIMAGE3D)(
            uint32 texture,
            int32 level,
            int32 xoffset,
            int32 yoffset,
            int32 zoffset,
            int32 x,
            int32 y,
            int32 width,
            int32 height);
        typedef void (OPEN_GL_API * PFN_GLCREATEBUFFERS)(
            int32 n,
            uint32 * buffers);
        typedef void (OPEN_GL_API * PFN_GLCREATEFRAMEBUFFERS)(
            int32 n,
            uint32 * framebuffers);
        typedef uint32 (OPEN_GL_API * PFN_GLCREATEPROGRAM)();
        typedef void (OPEN_GL_API * PFN_GLCREATEPROGRAMPIPELINES)(
            int32 n,
            uint32 * pipelines);
        typedef void (OPEN_GL_API * PFN_GLCREATEQUERIES)(
            uint32 target,
            int32 n,
            uint32 * ids);
        typedef void (OPEN_GL_API * PFN_GLCREATERENDERBUFFERS)(
            int32 n,
            uint32 * renderbuffers);
        typedef void (OPEN_GL_API * PFN_GLCREATESAMPLERS)(
            int32 n,
            uint32 * samplers);
        typedef uint32 (OPEN_GL_API * PFN_GLCREATESHADER)(
            uint32 type);
        typedef uint32 (OPEN_GL_API * PFN_GLCREATESHADERPROGRAMV)(
            uint32 type,
            int32 count,
            const char *const* strings);
        typedef void (OPEN_GL_API * PFN_GLCREATETEXTURES)(
            uint32 target,
            int32 n,
            uint32 * textures);
        typedef void (OPEN_GL_API * PFN_GLCREATETRANSFORMFEEDBACKS)(
            int32 n,
            uint32 * ids);
        typedef void (OPEN_GL_API * PFN_GLCREATEVERTEXARRAYS)(
            int32 n,
            uint32 * arrays);
        typedef void (OPEN_GL_API * PFN_GLCULLFACE)(
            uint32 mode);
        typedef void (OPEN_GL_API * PFN_GLDEBUGMESSAGECALLBACK)(
            GLDEBUGPROC callback,
            const void * userParam);
        typedef void (OPEN_GL_API * PFN_GLDEBUGMESSAGECONTROL)(
            uint32 source,
            uint32 type,
            uint32 severity,
            int32 count,
            const uint32 * ids,
            uint8 enabled);
        typedef void (OPEN_GL_API * PFN_GLDEBUGMESSAGEINSERT)(
            uint32 source,
            uint32 type,
            uint32 id,
            uint32 severity,
            int32 length,
            const char * buf);
        typedef void (OPEN_GL_API * PFN_GLDELETEBUFFERS)(
            int32 n,
            const uint32 * buffers);
        typedef void (OPEN_GL_API * PFN_GLDELETEFRAMEBUFFERS)(
            int32 n,
            const uint32 * framebuffers);
        typedef void (OPEN_GL_API * PFN_GLDELETEPROGRAM)(
            uint32 program);
        typedef void (OPEN_GL_API * PFN_GLDELETEPROGRAMPIPELINES)(
            int32 n,
            const uint32 * pipelines);
        typedef void (OPEN_GL_API * PFN_GLDELETEQUERIES)(
            int32 n,
            const uint32 * ids);
        typedef void (OPEN_GL_API * PFN_GLDELETERENDERBUFFERS)(
            int32 n,
            const uint32 * renderbuffers);
        typedef void (OPEN_GL_API * PFN_GLDELETESAMPLERS)(
            int32 count,
            const uint32 * samplers);
        typedef void (OPEN_GL_API * PFN_GLDELETESHADER)(
            uint32 shader);
        typedef void (OPEN_GL_API * PFN_GLDELETESYNC)(
            void * sync);
        typedef void (OPEN_GL_API * PFN_GLDELETETEXTURES)(
            int32 n,
            const uint32 * textures);
        typedef void (OPEN_GL_API * PFN_GLDELETETRANSFORMFEEDBACKS)(
            int32 n,
            const uint32 * ids);
        typedef void (OPEN_GL_API * PFN_GLDELETEVERTEXARRAYS)(
            int32 n,
            const uint32 * arrays);
        typedef void (OPEN_GL_API * PFN_GLDEPTHFUNC)(
            uint32 func);
        typedef void (OPEN_GL_API * PFN_GLDEPTHMASK)(
            uint8 flag);
        typedef void (OPEN_GL_API * PFN_GLDEPTHRANGE)(
            double near,
            double far);
        typedef void (OPEN_GL_API * PFN_GLDEPTHRANGEARRAYV)(
            uint32 first,
            int32 count,
            const double * v);
        typedef void (OPEN_GL_API * PFN_GLDEPTHRANGEINDEXED)(
            uint32 index,
            double n,
            double f);
        typedef void (OPEN_GL_API * PFN_GLDEPTHRANGEF)(
            float n,
            float f);
        typedef void (OPEN_GL_API * PFN_GLDETACHSHADER)(
            uint32 program,
            uint32 shader);
        typedef void (OPEN_GL_API * PFN_GLDISABLE)(
            uint32 cap);
        typedef void (OPEN_GL_API * PFN_GLDISABLEVERTEXARRAYATTRIB)(
            uint32 vaobj,
            uint32 index);
        typedef void (OPEN_GL_API * PFN_GLDISABLEVERTEXATTRIBARRAY)(
            uint32 index);
        typedef void (OPEN_GL_API * PFN_GLDISABLEI)(
            uint32 target,
            uint32 index);
        typedef void (OPEN_GL_API * PFN_GLDISPATCHCOMPUTE)(
            uint32 num_groups_x,
            uint32 num_groups_y,
            uint32 num_groups_z);
        typedef void (OPEN_GL_API * PFN_GLDISPATCHCOMPUTEINDIRECT)(
            ptrdiff_t indirect);
        typedef void (OPEN_GL_API * PFN_GLDRAWARRAYS)(
            uint32 mode,
            int32 first,
            int32 count);
        typedef void (OPEN_GL_API * PFN_GLDRAWARRAYSINDIRECT)(
            uint32 mode,
            const void * indirect);
        typedef void (OPEN_GL_API * PFN_GLDRAWARRAYSINSTANCED)(
            uint32 mode,
            int32 first,
            int32 count,
            int32 instancecount);
        typedef void (OPEN_GL_API * PFN_GLDRAWARRAYSINSTANCEDBASEINSTANCE)(
            uint32 mode,
            int32 first,
            int32 count,
            int32 instancecount,
            uint32 baseinstance);
        typedef void (OPEN_GL_API * PFN_GLDRAWBUFFER)(
            uint32 buf);
        typedef void (OPEN_GL_API * PFN_GLDRAWBUFFERS)(
            int32 n,
            const uint32 * bufs);
        typedef void (OPEN_GL_API * PFN_GLDRAWELEMENTS)(
            uint32 mode,
            int32 count,
            uint32 type,
            const void * indices);
        typedef void (OPEN_GL_API * PFN_GLDRAWELEMENTSBASEVERTEX)(
            uint32 mode,
            int32 count,
            uint32 type,
            const void * indices,
            int32 basevertex);
        typedef void (OPEN_GL_API * PFN_GLDRAWELEMENTSINDIRECT)(
            uint32 mode,
            uint32 type,
            const void * indirect);
        typedef void (OPEN_GL_API * PFN_GLDRAWELEMENTSINSTANCED)(
            uint32 mode,
            int32 count,
            uint32 type,
            const void * indices,
            int32 instancecount);
        typedef void (OPEN_GL_API * PFN_GLDRAWELEMENTSINSTANCEDBASEINSTANCE)(
            uint32 mode,
            int32 count,
            uint32 type,
            const void * indices,
            int32 instancecount,
            uint32 baseinstance);
        typedef void (OPEN_GL_API * PFN_GLDRAWELEMENTSINSTANCEDBASEVERTEX)(
            uint32 mode,
            int32 count,
            uint32 type,
            const void * indices,
            int32 instancecount,
            int32 basevertex);
        typedef void (OPEN_GL_API * PFN_GLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCE)(
            uint32 mode,
            int32 count,
            uint32 type,
            const void * indices,
            int32 instancecount,
            int32 basevertex,
            uint32 baseinstance);
        typedef void (OPEN_GL_API * PFN_GLDRAWRANGEELEMENTS)(
            uint32 mode,
            uint32 start,
            uint32 end,
            int32 count,
            uint32 type,
            const void * indices);
        typedef void (OPEN_GL_API * PFN_GLDRAWRANGEELEMENTSBASEVERTEX)(
            uint32 mode,
            uint32 start,
            uint32 end,
            int32 count,
            uint32 type,
            const void * indices,
            int32 basevertex);
        typedef void (OPEN_GL_API * PFN_GLDRAWTRANSFORMFEEDBACK)(
            uint32 mode,
            uint32 id);
        typedef void (OPEN_GL_API * PFN_GLDRAWTRANSFORMFEEDBACKINSTANCED)(
            uint32 mode,
            uint32 id,
            int32 instancecount);
        typedef void (OPEN_GL_API * PFN_GLDRAWTRANSFORMFEEDBACKSTREAM)(
            uint32 mode,
            uint32 id,
            uint32 stream);
        typedef void (OPEN_GL_API * PFN_GLDRAWTRANSFORMFEEDBACKSTREAMINSTANCED)(
            uint32 mode,
            uint32 id,
            uint32 stream,
            int32 instancecount);
        typedef void (OPEN_GL_API * PFN_GLENABLE)(
            uint32 cap);
        typedef void (OPEN_GL_API * PFN_GLENABLEVERTEXARRAYATTRIB)(
            uint32 vaobj,
            uint32 index);
        typedef void (OPEN_GL_API * PFN_GLENABLEVERTEXATTRIBARRAY)(
            uint32 index);
        typedef void (OPEN_GL_API * PFN_GLENABLEI)(
            uint32 target,
            uint32 index);
        typedef void (OPEN_GL_API * PFN_GLENDCONDITIONALRENDER)();
        typedef void (OPEN_GL_API * PFN_GLENDQUERY)(
            uint32 target);
        typedef void (OPEN_GL_API * PFN_GLENDQUERYINDEXED)(
            uint32 target,
            uint32 index);
        typedef void (OPEN_GL_API * PFN_GLENDTRANSFORMFEEDBACK)();
        typedef void * (OPEN_GL_API * PFN_GLFENCESYNC)(
            uint32 condition,
            uint32 flags);
        typedef void (OPEN_GL_API * PFN_GLFINISH)();
        typedef void (OPEN_GL_API * PFN_GLFLUSH)();
        typedef void (OPEN_GL_API * PFN_GLFLUSHMAPPEDBUFFERRANGE)(
            uint32 target,
            ptrdiff_t offset,
            ptrdiff_t length);
        typedef void (OPEN_GL_API * PFN_GLFLUSHMAPPEDNAMEDBUFFERRANGE)(
            uint32 buffer,
            ptrdiff_t offset,
            int32 length);
        typedef void (OPEN_GL_API * PFN_GLFRAMEBUFFERPARAMETERI)(
            uint32 target,
            uint32 pname,
            int32 param);
        typedef void (OPEN_GL_API * PFN_GLFRAMEBUFFERRENDERBUFFER)(
            uint32 target,
            uint32 attachment,
            uint32 renderbuffertarget,
            uint32 renderbuffer);
        typedef void (OPEN_GL_API * PFN_GLFRAMEBUFFERTEXTURE)(
            uint32 target,
            uint32 attachment,
            uint32 texture,
            int32 level);
        typedef void (OPEN_GL_API * PFN_GLFRAMEBUFFERTEXTURE1D)(
            uint32 target,
            uint32 attachment,
            uint32 textarget,
            uint32 texture,
            int32 level);
        typedef void (OPEN_GL_API * PFN_GLFRAMEBUFFERTEXTURE2D)(
            uint32 target,
            uint32 attachment,
            uint32 textarget,
            uint32 texture,
            int32 level);
        typedef void (OPEN_GL_API * PFN_GLFRAMEBUFFERTEXTURE3D)(
            uint32 target,
            uint32 attachment,
            uint32 textarget,
            uint32 texture,
            int32 level,
            int32 zoffset);
        typedef void (OPEN_GL_API * PFN_GLFRAMEBUFFERTEXTURELAYER)(
            uint32 target,
            uint32 attachment,
            uint32 texture,
            int32 level,
            int32 layer);
        typedef void (OPEN_GL_API * PFN_GLFRONTFACE)(
            uint32 mode);
        typedef void (OPEN_GL_API * PFN_GLGENBUFFERS)(
            int32 n,
            uint32 * buffers);
        typedef void (OPEN_GL_API * PFN_GLGENFRAMEBUFFERS)(
            int32 n,
            uint32 * framebuffers);
        typedef void (OPEN_GL_API * PFN_GLGENPROGRAMPIPELINES)(
            int32 n,
            uint32 * pipelines);
        typedef void (OPEN_GL_API * PFN_GLGENQUERIES)(
            int32 n,
            uint32 * ids);
        typedef void (OPEN_GL_API * PFN_GLGENRENDERBUFFERS)(
            int32 n,
            uint32 * renderbuffers);
        typedef void (OPEN_GL_API * PFN_GLGENSAMPLERS)(
            int32 count,
            uint32 * samplers);
        typedef void (OPEN_GL_API * PFN_GLGENTEXTURES)(
            int32 n,
            uint32 * textures);
        typedef void (OPEN_GL_API * PFN_GLGENTRANSFORMFEEDBACKS)(
            int32 n,
            uint32 * ids);
        typedef void (OPEN_GL_API * PFN_GLGENVERTEXARRAYS)(
            int32 n,
            uint32 * arrays);
        typedef void (OPEN_GL_API * PFN_GLGENERATEMIPMAP)(
            uint32 target);
        typedef void (OPEN_GL_API * PFN_GLGENERATETEXTUREMIPMAP)(
            uint32 texture);
        typedef void (OPEN_GL_API * PFN_GLGETACTIVEATOMICCOUNTERBUFFERIV)(
            uint32 program,
            uint32 bufferIndex,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETACTIVEATTRIB)(
            uint32 program,
            uint32 index,
            int32 bufSize,
            int32 * length,
            int32 * size,
            uint32 * type,
            char * name);
        typedef void (OPEN_GL_API * PFN_GLGETACTIVESUBROUTINENAME)(
            uint32 program,
            uint32 shadertype,
            uint32 index,
            int32 bufsize,
            int32 * length,
            char * name);
        typedef void (OPEN_GL_API * PFN_GLGETACTIVESUBROUTINEUNIFORMNAME)(
            uint32 program,
            uint32 shadertype,
            uint32 index,
            int32 bufsize,
            int32 * length,
            char * name);
        typedef void (OPEN_GL_API * PFN_GLGETACTIVESUBROUTINEUNIFORMIV)(
            uint32 program,
            uint32 shadertype,
            uint32 index,
            uint32 pname,
            int32 * values);
        typedef void (OPEN_GL_API * PFN_GLGETACTIVEUNIFORM)(
            uint32 program,
            uint32 index,
            int32 bufSize,
            int32 * length,
            int32 * size,
            uint32 * type,
            char * name);
        typedef void (OPEN_GL_API * PFN_GLGETACTIVEUNIFORMBLOCKNAME)(
            uint32 program,
            uint32 uniformBlockIndex,
            int32 bufSize,
            int32 * length,
            char * uniformBlockName);
        typedef void (OPEN_GL_API * PFN_GLGETACTIVEUNIFORMBLOCKIV)(
            uint32 program,
            uint32 uniformBlockIndex,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETACTIVEUNIFORMNAME)(
            uint32 program,
            uint32 uniformIndex,
            int32 bufSize,
            int32 * length,
            char * uniformName);
        typedef void (OPEN_GL_API * PFN_GLGETACTIVEUNIFORMSIV)(
            uint32 program,
            int32 uniformCount,
            const uint32 * uniformIndices,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETATTACHEDSHADERS)(
            uint32 program,
            int32 maxCount,
            int32 * count,
            uint32 * shaders);
        typedef int32 (OPEN_GL_API * PFN_GLGETATTRIBLOCATION)(
            uint32 program,
            const char * name);
        typedef void (OPEN_GL_API * PFN_GLGETBOOLEANI_V)(
            uint32 target,
            uint32 index,
            uint8 * data);
        typedef void (OPEN_GL_API * PFN_GLGETBOOLEANV)(
            uint32 pname,
            uint8 * data);
        typedef void (OPEN_GL_API * PFN_GLGETBUFFERPARAMETERI64V)(
            uint32 target,
            uint32 pname,
            int64 * params);
        typedef void (OPEN_GL_API * PFN_GLGETBUFFERPARAMETERIV)(
            uint32 target,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETBUFFERPOINTERV)(
            uint32 target,
            uint32 pname,
            void ** params);
        typedef void (OPEN_GL_API * PFN_GLGETBUFFERSUBDATA)(
            uint32 target,
            ptrdiff_t offset,
            ptrdiff_t size,
            void * data);
        typedef void (OPEN_GL_API * PFN_GLGETCOMPRESSEDTEXIMAGE)(
            uint32 target,
            int32 level,
            void * img);
        typedef void (OPEN_GL_API * PFN_GLGETCOMPRESSEDTEXTUREIMAGE)(
            uint32 texture,
            int32 level,
            int32 bufSize,
            void * pixels);
        typedef uint32 (OPEN_GL_API * PFN_GLGETDEBUGMESSAGELOG)(
            uint32 count,
            int32 bufSize,
            uint32 * sources,
            uint32 * types,
            uint32 * ids,
            uint32 * severities,
            int32 * lengths,
            char * messageLog);
        typedef void (OPEN_GL_API * PFN_GLGETDOUBLEI_V)(
            uint32 target,
            uint32 index,
            double * data);
        typedef void (OPEN_GL_API * PFN_GLGETDOUBLEV)(
            uint32 pname,
            double * data);
        typedef uint32 (OPEN_GL_API * PFN_GLGETERROR)();
        typedef void (OPEN_GL_API * PFN_GLGETFLOATI_V)(
            uint32 target,
            uint32 index,
            float * data);
        typedef void (OPEN_GL_API * PFN_GLGETFLOATV)(
            uint32 pname,
            float * data);
        typedef int32 (OPEN_GL_API * PFN_GLGETFRAGDATAINDEX)(
            uint32 program,
            const char * name);
        typedef int32 (OPEN_GL_API * PFN_GLGETFRAGDATALOCATION)(
            uint32 program,
            const char * name);
        typedef void (OPEN_GL_API * PFN_GLGETFRAMEBUFFERATTACHMENTPARAMETERIV)(
            uint32 target,
            uint32 attachment,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETFRAMEBUFFERPARAMETERIV)(
            uint32 target,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETINTEGER64I_V)(
            uint32 target,
            uint32 index,
            int64 * data);
        typedef void (OPEN_GL_API * PFN_GLGETINTEGER64V)(
            uint32 pname,
            int64 * data);
        typedef void (OPEN_GL_API * PFN_GLGETINTEGERI_V)(
            uint32 target,
            uint32 index,
            int32 * data);
        typedef void (OPEN_GL_API * PFN_GLGETINTEGERV)(
            uint32 pname,
            int32 * data);
        typedef void (OPEN_GL_API * PFN_GLGETINTERNALFORMATI64V)(
            uint32 target,
            uint32 internalformat,
            uint32 pname,
            int32 bufSize,
            int64 * params);
        typedef void (OPEN_GL_API * PFN_GLGETINTERNALFORMATIV)(
            uint32 target,
            uint32 internalformat,
            uint32 pname,
            int32 bufSize,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETMULTISAMPLEFV)(
            uint32 pname,
            uint32 index,
            float * val);
        typedef void (OPEN_GL_API * PFN_GLGETNAMEDBUFFERPARAMETERI64V)(
            uint32 buffer,
            uint32 pname,
            int64 * params);
        typedef void (OPEN_GL_API * PFN_GLGETNAMEDBUFFERPARAMETERIV)(
            uint32 buffer,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETNAMEDBUFFERPOINTERV)(
            uint32 buffer,
            uint32 pname,
            void ** params);
        typedef void (OPEN_GL_API * PFN_GLGETNAMEDBUFFERSUBDATA)(
            uint32 buffer,
            ptrdiff_t offset,
            int32 size,
            void * data);
        typedef void (OPEN_GL_API * PFN_GLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIV)(
            uint32 framebuffer,
            uint32 attachment,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETNAMEDFRAMEBUFFERPARAMETERIV)(
            uint32 framebuffer,
            uint32 pname,
            int32 * param);
        typedef void (OPEN_GL_API * PFN_GLGETNAMEDRENDERBUFFERPARAMETERIV)(
            uint32 renderbuffer,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETOBJECTLABEL)(
            uint32 identifier,
            uint32 name,
            int32 bufSize,
            int32 * length,
            char * label);
        typedef void (OPEN_GL_API * PFN_GLGETOBJECTPTRLABEL)(
            const void * ptr,
            int32 bufSize,
            int32 * length,
            char * label);
        typedef void (OPEN_GL_API * PFN_GLGETPOINTERV)(
            uint32 pname,
            void ** params);
        typedef void (OPEN_GL_API * PFN_GLGETPROGRAMBINARY)(
            uint32 program,
            int32 bufSize,
            int32 * length,
            uint32 * binaryFormat,
            void * binary);
        typedef void (OPEN_GL_API * PFN_GLGETPROGRAMINFOLOG)(
            uint32 program,
            int32 bufSize,
            int32 * length,
            char * infoLog);
        typedef void (OPEN_GL_API * PFN_GLGETPROGRAMINTERFACEIV)(
            uint32 program,
            uint32 programInterface,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETPROGRAMPIPELINEINFOLOG)(
            uint32 pipeline,
            int32 bufSize,
            int32 * length,
            char * infoLog);
        typedef void (OPEN_GL_API * PFN_GLGETPROGRAMPIPELINEIV)(
            uint32 pipeline,
            uint32 pname,
            int32 * params);
        typedef uint32 (OPEN_GL_API * PFN_GLGETPROGRAMRESOURCEINDEX)(
            uint32 program,
            uint32 programInterface,
            const char * name);
        typedef int32 (OPEN_GL_API * PFN_GLGETPROGRAMRESOURCELOCATION)(
            uint32 program,
            uint32 programInterface,
            const char * name);
        typedef int32 (OPEN_GL_API * PFN_GLGETPROGRAMRESOURCELOCATIONINDEX)(
            uint32 program,
            uint32 programInterface,
            const char * name);
        typedef void (OPEN_GL_API * PFN_GLGETPROGRAMRESOURCENAME)(
            uint32 program,
            uint32 programInterface,
            uint32 index,
            int32 bufSize,
            int32 * length,
            char * name);
        typedef void (OPEN_GL_API * PFN_GLGETPROGRAMRESOURCEIV)(
            uint32 program,
            uint32 programInterface,
            uint32 index,
            int32 propCount,
            const uint32 * props,
            int32 bufSize,
            int32 * length,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETPROGRAMSTAGEIV)(
            uint32 program,
            uint32 shadertype,
            uint32 pname,
            int32 * values);
        typedef void (OPEN_GL_API * PFN_GLGETPROGRAMIV)(
            uint32 program,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETQUERYBUFFEROBJECTI64V)(
            uint32 id,
            uint32 buffer,
            uint32 pname,
            ptrdiff_t offset);
        typedef void (OPEN_GL_API * PFN_GLGETQUERYBUFFEROBJECTIV)(
            uint32 id,
            uint32 buffer,
            uint32 pname,
            ptrdiff_t offset);
        typedef void (OPEN_GL_API * PFN_GLGETQUERYBUFFEROBJECTUI64V)(
            uint32 id,
            uint32 buffer,
            uint32 pname,
            ptrdiff_t offset);
        typedef void (OPEN_GL_API * PFN_GLGETQUERYBUFFEROBJECTUIV)(
            uint32 id,
            uint32 buffer,
            uint32 pname,
            ptrdiff_t offset);
        typedef void (OPEN_GL_API * PFN_GLGETQUERYINDEXEDIV)(
            uint32 target,
            uint32 index,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETQUERYOBJECTI64V)(
            uint32 id,
            uint32 pname,
            int64 * params);
        typedef void (OPEN_GL_API * PFN_GLGETQUERYOBJECTIV)(
            uint32 id,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETQUERYOBJECTUI64V)(
            uint32 id,
            uint32 pname,
            uint64 * params);
        typedef void (OPEN_GL_API * PFN_GLGETQUERYOBJECTUIV)(
            uint32 id,
            uint32 pname,
            uint32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETQUERYIV)(
            uint32 target,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETRENDERBUFFERPARAMETERIV)(
            uint32 target,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETSAMPLERPARAMETERIIV)(
            uint32 sampler,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETSAMPLERPARAMETERIUIV)(
            uint32 sampler,
            uint32 pname,
            uint32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETSAMPLERPARAMETERFV)(
            uint32 sampler,
            uint32 pname,
            float * params);
        typedef void (OPEN_GL_API * PFN_GLGETSAMPLERPARAMETERIV)(
            uint32 sampler,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETSHADERINFOLOG)(
            uint32 shader,
            int32 bufSize,
            int32 * length,
            char * infoLog);
        typedef void (OPEN_GL_API * PFN_GLGETSHADERPRECISIONFORMAT)(
            uint32 shadertype,
            uint32 precisiontype,
            int32 * range,
            int32 * precision);
        typedef void (OPEN_GL_API * PFN_GLGETSHADERSOURCE)(
            uint32 shader,
            int32 bufSize,
            int32 * length,
            char * source);
        typedef void (OPEN_GL_API * PFN_GLGETSHADERIV)(
            uint32 shader,
            uint32 pname,
            int32 * params);
        typedef const uint8 * (OPEN_GL_API * PFN_GLGETSTRING)(
            uint32 name);
        typedef const uint8 * (OPEN_GL_API * PFN_GLGETSTRINGI)(
            uint32 name,
            uint32 index);
        typedef uint32 (OPEN_GL_API * PFN_GLGETSUBROUTINEINDEX)(
            uint32 program,
            uint32 shadertype,
            const char * name);
        typedef int32 (OPEN_GL_API * PFN_GLGETSUBROUTINEUNIFORMLOCATION)(
            uint32 program,
            uint32 shadertype,
            const char * name);
        typedef void (OPEN_GL_API * PFN_GLGETSYNCIV)(
            void * sync,
            uint32 pname,
            int32 bufSize,
            int32 * length,
            int32 * values);
        typedef void (OPEN_GL_API * PFN_GLGETTEXIMAGE)(
            uint32 target,
            int32 level,
            uint32 format,
            uint32 type,
            void * pixels);
        typedef void (OPEN_GL_API * PFN_GLGETTEXLEVELPARAMETERFV)(
            uint32 target,
            int32 level,
            uint32 pname,
            float * params);
        typedef void (OPEN_GL_API * PFN_GLGETTEXLEVELPARAMETERIV)(
            uint32 target,
            int32 level,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETTEXPARAMETERIIV)(
            uint32 target,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETTEXPARAMETERIUIV)(
            uint32 target,
            uint32 pname,
            uint32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETTEXPARAMETERFV)(
            uint32 target,
            uint32 pname,
            float * params);
        typedef void (OPEN_GL_API * PFN_GLGETTEXPARAMETERIV)(
            uint32 target,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETTEXTUREIMAGE)(
            uint32 texture,
            int32 level,
            uint32 format,
            uint32 type,
            int32 bufSize,
            void * pixels);
        typedef void (OPEN_GL_API * PFN_GLGETTEXTURELEVELPARAMETERFV)(
            uint32 texture,
            int32 level,
            uint32 pname,
            float * params);
        typedef void (OPEN_GL_API * PFN_GLGETTEXTURELEVELPARAMETERIV)(
            uint32 texture,
            int32 level,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETTEXTUREPARAMETERIIV)(
            uint32 texture,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETTEXTUREPARAMETERIUIV)(
            uint32 texture,
            uint32 pname,
            uint32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETTEXTUREPARAMETERFV)(
            uint32 texture,
            uint32 pname,
            float * params);
        typedef void (OPEN_GL_API * PFN_GLGETTEXTUREPARAMETERIV)(
            uint32 texture,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETTRANSFORMFEEDBACKVARYING)(
            uint32 program,
            uint32 index,
            int32 bufSize,
            int32 * length,
            int32 * size,
            uint32 * type,
            char * name);
        typedef void (OPEN_GL_API * PFN_GLGETTRANSFORMFEEDBACKI64_V)(
            uint32 xfb,
            uint32 pname,
            uint32 index,
            int64 * param);
        typedef void (OPEN_GL_API * PFN_GLGETTRANSFORMFEEDBACKI_V)(
            uint32 xfb,
            uint32 pname,
            uint32 index,
            int32 * param);
        typedef void (OPEN_GL_API * PFN_GLGETTRANSFORMFEEDBACKIV)(
            uint32 xfb,
            uint32 pname,
            int32 * param);
        typedef uint32 (OPEN_GL_API * PFN_GLGETUNIFORMBLOCKINDEX)(
            uint32 program,
            const char * uniformBlockName);
        typedef void (OPEN_GL_API * PFN_GLGETUNIFORMINDICES)(
            uint32 program,
            int32 uniformCount,
            const char *const* uniformNames,
            uint32 * uniformIndices);
        typedef int32 (OPEN_GL_API * PFN_GLGETUNIFORMLOCATION)(
            uint32 program,
            const char * name);
        typedef void (OPEN_GL_API * PFN_GLGETUNIFORMSUBROUTINEUIV)(
            uint32 shadertype,
            int32 location,
            uint32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETUNIFORMDV)(
            uint32 program,
            int32 location,
            double * params);
        typedef void (OPEN_GL_API * PFN_GLGETUNIFORMFV)(
            uint32 program,
            int32 location,
            float * params);
        typedef void (OPEN_GL_API * PFN_GLGETUNIFORMIV)(
            uint32 program,
            int32 location,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETUNIFORMUIV)(
            uint32 program,
            int32 location,
            uint32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETVERTEXARRAYINDEXED64IV)(
            uint32 vaobj,
            uint32 index,
            uint32 pname,
            int64 * param);
        typedef void (OPEN_GL_API * PFN_GLGETVERTEXARRAYINDEXEDIV)(
            uint32 vaobj,
            uint32 index,
            uint32 pname,
            int32 * param);
        typedef void (OPEN_GL_API * PFN_GLGETVERTEXARRAYIV)(
            uint32 vaobj,
            uint32 pname,
            int32 * param);
        typedef void (OPEN_GL_API * PFN_GLGETVERTEXATTRIBIIV)(
            uint32 index,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETVERTEXATTRIBIUIV)(
            uint32 index,
            uint32 pname,
            uint32 * params);
        typedef void (OPEN_GL_API * PFN_GLGETVERTEXATTRIBLDV)(
            uint32 index,
            uint32 pname,
            double * params);
        typedef void (OPEN_GL_API * PFN_GLGETVERTEXATTRIBPOINTERV)(
            uint32 index,
            uint32 pname,
            void ** pointer);
        typedef void (OPEN_GL_API * PFN_GLGETVERTEXATTRIBDV)(
            uint32 index,
            uint32 pname,
            double * params);
        typedef void (OPEN_GL_API * PFN_GLGETVERTEXATTRIBFV)(
            uint32 index,
            uint32 pname,
            float * params);
        typedef void (OPEN_GL_API * PFN_GLGETVERTEXATTRIBIV)(
            uint32 index,
            uint32 pname,
            int32 * params);
        typedef void (OPEN_GL_API * PFN_GLHINT)(
            uint32 target,
            uint32 mode);
        typedef void (OPEN_GL_API * PFN_GLINVALIDATEBUFFERDATA)(
            uint32 buffer);
        typedef void (OPEN_GL_API * PFN_GLINVALIDATEBUFFERSUBDATA)(
            uint32 buffer,
            ptrdiff_t offset,
            ptrdiff_t length);
        typedef void (OPEN_GL_API * PFN_GLINVALIDATEFRAMEBUFFER)(
            uint32 target,
            int32 numAttachments,
            const uint32 * attachments);
        typedef void (OPEN_GL_API * PFN_GLINVALIDATENAMEDFRAMEBUFFERDATA)(
            uint32 framebuffer,
            int32 numAttachments,
            const uint32 * attachments);
        typedef void (OPEN_GL_API * PFN_GLINVALIDATENAMEDFRAMEBUFFERSUBDATA)(
            uint32 framebuffer,
            int32 numAttachments,
            const uint32 * attachments,
            int32 x,
            int32 y,
            int32 width,
            int32 height);
        typedef void (OPEN_GL_API * PFN_GLINVALIDATESUBFRAMEBUFFER)(
            uint32 target,
            int32 numAttachments,
            const uint32 * attachments,
            int32 x,
            int32 y,
            int32 width,
            int32 height);
        typedef void (OPEN_GL_API * PFN_GLINVALIDATETEXIMAGE)(
            uint32 texture,
            int32 level);
        typedef void (OPEN_GL_API * PFN_GLINVALIDATETEXSUBIMAGE)(
            uint32 texture,
            int32 level,
            int32 xoffset,
            int32 yoffset,
            int32 zoffset,
            int32 width,
            int32 height,
            int32 depth);
        typedef uint8 (OPEN_GL_API * PFN_GLISBUFFER)(
            uint32 buffer);
        typedef uint8 (OPEN_GL_API * PFN_GLISENABLED)(
            uint32 cap);
        typedef uint8 (OPEN_GL_API * PFN_GLISENABLEDI)(
            uint32 target,
            uint32 index);
        typedef uint8 (OPEN_GL_API * PFN_GLISFRAMEBUFFER)(
            uint32 framebuffer);
        typedef uint8 (OPEN_GL_API * PFN_GLISPROGRAM)(
            uint32 program);
        typedef uint8 (OPEN_GL_API * PFN_GLISPROGRAMPIPELINE)(
            uint32 pipeline);
        typedef uint8 (OPEN_GL_API * PFN_GLISQUERY)(
            uint32 id);
        typedef uint8 (OPEN_GL_API * PFN_GLISRENDERBUFFER)(
            uint32 renderbuffer);
        typedef uint8 (OPEN_GL_API * PFN_GLISSAMPLER)(
            uint32 sampler);
        typedef uint8 (OPEN_GL_API * PFN_GLISSHADER)(
            uint32 shader);
        typedef uint8 (OPEN_GL_API * PFN_GLISSYNC)(
            void * sync);
        typedef uint8 (OPEN_GL_API * PFN_GLISTEXTURE)(
            uint32 texture);
        typedef uint8 (OPEN_GL_API * PFN_GLISTRANSFORMFEEDBACK)(
            uint32 id);
        typedef uint8 (OPEN_GL_API * PFN_GLISVERTEXARRAY)(
            uint32 array);
        typedef void (OPEN_GL_API * PFN_GLLINEWIDTH)(
            float width);
        typedef void (OPEN_GL_API * PFN_GLLINKPROGRAM)(
            uint32 program);
        typedef void (OPEN_GL_API * PFN_GLLOGICOP)(
            uint32 opcode);
        typedef void * (OPEN_GL_API * PFN_GLMAPBUFFER)(
            uint32 target,
            uint32 access);
        typedef void * (OPEN_GL_API * PFN_GLMAPBUFFERRANGE)(
            uint32 target,
            ptrdiff_t offset,
            ptrdiff_t length,
            uint32 access);
        typedef void * (OPEN_GL_API * PFN_GLMAPNAMEDBUFFER)(
            uint32 buffer,
            uint32 access);
        typedef void * (OPEN_GL_API * PFN_GLMAPNAMEDBUFFERRANGE)(
            uint32 buffer,
            ptrdiff_t offset,
            int32 length,
            uint32 access);
        typedef void (OPEN_GL_API * PFN_GLMEMORYBARRIER)(
            uint32 barriers);
        typedef void (OPEN_GL_API * PFN_GLMINSAMPLESHADING)(
            float value);
        typedef void (OPEN_GL_API * PFN_GLMULTIDRAWARRAYS)(
            uint32 mode,
            const int32 * first,
            const int32 * count,
            int32 drawcount);
        typedef void (OPEN_GL_API * PFN_GLMULTIDRAWARRAYSINDIRECT)(
            uint32 mode,
            const void * indirect,
            int32 drawcount,
            int32 stride);
        typedef void (OPEN_GL_API * PFN_GLMULTIDRAWELEMENTS)(
            uint32 mode,
            const int32 * count,
            uint32 type,
            const void *const* indices,
            int32 drawcount);
        typedef void (OPEN_GL_API * PFN_GLMULTIDRAWELEMENTSBASEVERTEX)(
            uint32 mode,
            const int32 * count,
            uint32 type,
            const void *const* indices,
            int32 drawcount,
            const int32 * basevertex);
        typedef void (OPEN_GL_API * PFN_GLMULTIDRAWELEMENTSINDIRECT)(
            uint32 mode,
            uint32 type,
            const void * indirect,
            int32 drawcount,
            int32 stride);
        typedef void (OPEN_GL_API * PFN_GLMULTITEXCOORDP1UI)(
            uint32 texture,
            uint32 type,
            uint32 coords);
        typedef void (OPEN_GL_API * PFN_GLMULTITEXCOORDP1UIV)(
            uint32 texture,
            uint32 type,
            const uint32 * coords);
        typedef void (OPEN_GL_API * PFN_GLMULTITEXCOORDP2UI)(
            uint32 texture,
            uint32 type,
            uint32 coords);
        typedef void (OPEN_GL_API * PFN_GLMULTITEXCOORDP2UIV)(
            uint32 texture,
            uint32 type,
            const uint32 * coords);
        typedef void (OPEN_GL_API * PFN_GLMULTITEXCOORDP3UI)(
            uint32 texture,
            uint32 type,
            uint32 coords);
        typedef void (OPEN_GL_API * PFN_GLMULTITEXCOORDP3UIV)(
            uint32 texture,
            uint32 type,
            const uint32 * coords);
        typedef void (OPEN_GL_API * PFN_GLMULTITEXCOORDP4UI)(
            uint32 texture,
            uint32 type,
            uint32 coords);
        typedef void (OPEN_GL_API * PFN_GLMULTITEXCOORDP4UIV)(
            uint32 texture,
            uint32 type,
            const uint32 * coords);
        typedef void (OPEN_GL_API * PFN_GLNAMEDBUFFERDATA)(
            uint32 buffer,
            int32 size,
            const void * data,
            uint32 usage);
        typedef void (OPEN_GL_API * PFN_GLNAMEDBUFFERSTORAGE)(
            uint32 buffer,
            int32 size,
            const void * data,
            uint32 flags);
        typedef void (OPEN_GL_API * PFN_GLNAMEDBUFFERSUBDATA)(
            uint32 buffer,
            ptrdiff_t offset,
            int32 size,
            const void * data);
        typedef void (OPEN_GL_API * PFN_GLNAMEDFRAMEBUFFERDRAWBUFFER)(
            uint32 framebuffer,
            uint32 buf);
        typedef void (OPEN_GL_API * PFN_GLNAMEDFRAMEBUFFERDRAWBUFFERS)(
            uint32 framebuffer,
            int32 n,
            const uint32 * bufs);
        typedef void (OPEN_GL_API * PFN_GLNAMEDFRAMEBUFFERPARAMETERI)(
            uint32 framebuffer,
            uint32 pname,
            int32 param);
        typedef void (OPEN_GL_API * PFN_GLNAMEDFRAMEBUFFERREADBUFFER)(
            uint32 framebuffer,
            uint32 src);
        typedef void (OPEN_GL_API * PFN_GLNAMEDFRAMEBUFFERRENDERBUFFER)(
            uint32 framebuffer,
            uint32 attachment,
            uint32 renderbuffertarget,
            uint32 renderbuffer);
        typedef void (OPEN_GL_API * PFN_GLNAMEDFRAMEBUFFERTEXTURE)(
            uint32 framebuffer,
            uint32 attachment,
            uint32 texture,
            int32 level);
        typedef void (OPEN_GL_API * PFN_GLNAMEDFRAMEBUFFERTEXTURELAYER)(
            uint32 framebuffer,
            uint32 attachment,
            uint32 texture,
            int32 level,
            int32 layer);
        typedef void (OPEN_GL_API * PFN_GLNAMEDRENDERBUFFERSTORAGE)(
            uint32 renderbuffer,
            uint32 internalformat,
            int32 width,
            int32 height);
        typedef void (OPEN_GL_API * PFN_GLNAMEDRENDERBUFFERSTORAGEMULTISAMPLE)(
            uint32 renderbuffer,
            int32 samples,
            uint32 internalformat,
            int32 width,
            int32 height);
        typedef void (OPEN_GL_API * PFN_GLNORMALP3UI)(
            uint32 type,
            uint32 coords);
        typedef void (OPEN_GL_API * PFN_GLNORMALP3UIV)(
            uint32 type,
            const uint32 * coords);
        typedef void (OPEN_GL_API * PFN_GLOBJECTLABEL)(
            uint32 identifier,
            uint32 name,
            int32 length,
            const char * label);
        typedef void (OPEN_GL_API * PFN_GLOBJECTPTRLABEL)(
            const void * ptr,
            int32 length,
            const char * label);
        typedef void (OPEN_GL_API * PFN_GLPATCHPARAMETERFV)(
            uint32 pname,
            const float * values);
        typedef void (OPEN_GL_API * PFN_GLPATCHPARAMETERI)(
            uint32 pname,
            int32 value);
        typedef void (OPEN_GL_API * PFN_GLPAUSETRANSFORMFEEDBACK)();
        typedef void (OPEN_GL_API * PFN_GLPIXELSTOREF)(
            uint32 pname,
            float param);
        typedef void (OPEN_GL_API * PFN_GLPIXELSTOREI)(
            uint32 pname,
            int32 param);
        typedef void (OPEN_GL_API * PFN_GLPOINTPARAMETERF)(
            uint32 pname,
            float param);
        typedef void (OPEN_GL_API * PFN_GLPOINTPARAMETERFV)(
            uint32 pname,
            const float * params);
        typedef void (OPEN_GL_API * PFN_GLPOINTPARAMETERI)(
            uint32 pname,
            int32 param);
        typedef void (OPEN_GL_API * PFN_GLPOINTPARAMETERIV)(
            uint32 pname,
            const int32 * params);
        typedef void (OPEN_GL_API * PFN_GLPOINTSIZE)(
            float size);
        typedef void (OPEN_GL_API * PFN_GLPOLYGONMODE)(
            uint32 face,
            uint32 mode);
        typedef void (OPEN_GL_API * PFN_GLPOLYGONOFFSET)(
            float factor,
            float units);
        typedef void (OPEN_GL_API * PFN_GLPOPDEBUGGROUP)();
        typedef void (OPEN_GL_API * PFN_GLPRIMITIVERESTARTINDEX)(
            uint32 index);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMBINARY)(
            uint32 program,
            uint32 binaryFormat,
            const void * binary,
            int32 length);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMPARAMETERI)(
            uint32 program,
            uint32 pname,
            int32 value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM1D)(
            uint32 program,
            int32 location,
            double v0);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM1DV)(
            uint32 program,
            int32 location,
            int32 count,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM1F)(
            uint32 program,
            int32 location,
            float v0);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM1FV)(
            uint32 program,
            int32 location,
            int32 count,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM1I)(
            uint32 program,
            int32 location,
            int32 v0);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM1IV)(
            uint32 program,
            int32 location,
            int32 count,
            const int32 * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM1UI)(
            uint32 program,
            int32 location,
            uint32 v0);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM1UIV)(
            uint32 program,
            int32 location,
            int32 count,
            const uint32 * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM2D)(
            uint32 program,
            int32 location,
            double v0,
            double v1);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM2DV)(
            uint32 program,
            int32 location,
            int32 count,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM2F)(
            uint32 program,
            int32 location,
            float v0,
            float v1);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM2FV)(
            uint32 program,
            int32 location,
            int32 count,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM2I)(
            uint32 program,
            int32 location,
            int32 v0,
            int32 v1);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM2IV)(
            uint32 program,
            int32 location,
            int32 count,
            const int32 * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM2UI)(
            uint32 program,
            int32 location,
            uint32 v0,
            uint32 v1);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM2UIV)(
            uint32 program,
            int32 location,
            int32 count,
            const uint32 * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM3D)(
            uint32 program,
            int32 location,
            double v0,
            double v1,
            double v2);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM3DV)(
            uint32 program,
            int32 location,
            int32 count,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM3F)(
            uint32 program,
            int32 location,
            float v0,
            float v1,
            float v2);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM3FV)(
            uint32 program,
            int32 location,
            int32 count,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM3I)(
            uint32 program,
            int32 location,
            int32 v0,
            int32 v1,
            int32 v2);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM3IV)(
            uint32 program,
            int32 location,
            int32 count,
            const int32 * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM3UI)(
            uint32 program,
            int32 location,
            uint32 v0,
            uint32 v1,
            uint32 v2);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM3UIV)(
            uint32 program,
            int32 location,
            int32 count,
            const uint32 * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM4D)(
            uint32 program,
            int32 location,
            double v0,
            double v1,
            double v2,
            double v3);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM4DV)(
            uint32 program,
            int32 location,
            int32 count,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM4F)(
            uint32 program,
            int32 location,
            float v0,
            float v1,
            float v2,
            float v3);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM4FV)(
            uint32 program,
            int32 location,
            int32 count,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM4I)(
            uint32 program,
            int32 location,
            int32 v0,
            int32 v1,
            int32 v2,
            int32 v3);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM4IV)(
            uint32 program,
            int32 location,
            int32 count,
            const int32 * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM4UI)(
            uint32 program,
            int32 location,
            uint32 v0,
            uint32 v1,
            uint32 v2,
            uint32 v3);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORM4UIV)(
            uint32 program,
            int32 location,
            int32 count,
            const uint32 * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORMMATRIX2DV)(
            uint32 program,
            int32 location,
            int32 count,
            uint8 transpose,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORMMATRIX2FV)(
            uint32 program,
            int32 location,
            int32 count,
            uint8 transpose,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORMMATRIX2X3DV)(
            uint32 program,
            int32 location,
            int32 count,
            uint8 transpose,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORMMATRIX2X3FV)(
            uint32 program,
            int32 location,
            int32 count,
            uint8 transpose,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORMMATRIX2X4DV)(
            uint32 program,
            int32 location,
            int32 count,
            uint8 transpose,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORMMATRIX2X4FV)(
            uint32 program,
            int32 location,
            int32 count,
            uint8 transpose,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORMMATRIX3DV)(
            uint32 program,
            int32 location,
            int32 count,
            uint8 transpose,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORMMATRIX3FV)(
            uint32 program,
            int32 location,
            int32 count,
            uint8 transpose,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORMMATRIX3X2DV)(
            uint32 program,
            int32 location,
            int32 count,
            uint8 transpose,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORMMATRIX3X2FV)(
            uint32 program,
            int32 location,
            int32 count,
            uint8 transpose,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORMMATRIX3X4DV)(
            uint32 program,
            int32 location,
            int32 count,
            uint8 transpose,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORMMATRIX3X4FV)(
            uint32 program,
            int32 location,
            int32 count,
            uint8 transpose,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORMMATRIX4DV)(
            uint32 program,
            int32 location,
            int32 count,
            uint8 transpose,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORMMATRIX4FV)(
            uint32 program,
            int32 location,
            int32 count,
            uint8 transpose,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORMMATRIX4X2DV)(
            uint32 program,
            int32 location,
            int32 count,
            uint8 transpose,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORMMATRIX4X2FV)(
            uint32 program,
            int32 location,
            int32 count,
            uint8 transpose,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORMMATRIX4X3DV)(
            uint32 program,
            int32 location,
            int32 count,
            uint8 transpose,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLPROGRAMUNIFORMMATRIX4X3FV)(
            uint32 program,
            int32 location,
            int32 count,
            uint8 transpose,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLPROVOKINGVERTEX)(
            uint32 mode);
        typedef void (OPEN_GL_API * PFN_GLPUSHDEBUGGROUP)(
            uint32 source,
            uint32 id,
            int32 length,
            const char * message);
        typedef void (OPEN_GL_API * PFN_GLQUERYCOUNTER)(
            uint32 id,
            uint32 target);
        typedef void (OPEN_GL_API * PFN_GLREADBUFFER)(
            uint32 src);
        typedef void (OPEN_GL_API * PFN_GLREADPIXELS)(
            int32 x,
            int32 y,
            int32 width,
            int32 height,
            uint32 format,
            uint32 type,
            void * pixels);
        typedef void (OPEN_GL_API * PFN_GLRELEASESHADERCOMPILER)();
        typedef void (OPEN_GL_API * PFN_GLRENDERBUFFERSTORAGE)(
            uint32 target,
            uint32 internalformat,
            int32 width,
            int32 height);
        typedef void (OPEN_GL_API * PFN_GLRENDERBUFFERSTORAGEMULTISAMPLE)(
            uint32 target,
            int32 samples,
            uint32 internalformat,
            int32 width,
            int32 height);
        typedef void (OPEN_GL_API * PFN_GLRESUMETRANSFORMFEEDBACK)();
        typedef void (OPEN_GL_API * PFN_GLSAMPLECOVERAGE)(
            float value,
            uint8 invert);
        typedef void (OPEN_GL_API * PFN_GLSAMPLEMASKI)(
            uint32 maskNumber,
            uint32 mask);
        typedef void (OPEN_GL_API * PFN_GLSAMPLERPARAMETERIIV)(
            uint32 sampler,
            uint32 pname,
            const int32 * param);
        typedef void (OPEN_GL_API * PFN_GLSAMPLERPARAMETERIUIV)(
            uint32 sampler,
            uint32 pname,
            const uint32 * param);
        typedef void (OPEN_GL_API * PFN_GLSAMPLERPARAMETERF)(
            uint32 sampler,
            uint32 pname,
            float param);
        typedef void (OPEN_GL_API * PFN_GLSAMPLERPARAMETERFV)(
            uint32 sampler,
            uint32 pname,
            const float * param);
        typedef void (OPEN_GL_API * PFN_GLSAMPLERPARAMETERI)(
            uint32 sampler,
            uint32 pname,
            int32 param);
        typedef void (OPEN_GL_API * PFN_GLSAMPLERPARAMETERIV)(
            uint32 sampler,
            uint32 pname,
            const int32 * param);
        typedef void (OPEN_GL_API * PFN_GLSCISSOR)(
            int32 x,
            int32 y,
            int32 width,
            int32 height);
        typedef void (OPEN_GL_API * PFN_GLSCISSORARRAYV)(
            uint32 first,
            int32 count,
            const int32 * v);
        typedef void (OPEN_GL_API * PFN_GLSCISSORINDEXED)(
            uint32 index,
            int32 left,
            int32 bottom,
            int32 width,
            int32 height);
        typedef void (OPEN_GL_API * PFN_GLSCISSORINDEXEDV)(
            uint32 index,
            const int32 * v);
        typedef void (OPEN_GL_API * PFN_GLSECONDARYCOLORP3UI)(
            uint32 type,
            uint32 color);
        typedef void (OPEN_GL_API * PFN_GLSECONDARYCOLORP3UIV)(
            uint32 type,
            const uint32 * color);
        typedef void (OPEN_GL_API * PFN_GLSHADERBINARY)(
            int32 count,
            const uint32 * shaders,
            uint32 binaryformat,
            const void * binary,
            int32 length);
        typedef void (OPEN_GL_API * PFN_GLSHADERSOURCE)(
            uint32 shader,
            int32 count,
            const char *const* string,
            const int32 * length);
        typedef void (OPEN_GL_API * PFN_GLSHADERSTORAGEBLOCKBINDING)(
            uint32 program,
            uint32 storageBlockIndex,
            uint32 storageBlockBinding);
        typedef void (OPEN_GL_API * PFN_GLSTENCILFUNC)(
            uint32 func,
            int32 ref,
            uint32 mask);
        typedef void (OPEN_GL_API * PFN_GLSTENCILFUNCSEPARATE)(
            uint32 face,
            uint32 func,
            int32 ref,
            uint32 mask);
        typedef void (OPEN_GL_API * PFN_GLSTENCILMASK)(
            uint32 mask);
        typedef void (OPEN_GL_API * PFN_GLSTENCILMASKSEPARATE)(
            uint32 face,
            uint32 mask);
        typedef void (OPEN_GL_API * PFN_GLSTENCILOP)(
            uint32 fail,
            uint32 zfail,
            uint32 zpass);
        typedef void (OPEN_GL_API * PFN_GLSTENCILOPSEPARATE)(
            uint32 face,
            uint32 sfail,
            uint32 dpfail,
            uint32 dppass);
        typedef void (OPEN_GL_API * PFN_GLTEXBUFFER)(
            uint32 target,
            uint32 internalformat,
            uint32 buffer);
        typedef void (OPEN_GL_API * PFN_GLTEXBUFFERRANGE)(
            uint32 target,
            uint32 internalformat,
            uint32 buffer,
            ptrdiff_t offset,
            ptrdiff_t size);
        typedef void (OPEN_GL_API * PFN_GLTEXCOORDP1UI)(
            uint32 type,
            uint32 coords);
        typedef void (OPEN_GL_API * PFN_GLTEXCOORDP1UIV)(
            uint32 type,
            const uint32 * coords);
        typedef void (OPEN_GL_API * PFN_GLTEXCOORDP2UI)(
            uint32 type,
            uint32 coords);
        typedef void (OPEN_GL_API * PFN_GLTEXCOORDP2UIV)(
            uint32 type,
            const uint32 * coords);
        typedef void (OPEN_GL_API * PFN_GLTEXCOORDP3UI)(
            uint32 type,
            uint32 coords);
        typedef void (OPEN_GL_API * PFN_GLTEXCOORDP3UIV)(
            uint32 type,
            const uint32 * coords);
        typedef void (OPEN_GL_API * PFN_GLTEXCOORDP4UI)(
            uint32 type,
            uint32 coords);
        typedef void (OPEN_GL_API * PFN_GLTEXCOORDP4UIV)(
            uint32 type,
            const uint32 * coords);
        typedef void (OPEN_GL_API * PFN_GLTEXIMAGE1D)(
            uint32 target,
            int32 level,
            int32 internalformat,
            int32 width,
            int32 border,
            uint32 format,
            uint32 type,
            const void * pixels);
        typedef void (OPEN_GL_API * PFN_GLTEXIMAGE2D)(
            uint32 target,
            int32 level,
            int32 internalformat,
            int32 width,
            int32 height,
            int32 border,
            uint32 format,
            uint32 type,
            const void * pixels);
        typedef void (OPEN_GL_API * PFN_GLTEXIMAGE2DMULTISAMPLE)(
            uint32 target,
            int32 samples,
            uint32 internalformat,
            int32 width,
            int32 height,
            uint8 fixedsamplelocations);
        typedef void (OPEN_GL_API * PFN_GLTEXIMAGE3D)(
            uint32 target,
            int32 level,
            int32 internalformat,
            int32 width,
            int32 height,
            int32 depth,
            int32 border,
            uint32 format,
            uint32 type,
            const void * pixels);
        typedef void (OPEN_GL_API * PFN_GLTEXIMAGE3DMULTISAMPLE)(
            uint32 target,
            int32 samples,
            uint32 internalformat,
            int32 width,
            int32 height,
            int32 depth,
            uint8 fixedsamplelocations);
        typedef void (OPEN_GL_API * PFN_GLTEXPARAMETERIIV)(
            uint32 target,
            uint32 pname,
            const int32 * params);
        typedef void (OPEN_GL_API * PFN_GLTEXPARAMETERIUIV)(
            uint32 target,
            uint32 pname,
            const uint32 * params);
        typedef void (OPEN_GL_API * PFN_GLTEXPARAMETERF)(
            uint32 target,
            uint32 pname,
            float param);
        typedef void (OPEN_GL_API * PFN_GLTEXPARAMETERFV)(
            uint32 target,
            uint32 pname,
            const float * params);
        typedef void (OPEN_GL_API * PFN_GLTEXPARAMETERI)(
            uint32 target,
            uint32 pname,
            int32 param);
        typedef void (OPEN_GL_API * PFN_GLTEXPARAMETERIV)(
            uint32 target,
            uint32 pname,
            const int32 * params);
        typedef void (OPEN_GL_API * PFN_GLTEXSTORAGE1D)(
            uint32 target,
            int32 levels,
            uint32 internalformat,
            int32 width);
        typedef void (OPEN_GL_API * PFN_GLTEXSTORAGE2D)(
            uint32 target,
            int32 levels,
            uint32 internalformat,
            int32 width,
            int32 height);
        typedef void (OPEN_GL_API * PFN_GLTEXSTORAGE2DMULTISAMPLE)(
            uint32 target,
            int32 samples,
            uint32 internalformat,
            int32 width,
            int32 height,
            uint8 fixedsamplelocations);
        typedef void (OPEN_GL_API * PFN_GLTEXSTORAGE3D)(
            uint32 target,
            int32 levels,
            uint32 internalformat,
            int32 width,
            int32 height,
            int32 depth);
        typedef void (OPEN_GL_API * PFN_GLTEXSTORAGE3DMULTISAMPLE)(
            uint32 target,
            int32 samples,
            uint32 internalformat,
            int32 width,
            int32 height,
            int32 depth,
            uint8 fixedsamplelocations);
        typedef void (OPEN_GL_API * PFN_GLTEXSUBIMAGE1D)(
            uint32 target,
            int32 level,
            int32 xoffset,
            int32 width,
            uint32 format,
            uint32 type,
            const void * pixels);
        typedef void (OPEN_GL_API * PFN_GLTEXSUBIMAGE2D)(
            uint32 target,
            int32 level,
            int32 xoffset,
            int32 yoffset,
            int32 width,
            int32 height,
            uint32 format,
            uint32 type,
            const void * pixels);
        typedef void (OPEN_GL_API * PFN_GLTEXSUBIMAGE3D)(
            uint32 target,
            int32 level,
            int32 xoffset,
            int32 yoffset,
            int32 zoffset,
            int32 width,
            int32 height,
            int32 depth,
            uint32 format,
            uint32 type,
            const void * pixels);
        typedef void (OPEN_GL_API * PFN_GLTEXTUREBUFFER)(
            uint32 texture,
            uint32 internalformat,
            uint32 buffer);
        typedef void (OPEN_GL_API * PFN_GLTEXTUREBUFFERRANGE)(
            uint32 texture,
            uint32 internalformat,
            uint32 buffer,
            ptrdiff_t offset,
            int32 size);
        typedef void (OPEN_GL_API * PFN_GLTEXTUREPARAMETERIIV)(
            uint32 texture,
            uint32 pname,
            const int32 * params);
        typedef void (OPEN_GL_API * PFN_GLTEXTUREPARAMETERIUIV)(
            uint32 texture,
            uint32 pname,
            const uint32 * params);
        typedef void (OPEN_GL_API * PFN_GLTEXTUREPARAMETERF)(
            uint32 texture,
            uint32 pname,
            float param);
        typedef void (OPEN_GL_API * PFN_GLTEXTUREPARAMETERFV)(
            uint32 texture,
            uint32 pname,
            const float * param);
        typedef void (OPEN_GL_API * PFN_GLTEXTUREPARAMETERI)(
            uint32 texture,
            uint32 pname,
            int32 param);
        typedef void (OPEN_GL_API * PFN_GLTEXTUREPARAMETERIV)(
            uint32 texture,
            uint32 pname,
            const int32 * param);
        typedef void (OPEN_GL_API * PFN_GLTEXTURESTORAGE1D)(
            uint32 texture,
            int32 levels,
            uint32 internalformat,
            int32 width);
        typedef void (OPEN_GL_API * PFN_GLTEXTURESTORAGE2D)(
            uint32 texture,
            int32 levels,
            uint32 internalformat,
            int32 width,
            int32 height);
        typedef void (OPEN_GL_API * PFN_GLTEXTURESTORAGE2DMULTISAMPLE)(
            uint32 texture,
            int32 samples,
            uint32 internalformat,
            int32 width,
            int32 height,
            uint8 fixedsamplelocations);
        typedef void (OPEN_GL_API * PFN_GLTEXTURESTORAGE3D)(
            uint32 texture,
            int32 levels,
            uint32 internalformat,
            int32 width,
            int32 height,
            int32 depth);
        typedef void (OPEN_GL_API * PFN_GLTEXTURESTORAGE3DMULTISAMPLE)(
            uint32 texture,
            int32 samples,
            uint32 internalformat,
            int32 width,
            int32 height,
            int32 depth,
            uint8 fixedsamplelocations);
        typedef void (OPEN_GL_API * PFN_GLTEXTURESUBIMAGE1D)(
            uint32 texture,
            int32 level,
            int32 xoffset,
            int32 width,
            uint32 format,
            uint32 type,
            const void * pixels);
        typedef void (OPEN_GL_API * PFN_GLTEXTURESUBIMAGE2D)(
            uint32 texture,
            int32 level,
            int32 xoffset,
            int32 yoffset,
            int32 width,
            int32 height,
            uint32 format,
            uint32 type,
            const void * pixels);
        typedef void (OPEN_GL_API * PFN_GLTEXTURESUBIMAGE3D)(
            uint32 texture,
            int32 level,
            int32 xoffset,
            int32 yoffset,
            int32 zoffset,
            int32 width,
            int32 height,
            int32 depth,
            uint32 format,
            uint32 type,
            const void * pixels);
        typedef void (OPEN_GL_API * PFN_GLTEXTUREVIEW)(
            uint32 texture,
            uint32 target,
            uint32 origtexture,
            uint32 internalformat,
            uint32 minlevel,
            uint32 numlevels,
            uint32 minlayer,
            uint32 numlayers);
        typedef void (OPEN_GL_API * PFN_GLTRANSFORMFEEDBACKBUFFERBASE)(
            uint32 xfb,
            uint32 index,
            uint32 buffer);
        typedef void (OPEN_GL_API * PFN_GLTRANSFORMFEEDBACKBUFFERRANGE)(
            uint32 xfb,
            uint32 index,
            uint32 buffer,
            ptrdiff_t offset,
            int32 size);
        typedef void (OPEN_GL_API * PFN_GLTRANSFORMFEEDBACKVARYINGS)(
            uint32 program,
            int32 count,
            const char *const* varyings,
            uint32 bufferMode);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM1D)(
            int32 location,
            double x);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM1DV)(
            int32 location,
            int32 count,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM1F)(
            int32 location,
            float v0);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM1FV)(
            int32 location,
            int32 count,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM1I)(
            int32 location,
            int32 v0);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM1IV)(
            int32 location,
            int32 count,
            const int32 * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM1UI)(
            int32 location,
            uint32 v0);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM1UIV)(
            int32 location,
            int32 count,
            const uint32 * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM2D)(
            int32 location,
            double x,
            double y);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM2DV)(
            int32 location,
            int32 count,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM2F)(
            int32 location,
            float v0,
            float v1);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM2FV)(
            int32 location,
            int32 count,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM2I)(
            int32 location,
            int32 v0,
            int32 v1);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM2IV)(
            int32 location,
            int32 count,
            const int32 * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM2UI)(
            int32 location,
            uint32 v0,
            uint32 v1);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM2UIV)(
            int32 location,
            int32 count,
            const uint32 * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM3D)(
            int32 location,
            double x,
            double y,
            double z);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM3DV)(
            int32 location,
            int32 count,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM3F)(
            int32 location,
            float v0,
            float v1,
            float v2);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM3FV)(
            int32 location,
            int32 count,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM3I)(
            int32 location,
            int32 v0,
            int32 v1,
            int32 v2);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM3IV)(
            int32 location,
            int32 count,
            const int32 * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM3UI)(
            int32 location,
            uint32 v0,
            uint32 v1,
            uint32 v2);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM3UIV)(
            int32 location,
            int32 count,
            const uint32 * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM4D)(
            int32 location,
            double x,
            double y,
            double z,
            double w);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM4DV)(
            int32 location,
            int32 count,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM4F)(
            int32 location,
            float v0,
            float v1,
            float v2,
            float v3);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM4FV)(
            int32 location,
            int32 count,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM4I)(
            int32 location,
            int32 v0,
            int32 v1,
            int32 v2,
            int32 v3);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM4IV)(
            int32 location,
            int32 count,
            const int32 * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM4UI)(
            int32 location,
            uint32 v0,
            uint32 v1,
            uint32 v2,
            uint32 v3);
        typedef void (OPEN_GL_API * PFN_GLUNIFORM4UIV)(
            int32 location,
            int32 count,
            const uint32 * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMBLOCKBINDING)(
            uint32 program,
            uint32 uniformBlockIndex,
            uint32 uniformBlockBinding);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMMATRIX2DV)(
            int32 location,
            int32 count,
            uint8 transpose,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMMATRIX2FV)(
            int32 location,
            int32 count,
            uint8 transpose,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMMATRIX2X3DV)(
            int32 location,
            int32 count,
            uint8 transpose,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMMATRIX2X3FV)(
            int32 location,
            int32 count,
            uint8 transpose,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMMATRIX2X4DV)(
            int32 location,
            int32 count,
            uint8 transpose,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMMATRIX2X4FV)(
            int32 location,
            int32 count,
            uint8 transpose,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMMATRIX3DV)(
            int32 location,
            int32 count,
            uint8 transpose,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMMATRIX3FV)(
            int32 location,
            int32 count,
            uint8 transpose,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMMATRIX3X2DV)(
            int32 location,
            int32 count,
            uint8 transpose,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMMATRIX3X2FV)(
            int32 location,
            int32 count,
            uint8 transpose,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMMATRIX3X4DV)(
            int32 location,
            int32 count,
            uint8 transpose,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMMATRIX3X4FV)(
            int32 location,
            int32 count,
            uint8 transpose,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMMATRIX4DV)(
            int32 location,
            int32 count,
            uint8 transpose,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMMATRIX4FV)(
            int32 location,
            int32 count,
            uint8 transpose,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMMATRIX4X2DV)(
            int32 location,
            int32 count,
            uint8 transpose,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMMATRIX4X2FV)(
            int32 location,
            int32 count,
            uint8 transpose,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMMATRIX4X3DV)(
            int32 location,
            int32 count,
            uint8 transpose,
            const double * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMMATRIX4X3FV)(
            int32 location,
            int32 count,
            uint8 transpose,
            const float * value);
        typedef void (OPEN_GL_API * PFN_GLUNIFORMSUBROUTINESUIV)(
            uint32 shadertype,
            int32 count,
            const uint32 * indices);
        typedef uint8 (OPEN_GL_API * PFN_GLUNMAPBUFFER)(
            uint32 target);
        typedef uint8 (OPEN_GL_API * PFN_GLUNMAPNAMEDBUFFER)(
            uint32 buffer);
        typedef void (OPEN_GL_API * PFN_GLUSEPROGRAM)(
            uint32 program);
        typedef void (OPEN_GL_API * PFN_GLUSEPROGRAMSTAGES)(
            uint32 pipeline,
            uint32 stages,
            uint32 program);
        typedef void (OPEN_GL_API * PFN_GLVALIDATEPROGRAM)(
            uint32 program);
        typedef void (OPEN_GL_API * PFN_GLVALIDATEPROGRAMPIPELINE)(
            uint32 pipeline);
        typedef void (OPEN_GL_API * PFN_GLVERTEXARRAYATTRIBBINDING)(
            uint32 vaobj,
            uint32 attribindex,
            uint32 bindingindex);
        typedef void (OPEN_GL_API * PFN_GLVERTEXARRAYATTRIBFORMAT)(
            uint32 vaobj,
            uint32 attribindex,
            int32 size,
            uint32 type,
            uint8 normalized,
            uint32 relativeoffset);
        typedef void (OPEN_GL_API * PFN_GLVERTEXARRAYATTRIBIFORMAT)(
            uint32 vaobj,
            uint32 attribindex,
            int32 size,
            uint32 type,
            uint32 relativeoffset);
        typedef void (OPEN_GL_API * PFN_GLVERTEXARRAYATTRIBLFORMAT)(
            uint32 vaobj,
            uint32 attribindex,
            int32 size,
            uint32 type,
            uint32 relativeoffset);
        typedef void (OPEN_GL_API * PFN_GLVERTEXARRAYBINDINGDIVISOR)(
            uint32 vaobj,
            uint32 bindingindex,
            uint32 divisor);
        typedef void (OPEN_GL_API * PFN_GLVERTEXARRAYELEMENTBUFFER)(
            uint32 vaobj,
            uint32 buffer);
        typedef void (OPEN_GL_API * PFN_GLVERTEXARRAYVERTEXBUFFER)(
            uint32 vaobj,
            uint32 bindingindex,
            uint32 buffer,
            ptrdiff_t offset,
            int32 stride);
        typedef void (OPEN_GL_API * PFN_GLVERTEXARRAYVERTEXBUFFERS)(
            uint32 vaobj,
            uint32 first,
            int32 count,
            const uint32 * buffers,
            const ptrdiff_t * offsets,
            const int32 * strides);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB1D)(
            uint32 index,
            double x);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB1DV)(
            uint32 index,
            const double * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB1F)(
            uint32 index,
            float x);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB1FV)(
            uint32 index,
            const float * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB1S)(
            uint32 index,
            int16 x);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB1SV)(
            uint32 index,
            const int16 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB2D)(
            uint32 index,
            double x,
            double y);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB2DV)(
            uint32 index,
            const double * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB2F)(
            uint32 index,
            float x,
            float y);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB2FV)(
            uint32 index,
            const float * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB2S)(
            uint32 index,
            int16 x,
            int16 y);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB2SV)(
            uint32 index,
            const int16 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB3D)(
            uint32 index,
            double x,
            double y,
            double z);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB3DV)(
            uint32 index,
            const double * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB3F)(
            uint32 index,
            float x,
            float y,
            float z);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB3FV)(
            uint32 index,
            const float * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB3S)(
            uint32 index,
            int16 x,
            int16 y,
            int16 z);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB3SV)(
            uint32 index,
            const int16 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB4NBV)(
            uint32 index,
            const int8 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB4NIV)(
            uint32 index,
            const int32 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB4NSV)(
            uint32 index,
            const int16 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB4NUB)(
            uint32 index,
            uint8 x,
            uint8 y,
            uint8 z,
            uint8 w);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB4NUBV)(
            uint32 index,
            const uint8 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB4NUIV)(
            uint32 index,
            const uint32 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB4NUSV)(
            uint32 index,
            const uint16 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB4BV)(
            uint32 index,
            const int8 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB4D)(
            uint32 index,
            double x,
            double y,
            double z,
            double w);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB4DV)(
            uint32 index,
            const double * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB4F)(
            uint32 index,
            float x,
            float y,
            float z,
            float w);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB4FV)(
            uint32 index,
            const float * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB4IV)(
            uint32 index,
            const int32 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB4S)(
            uint32 index,
            int16 x,
            int16 y,
            int16 z,
            int16 w);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB4SV)(
            uint32 index,
            const int16 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB4UBV)(
            uint32 index,
            const uint8 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB4UIV)(
            uint32 index,
            const uint32 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIB4USV)(
            uint32 index,
            const uint16 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBBINDING)(
            uint32 attribindex,
            uint32 bindingindex);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBDIVISOR)(
            uint32 index,
            uint32 divisor);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBFORMAT)(
            uint32 attribindex,
            int32 size,
            uint32 type,
            uint8 normalized,
            uint32 relativeoffset);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI1I)(
            uint32 index,
            int32 x);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI1IV)(
            uint32 index,
            const int32 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI1UI)(
            uint32 index,
            uint32 x);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI1UIV)(
            uint32 index,
            const uint32 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI2I)(
            uint32 index,
            int32 x,
            int32 y);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI2IV)(
            uint32 index,
            const int32 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI2UI)(
            uint32 index,
            uint32 x,
            uint32 y);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI2UIV)(
            uint32 index,
            const uint32 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI3I)(
            uint32 index,
            int32 x,
            int32 y,
            int32 z);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI3IV)(
            uint32 index,
            const int32 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI3UI)(
            uint32 index,
            uint32 x,
            uint32 y,
            uint32 z);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI3UIV)(
            uint32 index,
            const uint32 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI4BV)(
            uint32 index,
            const int8 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI4I)(
            uint32 index,
            int32 x,
            int32 y,
            int32 z,
            int32 w);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI4IV)(
            uint32 index,
            const int32 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI4SV)(
            uint32 index,
            const int16 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI4UBV)(
            uint32 index,
            const uint8 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI4UI)(
            uint32 index,
            uint32 x,
            uint32 y,
            uint32 z,
            uint32 w);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI4UIV)(
            uint32 index,
            const uint32 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBI4USV)(
            uint32 index,
            const uint16 * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBIFORMAT)(
            uint32 attribindex,
            int32 size,
            uint32 type,
            uint32 relativeoffset);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBIPOINTER)(
            uint32 index,
            int32 size,
            uint32 type,
            int32 stride,
            const void * pointer);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBL1D)(
            uint32 index,
            double x);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBL1DV)(
            uint32 index,
            const double * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBL2D)(
            uint32 index,
            double x,
            double y);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBL2DV)(
            uint32 index,
            const double * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBL3D)(
            uint32 index,
            double x,
            double y,
            double z);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBL3DV)(
            uint32 index,
            const double * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBL4D)(
            uint32 index,
            double x,
            double y,
            double z,
            double w);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBL4DV)(
            uint32 index,
            const double * v);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBLFORMAT)(
            uint32 attribindex,
            int32 size,
            uint32 type,
            uint32 relativeoffset);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBLPOINTER)(
            uint32 index,
            int32 size,
            uint32 type,
            int32 stride,
            const void * pointer);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBP1UI)(
            uint32 index,
            uint32 type,
            uint8 normalized,
            uint32 value);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBP1UIV)(
            uint32 index,
            uint32 type,
            uint8 normalized,
            const uint32 * value);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBP2UI)(
            uint32 index,
            uint32 type,
            uint8 normalized,
            uint32 value);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBP2UIV)(
            uint32 index,
            uint32 type,
            uint8 normalized,
            const uint32 * value);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBP3UI)(
            uint32 index,
            uint32 type,
            uint8 normalized,
            uint32 value);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBP3UIV)(
            uint32 index,
            uint32 type,
            uint8 normalized,
            const uint32 * value);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBP4UI)(
            uint32 index,
            uint32 type,
            uint8 normalized,
            uint32 value);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBP4UIV)(
            uint32 index,
            uint32 type,
            uint8 normalized,
            const uint32 * value);
        typedef void (OPEN_GL_API * PFN_GLVERTEXATTRIBPOINTER)(
            uint32 index,
            int32 size,
            uint32 type,
            uint8 normalized,
            int32 stride,
            const void * pointer);
        typedef void (OPEN_GL_API * PFN_GLVERTEXBINDINGDIVISOR)(
            uint32 bindingindex,
            uint32 divisor);
        typedef void (OPEN_GL_API * PFN_GLVERTEXP2UI)(
            uint32 type,
            uint32 value);
        typedef void (OPEN_GL_API * PFN_GLVERTEXP2UIV)(
            uint32 type,
            const uint32 * value);
        typedef void (OPEN_GL_API * PFN_GLVERTEXP3UI)(
            uint32 type,
            uint32 value);
        typedef void (OPEN_GL_API * PFN_GLVERTEXP3UIV)(
            uint32 type,
            const uint32 * value);
        typedef void (OPEN_GL_API * PFN_GLVERTEXP4UI)(
            uint32 type,
            uint32 value);
        typedef void (OPEN_GL_API * PFN_GLVERTEXP4UIV)(
            uint32 type,
            const uint32 * value);
        typedef void (OPEN_GL_API * PFN_GLVIEWPORT)(
            int32 x,
            int32 y,
            int32 width,
            int32 height);
        typedef void (OPEN_GL_API * PFN_GLVIEWPORTARRAYV)(
            uint32 first,
            int32 count,
            const float * v);
        typedef void (OPEN_GL_API * PFN_GLVIEWPORTINDEXEDF)(
            uint32 index,
            float x,
            float y,
            float w,
            float h);
        typedef void (OPEN_GL_API * PFN_GLVIEWPORTINDEXEDFV)(
            uint32 index,
            const float * v);
        typedef void (OPEN_GL_API * PFN_GLWAITSYNC)(
            void * sync,
            uint32 flags,
            uint64 timeout);

        /* End of prototypes */

        /* Entry points */
        struct Functions
        {
            PFN_GLACTIVESHADERPROGRAM                         ActiveShaderProgram;
            PFN_GLACTIVETEXTURE                               ActiveTexture;
            PFN_GLATTACHSHADER                                AttachShader;
            PFN_GLBEGINCONDITIONALRENDER                      BeginConditionalRender;
            PFN_GLBEGINQUERY                                  BeginQuery;
            PFN_GLBEGINQUERYINDEXED                           BeginQueryIndexed;
            PFN_GLBEGINTRANSFORMFEEDBACK                      BeginTransformFeedback;
            PFN_GLBINDATTRIBLOCATION                          BindAttribLocation;
            PFN_GLBINDBUFFER                                  BindBuffer;
            PFN_GLBINDBUFFERBASE                              BindBufferBase;
            PFN_GLBINDBUFFERRANGE                             BindBufferRange;
            PFN_GLBINDBUFFERSBASE                             BindBuffersBase;
            PFN_GLBINDBUFFERSRANGE                            BindBuffersRange;
            PFN_GLBINDFRAGDATALOCATION                        BindFragDataLocation;
            PFN_GLBINDFRAGDATALOCATIONINDEXED                 BindFragDataLocationIndexed;
            PFN_GLBINDFRAMEBUFFER                             BindFramebuffer;
            PFN_GLBINDIMAGETEXTURE                            BindImageTexture;
            PFN_GLBINDIMAGETEXTURES                           BindImageTextures;
            PFN_GLBINDPROGRAMPIPELINE                         BindProgramPipeline;
            PFN_GLBINDRENDERBUFFER                            BindRenderbuffer;
            PFN_GLBINDSAMPLER                                 BindSampler;
            PFN_GLBINDSAMPLERS                                BindSamplers;
            PFN_GLBINDTEXTURE                                 BindTexture;
            PFN_GLBINDTEXTUREUNIT                             BindTextureUnit;
            PFN_GLBINDTEXTURES                                BindTextures;
            PFN_GLBINDTRANSFORMFEEDBACK                       BindTransformFeedback;
            PFN_GLBINDVERTEXARRAY                             BindVertexArray;
            PFN_GLBINDVERTEXBUFFER                            BindVertexBuffer;
            PFN_GLBINDVERTEXBUFFERS                           BindVertexBuffers;
            PFN_GLBLENDCOLOR                                  BlendColor;
            PFN_GLBLENDEQUATION                               BlendEquation;
            PFN_GLBLENDEQUATIONSEPARATE                       BlendEquationSeparate;
            PFN_GLBLENDEQUATIONSEPARATEI                      BlendEquationSeparatei;
            PFN_GLBLENDEQUATIONI                              BlendEquationi;
            PFN_GLBLENDFUNC                                   BlendFunc;
            PFN_GLBLENDFUNCSEPARATE                           BlendFuncSeparate;
            PFN_GLBLENDFUNCSEPARATEI                          BlendFuncSeparatei;
            PFN_GLBLENDFUNCI                                  BlendFunci;
            PFN_GLBLITFRAMEBUFFER                             BlitFramebuffer;
            PFN_GLBLITNAMEDFRAMEBUFFER                        BlitNamedFramebuffer;
            PFN_GLBUFFERDATA                                  BufferData;
            PFN_GLBUFFERSTORAGE                               BufferStorage;
            PFN_GLBUFFERSUBDATA                               BufferSubData;
            PFN_GLCHECKFRAMEBUFFERSTATUS                      CheckFramebufferStatus;
            PFN_GLCHECKNAMEDFRAMEBUFFERSTATUS                 CheckNamedFramebufferStatus;
            PFN_GLCLAMPCOLOR                                  ClampColor;
            PFN_GLCLEAR                                       Clear;
            PFN_GLCLEARBUFFERDATA                             ClearBufferData;
            PFN_GLCLEARBUFFERSUBDATA                          ClearBufferSubData;
            PFN_GLCLEARBUFFERFI                               ClearBufferfi;
            PFN_GLCLEARBUFFERFV                               ClearBufferfv;
            PFN_GLCLEARBUFFERIV                               ClearBufferiv;
            PFN_GLCLEARBUFFERUIV                              ClearBufferuiv;
            PFN_GLCLEARCOLOR                                  ClearColor;
            PFN_GLCLEARDEPTH                                  ClearDepth;
            PFN_GLCLEARDEPTHF                                 ClearDepthf;
            PFN_GLCLEARNAMEDBUFFERDATA                        ClearNamedBufferData;
            PFN_GLCLEARNAMEDBUFFERSUBDATA                     ClearNamedBufferSubData;
            PFN_GLCLEARNAMEDFRAMEBUFFERFI                     ClearNamedFramebufferfi;
            PFN_GLCLEARNAMEDFRAMEBUFFERFV                     ClearNamedFramebufferfv;
            PFN_GLCLEARNAMEDFRAMEBUFFERIV                     ClearNamedFramebufferiv;
            PFN_GLCLEARNAMEDFRAMEBUFFERUIV                    ClearNamedFramebufferuiv;
            PFN_GLCLEARSTENCIL                                ClearStencil;
            PFN_GLCLEARTEXIMAGE                               ClearTexImage;
            PFN_GLCLEARTEXSUBIMAGE                            ClearTexSubImage;
            PFN_GLCLIENTWAITSYNC                              ClientWaitSync;
            PFN_GLCOLORMASK                                   ColorMask;
            PFN_GLCOLORMASKI                                  ColorMaski;
            PFN_GLCOLORP3UI                                   ColorP3ui;
            PFN_GLCOLORP3UIV                                  ColorP3uiv;
            PFN_GLCOLORP4UI                                   ColorP4ui;
            PFN_GLCOLORP4UIV                                  ColorP4uiv;
            PFN_GLCOMPILESHADER                               CompileShader;
            PFN_GLCOMPRESSEDTEXIMAGE1D                        CompressedTexImage1D;
            PFN_GLCOMPRESSEDTEXIMAGE2D                        CompressedTexImage2D;
            PFN_GLCOMPRESSEDTEXIMAGE3D                        CompressedTexImage3D;
            PFN_GLCOMPRESSEDTEXSUBIMAGE1D                     CompressedTexSubImage1D;
            PFN_GLCOMPRESSEDTEXSUBIMAGE2D                     CompressedTexSubImage2D;
            PFN_GLCOMPRESSEDTEXSUBIMAGE3D                     CompressedTexSubImage3D;
            PFN_GLCOMPRESSEDTEXTURESUBIMAGE1D                 CompressedTextureSubImage1D;
            PFN_GLCOMPRESSEDTEXTURESUBIMAGE2D                 CompressedTextureSubImage2D;
            PFN_GLCOMPRESSEDTEXTURESUBIMAGE3D                 CompressedTextureSubImage3D;
            PFN_GLCOPYBUFFERSUBDATA                           CopyBufferSubData;
            PFN_GLCOPYIMAGESUBDATA                            CopyImageSubData;
            PFN_GLCOPYNAMEDBUFFERSUBDATA                      CopyNamedBufferSubData;
            PFN_GLCOPYTEXIMAGE1D                              CopyTexImage1D;
            PFN_GLCOPYTEXIMAGE2D                              CopyTexImage2D;
            PFN_GLCOPYTEXSUBIMAGE1D                           CopyTexSubImage1D;
            PFN_GLCOPYTEXSUBIMAGE2D                           CopyTexSubImage2D;
            PFN_GLCOPYTEXSUBIMAGE3D                           CopyTexSubImage3D;
            PFN_GLCOPYTEXTURESUBIMAGE1D                       CopyTextureSubImage1D;
            PFN_GLCOPYTEXTURESUBIMAGE2D                       CopyTextureSubImage2D;
            PFN_GLCOPYTEXTURESUBIMAGE3D                       CopyTextureSubImage3D;
            PFN_GLCREATEBUFFERS                               CreateBuffers;
            PFN_GLCREATEFRAMEBUFFERS                          CreateFramebuffers;
            PFN_GLCREATEPROGRAM                               CreateProgram;
            PFN_GLCREATEPROGRAMPIPELINES                      CreateProgramPipelines;
            PFN_GLCREATEQUERIES                               CreateQueries;
            PFN_GLCREATERENDERBUFFERS                         CreateRenderbuffers;
            PFN_GLCREATESAMPLERS                              CreateSamplers;
            PFN_GLCREATESHADER                                CreateShader;
            PFN_GLCREATESHADERPROGRAMV                        CreateShaderProgramv;
            PFN_GLCREATETEXTURES                              CreateTextures;
            PFN_GLCREATETRANSFORMFEEDBACKS                    CreateTransformFeedbacks;
            PFN_GLCREATEVERTEXARRAYS                          CreateVertexArrays;
            PFN_GLCULLFACE                                    CullFace;
            PFN_GLDEBUGMESSAGECALLBACK                        DebugMessageCallback;
            PFN_GLDEBUGMESSAGECONTROL                         DebugMessageControl;
            PFN_GLDEBUGMESSAGEINSERT                          DebugMessageInsert;
            PFN_GLDELETEBUFFERS                               DeleteBuffers;
            PFN_GLDELETEFRAMEBUFFERS                          DeleteFramebuffers;
            PFN_GLDELETEPROGRAM                               DeleteProgram;
            PFN_GLDELETEPROGRAMPIPELINES                      DeleteProgramPipelines;
            PFN_GLDELETEQUERIES                               DeleteQueries;
            PFN_GLDELETERENDERBUFFERS                         DeleteRenderbuffers;
            PFN_GLDELETESAMPLERS                              DeleteSamplers;
            PFN_GLDELETESHADER                                DeleteShader;
            PFN_GLDELETESYNC                                  DeleteSync;
            PFN_GLDELETETEXTURES                              DeleteTextures;
            PFN_GLDELETETRANSFORMFEEDBACKS                    DeleteTransformFeedbacks;
            PFN_GLDELETEVERTEXARRAYS                          DeleteVertexArrays;
            PFN_GLDEPTHFUNC                                   DepthFunc;
            PFN_GLDEPTHMASK                                   DepthMask;
            PFN_GLDEPTHRANGE                                  DepthRange;
            PFN_GLDEPTHRANGEARRAYV                            DepthRangeArrayv;
            PFN_GLDEPTHRANGEINDEXED                           DepthRangeIndexed;
            PFN_GLDEPTHRANGEF                                 DepthRangef;
            PFN_GLDETACHSHADER                                DetachShader;
            PFN_GLDISABLE                                     Disable;
            PFN_GLDISABLEVERTEXARRAYATTRIB                    DisableVertexArrayAttrib;
            PFN_GLDISABLEVERTEXATTRIBARRAY                    DisableVertexAttribArray;
            PFN_GLDISABLEI                                    Disablei;
            PFN_GLDISPATCHCOMPUTE                             DispatchCompute;
            PFN_GLDISPATCHCOMPUTEINDIRECT                     DispatchComputeIndirect;
            PFN_GLDRAWARRAYS                                  DrawArrays;
            PFN_GLDRAWARRAYSINDIRECT                          DrawArraysIndirect;
            PFN_GLDRAWARRAYSINSTANCED                         DrawArraysInstanced;
            PFN_GLDRAWARRAYSINSTANCEDBASEINSTANCE             DrawArraysInstancedBaseInstance;
            PFN_GLDRAWBUFFER                                  DrawBuffer;
            PFN_GLDRAWBUFFERS                                 DrawBuffers;
            PFN_GLDRAWELEMENTS                                DrawElements;
            PFN_GLDRAWELEMENTSBASEVERTEX                      DrawElementsBaseVertex;
            PFN_GLDRAWELEMENTSINDIRECT                        DrawElementsIndirect;
            PFN_GLDRAWELEMENTSINSTANCED                       DrawElementsInstanced;
            PFN_GLDRAWELEMENTSINSTANCEDBASEINSTANCE           DrawElementsInstancedBaseInstance;
            PFN_GLDRAWELEMENTSINSTANCEDBASEVERTEX             DrawElementsInstancedBaseVertex;
            PFN_GLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCE DrawElementsInstancedBaseVertexBaseInstance;
            PFN_GLDRAWRANGEELEMENTS                           DrawRangeElements;
            PFN_GLDRAWRANGEELEMENTSBASEVERTEX                 DrawRangeElementsBaseVertex;
            PFN_GLDRAWTRANSFORMFEEDBACK                       DrawTransformFeedback;
            PFN_GLDRAWTRANSFORMFEEDBACKINSTANCED              DrawTransformFeedbackInstanced;
            PFN_GLDRAWTRANSFORMFEEDBACKSTREAM                 DrawTransformFeedbackStream;
            PFN_GLDRAWTRANSFORMFEEDBACKSTREAMINSTANCED        DrawTransformFeedbackStreamInstanced;
            PFN_GLENABLE                                      Enable;
            PFN_GLENABLEVERTEXARRAYATTRIB                     EnableVertexArrayAttrib;
            PFN_GLENABLEVERTEXATTRIBARRAY                     EnableVertexAttribArray;
            PFN_GLENABLEI                                     Enablei;
            PFN_GLENDCONDITIONALRENDER                        EndConditionalRender;
            PFN_GLENDQUERY                                    EndQuery;
            PFN_GLENDQUERYINDEXED                             EndQueryIndexed;
            PFN_GLENDTRANSFORMFEEDBACK                        EndTransformFeedback;
            PFN_GLFENCESYNC                                   FenceSync;
            PFN_GLFINISH                                      Finish;
            PFN_GLFLUSH                                       Flush;
            PFN_GLFLUSHMAPPEDBUFFERRANGE                      FlushMappedBufferRange;
            PFN_GLFLUSHMAPPEDNAMEDBUFFERRANGE                 FlushMappedNamedBufferRange;
            PFN_GLFRAMEBUFFERPARAMETERI                       FramebufferParameteri;
            PFN_GLFRAMEBUFFERRENDERBUFFER                     FramebufferRenderbuffer;
            PFN_GLFRAMEBUFFERTEXTURE                          FramebufferTexture;
            PFN_GLFRAMEBUFFERTEXTURE1D                        FramebufferTexture1D;
            PFN_GLFRAMEBUFFERTEXTURE2D                        FramebufferTexture2D;
            PFN_GLFRAMEBUFFERTEXTURE3D                        FramebufferTexture3D;
            PFN_GLFRAMEBUFFERTEXTURELAYER                     FramebufferTextureLayer;
            PFN_GLFRONTFACE                                   FrontFace;
            PFN_GLGENBUFFERS                                  GenBuffers;
            PFN_GLGENFRAMEBUFFERS                             GenFramebuffers;
            PFN_GLGENPROGRAMPIPELINES                         GenProgramPipelines;
            PFN_GLGENQUERIES                                  GenQueries;
            PFN_GLGENRENDERBUFFERS                            GenRenderbuffers;
            PFN_GLGENSAMPLERS                                 GenSamplers;
            PFN_GLGENTEXTURES                                 GenTextures;
            PFN_GLGENTRANSFORMFEEDBACKS                       GenTransformFeedbacks;
            PFN_GLGENVERTEXARRAYS                             GenVertexArrays;
            PFN_GLGENERATEMIPMAP                              GenerateMipmap;
            PFN_GLGENERATETEXTUREMIPMAP                       GenerateTextureMipmap;
            PFN_GLGETACTIVEATOMICCOUNTERBUFFERIV              GetActiveAtomicCounterBufferiv;
            PFN_GLGETACTIVEATTRIB                             GetActiveAttrib;
            PFN_GLGETACTIVESUBROUTINENAME                     GetActiveSubroutineName;
            PFN_GLGETACTIVESUBROUTINEUNIFORMNAME              GetActiveSubroutineUniformName;
            PFN_GLGETACTIVESUBROUTINEUNIFORMIV                GetActiveSubroutineUniformiv;
            PFN_GLGETACTIVEUNIFORM                            GetActiveUniform;
            PFN_GLGETACTIVEUNIFORMBLOCKNAME                   GetActiveUniformBlockName;
            PFN_GLGETACTIVEUNIFORMBLOCKIV                     GetActiveUniformBlockiv;
            PFN_GLGETACTIVEUNIFORMNAME                        GetActiveUniformName;
            PFN_GLGETACTIVEUNIFORMSIV                         GetActiveUniformsiv;
            PFN_GLGETATTACHEDSHADERS                          GetAttachedShaders;
            PFN_GLGETATTRIBLOCATION                           GetAttribLocation;
            PFN_GLGETBOOLEANI_V                               GetBooleani_v;
            PFN_GLGETBOOLEANV                                 GetBooleanv;
            PFN_GLGETBUFFERPARAMETERI64V                      GetBufferParameteri64v;
            PFN_GLGETBUFFERPARAMETERIV                        GetBufferParameteriv;
            PFN_GLGETBUFFERPOINTERV                           GetBufferPointerv;
            PFN_GLGETBUFFERSUBDATA                            GetBufferSubData;
            PFN_GLGETCOMPRESSEDTEXIMAGE                       GetCompressedTexImage;
            PFN_GLGETCOMPRESSEDTEXTUREIMAGE                   GetCompressedTextureImage;
            PFN_GLGETDEBUGMESSAGELOG                          GetDebugMessageLog;
            PFN_GLGETDOUBLEI_V                                GetDoublei_v;
            PFN_GLGETDOUBLEV                                  GetDoublev;
            PFN_GLGETERROR                                    GetError;
            PFN_GLGETFLOATI_V                                 GetFloati_v;
            PFN_GLGETFLOATV                                   GetFloatv;
            PFN_GLGETFRAGDATAINDEX                            GetFragDataIndex;
            PFN_GLGETFRAGDATALOCATION                         GetFragDataLocation;
            PFN_GLGETFRAMEBUFFERATTACHMENTPARAMETERIV         GetFramebufferAttachmentParameteriv;
            PFN_GLGETFRAMEBUFFERPARAMETERIV                   GetFramebufferParameteriv;
            PFN_GLGETINTEGER64I_V                             GetInteger64i_v;
            PFN_GLGETINTEGER64V                               GetInteger64v;
            PFN_GLGETINTEGERI_V                               GetIntegeri_v;
            PFN_GLGETINTEGERV                                 GetIntegerv;
            PFN_GLGETINTERNALFORMATI64V                       GetInternalformati64v;
            PFN_GLGETINTERNALFORMATIV                         GetInternalformativ;
            PFN_GLGETMULTISAMPLEFV                            GetMultisamplefv;
            PFN_GLGETNAMEDBUFFERPARAMETERI64V                 GetNamedBufferParameteri64v;
            PFN_GLGETNAMEDBUFFERPARAMETERIV                   GetNamedBufferParameteriv;
            PFN_GLGETNAMEDBUFFERPOINTERV                      GetNamedBufferPointerv;
            PFN_GLGETNAMEDBUFFERSUBDATA                       GetNamedBufferSubData;
            PFN_GLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIV    GetNamedFramebufferAttachmentParameteriv;
            PFN_GLGETNAMEDFRAMEBUFFERPARAMETERIV              GetNamedFramebufferParameteriv;
            PFN_GLGETNAMEDRENDERBUFFERPARAMETERIV             GetNamedRenderbufferParameteriv;
            PFN_GLGETOBJECTLABEL                              GetObjectLabel;
            PFN_GLGETOBJECTPTRLABEL                           GetObjectPtrLabel;
            PFN_GLGETPOINTERV                                 GetPointerv;
            PFN_GLGETPROGRAMBINARY                            GetProgramBinary;
            PFN_GLGETPROGRAMINFOLOG                           GetProgramInfoLog;
            PFN_GLGETPROGRAMINTERFACEIV                       GetProgramInterfaceiv;
            PFN_GLGETPROGRAMPIPELINEINFOLOG                   GetProgramPipelineInfoLog;
            PFN_GLGETPROGRAMPIPELINEIV                        GetProgramPipelineiv;
            PFN_GLGETPROGRAMRESOURCEINDEX                     GetProgramResourceIndex;
            PFN_GLGETPROGRAMRESOURCELOCATION                  GetProgramResourceLocation;
            PFN_GLGETPROGRAMRESOURCELOCATIONINDEX             GetProgramResourceLocationIndex;
            PFN_GLGETPROGRAMRESOURCENAME                      GetProgramResourceName;
            PFN_GLGETPROGRAMRESOURCEIV                        GetProgramResourceiv;
            PFN_GLGETPROGRAMSTAGEIV                           GetProgramStageiv;
            PFN_GLGETPROGRAMIV                                GetProgramiv;
            PFN_GLGETQUERYBUFFEROBJECTI64V                    GetQueryBufferObjecti64v;
            PFN_GLGETQUERYBUFFEROBJECTIV                      GetQueryBufferObjectiv;
            PFN_GLGETQUERYBUFFEROBJECTUI64V                   GetQueryBufferObjectui64v;
            PFN_GLGETQUERYBUFFEROBJECTUIV                     GetQueryBufferObjectuiv;
            PFN_GLGETQUERYINDEXEDIV                           GetQueryIndexediv;
            PFN_GLGETQUERYOBJECTI64V                          GetQueryObjecti64v;
            PFN_GLGETQUERYOBJECTIV                            GetQueryObjectiv;
            PFN_GLGETQUERYOBJECTUI64V                         GetQueryObjectui64v;
            PFN_GLGETQUERYOBJECTUIV                           GetQueryObjectuiv;
            PFN_GLGETQUERYIV                                  GetQueryiv;
            PFN_GLGETRENDERBUFFERPARAMETERIV                  GetRenderbufferParameteriv;
            PFN_GLGETSAMPLERPARAMETERIIV                      GetSamplerParameterIiv;
            PFN_GLGETSAMPLERPARAMETERIUIV                     GetSamplerParameterIuiv;
            PFN_GLGETSAMPLERPARAMETERFV                       GetSamplerParameterfv;
            PFN_GLGETSAMPLERPARAMETERIV                       GetSamplerParameteriv;
            PFN_GLGETSHADERINFOLOG                            GetShaderInfoLog;
            PFN_GLGETSHADERPRECISIONFORMAT                    GetShaderPrecisionFormat;
            PFN_GLGETSHADERSOURCE                             GetShaderSource;
            PFN_GLGETSHADERIV                                 GetShaderiv;
            PFN_GLGETSTRING                                   GetString;
            PFN_GLGETSTRINGI                                  GetStringi;
            PFN_GLGETSUBROUTINEINDEX                          GetSubroutineIndex;
            PFN_GLGETSUBROUTINEUNIFORMLOCATION                GetSubroutineUniformLocation;
            PFN_GLGETSYNCIV                                   GetSynciv;
            PFN_GLGETTEXIMAGE                                 GetTexImage;
            PFN_GLGETTEXLEVELPARAMETERFV                      GetTexLevelParameterfv;
            PFN_GLGETTEXLEVELPARAMETERIV                      GetTexLevelParameteriv;
            PFN_GLGETTEXPARAMETERIIV                          GetTexParameterIiv;
            PFN_GLGETTEXPARAMETERIUIV                         GetTexParameterIuiv;
            PFN_GLGETTEXPARAMETERFV                           GetTexParameterfv;
            PFN_GLGETTEXPARAMETERIV                           GetTexParameteriv;
            PFN_GLGETTEXTUREIMAGE                             GetTextureImage;
            PFN_GLGETTEXTURELEVELPARAMETERFV                  GetTextureLevelParameterfv;
            PFN_GLGETTEXTURELEVELPARAMETERIV                  GetTextureLevelParameteriv;
            PFN_GLGETTEXTUREPARAMETERIIV                      GetTextureParameterIiv;
            PFN_GLGETTEXTUREPARAMETERIUIV                     GetTextureParameterIuiv;
            PFN_GLGETTEXTUREPARAMETERFV                       GetTextureParameterfv;
            PFN_GLGETTEXTUREPARAMETERIV                       GetTextureParameteriv;
            PFN_GLGETTRANSFORMFEEDBACKVARYING                 GetTransformFeedbackVarying;
            PFN_GLGETTRANSFORMFEEDBACKI64_V                   GetTransformFeedbacki64_v;
            PFN_GLGETTRANSFORMFEEDBACKI_V                     GetTransformFeedbacki_v;
            PFN_GLGETTRANSFORMFEEDBACKIV                      GetTransformFeedbackiv;
            PFN_GLGETUNIFORMBLOCKINDEX                        GetUniformBlockIndex;
            PFN_GLGETUNIFORMINDICES                           GetUniformIndices;
            PFN_GLGETUNIFORMLOCATION                          GetUniformLocation;
            PFN_GLGETUNIFORMSUBROUTINEUIV                     GetUniformSubroutineuiv;
            PFN_GLGETUNIFORMDV                                GetUniformdv;
            PFN_GLGETUNIFORMFV                                GetUniformfv;
            PFN_GLGETUNIFORMIV                                GetUniformiv;
            PFN_GLGETUNIFORMUIV                               GetUniformuiv;
            PFN_GLGETVERTEXARRAYINDEXED64IV                   GetVertexArrayIndexed64iv;
            PFN_GLGETVERTEXARRAYINDEXEDIV                     GetVertexArrayIndexediv;
            PFN_GLGETVERTEXARRAYIV                            GetVertexArrayiv;
            PFN_GLGETVERTEXATTRIBIIV                          GetVertexAttribIiv;
            PFN_GLGETVERTEXATTRIBIUIV                         GetVertexAttribIuiv;
            PFN_GLGETVERTEXATTRIBLDV                          GetVertexAttribLdv;
            PFN_GLGETVERTEXATTRIBPOINTERV                     GetVertexAttribPointerv;
            PFN_GLGETVERTEXATTRIBDV                           GetVertexAttribdv;
            PFN_GLGETVERTEXATTRIBFV                           GetVertexAttribfv;
            PFN_GLGETVERTEXATTRIBIV                           GetVertexAttribiv;
            PFN_GLHINT                                        Hint;
            PFN_GLINVALIDATEBUFFERDATA                        InvalidateBufferData;
            PFN_GLINVALIDATEBUFFERSUBDATA                     InvalidateBufferSubData;
            PFN_GLINVALIDATEFRAMEBUFFER                       InvalidateFramebuffer;
            PFN_GLINVALIDATENAMEDFRAMEBUFFERDATA              InvalidateNamedFramebufferData;
            PFN_GLINVALIDATENAMEDFRAMEBUFFERSUBDATA           InvalidateNamedFramebufferSubData;
            PFN_GLINVALIDATESUBFRAMEBUFFER                    InvalidateSubFramebuffer;
            PFN_GLINVALIDATETEXIMAGE                          InvalidateTexImage;
            PFN_GLINVALIDATETEXSUBIMAGE                       InvalidateTexSubImage;
            PFN_GLISBUFFER                                    IsBuffer;
            PFN_GLISENABLED                                   IsEnabled;
            PFN_GLISENABLEDI                                  IsEnabledi;
            PFN_GLISFRAMEBUFFER                               IsFramebuffer;
            PFN_GLISPROGRAM                                   IsProgram;
            PFN_GLISPROGRAMPIPELINE                           IsProgramPipeline;
            PFN_GLISQUERY                                     IsQuery;
            PFN_GLISRENDERBUFFER                              IsRenderbuffer;
            PFN_GLISSAMPLER                                   IsSampler;
            PFN_GLISSHADER                                    IsShader;
            PFN_GLISSYNC                                      IsSync;
            PFN_GLISTEXTURE                                   IsTexture;
            PFN_GLISTRANSFORMFEEDBACK                         IsTransformFeedback;
            PFN_GLISVERTEXARRAY                               IsVertexArray;
            PFN_GLLINEWIDTH                                   LineWidth;
            PFN_GLLINKPROGRAM                                 LinkProgram;
            PFN_GLLOGICOP                                     LogicOp;
            PFN_GLMAPBUFFER                                   MapBuffer;
            PFN_GLMAPBUFFERRANGE                              MapBufferRange;
            PFN_GLMAPNAMEDBUFFER                              MapNamedBuffer;
            PFN_GLMAPNAMEDBUFFERRANGE                         MapNamedBufferRange;
            PFN_GLMEMORYBARRIER                               MemoryBarrier;
            PFN_GLMINSAMPLESHADING                            MinSampleShading;
            PFN_GLMULTIDRAWARRAYS                             MultiDrawArrays;
            PFN_GLMULTIDRAWARRAYSINDIRECT                     MultiDrawArraysIndirect;
            PFN_GLMULTIDRAWELEMENTS                           MultiDrawElements;
            PFN_GLMULTIDRAWELEMENTSBASEVERTEX                 MultiDrawElementsBaseVertex;
            PFN_GLMULTIDRAWELEMENTSINDIRECT                   MultiDrawElementsIndirect;
            PFN_GLMULTITEXCOORDP1UI                           MultiTexCoordP1ui;
            PFN_GLMULTITEXCOORDP1UIV                          MultiTexCoordP1uiv;
            PFN_GLMULTITEXCOORDP2UI                           MultiTexCoordP2ui;
            PFN_GLMULTITEXCOORDP2UIV                          MultiTexCoordP2uiv;
            PFN_GLMULTITEXCOORDP3UI                           MultiTexCoordP3ui;
            PFN_GLMULTITEXCOORDP3UIV                          MultiTexCoordP3uiv;
            PFN_GLMULTITEXCOORDP4UI                           MultiTexCoordP4ui;
            PFN_GLMULTITEXCOORDP4UIV                          MultiTexCoordP4uiv;
            PFN_GLNAMEDBUFFERDATA                             NamedBufferData;
            PFN_GLNAMEDBUFFERSTORAGE                          NamedBufferStorage;
            PFN_GLNAMEDBUFFERSUBDATA                          NamedBufferSubData;
            PFN_GLNAMEDFRAMEBUFFERDRAWBUFFER                  NamedFramebufferDrawBuffer;
            PFN_GLNAMEDFRAMEBUFFERDRAWBUFFERS                 NamedFramebufferDrawBuffers;
            PFN_GLNAMEDFRAMEBUFFERPARAMETERI                  NamedFramebufferParameteri;
            PFN_GLNAMEDFRAMEBUFFERREADBUFFER                  NamedFramebufferReadBuffer;
            PFN_GLNAMEDFRAMEBUFFERRENDERBUFFER                NamedFramebufferRenderbuffer;
            PFN_GLNAMEDFRAMEBUFFERTEXTURE                     NamedFramebufferTexture;
            PFN_GLNAMEDFRAMEBUFFERTEXTURELAYER                NamedFramebufferTextureLayer;
            PFN_GLNAMEDRENDERBUFFERSTORAGE                    NamedRenderbufferStorage;
            PFN_GLNAMEDRENDERBUFFERSTORAGEMULTISAMPLE         NamedRenderbufferStorageMultisample;
            PFN_GLNORMALP3UI                                  NormalP3ui;
            PFN_GLNORMALP3UIV                                 NormalP3uiv;
            PFN_GLOBJECTLABEL                                 ObjectLabel;
            PFN_GLOBJECTPTRLABEL                              ObjectPtrLabel;
            PFN_GLPATCHPARAMETERFV                            PatchParameterfv;
            PFN_GLPATCHPARAMETERI                             PatchParameteri;
            PFN_GLPAUSETRANSFORMFEEDBACK                      PauseTransformFeedback;
            PFN_GLPIXELSTOREF                                 PixelStoref;
            PFN_GLPIXELSTOREI                                 PixelStorei;
            PFN_GLPOINTPARAMETERF                             PointParameterf;
            PFN_GLPOINTPARAMETERFV                            PointParameterfv;
            PFN_GLPOINTPARAMETERI                             PointParameteri;
            PFN_GLPOINTPARAMETERIV                            PointParameteriv;
            PFN_GLPOINTSIZE                                   PointSize;
            PFN_GLPOLYGONMODE                                 PolygonMode;
            PFN_GLPOLYGONOFFSET                               PolygonOffset;
            PFN_GLPOPDEBUGGROUP                               PopDebugGroup;
            PFN_GLPRIMITIVERESTARTINDEX                       PrimitiveRestartIndex;
            PFN_GLPROGRAMBINARY                               ProgramBinary;
            PFN_GLPROGRAMPARAMETERI                           ProgramParameteri;
            PFN_GLPROGRAMUNIFORM1D                            ProgramUniform1d;
            PFN_GLPROGRAMUNIFORM1DV                           ProgramUniform1dv;
            PFN_GLPROGRAMUNIFORM1F                            ProgramUniform1f;
            PFN_GLPROGRAMUNIFORM1FV                           ProgramUniform1fv;
            PFN_GLPROGRAMUNIFORM1I                            ProgramUniform1i;
            PFN_GLPROGRAMUNIFORM1IV                           ProgramUniform1iv;
            PFN_GLPROGRAMUNIFORM1UI                           ProgramUniform1ui;
            PFN_GLPROGRAMUNIFORM1UIV                          ProgramUniform1uiv;
            PFN_GLPROGRAMUNIFORM2D                            ProgramUniform2d;
            PFN_GLPROGRAMUNIFORM2DV                           ProgramUniform2dv;
            PFN_GLPROGRAMUNIFORM2F                            ProgramUniform2f;
            PFN_GLPROGRAMUNIFORM2FV                           ProgramUniform2fv;
            PFN_GLPROGRAMUNIFORM2I                            ProgramUniform2i;
            PFN_GLPROGRAMUNIFORM2IV                           ProgramUniform2iv;
            PFN_GLPROGRAMUNIFORM2UI                           ProgramUniform2ui;
            PFN_GLPROGRAMUNIFORM2UIV                          ProgramUniform2uiv;
            PFN_GLPROGRAMUNIFORM3D                            ProgramUniform3d;
            PFN_GLPROGRAMUNIFORM3DV                           ProgramUniform3dv;
            PFN_GLPROGRAMUNIFORM3F                            ProgramUniform3f;
            PFN_GLPROGRAMUNIFORM3FV                           ProgramUniform3fv;
            PFN_GLPROGRAMUNIFORM3I                            ProgramUniform3i;
            PFN_GLPROGRAMUNIFORM3IV                           ProgramUniform3iv;
            PFN_GLPROGRAMUNIFORM3UI                           ProgramUniform3ui;
            PFN_GLPROGRAMUNIFORM3UIV                          ProgramUniform3uiv;
            PFN_GLPROGRAMUNIFORM4D                            ProgramUniform4d;
            PFN_GLPROGRAMUNIFORM4DV                           ProgramUniform4dv;
            PFN_GLPROGRAMUNIFORM4F                            ProgramUniform4f;
            PFN_GLPROGRAMUNIFORM4FV                           ProgramUniform4fv;
            PFN_GLPROGRAMUNIFORM4I                            ProgramUniform4i;
            PFN_GLPROGRAMUNIFORM4IV                           ProgramUniform4iv;
            PFN_GLPROGRAMUNIFORM4UI                           ProgramUniform4ui;
            PFN_GLPROGRAMUNIFORM4UIV                          ProgramUniform4uiv;
            PFN_GLPROGRAMUNIFORMMATRIX2DV                     ProgramUniformMatrix2dv;
            PFN_GLPROGRAMUNIFORMMATRIX2FV                     ProgramUniformMatrix2fv;
            PFN_GLPROGRAMUNIFORMMATRIX2X3DV                   ProgramUniformMatrix2x3dv;
            PFN_GLPROGRAMUNIFORMMATRIX2X3FV                   ProgramUniformMatrix2x3fv;
            PFN_GLPROGRAMUNIFORMMATRIX2X4DV                   ProgramUniformMatrix2x4dv;
            PFN_GLPROGRAMUNIFORMMATRIX2X4FV                   ProgramUniformMatrix2x4fv;
            PFN_GLPROGRAMUNIFORMMATRIX3DV                     ProgramUniformMatrix3dv;
            PFN_GLPROGRAMUNIFORMMATRIX3FV                     ProgramUniformMatrix3fv;
            PFN_GLPROGRAMUNIFORMMATRIX3X2DV                   ProgramUniformMatrix3x2dv;
            PFN_GLPROGRAMUNIFORMMATRIX3X2FV                   ProgramUniformMatrix3x2fv;
            PFN_GLPROGRAMUNIFORMMATRIX3X4DV                   ProgramUniformMatrix3x4dv;
            PFN_GLPROGRAMUNIFORMMATRIX3X4FV                   ProgramUniformMatrix3x4fv;
            PFN_GLPROGRAMUNIFORMMATRIX4DV                     ProgramUniformMatrix4dv;
            PFN_GLPROGRAMUNIFORMMATRIX4FV                     ProgramUniformMatrix4fv;
            PFN_GLPROGRAMUNIFORMMATRIX4X2DV                   ProgramUniformMatrix4x2dv;
            PFN_GLPROGRAMUNIFORMMATRIX4X2FV                   ProgramUniformMatrix4x2fv;
            PFN_GLPROGRAMUNIFORMMATRIX4X3DV                   ProgramUniformMatrix4x3dv;
            PFN_GLPROGRAMUNIFORMMATRIX4X3FV                   ProgramUniformMatrix4x3fv;
            PFN_GLPROVOKINGVERTEX                             ProvokingVertex;
            PFN_GLPUSHDEBUGGROUP                              PushDebugGroup;
            PFN_GLQUERYCOUNTER                                QueryCounter;
            PFN_GLREADBUFFER                                  ReadBuffer;
            PFN_GLREADPIXELS                                  ReadPixels;
            PFN_GLRELEASESHADERCOMPILER                       ReleaseShaderCompiler;
            PFN_GLRENDERBUFFERSTORAGE                         RenderbufferStorage;
            PFN_GLRENDERBUFFERSTORAGEMULTISAMPLE              RenderbufferStorageMultisample;
            PFN_GLRESUMETRANSFORMFEEDBACK                     ResumeTransformFeedback;
            PFN_GLSAMPLECOVERAGE                              SampleCoverage;
            PFN_GLSAMPLEMASKI                                 SampleMaski;
            PFN_GLSAMPLERPARAMETERIIV                         SamplerParameterIiv;
            PFN_GLSAMPLERPARAMETERIUIV                        SamplerParameterIuiv;
            PFN_GLSAMPLERPARAMETERF                           SamplerParameterf;
            PFN_GLSAMPLERPARAMETERFV                          SamplerParameterfv;
            PFN_GLSAMPLERPARAMETERI                           SamplerParameteri;
            PFN_GLSAMPLERPARAMETERIV                          SamplerParameteriv;
            PFN_GLSCISSOR                                     Scissor;
            PFN_GLSCISSORARRAYV                               ScissorArrayv;
            PFN_GLSCISSORINDEXED                              ScissorIndexed;
            PFN_GLSCISSORINDEXEDV                             ScissorIndexedv;
            PFN_GLSECONDARYCOLORP3UI                          SecondaryColorP3ui;
            PFN_GLSECONDARYCOLORP3UIV                         SecondaryColorP3uiv;
            PFN_GLSHADERBINARY                                ShaderBinary;
            PFN_GLSHADERSOURCE                                ShaderSource;
            PFN_GLSHADERSTORAGEBLOCKBINDING                   ShaderStorageBlockBinding;
            PFN_GLSTENCILFUNC                                 StencilFunc;
            PFN_GLSTENCILFUNCSEPARATE                         StencilFuncSeparate;
            PFN_GLSTENCILMASK                                 StencilMask;
            PFN_GLSTENCILMASKSEPARATE                         StencilMaskSeparate;
            PFN_GLSTENCILOP                                   StencilOp;
            PFN_GLSTENCILOPSEPARATE                           StencilOpSeparate;
            PFN_GLTEXBUFFER                                   TexBuffer;
            PFN_GLTEXBUFFERRANGE                              TexBufferRange;
            PFN_GLTEXCOORDP1UI                                TexCoordP1ui;
            PFN_GLTEXCOORDP1UIV                               TexCoordP1uiv;
            PFN_GLTEXCOORDP2UI                                TexCoordP2ui;
            PFN_GLTEXCOORDP2UIV                               TexCoordP2uiv;
            PFN_GLTEXCOORDP3UI                                TexCoordP3ui;
            PFN_GLTEXCOORDP3UIV                               TexCoordP3uiv;
            PFN_GLTEXCOORDP4UI                                TexCoordP4ui;
            PFN_GLTEXCOORDP4UIV                               TexCoordP4uiv;
            PFN_GLTEXIMAGE1D                                  TexImage1D;
            PFN_GLTEXIMAGE2D                                  TexImage2D;
            PFN_GLTEXIMAGE2DMULTISAMPLE                       TexImage2DMultisample;
            PFN_GLTEXIMAGE3D                                  TexImage3D;
            PFN_GLTEXIMAGE3DMULTISAMPLE                       TexImage3DMultisample;
            PFN_GLTEXPARAMETERIIV                             TexParameterIiv;
            PFN_GLTEXPARAMETERIUIV                            TexParameterIuiv;
            PFN_GLTEXPARAMETERF                               TexParameterf;
            PFN_GLTEXPARAMETERFV                              TexParameterfv;
            PFN_GLTEXPARAMETERI                               TexParameteri;
            PFN_GLTEXPARAMETERIV                              TexParameteriv;
            PFN_GLTEXSTORAGE1D                                TexStorage1D;
            PFN_GLTEXSTORAGE2D                                TexStorage2D;
            PFN_GLTEXSTORAGE2DMULTISAMPLE                     TexStorage2DMultisample;
            PFN_GLTEXSTORAGE3D                                TexStorage3D;
            PFN_GLTEXSTORAGE3DMULTISAMPLE                     TexStorage3DMultisample;
            PFN_GLTEXSUBIMAGE1D                               TexSubImage1D;
            PFN_GLTEXSUBIMAGE2D                               TexSubImage2D;
            PFN_GLTEXSUBIMAGE3D                               TexSubImage3D;
            PFN_GLTEXTUREBUFFER                               TextureBuffer;
            PFN_GLTEXTUREBUFFERRANGE                          TextureBufferRange;
            PFN_GLTEXTUREPARAMETERIIV                         TextureParameterIiv;
            PFN_GLTEXTUREPARAMETERIUIV                        TextureParameterIuiv;
            PFN_GLTEXTUREPARAMETERF                           TextureParameterf;
            PFN_GLTEXTUREPARAMETERFV                          TextureParameterfv;
            PFN_GLTEXTUREPARAMETERI                           TextureParameteri;
            PFN_GLTEXTUREPARAMETERIV                          TextureParameteriv;
            PFN_GLTEXTURESTORAGE1D                            TextureStorage1D;
            PFN_GLTEXTURESTORAGE2D                            TextureStorage2D;
            PFN_GLTEXTURESTORAGE2DMULTISAMPLE                 TextureStorage2DMultisample;
            PFN_GLTEXTURESTORAGE3D                            TextureStorage3D;
            PFN_GLTEXTURESTORAGE3DMULTISAMPLE                 TextureStorage3DMultisample;
            PFN_GLTEXTURESUBIMAGE1D                           TextureSubImage1D;
            PFN_GLTEXTURESUBIMAGE2D                           TextureSubImage2D;
            PFN_GLTEXTURESUBIMAGE3D                           TextureSubImage3D;
            PFN_GLTEXTUREVIEW                                 TextureView;
            PFN_GLTRANSFORMFEEDBACKBUFFERBASE                 TransformFeedbackBufferBase;
            PFN_GLTRANSFORMFEEDBACKBUFFERRANGE                TransformFeedbackBufferRange;
            PFN_GLTRANSFORMFEEDBACKVARYINGS                   TransformFeedbackVaryings;
            PFN_GLUNIFORM1D                                   Uniform1d;
            PFN_GLUNIFORM1DV                                  Uniform1dv;
            PFN_GLUNIFORM1F                                   Uniform1f;
            PFN_GLUNIFORM1FV                                  Uniform1fv;
            PFN_GLUNIFORM1I                                   Uniform1i;
            PFN_GLUNIFORM1IV                                  Uniform1iv;
            PFN_GLUNIFORM1UI                                  Uniform1ui;
            PFN_GLUNIFORM1UIV                                 Uniform1uiv;
            PFN_GLUNIFORM2D                                   Uniform2d;
            PFN_GLUNIFORM2DV                                  Uniform2dv;
            PFN_GLUNIFORM2F                                   Uniform2f;
            PFN_GLUNIFORM2FV                                  Uniform2fv;
            PFN_GLUNIFORM2I                                   Uniform2i;
            PFN_GLUNIFORM2IV                                  Uniform2iv;
            PFN_GLUNIFORM2UI                                  Uniform2ui;
            PFN_GLUNIFORM2UIV                                 Uniform2uiv;
            PFN_GLUNIFORM3D                                   Uniform3d;
            PFN_GLUNIFORM3DV                                  Uniform3dv;
            PFN_GLUNIFORM3F                                   Uniform3f;
            PFN_GLUNIFORM3FV                                  Uniform3fv;
            PFN_GLUNIFORM3I                                   Uniform3i;
            PFN_GLUNIFORM3IV                                  Uniform3iv;
            PFN_GLUNIFORM3UI                                  Uniform3ui;
            PFN_GLUNIFORM3UIV                                 Uniform3uiv;
            PFN_GLUNIFORM4D                                   Uniform4d;
            PFN_GLUNIFORM4DV                                  Uniform4dv;
            PFN_GLUNIFORM4F                                   Uniform4f;
            PFN_GLUNIFORM4FV                                  Uniform4fv;
            PFN_GLUNIFORM4I                                   Uniform4i;
            PFN_GLUNIFORM4IV                                  Uniform4iv;
            PFN_GLUNIFORM4UI                                  Uniform4ui;
            PFN_GLUNIFORM4UIV                                 Uniform4uiv;
            PFN_GLUNIFORMBLOCKBINDING                         UniformBlockBinding;
            PFN_GLUNIFORMMATRIX2DV                            UniformMatrix2dv;
            PFN_GLUNIFORMMATRIX2FV                            UniformMatrix2fv;
            PFN_GLUNIFORMMATRIX2X3DV                          UniformMatrix2x3dv;
            PFN_GLUNIFORMMATRIX2X3FV                          UniformMatrix2x3fv;
            PFN_GLUNIFORMMATRIX2X4DV                          UniformMatrix2x4dv;
            PFN_GLUNIFORMMATRIX2X4FV                          UniformMatrix2x4fv;
            PFN_GLUNIFORMMATRIX3DV                            UniformMatrix3dv;
            PFN_GLUNIFORMMATRIX3FV                            UniformMatrix3fv;
            PFN_GLUNIFORMMATRIX3X2DV                          UniformMatrix3x2dv;
            PFN_GLUNIFORMMATRIX3X2FV                          UniformMatrix3x2fv;
            PFN_GLUNIFORMMATRIX3X4DV                          UniformMatrix3x4dv;
            PFN_GLUNIFORMMATRIX3X4FV                          UniformMatrix3x4fv;
            PFN_GLUNIFORMMATRIX4DV                            UniformMatrix4dv;
            PFN_GLUNIFORMMATRIX4FV                            UniformMatrix4fv;
            PFN_GLUNIFORMMATRIX4X2DV                          UniformMatrix4x2dv;
            PFN_GLUNIFORMMATRIX4X2FV                          UniformMatrix4x2fv;
            PFN_GLUNIFORMMATRIX4X3DV                          UniformMatrix4x3dv;
            PFN_GLUNIFORMMATRIX4X3FV                          UniformMatrix4x3fv;
            PFN_GLUNIFORMSUBROUTINESUIV                       UniformSubroutinesuiv;
            PFN_GLUNMAPBUFFER                                 UnmapBuffer;
            PFN_GLUNMAPNAMEDBUFFER                            UnmapNamedBuffer;
            PFN_GLUSEPROGRAM                                  UseProgram;
            PFN_GLUSEPROGRAMSTAGES                            UseProgramStages;
            PFN_GLVALIDATEPROGRAM                             ValidateProgram;
            PFN_GLVALIDATEPROGRAMPIPELINE                     ValidateProgramPipeline;
            PFN_GLVERTEXARRAYATTRIBBINDING                    VertexArrayAttribBinding;
            PFN_GLVERTEXARRAYATTRIBFORMAT                     VertexArrayAttribFormat;
            PFN_GLVERTEXARRAYATTRIBIFORMAT                    VertexArrayAttribIFormat;
            PFN_GLVERTEXARRAYATTRIBLFORMAT                    VertexArrayAttribLFormat;
            PFN_GLVERTEXARRAYBINDINGDIVISOR                   VertexArrayBindingDivisor;
            PFN_GLVERTEXARRAYELEMENTBUFFER                    VertexArrayElementBuffer;
            PFN_GLVERTEXARRAYVERTEXBUFFER                     VertexArrayVertexBuffer;
            PFN_GLVERTEXARRAYVERTEXBUFFERS                    VertexArrayVertexBuffers;
            PFN_GLVERTEXATTRIB1D                              VertexAttrib1d;
            PFN_GLVERTEXATTRIB1DV                             VertexAttrib1dv;
            PFN_GLVERTEXATTRIB1F                              VertexAttrib1f;
            PFN_GLVERTEXATTRIB1FV                             VertexAttrib1fv;
            PFN_GLVERTEXATTRIB1S                              VertexAttrib1s;
            PFN_GLVERTEXATTRIB1SV                             VertexAttrib1sv;
            PFN_GLVERTEXATTRIB2D                              VertexAttrib2d;
            PFN_GLVERTEXATTRIB2DV                             VertexAttrib2dv;
            PFN_GLVERTEXATTRIB2F                              VertexAttrib2f;
            PFN_GLVERTEXATTRIB2FV                             VertexAttrib2fv;
            PFN_GLVERTEXATTRIB2S                              VertexAttrib2s;
            PFN_GLVERTEXATTRIB2SV                             VertexAttrib2sv;
            PFN_GLVERTEXATTRIB3D                              VertexAttrib3d;
            PFN_GLVERTEXATTRIB3DV                             VertexAttrib3dv;
            PFN_GLVERTEXATTRIB3F                              VertexAttrib3f;
            PFN_GLVERTEXATTRIB3FV                             VertexAttrib3fv;
            PFN_GLVERTEXATTRIB3S                              VertexAttrib3s;
            PFN_GLVERTEXATTRIB3SV                             VertexAttrib3sv;
            PFN_GLVERTEXATTRIB4NBV                            VertexAttrib4Nbv;
            PFN_GLVERTEXATTRIB4NIV                            VertexAttrib4Niv;
            PFN_GLVERTEXATTRIB4NSV                            VertexAttrib4Nsv;
            PFN_GLVERTEXATTRIB4NUB                            VertexAttrib4Nub;
            PFN_GLVERTEXATTRIB4NUBV                           VertexAttrib4Nubv;
            PFN_GLVERTEXATTRIB4NUIV                           VertexAttrib4Nuiv;
            PFN_GLVERTEXATTRIB4NUSV                           VertexAttrib4Nusv;
            PFN_GLVERTEXATTRIB4BV                             VertexAttrib4bv;
            PFN_GLVERTEXATTRIB4D                              VertexAttrib4d;
            PFN_GLVERTEXATTRIB4DV                             VertexAttrib4dv;
            PFN_GLVERTEXATTRIB4F                              VertexAttrib4f;
            PFN_GLVERTEXATTRIB4FV                             VertexAttrib4fv;
            PFN_GLVERTEXATTRIB4IV                             VertexAttrib4iv;
            PFN_GLVERTEXATTRIB4S                              VertexAttrib4s;
            PFN_GLVERTEXATTRIB4SV                             VertexAttrib4sv;
            PFN_GLVERTEXATTRIB4UBV                            VertexAttrib4ubv;
            PFN_GLVERTEXATTRIB4UIV                            VertexAttrib4uiv;
            PFN_GLVERTEXATTRIB4USV                            VertexAttrib4usv;
            PFN_GLVERTEXATTRIBBINDING                         VertexAttribBinding;
            PFN_GLVERTEXATTRIBDIVISOR                         VertexAttribDivisor;
            PFN_GLVERTEXATTRIBFORMAT                          VertexAttribFormat;
            PFN_GLVERTEXATTRIBI1I                             VertexAttribI1i;
            PFN_GLVERTEXATTRIBI1IV                            VertexAttribI1iv;
            PFN_GLVERTEXATTRIBI1UI                            VertexAttribI1ui;
            PFN_GLVERTEXATTRIBI1UIV                           VertexAttribI1uiv;
            PFN_GLVERTEXATTRIBI2I                             VertexAttribI2i;
            PFN_GLVERTEXATTRIBI2IV                            VertexAttribI2iv;
            PFN_GLVERTEXATTRIBI2UI                            VertexAttribI2ui;
            PFN_GLVERTEXATTRIBI2UIV                           VertexAttribI2uiv;
            PFN_GLVERTEXATTRIBI3I                             VertexAttribI3i;
            PFN_GLVERTEXATTRIBI3IV                            VertexAttribI3iv;
            PFN_GLVERTEXATTRIBI3UI                            VertexAttribI3ui;
            PFN_GLVERTEXATTRIBI3UIV                           VertexAttribI3uiv;
            PFN_GLVERTEXATTRIBI4BV                            VertexAttribI4bv;
            PFN_GLVERTEXATTRIBI4I                             VertexAttribI4i;
            PFN_GLVERTEXATTRIBI4IV                            VertexAttribI4iv;
            PFN_GLVERTEXATTRIBI4SV                            VertexAttribI4sv;
            PFN_GLVERTEXATTRIBI4UBV                           VertexAttribI4ubv;
            PFN_GLVERTEXATTRIBI4UI                            VertexAttribI4ui;
            PFN_GLVERTEXATTRIBI4UIV                           VertexAttribI4uiv;
            PFN_GLVERTEXATTRIBI4USV                           VertexAttribI4usv;
            PFN_GLVERTEXATTRIBIFORMAT                         VertexAttribIFormat;
            PFN_GLVERTEXATTRIBIPOINTER                        VertexAttribIPointer;
            PFN_GLVERTEXATTRIBL1D                             VertexAttribL1d;
            PFN_GLVERTEXATTRIBL1DV                            VertexAttribL1dv;
            PFN_GLVERTEXATTRIBL2D                             VertexAttribL2d;
            PFN_GLVERTEXATTRIBL2DV                            VertexAttribL2dv;
            PFN_GLVERTEXATTRIBL3D                             VertexAttribL3d;
            PFN_GLVERTEXATTRIBL3DV                            VertexAttribL3dv;
            PFN_GLVERTEXATTRIBL4D                             VertexAttribL4d;
            PFN_GLVERTEXATTRIBL4DV                            VertexAttribL4dv;
            PFN_GLVERTEXATTRIBLFORMAT                         VertexAttribLFormat;
            PFN_GLVERTEXATTRIBLPOINTER                        VertexAttribLPointer;
            PFN_GLVERTEXATTRIBP1UI                            VertexAttribP1ui;
            PFN_GLVERTEXATTRIBP1UIV                           VertexAttribP1uiv;
            PFN_GLVERTEXATTRIBP2UI                            VertexAttribP2ui;
            PFN_GLVERTEXATTRIBP2UIV                           VertexAttribP2uiv;
            PFN_GLVERTEXATTRIBP3UI                            VertexAttribP3ui;
            PFN_GLVERTEXATTRIBP3UIV                           VertexAttribP3uiv;
            PFN_GLVERTEXATTRIBP4UI                            VertexAttribP4ui;
            PFN_GLVERTEXATTRIBP4UIV                           VertexAttribP4uiv;
            PFN_GLVERTEXATTRIBPOINTER                         VertexAttribPointer;
            PFN_GLVERTEXBINDINGDIVISOR                        VertexBindingDivisor;
            PFN_GLVERTEXP2UI                                  VertexP2ui;
            PFN_GLVERTEXP2UIV                                 VertexP2uiv;
            PFN_GLVERTEXP3UI                                  VertexP3ui;
            PFN_GLVERTEXP3UIV                                 VertexP3uiv;
            PFN_GLVERTEXP4UI                                  VertexP4ui;
            PFN_GLVERTEXP4UIV                                 VertexP4uiv;
            PFN_GLVIEWPORT                                    Viewport;
            PFN_GLVIEWPORTARRAYV                              ViewportArrayv;
            PFN_GLVIEWPORTINDEXEDF                            ViewportIndexedf;
            PFN_GLVIEWPORTINDEXEDFV                           ViewportIndexedfv;
            PFN_GLWAITSYNC                                    WaitSync;
        };
    } /* namespace OpenGL */
} /* namespace O8 */

#endif /* O8_OPENGL_GL.HPP */

