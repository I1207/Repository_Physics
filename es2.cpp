{

  TRandom3 rnd;
  rnd.SetSeed(12345678);
  double nacc = 0.0;
  double nacc2 = 0.0;
  int ntot = 100000;
  double L = 0.01;
  double d = 0.2;
  for (int i=0;i<ntot;i++){
    double phi = 2*TMath::Pi()*rnd.Rndm();
    double coseno = 2*rnd.Rndm()-1;
    double theta = acos(coseno);
    if(theta > TMath::Pi()/2){
      TVector3 vers(sin(theta)*cos(phi),sin(theta)*sin(phi),cos(theta));
      double alpha = d/(cos(theta)); //d/vers.Z()
      TVector3 v =alpha*vers;
      if (abs(v.X())<L/2 && abs(v.Y())<L/2)
	nacc++;
      if (v.X() > 0 && v.X() <L && v.Y()>0 && v.Y()<L)
	nacc2++;
    }
    }

  double p = nacc/ntot;
  double ep = sqrt(p*(1-p)/ntot);
  double p2 = nacc2/ntot;
  double ep2 = sqrt(p*(1-p)/ntot);
  cout <<p<<" +- " <<ep<<endl;
  cout <<p2<<" +- " <<ep2<<endl;
  
  cout<<L*L/(4*TMath::Pi()*d*d) <<endl;

}
