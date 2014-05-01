(define 
(domain RockSample8-4)
(:types LOCATION ROCK HEIGHT MOVESTEP)
(:constants
	 p1-1 - LOCATION
	 p1-2 - LOCATION
	 p1-3 - LOCATION
	 p1-4 - LOCATION
	 p1-5 - LOCATION
	 p1-6 - LOCATION
	 p1-7 - LOCATION
	 p1-8 - LOCATION
	 p2-1 - LOCATION
	 p2-2 - LOCATION
	 p2-3 - LOCATION
	 p2-4 - LOCATION
	 p2-5 - LOCATION
	 p2-6 - LOCATION
	 p2-7 - LOCATION
	 p2-8 - LOCATION
	 p3-1 - LOCATION
	 p3-2 - LOCATION
	 p3-3 - LOCATION
	 p3-4 - LOCATION
	 p3-5 - LOCATION
	 p3-6 - LOCATION
	 p3-7 - LOCATION
	 p3-8 - LOCATION
	 p4-1 - LOCATION
	 p4-2 - LOCATION
	 p4-3 - LOCATION
	 p4-4 - LOCATION
	 p4-5 - LOCATION
	 p4-6 - LOCATION
	 p4-7 - LOCATION
	 p4-8 - LOCATION
	 p5-1 - LOCATION
	 p5-2 - LOCATION
	 p5-3 - LOCATION
	 p5-4 - LOCATION
	 p5-5 - LOCATION
	 p5-6 - LOCATION
	 p5-7 - LOCATION
	 p5-8 - LOCATION
	 p6-1 - LOCATION
	 p6-2 - LOCATION
	 p6-3 - LOCATION
	 p6-4 - LOCATION
	 p6-5 - LOCATION
	 p6-6 - LOCATION
	 p6-7 - LOCATION
	 p6-8 - LOCATION
	 p7-1 - LOCATION
	 p7-2 - LOCATION
	 p7-3 - LOCATION
	 p7-4 - LOCATION
	 p7-5 - LOCATION
	 p7-6 - LOCATION
	 p7-7 - LOCATION
	 p7-8 - LOCATION
	 p8-1 - LOCATION
	 p8-2 - LOCATION
	 p8-3 - LOCATION
	 p8-4 - LOCATION
	 p8-5 - LOCATION
	 p8-6 - LOCATION
	 p8-7 - LOCATION
	 p8-8 - LOCATION
	 r0 - ROCK
	 r1 - ROCK
	 r2 - ROCK
	 r3 - ROCK
	 h0 - HEIGHT
	 h1 - HEIGHT
)
(:predicates
	(rock-at ?r - ROCK ?p - LOCATION)
	(agent-at ?p - LOCATION)
	(adj ?p1 - LOCATION ?p2 - LOCATION)
	(good ?r - ROCK)
	(antena-height ?h - HEIGHT)
	(good-rocks-in-range)
)
(:action move
:parameters (?pSource - LOCATION ?pTarget - LOCATION)
:precondition (and (agent-at ?pSource) (adj ?pSource ?pTarget) (antena-height h0))
:effect (and (agent-at ?pTarget) (not (agent-at ?pSource)) (not (good-rocks-in-range))))

(:action sample
:parameters (?r - ROCK ?p - LOCATION)
:precondition (and (agent-at ?p) (rock-at ?r ?p) (good ?r))
:effect (not (good ?r)))

(:action raise-antena
:effect (and
(antena-height h1)(not (antena-height h0))))

(:action lower-antena
:effect (and
(not (antena-height h1))(antena-height h0)))

(:action activate-sensor-at-p1-1-h1
:precondition (and (agent-at p1-1) (antena-height h1))
:effect (and
	(when (or  (good r3)) (good-rocks-in-range))
	(when (and  (not (good r3))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-2-h1
:precondition (and (agent-at p1-2) (antena-height h1))
:effect (and
	(when (or  (good r2)) (good-rocks-in-range))
	(when (and  (not (good r2))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-3-h0
:precondition (and (agent-at p1-3) (antena-height h0))
:effect (and
	(when (or  (good r2)) (good-rocks-in-range))
	(when (and  (not (good r2))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-3-h1
:precondition (and (agent-at p1-3) (antena-height h1))
:effect (and
	(when (or  (good r2)) (good-rocks-in-range))
	(when (and  (not (good r2))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-4-h1
:precondition (and (agent-at p1-4) (antena-height h1))
:effect (and
	(when (or  (good r2)) (good-rocks-in-range))
	(when (and  (not (good r2))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-8-h1
:precondition (and (agent-at p1-8) (antena-height h1))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-1-h0
:precondition (and (agent-at p2-1) (antena-height h0))
:effect (and
	(when (or  (good r3)) (good-rocks-in-range))
	(when (and  (not (good r3))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-1-h1
:precondition (and (agent-at p2-1) (antena-height h1))
:effect (and
	(when (or  (good r3)) (good-rocks-in-range))
	(when (and  (not (good r3))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-2-h1
:precondition (and (agent-at p2-2) (antena-height h1))
:effect (and
	(when (or  (good r3)) (good-rocks-in-range))
	(when (and  (not (good r3))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-3-h1
:precondition (and (agent-at p2-3) (antena-height h1))
:effect (and
	(when (or  (good r2)) (good-rocks-in-range))
	(when (and  (not (good r2))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-7-h1
:precondition (and (agent-at p2-7) (antena-height h1))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-8-h0
:precondition (and (agent-at p2-8) (antena-height h0))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-8-h1
:precondition (and (agent-at p2-8) (antena-height h1))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-1-h1
:precondition (and (agent-at p3-1) (antena-height h1))
:effect (and
	(when (or  (good r3)) (good-rocks-in-range))
	(when (and  (not (good r3))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-8-h1
:precondition (and (agent-at p3-8) (antena-height h1))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-4-h1
:precondition (and (agent-at p6-4) (antena-height h1))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-3-h1
:precondition (and (agent-at p7-3) (antena-height h1))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-4-h0
:precondition (and (agent-at p7-4) (antena-height h0))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-4-h1
:precondition (and (agent-at p7-4) (antena-height h1))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-5-h1
:precondition (and (agent-at p7-5) (antena-height h1))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-4-h1
:precondition (and (agent-at p8-4) (antena-height h1))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action observe-sensor
:observe (good-rocks-in-range))

)