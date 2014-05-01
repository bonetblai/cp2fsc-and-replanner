(define (problem RockSample4-2)
    (:domain RockSample)
    (:objects
        h1 h2 - height
        p1-1 p1-2 p1-3 p1-4
        p2-1 p2-2 p2-3 p2-4
        p3-1 p3-2 p3-3 p3-4
        p4-1 p4-2 p4-3 p4-4 - location
        r0 r1 - rock
    )
    (:init
        (next-height h0 h1)
        (next-height h1 h2)

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

        (in-sensing-range h0 p1-1 p1-1)
        (in-sensing-range h0 p1-2 p1-2)
        (in-sensing-range h0 p1-3 p1-3)
        (in-sensing-range h0 p1-4 p1-4)
        (in-sensing-range h0 p2-1 p2-1)
        (in-sensing-range h0 p2-2 p2-2)
        (in-sensing-range h0 p2-3 p2-3)
        (in-sensing-range h0 p2-4 p2-4)
        (in-sensing-range h0 p3-1 p3-1)
        (in-sensing-range h0 p3-2 p3-2)
        (in-sensing-range h0 p3-3 p3-3)
        (in-sensing-range h0 p3-4 p3-4)
        (in-sensing-range h0 p4-1 p4-1)
        (in-sensing-range h0 p4-2 p4-2)
        (in-sensing-range h0 p4-3 p4-3)
        (in-sensing-range h0 p4-4 p4-4)

        ;; antenna height = 1 => senses good rocks at (euclidean) distance <= 1
        (in-sensing-range h1 p1-1 p1-1) (in-sensing-range h1 p1-1 p1-2) (in-sensing-range h1 p1-1 p2-1)
        (in-sensing-range h1 p1-2 p1-2) (in-sensing-range h1 p1-2 p1-1) (in-sensing-range h1 p1-2 p1-3) (in-sensing-range h1 p1-2 p2-2)
        (in-sensing-range h1 p1-3 p1-3) (in-sensing-range h1 p1-3 p1-2) (in-sensing-range h1 p1-3 p1-4) (in-sensing-range h1 p1-3 p2-3)
        (in-sensing-range h1 p1-4 p1-4) (in-sensing-range h1 p1-4 p1-3) (in-sensing-range h1 p1-4 p2-4)
        (in-sensing-range h1 p2-1 p2-1) (in-sensing-range h1 p2-1 p2-2) (in-sensing-range h1 p2-1 p1-1) (in-sensing-range h1 p2-1 p3-1)
        (in-sensing-range h1 p2-2 p2-2) (in-sensing-range h1 p2-2 p2-1) (in-sensing-range h1 p2-2 p2-3) (in-sensing-range h1 p2-2 p1-2) (in-sensing-range h1 p2-2 p3-2)
        (in-sensing-range h1 p2-3 p2-3) (in-sensing-range h1 p2-3 p2-2) (in-sensing-range h1 p2-3 p2-4) (in-sensing-range h1 p2-3 p1-3) (in-sensing-range h1 p2-3 p3-3)
        (in-sensing-range h1 p2-4 p2-4) (in-sensing-range h1 p2-4 p2-3) (in-sensing-range h1 p2-4 p1-4) (in-sensing-range h1 p2-4 p3-4)
        (in-sensing-range h1 p3-1 p3-1) (in-sensing-range h1 p3-1 p3-2) (in-sensing-range h1 p3-1 p2-1) (in-sensing-range h1 p3-1 p4-1)
        (in-sensing-range h1 p3-2 p3-2) (in-sensing-range h1 p3-2 p3-1) (in-sensing-range h1 p3-2 p3-3) (in-sensing-range h1 p3-2 p2-2) (in-sensing-range h1 p3-2 p4-2)
        (in-sensing-range h1 p3-3 p3-3) (in-sensing-range h1 p3-3 p3-2) (in-sensing-range h1 p3-3 p3-4) (in-sensing-range h1 p3-3 p2-3) (in-sensing-range h1 p3-3 p4-3)
        (in-sensing-range h1 p3-4 p3-4) (in-sensing-range h1 p3-4 p3-3) (in-sensing-range h1 p3-4 p2-4) (in-sensing-range h1 p3-4 p4-4)
        (in-sensing-range h1 p4-1 p4-1) (in-sensing-range h1 p4-1 p4-2) (in-sensing-range h1 p4-1 p3-1)
        (in-sensing-range h1 p4-2 p4-2) (in-sensing-range h1 p4-2 p4-1) (in-sensing-range h1 p4-2 p4-3) (in-sensing-range h1 p4-2 p3-2)
        (in-sensing-range h1 p4-3 p4-3) (in-sensing-range h1 p4-3 p4-2) (in-sensing-range h1 p4-3 p4-4) (in-sensing-range h1 p4-3 p3-3)
        (in-sensing-range h1 p4-4 p4-4) (in-sensing-range h1 p4-4 p4-3) (in-sensing-range h1 p4-4 p3-4)

        ;; (1,4)  (2,4)  (3,4)  (4,4)
        ;; (1,3)  (2,3)  (3,3)  (4,3)
        ;; (1,2)  (2,2)  (3,2)  (4,2)
        ;; (1,1)  (2,1)  (3,1)  (4,1)
        ;;
        ;; antenna height = 2 => senses good rocks at (euclidean) distance <= 2
        (in-sensing-range h2 p1-1 p1-1) (in-sensing-range h2 p1-1 p1-2) (in-sensing-range h2 p1-1 p2-1)
        (in-sensing-range h2 p1-1 p2-2)
        (in-sensing-range h2 p1-1 p1-3) (in-sensing-range h2 p1-1 p3-1)

        (in-sensing-range h2 p1-2 p1-2) (in-sensing-range h2 p1-2 p1-1) (in-sensing-range h2 p1-2 p1-3) (in-sensing-range h2 p1-2 p2-2)
        (in-sensing-range h2 p1-2 p2-1) (in-sensing-range h2 p1-2 p2-3)
        (in-sensing-range h2 p1-2 p1-4) (in-sensing-range h2 p1-2 p3-2)

        (in-sensing-range h2 p1-3 p1-3) (in-sensing-range h2 p1-3 p1-2) (in-sensing-range h2 p1-3 p1-4) (in-sensing-range h2 p1-3 p2-3)
        (in-sensing-range h2 p1-3 p2-2) (in-sensing-range h2 p1-3 p2-4)
        (in-sensing-range h2 p1-3 p1-1) (in-sensing-range h2 p1-3 p3-3)

        (in-sensing-range h2 p1-4 p1-4) (in-sensing-range h2 p1-4 p1-3) (in-sensing-range h2 p1-4 p2-4)
        (in-sensing-range h2 p1-4 p2-3)
        (in-sensing-range h2 p1-4 p1-2) (in-sensing-range h2 p1-4 p3-4)

        (in-sensing-range h2 p2-1 p2-1) (in-sensing-range h2 p2-1 p2-2) (in-sensing-range h2 p2-1 p1-1) (in-sensing-range h2 p2-1 p3-1)
        (in-sensing-range h2 p2-1 p1-2) (in-sensing-range h2 p2-1 p3-2)
        (in-sensing-range h2 p2-1 p2-3) (in-sensing-range h2 p2-1 p4-1)

        (in-sensing-range h2 p2-2 p2-2) (in-sensing-range h2 p2-2 p2-1) (in-sensing-range h2 p2-2 p2-3) (in-sensing-range h2 p2-2 p1-2) (in-sensing-range h2 p2-2 p3-2)
        (in-sensing-range h2 p2-2 p1-1) (in-sensing-range h2 p2-2 p3-1) (in-sensing-range h2 p2-2 p1-3) (in-sensing-range h2 p2-2 p3-3)
        (in-sensing-range h2 p2-2 p2-4) (in-sensing-range h2 p2-2 p4-2)

        (in-sensing-range h2 p2-3 p2-3) (in-sensing-range h2 p2-3 p2-2) (in-sensing-range h2 p2-3 p2-4) (in-sensing-range h2 p2-3 p1-3) (in-sensing-range h2 p2-3 p3-3)
        (in-sensing-range h2 p2-3 p1-2) (in-sensing-range h2 p2-3 p3-2) (in-sensing-range h2 p2-3 p1-4) (in-sensing-range h2 p2-3 p3-4)
        (in-sensing-range h2 p2-3 p2-1) (in-sensing-range h2 p2-3 p4-3)

        (in-sensing-range h2 p2-4 p2-4) (in-sensing-range h2 p2-4 p2-3) (in-sensing-range h2 p2-4 p1-4) (in-sensing-range h2 p2-4 p3-4)
        (in-sensing-range h2 p2-4 p1-3) (in-sensing-range h2 p2-4 p3-3)
        (in-sensing-range h2 p2-4 p2-2) (in-sensing-range h2 p2-4 p4-4)

        (in-sensing-range h2 p3-1 p3-1) (in-sensing-range h2 p3-1 p3-2) (in-sensing-range h2 p3-1 p2-1) (in-sensing-range h2 p3-1 p4-1)
        (in-sensing-range h2 p3-1 p2-2) (in-sensing-range h2 p3-1 p4-2)
        (in-sensing-range h2 p3-1 p3-3) (in-sensing-range h2 p3-1 p1-1)

        (in-sensing-range h2 p3-2 p3-2) (in-sensing-range h2 p3-2 p3-1) (in-sensing-range h2 p3-2 p3-3) (in-sensing-range h2 p3-2 p2-2) (in-sensing-range h2 p3-2 p4-2)
        (in-sensing-range h2 p3-2 p2-1) (in-sensing-range h2 p3-2 p4-1) (in-sensing-range h2 p3-2 p2-3) (in-sensing-range h2 p3-2 p4-3)
        (in-sensing-range h2 p3-2 p1-2) (in-sensing-range h2 p3-2 p3-4)

        (in-sensing-range h2 p3-3 p3-3) (in-sensing-range h2 p3-3 p3-2) (in-sensing-range h2 p3-3 p3-4) (in-sensing-range h2 p3-3 p2-3) (in-sensing-range h2 p3-3 p4-3)
        (in-sensing-range h2 p3-3 p2-2) (in-sensing-range h2 p3-3 p4-2) (in-sensing-range h2 p3-3 p2-4) (in-sensing-range h2 p3-3 p4-4)
        (in-sensing-range h2 p3-3 p3-1) (in-sensing-range h2 p3-3 p1-3)

        (in-sensing-range h2 p3-4 p3-4) (in-sensing-range h2 p3-4 p3-3) (in-sensing-range h2 p3-4 p2-4) (in-sensing-range h2 p3-4 p4-4)
        (in-sensing-range h2 p3-4 p2-3) (in-sensing-range h2 p3-4 p4-3)
        (in-sensing-range h2 p3-4 p3-2) (in-sensing-range h2 p3-4 p1-4)

        (in-sensing-range h2 p4-1 p4-1) (in-sensing-range h2 p4-1 p4-2) (in-sensing-range h2 p4-1 p3-1)
        (in-sensing-range h2 p4-1 p3-2)
        (in-sensing-range h2 p4-1 p4-3) (in-sensing-range h2 p4-1 p2-1)

        (in-sensing-range h2 p4-2 p4-2) (in-sensing-range h2 p4-2 p4-1) (in-sensing-range h2 p4-2 p4-3) (in-sensing-range h2 p4-2 p3-2)
        (in-sensing-range h2 p4-2 p3-1) (in-sensing-range h2 p4-2 p3-3)
        (in-sensing-range h2 p4-2 p4-4) (in-sensing-range h2 p4-2 p2-2)

        (in-sensing-range h2 p4-3 p4-3) (in-sensing-range h2 p4-3 p4-2) (in-sensing-range h2 p4-3 p4-4) (in-sensing-range h2 p4-3 p3-3)
        (in-sensing-range h2 p4-3 p3-2) (in-sensing-range h2 p4-3 p3-4)
        (in-sensing-range h2 p4-3 p4-1) (in-sensing-range h2 p4-3 p2-3)

        (in-sensing-range h2 p4-4 p4-4) (in-sensing-range h2 p4-4 p4-3) (in-sensing-range h2 p4-4 p3-4)
        (in-sensing-range h2 p4-4 p3-3)
        (in-sensing-range h2 p4-4 p4-2) (in-sensing-range h2 p4-4 p2-4)

        (agent-at p3-3)
        (antenna-height h0)
        ;(need-start)

        (rock-at r0 p4-2)
        (rock-at r1 p1-4)
    )
    (:goal (and (not (good r0)) (not (good r1))))
)

