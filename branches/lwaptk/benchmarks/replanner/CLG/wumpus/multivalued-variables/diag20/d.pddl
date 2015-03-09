(define (domain diagonal-wumpus-20x20) 
    (:requirements :strips :typing)
    (:types pos)
    (:constants
         p1-1  p1-2  p1-3  p1-4  p1-5  p1-6  p1-7  p1-8  p1-9  p1-10  p1-11  p1-12  p1-13  p1-14  p1-15  p1-16  p1-17  p1-18  p1-19  p1-20
         p2-1  p2-2  p2-3  p2-4  p2-5  p2-6  p2-7  p2-8  p2-9  p2-10  p2-11  p2-12  p2-13  p2-14  p2-15  p2-16  p2-17  p2-18  p2-19  p2-20
         p3-1  p3-2  p3-3  p3-4  p3-5  p3-6  p3-7  p3-8  p3-9  p3-10  p3-11  p3-12  p3-13  p3-14  p3-15  p3-16  p3-17  p3-18  p3-19  p3-20
         p4-1  p4-2  p4-3  p4-4  p4-5  p4-6  p4-7  p4-8  p4-9  p4-10  p4-11  p4-12  p4-13  p4-14  p4-15  p4-16  p4-17  p4-18  p4-19  p4-20
         p5-1  p5-2  p5-3  p5-4  p5-5  p5-6  p5-7  p5-8  p5-9  p5-10  p5-11  p5-12  p5-13  p5-14  p5-15  p5-16  p5-17  p5-18  p5-19  p5-20
         p6-1  p6-2  p6-3  p6-4  p6-5  p6-6  p6-7  p6-8  p6-9  p6-10  p6-11  p6-12  p6-13  p6-14  p6-15  p6-16  p6-17  p6-18  p6-19  p6-20
         p7-1  p7-2  p7-3  p7-4  p7-5  p7-6  p7-7  p7-8  p7-9  p7-10  p7-11  p7-12  p7-13  p7-14  p7-15  p7-16  p7-17  p7-18  p7-19  p7-20
         p8-1  p8-2  p8-3  p8-4  p8-5  p8-6  p8-7  p8-8  p8-9  p8-10  p8-11  p8-12  p8-13  p8-14  p8-15  p8-16  p8-17  p8-18  p8-19  p8-20
         p9-1  p9-2  p9-3  p9-4  p9-5  p9-6  p9-7  p9-8  p9-9  p9-10  p9-11  p9-12  p9-13  p9-14  p9-15  p9-16  p9-17  p9-18  p9-19  p9-20
        p10-1 p10-2 p10-3 p10-4 p10-5 p10-6 p10-7 p10-8 p10-9 p10-10 p10-11 p10-12 p10-13 p10-14 p10-15 p10-16 p10-17 p10-18 p10-19 p10-20
        p11-1 p11-2 p11-3 p11-4 p11-5 p11-6 p11-7 p11-8 p11-9 p11-10 p11-11 p11-12 p11-13 p11-14 p11-15 p11-16 p11-17 p11-18 p11-19 p11-20
        p12-1 p12-2 p12-3 p12-4 p12-5 p12-6 p12-7 p12-8 p12-9 p12-10 p12-11 p12-12 p12-13 p12-14 p12-15 p12-16 p12-17 p12-18 p12-19 p12-20
        p13-1 p13-2 p13-3 p13-4 p13-5 p13-6 p13-7 p13-8 p13-9 p13-10 p13-11 p13-12 p13-13 p13-14 p13-15 p13-16 p13-17 p13-18 p13-19 p13-20
        p14-1 p14-2 p14-3 p14-4 p14-5 p14-6 p14-7 p14-8 p14-9 p14-10 p14-11 p14-12 p14-13 p14-14 p14-15 p14-16 p14-17 p14-18 p14-19 p14-20
        p15-1 p15-2 p15-3 p15-4 p15-5 p15-6 p15-7 p15-8 p15-9 p15-10 p15-11 p15-12 p15-13 p15-14 p15-15 p15-16 p15-17 p15-18 p15-19 p15-20
        p16-1 p16-2 p16-3 p16-4 p16-5 p16-6 p16-7 p16-8 p16-9 p16-10 p16-11 p16-12 p16-13 p16-14 p16-15 p16-16 p16-17 p16-18 p16-19 p16-20
        p17-1 p17-2 p17-3 p17-4 p17-5 p17-6 p17-7 p17-8 p17-9 p17-10 p17-11 p17-12 p17-13 p17-14 p17-15 p17-16 p17-17 p17-18 p17-19 p17-20
        p18-1 p18-2 p18-3 p18-4 p18-5 p18-6 p18-7 p18-8 p18-9 p18-10 p18-11 p18-12 p18-13 p18-14 p18-15 p18-16 p18-17 p18-18 p18-19 p18-20
        p19-1 p19-2 p19-3 p19-4 p19-5 p19-6 p19-7 p19-8 p19-9 p19-10 p19-11 p19-12 p19-13 p19-14 p19-15 p19-16 p19-17 p19-18 p19-19 p19-20
        p20-1 p20-2 p20-3 p20-4 p20-5 p20-6 p20-7 p20-8 p20-9 p20-10 p20-11 p20-12 p20-13 p20-14 p20-15 p20-16 p20-17 p20-18 p20-19 p20-20 - pos
    )
    (:predicates
        (adj ?p ?q - pos)
        (need-start)
        (at ?p - pos)
        (alive)
        (wumpus-at ?p - pos)
        (gold-at ?p - pos)
        (got-the-treasure)
        (stench ?p - pos)
        ;(glitter ?p - pos)
    )

    (:variable agent-pos (forall (?p - pos) (at ?p)))
    (:variable gold-pos (got-the-treasure) (forall (?p - pos) (gold-at ?p)))
    (:variable wumpus-1 (wumpus-at p2-3) (wumpus-at p3-2))
    (:variable wumpus-2 (wumpus-at p3-4) (wumpus-at p4-3))
    (:variable wumpus-3 (wumpus-at p4-5) (wumpus-at p5-4))
    (:variable wumpus-4 (wumpus-at p5-6) (wumpus-at p6-5))
    (:variable wumpus-5 (wumpus-at p6-7) (wumpus-at p7-6))
    (:variable wumpus-6 (wumpus-at p7-8) (wumpus-at p8-7))
    (:variable wumpus-7 (wumpus-at p8-9) (wumpus-at p9-8))
    (:variable wumpus-8 (wumpus-at p9-10) (wumpus-at p10-9))
    (:variable wumpus-9 (wumpus-at p10-11) (wumpus-at p11-10))
    (:variable wumpus-10 (wumpus-at p11-12) (wumpus-at p12-11))
    (:variable wumpus-11 (wumpus-at p12-13) (wumpus-at p13-12))
    (:variable wumpus-12 (wumpus-at p13-14) (wumpus-at p14-13))
    (:variable wumpus-13 (wumpus-at p14-15) (wumpus-at p15-14))
    (:variable wumpus-14 (wumpus-at p15-16) (wumpus-at p16-15))
    (:variable wumpus-15 (wumpus-at p16-17) (wumpus-at p17-16))
    (:variable wumpus-16 (wumpus-at p17-18) (wumpus-at p18-17))
    (:variable wumpus-17 (wumpus-at p18-19) (wumpus-at p19-18))
    (:variable wumpus-18 (wumpus-at p19-20) (wumpus-at p20-19))
    (:obs-variable (stench-var ?p - pos) (stench ?p))
    ;(:obs-variable (glitter-var ?p - pos) (glitter ?p))

    (:action start
        :parameters (?j - pos)
        :precondition (and (need-start) (at ?j))
        :effect (not (need-start))
        :sensing-model
            (and (forall (?p - pos) (when (and (adj ?j ?p) (wumpus-at ?p)) (stench ?j)))
                 ;(forall (?p - pos) (when (and (at ?p) (gold-at ?p)) (glitter ?p)))
            )
    )

    (:action move
        :parameters (?i ?j - pos)
        :precondition (and (adj ?i ?j) (at ?i) (alive) (not (need-start)))
        :effect
            (and (not (at ?i)) (at ?j)
                 (when (wumpus-at ?j) (not (alive)))
            )
        :sensing-model
            (and (forall (?p - pos) (when (and (adj ?j ?p) (wumpus-at ?p)) (stench ?j)))
                 (when (forall (?p - pos) (or (not (adj ?p ?j)) (not (wumpus-at ?p)))) (not (stench ?j)))
                 ;(forall (?p - pos) (when (and (at ?p) (gold-at ?p)) (glitter ?p)))
            )
    )

    (:action grab
        :parameters (?i - pos)
        :precondition (and (at ?i) (gold-at ?i) (alive))
        :effect (and (got-the-treasure) (not (gold-at ?i)))
    )
)
