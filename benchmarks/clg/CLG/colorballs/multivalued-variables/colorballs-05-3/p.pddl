(define (problem colorballs-5-3)
    (:domain colorballs)
    (:objects
        o1 o2 o3 - obj 
        p1-1 p1-2 p1-3 p1-4 p1-5
        p2-1 p2-2 p2-3 p2-4 p2-5
        p3-1 p3-2 p3-3 p3-4 p3-5
        p4-1 p4-2 p4-3 p4-4 p4-5
        p5-1 p5-2 p5-3 p5-4 p5-5 - pos
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
        (adj p1-5 p2-5) (adj p2-5 p1-5)

        (adj p2-1 p2-2) (adj p2-2 p2-1)
        (adj p2-1 p3-1) (adj p3-1 p2-1)
        (adj p2-2 p2-3) (adj p2-3 p2-2)
        (adj p2-2 p3-2) (adj p3-2 p2-2)
        (adj p2-3 p2-4) (adj p2-4 p2-3)
        (adj p2-3 p3-3) (adj p3-3 p2-3)
        (adj p2-4 p2-5) (adj p2-5 p2-4)
        (adj p2-4 p3-4) (adj p3-4 p2-4)
        (adj p2-5 p3-5) (adj p3-5 p2-5)

        (adj p3-1 p3-2) (adj p3-2 p3-1)
        (adj p3-1 p4-1) (adj p4-1 p3-1)
        (adj p3-2 p3-3) (adj p3-3 p3-2)
        (adj p3-2 p4-2) (adj p4-2 p3-2)
        (adj p3-3 p3-4) (adj p3-4 p3-3)
        (adj p3-3 p4-3) (adj p4-3 p3-3)
        (adj p3-4 p3-5) (adj p3-5 p3-4)
        (adj p3-4 p4-4) (adj p4-4 p3-4)
        (adj p3-5 p4-5) (adj p4-5 p3-5)

        (adj p4-1 p4-2) (adj p4-2 p4-1)
        (adj p4-1 p5-1) (adj p5-1 p4-1)
        (adj p4-2 p4-3) (adj p4-3 p4-2)
        (adj p4-2 p5-2) (adj p5-2 p4-2)
        (adj p4-3 p4-4) (adj p4-4 p4-3)
        (adj p4-3 p5-3) (adj p5-3 p4-3)
        (adj p4-4 p4-5) (adj p4-5 p4-4)
        (adj p4-4 p5-4) (adj p5-4 p4-4)
        (adj p4-5 p5-5) (adj p5-5 p4-5)

        (adj p5-1 p5-2) (adj p5-2 p5-1)
        (adj p5-2 p5-3) (adj p5-3 p5-2)
        (adj p5-3 p5-4) (adj p5-4 p5-3)
        (adj p5-4 p5-5) (adj p5-5 p5-4)

        (garbage-at t1 p1-1)
        (garbage-at t2 p1-5)
        (garbage-at t3 p5-1)
        (garbage-at t4 p5-5)
        (garbage-color t1 red)
        (garbage-color t2 blue)
        (garbage-color t3 green)
        (garbage-color t4 purple)

        (at p3-3)
        (need-start)

        (not (obj-at o1 p1-1))
        (not (obj-at o1 p1-5))
        (not (obj-at o1 p5-1))
        (not (obj-at o1 p5-5))
        (not (obj-at o2 p1-1))
        (not (obj-at o2 p1-5))
        (not (obj-at o2 p5-1))
        (not (obj-at o2 p5-5))
        (not (obj-at o3 p1-1))
        (not (obj-at o3 p1-5))
        (not (obj-at o3 p5-1))
        (not (obj-at o3 p5-5))
    )
    ;(:goal (forall (?o - obj) (trashed ?o)))
    (:goal (and (trashed o1) (trashed o2) (trashed o3)))
)

