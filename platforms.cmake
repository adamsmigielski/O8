# Select target platform
IF(WIN32)
    SET(PLATFORM "win_32_64")
ENDIF(WIN32)
    

# Include target-specific definitions
INCLUDE_DIRECTORIES(src/Utilities/platforms/${PLATFORM})
ADD_SUBDIRECTORY(src/Utilities/platforms/${PLATFORM})