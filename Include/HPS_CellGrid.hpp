#ifndef HPS_CELLGRID_HPP_
#define HPS_CELLGRID_HPP_

#include <exception>
#include <mpi.h>
#include <petscdmda.h>
#include <HPS.hpp>

namespace HPS {

enum DIRECTION {

	XDIM,
	YDIM

};

class CellGrid {

public:

	typedef struct cellgrid_data {

		double x_lower, y_lower;
		double x_upper, y_upper;
		int    x_npts,  y_npts;
		double dx,      dy;

	} cellgrid_data_t;
	cellgrid_data_t data_;

	MPI_Comm comm;
	int my_rank;

	CellGrid(MPI_Comm comm, double x_lower, double y_lower, double x_upper, double y_upper, int x_npts, int y_npts);

	double getXLower();
	double getYLower();
	double getXUpper();
	double getYUpper();
	int getXNpts();
	int getYNpts();
	double getDx();
	double getDy();
	cellgrid_data_t* getData();
	MPI_Comm getComm();


	double operator()(int DIM, std::size_t index);

};

double cellgridIndex(CellGrid::cellgrid_data_t* data, int DIM, std::size_t index);


} // END OF NAMESPACE : HPS

#endif // HPS_CELLGRID_HPP_