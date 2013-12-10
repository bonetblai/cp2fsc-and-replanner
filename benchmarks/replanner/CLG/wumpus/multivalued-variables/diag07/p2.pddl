(define (problem wumpus7)
    (:domain diagonal-wumpus-7x7)
    (:init
(K_not_at_p1-1)
(K_gold-at_p7-7)
(K_not_stench_p7-6) (K_not_stench_p7-4) (K_not_stench_p7-3) (K_not_stench_p7-2) (K_not_stench_p7-1)
(K_not_stench_p6-7) (K_not_stench_p6-5) (K_not_stench_p6-3) (K_not_stench_p6-2) (K_not_stench_p6-1)
(K_stench_p5-7)
(K_not_stench_p5-6) (K_not_stench_p5-4) (K_not_stench_p5-2) (K_not_stench_p5-1)
(K_not_stench_p4-7)
(K_not_stench_p4-5) (K_not_stench_p4-3) (K_not_stench_p4-1)
(K_not_stench_p3-7) (K_not_stench_p3-6) (K_not_stench_p3-4) (K_not_stench_p3-2)
(K_not_stench_p2-7) (K_not_stench_p2-6) (K_not_stench_p2-5) (K_not_stench_p2-3) (K_not_stench_p2-1)
(K_not_stench_p1-7) (K_not_stench_p1-6) (K_not_stench_p1-5) (K_not_stench_p1-4) (K_not_stench_p1-2) (K_not_stench_p1-1)
(K_not_normal-execution)
(K_not_at_p7-7) (K_not_at_p7-6) (K_not_at_p7-5) (K_not_at_p7-4) (K_not_at_p7-3) (K_not_at_p7-2) (K_not_at_p7-1)
(K_not_at_p6-7) (K_not_at_p6-6) (K_not_at_p6-5) (K_not_at_p6-4) (K_not_at_p6-3) (K_not_at_p6-2) (K_not_at_p6-1)
(K_at_p5-7) (K_not_at_p5-6) (K_not_at_p5-5) (K_not_at_p5-4) (K_not_at_p5-3) (K_not_at_p5-2) (K_not_at_p5-1)
(K_not_at_p4-7) (K_not_at_p4-6) (K_not_at_p4-5) (K_not_at_p4-4) (K_not_at_p4-3) (K_not_at_p4-2) (K_not_at_p4-1)
(K_not_at_p3-7) (K_not_at_p3-6) (K_not_at_p3-5) (K_not_at_p3-4) (K_not_at_p3-3) (K_not_at_p3-2) (K_not_at_p3-1)
(K_not_at_p2-7) (K_not_at_p2-6) (K_not_at_p2-5) (K_not_at_p2-4) (K_not_at_p2-3) (K_not_at_p2-2) (K_not_at_p2-1)
(K_not_at_p1-7) (K_not_at_p1-6) (K_not_at_p1-5) (K_not_at_p1-4) (K_not_at_p1-3) (K_not_at_p1-2)
(K_not_got-the-treasure)
(K_not_need-post-for-smell-wumpus_p7-7) (K_not_need-post-for-smell-wumpus_p7-6) (K_not_need-post-for-smell-wumpus_p7-5) (K_not_need-post-for-smell-wumpus_p7-4) (K_not_need-post-for-smell-wumpus_p7-3) (K_not_need-post-for-smell-wumpus_p7-2) (K_not_need-post-for-smell-wumpus_p7-1)
(K_not_need-post-for-smell-wumpus_p6-7) (K_not_need-post-for-smell-wumpus_p6-6) (K_not_need-post-for-smell-wumpus_p6-5) (K_not_need-post-for-smell-wumpus_p6-4) (K_not_need-post-for-smell-wumpus_p6-3) (K_not_need-post-for-smell-wumpus_p6-2) (K_not_need-post-for-smell-wumpus_p6-1)
(K_need-post-for-smell-wumpus_p5-7) (K_not_need-post-for-smell-wumpus_p5-6) (K_not_need-post-for-smell-wumpus_p5-5) (K_not_need-post-for-smell-wumpus_p5-4) (K_not_need-post-for-smell-wumpus_p5-3) (K_not_need-post-for-smell-wumpus_p5-2) (K_not_need-post-for-smell-wumpus_p5-1)
(K_not_need-post-for-smell-wumpus_p4-7) (K_not_need-post-for-smell-wumpus_p4-6) (K_not_need-post-for-smell-wumpus_p4-5) (K_not_need-post-for-smell-wumpus_p4-4) (K_not_need-post-for-smell-wumpus_p4-3) (K_not_need-post-for-smell-wumpus_p4-2) (K_not_need-post-for-smell-wumpus_p4-1)
(K_not_need-post-for-smell-wumpus_p3-7) (K_not_need-post-for-smell-wumpus_p3-6) (K_not_need-post-for-smell-wumpus_p3-5) (K_not_need-post-for-smell-wumpus_p3-4) (K_not_need-post-for-smell-wumpus_p3-3) (K_not_need-post-for-smell-wumpus_p3-2) (K_not_need-post-for-smell-wumpus_p3-1)
(K_not_need-post-for-smell-wumpus_p2-7) (K_not_need-post-for-smell-wumpus_p2-6) (K_not_need-post-for-smell-wumpus_p2-5) (K_not_need-post-for-smell-wumpus_p2-4) (K_not_need-post-for-smell-wumpus_p2-3) (K_not_need-post-for-smell-wumpus_p2-2) (K_not_need-post-for-smell-wumpus_p2-1)
(K_not_need-post-for-smell-wumpus_p1-7) (K_not_need-post-for-smell-wumpus_p1-6) (K_not_need-post-for-smell-wumpus_p1-5) (K_not_need-post-for-smell-wumpus_p1-4) (K_not_need-post-for-smell-wumpus_p1-3) (K_not_need-post-for-smell-wumpus_p1-2) (K_not_need-post-for-smell-wumpus_p1-1)

(K_safe_p1-1) (K_safe_p1-2) (K_safe_p1-3) (K_safe_p1-4) (K_safe_p1-5) (K_safe_p1-6) (K_safe_p1-7)
(K_safe_p2-1) (K_safe_p2-2) (K_safe_p2-4) (K_safe_p2-5) (K_safe_p2-6) (K_safe_p2-7)
(K_safe_p3-1) (K_safe_p3-3) (K_safe_p3-5) (K_safe_p3-6) (K_safe_p3-7)
(K_safe_p4-1) (K_safe_p4-2) (K_safe_p4-4) (K_safe_p4-6) (K_safe_p4-7)
(K_safe_p5-1) (K_safe_p5-2) (K_safe_p5-3) (K_safe_p5-5) (K_safe_p5-7)
(K_safe_p6-1) (K_safe_p6-2) (K_safe_p6-3) (K_safe_p6-4) (K_safe_p6-6)
(K_safe_p7-1) (K_safe_p7-2) (K_safe_p7-3) (K_safe_p7-4) (K_safe_p7-5) (K_safe_p7-7)
)
    (:goal (and (K_normal-execution) (K_got-the-treasure)))
)
