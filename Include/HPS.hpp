#ifndef HPS_HPP_
#define HPS_HPP_

#include <petsc.h>
#include <p4est.h>

#include <HPS_Poisson.hpp>
// #include <HPS_CellGrid.hpp>
// #include <HPS_Patch.hpp>

namespace HPS {

int HPS_Init(int* aargc, char*** aargv, char help[]);
int HPS_Finalize();

} // END OF NAMESPACE : HPS

#endif // HPS_HPP_