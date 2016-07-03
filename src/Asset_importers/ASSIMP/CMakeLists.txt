PROJECT(Asset_Importer_ASSIMP)

# Set paths
SET(ASSIMP_INCLUDE_DIR "${CMAKE_BINARY_DIR}/../Dependencies/assimp/include" CACHE STRING "Path to ASSIMP include directory")
SET(ASSIMP_LIB_PATH "${CMAKE_BINARY_DIR}/../Dependencies/assimp/code/Release" CACHE STRING "Path to ASSIMP library")

# Add library
ADD_LIBRARY(Asset_Importer_ASSIMP SHARED
			Asset_importer_ASSIMP.cpp
			Asset_importer_ASSIMP.hpp
			PCH.cpp
			PCH.hpp)

# Add assimp
ADD_LIBRARY(assimp UNKNOWN IMPORTED)
SET_TARGET_PROPERTIES(assimp PROPERTIES IMPORTED_LOCATION ${ASSIMP_LIB_PATH})
INCLUDE_DIRECTORIES(${ASSIMP_INCLUDE_DIR})

# Link
TARGET_LINK_LIBRARIES(Asset_Importer_ASSIMP
                      Asset
					  Asset_Importer
					  helpers
					  memory
					  assimp)

