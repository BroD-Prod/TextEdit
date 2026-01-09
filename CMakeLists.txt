cmake_minimum_required(VERSION 3.10)
project(TextEdit)

# 1. Look for FLTK on the system automatically
find_package(FLTK REQUIRED)


include_directories(${FLTK_INCLUDE_DIR})

# 2. Define the executable
add_executable(TextEdit main.cpp)

# 3. Link the FLTK libraries
target_link_libraries(TextEdit ${FLTK_LIBRARIES})

# 4. Force the output to be directly in the build folder
set_target_properties(TextEdit PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)