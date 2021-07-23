#include "HPS_Poisson.hpp"

namespace HPS {

// PoissonProblem::PoissonProblem(int problem_ID, double Ax, double Bx, double Ay, double By) : ID(problem_ID), Ax(Ax), Bx(Bx), Ay(Ay), By(By) {}

// double PoissonProblem::u(double x, double y) {
// 	switch(ID) {
// 		case CONSTANT:
// 			return 1.0;
// 		case LINEAR:
// 			return x + y;
// 		case LAPLACE:
// 			return y*sin(2*M_PI*x) + x*cos(2*M_PI*y) + 4;
// 		case QUAD:
// 			return x*x + y*y + 2*x*y;
// 		case POLY:
// 			return y*y*x*x*x*x;
// 		case TRIG:
// 			return sin(2*M_PI*x) * sin(2*M_PI*y);
// 		default:
// 			throw std::invalid_argument("[PoissonProblem::u] Invalid problem_ID.");
// 	}
// }

// double PoissonProblem::f(double x, double y) {
// 	switch(ID) {
// 		case CONSTANT:
// 			return 0.0;
// 		case LINEAR:
// 			return 0.0;
// 		case LAPLACE:
// 			return 0.0;
// 		case QUAD:
// 			return 4.0;
// 		case POLY:
// 			return 2.0*x*x*(6.0*y*y + x*x);
// 		case TRIG:
// 			return -2.0*pow(2.0*M_PI,2)*u(x,y);
// 		default:
// 			throw std::invalid_argument("[PoissonProblem::u] Invalid problem_ID.");
// 	}

// }

// double PoissonProblem::dudx(double x, double y) {
// 	switch(ID) {
// 		case CONSTANT:
// 			return 0.0;
// 		case LINEAR:
// 			return 1.0;
// 		case QUAD:
// 			return 2.0*x + 2.0*y;
// 		case POLY:
// 			return 4.0*y*y*x*x*x;
// 		case TRIG:
// 			return 2.0*M_PI*cos(2.0*M_PI*x) * sin(2.0*M_PI*y);
// 		default:
// 			throw std::invalid_argument("[PoissonProblem::u] Invalid problem_ID.");
// 	}
// }

// double PoissonProblem::dudy(double x, double y) {
// 	switch(ID) {
// 		case CONSTANT:
// 			return 0.0;
// 		case LINEAR:
// 			return 1.0;
// 		case QUAD:
// 			return 2.0*y + 2*x;
// 		case POLY:
// 			return 2.0*y*x*x*x*x;
// 		case TRIG:
// 			return sin(2*M_PI*x) * 2.0*M_PI*cos(2*M_PI*y);
// 		default:
// 			throw std::invalid_argument("[PoissonProblem::u] Invalid problem_ID.");
// 	}
// }

double PoissonConstant::uFunction(double x, double y) {
	return 1.0;
}

double PoissonConstant::fFunction(double x, double y) {
	return 0.0;
}

double PoissonConstant::dudxFunction(double x, double y) {
	return 0.0;
}

double PoissonConstant::dudyFunction(double x, double y) {
	return 0.0;
}

double PoissonLinear::uFunction(double x, double y) {
	return x + y;
}

double PoissonLinear::fFunction(double x, double y) {
	return 0.0;
}

double PoissonLinear::dudxFunction(double x, double y) {
	return 1.0;
}

double PoissonLinear::dudyFunction(double x, double y) {
	return 1.0;
}

double PoissonQuad::uFunction(double x, double y) {
	return x*x + y*y + 2*x*y;
}

double PoissonQuad::fFunction(double x, double y) {
	return 4.0;
}

double PoissonQuad::dudxFunction(double x, double y) {
	return 2.0*x + 2.0*y;
}

double PoissonQuad::dudyFunction(double x, double y) {
	return 2.0*x + 2.0*y;
}

} // END OF NAMESPACE : HPS
