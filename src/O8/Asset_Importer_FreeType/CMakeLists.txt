PROJECT(Asset_Importer_FreeType)

ADD_LIBRARY(Asset_Importer_FreeType SHARED
			Asset_importer_FreeType.cpp
			Asset_importer_FreeType.hpp
			PCH.cpp
			PCH.hpp)

ADD_LIBRARY(freetype UNKNOWN IMPORTED)
SET_TARGET_PROPERTIES(freetype PROPERTIES IMPORTED_LOCATION ${FREE_TYPE_LIB_DIR}/freetype.lib)


INCLUDE_DIRECTORIES(${FREE_TYPE_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(Asset_Importer_FreeType
					  Asset_Importer
					  freetype
					  memory
					  text)

