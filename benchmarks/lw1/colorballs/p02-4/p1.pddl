(define (problem colorballs-2-4)
    (:domain colorballs)
    (:objects
        o1 o2 o3 o4 - obj 
        p1-1 p1-2
        p2-1 p2-2 - pos
        red blue purple green - col 
        t1 t2 t3 t4 - gar 
    )
    (:init
        (adj p1-1 p1-2) (adj p1-2 p1-1)
        (adj p1-1 p2-1) (adj p2-1 p1-1)
        (adj p1-2 p2-2) (adj p2-2 p1-2)
        (adj p2-1 p2-2) (adj p2-2 p2-1)

        (garbage-at t1 p1-1)
        (garbage-at t2 p1-2)
        (garbage-at t3 p2-1)
        (garbage-at t4 p2-2)
        (garbage-color t1 red)
        (garbage-color t2 blue)
        (garbage-color t3 green)
        (garbage-color t4 purple)

        (at p1-1)
        (need-start)

        (not (trashed o1))
        (not (trashed o2))
        (not (trashed o3))
        (not (trashed o4))
    )
    ;(:goal (forall (?o - obj) (trashed ?o)))
    (:goal (and (trashed o1) (trashed o2) (trashed o3)))
)

