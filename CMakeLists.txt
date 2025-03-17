cmake_minimum_required(VERSION 3.12)
project(NovaSquadron)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


#SDL2 library
find_package(SDL2 REQUIRED)
if(NOT SDL2_FOUND)
    message(SEND_ERROR "Failed to find SDL2")
    return()
endif()
link_directories()
# SPDLOG library
find_package(spdlog REQUIRED)

# Include directories for headers
include_directories(${SDL2_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/src/core ${CMAKE_SOURCE_DIR}/src/utils ${CMAKE_SOURCE_DIR}/src/world)


file(GLOB CPP_SOURCES "src/*.cpp" "src/core/*.cpp" "src/world/*.cpp" "src/utils/*.cpp")


# Create the executable
add_executable(novaSquadron ${CPP_SOURCES})
target_link_libraries(novaSquadron ${SDL2_LIBRARIES} spdlog::spdlog)
