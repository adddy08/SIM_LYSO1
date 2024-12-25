cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR)

project(Simulation)

find_package(Geant4 REQUIRED ui_all vis_all) #find Geant4 package

include(${Geant4_USE_FILE})   #include Geant4 setting
include_directories(${PROJECT_SOURCE_DIR}/include)  #add include directories


file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)  #define sources and headers
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)

add_executable(sim sim.cc ${sources} ${headers})     #add the executable
target_link_libraries(sim ${Geant4_LIBRARIES})

add_custom_target(Simulation DEPENDS sim)
