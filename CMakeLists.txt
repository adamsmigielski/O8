CMAKE_MINIMUM_REQUIRED (VERSION 3.1)
PROJECT(O8)

#Disable exceptions
ADD_DEFINITIONS(-D_HAS_EXCEPTIONS=0)

# Build shared libraries
SET(BUILD_SHARED_LIBS ON)

#Configuration
SET(PROJECT_CONFIGURATION "Project_configuration")
INCLUDE(${PROJECT_CONFIGURATION}/configuration.cmake)


# Include source and external libraries
INCLUDE_DIRECTORIES (src)


# Add source directory
ADD_SUBDIRECTORY(src)
