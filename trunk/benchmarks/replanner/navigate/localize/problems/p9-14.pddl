
(define (problem problem-9-14)
    (:domain localize-9)
    (:init
        ; possible initial locations
        (invariant (at p1-1) (at p1-2) (at p1-3) (at p1-4) (at p1-5) (at p1-6) (at p1-7) (at p1-8) (at p1-9) (at p2-1) (at p2-3) (at p2-5) (at p2-7) (at p2-9) (at p3-1) (at p3-3) (at p3-5) (at p3-7) (at p3-9) (at p4-1) (at p4-3) (at p4-5) (at p4-7) (at p4-9) (at p5-1) (at p5-3) (at p5-5) (at p5-7) (at p5-9) (at p6-1) (at p6-3) (at p6-5) (at p6-7) (at p6-9) (at p7-1) (at p7-3) (at p7-5) (at p7-7) (at p7-9) (at p8-1) (at p8-3) (at p8-5) (at p8-7) (at p8-9) (at p9-1) (at p9-2) (at p9-3) (at p9-4) (at p9-5) (at p9-6) (at p9-7) (at p9-8) (at p9-9))

        ; invariants
        (invariant (not (ok)) (free-up) (not (at p1-1)))
        (invariant (not (ok)) (free-right) (not (at p1-1)))
        (invariant (not (ok)) (not (free-down)) (not (at p1-1)))
        (invariant (not (ok)) (not (free-left)) (not (at p1-1)))
        (invariant (not (ok)) (free-up) (not (at p1-2)))
        (invariant (not (ok)) (not (free-right)) (not (at p1-2)))
        (invariant (not (ok)) (free-down) (not (at p1-2)))
        (invariant (not (ok)) (not (free-left)) (not (at p1-2)))
        (invariant (not (ok)) (free-up) (not (at p1-3)))
        (invariant (not (ok)) (free-right) (not (at p1-3)))
        (invariant (not (ok)) (free-down) (not (at p1-3)))
        (invariant (not (ok)) (not (free-left)) (not (at p1-3)))
        (invariant (not (ok)) (free-up) (not (at p1-4)))
        (invariant (not (ok)) (not (free-right)) (not (at p1-4)))
        (invariant (not (ok)) (free-down) (not (at p1-4)))
        (invariant (not (ok)) (not (free-left)) (not (at p1-4)))
        (invariant (not (ok)) (free-up) (not (at p1-5)))
        (invariant (not (ok)) (free-right) (not (at p1-5)))
        (invariant (not (ok)) (free-down) (not (at p1-5)))
        (invariant (not (ok)) (not (free-left)) (not (at p1-5)))
        (invariant (not (ok)) (free-up) (not (at p1-6)))
        (invariant (not (ok)) (not (free-right)) (not (at p1-6)))
        (invariant (not (ok)) (free-down) (not (at p1-6)))
        (invariant (not (ok)) (not (free-left)) (not (at p1-6)))
        (invariant (not (ok)) (free-up) (not (at p1-7)))
        (invariant (not (ok)) (free-right) (not (at p1-7)))
        (invariant (not (ok)) (free-down) (not (at p1-7)))
        (invariant (not (ok)) (not (free-left)) (not (at p1-7)))
        (invariant (not (ok)) (free-up) (not (at p1-8)))
        (invariant (not (ok)) (not (free-right)) (not (at p1-8)))
        (invariant (not (ok)) (free-down) (not (at p1-8)))
        (invariant (not (ok)) (not (free-left)) (not (at p1-8)))
        (invariant (not (ok)) (not (free-up)) (not (at p1-9)))
        (invariant (not (ok)) (free-right) (not (at p1-9)))
        (invariant (not (ok)) (free-down) (not (at p1-9)))
        (invariant (not (ok)) (not (free-left)) (not (at p1-9)))
        (invariant (not (ok)) (not (free-up)) (not (at p2-1)))
        (invariant (not (ok)) (free-right) (not (at p2-1)))
        (invariant (not (ok)) (not (free-down)) (not (at p2-1)))
        (invariant (not (ok)) (free-left) (not (at p2-1)))
        (invariant (not (ok)) (not (free-up)) (not (at p2-3)))
        (invariant (not (ok)) (free-right) (not (at p2-3)))
        (invariant (not (ok)) (not (free-down)) (not (at p2-3)))
        (invariant (not (ok)) (free-left) (not (at p2-3)))
        (invariant (not (ok)) (not (free-up)) (not (at p2-5)))
        (invariant (not (ok)) (free-right) (not (at p2-5)))
        (invariant (not (ok)) (not (free-down)) (not (at p2-5)))
        (invariant (not (ok)) (free-left) (not (at p2-5)))
        (invariant (not (ok)) (not (free-up)) (not (at p2-7)))
        (invariant (not (ok)) (free-right) (not (at p2-7)))
        (invariant (not (ok)) (not (free-down)) (not (at p2-7)))
        (invariant (not (ok)) (free-left) (not (at p2-7)))
        (invariant (not (ok)) (not (free-up)) (not (at p2-9)))
        (invariant (not (ok)) (free-right) (not (at p2-9)))
        (invariant (not (ok)) (not (free-down)) (not (at p2-9)))
        (invariant (not (ok)) (free-left) (not (at p2-9)))
        (invariant (not (ok)) (not (free-up)) (not (at p3-1)))
        (invariant (not (ok)) (free-right) (not (at p3-1)))
        (invariant (not (ok)) (not (free-down)) (not (at p3-1)))
        (invariant (not (ok)) (free-left) (not (at p3-1)))
        (invariant (not (ok)) (not (free-up)) (not (at p3-3)))
        (invariant (not (ok)) (free-right) (not (at p3-3)))
        (invariant (not (ok)) (not (free-down)) (not (at p3-3)))
        (invariant (not (ok)) (free-left) (not (at p3-3)))
        (invariant (not (ok)) (not (free-up)) (not (at p3-5)))
        (invariant (not (ok)) (free-right) (not (at p3-5)))
        (invariant (not (ok)) (not (free-down)) (not (at p3-5)))
        (invariant (not (ok)) (free-left) (not (at p3-5)))
        (invariant (not (ok)) (not (free-up)) (not (at p3-7)))
        (invariant (not (ok)) (free-right) (not (at p3-7)))
        (invariant (not (ok)) (not (free-down)) (not (at p3-7)))
        (invariant (not (ok)) (free-left) (not (at p3-7)))
        (invariant (not (ok)) (not (free-up)) (not (at p3-9)))
        (invariant (not (ok)) (free-right) (not (at p3-9)))
        (invariant (not (ok)) (not (free-down)) (not (at p3-9)))
        (invariant (not (ok)) (free-left) (not (at p3-9)))
        (invariant (not (ok)) (not (free-up)) (not (at p4-1)))
        (invariant (not (ok)) (free-right) (not (at p4-1)))
        (invariant (not (ok)) (not (free-down)) (not (at p4-1)))
        (invariant (not (ok)) (free-left) (not (at p4-1)))
        (invariant (not (ok)) (not (free-up)) (not (at p4-3)))
        (invariant (not (ok)) (free-right) (not (at p4-3)))
        (invariant (not (ok)) (not (free-down)) (not (at p4-3)))
        (invariant (not (ok)) (free-left) (not (at p4-3)))
        (invariant (not (ok)) (not (free-up)) (not (at p4-5)))
        (invariant (not (ok)) (free-right) (not (at p4-5)))
        (invariant (not (ok)) (not (free-down)) (not (at p4-5)))
        (invariant (not (ok)) (free-left) (not (at p4-5)))
        (invariant (not (ok)) (not (free-up)) (not (at p4-7)))
        (invariant (not (ok)) (free-right) (not (at p4-7)))
        (invariant (not (ok)) (not (free-down)) (not (at p4-7)))
        (invariant (not (ok)) (free-left) (not (at p4-7)))
        (invariant (not (ok)) (not (free-up)) (not (at p4-9)))
        (invariant (not (ok)) (free-right) (not (at p4-9)))
        (invariant (not (ok)) (not (free-down)) (not (at p4-9)))
        (invariant (not (ok)) (free-left) (not (at p4-9)))
        (invariant (not (ok)) (not (free-up)) (not (at p5-1)))
        (invariant (not (ok)) (free-right) (not (at p5-1)))
        (invariant (not (ok)) (not (free-down)) (not (at p5-1)))
        (invariant (not (ok)) (free-left) (not (at p5-1)))
        (invariant (not (ok)) (not (free-up)) (not (at p5-3)))
        (invariant (not (ok)) (free-right) (not (at p5-3)))
        (invariant (not (ok)) (not (free-down)) (not (at p5-3)))
        (invariant (not (ok)) (free-left) (not (at p5-3)))
        (invariant (not (ok)) (not (free-up)) (not (at p5-5)))
        (invariant (not (ok)) (free-right) (not (at p5-5)))
        (invariant (not (ok)) (not (free-down)) (not (at p5-5)))
        (invariant (not (ok)) (free-left) (not (at p5-5)))
        (invariant (not (ok)) (not (free-up)) (not (at p5-7)))
        (invariant (not (ok)) (free-right) (not (at p5-7)))
        (invariant (not (ok)) (not (free-down)) (not (at p5-7)))
        (invariant (not (ok)) (free-left) (not (at p5-7)))
        (invariant (not (ok)) (not (free-up)) (not (at p5-9)))
        (invariant (not (ok)) (free-right) (not (at p5-9)))
        (invariant (not (ok)) (not (free-down)) (not (at p5-9)))
        (invariant (not (ok)) (free-left) (not (at p5-9)))
        (invariant (not (ok)) (not (free-up)) (not (at p6-1)))
        (invariant (not (ok)) (free-right) (not (at p6-1)))
        (invariant (not (ok)) (not (free-down)) (not (at p6-1)))
        (invariant (not (ok)) (free-left) (not (at p6-1)))
        (invariant (not (ok)) (not (free-up)) (not (at p6-3)))
        (invariant (not (ok)) (free-right) (not (at p6-3)))
        (invariant (not (ok)) (not (free-down)) (not (at p6-3)))
        (invariant (not (ok)) (free-left) (not (at p6-3)))
        (invariant (not (ok)) (not (free-up)) (not (at p6-5)))
        (invariant (not (ok)) (free-right) (not (at p6-5)))
        (invariant (not (ok)) (not (free-down)) (not (at p6-5)))
        (invariant (not (ok)) (free-left) (not (at p6-5)))
        (invariant (not (ok)) (not (free-up)) (not (at p6-7)))
        (invariant (not (ok)) (free-right) (not (at p6-7)))
        (invariant (not (ok)) (not (free-down)) (not (at p6-7)))
        (invariant (not (ok)) (free-left) (not (at p6-7)))
        (invariant (not (ok)) (not (free-up)) (not (at p6-9)))
        (invariant (not (ok)) (free-right) (not (at p6-9)))
        (invariant (not (ok)) (not (free-down)) (not (at p6-9)))
        (invariant (not (ok)) (free-left) (not (at p6-9)))
        (invariant (not (ok)) (not (free-up)) (not (at p7-1)))
        (invariant (not (ok)) (free-right) (not (at p7-1)))
        (invariant (not (ok)) (not (free-down)) (not (at p7-1)))
        (invariant (not (ok)) (free-left) (not (at p7-1)))
        (invariant (not (ok)) (not (free-up)) (not (at p7-3)))
        (invariant (not (ok)) (free-right) (not (at p7-3)))
        (invariant (not (ok)) (not (free-down)) (not (at p7-3)))
        (invariant (not (ok)) (free-left) (not (at p7-3)))
        (invariant (not (ok)) (not (free-up)) (not (at p7-5)))
        (invariant (not (ok)) (free-right) (not (at p7-5)))
        (invariant (not (ok)) (not (free-down)) (not (at p7-5)))
        (invariant (not (ok)) (free-left) (not (at p7-5)))
        (invariant (not (ok)) (not (free-up)) (not (at p7-7)))
        (invariant (not (ok)) (free-right) (not (at p7-7)))
        (invariant (not (ok)) (not (free-down)) (not (at p7-7)))
        (invariant (not (ok)) (free-left) (not (at p7-7)))
        (invariant (not (ok)) (not (free-up)) (not (at p7-9)))
        (invariant (not (ok)) (free-right) (not (at p7-9)))
        (invariant (not (ok)) (not (free-down)) (not (at p7-9)))
        (invariant (not (ok)) (free-left) (not (at p7-9)))
        (invariant (not (ok)) (not (free-up)) (not (at p8-1)))
        (invariant (not (ok)) (free-right) (not (at p8-1)))
        (invariant (not (ok)) (not (free-down)) (not (at p8-1)))
        (invariant (not (ok)) (free-left) (not (at p8-1)))
        (invariant (not (ok)) (not (free-up)) (not (at p8-3)))
        (invariant (not (ok)) (free-right) (not (at p8-3)))
        (invariant (not (ok)) (not (free-down)) (not (at p8-3)))
        (invariant (not (ok)) (free-left) (not (at p8-3)))
        (invariant (not (ok)) (not (free-up)) (not (at p8-5)))
        (invariant (not (ok)) (free-right) (not (at p8-5)))
        (invariant (not (ok)) (not (free-down)) (not (at p8-5)))
        (invariant (not (ok)) (free-left) (not (at p8-5)))
        (invariant (not (ok)) (not (free-up)) (not (at p8-7)))
        (invariant (not (ok)) (free-right) (not (at p8-7)))
        (invariant (not (ok)) (not (free-down)) (not (at p8-7)))
        (invariant (not (ok)) (free-left) (not (at p8-7)))
        (invariant (not (ok)) (not (free-up)) (not (at p8-9)))
        (invariant (not (ok)) (free-right) (not (at p8-9)))
        (invariant (not (ok)) (not (free-down)) (not (at p8-9)))
        (invariant (not (ok)) (free-left) (not (at p8-9)))
        (invariant (not (ok)) (free-up) (not (at p9-1)))
        (invariant (not (ok)) (not (free-right)) (not (at p9-1)))
        (invariant (not (ok)) (not (free-down)) (not (at p9-1)))
        (invariant (not (ok)) (free-left) (not (at p9-1)))
        (invariant (not (ok)) (free-up) (not (at p9-2)))
        (invariant (not (ok)) (not (free-right)) (not (at p9-2)))
        (invariant (not (ok)) (free-down) (not (at p9-2)))
        (invariant (not (ok)) (not (free-left)) (not (at p9-2)))
        (invariant (not (ok)) (free-up) (not (at p9-3)))
        (invariant (not (ok)) (not (free-right)) (not (at p9-3)))
        (invariant (not (ok)) (free-down) (not (at p9-3)))
        (invariant (not (ok)) (free-left) (not (at p9-3)))
        (invariant (not (ok)) (free-up) (not (at p9-4)))
        (invariant (not (ok)) (not (free-right)) (not (at p9-4)))
        (invariant (not (ok)) (free-down) (not (at p9-4)))
        (invariant (not (ok)) (not (free-left)) (not (at p9-4)))
        (invariant (not (ok)) (free-up) (not (at p9-5)))
        (invariant (not (ok)) (not (free-right)) (not (at p9-5)))
        (invariant (not (ok)) (free-down) (not (at p9-5)))
        (invariant (not (ok)) (free-left) (not (at p9-5)))
        (invariant (not (ok)) (free-up) (not (at p9-6)))
        (invariant (not (ok)) (not (free-right)) (not (at p9-6)))
        (invariant (not (ok)) (free-down) (not (at p9-6)))
        (invariant (not (ok)) (not (free-left)) (not (at p9-6)))
        (invariant (not (ok)) (free-up) (not (at p9-7)))
        (invariant (not (ok)) (not (free-right)) (not (at p9-7)))
        (invariant (not (ok)) (free-down) (not (at p9-7)))
        (invariant (not (ok)) (free-left) (not (at p9-7)))
        (invariant (not (ok)) (free-up) (not (at p9-8)))
        (invariant (not (ok)) (not (free-right)) (not (at p9-8)))
        (invariant (not (ok)) (free-down) (not (at p9-8)))
        (invariant (not (ok)) (not (free-left)) (not (at p9-8)))
        (invariant (not (ok)) (not (free-up)) (not (at p9-9)))
        (invariant (not (ok)) (not (free-right)) (not (at p9-9)))
        (invariant (not (ok)) (free-down) (not (at p9-9)))
        (invariant (not (ok)) (free-left) (not (at p9-9)))
    )
    (:hidden (at p6-3) (free-right) (free-left))
    (:goal (at p9-9))
)

