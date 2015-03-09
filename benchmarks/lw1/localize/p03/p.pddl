(define (problem loc03)
    (:domain localize)
    (:objects
        p1-1 p1-2 p1-3
        p2-1 p2-2 p2-3
        p3-1 p3-2 p3-3 - pos
    )
    (:init
        (wall-down-of p1-1) (wall-left-of p1-1)
        (wall-up-of p2-1) (wall-down-of p2-1)
        (wall-right-of p3-1) (wall-down-of p3-1)
        (wall-right-of p1-2) (wall-left-of p1-2)
        (wall-right-of p3-2) (wall-left-of p3-2)
        (wall-up-of p1-3) (wall-left-of p1-3)
        (wall-up-of p2-3) (wall-down-of p2-3)
        (wall-up-of p3-3) (wall-right-of p3-3)

        (up-of p1-1 p1-2) (right-of p1-1 p2-1)
        (up-of p2-1 p2-2) (right-of p2-1 p3-1) (left-of p2-1 p1-1)
        (up-of p3-1 p3-2) (left-of p3-1 p2-1)
        (up-of p1-2 p1-3) (right-of p1-2 p2-2) (down-of p1-2 p1-1)
        (up-of p2-2 p2-3) (right-of p2-2 p3-2) (down-of p2-2 p2-1) (left-of p2-2 p1-2)
        (up-of p3-2 p3-3) (down-of p3-2 p3-1) (left-of p3-2 p2-2)
        (right-of p1-3 p2-3) (down-of p1-3 p1-2)
        (right-of p2-3 p3-3) (down-of p2-3 p2-2) (left-of p2-3 p1-3)
        (down-of p3-3 p3-2) (left-of p3-3 p2-3)

        (possible p1-1) (possible p2-1) (possible p3-1)
        (possible p1-2)                 (possible p3-2)
        (possible p1-3) (possible p2-3) (possible p3-3)
        
        (need-start)
    )
    (:goal (at p3-3))
)

