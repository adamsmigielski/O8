PROJECT(Asset)

ADD_LIBRARY(Asset STATIC
			PCH.cpp
			PCH.hpp
			Type.cpp
			Type.hpp)

IF (BUILD_ASSET_ARCHIVE)
	ADD_LIBRARY(Asset_Archive STATIC
				File.cpp
				File.hpp
				Library.cpp
				Library.hpp
				PCH.cpp
				PCH.hpp)

	TARGET_LINK_LIBRARIES(Asset_Archive
						  Asset
						  Common
						  Templates
						  Utility)
ENDIF (BUILD_ASSET_ARCHIVE)

IF (BUILD_ASSET_REGISTRY)
	ADD_LIBRARY(Asset_Archiver STATIC
				PCH.cpp
				PCH.hpp
				Archiver.cpp
				Archiver.hpp)

	TARGET_LINK_LIBRARIES(Asset_Archiver
						  Asset
						  Common
						  Templates
						  Utility)
ENDIF (BUILD_ASSET_REGISTRY)

IF (BUILD_ASSET_IMPORT)
	ADD_LIBRARY(Asset_Importer STATIC
				importer.cpp
				importer.hpp
				PCH.cpp
				PCH.hpp)

	ADD_LIBRARY(Asset_Import_Manager STATIC
				import_manager.cpp
				import_manager.hpp
				PCH.cpp
				PCH.hpp)

	TARGET_LINK_LIBRARIES(Asset_Importer
						  ${DL_IMPL})

	TARGET_LINK_LIBRARIES(Asset_Import_Manager
						  ${DL_IMPL})
ENDIF (BUILD_ASSET_IMPORT)




IF (BUILD_TESTS)
	ADD_EXECUTABLE(Asset_Test
				   main.cpp
				   PCH.cpp
				   PCH.hpp)

	TARGET_LINK_LIBRARIES(Asset_Test
						  DL)

	ADD_DEPENDENCIES(Asset_Test
					 Asset)
ENDIF (BUILD_TESTS)

