PROJECT(Asset_Archiver)

ADD_LIBRARY(Asset_Archiver STATIC
            PCH.cpp
            PCH.hpp
            Archiver.cpp
            Archiver.hpp)

ADD_DEPENDENCIES(Asset_Archiver
                 Asset_Archive)
