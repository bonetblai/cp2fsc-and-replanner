(define (problem n4-w3)
    (:domain freespace)
    (:objects x1 x2 x3 x4 - xpos
              y1 y2 y3 y4 - ypos)
    (:init
        (suc-x x1 x2) (suc-x x2 x3) (suc-x x3 x4)
        (suc-y y1 y2) (suc-y y2 y3) (suc-y y3 y4)
        (at x1 y1)
        (invariant (wall x1 y1) (not (wall x1 y1)))
        (invariant (wall x1 y2) (not (wall x1 y2)))
        (invariant (wall x1 y3) (not (wall x1 y3)))
        (invariant (wall x1 y4) (not (wall x1 y4)))
        (invariant (wall x2 y1) (not (wall x2 y1)))
        (invariant (wall x2 y2) (not (wall x2 y2)))
        (invariant (wall x2 y3) (not (wall x2 y3)))
        (invariant (wall x2 y4) (not (wall x2 y4)))
        (invariant (wall x3 y1) (not (wall x3 y1)))
        (invariant (wall x3 y2) (not (wall x3 y2)))
        (invariant (wall x3 y3) (not (wall x3 y3)))
        (invariant (wall x3 y4) (not (wall x3 y4)))
        (invariant (wall x4 y1) (not (wall x4 y1)))
        (invariant (wall x4 y2) (not (wall x4 y2)))
        (invariant (wall x4 y3) (not (wall x4 y3)))
        (invariant (wall x4 y4) (not (wall x4 y4)))
    )
    (:hidden (wall x3 y1) (wall x3 y2) (wall x3 y3))
    (:goal (at x4 y4))  ;; goal position
)