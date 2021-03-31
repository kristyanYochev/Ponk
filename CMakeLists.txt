cmake_minimum_required(VERSION 3.17)
project(Ponk)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML COMPONENTS system window graphics audio)

add_executable(${PROJECT_NAME} main.cpp Paddle.cpp Paddle.h Common.h Ball.cpp Ball.h Math.cpp Math.h ScoreCounter.cpp ScoreCounter.h Game.cpp Game.h)
target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics sfml-audio)
