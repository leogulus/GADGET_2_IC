#!/bin/bash


#
#./CombineGalaxies ../MakeNewDisk/z3_a6.dat 0 0 ../MakeNewDisk/z3_a6.dat 0 0 6.7 80.0 ./z3_a6_merger.dat
#./CombineGalaxies ../MakeNewDisk/z3_a6.dat 0 0 ../MakeNewDisk/z3_a6.dat 0 0 6.7 50.0 ./z3_a6_merger2.dat
#./CombineGalaxies ../MakeNewDisk/z3_a6.dat 0 0 ../MakeNewDisk/z3_a6.dat 0 0 6.7 100.0 ./z3_a6_merger3.dat


#./CombineGalaxies ../MakeNewDisk/z3_a4.5.dat 30 60 ../MakeNewDisk/z3_a4.5.dat -30 45 3.6 50.0 ./z3_a4.5_merger_e.dat
#./CombineGalaxies ../MakeNewDisk/z3_a6.dat 30 60 ../MakeNewDisk/z3_a6.dat -30 45 6.7 80.0 ./z3_a6_merger_e.dat

#./CombineGalaxies ../MakeNewDisk/z3_a4.5_eg.dat 0 0 ../MakeNewDisk/z3_a4.5_eg.dat 0 0 3.6 50.0 ./z3_a4.5_eg_merger_h.dat
#./CombineGalaxies ../MakeNewDisk/z3_a4.5_eg.dat 30 60 ../MakeNewDisk/z3_a4.5_eg.dat -30 45 3.6 50.0 ./z3_a4.5_eg_merger_e.dat

#./CombineGalaxies ../MakeNewDisk/z6_a6.dat 0 0 ../MakeNewDisk/z6_a6.dat 0 0 3.0 50.0 ./z6_a6_hmerger.dat
#./CombineGalaxies ../MakeNewDisk/z6_a7.dat 0 0 ../MakeNewDisk/z6_a7.dat 0 0 3.0 50.0 ./z6_a7_hmerger.dat

# z=5 mergers to test the z=4.5 observations
#./CombineGalaxies ../MakeNewDisk/z5_jy.dat 0 0 ../MakeNewDisk/z5_jy_2.dat 0 0 1.0 50.0 ./z5_jy_mergerA.dat
#./CombineGalaxies ../MakeNewDisk/z5_jy.dat 0 0 ../MakeNewDisk/z5_jy_2.dat 0 0 4.0 50.0 ./z5_jy_mergerB.dat

./CombineGalaxies /raid5/jyounger/GADGET_RUNS/MakeNewDisk/z5_jyfg0.4.dat  80 0 /raid5/jyounger/GADGET_RUNS/MakeNewDisk/z5_jyfg0.4_2.dat 110 0 1.0 50.0 ./z5_jyfg0.4_mergerC.dat
./CombineGalaxies /raid5/jyounger/GADGET_RUNS/MakeNewDisk/z5_jyfg0.4.dat 180 0 /raid5/jyounger/GADGET_RUNS/MakeNewDisk/z5_jyfg0.4_2.dat 180 0 1.0 50.0 ./z5_jyfg0.4_mergerD.dat



