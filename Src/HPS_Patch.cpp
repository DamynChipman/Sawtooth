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
Mat* Patch::getAMatrix() { return &(this->data_.A_matrix); }
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

void Patch::buildAMatrix() {

	if (this->is_leaf == false) {
		std::cerr << "[Patch::leafSolve] Calling `is_leaf` on patch that is not a leaf." << std::endl;
		return;
	} 

	// Form A
	DMDALocalInfo info;
	MatStencil row, col[5];
	double v[5];
	int ncols;

	DMDAGetLocalInfo(*(this->getDa()), &info);
	double dx = this->data_.cellgrid->dx;
	double dy = this->data_.cellgrid->dy;
	int localNx = info.mx;
	int localNy = info.my;

	for (int j = info.ys; j < info.ys + info.ym; j++) {
		for (int i = info.xs; i < info.xs + info.xm; i++) {
			// Iterate over each grid point on patch grid
			row.j = j;
			row.i = i;
			col[0].j = j;
			col[0].i = i;
			double rho = 1 / (dx * dx);
			// Begin cases
			//    Corners
			if (i == 0 && j == 0) { // Lower Left Corner
				ncols = 3;
				col[0].j = j;   col[0].i = i;   v[0] = -6 * rho;
				col[1].j = j+1; col[1].i = i;   v[1] = 1 * rho;
				col[2].j = j;   col[2].i = i+1; v[2] = 1 * rho;
			}
			else if (i == localNx - 1 && j == 0) { // Lower Right Corner
				ncols = 3;
				col[0].j = j;   col[0].i = i;   v[0] = -6 * rho;
				col[1].j = j+1; col[1].i = i;   v[1] = 1 * rho;
				col[2].j = j;   col[2].i = i-1; v[2] = 1 * rho;
			}
			else if (i == 0 && j == localNy - 1) { // Upper Left Corner
				ncols = 3;
				col[0].j = j;   col[0].i = i;   v[0] = -6 * rho;
				col[1].j = j-1; col[1].i = i;   v[1] = 1 * rho;
				col[2].j = j;   col[2].i = i+1; v[2] = 1 * rho;
			}
			else if (i == localNx - 1 && j == localNy - 1) { // Upper Right Corner
				ncols = 3;
				col[0].j = j;   col[0].i = i;   v[0] = -6 * rho;
				col[1].j = j-1; col[1].i = i;   v[1] = 1 * rho;
				col[2].j = j;   col[2].i = i-1; v[2] = 1 * rho;
			}
			//    Edges
			else if (j == 0) { // Left Edge
				ncols = 4;
				col[0].j = j;   col[0].i = i;   v[0] = -5 * rho;
				col[1].j = j-1; col[1].i = i;   v[1] = 1 * rho;
				col[2].j = j;   col[2].i = i+1; v[2] = 1 * rho;
				col[3].j = j+1; col[3].i = i;   v[3] = 1 * rho;
			}
			else if (j == localNy - 1) { // Right Edge
				ncols = 4;
				col[0].j = j;   col[0].i = i;   v[0] = -5 * rho;
				col[1].j = j;   col[1].i = i-1; v[1] = 1 * rho;
				col[2].j = j-1; col[2].i = i;   v[2] = 1 * rho;
				col[3].j = j+1;   col[3].i = i; v[3] = 1 * rho;
			}
			else if (i == 0) { // Bottom Edge
				ncols = 4;
				col[0].j = j;   col[0].i = i;   v[0] = -5 * rho;
				col[1].j = j;   col[1].i = i-1; v[1] = 1 * rho;
				col[2].j = j;   col[2].i = i+1; v[2] = 1 * rho;
				col[3].j = j+1; col[3].i = i;   v[3] = 1 * rho;
			}
			else if (i == localNx - 1) { // Top Edge
				ncols = 4;
				col[0].j = j;   col[0].i = i;   v[0] = -5 * rho;
				col[1].j = j;   col[1].i = i-1; v[1] = 1 * rho;
				col[2].j = j;   col[2].i = i+1; v[2] = 1 * rho;
				col[3].j = j-1; col[3].i = i;   v[3] = 1 * rho;
			}
			//    Center
			else {
				ncols = 5;
				col[0].j = j;   col[0].i = i;   v[0] = -4 * rho;
				col[1].j = j;   col[1].i = i-1; v[1] = 1 * rho;
				col[2].j = j-1; col[2].i = i;   v[2] = 1 * rho;
				col[3].j = j;   col[3].i = i+1; v[3] = 1 * rho;
				col[4].j = j+1; col[4].i = i;   v[4] = 1 * rho;
			}

			int nrows = 1;
			MatSetValuesStencil(this->data_.A_matrix, nrows, &row, ncols, col, v, INSERT_VALUES);
		}
	}

	MatAssemblyBegin(this->data_.A_matrix, MAT_FINAL_ASSEMBLY);
	MatAssemblyEnd(this->data_.A_matrix, MAT_FINAL_ASSEMBLY);
}

void Patch::buildSMatrix() {}
void Patch::buildTMatrix() {}

} // END OF NAMESPACE : HPS