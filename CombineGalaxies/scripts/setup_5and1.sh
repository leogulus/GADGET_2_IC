#!/bin/bash


#./CombineGalaxies ../MakeNewDisk/vc3x.dat 0 0 ../MakeNewDisk/vc3x.dat 0 0 5.0 100.0 ../ICs/vc3vc3x_h.dat
#./CombineGalaxies ../MakeNewDisk/vc3x.dat -109 -30 ../MakeNewDisk/vc3x.dat 71 -30 5.0 100.0 ../ICs/vc3vc3x_k.dat
#./CombineGalaxies ../MakeNewDisk/vc3x.dat 30 60 ../MakeNewDisk/vc3x.dat -30 45 5.0 100.0 ../ICs/vc3vc3x_e.dat


# this is the first go round, which mainly led to
# many of these galaxies taking a long time to merge.
#
#./CombineGalaxies ../MakeNewDisk/vc3x.dat 30 30 ../MakeNewDisk/vc1.5.dat 0 0 5.0 100.0 ../ICs/vc3I.dat
#./CombineGalaxies ../MakeNewDisk/vc1.5.dat 0 0 ../ICs/vc3I.dat 0 0 20.0 120.0 ../ICs/vc3II.dat
#./CombineGalaxies ../MakeNewDisk/vc1.5.dat 0 0 ../ICs/vc3II.dat 120 90 40.0 150.0 ../ICs/vc3III.dat
#./CombineGalaxies ../ICs/vc3III.dat -120 0 ../MakeNewDisk/vc1.5.dat 0 0 10.0 200.0 ../ICs/vc3IV.dat
#./CombineGalaxies ../ICs/vc3IV.dat 180 90 ../MakeNewDisk/vc1.5.dat 0 0 50.0 300.0 ../ICs/vc3V.dat



# on the second go round we'll reduce the orbital energy by
# changing the eccentricity on several of these orbits
#
./CombineGalaxies ../MakeNewDisk/vc/vc3x.dat 30 30 ../MakeNewDisk/vc/vc1.5.dat 0 0 10.0 100.0 0.9 ../ICs/vc3I.dat
./CombineGalaxies ../MakeNewDisk/vc/vc1.5.dat 0 0 ../ICs/vc3I.dat 0 0 20.0 120.0 0.8 ../ICs/vc3II.dat
./CombineGalaxies ../MakeNewDisk/vc/vc1.5.dat 0 0 ../ICs/vc3II.dat 120 90 30.0 150.0 0.7 ../ICs/vc3III.dat
./CombineGalaxies ../ICs/vc3III.dat -120 0 ../MakeNewDisk/vc/vc1.5.dat 0 0 50.0 200.0 0.65 ../ICs/vc3IV.dat
./CombineGalaxies ../ICs/vc3IV.dat 180 90 ../MakeNewDisk/vc/vc1.5.dat 0 0 70.0 250.0 0.6 ../ICs/vc3V.dat



