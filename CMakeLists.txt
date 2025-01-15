cmake_minimum_required (VERSION 3.31.3)

project(ConnectFour)

set (HEADERS
  headers/connect-four-game.h
  headers/player.h
  headers/player-controller.h
  headers/input.h
)

set (SOURCES
  src/connect-four-game.cpp
  src/player.cpp
  src/player-controller.cpp
  src/main.cpp
)

set (CMAKE_CXX_STANDARD 17)

add_executable (ConnectFour ${SOURCES} ${HEADERS})