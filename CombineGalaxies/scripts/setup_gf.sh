#!/bin/bash


#  h
# ---
#./CombineGalaxies ../MakeNewDisk/vc3u.dat 0 0 ../MakeNewDisk/vc3u.dat 0 0 5.0 100.0 ../ICs/vc3vc3u_h.dat
#./CombineGalaxies ../MakeNewDisk/vc3v.dat 0 0 ../MakeNewDisk/vc3v.dat 0 0 5.0 100.0 ../ICs/vc3vc3v_h.dat
#./CombineGalaxies ../MakeNewDisk/vc3w.dat 0 0 ../MakeNewDisk/vc3w.dat 0 0 5.0 100.0 ../ICs/vc3vc3w_h.dat
#./CombineGalaxies ../MakeNewDisk/vc3x2.dat 0 0 ../MakeNewDisk/vc3x2.dat 0 0 5.0 100.0 ../ICs/vc3vc3x2_h.dat
#./CombineGalaxies ../MakeNewDisk/vc3y.dat 0 0 ../MakeNewDisk/vc3y.dat 0 0 5.0 100.0 ../ICs/vc3vc3y_h.dat
#./CombineGalaxies ../MakeNewDisk/vc3z.dat 0 0 ../MakeNewDisk/vc3z.dat 0 0 5.0 100.0 ../ICs/vc3vc3z_h.dat

#  k
# ---
#./CombineGalaxies ../MakeNewDisk/vc3u.dat -109 -30 ../MakeNewDisk/vc3u.dat 71 -30 5.0 100.0 ../ICs/vc3vc3u_k.dat
#./CombineGalaxies ../MakeNewDisk/vc3v.dat -109 -30 ../MakeNewDisk/vc3v.dat 71 -30 5.0 100.0 ../ICs/vc3vc3v_k.dat
#./CombineGalaxies ../MakeNewDisk/vc3w.dat -109 -30 ../MakeNewDisk/vc3w.dat 71 -30 5.0 100.0 ../ICs/vc3vc3w_k.dat
#./CombineGalaxies ../MakeNewDisk/vc3x2.dat -109 -30 ../MakeNewDisk/vc3x2.dat 71 -30 5.0 100.0 ../ICs/vc3vc3x2_k.dat
#./CombineGalaxies ../MakeNewDisk/vc3y.dat -109 -30 ../MakeNewDisk/vc3y.dat 71 -30 5.0 100.0 ../ICs/vc3vc3y_k.dat
#./CombineGalaxies ../MakeNewDisk/vc3z.dat -109 -30 ../MakeNewDisk/vc3z.dat 71 -30 5.0 100.0 ../ICs/vc3vc3z_k.dat

#  e
# ---
#./CombineGalaxies ../MakeNewDisk/vc3u.dat 30 60 ../MakeNewDisk/vc3u.dat -30 45 5.0 100.0 ../ICs/vc3vc3u_e.dat
#./CombineGalaxies ../MakeNewDisk/vc3v.dat 30 60 ../MakeNewDisk/vc3v.dat -30 45 5.0 100.0 ../ICs/vc3vc3v_e.dat
#./CombineGalaxies ../MakeNewDisk/vc3w.dat 30 60 ../MakeNewDisk/vc3w.dat -30 45 5.0 100.0 ../ICs/vc3vc3w_e.dat
#./CombineGalaxies ../MakeNewDisk/vc3x2.dat 30 60 ../MakeNewDisk/vc3x2.dat -30 45 5.0 100.0 ../ICs/vc3vc3x2_e.dat
#./CombineGalaxies ../MakeNewDisk/vc3y.dat 30 60 ../MakeNewDisk/vc3y.dat -30 45 5.0 100.0 ../ICs/vc3vc3y_e.dat
#./CombineGalaxies ../MakeNewDisk/vc3z.dat 30 60 ../MakeNewDisk/vc3z.dat -30 45 5.0 100.0 ../ICs/vc3vc3z_e.dat

#  f
# ---
#./CombineGalaxies ../MakeNewDisk/vc/vc3u.dat 60 60 ../MakeNewDisk/vc/vc3u.dat 150 0  5.0 100.0 /raid4/tcox/ICs/vc/vc3vc3u_f.dat
#./CombineGalaxies ../MakeNewDisk/vc/vc3v.dat 60 60 ../MakeNewDisk/vc/vc3v.dat 150 0  5.0 100.0 /raid4/tcox/ICs/vc/vc3vc3v_f.dat
#./CombineGalaxies ../MakeNewDisk/vc/vc3w.dat 60 60 ../MakeNewDisk/vc/vc3w.dat 150 0  5.0 100.0 /raid4/tcox/ICs/vc/vc3vc3w_f.dat
#./CombineGalaxies ../MakeNewDisk/vc/vc3x2.dat 60 60 ../MakeNewDisk/vc/vc3x2.dat 150 0  5.0 100.0 /raid4/tcox/ICs/vc/vc3vc3x2_f.dat
#./CombineGalaxies ../MakeNewDisk/vc/vc3y.dat 60 60 ../MakeNewDisk/vc/vc3y.dat 150 0  5.0 100.0 /raid4/tcox/ICs/vc/vc3vc3y_f.dat
#./CombineGalaxies ../MakeNewDisk/vc/vc3z.dat 60 60 ../MakeNewDisk/vc/vc3z.dat 150 0  5.0 100.0 /raid4/tcox/ICs/vc/vc3vc3z_f.dat


# new as of 8/13/07

#  80% gas fraction
# --------------------
#./CombineGalaxies ../MakeNewDisk/vc3v.dat    0   0 ../MakeNewDisk/vc3v.dat   0   0  5.0 100.0 /raid4/tcox/ICs/b3h.dat
#./CombineGalaxies ../MakeNewDisk/vc3v.dat  180   0 ../MakeNewDisk/vc3v.dat   0   0  5.0 100.0 /raid4/tcox/ICs/b3b.dat
 ./CombineGalaxies ../MakeNewDisk/vc3v.dat  180   0 ../MakeNewDisk/vc3v.dat 180   0  5.0 100.0 /raid4/tcox/ICs/b3c.dat
 ./CombineGalaxies ../MakeNewDisk/vc3v.dat   90   0 ../MakeNewDisk/vc3v.dat   0   0  5.0 100.0 /raid4/tcox/ICs/b3d.dat
#./CombineGalaxies ../MakeNewDisk/vc3v.dat   30  60 ../MakeNewDisk/vc3v.dat -30  45  5.0 100.0 /raid4/tcox/ICs/b3e.dat
#./CombineGalaxies ../MakeNewDisk/vc3v.dat   60  60 ../MakeNewDisk/vc3v.dat 150   0  5.0 100.0 /raid4/tcox/ICs/b3f.dat
#./CombineGalaxies ../MakeNewDisk/vc3v.dat  100   0 ../MakeNewDisk/vc3v.dat -30  45  5.0 100.0 /raid4/tcox/ICs/b3g.dat

 ./CombineGalaxies ../MakeNewDisk/vc3v.dat    0   0 ../MakeNewDisk/vc3v.dat   71  30  5.0 100.0 /raid4/tcox/ICs/b3i.dat
 ./CombineGalaxies ../MakeNewDisk/vc3v.dat -109  90 ../MakeNewDisk/vc3v.dat   71  90  5.0 100.0 /raid4/tcox/ICs/b3j.dat
#./CombineGalaxies ../MakeNewDisk/vc3v.dat -109 -30 ../MakeNewDisk/vc3v.dat   71 -30  5.0 100.0 /raid4/tcox/ICs/b3k.dat
#./CombineGalaxies ../MakeNewDisk/vc3v.dat -109  30 ../MakeNewDisk/vc3v.dat  180   0  5.0 100.0 /raid4/tcox/ICs/b3l.dat
 ./CombineGalaxies ../MakeNewDisk/vc3v.dat    0   0 ../MakeNewDisk/vc3v.dat   71  90  5.0 100.0 /raid4/tcox/ICs/b3m.dat
#./CombineGalaxies ../MakeNewDisk/vc3v.dat -109 -30 ../MakeNewDisk/vc3v.dat   71  30  5.0 100.0 /raid4/tcox/ICs/b3n.dat
 ./CombineGalaxies ../MakeNewDisk/vc3v.dat -109  30 ../MakeNewDisk/vc3v.dat   71 -30  5.0 100.0 /raid4/tcox/ICs/b3o.dat
#./CombineGalaxies ../MakeNewDisk/vc3v.dat -109  90 ../MakeNewDisk/vc3v.dat  180   0  5.0 100.0 /raid4/tcox/ICs/b3p.dat


#  60% gas fraction
# --------------------
#./CombineGalaxies ../MakeNewDisk/vc3w.dat    0   0 ../MakeNewDisk/vc3w.dat   0   0  5.0 100.0 /raid4/tcox/ICs/c3h.dat
 ./CombineGalaxies ../MakeNewDisk/vc3w.dat  180   0 ../MakeNewDisk/vc3w.dat   0   0  5.0 100.0 /raid4/tcox/ICs/c3b.dat
 ./CombineGalaxies ../MakeNewDisk/vc3w.dat  180   0 ../MakeNewDisk/vc3w.dat 180   0  5.0 100.0 /raid4/tcox/ICs/c3c.dat
 ./CombineGalaxies ../MakeNewDisk/vc3w.dat   90   0 ../MakeNewDisk/vc3w.dat   0   0  5.0 100.0 /raid4/tcox/ICs/c3d.dat
#./CombineGalaxies ../MakeNewDisk/vc3w.dat   30  60 ../MakeNewDisk/vc3w.dat -30  45  5.0 100.0 /raid4/tcox/ICs/c3e.dat
#./CombineGalaxies ../MakeNewDisk/vc3w.dat   60  60 ../MakeNewDisk/vc3w.dat 150   0  5.0 100.0 /raid4/tcox/ICs/c3f.dat
 ./CombineGalaxies ../MakeNewDisk/vc3w.dat  100   0 ../MakeNewDisk/vc3w.dat -30  45  5.0 100.0 /raid4/tcox/ICs/c3g.dat

#./CombineGalaxies ../MakeNewDisk/vc3w.dat    0   0 ../MakeNewDisk/vc3w.dat   71  30  5.0 100.0 /raid4/tcox/ICs/c3i.dat
#./CombineGalaxies ../MakeNewDisk/vc3w.dat -109  90 ../MakeNewDisk/vc3w.dat   71  90  5.0 100.0 /raid4/tcox/ICs/c3j.dat
#./CombineGalaxies ../MakeNewDisk/vc3w.dat -109 -30 ../MakeNewDisk/vc3w.dat   71 -30  5.0 100.0 /raid4/tcox/ICs/c3k.dat
 ./CombineGalaxies ../MakeNewDisk/vc3w.dat -109  30 ../MakeNewDisk/vc3w.dat  180   0  5.0 100.0 /raid4/tcox/ICs/c3l.dat
#./CombineGalaxies ../MakeNewDisk/vc3w.dat    0   0 ../MakeNewDisk/vc3w.dat   71  90  5.0 100.0 /raid4/tcox/ICs/c3m.dat
 ./CombineGalaxies ../MakeNewDisk/vc3w.dat -109 -30 ../MakeNewDisk/vc3w.dat   71  30  5.0 100.0 /raid4/tcox/ICs/c3n.dat
 ./CombineGalaxies ../MakeNewDisk/vc3w.dat -109  30 ../MakeNewDisk/vc3w.dat   71 -30  5.0 100.0 /raid4/tcox/ICs/c3o.dat
 ./CombineGalaxies ../MakeNewDisk/vc3w.dat -109  90 ../MakeNewDisk/vc3w.dat  180   0  5.0 100.0 /raid4/tcox/ICs/c3p.dat





#  20% gas fraction
# --------------------
#./CombineGalaxies ../MakeNewDisk/vc3y.dat    0   0 ../MakeNewDisk/vc3y.dat   0   0  5.0 100.0 /raid4/tcox/ICs/e3h.dat
#./CombineGalaxies ../MakeNewDisk/vc3y.dat  180   0 ../MakeNewDisk/vc3y.dat   0   0  5.0 100.0 /raid4/tcox/ICs/e3b.dat
 ./CombineGalaxies ../MakeNewDisk/vc3y.dat  180   0 ../MakeNewDisk/vc3y.dat 180   0  5.0 100.0 /raid4/tcox/ICs/e3c.dat
 ./CombineGalaxies ../MakeNewDisk/vc3y.dat   90   0 ../MakeNewDisk/vc3y.dat   0   0  5.0 100.0 /raid4/tcox/ICs/e3d.dat
#./CombineGalaxies ../MakeNewDisk/vc3y.dat   30  60 ../MakeNewDisk/vc3y.dat -30  45  5.0 100.0 /raid4/tcox/ICs/e3e.dat
#./CombineGalaxies ../MakeNewDisk/vc3y.dat   60  60 ../MakeNewDisk/vc3y.dat 150   0  5.0 100.0 /raid4/tcox/ICs/e3f.dat
#./CombineGalaxies ../MakeNewDisk/vc3y.dat  100   0 ../MakeNewDisk/vc3y.dat -30  45  5.0 100.0 /raid4/tcox/ICs/e3g.dat

 ./CombineGalaxies ../MakeNewDisk/vc3y.dat    0   0 ../MakeNewDisk/vc3y.dat   71  30  5.0 100.0 /raid4/tcox/ICs/e3i.dat
 ./CombineGalaxies ../MakeNewDisk/vc3y.dat -109  90 ../MakeNewDisk/vc3y.dat   71  90  5.0 100.0 /raid4/tcox/ICs/e3j.dat
#./CombineGalaxies ../MakeNewDisk/vc3y.dat -109 -30 ../MakeNewDisk/vc3y.dat   71 -30  5.0 100.0 /raid4/tcox/ICs/e3k.dat
#./CombineGalaxies ../MakeNewDisk/vc3y.dat -109  30 ../MakeNewDisk/vc3y.dat  180   0  5.0 100.0 /raid4/tcox/ICs/e3l.dat
 ./CombineGalaxies ../MakeNewDisk/vc3y.dat    0   0 ../MakeNewDisk/vc3y.dat   71  90  5.0 100.0 /raid4/tcox/ICs/e3m.dat
#./CombineGalaxies ../MakeNewDisk/vc3y.dat -109 -30 ../MakeNewDisk/vc3y.dat   71  30  5.0 100.0 /raid4/tcox/ICs/e3n.dat
 ./CombineGalaxies ../MakeNewDisk/vc3y.dat -109  30 ../MakeNewDisk/vc3y.dat   71 -30  5.0 100.0 /raid4/tcox/ICs/e3o.dat
#./CombineGalaxies ../MakeNewDisk/vc3y.dat -109  90 ../MakeNewDisk/vc3y.dat  180   0  5.0 100.0 /raid4/tcox/ICs/e3p.dat



#  5% gas fraction
# --------------------
#./CombineGalaxies ../MakeNewDisk/vc3z.dat    0   0 ../MakeNewDisk/vc3z.dat   0   0  5.0 100.0 /raid4/tcox/ICs/z3h.dat
#./CombineGalaxies ../MakeNewDisk/vc3z.dat  180   0 ../MakeNewDisk/vc3z.dat   0   0  5.0 100.0 /raid4/tcox/ICs/z3b.dat
#./CombineGalaxies ../MakeNewDisk/vc3z.dat  180   0 ../MakeNewDisk/vc3z.dat 180   0  5.0 100.0 /raid4/tcox/ICs/z3c.dat
#./CombineGalaxies ../MakeNewDisk/vc3z.dat   90   0 ../MakeNewDisk/vc3z.dat   0   0  5.0 100.0 /raid4/tcox/ICs/z3d.dat
#./CombineGalaxies ../MakeNewDisk/vc3z.dat   30  60 ../MakeNewDisk/vc3z.dat -30  45  5.0 100.0 /raid4/tcox/ICs/z3e.dat
#./CombineGalaxies ../MakeNewDisk/vc3z.dat   60  60 ../MakeNewDisk/vc3z.dat 150   0  5.0 100.0 /raid4/tcox/ICs/z3f.dat
#./CombineGalaxies ../MakeNewDisk/vc3z.dat  100   0 ../MakeNewDisk/vc3z.dat -30  45  5.0 100.0 /raid4/tcox/ICs/z3g.dat

#./CombineGalaxies ../MakeNewDisk/vc3z.dat    0   0 ../MakeNewDisk/vc3z.dat   71  30  5.0 100.0 /raid4/tcox/ICs/z3i.dat
#./CombineGalaxies ../MakeNewDisk/vc3z.dat -109  90 ../MakeNewDisk/vc3z.dat   71  90  5.0 100.0 /raid4/tcox/ICs/z3j.dat
#./CombineGalaxies ../MakeNewDisk/vc3z.dat -109 -30 ../MakeNewDisk/vc3z.dat   71 -30  5.0 100.0 /raid4/tcox/ICs/z3k.dat
#./CombineGalaxies ../MakeNewDisk/vc3z.dat -109  30 ../MakeNewDisk/vc3z.dat  180   0  5.0 100.0 /raid4/tcox/ICs/z3l.dat
#./CombineGalaxies ../MakeNewDisk/vc3z.dat    0   0 ../MakeNewDisk/vc3z.dat   71  90  5.0 100.0 /raid4/tcox/ICs/z3m.dat
#./CombineGalaxies ../MakeNewDisk/vc3z.dat -109 -30 ../MakeNewDisk/vc3z.dat   71  30  5.0 100.0 /raid4/tcox/ICs/z3n.dat
#./CombineGalaxies ../MakeNewDisk/vc3z.dat -109  30 ../MakeNewDisk/vc3z.dat   71 -30  5.0 100.0 /raid4/tcox/ICs/z3o.dat
#./CombineGalaxies ../MakeNewDisk/vc3z.dat -109  90 ../MakeNewDisk/vc3z.dat  180   0  5.0 100.0 /raid4/tcox/ICs/z3p.dat








