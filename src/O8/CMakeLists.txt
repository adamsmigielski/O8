ADD_SUBDIRECTORY(Common)
ADD_SUBDIRECTORY(Templates)
ADD_SUBDIRECTORY(Test)
ADD_SUBDIRECTORY(Utility)

#DL
ADD_SUBDIRECTORY(DL)
IF(WIN32)
	ADD_SUBDIRECTORY(DL_Windows)
ENDIF(WIN32)

#Asset
ADD_SUBDIRECTORY(Asset)
ADD_SUBDIRECTORY(Asset_Importer)
IF (BUILD_ASSET_IMPORTER_ASSIMP)
	ADD_SUBDIRECTORY(Asset_Importer_ASSIMP)
ENDIF (BUILD_ASSET_IMPORTER_ASSIMP)

#Thread
ADD_SUBDIRECTORY(Thread)
IF(WIN32)
	ADD_SUBDIRECTORY(Thread_Windows)
ENDIF(WIN32)


#WS
ADD_SUBDIRECTORY(WS)
IF(WIN32)
	ADD_SUBDIRECTORY(WS_Windows)
ENDIF(WIN32)

#GI
ADD_SUBDIRECTORY(GI)
IF(BUILD_OPENGL)
	ADD_SUBDIRECTORY(GI_OGL)
	IF(WIN32)
		ADD_SUBDIRECTORY(GI_Windows_OGL)
	ENDIF(WIN32)
ENDIF(BUILD_OPENGL)

#RS
ADD_SUBDIRECTORY(RS)

#OpenGL
ADD_SUBDIRECTORY(OpenGL)