cmake_minimum_required(VERSION 3.20)
project(Atelier-tests-unitaires)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        NommageTests
        NommageTests/Calculateur.h
        NommageTests/Calculateur.cpp
        NommageTests/CalculateurTest.cpp
)

add_executable(
        3A
        3A/ManipulateurDeChaines.h
        3A/ManipulateurDeChaines.cpp
        3A/ManipulateurDeChainesTest.cpp
        3A/ChaineVideException.h
)

add_executable(
        FIRST
        FIRST/PanierAchat.h
        FIRST/PanierAchat.cpp
        FIRST/PanierAchatTest.cpp
        FIRST/LecteurDeConfigurations.cpp
)

target_link_libraries(
        NommageTests
        GTest::gtest_main
)

target_link_libraries(
        3A
        GTest::gtest_main
)

target_link_libraries(
        FIRST
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(NommageTests)
gtest_discover_tests(3A)
gtest_discover_tests(FIRST)