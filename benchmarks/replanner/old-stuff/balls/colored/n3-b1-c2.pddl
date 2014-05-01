(define (problem n3-b1-c1)
    (:domain colored-balls)
    (:objects
        p1 p2 p3 - pos
        b1 - ball
        red blue - color)
    (:init
        (suc p1 p2) (suc p2 p3)
        (at p1 p1)
        (empty-arm)
        (spot p1 p1 red)
        (spot p3 p1 blue)
        (not (ball-at-spot b1))
        (invariant (ball-color b1 red) (ball-color b1 blue))
        (invariant (ball-at-spot b1)
                   (ball-pos b1 p1 p1) (ball-pos b1 p1 p2) (ball-pos b1 p1 p3)
                   (ball-pos b1 p2 p1) (ball-pos b1 p2 p2) (ball-pos b1 p2 p3)
                   (ball-pos b1 p3 p1) (ball-pos b1 p3 p2) (ball-pos b1 p3 p3))
    )
    (:hidden (ball-pos b1 p3 p3) (ball-color b1 blue))
    (:goal (ball-at-spot b1))
)
