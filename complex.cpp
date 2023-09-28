#include "complex.h"
#include "TVector2.h"
#include <iostream>
#include <cmath>

using namespace std;

//L'operazione di somma e di sottrazione rimane invariata per la classe dei numeri complessi : TVector2 me li fornisce già

complex complex::operator*(const complex &f)const{

  return complex (fX * f.X() - fY * f.Y(), fY * f.X() + fX * f.Y());
  
}

complex complex::Con(){
  
  double val = -fY;
  complex c(fX,val);
  
  return c;
  
}

std::ostream &operator<<(std::ostream &stream, complex &p ){

  if (p.Y() >= 0 )
    stream << '(' <<p.X() << "+i" <<p.Y() <<')' <<endl;
  else
    stream<< '(' <<p.X() << "-i" <<p.Y()*(-1) <<')' <<endl;

    return stream;
};







