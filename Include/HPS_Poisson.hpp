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

// class PoissonProblem {

// public:

// 	int ID;
// 	double Ax;
// 	double Bx;
// 	double Ay;
// 	double By;

// 	PoissonProblem(int problem_ID, double Ax, double Bx, double Ay, double By);
// 	double u(double x, double y);
// 	double f(double x, double y);
// 	double dudx(double x, double y);
// 	double dudy(double x, double y);

// };

class Poisson2D {

protected:

	double _xLower;
	double _xUpper;
	double _yLower;
	double _yUpper;

public:

	// Constructors
	Poisson2D(double xLower, double xUpper, double yLower, double yUpper) :
		_xLower(xLower), _xUpper(xUpper), _yLower(yLower), _yUpper(yUpper)
			{}

	// Interface Functions
	virtual double uFunction(double x, double y) = 0;
	virtual double fFunction(double x, double y) = 0;
	virtual double dudxFunction(double x, double y) = 0;
	virtual double dudyFunction(double x, double y) = 0;

	// Getters and Setters
	double getXLower() { return _xLower; }
	double getXUpper() { return _xUpper; }
	double getYLower() { return _yLower; }
	double getYUpper() { return _yUpper; }
	void setXLower(double xLower) { _xLower = xLower; }
	void setXUpper(double xUpper) { _xUpper = xUpper; }
	void setYLower(double yLower) { _yLower = yLower; }
	void setYUpper(double yUpper) { _yUpper = yUpper; }

};

class PoissonConstant : public Poisson2D {

public:

	PoissonConstant(double xLower, double xUpper, double yLower, double yUpper) :
		Poisson2D{xLower, xUpper, yLower, yUpper}
			{}

	double uFunction(double x, double y);
	double fFunction(double x, double y);
	double dudxFunction(double x, double y);
	double dudyFunction(double x, double y);

};

class PoissonLinear : public Poisson2D {

public:

	PoissonLinear(double xLower, double xUpper, double yLower, double yUpper) :
		Poisson2D{xLower, xUpper, yLower, yUpper}
			{}

	double uFunction(double x, double y);
	double fFunction(double x, double y);
	double dudxFunction(double x, double y);
	double dudyFunction(double x, double y);

};

class PoissonQuad : public Poisson2D {

public:

	PoissonQuad(double xLower, double xUpper, double yLower, double yUpper) :
		Poisson2D{xLower, xUpper, yLower, yUpper}
			{}

	double uFunction(double x, double y);
	double fFunction(double x, double y);
	double dudxFunction(double x, double y);
	double dudyFunction(double x, double y);

};

} // END OF NAMESPACE : HPS

#endif // HPS_POISSON_HPP_
