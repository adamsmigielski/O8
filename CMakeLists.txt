PROJECT(O8)
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# Build type
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Debug CACHE STRING
      "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
      FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

# Build tests
SET( BUILD_TESTS ON CACHE BOOL "Build test executables")
SET( BUILD_OPENGL ON CACHE BOOL "Build OpenGL libraries")
SET( BUILD_ASSET_IMPORTER_ASSIMP ON CACHE BOOL "Build asset importer based on ASSIMP")

# Paths
set(GLM_INCLUDE_DIR "../Dependencies/glm" CACHE STRING "Path to GLM include directory")

IF(BUILD_ASSET_IMPORTER_ASSIMP)
	SET(ASSIMP_INCLUDE_DIR "../Dependencies/assimp/include" CACHE STRING "Path to ASSIMP include directory")
	SET(ASSIMP_LIB_DIR "../Dependencies/assimp/code/Release" CACHE STRING "Path to ASSIMP lib directory")
ENDIF(BUILD_ASSET_IMPORTER_ASSIMP)


# Build shared libraries
SET(BUILD_SHARED_LIBS ON)


# Include target specific stuff
INCLUDE(targets/targets.cmake)
INCLUDE(platforms/platforms.cmake)


#Disable exceptions
ADD_DEFINITIONS(-D_HAS_EXCEPTIONS=0)


# Include source and external libraries
INCLUDE_DIRECTORIES (include)
INCLUDE_DIRECTORIES (src)
INCLUDE_DIRECTORIES (${GLM_INCLUDE_DIR})


#Add source directory
ADD_SUBDIRECTORY(src)
