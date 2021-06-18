include_directories("${PROJECT_SOURCE_DIR}/Include")

file(GLOB sources "${PROJECT_SOURCE_DIR}/Src/*.cpp")

file(GLOB tests "${PROJECT_SOURCE_DIR}/Test/*.cpp")
list(REMOVE_ITEM tests "${PROJECT_SOURCE_DIR}/Test/main.cpp")

include(GoogleTest)

foreach(file ${tests})
  set(name)
  get_filename_component(name ${file} NAME_WE)
  add_executable("${name}_tests" ${file} "${PROJECT_SOURCE_DIR}/Test/main.cpp" ${sources})
  add_test(NAME ${name} COMMAND "${name}_tests")
  target_link_libraries("${name}_tests" PUBLIC gtest petsc p4est sawtooth)
endforeach()