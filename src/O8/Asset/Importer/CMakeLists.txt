PROJECT(Asset_Importer)

ADD_LIBRARY(Asset_Importer STATIC
            importer.cpp
            importer.hpp
            PCH.cpp
            PCH.hpp)

ADD_DEPENDENCIES(Asset_Importer
                 Asset
                 DL)
