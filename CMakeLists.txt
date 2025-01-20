cmake_minimum_required (VERSION 3.31.3)

project(ConnectFour)

set(HeadersDir headers)

set (Headers
${HeadersDir}/connect-four-game.h
${HeadersDir}/player.h
${HeadersDir}/player-controller.h
${HeadersDir}/input.h
)

set (Sources
src/connect-four-game.cpp
src/player.cpp
src/player-controller.cpp
src/main.cpp
)

set (CMAKE_CXX_STANDARD 17)

add_executable (ConnectFour ${Sources} ${Headers})

target_include_directories(ConnectFour PRIVATE ${HeadersDir})