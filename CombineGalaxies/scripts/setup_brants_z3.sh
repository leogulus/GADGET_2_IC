#!/bin/bash


#  h
# ---
# _h, _e (trial 1)
#./CombineGalaxies ../MakeNewDisk/z3_brant_v3g2q1.dat 0 0 ../MakeNewDisk/z3_brant_v3g2q1.dat 0 0 1.830812 22.4168125 /raid4/tcox/ICs/z3_brant_v3g2q1_h.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v3g2q1.dat 30 60 ../MakeNewDisk/z3_brant_v3g2q1.dat -30 45 1.830812 22.4168125 /raid4/tcox/ICs/z3_brant_v3g2q1_e.dat

# _h2 (trial 2)
# now, with orbit correction
#./CombineGalaxies ../MakeNewDisk/z3_brant_v3g2q1.dat 0 0 ../MakeNewDisk/z3_brant_v3g2q1.dat 0 0 1.830812 22.4168125 /raid4/tcox/ICs/z3_brant_v3g2q1_h2.dat

# _h3 (trial 3)
# now, with orbit correction & without disks having double concentration scaling
#./CombineGalaxies ../MakeNewDisk/z3_brant_v3g2q1_2.dat 0 0 ../MakeNewDisk/z3_brant_v3g2q1_2.dat 0 0 1.830812 22.4168125 /raid4/tcox/ICs/z3_brant_v3g2q1_h3.dat



# From here down, they are all like _h3, i.e., they
# have orbit corrections and the disks are properly
# scaling concentration with redshift.

#./CombineGalaxies ../MakeNewDisk/z3_brant_v4g2q1.dat 0 0 ../MakeNewDisk/z3_brant_v4g2q1.dat 0 0 2.716720 31.6636875 /raid4/tcox/ICs/z3_brant_v4g2q1_h.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v5g2q1.dat 0 0 ../MakeNewDisk/z3_brant_v5g2q1.dat 0 0 4.032040 44.8335625 /raid4/tcox/ICs/z3_brant_v5g2q1_h.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v6g2q1.dat 0 0 ../MakeNewDisk/z3_brant_v6g2q1.dat 0 0 6.666668 70.0525000 /raid4/tcox/ICs/z3_brant_v6g2q1_h.dat

#./CombineGalaxies ../MakeNewDisk/z3_brant_v3g1q1.dat 0 0 ../MakeNewDisk/z3_brant_v3g1q1.dat 0 0 1.830812 22.4168125 /raid4/tcox/ICs/z3_brant_v3g1q1_h.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v4g1q1.dat 0 0 ../MakeNewDisk/z3_brant_v4g1q1.dat 0 0 2.716720 31.6636875 /raid4/tcox/ICs/z3_brant_v4g1q1_h.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v5g1q1.dat 0 0 ../MakeNewDisk/z3_brant_v5g1q1.dat 0 0 4.032040 44.8335625 /raid4/tcox/ICs/z3_brant_v5g1q1_h.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v6g1q1.dat 0 0 ../MakeNewDisk/z3_brant_v6g1q1.dat 0 0 6.666668 70.0525000 /raid4/tcox/ICs/z3_brant_v6g1q1_h.dat


#  e
# ---

# updates from v1
#./CombineGalaxies ../MakeNewDisk/z3_brant_v3g2q1_2.dat 30 60 ../MakeNewDisk/z3_brant_v3g2q1_2.dat -30 45 1.830812 22.4168125 /raid4/tcox/ICs/z3_brant_v3g2q1_e2.dat

#./CombineGalaxies ../MakeNewDisk/z3_brant_v4g2q1.dat 30 60 ../MakeNewDisk/z3_brant_v4g2q1.dat -30 45 2.716720 31.6636875 /raid4/tcox/ICs/z3_brant_v4g2q1_e.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v5g2q1.dat 30 60 ../MakeNewDisk/z3_brant_v5g2q1.dat -30 45 4.032040 44.8335625 /raid4/tcox/ICs/z3_brant_v5g2q1_e.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v6g2q1.dat 30 60 ../MakeNewDisk/z3_brant_v6g2q1.dat -30 45 6.666668 70.0525000 /raid4/tcox/ICs/z3_brant_v6g2q1_e.dat

#./CombineGalaxies ../MakeNewDisk/z3_brant_v3g1q1.dat 30 60 ../MakeNewDisk/z3_brant_v3g1q1.dat -30 45 1.830812 22.4168125 /raid4/tcox/ICs/z3_brant_v3g1q1_e.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v4g1q1.dat 30 60 ../MakeNewDisk/z3_brant_v4g1q1.dat -30 45 2.716720 31.6636875 /raid4/tcox/ICs/z3_brant_v4g1q1_e.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v5g1q1.dat 30 60 ../MakeNewDisk/z3_brant_v5g1q1.dat -30 45 4.032040 44.8335625 /raid4/tcox/ICs/z3_brant_v5g1q1_e.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v6g1q1.dat 30 60 ../MakeNewDisk/z3_brant_v6g1q1.dat -30 45 6.666668 70.0525000 /raid4/tcox/ICs/z3_brant_v6g1q1_e.dat


#  f
# ---
#./CombineGalaxies ../MakeNewDisk/z3_brant_v3g2q1_2.dat 60 60 ../MakeNewDisk/z3_brant_v3g2q1_2.dat 150 0 1.830812 22.4168125 /raid4/tcox/ICs/z3_brant_v3g2q1_f.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v4g2q1.dat 60 60 ../MakeNewDisk/z3_brant_v4g2q1.dat 150 0 2.716720 31.6636875 /raid4/tcox/ICs/z3_brant_v4g2q1_f.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v5g2q1.dat 60 60 ../MakeNewDisk/z3_brant_v5g2q1.dat 150 0 4.032040 44.8335625 /raid4/tcox/ICs/z3_brant_v5g2q1_f.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v6g2q1.dat 60 60 ../MakeNewDisk/z3_brant_v6g2q1.dat 150 0 6.666668 70.0525000 /raid4/tcox/ICs/z3_brant_v6g2q1_f.dat

#./CombineGalaxies ../MakeNewDisk/z3_brant_v3g1q1.dat 60 60 ../MakeNewDisk/z3_brant_v3g1q1.dat 150 0 1.830812 22.4168125 /raid4/tcox/ICs/z3_brant_v3g1q1_f.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v4g1q1.dat 60 60 ../MakeNewDisk/z3_brant_v4g1q1.dat 150 0 2.716720 31.6636875 /raid4/tcox/ICs/z3_brant_v4g1q1_f.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v5g1q1.dat 60 60 ../MakeNewDisk/z3_brant_v5g1q1.dat 150 0 4.032040 44.8335625 /raid4/tcox/ICs/z3_brant_v5g1q1_f.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v6g1q1.dat 60 60 ../MakeNewDisk/z3_brant_v6g1q1.dat 150 0 6.666668 70.0525000 /raid4/tcox/ICs/z3_brant_v6g1q1_f.dat


#  k
# ---
#./CombineGalaxies ../MakeNewDisk/z3_brant_v3g2q1_2.dat -109 -30 ../MakeNewDisk/z3_brant_v3g2q1_2.dat 71 -30 1.830812 22.4168125 /raid4/tcox/ICs/z3_brant_v3g2q1_k.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v4g2q1.dat -109 -30 ../MakeNewDisk/z3_brant_v4g2q1.dat 71 -30 2.716720 31.6636875 /raid4/tcox/ICs/z3_brant_v4g2q1_k.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v5g2q1.dat -109 -30 ../MakeNewDisk/z3_brant_v5g2q1.dat 71 -30 4.032040 44.8335625 /raid4/tcox/ICs/z3_brant_v5g2q1_k.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v6g2q1.dat -109 -30 ../MakeNewDisk/z3_brant_v6g2q1.dat 71 -30 6.666668 70.0525000 /raid4/tcox/ICs/z3_brant_v6g2q1_k.dat

#./CombineGalaxies ../MakeNewDisk/z3_brant_v6g2q1.dat -109 -30 ../MakeNewDisk/z3_brant_v6g2q1.dat 71 -30 6.666668 150.0  /raid4/tcox/ICs/z3_brant_v6g2q1_k1.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v6g2q1.dat -109 -30 ../MakeNewDisk/z3_brant_v6g2q1.dat 71 -30 6.666668 120.0  /raid4/tcox/ICs/z3_brant_v6g2q1_k2.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v6g2q1.dat -109 -30 ../MakeNewDisk/z3_brant_v6g2q1.dat 71 -30 15.0  120.0  /raid4/tcox/ICs/z3_brant_v6g2q1_k3.dat

# turn off orbit correction
#./CombineGalaxies ../MakeNewDisk/z3_brant_v6g2q1.dat -109 -30 ../MakeNewDisk/z3_brant_v6g2q1.dat 71 -30 6.666668 150.0  /raid4/tcox/ICs/z3_brant_v6g2q1_k4.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v6g2q1.dat -109 -30 ../MakeNewDisk/z3_brant_v6g2q1.dat 71 -30 6.666668 120.0  /raid4/tcox/ICs/z3_brant_v6g2q1_k5.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v6g2q1.dat -109 -30 ../MakeNewDisk/z3_brant_v6g2q1.dat 71 -30 15.0  120.0  /raid4/tcox/ICs/z3_brant_v6g2q1_k6.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v6g2q1.dat -109 -30 ../MakeNewDisk/z3_brant_v6g2q1.dat 71 -30 6.666668 70.0525000 /raid4/tcox/ICs/z3_brant_v6g2q1_k7.dat # this is the "standard" orbit


#./CombineGalaxies ../MakeNewDisk/z3_brant_v3g1q1.dat -109 -30 ../MakeNewDisk/z3_brant_v3g1q1.dat 71 -30 1.830812 22.4168125 /raid4/tcox/ICs/z3_brant_v3g1q1_k.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v4g1q1.dat -109 -30 ../MakeNewDisk/z3_brant_v4g1q1.dat 71 -30 2.716720 31.6636875 /raid4/tcox/ICs/z3_brant_v4g1q1_k.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v5g1q1.dat -109 -30 ../MakeNewDisk/z3_brant_v5g1q1.dat 71 -30 4.032040 44.8335625 /raid4/tcox/ICs/z3_brant_v5g1q1_k.dat
#./CombineGalaxies ../MakeNewDisk/z3_brant_v6g1q1.dat -109 -30 ../MakeNewDisk/z3_brant_v6g1q1.dat 71 -30 6.666668 70.0525000 /raid4/tcox/ICs/z3_brant_v6g1q1_k.dat



#
# newest ones: test a few things differently then before
#
#

#
# exactly the same as before
#
./CombineGalaxies ../MakeNewDisk/z3_brant_v6g2q1.dat 30 60 ../MakeNewDisk/z3_brant_v6g2q1.dat -30 45 6.666668 70.0525000 /odyssey/tcox/CombineGalaxies/z3_brant_v6g2q1_e.dat

#
# actually this is similar, but we make the SFR timescale much longer
#
#./CombineGalaxies ../MakeNewDisk/z3_brant_v6v1g2q1.dat 30 60 ../MakeNewDisk/z3_brant_v6v1g2q1.dat -30 45 6.666668 70.0525000 /odyssey/tcox/CombineGalaxies/z3_brant_v6v1g2q1_e.dat

#
# actually this is similar, but we make the SFR timescale much longer
#
#./CombineGalaxies ../MakeNewDisk/z3_brant_v6v2g2q1.dat 30 60 ../MakeNewDisk/z3_brant_v6v2g2q1.dat -30 45 6.666668 70.0525000 /odyssey/tcox/CombineGalaxies/z3_brant_v6v2g2q1_e.dat







