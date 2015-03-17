PROJECT ( GI_Windows_OGL )

ADD_LIBRARY (GI_Windows_OGL SHARED
			 Adapter_win_ogl.cpp
			 Adapter_win_ogl.hpp
			 Context_win_ogl.cpp
			 Context_win_ogl.hpp
			 GI_win_ogl.cpp
			 GI_win_ogl.hpp
			 Mode_win_ogl.cpp
			 Mode_win_ogl.hpp
			 Output_win_ogl.cpp
			 Output_win_ogl.hpp
			 PCH.cpp
			 PCH.hpp
			 Presentation_win_ogl.cpp
			 Presentation_win_ogl.hpp
			 RI_win_ogl.cpp
			 RI_win_ogl.hpp)

TARGET_LINK_LIBRARIES (GI_Windows_OGL
					   DL
					   ${DL_IMPL}
					   GI
					   GI_OGL
					   OpenGL
					   Templates)
