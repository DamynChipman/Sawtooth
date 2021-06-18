#include <gtest/gtest.h>
#include <HPS_Poisson.hpp>

TEST(Poisson, init) {
	
	double x_lower = -1;
	double x_upper = 1;
	double y_lower = 0;
	double y_upper = 1;
	int ID = HPS::POLY;
	HPS::PoissonProblem poisson(ID, x_lower, x_upper, y_lower, y_upper);
	ASSERT_EQ(ID, poisson.ID);

}