PROJECT(Asset_Importer_ASSIMP)

ADD_LIBRARY(Asset_Importer_ASSIMP SHARED
			Asset_importer_ASSIMP.cpp
			Asset_importer_ASSIMP.hpp
			PCH.cpp
			PCH.hpp)

ADD_LIBRARY(assimp UNKNOWN IMPORTED)
SET_TARGET_PROPERTIES(assimp PROPERTIES IMPORTED_LOCATION ${ASSIMP_LIB_DIR}/assimp.lib)


INCLUDE_DIRECTORIES(${ASSIMP_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(Asset_Importer_ASSIMP
					  Asset_Importer
					  assimp)

