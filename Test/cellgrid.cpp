#include "gtest/gtest.h"
#include <mpi.h>
#include <vector>
#include <HPS_CellGrid.hpp>

TEST(CellGrid, init) {

	double x_lower = -1;
	double y_lower = 0;
	double x_upper = 1;
	double y_upper = 1;
	int x_npts = 4;
	int y_npts = 2;

	HPS::CellGrid grid(MPI_COMM_WORLD, x_lower, y_lower, x_upper, y_upper, x_npts, y_npts);

}

TEST(CellGrid, init_data) {

	double x_lower = -1;
	double y_lower = 0;
	double x_upper = 1;
	double y_upper = 1;
	int x_npts = 4;
	int y_npts = 2;

	HPS::CellGrid grid(MPI_COMM_WORLD, x_lower, y_lower, x_upper, y_upper, x_npts, y_npts);

	double dx = (x_upper - x_lower) / (x_npts);
	double dy = (y_upper - y_lower) / (y_npts);

	ASSERT_FLOAT_EQ(grid.getXLower(), x_lower);
	ASSERT_FLOAT_EQ(grid.getYLower(), y_lower);
	ASSERT_FLOAT_EQ(grid.getXUpper(), x_upper);
	ASSERT_FLOAT_EQ(grid.getYUpper(), y_upper);
	ASSERT_EQ(grid.getXNpts(), x_npts);
	ASSERT_EQ(grid.getYNpts(), y_npts);
	ASSERT_FLOAT_EQ(grid.getDx(), dx);
	ASSERT_FLOAT_EQ(grid.getDy(), dy);

}

TEST(CellGrid, points) {

	double x_lower = -1;
	double y_lower = 0;
	double x_upper = 1;
	double y_upper = 1;
	int x_npts = 4;
	int y_npts = 2;

	HPS::CellGrid grid(MPI_COMM_WORLD, x_lower, y_lower, x_upper, y_upper, x_npts, y_npts);

	std::vector<double> x_points = {-0.75, -0.25, 0.25, 0.75};
	std::vector<double> y_points = {0.25, 0.75};

	for (std::size_t i = 0; i < x_points.size(); i++) {
		ASSERT_FLOAT_EQ(grid(HPS::XDIM, i), x_points[i]);
	}
	
	for (std::size_t j = 0; j < y_points.size(); j++) {
		ASSERT_FLOAT_EQ(grid(HPS::YDIM, j), y_points[j]);
	}

}

TEST(CellGrid, data) {

	double x_lower = -1;
	double y_lower = 0;
	double x_upper = 1;
	double y_upper = 1;
	int x_npts = 4;
	int y_npts = 2;

	HPS::CellGrid grid(MPI_COMM_WORLD, x_lower, y_lower, x_upper, y_upper, x_npts, y_npts);

	std::vector<double> x_points = {-0.75, -0.25, 0.25, 0.75};
	std::vector<double> y_points = {0.25, 0.75};

	HPS::CellGrid::cellgrid_data_t* grid_data = grid.getData();

	for (std::size_t i = 0; i < x_points.size(); i++) {
		ASSERT_FLOAT_EQ(cellgridIndex(grid_data, HPS::XDIM, i), x_points[i]);
	}
	
	for (std::size_t j = 0; j < y_points.size(); j++) {
		ASSERT_FLOAT_EQ(cellgridIndex(grid_data, HPS::YDIM, j), y_points[j]);
	}

}