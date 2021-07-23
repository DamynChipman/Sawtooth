#ifndef HPS_P4EST_HPP_
#define HPS_P4EST_HPP_

#include <HPS_Poisson.hpp>
#include <HPS_Patch.hpp>
#include <p4est.h>

namespace HPS {

p4est_t* HPS_CreateP4est(Poisson2D* poisson, int min_level, int max_level, double refine_value);

} // END OF NAMESPACE : HPS

#endif // HPS_P4EST_HPP_