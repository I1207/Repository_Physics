#ifndef _COMPLEX
#define _COMPLEX

#include "TVector2.h"

class complex: public TVector2{
  
 public:

 using TVector2::TVector2;
 complex(TVector2 v):TVector2(v){};
 complex Con();
 complex operator*(const complex &f)const;
  
  };

std::ostream& operator<<(std::ostream& o, complex& );

#endif

