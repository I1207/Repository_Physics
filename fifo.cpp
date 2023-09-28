#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

//Implementare una fifo
//['''']
//10000
//''''
//12345
//62345

class fifo:public vector<double>{
public:
  fifo(int n=0):vector<double>(n),m_ind(0){} //costruttore
  double at(unsigned int i);
  void add(double x);
private:
  int m_ind; //Nuovo elemento da riempire
  int m_n;
};

double fifo::at(unsigned int i){
  double val;
  if(m_n<size()){
    val= (*this)[i];
      }
  else{
    val= (*this)[(m_ind+i)%size()];
  }
  return val;
}

void fifo::add(double val){
  if(m_ind==size())
    m_ind -= size();
    (*this)[m_ind++] = val;
  if(m_n != size())  m_n++;
}

int main(){
  fifo f(5);
  for(int i=1;i<=20;i++){
    cout<<"------" <<endl;
    f.add(i);
    for(unsigned int j=0;j<5;j++){
      cout<<f[j]<<"  "<<endl;
    }
    cout<<endl;
  }
 
  return 0;
}
