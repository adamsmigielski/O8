PROJECT(O8)
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# General executables to build
SET( BUILD_TESTS ON CACHE BOOL "Build test executables")
SET( BUILD_DEMO ON CACHE BOOL "Build demo executables")

# Modules to build
SET( BUILD_ASSET ON CACHE BOOL "Build asset libraries")
SET( BUILD_ASSET_ARCHIVE ON CACHE BOOL "Build asset archive libraries")
SET( BUILD_ASSET_IMPORT ON CACHE BOOL "Build asset import libraries")
SET( BUILD_ASSET_REGISTRY ON CACHE BOOL "Build asset registry libraries")
SET( BUILD_GI ON CACHE BOOL "Build graphics interface libraries")
SET( BUILD_RS ON CACHE BOOL "Build rendering system libraries")
SET( BUILD_WS ON CACHE BOOL "Build window management libraries")

# Dependant modules to build
SET( BUILD_ASSET_IMPORTER_ASSIMP ON CACHE BOOL "Build asset importer based on ASSIMP")
SET( BUILD_OPENGL ON CACHE BOOL "Build OpenGL libraries")
SET( BUILD_ENGINE ON CACHE BOOL "Build engine")


# Paths
set(GLM_INCLUDE_DIR "../Dependencies/glm" CACHE STRING "Path to GLM include directory")

IF(BUILD_ASSET_IMPORTER_ASSIMP)
	SET(ASSIMP_INCLUDE_DIR "${CMAKE_BINARY_DIR}/../Dependencies/assimp/include" CACHE STRING "Path to ASSIMP include directory")
	SET(ASSIMP_LIB_DIR "${CMAKE_BINARY_DIR}/../Dependencies/assimp/code/Release" CACHE STRING "Path to ASSIMP lib directory")
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


# Add source directory
ADD_SUBDIRECTORY(src)
