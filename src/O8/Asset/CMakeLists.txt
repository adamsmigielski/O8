PROJECT(Asset)

ADD_LIBRARY(Asset SHARED
			Asset.cpp
			Asset.hpp
			Descriptor.cpp
			Descriptor.hpp
			File.cpp
			File.hpp
			Library.cpp
			Library.hpp
			PCH.cpp
			PCH.hpp
			Registry.cpp
			Registry.hpp
			Type.cpp
			Type.hpp)

TARGET_LINK_LIBRARIES(Asset
					  Utility)

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

