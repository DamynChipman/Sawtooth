#include <HPS_CellGrid.hpp>

namespace HPS {

CellGrid::CellGrid(MPI_Comm comm, double x_lower, double y_lower, double x_upper, double y_upper, int x_npts, int y_npts) {
	
	this->comm = comm;
	MPI_Comm_rank(comm, &(this->my_rank));

	this->data_.x_lower = x_lower;
	this->data_.y_lower = y_lower;
	this->data_.x_upper = x_upper;
	this->data_.y_upper = y_upper;
	this->data_.x_npts = x_npts;
	this->data_.y_npts = y_npts;
	this->data_.dx = (x_upper - x_lower) / (x_npts);
	this->data_.dy = (y_upper - y_lower) / (y_npts);

}

double CellGrid::getXLower() { return this->data_.x_lower; }
double CellGrid::getYLower() { return this->data_.y_lower; }
double CellGrid::getXUpper() { return this->data_.x_upper; }
double CellGrid::getYUpper() { return this->data_.y_upper; }
int CellGrid::getXNpts() { return this->data_.x_npts; }
int CellGrid::getYNpts() { return this->data_.y_npts; }
double CellGrid::getDx() { return this->data_.dx; }
double CellGrid::getDy() { return this->data_.dy; }
CellGrid::cellgrid_data_t* CellGrid::getData() { return &(this->data_); }

double CellGrid::operator()(int DIM, std::size_t index) {
	if (DIM == XDIM)      { return this->getXLower() + (0.5 + index)*this->getDx(); }
	else if (DIM == YDIM) { return this->getYLower() + (0.5 + index)*this->getDy(); }
	else { throw std::invalid_argument("[CellGrid::operator()] Invalid `DIM` argument."); }
}

double cellgridIndex(CellGrid::cellgrid_data_t* data, int DIM, std::size_t index) {
	if (DIM == XDIM)      { return data->x_lower + (0.5 + index)*data->dx; }
	else if (DIM == YDIM) { return data->y_lower + (0.5 + index)*data->dy; }
	else { throw std::invalid_argument("[CellGrid::operator()] Invalid `DIM` argument."); }
}


} // END OF NAMESPACE : HPS