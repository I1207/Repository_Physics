#include <iostream>
#include <TRandom3.h>
#include <TMath.h>
#include <TVector3.h>

int main() {
  // Inizializza il generatore di numeri casuali TRandom3 e imposta il seme.
  TRandom3 rnd;
  rnd.SetSeed(12345678);

  // Inizializza le variabili per il conteggio degli eventi accettati.
  double nacc = 0.0; // Numero di eventi accettati per la condizione L/2
  double nacc2 = 0.0; // Numero di eventi accettati per la condizione L

  // Definizione del numero totale di eventi generati.
  int ntot = 100000;

  // Definizione dei parametri geometrici.
  double L = 0.01; // Lato del quadrato LxL
  double d = 0.2; // Distanza tra il punto di origine e il piano in cui vengono generati gli eventi

  // Ciclo attraverso gli eventi generati.
  for (int i = 0; i < ntot; i++) {
    // Genera angoli casuali sferici.
    double phi = 2 * TMath::Pi() * rnd.Rndm();
    double coseno = 2 * rnd.Rndm() - 1;
    double theta = acos(coseno);

    // Verifica se theta è maggiore di 90 gradi (pi/2).
    if (theta > TMath::Pi() / 2) {
      // Calcola il vettore direzione v.
      TVector3 vers(sin(theta) * cos(phi), sin(theta) * sin(phi), cos(theta));
      double alpha = d / cos(theta); // Distanza tra il punto di origine e il piano generatore.

      // Calcola il vettore v come prodotto di alpha e vers.
      TVector3 v = alpha * vers;

      // Verifica se v è all'interno del quadrato di lato L/2.
      if (abs(v.X()) < L / 2 && abs(v.Y()) < L / 2)
        nacc++;

      // Verifica se v è all'interno del quadrato di lato L.
      if (v.X() > 0 && v.X() < L && v.Y() > 0 && v.Y() < L)
        nacc2++;
    }
  }

  // Calcola le frazioni di eventi accettati.
  double p = nacc / ntot;
  double ep = sqrt(p * (1 - p) / ntot);
  double p2 = nacc2 / ntot;
  double ep2 = sqrt(p2 * (1 - p2) / ntot);

  // Stampa i risultati.
  std::cout << "Fraction of events accepted for L/2: " << p << " +- " << ep << std::endl;
  std::cout << "Fraction of events accepted for L: " << p2 << " +- " << ep2 << std::endl;

  // Calcola e stampa il valore atteso della frazione di eventi accettati per L/2.
  std::cout << "Expected fraction for L/2: " << L * L / (4 * TMath::Pi() * d * d) << std::endl;

  return 0;
}
