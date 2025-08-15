cmake_minimum_required(VERSION 3.16)
project(timber)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML package
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

# Check if SFML 2.5+ was successfully found by find_package()
# If not found, display error message with installation instructions
if(NOT SFML_FOUND)
    message(FATAL_ERROR
        "SFML 2.5 or higher not found!\n"
        "Please install SFML:\n"
        "  - Windows: Download from sfml-dev.org\n"
        "  - Linux: sudo apt install libsfml-dev\n"
        "Alternatively, set SFML_DIR to SFML's cmake path."
    )
endif()

# Add the "include" directory to the compiler's header search path
include_directories(include)

# Collect all .cpp files from the "src" directory
file(GLOB SOURCES "src/*.cpp")

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link SFML libraries to the executable
target_link_libraries(${PROJECT_NAME}
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)

# Copy the "assets" folder to the build directory
file(COPY assets/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets)
