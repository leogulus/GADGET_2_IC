#!/bin/bash


#
# i merger with each initial disk replaced by a spheroid
#
#./CombineGalaxies ../MakeNewDisk/vc3spheroid.dat 0 0 ../MakeNewDisk/vc3c.dat 71 30 5.0 100.0 /raid4/tcox/ICs/vc3vc3i_s1.dat
#./CombineGalaxies ../MakeNewDisk/vc3c.dat 0 0 ../MakeNewDisk/vc3spheroid.dat 71 30 5.0 100.0 /raid4/tcox/ICs/vc3vc3i_s2.dat


#
# now, the kdc remnant + other stuff
#
#./CombineGalaxies /raid4/tcox/vc3vc3i/snapshot_030 0 0 ../MakeNewDisk/vc3c.dat 71 30 5.0 100.0 /raid4/tcox/ICs/vc3vc3i_rem1.dat
#./CombineGalaxies /raid4/tcox/vc3vc3i/snapshot_030 0 0 ../MakeNewDisk/vc3spheroid.dat 71 30 5.0 100.0 /raid4/tcox/ICs/vc3vc3i_rem2.dat

#./CombineGalaxies /raid4/tcox/vc3vc3i/snapshot_030 0 0 /raid4/tcox/vc3vc3i/snapshot_030 71 30 5.0 100.0 /raid4/tcox/ICs/vc3vc3i_rem3.dat
#./CombineGalaxies /raid4/tcox/vc3vc3i/snapshot_030 0 0 /raid4/tcox/vc3vc3i/snapshot_030  0  0 5.0 100.0 /raid4/tcox/ICs/vc3vc3i_rem4.dat


# "bad" remergers, in the sense that the IC was evolved with the bad/poor
# integration accuracy
#./CombineGalaxies /raid4/tcox/bs/b2e/snapshot_030 0 0 /raid4/tcox/bs/b3e/snapshot_030 71 30 5.0 140.0 /raid4/tcox/ICs/b2eb3e.dat
#./CombineGalaxies /raid4/tcox/bs/b3e/snapshot_030 0 0 /raid4/tcox/bs/b3e/snapshot_030 71 30 5.0 140.0 /raid4/tcox/ICs/b3eb3e.dat
#./CombineGalaxies /raid4/tcox/bs/b3e/snapshot_030 0 0 /raid4/tcox/bs/b4e/snapshot_030 71 30 5.0 140.0 /raid4/tcox/ICs/b3eb4e.dat
#./CombineGalaxies /raid4/tcox/bs/b4e/snapshot_030 0 0 /raid4/tcox/bs/b4e/snapshot_030 71 30 5.0 140.0 /raid4/tcox/ICs/b4eb4e.dat


#./CombineGalaxies /raid4/tcox/bs/b2e/snapshot_013 0 0 /raid4/tcox/bs/b3e/snapshot_013 71 30 5.0 140.0 /raid4/tcox/ICs/b2eb3e.dat
#./CombineGalaxies /raid4/tcox/bs/b3e/snapshot_013 0 0 /raid4/tcox/bs/b3e/snapshot_013 71 30 5.0 140.0 /raid4/tcox/ICs/b3eb3e.dat
#./CombineGalaxies /raid4/tcox/bs/b3e/snapshot_013 0 0 /raid4/tcox/bs/b4e/snapshot_013 71 30 5.0 140.0 /raid4/tcox/ICs/b3eb4e.dat
#./CombineGalaxies /raid4/tcox/bs/b4e/snapshot_013 0 0 /raid4/tcox/bs/b4e/snapshot_013 71 30 5.0 140.0 /raid4/tcox/ICs/b4eb4e.dat


#./CombineGalaxies /raid4/tcox/vc3vc3f/snapshot_013 0 0 /raid4/tcox/vc3vc3f/snapshot_013 0 0 5.0 140.0 /raid4/tcox/ICs/vc3fvc3f.dat
#./CombineGalaxies /raid4/tcox/vc3vc3f/snapshot_013 0 0 /raid4/tcox/vc3vc3f/snapshot_013 90 30 5.0 140.0 /raid4/tcox/ICs/vc3fvc3f_polar.dat

#./CombineGalaxies /raid4/tcox/vc3vc3m/snapshot_013 0 0 /raid4/tcox/vc3vc3m/snapshot_013 0 0 5.0 140.0 /raid4/tcox/ICs/vc3mvc3m.dat
#./CombineGalaxies /raid4/tcox/vc3vc3m/snapshot_013 0 0 /raid4/tcox/vc3vc3m/snapshot_013 90 30 5.0 140.0 /raid4/tcox/ICs/vc3mvc3m_polar.dat


#./CombineGalaxies /raid4/tcox/vc3vc3c/snapshot_013  40  40 /raid4/tcox/vc3vc3o/snapshot_013 -30   0 5.0 140.0 /raid4/tcox/ICs/vc3cvc3o.dat
#./CombineGalaxies /raid4/tcox/vc3vc3h/snapshot_013  70 -40 /raid4/tcox/vc3vc3k/snapshot_013 180 -50 5.0 140.0 /raid4/tcox/ICs/vc3hvc3k.dat
#./CombineGalaxies /raid4/tcox/vc3vc3m/snapshot_013 -20  70 /raid4/tcox/vc3vc3e/snapshot_013  45  10 5.0 140.0 /raid4/tcox/ICs/vc3mvc3e.dat
#./CombineGalaxies /raid4/tcox/vc3vc3j/snapshot_013  60  20 /raid4/tcox/vc3vc3o/snapshot_013  90  10 5.0 140.0 /raid4/tcox/ICs/vc3jvc3o.dat


#./CombineGalaxies /raid4/tcox/vc3vc3h/snapshot_013  40  40 /raid4/tcox/vc3vc3h/snapshot_013 -30   0 5.0 140.0 /raid4/tcox/ICs/vc3hvc3h_1.dat
#./CombineGalaxies /raid4/tcox/vc3vc3h/snapshot_013  70 -40 /raid4/tcox/vc3vc3h/snapshot_013 180 -50 5.0 140.0 /raid4/tcox/ICs/vc3hvc3h_2.dat
#./CombineGalaxies /raid4/tcox/vc3vc3h/snapshot_013 -20  70 /raid4/tcox/vc3vc3h/snapshot_013  45  10 5.0 140.0 /raid4/tcox/ICs/vc3hvc3h_3.dat
#./CombineGalaxies /raid4/tcox/vc3vc3h/snapshot_013  60  20 /raid4/tcox/vc3vc3h/snapshot_013  90  10 5.0 140.0 /raid4/tcox/ICs/vc3hvc3h_4.dat
#./CombineGalaxies /raid4/tcox/vc3vc3h/snapshot_013   0   0 /raid4/tcox/vc3vc3h/snapshot_013   0   0 5.0 140.0 /raid4/tcox/ICs/vc3hvc3h_5.dat


# now a few gas fraction ones

#./CombineGalaxies /raid4/tcox/zs/z3f/snapshot_013 0 0 /raid4/tcox/zs/z3f/snapshot_013  0  0 5.0 140.0 /raid4/tcox/ICs/z3fz3f.dat
#./CombineGalaxies /raid4/tcox/zs/z3f/snapshot_013 0 0 /raid4/tcox/zs/z3f/snapshot_013 90 30 5.0 140.0 /raid4/tcox/ICs/z3fz3f_polar.dat
#
#./CombineGalaxies /raid4/tcox/zs/z3m/snapshot_013 0 0 /raid4/tcox/zs/z3m/snapshot_013  0  0 5.0 140.0 /raid4/tcox/ICs/z3mz3m.dat
#./CombineGalaxies /raid4/tcox/zs/z3m/snapshot_013 0 0 /raid4/tcox/zs/z3m/snapshot_013 90 30 5.0 140.0 /raid4/tcox/ICs/z3mz3m_polar.dat

#./CombineGalaxies /raid4/tcox/zs/z3h/snapshot_013 0 0 /raid4/tcox/zs/z3h/snapshot_013  0  0 5.0 140.0 /raid4/tcox/ICs/z3hz3h.dat
#./CombineGalaxies /raid4/tcox/zs/z3h/snapshot_013 0 0 /raid4/tcox/zs/z3h/snapshot_013 90 30 5.0 140.0 /raid4/tcox/ICs/z3hz3h_polar.dat



#./CombineGalaxies /raid4/tcox/es/e2e_i1/snapshot_018 0 0 /raid4/tcox/es/e2e_i1/snapshot_018 30 90 5.0 120.0 /raid4/tcox/ICs/e2ee2e.dat
#./CombineGalaxies /raid4/tcox/es/e2k_i1/snapshot_018 0 0 /raid4/tcox/es/e2k_i1/snapshot_018 30 90 5.0 120.0 /raid4/tcox/ICs/e2ke2k.dat
#
#./CombineGalaxies /raid4/tcox/es/e3e_i1/snapshot_018 0 0 /raid4/tcox/es/e3e_i1/snapshot_018 30 90 5.0 140.0 /raid4/tcox/ICs/e3ee3e.dat
#./CombineGalaxies /raid4/tcox/es/e3k_i1/snapshot_018 0 0 /raid4/tcox/es/e3e_i1/snapshot_018 30 90 5.0 140.0 /raid4/tcox/ICs/e3ke3e.dat
#./CombineGalaxies /raid4/tcox/es/e3k_i1/snapshot_018 0 0 /raid4/tcox/es/e3k_i1/snapshot_018 30 90 5.0 140.0 /raid4/tcox/ICs/e3ke3k.dat
#
#./CombineGalaxies /raid4/tcox/es/e4e_i1/snapshot_018 0 0 /raid4/tcox/es/e4e_i1/snapshot_018 30 90 5.0 180.0 /raid4/tcox/ICs/e4ee4e.dat
#./CombineGalaxies /raid4/tcox/es/e4k_i1/snapshot_018 0 0 /raid4/tcox/es/e4k_i1/snapshot_018 30 90 5.0 180.0 /raid4/tcox/ICs/e4ke4k.dat


# ./CombineGalaxies /n/home/tcox/data/bs/b2e/snapshot_018 0 0 /n/home/tcox/data/bs/b2e/snapshot_018 30 90 5.0 140.0 /n/home/tcox/data/ICs/b2eb2e.dat
# ./CombineGalaxies /n/home/tcox/data/bs/b2e/snapshot_018 0 0 /n/home/tcox/data/bs/b2k/snapshot_018 30 90 5.0 140.0 /n/home/tcox/data/ICs/b2eb2k.dat
# ./CombineGalaxies /n/home/tcox/data/bs/b2e/snapshot_018 0 0 /n/home/tcox/data/bs/b2h/snapshot_018 30 90 5.0 140.0 /n/home/tcox/data/ICs/b2eb2h.dat

# ./CombineGalaxies /n/home/tcox/data/bs/b3e/snapshot_018 0 0 /n/home/tcox/data/bs/b3e/snapshot_018 30 90 5.0 180.0 /n/home/tcox/data/ICs/b3eb3e.dat
# ./CombineGalaxies /n/home/tcox/data/bs/b3e/snapshot_018 0 0 /n/home/tcox/data/bs/b3f/snapshot_018 30 90 5.0 180.0 /n/home/tcox/data/ICs/b3eb3f.dat
# ./CombineGalaxies /n/home/tcox/data/bs/b3e/snapshot_018 0 0 /n/home/tcox/data/bs/b3k/snapshot_018 30 90 5.0 180.0 /n/home/tcox/data/ICs/b3eb3k.dat
# ./CombineGalaxies /n/home/tcox/data/bs/b3e/snapshot_018 0 0 /n/home/tcox/data/bs/b3h/snapshot_018 30 90 5.0 180.0 /n/home/tcox/data/ICs/b3eb3h.dat

./CombineGalaxies /n/home/tcox/data/bs/b4e/snapshot_018 0 0 /n/home/tcox/data/bs/b3e/snapshot_018 30 90 5.0 220.0 /n/home/tcox/data/ICs/b4eb3e.dat
./CombineGalaxies /n/home/tcox/data/bs/b4e/snapshot_018 0 0 /n/home/tcox/data/bs/b4e/snapshot_018 30 90 5.0 220.0 /n/home/tcox/data/ICs/b4eb4e.dat
# ./CombineGalaxies /n/home/tcox/data/bs/b4e/snapshot_018 0 0 /n/home/tcox/data/bs/b4e/snapshot_018 30 90 5.0 220.0 /n/home/tcox/data/ICs/b4eb4e.dat
# ./CombineGalaxies /n/home/tcox/data/bs/b4e/snapshot_018 0 0 /n/home/tcox/data/bs/b4k/snapshot_018 30 90 5.0 220.0 /n/home/tcox/data/ICs/b4eb4k.dat
# ./CombineGalaxies /n/home/tcox/data/bs/b4f/snapshot_018 0 0 /n/home/tcox/data/bs/b4h/snapshot_018 30 90 5.0 220.0 /n/home/tcox/data/ICs/b4fb4h.dat



