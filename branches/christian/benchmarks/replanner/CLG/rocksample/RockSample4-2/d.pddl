(define (domain RockSample4-2)
(:types LOCATION ROCK HEIGHT MOVESTEP)
(:constants
	 p1-1 - LOCATION
	 p1-2 - LOCATION
	 p1-3 - LOCATION
	 p1-4 - LOCATION
	 p2-1 - LOCATION
	 p2-2 - LOCATION
	 p2-3 - LOCATION
	 p2-4 - LOCATION
	 p3-1 - LOCATION
	 p3-2 - LOCATION
	 p3-3 - LOCATION
	 p3-4 - LOCATION
	 p4-1 - LOCATION
	 p4-2 - LOCATION
	 p4-3 - LOCATION
	 p4-4 - LOCATION
	 r0 - ROCK
	 r1 - ROCK
	 h0 - HEIGHT
	 h1 - HEIGHT
	 h2 - HEIGHT
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
	(when (antena-height h0) (and (not (antena-height h0)) (antena-height h1)))
	(when (antena-height h1) (and (not (antena-height h1)) (antena-height h2)))
))

(:action lower-antena
:effect (and
	(when (antena-height h1) (and (not (antena-height h1)) (antena-height h0)))
	(when (antena-height h2) (and (not (antena-height h2)) (antena-height h1)))
))

(:action activate-sensor-at-p1-2-h2
:precondition (and (agent-at p1-2) (antena-height h2))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-3-h1
:precondition (and (agent-at p1-3) (antena-height h1))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-3-h2
:precondition (and (agent-at p1-3) (antena-height h2))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-4-h0
:precondition (and (agent-at p1-4) (antena-height h0))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-4-h1
:precondition (and (agent-at p1-4) (antena-height h1))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-4-h2
:precondition (and (agent-at p1-4) (antena-height h2))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-2-h2
:precondition (and (agent-at p2-2) (antena-height h2))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-3-h2
:precondition (and (agent-at p2-3) (antena-height h2))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-4-h1
:precondition (and (agent-at p2-4) (antena-height h1))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-4-h2
:precondition (and (agent-at p2-4) (antena-height h2))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-1-h2
:precondition (and (agent-at p3-1) (antena-height h2))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-2-h1
:precondition (and (agent-at p3-2) (antena-height h1))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-2-h2
:precondition (and (agent-at p3-2) (antena-height h2))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-3-h2
:precondition (and (agent-at p3-3) (antena-height h2))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-4-h2
:precondition (and (agent-at p3-4) (antena-height h2))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-1-h1
:precondition (and (agent-at p4-1) (antena-height h1))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-1-h2
:precondition (and (agent-at p4-1) (antena-height h2))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-2-h0
:precondition (and (agent-at p4-2) (antena-height h0))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-2-h1
:precondition (and (agent-at p4-2) (antena-height h1))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-2-h2
:precondition (and (agent-at p4-2) (antena-height h2))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-3-h1
:precondition (and (agent-at p4-3) (antena-height h1))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-3-h2
:precondition (and (agent-at p4-3) (antena-height h2))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-4-h2
:precondition (and (agent-at p4-4) (antena-height h2))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action observe-sensor
:observe (good-rocks-in-range))

)
