(define (domain diagonal-wumpus-7x7)
    (:predicates
        (K_at_p1-1)
        (K_not_at_p1-1)
        (K_gold-at_p7-7)
        (K_not_gold-at_p7-7)
        (K_wumpus-at_p7-6)
        (K_not_wumpus-at_p7-6)
        (K_stench_p7-7)
        (K_not_stench_p7-7)
        (K_wumpus-at_p6-7)
        (K_not_wumpus-at_p6-7)
        (K_stench_p7-6)
        (K_not_stench_p7-6)
        (K_stench_p7-5)
        (K_not_stench_p7-5)
        (K_wumpus-at_p6-5)
        (K_not_wumpus-at_p6-5)
        (K_stench_p7-4)
        (K_not_stench_p7-4)
        (K_stench_p7-3)
        (K_not_stench_p7-3)
        (K_stench_p7-2)
        (K_not_stench_p7-2)
        (K_stench_p7-1)
        (K_not_stench_p7-1)
        (K_stench_p6-7)
        (K_not_stench_p6-7)
        (K_stench_p6-6)
        (K_not_stench_p6-6)
        (K_wumpus-at_p5-6)
        (K_not_wumpus-at_p5-6)
        (K_stench_p6-5)
        (K_not_stench_p6-5)
        (K_stench_p6-4)
        (K_not_stench_p6-4)
        (K_wumpus-at_p5-4)
        (K_not_wumpus-at_p5-4)
        (K_stench_p6-3)
        (K_not_stench_p6-3)
        (K_stench_p6-2)
        (K_not_stench_p6-2)
        (K_stench_p6-1)
        (K_not_stench_p6-1)
        (K_stench_p5-7)
        (K_not_stench_p5-7)
        (K_stench_p5-6)
        (K_not_stench_p5-6)
        (K_stench_p5-5)
        (K_not_stench_p5-5)
        (K_wumpus-at_p4-5)
        (K_not_wumpus-at_p4-5)
        (K_stench_p5-4)
        (K_not_stench_p5-4)
        (K_stench_p5-3)
        (K_not_stench_p5-3)
        (K_wumpus-at_p4-3)
        (K_not_wumpus-at_p4-3)
        (K_stench_p5-2)
        (K_not_stench_p5-2)
        (K_stench_p5-1)
        (K_not_stench_p5-1)
        (K_stench_p4-7)
        (K_not_stench_p4-7)
        (K_stench_p4-6)
        (K_not_stench_p4-6)
        (K_stench_p4-5)
        (K_not_stench_p4-5)
        (K_stench_p4-4)
        (K_not_stench_p4-4)
        (K_wumpus-at_p3-4)
        (K_not_wumpus-at_p3-4)
        (K_stench_p4-3)
        (K_not_stench_p4-3)
        (K_stench_p4-2)
        (K_not_stench_p4-2)
        (K_wumpus-at_p3-2)
        (K_not_wumpus-at_p3-2)
        (K_stench_p4-1)
        (K_not_stench_p4-1)
        (K_stench_p3-7)
        (K_not_stench_p3-7)
        (K_stench_p3-6)
        (K_not_stench_p3-6)
        (K_stench_p3-5)
        (K_not_stench_p3-5)
        (K_stench_p3-4)
        (K_not_stench_p3-4)
        (K_stench_p3-3)
        (K_not_stench_p3-3)
        (K_wumpus-at_p2-3)
        (K_not_wumpus-at_p2-3)
        (K_stench_p3-2)
        (K_not_stench_p3-2)
        (K_stench_p3-1)
        (K_not_stench_p3-1)
        (K_stench_p2-7)
        (K_not_stench_p2-7)
        (K_stench_p2-6)
        (K_not_stench_p2-6)
        (K_stench_p2-5)
        (K_not_stench_p2-5)
        (K_stench_p2-4)
        (K_not_stench_p2-4)
        (K_stench_p2-3)
        (K_not_stench_p2-3)
        (K_stench_p2-2)
        (K_not_stench_p2-2)
        (K_stench_p2-1)
        (K_not_stench_p2-1)
        (K_stench_p1-7)
        (K_not_stench_p1-7)
        (K_stench_p1-6)
        (K_not_stench_p1-6)
        (K_stench_p1-5)
        (K_not_stench_p1-5)
        (K_stench_p1-4)
        (K_not_stench_p1-4)
        (K_stench_p1-3)
        (K_not_stench_p1-3)
        (K_stench_p1-2)
        (K_not_stench_p1-2)
        (K_stench_p1-1)
        (K_not_stench_p1-1)
        (K_normal-execution)
        (K_not_normal-execution)
        (K_at_p7-7)
        (K_not_at_p7-7)
        (K_at_p7-6)
        (K_not_at_p7-6)
        (K_at_p7-5)
        (K_not_at_p7-5)
        (K_at_p7-4)
        (K_not_at_p7-4)
        (K_at_p7-3)
        (K_not_at_p7-3)
        (K_at_p7-2)
        (K_not_at_p7-2)
        (K_at_p7-1)
        (K_not_at_p7-1)
        (K_at_p6-7)
        (K_not_at_p6-7)
        (K_at_p6-6)
        (K_not_at_p6-6)
        (K_at_p6-5)
        (K_not_at_p6-5)
        (K_at_p6-4)
        (K_not_at_p6-4)
        (K_at_p6-3)
        (K_not_at_p6-3)
        (K_at_p6-2)
        (K_not_at_p6-2)
        (K_at_p6-1)
        (K_not_at_p6-1)
        (K_at_p5-7)
        (K_not_at_p5-7)
        (K_at_p5-6)
        (K_not_at_p5-6)
        (K_at_p5-5)
        (K_not_at_p5-5)
        (K_at_p5-4)
        (K_not_at_p5-4)
        (K_at_p5-3)
        (K_not_at_p5-3)
        (K_at_p5-2)
        (K_not_at_p5-2)
        (K_at_p5-1)
        (K_not_at_p5-1)
        (K_at_p4-7)
        (K_not_at_p4-7)
        (K_at_p4-6)
        (K_not_at_p4-6)
        (K_at_p4-5)
        (K_not_at_p4-5)
        (K_at_p4-4)
        (K_not_at_p4-4)
        (K_at_p4-3)
        (K_not_at_p4-3)
        (K_at_p4-2)
        (K_not_at_p4-2)
        (K_at_p4-1)
        (K_not_at_p4-1)
        (K_at_p3-7)
        (K_not_at_p3-7)
        (K_at_p3-6)
        (K_not_at_p3-6)
        (K_at_p3-5)
        (K_not_at_p3-5)
        (K_at_p3-4)
        (K_not_at_p3-4)
        (K_at_p3-3)
        (K_not_at_p3-3)
        (K_at_p3-2)
        (K_not_at_p3-2)
        (K_at_p3-1)
        (K_not_at_p3-1)
        (K_at_p2-7)
        (K_not_at_p2-7)
        (K_at_p2-6)
        (K_not_at_p2-6)
        (K_at_p2-5)
        (K_not_at_p2-5)
        (K_at_p2-4)
        (K_not_at_p2-4)
        (K_at_p2-3)
        (K_not_at_p2-3)
        (K_at_p2-2)
        (K_not_at_p2-2)
        (K_at_p2-1)
        (K_not_at_p2-1)
        (K_at_p1-7)
        (K_not_at_p1-7)
        (K_at_p1-6)
        (K_not_at_p1-6)
        (K_at_p1-5)
        (K_not_at_p1-5)
        (K_at_p1-4)
        (K_not_at_p1-4)
        (K_at_p1-3)
        (K_not_at_p1-3)
        (K_at_p1-2)
        (K_not_at_p1-2)
        (K_safe_p7-7)
        (K_not_safe_p7-7)
        (K_safe_p7-6)
        (K_not_safe_p7-6)
        (K_safe_p7-5)
        (K_not_safe_p7-5)
        (K_safe_p7-4)
        (K_not_safe_p7-4)
        (K_safe_p7-3)
        (K_not_safe_p7-3)
        (K_safe_p7-2)
        (K_not_safe_p7-2)
        (K_safe_p7-1)
        (K_not_safe_p7-1)
        (K_safe_p6-7)
        (K_not_safe_p6-7)
        (K_safe_p6-6)
        (K_not_safe_p6-6)
        (K_safe_p6-5)
        (K_not_safe_p6-5)
        (K_safe_p6-4)
        (K_not_safe_p6-4)
        (K_safe_p6-3)
        (K_not_safe_p6-3)
        (K_safe_p6-2)
        (K_not_safe_p6-2)
        (K_safe_p6-1)
        (K_not_safe_p6-1)
        (K_safe_p5-7)
        (K_not_safe_p5-7)
        (K_safe_p5-6)
        (K_not_safe_p5-6)
        (K_safe_p5-5)
        (K_not_safe_p5-5)
        (K_safe_p5-4)
        (K_not_safe_p5-4)
        (K_safe_p5-3)
        (K_not_safe_p5-3)
        (K_safe_p5-2)
        (K_not_safe_p5-2)
        (K_safe_p5-1)
        (K_not_safe_p5-1)
        (K_safe_p4-7)
        (K_not_safe_p4-7)
        (K_safe_p4-6)
        (K_not_safe_p4-6)
        (K_safe_p4-5)
        (K_not_safe_p4-5)
        (K_safe_p4-4)
        (K_not_safe_p4-4)
        (K_safe_p4-3)
        (K_not_safe_p4-3)
        (K_safe_p4-2)
        (K_not_safe_p4-2)
        (K_safe_p4-1)
        (K_not_safe_p4-1)
        (K_safe_p3-7)
        (K_not_safe_p3-7)
        (K_safe_p3-6)
        (K_not_safe_p3-6)
        (K_safe_p3-5)
        (K_not_safe_p3-5)
        (K_safe_p3-4)
        (K_not_safe_p3-4)
        (K_safe_p3-3)
        (K_not_safe_p3-3)
        (K_safe_p3-2)
        (K_not_safe_p3-2)
        (K_safe_p3-1)
        (K_not_safe_p3-1)
        (K_safe_p2-7)
        (K_not_safe_p2-7)
        (K_safe_p2-6)
        (K_not_safe_p2-6)
        (K_safe_p2-5)
        (K_not_safe_p2-5)
        (K_safe_p2-4)
        (K_not_safe_p2-4)
        (K_safe_p2-3)
        (K_not_safe_p2-3)
        (K_safe_p2-2)
        (K_not_safe_p2-2)
        (K_safe_p2-1)
        (K_not_safe_p2-1)
        (K_safe_p1-7)
        (K_not_safe_p1-7)
        (K_safe_p1-6)
        (K_not_safe_p1-6)
        (K_safe_p1-5)
        (K_not_safe_p1-5)
        (K_safe_p1-4)
        (K_not_safe_p1-4)
        (K_safe_p1-3)
        (K_not_safe_p1-3)
        (K_safe_p1-2)
        (K_not_safe_p1-2)
        (K_safe_p1-1)
        (K_not_safe_p1-1)
        (K_got-the-treasure)
        (K_not_got-the-treasure)
        (K_need-post-for-smell-wumpus_p7-7)
        (K_not_need-post-for-smell-wumpus_p7-7)
        (K_need-post-for-smell-wumpus_p7-6)
        (K_not_need-post-for-smell-wumpus_p7-6)
        (K_need-post-for-smell-wumpus_p7-5)
        (K_not_need-post-for-smell-wumpus_p7-5)
        (K_need-post-for-smell-wumpus_p7-4)
        (K_not_need-post-for-smell-wumpus_p7-4)
        (K_need-post-for-smell-wumpus_p7-3)
        (K_not_need-post-for-smell-wumpus_p7-3)
        (K_need-post-for-smell-wumpus_p7-2)
        (K_not_need-post-for-smell-wumpus_p7-2)
        (K_need-post-for-smell-wumpus_p7-1)
        (K_not_need-post-for-smell-wumpus_p7-1)
        (K_need-post-for-smell-wumpus_p6-7)
        (K_not_need-post-for-smell-wumpus_p6-7)
        (K_need-post-for-smell-wumpus_p6-6)
        (K_not_need-post-for-smell-wumpus_p6-6)
        (K_need-post-for-smell-wumpus_p6-5)
        (K_not_need-post-for-smell-wumpus_p6-5)
        (K_need-post-for-smell-wumpus_p6-4)
        (K_not_need-post-for-smell-wumpus_p6-4)
        (K_need-post-for-smell-wumpus_p6-3)
        (K_not_need-post-for-smell-wumpus_p6-3)
        (K_need-post-for-smell-wumpus_p6-2)
        (K_not_need-post-for-smell-wumpus_p6-2)
        (K_need-post-for-smell-wumpus_p6-1)
        (K_not_need-post-for-smell-wumpus_p6-1)
        (K_need-post-for-smell-wumpus_p5-7)
        (K_not_need-post-for-smell-wumpus_p5-7)
        (K_need-post-for-smell-wumpus_p5-6)
        (K_not_need-post-for-smell-wumpus_p5-6)
        (K_need-post-for-smell-wumpus_p5-5)
        (K_not_need-post-for-smell-wumpus_p5-5)
        (K_need-post-for-smell-wumpus_p5-4)
        (K_not_need-post-for-smell-wumpus_p5-4)
        (K_need-post-for-smell-wumpus_p5-3)
        (K_not_need-post-for-smell-wumpus_p5-3)
        (K_need-post-for-smell-wumpus_p5-2)
        (K_not_need-post-for-smell-wumpus_p5-2)
        (K_need-post-for-smell-wumpus_p5-1)
        (K_not_need-post-for-smell-wumpus_p5-1)
        (K_need-post-for-smell-wumpus_p4-7)
        (K_not_need-post-for-smell-wumpus_p4-7)
        (K_need-post-for-smell-wumpus_p4-6)
        (K_not_need-post-for-smell-wumpus_p4-6)
        (K_need-post-for-smell-wumpus_p4-5)
        (K_not_need-post-for-smell-wumpus_p4-5)
        (K_need-post-for-smell-wumpus_p4-4)
        (K_not_need-post-for-smell-wumpus_p4-4)
        (K_need-post-for-smell-wumpus_p4-3)
        (K_not_need-post-for-smell-wumpus_p4-3)
        (K_need-post-for-smell-wumpus_p4-2)
        (K_not_need-post-for-smell-wumpus_p4-2)
        (K_need-post-for-smell-wumpus_p4-1)
        (K_not_need-post-for-smell-wumpus_p4-1)
        (K_need-post-for-smell-wumpus_p3-7)
        (K_not_need-post-for-smell-wumpus_p3-7)
        (K_need-post-for-smell-wumpus_p3-6)
        (K_not_need-post-for-smell-wumpus_p3-6)
        (K_need-post-for-smell-wumpus_p3-5)
        (K_not_need-post-for-smell-wumpus_p3-5)
        (K_need-post-for-smell-wumpus_p3-4)
        (K_not_need-post-for-smell-wumpus_p3-4)
        (K_need-post-for-smell-wumpus_p3-3)
        (K_not_need-post-for-smell-wumpus_p3-3)
        (K_need-post-for-smell-wumpus_p3-2)
        (K_not_need-post-for-smell-wumpus_p3-2)
        (K_need-post-for-smell-wumpus_p3-1)
        (K_not_need-post-for-smell-wumpus_p3-1)
        (K_need-post-for-smell-wumpus_p2-7)
        (K_not_need-post-for-smell-wumpus_p2-7)
        (K_need-post-for-smell-wumpus_p2-6)
        (K_not_need-post-for-smell-wumpus_p2-6)
        (K_need-post-for-smell-wumpus_p2-5)
        (K_not_need-post-for-smell-wumpus_p2-5)
        (K_need-post-for-smell-wumpus_p2-4)
        (K_not_need-post-for-smell-wumpus_p2-4)
        (K_need-post-for-smell-wumpus_p2-3)
        (K_not_need-post-for-smell-wumpus_p2-3)
        (K_need-post-for-smell-wumpus_p2-2)
        (K_not_need-post-for-smell-wumpus_p2-2)
        (K_need-post-for-smell-wumpus_p2-1)
        (K_not_need-post-for-smell-wumpus_p2-1)
        (K_need-post-for-smell-wumpus_p1-7)
        (K_not_need-post-for-smell-wumpus_p1-7)
        (K_need-post-for-smell-wumpus_p1-6)
        (K_not_need-post-for-smell-wumpus_p1-6)
        (K_need-post-for-smell-wumpus_p1-5)
        (K_not_need-post-for-smell-wumpus_p1-5)
        (K_need-post-for-smell-wumpus_p1-4)
        (K_not_need-post-for-smell-wumpus_p1-4)
        (K_need-post-for-smell-wumpus_p1-3)
        (K_not_need-post-for-smell-wumpus_p1-3)
        (K_need-post-for-smell-wumpus_p1-2)
        (K_not_need-post-for-smell-wumpus_p1-2)
        (K_need-post-for-smell-wumpus_p1-1)
        (K_not_need-post-for-smell-wumpus_p1-1)
    )
    (:action inference_p1-1
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p1-1)) (K_safe_p1-1)))
    (:action inference_p1-2
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p1-2)) (K_safe_p1-2)))
    (:action inference_p1-3
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p1-3)) (K_safe_p1-3)))
    (:action inference_p1-4
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p1-4)) (K_safe_p1-4)))
    (:action inference_p1-5
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p1-5)) (K_safe_p1-5)))
    (:action inference_p1-6
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p1-6)) (K_safe_p1-6)))
    (:action inference_p1-7
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p1-7)) (K_safe_p1-7)))
    (:action inference_p2-1
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p2-1)) (K_safe_p2-1)))
    (:action inference_p2-2
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p2-2)) (K_safe_p2-2)))
    (:action inference_p2-3
        :precondition (and (K_not_wumpus-at_p2-3) (K_normal-execution))
        :effect (and (not (K_not_safe_p2-3)) (K_safe_p2-3)))
    (:action inference_p2-4
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p2-4)) (K_safe_p2-4)))
    (:action inference_p2-5
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p2-5)) (K_safe_p2-5)))
    (:action inference_p2-6
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p2-6)) (K_safe_p2-6)))
    (:action inference_p2-7
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p2-7)) (K_safe_p2-7)))
    (:action inference_p3-1
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p3-1)) (K_safe_p3-1)))
    (:action inference_p3-2
        :precondition (and (K_not_wumpus-at_p3-2) (K_normal-execution))
        :effect (and (not (K_not_safe_p3-2)) (K_safe_p3-2)))
    (:action inference_p3-3
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p3-3)) (K_safe_p3-3)))
    (:action inference_p3-4
        :precondition (and (K_not_wumpus-at_p3-4) (K_normal-execution))
        :effect (and (not (K_not_safe_p3-4)) (K_safe_p3-4)))
    (:action inference_p3-5
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p3-5)) (K_safe_p3-5)))
    (:action inference_p3-6
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p3-6)) (K_safe_p3-6)))
    (:action inference_p3-7
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p3-7)) (K_safe_p3-7)))
    (:action inference_p4-1
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p4-1)) (K_safe_p4-1)))
    (:action inference_p4-2
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p4-2)) (K_safe_p4-2)))
    (:action inference_p4-3
        :precondition (and (K_not_wumpus-at_p4-3) (K_normal-execution))
        :effect (and (not (K_not_safe_p4-3)) (K_safe_p4-3)))
    (:action inference_p4-4
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p4-4)) (K_safe_p4-4)))
    (:action inference_p4-5
        :precondition (and (K_not_wumpus-at_p4-5) (K_normal-execution))
        :effect (and (not (K_not_safe_p4-5)) (K_safe_p4-5)))
    (:action inference_p4-6
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p4-6)) (K_safe_p4-6)))
    (:action inference_p4-7
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p4-7)) (K_safe_p4-7)))
    (:action inference_p5-1
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p5-1)) (K_safe_p5-1)))
    (:action inference_p5-2
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p5-2)) (K_safe_p5-2)))
    (:action inference_p5-3
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p5-3)) (K_safe_p5-3)))
    (:action inference_p5-4
        :precondition (and (K_not_wumpus-at_p5-4) (K_normal-execution))
        :effect (and (not (K_not_safe_p5-4)) (K_safe_p5-4)))
    (:action inference_p5-5
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p5-5)) (K_safe_p5-5)))
    (:action inference_p5-6
        :precondition (and (K_not_wumpus-at_p5-6) (K_normal-execution))
        :effect (and (not (K_not_safe_p5-6)) (K_safe_p5-6)))
    (:action inference_p5-7
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p5-7)) (K_safe_p5-7)))
    (:action inference_p6-1
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p6-1)) (K_safe_p6-1)))
    (:action inference_p6-2
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p6-2)) (K_safe_p6-2)))
    (:action inference_p6-3
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p6-3)) (K_safe_p6-3)))
    (:action inference_p6-4
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p6-4)) (K_safe_p6-4)))
    (:action inference_p6-5
        :precondition (and (K_not_wumpus-at_p6-5) (K_normal-execution))
        :effect (and (not (K_not_safe_p6-5)) (K_safe_p6-5)))
    (:action inference_p6-6
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p6-6)) (K_safe_p6-6)))
    (:action inference_p6-7
        :precondition (and (K_not_wumpus-at_p6-7) (K_normal-execution))
        :effect (and (not (K_not_safe_p6-7)) (K_safe_p6-7)))
    (:action inference_p7-1
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p7-1)) (K_safe_p7-1)))
    (:action inference_p7-2
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p7-2)) (K_safe_p7-2)))
    (:action inference_p7-3
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p7-3)) (K_safe_p7-3)))
    (:action inference_p7-4
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p7-4)) (K_safe_p7-4)))
    (:action inference_p7-5
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p7-5)) (K_safe_p7-5)))
    (:action inference_p7-6
        :precondition (and (K_not_wumpus-at_p7-6) (K_normal-execution))
        :effect (and (not (K_not_safe_p7-6)) (K_safe_p7-6)))
    (:action inference_p7-7
        :precondition (K_normal-execution)
        :effect (and (not (K_not_safe_p7-7)) (K_safe_p7-7)))
    (:action move_p7-7_p7-6
        :precondition (and (K_normal-execution) (K_at_p7-7) (K_safe_p7-6))
        :effect (and (not (K_not_at_p7-6)) (not (K_at_p7-7)) (K_not_at_p7-7) (K_at_p7-6)))
    (:action move_p7-7_p6-7
        :precondition (and (K_normal-execution) (K_at_p7-7) (K_safe_p6-7))
        :effect (and (not (K_not_at_p6-7)) (not (K_at_p7-7)) (K_not_at_p7-7) (K_at_p6-7)))
    (:action move_p7-6_p7-7
        :precondition (and (K_normal-execution) (K_at_p7-6) (K_safe_p7-7))
        :effect (and (not (K_at_p7-6)) (not (K_not_at_p7-7)) (K_at_p7-7) (K_not_at_p7-6)))
    (:action move_p7-6_p7-5
        :precondition (and (K_normal-execution) (K_at_p7-6) (K_safe_p7-5))
        :effect (and (not (K_not_at_p7-5)) (not (K_at_p7-6)) (K_not_at_p7-6) (K_at_p7-5)))
    (:action move_p7-6_p6-6
        :precondition (and (K_normal-execution) (K_at_p7-6) (K_safe_p6-6))
        :effect (and (not (K_not_at_p6-6)) (not (K_at_p7-6)) (K_not_at_p7-6) (K_at_p6-6)))
    (:action move_p7-5_p7-6
        :precondition (and (K_normal-execution) (K_at_p7-5) (K_safe_p7-6))
        :effect (and (not (K_at_p7-5)) (not (K_not_at_p7-6)) (K_at_p7-6) (K_not_at_p7-5)))
    (:action move_p7-5_p7-4
        :precondition (and (K_normal-execution) (K_at_p7-5) (K_safe_p7-4))
        :effect (and (not (K_not_at_p7-4)) (not (K_at_p7-5)) (K_not_at_p7-5) (K_at_p7-4)))
    (:action move_p7-5_p6-5
        :precondition (and (K_normal-execution) (K_at_p7-5) (K_safe_p6-5))
        :effect (and (not (K_not_at_p6-5)) (not (K_at_p7-5)) (K_not_at_p7-5) (K_at_p6-5)))
    (:action move_p7-4_p7-5
        :precondition (and (K_normal-execution) (K_at_p7-4) (K_safe_p7-5))
        :effect (and (not (K_at_p7-4)) (not (K_not_at_p7-5)) (K_at_p7-5) (K_not_at_p7-4)))
    (:action move_p7-4_p7-3
        :precondition (and (K_normal-execution) (K_at_p7-4) (K_safe_p7-3))
        :effect (and (not (K_not_at_p7-3)) (not (K_at_p7-4)) (K_not_at_p7-4) (K_at_p7-3)))
    (:action move_p7-4_p6-4
        :precondition (and (K_normal-execution) (K_at_p7-4) (K_safe_p6-4))
        :effect (and (not (K_not_at_p6-4)) (not (K_at_p7-4)) (K_not_at_p7-4) (K_at_p6-4)))
    (:action move_p7-3_p7-4
        :precondition (and (K_normal-execution) (K_at_p7-3) (K_safe_p7-4))
        :effect (and (not (K_at_p7-3)) (not (K_not_at_p7-4)) (K_at_p7-4) (K_not_at_p7-3)))
    (:action move_p7-3_p7-2
        :precondition (and (K_normal-execution) (K_at_p7-3) (K_safe_p7-2))
        :effect (and (not (K_not_at_p7-2)) (not (K_at_p7-3)) (K_not_at_p7-3) (K_at_p7-2)))
    (:action move_p7-3_p6-3
        :precondition (and (K_normal-execution) (K_at_p7-3) (K_safe_p6-3))
        :effect (and (not (K_not_at_p6-3)) (not (K_at_p7-3)) (K_not_at_p7-3) (K_at_p6-3)))
    (:action move_p7-2_p7-3
        :precondition (and (K_normal-execution) (K_at_p7-2) (K_safe_p7-3))
        :effect (and (not (K_at_p7-2)) (not (K_not_at_p7-3)) (K_at_p7-3) (K_not_at_p7-2)))
    (:action move_p7-2_p7-1
        :precondition (and (K_normal-execution) (K_at_p7-2) (K_safe_p7-1))
        :effect (and (not (K_not_at_p7-1)) (not (K_at_p7-2)) (K_not_at_p7-2) (K_at_p7-1)))
    (:action move_p7-2_p6-2
        :precondition (and (K_normal-execution) (K_at_p7-2) (K_safe_p6-2))
        :effect (and (not (K_not_at_p6-2)) (not (K_at_p7-2)) (K_not_at_p7-2) (K_at_p6-2)))
    (:action move_p7-1_p7-2
        :precondition (and (K_normal-execution) (K_at_p7-1) (K_safe_p7-2))
        :effect (and (not (K_at_p7-1)) (not (K_not_at_p7-2)) (K_at_p7-2) (K_not_at_p7-1)))
    (:action move_p7-1_p6-1
        :precondition (and (K_normal-execution) (K_at_p7-1) (K_safe_p6-1))
        :effect (and (not (K_not_at_p6-1)) (not (K_at_p7-1)) (K_not_at_p7-1) (K_at_p6-1)))
    (:action move_p6-7_p7-7
        :precondition (and (K_normal-execution) (K_at_p6-7) (K_safe_p7-7))
        :effect (and (not (K_at_p6-7)) (not (K_not_at_p7-7)) (K_at_p7-7) (K_not_at_p6-7)))
    (:action move_p6-7_p6-6
        :precondition (and (K_normal-execution) (K_at_p6-7) (K_safe_p6-6))
        :effect (and (not (K_not_at_p6-6)) (not (K_at_p6-7)) (K_not_at_p6-7) (K_at_p6-6)))
    (:action move_p6-7_p5-7
        :precondition (and (K_normal-execution) (K_at_p6-7) (K_safe_p5-7))
        :effect (and (not (K_not_at_p5-7)) (not (K_at_p6-7)) (K_not_at_p6-7) (K_at_p5-7)))
    (:action move_p6-6_p7-6
        :precondition (and (K_normal-execution) (K_at_p6-6) (K_safe_p7-6))
        :effect (and (not (K_at_p6-6)) (not (K_not_at_p7-6)) (K_at_p7-6) (K_not_at_p6-6)))
    (:action move_p6-6_p6-7
        :precondition (and (K_normal-execution) (K_at_p6-6) (K_safe_p6-7))
        :effect (and (not (K_at_p6-6)) (not (K_not_at_p6-7)) (K_at_p6-7) (K_not_at_p6-6)))
    (:action move_p6-6_p6-5
        :precondition (and (K_normal-execution) (K_at_p6-6) (K_safe_p6-5))
        :effect (and (not (K_not_at_p6-5)) (not (K_at_p6-6)) (K_not_at_p6-6) (K_at_p6-5)))
    (:action move_p6-6_p5-6
        :precondition (and (K_normal-execution) (K_at_p6-6) (K_safe_p5-6))
        :effect (and (not (K_not_at_p5-6)) (not (K_at_p6-6)) (K_not_at_p6-6) (K_at_p5-6)))
    (:action move_p6-5_p7-5
        :precondition (and (K_normal-execution) (K_at_p6-5) (K_safe_p7-5))
        :effect (and (not (K_at_p6-5)) (not (K_not_at_p7-5)) (K_at_p7-5) (K_not_at_p6-5)))
    (:action move_p6-5_p6-6
        :precondition (and (K_normal-execution) (K_at_p6-5) (K_safe_p6-6))
        :effect (and (not (K_at_p6-5)) (not (K_not_at_p6-6)) (K_at_p6-6) (K_not_at_p6-5)))
    (:action move_p6-5_p6-4
        :precondition (and (K_normal-execution) (K_at_p6-5) (K_safe_p6-4))
        :effect (and (not (K_not_at_p6-4)) (not (K_at_p6-5)) (K_not_at_p6-5) (K_at_p6-4)))
    (:action move_p6-5_p5-5
        :precondition (and (K_normal-execution) (K_at_p6-5) (K_safe_p5-5))
        :effect (and (not (K_not_at_p5-5)) (not (K_at_p6-5)) (K_not_at_p6-5) (K_at_p5-5)))
    (:action move_p6-4_p7-4
        :precondition (and (K_normal-execution) (K_at_p6-4) (K_safe_p7-4))
        :effect (and (not (K_at_p6-4)) (not (K_not_at_p7-4)) (K_at_p7-4) (K_not_at_p6-4)))
    (:action move_p6-4_p6-5
        :precondition (and (K_normal-execution) (K_at_p6-4) (K_safe_p6-5))
        :effect (and (not (K_at_p6-4)) (not (K_not_at_p6-5)) (K_at_p6-5) (K_not_at_p6-4)))
    (:action move_p6-4_p6-3
        :precondition (and (K_normal-execution) (K_at_p6-4) (K_safe_p6-3))
        :effect (and (not (K_not_at_p6-3)) (not (K_at_p6-4)) (K_not_at_p6-4) (K_at_p6-3)))
    (:action move_p6-4_p5-4
        :precondition (and (K_normal-execution) (K_at_p6-4) (K_safe_p5-4))
        :effect (and (not (K_not_at_p5-4)) (not (K_at_p6-4)) (K_not_at_p6-4) (K_at_p5-4)))
    (:action move_p6-3_p7-3
        :precondition (and (K_normal-execution) (K_at_p6-3) (K_safe_p7-3))
        :effect (and (not (K_at_p6-3)) (not (K_not_at_p7-3)) (K_at_p7-3) (K_not_at_p6-3)))
    (:action move_p6-3_p6-4
        :precondition (and (K_normal-execution) (K_at_p6-3) (K_safe_p6-4))
        :effect (and (not (K_at_p6-3)) (not (K_not_at_p6-4)) (K_at_p6-4) (K_not_at_p6-3)))
    (:action move_p6-3_p6-2
        :precondition (and (K_normal-execution) (K_at_p6-3) (K_safe_p6-2))
        :effect (and (not (K_not_at_p6-2)) (not (K_at_p6-3)) (K_not_at_p6-3) (K_at_p6-2)))
    (:action move_p6-3_p5-3
        :precondition (and (K_normal-execution) (K_at_p6-3) (K_safe_p5-3))
        :effect (and (not (K_not_at_p5-3)) (not (K_at_p6-3)) (K_not_at_p6-3) (K_at_p5-3)))
    (:action move_p6-2_p7-2
        :precondition (and (K_normal-execution) (K_at_p6-2) (K_safe_p7-2))
        :effect (and (not (K_at_p6-2)) (not (K_not_at_p7-2)) (K_at_p7-2) (K_not_at_p6-2)))
    (:action move_p6-2_p6-3
        :precondition (and (K_normal-execution) (K_at_p6-2) (K_safe_p6-3))
        :effect (and (not (K_at_p6-2)) (not (K_not_at_p6-3)) (K_at_p6-3) (K_not_at_p6-2)))
    (:action move_p6-2_p6-1
        :precondition (and (K_normal-execution) (K_at_p6-2) (K_safe_p6-1))
        :effect (and (not (K_not_at_p6-1)) (not (K_at_p6-2)) (K_not_at_p6-2) (K_at_p6-1)))
    (:action move_p6-2_p5-2
        :precondition (and (K_normal-execution) (K_at_p6-2) (K_safe_p5-2))
        :effect (and (not (K_not_at_p5-2)) (not (K_at_p6-2)) (K_not_at_p6-2) (K_at_p5-2)))
    (:action move_p6-1_p7-1
        :precondition (and (K_normal-execution) (K_at_p6-1) (K_safe_p7-1))
        :effect (and (not (K_at_p6-1)) (not (K_not_at_p7-1)) (K_at_p7-1) (K_not_at_p6-1)))
    (:action move_p6-1_p6-2
        :precondition (and (K_normal-execution) (K_at_p6-1) (K_safe_p6-2))
        :effect (and (not (K_at_p6-1)) (not (K_not_at_p6-2)) (K_at_p6-2) (K_not_at_p6-1)))
    (:action move_p6-1_p5-1
        :precondition (and (K_normal-execution) (K_at_p6-1) (K_safe_p5-1))
        :effect (and (not (K_not_at_p5-1)) (not (K_at_p6-1)) (K_not_at_p6-1) (K_at_p5-1)))
    (:action move_p5-7_p6-7
        :precondition (and (K_normal-execution) (K_at_p5-7) (K_safe_p6-7))
        :effect (and (not (K_at_p5-7)) (not (K_not_at_p6-7)) (K_at_p6-7) (K_not_at_p5-7)))
    (:action move_p5-7_p5-6
        :precondition (and (K_normal-execution) (K_at_p5-7) (K_safe_p5-6))
        :effect (and (not (K_not_at_p5-6)) (not (K_at_p5-7)) (K_not_at_p5-7) (K_at_p5-6)))
    (:action move_p5-7_p4-7
        :precondition (and (K_normal-execution) (K_at_p5-7) (K_safe_p4-7))
        :effect (and (not (K_not_at_p4-7)) (not (K_at_p5-7)) (K_not_at_p5-7) (K_at_p4-7)))
    (:action move_p5-6_p6-6
        :precondition (and (K_normal-execution) (K_at_p5-6) (K_safe_p6-6))
        :effect (and (not (K_at_p5-6)) (not (K_not_at_p6-6)) (K_at_p6-6) (K_not_at_p5-6)))
    (:action move_p5-6_p5-7
        :precondition (and (K_normal-execution) (K_at_p5-6) (K_safe_p5-7))
        :effect (and (not (K_at_p5-6)) (not (K_not_at_p5-7)) (K_at_p5-7) (K_not_at_p5-6)))
    (:action move_p5-6_p5-5
        :precondition (and (K_normal-execution) (K_at_p5-6) (K_safe_p5-5))
        :effect (and (not (K_not_at_p5-5)) (not (K_at_p5-6)) (K_not_at_p5-6) (K_at_p5-5)))
    (:action move_p5-6_p4-6
        :precondition (and (K_normal-execution) (K_at_p5-6) (K_safe_p4-6))
        :effect (and (not (K_not_at_p4-6)) (not (K_at_p5-6)) (K_not_at_p5-6) (K_at_p4-6)))
    (:action move_p5-5_p6-5
        :precondition (and (K_normal-execution) (K_at_p5-5) (K_safe_p6-5))
        :effect (and (not (K_at_p5-5)) (not (K_not_at_p6-5)) (K_at_p6-5) (K_not_at_p5-5)))
    (:action move_p5-5_p5-6
        :precondition (and (K_normal-execution) (K_at_p5-5) (K_safe_p5-6))
        :effect (and (not (K_at_p5-5)) (not (K_not_at_p5-6)) (K_at_p5-6) (K_not_at_p5-5)))
    (:action move_p5-5_p5-4
        :precondition (and (K_normal-execution) (K_at_p5-5) (K_safe_p5-4))
        :effect (and (not (K_not_at_p5-4)) (not (K_at_p5-5)) (K_not_at_p5-5) (K_at_p5-4)))
    (:action move_p5-5_p4-5
        :precondition (and (K_normal-execution) (K_at_p5-5) (K_safe_p4-5))
        :effect (and (not (K_not_at_p4-5)) (not (K_at_p5-5)) (K_not_at_p5-5) (K_at_p4-5)))
    (:action move_p5-4_p6-4
        :precondition (and (K_normal-execution) (K_at_p5-4) (K_safe_p6-4))
        :effect (and (not (K_at_p5-4)) (not (K_not_at_p6-4)) (K_at_p6-4) (K_not_at_p5-4)))
    (:action move_p5-4_p5-5
        :precondition (and (K_normal-execution) (K_at_p5-4) (K_safe_p5-5))
        :effect (and (not (K_at_p5-4)) (not (K_not_at_p5-5)) (K_at_p5-5) (K_not_at_p5-4)))
    (:action move_p5-4_p5-3
        :precondition (and (K_normal-execution) (K_at_p5-4) (K_safe_p5-3))
        :effect (and (not (K_not_at_p5-3)) (not (K_at_p5-4)) (K_not_at_p5-4) (K_at_p5-3)))
    (:action move_p5-4_p4-4
        :precondition (and (K_normal-execution) (K_at_p5-4) (K_safe_p4-4))
        :effect (and (not (K_not_at_p4-4)) (not (K_at_p5-4)) (K_not_at_p5-4) (K_at_p4-4)))
    (:action move_p5-3_p6-3
        :precondition (and (K_normal-execution) (K_at_p5-3) (K_safe_p6-3))
        :effect (and (not (K_at_p5-3)) (not (K_not_at_p6-3)) (K_at_p6-3) (K_not_at_p5-3)))
    (:action move_p5-3_p5-4
        :precondition (and (K_normal-execution) (K_at_p5-3) (K_safe_p5-4))
        :effect (and (not (K_at_p5-3)) (not (K_not_at_p5-4)) (K_at_p5-4) (K_not_at_p5-3)))
    (:action move_p5-3_p5-2
        :precondition (and (K_normal-execution) (K_at_p5-3) (K_safe_p5-2))
        :effect (and (not (K_not_at_p5-2)) (not (K_at_p5-3)) (K_not_at_p5-3) (K_at_p5-2)))
    (:action move_p5-3_p4-3
        :precondition (and (K_normal-execution) (K_at_p5-3) (K_safe_p4-3))
        :effect (and (not (K_not_at_p4-3)) (not (K_at_p5-3)) (K_not_at_p5-3) (K_at_p4-3)))
    (:action move_p5-2_p6-2
        :precondition (and (K_normal-execution) (K_at_p5-2) (K_safe_p6-2))
        :effect (and (not (K_at_p5-2)) (not (K_not_at_p6-2)) (K_at_p6-2) (K_not_at_p5-2)))
    (:action move_p5-2_p5-3
        :precondition (and (K_normal-execution) (K_at_p5-2) (K_safe_p5-3))
        :effect (and (not (K_at_p5-2)) (not (K_not_at_p5-3)) (K_at_p5-3) (K_not_at_p5-2)))
    (:action move_p5-2_p5-1
        :precondition (and (K_normal-execution) (K_at_p5-2) (K_safe_p5-1))
        :effect (and (not (K_not_at_p5-1)) (not (K_at_p5-2)) (K_not_at_p5-2) (K_at_p5-1)))
    (:action move_p5-2_p4-2
        :precondition (and (K_normal-execution) (K_at_p5-2) (K_safe_p4-2))
        :effect (and (not (K_not_at_p4-2)) (not (K_at_p5-2)) (K_not_at_p5-2) (K_at_p4-2)))
    (:action move_p5-1_p6-1
        :precondition (and (K_normal-execution) (K_at_p5-1) (K_safe_p6-1))
        :effect (and (not (K_at_p5-1)) (not (K_not_at_p6-1)) (K_at_p6-1) (K_not_at_p5-1)))
    (:action move_p5-1_p5-2
        :precondition (and (K_normal-execution) (K_at_p5-1) (K_safe_p5-2))
        :effect (and (not (K_at_p5-1)) (not (K_not_at_p5-2)) (K_at_p5-2) (K_not_at_p5-1)))
    (:action move_p5-1_p4-1
        :precondition (and (K_normal-execution) (K_at_p5-1) (K_safe_p4-1))
        :effect (and (not (K_not_at_p4-1)) (not (K_at_p5-1)) (K_not_at_p5-1) (K_at_p4-1)))
    (:action move_p4-7_p5-7
        :precondition (and (K_normal-execution) (K_at_p4-7) (K_safe_p5-7))
        :effect (and (not (K_at_p4-7)) (not (K_not_at_p5-7)) (K_at_p5-7) (K_not_at_p4-7)))
    (:action move_p4-7_p4-6
        :precondition (and (K_normal-execution) (K_at_p4-7) (K_safe_p4-6))
        :effect (and (not (K_not_at_p4-6)) (not (K_at_p4-7)) (K_not_at_p4-7) (K_at_p4-6)))
    (:action move_p4-7_p3-7
        :precondition (and (K_normal-execution) (K_at_p4-7) (K_safe_p3-7))
        :effect (and (not (K_not_at_p3-7)) (not (K_at_p4-7)) (K_not_at_p4-7) (K_at_p3-7)))
    (:action move_p4-6_p5-6
        :precondition (and (K_normal-execution) (K_at_p4-6) (K_safe_p5-6))
        :effect (and (not (K_at_p4-6)) (not (K_not_at_p5-6)) (K_at_p5-6) (K_not_at_p4-6)))
    (:action move_p4-6_p4-7
        :precondition (and (K_normal-execution) (K_at_p4-6) (K_safe_p4-7))
        :effect (and (not (K_at_p4-6)) (not (K_not_at_p4-7)) (K_at_p4-7) (K_not_at_p4-6)))
    (:action move_p4-6_p4-5
        :precondition (and (K_normal-execution) (K_at_p4-6) (K_safe_p4-5))
        :effect (and (not (K_not_at_p4-5)) (not (K_at_p4-6)) (K_not_at_p4-6) (K_at_p4-5)))
    (:action move_p4-6_p3-6
        :precondition (and (K_normal-execution) (K_at_p4-6) (K_safe_p3-6))
        :effect (and (not (K_not_at_p3-6)) (not (K_at_p4-6)) (K_not_at_p4-6) (K_at_p3-6)))
    (:action move_p4-5_p5-5
        :precondition (and (K_normal-execution) (K_at_p4-5) (K_safe_p5-5))
        :effect (and (not (K_at_p4-5)) (not (K_not_at_p5-5)) (K_at_p5-5) (K_not_at_p4-5)))
    (:action move_p4-5_p4-6
        :precondition (and (K_normal-execution) (K_at_p4-5) (K_safe_p4-6))
        :effect (and (not (K_at_p4-5)) (not (K_not_at_p4-6)) (K_at_p4-6) (K_not_at_p4-5)))
    (:action move_p4-5_p4-4
        :precondition (and (K_normal-execution) (K_at_p4-5) (K_safe_p4-4))
        :effect (and (not (K_not_at_p4-4)) (not (K_at_p4-5)) (K_not_at_p4-5) (K_at_p4-4)))
    (:action move_p4-5_p3-5
        :precondition (and (K_normal-execution) (K_at_p4-5) (K_safe_p3-5))
        :effect (and (not (K_not_at_p3-5)) (not (K_at_p4-5)) (K_not_at_p4-5) (K_at_p3-5)))
    (:action move_p4-4_p5-4
        :precondition (and (K_normal-execution) (K_at_p4-4) (K_safe_p5-4))
        :effect (and (not (K_at_p4-4)) (not (K_not_at_p5-4)) (K_at_p5-4) (K_not_at_p4-4)))
    (:action move_p4-4_p4-5
        :precondition (and (K_normal-execution) (K_at_p4-4) (K_safe_p4-5))
        :effect (and (not (K_at_p4-4)) (not (K_not_at_p4-5)) (K_at_p4-5) (K_not_at_p4-4)))
    (:action move_p4-4_p4-3
        :precondition (and (K_normal-execution) (K_at_p4-4) (K_safe_p4-3))
        :effect (and (not (K_not_at_p4-3)) (not (K_at_p4-4)) (K_not_at_p4-4) (K_at_p4-3)))
    (:action move_p4-4_p3-4
        :precondition (and (K_normal-execution) (K_at_p4-4) (K_safe_p3-4))
        :effect (and (not (K_not_at_p3-4)) (not (K_at_p4-4)) (K_not_at_p4-4) (K_at_p3-4)))
    (:action move_p4-3_p5-3
        :precondition (and (K_normal-execution) (K_at_p4-3) (K_safe_p5-3))
        :effect (and (not (K_at_p4-3)) (not (K_not_at_p5-3)) (K_at_p5-3) (K_not_at_p4-3)))
    (:action move_p4-3_p4-4
        :precondition (and (K_normal-execution) (K_at_p4-3) (K_safe_p4-4))
        :effect (and (not (K_at_p4-3)) (not (K_not_at_p4-4)) (K_at_p4-4) (K_not_at_p4-3)))
    (:action move_p4-3_p4-2
        :precondition (and (K_normal-execution) (K_at_p4-3) (K_safe_p4-2))
        :effect (and (not (K_not_at_p4-2)) (not (K_at_p4-3)) (K_not_at_p4-3) (K_at_p4-2)))
    (:action move_p4-3_p3-3
        :precondition (and (K_normal-execution) (K_at_p4-3) (K_safe_p3-3))
        :effect (and (not (K_not_at_p3-3)) (not (K_at_p4-3)) (K_not_at_p4-3) (K_at_p3-3)))
    (:action move_p4-2_p5-2
        :precondition (and (K_normal-execution) (K_at_p4-2) (K_safe_p5-2))
        :effect (and (not (K_at_p4-2)) (not (K_not_at_p5-2)) (K_at_p5-2) (K_not_at_p4-2)))
    (:action move_p4-2_p4-3
        :precondition (and (K_normal-execution) (K_at_p4-2) (K_safe_p4-3))
        :effect (and (not (K_at_p4-2)) (not (K_not_at_p4-3)) (K_at_p4-3) (K_not_at_p4-2)))
    (:action move_p4-2_p4-1
        :precondition (and (K_normal-execution) (K_at_p4-2) (K_safe_p4-1))
        :effect (and (not (K_not_at_p4-1)) (not (K_at_p4-2)) (K_not_at_p4-2) (K_at_p4-1)))
    (:action move_p4-2_p3-2
        :precondition (and (K_normal-execution) (K_at_p4-2) (K_safe_p3-2))
        :effect (and (not (K_not_at_p3-2)) (not (K_at_p4-2)) (K_not_at_p4-2) (K_at_p3-2)))
    (:action move_p4-1_p5-1
        :precondition (and (K_normal-execution) (K_at_p4-1) (K_safe_p5-1))
        :effect (and (not (K_at_p4-1)) (not (K_not_at_p5-1)) (K_at_p5-1) (K_not_at_p4-1)))
    (:action move_p4-1_p4-2
        :precondition (and (K_normal-execution) (K_at_p4-1) (K_safe_p4-2))
        :effect (and (not (K_at_p4-1)) (not (K_not_at_p4-2)) (K_at_p4-2) (K_not_at_p4-1)))
    (:action move_p4-1_p3-1
        :precondition (and (K_normal-execution) (K_at_p4-1) (K_safe_p3-1))
        :effect (and (not (K_not_at_p3-1)) (not (K_at_p4-1)) (K_not_at_p4-1) (K_at_p3-1)))
    (:action move_p3-7_p4-7
        :precondition (and (K_normal-execution) (K_at_p3-7) (K_safe_p4-7))
        :effect (and (not (K_at_p3-7)) (not (K_not_at_p4-7)) (K_at_p4-7) (K_not_at_p3-7)))
    (:action move_p3-7_p3-6
        :precondition (and (K_normal-execution) (K_at_p3-7) (K_safe_p3-6))
        :effect (and (not (K_not_at_p3-6)) (not (K_at_p3-7)) (K_not_at_p3-7) (K_at_p3-6)))
    (:action move_p3-7_p2-7
        :precondition (and (K_normal-execution) (K_at_p3-7) (K_safe_p2-7))
        :effect (and (not (K_not_at_p2-7)) (not (K_at_p3-7)) (K_not_at_p3-7) (K_at_p2-7)))
    (:action move_p3-6_p4-6
        :precondition (and (K_normal-execution) (K_at_p3-6) (K_safe_p4-6))
        :effect (and (not (K_at_p3-6)) (not (K_not_at_p4-6)) (K_at_p4-6) (K_not_at_p3-6)))
    (:action move_p3-6_p3-7
        :precondition (and (K_normal-execution) (K_at_p3-6) (K_safe_p3-7))
        :effect (and (not (K_at_p3-6)) (not (K_not_at_p3-7)) (K_at_p3-7) (K_not_at_p3-6)))
    (:action move_p3-6_p3-5
        :precondition (and (K_normal-execution) (K_at_p3-6) (K_safe_p3-5))
        :effect (and (not (K_not_at_p3-5)) (not (K_at_p3-6)) (K_not_at_p3-6) (K_at_p3-5)))
    (:action move_p3-6_p2-6
        :precondition (and (K_normal-execution) (K_at_p3-6) (K_safe_p2-6))
        :effect (and (not (K_not_at_p2-6)) (not (K_at_p3-6)) (K_not_at_p3-6) (K_at_p2-6)))
    (:action move_p3-5_p4-5
        :precondition (and (K_normal-execution) (K_at_p3-5) (K_safe_p4-5))
        :effect (and (not (K_at_p3-5)) (not (K_not_at_p4-5)) (K_at_p4-5) (K_not_at_p3-5)))
    (:action move_p3-5_p3-6
        :precondition (and (K_normal-execution) (K_at_p3-5) (K_safe_p3-6))
        :effect (and (not (K_at_p3-5)) (not (K_not_at_p3-6)) (K_at_p3-6) (K_not_at_p3-5)))
    (:action move_p3-5_p3-4
        :precondition (and (K_normal-execution) (K_at_p3-5) (K_safe_p3-4))
        :effect (and (not (K_not_at_p3-4)) (not (K_at_p3-5)) (K_not_at_p3-5) (K_at_p3-4)))
    (:action move_p3-5_p2-5
        :precondition (and (K_normal-execution) (K_at_p3-5) (K_safe_p2-5))
        :effect (and (not (K_not_at_p2-5)) (not (K_at_p3-5)) (K_not_at_p3-5) (K_at_p2-5)))
    (:action move_p3-4_p4-4
        :precondition (and (K_normal-execution) (K_at_p3-4) (K_safe_p4-4))
        :effect (and (not (K_at_p3-4)) (not (K_not_at_p4-4)) (K_at_p4-4) (K_not_at_p3-4)))
    (:action move_p3-4_p3-5
        :precondition (and (K_normal-execution) (K_at_p3-4) (K_safe_p3-5))
        :effect (and (not (K_at_p3-4)) (not (K_not_at_p3-5)) (K_at_p3-5) (K_not_at_p3-4)))
    (:action move_p3-4_p3-3
        :precondition (and (K_normal-execution) (K_at_p3-4) (K_safe_p3-3))
        :effect (and (not (K_not_at_p3-3)) (not (K_at_p3-4)) (K_not_at_p3-4) (K_at_p3-3)))
    (:action move_p3-4_p2-4
        :precondition (and (K_normal-execution) (K_at_p3-4) (K_safe_p2-4))
        :effect (and (not (K_not_at_p2-4)) (not (K_at_p3-4)) (K_not_at_p3-4) (K_at_p2-4)))
    (:action move_p3-3_p4-3
        :precondition (and (K_normal-execution) (K_at_p3-3) (K_safe_p4-3))
        :effect (and (not (K_at_p3-3)) (not (K_not_at_p4-3)) (K_at_p4-3) (K_not_at_p3-3)))
    (:action move_p3-3_p3-4
        :precondition (and (K_normal-execution) (K_at_p3-3) (K_safe_p3-4))
        :effect (and (not (K_at_p3-3)) (not (K_not_at_p3-4)) (K_at_p3-4) (K_not_at_p3-3)))
    (:action move_p3-3_p3-2
        :precondition (and (K_normal-execution) (K_at_p3-3) (K_safe_p3-2))
        :effect (and (not (K_not_at_p3-2)) (not (K_at_p3-3)) (K_not_at_p3-3) (K_at_p3-2)))
    (:action move_p3-3_p2-3
        :precondition (and (K_normal-execution) (K_at_p3-3) (K_safe_p2-3))
        :effect (and (not (K_not_at_p2-3)) (not (K_at_p3-3)) (K_not_at_p3-3) (K_at_p2-3)))
    (:action move_p3-2_p4-2
        :precondition (and (K_normal-execution) (K_at_p3-2) (K_safe_p4-2))
        :effect (and (not (K_at_p3-2)) (not (K_not_at_p4-2)) (K_at_p4-2) (K_not_at_p3-2)))
    (:action move_p3-2_p3-3
        :precondition (and (K_normal-execution) (K_at_p3-2) (K_safe_p3-3))
        :effect (and (not (K_at_p3-2)) (not (K_not_at_p3-3)) (K_at_p3-3) (K_not_at_p3-2)))
    (:action move_p3-2_p3-1
        :precondition (and (K_normal-execution) (K_at_p3-2) (K_safe_p3-1))
        :effect (and (not (K_not_at_p3-1)) (not (K_at_p3-2)) (K_not_at_p3-2) (K_at_p3-1)))
    (:action move_p3-2_p2-2
        :precondition (and (K_normal-execution) (K_at_p3-2) (K_safe_p2-2))
        :effect (and (not (K_not_at_p2-2)) (not (K_at_p3-2)) (K_not_at_p3-2) (K_at_p2-2)))
    (:action move_p3-1_p4-1
        :precondition (and (K_normal-execution) (K_at_p3-1) (K_safe_p4-1))
        :effect (and (not (K_at_p3-1)) (not (K_not_at_p4-1)) (K_at_p4-1) (K_not_at_p3-1)))
    (:action move_p3-1_p3-2
        :precondition (and (K_normal-execution) (K_at_p3-1) (K_safe_p3-2))
        :effect (and (not (K_at_p3-1)) (not (K_not_at_p3-2)) (K_at_p3-2) (K_not_at_p3-1)))
    (:action move_p3-1_p2-1
        :precondition (and (K_normal-execution) (K_at_p3-1) (K_safe_p2-1))
        :effect (and (not (K_not_at_p2-1)) (not (K_at_p3-1)) (K_not_at_p3-1) (K_at_p2-1)))
    (:action move_p2-7_p3-7
        :precondition (and (K_normal-execution) (K_at_p2-7) (K_safe_p3-7))
        :effect (and (not (K_at_p2-7)) (not (K_not_at_p3-7)) (K_at_p3-7) (K_not_at_p2-7)))
    (:action move_p2-7_p2-6
        :precondition (and (K_normal-execution) (K_at_p2-7) (K_safe_p2-6))
        :effect (and (not (K_not_at_p2-6)) (not (K_at_p2-7)) (K_not_at_p2-7) (K_at_p2-6)))
    (:action move_p2-7_p1-7
        :precondition (and (K_normal-execution) (K_at_p2-7) (K_safe_p1-7))
        :effect (and (not (K_not_at_p1-7)) (not (K_at_p2-7)) (K_not_at_p2-7) (K_at_p1-7)))
    (:action move_p2-6_p3-6
        :precondition (and (K_normal-execution) (K_at_p2-6) (K_safe_p3-6))
        :effect (and (not (K_at_p2-6)) (not (K_not_at_p3-6)) (K_at_p3-6) (K_not_at_p2-6)))
    (:action move_p2-6_p2-7
        :precondition (and (K_normal-execution) (K_at_p2-6) (K_safe_p2-7))
        :effect (and (not (K_at_p2-6)) (not (K_not_at_p2-7)) (K_at_p2-7) (K_not_at_p2-6)))
    (:action move_p2-6_p2-5
        :precondition (and (K_normal-execution) (K_at_p2-6) (K_safe_p2-5))
        :effect (and (not (K_not_at_p2-5)) (not (K_at_p2-6)) (K_not_at_p2-6) (K_at_p2-5)))
    (:action move_p2-6_p1-6
        :precondition (and (K_normal-execution) (K_at_p2-6) (K_safe_p1-6))
        :effect (and (not (K_not_at_p1-6)) (not (K_at_p2-6)) (K_not_at_p2-6) (K_at_p1-6)))
    (:action move_p2-5_p3-5
        :precondition (and (K_normal-execution) (K_at_p2-5) (K_safe_p3-5))
        :effect (and (not (K_at_p2-5)) (not (K_not_at_p3-5)) (K_at_p3-5) (K_not_at_p2-5)))
    (:action move_p2-5_p2-6
        :precondition (and (K_normal-execution) (K_at_p2-5) (K_safe_p2-6))
        :effect (and (not (K_at_p2-5)) (not (K_not_at_p2-6)) (K_at_p2-6) (K_not_at_p2-5)))
    (:action move_p2-5_p2-4
        :precondition (and (K_normal-execution) (K_at_p2-5) (K_safe_p2-4))
        :effect (and (not (K_not_at_p2-4)) (not (K_at_p2-5)) (K_not_at_p2-5) (K_at_p2-4)))
    (:action move_p2-5_p1-5
        :precondition (and (K_normal-execution) (K_at_p2-5) (K_safe_p1-5))
        :effect (and (not (K_not_at_p1-5)) (not (K_at_p2-5)) (K_not_at_p2-5) (K_at_p1-5)))
    (:action move_p2-4_p3-4
        :precondition (and (K_normal-execution) (K_at_p2-4) (K_safe_p3-4))
        :effect (and (not (K_at_p2-4)) (not (K_not_at_p3-4)) (K_at_p3-4) (K_not_at_p2-4)))
    (:action move_p2-4_p2-5
        :precondition (and (K_normal-execution) (K_at_p2-4) (K_safe_p2-5))
        :effect (and (not (K_at_p2-4)) (not (K_not_at_p2-5)) (K_at_p2-5) (K_not_at_p2-4)))
    (:action move_p2-4_p2-3
        :precondition (and (K_normal-execution) (K_at_p2-4) (K_safe_p2-3))
        :effect (and (not (K_not_at_p2-3)) (not (K_at_p2-4)) (K_not_at_p2-4) (K_at_p2-3)))
    (:action move_p2-4_p1-4
        :precondition (and (K_normal-execution) (K_at_p2-4) (K_safe_p1-4))
        :effect (and (not (K_not_at_p1-4)) (not (K_at_p2-4)) (K_not_at_p2-4) (K_at_p1-4)))
    (:action move_p2-3_p3-3
        :precondition (and (K_normal-execution) (K_at_p2-3) (K_safe_p3-3))
        :effect (and (not (K_at_p2-3)) (not (K_not_at_p3-3)) (K_at_p3-3) (K_not_at_p2-3)))
    (:action move_p2-3_p2-4
        :precondition (and (K_normal-execution) (K_at_p2-3) (K_safe_p2-4))
        :effect (and (not (K_at_p2-3)) (not (K_not_at_p2-4)) (K_at_p2-4) (K_not_at_p2-3)))
    (:action move_p2-3_p2-2
        :precondition (and (K_normal-execution) (K_at_p2-3) (K_safe_p2-2))
        :effect (and (not (K_not_at_p2-2)) (not (K_at_p2-3)) (K_not_at_p2-3) (K_at_p2-2)))
    (:action move_p2-3_p1-3
        :precondition (and (K_normal-execution) (K_at_p2-3) (K_safe_p1-3))
        :effect (and (not (K_not_at_p1-3)) (not (K_at_p2-3)) (K_not_at_p2-3) (K_at_p1-3)))
    (:action move_p2-2_p3-2
        :precondition (and (K_normal-execution) (K_at_p2-2) (K_safe_p3-2))
        :effect (and (not (K_at_p2-2)) (not (K_not_at_p3-2)) (K_at_p3-2) (K_not_at_p2-2)))
    (:action move_p2-2_p2-3
        :precondition (and (K_normal-execution) (K_at_p2-2) (K_safe_p2-3))
        :effect (and (not (K_at_p2-2)) (not (K_not_at_p2-3)) (K_at_p2-3) (K_not_at_p2-2)))
    (:action move_p2-2_p2-1
        :precondition (and (K_normal-execution) (K_at_p2-2) (K_safe_p2-1))
        :effect (and (not (K_not_at_p2-1)) (not (K_at_p2-2)) (K_not_at_p2-2) (K_at_p2-1)))
    (:action move_p2-2_p1-2
        :precondition (and (K_normal-execution) (K_at_p2-2) (K_safe_p1-2))
        :effect (and (not (K_not_at_p1-2)) (not (K_at_p2-2)) (K_not_at_p2-2) (K_at_p1-2)))
    (:action move_p2-1_p3-1
        :precondition (and (K_normal-execution) (K_at_p2-1) (K_safe_p3-1))
        :effect (and (not (K_at_p2-1)) (not (K_not_at_p3-1)) (K_at_p3-1) (K_not_at_p2-1)))
    (:action move_p2-1_p2-2
        :precondition (and (K_normal-execution) (K_at_p2-1) (K_safe_p2-2))
        :effect (and (not (K_at_p2-1)) (not (K_not_at_p2-2)) (K_at_p2-2) (K_not_at_p2-1)))
    (:action move_p2-1_p1-1
        :precondition (and (K_normal-execution) (K_at_p2-1) (K_safe_p1-1))
        :effect (and (not (K_at_p2-1)) (not (K_not_at_p1-1)) (K_at_p1-1) (K_not_at_p2-1)))
    (:action move_p1-7_p2-7
        :precondition (and (K_normal-execution) (K_at_p1-7) (K_safe_p2-7))
        :effect (and (not (K_at_p1-7)) (not (K_not_at_p2-7)) (K_at_p2-7) (K_not_at_p1-7)))
    (:action move_p1-7_p1-6
        :precondition (and (K_normal-execution) (K_at_p1-7) (K_safe_p1-6))
        :effect (and (not (K_not_at_p1-6)) (not (K_at_p1-7)) (K_not_at_p1-7) (K_at_p1-6)))
    (:action move_p1-6_p2-6
        :precondition (and (K_normal-execution) (K_at_p1-6) (K_safe_p2-6))
        :effect (and (not (K_at_p1-6)) (not (K_not_at_p2-6)) (K_at_p2-6) (K_not_at_p1-6)))
    (:action move_p1-6_p1-7
        :precondition (and (K_normal-execution) (K_at_p1-6) (K_safe_p1-7))
        :effect (and (not (K_at_p1-6)) (not (K_not_at_p1-7)) (K_at_p1-7) (K_not_at_p1-6)))
    (:action move_p1-6_p1-5
        :precondition (and (K_normal-execution) (K_at_p1-6) (K_safe_p1-5))
        :effect (and (not (K_not_at_p1-5)) (not (K_at_p1-6)) (K_not_at_p1-6) (K_at_p1-5)))
    (:action move_p1-5_p2-5
        :precondition (and (K_normal-execution) (K_at_p1-5) (K_safe_p2-5))
        :effect (and (not (K_at_p1-5)) (not (K_not_at_p2-5)) (K_at_p2-5) (K_not_at_p1-5)))
    (:action move_p1-5_p1-6
        :precondition (and (K_normal-execution) (K_at_p1-5) (K_safe_p1-6))
        :effect (and (not (K_at_p1-5)) (not (K_not_at_p1-6)) (K_at_p1-6) (K_not_at_p1-5)))
    (:action move_p1-5_p1-4
        :precondition (and (K_normal-execution) (K_at_p1-5) (K_safe_p1-4))
        :effect (and (not (K_not_at_p1-4)) (not (K_at_p1-5)) (K_not_at_p1-5) (K_at_p1-4)))
    (:action move_p1-4_p2-4
        :precondition (and (K_normal-execution) (K_at_p1-4) (K_safe_p2-4))
        :effect (and (not (K_at_p1-4)) (not (K_not_at_p2-4)) (K_at_p2-4) (K_not_at_p1-4)))
    (:action move_p1-4_p1-5
        :precondition (and (K_normal-execution) (K_at_p1-4) (K_safe_p1-5))
        :effect (and (not (K_at_p1-4)) (not (K_not_at_p1-5)) (K_at_p1-5) (K_not_at_p1-4)))
    (:action move_p1-4_p1-3
        :precondition (and (K_normal-execution) (K_at_p1-4) (K_safe_p1-3))
        :effect (and (not (K_not_at_p1-3)) (not (K_at_p1-4)) (K_not_at_p1-4) (K_at_p1-3)))
    (:action move_p1-3_p2-3
        :precondition (and (K_normal-execution) (K_at_p1-3) (K_safe_p2-3))
        :effect (and (not (K_at_p1-3)) (not (K_not_at_p2-3)) (K_at_p2-3) (K_not_at_p1-3)))
    (:action move_p1-3_p1-4
        :precondition (and (K_normal-execution) (K_at_p1-3) (K_safe_p1-4))
        :effect (and (not (K_at_p1-3)) (not (K_not_at_p1-4)) (K_at_p1-4) (K_not_at_p1-3)))
    (:action move_p1-3_p1-2
        :precondition (and (K_normal-execution) (K_at_p1-3) (K_safe_p1-2))
        :effect (and (not (K_not_at_p1-2)) (not (K_at_p1-3)) (K_not_at_p1-3) (K_at_p1-2)))
    (:action move_p1-2_p2-2
        :precondition (and (K_normal-execution) (K_at_p1-2) (K_safe_p2-2))
        :effect (and (not (K_at_p1-2)) (not (K_not_at_p2-2)) (K_at_p2-2) (K_not_at_p1-2)))
    (:action move_p1-2_p1-3
        :precondition (and (K_normal-execution) (K_at_p1-2) (K_safe_p1-3))
        :effect (and (not (K_at_p1-2)) (not (K_not_at_p1-3)) (K_at_p1-3) (K_not_at_p1-2)))
    (:action move_p1-2_p1-1
        :precondition (and (K_normal-execution) (K_at_p1-2) (K_safe_p1-1))
        :effect (and (not (K_at_p1-2)) (not (K_not_at_p1-1)) (K_at_p1-1) (K_not_at_p1-2)))
    (:action move_p1-1_p2-1
        :precondition (and (K_at_p1-1) (K_normal-execution) (K_safe_p2-1))
        :effect (and (not (K_not_at_p2-1)) (not (K_at_p1-1)) (K_not_at_p1-1) (K_at_p2-1)))
    (:action move_p1-1_p1-2
        :precondition (and (K_at_p1-1) (K_normal-execution) (K_safe_p1-2))
        :effect (and (not (K_not_at_p1-2)) (not (K_at_p1-1)) (K_not_at_p1-1) (K_at_p1-2)))
    (:action grab_p7-7
        :precondition (and (K_gold-at_p7-7) (K_normal-execution) (K_at_p7-7))
        :effect (and (not (K_not_got-the-treasure)) (not (K_gold-at_p7-7)) (K_not_gold-at_p7-7) (K_got-the-treasure)))
    (:action smell-wumpus_p7-7__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p7-7))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p7-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p7-7)))
    (:action smell-wumpus_p7-7__post__
        :precondition (K_need-post-for-smell-wumpus_p7-7)
        :effect (and (not (K_need-post-for-smell-wumpus_p7-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p7-7)))
    (:action smell-wumpus_p7-6__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p7-6))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p7-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p7-6)))
    (:action smell-wumpus_p7-6__post__
        :precondition (K_need-post-for-smell-wumpus_p7-6)
        :effect (and (not (K_need-post-for-smell-wumpus_p7-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p7-6)))
    (:action smell-wumpus_p7-5__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p7-5))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p7-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p7-5)))
    (:action smell-wumpus_p7-5__post__
        :precondition (K_need-post-for-smell-wumpus_p7-5)
        :effect (and (not (K_need-post-for-smell-wumpus_p7-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p7-5)))
    (:action smell-wumpus_p7-4__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p7-4))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p7-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p7-4)))
    (:action smell-wumpus_p7-4__post__
        :precondition (K_need-post-for-smell-wumpus_p7-4)
        :effect (and (not (K_need-post-for-smell-wumpus_p7-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p7-4)))
    (:action smell-wumpus_p7-3__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p7-3))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p7-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p7-3)))
    (:action smell-wumpus_p7-3__post__
        :precondition (K_need-post-for-smell-wumpus_p7-3)
        :effect (and (not (K_need-post-for-smell-wumpus_p7-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p7-3)))
    (:action smell-wumpus_p7-2__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p7-2))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p7-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p7-2)))
    (:action smell-wumpus_p7-2__post__
        :precondition (K_need-post-for-smell-wumpus_p7-2)
        :effect (and (not (K_need-post-for-smell-wumpus_p7-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p7-2)))
    (:action smell-wumpus_p7-1__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p7-1))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p7-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p7-1)))
    (:action smell-wumpus_p7-1__post__
        :precondition (K_need-post-for-smell-wumpus_p7-1)
        :effect (and (not (K_need-post-for-smell-wumpus_p7-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p7-1)))
    (:action smell-wumpus_p6-7__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p6-7))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p6-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p6-7)))
    (:action smell-wumpus_p6-7__post__
        :precondition (K_need-post-for-smell-wumpus_p6-7)
        :effect (and (not (K_need-post-for-smell-wumpus_p6-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p6-7)))
    (:action smell-wumpus_p6-6__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p6-6))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p6-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p6-6)))
    (:action smell-wumpus_p6-6__post__
        :precondition (K_need-post-for-smell-wumpus_p6-6)
        :effect (and (not (K_need-post-for-smell-wumpus_p6-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p6-6)))
    (:action smell-wumpus_p6-5__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p6-5))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p6-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p6-5)))
    (:action smell-wumpus_p6-5__post__
        :precondition (K_need-post-for-smell-wumpus_p6-5)
        :effect (and (not (K_need-post-for-smell-wumpus_p6-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p6-5)))
    (:action smell-wumpus_p6-4__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p6-4))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p6-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p6-4)))
    (:action smell-wumpus_p6-4__post__
        :precondition (K_need-post-for-smell-wumpus_p6-4)
        :effect (and (not (K_need-post-for-smell-wumpus_p6-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p6-4)))
    (:action smell-wumpus_p6-3__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p6-3))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p6-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p6-3)))
    (:action smell-wumpus_p6-3__post__
        :precondition (K_need-post-for-smell-wumpus_p6-3)
        :effect (and (not (K_need-post-for-smell-wumpus_p6-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p6-3)))
    (:action smell-wumpus_p6-2__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p6-2))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p6-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p6-2)))
    (:action smell-wumpus_p6-2__post__
        :precondition (K_need-post-for-smell-wumpus_p6-2)
        :effect (and (not (K_need-post-for-smell-wumpus_p6-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p6-2)))
    (:action smell-wumpus_p6-1__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p6-1))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p6-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p6-1)))
    (:action smell-wumpus_p6-1__post__
        :precondition (K_need-post-for-smell-wumpus_p6-1)
        :effect (and (not (K_need-post-for-smell-wumpus_p6-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p6-1)))
    (:action smell-wumpus_p5-7__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p5-7))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p5-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p5-7)))
    (:action smell-wumpus_p5-7__post__
        :precondition (K_need-post-for-smell-wumpus_p5-7)
        :effect (and (not (K_need-post-for-smell-wumpus_p5-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p5-7)))
    (:action smell-wumpus_p5-6__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p5-6))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p5-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p5-6)))
    (:action smell-wumpus_p5-6__post__
        :precondition (K_need-post-for-smell-wumpus_p5-6)
        :effect (and (not (K_need-post-for-smell-wumpus_p5-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p5-6)))
    (:action smell-wumpus_p5-5__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p5-5))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p5-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p5-5)))
    (:action smell-wumpus_p5-5__post__
        :precondition (K_need-post-for-smell-wumpus_p5-5)
        :effect (and (not (K_need-post-for-smell-wumpus_p5-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p5-5)))
    (:action smell-wumpus_p5-4__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p5-4))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p5-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p5-4)))
    (:action smell-wumpus_p5-4__post__
        :precondition (K_need-post-for-smell-wumpus_p5-4)
        :effect (and (not (K_need-post-for-smell-wumpus_p5-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p5-4)))
    (:action smell-wumpus_p5-3__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p5-3))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p5-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p5-3)))
    (:action smell-wumpus_p5-3__post__
        :precondition (K_need-post-for-smell-wumpus_p5-3)
        :effect (and (not (K_need-post-for-smell-wumpus_p5-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p5-3)))
    (:action smell-wumpus_p5-2__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p5-2))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p5-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p5-2)))
    (:action smell-wumpus_p5-2__post__
        :precondition (K_need-post-for-smell-wumpus_p5-2)
        :effect (and (not (K_need-post-for-smell-wumpus_p5-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p5-2)))
    (:action smell-wumpus_p5-1__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p5-1))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p5-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p5-1)))
    (:action smell-wumpus_p5-1__post__
        :precondition (K_need-post-for-smell-wumpus_p5-1)
        :effect (and (not (K_need-post-for-smell-wumpus_p5-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p5-1)))
    (:action smell-wumpus_p4-7__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p4-7))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p4-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p4-7)))
    (:action smell-wumpus_p4-7__post__
        :precondition (K_need-post-for-smell-wumpus_p4-7)
        :effect (and (not (K_need-post-for-smell-wumpus_p4-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p4-7)))
    (:action smell-wumpus_p4-6__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p4-6))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p4-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p4-6)))
    (:action smell-wumpus_p4-6__post__
        :precondition (K_need-post-for-smell-wumpus_p4-6)
        :effect (and (not (K_need-post-for-smell-wumpus_p4-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p4-6)))
    (:action smell-wumpus_p4-5__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p4-5))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p4-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p4-5)))
    (:action smell-wumpus_p4-5__post__
        :precondition (K_need-post-for-smell-wumpus_p4-5)
        :effect (and (not (K_need-post-for-smell-wumpus_p4-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p4-5)))
    (:action smell-wumpus_p4-4__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p4-4))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p4-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p4-4)))
    (:action smell-wumpus_p4-4__post__
        :precondition (K_need-post-for-smell-wumpus_p4-4)
        :effect (and (not (K_need-post-for-smell-wumpus_p4-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p4-4)))
    (:action smell-wumpus_p4-3__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p4-3))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p4-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p4-3)))
    (:action smell-wumpus_p4-3__post__
        :precondition (K_need-post-for-smell-wumpus_p4-3)
        :effect (and (not (K_need-post-for-smell-wumpus_p4-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p4-3)))
    (:action smell-wumpus_p4-2__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p4-2))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p4-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p4-2)))
    (:action smell-wumpus_p4-2__post__
        :precondition (K_need-post-for-smell-wumpus_p4-2)
        :effect (and (not (K_need-post-for-smell-wumpus_p4-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p4-2)))
    (:action smell-wumpus_p4-1__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p4-1))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p4-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p4-1)))
    (:action smell-wumpus_p4-1__post__
        :precondition (K_need-post-for-smell-wumpus_p4-1)
        :effect (and (not (K_need-post-for-smell-wumpus_p4-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p4-1)))
    (:action smell-wumpus_p3-7__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p3-7))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p3-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p3-7)))
    (:action smell-wumpus_p3-7__post__
        :precondition (K_need-post-for-smell-wumpus_p3-7)
        :effect (and (not (K_need-post-for-smell-wumpus_p3-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p3-7)))
    (:action smell-wumpus_p3-6__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p3-6))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p3-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p3-6)))
    (:action smell-wumpus_p3-6__post__
        :precondition (K_need-post-for-smell-wumpus_p3-6)
        :effect (and (not (K_need-post-for-smell-wumpus_p3-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p3-6)))
    (:action smell-wumpus_p3-5__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p3-5))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p3-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p3-5)))
    (:action smell-wumpus_p3-5__post__
        :precondition (K_need-post-for-smell-wumpus_p3-5)
        :effect (and (not (K_need-post-for-smell-wumpus_p3-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p3-5)))
    (:action smell-wumpus_p3-4__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p3-4))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p3-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p3-4)))
    (:action smell-wumpus_p3-4__post__
        :precondition (K_need-post-for-smell-wumpus_p3-4)
        :effect (and (not (K_need-post-for-smell-wumpus_p3-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p3-4)))
    (:action smell-wumpus_p3-3__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p3-3))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p3-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p3-3)))
    (:action smell-wumpus_p3-3__post__
        :precondition (K_need-post-for-smell-wumpus_p3-3)
        :effect (and (not (K_need-post-for-smell-wumpus_p3-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p3-3)))
    (:action smell-wumpus_p3-2__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p3-2))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p3-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p3-2)))
    (:action smell-wumpus_p3-2__post__
        :precondition (K_need-post-for-smell-wumpus_p3-2)
        :effect (and (not (K_need-post-for-smell-wumpus_p3-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p3-2)))
    (:action smell-wumpus_p3-1__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p3-1))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p3-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p3-1)))
    (:action smell-wumpus_p3-1__post__
        :precondition (K_need-post-for-smell-wumpus_p3-1)
        :effect (and (not (K_need-post-for-smell-wumpus_p3-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p3-1)))
    (:action smell-wumpus_p2-7__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p2-7))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p2-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p2-7)))
    (:action smell-wumpus_p2-7__post__
        :precondition (K_need-post-for-smell-wumpus_p2-7)
        :effect (and (not (K_need-post-for-smell-wumpus_p2-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p2-7)))
    (:action smell-wumpus_p2-6__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p2-6))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p2-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p2-6)))
    (:action smell-wumpus_p2-6__post__
        :precondition (K_need-post-for-smell-wumpus_p2-6)
        :effect (and (not (K_need-post-for-smell-wumpus_p2-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p2-6)))
    (:action smell-wumpus_p2-5__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p2-5))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p2-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p2-5)))
    (:action smell-wumpus_p2-5__post__
        :precondition (K_need-post-for-smell-wumpus_p2-5)
        :effect (and (not (K_need-post-for-smell-wumpus_p2-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p2-5)))
    (:action smell-wumpus_p2-4__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p2-4))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p2-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p2-4)))
    (:action smell-wumpus_p2-4__post__
        :precondition (K_need-post-for-smell-wumpus_p2-4)
        :effect (and (not (K_need-post-for-smell-wumpus_p2-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p2-4)))
    (:action smell-wumpus_p2-3__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p2-3))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p2-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p2-3)))
    (:action smell-wumpus_p2-3__post__
        :precondition (K_need-post-for-smell-wumpus_p2-3)
        :effect (and (not (K_need-post-for-smell-wumpus_p2-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p2-3)))
    (:action smell-wumpus_p2-2__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p2-2))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p2-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p2-2)))
    (:action smell-wumpus_p2-2__post__
        :precondition (K_need-post-for-smell-wumpus_p2-2)
        :effect (and (not (K_need-post-for-smell-wumpus_p2-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p2-2)))
    (:action smell-wumpus_p2-1__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p2-1))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p2-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p2-1)))
    (:action smell-wumpus_p2-1__post__
        :precondition (K_need-post-for-smell-wumpus_p2-1)
        :effect (and (not (K_need-post-for-smell-wumpus_p2-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p2-1)))
    (:action smell-wumpus_p1-7__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p1-7))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p1-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p1-7)))
    (:action smell-wumpus_p1-7__post__
        :precondition (K_need-post-for-smell-wumpus_p1-7)
        :effect (and (not (K_need-post-for-smell-wumpus_p1-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p1-7)))
    (:action smell-wumpus_p1-6__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p1-6))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p1-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p1-6)))
    (:action smell-wumpus_p1-6__post__
        :precondition (K_need-post-for-smell-wumpus_p1-6)
        :effect (and (not (K_need-post-for-smell-wumpus_p1-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p1-6)))
    (:action smell-wumpus_p1-5__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p1-5))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p1-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p1-5)))
    (:action smell-wumpus_p1-5__post__
        :precondition (K_need-post-for-smell-wumpus_p1-5)
        :effect (and (not (K_need-post-for-smell-wumpus_p1-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p1-5)))
    (:action smell-wumpus_p1-4__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p1-4))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p1-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p1-4)))
    (:action smell-wumpus_p1-4__post__
        :precondition (K_need-post-for-smell-wumpus_p1-4)
        :effect (and (not (K_need-post-for-smell-wumpus_p1-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p1-4)))
    (:action smell-wumpus_p1-3__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p1-3))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p1-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p1-3)))
    (:action smell-wumpus_p1-3__post__
        :precondition (K_need-post-for-smell-wumpus_p1-3)
        :effect (and (not (K_need-post-for-smell-wumpus_p1-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p1-3)))
    (:action smell-wumpus_p1-2__turn_on_sensor__
        :precondition (and (K_normal-execution) (K_at_p1-2))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p1-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p1-2)))
    (:action smell-wumpus_p1-2__post__
        :precondition (K_need-post-for-smell-wumpus_p1-2)
        :effect (and (not (K_need-post-for-smell-wumpus_p1-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p1-2)))
    (:action smell-wumpus_p1-1__turn_on_sensor__
        :precondition (and (K_at_p1-1) (K_normal-execution))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p1-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p1-1)))
    (:action smell-wumpus_p1-1__post__
        :precondition (K_need-post-for-smell-wumpus_p1-1)
        :effect (and (not (K_need-post-for-smell-wumpus_p1-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p1-1)))
    (:action sensor-smell-wumpus_p7-7__sensor__-obs0-ver0
        :effect (when (and (not (K_not_stench_p7-7)) (not (K_stench_p7-7)) (K_need-post-for-smell-wumpus_p7-7)) (K_stench_p7-7)))
    (:action sensor-smell-wumpus_p7-7__sensor__-obs0-ver1
        :effect (when (and (not (K_not_stench_p7-7)) (not (K_stench_p7-7)) (K_need-post-for-smell-wumpus_p7-7)) (K_not_stench_p7-7)))
    (:action sensor-smell-wumpus_p7-5__sensor__-obs0-ver0
        :effect (when (and (not (K_not_stench_p7-5)) (not (K_stench_p7-5)) (K_need-post-for-smell-wumpus_p7-5)) (K_stench_p7-5)))
    (:action sensor-smell-wumpus_p7-5__sensor__-obs0-ver1
        :effect (when (and (not (K_not_stench_p7-5)) (not (K_stench_p7-5)) (K_need-post-for-smell-wumpus_p7-5)) (K_not_stench_p7-5)))
    (:action sensor-smell-wumpus_p6-6__sensor__-obs0-ver0
        :effect (when (and (not (K_not_stench_p6-6)) (not (K_stench_p6-6)) (K_need-post-for-smell-wumpus_p6-6)) (K_stench_p6-6)))
    (:action sensor-smell-wumpus_p6-6__sensor__-obs0-ver1
        :effect (when (and (not (K_not_stench_p6-6)) (not (K_stench_p6-6)) (K_need-post-for-smell-wumpus_p6-6)) (K_not_stench_p6-6)))
    (:action sensor-smell-wumpus_p6-4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_stench_p6-4)) (not (K_stench_p6-4)) (K_need-post-for-smell-wumpus_p6-4)) (K_stench_p6-4)))
    (:action sensor-smell-wumpus_p6-4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_stench_p6-4)) (not (K_stench_p6-4)) (K_need-post-for-smell-wumpus_p6-4)) (K_not_stench_p6-4)))
    (:action sensor-smell-wumpus_p5-7__sensor__-obs0-ver0
        :effect (when (and (not (K_not_stench_p5-7)) (not (K_stench_p5-7)) (K_need-post-for-smell-wumpus_p5-7)) (K_stench_p5-7)))
    (:action sensor-smell-wumpus_p5-7__sensor__-obs0-ver1
        :effect (when (and (not (K_not_stench_p5-7)) (not (K_stench_p5-7)) (K_need-post-for-smell-wumpus_p5-7)) (K_not_stench_p5-7)))
    (:action sensor-smell-wumpus_p5-5__sensor__-obs0-ver0
        :effect (when (and (not (K_not_stench_p5-5)) (not (K_stench_p5-5)) (K_need-post-for-smell-wumpus_p5-5)) (K_stench_p5-5)))
    (:action sensor-smell-wumpus_p5-5__sensor__-obs0-ver1
        :effect (when (and (not (K_not_stench_p5-5)) (not (K_stench_p5-5)) (K_need-post-for-smell-wumpus_p5-5)) (K_not_stench_p5-5)))
    (:action sensor-smell-wumpus_p5-3__sensor__-obs0-ver0
        :effect (when (and (not (K_not_stench_p5-3)) (not (K_stench_p5-3)) (K_need-post-for-smell-wumpus_p5-3)) (K_stench_p5-3)))
    (:action sensor-smell-wumpus_p5-3__sensor__-obs0-ver1
        :effect (when (and (not (K_not_stench_p5-3)) (not (K_stench_p5-3)) (K_need-post-for-smell-wumpus_p5-3)) (K_not_stench_p5-3)))
    (:action sensor-smell-wumpus_p4-6__sensor__-obs0-ver0
        :effect (when (and (not (K_not_stench_p4-6)) (not (K_stench_p4-6)) (K_need-post-for-smell-wumpus_p4-6)) (K_stench_p4-6)))
    (:action sensor-smell-wumpus_p4-6__sensor__-obs0-ver1
        :effect (when (and (not (K_not_stench_p4-6)) (not (K_stench_p4-6)) (K_need-post-for-smell-wumpus_p4-6)) (K_not_stench_p4-6)))
    (:action sensor-smell-wumpus_p4-4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_stench_p4-4)) (not (K_stench_p4-4)) (K_need-post-for-smell-wumpus_p4-4)) (K_stench_p4-4)))
    (:action sensor-smell-wumpus_p4-4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_stench_p4-4)) (not (K_stench_p4-4)) (K_need-post-for-smell-wumpus_p4-4)) (K_not_stench_p4-4)))
    (:action sensor-smell-wumpus_p4-2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_stench_p4-2)) (not (K_stench_p4-2)) (K_need-post-for-smell-wumpus_p4-2)) (K_stench_p4-2)))
    (:action sensor-smell-wumpus_p4-2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_stench_p4-2)) (not (K_stench_p4-2)) (K_need-post-for-smell-wumpus_p4-2)) (K_not_stench_p4-2)))
    (:action sensor-smell-wumpus_p3-5__sensor__-obs0-ver0
        :effect (when (and (not (K_not_stench_p3-5)) (not (K_stench_p3-5)) (K_need-post-for-smell-wumpus_p3-5)) (K_stench_p3-5)))
    (:action sensor-smell-wumpus_p3-5__sensor__-obs0-ver1
        :effect (when (and (not (K_not_stench_p3-5)) (not (K_stench_p3-5)) (K_need-post-for-smell-wumpus_p3-5)) (K_not_stench_p3-5)))
    (:action sensor-smell-wumpus_p3-3__sensor__-obs0-ver0
        :effect (when (and (not (K_not_stench_p3-3)) (not (K_stench_p3-3)) (K_need-post-for-smell-wumpus_p3-3)) (K_stench_p3-3)))
    (:action sensor-smell-wumpus_p3-3__sensor__-obs0-ver1
        :effect (when (and (not (K_not_stench_p3-3)) (not (K_stench_p3-3)) (K_need-post-for-smell-wumpus_p3-3)) (K_not_stench_p3-3)))
    (:action sensor-smell-wumpus_p3-1__sensor__-obs0-ver0
        :effect (when (and (not (K_not_stench_p3-1)) (not (K_stench_p3-1)) (K_need-post-for-smell-wumpus_p3-1)) (K_stench_p3-1)))
    (:action sensor-smell-wumpus_p3-1__sensor__-obs0-ver1
        :effect (when (and (not (K_not_stench_p3-1)) (not (K_stench_p3-1)) (K_need-post-for-smell-wumpus_p3-1)) (K_not_stench_p3-1)))
    (:action sensor-smell-wumpus_p2-4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_stench_p2-4)) (not (K_stench_p2-4)) (K_need-post-for-smell-wumpus_p2-4)) (K_stench_p2-4)))
    (:action sensor-smell-wumpus_p2-4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_stench_p2-4)) (not (K_stench_p2-4)) (K_need-post-for-smell-wumpus_p2-4)) (K_not_stench_p2-4)))
    (:action sensor-smell-wumpus_p2-2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_stench_p2-2)) (not (K_stench_p2-2)) (K_need-post-for-smell-wumpus_p2-2)) (K_stench_p2-2)))
    (:action sensor-smell-wumpus_p2-2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_stench_p2-2)) (not (K_stench_p2-2)) (K_need-post-for-smell-wumpus_p2-2)) (K_not_stench_p2-2)))
    (:action sensor-smell-wumpus_p1-3__sensor__-obs0-ver0
        :effect (when (and (not (K_not_stench_p1-3)) (not (K_stench_p1-3)) (K_need-post-for-smell-wumpus_p1-3)) (K_stench_p1-3)))
    (:action sensor-smell-wumpus_p1-3__sensor__-obs0-ver1
        :effect (when (and (not (K_not_stench_p1-3)) (not (K_stench_p1-3)) (K_need-post-for-smell-wumpus_p1-3)) (K_not_stench_p1-3)))
    (:action invariant-0
        :effect (when (and (not (K_wumpus-at_p7-6)) (K_not_stench_p7-7)) (K_not_wumpus-at_p7-6)))
    (:action invariant-1
        :effect (when (and (not (K_not_stench_p7-7)) (K_wumpus-at_p7-6)) (K_stench_p7-7)))
    (:action invariant-2
        :effect (when (and (not (K_wumpus-at_p6-7)) (K_not_stench_p7-7)) (K_not_wumpus-at_p6-7)))
    (:action invariant-3
        :effect (when (and (not (K_not_stench_p7-7)) (K_wumpus-at_p6-7)) (K_stench_p7-7)))
    (:action invariant-4
        :effect (when (and (not (K_not_wumpus-at_p7-6)) (K_stench_p7-7) (K_not_wumpus-at_p6-7)) (K_wumpus-at_p7-6)))
    (:action invariant-5
        :effect (when (and (not (K_not_wumpus-at_p6-7)) (K_not_wumpus-at_p7-6) (K_stench_p7-7)) (K_wumpus-at_p6-7)))
    (:action invariant-6
        :effect (when (and (not (K_stench_p7-7)) (K_not_wumpus-at_p7-6) (K_not_wumpus-at_p6-7)) (K_not_stench_p7-7)))
    (:action invariant-15
        :effect (when (and (not (K_wumpus-at_p7-6)) (K_not_stench_p7-5)) (K_not_wumpus-at_p7-6)))
    (:action invariant-16
        :effect (when (and (not (K_not_stench_p7-5)) (K_wumpus-at_p7-6)) (K_stench_p7-5)))
    (:action invariant-19
        :effect (when (and (not (K_wumpus-at_p6-5)) (K_not_stench_p7-5)) (K_not_wumpus-at_p6-5)))
    (:action invariant-20
        :effect (when (and (not (K_not_stench_p7-5)) (K_wumpus-at_p6-5)) (K_stench_p7-5)))
    (:action invariant-21
        :effect (when (and (not (K_not_wumpus-at_p7-6)) (K_stench_p7-5) (K_not_wumpus-at_p6-5)) (K_wumpus-at_p7-6)))
    (:action invariant-22
        :effect (when (and (not (K_stench_p7-5)) (K_not_wumpus-at_p7-6) (K_not_wumpus-at_p6-5)) (K_not_stench_p7-5)))
    (:action invariant-23
        :effect (when (and (not (K_not_wumpus-at_p6-5)) (K_not_wumpus-at_p7-6) (K_stench_p7-5)) (K_wumpus-at_p6-5)))
    (:action invariant-62
        :effect (when (and (not (K_wumpus-at_p7-6)) (K_not_stench_p6-6)) (K_not_wumpus-at_p7-6)))
    (:action invariant-63
        :effect (when (and (not (K_not_stench_p6-6)) (K_wumpus-at_p7-6)) (K_stench_p6-6)))
    (:action invariant-64
        :effect (when (and (not (K_wumpus-at_p6-7)) (K_not_stench_p6-6)) (K_not_wumpus-at_p6-7)))
    (:action invariant-65
        :effect (when (and (not (K_not_stench_p6-6)) (K_wumpus-at_p6-7)) (K_stench_p6-6)))
    (:action invariant-66
        :effect (when (and (not (K_wumpus-at_p6-5)) (K_not_stench_p6-6)) (K_not_wumpus-at_p6-5)))
    (:action invariant-67
        :effect (when (and (not (K_not_stench_p6-6)) (K_wumpus-at_p6-5)) (K_stench_p6-6)))
    (:action invariant-68
        :effect (when (and (not (K_wumpus-at_p5-6)) (K_not_stench_p6-6)) (K_not_wumpus-at_p5-6)))
    (:action invariant-69
        :effect (when (and (not (K_not_stench_p6-6)) (K_wumpus-at_p5-6)) (K_stench_p6-6)))
    (:action invariant-70
        :effect (when (and (not (K_not_wumpus-at_p7-6)) (K_not_wumpus-at_p6-7) (K_not_wumpus-at_p6-5) (K_stench_p6-6) (K_not_wumpus-at_p5-6)) (K_wumpus-at_p7-6)))
    (:action invariant-71
        :effect (when (and (not (K_not_wumpus-at_p6-7)) (K_not_wumpus-at_p7-6) (K_not_wumpus-at_p6-5) (K_stench_p6-6) (K_not_wumpus-at_p5-6)) (K_wumpus-at_p6-7)))
    (:action invariant-72
        :effect (when (and (not (K_not_wumpus-at_p6-5)) (K_not_wumpus-at_p7-6) (K_not_wumpus-at_p6-7) (K_stench_p6-6) (K_not_wumpus-at_p5-6)) (K_wumpus-at_p6-5)))
    (:action invariant-73
        :effect (when (and (not (K_not_wumpus-at_p5-6)) (K_not_wumpus-at_p7-6) (K_not_wumpus-at_p6-7) (K_not_wumpus-at_p6-5) (K_stench_p6-6)) (K_wumpus-at_p5-6)))
    (:action invariant-74
        :effect (when (and (not (K_stench_p6-6)) (K_not_wumpus-at_p7-6) (K_not_wumpus-at_p6-7) (K_not_wumpus-at_p6-5) (K_not_wumpus-at_p5-6)) (K_not_stench_p6-6)))
    (:action invariant-87
        :effect (when (and (not (K_wumpus-at_p6-5)) (K_not_stench_p6-4)) (K_not_wumpus-at_p6-5)))
    (:action invariant-88
        :effect (when (and (not (K_not_stench_p6-4)) (K_wumpus-at_p6-5)) (K_stench_p6-4)))
    (:action invariant-91
        :effect (when (and (not (K_wumpus-at_p5-4)) (K_not_stench_p6-4)) (K_not_wumpus-at_p5-4)))
    (:action invariant-92
        :effect (when (and (not (K_not_stench_p6-4)) (K_wumpus-at_p5-4)) (K_stench_p6-4)))
    (:action invariant-93
        :effect (when (and (not (K_stench_p6-4)) (K_not_wumpus-at_p6-5) (K_not_wumpus-at_p5-4)) (K_not_stench_p6-4)))
    (:action invariant-94
        :effect (when (and (not (K_not_wumpus-at_p6-5)) (K_stench_p6-4) (K_not_wumpus-at_p5-4)) (K_wumpus-at_p6-5)))
    (:action invariant-95
        :effect (when (and (not (K_not_wumpus-at_p5-4)) (K_not_wumpus-at_p6-5) (K_stench_p6-4)) (K_wumpus-at_p5-4)))
    (:action invariant-124
        :effect (when (and (not (K_wumpus-at_p6-7)) (K_not_stench_p5-7)) (K_not_wumpus-at_p6-7)))
    (:action invariant-125
        :effect (when (and (not (K_not_stench_p5-7)) (K_wumpus-at_p6-7)) (K_stench_p5-7)))
    (:action invariant-126
        :effect (when (and (not (K_wumpus-at_p5-6)) (K_not_stench_p5-7)) (K_not_wumpus-at_p5-6)))
    (:action invariant-127
        :effect (when (and (not (K_not_stench_p5-7)) (K_wumpus-at_p5-6)) (K_stench_p5-7)))
    (:action invariant-130
        :effect (when (and (not (K_not_wumpus-at_p6-7)) (K_not_wumpus-at_p5-6) (K_stench_p5-7)) (K_wumpus-at_p6-7)))
    (:action invariant-131
        :effect (when (and (not (K_not_wumpus-at_p5-6)) (K_not_wumpus-at_p6-7) (K_stench_p5-7)) (K_wumpus-at_p5-6)))
    (:action invariant-132
        :effect (when (and (not (K_stench_p5-7)) (K_not_wumpus-at_p6-7) (K_not_wumpus-at_p5-6)) (K_not_stench_p5-7)))
    (:action invariant-143
        :effect (when (and (not (K_wumpus-at_p6-5)) (K_not_stench_p5-5)) (K_not_wumpus-at_p6-5)))
    (:action invariant-144
        :effect (when (and (not (K_not_stench_p5-5)) (K_wumpus-at_p6-5)) (K_stench_p5-5)))
    (:action invariant-145
        :effect (when (and (not (K_wumpus-at_p5-6)) (K_not_stench_p5-5)) (K_not_wumpus-at_p5-6)))
    (:action invariant-146
        :effect (when (and (not (K_not_stench_p5-5)) (K_wumpus-at_p5-6)) (K_stench_p5-5)))
    (:action invariant-147
        :effect (when (and (not (K_wumpus-at_p5-4)) (K_not_stench_p5-5)) (K_not_wumpus-at_p5-4)))
    (:action invariant-148
        :effect (when (and (not (K_not_stench_p5-5)) (K_wumpus-at_p5-4)) (K_stench_p5-5)))
    (:action invariant-149
        :effect (when (and (not (K_wumpus-at_p4-5)) (K_not_stench_p5-5)) (K_not_wumpus-at_p4-5)))
    (:action invariant-150
        :effect (when (and (not (K_not_stench_p5-5)) (K_wumpus-at_p4-5)) (K_stench_p5-5)))
    (:action invariant-151
        :effect (when (and (not (K_not_wumpus-at_p6-5)) (K_not_wumpus-at_p5-6) (K_not_wumpus-at_p5-4) (K_stench_p5-5) (K_not_wumpus-at_p4-5)) (K_wumpus-at_p6-5)))
    (:action invariant-152
        :effect (when (and (not (K_not_wumpus-at_p5-6)) (K_not_wumpus-at_p6-5) (K_not_wumpus-at_p5-4) (K_stench_p5-5) (K_not_wumpus-at_p4-5)) (K_wumpus-at_p5-6)))
    (:action invariant-153
        :effect (when (and (not (K_not_wumpus-at_p5-4)) (K_not_wumpus-at_p6-5) (K_not_wumpus-at_p5-6) (K_stench_p5-5) (K_not_wumpus-at_p4-5)) (K_wumpus-at_p5-4)))
    (:action invariant-154
        :effect (when (and (not (K_not_wumpus-at_p4-5)) (K_not_wumpus-at_p6-5) (K_not_wumpus-at_p5-6) (K_not_wumpus-at_p5-4) (K_stench_p5-5)) (K_wumpus-at_p4-5)))
    (:action invariant-155
        :effect (when (and (not (K_stench_p5-5)) (K_not_wumpus-at_p6-5) (K_not_wumpus-at_p5-6) (K_not_wumpus-at_p5-4) (K_not_wumpus-at_p4-5)) (K_not_stench_p5-5)))
    (:action invariant-168
        :effect (when (and (not (K_wumpus-at_p5-4)) (K_not_stench_p5-3)) (K_not_wumpus-at_p5-4)))
    (:action invariant-169
        :effect (when (and (not (K_not_stench_p5-3)) (K_wumpus-at_p5-4)) (K_stench_p5-3)))
    (:action invariant-172
        :effect (when (and (not (K_wumpus-at_p4-3)) (K_not_stench_p5-3)) (K_not_wumpus-at_p4-3)))
    (:action invariant-173
        :effect (when (and (not (K_not_stench_p5-3)) (K_wumpus-at_p4-3)) (K_stench_p5-3)))
    (:action invariant-174
        :effect (when (and (not (K_stench_p5-3)) (K_not_wumpus-at_p5-4) (K_not_wumpus-at_p4-3)) (K_not_stench_p5-3)))
    (:action invariant-175
        :effect (when (and (not (K_not_wumpus-at_p5-4)) (K_stench_p5-3) (K_not_wumpus-at_p4-3)) (K_wumpus-at_p5-4)))
    (:action invariant-176
        :effect (when (and (not (K_not_wumpus-at_p4-3)) (K_not_wumpus-at_p5-4) (K_stench_p5-3)) (K_wumpus-at_p4-3)))
    (:action invariant-203
        :effect (when (and (not (K_wumpus-at_p5-6)) (K_not_stench_p4-6)) (K_not_wumpus-at_p5-6)))
    (:action invariant-204
        :effect (when (and (not (K_not_stench_p4-6)) (K_wumpus-at_p5-6)) (K_stench_p4-6)))
    (:action invariant-207
        :effect (when (and (not (K_wumpus-at_p4-5)) (K_not_stench_p4-6)) (K_not_wumpus-at_p4-5)))
    (:action invariant-208
        :effect (when (and (not (K_not_stench_p4-6)) (K_wumpus-at_p4-5)) (K_stench_p4-6)))
    (:action invariant-211
        :effect (when (and (not (K_not_wumpus-at_p5-6)) (K_not_wumpus-at_p4-5) (K_stench_p4-6)) (K_wumpus-at_p5-6)))
    (:action invariant-212
        :effect (when (and (not (K_stench_p4-6)) (K_not_wumpus-at_p5-6) (K_not_wumpus-at_p4-5)) (K_not_stench_p4-6)))
    (:action invariant-213
        :effect (when (and (not (K_not_wumpus-at_p4-5)) (K_not_wumpus-at_p5-6) (K_stench_p4-6)) (K_wumpus-at_p4-5)))
    (:action invariant-224
        :effect (when (and (not (K_wumpus-at_p5-4)) (K_not_stench_p4-4)) (K_not_wumpus-at_p5-4)))
    (:action invariant-225
        :effect (when (and (not (K_not_stench_p4-4)) (K_wumpus-at_p5-4)) (K_stench_p4-4)))
    (:action invariant-226
        :effect (when (and (not (K_wumpus-at_p4-5)) (K_not_stench_p4-4)) (K_not_wumpus-at_p4-5)))
    (:action invariant-227
        :effect (when (and (not (K_not_stench_p4-4)) (K_wumpus-at_p4-5)) (K_stench_p4-4)))
    (:action invariant-228
        :effect (when (and (not (K_wumpus-at_p4-3)) (K_not_stench_p4-4)) (K_not_wumpus-at_p4-3)))
    (:action invariant-229
        :effect (when (and (not (K_not_stench_p4-4)) (K_wumpus-at_p4-3)) (K_stench_p4-4)))
    (:action invariant-230
        :effect (when (and (not (K_wumpus-at_p3-4)) (K_not_stench_p4-4)) (K_not_wumpus-at_p3-4)))
    (:action invariant-231
        :effect (when (and (not (K_not_stench_p4-4)) (K_wumpus-at_p3-4)) (K_stench_p4-4)))
    (:action invariant-232
        :effect (when (and (not (K_not_wumpus-at_p5-4)) (K_not_wumpus-at_p4-5) (K_not_wumpus-at_p4-3) (K_stench_p4-4) (K_not_wumpus-at_p3-4)) (K_wumpus-at_p5-4)))
    (:action invariant-233
        :effect (when (and (not (K_not_wumpus-at_p4-5)) (K_not_wumpus-at_p5-4) (K_not_wumpus-at_p4-3) (K_stench_p4-4) (K_not_wumpus-at_p3-4)) (K_wumpus-at_p4-5)))
    (:action invariant-234
        :effect (when (and (not (K_not_wumpus-at_p4-3)) (K_not_wumpus-at_p5-4) (K_not_wumpus-at_p4-5) (K_stench_p4-4) (K_not_wumpus-at_p3-4)) (K_wumpus-at_p4-3)))
    (:action invariant-235
        :effect (when (and (not (K_not_wumpus-at_p3-4)) (K_not_wumpus-at_p5-4) (K_not_wumpus-at_p4-5) (K_not_wumpus-at_p4-3) (K_stench_p4-4)) (K_wumpus-at_p3-4)))
    (:action invariant-236
        :effect (when (and (not (K_stench_p4-4)) (K_not_wumpus-at_p5-4) (K_not_wumpus-at_p4-5) (K_not_wumpus-at_p4-3) (K_not_wumpus-at_p3-4)) (K_not_stench_p4-4)))
    (:action invariant-249
        :effect (when (and (not (K_wumpus-at_p4-3)) (K_not_stench_p4-2)) (K_not_wumpus-at_p4-3)))
    (:action invariant-250
        :effect (when (and (not (K_not_stench_p4-2)) (K_wumpus-at_p4-3)) (K_stench_p4-2)))
    (:action invariant-253
        :effect (when (and (not (K_wumpus-at_p3-2)) (K_not_stench_p4-2)) (K_not_wumpus-at_p3-2)))
    (:action invariant-254
        :effect (when (and (not (K_not_stench_p4-2)) (K_wumpus-at_p3-2)) (K_stench_p4-2)))
    (:action invariant-255
        :effect (when (and (not (K_stench_p4-2)) (K_not_wumpus-at_p4-3) (K_not_wumpus-at_p3-2)) (K_not_stench_p4-2)))
    (:action invariant-256
        :effect (when (and (not (K_not_wumpus-at_p4-3)) (K_stench_p4-2) (K_not_wumpus-at_p3-2)) (K_wumpus-at_p4-3)))
    (:action invariant-257
        :effect (when (and (not (K_not_wumpus-at_p3-2)) (K_not_wumpus-at_p4-3) (K_stench_p4-2)) (K_wumpus-at_p3-2)))
    (:action invariant-284
        :effect (when (and (not (K_wumpus-at_p4-5)) (K_not_stench_p3-5)) (K_not_wumpus-at_p4-5)))
    (:action invariant-285
        :effect (when (and (not (K_not_stench_p3-5)) (K_wumpus-at_p4-5)) (K_stench_p3-5)))
    (:action invariant-286
        :effect (when (and (not (K_not_wumpus-at_p6-7)) (K_not_wumpus-at_p7-6)) (K_wumpus-at_p6-7)))
    (:action invariant-287
        :effect (when (and (not (K_not_wumpus-at_p7-6)) (K_not_wumpus-at_p6-7)) (K_wumpus-at_p7-6)))
    (:action invariant-288
        :effect (when (and (not (K_wumpus-at_p3-4)) (K_not_stench_p3-5)) (K_not_wumpus-at_p3-4)))
    (:action invariant-289
        :effect (when (and (not (K_not_stench_p3-5)) (K_wumpus-at_p3-4)) (K_stench_p3-5)))
    (:action invariant-290
        :effect (when (and (not (K_wumpus-at_p6-7)) (K_wumpus-at_p7-6)) (K_not_wumpus-at_p6-7)))
    (:action invariant-291
        :effect (when (and (not (K_wumpus-at_p7-6)) (K_wumpus-at_p6-7)) (K_not_wumpus-at_p7-6)))
    (:action invariant-292
        :effect (when (and (not (K_not_wumpus-at_p4-5)) (K_not_wumpus-at_p3-4) (K_stench_p3-5)) (K_wumpus-at_p4-5)))
    (:action invariant-293
        :effect (when (and (not (K_stench_p3-5)) (K_not_wumpus-at_p4-5) (K_not_wumpus-at_p3-4)) (K_not_stench_p3-5)))
    (:action invariant-294
        :effect (when (and (not (K_not_wumpus-at_p3-4)) (K_not_wumpus-at_p4-5) (K_stench_p3-5)) (K_wumpus-at_p3-4)))
    (:action invariant-295
        :effect (when (and (not (K_not_wumpus-at_p5-6)) (K_not_wumpus-at_p6-5)) (K_wumpus-at_p5-6)))
    (:action invariant-296
        :effect (when (and (not (K_not_wumpus-at_p6-5)) (K_not_wumpus-at_p5-6)) (K_wumpus-at_p6-5)))
    (:action invariant-297
        :effect (when (and (not (K_wumpus-at_p5-6)) (K_wumpus-at_p6-5)) (K_not_wumpus-at_p5-6)))
    (:action invariant-298
        :effect (when (and (not (K_wumpus-at_p6-5)) (K_wumpus-at_p5-6)) (K_not_wumpus-at_p6-5)))
    (:action invariant-299
        :effect (when (and (not (K_not_wumpus-at_p4-5)) (K_not_wumpus-at_p5-4)) (K_wumpus-at_p4-5)))
    (:action invariant-300
        :effect (when (and (not (K_not_wumpus-at_p5-4)) (K_not_wumpus-at_p4-5)) (K_wumpus-at_p5-4)))
    (:action invariant-301
        :effect (when (and (not (K_wumpus-at_p4-5)) (K_wumpus-at_p5-4)) (K_not_wumpus-at_p4-5)))
    (:action invariant-302
        :effect (when (and (not (K_wumpus-at_p5-4)) (K_wumpus-at_p4-5)) (K_not_wumpus-at_p5-4)))
    (:action invariant-303
        :effect (when (and (not (K_not_wumpus-at_p3-4)) (K_not_wumpus-at_p4-3)) (K_wumpus-at_p3-4)))
    (:action invariant-304
        :effect (when (and (not (K_not_wumpus-at_p4-3)) (K_not_wumpus-at_p3-4)) (K_wumpus-at_p4-3)))
    (:action invariant-305
        :effect (when (and (not (K_wumpus-at_p4-3)) (K_not_stench_p3-3)) (K_not_wumpus-at_p4-3)))
    (:action invariant-306
        :effect (when (and (not (K_not_stench_p3-3)) (K_wumpus-at_p4-3)) (K_stench_p3-3)))
    (:action invariant-307
        :effect (when (and (not (K_wumpus-at_p3-4)) (K_not_stench_p3-3)) (K_not_wumpus-at_p3-4)))
    (:action invariant-308
        :effect (when (and (not (K_not_stench_p3-3)) (K_wumpus-at_p3-4)) (K_stench_p3-3)))
    (:action invariant-309
        :effect (when (and (not (K_wumpus-at_p3-2)) (K_not_stench_p3-3)) (K_not_wumpus-at_p3-2)))
    (:action invariant-310
        :effect (when (and (not (K_not_stench_p3-3)) (K_wumpus-at_p3-2)) (K_stench_p3-3)))
    (:action invariant-311
        :effect (when (and (not (K_wumpus-at_p2-3)) (K_not_stench_p3-3)) (K_not_wumpus-at_p2-3)))
    (:action invariant-312
        :effect (when (and (not (K_not_stench_p3-3)) (K_wumpus-at_p2-3)) (K_stench_p3-3)))
    (:action invariant-313
        :effect (when (and (not (K_not_wumpus-at_p4-3)) (K_not_wumpus-at_p3-4) (K_not_wumpus-at_p3-2) (K_stench_p3-3) (K_not_wumpus-at_p2-3)) (K_wumpus-at_p4-3)))
    (:action invariant-314
        :effect (when (and (not (K_not_wumpus-at_p3-4)) (K_not_wumpus-at_p4-3) (K_not_wumpus-at_p3-2) (K_stench_p3-3) (K_not_wumpus-at_p2-3)) (K_wumpus-at_p3-4)))
    (:action invariant-315
        :effect (when (and (not (K_not_wumpus-at_p3-2)) (K_not_wumpus-at_p4-3) (K_not_wumpus-at_p3-4) (K_stench_p3-3) (K_not_wumpus-at_p2-3)) (K_wumpus-at_p3-2)))
    (:action invariant-316
        :effect (when (and (not (K_not_wumpus-at_p2-3)) (K_not_wumpus-at_p4-3) (K_not_wumpus-at_p3-4) (K_not_wumpus-at_p3-2) (K_stench_p3-3)) (K_wumpus-at_p2-3)))
    (:action invariant-317
        :effect (when (and (not (K_stench_p3-3)) (K_not_wumpus-at_p4-3) (K_not_wumpus-at_p3-4) (K_not_wumpus-at_p3-2) (K_not_wumpus-at_p2-3)) (K_not_stench_p3-3)))
    (:action invariant-318
        :effect (when (and (not (K_wumpus-at_p3-4)) (K_wumpus-at_p4-3)) (K_not_wumpus-at_p3-4)))
    (:action invariant-319
        :effect (when (and (not (K_wumpus-at_p4-3)) (K_wumpus-at_p3-4)) (K_not_wumpus-at_p4-3)))
    (:action invariant-320
        :effect (when (and (not (K_not_wumpus-at_p2-3)) (K_not_wumpus-at_p3-2)) (K_wumpus-at_p2-3)))
    (:action invariant-321
        :effect (when (and (not (K_not_wumpus-at_p3-2)) (K_not_wumpus-at_p2-3)) (K_wumpus-at_p3-2)))
    (:action invariant-322
        :effect (when (and (not (K_wumpus-at_p2-3)) (K_wumpus-at_p3-2)) (K_not_wumpus-at_p2-3)))
    (:action invariant-323
        :effect (when (and (not (K_wumpus-at_p3-2)) (K_wumpus-at_p2-3)) (K_not_wumpus-at_p3-2)))
    (:action invariant-324
        :effect (when (and (not (K_not_at_p7-7)) (K_not_at_p1-1) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p7-7)))
    (:action invariant-325
        :effect (when (and (not (K_not_at_p7-6)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p7-6)))
    (:action invariant-326
        :effect (when (and (not (K_not_at_p7-5)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p7-5)))
    (:action invariant-327
        :effect (when (and (not (K_not_at_p7-4)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p7-4)))
    (:action invariant-328
        :effect (when (and (not (K_not_at_p7-3)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p7-3)))
    (:action invariant-329
        :effect (when (and (not (K_not_at_p7-2)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p7-2)))
    (:action invariant-330
        :effect (when (and (not (K_not_at_p7-1)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p7-1)))
    (:action invariant-331
        :effect (when (and (not (K_not_at_p6-7)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p6-7)))
    (:action invariant-332
        :effect (when (and (not (K_not_at_p6-6)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p6-6)))
    (:action invariant-333
        :effect (when (and (not (K_not_at_p6-5)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p6-5)))
    (:action invariant-334
        :effect (when (and (not (K_not_at_p6-4)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p6-4)))
    (:action invariant-335
        :effect (when (and (not (K_not_at_p6-3)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p6-3)))
    (:action invariant-336
        :effect (when (and (not (K_not_at_p6-2)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p6-2)))
    (:action invariant-337
        :effect (when (and (not (K_not_at_p6-1)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p6-1)))
    (:action invariant-338
        :effect (when (and (not (K_not_at_p5-7)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p5-7)))
    (:action invariant-339
        :effect (when (and (not (K_not_at_p5-6)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p5-6)))
    (:action invariant-340
        :effect (when (and (not (K_not_at_p5-5)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p5-5)))
    (:action invariant-341
        :effect (when (and (not (K_not_at_p5-4)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p5-4)))
    (:action invariant-342
        :effect (when (and (not (K_not_at_p5-3)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p5-3)))
    (:action invariant-343
        :effect (when (and (not (K_not_at_p5-2)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p5-2)))
    (:action invariant-344
        :effect (when (and (not (K_not_at_p5-1)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p5-1)))
    (:action invariant-345
        :effect (when (and (not (K_not_at_p4-7)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p4-7)))
    (:action invariant-346
        :effect (when (and (not (K_not_at_p4-6)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p4-6)))
    (:action invariant-347
        :effect (when (and (not (K_not_at_p4-5)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p4-5)))
    (:action invariant-348
        :effect (when (and (not (K_not_at_p4-4)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p4-4)))
    (:action invariant-349
        :effect (when (and (not (K_not_at_p4-3)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p4-3)))
    (:action invariant-350
        :effect (when (and (not (K_not_at_p4-2)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p4-2)))
    (:action invariant-351
        :effect (when (and (not (K_not_at_p4-1)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p4-1)))
    (:action invariant-352
        :effect (when (and (not (K_not_at_p3-7)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p3-7)))
    (:action invariant-353
        :effect (when (and (not (K_not_at_p3-6)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p3-6)))
    (:action invariant-354
        :effect (when (and (not (K_not_at_p3-5)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p3-5)))
    (:action invariant-355
        :effect (when (and (not (K_not_at_p3-4)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p3-4)))
    (:action invariant-356
        :effect (when (and (not (K_not_at_p3-3)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p3-3)))
    (:action invariant-357
        :effect (when (and (not (K_not_at_p3-2)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p3-2)))
    (:action invariant-358
        :effect (when (and (not (K_not_at_p3-1)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p3-1)))
    (:action invariant-359
        :effect (when (and (not (K_not_at_p2-7)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p2-7)))
    (:action invariant-360
        :effect (when (and (not (K_not_at_p2-6)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p2-6)))
    (:action invariant-361
        :effect (when (and (not (K_not_at_p2-5)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p2-5)))
    (:action invariant-362
        :effect (when (and (not (K_not_at_p2-4)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p2-4)))
    (:action invariant-363
        :effect (when (and (not (K_not_at_p2-3)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p2-3)))
    (:action invariant-364
        :effect (when (and (not (K_not_at_p2-2)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p2-2)))
    (:action invariant-365
        :effect (when (and (not (K_not_at_p2-1)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p2-1)))
    (:action invariant-366
        :effect (when (and (not (K_not_at_p1-7)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p1-7)))
    (:action invariant-367
        :effect (when (and (not (K_not_at_p1-6)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p1-6)))
    (:action invariant-368
        :effect (when (and (not (K_not_at_p1-5)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p1-5)))
    (:action invariant-369
        :effect (when (and (not (K_not_at_p1-4)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p1-4)))
    (:action invariant-370
        :effect (when (and (not (K_not_at_p1-3)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-2)) (K_at_p1-3)))
    (:action invariant-371
        :effect (when (and (not (K_not_at_p1-2)) (K_not_at_p1-1) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3)) (K_at_p1-2)))
    (:action invariant-372
        :effect (when (and (not (K_not_at_p1-1)) (K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1) (K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1) (K_not_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1) (K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1) (K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1) (K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1) (K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)) (K_at_p1-1)))
    (:action invariant-373
        :effect (when (and (not (K_at_p1-2)) (K_at_p1-1)) (K_not_at_p1-2)))
    (:action invariant-374
        :effect (when (and (not (K_at_p1-1)) (K_at_p1-2)) (K_not_at_p1-1)))
    (:action invariant-375
        :effect (when (and (not (K_at_p1-3)) (K_at_p1-1)) (K_not_at_p1-3)))
    (:action invariant-376
        :effect (when (and (not (K_at_p1-1)) (K_at_p1-3)) (K_not_at_p1-1)))
    (:action invariant-377
        :effect (when (and (not (K_wumpus-at_p3-2)) (K_not_stench_p3-1)) (K_not_wumpus-at_p3-2)))
    (:action invariant-378
        :effect (when (and (not (K_not_stench_p3-1)) (K_wumpus-at_p3-2)) (K_stench_p3-1)))
    (:action invariant-379
        :effect (when (and (not (K_at_p1-3)) (K_at_p1-2)) (K_not_at_p1-3)))
    (:action invariant-380
        :effect (when (and (not (K_at_p1-2)) (K_at_p1-3)) (K_not_at_p1-2)))
    (:action invariant-381
        :effect (when (and (not (K_stench_p3-1)) (K_not_wumpus-at_p3-2)) (K_not_stench_p3-1)))
    (:action invariant-382
        :effect (when (and (not (K_not_wumpus-at_p3-2)) (K_stench_p3-1)) (K_wumpus-at_p3-2)))
    (:action invariant-383
        :effect (when (and (not (K_at_p1-4)) (K_at_p1-1)) (K_not_at_p1-4)))
    (:action invariant-384
        :effect (when (and (not (K_at_p1-1)) (K_at_p1-4)) (K_not_at_p1-1)))
    (:action invariant-385
        :effect (when (and (not (K_at_p1-4)) (K_at_p1-2)) (K_not_at_p1-4)))
    (:action invariant-386
        :effect (when (and (not (K_at_p1-2)) (K_at_p1-4)) (K_not_at_p1-2)))
    (:action invariant-387
        :effect (when (and (not (K_at_p1-4)) (K_at_p1-3)) (K_not_at_p1-4)))
    (:action invariant-388
        :effect (when (and (not (K_at_p1-3)) (K_at_p1-4)) (K_not_at_p1-3)))
    (:action invariant-389
        :effect (when (and (not (K_at_p1-5)) (K_at_p1-1)) (K_not_at_p1-5)))
    (:action invariant-390
        :effect (when (and (not (K_at_p1-1)) (K_at_p1-5)) (K_not_at_p1-1)))
    (:action invariant-391
        :effect (when (and (not (K_at_p1-5)) (K_at_p1-2)) (K_not_at_p1-5)))
    (:action invariant-392
        :effect (when (and (not (K_at_p1-2)) (K_at_p1-5)) (K_not_at_p1-2)))
    (:action invariant-393
        :effect (when (and (not (K_at_p1-5)) (K_at_p1-3)) (K_not_at_p1-5)))
    (:action invariant-394
        :effect (when (and (not (K_at_p1-3)) (K_at_p1-5)) (K_not_at_p1-3)))
    (:action invariant-395
        :effect (when (and (not (K_at_p1-5)) (K_at_p1-4)) (K_not_at_p1-5)))
    (:action invariant-396
        :effect (when (and (not (K_at_p1-4)) (K_at_p1-5)) (K_not_at_p1-4)))
    (:action invariant-397
        :effect (when (and (not (K_at_p1-6)) (K_at_p1-1)) (K_not_at_p1-6)))
    (:action invariant-398
        :effect (when (and (not (K_at_p1-1)) (K_at_p1-6)) (K_not_at_p1-1)))
    (:action invariant-399
        :effect (when (and (not (K_at_p1-6)) (K_at_p1-2)) (K_not_at_p1-6)))
    (:action invariant-400
        :effect (when (and (not (K_at_p1-2)) (K_at_p1-6)) (K_not_at_p1-2)))
    (:action invariant-401
        :effect (when (and (not (K_at_p1-6)) (K_at_p1-3)) (K_not_at_p1-6)))
    (:action invariant-402
        :effect (when (and (not (K_at_p1-3)) (K_at_p1-6)) (K_not_at_p1-3)))
    (:action invariant-403
        :effect (when (and (not (K_at_p1-6)) (K_at_p1-4)) (K_not_at_p1-6)))
    (:action invariant-404
        :effect (when (and (not (K_at_p1-4)) (K_at_p1-6)) (K_not_at_p1-4)))
    (:action invariant-405
        :effect (when (and (not (K_at_p1-6)) (K_at_p1-5)) (K_not_at_p1-6)))
    (:action invariant-406
        :effect (when (and (not (K_at_p1-5)) (K_at_p1-6)) (K_not_at_p1-5)))
    (:action invariant-407
        :effect (when (and (not (K_at_p1-7)) (K_at_p1-1)) (K_not_at_p1-7)))
    (:action invariant-408
        :effect (when (and (not (K_at_p1-1)) (K_at_p1-7)) (K_not_at_p1-1)))
    (:action invariant-409
        :effect (when (and (not (K_at_p1-7)) (K_at_p1-2)) (K_not_at_p1-7)))
    (:action invariant-410
        :effect (when (and (not (K_at_p1-2)) (K_at_p1-7)) (K_not_at_p1-2)))
    (:action invariant-411
        :effect (when (and (not (K_wumpus-at_p3-4)) (K_not_stench_p2-4)) (K_not_wumpus-at_p3-4)))
    (:action invariant-412
        :effect (when (and (not (K_not_stench_p2-4)) (K_wumpus-at_p3-4)) (K_stench_p2-4)))
    (:action invariant-413
        :effect (when (and (not (K_at_p1-7)) (K_at_p1-3)) (K_not_at_p1-7)))
    (:action invariant-414
        :effect (when (and (not (K_at_p1-3)) (K_at_p1-7)) (K_not_at_p1-3)))
    (:action invariant-415
        :effect (when (and (not (K_wumpus-at_p2-3)) (K_not_stench_p2-4)) (K_not_wumpus-at_p2-3)))
    (:action invariant-416
        :effect (when (and (not (K_not_stench_p2-4)) (K_wumpus-at_p2-3)) (K_stench_p2-4)))
    (:action invariant-417
        :effect (when (and (not (K_at_p1-7)) (K_at_p1-4)) (K_not_at_p1-7)))
    (:action invariant-418
        :effect (when (and (not (K_at_p1-4)) (K_at_p1-7)) (K_not_at_p1-4)))
    (:action invariant-419
        :effect (when (and (not (K_not_wumpus-at_p3-4)) (K_not_wumpus-at_p2-3) (K_stench_p2-4)) (K_wumpus-at_p3-4)))
    (:action invariant-420
        :effect (when (and (not (K_stench_p2-4)) (K_not_wumpus-at_p3-4) (K_not_wumpus-at_p2-3)) (K_not_stench_p2-4)))
    (:action invariant-421
        :effect (when (and (not (K_not_wumpus-at_p2-3)) (K_not_wumpus-at_p3-4) (K_stench_p2-4)) (K_wumpus-at_p2-3)))
    (:action invariant-422
        :effect (when (and (not (K_at_p1-7)) (K_at_p1-5)) (K_not_at_p1-7)))
    (:action invariant-423
        :effect (when (and (not (K_at_p1-5)) (K_at_p1-7)) (K_not_at_p1-5)))
    (:action invariant-424
        :effect (when (and (not (K_at_p1-7)) (K_at_p1-6)) (K_not_at_p1-7)))
    (:action invariant-425
        :effect (when (and (not (K_at_p1-6)) (K_at_p1-7)) (K_not_at_p1-6)))
    (:action invariant-426
        :effect (when (and (not (K_at_p2-1)) (K_at_p1-1)) (K_not_at_p2-1)))
    (:action invariant-427
        :effect (when (and (not (K_at_p1-1)) (K_at_p2-1)) (K_not_at_p1-1)))
    (:action invariant-428
        :effect (when (and (not (K_at_p2-1)) (K_at_p1-2)) (K_not_at_p2-1)))
    (:action invariant-429
        :effect (when (and (not (K_at_p1-2)) (K_at_p2-1)) (K_not_at_p1-2)))
    (:action invariant-430
        :effect (when (and (not (K_at_p2-1)) (K_at_p1-3)) (K_not_at_p2-1)))
    (:action invariant-431
        :effect (when (and (not (K_at_p1-3)) (K_at_p2-1)) (K_not_at_p1-3)))
    (:action invariant-432
        :effect (when (and (not (K_wumpus-at_p3-2)) (K_not_stench_p2-2)) (K_not_wumpus-at_p3-2)))
    (:action invariant-433
        :effect (when (and (not (K_not_stench_p2-2)) (K_wumpus-at_p3-2)) (K_stench_p2-2)))
    (:action invariant-434
        :effect (when (and (not (K_wumpus-at_p2-3)) (K_not_stench_p2-2)) (K_not_wumpus-at_p2-3)))
    (:action invariant-435
        :effect (when (and (not (K_not_stench_p2-2)) (K_wumpus-at_p2-3)) (K_stench_p2-2)))
    (:action invariant-436
        :effect (when (and (not (K_at_p2-1)) (K_at_p1-4)) (K_not_at_p2-1)))
    (:action invariant-437
        :effect (when (and (not (K_at_p1-4)) (K_at_p2-1)) (K_not_at_p1-4)))
    (:action invariant-438
        :effect (when (and (not (K_at_p2-1)) (K_at_p1-5)) (K_not_at_p2-1)))
    (:action invariant-439
        :effect (when (and (not (K_at_p1-5)) (K_at_p2-1)) (K_not_at_p1-5)))
    (:action invariant-440
        :effect (when (and (not (K_not_wumpus-at_p3-2)) (K_not_wumpus-at_p2-3) (K_stench_p2-2)) (K_wumpus-at_p3-2)))
    (:action invariant-441
        :effect (when (and (not (K_not_wumpus-at_p2-3)) (K_not_wumpus-at_p3-2) (K_stench_p2-2)) (K_wumpus-at_p2-3)))
    (:action invariant-442
        :effect (when (and (not (K_stench_p2-2)) (K_not_wumpus-at_p3-2) (K_not_wumpus-at_p2-3)) (K_not_stench_p2-2)))
    (:action invariant-443
        :effect (when (and (not (K_at_p2-1)) (K_at_p1-6)) (K_not_at_p2-1)))
    (:action invariant-444
        :effect (when (and (not (K_at_p1-6)) (K_at_p2-1)) (K_not_at_p1-6)))
    (:action invariant-445
        :effect (when (and (not (K_at_p2-1)) (K_at_p1-7)) (K_not_at_p2-1)))
    (:action invariant-446
        :effect (when (and (not (K_at_p1-7)) (K_at_p2-1)) (K_not_at_p1-7)))
    (:action invariant-447
        :effect (when (and (not (K_at_p2-2)) (K_at_p1-1)) (K_not_at_p2-2)))
    (:action invariant-448
        :effect (when (and (not (K_at_p1-1)) (K_at_p2-2)) (K_not_at_p1-1)))
    (:action invariant-449
        :effect (when (and (not (K_at_p2-2)) (K_at_p1-2)) (K_not_at_p2-2)))
    (:action invariant-450
        :effect (when (and (not (K_at_p1-2)) (K_at_p2-2)) (K_not_at_p1-2)))
    (:action invariant-451
        :effect (when (and (not (K_at_p2-2)) (K_at_p1-3)) (K_not_at_p2-2)))
    (:action invariant-452
        :effect (when (and (not (K_at_p1-3)) (K_at_p2-2)) (K_not_at_p1-3)))
    (:action invariant-453
        :effect (when (and (not (K_at_p2-2)) (K_at_p1-4)) (K_not_at_p2-2)))
    (:action invariant-454
        :effect (when (and (not (K_at_p1-4)) (K_at_p2-2)) (K_not_at_p1-4)))
    (:action invariant-455
        :effect (when (and (not (K_at_p2-2)) (K_at_p1-5)) (K_not_at_p2-2)))
    (:action invariant-456
        :effect (when (and (not (K_at_p1-5)) (K_at_p2-2)) (K_not_at_p1-5)))
    (:action invariant-457
        :effect (when (and (not (K_at_p2-2)) (K_at_p1-6)) (K_not_at_p2-2)))
    (:action invariant-458
        :effect (when (and (not (K_at_p1-6)) (K_at_p2-2)) (K_not_at_p1-6)))
    (:action invariant-459
        :effect (when (and (not (K_at_p2-2)) (K_at_p1-7)) (K_not_at_p2-2)))
    (:action invariant-460
        :effect (when (and (not (K_at_p1-7)) (K_at_p2-2)) (K_not_at_p1-7)))
    (:action invariant-461
        :effect (when (and (not (K_at_p2-2)) (K_at_p2-1)) (K_not_at_p2-2)))
    (:action invariant-462
        :effect (when (and (not (K_at_p2-1)) (K_at_p2-2)) (K_not_at_p2-1)))
    (:action invariant-463
        :effect (when (and (not (K_at_p2-3)) (K_at_p1-1)) (K_not_at_p2-3)))
    (:action invariant-464
        :effect (when (and (not (K_at_p1-1)) (K_at_p2-3)) (K_not_at_p1-1)))
    (:action invariant-465
        :effect (when (and (not (K_at_p2-3)) (K_at_p1-2)) (K_not_at_p2-3)))
    (:action invariant-466
        :effect (when (and (not (K_at_p1-2)) (K_at_p2-3)) (K_not_at_p1-2)))
    (:action invariant-467
        :effect (when (and (not (K_at_p2-3)) (K_at_p1-3)) (K_not_at_p2-3)))
    (:action invariant-468
        :effect (when (and (not (K_at_p1-3)) (K_at_p2-3)) (K_not_at_p1-3)))
    (:action invariant-469
        :effect (when (and (not (K_at_p2-3)) (K_at_p1-4)) (K_not_at_p2-3)))
    (:action invariant-470
        :effect (when (and (not (K_at_p1-4)) (K_at_p2-3)) (K_not_at_p1-4)))
    (:action invariant-471
        :effect (when (and (not (K_at_p2-3)) (K_at_p1-5)) (K_not_at_p2-3)))
    (:action invariant-472
        :effect (when (and (not (K_at_p1-5)) (K_at_p2-3)) (K_not_at_p1-5)))
    (:action invariant-473
        :effect (when (and (not (K_at_p2-3)) (K_at_p1-6)) (K_not_at_p2-3)))
    (:action invariant-474
        :effect (when (and (not (K_at_p1-6)) (K_at_p2-3)) (K_not_at_p1-6)))
    (:action invariant-475
        :effect (when (and (not (K_at_p2-3)) (K_at_p1-7)) (K_not_at_p2-3)))
    (:action invariant-476
        :effect (when (and (not (K_at_p1-7)) (K_at_p2-3)) (K_not_at_p1-7)))
    (:action invariant-477
        :effect (when (and (not (K_at_p2-3)) (K_at_p2-1)) (K_not_at_p2-3)))
    (:action invariant-478
        :effect (when (and (not (K_at_p2-1)) (K_at_p2-3)) (K_not_at_p2-1)))
    (:action invariant-479
        :effect (when (and (not (K_at_p2-3)) (K_at_p2-2)) (K_not_at_p2-3)))
    (:action invariant-480
        :effect (when (and (not (K_at_p2-2)) (K_at_p2-3)) (K_not_at_p2-2)))
    (:action invariant-481
        :effect (when (and (not (K_wumpus-at_p2-3)) (K_not_stench_p1-3)) (K_not_wumpus-at_p2-3)))
    (:action invariant-482
        :effect (when (and (not (K_not_stench_p1-3)) (K_wumpus-at_p2-3)) (K_stench_p1-3)))
    (:action invariant-483
        :effect (when (and (not (K_at_p2-4)) (K_at_p1-1)) (K_not_at_p2-4)))
    (:action invariant-484
        :effect (when (and (not (K_at_p1-1)) (K_at_p2-4)) (K_not_at_p1-1)))
    (:action invariant-485
        :effect (when (and (not (K_at_p2-4)) (K_at_p1-2)) (K_not_at_p2-4)))
    (:action invariant-486
        :effect (when (and (not (K_at_p1-2)) (K_at_p2-4)) (K_not_at_p1-2)))
    (:action invariant-487
        :effect (when (and (not (K_not_wumpus-at_p2-3)) (K_stench_p1-3)) (K_wumpus-at_p2-3)))
    (:action invariant-488
        :effect (when (and (not (K_stench_p1-3)) (K_not_wumpus-at_p2-3)) (K_not_stench_p1-3)))
    (:action invariant-489
        :effect (when (and (not (K_at_p2-4)) (K_at_p1-3)) (K_not_at_p2-4)))
    (:action invariant-490
        :effect (when (and (not (K_at_p1-3)) (K_at_p2-4)) (K_not_at_p1-3)))
    (:action invariant-491
        :effect (when (and (not (K_at_p2-4)) (K_at_p1-4)) (K_not_at_p2-4)))
    (:action invariant-492
        :effect (when (and (not (K_at_p1-4)) (K_at_p2-4)) (K_not_at_p1-4)))
    (:action invariant-493
        :effect (when (and (not (K_at_p2-4)) (K_at_p1-5)) (K_not_at_p2-4)))
    (:action invariant-494
        :effect (when (and (not (K_at_p1-5)) (K_at_p2-4)) (K_not_at_p1-5)))
    (:action invariant-495
        :effect (when (and (not (K_at_p2-4)) (K_at_p1-6)) (K_not_at_p2-4)))
    (:action invariant-496
        :effect (when (and (not (K_at_p1-6)) (K_at_p2-4)) (K_not_at_p1-6)))
    (:action invariant-497
        :effect (when (and (not (K_at_p2-4)) (K_at_p1-7)) (K_not_at_p2-4)))
    (:action invariant-498
        :effect (when (and (not (K_at_p1-7)) (K_at_p2-4)) (K_not_at_p1-7)))
    (:action invariant-499
        :effect (when (and (not (K_at_p2-4)) (K_at_p2-1)) (K_not_at_p2-4)))
    (:action invariant-500
        :effect (when (and (not (K_at_p2-1)) (K_at_p2-4)) (K_not_at_p2-1)))
    (:action invariant-501
        :effect (when (and (not (K_at_p2-4)) (K_at_p2-2)) (K_not_at_p2-4)))
    (:action invariant-502
        :effect (when (and (not (K_at_p2-2)) (K_at_p2-4)) (K_not_at_p2-2)))
    (:action invariant-503
        :effect (when (and (not (K_at_p7-7)) (K_at_p7-6)) (K_not_at_p7-7)))
    (:action invariant-504
        :effect (when (and (not (K_at_p7-6)) (K_at_p7-7)) (K_not_at_p7-6)))
    (:action invariant-505
        :effect (when (and (not (K_at_p7-7)) (K_at_p7-5)) (K_not_at_p7-7)))
    (:action invariant-506
        :effect (when (and (not (K_at_p7-5)) (K_at_p7-7)) (K_not_at_p7-5)))
    (:action invariant-507
        :effect (when (and (not (K_at_p7-7)) (K_at_p7-4)) (K_not_at_p7-7)))
    (:action invariant-508
        :effect (when (and (not (K_at_p7-4)) (K_at_p7-7)) (K_not_at_p7-4)))
    (:action invariant-509
        :effect (when (and (not (K_at_p7-7)) (K_at_p7-3)) (K_not_at_p7-7)))
    (:action invariant-510
        :effect (when (and (not (K_at_p7-3)) (K_at_p7-7)) (K_not_at_p7-3)))
    (:action invariant-511
        :effect (when (and (not (K_at_p7-7)) (K_at_p7-2)) (K_not_at_p7-7)))
    (:action invariant-512
        :effect (when (and (not (K_at_p7-2)) (K_at_p7-7)) (K_not_at_p7-2)))
    (:action invariant-513
        :effect (when (and (not (K_at_p7-7)) (K_at_p7-1)) (K_not_at_p7-7)))
    (:action invariant-514
        :effect (when (and (not (K_at_p7-1)) (K_at_p7-7)) (K_not_at_p7-1)))
    (:action invariant-515
        :effect (when (and (not (K_at_p7-7)) (K_at_p6-7)) (K_not_at_p7-7)))
    (:action invariant-516
        :effect (when (and (not (K_at_p6-7)) (K_at_p7-7)) (K_not_at_p6-7)))
    (:action invariant-517
        :effect (when (and (not (K_at_p7-7)) (K_at_p6-6)) (K_not_at_p7-7)))
    (:action invariant-518
        :effect (when (and (not (K_at_p6-6)) (K_at_p7-7)) (K_not_at_p6-6)))
    (:action invariant-519
        :effect (when (and (not (K_at_p7-7)) (K_at_p6-5)) (K_not_at_p7-7)))
    (:action invariant-520
        :effect (when (and (not (K_at_p6-5)) (K_at_p7-7)) (K_not_at_p6-5)))
    (:action invariant-521
        :effect (when (and (not (K_at_p7-7)) (K_at_p6-4)) (K_not_at_p7-7)))
    (:action invariant-522
        :effect (when (and (not (K_at_p6-4)) (K_at_p7-7)) (K_not_at_p6-4)))
    (:action invariant-523
        :effect (when (and (not (K_at_p7-7)) (K_at_p6-3)) (K_not_at_p7-7)))
    (:action invariant-524
        :effect (when (and (not (K_at_p6-3)) (K_at_p7-7)) (K_not_at_p6-3)))
    (:action invariant-525
        :effect (when (and (not (K_at_p7-7)) (K_at_p6-2)) (K_not_at_p7-7)))
    (:action invariant-526
        :effect (when (and (not (K_at_p6-2)) (K_at_p7-7)) (K_not_at_p6-2)))
    (:action invariant-527
        :effect (when (and (not (K_at_p7-7)) (K_at_p6-1)) (K_not_at_p7-7)))
    (:action invariant-528
        :effect (when (and (not (K_at_p6-1)) (K_at_p7-7)) (K_not_at_p6-1)))
    (:action invariant-529
        :effect (when (and (not (K_at_p7-7)) (K_at_p5-7)) (K_not_at_p7-7)))
    (:action invariant-530
        :effect (when (and (not (K_at_p5-7)) (K_at_p7-7)) (K_not_at_p5-7)))
    (:action invariant-531
        :effect (when (and (not (K_at_p7-7)) (K_at_p5-6)) (K_not_at_p7-7)))
    (:action invariant-532
        :effect (when (and (not (K_at_p5-6)) (K_at_p7-7)) (K_not_at_p5-6)))
    (:action invariant-533
        :effect (when (and (not (K_at_p7-7)) (K_at_p5-5)) (K_not_at_p7-7)))
    (:action invariant-534
        :effect (when (and (not (K_at_p5-5)) (K_at_p7-7)) (K_not_at_p5-5)))
    (:action invariant-535
        :effect (when (and (not (K_at_p7-7)) (K_at_p5-4)) (K_not_at_p7-7)))
    (:action invariant-536
        :effect (when (and (not (K_at_p5-4)) (K_at_p7-7)) (K_not_at_p5-4)))
    (:action invariant-537
        :effect (when (and (not (K_at_p7-7)) (K_at_p5-3)) (K_not_at_p7-7)))
    (:action invariant-538
        :effect (when (and (not (K_at_p5-3)) (K_at_p7-7)) (K_not_at_p5-3)))
    (:action invariant-539
        :effect (when (and (not (K_at_p7-7)) (K_at_p5-2)) (K_not_at_p7-7)))
    (:action invariant-540
        :effect (when (and (not (K_at_p5-2)) (K_at_p7-7)) (K_not_at_p5-2)))
    (:action invariant-541
        :effect (when (and (not (K_at_p7-7)) (K_at_p5-1)) (K_not_at_p7-7)))
    (:action invariant-542
        :effect (when (and (not (K_at_p5-1)) (K_at_p7-7)) (K_not_at_p5-1)))
    (:action invariant-543
        :effect (when (and (not (K_at_p7-7)) (K_at_p4-7)) (K_not_at_p7-7)))
    (:action invariant-544
        :effect (when (and (not (K_at_p4-7)) (K_at_p7-7)) (K_not_at_p4-7)))
    (:action invariant-545
        :effect (when (and (not (K_at_p7-7)) (K_at_p4-6)) (K_not_at_p7-7)))
    (:action invariant-546
        :effect (when (and (not (K_at_p4-6)) (K_at_p7-7)) (K_not_at_p4-6)))
    (:action invariant-547
        :effect (when (and (not (K_at_p7-7)) (K_at_p4-5)) (K_not_at_p7-7)))
    (:action invariant-548
        :effect (when (and (not (K_at_p4-5)) (K_at_p7-7)) (K_not_at_p4-5)))
    (:action invariant-549
        :effect (when (and (not (K_at_p7-7)) (K_at_p4-4)) (K_not_at_p7-7)))
    (:action invariant-550
        :effect (when (and (not (K_at_p4-4)) (K_at_p7-7)) (K_not_at_p4-4)))
    (:action invariant-551
        :effect (when (and (not (K_at_p7-7)) (K_at_p4-3)) (K_not_at_p7-7)))
    (:action invariant-552
        :effect (when (and (not (K_at_p4-3)) (K_at_p7-7)) (K_not_at_p4-3)))
    (:action invariant-553
        :effect (when (and (not (K_at_p7-7)) (K_at_p4-2)) (K_not_at_p7-7)))
    (:action invariant-554
        :effect (when (and (not (K_at_p4-2)) (K_at_p7-7)) (K_not_at_p4-2)))
    (:action invariant-555
        :effect (when (and (not (K_at_p7-7)) (K_at_p4-1)) (K_not_at_p7-7)))
    (:action invariant-556
        :effect (when (and (not (K_at_p4-1)) (K_at_p7-7)) (K_not_at_p4-1)))
    (:action invariant-557
        :effect (when (and (not (K_at_p7-7)) (K_at_p3-7)) (K_not_at_p7-7)))
    (:action invariant-558
        :effect (when (and (not (K_at_p3-7)) (K_at_p7-7)) (K_not_at_p3-7)))
    (:action invariant-559
        :effect (when (and (not (K_at_p7-7)) (K_at_p3-6)) (K_not_at_p7-7)))
    (:action invariant-560
        :effect (when (and (not (K_at_p3-6)) (K_at_p7-7)) (K_not_at_p3-6)))
    (:action invariant-561
        :effect (when (and (not (K_at_p7-7)) (K_at_p3-5)) (K_not_at_p7-7)))
    (:action invariant-562
        :effect (when (and (not (K_at_p3-5)) (K_at_p7-7)) (K_not_at_p3-5)))
    (:action invariant-563
        :effect (when (and (not (K_at_p7-7)) (K_at_p3-4)) (K_not_at_p7-7)))
    (:action invariant-564
        :effect (when (and (not (K_at_p3-4)) (K_at_p7-7)) (K_not_at_p3-4)))
    (:action invariant-565
        :effect (when (and (not (K_at_p7-7)) (K_at_p3-3)) (K_not_at_p7-7)))
    (:action invariant-566
        :effect (when (and (not (K_at_p3-3)) (K_at_p7-7)) (K_not_at_p3-3)))
    (:action invariant-567
        :effect (when (and (not (K_at_p7-7)) (K_at_p3-2)) (K_not_at_p7-7)))
    (:action invariant-568
        :effect (when (and (not (K_at_p3-2)) (K_at_p7-7)) (K_not_at_p3-2)))
    (:action invariant-569
        :effect (when (and (not (K_at_p7-7)) (K_at_p3-1)) (K_not_at_p7-7)))
    (:action invariant-570
        :effect (when (and (not (K_at_p3-1)) (K_at_p7-7)) (K_not_at_p3-1)))
    (:action invariant-571
        :effect (when (and (not (K_at_p7-7)) (K_at_p2-7)) (K_not_at_p7-7)))
    (:action invariant-572
        :effect (when (and (not (K_at_p2-7)) (K_at_p7-7)) (K_not_at_p2-7)))
    (:action invariant-573
        :effect (when (and (not (K_at_p7-7)) (K_at_p2-6)) (K_not_at_p7-7)))
    (:action invariant-574
        :effect (when (and (not (K_at_p2-6)) (K_at_p7-7)) (K_not_at_p2-6)))
    (:action invariant-575
        :effect (when (and (not (K_at_p7-7)) (K_at_p2-5)) (K_not_at_p7-7)))
    (:action invariant-576
        :effect (when (and (not (K_at_p2-5)) (K_at_p7-7)) (K_not_at_p2-5)))
    (:action invariant-577
        :effect (when (and (not (K_at_p7-7)) (K_at_p2-4)) (K_not_at_p7-7)))
    (:action invariant-578
        :effect (when (and (not (K_at_p2-4)) (K_at_p7-7)) (K_not_at_p2-4)))
    (:action invariant-579
        :effect (when (and (not (K_at_p7-7)) (K_at_p2-3)) (K_not_at_p7-7)))
    (:action invariant-580
        :effect (when (and (not (K_at_p2-3)) (K_at_p7-7)) (K_not_at_p2-3)))
    (:action invariant-581
        :effect (when (and (not (K_at_p7-7)) (K_at_p2-2)) (K_not_at_p7-7)))
    (:action invariant-582
        :effect (when (and (not (K_at_p2-2)) (K_at_p7-7)) (K_not_at_p2-2)))
    (:action invariant-583
        :effect (when (and (not (K_at_p7-7)) (K_at_p2-1)) (K_not_at_p7-7)))
    (:action invariant-584
        :effect (when (and (not (K_at_p2-1)) (K_at_p7-7)) (K_not_at_p2-1)))
    (:action invariant-585
        :effect (when (and (not (K_at_p7-7)) (K_at_p1-7)) (K_not_at_p7-7)))
    (:action invariant-586
        :effect (when (and (not (K_at_p1-7)) (K_at_p7-7)) (K_not_at_p1-7)))
    (:action invariant-587
        :effect (when (and (not (K_at_p7-7)) (K_at_p1-6)) (K_not_at_p7-7)))
    (:action invariant-588
        :effect (when (and (not (K_at_p1-6)) (K_at_p7-7)) (K_not_at_p1-6)))
    (:action invariant-589
        :effect (when (and (not (K_at_p7-7)) (K_at_p1-5)) (K_not_at_p7-7)))
    (:action invariant-590
        :effect (when (and (not (K_at_p1-5)) (K_at_p7-7)) (K_not_at_p1-5)))
    (:action invariant-591
        :effect (when (and (not (K_at_p7-7)) (K_at_p1-4)) (K_not_at_p7-7)))
    (:action invariant-592
        :effect (when (and (not (K_at_p1-4)) (K_at_p7-7)) (K_not_at_p1-4)))
    (:action invariant-593
        :effect (when (and (not (K_at_p7-7)) (K_at_p1-3)) (K_not_at_p7-7)))
    (:action invariant-594
        :effect (when (and (not (K_at_p1-3)) (K_at_p7-7)) (K_not_at_p1-3)))
    (:action invariant-595
        :effect (when (and (not (K_at_p7-7)) (K_at_p1-2)) (K_not_at_p7-7)))
    (:action invariant-596
        :effect (when (and (not (K_at_p1-2)) (K_at_p7-7)) (K_not_at_p1-2)))
    (:action invariant-597
        :effect (when (and (not (K_at_p7-7)) (K_at_p1-1)) (K_not_at_p7-7)))
    (:action invariant-598
        :effect (when (and (not (K_at_p1-1)) (K_at_p7-7)) (K_not_at_p1-1)))
    (:action invariant-599
        :effect (when (and (not (K_at_p7-6)) (K_at_p7-5)) (K_not_at_p7-6)))
    (:action invariant-600
        :effect (when (and (not (K_at_p7-5)) (K_at_p7-6)) (K_not_at_p7-5)))
    (:action invariant-601
        :effect (when (and (not (K_at_p7-6)) (K_at_p7-4)) (K_not_at_p7-6)))
    (:action invariant-602
        :effect (when (and (not (K_at_p7-4)) (K_at_p7-6)) (K_not_at_p7-4)))
    (:action invariant-603
        :effect (when (and (not (K_at_p7-6)) (K_at_p7-3)) (K_not_at_p7-6)))
    (:action invariant-604
        :effect (when (and (not (K_at_p7-3)) (K_at_p7-6)) (K_not_at_p7-3)))
    (:action invariant-605
        :effect (when (and (not (K_at_p7-6)) (K_at_p7-2)) (K_not_at_p7-6)))
    (:action invariant-606
        :effect (when (and (not (K_at_p7-2)) (K_at_p7-6)) (K_not_at_p7-2)))
    (:action invariant-607
        :effect (when (and (not (K_at_p7-6)) (K_at_p7-1)) (K_not_at_p7-6)))
    (:action invariant-608
        :effect (when (and (not (K_at_p7-1)) (K_at_p7-6)) (K_not_at_p7-1)))
    (:action invariant-609
        :effect (when (and (not (K_at_p7-6)) (K_at_p6-7)) (K_not_at_p7-6)))
    (:action invariant-610
        :effect (when (and (not (K_at_p6-7)) (K_at_p7-6)) (K_not_at_p6-7)))
    (:action invariant-611
        :effect (when (and (not (K_at_p7-6)) (K_at_p6-6)) (K_not_at_p7-6)))
    (:action invariant-612
        :effect (when (and (not (K_at_p6-6)) (K_at_p7-6)) (K_not_at_p6-6)))
    (:action invariant-613
        :effect (when (and (not (K_at_p7-6)) (K_at_p6-5)) (K_not_at_p7-6)))
    (:action invariant-614
        :effect (when (and (not (K_at_p6-5)) (K_at_p7-6)) (K_not_at_p6-5)))
    (:action invariant-615
        :effect (when (and (not (K_at_p7-6)) (K_at_p6-4)) (K_not_at_p7-6)))
    (:action invariant-616
        :effect (when (and (not (K_at_p6-4)) (K_at_p7-6)) (K_not_at_p6-4)))
    (:action invariant-617
        :effect (when (and (not (K_at_p7-6)) (K_at_p6-3)) (K_not_at_p7-6)))
    (:action invariant-618
        :effect (when (and (not (K_at_p6-3)) (K_at_p7-6)) (K_not_at_p6-3)))
    (:action invariant-619
        :effect (when (and (not (K_at_p7-6)) (K_at_p6-2)) (K_not_at_p7-6)))
    (:action invariant-620
        :effect (when (and (not (K_at_p6-2)) (K_at_p7-6)) (K_not_at_p6-2)))
    (:action invariant-621
        :effect (when (and (not (K_at_p7-6)) (K_at_p6-1)) (K_not_at_p7-6)))
    (:action invariant-622
        :effect (when (and (not (K_at_p6-1)) (K_at_p7-6)) (K_not_at_p6-1)))
    (:action invariant-623
        :effect (when (and (not (K_at_p7-6)) (K_at_p5-7)) (K_not_at_p7-6)))
    (:action invariant-624
        :effect (when (and (not (K_at_p5-7)) (K_at_p7-6)) (K_not_at_p5-7)))
    (:action invariant-625
        :effect (when (and (not (K_at_p7-6)) (K_at_p5-6)) (K_not_at_p7-6)))
    (:action invariant-626
        :effect (when (and (not (K_at_p5-6)) (K_at_p7-6)) (K_not_at_p5-6)))
    (:action invariant-627
        :effect (when (and (not (K_at_p7-6)) (K_at_p5-5)) (K_not_at_p7-6)))
    (:action invariant-628
        :effect (when (and (not (K_at_p5-5)) (K_at_p7-6)) (K_not_at_p5-5)))
    (:action invariant-629
        :effect (when (and (not (K_at_p7-6)) (K_at_p5-4)) (K_not_at_p7-6)))
    (:action invariant-630
        :effect (when (and (not (K_at_p5-4)) (K_at_p7-6)) (K_not_at_p5-4)))
    (:action invariant-631
        :effect (when (and (not (K_at_p7-6)) (K_at_p5-3)) (K_not_at_p7-6)))
    (:action invariant-632
        :effect (when (and (not (K_at_p5-3)) (K_at_p7-6)) (K_not_at_p5-3)))
    (:action invariant-633
        :effect (when (and (not (K_at_p7-6)) (K_at_p5-2)) (K_not_at_p7-6)))
    (:action invariant-634
        :effect (when (and (not (K_at_p5-2)) (K_at_p7-6)) (K_not_at_p5-2)))
    (:action invariant-635
        :effect (when (and (not (K_at_p7-6)) (K_at_p5-1)) (K_not_at_p7-6)))
    (:action invariant-636
        :effect (when (and (not (K_at_p5-1)) (K_at_p7-6)) (K_not_at_p5-1)))
    (:action invariant-637
        :effect (when (and (not (K_at_p7-6)) (K_at_p4-7)) (K_not_at_p7-6)))
    (:action invariant-638
        :effect (when (and (not (K_at_p4-7)) (K_at_p7-6)) (K_not_at_p4-7)))
    (:action invariant-639
        :effect (when (and (not (K_at_p7-6)) (K_at_p4-6)) (K_not_at_p7-6)))
    (:action invariant-640
        :effect (when (and (not (K_at_p4-6)) (K_at_p7-6)) (K_not_at_p4-6)))
    (:action invariant-641
        :effect (when (and (not (K_at_p7-6)) (K_at_p4-5)) (K_not_at_p7-6)))
    (:action invariant-642
        :effect (when (and (not (K_at_p4-5)) (K_at_p7-6)) (K_not_at_p4-5)))
    (:action invariant-643
        :effect (when (and (not (K_at_p7-6)) (K_at_p4-4)) (K_not_at_p7-6)))
    (:action invariant-644
        :effect (when (and (not (K_at_p4-4)) (K_at_p7-6)) (K_not_at_p4-4)))
    (:action invariant-645
        :effect (when (and (not (K_at_p7-6)) (K_at_p4-3)) (K_not_at_p7-6)))
    (:action invariant-646
        :effect (when (and (not (K_at_p4-3)) (K_at_p7-6)) (K_not_at_p4-3)))
    (:action invariant-647
        :effect (when (and (not (K_at_p7-6)) (K_at_p4-2)) (K_not_at_p7-6)))
    (:action invariant-648
        :effect (when (and (not (K_at_p4-2)) (K_at_p7-6)) (K_not_at_p4-2)))
    (:action invariant-649
        :effect (when (and (not (K_at_p7-6)) (K_at_p4-1)) (K_not_at_p7-6)))
    (:action invariant-650
        :effect (when (and (not (K_at_p4-1)) (K_at_p7-6)) (K_not_at_p4-1)))
    (:action invariant-651
        :effect (when (and (not (K_at_p7-6)) (K_at_p3-7)) (K_not_at_p7-6)))
    (:action invariant-652
        :effect (when (and (not (K_at_p3-7)) (K_at_p7-6)) (K_not_at_p3-7)))
    (:action invariant-653
        :effect (when (and (not (K_at_p7-6)) (K_at_p3-6)) (K_not_at_p7-6)))
    (:action invariant-654
        :effect (when (and (not (K_at_p3-6)) (K_at_p7-6)) (K_not_at_p3-6)))
    (:action invariant-655
        :effect (when (and (not (K_at_p7-6)) (K_at_p3-5)) (K_not_at_p7-6)))
    (:action invariant-656
        :effect (when (and (not (K_at_p3-5)) (K_at_p7-6)) (K_not_at_p3-5)))
    (:action invariant-657
        :effect (when (and (not (K_at_p7-6)) (K_at_p3-4)) (K_not_at_p7-6)))
    (:action invariant-658
        :effect (when (and (not (K_at_p3-4)) (K_at_p7-6)) (K_not_at_p3-4)))
    (:action invariant-659
        :effect (when (and (not (K_at_p7-6)) (K_at_p3-3)) (K_not_at_p7-6)))
    (:action invariant-660
        :effect (when (and (not (K_at_p3-3)) (K_at_p7-6)) (K_not_at_p3-3)))
    (:action invariant-661
        :effect (when (and (not (K_at_p7-6)) (K_at_p3-2)) (K_not_at_p7-6)))
    (:action invariant-662
        :effect (when (and (not (K_at_p3-2)) (K_at_p7-6)) (K_not_at_p3-2)))
    (:action invariant-663
        :effect (when (and (not (K_at_p7-6)) (K_at_p3-1)) (K_not_at_p7-6)))
    (:action invariant-664
        :effect (when (and (not (K_at_p3-1)) (K_at_p7-6)) (K_not_at_p3-1)))
    (:action invariant-665
        :effect (when (and (not (K_at_p7-6)) (K_at_p2-7)) (K_not_at_p7-6)))
    (:action invariant-666
        :effect (when (and (not (K_at_p2-7)) (K_at_p7-6)) (K_not_at_p2-7)))
    (:action invariant-667
        :effect (when (and (not (K_at_p7-6)) (K_at_p2-6)) (K_not_at_p7-6)))
    (:action invariant-668
        :effect (when (and (not (K_at_p2-6)) (K_at_p7-6)) (K_not_at_p2-6)))
    (:action invariant-669
        :effect (when (and (not (K_at_p7-6)) (K_at_p2-5)) (K_not_at_p7-6)))
    (:action invariant-670
        :effect (when (and (not (K_at_p2-5)) (K_at_p7-6)) (K_not_at_p2-5)))
    (:action invariant-671
        :effect (when (and (not (K_at_p7-6)) (K_at_p2-4)) (K_not_at_p7-6)))
    (:action invariant-672
        :effect (when (and (not (K_at_p2-4)) (K_at_p7-6)) (K_not_at_p2-4)))
    (:action invariant-673
        :effect (when (and (not (K_at_p7-6)) (K_at_p2-3)) (K_not_at_p7-6)))
    (:action invariant-674
        :effect (when (and (not (K_at_p2-3)) (K_at_p7-6)) (K_not_at_p2-3)))
    (:action invariant-675
        :effect (when (and (not (K_at_p7-6)) (K_at_p2-2)) (K_not_at_p7-6)))
    (:action invariant-676
        :effect (when (and (not (K_at_p2-2)) (K_at_p7-6)) (K_not_at_p2-2)))
    (:action invariant-677
        :effect (when (and (not (K_at_p7-6)) (K_at_p2-1)) (K_not_at_p7-6)))
    (:action invariant-678
        :effect (when (and (not (K_at_p2-1)) (K_at_p7-6)) (K_not_at_p2-1)))
    (:action invariant-679
        :effect (when (and (not (K_at_p7-6)) (K_at_p1-7)) (K_not_at_p7-6)))
    (:action invariant-680
        :effect (when (and (not (K_at_p1-7)) (K_at_p7-6)) (K_not_at_p1-7)))
    (:action invariant-681
        :effect (when (and (not (K_at_p7-6)) (K_at_p1-6)) (K_not_at_p7-6)))
    (:action invariant-682
        :effect (when (and (not (K_at_p1-6)) (K_at_p7-6)) (K_not_at_p1-6)))
    (:action invariant-683
        :effect (when (and (not (K_at_p7-6)) (K_at_p1-5)) (K_not_at_p7-6)))
    (:action invariant-684
        :effect (when (and (not (K_at_p1-5)) (K_at_p7-6)) (K_not_at_p1-5)))
    (:action invariant-685
        :effect (when (and (not (K_at_p7-6)) (K_at_p1-4)) (K_not_at_p7-6)))
    (:action invariant-686
        :effect (when (and (not (K_at_p1-4)) (K_at_p7-6)) (K_not_at_p1-4)))
    (:action invariant-687
        :effect (when (and (not (K_at_p7-6)) (K_at_p1-3)) (K_not_at_p7-6)))
    (:action invariant-688
        :effect (when (and (not (K_at_p1-3)) (K_at_p7-6)) (K_not_at_p1-3)))
    (:action invariant-689
        :effect (when (and (not (K_at_p7-6)) (K_at_p1-2)) (K_not_at_p7-6)))
    (:action invariant-690
        :effect (when (and (not (K_at_p1-2)) (K_at_p7-6)) (K_not_at_p1-2)))
    (:action invariant-691
        :effect (when (and (not (K_at_p7-6)) (K_at_p1-1)) (K_not_at_p7-6)))
    (:action invariant-692
        :effect (when (and (not (K_at_p1-1)) (K_at_p7-6)) (K_not_at_p1-1)))
    (:action invariant-693
        :effect (when (and (not (K_at_p7-5)) (K_at_p7-4)) (K_not_at_p7-5)))
    (:action invariant-694
        :effect (when (and (not (K_at_p7-4)) (K_at_p7-5)) (K_not_at_p7-4)))
    (:action invariant-695
        :effect (when (and (not (K_at_p7-5)) (K_at_p7-3)) (K_not_at_p7-5)))
    (:action invariant-696
        :effect (when (and (not (K_at_p7-3)) (K_at_p7-5)) (K_not_at_p7-3)))
    (:action invariant-697
        :effect (when (and (not (K_at_p7-5)) (K_at_p7-2)) (K_not_at_p7-5)))
    (:action invariant-698
        :effect (when (and (not (K_at_p7-2)) (K_at_p7-5)) (K_not_at_p7-2)))
    (:action invariant-699
        :effect (when (and (not (K_at_p7-5)) (K_at_p7-1)) (K_not_at_p7-5)))
    (:action invariant-700
        :effect (when (and (not (K_at_p7-1)) (K_at_p7-5)) (K_not_at_p7-1)))
    (:action invariant-701
        :effect (when (and (not (K_at_p7-5)) (K_at_p6-7)) (K_not_at_p7-5)))
    (:action invariant-702
        :effect (when (and (not (K_at_p6-7)) (K_at_p7-5)) (K_not_at_p6-7)))
    (:action invariant-703
        :effect (when (and (not (K_at_p7-5)) (K_at_p6-6)) (K_not_at_p7-5)))
    (:action invariant-704
        :effect (when (and (not (K_at_p6-6)) (K_at_p7-5)) (K_not_at_p6-6)))
    (:action invariant-705
        :effect (when (and (not (K_at_p7-5)) (K_at_p6-5)) (K_not_at_p7-5)))
    (:action invariant-706
        :effect (when (and (not (K_at_p6-5)) (K_at_p7-5)) (K_not_at_p6-5)))
    (:action invariant-707
        :effect (when (and (not (K_at_p7-5)) (K_at_p6-4)) (K_not_at_p7-5)))
    (:action invariant-708
        :effect (when (and (not (K_at_p6-4)) (K_at_p7-5)) (K_not_at_p6-4)))
    (:action invariant-709
        :effect (when (and (not (K_at_p7-5)) (K_at_p6-3)) (K_not_at_p7-5)))
    (:action invariant-710
        :effect (when (and (not (K_at_p6-3)) (K_at_p7-5)) (K_not_at_p6-3)))
    (:action invariant-711
        :effect (when (and (not (K_at_p7-5)) (K_at_p6-2)) (K_not_at_p7-5)))
    (:action invariant-712
        :effect (when (and (not (K_at_p6-2)) (K_at_p7-5)) (K_not_at_p6-2)))
    (:action invariant-713
        :effect (when (and (not (K_at_p7-5)) (K_at_p6-1)) (K_not_at_p7-5)))
    (:action invariant-714
        :effect (when (and (not (K_at_p6-1)) (K_at_p7-5)) (K_not_at_p6-1)))
    (:action invariant-715
        :effect (when (and (not (K_at_p7-5)) (K_at_p5-7)) (K_not_at_p7-5)))
    (:action invariant-716
        :effect (when (and (not (K_at_p5-7)) (K_at_p7-5)) (K_not_at_p5-7)))
    (:action invariant-717
        :effect (when (and (not (K_at_p7-5)) (K_at_p5-6)) (K_not_at_p7-5)))
    (:action invariant-718
        :effect (when (and (not (K_at_p5-6)) (K_at_p7-5)) (K_not_at_p5-6)))
    (:action invariant-719
        :effect (when (and (not (K_at_p7-5)) (K_at_p5-5)) (K_not_at_p7-5)))
    (:action invariant-720
        :effect (when (and (not (K_at_p5-5)) (K_at_p7-5)) (K_not_at_p5-5)))
    (:action invariant-721
        :effect (when (and (not (K_at_p7-5)) (K_at_p5-4)) (K_not_at_p7-5)))
    (:action invariant-722
        :effect (when (and (not (K_at_p5-4)) (K_at_p7-5)) (K_not_at_p5-4)))
    (:action invariant-723
        :effect (when (and (not (K_at_p7-5)) (K_at_p5-3)) (K_not_at_p7-5)))
    (:action invariant-724
        :effect (when (and (not (K_at_p5-3)) (K_at_p7-5)) (K_not_at_p5-3)))
    (:action invariant-725
        :effect (when (and (not (K_at_p7-5)) (K_at_p5-2)) (K_not_at_p7-5)))
    (:action invariant-726
        :effect (when (and (not (K_at_p5-2)) (K_at_p7-5)) (K_not_at_p5-2)))
    (:action invariant-727
        :effect (when (and (not (K_at_p7-5)) (K_at_p5-1)) (K_not_at_p7-5)))
    (:action invariant-728
        :effect (when (and (not (K_at_p5-1)) (K_at_p7-5)) (K_not_at_p5-1)))
    (:action invariant-729
        :effect (when (and (not (K_at_p7-5)) (K_at_p4-7)) (K_not_at_p7-5)))
    (:action invariant-730
        :effect (when (and (not (K_at_p4-7)) (K_at_p7-5)) (K_not_at_p4-7)))
    (:action invariant-731
        :effect (when (and (not (K_at_p7-5)) (K_at_p4-6)) (K_not_at_p7-5)))
    (:action invariant-732
        :effect (when (and (not (K_at_p4-6)) (K_at_p7-5)) (K_not_at_p4-6)))
    (:action invariant-733
        :effect (when (and (not (K_at_p7-5)) (K_at_p4-5)) (K_not_at_p7-5)))
    (:action invariant-734
        :effect (when (and (not (K_at_p4-5)) (K_at_p7-5)) (K_not_at_p4-5)))
    (:action invariant-735
        :effect (when (and (not (K_at_p7-5)) (K_at_p4-4)) (K_not_at_p7-5)))
    (:action invariant-736
        :effect (when (and (not (K_at_p4-4)) (K_at_p7-5)) (K_not_at_p4-4)))
    (:action invariant-737
        :effect (when (and (not (K_at_p7-5)) (K_at_p4-3)) (K_not_at_p7-5)))
    (:action invariant-738
        :effect (when (and (not (K_at_p4-3)) (K_at_p7-5)) (K_not_at_p4-3)))
    (:action invariant-739
        :effect (when (and (not (K_at_p7-5)) (K_at_p4-2)) (K_not_at_p7-5)))
    (:action invariant-740
        :effect (when (and (not (K_at_p4-2)) (K_at_p7-5)) (K_not_at_p4-2)))
    (:action invariant-741
        :effect (when (and (not (K_at_p7-5)) (K_at_p4-1)) (K_not_at_p7-5)))
    (:action invariant-742
        :effect (when (and (not (K_at_p4-1)) (K_at_p7-5)) (K_not_at_p4-1)))
    (:action invariant-743
        :effect (when (and (not (K_at_p7-5)) (K_at_p3-7)) (K_not_at_p7-5)))
    (:action invariant-744
        :effect (when (and (not (K_at_p3-7)) (K_at_p7-5)) (K_not_at_p3-7)))
    (:action invariant-745
        :effect (when (and (not (K_at_p7-5)) (K_at_p3-6)) (K_not_at_p7-5)))
    (:action invariant-746
        :effect (when (and (not (K_at_p3-6)) (K_at_p7-5)) (K_not_at_p3-6)))
    (:action invariant-747
        :effect (when (and (not (K_at_p7-5)) (K_at_p3-5)) (K_not_at_p7-5)))
    (:action invariant-748
        :effect (when (and (not (K_at_p3-5)) (K_at_p7-5)) (K_not_at_p3-5)))
    (:action invariant-749
        :effect (when (and (not (K_at_p7-5)) (K_at_p3-4)) (K_not_at_p7-5)))
    (:action invariant-750
        :effect (when (and (not (K_at_p3-4)) (K_at_p7-5)) (K_not_at_p3-4)))
    (:action invariant-751
        :effect (when (and (not (K_at_p7-5)) (K_at_p3-3)) (K_not_at_p7-5)))
    (:action invariant-752
        :effect (when (and (not (K_at_p3-3)) (K_at_p7-5)) (K_not_at_p3-3)))
    (:action invariant-753
        :effect (when (and (not (K_at_p7-5)) (K_at_p3-2)) (K_not_at_p7-5)))
    (:action invariant-754
        :effect (when (and (not (K_at_p3-2)) (K_at_p7-5)) (K_not_at_p3-2)))
    (:action invariant-755
        :effect (when (and (not (K_at_p7-5)) (K_at_p3-1)) (K_not_at_p7-5)))
    (:action invariant-756
        :effect (when (and (not (K_at_p3-1)) (K_at_p7-5)) (K_not_at_p3-1)))
    (:action invariant-757
        :effect (when (and (not (K_at_p7-5)) (K_at_p2-7)) (K_not_at_p7-5)))
    (:action invariant-758
        :effect (when (and (not (K_at_p2-7)) (K_at_p7-5)) (K_not_at_p2-7)))
    (:action invariant-759
        :effect (when (and (not (K_at_p7-5)) (K_at_p2-6)) (K_not_at_p7-5)))
    (:action invariant-760
        :effect (when (and (not (K_at_p2-6)) (K_at_p7-5)) (K_not_at_p2-6)))
    (:action invariant-761
        :effect (when (and (not (K_at_p7-5)) (K_at_p2-5)) (K_not_at_p7-5)))
    (:action invariant-762
        :effect (when (and (not (K_at_p2-5)) (K_at_p7-5)) (K_not_at_p2-5)))
    (:action invariant-763
        :effect (when (and (not (K_at_p7-5)) (K_at_p2-4)) (K_not_at_p7-5)))
    (:action invariant-764
        :effect (when (and (not (K_at_p2-4)) (K_at_p7-5)) (K_not_at_p2-4)))
    (:action invariant-765
        :effect (when (and (not (K_at_p7-5)) (K_at_p2-3)) (K_not_at_p7-5)))
    (:action invariant-766
        :effect (when (and (not (K_at_p2-3)) (K_at_p7-5)) (K_not_at_p2-3)))
    (:action invariant-767
        :effect (when (and (not (K_at_p7-5)) (K_at_p2-2)) (K_not_at_p7-5)))
    (:action invariant-768
        :effect (when (and (not (K_at_p2-2)) (K_at_p7-5)) (K_not_at_p2-2)))
    (:action invariant-769
        :effect (when (and (not (K_at_p7-5)) (K_at_p2-1)) (K_not_at_p7-5)))
    (:action invariant-770
        :effect (when (and (not (K_at_p2-1)) (K_at_p7-5)) (K_not_at_p2-1)))
    (:action invariant-771
        :effect (when (and (not (K_at_p7-5)) (K_at_p1-7)) (K_not_at_p7-5)))
    (:action invariant-772
        :effect (when (and (not (K_at_p1-7)) (K_at_p7-5)) (K_not_at_p1-7)))
    (:action invariant-773
        :effect (when (and (not (K_at_p7-5)) (K_at_p1-6)) (K_not_at_p7-5)))
    (:action invariant-774
        :effect (when (and (not (K_at_p1-6)) (K_at_p7-5)) (K_not_at_p1-6)))
    (:action invariant-775
        :effect (when (and (not (K_at_p7-5)) (K_at_p1-5)) (K_not_at_p7-5)))
    (:action invariant-776
        :effect (when (and (not (K_at_p1-5)) (K_at_p7-5)) (K_not_at_p1-5)))
    (:action invariant-777
        :effect (when (and (not (K_at_p7-5)) (K_at_p1-4)) (K_not_at_p7-5)))
    (:action invariant-778
        :effect (when (and (not (K_at_p1-4)) (K_at_p7-5)) (K_not_at_p1-4)))
    (:action invariant-779
        :effect (when (and (not (K_at_p7-5)) (K_at_p1-3)) (K_not_at_p7-5)))
    (:action invariant-780
        :effect (when (and (not (K_at_p1-3)) (K_at_p7-5)) (K_not_at_p1-3)))
    (:action invariant-781
        :effect (when (and (not (K_at_p7-5)) (K_at_p1-2)) (K_not_at_p7-5)))
    (:action invariant-782
        :effect (when (and (not (K_at_p1-2)) (K_at_p7-5)) (K_not_at_p1-2)))
    (:action invariant-783
        :effect (when (and (not (K_at_p7-5)) (K_at_p1-1)) (K_not_at_p7-5)))
    (:action invariant-784
        :effect (when (and (not (K_at_p1-1)) (K_at_p7-5)) (K_not_at_p1-1)))
    (:action invariant-785
        :effect (when (and (not (K_at_p7-4)) (K_at_p7-3)) (K_not_at_p7-4)))
    (:action invariant-786
        :effect (when (and (not (K_at_p7-3)) (K_at_p7-4)) (K_not_at_p7-3)))
    (:action invariant-787
        :effect (when (and (not (K_at_p7-4)) (K_at_p7-2)) (K_not_at_p7-4)))
    (:action invariant-788
        :effect (when (and (not (K_at_p7-2)) (K_at_p7-4)) (K_not_at_p7-2)))
    (:action invariant-789
        :effect (when (and (not (K_at_p7-4)) (K_at_p7-1)) (K_not_at_p7-4)))
    (:action invariant-790
        :effect (when (and (not (K_at_p7-1)) (K_at_p7-4)) (K_not_at_p7-1)))
    (:action invariant-791
        :effect (when (and (not (K_at_p7-4)) (K_at_p6-7)) (K_not_at_p7-4)))
    (:action invariant-792
        :effect (when (and (not (K_at_p6-7)) (K_at_p7-4)) (K_not_at_p6-7)))
    (:action invariant-793
        :effect (when (and (not (K_at_p7-4)) (K_at_p6-6)) (K_not_at_p7-4)))
    (:action invariant-794
        :effect (when (and (not (K_at_p6-6)) (K_at_p7-4)) (K_not_at_p6-6)))
    (:action invariant-795
        :effect (when (and (not (K_at_p7-4)) (K_at_p6-5)) (K_not_at_p7-4)))
    (:action invariant-796
        :effect (when (and (not (K_at_p6-5)) (K_at_p7-4)) (K_not_at_p6-5)))
    (:action invariant-797
        :effect (when (and (not (K_at_p7-4)) (K_at_p6-4)) (K_not_at_p7-4)))
    (:action invariant-798
        :effect (when (and (not (K_at_p6-4)) (K_at_p7-4)) (K_not_at_p6-4)))
    (:action invariant-799
        :effect (when (and (not (K_at_p7-4)) (K_at_p6-3)) (K_not_at_p7-4)))
    (:action invariant-800
        :effect (when (and (not (K_at_p6-3)) (K_at_p7-4)) (K_not_at_p6-3)))
    (:action invariant-801
        :effect (when (and (not (K_at_p7-4)) (K_at_p6-2)) (K_not_at_p7-4)))
    (:action invariant-802
        :effect (when (and (not (K_at_p6-2)) (K_at_p7-4)) (K_not_at_p6-2)))
    (:action invariant-803
        :effect (when (and (not (K_at_p7-4)) (K_at_p6-1)) (K_not_at_p7-4)))
    (:action invariant-804
        :effect (when (and (not (K_at_p6-1)) (K_at_p7-4)) (K_not_at_p6-1)))
    (:action invariant-805
        :effect (when (and (not (K_at_p7-4)) (K_at_p5-7)) (K_not_at_p7-4)))
    (:action invariant-806
        :effect (when (and (not (K_at_p5-7)) (K_at_p7-4)) (K_not_at_p5-7)))
    (:action invariant-807
        :effect (when (and (not (K_at_p7-4)) (K_at_p5-6)) (K_not_at_p7-4)))
    (:action invariant-808
        :effect (when (and (not (K_at_p5-6)) (K_at_p7-4)) (K_not_at_p5-6)))
    (:action invariant-809
        :effect (when (and (not (K_at_p7-4)) (K_at_p5-5)) (K_not_at_p7-4)))
    (:action invariant-810
        :effect (when (and (not (K_at_p5-5)) (K_at_p7-4)) (K_not_at_p5-5)))
    (:action invariant-811
        :effect (when (and (not (K_at_p7-4)) (K_at_p5-4)) (K_not_at_p7-4)))
    (:action invariant-812
        :effect (when (and (not (K_at_p5-4)) (K_at_p7-4)) (K_not_at_p5-4)))
    (:action invariant-813
        :effect (when (and (not (K_at_p7-4)) (K_at_p5-3)) (K_not_at_p7-4)))
    (:action invariant-814
        :effect (when (and (not (K_at_p5-3)) (K_at_p7-4)) (K_not_at_p5-3)))
    (:action invariant-815
        :effect (when (and (not (K_at_p7-4)) (K_at_p5-2)) (K_not_at_p7-4)))
    (:action invariant-816
        :effect (when (and (not (K_at_p5-2)) (K_at_p7-4)) (K_not_at_p5-2)))
    (:action invariant-817
        :effect (when (and (not (K_at_p7-4)) (K_at_p5-1)) (K_not_at_p7-4)))
    (:action invariant-818
        :effect (when (and (not (K_at_p5-1)) (K_at_p7-4)) (K_not_at_p5-1)))
    (:action invariant-819
        :effect (when (and (not (K_at_p7-4)) (K_at_p4-7)) (K_not_at_p7-4)))
    (:action invariant-820
        :effect (when (and (not (K_at_p4-7)) (K_at_p7-4)) (K_not_at_p4-7)))
    (:action invariant-821
        :effect (when (and (not (K_at_p7-4)) (K_at_p4-6)) (K_not_at_p7-4)))
    (:action invariant-822
        :effect (when (and (not (K_at_p4-6)) (K_at_p7-4)) (K_not_at_p4-6)))
    (:action invariant-823
        :effect (when (and (not (K_at_p7-4)) (K_at_p4-5)) (K_not_at_p7-4)))
    (:action invariant-824
        :effect (when (and (not (K_at_p4-5)) (K_at_p7-4)) (K_not_at_p4-5)))
    (:action invariant-825
        :effect (when (and (not (K_at_p7-4)) (K_at_p4-4)) (K_not_at_p7-4)))
    (:action invariant-826
        :effect (when (and (not (K_at_p4-4)) (K_at_p7-4)) (K_not_at_p4-4)))
    (:action invariant-827
        :effect (when (and (not (K_at_p7-4)) (K_at_p4-3)) (K_not_at_p7-4)))
    (:action invariant-828
        :effect (when (and (not (K_at_p4-3)) (K_at_p7-4)) (K_not_at_p4-3)))
    (:action invariant-829
        :effect (when (and (not (K_at_p7-4)) (K_at_p4-2)) (K_not_at_p7-4)))
    (:action invariant-830
        :effect (when (and (not (K_at_p4-2)) (K_at_p7-4)) (K_not_at_p4-2)))
    (:action invariant-831
        :effect (when (and (not (K_at_p7-4)) (K_at_p4-1)) (K_not_at_p7-4)))
    (:action invariant-832
        :effect (when (and (not (K_at_p4-1)) (K_at_p7-4)) (K_not_at_p4-1)))
    (:action invariant-833
        :effect (when (and (not (K_at_p7-4)) (K_at_p3-7)) (K_not_at_p7-4)))
    (:action invariant-834
        :effect (when (and (not (K_at_p3-7)) (K_at_p7-4)) (K_not_at_p3-7)))
    (:action invariant-835
        :effect (when (and (not (K_at_p7-4)) (K_at_p3-6)) (K_not_at_p7-4)))
    (:action invariant-836
        :effect (when (and (not (K_at_p3-6)) (K_at_p7-4)) (K_not_at_p3-6)))
    (:action invariant-837
        :effect (when (and (not (K_at_p7-4)) (K_at_p3-5)) (K_not_at_p7-4)))
    (:action invariant-838
        :effect (when (and (not (K_at_p3-5)) (K_at_p7-4)) (K_not_at_p3-5)))
    (:action invariant-839
        :effect (when (and (not (K_at_p7-4)) (K_at_p3-4)) (K_not_at_p7-4)))
    (:action invariant-840
        :effect (when (and (not (K_at_p3-4)) (K_at_p7-4)) (K_not_at_p3-4)))
    (:action invariant-841
        :effect (when (and (not (K_at_p7-4)) (K_at_p3-3)) (K_not_at_p7-4)))
    (:action invariant-842
        :effect (when (and (not (K_at_p3-3)) (K_at_p7-4)) (K_not_at_p3-3)))
    (:action invariant-843
        :effect (when (and (not (K_at_p7-4)) (K_at_p3-2)) (K_not_at_p7-4)))
    (:action invariant-844
        :effect (when (and (not (K_at_p3-2)) (K_at_p7-4)) (K_not_at_p3-2)))
    (:action invariant-845
        :effect (when (and (not (K_at_p7-4)) (K_at_p3-1)) (K_not_at_p7-4)))
    (:action invariant-846
        :effect (when (and (not (K_at_p3-1)) (K_at_p7-4)) (K_not_at_p3-1)))
    (:action invariant-847
        :effect (when (and (not (K_at_p7-4)) (K_at_p2-7)) (K_not_at_p7-4)))
    (:action invariant-848
        :effect (when (and (not (K_at_p2-7)) (K_at_p7-4)) (K_not_at_p2-7)))
    (:action invariant-849
        :effect (when (and (not (K_at_p7-4)) (K_at_p2-6)) (K_not_at_p7-4)))
    (:action invariant-850
        :effect (when (and (not (K_at_p2-6)) (K_at_p7-4)) (K_not_at_p2-6)))
    (:action invariant-851
        :effect (when (and (not (K_at_p7-4)) (K_at_p2-5)) (K_not_at_p7-4)))
    (:action invariant-852
        :effect (when (and (not (K_at_p2-5)) (K_at_p7-4)) (K_not_at_p2-5)))
    (:action invariant-853
        :effect (when (and (not (K_at_p7-4)) (K_at_p2-4)) (K_not_at_p7-4)))
    (:action invariant-854
        :effect (when (and (not (K_at_p2-4)) (K_at_p7-4)) (K_not_at_p2-4)))
    (:action invariant-855
        :effect (when (and (not (K_at_p7-4)) (K_at_p2-3)) (K_not_at_p7-4)))
    (:action invariant-856
        :effect (when (and (not (K_at_p2-3)) (K_at_p7-4)) (K_not_at_p2-3)))
    (:action invariant-857
        :effect (when (and (not (K_at_p7-4)) (K_at_p2-2)) (K_not_at_p7-4)))
    (:action invariant-858
        :effect (when (and (not (K_at_p2-2)) (K_at_p7-4)) (K_not_at_p2-2)))
    (:action invariant-859
        :effect (when (and (not (K_at_p7-4)) (K_at_p2-1)) (K_not_at_p7-4)))
    (:action invariant-860
        :effect (when (and (not (K_at_p2-1)) (K_at_p7-4)) (K_not_at_p2-1)))
    (:action invariant-861
        :effect (when (and (not (K_at_p7-4)) (K_at_p1-7)) (K_not_at_p7-4)))
    (:action invariant-862
        :effect (when (and (not (K_at_p1-7)) (K_at_p7-4)) (K_not_at_p1-7)))
    (:action invariant-863
        :effect (when (and (not (K_at_p7-4)) (K_at_p1-6)) (K_not_at_p7-4)))
    (:action invariant-864
        :effect (when (and (not (K_at_p1-6)) (K_at_p7-4)) (K_not_at_p1-6)))
    (:action invariant-865
        :effect (when (and (not (K_at_p7-4)) (K_at_p1-5)) (K_not_at_p7-4)))
    (:action invariant-866
        :effect (when (and (not (K_at_p1-5)) (K_at_p7-4)) (K_not_at_p1-5)))
    (:action invariant-867
        :effect (when (and (not (K_at_p7-4)) (K_at_p1-4)) (K_not_at_p7-4)))
    (:action invariant-868
        :effect (when (and (not (K_at_p1-4)) (K_at_p7-4)) (K_not_at_p1-4)))
    (:action invariant-869
        :effect (when (and (not (K_at_p7-4)) (K_at_p1-3)) (K_not_at_p7-4)))
    (:action invariant-870
        :effect (when (and (not (K_at_p1-3)) (K_at_p7-4)) (K_not_at_p1-3)))
    (:action invariant-871
        :effect (when (and (not (K_at_p7-4)) (K_at_p1-2)) (K_not_at_p7-4)))
    (:action invariant-872
        :effect (when (and (not (K_at_p1-2)) (K_at_p7-4)) (K_not_at_p1-2)))
    (:action invariant-873
        :effect (when (and (not (K_at_p7-4)) (K_at_p1-1)) (K_not_at_p7-4)))
    (:action invariant-874
        :effect (when (and (not (K_at_p1-1)) (K_at_p7-4)) (K_not_at_p1-1)))
    (:action invariant-875
        :effect (when (and (not (K_at_p7-3)) (K_at_p7-2)) (K_not_at_p7-3)))
    (:action invariant-876
        :effect (when (and (not (K_at_p7-2)) (K_at_p7-3)) (K_not_at_p7-2)))
    (:action invariant-877
        :effect (when (and (not (K_at_p7-3)) (K_at_p7-1)) (K_not_at_p7-3)))
    (:action invariant-878
        :effect (when (and (not (K_at_p7-1)) (K_at_p7-3)) (K_not_at_p7-1)))
    (:action invariant-879
        :effect (when (and (not (K_at_p7-3)) (K_at_p6-7)) (K_not_at_p7-3)))
    (:action invariant-880
        :effect (when (and (not (K_at_p6-7)) (K_at_p7-3)) (K_not_at_p6-7)))
    (:action invariant-881
        :effect (when (and (not (K_at_p7-3)) (K_at_p6-6)) (K_not_at_p7-3)))
    (:action invariant-882
        :effect (when (and (not (K_at_p6-6)) (K_at_p7-3)) (K_not_at_p6-6)))
    (:action invariant-883
        :effect (when (and (not (K_at_p7-3)) (K_at_p6-5)) (K_not_at_p7-3)))
    (:action invariant-884
        :effect (when (and (not (K_at_p6-5)) (K_at_p7-3)) (K_not_at_p6-5)))
    (:action invariant-885
        :effect (when (and (not (K_at_p7-3)) (K_at_p6-4)) (K_not_at_p7-3)))
    (:action invariant-886
        :effect (when (and (not (K_at_p6-4)) (K_at_p7-3)) (K_not_at_p6-4)))
    (:action invariant-887
        :effect (when (and (not (K_at_p7-3)) (K_at_p6-3)) (K_not_at_p7-3)))
    (:action invariant-888
        :effect (when (and (not (K_at_p6-3)) (K_at_p7-3)) (K_not_at_p6-3)))
    (:action invariant-889
        :effect (when (and (not (K_at_p7-3)) (K_at_p6-2)) (K_not_at_p7-3)))
    (:action invariant-890
        :effect (when (and (not (K_at_p6-2)) (K_at_p7-3)) (K_not_at_p6-2)))
    (:action invariant-891
        :effect (when (and (not (K_at_p7-3)) (K_at_p6-1)) (K_not_at_p7-3)))
    (:action invariant-892
        :effect (when (and (not (K_at_p6-1)) (K_at_p7-3)) (K_not_at_p6-1)))
    (:action invariant-893
        :effect (when (and (not (K_at_p7-3)) (K_at_p5-7)) (K_not_at_p7-3)))
    (:action invariant-894
        :effect (when (and (not (K_at_p5-7)) (K_at_p7-3)) (K_not_at_p5-7)))
    (:action invariant-895
        :effect (when (and (not (K_at_p7-3)) (K_at_p5-6)) (K_not_at_p7-3)))
    (:action invariant-896
        :effect (when (and (not (K_at_p5-6)) (K_at_p7-3)) (K_not_at_p5-6)))
    (:action invariant-897
        :effect (when (and (not (K_at_p7-3)) (K_at_p5-5)) (K_not_at_p7-3)))
    (:action invariant-898
        :effect (when (and (not (K_at_p5-5)) (K_at_p7-3)) (K_not_at_p5-5)))
    (:action invariant-899
        :effect (when (and (not (K_at_p7-3)) (K_at_p5-4)) (K_not_at_p7-3)))
    (:action invariant-900
        :effect (when (and (not (K_at_p5-4)) (K_at_p7-3)) (K_not_at_p5-4)))
    (:action invariant-901
        :effect (when (and (not (K_at_p7-3)) (K_at_p5-3)) (K_not_at_p7-3)))
    (:action invariant-902
        :effect (when (and (not (K_at_p5-3)) (K_at_p7-3)) (K_not_at_p5-3)))
    (:action invariant-903
        :effect (when (and (not (K_at_p7-3)) (K_at_p5-2)) (K_not_at_p7-3)))
    (:action invariant-904
        :effect (when (and (not (K_at_p5-2)) (K_at_p7-3)) (K_not_at_p5-2)))
    (:action invariant-905
        :effect (when (and (not (K_at_p7-3)) (K_at_p5-1)) (K_not_at_p7-3)))
    (:action invariant-906
        :effect (when (and (not (K_at_p5-1)) (K_at_p7-3)) (K_not_at_p5-1)))
    (:action invariant-907
        :effect (when (and (not (K_at_p7-3)) (K_at_p4-7)) (K_not_at_p7-3)))
    (:action invariant-908
        :effect (when (and (not (K_at_p4-7)) (K_at_p7-3)) (K_not_at_p4-7)))
    (:action invariant-909
        :effect (when (and (not (K_at_p7-3)) (K_at_p4-6)) (K_not_at_p7-3)))
    (:action invariant-910
        :effect (when (and (not (K_at_p4-6)) (K_at_p7-3)) (K_not_at_p4-6)))
    (:action invariant-911
        :effect (when (and (not (K_at_p7-3)) (K_at_p4-5)) (K_not_at_p7-3)))
    (:action invariant-912
        :effect (when (and (not (K_at_p4-5)) (K_at_p7-3)) (K_not_at_p4-5)))
    (:action invariant-913
        :effect (when (and (not (K_at_p7-3)) (K_at_p4-4)) (K_not_at_p7-3)))
    (:action invariant-914
        :effect (when (and (not (K_at_p4-4)) (K_at_p7-3)) (K_not_at_p4-4)))
    (:action invariant-915
        :effect (when (and (not (K_at_p7-3)) (K_at_p4-3)) (K_not_at_p7-3)))
    (:action invariant-916
        :effect (when (and (not (K_at_p4-3)) (K_at_p7-3)) (K_not_at_p4-3)))
    (:action invariant-917
        :effect (when (and (not (K_at_p7-3)) (K_at_p4-2)) (K_not_at_p7-3)))
    (:action invariant-918
        :effect (when (and (not (K_at_p4-2)) (K_at_p7-3)) (K_not_at_p4-2)))
    (:action invariant-919
        :effect (when (and (not (K_at_p7-3)) (K_at_p4-1)) (K_not_at_p7-3)))
    (:action invariant-920
        :effect (when (and (not (K_at_p4-1)) (K_at_p7-3)) (K_not_at_p4-1)))
    (:action invariant-921
        :effect (when (and (not (K_at_p7-3)) (K_at_p3-7)) (K_not_at_p7-3)))
    (:action invariant-922
        :effect (when (and (not (K_at_p3-7)) (K_at_p7-3)) (K_not_at_p3-7)))
    (:action invariant-923
        :effect (when (and (not (K_at_p7-3)) (K_at_p3-6)) (K_not_at_p7-3)))
    (:action invariant-924
        :effect (when (and (not (K_at_p3-6)) (K_at_p7-3)) (K_not_at_p3-6)))
    (:action invariant-925
        :effect (when (and (not (K_at_p7-3)) (K_at_p3-5)) (K_not_at_p7-3)))
    (:action invariant-926
        :effect (when (and (not (K_at_p3-5)) (K_at_p7-3)) (K_not_at_p3-5)))
    (:action invariant-927
        :effect (when (and (not (K_at_p7-3)) (K_at_p3-4)) (K_not_at_p7-3)))
    (:action invariant-928
        :effect (when (and (not (K_at_p3-4)) (K_at_p7-3)) (K_not_at_p3-4)))
    (:action invariant-929
        :effect (when (and (not (K_at_p7-3)) (K_at_p3-3)) (K_not_at_p7-3)))
    (:action invariant-930
        :effect (when (and (not (K_at_p3-3)) (K_at_p7-3)) (K_not_at_p3-3)))
    (:action invariant-931
        :effect (when (and (not (K_at_p7-3)) (K_at_p3-2)) (K_not_at_p7-3)))
    (:action invariant-932
        :effect (when (and (not (K_at_p3-2)) (K_at_p7-3)) (K_not_at_p3-2)))
    (:action invariant-933
        :effect (when (and (not (K_at_p7-3)) (K_at_p3-1)) (K_not_at_p7-3)))
    (:action invariant-934
        :effect (when (and (not (K_at_p3-1)) (K_at_p7-3)) (K_not_at_p3-1)))
    (:action invariant-935
        :effect (when (and (not (K_at_p7-3)) (K_at_p2-7)) (K_not_at_p7-3)))
    (:action invariant-936
        :effect (when (and (not (K_at_p2-7)) (K_at_p7-3)) (K_not_at_p2-7)))
    (:action invariant-937
        :effect (when (and (not (K_at_p7-3)) (K_at_p2-6)) (K_not_at_p7-3)))
    (:action invariant-938
        :effect (when (and (not (K_at_p2-6)) (K_at_p7-3)) (K_not_at_p2-6)))
    (:action invariant-939
        :effect (when (and (not (K_at_p7-3)) (K_at_p2-5)) (K_not_at_p7-3)))
    (:action invariant-940
        :effect (when (and (not (K_at_p2-5)) (K_at_p7-3)) (K_not_at_p2-5)))
    (:action invariant-941
        :effect (when (and (not (K_at_p7-3)) (K_at_p2-4)) (K_not_at_p7-3)))
    (:action invariant-942
        :effect (when (and (not (K_at_p2-4)) (K_at_p7-3)) (K_not_at_p2-4)))
    (:action invariant-943
        :effect (when (and (not (K_at_p7-3)) (K_at_p2-3)) (K_not_at_p7-3)))
    (:action invariant-944
        :effect (when (and (not (K_at_p2-3)) (K_at_p7-3)) (K_not_at_p2-3)))
    (:action invariant-945
        :effect (when (and (not (K_at_p7-3)) (K_at_p2-2)) (K_not_at_p7-3)))
    (:action invariant-946
        :effect (when (and (not (K_at_p2-2)) (K_at_p7-3)) (K_not_at_p2-2)))
    (:action invariant-947
        :effect (when (and (not (K_at_p7-3)) (K_at_p2-1)) (K_not_at_p7-3)))
    (:action invariant-948
        :effect (when (and (not (K_at_p2-1)) (K_at_p7-3)) (K_not_at_p2-1)))
    (:action invariant-949
        :effect (when (and (not (K_at_p7-3)) (K_at_p1-7)) (K_not_at_p7-3)))
    (:action invariant-950
        :effect (when (and (not (K_at_p1-7)) (K_at_p7-3)) (K_not_at_p1-7)))
    (:action invariant-951
        :effect (when (and (not (K_at_p7-3)) (K_at_p1-6)) (K_not_at_p7-3)))
    (:action invariant-952
        :effect (when (and (not (K_at_p1-6)) (K_at_p7-3)) (K_not_at_p1-6)))
    (:action invariant-953
        :effect (when (and (not (K_at_p7-3)) (K_at_p1-5)) (K_not_at_p7-3)))
    (:action invariant-954
        :effect (when (and (not (K_at_p1-5)) (K_at_p7-3)) (K_not_at_p1-5)))
    (:action invariant-955
        :effect (when (and (not (K_at_p7-3)) (K_at_p1-4)) (K_not_at_p7-3)))
    (:action invariant-956
        :effect (when (and (not (K_at_p1-4)) (K_at_p7-3)) (K_not_at_p1-4)))
    (:action invariant-957
        :effect (when (and (not (K_at_p7-3)) (K_at_p1-3)) (K_not_at_p7-3)))
    (:action invariant-958
        :effect (when (and (not (K_at_p1-3)) (K_at_p7-3)) (K_not_at_p1-3)))
    (:action invariant-959
        :effect (when (and (not (K_at_p7-3)) (K_at_p1-2)) (K_not_at_p7-3)))
    (:action invariant-960
        :effect (when (and (not (K_at_p1-2)) (K_at_p7-3)) (K_not_at_p1-2)))
    (:action invariant-961
        :effect (when (and (not (K_at_p7-3)) (K_at_p1-1)) (K_not_at_p7-3)))
    (:action invariant-962
        :effect (when (and (not (K_at_p1-1)) (K_at_p7-3)) (K_not_at_p1-1)))
    (:action invariant-963
        :effect (when (and (not (K_at_p7-2)) (K_at_p7-1)) (K_not_at_p7-2)))
    (:action invariant-964
        :effect (when (and (not (K_at_p7-1)) (K_at_p7-2)) (K_not_at_p7-1)))
    (:action invariant-965
        :effect (when (and (not (K_at_p7-2)) (K_at_p6-7)) (K_not_at_p7-2)))
    (:action invariant-966
        :effect (when (and (not (K_at_p6-7)) (K_at_p7-2)) (K_not_at_p6-7)))
    (:action invariant-967
        :effect (when (and (not (K_at_p7-2)) (K_at_p6-6)) (K_not_at_p7-2)))
    (:action invariant-968
        :effect (when (and (not (K_at_p6-6)) (K_at_p7-2)) (K_not_at_p6-6)))
    (:action invariant-969
        :effect (when (and (not (K_at_p7-2)) (K_at_p6-5)) (K_not_at_p7-2)))
    (:action invariant-970
        :effect (when (and (not (K_at_p6-5)) (K_at_p7-2)) (K_not_at_p6-5)))
    (:action invariant-971
        :effect (when (and (not (K_at_p7-2)) (K_at_p6-4)) (K_not_at_p7-2)))
    (:action invariant-972
        :effect (when (and (not (K_at_p6-4)) (K_at_p7-2)) (K_not_at_p6-4)))
    (:action invariant-973
        :effect (when (and (not (K_at_p7-2)) (K_at_p6-3)) (K_not_at_p7-2)))
    (:action invariant-974
        :effect (when (and (not (K_at_p6-3)) (K_at_p7-2)) (K_not_at_p6-3)))
    (:action invariant-975
        :effect (when (and (not (K_at_p7-2)) (K_at_p6-2)) (K_not_at_p7-2)))
    (:action invariant-976
        :effect (when (and (not (K_at_p6-2)) (K_at_p7-2)) (K_not_at_p6-2)))
    (:action invariant-977
        :effect (when (and (not (K_at_p7-2)) (K_at_p6-1)) (K_not_at_p7-2)))
    (:action invariant-978
        :effect (when (and (not (K_at_p6-1)) (K_at_p7-2)) (K_not_at_p6-1)))
    (:action invariant-979
        :effect (when (and (not (K_at_p7-2)) (K_at_p5-7)) (K_not_at_p7-2)))
    (:action invariant-980
        :effect (when (and (not (K_at_p5-7)) (K_at_p7-2)) (K_not_at_p5-7)))
    (:action invariant-981
        :effect (when (and (not (K_at_p7-2)) (K_at_p5-6)) (K_not_at_p7-2)))
    (:action invariant-982
        :effect (when (and (not (K_at_p5-6)) (K_at_p7-2)) (K_not_at_p5-6)))
    (:action invariant-983
        :effect (when (and (not (K_at_p7-2)) (K_at_p5-5)) (K_not_at_p7-2)))
    (:action invariant-984
        :effect (when (and (not (K_at_p5-5)) (K_at_p7-2)) (K_not_at_p5-5)))
    (:action invariant-985
        :effect (when (and (not (K_at_p7-2)) (K_at_p5-4)) (K_not_at_p7-2)))
    (:action invariant-986
        :effect (when (and (not (K_at_p5-4)) (K_at_p7-2)) (K_not_at_p5-4)))
    (:action invariant-987
        :effect (when (and (not (K_at_p7-2)) (K_at_p5-3)) (K_not_at_p7-2)))
    (:action invariant-988
        :effect (when (and (not (K_at_p5-3)) (K_at_p7-2)) (K_not_at_p5-3)))
    (:action invariant-989
        :effect (when (and (not (K_at_p7-2)) (K_at_p5-2)) (K_not_at_p7-2)))
    (:action invariant-990
        :effect (when (and (not (K_at_p5-2)) (K_at_p7-2)) (K_not_at_p5-2)))
    (:action invariant-991
        :effect (when (and (not (K_at_p7-2)) (K_at_p5-1)) (K_not_at_p7-2)))
    (:action invariant-992
        :effect (when (and (not (K_at_p5-1)) (K_at_p7-2)) (K_not_at_p5-1)))
    (:action invariant-993
        :effect (when (and (not (K_at_p7-2)) (K_at_p4-7)) (K_not_at_p7-2)))
    (:action invariant-994
        :effect (when (and (not (K_at_p4-7)) (K_at_p7-2)) (K_not_at_p4-7)))
    (:action invariant-995
        :effect (when (and (not (K_at_p7-2)) (K_at_p4-6)) (K_not_at_p7-2)))
    (:action invariant-996
        :effect (when (and (not (K_at_p4-6)) (K_at_p7-2)) (K_not_at_p4-6)))
    (:action invariant-997
        :effect (when (and (not (K_at_p7-2)) (K_at_p4-5)) (K_not_at_p7-2)))
    (:action invariant-998
        :effect (when (and (not (K_at_p4-5)) (K_at_p7-2)) (K_not_at_p4-5)))
    (:action invariant-999
        :effect (when (and (not (K_at_p7-2)) (K_at_p4-4)) (K_not_at_p7-2)))
    (:action invariant-1000
        :effect (when (and (not (K_at_p4-4)) (K_at_p7-2)) (K_not_at_p4-4)))
    (:action invariant-1001
        :effect (when (and (not (K_at_p7-2)) (K_at_p4-3)) (K_not_at_p7-2)))
    (:action invariant-1002
        :effect (when (and (not (K_at_p4-3)) (K_at_p7-2)) (K_not_at_p4-3)))
    (:action invariant-1003
        :effect (when (and (not (K_at_p7-2)) (K_at_p4-2)) (K_not_at_p7-2)))
    (:action invariant-1004
        :effect (when (and (not (K_at_p4-2)) (K_at_p7-2)) (K_not_at_p4-2)))
    (:action invariant-1005
        :effect (when (and (not (K_at_p7-2)) (K_at_p4-1)) (K_not_at_p7-2)))
    (:action invariant-1006
        :effect (when (and (not (K_at_p4-1)) (K_at_p7-2)) (K_not_at_p4-1)))
    (:action invariant-1007
        :effect (when (and (not (K_at_p7-2)) (K_at_p3-7)) (K_not_at_p7-2)))
    (:action invariant-1008
        :effect (when (and (not (K_at_p3-7)) (K_at_p7-2)) (K_not_at_p3-7)))
    (:action invariant-1009
        :effect (when (and (not (K_at_p7-2)) (K_at_p3-6)) (K_not_at_p7-2)))
    (:action invariant-1010
        :effect (when (and (not (K_at_p3-6)) (K_at_p7-2)) (K_not_at_p3-6)))
    (:action invariant-1011
        :effect (when (and (not (K_at_p7-2)) (K_at_p3-5)) (K_not_at_p7-2)))
    (:action invariant-1012
        :effect (when (and (not (K_at_p3-5)) (K_at_p7-2)) (K_not_at_p3-5)))
    (:action invariant-1013
        :effect (when (and (not (K_at_p7-2)) (K_at_p3-4)) (K_not_at_p7-2)))
    (:action invariant-1014
        :effect (when (and (not (K_at_p3-4)) (K_at_p7-2)) (K_not_at_p3-4)))
    (:action invariant-1015
        :effect (when (and (not (K_at_p7-2)) (K_at_p3-3)) (K_not_at_p7-2)))
    (:action invariant-1016
        :effect (when (and (not (K_at_p3-3)) (K_at_p7-2)) (K_not_at_p3-3)))
    (:action invariant-1017
        :effect (when (and (not (K_at_p7-2)) (K_at_p3-2)) (K_not_at_p7-2)))
    (:action invariant-1018
        :effect (when (and (not (K_at_p3-2)) (K_at_p7-2)) (K_not_at_p3-2)))
    (:action invariant-1019
        :effect (when (and (not (K_at_p7-2)) (K_at_p3-1)) (K_not_at_p7-2)))
    (:action invariant-1020
        :effect (when (and (not (K_at_p3-1)) (K_at_p7-2)) (K_not_at_p3-1)))
    (:action invariant-1021
        :effect (when (and (not (K_at_p7-2)) (K_at_p2-7)) (K_not_at_p7-2)))
    (:action invariant-1022
        :effect (when (and (not (K_at_p2-7)) (K_at_p7-2)) (K_not_at_p2-7)))
    (:action invariant-1023
        :effect (when (and (not (K_at_p7-2)) (K_at_p2-6)) (K_not_at_p7-2)))
    (:action invariant-1024
        :effect (when (and (not (K_at_p2-6)) (K_at_p7-2)) (K_not_at_p2-6)))
    (:action invariant-1025
        :effect (when (and (not (K_at_p7-2)) (K_at_p2-5)) (K_not_at_p7-2)))
    (:action invariant-1026
        :effect (when (and (not (K_at_p2-5)) (K_at_p7-2)) (K_not_at_p2-5)))
    (:action invariant-1027
        :effect (when (and (not (K_at_p7-2)) (K_at_p2-4)) (K_not_at_p7-2)))
    (:action invariant-1028
        :effect (when (and (not (K_at_p2-4)) (K_at_p7-2)) (K_not_at_p2-4)))
    (:action invariant-1029
        :effect (when (and (not (K_at_p7-2)) (K_at_p2-3)) (K_not_at_p7-2)))
    (:action invariant-1030
        :effect (when (and (not (K_at_p2-3)) (K_at_p7-2)) (K_not_at_p2-3)))
    (:action invariant-1031
        :effect (when (and (not (K_at_p7-2)) (K_at_p2-2)) (K_not_at_p7-2)))
    (:action invariant-1032
        :effect (when (and (not (K_at_p2-2)) (K_at_p7-2)) (K_not_at_p2-2)))
    (:action invariant-1033
        :effect (when (and (not (K_at_p7-2)) (K_at_p2-1)) (K_not_at_p7-2)))
    (:action invariant-1034
        :effect (when (and (not (K_at_p2-1)) (K_at_p7-2)) (K_not_at_p2-1)))
    (:action invariant-1035
        :effect (when (and (not (K_at_p7-2)) (K_at_p1-7)) (K_not_at_p7-2)))
    (:action invariant-1036
        :effect (when (and (not (K_at_p1-7)) (K_at_p7-2)) (K_not_at_p1-7)))
    (:action invariant-1037
        :effect (when (and (not (K_at_p7-2)) (K_at_p1-6)) (K_not_at_p7-2)))
    (:action invariant-1038
        :effect (when (and (not (K_at_p1-6)) (K_at_p7-2)) (K_not_at_p1-6)))
    (:action invariant-1039
        :effect (when (and (not (K_at_p7-2)) (K_at_p1-5)) (K_not_at_p7-2)))
    (:action invariant-1040
        :effect (when (and (not (K_at_p1-5)) (K_at_p7-2)) (K_not_at_p1-5)))
    (:action invariant-1041
        :effect (when (and (not (K_at_p7-2)) (K_at_p1-4)) (K_not_at_p7-2)))
    (:action invariant-1042
        :effect (when (and (not (K_at_p1-4)) (K_at_p7-2)) (K_not_at_p1-4)))
    (:action invariant-1043
        :effect (when (and (not (K_at_p7-2)) (K_at_p1-3)) (K_not_at_p7-2)))
    (:action invariant-1044
        :effect (when (and (not (K_at_p1-3)) (K_at_p7-2)) (K_not_at_p1-3)))
    (:action invariant-1045
        :effect (when (and (not (K_at_p7-2)) (K_at_p1-2)) (K_not_at_p7-2)))
    (:action invariant-1046
        :effect (when (and (not (K_at_p1-2)) (K_at_p7-2)) (K_not_at_p1-2)))
    (:action invariant-1047
        :effect (when (and (not (K_at_p7-2)) (K_at_p1-1)) (K_not_at_p7-2)))
    (:action invariant-1048
        :effect (when (and (not (K_at_p1-1)) (K_at_p7-2)) (K_not_at_p1-1)))
    (:action invariant-1049
        :effect (when (and (not (K_at_p7-1)) (K_at_p6-7)) (K_not_at_p7-1)))
    (:action invariant-1050
        :effect (when (and (not (K_at_p6-7)) (K_at_p7-1)) (K_not_at_p6-7)))
    (:action invariant-1051
        :effect (when (and (not (K_at_p7-1)) (K_at_p6-6)) (K_not_at_p7-1)))
    (:action invariant-1052
        :effect (when (and (not (K_at_p6-6)) (K_at_p7-1)) (K_not_at_p6-6)))
    (:action invariant-1053
        :effect (when (and (not (K_at_p7-1)) (K_at_p6-5)) (K_not_at_p7-1)))
    (:action invariant-1054
        :effect (when (and (not (K_at_p6-5)) (K_at_p7-1)) (K_not_at_p6-5)))
    (:action invariant-1055
        :effect (when (and (not (K_at_p7-1)) (K_at_p6-4)) (K_not_at_p7-1)))
    (:action invariant-1056
        :effect (when (and (not (K_at_p6-4)) (K_at_p7-1)) (K_not_at_p6-4)))
    (:action invariant-1057
        :effect (when (and (not (K_at_p7-1)) (K_at_p6-3)) (K_not_at_p7-1)))
    (:action invariant-1058
        :effect (when (and (not (K_at_p6-3)) (K_at_p7-1)) (K_not_at_p6-3)))
    (:action invariant-1059
        :effect (when (and (not (K_at_p7-1)) (K_at_p6-2)) (K_not_at_p7-1)))
    (:action invariant-1060
        :effect (when (and (not (K_at_p6-2)) (K_at_p7-1)) (K_not_at_p6-2)))
    (:action invariant-1061
        :effect (when (and (not (K_at_p7-1)) (K_at_p6-1)) (K_not_at_p7-1)))
    (:action invariant-1062
        :effect (when (and (not (K_at_p6-1)) (K_at_p7-1)) (K_not_at_p6-1)))
    (:action invariant-1063
        :effect (when (and (not (K_at_p7-1)) (K_at_p5-7)) (K_not_at_p7-1)))
    (:action invariant-1064
        :effect (when (and (not (K_at_p5-7)) (K_at_p7-1)) (K_not_at_p5-7)))
    (:action invariant-1065
        :effect (when (and (not (K_at_p7-1)) (K_at_p5-6)) (K_not_at_p7-1)))
    (:action invariant-1066
        :effect (when (and (not (K_at_p5-6)) (K_at_p7-1)) (K_not_at_p5-6)))
    (:action invariant-1067
        :effect (when (and (not (K_at_p7-1)) (K_at_p5-5)) (K_not_at_p7-1)))
    (:action invariant-1068
        :effect (when (and (not (K_at_p5-5)) (K_at_p7-1)) (K_not_at_p5-5)))
    (:action invariant-1069
        :effect (when (and (not (K_at_p7-1)) (K_at_p5-4)) (K_not_at_p7-1)))
    (:action invariant-1070
        :effect (when (and (not (K_at_p5-4)) (K_at_p7-1)) (K_not_at_p5-4)))
    (:action invariant-1071
        :effect (when (and (not (K_at_p7-1)) (K_at_p5-3)) (K_not_at_p7-1)))
    (:action invariant-1072
        :effect (when (and (not (K_at_p5-3)) (K_at_p7-1)) (K_not_at_p5-3)))
    (:action invariant-1073
        :effect (when (and (not (K_at_p7-1)) (K_at_p5-2)) (K_not_at_p7-1)))
    (:action invariant-1074
        :effect (when (and (not (K_at_p5-2)) (K_at_p7-1)) (K_not_at_p5-2)))
    (:action invariant-1075
        :effect (when (and (not (K_at_p7-1)) (K_at_p5-1)) (K_not_at_p7-1)))
    (:action invariant-1076
        :effect (when (and (not (K_at_p5-1)) (K_at_p7-1)) (K_not_at_p5-1)))
    (:action invariant-1077
        :effect (when (and (not (K_at_p7-1)) (K_at_p4-7)) (K_not_at_p7-1)))
    (:action invariant-1078
        :effect (when (and (not (K_at_p4-7)) (K_at_p7-1)) (K_not_at_p4-7)))
    (:action invariant-1079
        :effect (when (and (not (K_at_p7-1)) (K_at_p4-6)) (K_not_at_p7-1)))
    (:action invariant-1080
        :effect (when (and (not (K_at_p4-6)) (K_at_p7-1)) (K_not_at_p4-6)))
    (:action invariant-1081
        :effect (when (and (not (K_at_p7-1)) (K_at_p4-5)) (K_not_at_p7-1)))
    (:action invariant-1082
        :effect (when (and (not (K_at_p4-5)) (K_at_p7-1)) (K_not_at_p4-5)))
    (:action invariant-1083
        :effect (when (and (not (K_at_p7-1)) (K_at_p4-4)) (K_not_at_p7-1)))
    (:action invariant-1084
        :effect (when (and (not (K_at_p4-4)) (K_at_p7-1)) (K_not_at_p4-4)))
    (:action invariant-1085
        :effect (when (and (not (K_at_p7-1)) (K_at_p4-3)) (K_not_at_p7-1)))
    (:action invariant-1086
        :effect (when (and (not (K_at_p4-3)) (K_at_p7-1)) (K_not_at_p4-3)))
    (:action invariant-1087
        :effect (when (and (not (K_at_p7-1)) (K_at_p4-2)) (K_not_at_p7-1)))
    (:action invariant-1088
        :effect (when (and (not (K_at_p4-2)) (K_at_p7-1)) (K_not_at_p4-2)))
    (:action invariant-1089
        :effect (when (and (not (K_at_p7-1)) (K_at_p4-1)) (K_not_at_p7-1)))
    (:action invariant-1090
        :effect (when (and (not (K_at_p4-1)) (K_at_p7-1)) (K_not_at_p4-1)))
    (:action invariant-1091
        :effect (when (and (not (K_at_p7-1)) (K_at_p3-7)) (K_not_at_p7-1)))
    (:action invariant-1092
        :effect (when (and (not (K_at_p3-7)) (K_at_p7-1)) (K_not_at_p3-7)))
    (:action invariant-1093
        :effect (when (and (not (K_at_p7-1)) (K_at_p3-6)) (K_not_at_p7-1)))
    (:action invariant-1094
        :effect (when (and (not (K_at_p3-6)) (K_at_p7-1)) (K_not_at_p3-6)))
    (:action invariant-1095
        :effect (when (and (not (K_at_p7-1)) (K_at_p3-5)) (K_not_at_p7-1)))
    (:action invariant-1096
        :effect (when (and (not (K_at_p3-5)) (K_at_p7-1)) (K_not_at_p3-5)))
    (:action invariant-1097
        :effect (when (and (not (K_at_p7-1)) (K_at_p3-4)) (K_not_at_p7-1)))
    (:action invariant-1098
        :effect (when (and (not (K_at_p3-4)) (K_at_p7-1)) (K_not_at_p3-4)))
    (:action invariant-1099
        :effect (when (and (not (K_at_p7-1)) (K_at_p3-3)) (K_not_at_p7-1)))
    (:action invariant-1100
        :effect (when (and (not (K_at_p3-3)) (K_at_p7-1)) (K_not_at_p3-3)))
    (:action invariant-1101
        :effect (when (and (not (K_at_p7-1)) (K_at_p3-2)) (K_not_at_p7-1)))
    (:action invariant-1102
        :effect (when (and (not (K_at_p3-2)) (K_at_p7-1)) (K_not_at_p3-2)))
    (:action invariant-1103
        :effect (when (and (not (K_at_p7-1)) (K_at_p3-1)) (K_not_at_p7-1)))
    (:action invariant-1104
        :effect (when (and (not (K_at_p3-1)) (K_at_p7-1)) (K_not_at_p3-1)))
    (:action invariant-1105
        :effect (when (and (not (K_at_p7-1)) (K_at_p2-7)) (K_not_at_p7-1)))
    (:action invariant-1106
        :effect (when (and (not (K_at_p2-7)) (K_at_p7-1)) (K_not_at_p2-7)))
    (:action invariant-1107
        :effect (when (and (not (K_at_p7-1)) (K_at_p2-6)) (K_not_at_p7-1)))
    (:action invariant-1108
        :effect (when (and (not (K_at_p2-6)) (K_at_p7-1)) (K_not_at_p2-6)))
    (:action invariant-1109
        :effect (when (and (not (K_at_p7-1)) (K_at_p2-5)) (K_not_at_p7-1)))
    (:action invariant-1110
        :effect (when (and (not (K_at_p2-5)) (K_at_p7-1)) (K_not_at_p2-5)))
    (:action invariant-1111
        :effect (when (and (not (K_at_p7-1)) (K_at_p2-4)) (K_not_at_p7-1)))
    (:action invariant-1112
        :effect (when (and (not (K_at_p2-4)) (K_at_p7-1)) (K_not_at_p2-4)))
    (:action invariant-1113
        :effect (when (and (not (K_at_p7-1)) (K_at_p2-3)) (K_not_at_p7-1)))
    (:action invariant-1114
        :effect (when (and (not (K_at_p2-3)) (K_at_p7-1)) (K_not_at_p2-3)))
    (:action invariant-1115
        :effect (when (and (not (K_at_p7-1)) (K_at_p2-2)) (K_not_at_p7-1)))
    (:action invariant-1116
        :effect (when (and (not (K_at_p2-2)) (K_at_p7-1)) (K_not_at_p2-2)))
    (:action invariant-1117
        :effect (when (and (not (K_at_p7-1)) (K_at_p2-1)) (K_not_at_p7-1)))
    (:action invariant-1118
        :effect (when (and (not (K_at_p2-1)) (K_at_p7-1)) (K_not_at_p2-1)))
    (:action invariant-1119
        :effect (when (and (not (K_at_p7-1)) (K_at_p1-7)) (K_not_at_p7-1)))
    (:action invariant-1120
        :effect (when (and (not (K_at_p1-7)) (K_at_p7-1)) (K_not_at_p1-7)))
    (:action invariant-1121
        :effect (when (and (not (K_at_p7-1)) (K_at_p1-6)) (K_not_at_p7-1)))
    (:action invariant-1122
        :effect (when (and (not (K_at_p1-6)) (K_at_p7-1)) (K_not_at_p1-6)))
    (:action invariant-1123
        :effect (when (and (not (K_at_p7-1)) (K_at_p1-5)) (K_not_at_p7-1)))
    (:action invariant-1124
        :effect (when (and (not (K_at_p1-5)) (K_at_p7-1)) (K_not_at_p1-5)))
    (:action invariant-1125
        :effect (when (and (not (K_at_p7-1)) (K_at_p1-4)) (K_not_at_p7-1)))
    (:action invariant-1126
        :effect (when (and (not (K_at_p1-4)) (K_at_p7-1)) (K_not_at_p1-4)))
    (:action invariant-1127
        :effect (when (and (not (K_at_p7-1)) (K_at_p1-3)) (K_not_at_p7-1)))
    (:action invariant-1128
        :effect (when (and (not (K_at_p1-3)) (K_at_p7-1)) (K_not_at_p1-3)))
    (:action invariant-1129
        :effect (when (and (not (K_at_p7-1)) (K_at_p1-2)) (K_not_at_p7-1)))
    (:action invariant-1130
        :effect (when (and (not (K_at_p1-2)) (K_at_p7-1)) (K_not_at_p1-2)))
    (:action invariant-1131
        :effect (when (and (not (K_at_p7-1)) (K_at_p1-1)) (K_not_at_p7-1)))
    (:action invariant-1132
        :effect (when (and (not (K_at_p1-1)) (K_at_p7-1)) (K_not_at_p1-1)))
    (:action invariant-1133
        :effect (when (and (not (K_at_p6-7)) (K_at_p6-6)) (K_not_at_p6-7)))
    (:action invariant-1134
        :effect (when (and (not (K_at_p6-6)) (K_at_p6-7)) (K_not_at_p6-6)))
    (:action invariant-1135
        :effect (when (and (not (K_at_p6-7)) (K_at_p6-5)) (K_not_at_p6-7)))
    (:action invariant-1136
        :effect (when (and (not (K_at_p6-5)) (K_at_p6-7)) (K_not_at_p6-5)))
    (:action invariant-1137
        :effect (when (and (not (K_at_p6-7)) (K_at_p6-4)) (K_not_at_p6-7)))
    (:action invariant-1138
        :effect (when (and (not (K_at_p6-4)) (K_at_p6-7)) (K_not_at_p6-4)))
    (:action invariant-1139
        :effect (when (and (not (K_at_p6-7)) (K_at_p6-3)) (K_not_at_p6-7)))
    (:action invariant-1140
        :effect (when (and (not (K_at_p6-3)) (K_at_p6-7)) (K_not_at_p6-3)))
    (:action invariant-1141
        :effect (when (and (not (K_at_p6-7)) (K_at_p6-2)) (K_not_at_p6-7)))
    (:action invariant-1142
        :effect (when (and (not (K_at_p6-2)) (K_at_p6-7)) (K_not_at_p6-2)))
    (:action invariant-1143
        :effect (when (and (not (K_at_p6-7)) (K_at_p6-1)) (K_not_at_p6-7)))
    (:action invariant-1144
        :effect (when (and (not (K_at_p6-1)) (K_at_p6-7)) (K_not_at_p6-1)))
    (:action invariant-1145
        :effect (when (and (not (K_at_p6-7)) (K_at_p5-7)) (K_not_at_p6-7)))
    (:action invariant-1146
        :effect (when (and (not (K_at_p5-7)) (K_at_p6-7)) (K_not_at_p5-7)))
    (:action invariant-1147
        :effect (when (and (not (K_at_p6-7)) (K_at_p5-6)) (K_not_at_p6-7)))
    (:action invariant-1148
        :effect (when (and (not (K_at_p5-6)) (K_at_p6-7)) (K_not_at_p5-6)))
    (:action invariant-1149
        :effect (when (and (not (K_at_p6-7)) (K_at_p5-5)) (K_not_at_p6-7)))
    (:action invariant-1150
        :effect (when (and (not (K_at_p5-5)) (K_at_p6-7)) (K_not_at_p5-5)))
    (:action invariant-1151
        :effect (when (and (not (K_at_p6-7)) (K_at_p5-4)) (K_not_at_p6-7)))
    (:action invariant-1152
        :effect (when (and (not (K_at_p5-4)) (K_at_p6-7)) (K_not_at_p5-4)))
    (:action invariant-1153
        :effect (when (and (not (K_at_p6-7)) (K_at_p5-3)) (K_not_at_p6-7)))
    (:action invariant-1154
        :effect (when (and (not (K_at_p5-3)) (K_at_p6-7)) (K_not_at_p5-3)))
    (:action invariant-1155
        :effect (when (and (not (K_at_p6-7)) (K_at_p5-2)) (K_not_at_p6-7)))
    (:action invariant-1156
        :effect (when (and (not (K_at_p5-2)) (K_at_p6-7)) (K_not_at_p5-2)))
    (:action invariant-1157
        :effect (when (and (not (K_at_p6-7)) (K_at_p5-1)) (K_not_at_p6-7)))
    (:action invariant-1158
        :effect (when (and (not (K_at_p5-1)) (K_at_p6-7)) (K_not_at_p5-1)))
    (:action invariant-1159
        :effect (when (and (not (K_at_p6-7)) (K_at_p4-7)) (K_not_at_p6-7)))
    (:action invariant-1160
        :effect (when (and (not (K_at_p4-7)) (K_at_p6-7)) (K_not_at_p4-7)))
    (:action invariant-1161
        :effect (when (and (not (K_at_p6-7)) (K_at_p4-6)) (K_not_at_p6-7)))
    (:action invariant-1162
        :effect (when (and (not (K_at_p4-6)) (K_at_p6-7)) (K_not_at_p4-6)))
    (:action invariant-1163
        :effect (when (and (not (K_at_p6-7)) (K_at_p4-5)) (K_not_at_p6-7)))
    (:action invariant-1164
        :effect (when (and (not (K_at_p4-5)) (K_at_p6-7)) (K_not_at_p4-5)))
    (:action invariant-1165
        :effect (when (and (not (K_at_p6-7)) (K_at_p4-4)) (K_not_at_p6-7)))
    (:action invariant-1166
        :effect (when (and (not (K_at_p4-4)) (K_at_p6-7)) (K_not_at_p4-4)))
    (:action invariant-1167
        :effect (when (and (not (K_at_p6-7)) (K_at_p4-3)) (K_not_at_p6-7)))
    (:action invariant-1168
        :effect (when (and (not (K_at_p4-3)) (K_at_p6-7)) (K_not_at_p4-3)))
    (:action invariant-1169
        :effect (when (and (not (K_at_p6-7)) (K_at_p4-2)) (K_not_at_p6-7)))
    (:action invariant-1170
        :effect (when (and (not (K_at_p4-2)) (K_at_p6-7)) (K_not_at_p4-2)))
    (:action invariant-1171
        :effect (when (and (not (K_at_p6-7)) (K_at_p4-1)) (K_not_at_p6-7)))
    (:action invariant-1172
        :effect (when (and (not (K_at_p4-1)) (K_at_p6-7)) (K_not_at_p4-1)))
    (:action invariant-1173
        :effect (when (and (not (K_at_p6-7)) (K_at_p3-7)) (K_not_at_p6-7)))
    (:action invariant-1174
        :effect (when (and (not (K_at_p3-7)) (K_at_p6-7)) (K_not_at_p3-7)))
    (:action invariant-1175
        :effect (when (and (not (K_at_p6-7)) (K_at_p3-6)) (K_not_at_p6-7)))
    (:action invariant-1176
        :effect (when (and (not (K_at_p3-6)) (K_at_p6-7)) (K_not_at_p3-6)))
    (:action invariant-1177
        :effect (when (and (not (K_at_p6-7)) (K_at_p3-5)) (K_not_at_p6-7)))
    (:action invariant-1178
        :effect (when (and (not (K_at_p3-5)) (K_at_p6-7)) (K_not_at_p3-5)))
    (:action invariant-1179
        :effect (when (and (not (K_at_p6-7)) (K_at_p3-4)) (K_not_at_p6-7)))
    (:action invariant-1180
        :effect (when (and (not (K_at_p3-4)) (K_at_p6-7)) (K_not_at_p3-4)))
    (:action invariant-1181
        :effect (when (and (not (K_at_p6-7)) (K_at_p3-3)) (K_not_at_p6-7)))
    (:action invariant-1182
        :effect (when (and (not (K_at_p3-3)) (K_at_p6-7)) (K_not_at_p3-3)))
    (:action invariant-1183
        :effect (when (and (not (K_at_p6-7)) (K_at_p3-2)) (K_not_at_p6-7)))
    (:action invariant-1184
        :effect (when (and (not (K_at_p3-2)) (K_at_p6-7)) (K_not_at_p3-2)))
    (:action invariant-1185
        :effect (when (and (not (K_at_p6-7)) (K_at_p3-1)) (K_not_at_p6-7)))
    (:action invariant-1186
        :effect (when (and (not (K_at_p3-1)) (K_at_p6-7)) (K_not_at_p3-1)))
    (:action invariant-1187
        :effect (when (and (not (K_at_p6-7)) (K_at_p2-7)) (K_not_at_p6-7)))
    (:action invariant-1188
        :effect (when (and (not (K_at_p2-7)) (K_at_p6-7)) (K_not_at_p2-7)))
    (:action invariant-1189
        :effect (when (and (not (K_at_p6-7)) (K_at_p2-6)) (K_not_at_p6-7)))
    (:action invariant-1190
        :effect (when (and (not (K_at_p2-6)) (K_at_p6-7)) (K_not_at_p2-6)))
    (:action invariant-1191
        :effect (when (and (not (K_at_p6-7)) (K_at_p2-5)) (K_not_at_p6-7)))
    (:action invariant-1192
        :effect (when (and (not (K_at_p2-5)) (K_at_p6-7)) (K_not_at_p2-5)))
    (:action invariant-1193
        :effect (when (and (not (K_at_p6-7)) (K_at_p2-4)) (K_not_at_p6-7)))
    (:action invariant-1194
        :effect (when (and (not (K_at_p2-4)) (K_at_p6-7)) (K_not_at_p2-4)))
    (:action invariant-1195
        :effect (when (and (not (K_at_p6-7)) (K_at_p2-3)) (K_not_at_p6-7)))
    (:action invariant-1196
        :effect (when (and (not (K_at_p2-3)) (K_at_p6-7)) (K_not_at_p2-3)))
    (:action invariant-1197
        :effect (when (and (not (K_at_p6-7)) (K_at_p2-2)) (K_not_at_p6-7)))
    (:action invariant-1198
        :effect (when (and (not (K_at_p2-2)) (K_at_p6-7)) (K_not_at_p2-2)))
    (:action invariant-1199
        :effect (when (and (not (K_at_p6-7)) (K_at_p2-1)) (K_not_at_p6-7)))
    (:action invariant-1200
        :effect (when (and (not (K_at_p2-1)) (K_at_p6-7)) (K_not_at_p2-1)))
    (:action invariant-1201
        :effect (when (and (not (K_at_p6-7)) (K_at_p1-7)) (K_not_at_p6-7)))
    (:action invariant-1202
        :effect (when (and (not (K_at_p1-7)) (K_at_p6-7)) (K_not_at_p1-7)))
    (:action invariant-1203
        :effect (when (and (not (K_at_p6-7)) (K_at_p1-6)) (K_not_at_p6-7)))
    (:action invariant-1204
        :effect (when (and (not (K_at_p1-6)) (K_at_p6-7)) (K_not_at_p1-6)))
    (:action invariant-1205
        :effect (when (and (not (K_at_p6-7)) (K_at_p1-5)) (K_not_at_p6-7)))
    (:action invariant-1206
        :effect (when (and (not (K_at_p1-5)) (K_at_p6-7)) (K_not_at_p1-5)))
    (:action invariant-1207
        :effect (when (and (not (K_at_p6-7)) (K_at_p1-4)) (K_not_at_p6-7)))
    (:action invariant-1208
        :effect (when (and (not (K_at_p1-4)) (K_at_p6-7)) (K_not_at_p1-4)))
    (:action invariant-1209
        :effect (when (and (not (K_at_p6-7)) (K_at_p1-3)) (K_not_at_p6-7)))
    (:action invariant-1210
        :effect (when (and (not (K_at_p1-3)) (K_at_p6-7)) (K_not_at_p1-3)))
    (:action invariant-1211
        :effect (when (and (not (K_at_p6-7)) (K_at_p1-2)) (K_not_at_p6-7)))
    (:action invariant-1212
        :effect (when (and (not (K_at_p1-2)) (K_at_p6-7)) (K_not_at_p1-2)))
    (:action invariant-1213
        :effect (when (and (not (K_at_p6-7)) (K_at_p1-1)) (K_not_at_p6-7)))
    (:action invariant-1214
        :effect (when (and (not (K_at_p1-1)) (K_at_p6-7)) (K_not_at_p1-1)))
    (:action invariant-1215
        :effect (when (and (not (K_at_p6-6)) (K_at_p6-5)) (K_not_at_p6-6)))
    (:action invariant-1216
        :effect (when (and (not (K_at_p6-5)) (K_at_p6-6)) (K_not_at_p6-5)))
    (:action invariant-1217
        :effect (when (and (not (K_at_p6-6)) (K_at_p6-4)) (K_not_at_p6-6)))
    (:action invariant-1218
        :effect (when (and (not (K_at_p6-4)) (K_at_p6-6)) (K_not_at_p6-4)))
    (:action invariant-1219
        :effect (when (and (not (K_at_p6-6)) (K_at_p6-3)) (K_not_at_p6-6)))
    (:action invariant-1220
        :effect (when (and (not (K_at_p6-3)) (K_at_p6-6)) (K_not_at_p6-3)))
    (:action invariant-1221
        :effect (when (and (not (K_at_p6-6)) (K_at_p6-2)) (K_not_at_p6-6)))
    (:action invariant-1222
        :effect (when (and (not (K_at_p6-2)) (K_at_p6-6)) (K_not_at_p6-2)))
    (:action invariant-1223
        :effect (when (and (not (K_at_p6-6)) (K_at_p6-1)) (K_not_at_p6-6)))
    (:action invariant-1224
        :effect (when (and (not (K_at_p6-1)) (K_at_p6-6)) (K_not_at_p6-1)))
    (:action invariant-1225
        :effect (when (and (not (K_at_p6-6)) (K_at_p5-7)) (K_not_at_p6-6)))
    (:action invariant-1226
        :effect (when (and (not (K_at_p5-7)) (K_at_p6-6)) (K_not_at_p5-7)))
    (:action invariant-1227
        :effect (when (and (not (K_at_p6-6)) (K_at_p5-6)) (K_not_at_p6-6)))
    (:action invariant-1228
        :effect (when (and (not (K_at_p5-6)) (K_at_p6-6)) (K_not_at_p5-6)))
    (:action invariant-1229
        :effect (when (and (not (K_at_p6-6)) (K_at_p5-5)) (K_not_at_p6-6)))
    (:action invariant-1230
        :effect (when (and (not (K_at_p5-5)) (K_at_p6-6)) (K_not_at_p5-5)))
    (:action invariant-1231
        :effect (when (and (not (K_at_p6-6)) (K_at_p5-4)) (K_not_at_p6-6)))
    (:action invariant-1232
        :effect (when (and (not (K_at_p5-4)) (K_at_p6-6)) (K_not_at_p5-4)))
    (:action invariant-1233
        :effect (when (and (not (K_at_p6-6)) (K_at_p5-3)) (K_not_at_p6-6)))
    (:action invariant-1234
        :effect (when (and (not (K_at_p5-3)) (K_at_p6-6)) (K_not_at_p5-3)))
    (:action invariant-1235
        :effect (when (and (not (K_at_p6-6)) (K_at_p5-2)) (K_not_at_p6-6)))
    (:action invariant-1236
        :effect (when (and (not (K_at_p5-2)) (K_at_p6-6)) (K_not_at_p5-2)))
    (:action invariant-1237
        :effect (when (and (not (K_at_p6-6)) (K_at_p5-1)) (K_not_at_p6-6)))
    (:action invariant-1238
        :effect (when (and (not (K_at_p5-1)) (K_at_p6-6)) (K_not_at_p5-1)))
    (:action invariant-1239
        :effect (when (and (not (K_at_p6-6)) (K_at_p4-7)) (K_not_at_p6-6)))
    (:action invariant-1240
        :effect (when (and (not (K_at_p4-7)) (K_at_p6-6)) (K_not_at_p4-7)))
    (:action invariant-1241
        :effect (when (and (not (K_at_p6-6)) (K_at_p4-6)) (K_not_at_p6-6)))
    (:action invariant-1242
        :effect (when (and (not (K_at_p4-6)) (K_at_p6-6)) (K_not_at_p4-6)))
    (:action invariant-1243
        :effect (when (and (not (K_at_p6-6)) (K_at_p4-5)) (K_not_at_p6-6)))
    (:action invariant-1244
        :effect (when (and (not (K_at_p4-5)) (K_at_p6-6)) (K_not_at_p4-5)))
    (:action invariant-1245
        :effect (when (and (not (K_at_p6-6)) (K_at_p4-4)) (K_not_at_p6-6)))
    (:action invariant-1246
        :effect (when (and (not (K_at_p4-4)) (K_at_p6-6)) (K_not_at_p4-4)))
    (:action invariant-1247
        :effect (when (and (not (K_at_p6-6)) (K_at_p4-3)) (K_not_at_p6-6)))
    (:action invariant-1248
        :effect (when (and (not (K_at_p4-3)) (K_at_p6-6)) (K_not_at_p4-3)))
    (:action invariant-1249
        :effect (when (and (not (K_at_p6-6)) (K_at_p4-2)) (K_not_at_p6-6)))
    (:action invariant-1250
        :effect (when (and (not (K_at_p4-2)) (K_at_p6-6)) (K_not_at_p4-2)))
    (:action invariant-1251
        :effect (when (and (not (K_at_p6-6)) (K_at_p4-1)) (K_not_at_p6-6)))
    (:action invariant-1252
        :effect (when (and (not (K_at_p4-1)) (K_at_p6-6)) (K_not_at_p4-1)))
    (:action invariant-1253
        :effect (when (and (not (K_at_p6-6)) (K_at_p3-7)) (K_not_at_p6-6)))
    (:action invariant-1254
        :effect (when (and (not (K_at_p3-7)) (K_at_p6-6)) (K_not_at_p3-7)))
    (:action invariant-1255
        :effect (when (and (not (K_at_p6-6)) (K_at_p3-6)) (K_not_at_p6-6)))
    (:action invariant-1256
        :effect (when (and (not (K_at_p3-6)) (K_at_p6-6)) (K_not_at_p3-6)))
    (:action invariant-1257
        :effect (when (and (not (K_at_p6-6)) (K_at_p3-5)) (K_not_at_p6-6)))
    (:action invariant-1258
        :effect (when (and (not (K_at_p3-5)) (K_at_p6-6)) (K_not_at_p3-5)))
    (:action invariant-1259
        :effect (when (and (not (K_at_p6-6)) (K_at_p3-4)) (K_not_at_p6-6)))
    (:action invariant-1260
        :effect (when (and (not (K_at_p3-4)) (K_at_p6-6)) (K_not_at_p3-4)))
    (:action invariant-1261
        :effect (when (and (not (K_at_p6-6)) (K_at_p3-3)) (K_not_at_p6-6)))
    (:action invariant-1262
        :effect (when (and (not (K_at_p3-3)) (K_at_p6-6)) (K_not_at_p3-3)))
    (:action invariant-1263
        :effect (when (and (not (K_at_p6-6)) (K_at_p3-2)) (K_not_at_p6-6)))
    (:action invariant-1264
        :effect (when (and (not (K_at_p3-2)) (K_at_p6-6)) (K_not_at_p3-2)))
    (:action invariant-1265
        :effect (when (and (not (K_at_p6-6)) (K_at_p3-1)) (K_not_at_p6-6)))
    (:action invariant-1266
        :effect (when (and (not (K_at_p3-1)) (K_at_p6-6)) (K_not_at_p3-1)))
    (:action invariant-1267
        :effect (when (and (not (K_at_p6-6)) (K_at_p2-7)) (K_not_at_p6-6)))
    (:action invariant-1268
        :effect (when (and (not (K_at_p2-7)) (K_at_p6-6)) (K_not_at_p2-7)))
    (:action invariant-1269
        :effect (when (and (not (K_at_p6-6)) (K_at_p2-6)) (K_not_at_p6-6)))
    (:action invariant-1270
        :effect (when (and (not (K_at_p2-6)) (K_at_p6-6)) (K_not_at_p2-6)))
    (:action invariant-1271
        :effect (when (and (not (K_at_p6-6)) (K_at_p2-5)) (K_not_at_p6-6)))
    (:action invariant-1272
        :effect (when (and (not (K_at_p2-5)) (K_at_p6-6)) (K_not_at_p2-5)))
    (:action invariant-1273
        :effect (when (and (not (K_at_p6-6)) (K_at_p2-4)) (K_not_at_p6-6)))
    (:action invariant-1274
        :effect (when (and (not (K_at_p2-4)) (K_at_p6-6)) (K_not_at_p2-4)))
    (:action invariant-1275
        :effect (when (and (not (K_at_p6-6)) (K_at_p2-3)) (K_not_at_p6-6)))
    (:action invariant-1276
        :effect (when (and (not (K_at_p2-3)) (K_at_p6-6)) (K_not_at_p2-3)))
    (:action invariant-1277
        :effect (when (and (not (K_at_p6-6)) (K_at_p2-2)) (K_not_at_p6-6)))
    (:action invariant-1278
        :effect (when (and (not (K_at_p2-2)) (K_at_p6-6)) (K_not_at_p2-2)))
    (:action invariant-1279
        :effect (when (and (not (K_at_p6-6)) (K_at_p2-1)) (K_not_at_p6-6)))
    (:action invariant-1280
        :effect (when (and (not (K_at_p2-1)) (K_at_p6-6)) (K_not_at_p2-1)))
    (:action invariant-1281
        :effect (when (and (not (K_at_p6-6)) (K_at_p1-7)) (K_not_at_p6-6)))
    (:action invariant-1282
        :effect (when (and (not (K_at_p1-7)) (K_at_p6-6)) (K_not_at_p1-7)))
    (:action invariant-1283
        :effect (when (and (not (K_at_p6-6)) (K_at_p1-6)) (K_not_at_p6-6)))
    (:action invariant-1284
        :effect (when (and (not (K_at_p1-6)) (K_at_p6-6)) (K_not_at_p1-6)))
    (:action invariant-1285
        :effect (when (and (not (K_at_p6-6)) (K_at_p1-5)) (K_not_at_p6-6)))
    (:action invariant-1286
        :effect (when (and (not (K_at_p1-5)) (K_at_p6-6)) (K_not_at_p1-5)))
    (:action invariant-1287
        :effect (when (and (not (K_at_p6-6)) (K_at_p1-4)) (K_not_at_p6-6)))
    (:action invariant-1288
        :effect (when (and (not (K_at_p1-4)) (K_at_p6-6)) (K_not_at_p1-4)))
    (:action invariant-1289
        :effect (when (and (not (K_at_p6-6)) (K_at_p1-3)) (K_not_at_p6-6)))
    (:action invariant-1290
        :effect (when (and (not (K_at_p1-3)) (K_at_p6-6)) (K_not_at_p1-3)))
    (:action invariant-1291
        :effect (when (and (not (K_at_p6-6)) (K_at_p1-2)) (K_not_at_p6-6)))
    (:action invariant-1292
        :effect (when (and (not (K_at_p1-2)) (K_at_p6-6)) (K_not_at_p1-2)))
    (:action invariant-1293
        :effect (when (and (not (K_at_p6-6)) (K_at_p1-1)) (K_not_at_p6-6)))
    (:action invariant-1294
        :effect (when (and (not (K_at_p1-1)) (K_at_p6-6)) (K_not_at_p1-1)))
    (:action invariant-1295
        :effect (when (and (not (K_at_p6-5)) (K_at_p6-4)) (K_not_at_p6-5)))
    (:action invariant-1296
        :effect (when (and (not (K_at_p6-4)) (K_at_p6-5)) (K_not_at_p6-4)))
    (:action invariant-1297
        :effect (when (and (not (K_at_p6-5)) (K_at_p6-3)) (K_not_at_p6-5)))
    (:action invariant-1298
        :effect (when (and (not (K_at_p6-3)) (K_at_p6-5)) (K_not_at_p6-3)))
    (:action invariant-1299
        :effect (when (and (not (K_at_p6-5)) (K_at_p6-2)) (K_not_at_p6-5)))
    (:action invariant-1300
        :effect (when (and (not (K_at_p6-2)) (K_at_p6-5)) (K_not_at_p6-2)))
    (:action invariant-1301
        :effect (when (and (not (K_at_p6-5)) (K_at_p6-1)) (K_not_at_p6-5)))
    (:action invariant-1302
        :effect (when (and (not (K_at_p6-1)) (K_at_p6-5)) (K_not_at_p6-1)))
    (:action invariant-1303
        :effect (when (and (not (K_at_p6-5)) (K_at_p5-7)) (K_not_at_p6-5)))
    (:action invariant-1304
        :effect (when (and (not (K_at_p5-7)) (K_at_p6-5)) (K_not_at_p5-7)))
    (:action invariant-1305
        :effect (when (and (not (K_at_p6-5)) (K_at_p5-6)) (K_not_at_p6-5)))
    (:action invariant-1306
        :effect (when (and (not (K_at_p5-6)) (K_at_p6-5)) (K_not_at_p5-6)))
    (:action invariant-1307
        :effect (when (and (not (K_at_p6-5)) (K_at_p5-5)) (K_not_at_p6-5)))
    (:action invariant-1308
        :effect (when (and (not (K_at_p5-5)) (K_at_p6-5)) (K_not_at_p5-5)))
    (:action invariant-1309
        :effect (when (and (not (K_at_p6-5)) (K_at_p5-4)) (K_not_at_p6-5)))
    (:action invariant-1310
        :effect (when (and (not (K_at_p5-4)) (K_at_p6-5)) (K_not_at_p5-4)))
    (:action invariant-1311
        :effect (when (and (not (K_at_p6-5)) (K_at_p5-3)) (K_not_at_p6-5)))
    (:action invariant-1312
        :effect (when (and (not (K_at_p5-3)) (K_at_p6-5)) (K_not_at_p5-3)))
    (:action invariant-1313
        :effect (when (and (not (K_at_p6-5)) (K_at_p5-2)) (K_not_at_p6-5)))
    (:action invariant-1314
        :effect (when (and (not (K_at_p5-2)) (K_at_p6-5)) (K_not_at_p5-2)))
    (:action invariant-1315
        :effect (when (and (not (K_at_p6-5)) (K_at_p5-1)) (K_not_at_p6-5)))
    (:action invariant-1316
        :effect (when (and (not (K_at_p5-1)) (K_at_p6-5)) (K_not_at_p5-1)))
    (:action invariant-1317
        :effect (when (and (not (K_at_p6-5)) (K_at_p4-7)) (K_not_at_p6-5)))
    (:action invariant-1318
        :effect (when (and (not (K_at_p4-7)) (K_at_p6-5)) (K_not_at_p4-7)))
    (:action invariant-1319
        :effect (when (and (not (K_at_p6-5)) (K_at_p4-6)) (K_not_at_p6-5)))
    (:action invariant-1320
        :effect (when (and (not (K_at_p4-6)) (K_at_p6-5)) (K_not_at_p4-6)))
    (:action invariant-1321
        :effect (when (and (not (K_at_p6-5)) (K_at_p4-5)) (K_not_at_p6-5)))
    (:action invariant-1322
        :effect (when (and (not (K_at_p4-5)) (K_at_p6-5)) (K_not_at_p4-5)))
    (:action invariant-1323
        :effect (when (and (not (K_at_p6-5)) (K_at_p4-4)) (K_not_at_p6-5)))
    (:action invariant-1324
        :effect (when (and (not (K_at_p4-4)) (K_at_p6-5)) (K_not_at_p4-4)))
    (:action invariant-1325
        :effect (when (and (not (K_at_p6-5)) (K_at_p4-3)) (K_not_at_p6-5)))
    (:action invariant-1326
        :effect (when (and (not (K_at_p4-3)) (K_at_p6-5)) (K_not_at_p4-3)))
    (:action invariant-1327
        :effect (when (and (not (K_at_p6-5)) (K_at_p4-2)) (K_not_at_p6-5)))
    (:action invariant-1328
        :effect (when (and (not (K_at_p4-2)) (K_at_p6-5)) (K_not_at_p4-2)))
    (:action invariant-1329
        :effect (when (and (not (K_at_p6-5)) (K_at_p4-1)) (K_not_at_p6-5)))
    (:action invariant-1330
        :effect (when (and (not (K_at_p4-1)) (K_at_p6-5)) (K_not_at_p4-1)))
    (:action invariant-1331
        :effect (when (and (not (K_at_p6-5)) (K_at_p3-7)) (K_not_at_p6-5)))
    (:action invariant-1332
        :effect (when (and (not (K_at_p3-7)) (K_at_p6-5)) (K_not_at_p3-7)))
    (:action invariant-1333
        :effect (when (and (not (K_at_p6-5)) (K_at_p3-6)) (K_not_at_p6-5)))
    (:action invariant-1334
        :effect (when (and (not (K_at_p3-6)) (K_at_p6-5)) (K_not_at_p3-6)))
    (:action invariant-1335
        :effect (when (and (not (K_at_p6-5)) (K_at_p3-5)) (K_not_at_p6-5)))
    (:action invariant-1336
        :effect (when (and (not (K_at_p3-5)) (K_at_p6-5)) (K_not_at_p3-5)))
    (:action invariant-1337
        :effect (when (and (not (K_at_p6-5)) (K_at_p3-4)) (K_not_at_p6-5)))
    (:action invariant-1338
        :effect (when (and (not (K_at_p3-4)) (K_at_p6-5)) (K_not_at_p3-4)))
    (:action invariant-1339
        :effect (when (and (not (K_at_p6-5)) (K_at_p3-3)) (K_not_at_p6-5)))
    (:action invariant-1340
        :effect (when (and (not (K_at_p3-3)) (K_at_p6-5)) (K_not_at_p3-3)))
    (:action invariant-1341
        :effect (when (and (not (K_at_p6-5)) (K_at_p3-2)) (K_not_at_p6-5)))
    (:action invariant-1342
        :effect (when (and (not (K_at_p3-2)) (K_at_p6-5)) (K_not_at_p3-2)))
    (:action invariant-1343
        :effect (when (and (not (K_at_p6-5)) (K_at_p3-1)) (K_not_at_p6-5)))
    (:action invariant-1344
        :effect (when (and (not (K_at_p3-1)) (K_at_p6-5)) (K_not_at_p3-1)))
    (:action invariant-1345
        :effect (when (and (not (K_at_p6-5)) (K_at_p2-7)) (K_not_at_p6-5)))
    (:action invariant-1346
        :effect (when (and (not (K_at_p2-7)) (K_at_p6-5)) (K_not_at_p2-7)))
    (:action invariant-1347
        :effect (when (and (not (K_at_p6-5)) (K_at_p2-6)) (K_not_at_p6-5)))
    (:action invariant-1348
        :effect (when (and (not (K_at_p2-6)) (K_at_p6-5)) (K_not_at_p2-6)))
    (:action invariant-1349
        :effect (when (and (not (K_at_p6-5)) (K_at_p2-5)) (K_not_at_p6-5)))
    (:action invariant-1350
        :effect (when (and (not (K_at_p2-5)) (K_at_p6-5)) (K_not_at_p2-5)))
    (:action invariant-1351
        :effect (when (and (not (K_at_p6-5)) (K_at_p2-4)) (K_not_at_p6-5)))
    (:action invariant-1352
        :effect (when (and (not (K_at_p2-4)) (K_at_p6-5)) (K_not_at_p2-4)))
    (:action invariant-1353
        :effect (when (and (not (K_at_p6-5)) (K_at_p2-3)) (K_not_at_p6-5)))
    (:action invariant-1354
        :effect (when (and (not (K_at_p2-3)) (K_at_p6-5)) (K_not_at_p2-3)))
    (:action invariant-1355
        :effect (when (and (not (K_at_p6-5)) (K_at_p2-2)) (K_not_at_p6-5)))
    (:action invariant-1356
        :effect (when (and (not (K_at_p2-2)) (K_at_p6-5)) (K_not_at_p2-2)))
    (:action invariant-1357
        :effect (when (and (not (K_at_p6-5)) (K_at_p2-1)) (K_not_at_p6-5)))
    (:action invariant-1358
        :effect (when (and (not (K_at_p2-1)) (K_at_p6-5)) (K_not_at_p2-1)))
    (:action invariant-1359
        :effect (when (and (not (K_at_p6-5)) (K_at_p1-7)) (K_not_at_p6-5)))
    (:action invariant-1360
        :effect (when (and (not (K_at_p1-7)) (K_at_p6-5)) (K_not_at_p1-7)))
    (:action invariant-1361
        :effect (when (and (not (K_at_p6-5)) (K_at_p1-6)) (K_not_at_p6-5)))
    (:action invariant-1362
        :effect (when (and (not (K_at_p1-6)) (K_at_p6-5)) (K_not_at_p1-6)))
    (:action invariant-1363
        :effect (when (and (not (K_at_p6-5)) (K_at_p1-5)) (K_not_at_p6-5)))
    (:action invariant-1364
        :effect (when (and (not (K_at_p1-5)) (K_at_p6-5)) (K_not_at_p1-5)))
    (:action invariant-1365
        :effect (when (and (not (K_at_p6-5)) (K_at_p1-4)) (K_not_at_p6-5)))
    (:action invariant-1366
        :effect (when (and (not (K_at_p1-4)) (K_at_p6-5)) (K_not_at_p1-4)))
    (:action invariant-1367
        :effect (when (and (not (K_at_p6-5)) (K_at_p1-3)) (K_not_at_p6-5)))
    (:action invariant-1368
        :effect (when (and (not (K_at_p1-3)) (K_at_p6-5)) (K_not_at_p1-3)))
    (:action invariant-1369
        :effect (when (and (not (K_at_p6-5)) (K_at_p1-2)) (K_not_at_p6-5)))
    (:action invariant-1370
        :effect (when (and (not (K_at_p1-2)) (K_at_p6-5)) (K_not_at_p1-2)))
    (:action invariant-1371
        :effect (when (and (not (K_at_p6-5)) (K_at_p1-1)) (K_not_at_p6-5)))
    (:action invariant-1372
        :effect (when (and (not (K_at_p1-1)) (K_at_p6-5)) (K_not_at_p1-1)))
    (:action invariant-1373
        :effect (when (and (not (K_at_p6-4)) (K_at_p6-3)) (K_not_at_p6-4)))
    (:action invariant-1374
        :effect (when (and (not (K_at_p6-3)) (K_at_p6-4)) (K_not_at_p6-3)))
    (:action invariant-1375
        :effect (when (and (not (K_at_p6-4)) (K_at_p6-2)) (K_not_at_p6-4)))
    (:action invariant-1376
        :effect (when (and (not (K_at_p6-2)) (K_at_p6-4)) (K_not_at_p6-2)))
    (:action invariant-1377
        :effect (when (and (not (K_at_p6-4)) (K_at_p6-1)) (K_not_at_p6-4)))
    (:action invariant-1378
        :effect (when (and (not (K_at_p6-1)) (K_at_p6-4)) (K_not_at_p6-1)))
    (:action invariant-1379
        :effect (when (and (not (K_at_p6-4)) (K_at_p5-7)) (K_not_at_p6-4)))
    (:action invariant-1380
        :effect (when (and (not (K_at_p5-7)) (K_at_p6-4)) (K_not_at_p5-7)))
    (:action invariant-1381
        :effect (when (and (not (K_at_p6-4)) (K_at_p5-6)) (K_not_at_p6-4)))
    (:action invariant-1382
        :effect (when (and (not (K_at_p5-6)) (K_at_p6-4)) (K_not_at_p5-6)))
    (:action invariant-1383
        :effect (when (and (not (K_at_p6-4)) (K_at_p5-5)) (K_not_at_p6-4)))
    (:action invariant-1384
        :effect (when (and (not (K_at_p5-5)) (K_at_p6-4)) (K_not_at_p5-5)))
    (:action invariant-1385
        :effect (when (and (not (K_at_p6-4)) (K_at_p5-4)) (K_not_at_p6-4)))
    (:action invariant-1386
        :effect (when (and (not (K_at_p5-4)) (K_at_p6-4)) (K_not_at_p5-4)))
    (:action invariant-1387
        :effect (when (and (not (K_at_p6-4)) (K_at_p5-3)) (K_not_at_p6-4)))
    (:action invariant-1388
        :effect (when (and (not (K_at_p5-3)) (K_at_p6-4)) (K_not_at_p5-3)))
    (:action invariant-1389
        :effect (when (and (not (K_at_p6-4)) (K_at_p5-2)) (K_not_at_p6-4)))
    (:action invariant-1390
        :effect (when (and (not (K_at_p5-2)) (K_at_p6-4)) (K_not_at_p5-2)))
    (:action invariant-1391
        :effect (when (and (not (K_at_p6-4)) (K_at_p5-1)) (K_not_at_p6-4)))
    (:action invariant-1392
        :effect (when (and (not (K_at_p5-1)) (K_at_p6-4)) (K_not_at_p5-1)))
    (:action invariant-1393
        :effect (when (and (not (K_at_p6-4)) (K_at_p4-7)) (K_not_at_p6-4)))
    (:action invariant-1394
        :effect (when (and (not (K_at_p4-7)) (K_at_p6-4)) (K_not_at_p4-7)))
    (:action invariant-1395
        :effect (when (and (not (K_at_p6-4)) (K_at_p4-6)) (K_not_at_p6-4)))
    (:action invariant-1396
        :effect (when (and (not (K_at_p4-6)) (K_at_p6-4)) (K_not_at_p4-6)))
    (:action invariant-1397
        :effect (when (and (not (K_at_p6-4)) (K_at_p4-5)) (K_not_at_p6-4)))
    (:action invariant-1398
        :effect (when (and (not (K_at_p4-5)) (K_at_p6-4)) (K_not_at_p4-5)))
    (:action invariant-1399
        :effect (when (and (not (K_at_p6-4)) (K_at_p4-4)) (K_not_at_p6-4)))
    (:action invariant-1400
        :effect (when (and (not (K_at_p4-4)) (K_at_p6-4)) (K_not_at_p4-4)))
    (:action invariant-1401
        :effect (when (and (not (K_at_p6-4)) (K_at_p4-3)) (K_not_at_p6-4)))
    (:action invariant-1402
        :effect (when (and (not (K_at_p4-3)) (K_at_p6-4)) (K_not_at_p4-3)))
    (:action invariant-1403
        :effect (when (and (not (K_at_p6-4)) (K_at_p4-2)) (K_not_at_p6-4)))
    (:action invariant-1404
        :effect (when (and (not (K_at_p4-2)) (K_at_p6-4)) (K_not_at_p4-2)))
    (:action invariant-1405
        :effect (when (and (not (K_at_p6-4)) (K_at_p4-1)) (K_not_at_p6-4)))
    (:action invariant-1406
        :effect (when (and (not (K_at_p4-1)) (K_at_p6-4)) (K_not_at_p4-1)))
    (:action invariant-1407
        :effect (when (and (not (K_at_p6-4)) (K_at_p3-7)) (K_not_at_p6-4)))
    (:action invariant-1408
        :effect (when (and (not (K_at_p3-7)) (K_at_p6-4)) (K_not_at_p3-7)))
    (:action invariant-1409
        :effect (when (and (not (K_at_p6-4)) (K_at_p3-6)) (K_not_at_p6-4)))
    (:action invariant-1410
        :effect (when (and (not (K_at_p3-6)) (K_at_p6-4)) (K_not_at_p3-6)))
    (:action invariant-1411
        :effect (when (and (not (K_at_p6-4)) (K_at_p3-5)) (K_not_at_p6-4)))
    (:action invariant-1412
        :effect (when (and (not (K_at_p3-5)) (K_at_p6-4)) (K_not_at_p3-5)))
    (:action invariant-1413
        :effect (when (and (not (K_at_p6-4)) (K_at_p3-4)) (K_not_at_p6-4)))
    (:action invariant-1414
        :effect (when (and (not (K_at_p3-4)) (K_at_p6-4)) (K_not_at_p3-4)))
    (:action invariant-1415
        :effect (when (and (not (K_at_p6-4)) (K_at_p3-3)) (K_not_at_p6-4)))
    (:action invariant-1416
        :effect (when (and (not (K_at_p3-3)) (K_at_p6-4)) (K_not_at_p3-3)))
    (:action invariant-1417
        :effect (when (and (not (K_at_p6-4)) (K_at_p3-2)) (K_not_at_p6-4)))
    (:action invariant-1418
        :effect (when (and (not (K_at_p3-2)) (K_at_p6-4)) (K_not_at_p3-2)))
    (:action invariant-1419
        :effect (when (and (not (K_at_p6-4)) (K_at_p3-1)) (K_not_at_p6-4)))
    (:action invariant-1420
        :effect (when (and (not (K_at_p3-1)) (K_at_p6-4)) (K_not_at_p3-1)))
    (:action invariant-1421
        :effect (when (and (not (K_at_p6-4)) (K_at_p2-7)) (K_not_at_p6-4)))
    (:action invariant-1422
        :effect (when (and (not (K_at_p2-7)) (K_at_p6-4)) (K_not_at_p2-7)))
    (:action invariant-1423
        :effect (when (and (not (K_at_p6-4)) (K_at_p2-6)) (K_not_at_p6-4)))
    (:action invariant-1424
        :effect (when (and (not (K_at_p2-6)) (K_at_p6-4)) (K_not_at_p2-6)))
    (:action invariant-1425
        :effect (when (and (not (K_at_p6-4)) (K_at_p2-5)) (K_not_at_p6-4)))
    (:action invariant-1426
        :effect (when (and (not (K_at_p2-5)) (K_at_p6-4)) (K_not_at_p2-5)))
    (:action invariant-1427
        :effect (when (and (not (K_at_p6-4)) (K_at_p2-4)) (K_not_at_p6-4)))
    (:action invariant-1428
        :effect (when (and (not (K_at_p2-4)) (K_at_p6-4)) (K_not_at_p2-4)))
    (:action invariant-1429
        :effect (when (and (not (K_at_p6-4)) (K_at_p2-3)) (K_not_at_p6-4)))
    (:action invariant-1430
        :effect (when (and (not (K_at_p2-3)) (K_at_p6-4)) (K_not_at_p2-3)))
    (:action invariant-1431
        :effect (when (and (not (K_at_p6-4)) (K_at_p2-2)) (K_not_at_p6-4)))
    (:action invariant-1432
        :effect (when (and (not (K_at_p2-2)) (K_at_p6-4)) (K_not_at_p2-2)))
    (:action invariant-1433
        :effect (when (and (not (K_at_p6-4)) (K_at_p2-1)) (K_not_at_p6-4)))
    (:action invariant-1434
        :effect (when (and (not (K_at_p2-1)) (K_at_p6-4)) (K_not_at_p2-1)))
    (:action invariant-1435
        :effect (when (and (not (K_at_p6-4)) (K_at_p1-7)) (K_not_at_p6-4)))
    (:action invariant-1436
        :effect (when (and (not (K_at_p1-7)) (K_at_p6-4)) (K_not_at_p1-7)))
    (:action invariant-1437
        :effect (when (and (not (K_at_p6-4)) (K_at_p1-6)) (K_not_at_p6-4)))
    (:action invariant-1438
        :effect (when (and (not (K_at_p1-6)) (K_at_p6-4)) (K_not_at_p1-6)))
    (:action invariant-1439
        :effect (when (and (not (K_at_p6-4)) (K_at_p1-5)) (K_not_at_p6-4)))
    (:action invariant-1440
        :effect (when (and (not (K_at_p1-5)) (K_at_p6-4)) (K_not_at_p1-5)))
    (:action invariant-1441
        :effect (when (and (not (K_at_p6-4)) (K_at_p1-4)) (K_not_at_p6-4)))
    (:action invariant-1442
        :effect (when (and (not (K_at_p1-4)) (K_at_p6-4)) (K_not_at_p1-4)))
    (:action invariant-1443
        :effect (when (and (not (K_at_p6-4)) (K_at_p1-3)) (K_not_at_p6-4)))
    (:action invariant-1444
        :effect (when (and (not (K_at_p1-3)) (K_at_p6-4)) (K_not_at_p1-3)))
    (:action invariant-1445
        :effect (when (and (not (K_at_p6-4)) (K_at_p1-2)) (K_not_at_p6-4)))
    (:action invariant-1446
        :effect (when (and (not (K_at_p1-2)) (K_at_p6-4)) (K_not_at_p1-2)))
    (:action invariant-1447
        :effect (when (and (not (K_at_p6-4)) (K_at_p1-1)) (K_not_at_p6-4)))
    (:action invariant-1448
        :effect (when (and (not (K_at_p1-1)) (K_at_p6-4)) (K_not_at_p1-1)))
    (:action invariant-1449
        :effect (when (and (not (K_at_p6-3)) (K_at_p6-2)) (K_not_at_p6-3)))
    (:action invariant-1450
        :effect (when (and (not (K_at_p6-2)) (K_at_p6-3)) (K_not_at_p6-2)))
    (:action invariant-1451
        :effect (when (and (not (K_at_p6-3)) (K_at_p6-1)) (K_not_at_p6-3)))
    (:action invariant-1452
        :effect (when (and (not (K_at_p6-1)) (K_at_p6-3)) (K_not_at_p6-1)))
    (:action invariant-1453
        :effect (when (and (not (K_at_p6-3)) (K_at_p5-7)) (K_not_at_p6-3)))
    (:action invariant-1454
        :effect (when (and (not (K_at_p5-7)) (K_at_p6-3)) (K_not_at_p5-7)))
    (:action invariant-1455
        :effect (when (and (not (K_at_p6-3)) (K_at_p5-6)) (K_not_at_p6-3)))
    (:action invariant-1456
        :effect (when (and (not (K_at_p5-6)) (K_at_p6-3)) (K_not_at_p5-6)))
    (:action invariant-1457
        :effect (when (and (not (K_at_p6-3)) (K_at_p5-5)) (K_not_at_p6-3)))
    (:action invariant-1458
        :effect (when (and (not (K_at_p5-5)) (K_at_p6-3)) (K_not_at_p5-5)))
    (:action invariant-1459
        :effect (when (and (not (K_at_p6-3)) (K_at_p5-4)) (K_not_at_p6-3)))
    (:action invariant-1460
        :effect (when (and (not (K_at_p5-4)) (K_at_p6-3)) (K_not_at_p5-4)))
    (:action invariant-1461
        :effect (when (and (not (K_at_p6-3)) (K_at_p5-3)) (K_not_at_p6-3)))
    (:action invariant-1462
        :effect (when (and (not (K_at_p5-3)) (K_at_p6-3)) (K_not_at_p5-3)))
    (:action invariant-1463
        :effect (when (and (not (K_at_p6-3)) (K_at_p5-2)) (K_not_at_p6-3)))
    (:action invariant-1464
        :effect (when (and (not (K_at_p5-2)) (K_at_p6-3)) (K_not_at_p5-2)))
    (:action invariant-1465
        :effect (when (and (not (K_at_p6-3)) (K_at_p5-1)) (K_not_at_p6-3)))
    (:action invariant-1466
        :effect (when (and (not (K_at_p5-1)) (K_at_p6-3)) (K_not_at_p5-1)))
    (:action invariant-1467
        :effect (when (and (not (K_at_p6-3)) (K_at_p4-7)) (K_not_at_p6-3)))
    (:action invariant-1468
        :effect (when (and (not (K_at_p4-7)) (K_at_p6-3)) (K_not_at_p4-7)))
    (:action invariant-1469
        :effect (when (and (not (K_at_p6-3)) (K_at_p4-6)) (K_not_at_p6-3)))
    (:action invariant-1470
        :effect (when (and (not (K_at_p4-6)) (K_at_p6-3)) (K_not_at_p4-6)))
    (:action invariant-1471
        :effect (when (and (not (K_at_p6-3)) (K_at_p4-5)) (K_not_at_p6-3)))
    (:action invariant-1472
        :effect (when (and (not (K_at_p4-5)) (K_at_p6-3)) (K_not_at_p4-5)))
    (:action invariant-1473
        :effect (when (and (not (K_at_p6-3)) (K_at_p4-4)) (K_not_at_p6-3)))
    (:action invariant-1474
        :effect (when (and (not (K_at_p4-4)) (K_at_p6-3)) (K_not_at_p4-4)))
    (:action invariant-1475
        :effect (when (and (not (K_at_p6-3)) (K_at_p4-3)) (K_not_at_p6-3)))
    (:action invariant-1476
        :effect (when (and (not (K_at_p4-3)) (K_at_p6-3)) (K_not_at_p4-3)))
    (:action invariant-1477
        :effect (when (and (not (K_at_p6-3)) (K_at_p4-2)) (K_not_at_p6-3)))
    (:action invariant-1478
        :effect (when (and (not (K_at_p4-2)) (K_at_p6-3)) (K_not_at_p4-2)))
    (:action invariant-1479
        :effect (when (and (not (K_at_p6-3)) (K_at_p4-1)) (K_not_at_p6-3)))
    (:action invariant-1480
        :effect (when (and (not (K_at_p4-1)) (K_at_p6-3)) (K_not_at_p4-1)))
    (:action invariant-1481
        :effect (when (and (not (K_at_p6-3)) (K_at_p3-7)) (K_not_at_p6-3)))
    (:action invariant-1482
        :effect (when (and (not (K_at_p3-7)) (K_at_p6-3)) (K_not_at_p3-7)))
    (:action invariant-1483
        :effect (when (and (not (K_at_p6-3)) (K_at_p3-6)) (K_not_at_p6-3)))
    (:action invariant-1484
        :effect (when (and (not (K_at_p3-6)) (K_at_p6-3)) (K_not_at_p3-6)))
    (:action invariant-1485
        :effect (when (and (not (K_at_p6-3)) (K_at_p3-5)) (K_not_at_p6-3)))
    (:action invariant-1486
        :effect (when (and (not (K_at_p3-5)) (K_at_p6-3)) (K_not_at_p3-5)))
    (:action invariant-1487
        :effect (when (and (not (K_at_p6-3)) (K_at_p3-4)) (K_not_at_p6-3)))
    (:action invariant-1488
        :effect (when (and (not (K_at_p3-4)) (K_at_p6-3)) (K_not_at_p3-4)))
    (:action invariant-1489
        :effect (when (and (not (K_at_p6-3)) (K_at_p3-3)) (K_not_at_p6-3)))
    (:action invariant-1490
        :effect (when (and (not (K_at_p3-3)) (K_at_p6-3)) (K_not_at_p3-3)))
    (:action invariant-1491
        :effect (when (and (not (K_at_p6-3)) (K_at_p3-2)) (K_not_at_p6-3)))
    (:action invariant-1492
        :effect (when (and (not (K_at_p3-2)) (K_at_p6-3)) (K_not_at_p3-2)))
    (:action invariant-1493
        :effect (when (and (not (K_at_p6-3)) (K_at_p3-1)) (K_not_at_p6-3)))
    (:action invariant-1494
        :effect (when (and (not (K_at_p3-1)) (K_at_p6-3)) (K_not_at_p3-1)))
    (:action invariant-1495
        :effect (when (and (not (K_at_p6-3)) (K_at_p2-7)) (K_not_at_p6-3)))
    (:action invariant-1496
        :effect (when (and (not (K_at_p2-7)) (K_at_p6-3)) (K_not_at_p2-7)))
    (:action invariant-1497
        :effect (when (and (not (K_at_p6-3)) (K_at_p2-6)) (K_not_at_p6-3)))
    (:action invariant-1498
        :effect (when (and (not (K_at_p2-6)) (K_at_p6-3)) (K_not_at_p2-6)))
    (:action invariant-1499
        :effect (when (and (not (K_at_p6-3)) (K_at_p2-5)) (K_not_at_p6-3)))
    (:action invariant-1500
        :effect (when (and (not (K_at_p2-5)) (K_at_p6-3)) (K_not_at_p2-5)))
    (:action invariant-1501
        :effect (when (and (not (K_at_p6-3)) (K_at_p2-4)) (K_not_at_p6-3)))
    (:action invariant-1502
        :effect (when (and (not (K_at_p2-4)) (K_at_p6-3)) (K_not_at_p2-4)))
    (:action invariant-1503
        :effect (when (and (not (K_at_p6-3)) (K_at_p2-3)) (K_not_at_p6-3)))
    (:action invariant-1504
        :effect (when (and (not (K_at_p2-3)) (K_at_p6-3)) (K_not_at_p2-3)))
    (:action invariant-1505
        :effect (when (and (not (K_at_p6-3)) (K_at_p2-2)) (K_not_at_p6-3)))
    (:action invariant-1506
        :effect (when (and (not (K_at_p2-2)) (K_at_p6-3)) (K_not_at_p2-2)))
    (:action invariant-1507
        :effect (when (and (not (K_at_p6-3)) (K_at_p2-1)) (K_not_at_p6-3)))
    (:action invariant-1508
        :effect (when (and (not (K_at_p2-1)) (K_at_p6-3)) (K_not_at_p2-1)))
    (:action invariant-1509
        :effect (when (and (not (K_at_p6-3)) (K_at_p1-7)) (K_not_at_p6-3)))
    (:action invariant-1510
        :effect (when (and (not (K_at_p1-7)) (K_at_p6-3)) (K_not_at_p1-7)))
    (:action invariant-1511
        :effect (when (and (not (K_at_p6-3)) (K_at_p1-6)) (K_not_at_p6-3)))
    (:action invariant-1512
        :effect (when (and (not (K_at_p1-6)) (K_at_p6-3)) (K_not_at_p1-6)))
    (:action invariant-1513
        :effect (when (and (not (K_at_p6-3)) (K_at_p1-5)) (K_not_at_p6-3)))
    (:action invariant-1514
        :effect (when (and (not (K_at_p1-5)) (K_at_p6-3)) (K_not_at_p1-5)))
    (:action invariant-1515
        :effect (when (and (not (K_at_p6-3)) (K_at_p1-4)) (K_not_at_p6-3)))
    (:action invariant-1516
        :effect (when (and (not (K_at_p1-4)) (K_at_p6-3)) (K_not_at_p1-4)))
    (:action invariant-1517
        :effect (when (and (not (K_at_p6-3)) (K_at_p1-3)) (K_not_at_p6-3)))
    (:action invariant-1518
        :effect (when (and (not (K_at_p1-3)) (K_at_p6-3)) (K_not_at_p1-3)))
    (:action invariant-1519
        :effect (when (and (not (K_at_p6-3)) (K_at_p1-2)) (K_not_at_p6-3)))
    (:action invariant-1520
        :effect (when (and (not (K_at_p1-2)) (K_at_p6-3)) (K_not_at_p1-2)))
    (:action invariant-1521
        :effect (when (and (not (K_at_p6-3)) (K_at_p1-1)) (K_not_at_p6-3)))
    (:action invariant-1522
        :effect (when (and (not (K_at_p1-1)) (K_at_p6-3)) (K_not_at_p1-1)))
    (:action invariant-1523
        :effect (when (and (not (K_at_p6-2)) (K_at_p6-1)) (K_not_at_p6-2)))
    (:action invariant-1524
        :effect (when (and (not (K_at_p6-1)) (K_at_p6-2)) (K_not_at_p6-1)))
    (:action invariant-1525
        :effect (when (and (not (K_at_p6-2)) (K_at_p5-7)) (K_not_at_p6-2)))
    (:action invariant-1526
        :effect (when (and (not (K_at_p5-7)) (K_at_p6-2)) (K_not_at_p5-7)))
    (:action invariant-1527
        :effect (when (and (not (K_at_p6-2)) (K_at_p5-6)) (K_not_at_p6-2)))
    (:action invariant-1528
        :effect (when (and (not (K_at_p5-6)) (K_at_p6-2)) (K_not_at_p5-6)))
    (:action invariant-1529
        :effect (when (and (not (K_at_p6-2)) (K_at_p5-5)) (K_not_at_p6-2)))
    (:action invariant-1530
        :effect (when (and (not (K_at_p5-5)) (K_at_p6-2)) (K_not_at_p5-5)))
    (:action invariant-1531
        :effect (when (and (not (K_at_p6-2)) (K_at_p5-4)) (K_not_at_p6-2)))
    (:action invariant-1532
        :effect (when (and (not (K_at_p5-4)) (K_at_p6-2)) (K_not_at_p5-4)))
    (:action invariant-1533
        :effect (when (and (not (K_at_p6-2)) (K_at_p5-3)) (K_not_at_p6-2)))
    (:action invariant-1534
        :effect (when (and (not (K_at_p5-3)) (K_at_p6-2)) (K_not_at_p5-3)))
    (:action invariant-1535
        :effect (when (and (not (K_at_p6-2)) (K_at_p5-2)) (K_not_at_p6-2)))
    (:action invariant-1536
        :effect (when (and (not (K_at_p5-2)) (K_at_p6-2)) (K_not_at_p5-2)))
    (:action invariant-1537
        :effect (when (and (not (K_at_p6-2)) (K_at_p5-1)) (K_not_at_p6-2)))
    (:action invariant-1538
        :effect (when (and (not (K_at_p5-1)) (K_at_p6-2)) (K_not_at_p5-1)))
    (:action invariant-1539
        :effect (when (and (not (K_at_p6-2)) (K_at_p4-7)) (K_not_at_p6-2)))
    (:action invariant-1540
        :effect (when (and (not (K_at_p4-7)) (K_at_p6-2)) (K_not_at_p4-7)))
    (:action invariant-1541
        :effect (when (and (not (K_at_p6-2)) (K_at_p4-6)) (K_not_at_p6-2)))
    (:action invariant-1542
        :effect (when (and (not (K_at_p4-6)) (K_at_p6-2)) (K_not_at_p4-6)))
    (:action invariant-1543
        :effect (when (and (not (K_at_p6-2)) (K_at_p4-5)) (K_not_at_p6-2)))
    (:action invariant-1544
        :effect (when (and (not (K_at_p4-5)) (K_at_p6-2)) (K_not_at_p4-5)))
    (:action invariant-1545
        :effect (when (and (not (K_at_p6-2)) (K_at_p4-4)) (K_not_at_p6-2)))
    (:action invariant-1546
        :effect (when (and (not (K_at_p4-4)) (K_at_p6-2)) (K_not_at_p4-4)))
    (:action invariant-1547
        :effect (when (and (not (K_at_p6-2)) (K_at_p4-3)) (K_not_at_p6-2)))
    (:action invariant-1548
        :effect (when (and (not (K_at_p4-3)) (K_at_p6-2)) (K_not_at_p4-3)))
    (:action invariant-1549
        :effect (when (and (not (K_at_p6-2)) (K_at_p4-2)) (K_not_at_p6-2)))
    (:action invariant-1550
        :effect (when (and (not (K_at_p4-2)) (K_at_p6-2)) (K_not_at_p4-2)))
    (:action invariant-1551
        :effect (when (and (not (K_at_p6-2)) (K_at_p4-1)) (K_not_at_p6-2)))
    (:action invariant-1552
        :effect (when (and (not (K_at_p4-1)) (K_at_p6-2)) (K_not_at_p4-1)))
    (:action invariant-1553
        :effect (when (and (not (K_at_p6-2)) (K_at_p3-7)) (K_not_at_p6-2)))
    (:action invariant-1554
        :effect (when (and (not (K_at_p3-7)) (K_at_p6-2)) (K_not_at_p3-7)))
    (:action invariant-1555
        :effect (when (and (not (K_at_p6-2)) (K_at_p3-6)) (K_not_at_p6-2)))
    (:action invariant-1556
        :effect (when (and (not (K_at_p3-6)) (K_at_p6-2)) (K_not_at_p3-6)))
    (:action invariant-1557
        :effect (when (and (not (K_at_p6-2)) (K_at_p3-5)) (K_not_at_p6-2)))
    (:action invariant-1558
        :effect (when (and (not (K_at_p3-5)) (K_at_p6-2)) (K_not_at_p3-5)))
    (:action invariant-1559
        :effect (when (and (not (K_at_p6-2)) (K_at_p3-4)) (K_not_at_p6-2)))
    (:action invariant-1560
        :effect (when (and (not (K_at_p3-4)) (K_at_p6-2)) (K_not_at_p3-4)))
    (:action invariant-1561
        :effect (when (and (not (K_at_p6-2)) (K_at_p3-3)) (K_not_at_p6-2)))
    (:action invariant-1562
        :effect (when (and (not (K_at_p3-3)) (K_at_p6-2)) (K_not_at_p3-3)))
    (:action invariant-1563
        :effect (when (and (not (K_at_p6-2)) (K_at_p3-2)) (K_not_at_p6-2)))
    (:action invariant-1564
        :effect (when (and (not (K_at_p3-2)) (K_at_p6-2)) (K_not_at_p3-2)))
    (:action invariant-1565
        :effect (when (and (not (K_at_p6-2)) (K_at_p3-1)) (K_not_at_p6-2)))
    (:action invariant-1566
        :effect (when (and (not (K_at_p3-1)) (K_at_p6-2)) (K_not_at_p3-1)))
    (:action invariant-1567
        :effect (when (and (not (K_at_p6-2)) (K_at_p2-7)) (K_not_at_p6-2)))
    (:action invariant-1568
        :effect (when (and (not (K_at_p2-7)) (K_at_p6-2)) (K_not_at_p2-7)))
    (:action invariant-1569
        :effect (when (and (not (K_at_p6-2)) (K_at_p2-6)) (K_not_at_p6-2)))
    (:action invariant-1570
        :effect (when (and (not (K_at_p2-6)) (K_at_p6-2)) (K_not_at_p2-6)))
    (:action invariant-1571
        :effect (when (and (not (K_at_p6-2)) (K_at_p2-5)) (K_not_at_p6-2)))
    (:action invariant-1572
        :effect (when (and (not (K_at_p2-5)) (K_at_p6-2)) (K_not_at_p2-5)))
    (:action invariant-1573
        :effect (when (and (not (K_at_p6-2)) (K_at_p2-4)) (K_not_at_p6-2)))
    (:action invariant-1574
        :effect (when (and (not (K_at_p2-4)) (K_at_p6-2)) (K_not_at_p2-4)))
    (:action invariant-1575
        :effect (when (and (not (K_at_p6-2)) (K_at_p2-3)) (K_not_at_p6-2)))
    (:action invariant-1576
        :effect (when (and (not (K_at_p2-3)) (K_at_p6-2)) (K_not_at_p2-3)))
    (:action invariant-1577
        :effect (when (and (not (K_at_p6-2)) (K_at_p2-2)) (K_not_at_p6-2)))
    (:action invariant-1578
        :effect (when (and (not (K_at_p2-2)) (K_at_p6-2)) (K_not_at_p2-2)))
    (:action invariant-1579
        :effect (when (and (not (K_at_p6-2)) (K_at_p2-1)) (K_not_at_p6-2)))
    (:action invariant-1580
        :effect (when (and (not (K_at_p2-1)) (K_at_p6-2)) (K_not_at_p2-1)))
    (:action invariant-1581
        :effect (when (and (not (K_at_p6-2)) (K_at_p1-7)) (K_not_at_p6-2)))
    (:action invariant-1582
        :effect (when (and (not (K_at_p1-7)) (K_at_p6-2)) (K_not_at_p1-7)))
    (:action invariant-1583
        :effect (when (and (not (K_at_p6-2)) (K_at_p1-6)) (K_not_at_p6-2)))
    (:action invariant-1584
        :effect (when (and (not (K_at_p1-6)) (K_at_p6-2)) (K_not_at_p1-6)))
    (:action invariant-1585
        :effect (when (and (not (K_at_p6-2)) (K_at_p1-5)) (K_not_at_p6-2)))
    (:action invariant-1586
        :effect (when (and (not (K_at_p1-5)) (K_at_p6-2)) (K_not_at_p1-5)))
    (:action invariant-1587
        :effect (when (and (not (K_at_p6-2)) (K_at_p1-4)) (K_not_at_p6-2)))
    (:action invariant-1588
        :effect (when (and (not (K_at_p1-4)) (K_at_p6-2)) (K_not_at_p1-4)))
    (:action invariant-1589
        :effect (when (and (not (K_at_p6-2)) (K_at_p1-3)) (K_not_at_p6-2)))
    (:action invariant-1590
        :effect (when (and (not (K_at_p1-3)) (K_at_p6-2)) (K_not_at_p1-3)))
    (:action invariant-1591
        :effect (when (and (not (K_at_p6-2)) (K_at_p1-2)) (K_not_at_p6-2)))
    (:action invariant-1592
        :effect (when (and (not (K_at_p1-2)) (K_at_p6-2)) (K_not_at_p1-2)))
    (:action invariant-1593
        :effect (when (and (not (K_at_p6-2)) (K_at_p1-1)) (K_not_at_p6-2)))
    (:action invariant-1594
        :effect (when (and (not (K_at_p1-1)) (K_at_p6-2)) (K_not_at_p1-1)))
    (:action invariant-1595
        :effect (when (and (not (K_at_p6-1)) (K_at_p5-7)) (K_not_at_p6-1)))
    (:action invariant-1596
        :effect (when (and (not (K_at_p5-7)) (K_at_p6-1)) (K_not_at_p5-7)))
    (:action invariant-1597
        :effect (when (and (not (K_at_p6-1)) (K_at_p5-6)) (K_not_at_p6-1)))
    (:action invariant-1598
        :effect (when (and (not (K_at_p5-6)) (K_at_p6-1)) (K_not_at_p5-6)))
    (:action invariant-1599
        :effect (when (and (not (K_at_p6-1)) (K_at_p5-5)) (K_not_at_p6-1)))
    (:action invariant-1600
        :effect (when (and (not (K_at_p5-5)) (K_at_p6-1)) (K_not_at_p5-5)))
    (:action invariant-1601
        :effect (when (and (not (K_at_p6-1)) (K_at_p5-4)) (K_not_at_p6-1)))
    (:action invariant-1602
        :effect (when (and (not (K_at_p5-4)) (K_at_p6-1)) (K_not_at_p5-4)))
    (:action invariant-1603
        :effect (when (and (not (K_at_p6-1)) (K_at_p5-3)) (K_not_at_p6-1)))
    (:action invariant-1604
        :effect (when (and (not (K_at_p5-3)) (K_at_p6-1)) (K_not_at_p5-3)))
    (:action invariant-1605
        :effect (when (and (not (K_at_p6-1)) (K_at_p5-2)) (K_not_at_p6-1)))
    (:action invariant-1606
        :effect (when (and (not (K_at_p5-2)) (K_at_p6-1)) (K_not_at_p5-2)))
    (:action invariant-1607
        :effect (when (and (not (K_at_p6-1)) (K_at_p5-1)) (K_not_at_p6-1)))
    (:action invariant-1608
        :effect (when (and (not (K_at_p5-1)) (K_at_p6-1)) (K_not_at_p5-1)))
    (:action invariant-1609
        :effect (when (and (not (K_at_p6-1)) (K_at_p4-7)) (K_not_at_p6-1)))
    (:action invariant-1610
        :effect (when (and (not (K_at_p4-7)) (K_at_p6-1)) (K_not_at_p4-7)))
    (:action invariant-1611
        :effect (when (and (not (K_at_p6-1)) (K_at_p4-6)) (K_not_at_p6-1)))
    (:action invariant-1612
        :effect (when (and (not (K_at_p4-6)) (K_at_p6-1)) (K_not_at_p4-6)))
    (:action invariant-1613
        :effect (when (and (not (K_at_p6-1)) (K_at_p4-5)) (K_not_at_p6-1)))
    (:action invariant-1614
        :effect (when (and (not (K_at_p4-5)) (K_at_p6-1)) (K_not_at_p4-5)))
    (:action invariant-1615
        :effect (when (and (not (K_at_p6-1)) (K_at_p4-4)) (K_not_at_p6-1)))
    (:action invariant-1616
        :effect (when (and (not (K_at_p4-4)) (K_at_p6-1)) (K_not_at_p4-4)))
    (:action invariant-1617
        :effect (when (and (not (K_at_p6-1)) (K_at_p4-3)) (K_not_at_p6-1)))
    (:action invariant-1618
        :effect (when (and (not (K_at_p4-3)) (K_at_p6-1)) (K_not_at_p4-3)))
    (:action invariant-1619
        :effect (when (and (not (K_at_p6-1)) (K_at_p4-2)) (K_not_at_p6-1)))
    (:action invariant-1620
        :effect (when (and (not (K_at_p4-2)) (K_at_p6-1)) (K_not_at_p4-2)))
    (:action invariant-1621
        :effect (when (and (not (K_at_p6-1)) (K_at_p4-1)) (K_not_at_p6-1)))
    (:action invariant-1622
        :effect (when (and (not (K_at_p4-1)) (K_at_p6-1)) (K_not_at_p4-1)))
    (:action invariant-1623
        :effect (when (and (not (K_at_p6-1)) (K_at_p3-7)) (K_not_at_p6-1)))
    (:action invariant-1624
        :effect (when (and (not (K_at_p3-7)) (K_at_p6-1)) (K_not_at_p3-7)))
    (:action invariant-1625
        :effect (when (and (not (K_at_p6-1)) (K_at_p3-6)) (K_not_at_p6-1)))
    (:action invariant-1626
        :effect (when (and (not (K_at_p3-6)) (K_at_p6-1)) (K_not_at_p3-6)))
    (:action invariant-1627
        :effect (when (and (not (K_at_p6-1)) (K_at_p3-5)) (K_not_at_p6-1)))
    (:action invariant-1628
        :effect (when (and (not (K_at_p3-5)) (K_at_p6-1)) (K_not_at_p3-5)))
    (:action invariant-1629
        :effect (when (and (not (K_at_p6-1)) (K_at_p3-4)) (K_not_at_p6-1)))
    (:action invariant-1630
        :effect (when (and (not (K_at_p3-4)) (K_at_p6-1)) (K_not_at_p3-4)))
    (:action invariant-1631
        :effect (when (and (not (K_at_p6-1)) (K_at_p3-3)) (K_not_at_p6-1)))
    (:action invariant-1632
        :effect (when (and (not (K_at_p3-3)) (K_at_p6-1)) (K_not_at_p3-3)))
    (:action invariant-1633
        :effect (when (and (not (K_at_p6-1)) (K_at_p3-2)) (K_not_at_p6-1)))
    (:action invariant-1634
        :effect (when (and (not (K_at_p3-2)) (K_at_p6-1)) (K_not_at_p3-2)))
    (:action invariant-1635
        :effect (when (and (not (K_at_p6-1)) (K_at_p3-1)) (K_not_at_p6-1)))
    (:action invariant-1636
        :effect (when (and (not (K_at_p3-1)) (K_at_p6-1)) (K_not_at_p3-1)))
    (:action invariant-1637
        :effect (when (and (not (K_at_p6-1)) (K_at_p2-7)) (K_not_at_p6-1)))
    (:action invariant-1638
        :effect (when (and (not (K_at_p2-7)) (K_at_p6-1)) (K_not_at_p2-7)))
    (:action invariant-1639
        :effect (when (and (not (K_at_p6-1)) (K_at_p2-6)) (K_not_at_p6-1)))
    (:action invariant-1640
        :effect (when (and (not (K_at_p2-6)) (K_at_p6-1)) (K_not_at_p2-6)))
    (:action invariant-1641
        :effect (when (and (not (K_at_p6-1)) (K_at_p2-5)) (K_not_at_p6-1)))
    (:action invariant-1642
        :effect (when (and (not (K_at_p2-5)) (K_at_p6-1)) (K_not_at_p2-5)))
    (:action invariant-1643
        :effect (when (and (not (K_at_p6-1)) (K_at_p2-4)) (K_not_at_p6-1)))
    (:action invariant-1644
        :effect (when (and (not (K_at_p2-4)) (K_at_p6-1)) (K_not_at_p2-4)))
    (:action invariant-1645
        :effect (when (and (not (K_at_p6-1)) (K_at_p2-3)) (K_not_at_p6-1)))
    (:action invariant-1646
        :effect (when (and (not (K_at_p2-3)) (K_at_p6-1)) (K_not_at_p2-3)))
    (:action invariant-1647
        :effect (when (and (not (K_at_p6-1)) (K_at_p2-2)) (K_not_at_p6-1)))
    (:action invariant-1648
        :effect (when (and (not (K_at_p2-2)) (K_at_p6-1)) (K_not_at_p2-2)))
    (:action invariant-1649
        :effect (when (and (not (K_at_p6-1)) (K_at_p2-1)) (K_not_at_p6-1)))
    (:action invariant-1650
        :effect (when (and (not (K_at_p2-1)) (K_at_p6-1)) (K_not_at_p2-1)))
    (:action invariant-1651
        :effect (when (and (not (K_at_p6-1)) (K_at_p1-7)) (K_not_at_p6-1)))
    (:action invariant-1652
        :effect (when (and (not (K_at_p1-7)) (K_at_p6-1)) (K_not_at_p1-7)))
    (:action invariant-1653
        :effect (when (and (not (K_at_p6-1)) (K_at_p1-6)) (K_not_at_p6-1)))
    (:action invariant-1654
        :effect (when (and (not (K_at_p1-6)) (K_at_p6-1)) (K_not_at_p1-6)))
    (:action invariant-1655
        :effect (when (and (not (K_at_p6-1)) (K_at_p1-5)) (K_not_at_p6-1)))
    (:action invariant-1656
        :effect (when (and (not (K_at_p1-5)) (K_at_p6-1)) (K_not_at_p1-5)))
    (:action invariant-1657
        :effect (when (and (not (K_at_p6-1)) (K_at_p1-4)) (K_not_at_p6-1)))
    (:action invariant-1658
        :effect (when (and (not (K_at_p1-4)) (K_at_p6-1)) (K_not_at_p1-4)))
    (:action invariant-1659
        :effect (when (and (not (K_at_p6-1)) (K_at_p1-3)) (K_not_at_p6-1)))
    (:action invariant-1660
        :effect (when (and (not (K_at_p1-3)) (K_at_p6-1)) (K_not_at_p1-3)))
    (:action invariant-1661
        :effect (when (and (not (K_at_p6-1)) (K_at_p1-2)) (K_not_at_p6-1)))
    (:action invariant-1662
        :effect (when (and (not (K_at_p1-2)) (K_at_p6-1)) (K_not_at_p1-2)))
    (:action invariant-1663
        :effect (when (and (not (K_at_p6-1)) (K_at_p1-1)) (K_not_at_p6-1)))
    (:action invariant-1664
        :effect (when (and (not (K_at_p1-1)) (K_at_p6-1)) (K_not_at_p1-1)))
    (:action invariant-1665
        :effect (when (and (not (K_at_p5-7)) (K_at_p5-6)) (K_not_at_p5-7)))
    (:action invariant-1666
        :effect (when (and (not (K_at_p5-6)) (K_at_p5-7)) (K_not_at_p5-6)))
    (:action invariant-1667
        :effect (when (and (not (K_at_p5-7)) (K_at_p5-5)) (K_not_at_p5-7)))
    (:action invariant-1668
        :effect (when (and (not (K_at_p5-5)) (K_at_p5-7)) (K_not_at_p5-5)))
    (:action invariant-1669
        :effect (when (and (not (K_at_p5-7)) (K_at_p5-4)) (K_not_at_p5-7)))
    (:action invariant-1670
        :effect (when (and (not (K_at_p5-4)) (K_at_p5-7)) (K_not_at_p5-4)))
    (:action invariant-1671
        :effect (when (and (not (K_at_p5-7)) (K_at_p5-3)) (K_not_at_p5-7)))
    (:action invariant-1672
        :effect (when (and (not (K_at_p5-3)) (K_at_p5-7)) (K_not_at_p5-3)))
    (:action invariant-1673
        :effect (when (and (not (K_at_p5-7)) (K_at_p5-2)) (K_not_at_p5-7)))
    (:action invariant-1674
        :effect (when (and (not (K_at_p5-2)) (K_at_p5-7)) (K_not_at_p5-2)))
    (:action invariant-1675
        :effect (when (and (not (K_at_p5-7)) (K_at_p5-1)) (K_not_at_p5-7)))
    (:action invariant-1676
        :effect (when (and (not (K_at_p5-1)) (K_at_p5-7)) (K_not_at_p5-1)))
    (:action invariant-1677
        :effect (when (and (not (K_at_p5-7)) (K_at_p4-7)) (K_not_at_p5-7)))
    (:action invariant-1678
        :effect (when (and (not (K_at_p4-7)) (K_at_p5-7)) (K_not_at_p4-7)))
    (:action invariant-1679
        :effect (when (and (not (K_at_p5-7)) (K_at_p4-6)) (K_not_at_p5-7)))
    (:action invariant-1680
        :effect (when (and (not (K_at_p4-6)) (K_at_p5-7)) (K_not_at_p4-6)))
    (:action invariant-1681
        :effect (when (and (not (K_at_p5-7)) (K_at_p4-5)) (K_not_at_p5-7)))
    (:action invariant-1682
        :effect (when (and (not (K_at_p4-5)) (K_at_p5-7)) (K_not_at_p4-5)))
    (:action invariant-1683
        :effect (when (and (not (K_at_p5-7)) (K_at_p4-4)) (K_not_at_p5-7)))
    (:action invariant-1684
        :effect (when (and (not (K_at_p4-4)) (K_at_p5-7)) (K_not_at_p4-4)))
    (:action invariant-1685
        :effect (when (and (not (K_at_p5-7)) (K_at_p4-3)) (K_not_at_p5-7)))
    (:action invariant-1686
        :effect (when (and (not (K_at_p4-3)) (K_at_p5-7)) (K_not_at_p4-3)))
    (:action invariant-1687
        :effect (when (and (not (K_at_p5-7)) (K_at_p4-2)) (K_not_at_p5-7)))
    (:action invariant-1688
        :effect (when (and (not (K_at_p4-2)) (K_at_p5-7)) (K_not_at_p4-2)))
    (:action invariant-1689
        :effect (when (and (not (K_at_p5-7)) (K_at_p4-1)) (K_not_at_p5-7)))
    (:action invariant-1690
        :effect (when (and (not (K_at_p4-1)) (K_at_p5-7)) (K_not_at_p4-1)))
    (:action invariant-1691
        :effect (when (and (not (K_at_p5-7)) (K_at_p3-7)) (K_not_at_p5-7)))
    (:action invariant-1692
        :effect (when (and (not (K_at_p3-7)) (K_at_p5-7)) (K_not_at_p3-7)))
    (:action invariant-1693
        :effect (when (and (not (K_at_p5-7)) (K_at_p3-6)) (K_not_at_p5-7)))
    (:action invariant-1694
        :effect (when (and (not (K_at_p3-6)) (K_at_p5-7)) (K_not_at_p3-6)))
    (:action invariant-1695
        :effect (when (and (not (K_at_p5-7)) (K_at_p3-5)) (K_not_at_p5-7)))
    (:action invariant-1696
        :effect (when (and (not (K_at_p3-5)) (K_at_p5-7)) (K_not_at_p3-5)))
    (:action invariant-1697
        :effect (when (and (not (K_at_p5-7)) (K_at_p3-4)) (K_not_at_p5-7)))
    (:action invariant-1698
        :effect (when (and (not (K_at_p3-4)) (K_at_p5-7)) (K_not_at_p3-4)))
    (:action invariant-1699
        :effect (when (and (not (K_at_p5-7)) (K_at_p3-3)) (K_not_at_p5-7)))
    (:action invariant-1700
        :effect (when (and (not (K_at_p3-3)) (K_at_p5-7)) (K_not_at_p3-3)))
    (:action invariant-1701
        :effect (when (and (not (K_at_p5-7)) (K_at_p3-2)) (K_not_at_p5-7)))
    (:action invariant-1702
        :effect (when (and (not (K_at_p3-2)) (K_at_p5-7)) (K_not_at_p3-2)))
    (:action invariant-1703
        :effect (when (and (not (K_at_p5-7)) (K_at_p3-1)) (K_not_at_p5-7)))
    (:action invariant-1704
        :effect (when (and (not (K_at_p3-1)) (K_at_p5-7)) (K_not_at_p3-1)))
    (:action invariant-1705
        :effect (when (and (not (K_at_p5-7)) (K_at_p2-7)) (K_not_at_p5-7)))
    (:action invariant-1706
        :effect (when (and (not (K_at_p2-7)) (K_at_p5-7)) (K_not_at_p2-7)))
    (:action invariant-1707
        :effect (when (and (not (K_at_p5-7)) (K_at_p2-6)) (K_not_at_p5-7)))
    (:action invariant-1708
        :effect (when (and (not (K_at_p2-6)) (K_at_p5-7)) (K_not_at_p2-6)))
    (:action invariant-1709
        :effect (when (and (not (K_at_p5-7)) (K_at_p2-5)) (K_not_at_p5-7)))
    (:action invariant-1710
        :effect (when (and (not (K_at_p2-5)) (K_at_p5-7)) (K_not_at_p2-5)))
    (:action invariant-1711
        :effect (when (and (not (K_at_p5-7)) (K_at_p2-4)) (K_not_at_p5-7)))
    (:action invariant-1712
        :effect (when (and (not (K_at_p2-4)) (K_at_p5-7)) (K_not_at_p2-4)))
    (:action invariant-1713
        :effect (when (and (not (K_at_p5-7)) (K_at_p2-3)) (K_not_at_p5-7)))
    (:action invariant-1714
        :effect (when (and (not (K_at_p2-3)) (K_at_p5-7)) (K_not_at_p2-3)))
    (:action invariant-1715
        :effect (when (and (not (K_at_p5-7)) (K_at_p2-2)) (K_not_at_p5-7)))
    (:action invariant-1716
        :effect (when (and (not (K_at_p2-2)) (K_at_p5-7)) (K_not_at_p2-2)))
    (:action invariant-1717
        :effect (when (and (not (K_at_p5-7)) (K_at_p2-1)) (K_not_at_p5-7)))
    (:action invariant-1718
        :effect (when (and (not (K_at_p2-1)) (K_at_p5-7)) (K_not_at_p2-1)))
    (:action invariant-1719
        :effect (when (and (not (K_at_p5-7)) (K_at_p1-7)) (K_not_at_p5-7)))
    (:action invariant-1720
        :effect (when (and (not (K_at_p1-7)) (K_at_p5-7)) (K_not_at_p1-7)))
    (:action invariant-1721
        :effect (when (and (not (K_at_p5-7)) (K_at_p1-6)) (K_not_at_p5-7)))
    (:action invariant-1722
        :effect (when (and (not (K_at_p1-6)) (K_at_p5-7)) (K_not_at_p1-6)))
    (:action invariant-1723
        :effect (when (and (not (K_at_p5-7)) (K_at_p1-5)) (K_not_at_p5-7)))
    (:action invariant-1724
        :effect (when (and (not (K_at_p1-5)) (K_at_p5-7)) (K_not_at_p1-5)))
    (:action invariant-1725
        :effect (when (and (not (K_at_p5-7)) (K_at_p1-4)) (K_not_at_p5-7)))
    (:action invariant-1726
        :effect (when (and (not (K_at_p1-4)) (K_at_p5-7)) (K_not_at_p1-4)))
    (:action invariant-1727
        :effect (when (and (not (K_at_p5-7)) (K_at_p1-3)) (K_not_at_p5-7)))
    (:action invariant-1728
        :effect (when (and (not (K_at_p1-3)) (K_at_p5-7)) (K_not_at_p1-3)))
    (:action invariant-1729
        :effect (when (and (not (K_at_p5-7)) (K_at_p1-2)) (K_not_at_p5-7)))
    (:action invariant-1730
        :effect (when (and (not (K_at_p1-2)) (K_at_p5-7)) (K_not_at_p1-2)))
    (:action invariant-1731
        :effect (when (and (not (K_at_p5-7)) (K_at_p1-1)) (K_not_at_p5-7)))
    (:action invariant-1732
        :effect (when (and (not (K_at_p1-1)) (K_at_p5-7)) (K_not_at_p1-1)))
    (:action invariant-1733
        :effect (when (and (not (K_at_p5-6)) (K_at_p5-5)) (K_not_at_p5-6)))
    (:action invariant-1734
        :effect (when (and (not (K_at_p5-5)) (K_at_p5-6)) (K_not_at_p5-5)))
    (:action invariant-1735
        :effect (when (and (not (K_at_p5-6)) (K_at_p5-4)) (K_not_at_p5-6)))
    (:action invariant-1736
        :effect (when (and (not (K_at_p5-4)) (K_at_p5-6)) (K_not_at_p5-4)))
    (:action invariant-1737
        :effect (when (and (not (K_at_p5-6)) (K_at_p5-3)) (K_not_at_p5-6)))
    (:action invariant-1738
        :effect (when (and (not (K_at_p5-3)) (K_at_p5-6)) (K_not_at_p5-3)))
    (:action invariant-1739
        :effect (when (and (not (K_at_p5-6)) (K_at_p5-2)) (K_not_at_p5-6)))
    (:action invariant-1740
        :effect (when (and (not (K_at_p5-2)) (K_at_p5-6)) (K_not_at_p5-2)))
    (:action invariant-1741
        :effect (when (and (not (K_at_p5-6)) (K_at_p5-1)) (K_not_at_p5-6)))
    (:action invariant-1742
        :effect (when (and (not (K_at_p5-1)) (K_at_p5-6)) (K_not_at_p5-1)))
    (:action invariant-1743
        :effect (when (and (not (K_at_p5-6)) (K_at_p4-7)) (K_not_at_p5-6)))
    (:action invariant-1744
        :effect (when (and (not (K_at_p4-7)) (K_at_p5-6)) (K_not_at_p4-7)))
    (:action invariant-1745
        :effect (when (and (not (K_at_p5-6)) (K_at_p4-6)) (K_not_at_p5-6)))
    (:action invariant-1746
        :effect (when (and (not (K_at_p4-6)) (K_at_p5-6)) (K_not_at_p4-6)))
    (:action invariant-1747
        :effect (when (and (not (K_at_p5-6)) (K_at_p4-5)) (K_not_at_p5-6)))
    (:action invariant-1748
        :effect (when (and (not (K_at_p4-5)) (K_at_p5-6)) (K_not_at_p4-5)))
    (:action invariant-1749
        :effect (when (and (not (K_at_p5-6)) (K_at_p4-4)) (K_not_at_p5-6)))
    (:action invariant-1750
        :effect (when (and (not (K_at_p4-4)) (K_at_p5-6)) (K_not_at_p4-4)))
    (:action invariant-1751
        :effect (when (and (not (K_at_p5-6)) (K_at_p4-3)) (K_not_at_p5-6)))
    (:action invariant-1752
        :effect (when (and (not (K_at_p4-3)) (K_at_p5-6)) (K_not_at_p4-3)))
    (:action invariant-1753
        :effect (when (and (not (K_at_p5-6)) (K_at_p4-2)) (K_not_at_p5-6)))
    (:action invariant-1754
        :effect (when (and (not (K_at_p4-2)) (K_at_p5-6)) (K_not_at_p4-2)))
    (:action invariant-1755
        :effect (when (and (not (K_at_p5-6)) (K_at_p4-1)) (K_not_at_p5-6)))
    (:action invariant-1756
        :effect (when (and (not (K_at_p4-1)) (K_at_p5-6)) (K_not_at_p4-1)))
    (:action invariant-1757
        :effect (when (and (not (K_at_p5-6)) (K_at_p3-7)) (K_not_at_p5-6)))
    (:action invariant-1758
        :effect (when (and (not (K_at_p3-7)) (K_at_p5-6)) (K_not_at_p3-7)))
    (:action invariant-1759
        :effect (when (and (not (K_at_p5-6)) (K_at_p3-6)) (K_not_at_p5-6)))
    (:action invariant-1760
        :effect (when (and (not (K_at_p3-6)) (K_at_p5-6)) (K_not_at_p3-6)))
    (:action invariant-1761
        :effect (when (and (not (K_at_p5-6)) (K_at_p3-5)) (K_not_at_p5-6)))
    (:action invariant-1762
        :effect (when (and (not (K_at_p3-5)) (K_at_p5-6)) (K_not_at_p3-5)))
    (:action invariant-1763
        :effect (when (and (not (K_at_p5-6)) (K_at_p3-4)) (K_not_at_p5-6)))
    (:action invariant-1764
        :effect (when (and (not (K_at_p3-4)) (K_at_p5-6)) (K_not_at_p3-4)))
    (:action invariant-1765
        :effect (when (and (not (K_at_p5-6)) (K_at_p3-3)) (K_not_at_p5-6)))
    (:action invariant-1766
        :effect (when (and (not (K_at_p3-3)) (K_at_p5-6)) (K_not_at_p3-3)))
    (:action invariant-1767
        :effect (when (and (not (K_at_p5-6)) (K_at_p3-2)) (K_not_at_p5-6)))
    (:action invariant-1768
        :effect (when (and (not (K_at_p3-2)) (K_at_p5-6)) (K_not_at_p3-2)))
    (:action invariant-1769
        :effect (when (and (not (K_at_p5-6)) (K_at_p3-1)) (K_not_at_p5-6)))
    (:action invariant-1770
        :effect (when (and (not (K_at_p3-1)) (K_at_p5-6)) (K_not_at_p3-1)))
    (:action invariant-1771
        :effect (when (and (not (K_at_p5-6)) (K_at_p2-7)) (K_not_at_p5-6)))
    (:action invariant-1772
        :effect (when (and (not (K_at_p2-7)) (K_at_p5-6)) (K_not_at_p2-7)))
    (:action invariant-1773
        :effect (when (and (not (K_at_p5-6)) (K_at_p2-6)) (K_not_at_p5-6)))
    (:action invariant-1774
        :effect (when (and (not (K_at_p2-6)) (K_at_p5-6)) (K_not_at_p2-6)))
    (:action invariant-1775
        :effect (when (and (not (K_at_p5-6)) (K_at_p2-5)) (K_not_at_p5-6)))
    (:action invariant-1776
        :effect (when (and (not (K_at_p2-5)) (K_at_p5-6)) (K_not_at_p2-5)))
    (:action invariant-1777
        :effect (when (and (not (K_at_p5-6)) (K_at_p2-4)) (K_not_at_p5-6)))
    (:action invariant-1778
        :effect (when (and (not (K_at_p2-4)) (K_at_p5-6)) (K_not_at_p2-4)))
    (:action invariant-1779
        :effect (when (and (not (K_at_p5-6)) (K_at_p2-3)) (K_not_at_p5-6)))
    (:action invariant-1780
        :effect (when (and (not (K_at_p2-3)) (K_at_p5-6)) (K_not_at_p2-3)))
    (:action invariant-1781
        :effect (when (and (not (K_at_p5-6)) (K_at_p2-2)) (K_not_at_p5-6)))
    (:action invariant-1782
        :effect (when (and (not (K_at_p2-2)) (K_at_p5-6)) (K_not_at_p2-2)))
    (:action invariant-1783
        :effect (when (and (not (K_at_p5-6)) (K_at_p2-1)) (K_not_at_p5-6)))
    (:action invariant-1784
        :effect (when (and (not (K_at_p2-1)) (K_at_p5-6)) (K_not_at_p2-1)))
    (:action invariant-1785
        :effect (when (and (not (K_at_p5-6)) (K_at_p1-7)) (K_not_at_p5-6)))
    (:action invariant-1786
        :effect (when (and (not (K_at_p1-7)) (K_at_p5-6)) (K_not_at_p1-7)))
    (:action invariant-1787
        :effect (when (and (not (K_at_p5-6)) (K_at_p1-6)) (K_not_at_p5-6)))
    (:action invariant-1788
        :effect (when (and (not (K_at_p1-6)) (K_at_p5-6)) (K_not_at_p1-6)))
    (:action invariant-1789
        :effect (when (and (not (K_at_p5-6)) (K_at_p1-5)) (K_not_at_p5-6)))
    (:action invariant-1790
        :effect (when (and (not (K_at_p1-5)) (K_at_p5-6)) (K_not_at_p1-5)))
    (:action invariant-1791
        :effect (when (and (not (K_at_p5-6)) (K_at_p1-4)) (K_not_at_p5-6)))
    (:action invariant-1792
        :effect (when (and (not (K_at_p1-4)) (K_at_p5-6)) (K_not_at_p1-4)))
    (:action invariant-1793
        :effect (when (and (not (K_at_p5-6)) (K_at_p1-3)) (K_not_at_p5-6)))
    (:action invariant-1794
        :effect (when (and (not (K_at_p1-3)) (K_at_p5-6)) (K_not_at_p1-3)))
    (:action invariant-1795
        :effect (when (and (not (K_at_p5-6)) (K_at_p1-2)) (K_not_at_p5-6)))
    (:action invariant-1796
        :effect (when (and (not (K_at_p1-2)) (K_at_p5-6)) (K_not_at_p1-2)))
    (:action invariant-1797
        :effect (when (and (not (K_at_p5-6)) (K_at_p1-1)) (K_not_at_p5-6)))
    (:action invariant-1798
        :effect (when (and (not (K_at_p1-1)) (K_at_p5-6)) (K_not_at_p1-1)))
    (:action invariant-1799
        :effect (when (and (not (K_at_p5-5)) (K_at_p5-4)) (K_not_at_p5-5)))
    (:action invariant-1800
        :effect (when (and (not (K_at_p5-4)) (K_at_p5-5)) (K_not_at_p5-4)))
    (:action invariant-1801
        :effect (when (and (not (K_at_p5-5)) (K_at_p5-3)) (K_not_at_p5-5)))
    (:action invariant-1802
        :effect (when (and (not (K_at_p5-3)) (K_at_p5-5)) (K_not_at_p5-3)))
    (:action invariant-1803
        :effect (when (and (not (K_at_p5-5)) (K_at_p5-2)) (K_not_at_p5-5)))
    (:action invariant-1804
        :effect (when (and (not (K_at_p5-2)) (K_at_p5-5)) (K_not_at_p5-2)))
    (:action invariant-1805
        :effect (when (and (not (K_at_p5-5)) (K_at_p5-1)) (K_not_at_p5-5)))
    (:action invariant-1806
        :effect (when (and (not (K_at_p5-1)) (K_at_p5-5)) (K_not_at_p5-1)))
    (:action invariant-1807
        :effect (when (and (not (K_at_p5-5)) (K_at_p4-7)) (K_not_at_p5-5)))
    (:action invariant-1808
        :effect (when (and (not (K_at_p4-7)) (K_at_p5-5)) (K_not_at_p4-7)))
    (:action invariant-1809
        :effect (when (and (not (K_at_p5-5)) (K_at_p4-6)) (K_not_at_p5-5)))
    (:action invariant-1810
        :effect (when (and (not (K_at_p4-6)) (K_at_p5-5)) (K_not_at_p4-6)))
    (:action invariant-1811
        :effect (when (and (not (K_at_p5-5)) (K_at_p4-5)) (K_not_at_p5-5)))
    (:action invariant-1812
        :effect (when (and (not (K_at_p4-5)) (K_at_p5-5)) (K_not_at_p4-5)))
    (:action invariant-1813
        :effect (when (and (not (K_at_p5-5)) (K_at_p4-4)) (K_not_at_p5-5)))
    (:action invariant-1814
        :effect (when (and (not (K_at_p4-4)) (K_at_p5-5)) (K_not_at_p4-4)))
    (:action invariant-1815
        :effect (when (and (not (K_at_p5-5)) (K_at_p4-3)) (K_not_at_p5-5)))
    (:action invariant-1816
        :effect (when (and (not (K_at_p4-3)) (K_at_p5-5)) (K_not_at_p4-3)))
    (:action invariant-1817
        :effect (when (and (not (K_at_p5-5)) (K_at_p4-2)) (K_not_at_p5-5)))
    (:action invariant-1818
        :effect (when (and (not (K_at_p4-2)) (K_at_p5-5)) (K_not_at_p4-2)))
    (:action invariant-1819
        :effect (when (and (not (K_at_p5-5)) (K_at_p4-1)) (K_not_at_p5-5)))
    (:action invariant-1820
        :effect (when (and (not (K_at_p4-1)) (K_at_p5-5)) (K_not_at_p4-1)))
    (:action invariant-1821
        :effect (when (and (not (K_at_p5-5)) (K_at_p3-7)) (K_not_at_p5-5)))
    (:action invariant-1822
        :effect (when (and (not (K_at_p3-7)) (K_at_p5-5)) (K_not_at_p3-7)))
    (:action invariant-1823
        :effect (when (and (not (K_at_p5-5)) (K_at_p3-6)) (K_not_at_p5-5)))
    (:action invariant-1824
        :effect (when (and (not (K_at_p3-6)) (K_at_p5-5)) (K_not_at_p3-6)))
    (:action invariant-1825
        :effect (when (and (not (K_at_p5-5)) (K_at_p3-5)) (K_not_at_p5-5)))
    (:action invariant-1826
        :effect (when (and (not (K_at_p3-5)) (K_at_p5-5)) (K_not_at_p3-5)))
    (:action invariant-1827
        :effect (when (and (not (K_at_p5-5)) (K_at_p3-4)) (K_not_at_p5-5)))
    (:action invariant-1828
        :effect (when (and (not (K_at_p3-4)) (K_at_p5-5)) (K_not_at_p3-4)))
    (:action invariant-1829
        :effect (when (and (not (K_at_p5-5)) (K_at_p3-3)) (K_not_at_p5-5)))
    (:action invariant-1830
        :effect (when (and (not (K_at_p3-3)) (K_at_p5-5)) (K_not_at_p3-3)))
    (:action invariant-1831
        :effect (when (and (not (K_at_p5-5)) (K_at_p3-2)) (K_not_at_p5-5)))
    (:action invariant-1832
        :effect (when (and (not (K_at_p3-2)) (K_at_p5-5)) (K_not_at_p3-2)))
    (:action invariant-1833
        :effect (when (and (not (K_at_p5-5)) (K_at_p3-1)) (K_not_at_p5-5)))
    (:action invariant-1834
        :effect (when (and (not (K_at_p3-1)) (K_at_p5-5)) (K_not_at_p3-1)))
    (:action invariant-1835
        :effect (when (and (not (K_at_p5-5)) (K_at_p2-7)) (K_not_at_p5-5)))
    (:action invariant-1836
        :effect (when (and (not (K_at_p2-7)) (K_at_p5-5)) (K_not_at_p2-7)))
    (:action invariant-1837
        :effect (when (and (not (K_at_p5-5)) (K_at_p2-6)) (K_not_at_p5-5)))
    (:action invariant-1838
        :effect (when (and (not (K_at_p2-6)) (K_at_p5-5)) (K_not_at_p2-6)))
    (:action invariant-1839
        :effect (when (and (not (K_at_p5-5)) (K_at_p2-5)) (K_not_at_p5-5)))
    (:action invariant-1840
        :effect (when (and (not (K_at_p2-5)) (K_at_p5-5)) (K_not_at_p2-5)))
    (:action invariant-1841
        :effect (when (and (not (K_at_p5-5)) (K_at_p2-4)) (K_not_at_p5-5)))
    (:action invariant-1842
        :effect (when (and (not (K_at_p2-4)) (K_at_p5-5)) (K_not_at_p2-4)))
    (:action invariant-1843
        :effect (when (and (not (K_at_p5-5)) (K_at_p2-3)) (K_not_at_p5-5)))
    (:action invariant-1844
        :effect (when (and (not (K_at_p2-3)) (K_at_p5-5)) (K_not_at_p2-3)))
    (:action invariant-1845
        :effect (when (and (not (K_at_p5-5)) (K_at_p2-2)) (K_not_at_p5-5)))
    (:action invariant-1846
        :effect (when (and (not (K_at_p2-2)) (K_at_p5-5)) (K_not_at_p2-2)))
    (:action invariant-1847
        :effect (when (and (not (K_at_p5-5)) (K_at_p2-1)) (K_not_at_p5-5)))
    (:action invariant-1848
        :effect (when (and (not (K_at_p2-1)) (K_at_p5-5)) (K_not_at_p2-1)))
    (:action invariant-1849
        :effect (when (and (not (K_at_p5-5)) (K_at_p1-7)) (K_not_at_p5-5)))
    (:action invariant-1850
        :effect (when (and (not (K_at_p1-7)) (K_at_p5-5)) (K_not_at_p1-7)))
    (:action invariant-1851
        :effect (when (and (not (K_at_p5-5)) (K_at_p1-6)) (K_not_at_p5-5)))
    (:action invariant-1852
        :effect (when (and (not (K_at_p1-6)) (K_at_p5-5)) (K_not_at_p1-6)))
    (:action invariant-1853
        :effect (when (and (not (K_at_p5-5)) (K_at_p1-5)) (K_not_at_p5-5)))
    (:action invariant-1854
        :effect (when (and (not (K_at_p1-5)) (K_at_p5-5)) (K_not_at_p1-5)))
    (:action invariant-1855
        :effect (when (and (not (K_at_p5-5)) (K_at_p1-4)) (K_not_at_p5-5)))
    (:action invariant-1856
        :effect (when (and (not (K_at_p1-4)) (K_at_p5-5)) (K_not_at_p1-4)))
    (:action invariant-1857
        :effect (when (and (not (K_at_p5-5)) (K_at_p1-3)) (K_not_at_p5-5)))
    (:action invariant-1858
        :effect (when (and (not (K_at_p1-3)) (K_at_p5-5)) (K_not_at_p1-3)))
    (:action invariant-1859
        :effect (when (and (not (K_at_p5-5)) (K_at_p1-2)) (K_not_at_p5-5)))
    (:action invariant-1860
        :effect (when (and (not (K_at_p1-2)) (K_at_p5-5)) (K_not_at_p1-2)))
    (:action invariant-1861
        :effect (when (and (not (K_at_p5-5)) (K_at_p1-1)) (K_not_at_p5-5)))
    (:action invariant-1862
        :effect (when (and (not (K_at_p1-1)) (K_at_p5-5)) (K_not_at_p1-1)))
    (:action invariant-1863
        :effect (when (and (not (K_at_p5-4)) (K_at_p5-3)) (K_not_at_p5-4)))
    (:action invariant-1864
        :effect (when (and (not (K_at_p5-3)) (K_at_p5-4)) (K_not_at_p5-3)))
    (:action invariant-1865
        :effect (when (and (not (K_at_p5-4)) (K_at_p5-2)) (K_not_at_p5-4)))
    (:action invariant-1866
        :effect (when (and (not (K_at_p5-2)) (K_at_p5-4)) (K_not_at_p5-2)))
    (:action invariant-1867
        :effect (when (and (not (K_at_p5-4)) (K_at_p5-1)) (K_not_at_p5-4)))
    (:action invariant-1868
        :effect (when (and (not (K_at_p5-1)) (K_at_p5-4)) (K_not_at_p5-1)))
    (:action invariant-1869
        :effect (when (and (not (K_at_p5-4)) (K_at_p4-7)) (K_not_at_p5-4)))
    (:action invariant-1870
        :effect (when (and (not (K_at_p4-7)) (K_at_p5-4)) (K_not_at_p4-7)))
    (:action invariant-1871
        :effect (when (and (not (K_at_p5-4)) (K_at_p4-6)) (K_not_at_p5-4)))
    (:action invariant-1872
        :effect (when (and (not (K_at_p4-6)) (K_at_p5-4)) (K_not_at_p4-6)))
    (:action invariant-1873
        :effect (when (and (not (K_at_p5-4)) (K_at_p4-5)) (K_not_at_p5-4)))
    (:action invariant-1874
        :effect (when (and (not (K_at_p4-5)) (K_at_p5-4)) (K_not_at_p4-5)))
    (:action invariant-1875
        :effect (when (and (not (K_at_p5-4)) (K_at_p4-4)) (K_not_at_p5-4)))
    (:action invariant-1876
        :effect (when (and (not (K_at_p4-4)) (K_at_p5-4)) (K_not_at_p4-4)))
    (:action invariant-1877
        :effect (when (and (not (K_at_p5-4)) (K_at_p4-3)) (K_not_at_p5-4)))
    (:action invariant-1878
        :effect (when (and (not (K_at_p4-3)) (K_at_p5-4)) (K_not_at_p4-3)))
    (:action invariant-1879
        :effect (when (and (not (K_at_p5-4)) (K_at_p4-2)) (K_not_at_p5-4)))
    (:action invariant-1880
        :effect (when (and (not (K_at_p4-2)) (K_at_p5-4)) (K_not_at_p4-2)))
    (:action invariant-1881
        :effect (when (and (not (K_at_p5-4)) (K_at_p4-1)) (K_not_at_p5-4)))
    (:action invariant-1882
        :effect (when (and (not (K_at_p4-1)) (K_at_p5-4)) (K_not_at_p4-1)))
    (:action invariant-1883
        :effect (when (and (not (K_at_p5-4)) (K_at_p3-7)) (K_not_at_p5-4)))
    (:action invariant-1884
        :effect (when (and (not (K_at_p3-7)) (K_at_p5-4)) (K_not_at_p3-7)))
    (:action invariant-1885
        :effect (when (and (not (K_at_p5-4)) (K_at_p3-6)) (K_not_at_p5-4)))
    (:action invariant-1886
        :effect (when (and (not (K_at_p3-6)) (K_at_p5-4)) (K_not_at_p3-6)))
    (:action invariant-1887
        :effect (when (and (not (K_at_p5-4)) (K_at_p3-5)) (K_not_at_p5-4)))
    (:action invariant-1888
        :effect (when (and (not (K_at_p3-5)) (K_at_p5-4)) (K_not_at_p3-5)))
    (:action invariant-1889
        :effect (when (and (not (K_at_p5-4)) (K_at_p3-4)) (K_not_at_p5-4)))
    (:action invariant-1890
        :effect (when (and (not (K_at_p3-4)) (K_at_p5-4)) (K_not_at_p3-4)))
    (:action invariant-1891
        :effect (when (and (not (K_at_p5-4)) (K_at_p3-3)) (K_not_at_p5-4)))
    (:action invariant-1892
        :effect (when (and (not (K_at_p3-3)) (K_at_p5-4)) (K_not_at_p3-3)))
    (:action invariant-1893
        :effect (when (and (not (K_at_p5-4)) (K_at_p3-2)) (K_not_at_p5-4)))
    (:action invariant-1894
        :effect (when (and (not (K_at_p3-2)) (K_at_p5-4)) (K_not_at_p3-2)))
    (:action invariant-1895
        :effect (when (and (not (K_at_p5-4)) (K_at_p3-1)) (K_not_at_p5-4)))
    (:action invariant-1896
        :effect (when (and (not (K_at_p3-1)) (K_at_p5-4)) (K_not_at_p3-1)))
    (:action invariant-1897
        :effect (when (and (not (K_at_p5-4)) (K_at_p2-7)) (K_not_at_p5-4)))
    (:action invariant-1898
        :effect (when (and (not (K_at_p2-7)) (K_at_p5-4)) (K_not_at_p2-7)))
    (:action invariant-1899
        :effect (when (and (not (K_at_p5-4)) (K_at_p2-6)) (K_not_at_p5-4)))
    (:action invariant-1900
        :effect (when (and (not (K_at_p2-6)) (K_at_p5-4)) (K_not_at_p2-6)))
    (:action invariant-1901
        :effect (when (and (not (K_at_p5-4)) (K_at_p2-5)) (K_not_at_p5-4)))
    (:action invariant-1902
        :effect (when (and (not (K_at_p2-5)) (K_at_p5-4)) (K_not_at_p2-5)))
    (:action invariant-1903
        :effect (when (and (not (K_at_p5-4)) (K_at_p2-4)) (K_not_at_p5-4)))
    (:action invariant-1904
        :effect (when (and (not (K_at_p2-4)) (K_at_p5-4)) (K_not_at_p2-4)))
    (:action invariant-1905
        :effect (when (and (not (K_at_p5-4)) (K_at_p2-3)) (K_not_at_p5-4)))
    (:action invariant-1906
        :effect (when (and (not (K_at_p2-3)) (K_at_p5-4)) (K_not_at_p2-3)))
    (:action invariant-1907
        :effect (when (and (not (K_at_p5-4)) (K_at_p2-2)) (K_not_at_p5-4)))
    (:action invariant-1908
        :effect (when (and (not (K_at_p2-2)) (K_at_p5-4)) (K_not_at_p2-2)))
    (:action invariant-1909
        :effect (when (and (not (K_at_p5-4)) (K_at_p2-1)) (K_not_at_p5-4)))
    (:action invariant-1910
        :effect (when (and (not (K_at_p2-1)) (K_at_p5-4)) (K_not_at_p2-1)))
    (:action invariant-1911
        :effect (when (and (not (K_at_p5-4)) (K_at_p1-7)) (K_not_at_p5-4)))
    (:action invariant-1912
        :effect (when (and (not (K_at_p1-7)) (K_at_p5-4)) (K_not_at_p1-7)))
    (:action invariant-1913
        :effect (when (and (not (K_at_p5-4)) (K_at_p1-6)) (K_not_at_p5-4)))
    (:action invariant-1914
        :effect (when (and (not (K_at_p1-6)) (K_at_p5-4)) (K_not_at_p1-6)))
    (:action invariant-1915
        :effect (when (and (not (K_at_p5-4)) (K_at_p1-5)) (K_not_at_p5-4)))
    (:action invariant-1916
        :effect (when (and (not (K_at_p1-5)) (K_at_p5-4)) (K_not_at_p1-5)))
    (:action invariant-1917
        :effect (when (and (not (K_at_p5-4)) (K_at_p1-4)) (K_not_at_p5-4)))
    (:action invariant-1918
        :effect (when (and (not (K_at_p1-4)) (K_at_p5-4)) (K_not_at_p1-4)))
    (:action invariant-1919
        :effect (when (and (not (K_at_p5-4)) (K_at_p1-3)) (K_not_at_p5-4)))
    (:action invariant-1920
        :effect (when (and (not (K_at_p1-3)) (K_at_p5-4)) (K_not_at_p1-3)))
    (:action invariant-1921
        :effect (when (and (not (K_at_p5-4)) (K_at_p1-2)) (K_not_at_p5-4)))
    (:action invariant-1922
        :effect (when (and (not (K_at_p1-2)) (K_at_p5-4)) (K_not_at_p1-2)))
    (:action invariant-1923
        :effect (when (and (not (K_at_p5-4)) (K_at_p1-1)) (K_not_at_p5-4)))
    (:action invariant-1924
        :effect (when (and (not (K_at_p1-1)) (K_at_p5-4)) (K_not_at_p1-1)))
    (:action invariant-1925
        :effect (when (and (not (K_at_p5-3)) (K_at_p5-2)) (K_not_at_p5-3)))
    (:action invariant-1926
        :effect (when (and (not (K_at_p5-2)) (K_at_p5-3)) (K_not_at_p5-2)))
    (:action invariant-1927
        :effect (when (and (not (K_at_p5-3)) (K_at_p5-1)) (K_not_at_p5-3)))
    (:action invariant-1928
        :effect (when (and (not (K_at_p5-1)) (K_at_p5-3)) (K_not_at_p5-1)))
    (:action invariant-1929
        :effect (when (and (not (K_at_p5-3)) (K_at_p4-7)) (K_not_at_p5-3)))
    (:action invariant-1930
        :effect (when (and (not (K_at_p4-7)) (K_at_p5-3)) (K_not_at_p4-7)))
    (:action invariant-1931
        :effect (when (and (not (K_at_p5-3)) (K_at_p4-6)) (K_not_at_p5-3)))
    (:action invariant-1932
        :effect (when (and (not (K_at_p4-6)) (K_at_p5-3)) (K_not_at_p4-6)))
    (:action invariant-1933
        :effect (when (and (not (K_at_p5-3)) (K_at_p4-5)) (K_not_at_p5-3)))
    (:action invariant-1934
        :effect (when (and (not (K_at_p4-5)) (K_at_p5-3)) (K_not_at_p4-5)))
    (:action invariant-1935
        :effect (when (and (not (K_at_p5-3)) (K_at_p4-4)) (K_not_at_p5-3)))
    (:action invariant-1936
        :effect (when (and (not (K_at_p4-4)) (K_at_p5-3)) (K_not_at_p4-4)))
    (:action invariant-1937
        :effect (when (and (not (K_at_p5-3)) (K_at_p4-3)) (K_not_at_p5-3)))
    (:action invariant-1938
        :effect (when (and (not (K_at_p4-3)) (K_at_p5-3)) (K_not_at_p4-3)))
    (:action invariant-1939
        :effect (when (and (not (K_at_p5-3)) (K_at_p4-2)) (K_not_at_p5-3)))
    (:action invariant-1940
        :effect (when (and (not (K_at_p4-2)) (K_at_p5-3)) (K_not_at_p4-2)))
    (:action invariant-1941
        :effect (when (and (not (K_at_p5-3)) (K_at_p4-1)) (K_not_at_p5-3)))
    (:action invariant-1942
        :effect (when (and (not (K_at_p4-1)) (K_at_p5-3)) (K_not_at_p4-1)))
    (:action invariant-1943
        :effect (when (and (not (K_at_p5-3)) (K_at_p3-7)) (K_not_at_p5-3)))
    (:action invariant-1944
        :effect (when (and (not (K_at_p3-7)) (K_at_p5-3)) (K_not_at_p3-7)))
    (:action invariant-1945
        :effect (when (and (not (K_at_p5-3)) (K_at_p3-6)) (K_not_at_p5-3)))
    (:action invariant-1946
        :effect (when (and (not (K_at_p3-6)) (K_at_p5-3)) (K_not_at_p3-6)))
    (:action invariant-1947
        :effect (when (and (not (K_at_p5-3)) (K_at_p3-5)) (K_not_at_p5-3)))
    (:action invariant-1948
        :effect (when (and (not (K_at_p3-5)) (K_at_p5-3)) (K_not_at_p3-5)))
    (:action invariant-1949
        :effect (when (and (not (K_at_p5-3)) (K_at_p3-4)) (K_not_at_p5-3)))
    (:action invariant-1950
        :effect (when (and (not (K_at_p3-4)) (K_at_p5-3)) (K_not_at_p3-4)))
    (:action invariant-1951
        :effect (when (and (not (K_at_p5-3)) (K_at_p3-3)) (K_not_at_p5-3)))
    (:action invariant-1952
        :effect (when (and (not (K_at_p3-3)) (K_at_p5-3)) (K_not_at_p3-3)))
    (:action invariant-1953
        :effect (when (and (not (K_at_p5-3)) (K_at_p3-2)) (K_not_at_p5-3)))
    (:action invariant-1954
        :effect (when (and (not (K_at_p3-2)) (K_at_p5-3)) (K_not_at_p3-2)))
    (:action invariant-1955
        :effect (when (and (not (K_at_p5-3)) (K_at_p3-1)) (K_not_at_p5-3)))
    (:action invariant-1956
        :effect (when (and (not (K_at_p3-1)) (K_at_p5-3)) (K_not_at_p3-1)))
    (:action invariant-1957
        :effect (when (and (not (K_at_p5-3)) (K_at_p2-7)) (K_not_at_p5-3)))
    (:action invariant-1958
        :effect (when (and (not (K_at_p2-7)) (K_at_p5-3)) (K_not_at_p2-7)))
    (:action invariant-1959
        :effect (when (and (not (K_at_p5-3)) (K_at_p2-6)) (K_not_at_p5-3)))
    (:action invariant-1960
        :effect (when (and (not (K_at_p2-6)) (K_at_p5-3)) (K_not_at_p2-6)))
    (:action invariant-1961
        :effect (when (and (not (K_at_p5-3)) (K_at_p2-5)) (K_not_at_p5-3)))
    (:action invariant-1962
        :effect (when (and (not (K_at_p2-5)) (K_at_p5-3)) (K_not_at_p2-5)))
    (:action invariant-1963
        :effect (when (and (not (K_at_p5-3)) (K_at_p2-4)) (K_not_at_p5-3)))
    (:action invariant-1964
        :effect (when (and (not (K_at_p2-4)) (K_at_p5-3)) (K_not_at_p2-4)))
    (:action invariant-1965
        :effect (when (and (not (K_at_p5-3)) (K_at_p2-3)) (K_not_at_p5-3)))
    (:action invariant-1966
        :effect (when (and (not (K_at_p2-3)) (K_at_p5-3)) (K_not_at_p2-3)))
    (:action invariant-1967
        :effect (when (and (not (K_at_p5-3)) (K_at_p2-2)) (K_not_at_p5-3)))
    (:action invariant-1968
        :effect (when (and (not (K_at_p2-2)) (K_at_p5-3)) (K_not_at_p2-2)))
    (:action invariant-1969
        :effect (when (and (not (K_at_p5-3)) (K_at_p2-1)) (K_not_at_p5-3)))
    (:action invariant-1970
        :effect (when (and (not (K_at_p2-1)) (K_at_p5-3)) (K_not_at_p2-1)))
    (:action invariant-1971
        :effect (when (and (not (K_at_p5-3)) (K_at_p1-7)) (K_not_at_p5-3)))
    (:action invariant-1972
        :effect (when (and (not (K_at_p1-7)) (K_at_p5-3)) (K_not_at_p1-7)))
    (:action invariant-1973
        :effect (when (and (not (K_at_p5-3)) (K_at_p1-6)) (K_not_at_p5-3)))
    (:action invariant-1974
        :effect (when (and (not (K_at_p1-6)) (K_at_p5-3)) (K_not_at_p1-6)))
    (:action invariant-1975
        :effect (when (and (not (K_at_p5-3)) (K_at_p1-5)) (K_not_at_p5-3)))
    (:action invariant-1976
        :effect (when (and (not (K_at_p1-5)) (K_at_p5-3)) (K_not_at_p1-5)))
    (:action invariant-1977
        :effect (when (and (not (K_at_p5-3)) (K_at_p1-4)) (K_not_at_p5-3)))
    (:action invariant-1978
        :effect (when (and (not (K_at_p1-4)) (K_at_p5-3)) (K_not_at_p1-4)))
    (:action invariant-1979
        :effect (when (and (not (K_at_p5-3)) (K_at_p1-3)) (K_not_at_p5-3)))
    (:action invariant-1980
        :effect (when (and (not (K_at_p1-3)) (K_at_p5-3)) (K_not_at_p1-3)))
    (:action invariant-1981
        :effect (when (and (not (K_at_p5-3)) (K_at_p1-2)) (K_not_at_p5-3)))
    (:action invariant-1982
        :effect (when (and (not (K_at_p1-2)) (K_at_p5-3)) (K_not_at_p1-2)))
    (:action invariant-1983
        :effect (when (and (not (K_at_p5-3)) (K_at_p1-1)) (K_not_at_p5-3)))
    (:action invariant-1984
        :effect (when (and (not (K_at_p1-1)) (K_at_p5-3)) (K_not_at_p1-1)))
    (:action invariant-1985
        :effect (when (and (not (K_at_p5-2)) (K_at_p5-1)) (K_not_at_p5-2)))
    (:action invariant-1986
        :effect (when (and (not (K_at_p5-1)) (K_at_p5-2)) (K_not_at_p5-1)))
    (:action invariant-1987
        :effect (when (and (not (K_at_p5-2)) (K_at_p4-7)) (K_not_at_p5-2)))
    (:action invariant-1988
        :effect (when (and (not (K_at_p4-7)) (K_at_p5-2)) (K_not_at_p4-7)))
    (:action invariant-1989
        :effect (when (and (not (K_at_p5-2)) (K_at_p4-6)) (K_not_at_p5-2)))
    (:action invariant-1990
        :effect (when (and (not (K_at_p4-6)) (K_at_p5-2)) (K_not_at_p4-6)))
    (:action invariant-1991
        :effect (when (and (not (K_at_p5-2)) (K_at_p4-5)) (K_not_at_p5-2)))
    (:action invariant-1992
        :effect (when (and (not (K_at_p4-5)) (K_at_p5-2)) (K_not_at_p4-5)))
    (:action invariant-1993
        :effect (when (and (not (K_at_p5-2)) (K_at_p4-4)) (K_not_at_p5-2)))
    (:action invariant-1994
        :effect (when (and (not (K_at_p4-4)) (K_at_p5-2)) (K_not_at_p4-4)))
    (:action invariant-1995
        :effect (when (and (not (K_at_p5-2)) (K_at_p4-3)) (K_not_at_p5-2)))
    (:action invariant-1996
        :effect (when (and (not (K_at_p4-3)) (K_at_p5-2)) (K_not_at_p4-3)))
    (:action invariant-1997
        :effect (when (and (not (K_at_p5-2)) (K_at_p4-2)) (K_not_at_p5-2)))
    (:action invariant-1998
        :effect (when (and (not (K_at_p4-2)) (K_at_p5-2)) (K_not_at_p4-2)))
    (:action invariant-1999
        :effect (when (and (not (K_at_p5-2)) (K_at_p4-1)) (K_not_at_p5-2)))
    (:action invariant-2000
        :effect (when (and (not (K_at_p4-1)) (K_at_p5-2)) (K_not_at_p4-1)))
    (:action invariant-2001
        :effect (when (and (not (K_at_p5-2)) (K_at_p3-7)) (K_not_at_p5-2)))
    (:action invariant-2002
        :effect (when (and (not (K_at_p3-7)) (K_at_p5-2)) (K_not_at_p3-7)))
    (:action invariant-2003
        :effect (when (and (not (K_at_p5-2)) (K_at_p3-6)) (K_not_at_p5-2)))
    (:action invariant-2004
        :effect (when (and (not (K_at_p3-6)) (K_at_p5-2)) (K_not_at_p3-6)))
    (:action invariant-2005
        :effect (when (and (not (K_at_p5-2)) (K_at_p3-5)) (K_not_at_p5-2)))
    (:action invariant-2006
        :effect (when (and (not (K_at_p3-5)) (K_at_p5-2)) (K_not_at_p3-5)))
    (:action invariant-2007
        :effect (when (and (not (K_at_p5-2)) (K_at_p3-4)) (K_not_at_p5-2)))
    (:action invariant-2008
        :effect (when (and (not (K_at_p3-4)) (K_at_p5-2)) (K_not_at_p3-4)))
    (:action invariant-2009
        :effect (when (and (not (K_at_p5-2)) (K_at_p3-3)) (K_not_at_p5-2)))
    (:action invariant-2010
        :effect (when (and (not (K_at_p3-3)) (K_at_p5-2)) (K_not_at_p3-3)))
    (:action invariant-2011
        :effect (when (and (not (K_at_p5-2)) (K_at_p3-2)) (K_not_at_p5-2)))
    (:action invariant-2012
        :effect (when (and (not (K_at_p3-2)) (K_at_p5-2)) (K_not_at_p3-2)))
    (:action invariant-2013
        :effect (when (and (not (K_at_p5-2)) (K_at_p3-1)) (K_not_at_p5-2)))
    (:action invariant-2014
        :effect (when (and (not (K_at_p3-1)) (K_at_p5-2)) (K_not_at_p3-1)))
    (:action invariant-2015
        :effect (when (and (not (K_at_p5-2)) (K_at_p2-7)) (K_not_at_p5-2)))
    (:action invariant-2016
        :effect (when (and (not (K_at_p2-7)) (K_at_p5-2)) (K_not_at_p2-7)))
    (:action invariant-2017
        :effect (when (and (not (K_at_p5-2)) (K_at_p2-6)) (K_not_at_p5-2)))
    (:action invariant-2018
        :effect (when (and (not (K_at_p2-6)) (K_at_p5-2)) (K_not_at_p2-6)))
    (:action invariant-2019
        :effect (when (and (not (K_at_p5-2)) (K_at_p2-5)) (K_not_at_p5-2)))
    (:action invariant-2020
        :effect (when (and (not (K_at_p2-5)) (K_at_p5-2)) (K_not_at_p2-5)))
    (:action invariant-2021
        :effect (when (and (not (K_at_p5-2)) (K_at_p2-4)) (K_not_at_p5-2)))
    (:action invariant-2022
        :effect (when (and (not (K_at_p2-4)) (K_at_p5-2)) (K_not_at_p2-4)))
    (:action invariant-2023
        :effect (when (and (not (K_at_p5-2)) (K_at_p2-3)) (K_not_at_p5-2)))
    (:action invariant-2024
        :effect (when (and (not (K_at_p2-3)) (K_at_p5-2)) (K_not_at_p2-3)))
    (:action invariant-2025
        :effect (when (and (not (K_at_p5-2)) (K_at_p2-2)) (K_not_at_p5-2)))
    (:action invariant-2026
        :effect (when (and (not (K_at_p2-2)) (K_at_p5-2)) (K_not_at_p2-2)))
    (:action invariant-2027
        :effect (when (and (not (K_at_p5-2)) (K_at_p2-1)) (K_not_at_p5-2)))
    (:action invariant-2028
        :effect (when (and (not (K_at_p2-1)) (K_at_p5-2)) (K_not_at_p2-1)))
    (:action invariant-2029
        :effect (when (and (not (K_at_p5-2)) (K_at_p1-7)) (K_not_at_p5-2)))
    (:action invariant-2030
        :effect (when (and (not (K_at_p1-7)) (K_at_p5-2)) (K_not_at_p1-7)))
    (:action invariant-2031
        :effect (when (and (not (K_at_p5-2)) (K_at_p1-6)) (K_not_at_p5-2)))
    (:action invariant-2032
        :effect (when (and (not (K_at_p1-6)) (K_at_p5-2)) (K_not_at_p1-6)))
    (:action invariant-2033
        :effect (when (and (not (K_at_p5-2)) (K_at_p1-5)) (K_not_at_p5-2)))
    (:action invariant-2034
        :effect (when (and (not (K_at_p1-5)) (K_at_p5-2)) (K_not_at_p1-5)))
    (:action invariant-2035
        :effect (when (and (not (K_at_p5-2)) (K_at_p1-4)) (K_not_at_p5-2)))
    (:action invariant-2036
        :effect (when (and (not (K_at_p1-4)) (K_at_p5-2)) (K_not_at_p1-4)))
    (:action invariant-2037
        :effect (when (and (not (K_at_p5-2)) (K_at_p1-3)) (K_not_at_p5-2)))
    (:action invariant-2038
        :effect (when (and (not (K_at_p1-3)) (K_at_p5-2)) (K_not_at_p1-3)))
    (:action invariant-2039
        :effect (when (and (not (K_at_p5-2)) (K_at_p1-2)) (K_not_at_p5-2)))
    (:action invariant-2040
        :effect (when (and (not (K_at_p1-2)) (K_at_p5-2)) (K_not_at_p1-2)))
    (:action invariant-2041
        :effect (when (and (not (K_at_p5-2)) (K_at_p1-1)) (K_not_at_p5-2)))
    (:action invariant-2042
        :effect (when (and (not (K_at_p1-1)) (K_at_p5-2)) (K_not_at_p1-1)))
    (:action invariant-2043
        :effect (when (and (not (K_at_p5-1)) (K_at_p4-7)) (K_not_at_p5-1)))
    (:action invariant-2044
        :effect (when (and (not (K_at_p4-7)) (K_at_p5-1)) (K_not_at_p4-7)))
    (:action invariant-2045
        :effect (when (and (not (K_at_p5-1)) (K_at_p4-6)) (K_not_at_p5-1)))
    (:action invariant-2046
        :effect (when (and (not (K_at_p4-6)) (K_at_p5-1)) (K_not_at_p4-6)))
    (:action invariant-2047
        :effect (when (and (not (K_at_p5-1)) (K_at_p4-5)) (K_not_at_p5-1)))
    (:action invariant-2048
        :effect (when (and (not (K_at_p4-5)) (K_at_p5-1)) (K_not_at_p4-5)))
    (:action invariant-2049
        :effect (when (and (not (K_at_p5-1)) (K_at_p4-4)) (K_not_at_p5-1)))
    (:action invariant-2050
        :effect (when (and (not (K_at_p4-4)) (K_at_p5-1)) (K_not_at_p4-4)))
    (:action invariant-2051
        :effect (when (and (not (K_at_p5-1)) (K_at_p4-3)) (K_not_at_p5-1)))
    (:action invariant-2052
        :effect (when (and (not (K_at_p4-3)) (K_at_p5-1)) (K_not_at_p4-3)))
    (:action invariant-2053
        :effect (when (and (not (K_at_p5-1)) (K_at_p4-2)) (K_not_at_p5-1)))
    (:action invariant-2054
        :effect (when (and (not (K_at_p4-2)) (K_at_p5-1)) (K_not_at_p4-2)))
    (:action invariant-2055
        :effect (when (and (not (K_at_p5-1)) (K_at_p4-1)) (K_not_at_p5-1)))
    (:action invariant-2056
        :effect (when (and (not (K_at_p4-1)) (K_at_p5-1)) (K_not_at_p4-1)))
    (:action invariant-2057
        :effect (when (and (not (K_at_p5-1)) (K_at_p3-7)) (K_not_at_p5-1)))
    (:action invariant-2058
        :effect (when (and (not (K_at_p3-7)) (K_at_p5-1)) (K_not_at_p3-7)))
    (:action invariant-2059
        :effect (when (and (not (K_at_p5-1)) (K_at_p3-6)) (K_not_at_p5-1)))
    (:action invariant-2060
        :effect (when (and (not (K_at_p3-6)) (K_at_p5-1)) (K_not_at_p3-6)))
    (:action invariant-2061
        :effect (when (and (not (K_at_p5-1)) (K_at_p3-5)) (K_not_at_p5-1)))
    (:action invariant-2062
        :effect (when (and (not (K_at_p3-5)) (K_at_p5-1)) (K_not_at_p3-5)))
    (:action invariant-2063
        :effect (when (and (not (K_at_p5-1)) (K_at_p3-4)) (K_not_at_p5-1)))
    (:action invariant-2064
        :effect (when (and (not (K_at_p3-4)) (K_at_p5-1)) (K_not_at_p3-4)))
    (:action invariant-2065
        :effect (when (and (not (K_at_p5-1)) (K_at_p3-3)) (K_not_at_p5-1)))
    (:action invariant-2066
        :effect (when (and (not (K_at_p3-3)) (K_at_p5-1)) (K_not_at_p3-3)))
    (:action invariant-2067
        :effect (when (and (not (K_at_p5-1)) (K_at_p3-2)) (K_not_at_p5-1)))
    (:action invariant-2068
        :effect (when (and (not (K_at_p3-2)) (K_at_p5-1)) (K_not_at_p3-2)))
    (:action invariant-2069
        :effect (when (and (not (K_at_p5-1)) (K_at_p3-1)) (K_not_at_p5-1)))
    (:action invariant-2070
        :effect (when (and (not (K_at_p3-1)) (K_at_p5-1)) (K_not_at_p3-1)))
    (:action invariant-2071
        :effect (when (and (not (K_at_p5-1)) (K_at_p2-7)) (K_not_at_p5-1)))
    (:action invariant-2072
        :effect (when (and (not (K_at_p2-7)) (K_at_p5-1)) (K_not_at_p2-7)))
    (:action invariant-2073
        :effect (when (and (not (K_at_p5-1)) (K_at_p2-6)) (K_not_at_p5-1)))
    (:action invariant-2074
        :effect (when (and (not (K_at_p2-6)) (K_at_p5-1)) (K_not_at_p2-6)))
    (:action invariant-2075
        :effect (when (and (not (K_at_p5-1)) (K_at_p2-5)) (K_not_at_p5-1)))
    (:action invariant-2076
        :effect (when (and (not (K_at_p2-5)) (K_at_p5-1)) (K_not_at_p2-5)))
    (:action invariant-2077
        :effect (when (and (not (K_at_p5-1)) (K_at_p2-4)) (K_not_at_p5-1)))
    (:action invariant-2078
        :effect (when (and (not (K_at_p2-4)) (K_at_p5-1)) (K_not_at_p2-4)))
    (:action invariant-2079
        :effect (when (and (not (K_at_p5-1)) (K_at_p2-3)) (K_not_at_p5-1)))
    (:action invariant-2080
        :effect (when (and (not (K_at_p2-3)) (K_at_p5-1)) (K_not_at_p2-3)))
    (:action invariant-2081
        :effect (when (and (not (K_at_p5-1)) (K_at_p2-2)) (K_not_at_p5-1)))
    (:action invariant-2082
        :effect (when (and (not (K_at_p2-2)) (K_at_p5-1)) (K_not_at_p2-2)))
    (:action invariant-2083
        :effect (when (and (not (K_at_p5-1)) (K_at_p2-1)) (K_not_at_p5-1)))
    (:action invariant-2084
        :effect (when (and (not (K_at_p2-1)) (K_at_p5-1)) (K_not_at_p2-1)))
    (:action invariant-2085
        :effect (when (and (not (K_at_p5-1)) (K_at_p1-7)) (K_not_at_p5-1)))
    (:action invariant-2086
        :effect (when (and (not (K_at_p1-7)) (K_at_p5-1)) (K_not_at_p1-7)))
    (:action invariant-2087
        :effect (when (and (not (K_at_p5-1)) (K_at_p1-6)) (K_not_at_p5-1)))
    (:action invariant-2088
        :effect (when (and (not (K_at_p1-6)) (K_at_p5-1)) (K_not_at_p1-6)))
    (:action invariant-2089
        :effect (when (and (not (K_at_p5-1)) (K_at_p1-5)) (K_not_at_p5-1)))
    (:action invariant-2090
        :effect (when (and (not (K_at_p1-5)) (K_at_p5-1)) (K_not_at_p1-5)))
    (:action invariant-2091
        :effect (when (and (not (K_at_p5-1)) (K_at_p1-4)) (K_not_at_p5-1)))
    (:action invariant-2092
        :effect (when (and (not (K_at_p1-4)) (K_at_p5-1)) (K_not_at_p1-4)))
    (:action invariant-2093
        :effect (when (and (not (K_at_p5-1)) (K_at_p1-3)) (K_not_at_p5-1)))
    (:action invariant-2094
        :effect (when (and (not (K_at_p1-3)) (K_at_p5-1)) (K_not_at_p1-3)))
    (:action invariant-2095
        :effect (when (and (not (K_at_p5-1)) (K_at_p1-2)) (K_not_at_p5-1)))
    (:action invariant-2096
        :effect (when (and (not (K_at_p1-2)) (K_at_p5-1)) (K_not_at_p1-2)))
    (:action invariant-2097
        :effect (when (and (not (K_at_p5-1)) (K_at_p1-1)) (K_not_at_p5-1)))
    (:action invariant-2098
        :effect (when (and (not (K_at_p1-1)) (K_at_p5-1)) (K_not_at_p1-1)))
    (:action invariant-2099
        :effect (when (and (not (K_at_p4-7)) (K_at_p4-6)) (K_not_at_p4-7)))
    (:action invariant-2100
        :effect (when (and (not (K_at_p4-6)) (K_at_p4-7)) (K_not_at_p4-6)))
    (:action invariant-2101
        :effect (when (and (not (K_at_p4-7)) (K_at_p4-5)) (K_not_at_p4-7)))
    (:action invariant-2102
        :effect (when (and (not (K_at_p4-5)) (K_at_p4-7)) (K_not_at_p4-5)))
    (:action invariant-2103
        :effect (when (and (not (K_at_p4-7)) (K_at_p4-4)) (K_not_at_p4-7)))
    (:action invariant-2104
        :effect (when (and (not (K_at_p4-4)) (K_at_p4-7)) (K_not_at_p4-4)))
    (:action invariant-2105
        :effect (when (and (not (K_at_p4-7)) (K_at_p4-3)) (K_not_at_p4-7)))
    (:action invariant-2106
        :effect (when (and (not (K_at_p4-3)) (K_at_p4-7)) (K_not_at_p4-3)))
    (:action invariant-2107
        :effect (when (and (not (K_at_p4-7)) (K_at_p4-2)) (K_not_at_p4-7)))
    (:action invariant-2108
        :effect (when (and (not (K_at_p4-2)) (K_at_p4-7)) (K_not_at_p4-2)))
    (:action invariant-2109
        :effect (when (and (not (K_at_p4-7)) (K_at_p4-1)) (K_not_at_p4-7)))
    (:action invariant-2110
        :effect (when (and (not (K_at_p4-1)) (K_at_p4-7)) (K_not_at_p4-1)))
    (:action invariant-2111
        :effect (when (and (not (K_at_p4-7)) (K_at_p3-7)) (K_not_at_p4-7)))
    (:action invariant-2112
        :effect (when (and (not (K_at_p3-7)) (K_at_p4-7)) (K_not_at_p3-7)))
    (:action invariant-2113
        :effect (when (and (not (K_at_p4-7)) (K_at_p3-6)) (K_not_at_p4-7)))
    (:action invariant-2114
        :effect (when (and (not (K_at_p3-6)) (K_at_p4-7)) (K_not_at_p3-6)))
    (:action invariant-2115
        :effect (when (and (not (K_at_p4-7)) (K_at_p3-5)) (K_not_at_p4-7)))
    (:action invariant-2116
        :effect (when (and (not (K_at_p3-5)) (K_at_p4-7)) (K_not_at_p3-5)))
    (:action invariant-2117
        :effect (when (and (not (K_at_p4-7)) (K_at_p3-4)) (K_not_at_p4-7)))
    (:action invariant-2118
        :effect (when (and (not (K_at_p3-4)) (K_at_p4-7)) (K_not_at_p3-4)))
    (:action invariant-2119
        :effect (when (and (not (K_at_p4-7)) (K_at_p3-3)) (K_not_at_p4-7)))
    (:action invariant-2120
        :effect (when (and (not (K_at_p3-3)) (K_at_p4-7)) (K_not_at_p3-3)))
    (:action invariant-2121
        :effect (when (and (not (K_at_p4-7)) (K_at_p3-2)) (K_not_at_p4-7)))
    (:action invariant-2122
        :effect (when (and (not (K_at_p3-2)) (K_at_p4-7)) (K_not_at_p3-2)))
    (:action invariant-2123
        :effect (when (and (not (K_at_p4-7)) (K_at_p3-1)) (K_not_at_p4-7)))
    (:action invariant-2124
        :effect (when (and (not (K_at_p3-1)) (K_at_p4-7)) (K_not_at_p3-1)))
    (:action invariant-2125
        :effect (when (and (not (K_at_p4-7)) (K_at_p2-7)) (K_not_at_p4-7)))
    (:action invariant-2126
        :effect (when (and (not (K_at_p2-7)) (K_at_p4-7)) (K_not_at_p2-7)))
    (:action invariant-2127
        :effect (when (and (not (K_at_p4-7)) (K_at_p2-6)) (K_not_at_p4-7)))
    (:action invariant-2128
        :effect (when (and (not (K_at_p2-6)) (K_at_p4-7)) (K_not_at_p2-6)))
    (:action invariant-2129
        :effect (when (and (not (K_at_p4-7)) (K_at_p2-5)) (K_not_at_p4-7)))
    (:action invariant-2130
        :effect (when (and (not (K_at_p2-5)) (K_at_p4-7)) (K_not_at_p2-5)))
    (:action invariant-2131
        :effect (when (and (not (K_at_p4-7)) (K_at_p2-4)) (K_not_at_p4-7)))
    (:action invariant-2132
        :effect (when (and (not (K_at_p2-4)) (K_at_p4-7)) (K_not_at_p2-4)))
    (:action invariant-2133
        :effect (when (and (not (K_at_p4-7)) (K_at_p2-3)) (K_not_at_p4-7)))
    (:action invariant-2134
        :effect (when (and (not (K_at_p2-3)) (K_at_p4-7)) (K_not_at_p2-3)))
    (:action invariant-2135
        :effect (when (and (not (K_at_p4-7)) (K_at_p2-2)) (K_not_at_p4-7)))
    (:action invariant-2136
        :effect (when (and (not (K_at_p2-2)) (K_at_p4-7)) (K_not_at_p2-2)))
    (:action invariant-2137
        :effect (when (and (not (K_at_p4-7)) (K_at_p2-1)) (K_not_at_p4-7)))
    (:action invariant-2138
        :effect (when (and (not (K_at_p2-1)) (K_at_p4-7)) (K_not_at_p2-1)))
    (:action invariant-2139
        :effect (when (and (not (K_at_p4-7)) (K_at_p1-7)) (K_not_at_p4-7)))
    (:action invariant-2140
        :effect (when (and (not (K_at_p1-7)) (K_at_p4-7)) (K_not_at_p1-7)))
    (:action invariant-2141
        :effect (when (and (not (K_at_p4-7)) (K_at_p1-6)) (K_not_at_p4-7)))
    (:action invariant-2142
        :effect (when (and (not (K_at_p1-6)) (K_at_p4-7)) (K_not_at_p1-6)))
    (:action invariant-2143
        :effect (when (and (not (K_at_p4-7)) (K_at_p1-5)) (K_not_at_p4-7)))
    (:action invariant-2144
        :effect (when (and (not (K_at_p1-5)) (K_at_p4-7)) (K_not_at_p1-5)))
    (:action invariant-2145
        :effect (when (and (not (K_at_p4-7)) (K_at_p1-4)) (K_not_at_p4-7)))
    (:action invariant-2146
        :effect (when (and (not (K_at_p1-4)) (K_at_p4-7)) (K_not_at_p1-4)))
    (:action invariant-2147
        :effect (when (and (not (K_at_p4-7)) (K_at_p1-3)) (K_not_at_p4-7)))
    (:action invariant-2148
        :effect (when (and (not (K_at_p1-3)) (K_at_p4-7)) (K_not_at_p1-3)))
    (:action invariant-2149
        :effect (when (and (not (K_at_p4-7)) (K_at_p1-2)) (K_not_at_p4-7)))
    (:action invariant-2150
        :effect (when (and (not (K_at_p1-2)) (K_at_p4-7)) (K_not_at_p1-2)))
    (:action invariant-2151
        :effect (when (and (not (K_at_p4-7)) (K_at_p1-1)) (K_not_at_p4-7)))
    (:action invariant-2152
        :effect (when (and (not (K_at_p1-1)) (K_at_p4-7)) (K_not_at_p1-1)))
    (:action invariant-2153
        :effect (when (and (not (K_at_p4-6)) (K_at_p4-5)) (K_not_at_p4-6)))
    (:action invariant-2154
        :effect (when (and (not (K_at_p4-5)) (K_at_p4-6)) (K_not_at_p4-5)))
    (:action invariant-2155
        :effect (when (and (not (K_at_p4-6)) (K_at_p4-4)) (K_not_at_p4-6)))
    (:action invariant-2156
        :effect (when (and (not (K_at_p4-4)) (K_at_p4-6)) (K_not_at_p4-4)))
    (:action invariant-2157
        :effect (when (and (not (K_at_p4-6)) (K_at_p4-3)) (K_not_at_p4-6)))
    (:action invariant-2158
        :effect (when (and (not (K_at_p4-3)) (K_at_p4-6)) (K_not_at_p4-3)))
    (:action invariant-2159
        :effect (when (and (not (K_at_p4-6)) (K_at_p4-2)) (K_not_at_p4-6)))
    (:action invariant-2160
        :effect (when (and (not (K_at_p4-2)) (K_at_p4-6)) (K_not_at_p4-2)))
    (:action invariant-2161
        :effect (when (and (not (K_at_p4-6)) (K_at_p4-1)) (K_not_at_p4-6)))
    (:action invariant-2162
        :effect (when (and (not (K_at_p4-1)) (K_at_p4-6)) (K_not_at_p4-1)))
    (:action invariant-2163
        :effect (when (and (not (K_at_p4-6)) (K_at_p3-7)) (K_not_at_p4-6)))
    (:action invariant-2164
        :effect (when (and (not (K_at_p3-7)) (K_at_p4-6)) (K_not_at_p3-7)))
    (:action invariant-2165
        :effect (when (and (not (K_at_p4-6)) (K_at_p3-6)) (K_not_at_p4-6)))
    (:action invariant-2166
        :effect (when (and (not (K_at_p3-6)) (K_at_p4-6)) (K_not_at_p3-6)))
    (:action invariant-2167
        :effect (when (and (not (K_at_p4-6)) (K_at_p3-5)) (K_not_at_p4-6)))
    (:action invariant-2168
        :effect (when (and (not (K_at_p3-5)) (K_at_p4-6)) (K_not_at_p3-5)))
    (:action invariant-2169
        :effect (when (and (not (K_at_p4-6)) (K_at_p3-4)) (K_not_at_p4-6)))
    (:action invariant-2170
        :effect (when (and (not (K_at_p3-4)) (K_at_p4-6)) (K_not_at_p3-4)))
    (:action invariant-2171
        :effect (when (and (not (K_at_p4-6)) (K_at_p3-3)) (K_not_at_p4-6)))
    (:action invariant-2172
        :effect (when (and (not (K_at_p3-3)) (K_at_p4-6)) (K_not_at_p3-3)))
    (:action invariant-2173
        :effect (when (and (not (K_at_p4-6)) (K_at_p3-2)) (K_not_at_p4-6)))
    (:action invariant-2174
        :effect (when (and (not (K_at_p3-2)) (K_at_p4-6)) (K_not_at_p3-2)))
    (:action invariant-2175
        :effect (when (and (not (K_at_p4-6)) (K_at_p3-1)) (K_not_at_p4-6)))
    (:action invariant-2176
        :effect (when (and (not (K_at_p3-1)) (K_at_p4-6)) (K_not_at_p3-1)))
    (:action invariant-2177
        :effect (when (and (not (K_at_p4-6)) (K_at_p2-7)) (K_not_at_p4-6)))
    (:action invariant-2178
        :effect (when (and (not (K_at_p2-7)) (K_at_p4-6)) (K_not_at_p2-7)))
    (:action invariant-2179
        :effect (when (and (not (K_at_p4-6)) (K_at_p2-6)) (K_not_at_p4-6)))
    (:action invariant-2180
        :effect (when (and (not (K_at_p2-6)) (K_at_p4-6)) (K_not_at_p2-6)))
    (:action invariant-2181
        :effect (when (and (not (K_at_p4-6)) (K_at_p2-5)) (K_not_at_p4-6)))
    (:action invariant-2182
        :effect (when (and (not (K_at_p2-5)) (K_at_p4-6)) (K_not_at_p2-5)))
    (:action invariant-2183
        :effect (when (and (not (K_at_p4-6)) (K_at_p2-4)) (K_not_at_p4-6)))
    (:action invariant-2184
        :effect (when (and (not (K_at_p2-4)) (K_at_p4-6)) (K_not_at_p2-4)))
    (:action invariant-2185
        :effect (when (and (not (K_at_p4-6)) (K_at_p2-3)) (K_not_at_p4-6)))
    (:action invariant-2186
        :effect (when (and (not (K_at_p2-3)) (K_at_p4-6)) (K_not_at_p2-3)))
    (:action invariant-2187
        :effect (when (and (not (K_at_p4-6)) (K_at_p2-2)) (K_not_at_p4-6)))
    (:action invariant-2188
        :effect (when (and (not (K_at_p2-2)) (K_at_p4-6)) (K_not_at_p2-2)))
    (:action invariant-2189
        :effect (when (and (not (K_at_p4-6)) (K_at_p2-1)) (K_not_at_p4-6)))
    (:action invariant-2190
        :effect (when (and (not (K_at_p2-1)) (K_at_p4-6)) (K_not_at_p2-1)))
    (:action invariant-2191
        :effect (when (and (not (K_at_p4-6)) (K_at_p1-7)) (K_not_at_p4-6)))
    (:action invariant-2192
        :effect (when (and (not (K_at_p1-7)) (K_at_p4-6)) (K_not_at_p1-7)))
    (:action invariant-2193
        :effect (when (and (not (K_at_p4-6)) (K_at_p1-6)) (K_not_at_p4-6)))
    (:action invariant-2194
        :effect (when (and (not (K_at_p1-6)) (K_at_p4-6)) (K_not_at_p1-6)))
    (:action invariant-2195
        :effect (when (and (not (K_at_p4-6)) (K_at_p1-5)) (K_not_at_p4-6)))
    (:action invariant-2196
        :effect (when (and (not (K_at_p1-5)) (K_at_p4-6)) (K_not_at_p1-5)))
    (:action invariant-2197
        :effect (when (and (not (K_at_p4-6)) (K_at_p1-4)) (K_not_at_p4-6)))
    (:action invariant-2198
        :effect (when (and (not (K_at_p1-4)) (K_at_p4-6)) (K_not_at_p1-4)))
    (:action invariant-2199
        :effect (when (and (not (K_at_p4-6)) (K_at_p1-3)) (K_not_at_p4-6)))
    (:action invariant-2200
        :effect (when (and (not (K_at_p1-3)) (K_at_p4-6)) (K_not_at_p1-3)))
    (:action invariant-2201
        :effect (when (and (not (K_at_p4-6)) (K_at_p1-2)) (K_not_at_p4-6)))
    (:action invariant-2202
        :effect (when (and (not (K_at_p1-2)) (K_at_p4-6)) (K_not_at_p1-2)))
    (:action invariant-2203
        :effect (when (and (not (K_at_p4-6)) (K_at_p1-1)) (K_not_at_p4-6)))
    (:action invariant-2204
        :effect (when (and (not (K_at_p1-1)) (K_at_p4-6)) (K_not_at_p1-1)))
    (:action invariant-2205
        :effect (when (and (not (K_at_p4-5)) (K_at_p4-4)) (K_not_at_p4-5)))
    (:action invariant-2206
        :effect (when (and (not (K_at_p4-4)) (K_at_p4-5)) (K_not_at_p4-4)))
    (:action invariant-2207
        :effect (when (and (not (K_at_p4-5)) (K_at_p4-3)) (K_not_at_p4-5)))
    (:action invariant-2208
        :effect (when (and (not (K_at_p4-3)) (K_at_p4-5)) (K_not_at_p4-3)))
    (:action invariant-2209
        :effect (when (and (not (K_at_p4-5)) (K_at_p4-2)) (K_not_at_p4-5)))
    (:action invariant-2210
        :effect (when (and (not (K_at_p4-2)) (K_at_p4-5)) (K_not_at_p4-2)))
    (:action invariant-2211
        :effect (when (and (not (K_at_p4-5)) (K_at_p4-1)) (K_not_at_p4-5)))
    (:action invariant-2212
        :effect (when (and (not (K_at_p4-1)) (K_at_p4-5)) (K_not_at_p4-1)))
    (:action invariant-2213
        :effect (when (and (not (K_at_p4-5)) (K_at_p3-7)) (K_not_at_p4-5)))
    (:action invariant-2214
        :effect (when (and (not (K_at_p3-7)) (K_at_p4-5)) (K_not_at_p3-7)))
    (:action invariant-2215
        :effect (when (and (not (K_at_p4-5)) (K_at_p3-6)) (K_not_at_p4-5)))
    (:action invariant-2216
        :effect (when (and (not (K_at_p3-6)) (K_at_p4-5)) (K_not_at_p3-6)))
    (:action invariant-2217
        :effect (when (and (not (K_at_p4-5)) (K_at_p3-5)) (K_not_at_p4-5)))
    (:action invariant-2218
        :effect (when (and (not (K_at_p3-5)) (K_at_p4-5)) (K_not_at_p3-5)))
    (:action invariant-2219
        :effect (when (and (not (K_at_p4-5)) (K_at_p3-4)) (K_not_at_p4-5)))
    (:action invariant-2220
        :effect (when (and (not (K_at_p3-4)) (K_at_p4-5)) (K_not_at_p3-4)))
    (:action invariant-2221
        :effect (when (and (not (K_at_p4-5)) (K_at_p3-3)) (K_not_at_p4-5)))
    (:action invariant-2222
        :effect (when (and (not (K_at_p3-3)) (K_at_p4-5)) (K_not_at_p3-3)))
    (:action invariant-2223
        :effect (when (and (not (K_at_p4-5)) (K_at_p3-2)) (K_not_at_p4-5)))
    (:action invariant-2224
        :effect (when (and (not (K_at_p3-2)) (K_at_p4-5)) (K_not_at_p3-2)))
    (:action invariant-2225
        :effect (when (and (not (K_at_p4-5)) (K_at_p3-1)) (K_not_at_p4-5)))
    (:action invariant-2226
        :effect (when (and (not (K_at_p3-1)) (K_at_p4-5)) (K_not_at_p3-1)))
    (:action invariant-2227
        :effect (when (and (not (K_at_p4-5)) (K_at_p2-7)) (K_not_at_p4-5)))
    (:action invariant-2228
        :effect (when (and (not (K_at_p2-7)) (K_at_p4-5)) (K_not_at_p2-7)))
    (:action invariant-2229
        :effect (when (and (not (K_at_p4-5)) (K_at_p2-6)) (K_not_at_p4-5)))
    (:action invariant-2230
        :effect (when (and (not (K_at_p2-6)) (K_at_p4-5)) (K_not_at_p2-6)))
    (:action invariant-2231
        :effect (when (and (not (K_at_p4-5)) (K_at_p2-5)) (K_not_at_p4-5)))
    (:action invariant-2232
        :effect (when (and (not (K_at_p2-5)) (K_at_p4-5)) (K_not_at_p2-5)))
    (:action invariant-2233
        :effect (when (and (not (K_at_p4-5)) (K_at_p2-4)) (K_not_at_p4-5)))
    (:action invariant-2234
        :effect (when (and (not (K_at_p2-4)) (K_at_p4-5)) (K_not_at_p2-4)))
    (:action invariant-2235
        :effect (when (and (not (K_at_p4-5)) (K_at_p2-3)) (K_not_at_p4-5)))
    (:action invariant-2236
        :effect (when (and (not (K_at_p2-3)) (K_at_p4-5)) (K_not_at_p2-3)))
    (:action invariant-2237
        :effect (when (and (not (K_at_p4-5)) (K_at_p2-2)) (K_not_at_p4-5)))
    (:action invariant-2238
        :effect (when (and (not (K_at_p2-2)) (K_at_p4-5)) (K_not_at_p2-2)))
    (:action invariant-2239
        :effect (when (and (not (K_at_p4-5)) (K_at_p2-1)) (K_not_at_p4-5)))
    (:action invariant-2240
        :effect (when (and (not (K_at_p2-1)) (K_at_p4-5)) (K_not_at_p2-1)))
    (:action invariant-2241
        :effect (when (and (not (K_at_p4-5)) (K_at_p1-7)) (K_not_at_p4-5)))
    (:action invariant-2242
        :effect (when (and (not (K_at_p1-7)) (K_at_p4-5)) (K_not_at_p1-7)))
    (:action invariant-2243
        :effect (when (and (not (K_at_p4-5)) (K_at_p1-6)) (K_not_at_p4-5)))
    (:action invariant-2244
        :effect (when (and (not (K_at_p1-6)) (K_at_p4-5)) (K_not_at_p1-6)))
    (:action invariant-2245
        :effect (when (and (not (K_at_p4-5)) (K_at_p1-5)) (K_not_at_p4-5)))
    (:action invariant-2246
        :effect (when (and (not (K_at_p1-5)) (K_at_p4-5)) (K_not_at_p1-5)))
    (:action invariant-2247
        :effect (when (and (not (K_at_p4-5)) (K_at_p1-4)) (K_not_at_p4-5)))
    (:action invariant-2248
        :effect (when (and (not (K_at_p1-4)) (K_at_p4-5)) (K_not_at_p1-4)))
    (:action invariant-2249
        :effect (when (and (not (K_at_p4-5)) (K_at_p1-3)) (K_not_at_p4-5)))
    (:action invariant-2250
        :effect (when (and (not (K_at_p1-3)) (K_at_p4-5)) (K_not_at_p1-3)))
    (:action invariant-2251
        :effect (when (and (not (K_at_p4-5)) (K_at_p1-2)) (K_not_at_p4-5)))
    (:action invariant-2252
        :effect (when (and (not (K_at_p1-2)) (K_at_p4-5)) (K_not_at_p1-2)))
    (:action invariant-2253
        :effect (when (and (not (K_at_p4-5)) (K_at_p1-1)) (K_not_at_p4-5)))
    (:action invariant-2254
        :effect (when (and (not (K_at_p1-1)) (K_at_p4-5)) (K_not_at_p1-1)))
    (:action invariant-2255
        :effect (when (and (not (K_at_p4-4)) (K_at_p4-3)) (K_not_at_p4-4)))
    (:action invariant-2256
        :effect (when (and (not (K_at_p4-3)) (K_at_p4-4)) (K_not_at_p4-3)))
    (:action invariant-2257
        :effect (when (and (not (K_at_p4-4)) (K_at_p4-2)) (K_not_at_p4-4)))
    (:action invariant-2258
        :effect (when (and (not (K_at_p4-2)) (K_at_p4-4)) (K_not_at_p4-2)))
    (:action invariant-2259
        :effect (when (and (not (K_at_p4-4)) (K_at_p4-1)) (K_not_at_p4-4)))
    (:action invariant-2260
        :effect (when (and (not (K_at_p4-1)) (K_at_p4-4)) (K_not_at_p4-1)))
    (:action invariant-2261
        :effect (when (and (not (K_at_p4-4)) (K_at_p3-7)) (K_not_at_p4-4)))
    (:action invariant-2262
        :effect (when (and (not (K_at_p3-7)) (K_at_p4-4)) (K_not_at_p3-7)))
    (:action invariant-2263
        :effect (when (and (not (K_at_p4-4)) (K_at_p3-6)) (K_not_at_p4-4)))
    (:action invariant-2264
        :effect (when (and (not (K_at_p3-6)) (K_at_p4-4)) (K_not_at_p3-6)))
    (:action invariant-2265
        :effect (when (and (not (K_at_p4-4)) (K_at_p3-5)) (K_not_at_p4-4)))
    (:action invariant-2266
        :effect (when (and (not (K_at_p3-5)) (K_at_p4-4)) (K_not_at_p3-5)))
    (:action invariant-2267
        :effect (when (and (not (K_at_p4-4)) (K_at_p3-4)) (K_not_at_p4-4)))
    (:action invariant-2268
        :effect (when (and (not (K_at_p3-4)) (K_at_p4-4)) (K_not_at_p3-4)))
    (:action invariant-2269
        :effect (when (and (not (K_at_p4-4)) (K_at_p3-3)) (K_not_at_p4-4)))
    (:action invariant-2270
        :effect (when (and (not (K_at_p3-3)) (K_at_p4-4)) (K_not_at_p3-3)))
    (:action invariant-2271
        :effect (when (and (not (K_at_p4-4)) (K_at_p3-2)) (K_not_at_p4-4)))
    (:action invariant-2272
        :effect (when (and (not (K_at_p3-2)) (K_at_p4-4)) (K_not_at_p3-2)))
    (:action invariant-2273
        :effect (when (and (not (K_at_p4-4)) (K_at_p3-1)) (K_not_at_p4-4)))
    (:action invariant-2274
        :effect (when (and (not (K_at_p3-1)) (K_at_p4-4)) (K_not_at_p3-1)))
    (:action invariant-2275
        :effect (when (and (not (K_at_p4-4)) (K_at_p2-7)) (K_not_at_p4-4)))
    (:action invariant-2276
        :effect (when (and (not (K_at_p2-7)) (K_at_p4-4)) (K_not_at_p2-7)))
    (:action invariant-2277
        :effect (when (and (not (K_at_p4-4)) (K_at_p2-6)) (K_not_at_p4-4)))
    (:action invariant-2278
        :effect (when (and (not (K_at_p2-6)) (K_at_p4-4)) (K_not_at_p2-6)))
    (:action invariant-2279
        :effect (when (and (not (K_at_p4-4)) (K_at_p2-5)) (K_not_at_p4-4)))
    (:action invariant-2280
        :effect (when (and (not (K_at_p2-5)) (K_at_p4-4)) (K_not_at_p2-5)))
    (:action invariant-2281
        :effect (when (and (not (K_at_p4-4)) (K_at_p2-4)) (K_not_at_p4-4)))
    (:action invariant-2282
        :effect (when (and (not (K_at_p2-4)) (K_at_p4-4)) (K_not_at_p2-4)))
    (:action invariant-2283
        :effect (when (and (not (K_at_p4-4)) (K_at_p2-3)) (K_not_at_p4-4)))
    (:action invariant-2284
        :effect (when (and (not (K_at_p2-3)) (K_at_p4-4)) (K_not_at_p2-3)))
    (:action invariant-2285
        :effect (when (and (not (K_at_p4-4)) (K_at_p2-2)) (K_not_at_p4-4)))
    (:action invariant-2286
        :effect (when (and (not (K_at_p2-2)) (K_at_p4-4)) (K_not_at_p2-2)))
    (:action invariant-2287
        :effect (when (and (not (K_at_p4-4)) (K_at_p2-1)) (K_not_at_p4-4)))
    (:action invariant-2288
        :effect (when (and (not (K_at_p2-1)) (K_at_p4-4)) (K_not_at_p2-1)))
    (:action invariant-2289
        :effect (when (and (not (K_at_p4-4)) (K_at_p1-7)) (K_not_at_p4-4)))
    (:action invariant-2290
        :effect (when (and (not (K_at_p1-7)) (K_at_p4-4)) (K_not_at_p1-7)))
    (:action invariant-2291
        :effect (when (and (not (K_at_p4-4)) (K_at_p1-6)) (K_not_at_p4-4)))
    (:action invariant-2292
        :effect (when (and (not (K_at_p1-6)) (K_at_p4-4)) (K_not_at_p1-6)))
    (:action invariant-2293
        :effect (when (and (not (K_at_p4-4)) (K_at_p1-5)) (K_not_at_p4-4)))
    (:action invariant-2294
        :effect (when (and (not (K_at_p1-5)) (K_at_p4-4)) (K_not_at_p1-5)))
    (:action invariant-2295
        :effect (when (and (not (K_at_p4-4)) (K_at_p1-4)) (K_not_at_p4-4)))
    (:action invariant-2296
        :effect (when (and (not (K_at_p1-4)) (K_at_p4-4)) (K_not_at_p1-4)))
    (:action invariant-2297
        :effect (when (and (not (K_at_p4-4)) (K_at_p1-3)) (K_not_at_p4-4)))
    (:action invariant-2298
        :effect (when (and (not (K_at_p1-3)) (K_at_p4-4)) (K_not_at_p1-3)))
    (:action invariant-2299
        :effect (when (and (not (K_at_p4-4)) (K_at_p1-2)) (K_not_at_p4-4)))
    (:action invariant-2300
        :effect (when (and (not (K_at_p1-2)) (K_at_p4-4)) (K_not_at_p1-2)))
    (:action invariant-2301
        :effect (when (and (not (K_at_p4-4)) (K_at_p1-1)) (K_not_at_p4-4)))
    (:action invariant-2302
        :effect (when (and (not (K_at_p1-1)) (K_at_p4-4)) (K_not_at_p1-1)))
    (:action invariant-2303
        :effect (when (and (not (K_at_p4-3)) (K_at_p4-2)) (K_not_at_p4-3)))
    (:action invariant-2304
        :effect (when (and (not (K_at_p4-2)) (K_at_p4-3)) (K_not_at_p4-2)))
    (:action invariant-2305
        :effect (when (and (not (K_at_p4-3)) (K_at_p4-1)) (K_not_at_p4-3)))
    (:action invariant-2306
        :effect (when (and (not (K_at_p4-1)) (K_at_p4-3)) (K_not_at_p4-1)))
    (:action invariant-2307
        :effect (when (and (not (K_at_p4-3)) (K_at_p3-7)) (K_not_at_p4-3)))
    (:action invariant-2308
        :effect (when (and (not (K_at_p3-7)) (K_at_p4-3)) (K_not_at_p3-7)))
    (:action invariant-2309
        :effect (when (and (not (K_at_p4-3)) (K_at_p3-6)) (K_not_at_p4-3)))
    (:action invariant-2310
        :effect (when (and (not (K_at_p3-6)) (K_at_p4-3)) (K_not_at_p3-6)))
    (:action invariant-2311
        :effect (when (and (not (K_at_p4-3)) (K_at_p3-5)) (K_not_at_p4-3)))
    (:action invariant-2312
        :effect (when (and (not (K_at_p3-5)) (K_at_p4-3)) (K_not_at_p3-5)))
    (:action invariant-2313
        :effect (when (and (not (K_at_p4-3)) (K_at_p3-4)) (K_not_at_p4-3)))
    (:action invariant-2314
        :effect (when (and (not (K_at_p3-4)) (K_at_p4-3)) (K_not_at_p3-4)))
    (:action invariant-2315
        :effect (when (and (not (K_at_p4-3)) (K_at_p3-3)) (K_not_at_p4-3)))
    (:action invariant-2316
        :effect (when (and (not (K_at_p3-3)) (K_at_p4-3)) (K_not_at_p3-3)))
    (:action invariant-2317
        :effect (when (and (not (K_at_p4-3)) (K_at_p3-2)) (K_not_at_p4-3)))
    (:action invariant-2318
        :effect (when (and (not (K_at_p3-2)) (K_at_p4-3)) (K_not_at_p3-2)))
    (:action invariant-2319
        :effect (when (and (not (K_at_p4-3)) (K_at_p3-1)) (K_not_at_p4-3)))
    (:action invariant-2320
        :effect (when (and (not (K_at_p3-1)) (K_at_p4-3)) (K_not_at_p3-1)))
    (:action invariant-2321
        :effect (when (and (not (K_at_p4-3)) (K_at_p2-7)) (K_not_at_p4-3)))
    (:action invariant-2322
        :effect (when (and (not (K_at_p2-7)) (K_at_p4-3)) (K_not_at_p2-7)))
    (:action invariant-2323
        :effect (when (and (not (K_at_p4-3)) (K_at_p2-6)) (K_not_at_p4-3)))
    (:action invariant-2324
        :effect (when (and (not (K_at_p2-6)) (K_at_p4-3)) (K_not_at_p2-6)))
    (:action invariant-2325
        :effect (when (and (not (K_at_p4-3)) (K_at_p2-5)) (K_not_at_p4-3)))
    (:action invariant-2326
        :effect (when (and (not (K_at_p2-5)) (K_at_p4-3)) (K_not_at_p2-5)))
    (:action invariant-2327
        :effect (when (and (not (K_at_p4-3)) (K_at_p2-4)) (K_not_at_p4-3)))
    (:action invariant-2328
        :effect (when (and (not (K_at_p2-4)) (K_at_p4-3)) (K_not_at_p2-4)))
    (:action invariant-2329
        :effect (when (and (not (K_at_p4-3)) (K_at_p2-3)) (K_not_at_p4-3)))
    (:action invariant-2330
        :effect (when (and (not (K_at_p2-3)) (K_at_p4-3)) (K_not_at_p2-3)))
    (:action invariant-2331
        :effect (when (and (not (K_at_p4-3)) (K_at_p2-2)) (K_not_at_p4-3)))
    (:action invariant-2332
        :effect (when (and (not (K_at_p2-2)) (K_at_p4-3)) (K_not_at_p2-2)))
    (:action invariant-2333
        :effect (when (and (not (K_at_p4-3)) (K_at_p2-1)) (K_not_at_p4-3)))
    (:action invariant-2334
        :effect (when (and (not (K_at_p2-1)) (K_at_p4-3)) (K_not_at_p2-1)))
    (:action invariant-2335
        :effect (when (and (not (K_at_p4-3)) (K_at_p1-7)) (K_not_at_p4-3)))
    (:action invariant-2336
        :effect (when (and (not (K_at_p1-7)) (K_at_p4-3)) (K_not_at_p1-7)))
    (:action invariant-2337
        :effect (when (and (not (K_at_p4-3)) (K_at_p1-6)) (K_not_at_p4-3)))
    (:action invariant-2338
        :effect (when (and (not (K_at_p1-6)) (K_at_p4-3)) (K_not_at_p1-6)))
    (:action invariant-2339
        :effect (when (and (not (K_at_p4-3)) (K_at_p1-5)) (K_not_at_p4-3)))
    (:action invariant-2340
        :effect (when (and (not (K_at_p1-5)) (K_at_p4-3)) (K_not_at_p1-5)))
    (:action invariant-2341
        :effect (when (and (not (K_at_p4-3)) (K_at_p1-4)) (K_not_at_p4-3)))
    (:action invariant-2342
        :effect (when (and (not (K_at_p1-4)) (K_at_p4-3)) (K_not_at_p1-4)))
    (:action invariant-2343
        :effect (when (and (not (K_at_p4-3)) (K_at_p1-3)) (K_not_at_p4-3)))
    (:action invariant-2344
        :effect (when (and (not (K_at_p1-3)) (K_at_p4-3)) (K_not_at_p1-3)))
    (:action invariant-2345
        :effect (when (and (not (K_at_p4-3)) (K_at_p1-2)) (K_not_at_p4-3)))
    (:action invariant-2346
        :effect (when (and (not (K_at_p1-2)) (K_at_p4-3)) (K_not_at_p1-2)))
    (:action invariant-2347
        :effect (when (and (not (K_at_p4-3)) (K_at_p1-1)) (K_not_at_p4-3)))
    (:action invariant-2348
        :effect (when (and (not (K_at_p1-1)) (K_at_p4-3)) (K_not_at_p1-1)))
    (:action invariant-2349
        :effect (when (and (not (K_at_p4-2)) (K_at_p4-1)) (K_not_at_p4-2)))
    (:action invariant-2350
        :effect (when (and (not (K_at_p4-1)) (K_at_p4-2)) (K_not_at_p4-1)))
    (:action invariant-2351
        :effect (when (and (not (K_at_p4-2)) (K_at_p3-7)) (K_not_at_p4-2)))
    (:action invariant-2352
        :effect (when (and (not (K_at_p3-7)) (K_at_p4-2)) (K_not_at_p3-7)))
    (:action invariant-2353
        :effect (when (and (not (K_at_p4-2)) (K_at_p3-6)) (K_not_at_p4-2)))
    (:action invariant-2354
        :effect (when (and (not (K_at_p3-6)) (K_at_p4-2)) (K_not_at_p3-6)))
    (:action invariant-2355
        :effect (when (and (not (K_at_p4-2)) (K_at_p3-5)) (K_not_at_p4-2)))
    (:action invariant-2356
        :effect (when (and (not (K_at_p3-5)) (K_at_p4-2)) (K_not_at_p3-5)))
    (:action invariant-2357
        :effect (when (and (not (K_at_p4-2)) (K_at_p3-4)) (K_not_at_p4-2)))
    (:action invariant-2358
        :effect (when (and (not (K_at_p3-4)) (K_at_p4-2)) (K_not_at_p3-4)))
    (:action invariant-2359
        :effect (when (and (not (K_at_p4-2)) (K_at_p3-3)) (K_not_at_p4-2)))
    (:action invariant-2360
        :effect (when (and (not (K_at_p3-3)) (K_at_p4-2)) (K_not_at_p3-3)))
    (:action invariant-2361
        :effect (when (and (not (K_at_p4-2)) (K_at_p3-2)) (K_not_at_p4-2)))
    (:action invariant-2362
        :effect (when (and (not (K_at_p3-2)) (K_at_p4-2)) (K_not_at_p3-2)))
    (:action invariant-2363
        :effect (when (and (not (K_at_p4-2)) (K_at_p3-1)) (K_not_at_p4-2)))
    (:action invariant-2364
        :effect (when (and (not (K_at_p3-1)) (K_at_p4-2)) (K_not_at_p3-1)))
    (:action invariant-2365
        :effect (when (and (not (K_at_p4-2)) (K_at_p2-7)) (K_not_at_p4-2)))
    (:action invariant-2366
        :effect (when (and (not (K_at_p2-7)) (K_at_p4-2)) (K_not_at_p2-7)))
    (:action invariant-2367
        :effect (when (and (not (K_at_p4-2)) (K_at_p2-6)) (K_not_at_p4-2)))
    (:action invariant-2368
        :effect (when (and (not (K_at_p2-6)) (K_at_p4-2)) (K_not_at_p2-6)))
    (:action invariant-2369
        :effect (when (and (not (K_at_p4-2)) (K_at_p2-5)) (K_not_at_p4-2)))
    (:action invariant-2370
        :effect (when (and (not (K_at_p2-5)) (K_at_p4-2)) (K_not_at_p2-5)))
    (:action invariant-2371
        :effect (when (and (not (K_at_p4-2)) (K_at_p2-4)) (K_not_at_p4-2)))
    (:action invariant-2372
        :effect (when (and (not (K_at_p2-4)) (K_at_p4-2)) (K_not_at_p2-4)))
    (:action invariant-2373
        :effect (when (and (not (K_at_p4-2)) (K_at_p2-3)) (K_not_at_p4-2)))
    (:action invariant-2374
        :effect (when (and (not (K_at_p2-3)) (K_at_p4-2)) (K_not_at_p2-3)))
    (:action invariant-2375
        :effect (when (and (not (K_at_p4-2)) (K_at_p2-2)) (K_not_at_p4-2)))
    (:action invariant-2376
        :effect (when (and (not (K_at_p2-2)) (K_at_p4-2)) (K_not_at_p2-2)))
    (:action invariant-2377
        :effect (when (and (not (K_at_p4-2)) (K_at_p2-1)) (K_not_at_p4-2)))
    (:action invariant-2378
        :effect (when (and (not (K_at_p2-1)) (K_at_p4-2)) (K_not_at_p2-1)))
    (:action invariant-2379
        :effect (when (and (not (K_at_p4-2)) (K_at_p1-7)) (K_not_at_p4-2)))
    (:action invariant-2380
        :effect (when (and (not (K_at_p1-7)) (K_at_p4-2)) (K_not_at_p1-7)))
    (:action invariant-2381
        :effect (when (and (not (K_at_p4-2)) (K_at_p1-6)) (K_not_at_p4-2)))
    (:action invariant-2382
        :effect (when (and (not (K_at_p1-6)) (K_at_p4-2)) (K_not_at_p1-6)))
    (:action invariant-2383
        :effect (when (and (not (K_at_p4-2)) (K_at_p1-5)) (K_not_at_p4-2)))
    (:action invariant-2384
        :effect (when (and (not (K_at_p1-5)) (K_at_p4-2)) (K_not_at_p1-5)))
    (:action invariant-2385
        :effect (when (and (not (K_at_p4-2)) (K_at_p1-4)) (K_not_at_p4-2)))
    (:action invariant-2386
        :effect (when (and (not (K_at_p1-4)) (K_at_p4-2)) (K_not_at_p1-4)))
    (:action invariant-2387
        :effect (when (and (not (K_at_p4-2)) (K_at_p1-3)) (K_not_at_p4-2)))
    (:action invariant-2388
        :effect (when (and (not (K_at_p1-3)) (K_at_p4-2)) (K_not_at_p1-3)))
    (:action invariant-2389
        :effect (when (and (not (K_at_p4-2)) (K_at_p1-2)) (K_not_at_p4-2)))
    (:action invariant-2390
        :effect (when (and (not (K_at_p1-2)) (K_at_p4-2)) (K_not_at_p1-2)))
    (:action invariant-2391
        :effect (when (and (not (K_at_p4-2)) (K_at_p1-1)) (K_not_at_p4-2)))
    (:action invariant-2392
        :effect (when (and (not (K_at_p1-1)) (K_at_p4-2)) (K_not_at_p1-1)))
    (:action invariant-2393
        :effect (when (and (not (K_at_p4-1)) (K_at_p3-7)) (K_not_at_p4-1)))
    (:action invariant-2394
        :effect (when (and (not (K_at_p3-7)) (K_at_p4-1)) (K_not_at_p3-7)))
    (:action invariant-2395
        :effect (when (and (not (K_at_p4-1)) (K_at_p3-6)) (K_not_at_p4-1)))
    (:action invariant-2396
        :effect (when (and (not (K_at_p3-6)) (K_at_p4-1)) (K_not_at_p3-6)))
    (:action invariant-2397
        :effect (when (and (not (K_at_p4-1)) (K_at_p3-5)) (K_not_at_p4-1)))
    (:action invariant-2398
        :effect (when (and (not (K_at_p3-5)) (K_at_p4-1)) (K_not_at_p3-5)))
    (:action invariant-2399
        :effect (when (and (not (K_at_p4-1)) (K_at_p3-4)) (K_not_at_p4-1)))
    (:action invariant-2400
        :effect (when (and (not (K_at_p3-4)) (K_at_p4-1)) (K_not_at_p3-4)))
    (:action invariant-2401
        :effect (when (and (not (K_at_p4-1)) (K_at_p3-3)) (K_not_at_p4-1)))
    (:action invariant-2402
        :effect (when (and (not (K_at_p3-3)) (K_at_p4-1)) (K_not_at_p3-3)))
    (:action invariant-2403
        :effect (when (and (not (K_at_p4-1)) (K_at_p3-2)) (K_not_at_p4-1)))
    (:action invariant-2404
        :effect (when (and (not (K_at_p3-2)) (K_at_p4-1)) (K_not_at_p3-2)))
    (:action invariant-2405
        :effect (when (and (not (K_at_p4-1)) (K_at_p3-1)) (K_not_at_p4-1)))
    (:action invariant-2406
        :effect (when (and (not (K_at_p3-1)) (K_at_p4-1)) (K_not_at_p3-1)))
    (:action invariant-2407
        :effect (when (and (not (K_at_p4-1)) (K_at_p2-7)) (K_not_at_p4-1)))
    (:action invariant-2408
        :effect (when (and (not (K_at_p2-7)) (K_at_p4-1)) (K_not_at_p2-7)))
    (:action invariant-2409
        :effect (when (and (not (K_at_p4-1)) (K_at_p2-6)) (K_not_at_p4-1)))
    (:action invariant-2410
        :effect (when (and (not (K_at_p2-6)) (K_at_p4-1)) (K_not_at_p2-6)))
    (:action invariant-2411
        :effect (when (and (not (K_at_p4-1)) (K_at_p2-5)) (K_not_at_p4-1)))
    (:action invariant-2412
        :effect (when (and (not (K_at_p2-5)) (K_at_p4-1)) (K_not_at_p2-5)))
    (:action invariant-2413
        :effect (when (and (not (K_at_p4-1)) (K_at_p2-4)) (K_not_at_p4-1)))
    (:action invariant-2414
        :effect (when (and (not (K_at_p2-4)) (K_at_p4-1)) (K_not_at_p2-4)))
    (:action invariant-2415
        :effect (when (and (not (K_at_p4-1)) (K_at_p2-3)) (K_not_at_p4-1)))
    (:action invariant-2416
        :effect (when (and (not (K_at_p2-3)) (K_at_p4-1)) (K_not_at_p2-3)))
    (:action invariant-2417
        :effect (when (and (not (K_at_p4-1)) (K_at_p2-2)) (K_not_at_p4-1)))
    (:action invariant-2418
        :effect (when (and (not (K_at_p2-2)) (K_at_p4-1)) (K_not_at_p2-2)))
    (:action invariant-2419
        :effect (when (and (not (K_at_p4-1)) (K_at_p2-1)) (K_not_at_p4-1)))
    (:action invariant-2420
        :effect (when (and (not (K_at_p2-1)) (K_at_p4-1)) (K_not_at_p2-1)))
    (:action invariant-2421
        :effect (when (and (not (K_at_p4-1)) (K_at_p1-7)) (K_not_at_p4-1)))
    (:action invariant-2422
        :effect (when (and (not (K_at_p1-7)) (K_at_p4-1)) (K_not_at_p1-7)))
    (:action invariant-2423
        :effect (when (and (not (K_at_p4-1)) (K_at_p1-6)) (K_not_at_p4-1)))
    (:action invariant-2424
        :effect (when (and (not (K_at_p1-6)) (K_at_p4-1)) (K_not_at_p1-6)))
    (:action invariant-2425
        :effect (when (and (not (K_at_p4-1)) (K_at_p1-5)) (K_not_at_p4-1)))
    (:action invariant-2426
        :effect (when (and (not (K_at_p1-5)) (K_at_p4-1)) (K_not_at_p1-5)))
    (:action invariant-2427
        :effect (when (and (not (K_at_p4-1)) (K_at_p1-4)) (K_not_at_p4-1)))
    (:action invariant-2428
        :effect (when (and (not (K_at_p1-4)) (K_at_p4-1)) (K_not_at_p1-4)))
    (:action invariant-2429
        :effect (when (and (not (K_at_p4-1)) (K_at_p1-3)) (K_not_at_p4-1)))
    (:action invariant-2430
        :effect (when (and (not (K_at_p1-3)) (K_at_p4-1)) (K_not_at_p1-3)))
    (:action invariant-2431
        :effect (when (and (not (K_at_p4-1)) (K_at_p1-2)) (K_not_at_p4-1)))
    (:action invariant-2432
        :effect (when (and (not (K_at_p1-2)) (K_at_p4-1)) (K_not_at_p1-2)))
    (:action invariant-2433
        :effect (when (and (not (K_at_p4-1)) (K_at_p1-1)) (K_not_at_p4-1)))
    (:action invariant-2434
        :effect (when (and (not (K_at_p1-1)) (K_at_p4-1)) (K_not_at_p1-1)))
    (:action invariant-2435
        :effect (when (and (not (K_at_p3-7)) (K_at_p3-6)) (K_not_at_p3-7)))
    (:action invariant-2436
        :effect (when (and (not (K_at_p3-6)) (K_at_p3-7)) (K_not_at_p3-6)))
    (:action invariant-2437
        :effect (when (and (not (K_at_p3-7)) (K_at_p3-5)) (K_not_at_p3-7)))
    (:action invariant-2438
        :effect (when (and (not (K_at_p3-5)) (K_at_p3-7)) (K_not_at_p3-5)))
    (:action invariant-2439
        :effect (when (and (not (K_at_p3-7)) (K_at_p3-4)) (K_not_at_p3-7)))
    (:action invariant-2440
        :effect (when (and (not (K_at_p3-4)) (K_at_p3-7)) (K_not_at_p3-4)))
    (:action invariant-2441
        :effect (when (and (not (K_at_p3-7)) (K_at_p3-3)) (K_not_at_p3-7)))
    (:action invariant-2442
        :effect (when (and (not (K_at_p3-3)) (K_at_p3-7)) (K_not_at_p3-3)))
    (:action invariant-2443
        :effect (when (and (not (K_at_p3-7)) (K_at_p3-2)) (K_not_at_p3-7)))
    (:action invariant-2444
        :effect (when (and (not (K_at_p3-2)) (K_at_p3-7)) (K_not_at_p3-2)))
    (:action invariant-2445
        :effect (when (and (not (K_at_p3-7)) (K_at_p3-1)) (K_not_at_p3-7)))
    (:action invariant-2446
        :effect (when (and (not (K_at_p3-1)) (K_at_p3-7)) (K_not_at_p3-1)))
    (:action invariant-2447
        :effect (when (and (not (K_at_p3-7)) (K_at_p2-7)) (K_not_at_p3-7)))
    (:action invariant-2448
        :effect (when (and (not (K_at_p2-7)) (K_at_p3-7)) (K_not_at_p2-7)))
    (:action invariant-2449
        :effect (when (and (not (K_at_p3-7)) (K_at_p2-6)) (K_not_at_p3-7)))
    (:action invariant-2450
        :effect (when (and (not (K_at_p2-6)) (K_at_p3-7)) (K_not_at_p2-6)))
    (:action invariant-2451
        :effect (when (and (not (K_at_p3-7)) (K_at_p2-5)) (K_not_at_p3-7)))
    (:action invariant-2452
        :effect (when (and (not (K_at_p2-5)) (K_at_p3-7)) (K_not_at_p2-5)))
    (:action invariant-2453
        :effect (when (and (not (K_at_p3-7)) (K_at_p2-4)) (K_not_at_p3-7)))
    (:action invariant-2454
        :effect (when (and (not (K_at_p2-4)) (K_at_p3-7)) (K_not_at_p2-4)))
    (:action invariant-2455
        :effect (when (and (not (K_at_p3-7)) (K_at_p2-3)) (K_not_at_p3-7)))
    (:action invariant-2456
        :effect (when (and (not (K_at_p2-3)) (K_at_p3-7)) (K_not_at_p2-3)))
    (:action invariant-2457
        :effect (when (and (not (K_at_p3-7)) (K_at_p2-2)) (K_not_at_p3-7)))
    (:action invariant-2458
        :effect (when (and (not (K_at_p2-2)) (K_at_p3-7)) (K_not_at_p2-2)))
    (:action invariant-2459
        :effect (when (and (not (K_at_p3-7)) (K_at_p2-1)) (K_not_at_p3-7)))
    (:action invariant-2460
        :effect (when (and (not (K_at_p2-1)) (K_at_p3-7)) (K_not_at_p2-1)))
    (:action invariant-2461
        :effect (when (and (not (K_at_p3-7)) (K_at_p1-7)) (K_not_at_p3-7)))
    (:action invariant-2462
        :effect (when (and (not (K_at_p1-7)) (K_at_p3-7)) (K_not_at_p1-7)))
    (:action invariant-2463
        :effect (when (and (not (K_at_p3-7)) (K_at_p1-6)) (K_not_at_p3-7)))
    (:action invariant-2464
        :effect (when (and (not (K_at_p1-6)) (K_at_p3-7)) (K_not_at_p1-6)))
    (:action invariant-2465
        :effect (when (and (not (K_at_p3-7)) (K_at_p1-5)) (K_not_at_p3-7)))
    (:action invariant-2466
        :effect (when (and (not (K_at_p1-5)) (K_at_p3-7)) (K_not_at_p1-5)))
    (:action invariant-2467
        :effect (when (and (not (K_at_p3-7)) (K_at_p1-4)) (K_not_at_p3-7)))
    (:action invariant-2468
        :effect (when (and (not (K_at_p1-4)) (K_at_p3-7)) (K_not_at_p1-4)))
    (:action invariant-2469
        :effect (when (and (not (K_at_p3-7)) (K_at_p1-3)) (K_not_at_p3-7)))
    (:action invariant-2470
        :effect (when (and (not (K_at_p1-3)) (K_at_p3-7)) (K_not_at_p1-3)))
    (:action invariant-2471
        :effect (when (and (not (K_at_p3-7)) (K_at_p1-2)) (K_not_at_p3-7)))
    (:action invariant-2472
        :effect (when (and (not (K_at_p1-2)) (K_at_p3-7)) (K_not_at_p1-2)))
    (:action invariant-2473
        :effect (when (and (not (K_at_p3-7)) (K_at_p1-1)) (K_not_at_p3-7)))
    (:action invariant-2474
        :effect (when (and (not (K_at_p1-1)) (K_at_p3-7)) (K_not_at_p1-1)))
    (:action invariant-2475
        :effect (when (and (not (K_at_p3-6)) (K_at_p3-5)) (K_not_at_p3-6)))
    (:action invariant-2476
        :effect (when (and (not (K_at_p3-5)) (K_at_p3-6)) (K_not_at_p3-5)))
    (:action invariant-2477
        :effect (when (and (not (K_at_p3-6)) (K_at_p3-4)) (K_not_at_p3-6)))
    (:action invariant-2478
        :effect (when (and (not (K_at_p3-4)) (K_at_p3-6)) (K_not_at_p3-4)))
    (:action invariant-2479
        :effect (when (and (not (K_at_p3-6)) (K_at_p3-3)) (K_not_at_p3-6)))
    (:action invariant-2480
        :effect (when (and (not (K_at_p3-3)) (K_at_p3-6)) (K_not_at_p3-3)))
    (:action invariant-2481
        :effect (when (and (not (K_at_p3-6)) (K_at_p3-2)) (K_not_at_p3-6)))
    (:action invariant-2482
        :effect (when (and (not (K_at_p3-2)) (K_at_p3-6)) (K_not_at_p3-2)))
    (:action invariant-2483
        :effect (when (and (not (K_at_p3-6)) (K_at_p3-1)) (K_not_at_p3-6)))
    (:action invariant-2484
        :effect (when (and (not (K_at_p3-1)) (K_at_p3-6)) (K_not_at_p3-1)))
    (:action invariant-2485
        :effect (when (and (not (K_at_p3-6)) (K_at_p2-7)) (K_not_at_p3-6)))
    (:action invariant-2486
        :effect (when (and (not (K_at_p2-7)) (K_at_p3-6)) (K_not_at_p2-7)))
    (:action invariant-2487
        :effect (when (and (not (K_at_p3-6)) (K_at_p2-6)) (K_not_at_p3-6)))
    (:action invariant-2488
        :effect (when (and (not (K_at_p2-6)) (K_at_p3-6)) (K_not_at_p2-6)))
    (:action invariant-2489
        :effect (when (and (not (K_at_p3-6)) (K_at_p2-5)) (K_not_at_p3-6)))
    (:action invariant-2490
        :effect (when (and (not (K_at_p2-5)) (K_at_p3-6)) (K_not_at_p2-5)))
    (:action invariant-2491
        :effect (when (and (not (K_at_p3-6)) (K_at_p2-4)) (K_not_at_p3-6)))
    (:action invariant-2492
        :effect (when (and (not (K_at_p2-4)) (K_at_p3-6)) (K_not_at_p2-4)))
    (:action invariant-2493
        :effect (when (and (not (K_at_p3-6)) (K_at_p2-3)) (K_not_at_p3-6)))
    (:action invariant-2494
        :effect (when (and (not (K_at_p2-3)) (K_at_p3-6)) (K_not_at_p2-3)))
    (:action invariant-2495
        :effect (when (and (not (K_at_p3-6)) (K_at_p2-2)) (K_not_at_p3-6)))
    (:action invariant-2496
        :effect (when (and (not (K_at_p2-2)) (K_at_p3-6)) (K_not_at_p2-2)))
    (:action invariant-2497
        :effect (when (and (not (K_at_p3-6)) (K_at_p2-1)) (K_not_at_p3-6)))
    (:action invariant-2498
        :effect (when (and (not (K_at_p2-1)) (K_at_p3-6)) (K_not_at_p2-1)))
    (:action invariant-2499
        :effect (when (and (not (K_at_p3-6)) (K_at_p1-7)) (K_not_at_p3-6)))
    (:action invariant-2500
        :effect (when (and (not (K_at_p1-7)) (K_at_p3-6)) (K_not_at_p1-7)))
    (:action invariant-2501
        :effect (when (and (not (K_at_p3-6)) (K_at_p1-6)) (K_not_at_p3-6)))
    (:action invariant-2502
        :effect (when (and (not (K_at_p1-6)) (K_at_p3-6)) (K_not_at_p1-6)))
    (:action invariant-2503
        :effect (when (and (not (K_at_p3-6)) (K_at_p1-5)) (K_not_at_p3-6)))
    (:action invariant-2504
        :effect (when (and (not (K_at_p1-5)) (K_at_p3-6)) (K_not_at_p1-5)))
    (:action invariant-2505
        :effect (when (and (not (K_at_p3-6)) (K_at_p1-4)) (K_not_at_p3-6)))
    (:action invariant-2506
        :effect (when (and (not (K_at_p1-4)) (K_at_p3-6)) (K_not_at_p1-4)))
    (:action invariant-2507
        :effect (when (and (not (K_at_p3-6)) (K_at_p1-3)) (K_not_at_p3-6)))
    (:action invariant-2508
        :effect (when (and (not (K_at_p1-3)) (K_at_p3-6)) (K_not_at_p1-3)))
    (:action invariant-2509
        :effect (when (and (not (K_at_p3-6)) (K_at_p1-2)) (K_not_at_p3-6)))
    (:action invariant-2510
        :effect (when (and (not (K_at_p1-2)) (K_at_p3-6)) (K_not_at_p1-2)))
    (:action invariant-2511
        :effect (when (and (not (K_at_p3-6)) (K_at_p1-1)) (K_not_at_p3-6)))
    (:action invariant-2512
        :effect (when (and (not (K_at_p1-1)) (K_at_p3-6)) (K_not_at_p1-1)))
    (:action invariant-2513
        :effect (when (and (not (K_at_p3-5)) (K_at_p3-4)) (K_not_at_p3-5)))
    (:action invariant-2514
        :effect (when (and (not (K_at_p3-4)) (K_at_p3-5)) (K_not_at_p3-4)))
    (:action invariant-2515
        :effect (when (and (not (K_at_p3-5)) (K_at_p3-3)) (K_not_at_p3-5)))
    (:action invariant-2516
        :effect (when (and (not (K_at_p3-3)) (K_at_p3-5)) (K_not_at_p3-3)))
    (:action invariant-2517
        :effect (when (and (not (K_at_p3-5)) (K_at_p3-2)) (K_not_at_p3-5)))
    (:action invariant-2518
        :effect (when (and (not (K_at_p3-2)) (K_at_p3-5)) (K_not_at_p3-2)))
    (:action invariant-2519
        :effect (when (and (not (K_at_p3-5)) (K_at_p3-1)) (K_not_at_p3-5)))
    (:action invariant-2520
        :effect (when (and (not (K_at_p3-1)) (K_at_p3-5)) (K_not_at_p3-1)))
    (:action invariant-2521
        :effect (when (and (not (K_at_p3-5)) (K_at_p2-7)) (K_not_at_p3-5)))
    (:action invariant-2522
        :effect (when (and (not (K_at_p2-7)) (K_at_p3-5)) (K_not_at_p2-7)))
    (:action invariant-2523
        :effect (when (and (not (K_at_p3-5)) (K_at_p2-6)) (K_not_at_p3-5)))
    (:action invariant-2524
        :effect (when (and (not (K_at_p2-6)) (K_at_p3-5)) (K_not_at_p2-6)))
    (:action invariant-2525
        :effect (when (and (not (K_at_p3-5)) (K_at_p2-5)) (K_not_at_p3-5)))
    (:action invariant-2526
        :effect (when (and (not (K_at_p2-5)) (K_at_p3-5)) (K_not_at_p2-5)))
    (:action invariant-2527
        :effect (when (and (not (K_at_p3-5)) (K_at_p2-4)) (K_not_at_p3-5)))
    (:action invariant-2528
        :effect (when (and (not (K_at_p2-4)) (K_at_p3-5)) (K_not_at_p2-4)))
    (:action invariant-2529
        :effect (when (and (not (K_at_p3-5)) (K_at_p2-3)) (K_not_at_p3-5)))
    (:action invariant-2530
        :effect (when (and (not (K_at_p2-3)) (K_at_p3-5)) (K_not_at_p2-3)))
    (:action invariant-2531
        :effect (when (and (not (K_at_p3-5)) (K_at_p2-2)) (K_not_at_p3-5)))
    (:action invariant-2532
        :effect (when (and (not (K_at_p2-2)) (K_at_p3-5)) (K_not_at_p2-2)))
    (:action invariant-2533
        :effect (when (and (not (K_at_p3-5)) (K_at_p2-1)) (K_not_at_p3-5)))
    (:action invariant-2534
        :effect (when (and (not (K_at_p2-1)) (K_at_p3-5)) (K_not_at_p2-1)))
    (:action invariant-2535
        :effect (when (and (not (K_at_p3-5)) (K_at_p1-7)) (K_not_at_p3-5)))
    (:action invariant-2536
        :effect (when (and (not (K_at_p1-7)) (K_at_p3-5)) (K_not_at_p1-7)))
    (:action invariant-2537
        :effect (when (and (not (K_at_p3-5)) (K_at_p1-6)) (K_not_at_p3-5)))
    (:action invariant-2538
        :effect (when (and (not (K_at_p1-6)) (K_at_p3-5)) (K_not_at_p1-6)))
    (:action invariant-2539
        :effect (when (and (not (K_at_p3-5)) (K_at_p1-5)) (K_not_at_p3-5)))
    (:action invariant-2540
        :effect (when (and (not (K_at_p1-5)) (K_at_p3-5)) (K_not_at_p1-5)))
    (:action invariant-2541
        :effect (when (and (not (K_at_p3-5)) (K_at_p1-4)) (K_not_at_p3-5)))
    (:action invariant-2542
        :effect (when (and (not (K_at_p1-4)) (K_at_p3-5)) (K_not_at_p1-4)))
    (:action invariant-2543
        :effect (when (and (not (K_at_p3-5)) (K_at_p1-3)) (K_not_at_p3-5)))
    (:action invariant-2544
        :effect (when (and (not (K_at_p1-3)) (K_at_p3-5)) (K_not_at_p1-3)))
    (:action invariant-2545
        :effect (when (and (not (K_at_p3-5)) (K_at_p1-2)) (K_not_at_p3-5)))
    (:action invariant-2546
        :effect (when (and (not (K_at_p1-2)) (K_at_p3-5)) (K_not_at_p1-2)))
    (:action invariant-2547
        :effect (when (and (not (K_at_p3-5)) (K_at_p1-1)) (K_not_at_p3-5)))
    (:action invariant-2548
        :effect (when (and (not (K_at_p1-1)) (K_at_p3-5)) (K_not_at_p1-1)))
    (:action invariant-2549
        :effect (when (and (not (K_at_p3-4)) (K_at_p3-3)) (K_not_at_p3-4)))
    (:action invariant-2550
        :effect (when (and (not (K_at_p3-3)) (K_at_p3-4)) (K_not_at_p3-3)))
    (:action invariant-2551
        :effect (when (and (not (K_at_p3-4)) (K_at_p3-2)) (K_not_at_p3-4)))
    (:action invariant-2552
        :effect (when (and (not (K_at_p3-2)) (K_at_p3-4)) (K_not_at_p3-2)))
    (:action invariant-2553
        :effect (when (and (not (K_at_p3-4)) (K_at_p3-1)) (K_not_at_p3-4)))
    (:action invariant-2554
        :effect (when (and (not (K_at_p3-1)) (K_at_p3-4)) (K_not_at_p3-1)))
    (:action invariant-2555
        :effect (when (and (not (K_at_p3-4)) (K_at_p2-7)) (K_not_at_p3-4)))
    (:action invariant-2556
        :effect (when (and (not (K_at_p2-7)) (K_at_p3-4)) (K_not_at_p2-7)))
    (:action invariant-2557
        :effect (when (and (not (K_at_p3-4)) (K_at_p2-6)) (K_not_at_p3-4)))
    (:action invariant-2558
        :effect (when (and (not (K_at_p2-6)) (K_at_p3-4)) (K_not_at_p2-6)))
    (:action invariant-2559
        :effect (when (and (not (K_at_p3-4)) (K_at_p2-5)) (K_not_at_p3-4)))
    (:action invariant-2560
        :effect (when (and (not (K_at_p2-5)) (K_at_p3-4)) (K_not_at_p2-5)))
    (:action invariant-2561
        :effect (when (and (not (K_at_p3-4)) (K_at_p2-4)) (K_not_at_p3-4)))
    (:action invariant-2562
        :effect (when (and (not (K_at_p2-4)) (K_at_p3-4)) (K_not_at_p2-4)))
    (:action invariant-2563
        :effect (when (and (not (K_at_p3-4)) (K_at_p2-3)) (K_not_at_p3-4)))
    (:action invariant-2564
        :effect (when (and (not (K_at_p2-3)) (K_at_p3-4)) (K_not_at_p2-3)))
    (:action invariant-2565
        :effect (when (and (not (K_at_p3-4)) (K_at_p2-2)) (K_not_at_p3-4)))
    (:action invariant-2566
        :effect (when (and (not (K_at_p2-2)) (K_at_p3-4)) (K_not_at_p2-2)))
    (:action invariant-2567
        :effect (when (and (not (K_at_p3-4)) (K_at_p2-1)) (K_not_at_p3-4)))
    (:action invariant-2568
        :effect (when (and (not (K_at_p2-1)) (K_at_p3-4)) (K_not_at_p2-1)))
    (:action invariant-2569
        :effect (when (and (not (K_at_p3-4)) (K_at_p1-7)) (K_not_at_p3-4)))
    (:action invariant-2570
        :effect (when (and (not (K_at_p1-7)) (K_at_p3-4)) (K_not_at_p1-7)))
    (:action invariant-2571
        :effect (when (and (not (K_at_p3-4)) (K_at_p1-6)) (K_not_at_p3-4)))
    (:action invariant-2572
        :effect (when (and (not (K_at_p1-6)) (K_at_p3-4)) (K_not_at_p1-6)))
    (:action invariant-2573
        :effect (when (and (not (K_at_p3-4)) (K_at_p1-5)) (K_not_at_p3-4)))
    (:action invariant-2574
        :effect (when (and (not (K_at_p1-5)) (K_at_p3-4)) (K_not_at_p1-5)))
    (:action invariant-2575
        :effect (when (and (not (K_at_p3-4)) (K_at_p1-4)) (K_not_at_p3-4)))
    (:action invariant-2576
        :effect (when (and (not (K_at_p1-4)) (K_at_p3-4)) (K_not_at_p1-4)))
    (:action invariant-2577
        :effect (when (and (not (K_at_p3-4)) (K_at_p1-3)) (K_not_at_p3-4)))
    (:action invariant-2578
        :effect (when (and (not (K_at_p1-3)) (K_at_p3-4)) (K_not_at_p1-3)))
    (:action invariant-2579
        :effect (when (and (not (K_at_p3-4)) (K_at_p1-2)) (K_not_at_p3-4)))
    (:action invariant-2580
        :effect (when (and (not (K_at_p1-2)) (K_at_p3-4)) (K_not_at_p1-2)))
    (:action invariant-2581
        :effect (when (and (not (K_at_p3-4)) (K_at_p1-1)) (K_not_at_p3-4)))
    (:action invariant-2582
        :effect (when (and (not (K_at_p1-1)) (K_at_p3-4)) (K_not_at_p1-1)))
    (:action invariant-2583
        :effect (when (and (not (K_at_p3-3)) (K_at_p3-2)) (K_not_at_p3-3)))
    (:action invariant-2584
        :effect (when (and (not (K_at_p3-2)) (K_at_p3-3)) (K_not_at_p3-2)))
    (:action invariant-2585
        :effect (when (and (not (K_at_p3-3)) (K_at_p3-1)) (K_not_at_p3-3)))
    (:action invariant-2586
        :effect (when (and (not (K_at_p3-1)) (K_at_p3-3)) (K_not_at_p3-1)))
    (:action invariant-2587
        :effect (when (and (not (K_at_p3-3)) (K_at_p2-7)) (K_not_at_p3-3)))
    (:action invariant-2588
        :effect (when (and (not (K_at_p2-7)) (K_at_p3-3)) (K_not_at_p2-7)))
    (:action invariant-2589
        :effect (when (and (not (K_at_p3-3)) (K_at_p2-6)) (K_not_at_p3-3)))
    (:action invariant-2590
        :effect (when (and (not (K_at_p2-6)) (K_at_p3-3)) (K_not_at_p2-6)))
    (:action invariant-2591
        :effect (when (and (not (K_at_p3-3)) (K_at_p2-5)) (K_not_at_p3-3)))
    (:action invariant-2592
        :effect (when (and (not (K_at_p2-5)) (K_at_p3-3)) (K_not_at_p2-5)))
    (:action invariant-2593
        :effect (when (and (not (K_at_p3-3)) (K_at_p2-4)) (K_not_at_p3-3)))
    (:action invariant-2594
        :effect (when (and (not (K_at_p2-4)) (K_at_p3-3)) (K_not_at_p2-4)))
    (:action invariant-2595
        :effect (when (and (not (K_at_p3-3)) (K_at_p2-3)) (K_not_at_p3-3)))
    (:action invariant-2596
        :effect (when (and (not (K_at_p2-3)) (K_at_p3-3)) (K_not_at_p2-3)))
    (:action invariant-2597
        :effect (when (and (not (K_at_p3-3)) (K_at_p2-2)) (K_not_at_p3-3)))
    (:action invariant-2598
        :effect (when (and (not (K_at_p2-2)) (K_at_p3-3)) (K_not_at_p2-2)))
    (:action invariant-2599
        :effect (when (and (not (K_at_p3-3)) (K_at_p2-1)) (K_not_at_p3-3)))
    (:action invariant-2600
        :effect (when (and (not (K_at_p2-1)) (K_at_p3-3)) (K_not_at_p2-1)))
    (:action invariant-2601
        :effect (when (and (not (K_at_p3-3)) (K_at_p1-7)) (K_not_at_p3-3)))
    (:action invariant-2602
        :effect (when (and (not (K_at_p1-7)) (K_at_p3-3)) (K_not_at_p1-7)))
    (:action invariant-2603
        :effect (when (and (not (K_at_p3-3)) (K_at_p1-6)) (K_not_at_p3-3)))
    (:action invariant-2604
        :effect (when (and (not (K_at_p1-6)) (K_at_p3-3)) (K_not_at_p1-6)))
    (:action invariant-2605
        :effect (when (and (not (K_at_p3-3)) (K_at_p1-5)) (K_not_at_p3-3)))
    (:action invariant-2606
        :effect (when (and (not (K_at_p1-5)) (K_at_p3-3)) (K_not_at_p1-5)))
    (:action invariant-2607
        :effect (when (and (not (K_at_p3-3)) (K_at_p1-4)) (K_not_at_p3-3)))
    (:action invariant-2608
        :effect (when (and (not (K_at_p1-4)) (K_at_p3-3)) (K_not_at_p1-4)))
    (:action invariant-2609
        :effect (when (and (not (K_at_p3-3)) (K_at_p1-3)) (K_not_at_p3-3)))
    (:action invariant-2610
        :effect (when (and (not (K_at_p1-3)) (K_at_p3-3)) (K_not_at_p1-3)))
    (:action invariant-2611
        :effect (when (and (not (K_at_p3-3)) (K_at_p1-2)) (K_not_at_p3-3)))
    (:action invariant-2612
        :effect (when (and (not (K_at_p1-2)) (K_at_p3-3)) (K_not_at_p1-2)))
    (:action invariant-2613
        :effect (when (and (not (K_at_p3-3)) (K_at_p1-1)) (K_not_at_p3-3)))
    (:action invariant-2614
        :effect (when (and (not (K_at_p1-1)) (K_at_p3-3)) (K_not_at_p1-1)))
    (:action invariant-2615
        :effect (when (and (not (K_at_p3-2)) (K_at_p3-1)) (K_not_at_p3-2)))
    (:action invariant-2616
        :effect (when (and (not (K_at_p3-1)) (K_at_p3-2)) (K_not_at_p3-1)))
    (:action invariant-2617
        :effect (when (and (not (K_at_p3-2)) (K_at_p2-7)) (K_not_at_p3-2)))
    (:action invariant-2618
        :effect (when (and (not (K_at_p2-7)) (K_at_p3-2)) (K_not_at_p2-7)))
    (:action invariant-2619
        :effect (when (and (not (K_at_p3-2)) (K_at_p2-6)) (K_not_at_p3-2)))
    (:action invariant-2620
        :effect (when (and (not (K_at_p2-6)) (K_at_p3-2)) (K_not_at_p2-6)))
    (:action invariant-2621
        :effect (when (and (not (K_at_p3-2)) (K_at_p2-5)) (K_not_at_p3-2)))
    (:action invariant-2622
        :effect (when (and (not (K_at_p2-5)) (K_at_p3-2)) (K_not_at_p2-5)))
    (:action invariant-2623
        :effect (when (and (not (K_at_p3-2)) (K_at_p2-4)) (K_not_at_p3-2)))
    (:action invariant-2624
        :effect (when (and (not (K_at_p2-4)) (K_at_p3-2)) (K_not_at_p2-4)))
    (:action invariant-2625
        :effect (when (and (not (K_at_p3-2)) (K_at_p2-3)) (K_not_at_p3-2)))
    (:action invariant-2626
        :effect (when (and (not (K_at_p2-3)) (K_at_p3-2)) (K_not_at_p2-3)))
    (:action invariant-2627
        :effect (when (and (not (K_at_p3-2)) (K_at_p2-2)) (K_not_at_p3-2)))
    (:action invariant-2628
        :effect (when (and (not (K_at_p2-2)) (K_at_p3-2)) (K_not_at_p2-2)))
    (:action invariant-2629
        :effect (when (and (not (K_at_p3-2)) (K_at_p2-1)) (K_not_at_p3-2)))
    (:action invariant-2630
        :effect (when (and (not (K_at_p2-1)) (K_at_p3-2)) (K_not_at_p2-1)))
    (:action invariant-2631
        :effect (when (and (not (K_at_p3-2)) (K_at_p1-7)) (K_not_at_p3-2)))
    (:action invariant-2632
        :effect (when (and (not (K_at_p1-7)) (K_at_p3-2)) (K_not_at_p1-7)))
    (:action invariant-2633
        :effect (when (and (not (K_at_p3-2)) (K_at_p1-6)) (K_not_at_p3-2)))
    (:action invariant-2634
        :effect (when (and (not (K_at_p1-6)) (K_at_p3-2)) (K_not_at_p1-6)))
    (:action invariant-2635
        :effect (when (and (not (K_at_p3-2)) (K_at_p1-5)) (K_not_at_p3-2)))
    (:action invariant-2636
        :effect (when (and (not (K_at_p1-5)) (K_at_p3-2)) (K_not_at_p1-5)))
    (:action invariant-2637
        :effect (when (and (not (K_at_p3-2)) (K_at_p1-4)) (K_not_at_p3-2)))
    (:action invariant-2638
        :effect (when (and (not (K_at_p1-4)) (K_at_p3-2)) (K_not_at_p1-4)))
    (:action invariant-2639
        :effect (when (and (not (K_at_p3-2)) (K_at_p1-3)) (K_not_at_p3-2)))
    (:action invariant-2640
        :effect (when (and (not (K_at_p1-3)) (K_at_p3-2)) (K_not_at_p1-3)))
    (:action invariant-2641
        :effect (when (and (not (K_at_p3-2)) (K_at_p1-2)) (K_not_at_p3-2)))
    (:action invariant-2642
        :effect (when (and (not (K_at_p1-2)) (K_at_p3-2)) (K_not_at_p1-2)))
    (:action invariant-2643
        :effect (when (and (not (K_at_p3-2)) (K_at_p1-1)) (K_not_at_p3-2)))
    (:action invariant-2644
        :effect (when (and (not (K_at_p1-1)) (K_at_p3-2)) (K_not_at_p1-1)))
    (:action invariant-2645
        :effect (when (and (not (K_at_p3-1)) (K_at_p2-7)) (K_not_at_p3-1)))
    (:action invariant-2646
        :effect (when (and (not (K_at_p2-7)) (K_at_p3-1)) (K_not_at_p2-7)))
    (:action invariant-2647
        :effect (when (and (not (K_at_p3-1)) (K_at_p2-6)) (K_not_at_p3-1)))
    (:action invariant-2648
        :effect (when (and (not (K_at_p2-6)) (K_at_p3-1)) (K_not_at_p2-6)))
    (:action invariant-2649
        :effect (when (and (not (K_at_p3-1)) (K_at_p2-5)) (K_not_at_p3-1)))
    (:action invariant-2650
        :effect (when (and (not (K_at_p2-5)) (K_at_p3-1)) (K_not_at_p2-5)))
    (:action invariant-2651
        :effect (when (and (not (K_at_p3-1)) (K_at_p2-4)) (K_not_at_p3-1)))
    (:action invariant-2652
        :effect (when (and (not (K_at_p2-4)) (K_at_p3-1)) (K_not_at_p2-4)))
    (:action invariant-2653
        :effect (when (and (not (K_at_p3-1)) (K_at_p2-3)) (K_not_at_p3-1)))
    (:action invariant-2654
        :effect (when (and (not (K_at_p2-3)) (K_at_p3-1)) (K_not_at_p2-3)))
    (:action invariant-2655
        :effect (when (and (not (K_at_p3-1)) (K_at_p2-2)) (K_not_at_p3-1)))
    (:action invariant-2656
        :effect (when (and (not (K_at_p2-2)) (K_at_p3-1)) (K_not_at_p2-2)))
    (:action invariant-2657
        :effect (when (and (not (K_at_p3-1)) (K_at_p2-1)) (K_not_at_p3-1)))
    (:action invariant-2658
        :effect (when (and (not (K_at_p2-1)) (K_at_p3-1)) (K_not_at_p2-1)))
    (:action invariant-2659
        :effect (when (and (not (K_at_p3-1)) (K_at_p1-7)) (K_not_at_p3-1)))
    (:action invariant-2660
        :effect (when (and (not (K_at_p1-7)) (K_at_p3-1)) (K_not_at_p1-7)))
    (:action invariant-2661
        :effect (when (and (not (K_at_p3-1)) (K_at_p1-6)) (K_not_at_p3-1)))
    (:action invariant-2662
        :effect (when (and (not (K_at_p1-6)) (K_at_p3-1)) (K_not_at_p1-6)))
    (:action invariant-2663
        :effect (when (and (not (K_at_p3-1)) (K_at_p1-5)) (K_not_at_p3-1)))
    (:action invariant-2664
        :effect (when (and (not (K_at_p1-5)) (K_at_p3-1)) (K_not_at_p1-5)))
    (:action invariant-2665
        :effect (when (and (not (K_at_p3-1)) (K_at_p1-4)) (K_not_at_p3-1)))
    (:action invariant-2666
        :effect (when (and (not (K_at_p1-4)) (K_at_p3-1)) (K_not_at_p1-4)))
    (:action invariant-2667
        :effect (when (and (not (K_at_p3-1)) (K_at_p1-3)) (K_not_at_p3-1)))
    (:action invariant-2668
        :effect (when (and (not (K_at_p1-3)) (K_at_p3-1)) (K_not_at_p1-3)))
    (:action invariant-2669
        :effect (when (and (not (K_at_p3-1)) (K_at_p1-2)) (K_not_at_p3-1)))
    (:action invariant-2670
        :effect (when (and (not (K_at_p1-2)) (K_at_p3-1)) (K_not_at_p1-2)))
    (:action invariant-2671
        :effect (when (and (not (K_at_p3-1)) (K_at_p1-1)) (K_not_at_p3-1)))
    (:action invariant-2672
        :effect (when (and (not (K_at_p1-1)) (K_at_p3-1)) (K_not_at_p1-1)))
    (:action invariant-2673
        :effect (when (and (not (K_at_p2-7)) (K_at_p2-6)) (K_not_at_p2-7)))
    (:action invariant-2674
        :effect (when (and (not (K_at_p2-6)) (K_at_p2-7)) (K_not_at_p2-6)))
    (:action invariant-2675
        :effect (when (and (not (K_at_p2-7)) (K_at_p2-5)) (K_not_at_p2-7)))
    (:action invariant-2676
        :effect (when (and (not (K_at_p2-5)) (K_at_p2-7)) (K_not_at_p2-5)))
    (:action invariant-2677
        :effect (when (and (not (K_at_p2-7)) (K_at_p2-4)) (K_not_at_p2-7)))
    (:action invariant-2678
        :effect (when (and (not (K_at_p2-4)) (K_at_p2-7)) (K_not_at_p2-4)))
    (:action invariant-2679
        :effect (when (and (not (K_at_p2-7)) (K_at_p2-3)) (K_not_at_p2-7)))
    (:action invariant-2680
        :effect (when (and (not (K_at_p2-3)) (K_at_p2-7)) (K_not_at_p2-3)))
    (:action invariant-2681
        :effect (when (and (not (K_at_p2-7)) (K_at_p2-2)) (K_not_at_p2-7)))
    (:action invariant-2682
        :effect (when (and (not (K_at_p2-2)) (K_at_p2-7)) (K_not_at_p2-2)))
    (:action invariant-2683
        :effect (when (and (not (K_at_p2-7)) (K_at_p2-1)) (K_not_at_p2-7)))
    (:action invariant-2684
        :effect (when (and (not (K_at_p2-1)) (K_at_p2-7)) (K_not_at_p2-1)))
    (:action invariant-2685
        :effect (when (and (not (K_at_p2-7)) (K_at_p1-7)) (K_not_at_p2-7)))
    (:action invariant-2686
        :effect (when (and (not (K_at_p1-7)) (K_at_p2-7)) (K_not_at_p1-7)))
    (:action invariant-2687
        :effect (when (and (not (K_at_p2-7)) (K_at_p1-6)) (K_not_at_p2-7)))
    (:action invariant-2688
        :effect (when (and (not (K_at_p1-6)) (K_at_p2-7)) (K_not_at_p1-6)))
    (:action invariant-2689
        :effect (when (and (not (K_at_p2-7)) (K_at_p1-5)) (K_not_at_p2-7)))
    (:action invariant-2690
        :effect (when (and (not (K_at_p1-5)) (K_at_p2-7)) (K_not_at_p1-5)))
    (:action invariant-2691
        :effect (when (and (not (K_at_p2-7)) (K_at_p1-4)) (K_not_at_p2-7)))
    (:action invariant-2692
        :effect (when (and (not (K_at_p1-4)) (K_at_p2-7)) (K_not_at_p1-4)))
    (:action invariant-2693
        :effect (when (and (not (K_at_p2-7)) (K_at_p1-3)) (K_not_at_p2-7)))
    (:action invariant-2694
        :effect (when (and (not (K_at_p1-3)) (K_at_p2-7)) (K_not_at_p1-3)))
    (:action invariant-2695
        :effect (when (and (not (K_at_p2-7)) (K_at_p1-2)) (K_not_at_p2-7)))
    (:action invariant-2696
        :effect (when (and (not (K_at_p1-2)) (K_at_p2-7)) (K_not_at_p1-2)))
    (:action invariant-2697
        :effect (when (and (not (K_at_p2-7)) (K_at_p1-1)) (K_not_at_p2-7)))
    (:action invariant-2698
        :effect (when (and (not (K_at_p1-1)) (K_at_p2-7)) (K_not_at_p1-1)))
    (:action invariant-2699
        :effect (when (and (not (K_at_p2-6)) (K_at_p2-5)) (K_not_at_p2-6)))
    (:action invariant-2700
        :effect (when (and (not (K_at_p2-5)) (K_at_p2-6)) (K_not_at_p2-5)))
    (:action invariant-2701
        :effect (when (and (not (K_at_p2-6)) (K_at_p2-4)) (K_not_at_p2-6)))
    (:action invariant-2702
        :effect (when (and (not (K_at_p2-4)) (K_at_p2-6)) (K_not_at_p2-4)))
    (:action invariant-2703
        :effect (when (and (not (K_at_p2-6)) (K_at_p2-3)) (K_not_at_p2-6)))
    (:action invariant-2704
        :effect (when (and (not (K_at_p2-3)) (K_at_p2-6)) (K_not_at_p2-3)))
    (:action invariant-2705
        :effect (when (and (not (K_at_p2-6)) (K_at_p2-2)) (K_not_at_p2-6)))
    (:action invariant-2706
        :effect (when (and (not (K_at_p2-2)) (K_at_p2-6)) (K_not_at_p2-2)))
    (:action invariant-2707
        :effect (when (and (not (K_at_p2-6)) (K_at_p2-1)) (K_not_at_p2-6)))
    (:action invariant-2708
        :effect (when (and (not (K_at_p2-1)) (K_at_p2-6)) (K_not_at_p2-1)))
    (:action invariant-2709
        :effect (when (and (not (K_at_p2-6)) (K_at_p1-7)) (K_not_at_p2-6)))
    (:action invariant-2710
        :effect (when (and (not (K_at_p1-7)) (K_at_p2-6)) (K_not_at_p1-7)))
    (:action invariant-2711
        :effect (when (and (not (K_at_p2-6)) (K_at_p1-6)) (K_not_at_p2-6)))
    (:action invariant-2712
        :effect (when (and (not (K_at_p1-6)) (K_at_p2-6)) (K_not_at_p1-6)))
    (:action invariant-2713
        :effect (when (and (not (K_at_p2-6)) (K_at_p1-5)) (K_not_at_p2-6)))
    (:action invariant-2714
        :effect (when (and (not (K_at_p1-5)) (K_at_p2-6)) (K_not_at_p1-5)))
    (:action invariant-2715
        :effect (when (and (not (K_at_p2-6)) (K_at_p1-4)) (K_not_at_p2-6)))
    (:action invariant-2716
        :effect (when (and (not (K_at_p1-4)) (K_at_p2-6)) (K_not_at_p1-4)))
    (:action invariant-2717
        :effect (when (and (not (K_at_p2-6)) (K_at_p1-3)) (K_not_at_p2-6)))
    (:action invariant-2718
        :effect (when (and (not (K_at_p1-3)) (K_at_p2-6)) (K_not_at_p1-3)))
    (:action invariant-2719
        :effect (when (and (not (K_at_p2-6)) (K_at_p1-2)) (K_not_at_p2-6)))
    (:action invariant-2720
        :effect (when (and (not (K_at_p1-2)) (K_at_p2-6)) (K_not_at_p1-2)))
    (:action invariant-2721
        :effect (when (and (not (K_at_p2-6)) (K_at_p1-1)) (K_not_at_p2-6)))
    (:action invariant-2722
        :effect (when (and (not (K_at_p1-1)) (K_at_p2-6)) (K_not_at_p1-1)))
    (:action invariant-2723
        :effect (when (and (not (K_at_p2-5)) (K_at_p2-4)) (K_not_at_p2-5)))
    (:action invariant-2724
        :effect (when (and (not (K_at_p2-4)) (K_at_p2-5)) (K_not_at_p2-4)))
    (:action invariant-2725
        :effect (when (and (not (K_at_p2-5)) (K_at_p2-3)) (K_not_at_p2-5)))
    (:action invariant-2726
        :effect (when (and (not (K_at_p2-3)) (K_at_p2-5)) (K_not_at_p2-3)))
    (:action invariant-2727
        :effect (when (and (not (K_at_p2-5)) (K_at_p2-2)) (K_not_at_p2-5)))
    (:action invariant-2728
        :effect (when (and (not (K_at_p2-2)) (K_at_p2-5)) (K_not_at_p2-2)))
    (:action invariant-2729
        :effect (when (and (not (K_at_p2-5)) (K_at_p2-1)) (K_not_at_p2-5)))
    (:action invariant-2730
        :effect (when (and (not (K_at_p2-1)) (K_at_p2-5)) (K_not_at_p2-1)))
    (:action invariant-2731
        :effect (when (and (not (K_at_p2-5)) (K_at_p1-7)) (K_not_at_p2-5)))
    (:action invariant-2732
        :effect (when (and (not (K_at_p1-7)) (K_at_p2-5)) (K_not_at_p1-7)))
    (:action invariant-2733
        :effect (when (and (not (K_at_p2-5)) (K_at_p1-6)) (K_not_at_p2-5)))
    (:action invariant-2734
        :effect (when (and (not (K_at_p1-6)) (K_at_p2-5)) (K_not_at_p1-6)))
    (:action invariant-2735
        :effect (when (and (not (K_at_p2-5)) (K_at_p1-5)) (K_not_at_p2-5)))
    (:action invariant-2736
        :effect (when (and (not (K_at_p1-5)) (K_at_p2-5)) (K_not_at_p1-5)))
    (:action invariant-2737
        :effect (when (and (not (K_at_p2-5)) (K_at_p1-4)) (K_not_at_p2-5)))
    (:action invariant-2738
        :effect (when (and (not (K_at_p1-4)) (K_at_p2-5)) (K_not_at_p1-4)))
    (:action invariant-2739
        :effect (when (and (not (K_at_p2-5)) (K_at_p1-3)) (K_not_at_p2-5)))
    (:action invariant-2740
        :effect (when (and (not (K_at_p1-3)) (K_at_p2-5)) (K_not_at_p1-3)))
    (:action invariant-2741
        :effect (when (and (not (K_at_p2-5)) (K_at_p1-2)) (K_not_at_p2-5)))
    (:action invariant-2742
        :effect (when (and (not (K_at_p1-2)) (K_at_p2-5)) (K_not_at_p1-2)))
    (:action invariant-2743
        :effect (when (and (not (K_at_p2-5)) (K_at_p1-1)) (K_not_at_p2-5)))
    (:action invariant-2744
        :effect (when (and (not (K_at_p1-1)) (K_at_p2-5)) (K_not_at_p1-1)))
    (:action invariant-2745
        :effect (when (and (not (K_at_p2-4)) (K_at_p2-3)) (K_not_at_p2-4)))
    (:action invariant-2746
        :effect (when (and (not (K_at_p2-3)) (K_at_p2-4)) (K_not_at_p2-3)))
)
