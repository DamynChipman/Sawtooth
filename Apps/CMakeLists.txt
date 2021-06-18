include_directories("${PROJECT_SOURCE_DIR}/Include")
add_executable(helloSawtooth helloSawtooth.cpp)
target_link_libraries(helloSawtooth LINK_PUBLIC sawtooth)