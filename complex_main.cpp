#include <iostream>
#include "complex.h"

using namespace std;

int main(){
  
  complex a(10,3);
  complex b(3,-2);
  
  complex prod = a*b;
  complex sum = a+b;
  complex diff = a-b;
  complex Con_a = a.Con();

  cout<<"Somma = " <<sum <<endl;
  cout<<"Differenza = " <<diff <<endl;
  cout<<"Prodotto = " <<prod <<endl;
  cout<<"Coniugato di a " <<Con_a <<endl;
  
return 0;

}
