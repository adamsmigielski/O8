PROJECT(AssetCmdTool)

ADD_EXECUTABLE(AssetCmdTool
			   main.cpp
			   PCH.cpp
			   PCH.hpp)

TARGET_LINK_LIBRARIES(AssetCmdTool
					  Asset_Import_Manager
					  Asset_Importer
					  Asset_Archiver
					  Asset_Archive
					  Asset
					  basic
					  containers
					  helpers
					  memory
					  ${DL_IMPL}
					  DL)

IF(BUILD_ASSET_IMPORTER_ASSIMP)
	ADD_DEPENDENCIES(AssetCmdTool
					 Asset_Importer_ASSIMP)
ENDIF(BUILD_ASSET_IMPORTER_ASSIMP)

IF(BUILD_ASSET_IMPORTER_FREETYPE)
	ADD_DEPENDENCIES(AssetCmdTool
					 Asset_Importer_FreeType)
ENDIF(BUILD_ASSET_IMPORTER_FREETYPE)