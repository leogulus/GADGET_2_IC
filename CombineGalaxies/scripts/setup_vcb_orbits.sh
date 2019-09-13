#!/bin/bash


#  same as previous 40%'ers, but with a bulge
# ---------------------------------------------

./CombineGalaxies ../MakeNewDisk/vc3c_bulge.dat    0   0 ../MakeNewDisk/vc3c_bulge.dat   0   0 5.0 100.0 /raid4/tcox/ICs/vc3vc3h_bulge.dat
./CombineGalaxies ../MakeNewDisk/vc3c_bulge.dat   30  60 ../MakeNewDisk/vc3c_bulge.dat -30  45 5.0 100.0 /raid4/tcox/ICs/vc3vc3e_bulge.dat
./CombineGalaxies ../MakeNewDisk/vc3c_bulge.dat   60  60 ../MakeNewDisk/vc3c_bulge.dat 150   0 5.0 100.0 /raid4/tcox/ICs/vc3vc3f_bulge.dat
./CombineGalaxies ../MakeNewDisk/vc3c_bulge.dat -109 -30 ../MakeNewDisk/vc3c_bulge.dat  71 -30 5.0 100.0 /raid4/tcox/ICs/vc3vc3k_bulge.dat



