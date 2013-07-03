
(define (problem problem-5-5-11922)
    (:domain RockSample)
    (:objects
        p0-0 p0-1 p0-2 p0-3 p0-4 p1-0 p1-1 p1-2 p1-3 p1-4 p2-0 p2-1 p2-2 p2-3 p2-4 p3-0 p3-1 p3-2 p3-3 p3-4 p4-0 p4-1 p4-2 p4-3 p4-4 - LOCATION
        r0 r1 r2 r3 r4 - ROCK
    )

    (:init
        ;; adjacencies
        (adj p0-0 p0-1) (adj p0-0 p1-0) (adj p0-1 p0-0) (adj p0-1 p0-2) (adj p0-1 p1-1) (adj p0-2 p0-1) (adj p0-2 p0-3) (adj p0-2 p1-2) (adj p0-3 p0-2) (adj p0-3 p0-4) (adj p0-3 p1-3) (adj p0-4 p0-3) (adj p0-4 p1-4) (adj p1-0 p0-0) (adj p1-0 p1-1) (adj p1-0 p2-0) (adj p1-1 p0-1) (adj p1-1 p1-0) (adj p1-1 p1-2) (adj p1-1 p2-1) (adj p1-2 p0-2) (adj p1-2 p1-1) (adj p1-2 p1-3) (adj p1-2 p2-2) (adj p1-3 p0-3) (adj p1-3 p1-2) (adj p1-3 p1-4) (adj p1-3 p2-3) (adj p1-4 p0-4) (adj p1-4 p1-3) (adj p1-4 p2-4) (adj p2-0 p1-0) (adj p2-0 p2-1) (adj p2-0 p3-0) (adj p2-1 p1-1) (adj p2-1 p2-0) (adj p2-1 p2-2) (adj p2-1 p3-1) (adj p2-2 p1-2) (adj p2-2 p2-1) (adj p2-2 p2-3) (adj p2-2 p3-2) (adj p2-3 p1-3) (adj p2-3 p2-2) (adj p2-3 p2-4) (adj p2-3 p3-3) (adj p2-4 p1-4) (adj p2-4 p2-3) (adj p2-4 p3-4) (adj p3-0 p2-0) (adj p3-0 p3-1) (adj p3-0 p4-0) (adj p3-1 p2-1) (adj p3-1 p3-0) (adj p3-1 p3-2) (adj p3-1 p4-1) (adj p3-2 p2-2) (adj p3-2 p3-1) (adj p3-2 p3-3) (adj p3-2 p4-2) (adj p3-3 p2-3) (adj p3-3 p3-2) (adj p3-3 p3-4) (adj p3-3 p4-3) (adj p3-4 p2-4) (adj p3-4 p3-3) (adj p3-4 p4-4) (adj p4-0 p3-0) (adj p4-0 p4-1) (adj p4-1 p3-1) (adj p4-1 p4-0) (adj p4-1 p4-2) (adj p4-2 p3-2) (adj p4-2 p4-1) (adj p4-2 p4-3) (adj p4-3 p3-3) (adj p4-3 p4-2) (adj p4-3 p4-4) (adj p4-4 p3-4) (adj p4-4 p4-3)

        ;; agent configuration
        (agent-at p2-2)
        (antenna-height h0)
        (not-sensing)

        ;; rock configuration
        (rock-at r0 p4-0)
        (invariant (good r0) (not (good r0)))
        (rock-at r1 p3-3)
        (invariant (good r1) (not (good r1)))
        (rock-at r2 p0-4)
        (invariant (good r2) (not (good r2)))
        (rock-at r3 p1-4)
        (invariant (good r3) (not (good r3)))
        (rock-at r4 p1-2)
        (invariant (good r4) (not (good r4)))

        ;; range calculation
        (in-range r0 p2-0 h2)
        (in-range r0 p3-0 h1)
        (in-range r0 p3-0 h2)
        (in-range r0 p3-1 h2)
        (in-range r0 p4-0 h0)
        (in-range r0 p4-0 h1)
        (in-range r0 p4-0 h2)
        (in-range r0 p4-1 h1)
        (in-range r0 p4-1 h2)
        (in-range r0 p4-2 h2)
        (in-range r1 p1-3 h2)
        (in-range r1 p2-2 h2)
        (in-range r1 p2-3 h1)
        (in-range r1 p2-3 h2)
        (in-range r1 p2-4 h2)
        (in-range r1 p3-1 h2)
        (in-range r1 p3-2 h1)
        (in-range r1 p3-2 h2)
        (in-range r1 p3-3 h0)
        (in-range r1 p3-3 h1)
        (in-range r1 p3-3 h2)
        (in-range r1 p3-4 h1)
        (in-range r1 p3-4 h2)
        (in-range r1 p4-2 h2)
        (in-range r1 p4-3 h1)
        (in-range r1 p4-3 h2)
        (in-range r1 p4-4 h2)
        (in-range r2 p0-2 h2)
        (in-range r2 p0-3 h1)
        (in-range r2 p0-3 h2)
        (in-range r2 p0-4 h0)
        (in-range r2 p0-4 h1)
        (in-range r2 p0-4 h2)
        (in-range r2 p1-3 h2)
        (in-range r2 p1-4 h1)
        (in-range r2 p1-4 h2)
        (in-range r2 p2-4 h2)
        (in-range r3 p0-3 h2)
        (in-range r3 p0-4 h1)
        (in-range r3 p0-4 h2)
        (in-range r3 p1-2 h2)
        (in-range r3 p1-3 h1)
        (in-range r3 p1-3 h2)
        (in-range r3 p1-4 h0)
        (in-range r3 p1-4 h1)
        (in-range r3 p1-4 h2)
        (in-range r3 p2-3 h2)
        (in-range r3 p2-4 h1)
        (in-range r3 p2-4 h2)
        (in-range r3 p3-4 h2)
        (in-range r4 p0-1 h2)
        (in-range r4 p0-2 h1)
        (in-range r4 p0-2 h2)
        (in-range r4 p0-3 h2)
        (in-range r4 p1-0 h2)
        (in-range r4 p1-1 h1)
        (in-range r4 p1-1 h2)
        (in-range r4 p1-2 h0)
        (in-range r4 p1-2 h1)
        (in-range r4 p1-2 h2)
        (in-range r4 p1-3 h1)
        (in-range r4 p1-3 h2)
        (in-range r4 p1-4 h2)
        (in-range r4 p2-1 h2)
        (in-range r4 p2-2 h1)
        (in-range r4 p2-2 h2)
        (in-range r4 p2-3 h2)
        (in-range r4 p3-2 h2)

        ;; invariants
        (invariant (not (good r0)) (good-rocks-in-range p2-0 h2))
        (invariant (not (good r0)) (good-rocks-in-range p3-0 h1))
        (invariant (not (good r0)) (good-rocks-in-range p3-0 h2))
        (invariant (not (good r0)) (good-rocks-in-range p3-1 h2))
        (invariant (not (good r0)) (good-rocks-in-range p4-0 h0))
        (invariant (not (good r0)) (good-rocks-in-range p4-0 h1))
        (invariant (not (good r0)) (good-rocks-in-range p4-0 h2))
        (invariant (not (good r0)) (good-rocks-in-range p4-1 h1))
        (invariant (not (good r0)) (good-rocks-in-range p4-1 h2))
        (invariant (not (good r0)) (good-rocks-in-range p4-2 h2))
        (invariant (not (good r1)) (good-rocks-in-range p1-3 h2))
        (invariant (not (good r1)) (good-rocks-in-range p2-2 h2))
        (invariant (not (good r1)) (good-rocks-in-range p2-3 h1))
        (invariant (not (good r1)) (good-rocks-in-range p2-3 h2))
        (invariant (not (good r1)) (good-rocks-in-range p2-4 h2))
        (invariant (not (good r1)) (good-rocks-in-range p3-1 h2))
        (invariant (not (good r1)) (good-rocks-in-range p3-2 h1))
        (invariant (not (good r1)) (good-rocks-in-range p3-2 h2))
        (invariant (not (good r1)) (good-rocks-in-range p3-3 h0))
        (invariant (not (good r1)) (good-rocks-in-range p3-3 h1))
        (invariant (not (good r1)) (good-rocks-in-range p3-3 h2))
        (invariant (not (good r1)) (good-rocks-in-range p3-4 h1))
        (invariant (not (good r1)) (good-rocks-in-range p3-4 h2))
        (invariant (not (good r1)) (good-rocks-in-range p4-2 h2))
        (invariant (not (good r1)) (good-rocks-in-range p4-3 h1))
        (invariant (not (good r1)) (good-rocks-in-range p4-3 h2))
        (invariant (not (good r1)) (good-rocks-in-range p4-4 h2))
        (invariant (not (good r2)) (good-rocks-in-range p0-2 h2))
        (invariant (not (good r2)) (good-rocks-in-range p0-3 h1))
        (invariant (not (good r2)) (good-rocks-in-range p0-3 h2))
        (invariant (not (good r2)) (good-rocks-in-range p0-4 h0))
        (invariant (not (good r2)) (good-rocks-in-range p0-4 h1))
        (invariant (not (good r2)) (good-rocks-in-range p0-4 h2))
        (invariant (not (good r2)) (good-rocks-in-range p1-3 h2))
        (invariant (not (good r2)) (good-rocks-in-range p1-4 h1))
        (invariant (not (good r2)) (good-rocks-in-range p1-4 h2))
        (invariant (not (good r2)) (good-rocks-in-range p2-4 h2))
        (invariant (not (good r3)) (good-rocks-in-range p0-3 h2))
        (invariant (not (good r3)) (good-rocks-in-range p0-4 h1))
        (invariant (not (good r3)) (good-rocks-in-range p0-4 h2))
        (invariant (not (good r3)) (good-rocks-in-range p1-2 h2))
        (invariant (not (good r3)) (good-rocks-in-range p1-3 h1))
        (invariant (not (good r3)) (good-rocks-in-range p1-3 h2))
        (invariant (not (good r3)) (good-rocks-in-range p1-4 h0))
        (invariant (not (good r3)) (good-rocks-in-range p1-4 h1))
        (invariant (not (good r3)) (good-rocks-in-range p1-4 h2))
        (invariant (not (good r3)) (good-rocks-in-range p2-3 h2))
        (invariant (not (good r3)) (good-rocks-in-range p2-4 h1))
        (invariant (not (good r3)) (good-rocks-in-range p2-4 h2))
        (invariant (not (good r3)) (good-rocks-in-range p3-4 h2))
        (invariant (not (good r4)) (good-rocks-in-range p0-1 h2))
        (invariant (not (good r4)) (good-rocks-in-range p0-2 h1))
        (invariant (not (good r4)) (good-rocks-in-range p0-2 h2))
        (invariant (not (good r4)) (good-rocks-in-range p0-3 h2))
        (invariant (not (good r4)) (good-rocks-in-range p1-0 h2))
        (invariant (not (good r4)) (good-rocks-in-range p1-1 h1))
        (invariant (not (good r4)) (good-rocks-in-range p1-1 h2))
        (invariant (not (good r4)) (good-rocks-in-range p1-2 h0))
        (invariant (not (good r4)) (good-rocks-in-range p1-2 h1))
        (invariant (not (good r4)) (good-rocks-in-range p1-2 h2))
        (invariant (not (good r4)) (good-rocks-in-range p1-3 h1))
        (invariant (not (good r4)) (good-rocks-in-range p1-3 h2))
        (invariant (not (good r4)) (good-rocks-in-range p1-4 h2))
        (invariant (not (good r4)) (good-rocks-in-range p2-1 h2))
        (invariant (not (good r4)) (good-rocks-in-range p2-2 h1))
        (invariant (not (good r4)) (good-rocks-in-range p2-2 h2))
        (invariant (not (good r4)) (good-rocks-in-range p2-3 h2))
        (invariant (not (good r4)) (good-rocks-in-range p3-2 h2))
        (invariant (not (good-rocks-in-range p0-1 h2)) (good r4))
        (invariant (not (good-rocks-in-range p0-2 h1)) (good r4))
        (invariant (not (good-rocks-in-range p0-2 h2)) (good r2) (good r4))
        (invariant (not (good-rocks-in-range p0-3 h1)) (good r2))
        (invariant (not (good-rocks-in-range p0-3 h2)) (good r2) (good r3) (good r4))
        (invariant (not (good-rocks-in-range p0-4 h0)) (good r2))
        (invariant (not (good-rocks-in-range p0-4 h1)) (good r2) (good r3))
        (invariant (not (good-rocks-in-range p0-4 h2)) (good r2) (good r3))
        (invariant (not (good-rocks-in-range p1-0 h2)) (good r4))
        (invariant (not (good-rocks-in-range p1-1 h1)) (good r4))
        (invariant (not (good-rocks-in-range p1-1 h2)) (good r4))
        (invariant (not (good-rocks-in-range p1-2 h0)) (good r4))
        (invariant (not (good-rocks-in-range p1-2 h1)) (good r4))
        (invariant (not (good-rocks-in-range p1-2 h2)) (good r3) (good r4))
        (invariant (not (good-rocks-in-range p1-3 h1)) (good r3) (good r4))
        (invariant (not (good-rocks-in-range p1-3 h2)) (good r1) (good r2) (good r3) (good r4))
        (invariant (not (good-rocks-in-range p1-4 h0)) (good r3))
        (invariant (not (good-rocks-in-range p1-4 h1)) (good r2) (good r3))
        (invariant (not (good-rocks-in-range p1-4 h2)) (good r2) (good r3) (good r4))
        (invariant (not (good-rocks-in-range p2-0 h2)) (good r0))
        (invariant (not (good-rocks-in-range p2-1 h2)) (good r4))
        (invariant (not (good-rocks-in-range p2-2 h1)) (good r4))
        (invariant (not (good-rocks-in-range p2-2 h2)) (good r1) (good r4))
        (invariant (not (good-rocks-in-range p2-3 h1)) (good r1))
        (invariant (not (good-rocks-in-range p2-3 h2)) (good r1) (good r3) (good r4))
        (invariant (not (good-rocks-in-range p2-4 h1)) (good r3))
        (invariant (not (good-rocks-in-range p2-4 h2)) (good r1) (good r2) (good r3))
        (invariant (not (good-rocks-in-range p3-0 h1)) (good r0))
        (invariant (not (good-rocks-in-range p3-0 h2)) (good r0))
        (invariant (not (good-rocks-in-range p3-1 h2)) (good r0) (good r1))
        (invariant (not (good-rocks-in-range p3-2 h1)) (good r1))
        (invariant (not (good-rocks-in-range p3-2 h2)) (good r1) (good r4))
        (invariant (not (good-rocks-in-range p3-3 h0)) (good r1))
        (invariant (not (good-rocks-in-range p3-3 h1)) (good r1))
        (invariant (not (good-rocks-in-range p3-3 h2)) (good r1))
        (invariant (not (good-rocks-in-range p3-4 h1)) (good r1))
        (invariant (not (good-rocks-in-range p3-4 h2)) (good r1) (good r3))
        (invariant (not (good-rocks-in-range p4-0 h0)) (good r0))
        (invariant (not (good-rocks-in-range p4-0 h1)) (good r0))
        (invariant (not (good-rocks-in-range p4-0 h2)) (good r0))
        (invariant (not (good-rocks-in-range p4-1 h1)) (good r0))
        (invariant (not (good-rocks-in-range p4-1 h2)) (good r0))
        (invariant (not (good-rocks-in-range p4-2 h2)) (good r0) (good r1))
        (invariant (not (good-rocks-in-range p4-3 h1)) (good r1))
        (invariant (not (good-rocks-in-range p4-3 h2)) (good r1))
        (invariant (not (good-rocks-in-range p4-4 h2)) (good r1))
    )

    (:hidden
        (good r1)
        (good-rocks-in-range p1-3 h2)
        (good-rocks-in-range p2-2 h2)
        (good-rocks-in-range p2-3 h1)
        (good-rocks-in-range p2-3 h2)
        (good-rocks-in-range p2-4 h2)
        (good-rocks-in-range p3-1 h2)
        (good-rocks-in-range p3-2 h1)
        (good-rocks-in-range p3-2 h2)
        (good-rocks-in-range p3-3 h0)
        (good-rocks-in-range p3-3 h1)
        (good-rocks-in-range p3-3 h2)
        (good-rocks-in-range p3-4 h1)
        (good-rocks-in-range p3-4 h2)
        (good-rocks-in-range p4-2 h2)
        (good-rocks-in-range p4-3 h1)
        (good-rocks-in-range p4-3 h2)
        (good-rocks-in-range p4-4 h2)
        (good r2)
        (good-rocks-in-range p0-2 h2)
        (good-rocks-in-range p0-3 h1)
        (good-rocks-in-range p0-3 h2)
        (good-rocks-in-range p0-4 h0)
        (good-rocks-in-range p0-4 h1)
        (good-rocks-in-range p0-4 h2)
        (good-rocks-in-range p1-3 h2)
        (good-rocks-in-range p1-4 h1)
        (good-rocks-in-range p1-4 h2)
        (good-rocks-in-range p2-4 h2)
        (good r3)
        (good-rocks-in-range p0-3 h2)
        (good-rocks-in-range p0-4 h1)
        (good-rocks-in-range p0-4 h2)
        (good-rocks-in-range p1-2 h2)
        (good-rocks-in-range p1-3 h1)
        (good-rocks-in-range p1-3 h2)
        (good-rocks-in-range p1-4 h0)
        (good-rocks-in-range p1-4 h1)
        (good-rocks-in-range p1-4 h2)
        (good-rocks-in-range p2-3 h2)
        (good-rocks-in-range p2-4 h1)
        (good-rocks-in-range p2-4 h2)
        (good-rocks-in-range p3-4 h2)
    )

    (:goal (and (done r0) (done r1) (done r2) (done r3) (done r4)))
)
