/**
 * 
 * [TODO: Add Documentation]
 * 
 */
#ifndef HPS_H_
#define HPS_H_

#include <mpi.h>
#include <p4est.h>
#include <petsc.h>
#include <petscvec.h>
#include <petscmat.h>
#include <petscdmda.h>


enum DIRECTIONS {
	XDIM,
	YDIM
};

enum ELLIPTIC_PROBLEMS {
	LAPLACE,
	POISSON,
	HELMHOLTZ,
	COEFFICIENT
};

/**
 * ============================================================================
 * Base HPS Functions
 * ============================================================================
 */
int hps_init(int* aargc, char*** aargv, char help[]);
int hps_finalize();

/**
 * ============================================================================
 * Data Structures
 * 
 *     hps_cellgrid_t : Contains the local grid information
 *     hps_patch_t : Contains patch data
 * ============================================================================
 */
typedef struct hps_cellgrid {

	double    x_lower, y_lower;
	double    x_upper, y_upper;
	int       x_npts, y_npts;
	double    dx, dy;

} hps_cellgrid_t;

int hps_cellgrid_init (
	hps_cellgrid_t* self,
	double x_lower,
	double y_lower,
	double x_upper,
	double y_upper,
	int x_npts,
	int y_npts
);

double hps_cellgrid_index (
	hps_cellgrid_t* self,
	int direction,
	int index
);

typedef struct hps_patch {
	
	MPI_Comm comm;
	hps_cellgrid_t grid;
	DM petsc_da;
	Mat X_matrix;            // Interior Load -> Interior Potential
	Mat H_matrix;            // Interior Load -> Exterior Flux
	Mat T_matrix;            // Exterior Potential -> Interior Potential
	Mat S_matrix;            // Exterior Potential -> Exterior Flux
	Vec g_vector;            // Exterior Potential
	Vec h_vector;            // Exterior Flux
	Vec f_vector;            // Interior Load

} hps_patch_t;

int hps_patch_init (
	hps_patch_t* self,
	MPI_Comm comm,
	hps_cellgrid_t grid
);

typedef struct hps_elliptic {

	int problem_flag;

} hps_elliptic_t;

/**
 * ============================================================================
 * Patch Solver Functions
 * ============================================================================
 */


/**
 * ============================================================================
 * p4est Functions
 * ============================================================================
 */

// static void p4est_hps_patch_init_fn()

#endif // HPS_H_