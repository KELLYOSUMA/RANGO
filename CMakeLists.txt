cmake_minimum_required(VERSION 3.10)

project(RANGO LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)
add_executable(RANGO scr/GAME/main.cpp 

                      #engine source files 
                      scr/ENGINE/Source/RANGO/Core/Base.cpp
                      scr/ENGINE/Source/RANGO/Window/Window.cpp
                      scr/ENGINE/Include/RANGO/Events/Events.hpp
                      scr/ENGINE/Include/RANGO/Events/KeyEvents.hpp
                      scr/ENGINE/Include/RANGO/Events/MouseEvents.hpp
                      scr/ENGINE/Include/RANGO/Events/ApplicationEvents.hpp
)
#include directories for all the include files in the project 

target_include_directories(RANGO PRIVATE ${CMAKE_SOURCE_DIR}/scr/ENGINE/Include/RANGO/Core/
                                         ${CMAKE_SOURCE_DIR}/scr/ENGINE/Include/RANGO/Core/Macros/
                                         ${CMAKE_SOURCE_DIR}/scr/ENGINE/Include/RANGO/Core/Headers/
                                         ${CMAKE_SOURCE_DIR}/scr/ENGINE/Include/RANGO/Window/
                                         ${CMAKE_SOURCE_DIR}/scr/ENGINE/Include/RANGO/Events/Codes/
                                         ${CMAKE_SOURCE_DIR}/scr/ENGINE/Include/RANGO/Events/)
#all the libraries i am going to use in this project are here 


add_subdirectory(Vendor/glfw)
target_link_libraries(RANGO PRIVATE glfw)