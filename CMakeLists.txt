cmake_minimum_required(VERSION 3.17)
project(Sawtooth VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" . WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build . WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src ${CMAKE_BINARY_DIR}/googletest-build)
enable_testing()

find_package(MPI)

include_directories("/bsuhome/dchipman/packages/spack/opt/spack/linux-centos7-skylake/gcc-8.2.0/p4est-2.2-tdilk4u45mkq6eplnrmxgzuatgi5oqkk/include")
include_directories("/bsuhome/dchipman/packages/spack/opt/spack/linux-centos7-skylake/gcc-8.2.0/petsc-3.13.1-v2btfokpcar67y4svvsa4cjht7ohpug7/include")

add_subdirectory(Src)
add_subdirectory(Apps)
add_subdirectory(Test)