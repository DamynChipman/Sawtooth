#include <gtest/gtest.h>
#include <HPS_Poisson.hpp>

// TEST(Poisson, init) {
	
// 	double x_lower = -1;
// 	double x_upper = 1;
// 	double y_lower = 0;
// 	double y_upper = 1;
// 	int ID = HPS::POLY;
// 	HPS::PoissonProblem poisson(ID, x_lower, x_upper, y_lower, y_upper);
// 	ASSERT_EQ(ID, poisson.ID);

// }

TEST(PoissonConstant, init) {

	double xLower = -1;
	double xUpper = 1;
	double yLower = 0;
	double yUpper = 2;
	HPS::PoissonConstant poisson(xLower, xUpper, yLower, yUpper);

	ASSERT_EQ(xLower, poisson.getXLower());
	ASSERT_EQ(xUpper, poisson.getXUpper());
	ASSERT_EQ(yLower, poisson.getYLower());
	ASSERT_EQ(yUpper, poisson.getYUpper());

}

TEST(PoissonConstant, functions) {

	double xLower = -1;
	double xUpper = 1;
	double yLower = 0;
	double yUpper = 2;
	HPS::PoissonConstant poisson(xLower, xUpper, yLower, yUpper);

	ASSERT_FLOAT_EQ(poisson.uFunction(0, 0), 1.0);
	ASSERT_FLOAT_EQ(poisson.fFunction(0, 0), 0.0);
	ASSERT_FLOAT_EQ(poisson.dudxFunction(0, 0), 0.0);
	ASSERT_FLOAT_EQ(poisson.dudyFunction(0, 0), 0.0);

}

TEST(PoissonLinear, init) {

	double xLower = -1;
	double xUpper = 1;
	double yLower = 0;
	double yUpper = 2;
	HPS::PoissonLinear poisson(xLower, xUpper, yLower, yUpper);

	ASSERT_EQ(xLower, poisson.getXLower());
	ASSERT_EQ(xUpper, poisson.getXUpper());
	ASSERT_EQ(yLower, poisson.getYLower());
	ASSERT_EQ(yUpper, poisson.getYUpper());

}

TEST(PoissonLinear, functions) {

	double xLower = -1;
	double xUpper = 1;
	double yLower = 0;
	double yUpper = 2;
	HPS::PoissonLinear poisson(xLower, xUpper, yLower, yUpper);

	ASSERT_FLOAT_EQ(poisson.uFunction(1.0, 1.0), 2.0);
	ASSERT_FLOAT_EQ(poisson.fFunction(0, 0), 0.0);
	ASSERT_FLOAT_EQ(poisson.dudxFunction(0, 0), 1.0);
	ASSERT_FLOAT_EQ(poisson.dudyFunction(0, 0), 1.0);
	
}

TEST(PoissonQuad, init) {

	double xLower = -1;
	double xUpper = 1;
	double yLower = 0;
	double yUpper = 2;
	HPS::PoissonQuad poisson(xLower, xUpper, yLower, yUpper);

	ASSERT_EQ(xLower, poisson.getXLower());
	ASSERT_EQ(xUpper, poisson.getXUpper());
	ASSERT_EQ(yLower, poisson.getYLower());
	ASSERT_EQ(yUpper, poisson.getYUpper());

}

TEST(PoissonQuad, functions) {

	double xLower = -1;
	double xUpper = 1;
	double yLower = 0;
	double yUpper = 2;
	HPS::PoissonQuad poisson(xLower, xUpper, yLower, yUpper);

	ASSERT_FLOAT_EQ(poisson.uFunction(1.0, 1.0), 4.0);
	ASSERT_FLOAT_EQ(poisson.fFunction(1.0, 1.0), 4.0);
	ASSERT_FLOAT_EQ(poisson.dudxFunction(1.0, 1.0), 4.0);
	ASSERT_FLOAT_EQ(poisson.dudyFunction(1.0, 1.0), 4.0);
	
}