PROJECT(O8)

#Disable exceptions
ADD_DEFINITIONS(-D_HAS_EXCEPTIONS=0)


# Include source and external libraries
INCLUDE_DIRECTORIES (include)
INCLUDE_DIRECTORIES (src)
INCLUDE_DIRECTORIES (${GLM_INCLUDE_DIR})


# Add source directory
ADD_SUBDIRECTORY(src)
