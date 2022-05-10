cmake_minimum_required(VERSION 3.21)
project(ArtistsLibrary)

set(CMAKE_CXX_STANDARD 14)

include_directories(ArtistsLibrary)
include_directories(ArtistsLibraryTest)

add_executable(ArtistsLibrary
        ArtistsLibrary/Artist.cpp
        ArtistsLibrary/Artist.h
        ArtistsLibrary/ArtistController.cpp
        ArtistsLibrary/ArtistController.h
        ArtistsLibrary/ArtistRepository.cpp
        ArtistsLibrary/ArtistRepository.h
        ArtistsLibrary/KHH.cpp
        ArtistsLibrary/KHH.h
        ArtistsLibrary/KRnB.cpp
        ArtistsLibrary/KRnB.h
        ArtistsLibrary/main.cpp
        ArtistsLibrary/UserInterface.cpp
        ArtistsLibrary/UserInterface.h
        ArtistsLibraryTest/ArtistLibraryTest.cpp
        ArtistsLibraryTest/pch.cpp
        ArtistsLibraryTest/pch.h
        ArtistsLibraryTest/resource.h)
