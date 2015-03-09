(define (problem p-17)
    (:domain doors)
    (:objects
        p1-1 p1-2 p1-3 p1-4 p1-5 p1-6 p1-7 p1-8 p1-9 p1-10 p1-11 p1-12 p1-13 p1-14 p1-15 p1-16 p1-17
        p2-1 p2-2 p2-3 p2-4 p2-5 p2-6 p2-7 p2-8 p2-9 p2-10 p2-11 p2-12 p2-13 p2-14 p2-15 p2-16 p2-17
        p3-1 p3-2 p3-3 p3-4 p3-5 p3-6 p3-7 p3-8 p3-9 p3-10 p3-11 p3-12 p3-13 p3-14 p3-15 p3-16 p3-17
        p4-1 p4-2 p4-3 p4-4 p4-5 p4-6 p4-7 p4-8 p4-9 p4-10 p4-11 p4-12 p4-13 p4-14 p4-15 p4-16 p4-17
        p5-1 p5-2 p5-3 p5-4 p5-5 p5-6 p5-7 p5-8 p5-9 p5-10 p5-11 p5-12 p5-13 p5-14 p5-15 p5-16 p5-17
        p6-1 p6-2 p6-3 p6-4 p6-5 p6-6 p6-7 p6-8 p6-9 p6-10 p6-11 p6-12 p6-13 p6-14 p6-15 p6-16 p6-17
        p7-1 p7-2 p7-3 p7-4 p7-5 p7-6 p7-7 p7-8 p7-9 p7-10 p7-11 p7-12 p7-13 p7-14 p7-15 p7-16 p7-17
        p8-1 p8-2 p8-3 p8-4 p8-5 p8-6 p8-7 p8-8 p8-9 p8-10 p8-11 p8-12 p8-13 p8-14 p8-15 p8-16 p8-17
        p9-1 p9-2 p9-3 p9-4 p9-5 p9-6 p9-7 p9-8 p9-9 p9-10 p9-11 p9-12 p9-13 p9-14 p9-15 p9-16 p9-17
        p10-1 p10-2 p10-3 p10-4 p10-5 p10-6 p10-7 p10-8 p10-9 p10-10 p10-11 p10-12 p10-13 p10-14 p10-15 p10-16 p10-17
        p11-1 p11-2 p11-3 p11-4 p11-5 p11-6 p11-7 p11-8 p11-9 p11-10 p11-11 p11-12 p11-13 p11-14 p11-15 p11-16 p11-17
        p12-1 p12-2 p12-3 p12-4 p12-5 p12-6 p12-7 p12-8 p12-9 p12-10 p12-11 p12-12 p12-13 p12-14 p12-15 p12-16 p12-17
        p13-1 p13-2 p13-3 p13-4 p13-5 p13-6 p13-7 p13-8 p13-9 p13-10 p13-11 p13-12 p13-13 p13-14 p13-15 p13-16 p13-17
        p14-1 p14-2 p14-3 p14-4 p14-5 p14-6 p14-7 p14-8 p14-9 p14-10 p14-11 p14-12 p14-13 p14-14 p14-15 p14-16 p14-17
        p15-1 p15-2 p15-3 p15-4 p15-5 p15-6 p15-7 p15-8 p15-9 p15-10 p15-11 p15-12 p15-13 p15-14 p15-15 p15-16 p15-17
        p16-1 p16-2 p16-3 p16-4 p16-5 p16-6 p16-7 p16-8 p16-9 p16-10 p16-11 p16-12 p16-13 p16-14 p16-15 p16-16 p16-17
        p17-1 p17-2 p17-3 p17-4 p17-5 p17-6 p17-7 p17-8 p17-9 p17-10 p17-11 p17-12 p17-13 p17-14 p17-15 p17-16 p17-17 - pos
        c2 c4 c6 c8 c10 c12 c14 c16 - col
        r1 r2 r3 r4 r5 r6 r7 r8 r9 r10 r11 r12 r13 r14 r15 r16 r17 - row
    )
    (:init
        (adj p1-1 p1-2) (adj p1-2 p1-1)
        (adj p1-1 p2-1)
        (adj p1-2 p1-3) (adj p1-3 p1-2)
        (adj p1-2 p2-2)
        (adj p1-3 p1-4) (adj p1-4 p1-3)
        (adj p1-3 p2-3)
        (adj p1-4 p1-5) (adj p1-5 p1-4)
        (adj p1-4 p2-4)
        (adj p1-5 p1-6) (adj p1-6 p1-5)
        (adj p1-5 p2-5)
        (adj p1-6 p1-7) (adj p1-7 p1-6)
        (adj p1-6 p2-6)
        (adj p1-7 p1-8) (adj p1-8 p1-7)
        (adj p1-7 p2-7)
        (adj p1-8 p1-9) (adj p1-9 p1-8)
        (adj p1-8 p2-8)
        (adj p1-9 p1-10) (adj p1-10 p1-9)
        (adj p1-9 p2-9)
        (adj p1-10 p1-11) (adj p1-11 p1-10)
        (adj p1-10 p2-10)
        (adj p1-11 p1-12) (adj p1-12 p1-11)
        (adj p1-11 p2-11)
        (adj p1-12 p1-13) (adj p1-13 p1-12)
        (adj p1-12 p2-12)
        (adj p1-13 p1-14) (adj p1-14 p1-13)
        (adj p1-13 p2-13)
        (adj p1-14 p1-15) (adj p1-15 p1-14)
        (adj p1-14 p2-14)
        (adj p1-15 p1-16) (adj p1-16 p1-15)
        (adj p1-15 p2-15)
        (adj p1-16 p1-17) (adj p1-17 p1-16)
        (adj p1-16 p2-16)
        (adj p1-17 p2-17)
        (adj p2-1 p2-2) (adj p2-2 p2-1)
        (adj p2-1 p3-1)
        (adj p2-2 p2-3) (adj p2-3 p2-2)
        (adj p2-2 p3-2)
        (adj p2-3 p2-4) (adj p2-4 p2-3)
        (adj p2-3 p3-3)
        (adj p2-4 p2-5) (adj p2-5 p2-4)
        (adj p2-4 p3-4)
        (adj p2-5 p2-6) (adj p2-6 p2-5)
        (adj p2-5 p3-5)
        (adj p2-6 p2-7) (adj p2-7 p2-6)
        (adj p2-6 p3-6)
        (adj p2-7 p2-8) (adj p2-8 p2-7)
        (adj p2-7 p3-7)
        (adj p2-8 p2-9) (adj p2-9 p2-8)
        (adj p2-8 p3-8)
        (adj p2-9 p2-10) (adj p2-10 p2-9)
        (adj p2-9 p3-9)
        (adj p2-10 p2-11) (adj p2-11 p2-10)
        (adj p2-10 p3-10)
        (adj p2-11 p2-12) (adj p2-12 p2-11)
        (adj p2-11 p3-11)
        (adj p2-12 p2-13) (adj p2-13 p2-12)
        (adj p2-12 p3-12)
        (adj p2-13 p2-14) (adj p2-14 p2-13)
        (adj p2-13 p3-13)
        (adj p2-14 p2-15) (adj p2-15 p2-14)
        (adj p2-14 p3-14)
        (adj p2-15 p2-16) (adj p2-16 p2-15)
        (adj p2-15 p3-15)
        (adj p2-16 p2-17) (adj p2-17 p2-16)
        (adj p2-16 p3-16)
        (adj p2-17 p3-17)
        (adj p3-1 p3-2) (adj p3-2 p3-1)
        (adj p3-1 p4-1)
        (adj p3-2 p3-3) (adj p3-3 p3-2)
        (adj p3-2 p4-2)
        (adj p3-3 p3-4) (adj p3-4 p3-3)
        (adj p3-3 p4-3)
        (adj p3-4 p3-5) (adj p3-5 p3-4)
        (adj p3-4 p4-4)
        (adj p3-5 p3-6) (adj p3-6 p3-5)
        (adj p3-5 p4-5)
        (adj p3-6 p3-7) (adj p3-7 p3-6)
        (adj p3-6 p4-6)
        (adj p3-7 p3-8) (adj p3-8 p3-7)
        (adj p3-7 p4-7)
        (adj p3-8 p3-9) (adj p3-9 p3-8)
        (adj p3-8 p4-8)
        (adj p3-9 p3-10) (adj p3-10 p3-9)
        (adj p3-9 p4-9)
        (adj p3-10 p3-11) (adj p3-11 p3-10)
        (adj p3-10 p4-10)
        (adj p3-11 p3-12) (adj p3-12 p3-11)
        (adj p3-11 p4-11)
        (adj p3-12 p3-13) (adj p3-13 p3-12)
        (adj p3-12 p4-12)
        (adj p3-13 p3-14) (adj p3-14 p3-13)
        (adj p3-13 p4-13)
        (adj p3-14 p3-15) (adj p3-15 p3-14)
        (adj p3-14 p4-14)
        (adj p3-15 p3-16) (adj p3-16 p3-15)
        (adj p3-15 p4-15)
        (adj p3-16 p3-17) (adj p3-17 p3-16)
        (adj p3-16 p4-16)
        (adj p3-17 p4-17)
        (adj p4-1 p4-2) (adj p4-2 p4-1)
        (adj p4-1 p5-1)
        (adj p4-2 p4-3) (adj p4-3 p4-2)
        (adj p4-2 p5-2)
        (adj p4-3 p4-4) (adj p4-4 p4-3)
        (adj p4-3 p5-3)
        (adj p4-4 p4-5) (adj p4-5 p4-4)
        (adj p4-4 p5-4)
        (adj p4-5 p4-6) (adj p4-6 p4-5)
        (adj p4-5 p5-5)
        (adj p4-6 p4-7) (adj p4-7 p4-6)
        (adj p4-6 p5-6)
        (adj p4-7 p4-8) (adj p4-8 p4-7)
        (adj p4-7 p5-7)
        (adj p4-8 p4-9) (adj p4-9 p4-8)
        (adj p4-8 p5-8)
        (adj p4-9 p4-10) (adj p4-10 p4-9)
        (adj p4-9 p5-9)
        (adj p4-10 p4-11) (adj p4-11 p4-10)
        (adj p4-10 p5-10)
        (adj p4-11 p4-12) (adj p4-12 p4-11)
        (adj p4-11 p5-11)
        (adj p4-12 p4-13) (adj p4-13 p4-12)
        (adj p4-12 p5-12)
        (adj p4-13 p4-14) (adj p4-14 p4-13)
        (adj p4-13 p5-13)
        (adj p4-14 p4-15) (adj p4-15 p4-14)
        (adj p4-14 p5-14)
        (adj p4-15 p4-16) (adj p4-16 p4-15)
        (adj p4-15 p5-15)
        (adj p4-16 p4-17) (adj p4-17 p4-16)
        (adj p4-16 p5-16)
        (adj p4-17 p5-17)
        (adj p5-1 p5-2) (adj p5-2 p5-1)
        (adj p5-1 p6-1)
        (adj p5-2 p5-3) (adj p5-3 p5-2)
        (adj p5-2 p6-2)
        (adj p5-3 p5-4) (adj p5-4 p5-3)
        (adj p5-3 p6-3)
        (adj p5-4 p5-5) (adj p5-5 p5-4)
        (adj p5-4 p6-4)
        (adj p5-5 p5-6) (adj p5-6 p5-5)
        (adj p5-5 p6-5)
        (adj p5-6 p5-7) (adj p5-7 p5-6)
        (adj p5-6 p6-6)
        (adj p5-7 p5-8) (adj p5-8 p5-7)
        (adj p5-7 p6-7)
        (adj p5-8 p5-9) (adj p5-9 p5-8)
        (adj p5-8 p6-8)
        (adj p5-9 p5-10) (adj p5-10 p5-9)
        (adj p5-9 p6-9)
        (adj p5-10 p5-11) (adj p5-11 p5-10)
        (adj p5-10 p6-10)
        (adj p5-11 p5-12) (adj p5-12 p5-11)
        (adj p5-11 p6-11)
        (adj p5-12 p5-13) (adj p5-13 p5-12)
        (adj p5-12 p6-12)
        (adj p5-13 p5-14) (adj p5-14 p5-13)
        (adj p5-13 p6-13)
        (adj p5-14 p5-15) (adj p5-15 p5-14)
        (adj p5-14 p6-14)
        (adj p5-15 p5-16) (adj p5-16 p5-15)
        (adj p5-15 p6-15)
        (adj p5-16 p5-17) (adj p5-17 p5-16)
        (adj p5-16 p6-16)
        (adj p5-17 p6-17)
        (adj p6-1 p6-2) (adj p6-2 p6-1)
        (adj p6-1 p7-1)
        (adj p6-2 p6-3) (adj p6-3 p6-2)
        (adj p6-2 p7-2)
        (adj p6-3 p6-4) (adj p6-4 p6-3)
        (adj p6-3 p7-3)
        (adj p6-4 p6-5) (adj p6-5 p6-4)
        (adj p6-4 p7-4)
        (adj p6-5 p6-6) (adj p6-6 p6-5)
        (adj p6-5 p7-5)
        (adj p6-6 p6-7) (adj p6-7 p6-6)
        (adj p6-6 p7-6)
        (adj p6-7 p6-8) (adj p6-8 p6-7)
        (adj p6-7 p7-7)
        (adj p6-8 p6-9) (adj p6-9 p6-8)
        (adj p6-8 p7-8)
        (adj p6-9 p6-10) (adj p6-10 p6-9)
        (adj p6-9 p7-9)
        (adj p6-10 p6-11) (adj p6-11 p6-10)
        (adj p6-10 p7-10)
        (adj p6-11 p6-12) (adj p6-12 p6-11)
        (adj p6-11 p7-11)
        (adj p6-12 p6-13) (adj p6-13 p6-12)
        (adj p6-12 p7-12)
        (adj p6-13 p6-14) (adj p6-14 p6-13)
        (adj p6-13 p7-13)
        (adj p6-14 p6-15) (adj p6-15 p6-14)
        (adj p6-14 p7-14)
        (adj p6-15 p6-16) (adj p6-16 p6-15)
        (adj p6-15 p7-15)
        (adj p6-16 p6-17) (adj p6-17 p6-16)
        (adj p6-16 p7-16)
        (adj p6-17 p7-17)
        (adj p7-1 p7-2) (adj p7-2 p7-1)
        (adj p7-1 p8-1)
        (adj p7-2 p7-3) (adj p7-3 p7-2)
        (adj p7-2 p8-2)
        (adj p7-3 p7-4) (adj p7-4 p7-3)
        (adj p7-3 p8-3)
        (adj p7-4 p7-5) (adj p7-5 p7-4)
        (adj p7-4 p8-4)
        (adj p7-5 p7-6) (adj p7-6 p7-5)
        (adj p7-5 p8-5)
        (adj p7-6 p7-7) (adj p7-7 p7-6)
        (adj p7-6 p8-6)
        (adj p7-7 p7-8) (adj p7-8 p7-7)
        (adj p7-7 p8-7)
        (adj p7-8 p7-9) (adj p7-9 p7-8)
        (adj p7-8 p8-8)
        (adj p7-9 p7-10) (adj p7-10 p7-9)
        (adj p7-9 p8-9)
        (adj p7-10 p7-11) (adj p7-11 p7-10)
        (adj p7-10 p8-10)
        (adj p7-11 p7-12) (adj p7-12 p7-11)
        (adj p7-11 p8-11)
        (adj p7-12 p7-13) (adj p7-13 p7-12)
        (adj p7-12 p8-12)
        (adj p7-13 p7-14) (adj p7-14 p7-13)
        (adj p7-13 p8-13)
        (adj p7-14 p7-15) (adj p7-15 p7-14)
        (adj p7-14 p8-14)
        (adj p7-15 p7-16) (adj p7-16 p7-15)
        (adj p7-15 p8-15)
        (adj p7-16 p7-17) (adj p7-17 p7-16)
        (adj p7-16 p8-16)
        (adj p7-17 p8-17)
        (adj p8-1 p8-2) (adj p8-2 p8-1)
        (adj p8-1 p9-1)
        (adj p8-2 p8-3) (adj p8-3 p8-2)
        (adj p8-2 p9-2)
        (adj p8-3 p8-4) (adj p8-4 p8-3)
        (adj p8-3 p9-3)
        (adj p8-4 p8-5) (adj p8-5 p8-4)
        (adj p8-4 p9-4)
        (adj p8-5 p8-6) (adj p8-6 p8-5)
        (adj p8-5 p9-5)
        (adj p8-6 p8-7) (adj p8-7 p8-6)
        (adj p8-6 p9-6)
        (adj p8-7 p8-8) (adj p8-8 p8-7)
        (adj p8-7 p9-7)
        (adj p8-8 p8-9) (adj p8-9 p8-8)
        (adj p8-8 p9-8)
        (adj p8-9 p8-10) (adj p8-10 p8-9)
        (adj p8-9 p9-9)
        (adj p8-10 p8-11) (adj p8-11 p8-10)
        (adj p8-10 p9-10)
        (adj p8-11 p8-12) (adj p8-12 p8-11)
        (adj p8-11 p9-11)
        (adj p8-12 p8-13) (adj p8-13 p8-12)
        (adj p8-12 p9-12)
        (adj p8-13 p8-14) (adj p8-14 p8-13)
        (adj p8-13 p9-13)
        (adj p8-14 p8-15) (adj p8-15 p8-14)
        (adj p8-14 p9-14)
        (adj p8-15 p8-16) (adj p8-16 p8-15)
        (adj p8-15 p9-15)
        (adj p8-16 p8-17) (adj p8-17 p8-16)
        (adj p8-16 p9-16)
        (adj p8-17 p9-17)
        (adj p9-1 p9-2) (adj p9-2 p9-1)
        (adj p9-1 p10-1)
        (adj p9-2 p9-3) (adj p9-3 p9-2)
        (adj p9-2 p10-2)
        (adj p9-3 p9-4) (adj p9-4 p9-3)
        (adj p9-3 p10-3)
        (adj p9-4 p9-5) (adj p9-5 p9-4)
        (adj p9-4 p10-4)
        (adj p9-5 p9-6) (adj p9-6 p9-5)
        (adj p9-5 p10-5)
        (adj p9-6 p9-7) (adj p9-7 p9-6)
        (adj p9-6 p10-6)
        (adj p9-7 p9-8) (adj p9-8 p9-7)
        (adj p9-7 p10-7)
        (adj p9-8 p9-9) (adj p9-9 p9-8)
        (adj p9-8 p10-8)
        (adj p9-9 p9-10) (adj p9-10 p9-9)
        (adj p9-9 p10-9)
        (adj p9-10 p9-11) (adj p9-11 p9-10)
        (adj p9-10 p10-10)
        (adj p9-11 p9-12) (adj p9-12 p9-11)
        (adj p9-11 p10-11)
        (adj p9-12 p9-13) (adj p9-13 p9-12)
        (adj p9-12 p10-12)
        (adj p9-13 p9-14) (adj p9-14 p9-13)
        (adj p9-13 p10-13)
        (adj p9-14 p9-15) (adj p9-15 p9-14)
        (adj p9-14 p10-14)
        (adj p9-15 p9-16) (adj p9-16 p9-15)
        (adj p9-15 p10-15)
        (adj p9-16 p9-17) (adj p9-17 p9-16)
        (adj p9-16 p10-16)
        (adj p9-17 p10-17)
        (adj p10-1 p10-2) (adj p10-2 p10-1)
        (adj p10-1 p11-1)
        (adj p10-2 p10-3) (adj p10-3 p10-2)
        (adj p10-2 p11-2)
        (adj p10-3 p10-4) (adj p10-4 p10-3)
        (adj p10-3 p11-3)
        (adj p10-4 p10-5) (adj p10-5 p10-4)
        (adj p10-4 p11-4)
        (adj p10-5 p10-6) (adj p10-6 p10-5)
        (adj p10-5 p11-5)
        (adj p10-6 p10-7) (adj p10-7 p10-6)
        (adj p10-6 p11-6)
        (adj p10-7 p10-8) (adj p10-8 p10-7)
        (adj p10-7 p11-7)
        (adj p10-8 p10-9) (adj p10-9 p10-8)
        (adj p10-8 p11-8)
        (adj p10-9 p10-10) (adj p10-10 p10-9)
        (adj p10-9 p11-9)
        (adj p10-10 p10-11) (adj p10-11 p10-10)
        (adj p10-10 p11-10)
        (adj p10-11 p10-12) (adj p10-12 p10-11)
        (adj p10-11 p11-11)
        (adj p10-12 p10-13) (adj p10-13 p10-12)
        (adj p10-12 p11-12)
        (adj p10-13 p10-14) (adj p10-14 p10-13)
        (adj p10-13 p11-13)
        (adj p10-14 p10-15) (adj p10-15 p10-14)
        (adj p10-14 p11-14)
        (adj p10-15 p10-16) (adj p10-16 p10-15)
        (adj p10-15 p11-15)
        (adj p10-16 p10-17) (adj p10-17 p10-16)
        (adj p10-16 p11-16)
        (adj p10-17 p11-17)
        (adj p11-1 p11-2) (adj p11-2 p11-1)
        (adj p11-1 p12-1)
        (adj p11-2 p11-3) (adj p11-3 p11-2)
        (adj p11-2 p12-2)
        (adj p11-3 p11-4) (adj p11-4 p11-3)
        (adj p11-3 p12-3)
        (adj p11-4 p11-5) (adj p11-5 p11-4)
        (adj p11-4 p12-4)
        (adj p11-5 p11-6) (adj p11-6 p11-5)
        (adj p11-5 p12-5)
        (adj p11-6 p11-7) (adj p11-7 p11-6)
        (adj p11-6 p12-6)
        (adj p11-7 p11-8) (adj p11-8 p11-7)
        (adj p11-7 p12-7)
        (adj p11-8 p11-9) (adj p11-9 p11-8)
        (adj p11-8 p12-8)
        (adj p11-9 p11-10) (adj p11-10 p11-9)
        (adj p11-9 p12-9)
        (adj p11-10 p11-11) (adj p11-11 p11-10)
        (adj p11-10 p12-10)
        (adj p11-11 p11-12) (adj p11-12 p11-11)
        (adj p11-11 p12-11)
        (adj p11-12 p11-13) (adj p11-13 p11-12)
        (adj p11-12 p12-12)
        (adj p11-13 p11-14) (adj p11-14 p11-13)
        (adj p11-13 p12-13)
        (adj p11-14 p11-15) (adj p11-15 p11-14)
        (adj p11-14 p12-14)
        (adj p11-15 p11-16) (adj p11-16 p11-15)
        (adj p11-15 p12-15)
        (adj p11-16 p11-17) (adj p11-17 p11-16)
        (adj p11-16 p12-16)
        (adj p11-17 p12-17)
        (adj p12-1 p12-2) (adj p12-2 p12-1)
        (adj p12-1 p13-1)
        (adj p12-2 p12-3) (adj p12-3 p12-2)
        (adj p12-2 p13-2)
        (adj p12-3 p12-4) (adj p12-4 p12-3)
        (adj p12-3 p13-3)
        (adj p12-4 p12-5) (adj p12-5 p12-4)
        (adj p12-4 p13-4)
        (adj p12-5 p12-6) (adj p12-6 p12-5)
        (adj p12-5 p13-5)
        (adj p12-6 p12-7) (adj p12-7 p12-6)
        (adj p12-6 p13-6)
        (adj p12-7 p12-8) (adj p12-8 p12-7)
        (adj p12-7 p13-7)
        (adj p12-8 p12-9) (adj p12-9 p12-8)
        (adj p12-8 p13-8)
        (adj p12-9 p12-10) (adj p12-10 p12-9)
        (adj p12-9 p13-9)
        (adj p12-10 p12-11) (adj p12-11 p12-10)
        (adj p12-10 p13-10)
        (adj p12-11 p12-12) (adj p12-12 p12-11)
        (adj p12-11 p13-11)
        (adj p12-12 p12-13) (adj p12-13 p12-12)
        (adj p12-12 p13-12)
        (adj p12-13 p12-14) (adj p12-14 p12-13)
        (adj p12-13 p13-13)
        (adj p12-14 p12-15) (adj p12-15 p12-14)
        (adj p12-14 p13-14)
        (adj p12-15 p12-16) (adj p12-16 p12-15)
        (adj p12-15 p13-15)
        (adj p12-16 p12-17) (adj p12-17 p12-16)
        (adj p12-16 p13-16)
        (adj p12-17 p13-17)
        (adj p13-1 p13-2) (adj p13-2 p13-1)
        (adj p13-1 p14-1)
        (adj p13-2 p13-3) (adj p13-3 p13-2)
        (adj p13-2 p14-2)
        (adj p13-3 p13-4) (adj p13-4 p13-3)
        (adj p13-3 p14-3)
        (adj p13-4 p13-5) (adj p13-5 p13-4)
        (adj p13-4 p14-4)
        (adj p13-5 p13-6) (adj p13-6 p13-5)
        (adj p13-5 p14-5)
        (adj p13-6 p13-7) (adj p13-7 p13-6)
        (adj p13-6 p14-6)
        (adj p13-7 p13-8) (adj p13-8 p13-7)
        (adj p13-7 p14-7)
        (adj p13-8 p13-9) (adj p13-9 p13-8)
        (adj p13-8 p14-8)
        (adj p13-9 p13-10) (adj p13-10 p13-9)
        (adj p13-9 p14-9)
        (adj p13-10 p13-11) (adj p13-11 p13-10)
        (adj p13-10 p14-10)
        (adj p13-11 p13-12) (adj p13-12 p13-11)
        (adj p13-11 p14-11)
        (adj p13-12 p13-13) (adj p13-13 p13-12)
        (adj p13-12 p14-12)
        (adj p13-13 p13-14) (adj p13-14 p13-13)
        (adj p13-13 p14-13)
        (adj p13-14 p13-15) (adj p13-15 p13-14)
        (adj p13-14 p14-14)
        (adj p13-15 p13-16) (adj p13-16 p13-15)
        (adj p13-15 p14-15)
        (adj p13-16 p13-17) (adj p13-17 p13-16)
        (adj p13-16 p14-16)
        (adj p13-17 p14-17)
        (adj p14-1 p14-2) (adj p14-2 p14-1)
        (adj p14-1 p15-1)
        (adj p14-2 p14-3) (adj p14-3 p14-2)
        (adj p14-2 p15-2)
        (adj p14-3 p14-4) (adj p14-4 p14-3)
        (adj p14-3 p15-3)
        (adj p14-4 p14-5) (adj p14-5 p14-4)
        (adj p14-4 p15-4)
        (adj p14-5 p14-6) (adj p14-6 p14-5)
        (adj p14-5 p15-5)
        (adj p14-6 p14-7) (adj p14-7 p14-6)
        (adj p14-6 p15-6)
        (adj p14-7 p14-8) (adj p14-8 p14-7)
        (adj p14-7 p15-7)
        (adj p14-8 p14-9) (adj p14-9 p14-8)
        (adj p14-8 p15-8)
        (adj p14-9 p14-10) (adj p14-10 p14-9)
        (adj p14-9 p15-9)
        (adj p14-10 p14-11) (adj p14-11 p14-10)
        (adj p14-10 p15-10)
        (adj p14-11 p14-12) (adj p14-12 p14-11)
        (adj p14-11 p15-11)
        (adj p14-12 p14-13) (adj p14-13 p14-12)
        (adj p14-12 p15-12)
        (adj p14-13 p14-14) (adj p14-14 p14-13)
        (adj p14-13 p15-13)
        (adj p14-14 p14-15) (adj p14-15 p14-14)
        (adj p14-14 p15-14)
        (adj p14-15 p14-16) (adj p14-16 p14-15)
        (adj p14-15 p15-15)
        (adj p14-16 p14-17) (adj p14-17 p14-16)
        (adj p14-16 p15-16)
        (adj p14-17 p15-17)
        (adj p15-1 p15-2) (adj p15-2 p15-1)
        (adj p15-1 p16-1)
        (adj p15-2 p15-3) (adj p15-3 p15-2)
        (adj p15-2 p16-2)
        (adj p15-3 p15-4) (adj p15-4 p15-3)
        (adj p15-3 p16-3)
        (adj p15-4 p15-5) (adj p15-5 p15-4)
        (adj p15-4 p16-4)
        (adj p15-5 p15-6) (adj p15-6 p15-5)
        (adj p15-5 p16-5)
        (adj p15-6 p15-7) (adj p15-7 p15-6)
        (adj p15-6 p16-6)
        (adj p15-7 p15-8) (adj p15-8 p15-7)
        (adj p15-7 p16-7)
        (adj p15-8 p15-9) (adj p15-9 p15-8)
        (adj p15-8 p16-8)
        (adj p15-9 p15-10) (adj p15-10 p15-9)
        (adj p15-9 p16-9)
        (adj p15-10 p15-11) (adj p15-11 p15-10)
        (adj p15-10 p16-10)
        (adj p15-11 p15-12) (adj p15-12 p15-11)
        (adj p15-11 p16-11)
        (adj p15-12 p15-13) (adj p15-13 p15-12)
        (adj p15-12 p16-12)
        (adj p15-13 p15-14) (adj p15-14 p15-13)
        (adj p15-13 p16-13)
        (adj p15-14 p15-15) (adj p15-15 p15-14)
        (adj p15-14 p16-14)
        (adj p15-15 p15-16) (adj p15-16 p15-15)
        (adj p15-15 p16-15)
        (adj p15-16 p15-17) (adj p15-17 p15-16)
        (adj p15-16 p16-16)
        (adj p15-17 p16-17)
        (adj p16-1 p16-2) (adj p16-2 p16-1)
        (adj p16-1 p17-1)
        (adj p16-2 p16-3) (adj p16-3 p16-2)
        (adj p16-2 p17-2)
        (adj p16-3 p16-4) (adj p16-4 p16-3)
        (adj p16-3 p17-3)
        (adj p16-4 p16-5) (adj p16-5 p16-4)
        (adj p16-4 p17-4)
        (adj p16-5 p16-6) (adj p16-6 p16-5)
        (adj p16-5 p17-5)
        (adj p16-6 p16-7) (adj p16-7 p16-6)
        (adj p16-6 p17-6)
        (adj p16-7 p16-8) (adj p16-8 p16-7)
        (adj p16-7 p17-7)
        (adj p16-8 p16-9) (adj p16-9 p16-8)
        (adj p16-8 p17-8)
        (adj p16-9 p16-10) (adj p16-10 p16-9)
        (adj p16-9 p17-9)
        (adj p16-10 p16-11) (adj p16-11 p16-10)
        (adj p16-10 p17-10)
        (adj p16-11 p16-12) (adj p16-12 p16-11)
        (adj p16-11 p17-11)
        (adj p16-12 p16-13) (adj p16-13 p16-12)
        (adj p16-12 p17-12)
        (adj p16-13 p16-14) (adj p16-14 p16-13)
        (adj p16-13 p17-13)
        (adj p16-14 p16-15) (adj p16-15 p16-14)
        (adj p16-14 p17-14)
        (adj p16-15 p16-16) (adj p16-16 p16-15)
        (adj p16-15 p17-15)
        (adj p16-16 p16-17) (adj p16-17 p16-16)
        (adj p16-16 p17-16)
        (adj p16-17 p17-17)
        (adj p17-1 p17-2) (adj p17-2 p17-1)
        (adj p17-2 p17-3) (adj p17-3 p17-2)
        (adj p17-3 p17-4) (adj p17-4 p17-3)
        (adj p17-4 p17-5) (adj p17-5 p17-4)
        (adj p17-5 p17-6) (adj p17-6 p17-5)
        (adj p17-6 p17-7) (adj p17-7 p17-6)
        (adj p17-7 p17-8) (adj p17-8 p17-7)
        (adj p17-8 p17-9) (adj p17-9 p17-8)
        (adj p17-9 p17-10) (adj p17-10 p17-9)
        (adj p17-10 p17-11) (adj p17-11 p17-10)
        (adj p17-11 p17-12) (adj p17-12 p17-11)
        (adj p17-12 p17-13) (adj p17-13 p17-12)
        (adj p17-13 p17-14) (adj p17-14 p17-13)
        (adj p17-14 p17-15) (adj p17-15 p17-14)
        (adj p17-15 p17-16) (adj p17-16 p17-15)
        (adj p17-16 p17-17) (adj p17-17 p17-16)

        (at-col c2 p2-1)
        (at-col c2 p2-2)
        (at-col c2 p2-3)
        (at-col c2 p2-4)
        (at-col c2 p2-5)
        (at-col c2 p2-6)
        (at-col c2 p2-7)
        (at-col c2 p2-8)
        (at-col c2 p2-9)
        (at-col c2 p2-10)
        (at-col c2 p2-11)
        (at-col c2 p2-12)
        (at-col c2 p2-13)
        (at-col c2 p2-14)
        (at-col c2 p2-15)
        (at-col c2 p2-16)
        (at-col c2 p2-17)
        (at-col c4 p4-1)
        (at-col c4 p4-2)
        (at-col c4 p4-3)
        (at-col c4 p4-4)
        (at-col c4 p4-5)
        (at-col c4 p4-6)
        (at-col c4 p4-7)
        (at-col c4 p4-8)
        (at-col c4 p4-9)
        (at-col c4 p4-10)
        (at-col c4 p4-11)
        (at-col c4 p4-12)
        (at-col c4 p4-13)
        (at-col c4 p4-14)
        (at-col c4 p4-15)
        (at-col c4 p4-16)
        (at-col c4 p4-17)
        (at-col c6 p6-1)
        (at-col c6 p6-2)
        (at-col c6 p6-3)
        (at-col c6 p6-4)
        (at-col c6 p6-5)
        (at-col c6 p6-6)
        (at-col c6 p6-7)
        (at-col c6 p6-8)
        (at-col c6 p6-9)
        (at-col c6 p6-10)
        (at-col c6 p6-11)
        (at-col c6 p6-12)
        (at-col c6 p6-13)
        (at-col c6 p6-14)
        (at-col c6 p6-15)
        (at-col c6 p6-16)
        (at-col c6 p6-17)
        (at-col c8 p8-1)
        (at-col c8 p8-2)
        (at-col c8 p8-3)
        (at-col c8 p8-4)
        (at-col c8 p8-5)
        (at-col c8 p8-6)
        (at-col c8 p8-7)
        (at-col c8 p8-8)
        (at-col c8 p8-9)
        (at-col c8 p8-10)
        (at-col c8 p8-11)
        (at-col c8 p8-12)
        (at-col c8 p8-13)
        (at-col c8 p8-14)
        (at-col c8 p8-15)
        (at-col c8 p8-16)
        (at-col c8 p8-17)
        (at-col c10 p10-1)
        (at-col c10 p10-2)
        (at-col c10 p10-3)
        (at-col c10 p10-4)
        (at-col c10 p10-5)
        (at-col c10 p10-6)
        (at-col c10 p10-7)
        (at-col c10 p10-8)
        (at-col c10 p10-9)
        (at-col c10 p10-10)
        (at-col c10 p10-11)
        (at-col c10 p10-12)
        (at-col c10 p10-13)
        (at-col c10 p10-14)
        (at-col c10 p10-15)
        (at-col c10 p10-16)
        (at-col c10 p10-17)
        (at-col c12 p12-1)
        (at-col c12 p12-2)
        (at-col c12 p12-3)
        (at-col c12 p12-4)
        (at-col c12 p12-5)
        (at-col c12 p12-6)
        (at-col c12 p12-7)
        (at-col c12 p12-8)
        (at-col c12 p12-9)
        (at-col c12 p12-10)
        (at-col c12 p12-11)
        (at-col c12 p12-12)
        (at-col c12 p12-13)
        (at-col c12 p12-14)
        (at-col c12 p12-15)
        (at-col c12 p12-16)
        (at-col c12 p12-17)
        (at-col c14 p14-1)
        (at-col c14 p14-2)
        (at-col c14 p14-3)
        (at-col c14 p14-4)
        (at-col c14 p14-5)
        (at-col c14 p14-6)
        (at-col c14 p14-7)
        (at-col c14 p14-8)
        (at-col c14 p14-9)
        (at-col c14 p14-10)
        (at-col c14 p14-11)
        (at-col c14 p14-12)
        (at-col c14 p14-13)
        (at-col c14 p14-14)
        (at-col c14 p14-15)
        (at-col c14 p14-16)
        (at-col c14 p14-17)
        (at-col c16 p16-1)
        (at-col c16 p16-2)
        (at-col c16 p16-3)
        (at-col c16 p16-4)
        (at-col c16 p16-5)
        (at-col c16 p16-6)
        (at-col c16 p16-7)
        (at-col c16 p16-8)
        (at-col c16 p16-9)
        (at-col c16 p16-10)
        (at-col c16 p16-11)
        (at-col c16 p16-12)
        (at-col c16 p16-13)
        (at-col c16 p16-14)
        (at-col c16 p16-15)
        (at-col c16 p16-16)
        (at-col c16 p16-17)

        (at-row r1 p1-1)
        (at-row r1 p2-1)
        (at-row r1 p3-1)
        (at-row r1 p4-1)
        (at-row r1 p5-1)
        (at-row r1 p6-1)
        (at-row r1 p7-1)
        (at-row r1 p8-1)
        (at-row r1 p9-1)
        (at-row r1 p10-1)
        (at-row r1 p11-1)
        (at-row r1 p12-1)
        (at-row r1 p13-1)
        (at-row r1 p14-1)
        (at-row r1 p15-1)
        (at-row r1 p16-1)
        (at-row r1 p17-1)
        (at-row r2 p1-2)
        (at-row r2 p2-2)
        (at-row r2 p3-2)
        (at-row r2 p4-2)
        (at-row r2 p5-2)
        (at-row r2 p6-2)
        (at-row r2 p7-2)
        (at-row r2 p8-2)
        (at-row r2 p9-2)
        (at-row r2 p10-2)
        (at-row r2 p11-2)
        (at-row r2 p12-2)
        (at-row r2 p13-2)
        (at-row r2 p14-2)
        (at-row r2 p15-2)
        (at-row r2 p16-2)
        (at-row r2 p17-2)
        (at-row r3 p1-3)
        (at-row r3 p2-3)
        (at-row r3 p3-3)
        (at-row r3 p4-3)
        (at-row r3 p5-3)
        (at-row r3 p6-3)
        (at-row r3 p7-3)
        (at-row r3 p8-3)
        (at-row r3 p9-3)
        (at-row r3 p10-3)
        (at-row r3 p11-3)
        (at-row r3 p12-3)
        (at-row r3 p13-3)
        (at-row r3 p14-3)
        (at-row r3 p15-3)
        (at-row r3 p16-3)
        (at-row r3 p17-3)
        (at-row r4 p1-4)
        (at-row r4 p2-4)
        (at-row r4 p3-4)
        (at-row r4 p4-4)
        (at-row r4 p5-4)
        (at-row r4 p6-4)
        (at-row r4 p7-4)
        (at-row r4 p8-4)
        (at-row r4 p9-4)
        (at-row r4 p10-4)
        (at-row r4 p11-4)
        (at-row r4 p12-4)
        (at-row r4 p13-4)
        (at-row r4 p14-4)
        (at-row r4 p15-4)
        (at-row r4 p16-4)
        (at-row r4 p17-4)
        (at-row r5 p1-5)
        (at-row r5 p2-5)
        (at-row r5 p3-5)
        (at-row r5 p4-5)
        (at-row r5 p5-5)
        (at-row r5 p6-5)
        (at-row r5 p7-5)
        (at-row r5 p8-5)
        (at-row r5 p9-5)
        (at-row r5 p10-5)
        (at-row r5 p11-5)
        (at-row r5 p12-5)
        (at-row r5 p13-5)
        (at-row r5 p14-5)
        (at-row r5 p15-5)
        (at-row r5 p16-5)
        (at-row r5 p17-5)
        (at-row r6 p1-6)
        (at-row r6 p2-6)
        (at-row r6 p3-6)
        (at-row r6 p4-6)
        (at-row r6 p5-6)
        (at-row r6 p6-6)
        (at-row r6 p7-6)
        (at-row r6 p8-6)
        (at-row r6 p9-6)
        (at-row r6 p10-6)
        (at-row r6 p11-6)
        (at-row r6 p12-6)
        (at-row r6 p13-6)
        (at-row r6 p14-6)
        (at-row r6 p15-6)
        (at-row r6 p16-6)
        (at-row r6 p17-6)
        (at-row r7 p1-7)
        (at-row r7 p2-7)
        (at-row r7 p3-7)
        (at-row r7 p4-7)
        (at-row r7 p5-7)
        (at-row r7 p6-7)
        (at-row r7 p7-7)
        (at-row r7 p8-7)
        (at-row r7 p9-7)
        (at-row r7 p10-7)
        (at-row r7 p11-7)
        (at-row r7 p12-7)
        (at-row r7 p13-7)
        (at-row r7 p14-7)
        (at-row r7 p15-7)
        (at-row r7 p16-7)
        (at-row r7 p17-7)
        (at-row r8 p1-8)
        (at-row r8 p2-8)
        (at-row r8 p3-8)
        (at-row r8 p4-8)
        (at-row r8 p5-8)
        (at-row r8 p6-8)
        (at-row r8 p7-8)
        (at-row r8 p8-8)
        (at-row r8 p9-8)
        (at-row r8 p10-8)
        (at-row r8 p11-8)
        (at-row r8 p12-8)
        (at-row r8 p13-8)
        (at-row r8 p14-8)
        (at-row r8 p15-8)
        (at-row r8 p16-8)
        (at-row r8 p17-8)
        (at-row r9 p1-9)
        (at-row r9 p2-9)
        (at-row r9 p3-9)
        (at-row r9 p4-9)
        (at-row r9 p5-9)
        (at-row r9 p6-9)
        (at-row r9 p7-9)
        (at-row r9 p8-9)
        (at-row r9 p9-9)
        (at-row r9 p10-9)
        (at-row r9 p11-9)
        (at-row r9 p12-9)
        (at-row r9 p13-9)
        (at-row r9 p14-9)
        (at-row r9 p15-9)
        (at-row r9 p16-9)
        (at-row r9 p17-9)
        (at-row r10 p1-10)
        (at-row r10 p2-10)
        (at-row r10 p3-10)
        (at-row r10 p4-10)
        (at-row r10 p5-10)
        (at-row r10 p6-10)
        (at-row r10 p7-10)
        (at-row r10 p8-10)
        (at-row r10 p9-10)
        (at-row r10 p10-10)
        (at-row r10 p11-10)
        (at-row r10 p12-10)
        (at-row r10 p13-10)
        (at-row r10 p14-10)
        (at-row r10 p15-10)
        (at-row r10 p16-10)
        (at-row r10 p17-10)
        (at-row r11 p1-11)
        (at-row r11 p2-11)
        (at-row r11 p3-11)
        (at-row r11 p4-11)
        (at-row r11 p5-11)
        (at-row r11 p6-11)
        (at-row r11 p7-11)
        (at-row r11 p8-11)
        (at-row r11 p9-11)
        (at-row r11 p10-11)
        (at-row r11 p11-11)
        (at-row r11 p12-11)
        (at-row r11 p13-11)
        (at-row r11 p14-11)
        (at-row r11 p15-11)
        (at-row r11 p16-11)
        (at-row r11 p17-11)
        (at-row r12 p1-12)
        (at-row r12 p2-12)
        (at-row r12 p3-12)
        (at-row r12 p4-12)
        (at-row r12 p5-12)
        (at-row r12 p6-12)
        (at-row r12 p7-12)
        (at-row r12 p8-12)
        (at-row r12 p9-12)
        (at-row r12 p10-12)
        (at-row r12 p11-12)
        (at-row r12 p12-12)
        (at-row r12 p13-12)
        (at-row r12 p14-12)
        (at-row r12 p15-12)
        (at-row r12 p16-12)
        (at-row r12 p17-12)
        (at-row r13 p1-13)
        (at-row r13 p2-13)
        (at-row r13 p3-13)
        (at-row r13 p4-13)
        (at-row r13 p5-13)
        (at-row r13 p6-13)
        (at-row r13 p7-13)
        (at-row r13 p8-13)
        (at-row r13 p9-13)
        (at-row r13 p10-13)
        (at-row r13 p11-13)
        (at-row r13 p12-13)
        (at-row r13 p13-13)
        (at-row r13 p14-13)
        (at-row r13 p15-13)
        (at-row r13 p16-13)
        (at-row r13 p17-13)
        (at-row r14 p1-14)
        (at-row r14 p2-14)
        (at-row r14 p3-14)
        (at-row r14 p4-14)
        (at-row r14 p5-14)
        (at-row r14 p6-14)
        (at-row r14 p7-14)
        (at-row r14 p8-14)
        (at-row r14 p9-14)
        (at-row r14 p10-14)
        (at-row r14 p11-14)
        (at-row r14 p12-14)
        (at-row r14 p13-14)
        (at-row r14 p14-14)
        (at-row r14 p15-14)
        (at-row r14 p16-14)
        (at-row r14 p17-14)
        (at-row r15 p1-15)
        (at-row r15 p2-15)
        (at-row r15 p3-15)
        (at-row r15 p4-15)
        (at-row r15 p5-15)
        (at-row r15 p6-15)
        (at-row r15 p7-15)
        (at-row r15 p8-15)
        (at-row r15 p9-15)
        (at-row r15 p10-15)
        (at-row r15 p11-15)
        (at-row r15 p12-15)
        (at-row r15 p13-15)
        (at-row r15 p14-15)
        (at-row r15 p15-15)
        (at-row r15 p16-15)
        (at-row r15 p17-15)
        (at-row r16 p1-16)
        (at-row r16 p2-16)
        (at-row r16 p3-16)
        (at-row r16 p4-16)
        (at-row r16 p5-16)
        (at-row r16 p6-16)
        (at-row r16 p7-16)
        (at-row r16 p8-16)
        (at-row r16 p9-16)
        (at-row r16 p10-16)
        (at-row r16 p11-16)
        (at-row r16 p12-16)
        (at-row r16 p13-16)
        (at-row r16 p14-16)
        (at-row r16 p15-16)
        (at-row r16 p16-16)
        (at-row r16 p17-16)
        (at-row r17 p1-17)
        (at-row r17 p2-17)
        (at-row r17 p3-17)
        (at-row r17 p4-17)
        (at-row r17 p5-17)
        (at-row r17 p6-17)
        (at-row r17 p7-17)
        (at-row r17 p8-17)
        (at-row r17 p9-17)
        (at-row r17 p10-17)
        (at-row r17 p11-17)
        (at-row r17 p12-17)
        (at-row r17 p13-17)
        (at-row r17 p14-17)
        (at-row r17 p15-17)
        (at-row r17 p16-17)
        (at-row r17 p17-17)

        (need-start)
        (at p1-9)

        (opened p1-1)
        (opened p1-2)
        (opened p1-3)
        (opened p1-4)
        (opened p1-5)
        (opened p1-6)
        (opened p1-7)
        (opened p1-8)
        (opened p1-9)
        (opened p1-10)
        (opened p1-11)
        (opened p1-12)
        (opened p1-13)
        (opened p1-14)
        (opened p1-15)
        (opened p1-16)
        (opened p1-17)
        (opened p3-1)
        (opened p3-2)
        (opened p3-3)
        (opened p3-4)
        (opened p3-5)
        (opened p3-6)
        (opened p3-7)
        (opened p3-8)
        (opened p3-9)
        (opened p3-10)
        (opened p3-11)
        (opened p3-12)
        (opened p3-13)
        (opened p3-14)
        (opened p3-15)
        (opened p3-16)
        (opened p3-17)
        (opened p5-1)
        (opened p5-2)
        (opened p5-3)
        (opened p5-4)
        (opened p5-5)
        (opened p5-6)
        (opened p5-7)
        (opened p5-8)
        (opened p5-9)
        (opened p5-10)
        (opened p5-11)
        (opened p5-12)
        (opened p5-13)
        (opened p5-14)
        (opened p5-15)
        (opened p5-16)
        (opened p5-17)
        (opened p7-1)
        (opened p7-2)
        (opened p7-3)
        (opened p7-4)
        (opened p7-5)
        (opened p7-6)
        (opened p7-7)
        (opened p7-8)
        (opened p7-9)
        (opened p7-10)
        (opened p7-11)
        (opened p7-12)
        (opened p7-13)
        (opened p7-14)
        (opened p7-15)
        (opened p7-16)
        (opened p7-17)
        (opened p9-1)
        (opened p9-2)
        (opened p9-3)
        (opened p9-4)
        (opened p9-5)
        (opened p9-6)
        (opened p9-7)
        (opened p9-8)
        (opened p9-9)
        (opened p9-10)
        (opened p9-11)
        (opened p9-12)
        (opened p9-13)
        (opened p9-14)
        (opened p9-15)
        (opened p9-16)
        (opened p9-17)
        (opened p11-1)
        (opened p11-2)
        (opened p11-3)
        (opened p11-4)
        (opened p11-5)
        (opened p11-6)
        (opened p11-7)
        (opened p11-8)
        (opened p11-9)
        (opened p11-10)
        (opened p11-11)
        (opened p11-12)
        (opened p11-13)
        (opened p11-14)
        (opened p11-15)
        (opened p11-16)
        (opened p11-17)
        (opened p13-1)
        (opened p13-2)
        (opened p13-3)
        (opened p13-4)
        (opened p13-5)
        (opened p13-6)
        (opened p13-7)
        (opened p13-8)
        (opened p13-9)
        (opened p13-10)
        (opened p13-11)
        (opened p13-12)
        (opened p13-13)
        (opened p13-14)
        (opened p13-15)
        (opened p13-16)
        (opened p13-17)
        (opened p15-1)
        (opened p15-2)
        (opened p15-3)
        (opened p15-4)
        (opened p15-5)
        (opened p15-6)
        (opened p15-7)
        (opened p15-8)
        (opened p15-9)
        (opened p15-10)
        (opened p15-11)
        (opened p15-12)
        (opened p15-13)
        (opened p15-14)
        (opened p15-15)
        (opened p15-16)
        (opened p15-17)
        (opened p17-1)
        (opened p17-2)
        (opened p17-3)
        (opened p17-4)
        (opened p17-5)
        (opened p17-6)
        (opened p17-7)
        (opened p17-8)
        (opened p17-9)
        (opened p17-10)
        (opened p17-11)
        (opened p17-12)
        (opened p17-13)
        (opened p17-14)
        (opened p17-15)
        (opened p17-16)
        (opened p17-17)
    )
    (:goal (at p17-9))
)

