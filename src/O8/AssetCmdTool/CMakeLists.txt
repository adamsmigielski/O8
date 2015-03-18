PROJECT(AssetCmdTool)

ADD_EXECUTABLE(AssetCmdTool
			   main.cpp
			   PCH.cpp
			   PCH.hpp)

TARGET_LINK_LIBRARIES(AssetCmdTool
					  Asset_Loader
					  Asset_Import_Manager
					  Utility)