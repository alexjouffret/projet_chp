#include <vector>
#include "fonctions.hpp"
#include "matrix.hpp"

void sparseMatrix(std::vector<double> &row,std::vector<double> &col,std::vector<double> &value, int Nx, int Ny, double Lx, double Ly, double D, double dt){
  // Fonction qui remplt la matrice associée au problème avec un stockage coordonnées
  double di(0),sdi(0),ssdi(0);
  di=1+(2*dt*Lx*Lx*D/(Nx*Nx))+(2*dt*Ly*Ly*D/(Ny*Ny));
  sdi=-dt*D*Ly*Ly/(Ny*Ny);
  ssdi=-dt*D*Lx*Lx/(Nx*Nx);
  for(int i=0; i<(Nx*Ny); i++){
    col.push_back(i);
    row.push_back(i);
    value.push_back(di);
    if((i+1)%Nx==0){} // ! attention au 0 qui apparait au lieu du sdi a chaque fin de bloc !
    else{
      col.push_back(i); //stockage de la sous-diagonale
      row.push_back(i+1);
      value.push_back(sdi);
      col.push_back(i+1); //stockage de la sur-diagonale (symetrie)
      row.push_back(i);
      value.push_back(sdi);
    }
    if(i+Nx<Nx*Nx){
    col.push_back(i); //stockage de la sous-sous-diagonale
    row.push_back(i+Nx);
    value.push_back(ssdi);
    col.push_back(i+Nx); //stockage de la sur-sur-diagonale (symetrie)
    row.push_back(i);
    value.push_back(ssdi);
    }
  }
}

// ---------------------------------------------------------

void secondMembre(std::vector<double> &U, int Nx, int Ny, double dt, double Lx, double Ly, int mode){
  // Fonction qui remplit le second membre
  double dx(0),dy(0);
  dx=Lx/Nx;
  dy=Ly/Ny;
  for(int i=0; i<Nx; i++){
    for(int j=0; j<Ny; j++){
      U[i+j*Nx]+=dt*f(i*dx,j*dy,dt,Lx,Lx,mode);
      if(j==0 || j==Ny-1){                          // Conditions au limites sur gamma 0
        U[i+j*Nx]+=g(i*dx,j*dy,mode);
      }
      if(i%Nx==0 || i%Nx==Nx-1){                    // Conditions aux limites sur gamma 1
        U[i+j*Nx]+=h(i*dx,j*dy,mode);
      }
    }
  }
}
