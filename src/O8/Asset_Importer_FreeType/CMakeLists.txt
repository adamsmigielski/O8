PROJECT(Asset_Importer_FreeType)

# Set paths
SET(FREE_TYPE_INCLUDE_DIR "${CMAKE_BINARY_DIR}/../Dependencies/freetype2/include" CACHE STRING "Path to FreeType 2 include directory")
SET(FREE_TYPE_LIB_PATH "${CMAKE_BINARY_DIR}/../Dependencies/freetype2/Release" CACHE STRING "Path to FreeType 2 lib directory")

# Add library
ADD_LIBRARY(Asset_Importer_FreeType SHARED
			Asset_importer_FreeType.cpp
			Asset_importer_FreeType.hpp
			PCH.cpp
			PCH.hpp)

# Add freetype
ADD_LIBRARY(freetype UNKNOWN IMPORTED)
SET_TARGET_PROPERTIES(freetype PROPERTIES IMPORTED_LOCATION ${FREE_TYPE_LIB_PATH})
INCLUDE_DIRECTORIES(${FREE_TYPE_INCLUDE_DIR})

# Link
TARGET_LINK_LIBRARIES(Asset_Importer_FreeType
					  Asset_Importer
					  freetype
					  memory
					  text)

