#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

void sparseMatrix(std::vector<double> &row,std::vector<double> &col,std::vector<double> &value, int Nx, int Ny, double Lx, double Ly, double D, double dt);
void secondMembre(std::vector<double> &U, int Nx, int Ny, double dt, double Lx, double Ly, int mode);

#endif // _MATRIX_HPP_
