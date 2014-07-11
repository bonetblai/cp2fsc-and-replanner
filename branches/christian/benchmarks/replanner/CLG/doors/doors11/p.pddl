(define (problem doors-11)
(:domain doors)

 (:objects 
    p1-1
    p1-2
    p1-3
    p1-4
    p1-5
    p1-6
    p1-7
    p1-8
    p1-9
    p1-10
    p1-11
    p2-1
    p2-2
    p2-3
    p2-4
    p2-5
    p2-6
    p2-7
    p2-8
    p2-9
    p2-10
    p2-11
    p3-1
    p3-2
    p3-3
    p3-4
    p3-5
    p3-6
    p3-7
    p3-8
    p3-9
    p3-10
    p3-11
    p4-1
    p4-2
    p4-3
    p4-4
    p4-5
    p4-6
    p4-7
    p4-8
    p4-9
    p4-10
    p4-11
    p5-1
    p5-2
    p5-3
    p5-4
    p5-5
    p5-6
    p5-7
    p5-8
    p5-9
    p5-10
    p5-11
    p6-1
    p6-2
    p6-3
    p6-4
    p6-5
    p6-6
    p6-7
    p6-8
    p6-9
    p6-10
    p6-11
    p7-1
    p7-2
    p7-3
    p7-4
    p7-5
    p7-6
    p7-7
    p7-8
    p7-9
    p7-10
    p7-11
    p8-1
    p8-2
    p8-3
    p8-4
    p8-5
    p8-6
    p8-7
    p8-8
    p8-9
    p8-10
    p8-11
    p9-1
    p9-2
    p9-3
    p9-4
    p9-5
    p9-6
    p9-7
    p9-8
    p9-9
    p9-10
    p9-11
    p10-1
    p10-2
    p10-3
    p10-4
    p10-5
    p10-6
    p10-7
    p10-8
    p10-9
    p10-10
    p10-11
    p11-1
    p11-2
    p11-3
    p11-4
    p11-5
    p11-6
    p11-7
    p11-8
    p11-9
    p11-10
    p11-11

 - pos 
    )
   (:init
    (and
 (at p1-6)
     (adj p1-1 p2-1)
     (adj p2-1 p1-1)

     (adj p1-2 p2-2)
     (adj p2-2 p1-2)

     (adj p1-3 p2-3)
     (adj p2-3 p1-3)

     (adj p1-4 p2-4)
     (adj p2-4 p1-4)

     (adj p1-5 p2-5)
     (adj p2-5 p1-5)

     (adj p1-6 p2-6)
     (adj p2-6 p1-6)

     (adj p1-7 p2-7)
     (adj p2-7 p1-7)

     (adj p1-8 p2-8)
     (adj p2-8 p1-8)

     (adj p1-9 p2-9)
     (adj p2-9 p1-9)

     (adj p1-10 p2-10)
     (adj p2-10 p1-10)

     (adj p1-11 p2-11)
     (adj p2-11 p1-11)

     (adj p2-1 p3-1)
     (adj p3-1 p2-1)

     (adj p2-2 p3-2)
     (adj p3-2 p2-2)

     (adj p2-3 p3-3)
     (adj p3-3 p2-3)

     (adj p2-4 p3-4)
     (adj p3-4 p2-4)

     (adj p2-5 p3-5)
     (adj p3-5 p2-5)

     (adj p2-6 p3-6)
     (adj p3-6 p2-6)

     (adj p2-7 p3-7)
     (adj p3-7 p2-7)

     (adj p2-8 p3-8)
     (adj p3-8 p2-8)

     (adj p2-9 p3-9)
     (adj p3-9 p2-9)

     (adj p2-10 p3-10)
     (adj p3-10 p2-10)

     (adj p2-11 p3-11)
     (adj p3-11 p2-11)

     (adj p3-1 p4-1)
     (adj p4-1 p3-1)

     (adj p3-2 p4-2)
     (adj p4-2 p3-2)

     (adj p3-3 p4-3)
     (adj p4-3 p3-3)

     (adj p3-4 p4-4)
     (adj p4-4 p3-4)

     (adj p3-5 p4-5)
     (adj p4-5 p3-5)

     (adj p3-6 p4-6)
     (adj p4-6 p3-6)

     (adj p3-7 p4-7)
     (adj p4-7 p3-7)

     (adj p3-8 p4-8)
     (adj p4-8 p3-8)

     (adj p3-9 p4-9)
     (adj p4-9 p3-9)

     (adj p3-10 p4-10)
     (adj p4-10 p3-10)

     (adj p3-11 p4-11)
     (adj p4-11 p3-11)

     (adj p4-1 p5-1)
     (adj p5-1 p4-1)

     (adj p4-2 p5-2)
     (adj p5-2 p4-2)

     (adj p4-3 p5-3)
     (adj p5-3 p4-3)

     (adj p4-4 p5-4)
     (adj p5-4 p4-4)

     (adj p4-5 p5-5)
     (adj p5-5 p4-5)

     (adj p4-6 p5-6)
     (adj p5-6 p4-6)

     (adj p4-7 p5-7)
     (adj p5-7 p4-7)

     (adj p4-8 p5-8)
     (adj p5-8 p4-8)

     (adj p4-9 p5-9)
     (adj p5-9 p4-9)

     (adj p4-10 p5-10)
     (adj p5-10 p4-10)

     (adj p4-11 p5-11)
     (adj p5-11 p4-11)

     (adj p5-1 p6-1)
     (adj p6-1 p5-1)

     (adj p5-2 p6-2)
     (adj p6-2 p5-2)

     (adj p5-3 p6-3)
     (adj p6-3 p5-3)

     (adj p5-4 p6-4)
     (adj p6-4 p5-4)

     (adj p5-5 p6-5)
     (adj p6-5 p5-5)

     (adj p5-6 p6-6)
     (adj p6-6 p5-6)

     (adj p5-7 p6-7)
     (adj p6-7 p5-7)

     (adj p5-8 p6-8)
     (adj p6-8 p5-8)

     (adj p5-9 p6-9)
     (adj p6-9 p5-9)

     (adj p5-10 p6-10)
     (adj p6-10 p5-10)

     (adj p5-11 p6-11)
     (adj p6-11 p5-11)

     (adj p6-1 p7-1)
     (adj p7-1 p6-1)

     (adj p6-2 p7-2)
     (adj p7-2 p6-2)

     (adj p6-3 p7-3)
     (adj p7-3 p6-3)

     (adj p6-4 p7-4)
     (adj p7-4 p6-4)

     (adj p6-5 p7-5)
     (adj p7-5 p6-5)

     (adj p6-6 p7-6)
     (adj p7-6 p6-6)

     (adj p6-7 p7-7)
     (adj p7-7 p6-7)

     (adj p6-8 p7-8)
     (adj p7-8 p6-8)

     (adj p6-9 p7-9)
     (adj p7-9 p6-9)

     (adj p6-10 p7-10)
     (adj p7-10 p6-10)

     (adj p6-11 p7-11)
     (adj p7-11 p6-11)

     (adj p7-1 p8-1)
     (adj p8-1 p7-1)

     (adj p7-2 p8-2)
     (adj p8-2 p7-2)

     (adj p7-3 p8-3)
     (adj p8-3 p7-3)

     (adj p7-4 p8-4)
     (adj p8-4 p7-4)

     (adj p7-5 p8-5)
     (adj p8-5 p7-5)

     (adj p7-6 p8-6)
     (adj p8-6 p7-6)

     (adj p7-7 p8-7)
     (adj p8-7 p7-7)

     (adj p7-8 p8-8)
     (adj p8-8 p7-8)

     (adj p7-9 p8-9)
     (adj p8-9 p7-9)

     (adj p7-10 p8-10)
     (adj p8-10 p7-10)

     (adj p7-11 p8-11)
     (adj p8-11 p7-11)

     (adj p8-1 p9-1)
     (adj p9-1 p8-1)

     (adj p8-2 p9-2)
     (adj p9-2 p8-2)

     (adj p8-3 p9-3)
     (adj p9-3 p8-3)

     (adj p8-4 p9-4)
     (adj p9-4 p8-4)

     (adj p8-5 p9-5)
     (adj p9-5 p8-5)

     (adj p8-6 p9-6)
     (adj p9-6 p8-6)

     (adj p8-7 p9-7)
     (adj p9-7 p8-7)

     (adj p8-8 p9-8)
     (adj p9-8 p8-8)

     (adj p8-9 p9-9)
     (adj p9-9 p8-9)

     (adj p8-10 p9-10)
     (adj p9-10 p8-10)

     (adj p8-11 p9-11)
     (adj p9-11 p8-11)

     (adj p9-1 p10-1)
     (adj p10-1 p9-1)

     (adj p9-2 p10-2)
     (adj p10-2 p9-2)

     (adj p9-3 p10-3)
     (adj p10-3 p9-3)

     (adj p9-4 p10-4)
     (adj p10-4 p9-4)

     (adj p9-5 p10-5)
     (adj p10-5 p9-5)

     (adj p9-6 p10-6)
     (adj p10-6 p9-6)

     (adj p9-7 p10-7)
     (adj p10-7 p9-7)

     (adj p9-8 p10-8)
     (adj p10-8 p9-8)

     (adj p9-9 p10-9)
     (adj p10-9 p9-9)

     (adj p9-10 p10-10)
     (adj p10-10 p9-10)

     (adj p9-11 p10-11)
     (adj p10-11 p9-11)

     (adj p10-1 p11-1)
     (adj p11-1 p10-1)

     (adj p10-2 p11-2)
     (adj p11-2 p10-2)

     (adj p10-3 p11-3)
     (adj p11-3 p10-3)

     (adj p10-4 p11-4)
     (adj p11-4 p10-4)

     (adj p10-5 p11-5)
     (adj p11-5 p10-5)

     (adj p10-6 p11-6)
     (adj p11-6 p10-6)

     (adj p10-7 p11-7)
     (adj p11-7 p10-7)

     (adj p10-8 p11-8)
     (adj p11-8 p10-8)

     (adj p10-9 p11-9)
     (adj p11-9 p10-9)

     (adj p10-10 p11-10)
     (adj p11-10 p10-10)

     (adj p10-11 p11-11)
     (adj p11-11 p10-11)


     (adj p1-1 p1-2)
     (adj p1-2 p1-1)

     (adj p2-1 p2-2)
     (adj p2-2 p2-1)

     (adj p3-1 p3-2)
     (adj p3-2 p3-1)

     (adj p4-1 p4-2)
     (adj p4-2 p4-1)

     (adj p5-1 p5-2)
     (adj p5-2 p5-1)

     (adj p6-1 p6-2)
     (adj p6-2 p6-1)

     (adj p7-1 p7-2)
     (adj p7-2 p7-1)

     (adj p8-1 p8-2)
     (adj p8-2 p8-1)

     (adj p9-1 p9-2)
     (adj p9-2 p9-1)

     (adj p10-1 p10-2)
     (adj p10-2 p10-1)

     (adj p11-1 p11-2)
     (adj p11-2 p11-1)

     (adj p1-2 p1-3)
     (adj p1-3 p1-2)

     (adj p2-2 p2-3)
     (adj p2-3 p2-2)

     (adj p3-2 p3-3)
     (adj p3-3 p3-2)

     (adj p4-2 p4-3)
     (adj p4-3 p4-2)

     (adj p5-2 p5-3)
     (adj p5-3 p5-2)

     (adj p6-2 p6-3)
     (adj p6-3 p6-2)

     (adj p7-2 p7-3)
     (adj p7-3 p7-2)

     (adj p8-2 p8-3)
     (adj p8-3 p8-2)

     (adj p9-2 p9-3)
     (adj p9-3 p9-2)

     (adj p10-2 p10-3)
     (adj p10-3 p10-2)

     (adj p11-2 p11-3)
     (adj p11-3 p11-2)

     (adj p1-3 p1-4)
     (adj p1-4 p1-3)

     (adj p2-3 p2-4)
     (adj p2-4 p2-3)

     (adj p3-3 p3-4)
     (adj p3-4 p3-3)

     (adj p4-3 p4-4)
     (adj p4-4 p4-3)

     (adj p5-3 p5-4)
     (adj p5-4 p5-3)

     (adj p6-3 p6-4)
     (adj p6-4 p6-3)

     (adj p7-3 p7-4)
     (adj p7-4 p7-3)

     (adj p8-3 p8-4)
     (adj p8-4 p8-3)

     (adj p9-3 p9-4)
     (adj p9-4 p9-3)

     (adj p10-3 p10-4)
     (adj p10-4 p10-3)

     (adj p11-3 p11-4)
     (adj p11-4 p11-3)

     (adj p1-4 p1-5)
     (adj p1-5 p1-4)

     (adj p2-4 p2-5)
     (adj p2-5 p2-4)

     (adj p3-4 p3-5)
     (adj p3-5 p3-4)

     (adj p4-4 p4-5)
     (adj p4-5 p4-4)

     (adj p5-4 p5-5)
     (adj p5-5 p5-4)

     (adj p6-4 p6-5)
     (adj p6-5 p6-4)

     (adj p7-4 p7-5)
     (adj p7-5 p7-4)

     (adj p8-4 p8-5)
     (adj p8-5 p8-4)

     (adj p9-4 p9-5)
     (adj p9-5 p9-4)

     (adj p10-4 p10-5)
     (adj p10-5 p10-4)

     (adj p11-4 p11-5)
     (adj p11-5 p11-4)

     (adj p1-5 p1-6)
     (adj p1-6 p1-5)

     (adj p2-5 p2-6)
     (adj p2-6 p2-5)

     (adj p3-5 p3-6)
     (adj p3-6 p3-5)

     (adj p4-5 p4-6)
     (adj p4-6 p4-5)

     (adj p5-5 p5-6)
     (adj p5-6 p5-5)

     (adj p6-5 p6-6)
     (adj p6-6 p6-5)

     (adj p7-5 p7-6)
     (adj p7-6 p7-5)

     (adj p8-5 p8-6)
     (adj p8-6 p8-5)

     (adj p9-5 p9-6)
     (adj p9-6 p9-5)

     (adj p10-5 p10-6)
     (adj p10-6 p10-5)

     (adj p11-5 p11-6)
     (adj p11-6 p11-5)

     (adj p1-6 p1-7)
     (adj p1-7 p1-6)

     (adj p2-6 p2-7)
     (adj p2-7 p2-6)

     (adj p3-6 p3-7)
     (adj p3-7 p3-6)

     (adj p4-6 p4-7)
     (adj p4-7 p4-6)

     (adj p5-6 p5-7)
     (adj p5-7 p5-6)

     (adj p6-6 p6-7)
     (adj p6-7 p6-6)

     (adj p7-6 p7-7)
     (adj p7-7 p7-6)

     (adj p8-6 p8-7)
     (adj p8-7 p8-6)

     (adj p9-6 p9-7)
     (adj p9-7 p9-6)

     (adj p10-6 p10-7)
     (adj p10-7 p10-6)

     (adj p11-6 p11-7)
     (adj p11-7 p11-6)

     (adj p1-7 p1-8)
     (adj p1-8 p1-7)

     (adj p2-7 p2-8)
     (adj p2-8 p2-7)

     (adj p3-7 p3-8)
     (adj p3-8 p3-7)

     (adj p4-7 p4-8)
     (adj p4-8 p4-7)

     (adj p5-7 p5-8)
     (adj p5-8 p5-7)

     (adj p6-7 p6-8)
     (adj p6-8 p6-7)

     (adj p7-7 p7-8)
     (adj p7-8 p7-7)

     (adj p8-7 p8-8)
     (adj p8-8 p8-7)

     (adj p9-7 p9-8)
     (adj p9-8 p9-7)

     (adj p10-7 p10-8)
     (adj p10-8 p10-7)

     (adj p11-7 p11-8)
     (adj p11-8 p11-7)

     (adj p1-8 p1-9)
     (adj p1-9 p1-8)

     (adj p2-8 p2-9)
     (adj p2-9 p2-8)

     (adj p3-8 p3-9)
     (adj p3-9 p3-8)

     (adj p4-8 p4-9)
     (adj p4-9 p4-8)

     (adj p5-8 p5-9)
     (adj p5-9 p5-8)

     (adj p6-8 p6-9)
     (adj p6-9 p6-8)

     (adj p7-8 p7-9)
     (adj p7-9 p7-8)

     (adj p8-8 p8-9)
     (adj p8-9 p8-8)

     (adj p9-8 p9-9)
     (adj p9-9 p9-8)

     (adj p10-8 p10-9)
     (adj p10-9 p10-8)

     (adj p11-8 p11-9)
     (adj p11-9 p11-8)

     (adj p1-9 p1-10)
     (adj p1-10 p1-9)

     (adj p2-9 p2-10)
     (adj p2-10 p2-9)

     (adj p3-9 p3-10)
     (adj p3-10 p3-9)

     (adj p4-9 p4-10)
     (adj p4-10 p4-9)

     (adj p5-9 p5-10)
     (adj p5-10 p5-9)

     (adj p6-9 p6-10)
     (adj p6-10 p6-9)

     (adj p7-9 p7-10)
     (adj p7-10 p7-9)

     (adj p8-9 p8-10)
     (adj p8-10 p8-9)

     (adj p9-9 p9-10)
     (adj p9-10 p9-9)

     (adj p10-9 p10-10)
     (adj p10-10 p10-9)

     (adj p11-9 p11-10)
     (adj p11-10 p11-9)

     (adj p1-10 p1-11)
     (adj p1-11 p1-10)

     (adj p2-10 p2-11)
     (adj p2-11 p2-10)

     (adj p3-10 p3-11)
     (adj p3-11 p3-10)

     (adj p4-10 p4-11)
     (adj p4-11 p4-10)

     (adj p5-10 p5-11)
     (adj p5-11 p5-10)

     (adj p6-10 p6-11)
     (adj p6-11 p6-10)

     (adj p7-10 p7-11)
     (adj p7-11 p7-10)

     (adj p8-10 p8-11)
     (adj p8-11 p8-10)

     (adj p9-10 p9-11)
     (adj p9-11 p9-10)

     (adj p10-10 p10-11)
     (adj p10-11 p10-10)

     (adj p11-10 p11-11)
     (adj p11-11 p11-10)


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
     (oneof
        (opened p2-1)
        (opened p2-2)
        (opened p2-3)
        (opened p2-4)
        (opened p2-5)
        (opened p2-6)
        (opened p2-7)
        (opened p2-8)
        (opened p2-9)
        (opened p2-10)
        (opened p2-11)
     )
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
     (oneof
        (opened p4-1)
        (opened p4-2)
        (opened p4-3)
        (opened p4-4)
        (opened p4-5)
        (opened p4-6)
        (opened p4-7)
        (opened p4-8)
        (opened p4-9)
        (opened p4-10)
        (opened p4-11)
     )
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
     (oneof
        (opened p6-1)
        (opened p6-2)
        (opened p6-3)
        (opened p6-4)
        (opened p6-5)
        (opened p6-6)
        (opened p6-7)
        (opened p6-8)
        (opened p6-9)
        (opened p6-10)
        (opened p6-11)
     )
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
     (oneof
        (opened p8-1)
        (opened p8-2)
        (opened p8-3)
        (opened p8-4)
        (opened p8-5)
        (opened p8-6)
        (opened p8-7)
        (opened p8-8)
        (opened p8-9)
        (opened p8-10)
        (opened p8-11)
     )
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
     (oneof
        (opened p10-1)
        (opened p10-2)
        (opened p10-3)
        (opened p10-4)
        (opened p10-5)
        (opened p10-6)
        (opened p10-7)
        (opened p10-8)
        (opened p10-9)
        (opened p10-10)
        (opened p10-11)
     )
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

    )
    )
    (:goal (and (at p11-6))
))
