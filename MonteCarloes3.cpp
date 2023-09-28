{
  TRandom3 rnd;
  rnd.SetSeed(12345678);
  
  double nacc = 0.0; //numero eventi accettati
  double R=1;
  int ntot =100000;

  for (int i=0;i<ntot;i++){
    double x = rnd.Rndm()*2-1;
    double y = rnd.Rndm()*2-1;
    double z = rnd.Rndm()*2-1;
    double r = sqrt(x*x+y*y+z*z);
    if(r<R && r>R/2){
      nacc++;
  }
  }
  cout <<pow(2*R,3)*(nacc/ntot) <<endl;
  // cout <<(4/3)*TMath::Pi()*pow(R,3) <<endl; Volume teorico

}
