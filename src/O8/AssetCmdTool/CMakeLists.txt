PROJECT(AssetCmdTool)

ADD_EXECUTABLE(AssetCmdTool
			   main.cpp
			   PCH.cpp
			   PCH.hpp)

TARGET_LINK_LIBRARIES(AssetCmdTool
					  basic
					  containers
					  helpers
					  memory
					  ${DL_IMPL}
					  Asset
					  Asset_Archive
					  Asset_Archiver
					  Asset_Importer
					  Asset_Import_Manager)

IF(BUILD_ASSET_IMPORTER_ASSIMP)
	ADD_DEPENDENCIES(AssetCmdTool
					 Asset_Importer_ASSIMP)
ENDIF(BUILD_ASSET_IMPORTER_ASSIMP)

IF(BUILD_ASSET_IMPORTER_FREETYPE)
	ADD_DEPENDENCIES(AssetCmdTool
					 Asset_Importer_FreeType)
ENDIF(BUILD_ASSET_IMPORTER_FREETYPE)