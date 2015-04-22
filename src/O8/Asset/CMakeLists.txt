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

