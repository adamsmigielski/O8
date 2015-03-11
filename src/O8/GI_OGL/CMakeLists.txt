PROJECT ( GI_OGL )

ADD_LIBRARY (GI_OGL STATIC
			 PCH.cpp
			 PCH.hpp
			 Presentation_ogl.cpp
			 Presentation_ogl.hpp
			 RI_ogl.cpp
			 RI_ogl.hpp
			 Texture_ogl.cpp
			 Texture_ogl.hpp)

TARGET_LINK_LIBRARIES (GI_OGL
					   GI
					   OpenGL)
