#!/bin/bash


#  mm1
# -----
# ./CombineGalaxies ../MakeNewDisk/vc3c.dat  30  60 ../MakeNewDisk/vc3c.dat -30 45 5.0 100.0 multi_a.dat
# ./CombineGalaxies ../MakeNewDisk/vc3c.dat  45  20 multi_a.dat  180  30  10.0  120.0   multi_b.dat
# ./CombineGalaxies multi_b.dat  100 10  ../MakeNewDisk/vc3c.dat  180  0  30.0  140.0   multi_c.dat
# ./CombineGalaxies ../MakeNewDisk/vc3c.dat  30  60 multi_c.dat   30  60   3.0  180.0   multi_5x.dat


#  mm2
# -----
#./CombineGalaxies multi_a.dat  45  20  multi_a.dat  120  30  20.0  140.0   multi_mm2.dat



#  mm3
# -----
# ./CombineGalaxies ../MakeNewDisk/vc3c.dat  60  60 ../MakeNewDisk/vc3c.dat 150 0 5.0 100.0 multi_3a.dat
# ./CombineGalaxies multi_3a.dat  45  20  multi_3a.dat  120  30  20.0  140.0   multi_mm3.dat


#  mm4
# -----
# ./CombineGalaxies ../MakeNewDisk/vc3c.dat  45  60 ../MakeNewDisk/vc3c.dat 115 0  25.0 150.0 multi_4a.dat
# ./CombineGalaxies multi_4a.dat  145  20  multi_4a.dat  90  80  5.0  200.0   multi_mm4.dat


#  mm5
# -----
# ./CombineGalaxies ../MakeNewDisk/vc3c.dat  60  60 ../MakeNewDisk/vc3c.dat 45 50  15.0 150.0 multi_5a.dat
# ./CombineGalaxies ../MakeNewDisk/vc3c.dat  45  -60 ../MakeNewDisk/vc3c.dat 165 -20  35.0 150.0 multi_5b.dat
# ./CombineGalaxies multi_5a.dat  125  70  multi_5b.dat  120 10  5.0  160.0   multi_5c.dat
# ./CombineGalaxies multi_5c.dat  25  20  multi_5c.dat  90 75  2.0  250.0   multi_mm5.dat


#  mm6
# -----
 ./CombineGalaxies multi_3a.dat  45  20  multi_3a.dat  120  30  60.0  140.0   multi_mm6.dat

#  mm7
# -----
 ./CombineGalaxies multi_3a.dat  45  20  multi_3a.dat  120  30   5.0  140.0   multi_mm7.dat

#  mm8
# -----
 ./CombineGalaxies multi_3a.dat  45  20  multi_3a.dat  -60  30  20.0  140.0   multi_mm8.dat



