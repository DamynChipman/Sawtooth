#ifndef HPS_POISSON_HPP_
#define HPS_POISSON_HPP_

#include <iostream>
#include <cmath>

namespace HPS {

// ===== Enums =====
enum PROBLEM_TYPE {
	CONSTANT,
	LINEAR,
	LAPLACE,
	QUAD,
	POLY,
	TRIG
};

enum BOUNDARY_SIDE {
	WEST,
	EAST,
	SOUTH,
	NORTH
};

// ===== Function Definitions =====
// double poisson_u(double x, double y, int PROB_ID);
// double poisson_f(double x, double y, int PROB_ID);
// double poisson_g(double x, double y, int PROB_ID, int BC_SIDE);
// double poisson_h(double x, double y, int PROB_ID, int BC_SIDE);

class PoissonProblem {

public:

	int ID;
	double Ax;
	double Bx;
	double Ay;
	double By;

	PoissonProblem(int problem_ID, double Ax, double Bx, double Ay, double By);
	double u(double x, double y);
	double f(double x, double y);
	double dudx(double x, double y);
	double dudy(double x, double y);

};

} // END OF NAMESPACE : HPS

#endif // HPS_POISSON_HPP_
