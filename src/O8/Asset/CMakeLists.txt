PROJECT(Asset)

ADD_LIBRARY(Asset STATIC
			Asset_descriptor.cpp
			Asset_descriptor.hpp
			PCH.cpp
			PCH.hpp
			Type.cpp
			Type.hpp)

IF (BUILD_ASSET_ARCHIVE)
	ADD_LIBRARY(Asset_Archive SHARED
				File.cpp
				File.hpp
				PCH.cpp
				PCH.hpp)

	TARGET_LINK_LIBRARIES(Asset_Archive
						  Asset
						  Common
						  Templates
						  Utility)
ENDIF (BUILD_ASSET_ARCHIVE)

IF (BUILD_ASSET_REGISTRY)
	ADD_LIBRARY(Asset_Registry SHARED
				PCH.cpp
				PCH.hpp
				Registry.cpp
				Registry.hpp)

	TARGET_LINK_LIBRARIES(Asset_Registry
						  Asset
						  Common
						  Templates
						  Utility)
ENDIF (BUILD_ASSET_REGISTRY)

ADD_LIBRARY(Asset_Loader STATIC
			Loader.cpp
			Loader.hpp
			PCH.cpp
			PCH.hpp)

TARGET_LINK_LIBRARIES(Asset_Loader
					  ${DL_IMPL})


IF (BUILD_TESTS)
	ADD_EXECUTABLE(Asset_Test
				   main.cpp
				   PCH.cpp
				   PCH.hpp)

	TARGET_LINK_LIBRARIES(Asset_Test
						  DL
						  Asset_Loader)

	ADD_DEPENDENCIES(Asset_Test
					 Asset)
ENDIF (BUILD_TESTS)

