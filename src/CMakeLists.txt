cmake_minimum_required(VERSION 3.15...3.23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O")

add_executable(myproject1
        main.cpp
        entity.cpp
        sparse_array.hpp
        )

target_link_libraries(myproject1
        PRIVATE myproject::myproject_options
            myproject::myproject_warnings
        )

set_target_properties(myproject1
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "../"
)

include_directories(myproject1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
