#!/bin/bash


#
# 
#
DATADIR="/raid6/gbesla/MW-LMC/runs/grid2/parabolic2/B/"

echo "making (soft) duplicate directory to: $DATADIR"

FILELIST="E  Sa  Sb  Sc  Sd  Im"


for DFILE in $FILELIST
do
        ln -s $DATADIR$DFILE $DFILE
        ./CombineGalaxies ../MakeNewDisk/vc3spheroid.dat 0 0 ../MakeNewDisk/vc3c.dat 71 30 5.0 100.0 /raid4/tcox/ICs/vc3vc3i_s1.dat
        # echo "ln -s $DATADIR$DFILE $DFILE"
done



# -----------------------------------------------
echo "done"





./CombineGalaxies ../MakeNewDisk/vc3spheroid.dat 0 0 ../MakeNewDisk/vc3c.dat 71 30 5.0 100.0 /raid4/tcox/ICs/vc3vc3i_s1.dat
./CombineGalaxies ../MakeNewDisk/vc3c.dat 0 0 ../MakeNewDisk/vc3spheroid.dat 71 30 5.0 100.0 /raid4/tcox/ICs/vc3vc3i_s2.dat






