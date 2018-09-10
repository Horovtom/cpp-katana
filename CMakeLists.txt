cmake_minimum_required(VERSION 3.9)
project(katana)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeFinds")
find_package(SDL2 COMPONENTS main gfx image mixer net ttf REQUIRED)
#find_package(SDL2 REQUIRED)
#find_package(SDL2_image REQUIRED)
#find_package(SDL2_ttf REQUIRED)
#find_package(SDL2_gfx REQUIRED)

#include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIR})

#string(STRIP ${SDL2_INCLUDE_DIRS} SDL2_INCLUDE_DIRS)
#string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)


add_executable(UnitTest main.cpp Grid.cpp Grid.h Legend.cpp Legend.h ObjectManager.cpp ObjectManager.h
        LogicManager.cpp LogicManager.h CluesGraphicsObject.cpp CluesGraphicsObject.h UIGraphicsObject.cpp
        UIGraphicsObject.h GridGraphicsObject.cpp GridGraphicsObject.h LTexture.cpp LTexture.h Coordinate.cpp
        Coordinate.h statics.h)
# target_link_libraries(UnitTest ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})
target_link_libraries(UnitTest ${SDL2_LIBRARIES})
add_executable(Katana main.cpp Grid.cpp Grid.h Legend.cpp Legend.h ObjectManager.cpp ObjectManager.h
        LogicManager.cpp LogicManager.h CluesGraphicsObject.cpp CluesGraphicsObject.h UIGraphicsObject.cpp
        UIGraphicsObject.h GridGraphicsObject.cpp GridGraphicsObject.h LTexture.cpp LTexture.h Coordinate.cpp
        Coordinate.h NumbersTextures.cpp NumbersTextures.h Timer.cpp Timer.h statics.h Vector2.cpp Vector2.h)
#target_link_libraries(Katana ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})
target_link_libraries(Katana ${SDL2_LIBRARIES})