# Importa il modulo ROOT e il modulo math per utilizzare le funzioni e le classi necessarie.
from ROOT import *
import math as m

# Inizializza un generatore di numeri casuali TRandom3 e imposta il seme.
rnd = TRandom3()
rnd.SetSeed(12345678)

# Definizione del numero totale di eventi da generare.
ntot = 1000

# Definizione dei parametri per la generazione degli eventi.
tau1 = 0.1  # Tempo di vita 1
f = 0.3  # Frazione degli eventi con tau1
tau2 = 1  # Tempo di vita 2
tacc = 0.01  # Tempo di accettazione

# Creazione di due istanze di istogrammi TH1D.
h = TH1D("h", "", 100, 0, 3)  # Istogramma principale
hm = TH1D("hm", "", 100, 0, 3)  # Istogramma per gli eventi accettati

# Ciclo attraverso la generazione degli eventi.
for i in range(0, ntot):
    tau = 0.0

    # Genera casualmente un valore di tau1 o tau2 in base alla frazione f.
    if rnd.Rndm() < f:
        tau = tau1
    else:
        tau = tau2

    # Genera un tempo di decadimento t da una distribuzione esponenziale.
    t = -tau * m.log(1 - rnd.Rndm())

    # Verifica se l'evento viene accettato in base a una certa probabilità.
    if rnd.Rndm() < (1 - m.exp(-t / tacc)):
        hm.Fill(t)  # Aggiunge il tempo t all'istogramma degli eventi accettati.
    h.Fill(t)  # Aggiunge il tempo t all'istogramma principale.

# Disegna l'istogramma principale.
h.Draw()

# Disegna l'istogramma degli eventi accettati sopra quello principale.
hm.Draw("SAME")

# Imposta il colore dell'istogramma degli eventi accettati a blu.
hm.SetLineColor(2)

# Aggiorna la visualizzazione del canvas.
gPad.Modified()
gPad.Update()

# Esegue l'applicazione per visualizzare il risultato.
gApplication.Run(True)
