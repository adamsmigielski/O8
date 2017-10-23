IF(BUILD_OPENGL)
	ADD_SUBDIRECTORY(OGL)
	ADD_SUBDIRECTORY(${GI_GL_IMPL_DIR})
ENDIF(BUILD_OPENGL)

IF(BUILD_VULKAN)
	ADD_SUBDIRECTORY(Vulkan)
ENDIF(BUILD_VULKAN)



PROJECT ( GI )


# Files
SET (GI_FILES
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

SET (GI_LOADER_FILES
	 Loader.cpp
	 Loader.hpp
	 PCH.cpp
	 PCH.hpp)

# Binaries
ADD_LIBRARY (GI STATIC ${GI_FILES})

ADD_LIBRARY (GI_Loader STATIC ${GI_LOADER_FILES})

# Setup GI
ADD_DEPENDENCIES(GI
				 basic
				 containers
				 helpers
				 memory
				 task)

# Setup GI_Loader
TARGET_LINK_LIBRARIES (GI_Loader
					   ${DL_IMPL})

# Test
IF (BUILD_TESTS)

# Binaries
    ADD_LIBRARY (GI_UT STATIC ${GI_FILES})

	ADD_EXECUTABLE (GI_Test
					Loader.hpp
					${CMAKE_SOURCE_DIR}/src/Unit_Tests/main.cpp
					PCH.cpp
					PCH.hpp
					test.cpp)

# Setup GI_UT
	TARGET_COMPILE_DEFINITIONS (GI_UT PUBLIC UNIT_TESTS_ENABLE)

# Setup GI_Test
	TARGET_COMPILE_DEFINITIONS (GI_Test PUBLIC UNIT_TESTS_ENABLE)

	TARGET_LINK_LIBRARIES(GI_Test
						  Unit_Tests
						  Thread_Loader
						  WS
						  ${WS_IMPL}
						  GI_UT
						  GI_Loader)

	IF (BUILD_OPENGL)
		ADD_DEPENDENCIES(GI_Test
						${GI_GL_IMPL})
	ENDIF (BUILD_OPENGL)
ENDIF (BUILD_TESTS)
