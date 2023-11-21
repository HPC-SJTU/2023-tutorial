cmake_minimum_required(VERSION 3.10)

project(TestCMake)

#set relative paths.
set(LIB ${CMAKE_SOURCE_DIR}/lib)
set(INC ${CMAKE_SOURCE_DIR}/inc)
set(SRC a.cc ${CMAKE_SOURCE_DIR}/src/b.cc)
set(LIBRARY_OUTPUT_DIRECTORY $(LIB))

add_executable(a ${SRC})
target_include_directories(a PUBLIC ${INC})

add_library(test STATIC ${CMAKE_SOURCE_DIR}/src/c.cc)
target_include_directories(test PUBLIC ${INC})
target_link_libraries(a PUBLIC test)

