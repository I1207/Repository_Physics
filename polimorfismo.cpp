#include <cmath>
#include <iostream>
#include <TVector2.h>
#include <vector>


using namespace std;

class poligono{
public:
  poligono(){};
  poligono(const vector <TVector2>& punti):m_punti(punti){};
  double perimetro();
  virtual double area() = 0;
protected:
  vector<TVector2> m_punti;
};

double poligono::perimetro(){
  double val=0;
  for(int i = 1;i<m_punti.size();i++){
    val += (m_punti[i]-m_punti[i-1]).Mod();
  }
  val += (m_punti[0]-m_punti[m_punti.size()-1]).Mod();
  return val;
}

class triangolo:public poligono{
public:
  triangolo(TVector2 p1,TVector2 p2,TVector2 p3):poligono(){
    setlati(p1,p2,p3);
  }
  triangolo(double a,double b ,double c):poligono(){
    TVector2 p1(0,0);
    TVector2 p2(a,0);
    double theta = acos(a*a+b*b-c*c)/(2*a*b);
    TVector2 p3(c*cos(theta),c*sin(theta));
    setlati(p1,p2,p3);
  }
  void setlati(TVector2 p1,TVector2 p2,TVector2 p3){
    m_punti.push_back(p1);
    m_punti.push_back(p2);
    m_punti.push_back(p3);
  }
  double area(){
    return m_punti[1].X()*m_punti[2].Y()/2;
  }
};

int main(){
  triangolo t(1,1,1);
  cout<<"Il perimetro del triangolo scelto  vale "<<t.perimetro()<<endl;
  cout<<"L'area del triangolo scelto vale " <<t.area()<<endl;
  
}
