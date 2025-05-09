cmake_minimum_required(VERSION 3.12)
project(NovaSquadron)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


#SDL2 library
find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)
if(NOT SDL2_FOUND OR NOT SDL2_IMAGE_FOUND)
    message(SEND_ERROR "Please install SDL2 and SDL2_image development packages.")
    return()
endif()
message(STATUS "SDL2 version: ${SDL2_VERSION}")
message(STATUS "SDL2_image version: ${SDL2_IMAGE_VERSION}")

# SPDLOG library
find_package(spdlog REQUIRED)
if(NOT spdlog_FOUND)
    message(SEND_ERROR "Please install spdlog development package.")
    return()
endif()
message(STATUS "spdlog version: ${spdlog_VERSION}")


link_directories()



# Include directories for headers
include_directories(${SDL2_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/src/core ${CMAKE_SOURCE_DIR}/src/utils ${CMAKE_SOURCE_DIR}/src/world)


file(GLOB CPP_SOURCES "src/*.cpp" "src/core/*.cpp" "src/world/*.cpp" "src/utils/*.cpp")


# Create the executable
add_executable(novaSquadron ${CPP_SOURCES})
target_link_libraries(novaSquadron SDL2::SDL2 SDL2_image::SDL2_image spdlog::spdlog)

add_custom_command(
    TARGET novaSquadron POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/src/assets
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets
)