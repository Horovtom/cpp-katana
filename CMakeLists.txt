cmake_minimum_required(VERSION 3.9)
project(Katana)

set(CMAKE_CXX_STANDARD 17)


find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM gtkmm-3.0) # look into FindPkgConfig.cmake,
# it contains documentation
# Now the variables GTKMM_INCLUDE_DIRS, GTKMM_LIBRARY_DIRS and GTKMM_LIBRARIES
# contain what you expect

link_directories(
        ${GTKMM_LIBRARY_DIRS})

include_directories(
        ${GTKMM_INCLUDE_DIRS})

set(KATANA_SOURCES
        src/game/logic/Game.cpp
        src/game/logic/Clues.cpp
        src/game/logic/Grid.cpp
        )

set(GRAPHICS_SOURCES
        src/game/Controller.cpp
        src/graphics/GameWindow.cpp
        src/graphics/GameArea.cpp
        )

add_executable(Katana
        main.cpp
        ${KATANA_SOURCES}
        ${GRAPHICS_SOURCES}
        )

target_link_libraries(Katana
        ${GTKMM_LIBRARIES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path
target_include_directories(Katana
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )

# -------------- TESTS ------------------
set(TEST_SOURCES
        src/tests/Test.cpp
        )

add_executable(Test src/tests/runTests.cpp ${GAME_SOURCES} ${AI_SOURCES} ${TEST_SOURCES})
target_include_directories(Test
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include)
