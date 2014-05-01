
(define (problem problem-4-2-01)
    (:domain RockSample)
    (:objects
        p1-1 p1-2 p1-3 p1-4 p2-1 p2-2 p2-3 p2-4 p3-1 p3-2 p3-3 p3-4 p4-1 p4-2 p4-3 p4-4 - LOCATION
        r0 r1 - ROCK
    )

    (:init
	(adj p1-1 p1-2) (adj p1-1 p2-1)
	(adj p1-2 p1-1) (adj p1-2 p1-3) (adj p1-2 p2-2)
        (adj p1-3 p1-2) (adj p1-3 p1-4) (adj p1-3 p2-3)
	(adj p1-4 p1-3) (adj p1-4 p2-4)
        (adj p2-1 p1-1) (adj p2-1 p2-2) (adj p2-1 p3-1)
	(adj p2-2 p1-2) (adj p2-2 p2-1) (adj p2-2 p2-3) (adj p2-2 p3-2)
	(adj p2-3 p1-3) (adj p2-3 p2-2) (adj p2-3 p2-4) (adj p2-3 p3-3)
	(adj p2-4 p1-4) (adj p2-4 p2-3) (adj p2-4 p3-4)
	(adj p3-1 p2-1) (adj p3-1 p3-2) (adj p3-1 p4-1)
	(adj p3-2 p2-2) (adj p3-2 p3-1) (adj p3-2 p3-3) (adj p3-2 p4-2)
	(adj p3-3 p2-3) (adj p3-3 p3-2) (adj p3-3 p3-4) (adj p3-3 p4-3)
	(adj p3-4 p2-4) (adj p3-4 p3-3) (adj p3-4 p4-4)
        (adj p4-1 p3-1) (adj p4-1 p4-2)
	(adj p4-2 p3-2) (adj p4-2 p4-1) (adj p4-2 p4-3)
	(adj p4-3 p3-3) (adj p4-3 p4-2) (adj p4-3 p4-4)
	(adj p4-4 p3-4) (adj p4-4 p4-3)

	(agent-at p3-3)
	(antenna-height h0)
        (not-sensing)

	(rock-at r0 p4-2)
	(rock-at r1 p1-4)
	(invariant (good r0) (not (good r0)))
	(invariant (good r1) (not (good r1)))

        ;; activate-sensor-at-p1-2-h2
        (in-range r1 p1-2 h2)

        ;; activate-sensor-at-p1-3-h1
        ;; activate-sensor-at-p1-3-h2
        (in-range r1 p1-3 h1)
        (in-range r1 p1-3 h2)

        ;; activate-sensor-at-p1-4-h0
        ;; activate-sensor-at-p1-4-h1
        ;; activate-sensor-at-p1-4-h2
        (in-range r1 p1-4 h0)
        (in-range r1 p1-4 h1)
        (in-range r1 p1-4 h2)

        ;; activate-sensor-at-p2-2-h2
        (in-range r0 p2-2 h2)

        ;; activate-sensor-at-p2-3-h2
        (in-range r1 p2-3 h2)

        ;; activate-sensor-at-p2-4-h1
        ;; activate-sensor-at-p2-4-h2
        (in-range r1 p2-4 h1)
        (in-range r1 p2-4 h2)

        ;; activate-sensor-at-p3-1-h2
        (in-range r0 p3-1 h2)

        ;; activate-sensor-at-p3-2-h1
        ;; activate-sensor-at-p3-2-h2
        (in-range r0 p3-2 h1)
        (in-range r0 p3-2 h2)

        ;; activate-sensor-at-p3-3-h2
        (in-range r0 p3-3 h2)

        ;; activate-sensor-at-p3-4-h2
        (in-range r1 p3-4 h2)

        ;; activate-sensor-at-p4-1-h1
        ;; activate-sensor-at-p4-1-h2
        (in-range r0 p4-1 h1)
        (in-range r0 p4-1 h2)

        ;; activate-sensor-at-p4-2-h0
        ;; activate-sensor-at-p4-2-h1
        ;; activate-sensor-at-p4-2-h2
        (in-range r0 p4-2 h0)
        (in-range r0 p4-2 h1)
        (in-range r0 p4-2 h2)

        ;; activate-sensor-at-p4-3-h1
        ;; activate-sensor-at-p4-3-h2
        (in-range r0 p4-3 h1)
        (in-range r0 p4-3 h2)

        ;; activate-sensor-at-p4-4-h2
        (in-range r0 p4-4 h2)


        (invariant (not (good r0)) (good-rocks-in-range p3-1 h2))
        (invariant (not (good r0)) (good-rocks-in-range p3-2 h1))
        (invariant (not (good r0)) (good-rocks-in-range p3-2 h2))
        (invariant (not (good r0)) (good-rocks-in-range p3-3 h2))
        (invariant (not (good r0)) (good-rocks-in-range p4-1 h2))
        (invariant (not (good r0)) (good-rocks-in-range p4-1 h1))
        (invariant (not (good r0)) (good-rocks-in-range p4-2 h0))
        (invariant (not (good r0)) (good-rocks-in-range p4-2 h1))
        (invariant (not (good r0)) (good-rocks-in-range p4-2 h2))
        (invariant (not (good r0)) (good-rocks-in-range p4-3 h1))
        (invariant (not (good r0)) (good-rocks-in-range p4-3 h2))
        (invariant (not (good r0)) (good-rocks-in-range p4-4 h2))

        (invariant (good r0) (not (good-rocks-in-range p3-1 h2)))
        (invariant (good r0) (not (good-rocks-in-range p3-2 h1)))
        (invariant (good r0) (not (good-rocks-in-range p3-2 h2)))
        (invariant (good r0) (not (good-rocks-in-range p3-3 h2)))
        (invariant (good r0) (not (good-rocks-in-range p4-1 h2)))
        (invariant (good r0) (not (good-rocks-in-range p4-1 h1)))
        (invariant (good r0) (not (good-rocks-in-range p4-2 h0)))
        (invariant (good r0) (not (good-rocks-in-range p4-2 h1)))
        (invariant (good r0) (not (good-rocks-in-range p4-2 h2)))
        (invariant (good r0) (not (good-rocks-in-range p4-3 h1)))
        (invariant (good r0) (not (good-rocks-in-range p4-3 h2)))
        (invariant (good r0) (not (good-rocks-in-range p4-4 h2)))

        (invariant (not (good r1)) (good-rocks-in-range p1-2 h2))
        (invariant (not (good r1)) (good-rocks-in-range p1-3 h1))
        (invariant (not (good r1)) (good-rocks-in-range p1-3 h2))
        (invariant (not (good r1)) (good-rocks-in-range p1-4 h0))
        (invariant (not (good r1)) (good-rocks-in-range p1-4 h1))
        (invariant (not (good r1)) (good-rocks-in-range p1-4 h2))
        (invariant (not (good r1)) (good-rocks-in-range p2-3 h2))
        (invariant (not (good r1)) (good-rocks-in-range p2-4 h1))
        (invariant (not (good r1)) (good-rocks-in-range p2-4 h2))

        (invariant (good r1) (not (good-rocks-in-range p1-2 h2)))
        (invariant (good r1) (not (good-rocks-in-range p1-3 h1)))
        (invariant (good r1) (not (good-rocks-in-range p1-3 h2)))
        (invariant (good r1) (not (good-rocks-in-range p1-4 h0)))
        (invariant (good r1) (not (good-rocks-in-range p1-4 h1)))
        (invariant (good r1) (not (good-rocks-in-range p1-4 h2)))
        (invariant (good r1) (not (good-rocks-in-range p2-3 h2)))
        (invariant (good r1) (not (good-rocks-in-range p2-4 h1)))
        (invariant (good r1) (not (good-rocks-in-range p2-4 h2)))




    )

    (:hidden
        ;(good r0)
        ;(good-rocks-in-range p3-1 h2)
        ;(good-rocks-in-range p3-2 h1)
        ;(good-rocks-in-range p3-2 h2)
        ;(good-rocks-in-range p3-3 h2)
        ;(good-rocks-in-range p4-1 h2)
        ;(good-rocks-in-range p4-1 h1)
        ;(good-rocks-in-range p4-2 h0)
        ;(good-rocks-in-range p4-2 h1)
        ;(good-rocks-in-range p4-2 h2)
        ;(good-rocks-in-range p4-3 h1)
        ;(good-rocks-in-range p4-3 h2)
        ;(good-rocks-in-range p4-4 h2)

        ;(good r1)
        ;(good-rocks-in-range p1-2 h2)
        ;(good-rocks-in-range p1-3 h1)
        ;(good-rocks-in-range p1-3 h2)
        ;(good-rocks-in-range p1-4 h0)
        ;(good-rocks-in-range p1-4 h1)
        ;(good-rocks-in-range p1-4 h2)
        ;(good-rocks-in-range p2-3 h2)
        ;(good-rocks-in-range p2-4 h1)
        ;(good-rocks-in-range p2-4 h2)
    )

    (:goal (and (done r0) (done r1)))
)

