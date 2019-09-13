#!/bin/bash


echo " " 
echo " " 
echo "-------------------------------------"
echo " These were our first trials. "
echo " They seemed to have too slow an initial radial velocity."
echo " "
#./CombineGalaxies ../MakeNewDisk/mw.dat 0 0 ../MakeNewDisk/m31.dat 80 15 315.0 546.0 0.494 test.dat
#./CombineGalaxies ../MakeNewDisk/mw.dat 0 0 ../MakeNewDisk/m31.dat 80 15 315.0 546.0 0.55  test.dat
#./CombineGalaxies ../MakeNewDisk/mw.dat 0 0 ../MakeNewDisk/m31.dat 80 15 350.0 546.0 0.6   test.dat



echo " " 
echo " " 
echo "-------------------------------------"
echo " Trial #2"
echo " These look much better."
echo " "
#./CombineGalaxies ../MakeNewDisk/mw.dat 0 0 ../MakeNewDisk/m31.dat 80 15 115.0 546.0 0.80 test.dat
#./CombineGalaxies ../MakeNewDisk/mw.dat 0 0 ../MakeNewDisk/m31.dat 80 15 115.0 546.0 0.825  test.dat
#./CombineGalaxies ../MakeNewDisk/mw.dat 0 0 ../MakeNewDisk/m31.dat 80 15 150.0 546.0 0.875   localgals_now1.dat



echo " " 
echo " " 
echo "-------------------------------------"
echo " Trial #3"
echo " Now try to find a different R_peri's."
echo " "
#./CombineGalaxies ../MakeNewDisk/mw.dat 0 0 ../MakeNewDisk/m31.dat 80 15 285.0 546.0 0.90 test.dat
#./CombineGalaxies ../MakeNewDisk/mw.dat 0 0 ../MakeNewDisk/m31.dat 80 15 285.0 546.0 0.925  test.dat
./CombineGalaxies ../MakeNewDisk/mw.dat 0 0 ../MakeNewDisk/m31.dat 80 15 285.0 546.0 0.975   localgals_now2.dat

