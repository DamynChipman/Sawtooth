#include <HPS_P4est.hpp>

namespace HPS {

int MAX_LEVEL = 0;
// double (Poisson2D::*POISSON_RHS_FUNCTION) (double x, double y);

static int refine_fn_always(p4est_t* p4est, p4est_topidx_t which_tree, p4est_quadrant_t* quadrant) {
	return 1;
}

static int refine_fn_by_value(p4est_t* p4est, p4est_topidx_t which_tree, p4est_quadrant_t* quadrant) {
	
	// Get quadrant's lower left coordinate
	double vxyz[3];
	p4est_qcoord_to_vertex(p4est->connectivity, which_tree, quadrant->x, quadrant->y, vxyz);

	// Map from vertex space to poisson space
	// ---> WORKING HERE <---

}

p4est_t* HPS_CreateP4est(Poisson2D* poisson, int min_level, int max_level, double refine_value) {

	// Set global variables
	MAX_LEVEL = max_level;
	// POISSON_RHS_FUNCTION = &Poisson2D::fFunction;
	// POISSON_RHS_FUNCTION = &(poisson->fFunction);

	// double f = POISSON_RHS_FUNCTION(0, 0);

	// Create connectivity
	p4est_connectivity_t* conn = p4est_connectivity_new_unitsquare();

	// Create p4est object
	p4est_t* p4est = p4est_new(MPI_COMM_WORLD, conn, sizeof(Patch::patch_data_t), NULL, NULL);

	// Refine p4est until min_level is reached
	int current_level;
	for (current_level = 0; current_level < min_level; current_level++) {
		int recursive = 0;
		p4est_refine(p4est, recursive, refine_fn_always, NULL);
	}

	// Begin refining if middle of quad is greater or less than refine_value
	

	// Return address of p4est object
	return p4est;

}

} // END OF NAMESPACE : HPS