include_directories(${PROJECT_SOURCE_DIR}/Include)
add_library(sawtooth STATIC HPS_CellGrid.cpp HPS_Patch.cpp HPS_Poisson.cpp HPS.cpp HPS_P4est.cpp)
target_link_libraries(sawtooth petsc p4est)