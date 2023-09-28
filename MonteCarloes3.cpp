{
  // Inizializza il generatore di numeri casuali TRandom3 e imposta il seme.
  TRandom3 rnd;
  rnd.SetSeed(12345678);
  
  // Inizializza una variabile per il conteggio degli eventi accettati.
  double nacc = 0.0; // Numero di eventi accettati

  // Definizione del raggio della sfera.
  double R = 1;

  // Definizione del numero totale di eventi generati.
  int ntot = 100000;

  // Ciclo attraverso gli eventi generati.
  for (int i = 0; i < ntot; i++) {
    // Genera coordinate casuali in un cubo centrato nell'origine.
    double x = rnd.Rndm() * 2 - 1;
    double y = rnd.Rndm() * 2 - 1;
    double z = rnd.Rndm() * 2 - 1;

    // Calcola la distanza dall'origine (la norma del vettore (x, y, z)).
    double r = sqrt(x * x + y * y + z * z);

    // Verifica se il punto è all'interno di una sfera di raggio R ma fuori da una sfera di raggio R/2.
    if (r < R && r > R / 2) {
      nacc++; // Incrementa il conteggio degli eventi accettati.
    }
  }

  // Calcola e stampa il volume stimato della regione accettata.
  cout << pow(2 * R, 3) * (nacc / ntot) << endl;
  // cout << (4/3) * TMath::Pi() * pow(R, 3) << endl; // Volume teorico di una sfera di raggio R
}
