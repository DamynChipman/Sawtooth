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
	// printf("[hps] This is HPS 0.1\n");
	return ierr;

}

int HPS_Finalize() {

	int ierr = 0;
	ierr = PetscFinalize(); if (ierr) return ierr;
	ierr = MPI_Finalize(); if (ierr) return ierr;
	return ierr;

}

} // END OF NAMESPACE : HPS

