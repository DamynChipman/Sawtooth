#include <HPS_Patch.hpp>

namespace HPS {

Patch::Patch(MPI_Comm comm, CellGrid grid, int ID, int level, bool is_leaf) {

	this->comm = comm;
	MPI_Comm_rank(comm, &(this->my_rank));

	this->my_ID = ID;
	this->my_level = level;
	this->is_leaf = is_leaf;

	this->data_.cellgrid = grid.getData();

	DMBoundaryType bx = DM_BOUNDARY_NONE;
	DMBoundaryType by = DM_BOUNDARY_NONE;
	DMDAStencilType stencil_type = DMDA_STENCIL_STAR;
	PetscInt M = grid.getXNpts();
	PetscInt N = grid.getYNpts();
	PetscInt m = PETSC_DECIDE;
	PetscInt n = PETSC_DECIDE;
	PetscInt dof = 1;
	PetscInt s = 1;
	DMDACreate2d(this->comm, bx, by, stencil_type, M, N, m, n, dof, s, NULL, NULL, &(this->data_.petsc_da));

}

Patch::~Patch() {}

Vec* Patch::getFVector() { return &(this->data_.f_vector); }
Vec* Patch::getGVector() { return &(this->data_.g_vector); }
Vec* Patch::getHVector() { return &(this->data_.h_vector); }
Mat* Patch::getXMatrix() { return &(this->data_.X_matrix); }
Mat* Patch::getHMatrix() { return &(this->data_.H_matrix); }
Mat* Patch::getSMatrix() { return &(this->data_.S_matrix); }
Mat* Patch::getTMatrix() { return &(this->data_.T_matrix); }
DM* Patch::getDa() { return &(this->data_.petsc_da); }
Patch::patch_data_t* Patch::getData() { return &(this->data_); }
MPI_Comm Patch::getComm() { return this->comm; }
int Patch::getRank() { return this->my_rank; }
int Patch::getID() { return this->my_ID; }
int Patch::getLevel() { return this->my_level; }

void buildTMatrix() {}

} // END OF NAMESPACE : HPS