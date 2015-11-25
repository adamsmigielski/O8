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

	ADD_DEPENDENCIES(Asset_Archive
					 containers
				     helpers
					 memory
					 Asset)
ENDIF (BUILD_ASSET_ARCHIVE)

IF (BUILD_ASSET_REGISTRY)
	ADD_LIBRARY(Asset_Archiver STATIC
				PCH.cpp
				PCH.hpp
				Archiver.cpp
				Archiver.hpp)

	ADD_DEPENDENCIES(Asset_Archiver
					 Asset_Archive)
ENDIF (BUILD_ASSET_REGISTRY)

IF (BUILD_ASSET_IMPORT)
	ADD_LIBRARY(Asset_Importer STATIC
				importer.cpp
				importer.hpp
				PCH.cpp
				PCH.hpp)

	ADD_DEPENDENCIES(Asset_Importer
					 Asset
					 DL)

	ADD_LIBRARY(Asset_Import_Manager STATIC
				import_manager.cpp
				import_manager.hpp
				PCH.cpp
				PCH.hpp)

	ADD_DEPENDENCIES(Asset_Import_Manager
					 containers
				     helpers
					 Asset_Importer)
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

