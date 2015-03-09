(define (problem colorballs-6-2)
    (:domain colorballs)
    (:objects
        o1 o2 - obj 
        p1-1 p1-2 p1-3 p1-4 p1-5 p1-6
        p2-1 p2-2 p2-3 p2-4 p2-5 p2-6
        p3-1 p3-2 p3-3 p3-4 p3-5 p3-6
        p4-1 p4-2 p4-3 p4-4 p4-5 p4-6
        p5-1 p5-2 p5-3 p5-4 p5-5 p5-6
        p6-1 p6-2 p6-3 p6-4 p6-5 p6-6 - pos
        red blue purple green - col 
        t1 t2 t3 t4 - gar 
    )
    (:init
        (adj p1-1 p1-2) (adj p1-2 p1-1)
        (adj p1-1 p2-1) (adj p2-1 p1-1)
        (adj p1-2 p1-3) (adj p1-3 p1-2)
        (adj p1-2 p2-2) (adj p2-2 p1-2)
        (adj p1-3 p1-4) (adj p1-4 p1-3)
        (adj p1-3 p2-3) (adj p2-3 p1-3)
        (adj p1-4 p1-5) (adj p1-5 p1-4)
        (adj p1-4 p2-4) (adj p2-4 p1-4)
        (adj p1-5 p1-6) (adj p1-6 p1-5)
        (adj p1-5 p2-5) (adj p2-5 p1-5)
        (adj p1-6 p2-6) (adj p2-6 p1-6)

        (adj p2-1 p2-2) (adj p2-2 p2-1)
        (adj p2-1 p3-1) (adj p3-1 p2-1)
        (adj p2-2 p2-3) (adj p2-3 p2-2)
        (adj p2-2 p3-2) (adj p3-2 p2-2)
        (adj p2-3 p2-4) (adj p2-4 p2-3)
        (adj p2-3 p3-3) (adj p3-3 p2-3)
        (adj p2-4 p2-5) (adj p2-5 p2-4)
        (adj p2-4 p3-4) (adj p3-4 p2-4)
        (adj p2-5 p2-6) (adj p2-6 p2-5)
        (adj p2-5 p3-5) (adj p3-5 p2-5)
        (adj p2-6 p3-6) (adj p3-6 p2-6)

        (adj p3-1 p3-2) (adj p3-2 p3-1)
        (adj p3-1 p4-1) (adj p4-1 p3-1)
        (adj p3-2 p3-3) (adj p3-3 p3-2)
        (adj p3-2 p4-2) (adj p4-2 p3-2)
        (adj p3-3 p3-4) (adj p3-4 p3-3)
        (adj p3-3 p4-3) (adj p4-3 p3-3)
        (adj p3-4 p3-5) (adj p3-5 p3-4)
        (adj p3-4 p4-4) (adj p4-4 p3-4)
        (adj p3-5 p3-6) (adj p3-6 p3-5)
        (adj p3-5 p4-5) (adj p4-5 p3-5)
        (adj p3-6 p4-6) (adj p4-6 p3-6)

        (adj p4-1 p4-2) (adj p4-2 p4-1)
        (adj p4-1 p5-1) (adj p5-1 p4-1)
        (adj p4-2 p4-3) (adj p4-3 p4-2)
        (adj p4-2 p5-2) (adj p5-2 p4-2)
        (adj p4-3 p4-4) (adj p4-4 p4-3)
        (adj p4-3 p5-3) (adj p5-3 p4-3)
        (adj p4-4 p4-5) (adj p4-5 p4-4)
        (adj p4-4 p5-4) (adj p5-4 p4-4)
        (adj p4-5 p4-6) (adj p4-6 p4-5)
        (adj p4-5 p5-5) (adj p5-5 p4-5)
        (adj p4-6 p5-6) (adj p5-6 p4-6)

        (adj p5-1 p5-2) (adj p5-2 p5-1)
        (adj p5-1 p6-1) (adj p6-1 p5-1)
        (adj p5-2 p5-3) (adj p5-3 p5-2)
        (adj p5-2 p6-2) (adj p6-2 p5-2)
        (adj p5-3 p5-4) (adj p5-4 p5-3)
        (adj p5-3 p6-3) (adj p6-3 p5-3)
        (adj p5-4 p5-5) (adj p5-5 p5-4)
        (adj p5-4 p6-4) (adj p6-4 p5-4)
        (adj p5-5 p5-6) (adj p5-6 p5-5)
        (adj p5-5 p6-5) (adj p6-5 p5-5)
        (adj p5-6 p6-6) (adj p6-6 p5-6)

        (adj p6-1 p6-2) (adj p6-2 p6-1)
        (adj p6-2 p6-3) (adj p6-3 p6-2)
        (adj p6-3 p6-4) (adj p6-4 p6-3)
        (adj p6-4 p6-5) (adj p6-5 p6-4)
        (adj p6-5 p6-6) (adj p6-6 p6-5)

        (garbage-at t1 p1-1)
        (garbage-at t2 p1-6)
        (garbage-at t3 p6-1)
        (garbage-at t4 p6-6)
        (garbage-color t1 red)
        (garbage-color t2 blue)
        (garbage-color t3 green)
        (garbage-color t4 purple)

        (at p3-3)
        (need-start)

        (not (obj-at o1 p1-1))
        (not (obj-at o1 p1-6))
        (not (obj-at o1 p6-1))
        (not (obj-at o1 p6-6))
        (not (obj-at o2 p1-1))
        (not (obj-at o2 p1-6))
        (not (obj-at o2 p6-1))
        (not (obj-at o2 p6-6))
    )
    ;(:goal (forall (?o - obj) (trashed ?o)))
    (:goal (and (trashed o1) (trashed o2)))
)
