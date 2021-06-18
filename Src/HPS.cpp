/**
 * 
 *  [TODO: Add documentation]
 * 
 */
#include <HPS.hpp>

namespace HPS {

int HPS_Init(int* aargc, char*** aargv, char help[]) {

	int ierr = 0;
	ierr = MPI_Init(aargc, aargv); if (ierr) return ierr;
	p4est_init(NULL, SC_LP_DEFAULT);
	ierr = PetscInitialize(aargc, aargv, (char*) 0, help);
	printf("[hps] This is HPS 0.1\n");
	return ierr;

}

int HPS_Finalize() {

	int ierr = 0;
	ierr = PetscFinalize(); if (ierr) return ierr;
	ierr = MPI_Finalize(); if (ierr) return ierr;
	return ierr;

}

} // END OF NAMESPACE : HPS

// int hps_cellgrid_init(hps_cellgrid_t* self, double x_lower, double y_lower, double x_upper, double y_upper, int x_npts, int y_npts) {

// 	int ierr = 0;

// 	if (x_lower > x_upper || y_lower > y_upper) return 1;
// 	if (x_npts <= 0 || y_npts <= 0) return 1;
	
// 	self->x_lower = x_lower;
// 	self->y_lower = y_lower;
// 	self->x_upper = x_upper;
// 	self->y_upper = y_upper;
// 	self->x_npts = x_npts;
// 	self->y_npts = y_npts;
// 	self->dx = (self->x_upper - self->x_lower) / (self->x_npts);
// 	self->dy = (self->y_upper - self->y_lower) / (self->y_npts);

// 	return ierr;

// }

// double hps_cellgrid_index(hps_cellgrid_t* self, int direction, int index) {

// 	double point;
// 	if (direction == XDIM) {
// 		point = self->x_lower + self->dx / 2 + index * self->dx;
// 		return point;
// 	}
// 	else if (direction == YDIM) {
// 		point = self->y_lower + self->dy / 2 + index * self->dy;
// 		return point;
// 	}

// }


// int hps_patch_init(hps_patch_t* self, MPI_Comm comm, hps_cellgrid_t grid) {

// 	int ierr = 0;

// 	self->comm = comm;
// 	self->grid = grid;

// 	DMBoundaryType bx = DM_BOUNDARY_NONE;
// 	DMBoundaryType by = DM_BOUNDARY_NONE;
// 	DMDAStencilType stencil_type = DMDA_STENCIL_STAR;
// 	PetscInt M = grid.x_npts;
// 	PetscInt N = grid.y_npts;
// 	PetscInt m = PETSC_DECIDE;
// 	PetscInt n = PETSC_DECIDE;
// 	PetscInt dof = 1;
// 	PetscInt s = 1;
// 	ierr = DMDACreate2d(comm, bx, by, stencil_type, M, N, m, n, dof, s, NULL, NULL, &(self->petsc_da));

// 	return ierr;

// }