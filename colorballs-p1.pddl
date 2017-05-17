(define (problem colorballs-4-2)
    (:domain colorballs)
    (:objects
        o1 - obj ;o2 - obj 
        p1-1 p1-2 p1-3 p1-4
        p2-1 p2-2 p2-3 p2-4
        p3-1 p3-2 p3-3 p3-4
        p4-1 p4-2 p4-3 p4-4 - pos
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
        (adj p1-4 p2-4) (adj p2-4 p1-4)

        (adj p2-1 p2-2) (adj p2-2 p2-1)
        (adj p2-1 p3-1) (adj p3-1 p2-1)
        (adj p2-2 p2-3) (adj p2-3 p2-2)
        (adj p2-2 p3-2) (adj p3-2 p2-2)
        (adj p2-3 p2-4) (adj p2-4 p2-3)
        (adj p2-3 p3-3) (adj p3-3 p2-3)
        (adj p2-4 p3-4) (adj p3-4 p2-4)

        (adj p3-1 p3-2) (adj p3-2 p3-1)
        (adj p3-1 p4-1) (adj p4-1 p3-1)
        (adj p3-2 p3-3) (adj p3-3 p3-2)
        (adj p3-2 p4-2) (adj p4-2 p3-2)
        (adj p3-3 p3-4) (adj p3-4 p3-3)
        (adj p3-3 p4-3) (adj p4-3 p3-3)
        (adj p3-4 p4-4) (adj p4-4 p3-4)

        (adj p4-1 p4-2) (adj p4-2 p4-1)
        (adj p4-2 p4-3) (adj p4-3 p4-2)
        (adj p4-3 p4-4) (adj p4-4 p4-3)

        (garbage-at t1 p1-1)
        (garbage-at t2 p1-4)
        (garbage-at t3 p4-1)
        (garbage-at t4 p4-4)
        (garbage-color t1 red)
        (garbage-color t2 blue)
        (garbage-color t3 green)
        (garbage-color t4 purple)

        (at p2-2)
        (need-start)

        (not (trashed o1))
        ;(not (trashed o2))
        (not (holding o1))
        ;(not (holding o2))

        (not (obj-at o1 p1-1))
        (not (obj-at o1 p1-4))
        (not (obj-at o1 p4-1))
        (not (obj-at o1 p4-4))
        ;(not (obj-at o2 p1-1))
        ;(not (obj-at o2 p1-4))
        ;(not (obj-at o2 p4-1))
        ;(not (obj-at o2 p4-4))
    )
    ;(:goal (forall (?o - obj) (trashed ?o)))
    (:goal (and (trashed o1))); (trashed o2)))
)

