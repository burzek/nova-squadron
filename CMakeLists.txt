cmake_minimum_required(VERSION 3.12)
project(NovaSquadron)

# Set C++ standard to C++11 (or higher if needed)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


#SDL2 library
find_package(SDL2 REQUIRED)
if(NOT SDL2_FOUND)
    message(SEND_ERROR "Failed to find SDL2")
    return()
endif()

# SPDLOG library
find_package(spdlog REQUIRED)

# Include directories for headers
include_directories(${SDL2_INCLUDE_DIRS})



file(GLOB CPP_SOURCES "src/*.cpp" "src/core/*.cpp" "src/world/*.cpp" "src/utils/*.cpp")

# Create the executable
add_executable(novaSquadron ${CPP_SOURCES})
target_link_libraries(novaSquadron ${SDL2_LIBRARIES} spdlog::spdlog)
