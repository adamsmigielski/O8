# General executables to build
SET( BUILD_TESTS ON CACHE BOOL "Build test executables")
SET( BUILD_TOOLS ON CACHE BOOL "Build tools executables")
SET( BUILD_DEMO ON CACHE BOOL "Build demo executables")

# Modules to build
SET( BUILD_ASSET ON CACHE BOOL "Build asset libraries")
SET( BUILD_ASSET_ARCHIVE ON CACHE BOOL "Build asset archive libraries")
SET( BUILD_ASSET_IMPORT ON CACHE BOOL "Build asset import libraries")
SET( BUILD_ASSET_REGISTRY ON CACHE BOOL "Build asset registry libraries")
SET( BUILD_GI ON CACHE BOOL "Build graphics interface libraries")
SET( BUILD_RS ON CACHE BOOL "Build rendering system libraries")
SET( BUILD_WS ON CACHE BOOL "Build window management libraries")

# Dependant modules to build
SET( BUILD_ASSET_IMPORTER_ASSIMP ON CACHE BOOL "Build asset importer based on ASSIMP")
SET( BUILD_ASSET_IMPORTER_FREETYPE ON CACHE BOOL "Build asset importer based on FreeType 2")
SET( BUILD_OPENGL ON CACHE BOOL "Build OpenGL libraries")
SET( BUILD_VULKAN ON CACHE BOOL "Build Vulkan libraries")
SET( BUILD_ENGINE ON CACHE BOOL "Build engine")

# Configuration
IF(WIN32)
	# Lib names
	SET(GI_GL_IMPL "GI_Windows_OGL")

	# Impl directories
	SET(GI_GL_IMPL_DIR "GI_Windows_OGL")

	# DLL paths
	SET(GI_GL_IMPL_PATH "GI_Windows_OGL.dll")
ENDIF(WIN32)

IF    (BUILD_GI)
	IF    (BUILD_OPENGL)
		ADD_DEFINITIONS(-DGI_IMPL="${GI_GL_IMPL_PATH}")
	ENDIF (BUILD_OPENGL)
ENDIF (BUILD_GI)


#Add subdirectories

#Basic
ADD_SUBDIRECTORY(Image)

# DLL
ADD_SUBDIRECTORY(DL)

# Threads
ADD_SUBDIRECTORY(Thread)


# Modules
#Asset
IF (BUILD_ASSET)
	ADD_SUBDIRECTORY(Asset)
ENDIF (BUILD_ASSET)

#GI
IF (BUILD_GI)
	ADD_SUBDIRECTORY(GI)

	IF (BUILD_RS)
		ADD_SUBDIRECTORY(RS)
	ENDIF (BUILD_RS)
ENDIF (BUILD_GI)


#Engine
IF (BUILD_GI AND BUILD_RS AND BUILD_ASSET AND BUILD_ENGINE)
	ADD_SUBDIRECTORY(Engine)
ENDIF (BUILD_GI AND BUILD_RS AND BUILD_ASSET AND BUILD_ENGINE)

#WS
IF (BUILD_WS)
	ADD_SUBDIRECTORY(WS)
ENDIF (BUILD_WS)


# Demo application
IF (BUILD_DEMO)
	IF (BUILD_GI AND BUILD_ASSET AND BUILD_ENGINE AND BUILD_WS)
		ADD_SUBDIRECTORY(Demo_basics)
		ADD_SUBDIRECTORY(Demo_vulkan)
	ENDIF (BUILD_GI AND BUILD_ASSET AND BUILD_ENGINE AND BUILD_WS)
ENDIF (BUILD_DEMO)

