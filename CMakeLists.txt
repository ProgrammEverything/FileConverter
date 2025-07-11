cmake_minimum_required(VERSION 3.16)
project(Platformer VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file (GLOB RESOURCE_SOURCE "src/*.cpp" "hdrs/*.h")
include_directories(hdrs icons)
add_executable(Platformer ${RESOURCE_SOURCE})
find_package(wxWidgets REQUIRED COMPONENTS net core base)
find_package(X11 REQUIRED)

if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

# target_compile_options(Platformer PRIVATE -fsanitize=address) # debug 

target_link_libraries(Platformer ${wxWidgets_LIBRARIES} ${X11_LIBRARIES})