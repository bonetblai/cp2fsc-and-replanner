(define 
(domain RockSample8-14)
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
	 r4 - ROCK
	 r5 - ROCK
	 r6 - ROCK
	 r7 - ROCK
	 r8 - ROCK
	 r9 - ROCK
	 r10 - ROCK
	 r11 - ROCK
	 r12 - ROCK
	 r13 - ROCK
	 h0 - HEIGHT
	 h1 - HEIGHT
	 h2 - HEIGHT
	 h3 - HEIGHT
	 h4 - HEIGHT
	 ms0 - MOVESTEP
	 ms1 - MOVESTEP
	 ms2 - MOVESTEP
	 ms3 - MOVESTEP
	 ms4 - MOVESTEP
)
(:predicates
	(rock-at ?r - ROCK ?p - LOCATION)
	(agent-at ?p - LOCATION)
	(adj ?p1 - LOCATION ?p2 - LOCATION)
	(good ?r - ROCK)
	(antena-height ?h - HEIGHT)
	(good-rocks-in-range)
(move-step ?m - MOVESTEP)
(move-target ?p - LOCATION)
)
(:action move0
:parameters (?pSource - LOCATION ?pTarget - LOCATION)
:precondition (and (agent-at ?pSource) (adj ?pSource ?pTarget) (antena-height h0) (move-step ms0))
:effect (and (move-target ?pTarget) (not (move-step ms0)) (move-step ms1) (not (good-rocks-in-range))))
(:action move1
:parameters (?pSource - LOCATION ?pTarget - LOCATION)
:precondition (and (agent-at ?pSource) (adj ?pSource ?pTarget) (move-target ?pTarget) (antena-height h0) (move-step ms1))
:effect (and (not (move-step ms1)) (move-step ms2) (not (good-rocks-in-range))))
(:action move2
:parameters (?pSource - LOCATION ?pTarget - LOCATION)
:precondition (and (agent-at ?pSource) (adj ?pSource ?pTarget) (move-target ?pTarget) (antena-height h0) (move-step ms2))
:effect (and (not (move-step ms2)) (move-step ms3) (not (good-rocks-in-range))))
(:action move3
:parameters (?pSource - LOCATION ?pTarget - LOCATION)
:precondition (and (agent-at ?pSource) (adj ?pSource ?pTarget) (move-target ?pTarget) (antena-height h0) (move-step ms3))
:effect (and (not (move-step ms3)) (move-step ms4) (not (good-rocks-in-range))))
(:action move4
:parameters (?pSource - LOCATION ?pTarget - LOCATION)
:precondition (and (agent-at ?pSource) (adj ?pSource ?pTarget) (move-target ?pTarget) (antena-height h0) (move-step ms4))
:effect (and  (not (move-step ms4)) (move-step ms0) (not (good-rocks-in-range))(not (agent-at ?pSource)) (agent-at ?pTarget) (not (move-target ?pTarget))))

(:action sample
:parameters (?r - ROCK ?p - LOCATION)
:precondition (and (agent-at ?p) (rock-at ?r ?p) (good ?r))
:effect (not (good ?r)))

(:action raise-antena
:effect (and
	(when (antena-height h0) (and (not (antena-height h0)) (antena-height h1)))
	(when (antena-height h1) (and (not (antena-height h1)) (antena-height h2)))
	(when (antena-height h2) (and (not (antena-height h2)) (antena-height h3)))
	(when (antena-height h3) (and (not (antena-height h3)) (antena-height h4)))
))

(:action lower-antena
:effect (and
	(when (antena-height h1) (and (not (antena-height h1)) (antena-height h0)))
	(when (antena-height h2) (and (not (antena-height h2)) (antena-height h1)))
	(when (antena-height h3) (and (not (antena-height h3)) (antena-height h2)))
	(when (antena-height h4) (and (not (antena-height h4)) (antena-height h3)))
))

(:action activate-sensor-at-p1-1-h1
:precondition (and (agent-at p1-1) (antena-height h1))
:effect (and
	(when (or  (good r3)) (good-rocks-in-range))
	(when (and  (not (good r3))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-1-h2
:precondition (and (agent-at p1-1) (antena-height h2))
:effect (and
	(when (or  (good r2) (good r3)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-1-h3
:precondition (and (agent-at p1-1) (antena-height h3))
:effect (and
	(when (or  (good r2) (good r3)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-1-h4
:precondition (and (agent-at p1-1) (antena-height h4))
:effect (and
	(when (or  (good r2) (good r3) (good r5) (good r6)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r5)) (not (good r6))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-2-h1
:precondition (and (agent-at p1-2) (antena-height h1))
:effect (and
	(when (or  (good r2)) (good-rocks-in-range))
	(when (and  (not (good r2))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-2-h2
:precondition (and (agent-at p1-2) (antena-height h2))
:effect (and
	(when (or  (good r2) (good r3)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-2-h3
:precondition (and (agent-at p1-2) (antena-height h3))
:effect (and
	(when (or  (good r2) (good r3) (good r5)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r5))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-2-h4
:precondition (and (agent-at p1-2) (antena-height h4))
:effect (and
	(when (or  (good r2) (good r3) (good r5) (good r6) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r5)) (not (good r6)) (not (good r12))) (not (good-rocks-in-range)))
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

(:action activate-sensor-at-p1-3-h2
:precondition (and (agent-at p1-3) (antena-height h2))
:effect (and
	(when (or  (good r2) (good r5)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r5))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-3-h3
:precondition (and (agent-at p1-3) (antena-height h3))
:effect (and
	(when (or  (good r2) (good r3) (good r5) (good r6) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r5)) (not (good r6)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-3-h4
:precondition (and (agent-at p1-3) (antena-height h4))
:effect (and
	(when (or  (good r2) (good r3) (good r5) (good r6) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r5)) (not (good r6)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-4-h1
:precondition (and (agent-at p1-4) (antena-height h1))
:effect (and
	(when (or  (good r2) (good r5)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r5))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-4-h2
:precondition (and (agent-at p1-4) (antena-height h2))
:effect (and
	(when (or  (good r2) (good r5) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r5)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-4-h3
:precondition (and (agent-at p1-4) (antena-height h3))
:effect (and
	(when (or  (good r2) (good r5) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r5)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-4-h4
:precondition (and (agent-at p1-4) (antena-height h4))
:effect (and
	(when (or  (good r2) (good r3) (good r5) (good r6) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r5)) (not (good r6)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-5-h0
:precondition (and (agent-at p1-5) (antena-height h0))
:effect (and
	(when (or  (good r5)) (good-rocks-in-range))
	(when (and  (not (good r5))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-5-h1
:precondition (and (agent-at p1-5) (antena-height h1))
:effect (and
	(when (or  (good r5) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r5)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-5-h2
:precondition (and (agent-at p1-5) (antena-height h2))
:effect (and
	(when (or  (good r2) (good r5) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r5)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-5-h3
:precondition (and (agent-at p1-5) (antena-height h3))
:effect (and
	(when (or  (good r2) (good r5) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r5)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-5-h4
:precondition (and (agent-at p1-5) (antena-height h4))
:effect (and
	(when (or  (good r1) (good r2) (good r5) (good r6) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r2)) (not (good r5)) (not (good r6)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-6-h0
:precondition (and (agent-at p1-6) (antena-height h0))
:effect (and
	(when (or  (good r12)) (good-rocks-in-range))
	(when (and  (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-6-h1
:precondition (and (agent-at p1-6) (antena-height h1))
:effect (and
	(when (or  (good r5) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r5)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-6-h2
:precondition (and (agent-at p1-6) (antena-height h2))
:effect (and
	(when (or  (good r5) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r5)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-6-h3
:precondition (and (agent-at p1-6) (antena-height h3))
:effect (and
	(when (or  (good r1) (good r2) (good r5) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r2)) (not (good r5)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-6-h4
:precondition (and (agent-at p1-6) (antena-height h4))
:effect (and
	(when (or  (good r1) (good r2) (good r5) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r2)) (not (good r5)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-7-h1
:precondition (and (agent-at p1-7) (antena-height h1))
:effect (and
	(when (or  (good r12)) (good-rocks-in-range))
	(when (and  (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-7-h2
:precondition (and (agent-at p1-7) (antena-height h2))
:effect (and
	(when (or  (good r1) (good r5) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r5)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-7-h3
:precondition (and (agent-at p1-7) (antena-height h3))
:effect (and
	(when (or  (good r1) (good r5) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r5)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-7-h4
:precondition (and (agent-at p1-7) (antena-height h4))
:effect (and
	(when (or  (good r1) (good r2) (good r5) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r2)) (not (good r5)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-8-h1
:precondition (and (agent-at p1-8) (antena-height h1))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-8-h2
:precondition (and (agent-at p1-8) (antena-height h2))
:effect (and
	(when (or  (good r1) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-8-h3
:precondition (and (agent-at p1-8) (antena-height h3))
:effect (and
	(when (or  (good r1) (good r5) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r5)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p1-8-h4
:precondition (and (agent-at p1-8) (antena-height h4))
:effect (and
	(when (or  (good r1) (good r5) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r5)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
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

(:action activate-sensor-at-p2-1-h2
:precondition (and (agent-at p2-1) (antena-height h2))
:effect (and
	(when (or  (good r3)) (good-rocks-in-range))
	(when (and  (not (good r3))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-1-h3
:precondition (and (agent-at p2-1) (antena-height h3))
:effect (and
	(when (or  (good r2) (good r3) (good r6)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r6))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-1-h4
:precondition (and (agent-at p2-1) (antena-height h4))
:effect (and
	(when (or  (good r2) (good r3) (good r6) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r6)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-2-h1
:precondition (and (agent-at p2-2) (antena-height h1))
:effect (and
	(when (or  (good r3)) (good-rocks-in-range))
	(when (and  (not (good r3))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-2-h2
:precondition (and (agent-at p2-2) (antena-height h2))
:effect (and
	(when (or  (good r2) (good r3)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-2-h3
:precondition (and (agent-at p2-2) (antena-height h3))
:effect (and
	(when (or  (good r2) (good r3) (good r6)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r6))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-2-h4
:precondition (and (agent-at p2-2) (antena-height h4))
:effect (and
	(when (or  (good r2) (good r3) (good r5) (good r6) (good r7)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r5)) (not (good r6)) (not (good r7))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-3-h1
:precondition (and (agent-at p2-3) (antena-height h1))
:effect (and
	(when (or  (good r2)) (good-rocks-in-range))
	(when (and  (not (good r2))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-3-h2
:precondition (and (agent-at p2-3) (antena-height h2))
:effect (and
	(when (or  (good r2) (good r3) (good r6)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r6))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-3-h3
:precondition (and (agent-at p2-3) (antena-height h3))
:effect (and
	(when (or  (good r2) (good r3) (good r5) (good r6)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r5)) (not (good r6))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-3-h4
:precondition (and (agent-at p2-3) (antena-height h4))
:effect (and
	(when (or  (good r2) (good r3) (good r5) (good r6) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r5)) (not (good r6)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-4-h2
:precondition (and (agent-at p2-4) (antena-height h2))
:effect (and
	(when (or  (good r2) (good r5)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r5))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-4-h3
:precondition (and (agent-at p2-4) (antena-height h3))
:effect (and
	(when (or  (good r2) (good r3) (good r5) (good r6) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r5)) (not (good r6)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-4-h4
:precondition (and (agent-at p2-4) (antena-height h4))
:effect (and
	(when (or  (good r1) (good r2) (good r3) (good r5) (good r6) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r2)) (not (good r3)) (not (good r5)) (not (good r6)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-5-h1
:precondition (and (agent-at p2-5) (antena-height h1))
:effect (and
	(when (or  (good r5)) (good-rocks-in-range))
	(when (and  (not (good r5))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-5-h2
:precondition (and (agent-at p2-5) (antena-height h2))
:effect (and
	(when (or  (good r5) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r5)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-5-h3
:precondition (and (agent-at p2-5) (antena-height h3))
:effect (and
	(when (or  (good r1) (good r2) (good r5) (good r6) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r2)) (not (good r5)) (not (good r6)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-5-h4
:precondition (and (agent-at p2-5) (antena-height h4))
:effect (and
	(when (or  (good r1) (good r2) (good r3) (good r5) (good r6) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r2)) (not (good r3)) (not (good r5)) (not (good r6)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-6-h1
:precondition (and (agent-at p2-6) (antena-height h1))
:effect (and
	(when (or  (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-6-h2
:precondition (and (agent-at p2-6) (antena-height h2))
:effect (and
	(when (or  (good r1) (good r5) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r5)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-6-h3
:precondition (and (agent-at p2-6) (antena-height h3))
:effect (and
	(when (or  (good r1) (good r5) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r5)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-6-h4
:precondition (and (agent-at p2-6) (antena-height h4))
:effect (and
	(when (or  (good r1) (good r2) (good r5) (good r6) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r2)) (not (good r5)) (not (good r6)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-7-h1
:precondition (and (agent-at p2-7) (antena-height h1))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-7-h2
:precondition (and (agent-at p2-7) (antena-height h2))
:effect (and
	(when (or  (good r1) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-7-h3
:precondition (and (agent-at p2-7) (antena-height h3))
:effect (and
	(when (or  (good r1) (good r5) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r5)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-7-h4
:precondition (and (agent-at p2-7) (antena-height h4))
:effect (and
	(when (or  (good r1) (good r5) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r5)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
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

(:action activate-sensor-at-p2-8-h2
:precondition (and (agent-at p2-8) (antena-height h2))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-8-h3
:precondition (and (agent-at p2-8) (antena-height h3))
:effect (and
	(when (or  (good r1) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p2-8-h4
:precondition (and (agent-at p2-8) (antena-height h4))
:effect (and
	(when (or  (good r1) (good r5) (good r9) (good r11) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r5)) (not (good r9)) (not (good r11)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-1-h1
:precondition (and (agent-at p3-1) (antena-height h1))
:effect (and
	(when (or  (good r3)) (good-rocks-in-range))
	(when (and  (not (good r3))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-1-h2
:precondition (and (agent-at p3-1) (antena-height h2))
:effect (and
	(when (or  (good r3)) (good-rocks-in-range))
	(when (and  (not (good r3))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-1-h3
:precondition (and (agent-at p3-1) (antena-height h3))
:effect (and
	(when (or  (good r2) (good r3) (good r6) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r6)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-1-h4
:precondition (and (agent-at p3-1) (antena-height h4))
:effect (and
	(when (or  (good r2) (good r3) (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-2-h2
:precondition (and (agent-at p3-2) (antena-height h2))
:effect (and
	(when (or  (good r3) (good r6)) (good-rocks-in-range))
	(when (and  (not (good r3)) (not (good r6))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-2-h3
:precondition (and (agent-at p3-2) (antena-height h3))
:effect (and
	(when (or  (good r2) (good r3) (good r6) (good r7)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r6)) (not (good r7))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-2-h4
:precondition (and (agent-at p3-2) (antena-height h4))
:effect (and
	(when (or  (good r2) (good r3) (good r5) (good r6) (good r7) (good r8) (good r9)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r5)) (not (good r6)) (not (good r7)) (not (good r8)) (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-3-h1
:precondition (and (agent-at p3-3) (antena-height h1))
:effect (and
	(when (or  (good r6)) (good-rocks-in-range))
	(when (and  (not (good r6))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-3-h2
:precondition (and (agent-at p3-3) (antena-height h2))
:effect (and
	(when (or  (good r2) (good r6)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r6))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-3-h3
:precondition (and (agent-at p3-3) (antena-height h3))
:effect (and
	(when (or  (good r2) (good r3) (good r5) (good r6) (good r9)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r5)) (not (good r6)) (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-3-h4
:precondition (and (agent-at p3-3) (antena-height h4))
:effect (and
	(when (or  (good r2) (good r3) (good r5) (good r6) (good r7) (good r8) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r5)) (not (good r6)) (not (good r7)) (not (good r8)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-4-h2
:precondition (and (agent-at p3-4) (antena-height h2))
:effect (and
	(when (or  (good r6) (good r9)) (good-rocks-in-range))
	(when (and  (not (good r6)) (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-4-h3
:precondition (and (agent-at p3-4) (antena-height h3))
:effect (and
	(when (or  (good r2) (good r5) (good r6) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r5)) (not (good r6)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-4-h4
:precondition (and (agent-at p3-4) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r2) (good r3) (good r5) (good r6) (good r7) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r2)) (not (good r3)) (not (good r5)) (not (good r6)) (not (good r7)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-5-h1
:precondition (and (agent-at p3-5) (antena-height h1))
:effect (and
	(when (or  (good r9)) (good-rocks-in-range))
	(when (and  (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-5-h2
:precondition (and (agent-at p3-5) (antena-height h2))
:effect (and
	(when (or  (good r5) (good r9)) (good-rocks-in-range))
	(when (and  (not (good r5)) (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-5-h3
:precondition (and (agent-at p3-5) (antena-height h3))
:effect (and
	(when (or  (good r2) (good r5) (good r6) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r5)) (not (good r6)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-5-h4
:precondition (and (agent-at p3-5) (antena-height h4))
:effect (and
	(when (or  (good r1) (good r2) (good r5) (good r6) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r2)) (not (good r5)) (not (good r6)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-6-h0
:precondition (and (agent-at p3-6) (antena-height h0))
:effect (and
	(when (or  (good r9)) (good-rocks-in-range))
	(when (and  (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-6-h1
:precondition (and (agent-at p3-6) (antena-height h1))
:effect (and
	(when (or  (good r9)) (good-rocks-in-range))
	(when (and  (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-6-h2
:precondition (and (agent-at p3-6) (antena-height h2))
:effect (and
	(when (or  (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-6-h3
:precondition (and (agent-at p3-6) (antena-height h3))
:effect (and
	(when (or  (good r1) (good r5) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r5)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-6-h4
:precondition (and (agent-at p3-6) (antena-height h4))
:effect (and
	(when (or  (good r1) (good r2) (good r5) (good r6) (good r9) (good r11) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r2)) (not (good r5)) (not (good r6)) (not (good r9)) (not (good r11)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-7-h1
:precondition (and (agent-at p3-7) (antena-height h1))
:effect (and
	(when (or  (good r9)) (good-rocks-in-range))
	(when (and  (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-7-h2
:precondition (and (agent-at p3-7) (antena-height h2))
:effect (and
	(when (or  (good r1) (good r9)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-7-h3
:precondition (and (agent-at p3-7) (antena-height h3))
:effect (and
	(when (or  (good r1) (good r5) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r5)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-7-h4
:precondition (and (agent-at p3-7) (antena-height h4))
:effect (and
	(when (or  (good r1) (good r5) (good r9) (good r11) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r5)) (not (good r9)) (not (good r11)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-8-h1
:precondition (and (agent-at p3-8) (antena-height h1))
:effect (and
	(when (or  (good r1)) (good-rocks-in-range))
	(when (and  (not (good r1))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-8-h2
:precondition (and (agent-at p3-8) (antena-height h2))
:effect (and
	(when (or  (good r1) (good r9)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-8-h3
:precondition (and (agent-at p3-8) (antena-height h3))
:effect (and
	(when (or  (good r1) (good r9) (good r11) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r9)) (not (good r11)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p3-8-h4
:precondition (and (agent-at p3-8) (antena-height h4))
:effect (and
	(when (or  (good r1) (good r5) (good r9) (good r11) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r5)) (not (good r9)) (not (good r11)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-1-h2
:precondition (and (agent-at p4-1) (antena-height h2))
:effect (and
	(when (or  (good r3) (good r6) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r3)) (not (good r6)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-1-h3
:precondition (and (agent-at p4-1) (antena-height h3))
:effect (and
	(when (or  (good r3) (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r3)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-1-h4
:precondition (and (agent-at p4-1) (antena-height h4))
:effect (and
	(when (or  (good r2) (good r3) (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-2-h1
:precondition (and (agent-at p4-2) (antena-height h1))
:effect (and
	(when (or  (good r6)) (good-rocks-in-range))
	(when (and  (not (good r6))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-2-h2
:precondition (and (agent-at p4-2) (antena-height h2))
:effect (and
	(when (or  (good r6) (good r7)) (good-rocks-in-range))
	(when (and  (not (good r6)) (not (good r7))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-2-h3
:precondition (and (agent-at p4-2) (antena-height h3))
:effect (and
	(when (or  (good r3) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r3)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-2-h4
:precondition (and (agent-at p4-2) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r2) (good r3) (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r2)) (not (good r3)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-3-h0
:precondition (and (agent-at p4-3) (antena-height h0))
:effect (and
	(when (or  (good r6)) (good-rocks-in-range))
	(when (and  (not (good r6))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-3-h1
:precondition (and (agent-at p4-3) (antena-height h1))
:effect (and
	(when (or  (good r6)) (good-rocks-in-range))
	(when (and  (not (good r6))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-3-h2
:precondition (and (agent-at p4-3) (antena-height h2))
:effect (and
	(when (or  (good r6)) (good-rocks-in-range))
	(when (and  (not (good r6))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-3-h3
:precondition (and (agent-at p4-3) (antena-height h3))
:effect (and
	(when (or  (good r2) (good r3) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r2)) (not (good r3)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-3-h4
:precondition (and (agent-at p4-3) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r2) (good r3) (good r4) (good r5) (good r6) (good r7) (good r8) (good r9)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r2)) (not (good r3)) (not (good r4)) (not (good r5)) (not (good r6)) (not (good r7)) (not (good r8)) (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-4-h1
:precondition (and (agent-at p4-4) (antena-height h1))
:effect (and
	(when (or  (good r6)) (good-rocks-in-range))
	(when (and  (not (good r6))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-4-h2
:precondition (and (agent-at p4-4) (antena-height h2))
:effect (and
	(when (or  (good r6)) (good-rocks-in-range))
	(when (and  (not (good r6))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-4-h3
:precondition (and (agent-at p4-4) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r6) (good r7) (good r9)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r6)) (not (good r7)) (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-4-h4
:precondition (and (agent-at p4-4) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r2) (good r3) (good r5) (good r6) (good r7) (good r8) (good r9) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r2)) (not (good r3)) (not (good r5)) (not (good r6)) (not (good r7)) (not (good r8)) (not (good r9)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-5-h2
:precondition (and (agent-at p4-5) (antena-height h2))
:effect (and
	(when (or  (good r6) (good r9)) (good-rocks-in-range))
	(when (and  (not (good r6)) (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-5-h3
:precondition (and (agent-at p4-5) (antena-height h3))
:effect (and
	(when (or  (good r5) (good r6) (good r9)) (good-rocks-in-range))
	(when (and  (not (good r5)) (not (good r6)) (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-5-h4
:precondition (and (agent-at p4-5) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r1) (good r2) (good r5) (good r6) (good r7) (good r9) (good r11) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r1)) (not (good r2)) (not (good r5)) (not (good r6)) (not (good r7)) (not (good r9)) (not (good r11)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-6-h1
:precondition (and (agent-at p4-6) (antena-height h1))
:effect (and
	(when (or  (good r9)) (good-rocks-in-range))
	(when (and  (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-6-h2
:precondition (and (agent-at p4-6) (antena-height h2))
:effect (and
	(when (or  (good r9)) (good-rocks-in-range))
	(when (and  (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-6-h3
:precondition (and (agent-at p4-6) (antena-height h3))
:effect (and
	(when (or  (good r1) (good r6) (good r9) (good r11) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r6)) (not (good r9)) (not (good r11)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-6-h4
:precondition (and (agent-at p4-6) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r1) (good r5) (good r6) (good r9) (good r11) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r1)) (not (good r5)) (not (good r6)) (not (good r9)) (not (good r11)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-7-h2
:precondition (and (agent-at p4-7) (antena-height h2))
:effect (and
	(when (or  (good r9)) (good-rocks-in-range))
	(when (and  (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-7-h3
:precondition (and (agent-at p4-7) (antena-height h3))
:effect (and
	(when (or  (good r1) (good r9) (good r11)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r9)) (not (good r11))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-7-h4
:precondition (and (agent-at p4-7) (antena-height h4))
:effect (and
	(when (or  (good r1) (good r5) (good r6) (good r9) (good r10) (good r11) (good r12)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r5)) (not (good r6)) (not (good r9)) (not (good r10)) (not (good r11)) (not (good r12))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-8-h2
:precondition (and (agent-at p4-8) (antena-height h2))
:effect (and
	(when (or  (good r1) (good r11)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r11))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-8-h3
:precondition (and (agent-at p4-8) (antena-height h3))
:effect (and
	(when (or  (good r1) (good r9) (good r11)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r9)) (not (good r11))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p4-8-h4
:precondition (and (agent-at p4-8) (antena-height h4))
:effect (and
	(when (or  (good r1) (good r9) (good r11) (good r12) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r9)) (not (good r11)) (not (good r12)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-1-h1
:precondition (and (agent-at p5-1) (antena-height h1))
:effect (and
	(when (or  (good r8)) (good-rocks-in-range))
	(when (and  (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-1-h2
:precondition (and (agent-at p5-1) (antena-height h2))
:effect (and
	(when (or  (good r4) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r4)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-1-h3
:precondition (and (agent-at p5-1) (antena-height h3))
:effect (and
	(when (or  (good r3) (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r3)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-1-h4
:precondition (and (agent-at p5-1) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r3) (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r3)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-2-h1
:precondition (and (agent-at p5-2) (antena-height h1))
:effect (and
	(when (or  (good r7)) (good-rocks-in-range))
	(when (and  (not (good r7))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-2-h2
:precondition (and (agent-at p5-2) (antena-height h2))
:effect (and
	(when (or  (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-2-h3
:precondition (and (agent-at p5-2) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-2-h4
:precondition (and (agent-at p5-2) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r3) (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r3)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-3-h1
:precondition (and (agent-at p5-3) (antena-height h1))
:effect (and
	(when (or  (good r6)) (good-rocks-in-range))
	(when (and  (not (good r6))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-3-h2
:precondition (and (agent-at p5-3) (antena-height h2))
:effect (and
	(when (or  (good r6) (good r7)) (good-rocks-in-range))
	(when (and  (not (good r6)) (not (good r7))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-3-h3
:precondition (and (agent-at p5-3) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-3-h4
:precondition (and (agent-at p5-3) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r2) (good r3) (good r4) (good r6) (good r7) (good r8) (good r9)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r2)) (not (good r3)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8)) (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-4-h2
:precondition (and (agent-at p5-4) (antena-height h2))
:effect (and
	(when (or  (good r0) (good r6)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r6))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-4-h3
:precondition (and (agent-at p5-4) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r6) (good r7) (good r9)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r6)) (not (good r7)) (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-4-h4
:precondition (and (agent-at p5-4) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r4) (good r6) (good r7) (good r8) (good r9)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8)) (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-5-h3
:precondition (and (agent-at p5-5) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r6) (good r9)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r6)) (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-5-h4
:precondition (and (agent-at p5-5) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r5) (good r6) (good r7) (good r9) (good r10) (good r11)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r5)) (not (good r6)) (not (good r7)) (not (good r9)) (not (good r10)) (not (good r11))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-6-h2
:precondition (and (agent-at p5-6) (antena-height h2))
:effect (and
	(when (or  (good r9)) (good-rocks-in-range))
	(when (and  (not (good r9))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-6-h3
:precondition (and (agent-at p5-6) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r9) (good r11)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r9)) (not (good r11))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-6-h4
:precondition (and (agent-at p5-6) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r1) (good r6) (good r9) (good r10) (good r11) (good r12) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r1)) (not (good r6)) (not (good r9)) (not (good r10)) (not (good r11)) (not (good r12)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-7-h2
:precondition (and (agent-at p5-7) (antena-height h2))
:effect (and
	(when (or  (good r11)) (good-rocks-in-range))
	(when (and  (not (good r11))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-7-h3
:precondition (and (agent-at p5-7) (antena-height h3))
:effect (and
	(when (or  (good r9) (good r10) (good r11)) (good-rocks-in-range))
	(when (and  (not (good r9)) (not (good r10)) (not (good r11))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-7-h4
:precondition (and (agent-at p5-7) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r1) (good r9) (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r1)) (not (good r9)) (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-8-h1
:precondition (and (agent-at p5-8) (antena-height h1))
:effect (and
	(when (or  (good r11)) (good-rocks-in-range))
	(when (and  (not (good r11))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-8-h2
:precondition (and (agent-at p5-8) (antena-height h2))
:effect (and
	(when (or  (good r11)) (good-rocks-in-range))
	(when (and  (not (good r11))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-8-h3
:precondition (and (agent-at p5-8) (antena-height h3))
:effect (and
	(when (or  (good r1) (good r9) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r9)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p5-8-h4
:precondition (and (agent-at p5-8) (antena-height h4))
:effect (and
	(when (or  (good r1) (good r9) (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r9)) (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-1-h0
:precondition (and (agent-at p6-1) (antena-height h0))
:effect (and
	(when (or  (good r8)) (good-rocks-in-range))
	(when (and  (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-1-h1
:precondition (and (agent-at p6-1) (antena-height h1))
:effect (and
	(when (or  (good r4) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r4)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-1-h2
:precondition (and (agent-at p6-1) (antena-height h2))
:effect (and
	(when (or  (good r4) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r4)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-1-h3
:precondition (and (agent-at p6-1) (antena-height h3))
:effect (and
	(when (or  (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-1-h4
:precondition (and (agent-at p6-1) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r3) (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r3)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-2-h0
:precondition (and (agent-at p6-2) (antena-height h0))
:effect (and
	(when (or  (good r7)) (good-rocks-in-range))
	(when (and  (not (good r7))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-2-h1
:precondition (and (agent-at p6-2) (antena-height h1))
:effect (and
	(when (or  (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-2-h2
:precondition (and (agent-at p6-2) (antena-height h2))
:effect (and
	(when (or  (good r4) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r4)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-2-h3
:precondition (and (agent-at p6-2) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-2-h4
:precondition (and (agent-at p6-2) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-3-h1
:precondition (and (agent-at p6-3) (antena-height h1))
:effect (and
	(when (or  (good r7)) (good-rocks-in-range))
	(when (and  (not (good r7))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-3-h2
:precondition (and (agent-at p6-3) (antena-height h2))
:effect (and
	(when (or  (good r0) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-3-h3
:precondition (and (agent-at p6-3) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-3-h4
:precondition (and (agent-at p6-3) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-4-h1
:precondition (and (agent-at p6-4) (antena-height h1))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-4-h2
:precondition (and (agent-at p6-4) (antena-height h2))
:effect (and
	(when (or  (good r0) (good r7)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r7))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-4-h3
:precondition (and (agent-at p6-4) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-4-h4
:precondition (and (agent-at p6-4) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r4) (good r6) (good r7) (good r8) (good r9) (good r10) (good r11)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8)) (not (good r9)) (not (good r10)) (not (good r11))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-5-h2
:precondition (and (agent-at p6-5) (antena-height h2))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-5-h3
:precondition (and (agent-at p6-5) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r6) (good r7) (good r10) (good r11)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r6)) (not (good r7)) (not (good r10)) (not (good r11))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-5-h4
:precondition (and (agent-at p6-5) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r6) (good r7) (good r8) (good r9) (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r6)) (not (good r7)) (not (good r8)) (not (good r9)) (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-6-h2
:precondition (and (agent-at p6-6) (antena-height h2))
:effect (and
	(when (or  (good r11)) (good-rocks-in-range))
	(when (and  (not (good r11))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-6-h3
:precondition (and (agent-at p6-6) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r9) (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r9)) (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-6-h4
:precondition (and (agent-at p6-6) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r6) (good r7) (good r9) (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r6)) (not (good r7)) (not (good r9)) (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-7-h1
:precondition (and (agent-at p6-7) (antena-height h1))
:effect (and
	(when (or  (good r11)) (good-rocks-in-range))
	(when (and  (not (good r11))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-7-h2
:precondition (and (agent-at p6-7) (antena-height h2))
:effect (and
	(when (or  (good r10) (good r11)) (good-rocks-in-range))
	(when (and  (not (good r10)) (not (good r11))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-7-h3
:precondition (and (agent-at p6-7) (antena-height h3))
:effect (and
	(when (or  (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-7-h4
:precondition (and (agent-at p6-7) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r9) (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r9)) (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-8-h0
:precondition (and (agent-at p6-8) (antena-height h0))
:effect (and
	(when (or  (good r11)) (good-rocks-in-range))
	(when (and  (not (good r11))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-8-h1
:precondition (and (agent-at p6-8) (antena-height h1))
:effect (and
	(when (or  (good r11)) (good-rocks-in-range))
	(when (and  (not (good r11))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-8-h2
:precondition (and (agent-at p6-8) (antena-height h2))
:effect (and
	(when (or  (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-8-h3
:precondition (and (agent-at p6-8) (antena-height h3))
:effect (and
	(when (or  (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p6-8-h4
:precondition (and (agent-at p6-8) (antena-height h4))
:effect (and
	(when (or  (good r1) (good r9) (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r1)) (not (good r9)) (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-1-h0
:precondition (and (agent-at p7-1) (antena-height h0))
:effect (and
	(when (or  (good r4)) (good-rocks-in-range))
	(when (and  (not (good r4))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-1-h1
:precondition (and (agent-at p7-1) (antena-height h1))
:effect (and
	(when (or  (good r4) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r4)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-1-h2
:precondition (and (agent-at p7-1) (antena-height h2))
:effect (and
	(when (or  (good r4) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r4)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-1-h3
:precondition (and (agent-at p7-1) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r4) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-1-h4
:precondition (and (agent-at p7-1) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-2-h1
:precondition (and (agent-at p7-2) (antena-height h1))
:effect (and
	(when (or  (good r4) (good r7)) (good-rocks-in-range))
	(when (and  (not (good r4)) (not (good r7))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-2-h2
:precondition (and (agent-at p7-2) (antena-height h2))
:effect (and
	(when (or  (good r0) (good r4) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-2-h3
:precondition (and (agent-at p7-2) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r4) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-2-h4
:precondition (and (agent-at p7-2) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-3-h1
:precondition (and (agent-at p7-3) (antena-height h1))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-3-h2
:precondition (and (agent-at p7-3) (antena-height h2))
:effect (and
	(when (or  (good r0) (good r4) (good r7)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r7))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-3-h3
:precondition (and (agent-at p7-3) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-3-h4
:precondition (and (agent-at p7-3) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r4) (good r6) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
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

(:action activate-sensor-at-p7-4-h2
:precondition (and (agent-at p7-4) (antena-height h2))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-4-h3
:precondition (and (agent-at p7-4) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r4) (good r7)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r7))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-4-h4
:precondition (and (agent-at p7-4) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r4) (good r6) (good r7) (good r8) (good r10)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8)) (not (good r10))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-5-h1
:precondition (and (agent-at p7-5) (antena-height h1))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-5-h2
:precondition (and (agent-at p7-5) (antena-height h2))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-5-h3
:precondition (and (agent-at p7-5) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r10)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r10))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-5-h4
:precondition (and (agent-at p7-5) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r4) (good r6) (good r7) (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-6-h2
:precondition (and (agent-at p7-6) (antena-height h2))
:effect (and
	(when (or  (good r0) (good r10)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r10))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-6-h3
:precondition (and (agent-at p7-6) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-6-h4
:precondition (and (agent-at p7-6) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r9) (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r9)) (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-7-h1
:precondition (and (agent-at p7-7) (antena-height h1))
:effect (and
	(when (or  (good r10)) (good-rocks-in-range))
	(when (and  (not (good r10))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-7-h2
:precondition (and (agent-at p7-7) (antena-height h2))
:effect (and
	(when (or  (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-7-h3
:precondition (and (agent-at p7-7) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-7-h4
:precondition (and (agent-at p7-7) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-8-h1
:precondition (and (agent-at p7-8) (antena-height h1))
:effect (and
	(when (or  (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-8-h2
:precondition (and (agent-at p7-8) (antena-height h2))
:effect (and
	(when (or  (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-8-h3
:precondition (and (agent-at p7-8) (antena-height h3))
:effect (and
	(when (or  (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p7-8-h4
:precondition (and (agent-at p7-8) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-1-h1
:precondition (and (agent-at p8-1) (antena-height h1))
:effect (and
	(when (or  (good r4)) (good-rocks-in-range))
	(when (and  (not (good r4))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-1-h2
:precondition (and (agent-at p8-1) (antena-height h2))
:effect (and
	(when (or  (good r4) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r4)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-1-h3
:precondition (and (agent-at p8-1) (antena-height h3))
:effect (and
	(when (or  (good r4) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r4)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-1-h4
:precondition (and (agent-at p8-1) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r4) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-2-h2
:precondition (and (agent-at p8-2) (antena-height h2))
:effect (and
	(when (or  (good r4) (good r7)) (good-rocks-in-range))
	(when (and  (not (good r4)) (not (good r7))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-2-h3
:precondition (and (agent-at p8-2) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r4) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-2-h4
:precondition (and (agent-at p8-2) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r4) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-3-h2
:precondition (and (agent-at p8-3) (antena-height h2))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-3-h3
:precondition (and (agent-at p8-3) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r4) (good r7) (good r8)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r7)) (not (good r8))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-3-h4
:precondition (and (agent-at p8-3) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r4) (good r6) (good r7) (good r8) (good r10)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r6)) (not (good r7)) (not (good r8)) (not (good r10))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-4-h1
:precondition (and (agent-at p8-4) (antena-height h1))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-4-h2
:precondition (and (agent-at p8-4) (antena-height h2))
:effect (and
	(when (or  (good r0)) (good-rocks-in-range))
	(when (and  (not (good r0))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-4-h3
:precondition (and (agent-at p8-4) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r7) (good r10)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r7)) (not (good r10))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-4-h4
:precondition (and (agent-at p8-4) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r4) (good r7) (good r8) (good r10) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r4)) (not (good r7)) (not (good r8)) (not (good r10)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-5-h2
:precondition (and (agent-at p8-5) (antena-height h2))
:effect (and
	(when (or  (good r0) (good r10)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r10))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-5-h3
:precondition (and (agent-at p8-5) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r10) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r10)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-5-h4
:precondition (and (agent-at p8-5) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r7) (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r7)) (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-6-h1
:precondition (and (agent-at p8-6) (antena-height h1))
:effect (and
	(when (or  (good r10)) (good-rocks-in-range))
	(when (and  (not (good r10))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-6-h2
:precondition (and (agent-at p8-6) (antena-height h2))
:effect (and
	(when (or  (good r10) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r10)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-6-h3
:precondition (and (agent-at p8-6) (antena-height h3))
:effect (and
	(when (or  (good r0) (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-6-h4
:precondition (and (agent-at p8-6) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-7-h0
:precondition (and (agent-at p8-7) (antena-height h0))
:effect (and
	(when (or  (good r10)) (good-rocks-in-range))
	(when (and  (not (good r10))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-7-h1
:precondition (and (agent-at p8-7) (antena-height h1))
:effect (and
	(when (or  (good r10) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r10)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-7-h2
:precondition (and (agent-at p8-7) (antena-height h2))
:effect (and
	(when (or  (good r10) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r10)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-7-h3
:precondition (and (agent-at p8-7) (antena-height h3))
:effect (and
	(when (or  (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-7-h4
:precondition (and (agent-at p8-7) (antena-height h4))
:effect (and
	(when (or  (good r0) (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r0)) (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-8-h0
:precondition (and (agent-at p8-8) (antena-height h0))
:effect (and
	(when (or  (good r13)) (good-rocks-in-range))
	(when (and  (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-8-h1
:precondition (and (agent-at p8-8) (antena-height h1))
:effect (and
	(when (or  (good r10) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r10)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-8-h2
:precondition (and (agent-at p8-8) (antena-height h2))
:effect (and
	(when (or  (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-8-h3
:precondition (and (agent-at p8-8) (antena-height h3))
:effect (and
	(when (or  (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action activate-sensor-at-p8-8-h4
:precondition (and (agent-at p8-8) (antena-height h4))
:effect (and
	(when (or  (good r10) (good r11) (good r13)) (good-rocks-in-range))
	(when (and  (not (good r10)) (not (good r11)) (not (good r13))) (not (good-rocks-in-range)))
))

(:action observe-sensor
:observe (good-rocks-in-range))

)