cmake_minimum_required(VERSION 3.3)
project(Watch)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -D__NO_INLINE__")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

set(SOURCE_FILES main.cpp GameState.h Game.cpp Game.h GameStateStart.cpp GameStateStart.h GameStatePlay.cpp GameStatePlay.h TextureManager.cpp TextureManager.h Animation.h AnimationHandler.cpp AnimationHandler.h Player.cpp Player.h Map.cpp Map.h Tile.cpp Tile.h)
include_directories(fonts)
add_executable(Watch ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Watch ${SFML_LIBRARIES})
endif()