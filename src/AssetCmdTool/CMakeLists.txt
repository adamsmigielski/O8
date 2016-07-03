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
