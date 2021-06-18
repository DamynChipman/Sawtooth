static char help[] = "Hello World for Sawtooth.\n\n";

#include <stdio.h>
#include <mpi.h>
#include <HPS.hpp>

#define HEAD_RANK 0

using namespace HPS;

int main(int argc, char** argv) {
	printf("Hello Sawtooth!\n");
	int ierr = 0;

	ierr = HPS_Init(&argc, &argv, help);

	// int my_rank, total_ranks;
	// MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	// MPI_Comm_size(MPI_COMM_WORLD, &total_ranks);

	// double x_lower = -1;
	// double y_lower = 0;
	// double x_upper = 1;
	// double y_upper = 5;
	// int x_npts = 5;
	// int y_npts = 10;
	// hps_cellgrid_t grid;
	// ierr = hps_cellgrid_init(&grid, x_lower, y_lower, x_upper, y_upper, x_npts, y_npts);

	// if (my_rank == HEAD_RANK) {
	// 	for (int i = 0; i < x_npts; i++) {
	// 		printf("%8.4f  ", hps_cellgrid_index(&grid, XDIM, i));
	// 	}
	// 	printf("\n");

	// 	for (int j = 0; j < y_npts; j++) {
	// 		printf("%8.4f  ", hps_cellgrid_index(&grid, YDIM, j));
	// 	}
	// 	printf("\n");
	// }

	ierr = HPS_Finalize();
	return ierr;
}