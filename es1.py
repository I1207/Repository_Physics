from ROOT import *
import math as m

rnd = TRandom3()
rnd.SetSeed(12345678)

ntot = 1000 #numero totale di eventi da generare
tau1 = 0.1
f= 0.3
tau2 = 1
tacc = 0.01


h = TH1D("h","",100,0,3)
hm = TH1D("hm","",100,0,3)

for i in range(0,ntot):
        tau = 0.0
        if rnd.Rndm()<f:
                tau = tau1
        else:
                tau = tau2
        t = -tau*m.log(1-rnd.Rndm())
        if rnd.Rndm()<(1-m.exp(-t/tacc)):
                hm.Fill(t)
        h.Fill(t)
h.Draw()
hm.Draw("SAME")
hm.SetLineColor(2)
gPad.Modified()
gPad.Update()
gApplication.Run(True)

