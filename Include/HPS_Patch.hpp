#ifndef HPS_PATCH_HPP_
#define HPS_PATCH_HPP_

#include <HPS.hpp>
#include <HPS_CellGrid.hpp>
#include <mpi.h>
#include <petscvec.h>
#include <petscmat.h>
#include <petscdmda.h>


namespace HPS {

class Patch {

public:

	typedef struct patch_data {

		CellGrid::cellgrid_data_t* cellgrid;
		Vec f_vector;    // RHS Load Vector
		Vec g_vector;    // Dirichlet BC Vector
		Vec h_vector;    // Neumann BC Vector
		Mat A_matrix;    // Finite Difference Stencil Matrix
		Mat X_matrix;    // Interior Potential Matrix
		Mat H_matrix;    // Interior Flux Matrix
		Mat S_matrix;    // Solution Matrix
		Mat T_matrix;    // Dirichlet-to-Neumann Matrix
		DM  petsc_da;    // Distributed Array

	} patch_data_t;
	patch_data_t data_;

	MPI_Comm comm;
	int my_rank;
	int my_ID;
	int my_level;
	bool is_leaf;

	Patch(MPI_Comm comm, CellGrid grid, int ID, int level, bool is_leaf);
	~Patch();

	Vec* getFVector();
	Vec* getGVector();
	Vec* getHVector();
	Mat* getAMatrix();
	Mat* getXMatrix();
	Mat* getHMatrix();
	Mat* getSMatrix();
	Mat* getTMatrix();
	DM* getDa();
	patch_data_t* getData();
	MPI_Comm getComm();
	int getRank();
	int getID();
	int getLevel();
	
	void buildAMatrix();
	void buildSMatrix();
	void buildTMatrix();

};

} // END OF NAMESPACE : HPS

#endif // HPS_PATCH_HPP_