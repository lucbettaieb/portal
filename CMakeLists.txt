cmake_minimum_required(VERSION 2.8.3)
project(portal)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sound_play
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(sounds src/sounds.cpp)

target_link_libraries(sounds
  ${catkin_LIBRARIES}
)