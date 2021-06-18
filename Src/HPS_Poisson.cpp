#include "HPS_Poisson.hpp"

namespace HPS {

PoissonProblem::PoissonProblem(int problem_ID, double Ax, double Bx, double Ay, double By) : ID(problem_ID), Ax(Ax), Bx(Bx), Ay(Ay), By(By) {}

double PoissonProblem::u(double x, double y) {
	switch(ID) {
		case CONSTANT:
			return 1.0;
		case LINEAR:
			return x + y;
		case LAPLACE:
			return y*sin(2*M_PI*x) + x*cos(2*M_PI*y) + 4;
		case QUAD:
			return x*x + y*y + 2*x*y;
		case POLY:
			return y*y*x*x*x*x;
		case TRIG:
			return sin(2*M_PI*x) * sin(2*M_PI*y);
		default:
			throw std::invalid_argument("[PoissonProblem::u] Invalid problem_ID.");
	}
}

double PoissonProblem::f(double x, double y) {
	switch(ID) {
		case CONSTANT:
			return 0.0;
		case LINEAR:
			return 0.0;
		case LAPLACE:
			return 0.0;
		case QUAD:
			return 4.0;
		case POLY:
			return 2.0*x*x*(6.0*y*y + x*x);
		case TRIG:
			return -2.0*pow(2.0*M_PI,2)*u(x,y);
		default:
			throw std::invalid_argument("[PoissonProblem::u] Invalid problem_ID.");
	}

}

double PoissonProblem::dudx(double x, double y) {
	switch(ID) {
		case CONSTANT:
			return 0.0;
		case LINEAR:
			return 1.0;
		case QUAD:
			return 2.0*x + 2.0*y;
		case POLY:
			return 4.0*y*y*x*x*x;
		case TRIG:
			return 2.0*M_PI*cos(2.0*M_PI*x) * sin(2.0*M_PI*y);
		default:
			throw std::invalid_argument("[PoissonProblem::u] Invalid problem_ID.");
	}
}

double PoissonProblem::dudy(double x, double y) {
	switch(ID) {
		case CONSTANT:
			return 0.0;
		case LINEAR:
			return 1.0;
		case QUAD:
			return 2.0*y + 2*x;
		case POLY:
			return 2.0*y*x*x*x*x;
		case TRIG:
			return sin(2*M_PI*x) * 2.0*M_PI*cos(2*M_PI*y);
		default:
			throw std::invalid_argument("[PoissonProblem::u] Invalid problem_ID.");
	}
}

} // END OF NAMESPACE : HPS
