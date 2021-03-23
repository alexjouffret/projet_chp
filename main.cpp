#include <cstdio>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <iostream>

// #include <mpi.h>
#include "fonctions.hpp"
#include "matrix.hpp"
#include "charge.hpp"

using namespace std;

int main(int argc, char** argv) {

  // Lecture des données dans le fichier paramètres (parameters.txt)
  ifstream file("parameters.txt");
  int    Nx(0), Ny(0);        // Nombre de noeuds en x et en y
  double Lx(0), Ly(0), D(0), dt(0);
  int    mode(0);             // Variable qui permet de choisir quelles fonctions f,g,h sont prises
  file >> Nx >> Ny >> Lx >> Ly >> D >> dt >> mode;
  printf("Nx = %d, Ny = %d, Lx = %f, Ly = %f, D = %f , dt = %f, mode = %d\n", Nx, Ny, Lx, Ly, D, dt, mode);
  file.close();

  // ---------------------------------------------------------

  // Test des valeurs des fonctions f, g et h
  // double testf, testg, testh;
  // double x(0.2),y(0.3);
  // testf = f(x,y,dt,Lx,Ly,mode);
  // testg = g(x,y,mode);
  // testh = h(x,y,mode);
  // printf("Testf = %f, Testg = %f, Testh = %f \n", testf, testg, testh );

  // ---------------------------------------------------------

  // Construction de la matrice associée au problème
  vector<double> row,col,value;
  vector<double> Uo(Nx*Ny,0);
  sparseMatrix(row,col,value,Nx,Ny,Lx,Ly,D,dt);
  secondMembre(Uo,Nx,Ny,dt,Lx,Ly,mode);

  // ---------------------------------------------------------

  //Affichage des vecteurs du stockage creux de la matrice
  // printf("\nAffichage de la matrice en stockage creux (coordonnées) \n\n");
  // for(int i=0; i<value.size(); i++){
  //   cout << value[i] << " ";
  // }
  // cout << endl;
  // cout << value.size() << endl;
  // for(int i=0; i<row.size(); i++){
  //     cout << row[i] << " ";
  // }
  // cout << endl;
  // cout << row.size() << endl;
  // for(int i=0; i<col.size(); i++){
  // cout << col[i] << " ";
  // }
  // cout << endl;
  // cout << col.size() << endl;


  return 0;

}
