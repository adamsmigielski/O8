PROJECT ( GI )

ADD_LIBRARY (GI STATIC
			 Adapter.cpp
			 Adapter.hpp
			 Buffer.cpp
			 Buffer.hpp
			 GI.cpp
			 GI.hpp
			 Mode.cpp
			 Mode.hpp
			 Output.cpp
			 Output.hpp
			 PCH.cpp
			 PCH.hpp
			 Presentation.cpp
			 Presentation.hpp
			 RI.cpp
			 RI.hpp
			 Texture.cpp
			 Texture.hpp)

ADD_DEPENDENCIES(GI
				 Common
				 containers
				 helpers
				 memory
				 task)

ADD_LIBRARY (GI_Loader STATIC
			 Loader.cpp
			 Loader.hpp
			 PCH.cpp
			 PCH.hpp)

TARGET_LINK_LIBRARIES (GI_Loader
					   ${DL_IMPL})

IF (BUILD_TESTS)
	ADD_EXECUTABLE (GI_Test
					Loader.hpp
					main.cpp
					PCH.cpp
					PCH.hpp)

	TARGET_LINK_LIBRARIES(GI_Test
						  Test
						  Thread_Loader
						  WS
						  WS_Loader
						  GI
						  GI_Loader)

	ADD_DEPENDENCIES(GI_Test
					 GI_Windows_OGL
					 WS_Windows)
ENDIF (BUILD_TESTS)
