(define (problem n37)
    (:domain colored-balls)
    (:objects p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 p11 p12 p13 p14 p15 p16 p17 p18 p19 p20 p21 p22 p23 p24 p25 p26 p27 p28 p29 p30 p31 p32 p33 p34 p35 p36 p37 - pos)
    (:init
        (suc p1 p2) (suc p2 p3) (suc p3 p4) (suc p4 p5) (suc p5 p6) (suc p6 p7) (suc p7 p8) (suc p8 p9) (suc p9 p10) (suc p10 p11) (suc p11 p12) (suc p12 p13) (suc p13 p14) (suc p14 p15) (suc p15 p16) (suc p16 p17) (suc p17 p18) (suc p18 p19) (suc p19 p20) (suc p20 p21) (suc p21 p22) (suc p22 p23) (suc p23 p24) (suc p24 p25) (suc p25 p26) (suc p26 p27) (suc p27 p28) (suc p28 p29) (suc p29 p30) (suc p30 p31) (suc p31 p32) (suc p32 p33) (suc p33 p34) (suc p34 p35) (suc p35 p36) (suc p36 p37)
        (wall p2 p1) (wall p2 p2) (wall p2 p3) (wall p2 p4) (wall p2 p5) (wall p2 p6) (wall p2 p7) (wall p2 p8) (wall p2 p9) (wall p2 p10) (wall p2 p11) (wall p2 p12) (wall p2 p13) (wall p2 p14) (wall p2 p15) (wall p2 p16) (wall p2 p17) (wall p2 p18) (wall p2 p19) (wall p2 p20) (wall p2 p21) (wall p2 p22) (wall p2 p23) (wall p2 p24) (wall p2 p25) (wall p2 p26) (wall p2 p27) (wall p2 p28) (wall p2 p29) (wall p2 p30) (wall p2 p31) (wall p2 p32) (wall p2 p33) (wall p2 p34) (wall p2 p35) (wall p2 p36) (wall p2 p37)
        (wall p4 p1) (wall p4 p2) (wall p4 p3) (wall p4 p4) (wall p4 p5) (wall p4 p6) (wall p4 p7) (wall p4 p8) (wall p4 p9) (wall p4 p10) (wall p4 p11) (wall p4 p12) (wall p4 p13) (wall p4 p14) (wall p4 p15) (wall p4 p16) (wall p4 p17) (wall p4 p18) (wall p4 p19) (wall p4 p20) (wall p4 p21) (wall p4 p22) (wall p4 p23) (wall p4 p24) (wall p4 p25) (wall p4 p26) (wall p4 p27) (wall p4 p28) (wall p4 p29) (wall p4 p30) (wall p4 p31) (wall p4 p32) (wall p4 p33) (wall p4 p34) (wall p4 p35) (wall p4 p36) (wall p4 p37)
        (wall p6 p1) (wall p6 p2) (wall p6 p3) (wall p6 p4) (wall p6 p5) (wall p6 p6) (wall p6 p7) (wall p6 p8) (wall p6 p9) (wall p6 p10) (wall p6 p11) (wall p6 p12) (wall p6 p13) (wall p6 p14) (wall p6 p15) (wall p6 p16) (wall p6 p17) (wall p6 p18) (wall p6 p19) (wall p6 p20) (wall p6 p21) (wall p6 p22) (wall p6 p23) (wall p6 p24) (wall p6 p25) (wall p6 p26) (wall p6 p27) (wall p6 p28) (wall p6 p29) (wall p6 p30) (wall p6 p31) (wall p6 p32) (wall p6 p33) (wall p6 p34) (wall p6 p35) (wall p6 p36) (wall p6 p37)
        (wall p8 p1) (wall p8 p2) (wall p8 p3) (wall p8 p4) (wall p8 p5) (wall p8 p6) (wall p8 p7) (wall p8 p8) (wall p8 p9) (wall p8 p10) (wall p8 p11) (wall p8 p12) (wall p8 p13) (wall p8 p14) (wall p8 p15) (wall p8 p16) (wall p8 p17) (wall p8 p18) (wall p8 p19) (wall p8 p20) (wall p8 p21) (wall p8 p22) (wall p8 p23) (wall p8 p24) (wall p8 p25) (wall p8 p26) (wall p8 p27) (wall p8 p28) (wall p8 p29) (wall p8 p30) (wall p8 p31) (wall p8 p32) (wall p8 p33) (wall p8 p34) (wall p8 p35) (wall p8 p36) (wall p8 p37)
        (wall p10 p1) (wall p10 p2) (wall p10 p3) (wall p10 p4) (wall p10 p5) (wall p10 p6) (wall p10 p7) (wall p10 p8) (wall p10 p9) (wall p10 p10) (wall p10 p11) (wall p10 p12) (wall p10 p13) (wall p10 p14) (wall p10 p15) (wall p10 p16) (wall p10 p17) (wall p10 p18) (wall p10 p19) (wall p10 p20) (wall p10 p21) (wall p10 p22) (wall p10 p23) (wall p10 p24) (wall p10 p25) (wall p10 p26) (wall p10 p27) (wall p10 p28) (wall p10 p29) (wall p10 p30) (wall p10 p31) (wall p10 p32) (wall p10 p33) (wall p10 p34) (wall p10 p35) (wall p10 p36) (wall p10 p37)
        (wall p12 p1) (wall p12 p2) (wall p12 p3) (wall p12 p4) (wall p12 p5) (wall p12 p6) (wall p12 p7) (wall p12 p8) (wall p12 p9) (wall p12 p10) (wall p12 p11) (wall p12 p12) (wall p12 p13) (wall p12 p14) (wall p12 p15) (wall p12 p16) (wall p12 p17) (wall p12 p18) (wall p12 p19) (wall p12 p20) (wall p12 p21) (wall p12 p22) (wall p12 p23) (wall p12 p24) (wall p12 p25) (wall p12 p26) (wall p12 p27) (wall p12 p28) (wall p12 p29) (wall p12 p30) (wall p12 p31) (wall p12 p32) (wall p12 p33) (wall p12 p34) (wall p12 p35) (wall p12 p36) (wall p12 p37)
        (wall p14 p1) (wall p14 p2) (wall p14 p3) (wall p14 p4) (wall p14 p5) (wall p14 p6) (wall p14 p7) (wall p14 p8) (wall p14 p9) (wall p14 p10) (wall p14 p11) (wall p14 p12) (wall p14 p13) (wall p14 p14) (wall p14 p15) (wall p14 p16) (wall p14 p17) (wall p14 p18) (wall p14 p19) (wall p14 p20) (wall p14 p21) (wall p14 p22) (wall p14 p23) (wall p14 p24) (wall p14 p25) (wall p14 p26) (wall p14 p27) (wall p14 p28) (wall p14 p29) (wall p14 p30) (wall p14 p31) (wall p14 p32) (wall p14 p33) (wall p14 p34) (wall p14 p35) (wall p14 p36) (wall p14 p37)
        (wall p16 p1) (wall p16 p2) (wall p16 p3) (wall p16 p4) (wall p16 p5) (wall p16 p6) (wall p16 p7) (wall p16 p8) (wall p16 p9) (wall p16 p10) (wall p16 p11) (wall p16 p12) (wall p16 p13) (wall p16 p14) (wall p16 p15) (wall p16 p16) (wall p16 p17) (wall p16 p18) (wall p16 p19) (wall p16 p20) (wall p16 p21) (wall p16 p22) (wall p16 p23) (wall p16 p24) (wall p16 p25) (wall p16 p26) (wall p16 p27) (wall p16 p28) (wall p16 p29) (wall p16 p30) (wall p16 p31) (wall p16 p32) (wall p16 p33) (wall p16 p34) (wall p16 p35) (wall p16 p36) (wall p16 p37)
        (wall p18 p1) (wall p18 p2) (wall p18 p3) (wall p18 p4) (wall p18 p5) (wall p18 p6) (wall p18 p7) (wall p18 p8) (wall p18 p9) (wall p18 p10) (wall p18 p11) (wall p18 p12) (wall p18 p13) (wall p18 p14) (wall p18 p15) (wall p18 p16) (wall p18 p17) (wall p18 p18) (wall p18 p19) (wall p18 p20) (wall p18 p21) (wall p18 p22) (wall p18 p23) (wall p18 p24) (wall p18 p25) (wall p18 p26) (wall p18 p27) (wall p18 p28) (wall p18 p29) (wall p18 p30) (wall p18 p31) (wall p18 p32) (wall p18 p33) (wall p18 p34) (wall p18 p35) (wall p18 p36) (wall p18 p37)
        (wall p20 p1) (wall p20 p2) (wall p20 p3) (wall p20 p4) (wall p20 p5) (wall p20 p6) (wall p20 p7) (wall p20 p8) (wall p20 p9) (wall p20 p10) (wall p20 p11) (wall p20 p12) (wall p20 p13) (wall p20 p14) (wall p20 p15) (wall p20 p16) (wall p20 p17) (wall p20 p18) (wall p20 p19) (wall p20 p20) (wall p20 p21) (wall p20 p22) (wall p20 p23) (wall p20 p24) (wall p20 p25) (wall p20 p26) (wall p20 p27) (wall p20 p28) (wall p20 p29) (wall p20 p30) (wall p20 p31) (wall p20 p32) (wall p20 p33) (wall p20 p34) (wall p20 p35) (wall p20 p36) (wall p20 p37)
        (wall p22 p1) (wall p22 p2) (wall p22 p3) (wall p22 p4) (wall p22 p5) (wall p22 p6) (wall p22 p7) (wall p22 p8) (wall p22 p9) (wall p22 p10) (wall p22 p11) (wall p22 p12) (wall p22 p13) (wall p22 p14) (wall p22 p15) (wall p22 p16) (wall p22 p17) (wall p22 p18) (wall p22 p19) (wall p22 p20) (wall p22 p21) (wall p22 p22) (wall p22 p23) (wall p22 p24) (wall p22 p25) (wall p22 p26) (wall p22 p27) (wall p22 p28) (wall p22 p29) (wall p22 p30) (wall p22 p31) (wall p22 p32) (wall p22 p33) (wall p22 p34) (wall p22 p35) (wall p22 p36) (wall p22 p37)
        (wall p24 p1) (wall p24 p2) (wall p24 p3) (wall p24 p4) (wall p24 p5) (wall p24 p6) (wall p24 p7) (wall p24 p8) (wall p24 p9) (wall p24 p10) (wall p24 p11) (wall p24 p12) (wall p24 p13) (wall p24 p14) (wall p24 p15) (wall p24 p16) (wall p24 p17) (wall p24 p18) (wall p24 p19) (wall p24 p20) (wall p24 p21) (wall p24 p22) (wall p24 p23) (wall p24 p24) (wall p24 p25) (wall p24 p26) (wall p24 p27) (wall p24 p28) (wall p24 p29) (wall p24 p30) (wall p24 p31) (wall p24 p32) (wall p24 p33) (wall p24 p34) (wall p24 p35) (wall p24 p36) (wall p24 p37)
        (wall p26 p1) (wall p26 p2) (wall p26 p3) (wall p26 p4) (wall p26 p5) (wall p26 p6) (wall p26 p7) (wall p26 p8) (wall p26 p9) (wall p26 p10) (wall p26 p11) (wall p26 p12) (wall p26 p13) (wall p26 p14) (wall p26 p15) (wall p26 p16) (wall p26 p17) (wall p26 p18) (wall p26 p19) (wall p26 p20) (wall p26 p21) (wall p26 p22) (wall p26 p23) (wall p26 p24) (wall p26 p25) (wall p26 p26) (wall p26 p27) (wall p26 p28) (wall p26 p29) (wall p26 p30) (wall p26 p31) (wall p26 p32) (wall p26 p33) (wall p26 p34) (wall p26 p35) (wall p26 p36) (wall p26 p37)
        (wall p28 p1) (wall p28 p2) (wall p28 p3) (wall p28 p4) (wall p28 p5) (wall p28 p6) (wall p28 p7) (wall p28 p8) (wall p28 p9) (wall p28 p10) (wall p28 p11) (wall p28 p12) (wall p28 p13) (wall p28 p14) (wall p28 p15) (wall p28 p16) (wall p28 p17) (wall p28 p18) (wall p28 p19) (wall p28 p20) (wall p28 p21) (wall p28 p22) (wall p28 p23) (wall p28 p24) (wall p28 p25) (wall p28 p26) (wall p28 p27) (wall p28 p28) (wall p28 p29) (wall p28 p30) (wall p28 p31) (wall p28 p32) (wall p28 p33) (wall p28 p34) (wall p28 p35) (wall p28 p36) (wall p28 p37)
        (wall p30 p1) (wall p30 p2) (wall p30 p3) (wall p30 p4) (wall p30 p5) (wall p30 p6) (wall p30 p7) (wall p30 p8) (wall p30 p9) (wall p30 p10) (wall p30 p11) (wall p30 p12) (wall p30 p13) (wall p30 p14) (wall p30 p15) (wall p30 p16) (wall p30 p17) (wall p30 p18) (wall p30 p19) (wall p30 p20) (wall p30 p21) (wall p30 p22) (wall p30 p23) (wall p30 p24) (wall p30 p25) (wall p30 p26) (wall p30 p27) (wall p30 p28) (wall p30 p29) (wall p30 p30) (wall p30 p31) (wall p30 p32) (wall p30 p33) (wall p30 p34) (wall p30 p35) (wall p30 p36) (wall p30 p37)
        (wall p32 p1) (wall p32 p2) (wall p32 p3) (wall p32 p4) (wall p32 p5) (wall p32 p6) (wall p32 p7) (wall p32 p8) (wall p32 p9) (wall p32 p10) (wall p32 p11) (wall p32 p12) (wall p32 p13) (wall p32 p14) (wall p32 p15) (wall p32 p16) (wall p32 p17) (wall p32 p18) (wall p32 p19) (wall p32 p20) (wall p32 p21) (wall p32 p22) (wall p32 p23) (wall p32 p24) (wall p32 p25) (wall p32 p26) (wall p32 p27) (wall p32 p28) (wall p32 p29) (wall p32 p30) (wall p32 p31) (wall p32 p32) (wall p32 p33) (wall p32 p34) (wall p32 p35) (wall p32 p36) (wall p32 p37)
        (wall p34 p1) (wall p34 p2) (wall p34 p3) (wall p34 p4) (wall p34 p5) (wall p34 p6) (wall p34 p7) (wall p34 p8) (wall p34 p9) (wall p34 p10) (wall p34 p11) (wall p34 p12) (wall p34 p13) (wall p34 p14) (wall p34 p15) (wall p34 p16) (wall p34 p17) (wall p34 p18) (wall p34 p19) (wall p34 p20) (wall p34 p21) (wall p34 p22) (wall p34 p23) (wall p34 p24) (wall p34 p25) (wall p34 p26) (wall p34 p27) (wall p34 p28) (wall p34 p29) (wall p34 p30) (wall p34 p31) (wall p34 p32) (wall p34 p33) (wall p34 p34) (wall p34 p35) (wall p34 p36) (wall p34 p37)
        (wall p36 p1) (wall p36 p2) (wall p36 p3) (wall p36 p4) (wall p36 p5) (wall p36 p6) (wall p36 p7) (wall p36 p8) (wall p36 p9) (wall p36 p10) (wall p36 p11) (wall p36 p12) (wall p36 p13) (wall p36 p14) (wall p36 p15) (wall p36 p16) (wall p36 p17) (wall p36 p18) (wall p36 p19) (wall p36 p20) (wall p36 p21) (wall p36 p22) (wall p36 p23) (wall p36 p24) (wall p36 p25) (wall p36 p26) (wall p36 p27) (wall p36 p28) (wall p36 p29) (wall p36 p30) (wall p36 p31) (wall p36 p32) (wall p36 p33) (wall p36 p34) (wall p36 p35) (wall p36 p36) (wall p36 p37)
        (at p1 p19)
        (invariant (door p2 p1) (door p2 p2) (door p2 p3) (door p2 p4) (door p2 p5) (door p2 p6) (door p2 p7) (door p2 p8) (door p2 p9) (door p2 p10) (door p2 p11) (door p2 p12) (door p2 p13) (door p2 p14) (door p2 p15) (door p2 p16) (door p2 p17) (door p2 p18) (door p2 p19) (door p2 p20) (door p2 p21) (door p2 p22) (door p2 p23) (door p2 p24) (door p2 p25) (door p2 p26) (door p2 p27) (door p2 p28) (door p2 p29) (door p2 p30) (door p2 p31) (door p2 p32) (door p2 p33) (door p2 p34) (door p2 p35) (door p2 p36) (door p2 p37))
        (invariant (door p4 p1) (door p4 p2) (door p4 p3) (door p4 p4) (door p4 p5) (door p4 p6) (door p4 p7) (door p4 p8) (door p4 p9) (door p4 p10) (door p4 p11) (door p4 p12) (door p4 p13) (door p4 p14) (door p4 p15) (door p4 p16) (door p4 p17) (door p4 p18) (door p4 p19) (door p4 p20) (door p4 p21) (door p4 p22) (door p4 p23) (door p4 p24) (door p4 p25) (door p4 p26) (door p4 p27) (door p4 p28) (door p4 p29) (door p4 p30) (door p4 p31) (door p4 p32) (door p4 p33) (door p4 p34) (door p4 p35) (door p4 p36) (door p4 p37))
        (invariant (door p6 p1) (door p6 p2) (door p6 p3) (door p6 p4) (door p6 p5) (door p6 p6) (door p6 p7) (door p6 p8) (door p6 p9) (door p6 p10) (door p6 p11) (door p6 p12) (door p6 p13) (door p6 p14) (door p6 p15) (door p6 p16) (door p6 p17) (door p6 p18) (door p6 p19) (door p6 p20) (door p6 p21) (door p6 p22) (door p6 p23) (door p6 p24) (door p6 p25) (door p6 p26) (door p6 p27) (door p6 p28) (door p6 p29) (door p6 p30) (door p6 p31) (door p6 p32) (door p6 p33) (door p6 p34) (door p6 p35) (door p6 p36) (door p6 p37))
        (invariant (door p8 p1) (door p8 p2) (door p8 p3) (door p8 p4) (door p8 p5) (door p8 p6) (door p8 p7) (door p8 p8) (door p8 p9) (door p8 p10) (door p8 p11) (door p8 p12) (door p8 p13) (door p8 p14) (door p8 p15) (door p8 p16) (door p8 p17) (door p8 p18) (door p8 p19) (door p8 p20) (door p8 p21) (door p8 p22) (door p8 p23) (door p8 p24) (door p8 p25) (door p8 p26) (door p8 p27) (door p8 p28) (door p8 p29) (door p8 p30) (door p8 p31) (door p8 p32) (door p8 p33) (door p8 p34) (door p8 p35) (door p8 p36) (door p8 p37))
        (invariant (door p10 p1) (door p10 p2) (door p10 p3) (door p10 p4) (door p10 p5) (door p10 p6) (door p10 p7) (door p10 p8) (door p10 p9) (door p10 p10) (door p10 p11) (door p10 p12) (door p10 p13) (door p10 p14) (door p10 p15) (door p10 p16) (door p10 p17) (door p10 p18) (door p10 p19) (door p10 p20) (door p10 p21) (door p10 p22) (door p10 p23) (door p10 p24) (door p10 p25) (door p10 p26) (door p10 p27) (door p10 p28) (door p10 p29) (door p10 p30) (door p10 p31) (door p10 p32) (door p10 p33) (door p10 p34) (door p10 p35) (door p10 p36) (door p10 p37))
        (invariant (door p12 p1) (door p12 p2) (door p12 p3) (door p12 p4) (door p12 p5) (door p12 p6) (door p12 p7) (door p12 p8) (door p12 p9) (door p12 p10) (door p12 p11) (door p12 p12) (door p12 p13) (door p12 p14) (door p12 p15) (door p12 p16) (door p12 p17) (door p12 p18) (door p12 p19) (door p12 p20) (door p12 p21) (door p12 p22) (door p12 p23) (door p12 p24) (door p12 p25) (door p12 p26) (door p12 p27) (door p12 p28) (door p12 p29) (door p12 p30) (door p12 p31) (door p12 p32) (door p12 p33) (door p12 p34) (door p12 p35) (door p12 p36) (door p12 p37))
        (invariant (door p14 p1) (door p14 p2) (door p14 p3) (door p14 p4) (door p14 p5) (door p14 p6) (door p14 p7) (door p14 p8) (door p14 p9) (door p14 p10) (door p14 p11) (door p14 p12) (door p14 p13) (door p14 p14) (door p14 p15) (door p14 p16) (door p14 p17) (door p14 p18) (door p14 p19) (door p14 p20) (door p14 p21) (door p14 p22) (door p14 p23) (door p14 p24) (door p14 p25) (door p14 p26) (door p14 p27) (door p14 p28) (door p14 p29) (door p14 p30) (door p14 p31) (door p14 p32) (door p14 p33) (door p14 p34) (door p14 p35) (door p14 p36) (door p14 p37))
        (invariant (door p16 p1) (door p16 p2) (door p16 p3) (door p16 p4) (door p16 p5) (door p16 p6) (door p16 p7) (door p16 p8) (door p16 p9) (door p16 p10) (door p16 p11) (door p16 p12) (door p16 p13) (door p16 p14) (door p16 p15) (door p16 p16) (door p16 p17) (door p16 p18) (door p16 p19) (door p16 p20) (door p16 p21) (door p16 p22) (door p16 p23) (door p16 p24) (door p16 p25) (door p16 p26) (door p16 p27) (door p16 p28) (door p16 p29) (door p16 p30) (door p16 p31) (door p16 p32) (door p16 p33) (door p16 p34) (door p16 p35) (door p16 p36) (door p16 p37))
        (invariant (door p18 p1) (door p18 p2) (door p18 p3) (door p18 p4) (door p18 p5) (door p18 p6) (door p18 p7) (door p18 p8) (door p18 p9) (door p18 p10) (door p18 p11) (door p18 p12) (door p18 p13) (door p18 p14) (door p18 p15) (door p18 p16) (door p18 p17) (door p18 p18) (door p18 p19) (door p18 p20) (door p18 p21) (door p18 p22) (door p18 p23) (door p18 p24) (door p18 p25) (door p18 p26) (door p18 p27) (door p18 p28) (door p18 p29) (door p18 p30) (door p18 p31) (door p18 p32) (door p18 p33) (door p18 p34) (door p18 p35) (door p18 p36) (door p18 p37))
        (invariant (door p20 p1) (door p20 p2) (door p20 p3) (door p20 p4) (door p20 p5) (door p20 p6) (door p20 p7) (door p20 p8) (door p20 p9) (door p20 p10) (door p20 p11) (door p20 p12) (door p20 p13) (door p20 p14) (door p20 p15) (door p20 p16) (door p20 p17) (door p20 p18) (door p20 p19) (door p20 p20) (door p20 p21) (door p20 p22) (door p20 p23) (door p20 p24) (door p20 p25) (door p20 p26) (door p20 p27) (door p20 p28) (door p20 p29) (door p20 p30) (door p20 p31) (door p20 p32) (door p20 p33) (door p20 p34) (door p20 p35) (door p20 p36) (door p20 p37))
        (invariant (door p22 p1) (door p22 p2) (door p22 p3) (door p22 p4) (door p22 p5) (door p22 p6) (door p22 p7) (door p22 p8) (door p22 p9) (door p22 p10) (door p22 p11) (door p22 p12) (door p22 p13) (door p22 p14) (door p22 p15) (door p22 p16) (door p22 p17) (door p22 p18) (door p22 p19) (door p22 p20) (door p22 p21) (door p22 p22) (door p22 p23) (door p22 p24) (door p22 p25) (door p22 p26) (door p22 p27) (door p22 p28) (door p22 p29) (door p22 p30) (door p22 p31) (door p22 p32) (door p22 p33) (door p22 p34) (door p22 p35) (door p22 p36) (door p22 p37))
        (invariant (door p24 p1) (door p24 p2) (door p24 p3) (door p24 p4) (door p24 p5) (door p24 p6) (door p24 p7) (door p24 p8) (door p24 p9) (door p24 p10) (door p24 p11) (door p24 p12) (door p24 p13) (door p24 p14) (door p24 p15) (door p24 p16) (door p24 p17) (door p24 p18) (door p24 p19) (door p24 p20) (door p24 p21) (door p24 p22) (door p24 p23) (door p24 p24) (door p24 p25) (door p24 p26) (door p24 p27) (door p24 p28) (door p24 p29) (door p24 p30) (door p24 p31) (door p24 p32) (door p24 p33) (door p24 p34) (door p24 p35) (door p24 p36) (door p24 p37))
        (invariant (door p26 p1) (door p26 p2) (door p26 p3) (door p26 p4) (door p26 p5) (door p26 p6) (door p26 p7) (door p26 p8) (door p26 p9) (door p26 p10) (door p26 p11) (door p26 p12) (door p26 p13) (door p26 p14) (door p26 p15) (door p26 p16) (door p26 p17) (door p26 p18) (door p26 p19) (door p26 p20) (door p26 p21) (door p26 p22) (door p26 p23) (door p26 p24) (door p26 p25) (door p26 p26) (door p26 p27) (door p26 p28) (door p26 p29) (door p26 p30) (door p26 p31) (door p26 p32) (door p26 p33) (door p26 p34) (door p26 p35) (door p26 p36) (door p26 p37))
        (invariant (door p28 p1) (door p28 p2) (door p28 p3) (door p28 p4) (door p28 p5) (door p28 p6) (door p28 p7) (door p28 p8) (door p28 p9) (door p28 p10) (door p28 p11) (door p28 p12) (door p28 p13) (door p28 p14) (door p28 p15) (door p28 p16) (door p28 p17) (door p28 p18) (door p28 p19) (door p28 p20) (door p28 p21) (door p28 p22) (door p28 p23) (door p28 p24) (door p28 p25) (door p28 p26) (door p28 p27) (door p28 p28) (door p28 p29) (door p28 p30) (door p28 p31) (door p28 p32) (door p28 p33) (door p28 p34) (door p28 p35) (door p28 p36) (door p28 p37))
        (invariant (door p30 p1) (door p30 p2) (door p30 p3) (door p30 p4) (door p30 p5) (door p30 p6) (door p30 p7) (door p30 p8) (door p30 p9) (door p30 p10) (door p30 p11) (door p30 p12) (door p30 p13) (door p30 p14) (door p30 p15) (door p30 p16) (door p30 p17) (door p30 p18) (door p30 p19) (door p30 p20) (door p30 p21) (door p30 p22) (door p30 p23) (door p30 p24) (door p30 p25) (door p30 p26) (door p30 p27) (door p30 p28) (door p30 p29) (door p30 p30) (door p30 p31) (door p30 p32) (door p30 p33) (door p30 p34) (door p30 p35) (door p30 p36) (door p30 p37))
        (invariant (door p32 p1) (door p32 p2) (door p32 p3) (door p32 p4) (door p32 p5) (door p32 p6) (door p32 p7) (door p32 p8) (door p32 p9) (door p32 p10) (door p32 p11) (door p32 p12) (door p32 p13) (door p32 p14) (door p32 p15) (door p32 p16) (door p32 p17) (door p32 p18) (door p32 p19) (door p32 p20) (door p32 p21) (door p32 p22) (door p32 p23) (door p32 p24) (door p32 p25) (door p32 p26) (door p32 p27) (door p32 p28) (door p32 p29) (door p32 p30) (door p32 p31) (door p32 p32) (door p32 p33) (door p32 p34) (door p32 p35) (door p32 p36) (door p32 p37))
        (invariant (door p34 p1) (door p34 p2) (door p34 p3) (door p34 p4) (door p34 p5) (door p34 p6) (door p34 p7) (door p34 p8) (door p34 p9) (door p34 p10) (door p34 p11) (door p34 p12) (door p34 p13) (door p34 p14) (door p34 p15) (door p34 p16) (door p34 p17) (door p34 p18) (door p34 p19) (door p34 p20) (door p34 p21) (door p34 p22) (door p34 p23) (door p34 p24) (door p34 p25) (door p34 p26) (door p34 p27) (door p34 p28) (door p34 p29) (door p34 p30) (door p34 p31) (door p34 p32) (door p34 p33) (door p34 p34) (door p34 p35) (door p34 p36) (door p34 p37))
        (invariant (door p36 p1) (door p36 p2) (door p36 p3) (door p36 p4) (door p36 p5) (door p36 p6) (door p36 p7) (door p36 p8) (door p36 p9) (door p36 p10) (door p36 p11) (door p36 p12) (door p36 p13) (door p36 p14) (door p36 p15) (door p36 p16) (door p36 p17) (door p36 p18) (door p36 p19) (door p36 p20) (door p36 p21) (door p36 p22) (door p36 p23) (door p36 p24) (door p36 p25) (door p36 p26) (door p36 p27) (door p36 p28) (door p36 p29) (door p36 p30) (door p36 p31) (door p36 p32) (door p36 p33) (door p36 p34) (door p36 p35) (door p36 p36) (door p36 p37))
    )
    (:hidden (door p2 p12) (door p4 p17) (door p6 p30) (door p8 p15) (door p10 p2) (door p12 p22) (door p14 p2) (door p16 p34) (door p18 p24) (door p20 p12) (door p22 p7) (door p24 p5) (door p26 p7) (door p28 p17) (door p30 p25) (door p32 p29) (door p34 p25) (door p36 p7))
    (:goal (at p37 p19))
)
