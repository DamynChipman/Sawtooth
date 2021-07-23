#include "gtest/gtest.h"
#include <HPS_P4est.hpp>
#include <HPS_Poisson.hpp>
#include <mpi.h>

TEST(P4est, create_p4est_init) {

	double x_lower = -1;
	double y_lower = 0;
	double x_upper = 1;
	double y_upper = 1;
	int x_npts = 4;
	int y_npts = 2;
	double refine_value = 2.0;

	HPS::CellGrid grid(MPI_COMM_WORLD, x_lower, y_lower, x_upper, y_upper, x_npts, y_npts);
	HPS::PoissonConstant poisson(x_lower, x_upper, y_lower, y_upper);
	p4est_t* p4est = HPS::HPS_CreateP4est(&poisson, 0, 2, refine_value);

}