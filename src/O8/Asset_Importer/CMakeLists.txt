PROJECT(Asset_Importer)

ADD_LIBRARY(Asset_Importer STATIC
			Asset_importer.cpp
			Asset_importer.hpp
			PCH.cpp
			PCH.hpp)

ADD_LIBRARY(Asset_Import_Manager STATIC
			Asset_import_manager.cpp
			Asset_import_manager.hpp
			PCH.cpp
			PCH.hpp)

TARGET_LINK_LIBRARIES(Asset_Importer
				      ${DL_IMPL})

TARGET_LINK_LIBRARIES(Asset_Import_Manager
				      ${DL_IMPL})

