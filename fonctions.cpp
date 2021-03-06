#include "fonctions.hpp"

#include <math.h>

double f(double x,double y,double t, double Lx, double Ly, int mode){
  if(mode==1){
    return 2*(y-(y*y)+x-(x*x));
  }
  if(mode==2){
    return sin(x)+cos(y);
  }
  if(mode==3){
    return exp(-pow(x-(Lx/2),2))*exp(-pow(y-(Ly/2),2))*cos((2*atan(1))*t);
  }
}

// ------------------------------------------------

double g(double x,double y,int mode){
  if(mode==1){
      return 0;
  }
  if(mode==2){
    return sin(x)+cos(y);
  }
  if(mode==3){
      return 0;
  }
}

// ------------------------------------------------

double h(double x,double y,int mode){
  if(mode==1){
      return 0;
  }
  if(mode==2){
    return sin(x)+cos(y);
  }
  if(mode==3){
      return 1;
  }
}
