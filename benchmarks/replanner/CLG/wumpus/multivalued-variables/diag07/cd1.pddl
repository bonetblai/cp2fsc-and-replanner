(define (domain wumpus-contingent)
    (:predicates
        (K_normal-execution) (K_not_normal-execution) (K_at_p1-1) (K_not_at_p1-1) (K_gold-at_p7-7) (K_not_gold-at_p7-7) (K_safe_p2-3) (K_not_safe_p2-3) (K_safe_p3-2) (K_not_safe_p3-2) (K_safe_p3-4) (K_not_safe_p3-4) (K_safe_p4-3) (K_not_safe_p4-3) (K_safe_p5-4) (K_not_safe_p5-4) (K_safe_p4-5) (K_not_safe_p4-5) (K_safe_p6-5) (K_not_safe_p6-5) (K_safe_p5-6) (K_not_safe_p5-6) (K_safe_p6-7) (K_not_safe_p6-7) (K_safe_p7-6) (K_not_safe_p7-6) (K_wumpus-at_p2-3) (K_not_wumpus-at_p2-3) (K_pit-at_p2-3) (K_not_pit-at_p2-3) (K_wumpus-at_p3-2) (K_not_wumpus-at_p3-2) (K_pit-at_p3-2) (K_not_pit-at_p3-2) (K_wumpus-at_p3-4) (K_not_wumpus-at_p3-4) (K_pit-at_p3-4) (K_not_pit-at_p3-4) (K_wumpus-at_p4-3) (K_not_wumpus-at_p4-3) (K_pit-at_p4-3) (K_not_pit-at_p4-3) (K_wumpus-at_p5-4) (K_not_wumpus-at_p5-4) (K_pit-at_p5-4) (K_not_pit-at_p5-4) (K_wumpus-at_p4-5) (K_not_wumpus-at_p4-5) (K_pit-at_p4-5) (K_not_pit-at_p4-5) (K_wumpus-at_p6-5) (K_not_wumpus-at_p6-5) (K_pit-at_p6-5) (K_not_pit-at_p6-5) (K_wumpus-at_p5-6) (K_not_wumpus-at_p5-6) (K_pit-at_p5-6) (K_not_pit-at_p5-6) (K_wumpus-at_p6-7) (K_not_wumpus-at_p6-7) (K_pit-at_p6-7) (K_not_pit-at_p6-7) (K_wumpus-at_p7-6) (K_not_wumpus-at_p7-6) (K_pit-at_p7-6) (K_not_pit-at_p7-6) (K_stench_p1-3) (K_not_stench_p1-3) (K_stench_p3-1) (K_not_stench_p3-1) (K_stench_p2-2) (K_not_stench_p2-2) (K_stench_p3-3) (K_not_stench_p3-3) (K_stench_p2-4) (K_not_stench_p2-4) (K_stench_p4-2) (K_not_stench_p4-2) (K_stench_p4-4) (K_not_stench_p4-4) (K_stench_p3-5) (K_not_stench_p3-5) (K_stench_p5-3) (K_not_stench_p5-3) (K_stench_p5-5) (K_not_stench_p5-5) (K_stench_p4-6) (K_not_stench_p4-6) (K_stench_p6-4) (K_not_stench_p6-4) (K_stench_p6-6) (K_not_stench_p6-6) (K_stench_p5-7) (K_not_stench_p5-7) (K_stench_p7-5) (K_not_stench_p7-5) (K_stench_p7-7) (K_not_stench_p7-7) (K_breeze_p1-3) (K_not_breeze_p1-3) (K_breeze_p3-1) (K_not_breeze_p3-1) (K_breeze_p2-2) (K_not_breeze_p2-2) (K_breeze_p3-3) (K_not_breeze_p3-3) (K_breeze_p2-4) (K_not_breeze_p2-4) (K_breeze_p4-2) (K_not_breeze_p4-2) (K_breeze_p4-4) (K_not_breeze_p4-4) (K_breeze_p3-5) (K_not_breeze_p3-5) (K_breeze_p5-3) (K_not_breeze_p5-3) (K_breeze_p5-5) (K_not_breeze_p5-5) (K_breeze_p4-6) (K_not_breeze_p4-6) (K_breeze_p6-4) (K_not_breeze_p6-4) (K_breeze_p6-6) (K_not_breeze_p6-6) (K_breeze_p5-7) (K_not_breeze_p5-7) (K_breeze_p7-5) (K_not_breeze_p7-5) (K_breeze_p7-7) (K_not_breeze_p7-7) (K_got-the-treasure) (K_not_got-the-treasure) (K_at_p7-7) (K_not_at_p7-7) (K_need-post-for-smell-wumpus_p7-7) (K_not_need-post-for-smell-wumpus_p7-7) (K_at_p7-6) (K_not_at_p7-6) (K_need-post-for-smell-wumpus_p7-6) (K_not_need-post-for-smell-wumpus_p7-6) (K_at_p7-5) (K_not_at_p7-5) (K_need-post-for-smell-wumpus_p7-5) (K_not_need-post-for-smell-wumpus_p7-5) (K_at_p7-4) (K_not_at_p7-4) (K_need-post-for-smell-wumpus_p7-4) (K_not_need-post-for-smell-wumpus_p7-4) (K_at_p7-3) (K_not_at_p7-3) (K_need-post-for-smell-wumpus_p7-3) (K_not_need-post-for-smell-wumpus_p7-3) (K_at_p7-2) (K_not_at_p7-2) (K_need-post-for-smell-wumpus_p7-2) (K_not_need-post-for-smell-wumpus_p7-2) (K_at_p7-1) (K_not_at_p7-1) (K_need-post-for-smell-wumpus_p7-1) (K_not_need-post-for-smell-wumpus_p7-1) (K_at_p6-7) (K_not_at_p6-7) (K_need-post-for-smell-wumpus_p6-7) (K_not_need-post-for-smell-wumpus_p6-7) (K_at_p6-6) (K_not_at_p6-6) (K_need-post-for-smell-wumpus_p6-6) (K_not_need-post-for-smell-wumpus_p6-6) (K_at_p6-5) (K_not_at_p6-5) (K_need-post-for-smell-wumpus_p6-5) (K_not_need-post-for-smell-wumpus_p6-5) (K_at_p6-4) (K_not_at_p6-4) (K_need-post-for-smell-wumpus_p6-4) (K_not_need-post-for-smell-wumpus_p6-4) (K_at_p6-3) (K_not_at_p6-3) (K_need-post-for-smell-wumpus_p6-3) (K_not_need-post-for-smell-wumpus_p6-3) (K_at_p6-2) (K_not_at_p6-2) (K_need-post-for-smell-wumpus_p6-2) (K_not_need-post-for-smell-wumpus_p6-2) (K_at_p6-1) (K_not_at_p6-1) (K_need-post-for-smell-wumpus_p6-1) (K_not_need-post-for-smell-wumpus_p6-1) (K_at_p5-7) (K_not_at_p5-7) (K_need-post-for-smell-wumpus_p5-7) (K_not_need-post-for-smell-wumpus_p5-7) (K_at_p5-6) (K_not_at_p5-6) (K_need-post-for-smell-wumpus_p5-6) (K_not_need-post-for-smell-wumpus_p5-6) (K_at_p5-5) (K_not_at_p5-5) (K_need-post-for-smell-wumpus_p5-5) (K_not_need-post-for-smell-wumpus_p5-5) (K_at_p5-4) (K_not_at_p5-4) (K_need-post-for-smell-wumpus_p5-4) (K_not_need-post-for-smell-wumpus_p5-4) (K_at_p5-3) (K_not_at_p5-3) (K_need-post-for-smell-wumpus_p5-3) (K_not_need-post-for-smell-wumpus_p5-3) (K_at_p5-2) (K_not_at_p5-2) (K_need-post-for-smell-wumpus_p5-2) (K_not_need-post-for-smell-wumpus_p5-2) (K_at_p5-1) (K_not_at_p5-1) (K_need-post-for-smell-wumpus_p5-1) (K_not_need-post-for-smell-wumpus_p5-1) (K_at_p4-7) (K_not_at_p4-7) (K_need-post-for-smell-wumpus_p4-7) (K_not_need-post-for-smell-wumpus_p4-7) (K_at_p4-6) (K_not_at_p4-6) (K_need-post-for-smell-wumpus_p4-6) (K_not_need-post-for-smell-wumpus_p4-6) (K_at_p4-5) (K_not_at_p4-5) (K_need-post-for-smell-wumpus_p4-5) (K_not_need-post-for-smell-wumpus_p4-5) (K_at_p4-4) (K_not_at_p4-4) (K_need-post-for-smell-wumpus_p4-4) (K_not_need-post-for-smell-wumpus_p4-4) (K_at_p4-3) (K_not_at_p4-3) (K_need-post-for-smell-wumpus_p4-3) (K_not_need-post-for-smell-wumpus_p4-3) (K_at_p4-2) (K_not_at_p4-2) (K_need-post-for-smell-wumpus_p4-2) (K_not_need-post-for-smell-wumpus_p4-2) (K_at_p4-1) (K_not_at_p4-1) (K_need-post-for-smell-wumpus_p4-1) (K_not_need-post-for-smell-wumpus_p4-1) (K_at_p3-7) (K_not_at_p3-7) (K_need-post-for-smell-wumpus_p3-7) (K_not_need-post-for-smell-wumpus_p3-7) (K_at_p3-6) (K_not_at_p3-6) (K_need-post-for-smell-wumpus_p3-6) (K_not_need-post-for-smell-wumpus_p3-6) (K_at_p3-5) (K_not_at_p3-5) (K_need-post-for-smell-wumpus_p3-5) (K_not_need-post-for-smell-wumpus_p3-5) (K_at_p3-4) (K_not_at_p3-4) (K_need-post-for-smell-wumpus_p3-4) (K_not_need-post-for-smell-wumpus_p3-4) (K_at_p3-3) (K_not_at_p3-3) (K_need-post-for-smell-wumpus_p3-3) (K_not_need-post-for-smell-wumpus_p3-3) (K_at_p3-2) (K_not_at_p3-2) (K_need-post-for-smell-wumpus_p3-2) (K_not_need-post-for-smell-wumpus_p3-2) (K_at_p3-1) (K_not_at_p3-1) (K_need-post-for-smell-wumpus_p3-1) (K_not_need-post-for-smell-wumpus_p3-1) (K_at_p2-7) (K_not_at_p2-7) (K_need-post-for-smell-wumpus_p2-7) (K_not_need-post-for-smell-wumpus_p2-7) (K_at_p2-6) (K_not_at_p2-6) (K_need-post-for-smell-wumpus_p2-6) (K_not_need-post-for-smell-wumpus_p2-6) (K_at_p2-5) (K_not_at_p2-5) (K_need-post-for-smell-wumpus_p2-5) (K_not_need-post-for-smell-wumpus_p2-5) (K_at_p2-4) (K_not_at_p2-4) (K_need-post-for-smell-wumpus_p2-4) (K_not_need-post-for-smell-wumpus_p2-4) (K_at_p2-3) (K_not_at_p2-3) (K_need-post-for-smell-wumpus_p2-3) (K_not_need-post-for-smell-wumpus_p2-3) (K_at_p2-2) (K_not_at_p2-2) (K_need-post-for-smell-wumpus_p2-2) (K_not_need-post-for-smell-wumpus_p2-2) (K_at_p2-1) (K_not_at_p2-1) (K_need-post-for-smell-wumpus_p2-1) (K_not_need-post-for-smell-wumpus_p2-1) (K_at_p1-7) (K_not_at_p1-7) (K_need-post-for-smell-wumpus_p1-7) (K_not_need-post-for-smell-wumpus_p1-7) (K_at_p1-6) (K_not_at_p1-6) (K_need-post-for-smell-wumpus_p1-6) (K_not_need-post-for-smell-wumpus_p1-6) (K_at_p1-5) (K_not_at_p1-5) (K_need-post-for-smell-wumpus_p1-5) (K_not_need-post-for-smell-wumpus_p1-5) (K_at_p1-4) (K_not_at_p1-4) (K_need-post-for-smell-wumpus_p1-4) (K_not_need-post-for-smell-wumpus_p1-4) (K_at_p1-3) (K_not_at_p1-3) (K_need-post-for-smell-wumpus_p1-3) (K_not_need-post-for-smell-wumpus_p1-3) (K_at_p1-2) (K_not_at_p1-2) (K_need-post-for-smell-wumpus_p1-2) (K_not_need-post-for-smell-wumpus_p1-2) (K_need-post-for-smell-wumpus_p1-1) (K_not_need-post-for-smell-wumpus_p1-1) (K_need-post-for-feel-breeze_p7-7) (K_not_need-post-for-feel-breeze_p7-7) (K_need-post-for-feel-breeze_p7-6) (K_not_need-post-for-feel-breeze_p7-6) (K_need-post-for-feel-breeze_p7-5) (K_not_need-post-for-feel-breeze_p7-5) (K_need-post-for-feel-breeze_p7-4) (K_not_need-post-for-feel-breeze_p7-4) (K_need-post-for-feel-breeze_p7-3) (K_not_need-post-for-feel-breeze_p7-3) (K_need-post-for-feel-breeze_p7-2) (K_not_need-post-for-feel-breeze_p7-2) (K_need-post-for-feel-breeze_p7-1) (K_not_need-post-for-feel-breeze_p7-1) (K_need-post-for-feel-breeze_p6-7) (K_not_need-post-for-feel-breeze_p6-7) (K_need-post-for-feel-breeze_p6-6) (K_not_need-post-for-feel-breeze_p6-6) (K_need-post-for-feel-breeze_p6-5) (K_not_need-post-for-feel-breeze_p6-5) (K_need-post-for-feel-breeze_p6-4) (K_not_need-post-for-feel-breeze_p6-4) (K_need-post-for-feel-breeze_p6-3) (K_not_need-post-for-feel-breeze_p6-3) (K_need-post-for-feel-breeze_p6-2) (K_not_need-post-for-feel-breeze_p6-2) (K_need-post-for-feel-breeze_p6-1) (K_not_need-post-for-feel-breeze_p6-1) (K_need-post-for-feel-breeze_p5-7) (K_not_need-post-for-feel-breeze_p5-7) (K_need-post-for-feel-breeze_p5-6) (K_not_need-post-for-feel-breeze_p5-6) (K_need-post-for-feel-breeze_p5-5) (K_not_need-post-for-feel-breeze_p5-5) (K_need-post-for-feel-breeze_p5-4) (K_not_need-post-for-feel-breeze_p5-4) (K_need-post-for-feel-breeze_p5-3) (K_not_need-post-for-feel-breeze_p5-3) (K_need-post-for-feel-breeze_p5-2) (K_not_need-post-for-feel-breeze_p5-2) (K_need-post-for-feel-breeze_p5-1) (K_not_need-post-for-feel-breeze_p5-1) (K_need-post-for-feel-breeze_p4-7) (K_not_need-post-for-feel-breeze_p4-7) (K_need-post-for-feel-breeze_p4-6) (K_not_need-post-for-feel-breeze_p4-6) (K_need-post-for-feel-breeze_p4-5) (K_not_need-post-for-feel-breeze_p4-5) (K_need-post-for-feel-breeze_p4-4) (K_not_need-post-for-feel-breeze_p4-4) (K_need-post-for-feel-breeze_p4-3) (K_not_need-post-for-feel-breeze_p4-3) (K_need-post-for-feel-breeze_p4-2) (K_not_need-post-for-feel-breeze_p4-2) (K_need-post-for-feel-breeze_p4-1) (K_not_need-post-for-feel-breeze_p4-1) (K_need-post-for-feel-breeze_p3-7) (K_not_need-post-for-feel-breeze_p3-7) (K_need-post-for-feel-breeze_p3-6) (K_not_need-post-for-feel-breeze_p3-6) (K_need-post-for-feel-breeze_p3-5) (K_not_need-post-for-feel-breeze_p3-5) (K_need-post-for-feel-breeze_p3-4) (K_not_need-post-for-feel-breeze_p3-4) (K_need-post-for-feel-breeze_p3-3) (K_not_need-post-for-feel-breeze_p3-3) (K_need-post-for-feel-breeze_p3-2) (K_not_need-post-for-feel-breeze_p3-2) (K_need-post-for-feel-breeze_p3-1) (K_not_need-post-for-feel-breeze_p3-1) (K_need-post-for-feel-breeze_p2-7) (K_not_need-post-for-feel-breeze_p2-7) (K_need-post-for-feel-breeze_p2-6) (K_not_need-post-for-feel-breeze_p2-6) (K_need-post-for-feel-breeze_p2-5) (K_not_need-post-for-feel-breeze_p2-5) (K_need-post-for-feel-breeze_p2-4) (K_not_need-post-for-feel-breeze_p2-4) (K_need-post-for-feel-breeze_p2-3) (K_not_need-post-for-feel-breeze_p2-3) (K_need-post-for-feel-breeze_p2-2) (K_not_need-post-for-feel-breeze_p2-2) (K_need-post-for-feel-breeze_p2-1) (K_not_need-post-for-feel-breeze_p2-1) (K_need-post-for-feel-breeze_p1-7) (K_not_need-post-for-feel-breeze_p1-7) (K_need-post-for-feel-breeze_p1-6) (K_not_need-post-for-feel-breeze_p1-6) (K_need-post-for-feel-breeze_p1-5) (K_not_need-post-for-feel-breeze_p1-5) (K_need-post-for-feel-breeze_p1-4) (K_not_need-post-for-feel-breeze_p1-4) (K_need-post-for-feel-breeze_p1-3) (K_not_need-post-for-feel-breeze_p1-3) (K_need-post-for-feel-breeze_p1-2) (K_not_need-post-for-feel-breeze_p1-2) (K_need-post-for-feel-breeze_p1-1) (K_not_need-post-for-feel-breeze_p1-1) (K_stench_p7-6) (K_not_stench_p7-6) (K_stench_p7-4) (K_not_stench_p7-4) (K_stench_p7-3) (K_not_stench_p7-3) (K_stench_p7-2) (K_not_stench_p7-2) (K_stench_p7-1) (K_not_stench_p7-1) (K_stench_p6-7) (K_not_stench_p6-7) (K_stench_p6-5) (K_not_stench_p6-5) (K_stench_p6-3) (K_not_stench_p6-3) (K_stench_p6-2) (K_not_stench_p6-2) (K_stench_p6-1) (K_not_stench_p6-1) (K_stench_p5-6) (K_not_stench_p5-6) (K_stench_p5-4) (K_not_stench_p5-4) (K_stench_p5-2) (K_not_stench_p5-2) (K_stench_p5-1) (K_not_stench_p5-1) (K_stench_p4-7) (K_not_stench_p4-7) (K_stench_p4-5) (K_not_stench_p4-5) (K_stench_p4-3) (K_not_stench_p4-3) (K_stench_p4-1) (K_not_stench_p4-1) (K_stench_p3-7) (K_not_stench_p3-7) (K_stench_p3-6) (K_not_stench_p3-6) (K_stench_p3-4) (K_not_stench_p3-4) (K_stench_p3-2) (K_not_stench_p3-2) (K_stench_p2-7) (K_not_stench_p2-7) (K_stench_p2-6) (K_not_stench_p2-6) (K_stench_p2-5) (K_not_stench_p2-5) (K_stench_p2-3) (K_not_stench_p2-3) (K_stench_p2-1) (K_not_stench_p2-1) (K_stench_p1-7) (K_not_stench_p1-7) (K_stench_p1-6) (K_not_stench_p1-6) (K_stench_p1-5) (K_not_stench_p1-5) (K_stench_p1-4) (K_not_stench_p1-4) (K_stench_p1-2) (K_not_stench_p1-2) (K_stench_p1-1) (K_not_stench_p1-1) (K_breeze_p7-6) (K_not_breeze_p7-6) (K_breeze_p7-4) (K_not_breeze_p7-4) (K_breeze_p7-3) (K_not_breeze_p7-3) (K_breeze_p7-2) (K_not_breeze_p7-2) (K_breeze_p7-1) (K_not_breeze_p7-1) (K_breeze_p6-7) (K_not_breeze_p6-7) (K_breeze_p6-5) (K_not_breeze_p6-5) (K_breeze_p6-3) (K_not_breeze_p6-3) (K_breeze_p6-2) (K_not_breeze_p6-2) (K_breeze_p6-1) (K_not_breeze_p6-1) (K_breeze_p5-6) (K_not_breeze_p5-6) (K_breeze_p5-4) (K_not_breeze_p5-4) (K_breeze_p5-2) (K_not_breeze_p5-2) (K_breeze_p5-1) (K_not_breeze_p5-1) (K_breeze_p4-7) (K_not_breeze_p4-7) (K_breeze_p4-5) (K_not_breeze_p4-5) (K_breeze_p4-3) (K_not_breeze_p4-3) (K_breeze_p4-1) (K_not_breeze_p4-1) (K_breeze_p3-7) (K_not_breeze_p3-7) (K_breeze_p3-6) (K_not_breeze_p3-6) (K_breeze_p3-4) (K_not_breeze_p3-4) (K_breeze_p3-2) (K_not_breeze_p3-2) (K_breeze_p2-7) (K_not_breeze_p2-7) (K_breeze_p2-6) (K_not_breeze_p2-6) (K_breeze_p2-5) (K_not_breeze_p2-5) (K_breeze_p2-3) (K_not_breeze_p2-3) (K_breeze_p2-1) (K_not_breeze_p2-1) (K_breeze_p1-7) (K_not_breeze_p1-7) (K_breeze_p1-6) (K_not_breeze_p1-6) (K_breeze_p1-5) (K_not_breeze_p1-5) (K_breeze_p1-4) (K_not_breeze_p1-4) (K_breeze_p1-2) (K_not_breeze_p1-2) (K_breeze_p1-1) (K_not_breeze_p1-1)
    )


    (:action move_p7-7_p7-6
        :precondition (and (K_normal-execution) (K_safe_p7-6) (K_at_p7-7))
        :effect (and (not (K_not_at_p7-6)) (not (K_at_p7-7)) (K_not_at_p7-7) (K_at_p7-6)))
    (:action move_p7-7_p6-7
        :precondition (and (K_normal-execution) (K_safe_p6-7) (K_at_p7-7))
        :effect (and (not (K_not_at_p6-7)) (not (K_at_p7-7)) (K_not_at_p7-7) (K_at_p6-7)))
    (:action move_p7-6_p7-7
        :precondition (and (K_normal-execution) (K_at_p7-6))
        :effect (and (not (K_at_p7-6)) (not (K_not_at_p7-7)) (K_at_p7-7) (K_not_at_p7-6)))
    (:action move_p7-6_p7-5
        :precondition (and (K_normal-execution) (K_at_p7-6))
        :effect (and (not (K_not_at_p7-5)) (not (K_at_p7-6)) (K_not_at_p7-6) (K_at_p7-5)))
    (:action move_p7-6_p6-6
        :precondition (and (K_normal-execution) (K_at_p7-6))
        :effect (and (not (K_not_at_p6-6)) (not (K_at_p7-6)) (K_not_at_p7-6) (K_at_p6-6)))
    (:action move_p7-5_p7-6
        :precondition (and (K_normal-execution) (K_safe_p7-6) (K_at_p7-5))
        :effect (and (not (K_at_p7-5)) (not (K_not_at_p7-6)) (K_at_p7-6) (K_not_at_p7-5)))
    (:action move_p7-5_p7-4
        :precondition (and (K_normal-execution) (K_at_p7-5))
        :effect (and (not (K_not_at_p7-4)) (not (K_at_p7-5)) (K_not_at_p7-5) (K_at_p7-4)))
    (:action move_p7-5_p6-5
        :precondition (and (K_normal-execution) (K_safe_p6-5) (K_at_p7-5))
        :effect (and (not (K_not_at_p6-5)) (not (K_at_p7-5)) (K_not_at_p7-5) (K_at_p6-5)))
    (:action move_p7-4_p7-5
        :precondition (and (K_normal-execution) (K_at_p7-4))
        :effect (and (not (K_at_p7-4)) (not (K_not_at_p7-5)) (K_at_p7-5) (K_not_at_p7-4)))
    (:action move_p7-4_p7-3
        :precondition (and (K_normal-execution) (K_at_p7-4))
        :effect (and (not (K_not_at_p7-3)) (not (K_at_p7-4)) (K_not_at_p7-4) (K_at_p7-3)))
    (:action move_p7-4_p6-4
        :precondition (and (K_normal-execution) (K_at_p7-4))
        :effect (and (not (K_not_at_p6-4)) (not (K_at_p7-4)) (K_not_at_p7-4) (K_at_p6-4)))
    (:action move_p7-3_p7-4
        :precondition (and (K_normal-execution) (K_at_p7-3))
        :effect (and (not (K_at_p7-3)) (not (K_not_at_p7-4)) (K_at_p7-4) (K_not_at_p7-3)))
    (:action move_p7-3_p7-2
        :precondition (and (K_normal-execution) (K_at_p7-3))
        :effect (and (not (K_not_at_p7-2)) (not (K_at_p7-3)) (K_not_at_p7-3) (K_at_p7-2)))
    (:action move_p7-3_p6-3
        :precondition (and (K_normal-execution) (K_at_p7-3))
        :effect (and (not (K_not_at_p6-3)) (not (K_at_p7-3)) (K_not_at_p7-3) (K_at_p6-3)))
    (:action move_p7-2_p7-3
        :precondition (and (K_normal-execution) (K_at_p7-2))
        :effect (and (not (K_at_p7-2)) (not (K_not_at_p7-3)) (K_at_p7-3) (K_not_at_p7-2)))
    (:action move_p7-2_p7-1
        :precondition (and (K_normal-execution) (K_at_p7-2))
        :effect (and (not (K_not_at_p7-1)) (not (K_at_p7-2)) (K_not_at_p7-2) (K_at_p7-1)))
    (:action move_p7-2_p6-2
        :precondition (and (K_normal-execution) (K_at_p7-2))
        :effect (and (not (K_not_at_p6-2)) (not (K_at_p7-2)) (K_not_at_p7-2) (K_at_p6-2)))
    (:action move_p7-1_p7-2
        :precondition (and (K_normal-execution) (K_at_p7-1))
        :effect (and (not (K_at_p7-1)) (not (K_not_at_p7-2)) (K_at_p7-2) (K_not_at_p7-1)))
    (:action move_p7-1_p6-1
        :precondition (and (K_normal-execution) (K_at_p7-1))
        :effect (and (not (K_not_at_p6-1)) (not (K_at_p7-1)) (K_not_at_p7-1) (K_at_p6-1)))
    (:action move_p6-7_p7-7
        :precondition (and (K_normal-execution) (K_at_p6-7))
        :effect (and (not (K_at_p6-7)) (not (K_not_at_p7-7)) (K_at_p7-7) (K_not_at_p6-7)))
    (:action move_p6-7_p6-6
        :precondition (and (K_normal-execution) (K_at_p6-7))
        :effect (and (not (K_not_at_p6-6)) (not (K_at_p6-7)) (K_not_at_p6-7) (K_at_p6-6)))
    (:action move_p6-7_p5-7
        :precondition (and (K_normal-execution) (K_at_p6-7))
        :effect (and (not (K_not_at_p5-7)) (not (K_at_p6-7)) (K_not_at_p6-7) (K_at_p5-7)))
    (:action move_p6-6_p7-6
        :precondition (and (K_normal-execution) (K_safe_p7-6) (K_at_p6-6))
        :effect (and (not (K_at_p6-6)) (not (K_not_at_p7-6)) (K_at_p7-6) (K_not_at_p6-6)))
    (:action move_p6-6_p6-7
        :precondition (and (K_normal-execution) (K_safe_p6-7) (K_at_p6-6))
        :effect (and (not (K_at_p6-6)) (not (K_not_at_p6-7)) (K_at_p6-7) (K_not_at_p6-6)))
    (:action move_p6-6_p6-5
        :precondition (and (K_normal-execution) (K_safe_p6-5) (K_at_p6-6))
        :effect (and (not (K_not_at_p6-5)) (not (K_at_p6-6)) (K_not_at_p6-6) (K_at_p6-5)))
    (:action move_p6-6_p5-6
        :precondition (and (K_normal-execution) (K_safe_p5-6) (K_at_p6-6))
        :effect (and (not (K_not_at_p5-6)) (not (K_at_p6-6)) (K_not_at_p6-6) (K_at_p5-6)))
    (:action move_p6-5_p7-5
        :precondition (and (K_normal-execution) (K_at_p6-5))
        :effect (and (not (K_at_p6-5)) (not (K_not_at_p7-5)) (K_at_p7-5) (K_not_at_p6-5)))
    (:action move_p6-5_p6-6
        :precondition (and (K_normal-execution) (K_at_p6-5))
        :effect (and (not (K_at_p6-5)) (not (K_not_at_p6-6)) (K_at_p6-6) (K_not_at_p6-5)))
    (:action move_p6-5_p6-4
        :precondition (and (K_normal-execution) (K_at_p6-5))
        :effect (and (not (K_not_at_p6-4)) (not (K_at_p6-5)) (K_not_at_p6-5) (K_at_p6-4)))
    (:action move_p6-5_p5-5
        :precondition (and (K_normal-execution) (K_at_p6-5))
        :effect (and (not (K_not_at_p5-5)) (not (K_at_p6-5)) (K_not_at_p6-5) (K_at_p5-5)))
    (:action move_p6-4_p7-4
        :precondition (and (K_normal-execution) (K_at_p6-4))
        :effect (and (not (K_at_p6-4)) (not (K_not_at_p7-4)) (K_at_p7-4) (K_not_at_p6-4)))
    (:action move_p6-4_p6-5
        :precondition (and (K_normal-execution) (K_safe_p6-5) (K_at_p6-4))
        :effect (and (not (K_at_p6-4)) (not (K_not_at_p6-5)) (K_at_p6-5) (K_not_at_p6-4)))
    (:action move_p6-4_p6-3
        :precondition (and (K_normal-execution) (K_at_p6-4))
        :effect (and (not (K_not_at_p6-3)) (not (K_at_p6-4)) (K_not_at_p6-4) (K_at_p6-3)))
    (:action move_p6-4_p5-4
        :precondition (and (K_normal-execution) (K_safe_p5-4) (K_at_p6-4))
        :effect (and (not (K_not_at_p5-4)) (not (K_at_p6-4)) (K_not_at_p6-4) (K_at_p5-4)))
    (:action move_p6-3_p7-3
        :precondition (and (K_normal-execution) (K_at_p6-3))
        :effect (and (not (K_at_p6-3)) (not (K_not_at_p7-3)) (K_at_p7-3) (K_not_at_p6-3)))
    (:action move_p6-3_p6-4
        :precondition (and (K_normal-execution) (K_at_p6-3))
        :effect (and (not (K_at_p6-3)) (not (K_not_at_p6-4)) (K_at_p6-4) (K_not_at_p6-3)))
    (:action move_p6-3_p6-2
        :precondition (and (K_normal-execution) (K_at_p6-3))
        :effect (and (not (K_not_at_p6-2)) (not (K_at_p6-3)) (K_not_at_p6-3) (K_at_p6-2)))
    (:action move_p6-3_p5-3
        :precondition (and (K_normal-execution) (K_at_p6-3))
        :effect (and (not (K_not_at_p5-3)) (not (K_at_p6-3)) (K_not_at_p6-3) (K_at_p5-3)))
    (:action move_p6-2_p7-2
        :precondition (and (K_normal-execution) (K_at_p6-2))
        :effect (and (not (K_at_p6-2)) (not (K_not_at_p7-2)) (K_at_p7-2) (K_not_at_p6-2)))
    (:action move_p6-2_p6-3
        :precondition (and (K_normal-execution) (K_at_p6-2))
        :effect (and (not (K_at_p6-2)) (not (K_not_at_p6-3)) (K_at_p6-3) (K_not_at_p6-2)))
    (:action move_p6-2_p6-1
        :precondition (and (K_normal-execution) (K_at_p6-2))
        :effect (and (not (K_not_at_p6-1)) (not (K_at_p6-2)) (K_not_at_p6-2) (K_at_p6-1)))
    (:action move_p6-2_p5-2
        :precondition (and (K_normal-execution) (K_at_p6-2))
        :effect (and (not (K_not_at_p5-2)) (not (K_at_p6-2)) (K_not_at_p6-2) (K_at_p5-2)))
    (:action move_p6-1_p7-1
        :precondition (and (K_normal-execution) (K_at_p6-1))
        :effect (and (not (K_at_p6-1)) (not (K_not_at_p7-1)) (K_at_p7-1) (K_not_at_p6-1)))
    (:action move_p6-1_p6-2
        :precondition (and (K_normal-execution) (K_at_p6-1))
        :effect (and (not (K_at_p6-1)) (not (K_not_at_p6-2)) (K_at_p6-2) (K_not_at_p6-1)))
    (:action move_p6-1_p5-1
        :precondition (and (K_normal-execution) (K_at_p6-1))
        :effect (and (not (K_not_at_p5-1)) (not (K_at_p6-1)) (K_not_at_p6-1) (K_at_p5-1)))
    (:action move_p5-7_p6-7
        :precondition (and (K_normal-execution) (K_safe_p6-7) (K_at_p5-7))
        :effect (and (not (K_at_p5-7)) (not (K_not_at_p6-7)) (K_at_p6-7) (K_not_at_p5-7)))
    (:action move_p5-7_p5-6
        :precondition (and (K_normal-execution) (K_safe_p5-6) (K_at_p5-7))
        :effect (and (not (K_not_at_p5-6)) (not (K_at_p5-7)) (K_not_at_p5-7) (K_at_p5-6)))
    (:action move_p5-7_p4-7
        :precondition (and (K_normal-execution) (K_at_p5-7))
        :effect (and (not (K_not_at_p4-7)) (not (K_at_p5-7)) (K_not_at_p5-7) (K_at_p4-7)))
    (:action move_p5-6_p6-6
        :precondition (and (K_normal-execution) (K_at_p5-6))
        :effect (and (not (K_at_p5-6)) (not (K_not_at_p6-6)) (K_at_p6-6) (K_not_at_p5-6)))
    (:action move_p5-6_p5-7
        :precondition (and (K_normal-execution) (K_at_p5-6))
        :effect (and (not (K_at_p5-6)) (not (K_not_at_p5-7)) (K_at_p5-7) (K_not_at_p5-6)))
    (:action move_p5-6_p5-5
        :precondition (and (K_normal-execution) (K_at_p5-6))
        :effect (and (not (K_not_at_p5-5)) (not (K_at_p5-6)) (K_not_at_p5-6) (K_at_p5-5)))
    (:action move_p5-6_p4-6
        :precondition (and (K_normal-execution) (K_at_p5-6))
        :effect (and (not (K_not_at_p4-6)) (not (K_at_p5-6)) (K_not_at_p5-6) (K_at_p4-6)))
    (:action move_p5-5_p6-5
        :precondition (and (K_normal-execution) (K_safe_p6-5) (K_at_p5-5))
        :effect (and (not (K_at_p5-5)) (not (K_not_at_p6-5)) (K_at_p6-5) (K_not_at_p5-5)))
    (:action move_p5-5_p5-6
        :precondition (and (K_normal-execution) (K_safe_p5-6) (K_at_p5-5))
        :effect (and (not (K_at_p5-5)) (not (K_not_at_p5-6)) (K_at_p5-6) (K_not_at_p5-5)))
    (:action move_p5-5_p5-4
        :precondition (and (K_normal-execution) (K_safe_p5-4) (K_at_p5-5))
        :effect (and (not (K_not_at_p5-4)) (not (K_at_p5-5)) (K_not_at_p5-5) (K_at_p5-4)))
    (:action move_p5-5_p4-5
        :precondition (and (K_normal-execution) (K_safe_p4-5) (K_at_p5-5))
        :effect (and (not (K_not_at_p4-5)) (not (K_at_p5-5)) (K_not_at_p5-5) (K_at_p4-5)))
    (:action move_p5-4_p6-4
        :precondition (and (K_normal-execution) (K_at_p5-4))
        :effect (and (not (K_at_p5-4)) (not (K_not_at_p6-4)) (K_at_p6-4) (K_not_at_p5-4)))
    (:action move_p5-4_p5-5
        :precondition (and (K_normal-execution) (K_at_p5-4))
        :effect (and (not (K_at_p5-4)) (not (K_not_at_p5-5)) (K_at_p5-5) (K_not_at_p5-4)))
    (:action move_p5-4_p5-3
        :precondition (and (K_normal-execution) (K_at_p5-4))
        :effect (and (not (K_not_at_p5-3)) (not (K_at_p5-4)) (K_not_at_p5-4) (K_at_p5-3)))
    (:action move_p5-4_p4-4
        :precondition (and (K_normal-execution) (K_at_p5-4))
        :effect (and (not (K_not_at_p4-4)) (not (K_at_p5-4)) (K_not_at_p5-4) (K_at_p4-4)))
    (:action move_p5-3_p6-3
        :precondition (and (K_normal-execution) (K_at_p5-3))
        :effect (and (not (K_at_p5-3)) (not (K_not_at_p6-3)) (K_at_p6-3) (K_not_at_p5-3)))
    (:action move_p5-3_p5-4
        :precondition (and (K_normal-execution) (K_safe_p5-4) (K_at_p5-3))
        :effect (and (not (K_at_p5-3)) (not (K_not_at_p5-4)) (K_at_p5-4) (K_not_at_p5-3)))
    (:action move_p5-3_p5-2
        :precondition (and (K_normal-execution) (K_at_p5-3))
        :effect (and (not (K_not_at_p5-2)) (not (K_at_p5-3)) (K_not_at_p5-3) (K_at_p5-2)))
    (:action move_p5-3_p4-3
        :precondition (and (K_normal-execution) (K_safe_p4-3) (K_at_p5-3))
        :effect (and (not (K_not_at_p4-3)) (not (K_at_p5-3)) (K_not_at_p5-3) (K_at_p4-3)))
    (:action move_p5-2_p6-2
        :precondition (and (K_normal-execution) (K_at_p5-2))
        :effect (and (not (K_at_p5-2)) (not (K_not_at_p6-2)) (K_at_p6-2) (K_not_at_p5-2)))
    (:action move_p5-2_p5-3
        :precondition (and (K_normal-execution) (K_at_p5-2))
        :effect (and (not (K_at_p5-2)) (not (K_not_at_p5-3)) (K_at_p5-3) (K_not_at_p5-2)))
    (:action move_p5-2_p5-1
        :precondition (and (K_normal-execution) (K_at_p5-2))
        :effect (and (not (K_not_at_p5-1)) (not (K_at_p5-2)) (K_not_at_p5-2) (K_at_p5-1)))
    (:action move_p5-2_p4-2
        :precondition (and (K_normal-execution) (K_at_p5-2))
        :effect (and (not (K_not_at_p4-2)) (not (K_at_p5-2)) (K_not_at_p5-2) (K_at_p4-2)))
    (:action move_p5-1_p6-1
        :precondition (and (K_normal-execution) (K_at_p5-1))
        :effect (and (not (K_at_p5-1)) (not (K_not_at_p6-1)) (K_at_p6-1) (K_not_at_p5-1)))
    (:action move_p5-1_p5-2
        :precondition (and (K_normal-execution) (K_at_p5-1))
        :effect (and (not (K_at_p5-1)) (not (K_not_at_p5-2)) (K_at_p5-2) (K_not_at_p5-1)))
    (:action move_p5-1_p4-1
        :precondition (and (K_normal-execution) (K_at_p5-1))
        :effect (and (not (K_not_at_p4-1)) (not (K_at_p5-1)) (K_not_at_p5-1) (K_at_p4-1)))
    (:action move_p4-7_p5-7
        :precondition (and (K_normal-execution) (K_at_p4-7))
        :effect (and (not (K_at_p4-7)) (not (K_not_at_p5-7)) (K_at_p5-7) (K_not_at_p4-7)))
    (:action move_p4-7_p4-6
        :precondition (and (K_normal-execution) (K_at_p4-7))
        :effect (and (not (K_not_at_p4-6)) (not (K_at_p4-7)) (K_not_at_p4-7) (K_at_p4-6)))
    (:action move_p4-7_p3-7
        :precondition (and (K_normal-execution) (K_at_p4-7))
        :effect (and (not (K_not_at_p3-7)) (not (K_at_p4-7)) (K_not_at_p4-7) (K_at_p3-7)))
    (:action move_p4-6_p5-6
        :precondition (and (K_normal-execution) (K_safe_p5-6) (K_at_p4-6))
        :effect (and (not (K_at_p4-6)) (not (K_not_at_p5-6)) (K_at_p5-6) (K_not_at_p4-6)))
    (:action move_p4-6_p4-7
        :precondition (and (K_normal-execution) (K_at_p4-6))
        :effect (and (not (K_at_p4-6)) (not (K_not_at_p4-7)) (K_at_p4-7) (K_not_at_p4-6)))
    (:action move_p4-6_p4-5
        :precondition (and (K_normal-execution) (K_safe_p4-5) (K_at_p4-6))
        :effect (and (not (K_not_at_p4-5)) (not (K_at_p4-6)) (K_not_at_p4-6) (K_at_p4-5)))
    (:action move_p4-6_p3-6
        :precondition (and (K_normal-execution) (K_at_p4-6))
        :effect (and (not (K_not_at_p3-6)) (not (K_at_p4-6)) (K_not_at_p4-6) (K_at_p3-6)))
    (:action move_p4-5_p5-5
        :precondition (and (K_normal-execution) (K_at_p4-5))
        :effect (and (not (K_at_p4-5)) (not (K_not_at_p5-5)) (K_at_p5-5) (K_not_at_p4-5)))
    (:action move_p4-5_p4-6
        :precondition (and (K_normal-execution) (K_at_p4-5))
        :effect (and (not (K_at_p4-5)) (not (K_not_at_p4-6)) (K_at_p4-6) (K_not_at_p4-5)))
    (:action move_p4-5_p4-4
        :precondition (and (K_normal-execution) (K_at_p4-5))
        :effect (and (not (K_not_at_p4-4)) (not (K_at_p4-5)) (K_not_at_p4-5) (K_at_p4-4)))
    (:action move_p4-5_p3-5
        :precondition (and (K_normal-execution) (K_at_p4-5))
        :effect (and (not (K_not_at_p3-5)) (not (K_at_p4-5)) (K_not_at_p4-5) (K_at_p3-5)))
    (:action move_p4-4_p5-4
        :precondition (and (K_normal-execution) (K_safe_p5-4) (K_at_p4-4))
        :effect (and (not (K_at_p4-4)) (not (K_not_at_p5-4)) (K_at_p5-4) (K_not_at_p4-4)))
    (:action move_p4-4_p4-5
        :precondition (and (K_normal-execution) (K_safe_p4-5) (K_at_p4-4))
        :effect (and (not (K_at_p4-4)) (not (K_not_at_p4-5)) (K_at_p4-5) (K_not_at_p4-4)))
    (:action move_p4-4_p4-3
        :precondition (and (K_normal-execution) (K_safe_p4-3) (K_at_p4-4))
        :effect (and (not (K_not_at_p4-3)) (not (K_at_p4-4)) (K_not_at_p4-4) (K_at_p4-3)))
    (:action move_p4-4_p3-4
        :precondition (and (K_normal-execution) (K_safe_p3-4) (K_at_p4-4))
        :effect (and (not (K_not_at_p3-4)) (not (K_at_p4-4)) (K_not_at_p4-4) (K_at_p3-4)))
    (:action move_p4-3_p5-3
        :precondition (and (K_normal-execution) (K_at_p4-3))
        :effect (and (not (K_at_p4-3)) (not (K_not_at_p5-3)) (K_at_p5-3) (K_not_at_p4-3)))
    (:action move_p4-3_p4-4
        :precondition (and (K_normal-execution) (K_at_p4-3))
        :effect (and (not (K_at_p4-3)) (not (K_not_at_p4-4)) (K_at_p4-4) (K_not_at_p4-3)))
    (:action move_p4-3_p4-2
        :precondition (and (K_normal-execution) (K_at_p4-3))
        :effect (and (not (K_not_at_p4-2)) (not (K_at_p4-3)) (K_not_at_p4-3) (K_at_p4-2)))
    (:action move_p4-3_p3-3
        :precondition (and (K_normal-execution) (K_at_p4-3))
        :effect (and (not (K_not_at_p3-3)) (not (K_at_p4-3)) (K_not_at_p4-3) (K_at_p3-3)))
    (:action move_p4-2_p5-2
        :precondition (and (K_normal-execution) (K_at_p4-2))
        :effect (and (not (K_at_p4-2)) (not (K_not_at_p5-2)) (K_at_p5-2) (K_not_at_p4-2)))
    (:action move_p4-2_p4-3
        :precondition (and (K_normal-execution) (K_safe_p4-3) (K_at_p4-2))
        :effect (and (not (K_at_p4-2)) (not (K_not_at_p4-3)) (K_at_p4-3) (K_not_at_p4-2)))
    (:action move_p4-2_p4-1
        :precondition (and (K_normal-execution) (K_at_p4-2))
        :effect (and (not (K_not_at_p4-1)) (not (K_at_p4-2)) (K_not_at_p4-2) (K_at_p4-1)))
    (:action move_p4-2_p3-2
        :precondition (and (K_normal-execution) (K_safe_p3-2) (K_at_p4-2))
        :effect (and (not (K_not_at_p3-2)) (not (K_at_p4-2)) (K_not_at_p4-2) (K_at_p3-2)))
    (:action move_p4-1_p5-1
        :precondition (and (K_normal-execution) (K_at_p4-1))
        :effect (and (not (K_at_p4-1)) (not (K_not_at_p5-1)) (K_at_p5-1) (K_not_at_p4-1)))
    (:action move_p4-1_p4-2
        :precondition (and (K_normal-execution) (K_at_p4-1))
        :effect (and (not (K_at_p4-1)) (not (K_not_at_p4-2)) (K_at_p4-2) (K_not_at_p4-1)))
    (:action move_p4-1_p3-1
        :precondition (and (K_normal-execution) (K_at_p4-1))
        :effect (and (not (K_not_at_p3-1)) (not (K_at_p4-1)) (K_not_at_p4-1) (K_at_p3-1)))
    (:action move_p3-7_p4-7
        :precondition (and (K_normal-execution) (K_at_p3-7))
        :effect (and (not (K_at_p3-7)) (not (K_not_at_p4-7)) (K_at_p4-7) (K_not_at_p3-7)))
    (:action move_p3-7_p3-6
        :precondition (and (K_normal-execution) (K_at_p3-7))
        :effect (and (not (K_not_at_p3-6)) (not (K_at_p3-7)) (K_not_at_p3-7) (K_at_p3-6)))
    (:action move_p3-7_p2-7
        :precondition (and (K_normal-execution) (K_at_p3-7))
        :effect (and (not (K_not_at_p2-7)) (not (K_at_p3-7)) (K_not_at_p3-7) (K_at_p2-7)))
    (:action move_p3-6_p4-6
        :precondition (and (K_normal-execution) (K_at_p3-6))
        :effect (and (not (K_at_p3-6)) (not (K_not_at_p4-6)) (K_at_p4-6) (K_not_at_p3-6)))
    (:action move_p3-6_p3-7
        :precondition (and (K_normal-execution) (K_at_p3-6))
        :effect (and (not (K_at_p3-6)) (not (K_not_at_p3-7)) (K_at_p3-7) (K_not_at_p3-6)))
    (:action move_p3-6_p3-5
        :precondition (and (K_normal-execution) (K_at_p3-6))
        :effect (and (not (K_not_at_p3-5)) (not (K_at_p3-6)) (K_not_at_p3-6) (K_at_p3-5)))
    (:action move_p3-6_p2-6
        :precondition (and (K_normal-execution) (K_at_p3-6))
        :effect (and (not (K_not_at_p2-6)) (not (K_at_p3-6)) (K_not_at_p3-6) (K_at_p2-6)))
    (:action move_p3-5_p4-5
        :precondition (and (K_normal-execution) (K_safe_p4-5) (K_at_p3-5))
        :effect (and (not (K_at_p3-5)) (not (K_not_at_p4-5)) (K_at_p4-5) (K_not_at_p3-5)))
    (:action move_p3-5_p3-6
        :precondition (and (K_normal-execution) (K_at_p3-5))
        :effect (and (not (K_at_p3-5)) (not (K_not_at_p3-6)) (K_at_p3-6) (K_not_at_p3-5)))
    (:action move_p3-5_p3-4
        :precondition (and (K_normal-execution) (K_safe_p3-4) (K_at_p3-5))
        :effect (and (not (K_not_at_p3-4)) (not (K_at_p3-5)) (K_not_at_p3-5) (K_at_p3-4)))
    (:action move_p3-5_p2-5
        :precondition (and (K_normal-execution) (K_at_p3-5))
        :effect (and (not (K_not_at_p2-5)) (not (K_at_p3-5)) (K_not_at_p3-5) (K_at_p2-5)))
    (:action move_p3-4_p4-4
        :precondition (and (K_normal-execution) (K_at_p3-4))
        :effect (and (not (K_at_p3-4)) (not (K_not_at_p4-4)) (K_at_p4-4) (K_not_at_p3-4)))
    (:action move_p3-4_p3-5
        :precondition (and (K_normal-execution) (K_at_p3-4))
        :effect (and (not (K_at_p3-4)) (not (K_not_at_p3-5)) (K_at_p3-5) (K_not_at_p3-4)))
    (:action move_p3-4_p3-3
        :precondition (and (K_normal-execution) (K_at_p3-4))
        :effect (and (not (K_not_at_p3-3)) (not (K_at_p3-4)) (K_not_at_p3-4) (K_at_p3-3)))
    (:action move_p3-4_p2-4
        :precondition (and (K_normal-execution) (K_at_p3-4))
        :effect (and (not (K_not_at_p2-4)) (not (K_at_p3-4)) (K_not_at_p3-4) (K_at_p2-4)))
    (:action move_p3-3_p4-3
        :precondition (and (K_normal-execution) (K_safe_p4-3) (K_at_p3-3))
        :effect (and (not (K_at_p3-3)) (not (K_not_at_p4-3)) (K_at_p4-3) (K_not_at_p3-3)))
    (:action move_p3-3_p3-4
        :precondition (and (K_normal-execution) (K_safe_p3-4) (K_at_p3-3))
        :effect (and (not (K_at_p3-3)) (not (K_not_at_p3-4)) (K_at_p3-4) (K_not_at_p3-3)))
    (:action move_p3-3_p3-2
        :precondition (and (K_normal-execution) (K_safe_p3-2) (K_at_p3-3))
        :effect (and (not (K_not_at_p3-2)) (not (K_at_p3-3)) (K_not_at_p3-3) (K_at_p3-2)))
    (:action move_p3-3_p2-3
        :precondition (and (K_normal-execution) (K_safe_p2-3) (K_at_p3-3))
        :effect (and (not (K_not_at_p2-3)) (not (K_at_p3-3)) (K_not_at_p3-3) (K_at_p2-3)))
    (:action move_p3-2_p4-2
        :precondition (and (K_normal-execution) (K_at_p3-2))
        :effect (and (not (K_at_p3-2)) (not (K_not_at_p4-2)) (K_at_p4-2) (K_not_at_p3-2)))
    (:action move_p3-2_p3-3
        :precondition (and (K_normal-execution) (K_at_p3-2))
        :effect (and (not (K_at_p3-2)) (not (K_not_at_p3-3)) (K_at_p3-3) (K_not_at_p3-2)))
    (:action move_p3-2_p3-1
        :precondition (and (K_normal-execution) (K_at_p3-2))
        :effect (and (not (K_not_at_p3-1)) (not (K_at_p3-2)) (K_not_at_p3-2) (K_at_p3-1)))
    (:action move_p3-2_p2-2
        :precondition (and (K_normal-execution) (K_at_p3-2))
        :effect (and (not (K_not_at_p2-2)) (not (K_at_p3-2)) (K_not_at_p3-2) (K_at_p2-2)))
    (:action move_p3-1_p4-1
        :precondition (and (K_normal-execution) (K_at_p3-1))
        :effect (and (not (K_at_p3-1)) (not (K_not_at_p4-1)) (K_at_p4-1) (K_not_at_p3-1)))
    (:action move_p3-1_p3-2
        :precondition (and (K_normal-execution) (K_safe_p3-2) (K_at_p3-1))
        :effect (and (not (K_at_p3-1)) (not (K_not_at_p3-2)) (K_at_p3-2) (K_not_at_p3-1)))
    (:action move_p3-1_p2-1
        :precondition (and (K_normal-execution) (K_at_p3-1))
        :effect (and (not (K_not_at_p2-1)) (not (K_at_p3-1)) (K_not_at_p3-1) (K_at_p2-1)))
    (:action move_p2-7_p3-7
        :precondition (and (K_normal-execution) (K_at_p2-7))
        :effect (and (not (K_at_p2-7)) (not (K_not_at_p3-7)) (K_at_p3-7) (K_not_at_p2-7)))
    (:action move_p2-7_p2-6
        :precondition (and (K_normal-execution) (K_at_p2-7))
        :effect (and (not (K_not_at_p2-6)) (not (K_at_p2-7)) (K_not_at_p2-7) (K_at_p2-6)))
    (:action move_p2-7_p1-7
        :precondition (and (K_normal-execution) (K_at_p2-7))
        :effect (and (not (K_not_at_p1-7)) (not (K_at_p2-7)) (K_not_at_p2-7) (K_at_p1-7)))
    (:action move_p2-6_p3-6
        :precondition (and (K_normal-execution) (K_at_p2-6))
        :effect (and (not (K_at_p2-6)) (not (K_not_at_p3-6)) (K_at_p3-6) (K_not_at_p2-6)))
    (:action move_p2-6_p2-7
        :precondition (and (K_normal-execution) (K_at_p2-6))
        :effect (and (not (K_at_p2-6)) (not (K_not_at_p2-7)) (K_at_p2-7) (K_not_at_p2-6)))
    (:action move_p2-6_p2-5
        :precondition (and (K_normal-execution) (K_at_p2-6))
        :effect (and (not (K_not_at_p2-5)) (not (K_at_p2-6)) (K_not_at_p2-6) (K_at_p2-5)))
    (:action move_p2-6_p1-6
        :precondition (and (K_normal-execution) (K_at_p2-6))
        :effect (and (not (K_not_at_p1-6)) (not (K_at_p2-6)) (K_not_at_p2-6) (K_at_p1-6)))
    (:action move_p2-5_p3-5
        :precondition (and (K_normal-execution) (K_at_p2-5))
        :effect (and (not (K_at_p2-5)) (not (K_not_at_p3-5)) (K_at_p3-5) (K_not_at_p2-5)))
    (:action move_p2-5_p2-6
        :precondition (and (K_normal-execution) (K_at_p2-5))
        :effect (and (not (K_at_p2-5)) (not (K_not_at_p2-6)) (K_at_p2-6) (K_not_at_p2-5)))
    (:action move_p2-5_p2-4
        :precondition (and (K_normal-execution) (K_at_p2-5))
        :effect (and (not (K_not_at_p2-4)) (not (K_at_p2-5)) (K_not_at_p2-5) (K_at_p2-4)))
    (:action move_p2-5_p1-5
        :precondition (and (K_normal-execution) (K_at_p2-5))
        :effect (and (not (K_not_at_p1-5)) (not (K_at_p2-5)) (K_not_at_p2-5) (K_at_p1-5)))
    (:action move_p2-4_p3-4
        :precondition (and (K_normal-execution) (K_safe_p3-4) (K_at_p2-4))
        :effect (and (not (K_at_p2-4)) (not (K_not_at_p3-4)) (K_at_p3-4) (K_not_at_p2-4)))
    (:action move_p2-4_p2-5
        :precondition (and (K_normal-execution) (K_at_p2-4))
        :effect (and (not (K_at_p2-4)) (not (K_not_at_p2-5)) (K_at_p2-5) (K_not_at_p2-4)))
    (:action move_p2-4_p2-3
        :precondition (and (K_normal-execution) (K_safe_p2-3) (K_at_p2-4))
        :effect (and (not (K_not_at_p2-3)) (not (K_at_p2-4)) (K_not_at_p2-4) (K_at_p2-3)))
    (:action move_p2-4_p1-4
        :precondition (and (K_normal-execution) (K_at_p2-4))
        :effect (and (not (K_not_at_p1-4)) (not (K_at_p2-4)) (K_not_at_p2-4) (K_at_p1-4)))
    (:action move_p2-3_p3-3
        :precondition (and (K_normal-execution) (K_at_p2-3))
        :effect (and (not (K_at_p2-3)) (not (K_not_at_p3-3)) (K_at_p3-3) (K_not_at_p2-3)))
    (:action move_p2-3_p2-4
        :precondition (and (K_normal-execution) (K_at_p2-3))
        :effect (and (not (K_at_p2-3)) (not (K_not_at_p2-4)) (K_at_p2-4) (K_not_at_p2-3)))
    (:action move_p2-3_p2-2
        :precondition (and (K_normal-execution) (K_at_p2-3))
        :effect (and (not (K_not_at_p2-2)) (not (K_at_p2-3)) (K_not_at_p2-3) (K_at_p2-2)))
    (:action move_p2-3_p1-3
        :precondition (and (K_normal-execution) (K_at_p2-3))
        :effect (and (not (K_not_at_p1-3)) (not (K_at_p2-3)) (K_not_at_p2-3) (K_at_p1-3)))
    (:action move_p2-2_p3-2
        :precondition (and (K_normal-execution) (K_safe_p3-2) (K_at_p2-2))
        :effect (and (not (K_at_p2-2)) (not (K_not_at_p3-2)) (K_at_p3-2) (K_not_at_p2-2)))
    (:action move_p2-2_p2-3
        :precondition (and (K_normal-execution) (K_safe_p2-3) (K_at_p2-2))
        :effect (and (not (K_at_p2-2)) (not (K_not_at_p2-3)) (K_at_p2-3) (K_not_at_p2-2)))
    (:action move_p2-2_p2-1
        :precondition (and (K_normal-execution) (K_at_p2-2))
        :effect (and (not (K_not_at_p2-1)) (not (K_at_p2-2)) (K_not_at_p2-2) (K_at_p2-1)))
    (:action move_p2-2_p1-2
        :precondition (and (K_normal-execution) (K_at_p2-2))
        :effect (and (not (K_not_at_p1-2)) (not (K_at_p2-2)) (K_not_at_p2-2) (K_at_p1-2)))
    (:action move_p2-1_p3-1
        :precondition (and (K_normal-execution) (K_at_p2-1))
        :effect (and (not (K_at_p2-1)) (not (K_not_at_p3-1)) (K_at_p3-1) (K_not_at_p2-1)))
    (:action move_p2-1_p2-2
        :precondition (and (K_normal-execution) (K_at_p2-1))
        :effect (and (not (K_at_p2-1)) (not (K_not_at_p2-2)) (K_at_p2-2) (K_not_at_p2-1)))
    (:action move_p1-7_p2-7
        :precondition (and (K_normal-execution) (K_at_p1-7))
        :effect (and (not (K_at_p1-7)) (not (K_not_at_p2-7)) (K_at_p2-7) (K_not_at_p1-7)))
    (:action move_p1-7_p1-6
        :precondition (and (K_normal-execution) (K_at_p1-7))
        :effect (and (not (K_not_at_p1-6)) (not (K_at_p1-7)) (K_not_at_p1-7) (K_at_p1-6)))
    (:action move_p1-6_p2-6
        :precondition (and (K_normal-execution) (K_at_p1-6))
        :effect (and (not (K_at_p1-6)) (not (K_not_at_p2-6)) (K_at_p2-6) (K_not_at_p1-6)))
    (:action move_p1-6_p1-7
        :precondition (and (K_normal-execution) (K_at_p1-6))
        :effect (and (not (K_at_p1-6)) (not (K_not_at_p1-7)) (K_at_p1-7) (K_not_at_p1-6)))
    (:action move_p1-6_p1-5
        :precondition (and (K_normal-execution) (K_at_p1-6))
        :effect (and (not (K_not_at_p1-5)) (not (K_at_p1-6)) (K_not_at_p1-6) (K_at_p1-5)))
    (:action move_p1-5_p2-5
        :precondition (and (K_normal-execution) (K_at_p1-5))
        :effect (and (not (K_at_p1-5)) (not (K_not_at_p2-5)) (K_at_p2-5) (K_not_at_p1-5)))
    (:action move_p1-5_p1-6
        :precondition (and (K_normal-execution) (K_at_p1-5))
        :effect (and (not (K_at_p1-5)) (not (K_not_at_p1-6)) (K_at_p1-6) (K_not_at_p1-5)))
    (:action move_p1-5_p1-4
        :precondition (and (K_normal-execution) (K_at_p1-5))
        :effect (and (not (K_not_at_p1-4)) (not (K_at_p1-5)) (K_not_at_p1-5) (K_at_p1-4)))
    (:action move_p1-4_p2-4
        :precondition (and (K_normal-execution) (K_at_p1-4))
        :effect (and (not (K_at_p1-4)) (not (K_not_at_p2-4)) (K_at_p2-4) (K_not_at_p1-4)))
    (:action move_p1-4_p1-5
        :precondition (and (K_normal-execution) (K_at_p1-4))
        :effect (and (not (K_at_p1-4)) (not (K_not_at_p1-5)) (K_at_p1-5) (K_not_at_p1-4)))
    (:action move_p1-4_p1-3
        :precondition (and (K_normal-execution) (K_at_p1-4))
        :effect (and (not (K_not_at_p1-3)) (not (K_at_p1-4)) (K_not_at_p1-4) (K_at_p1-3)))
    (:action move_p1-3_p2-3
        :precondition (and (K_normal-execution) (K_safe_p2-3) (K_at_p1-3))
        :effect (and (not (K_at_p1-3)) (not (K_not_at_p2-3)) (K_at_p2-3) (K_not_at_p1-3)))
    (:action move_p1-3_p1-4
        :precondition (and (K_normal-execution) (K_at_p1-3))
        :effect (and (not (K_at_p1-3)) (not (K_not_at_p1-4)) (K_at_p1-4) (K_not_at_p1-3)))
    (:action move_p1-3_p1-2
        :precondition (and (K_normal-execution) (K_at_p1-3))
        :effect (and (not (K_not_at_p1-2)) (not (K_at_p1-3)) (K_not_at_p1-3) (K_at_p1-2)))
    (:action move_p1-2_p2-2
        :precondition (and (K_normal-execution) (K_at_p1-2))
        :effect (and (not (K_at_p1-2)) (not (K_not_at_p2-2)) (K_at_p2-2) (K_not_at_p1-2)))
    (:action move_p1-2_p1-3
        :precondition (and (K_normal-execution) (K_at_p1-2))
        :effect (and (not (K_at_p1-2)) (not (K_not_at_p1-3)) (K_at_p1-3) (K_not_at_p1-2)))
    (:action move_p1-2_p1-1
        :precondition (and (K_normal-execution) (K_at_p1-2))
        :effect (and (not (K_at_p1-2)) (not (K_not_at_p1-1)) (K_at_p1-1) (K_not_at_p1-2)))
    (:action move_p1-1_p1-2
        :precondition (and (K_normal-execution) (K_at_p1-1))
        :effect (and (not (K_not_at_p1-2)) (not (K_at_p1-1)) (K_not_at_p1-1) (K_at_p1-2)))


    (:action grab_p7-7
        :precondition (and (K_normal-execution) (K_gold-at_p7-7) (K_at_p7-7))
        :effect (and (not (K_not_got-the-treasure)) (not (K_gold-at_p7-7)) (K_not_gold-at_p7-7) (K_got-the-treasure)))


    (:action smell-wumpus_p7-7
        :precondition (and (K_normal-execution) (K_at_p7-7))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p7-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p7-7)))
    (:action smell-wumpus_p7-7__post__
        :precondition (K_need-post-for-smell-wumpus_p7-7)
        :effect (and (not (K_need-post-for-smell-wumpus_p7-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p7-7)))
    (:action smell-wumpus_p7-6
        :precondition (and (K_normal-execution) (K_at_p7-6))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p7-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p7-6)))
    (:action smell-wumpus_p7-6__post__
        :precondition (K_need-post-for-smell-wumpus_p7-6)
        :effect (and (not (K_need-post-for-smell-wumpus_p7-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p7-6)))
    (:action smell-wumpus_p7-5
        :precondition (and (K_normal-execution) (K_at_p7-5))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p7-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p7-5)))
    (:action smell-wumpus_p7-5__post__
        :precondition (K_need-post-for-smell-wumpus_p7-5)
        :effect (and (not (K_need-post-for-smell-wumpus_p7-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p7-5)))
    (:action smell-wumpus_p7-4
        :precondition (and (K_normal-execution) (K_at_p7-4))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p7-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p7-4)))
    (:action smell-wumpus_p7-4__post__
        :precondition (K_need-post-for-smell-wumpus_p7-4)
        :effect (and (not (K_need-post-for-smell-wumpus_p7-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p7-4)))
    (:action smell-wumpus_p7-3
        :precondition (and (K_normal-execution) (K_at_p7-3))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p7-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p7-3)))
    (:action smell-wumpus_p7-3__post__
        :precondition (K_need-post-for-smell-wumpus_p7-3)
        :effect (and (not (K_need-post-for-smell-wumpus_p7-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p7-3)))
    (:action smell-wumpus_p7-2
        :precondition (and (K_normal-execution) (K_at_p7-2))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p7-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p7-2)))
    (:action smell-wumpus_p7-2__post__
        :precondition (K_need-post-for-smell-wumpus_p7-2)
        :effect (and (not (K_need-post-for-smell-wumpus_p7-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p7-2)))
    (:action smell-wumpus_p7-1
        :precondition (and (K_normal-execution) (K_at_p7-1))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p7-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p7-1)))
    (:action smell-wumpus_p7-1__post__
        :precondition (K_need-post-for-smell-wumpus_p7-1)
        :effect (and (not (K_need-post-for-smell-wumpus_p7-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p7-1)))

    (:action smell-wumpus_p6-7
        :precondition (and (K_normal-execution) (K_at_p6-7))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p6-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p6-7)))
    (:action smell-wumpus_p6-7__post__
        :precondition (K_need-post-for-smell-wumpus_p6-7)
        :effect (and (not (K_need-post-for-smell-wumpus_p6-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p6-7)))
    (:action smell-wumpus_p6-6
        :precondition (and (K_normal-execution) (K_at_p6-6))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p6-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p6-6)))
    (:action smell-wumpus_p6-6__post__
        :precondition (K_need-post-for-smell-wumpus_p6-6)
        :effect (and (not (K_need-post-for-smell-wumpus_p6-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p6-6)))
    (:action smell-wumpus_p6-5
        :precondition (and (K_normal-execution) (K_at_p6-5))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p6-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p6-5)))
    (:action smell-wumpus_p6-5__post__
        :precondition (K_need-post-for-smell-wumpus_p6-5)
        :effect (and (not (K_need-post-for-smell-wumpus_p6-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p6-5)))
    (:action smell-wumpus_p6-4
        :precondition (and (K_normal-execution) (K_at_p6-4))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p6-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p6-4)))
    (:action smell-wumpus_p6-4__post__
        :precondition (K_need-post-for-smell-wumpus_p6-4)
        :effect (and (not (K_need-post-for-smell-wumpus_p6-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p6-4)))
    (:action smell-wumpus_p6-3
        :precondition (and (K_normal-execution) (K_at_p6-3))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p6-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p6-3)))
    (:action smell-wumpus_p6-3__post__
        :precondition (K_need-post-for-smell-wumpus_p6-3)
        :effect (and (not (K_need-post-for-smell-wumpus_p6-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p6-3)))
    (:action smell-wumpus_p6-2
        :precondition (and (K_normal-execution) (K_at_p6-2))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p6-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p6-2)))
    (:action smell-wumpus_p6-2__post__
        :precondition (K_need-post-for-smell-wumpus_p6-2)
        :effect (and (not (K_need-post-for-smell-wumpus_p6-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p6-2)))
    (:action smell-wumpus_p6-1
        :precondition (and (K_normal-execution) (K_at_p6-1))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p6-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p6-1)))
    (:action smell-wumpus_p6-1__post__
        :precondition (K_need-post-for-smell-wumpus_p6-1)
        :effect (and (not (K_need-post-for-smell-wumpus_p6-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p6-1)))

    (:action smell-wumpus_p5-7
        :precondition (and (K_normal-execution) (K_at_p5-7))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p5-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p5-7)))
    (:action smell-wumpus_p5-7__post__
        :precondition (K_need-post-for-smell-wumpus_p5-7)
        :effect (and (not (K_need-post-for-smell-wumpus_p5-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p5-7)))
    (:action smell-wumpus_p5-6
        :precondition (and (K_normal-execution) (K_at_p5-6))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p5-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p5-6)))
    (:action smell-wumpus_p5-6__post__
        :precondition (K_need-post-for-smell-wumpus_p5-6)
        :effect (and (not (K_need-post-for-smell-wumpus_p5-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p5-6)))
    (:action smell-wumpus_p5-5
        :precondition (and (K_normal-execution) (K_at_p5-5))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p5-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p5-5)))
    (:action smell-wumpus_p5-5__post__
        :precondition (K_need-post-for-smell-wumpus_p5-5)
        :effect (and (not (K_need-post-for-smell-wumpus_p5-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p5-5)))
    (:action smell-wumpus_p5-4
        :precondition (and (K_normal-execution) (K_at_p5-4))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p5-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p5-4)))
    (:action smell-wumpus_p5-4__post__
        :precondition (K_need-post-for-smell-wumpus_p5-4)
        :effect (and (not (K_need-post-for-smell-wumpus_p5-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p5-4)))
    (:action smell-wumpus_p5-3
        :precondition (and (K_normal-execution) (K_at_p5-3))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p5-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p5-3)))
    (:action smell-wumpus_p5-3__post__
        :precondition (K_need-post-for-smell-wumpus_p5-3)
        :effect (and (not (K_need-post-for-smell-wumpus_p5-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p5-3)))
    (:action smell-wumpus_p5-2
        :precondition (and (K_normal-execution) (K_at_p5-2))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p5-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p5-2)))
    (:action smell-wumpus_p5-2__post__
        :precondition (K_need-post-for-smell-wumpus_p5-2)
        :effect (and (not (K_need-post-for-smell-wumpus_p5-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p5-2)))
    (:action smell-wumpus_p5-1
        :precondition (and (K_normal-execution) (K_at_p5-1))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p5-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p5-1)))
    (:action smell-wumpus_p5-1__post__
        :precondition (K_need-post-for-smell-wumpus_p5-1)
        :effect (and (not (K_need-post-for-smell-wumpus_p5-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p5-1)))

    (:action smell-wumpus_p4-7
        :precondition (and (K_normal-execution) (K_at_p4-7))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p4-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p4-7)))
    (:action smell-wumpus_p4-7__post__
        :precondition (K_need-post-for-smell-wumpus_p4-7)
        :effect (and (not (K_need-post-for-smell-wumpus_p4-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p4-7)))
    (:action smell-wumpus_p4-6
        :precondition (and (K_normal-execution) (K_at_p4-6))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p4-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p4-6)))
    (:action smell-wumpus_p4-6__post__
        :precondition (K_need-post-for-smell-wumpus_p4-6)
        :effect (and (not (K_need-post-for-smell-wumpus_p4-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p4-6)))
    (:action smell-wumpus_p4-5
        :precondition (and (K_normal-execution) (K_at_p4-5))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p4-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p4-5)))
    (:action smell-wumpus_p4-5__post__
        :precondition (K_need-post-for-smell-wumpus_p4-5)
        :effect (and (not (K_need-post-for-smell-wumpus_p4-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p4-5)))
    (:action smell-wumpus_p4-4
        :precondition (and (K_normal-execution) (K_at_p4-4))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p4-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p4-4)))
    (:action smell-wumpus_p4-4__post__
        :precondition (K_need-post-for-smell-wumpus_p4-4)
        :effect (and (not (K_need-post-for-smell-wumpus_p4-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p4-4)))
    (:action smell-wumpus_p4-3
        :precondition (and (K_normal-execution) (K_at_p4-3))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p4-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p4-3)))
    (:action smell-wumpus_p4-3__post__
        :precondition (K_need-post-for-smell-wumpus_p4-3)
        :effect (and (not (K_need-post-for-smell-wumpus_p4-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p4-3)))
    (:action smell-wumpus_p4-2
        :precondition (and (K_normal-execution) (K_at_p4-2))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p4-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p4-2)))
    (:action smell-wumpus_p4-2__post__
        :precondition (K_need-post-for-smell-wumpus_p4-2)
        :effect (and (not (K_need-post-for-smell-wumpus_p4-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p4-2)))
    (:action smell-wumpus_p4-1
        :precondition (and (K_normal-execution) (K_at_p4-1))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p4-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p4-1)))
    (:action smell-wumpus_p4-1__post__
        :precondition (K_need-post-for-smell-wumpus_p4-1)
        :effect (and (not (K_need-post-for-smell-wumpus_p4-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p4-1)))

    (:action smell-wumpus_p3-7
        :precondition (and (K_normal-execution) (K_at_p3-7))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p3-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p3-7)))
    (:action smell-wumpus_p3-7__post__
        :precondition (K_need-post-for-smell-wumpus_p3-7)
        :effect (and (not (K_need-post-for-smell-wumpus_p3-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p3-7)))
    (:action smell-wumpus_p3-6
        :precondition (and (K_normal-execution) (K_at_p3-6))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p3-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p3-6)))
    (:action smell-wumpus_p3-6__post__
        :precondition (K_need-post-for-smell-wumpus_p3-6)
        :effect (and (not (K_need-post-for-smell-wumpus_p3-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p3-6)))
    (:action smell-wumpus_p3-5
        :precondition (and (K_normal-execution) (K_at_p3-5))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p3-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p3-5)))
    (:action smell-wumpus_p3-5__post__
        :precondition (K_need-post-for-smell-wumpus_p3-5)
        :effect (and (not (K_need-post-for-smell-wumpus_p3-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p3-5)))
    (:action smell-wumpus_p3-4
        :precondition (and (K_normal-execution) (K_at_p3-4))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p3-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p3-4)))
    (:action smell-wumpus_p3-4__post__
        :precondition (K_need-post-for-smell-wumpus_p3-4)
        :effect (and (not (K_need-post-for-smell-wumpus_p3-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p3-4)))
    (:action smell-wumpus_p3-3
        :precondition (and (K_normal-execution) (K_at_p3-3))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p3-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p3-3)))
    (:action smell-wumpus_p3-3__post__
        :precondition (K_need-post-for-smell-wumpus_p3-3)
        :effect (and (not (K_need-post-for-smell-wumpus_p3-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p3-3)))
    (:action smell-wumpus_p3-2
        :precondition (and (K_normal-execution) (K_at_p3-2))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p3-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p3-2)))
    (:action smell-wumpus_p3-2__post__
        :precondition (K_need-post-for-smell-wumpus_p3-2)
        :effect (and (not (K_need-post-for-smell-wumpus_p3-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p3-2)))
    (:action smell-wumpus_p3-1
        :precondition (and (K_normal-execution) (K_at_p3-1))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p3-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p3-1)))
    (:action smell-wumpus_p3-1__post__
        :precondition (K_need-post-for-smell-wumpus_p3-1)
        :effect (and (not (K_need-post-for-smell-wumpus_p3-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p3-1)))

    (:action smell-wumpus_p2-7
        :precondition (and (K_normal-execution) (K_at_p2-7))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p2-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p2-7)))
    (:action smell-wumpus_p2-7__post__
        :precondition (K_need-post-for-smell-wumpus_p2-7)
        :effect (and (not (K_need-post-for-smell-wumpus_p2-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p2-7)))
    (:action smell-wumpus_p2-6
        :precondition (and (K_normal-execution) (K_at_p2-6))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p2-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p2-6)))
    (:action smell-wumpus_p2-6__post__
        :precondition (K_need-post-for-smell-wumpus_p2-6)
        :effect (and (not (K_need-post-for-smell-wumpus_p2-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p2-6)))
    (:action smell-wumpus_p2-5
        :precondition (and (K_normal-execution) (K_at_p2-5))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p2-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p2-5)))
    (:action smell-wumpus_p2-5__post__
        :precondition (K_need-post-for-smell-wumpus_p2-5)
        :effect (and (not (K_need-post-for-smell-wumpus_p2-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p2-5)))
    (:action smell-wumpus_p2-4
        :precondition (and (K_normal-execution) (K_at_p2-4))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p2-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p2-4)))
    (:action smell-wumpus_p2-4__post__
        :precondition (K_need-post-for-smell-wumpus_p2-4)
        :effect (and (not (K_need-post-for-smell-wumpus_p2-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p2-4)))
    (:action smell-wumpus_p2-3
        :precondition (and (K_normal-execution) (K_at_p2-3))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p2-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p2-3)))
    (:action smell-wumpus_p2-3__post__
        :precondition (K_need-post-for-smell-wumpus_p2-3)
        :effect (and (not (K_need-post-for-smell-wumpus_p2-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p2-3)))
    (:action smell-wumpus_p2-2
        :precondition (and (K_normal-execution) (K_at_p2-2))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p2-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p2-2)))
    (:action smell-wumpus_p2-2__post__
        :precondition (K_need-post-for-smell-wumpus_p2-2)
        :effect (and (not (K_need-post-for-smell-wumpus_p2-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p2-2)))
    (:action smell-wumpus_p2-1
        :precondition (and (K_normal-execution) (K_at_p2-1))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p2-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p2-1)))
    (:action smell-wumpus_p2-1__post__
        :precondition (K_need-post-for-smell-wumpus_p2-1)
        :effect (and (not (K_need-post-for-smell-wumpus_p2-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p2-1)))

    (:action smell-wumpus_p1-7
        :precondition (and (K_normal-execution) (K_at_p1-7))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p1-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p1-7)))
    (:action smell-wumpus_p1-7__post__
        :precondition (K_need-post-for-smell-wumpus_p1-7)
        :effect (and (not (K_need-post-for-smell-wumpus_p1-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p1-7)))
    (:action smell-wumpus_p1-6
        :precondition (and (K_normal-execution) (K_at_p1-6))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p1-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p1-6)))
    (:action smell-wumpus_p1-6__post__
        :precondition (K_need-post-for-smell-wumpus_p1-6)
        :effect (and (not (K_need-post-for-smell-wumpus_p1-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p1-6)))
    (:action smell-wumpus_p1-5
        :precondition (and (K_normal-execution) (K_at_p1-5))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p1-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p1-5)))
    (:action smell-wumpus_p1-5__post__
        :precondition (K_need-post-for-smell-wumpus_p1-5)
        :effect (and (not (K_need-post-for-smell-wumpus_p1-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p1-5)))
    (:action smell-wumpus_p1-4
        :precondition (and (K_normal-execution) (K_at_p1-4))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p1-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p1-4)))
    (:action smell-wumpus_p1-4__post__
        :precondition (K_need-post-for-smell-wumpus_p1-4)
        :effect (and (not (K_need-post-for-smell-wumpus_p1-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p1-4)))
    (:action smell-wumpus_p1-3
        :precondition (and (K_normal-execution) (K_at_p1-3))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p1-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p1-3)))
    (:action smell-wumpus_p1-3__post__
        :precondition (K_need-post-for-smell-wumpus_p1-3)
        :effect (and (not (K_need-post-for-smell-wumpus_p1-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p1-3)))
    (:action smell-wumpus_p1-2
        :precondition (and (K_normal-execution) (K_at_p1-2))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p1-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p1-2)))
    (:action smell-wumpus_p1-2__post__
        :precondition (K_need-post-for-smell-wumpus_p1-2)
        :effect (and (not (K_need-post-for-smell-wumpus_p1-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p1-2)))
    (:action smell-wumpus_p1-1
        :precondition (and (K_normal-execution) (K_at_p1-1))
        :effect (and (not (K_not_need-post-for-smell-wumpus_p1-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-smell-wumpus_p1-1)))
    (:action smell-wumpus_p1-1__post__
        :precondition (K_need-post-for-smell-wumpus_p1-1)
        :effect (and (not (K_need-post-for-smell-wumpus_p1-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-smell-wumpus_p1-1)))

    (:action feel-breeze_p7-7
        :precondition (and (K_normal-execution) (K_at_p7-7))
        :effect (and (not (K_not_need-post-for-feel-breeze_p7-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p7-7)))
    (:action feel-breeze_p7-6
        :precondition (and (K_normal-execution) (K_at_p7-6))
        :effect (and (not (K_not_need-post-for-feel-breeze_p7-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p7-6)))
    (:action feel-breeze_p7-5
        :precondition (and (K_normal-execution) (K_at_p7-5))
        :effect (and (not (K_not_need-post-for-feel-breeze_p7-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p7-5)))
    (:action feel-breeze_p7-4
        :precondition (and (K_normal-execution) (K_at_p7-4))
        :effect (and (not (K_not_need-post-for-feel-breeze_p7-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p7-4)))
    (:action feel-breeze_p7-3
        :precondition (and (K_normal-execution) (K_at_p7-3))
        :effect (and (not (K_not_need-post-for-feel-breeze_p7-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p7-3)))
    (:action feel-breeze_p7-2
        :precondition (and (K_normal-execution) (K_at_p7-2))
        :effect (and (not (K_not_need-post-for-feel-breeze_p7-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p7-2)))
    (:action feel-breeze_p7-1
        :precondition (and (K_normal-execution) (K_at_p7-1))
        :effect (and (not (K_not_need-post-for-feel-breeze_p7-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p7-1)))
    (:action feel-breeze_p6-7
        :precondition (and (K_normal-execution) (K_at_p6-7))
        :effect (and (not (K_not_need-post-for-feel-breeze_p6-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p6-7)))
    (:action feel-breeze_p6-6
        :precondition (and (K_normal-execution) (K_at_p6-6))
        :effect (and (not (K_not_need-post-for-feel-breeze_p6-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p6-6)))
    (:action feel-breeze_p6-5
        :precondition (and (K_normal-execution) (K_at_p6-5))
        :effect (and (not (K_not_need-post-for-feel-breeze_p6-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p6-5)))
    (:action feel-breeze_p6-4
        :precondition (and (K_normal-execution) (K_at_p6-4))
        :effect (and (not (K_not_need-post-for-feel-breeze_p6-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p6-4)))
    (:action feel-breeze_p6-3
        :precondition (and (K_normal-execution) (K_at_p6-3))
        :effect (and (not (K_not_need-post-for-feel-breeze_p6-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p6-3)))
    (:action feel-breeze_p6-2
        :precondition (and (K_normal-execution) (K_at_p6-2))
        :effect (and (not (K_not_need-post-for-feel-breeze_p6-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p6-2)))
    (:action feel-breeze_p6-1
        :precondition (and (K_normal-execution) (K_at_p6-1))
        :effect (and (not (K_not_need-post-for-feel-breeze_p6-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p6-1)))
    (:action feel-breeze_p5-7
        :precondition (and (K_normal-execution) (K_at_p5-7))
        :effect (and (not (K_not_need-post-for-feel-breeze_p5-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p5-7)))
    (:action feel-breeze_p5-6
        :precondition (and (K_normal-execution) (K_at_p5-6))
        :effect (and (not (K_not_need-post-for-feel-breeze_p5-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p5-6)))
    (:action feel-breeze_p5-5
        :precondition (and (K_normal-execution) (K_at_p5-5))
        :effect (and (not (K_not_need-post-for-feel-breeze_p5-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p5-5)))
    (:action feel-breeze_p5-4
        :precondition (and (K_normal-execution) (K_at_p5-4))
        :effect (and (not (K_not_need-post-for-feel-breeze_p5-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p5-4)))
    (:action feel-breeze_p5-3
        :precondition (and (K_normal-execution) (K_at_p5-3))
        :effect (and (not (K_not_need-post-for-feel-breeze_p5-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p5-3)))
    (:action feel-breeze_p5-2
        :precondition (and (K_normal-execution) (K_at_p5-2))
        :effect (and (not (K_not_need-post-for-feel-breeze_p5-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p5-2)))
    (:action feel-breeze_p5-1
        :precondition (and (K_normal-execution) (K_at_p5-1))
        :effect (and (not (K_not_need-post-for-feel-breeze_p5-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p5-1)))
    (:action feel-breeze_p4-7
        :precondition (and (K_normal-execution) (K_at_p4-7))
        :effect (and (not (K_not_need-post-for-feel-breeze_p4-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p4-7)))
    (:action feel-breeze_p4-6
        :precondition (and (K_normal-execution) (K_at_p4-6))
        :effect (and (not (K_not_need-post-for-feel-breeze_p4-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p4-6)))
    (:action feel-breeze_p4-5
        :precondition (and (K_normal-execution) (K_at_p4-5))
        :effect (and (not (K_not_need-post-for-feel-breeze_p4-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p4-5)))
    (:action feel-breeze_p4-4
        :precondition (and (K_normal-execution) (K_at_p4-4))
        :effect (and (not (K_not_need-post-for-feel-breeze_p4-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p4-4)))
    (:action feel-breeze_p4-3
        :precondition (and (K_normal-execution) (K_at_p4-3))
        :effect (and (not (K_not_need-post-for-feel-breeze_p4-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p4-3)))
    (:action feel-breeze_p4-2
        :precondition (and (K_normal-execution) (K_at_p4-2))
        :effect (and (not (K_not_need-post-for-feel-breeze_p4-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p4-2)))
    (:action feel-breeze_p4-1
        :precondition (and (K_normal-execution) (K_at_p4-1))
        :effect (and (not (K_not_need-post-for-feel-breeze_p4-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p4-1)))
    (:action feel-breeze_p3-7
        :precondition (and (K_normal-execution) (K_at_p3-7))
        :effect (and (not (K_not_need-post-for-feel-breeze_p3-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p3-7)))
    (:action feel-breeze_p3-6
        :precondition (and (K_normal-execution) (K_at_p3-6))
        :effect (and (not (K_not_need-post-for-feel-breeze_p3-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p3-6)))
    (:action feel-breeze_p3-5
        :precondition (and (K_normal-execution) (K_at_p3-5))
        :effect (and (not (K_not_need-post-for-feel-breeze_p3-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p3-5)))
    (:action feel-breeze_p3-4
        :precondition (and (K_normal-execution) (K_at_p3-4))
        :effect (and (not (K_not_need-post-for-feel-breeze_p3-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p3-4)))
    (:action feel-breeze_p3-3
        :precondition (and (K_normal-execution) (K_at_p3-3))
        :effect (and (not (K_not_need-post-for-feel-breeze_p3-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p3-3)))
    (:action feel-breeze_p3-2
        :precondition (and (K_normal-execution) (K_at_p3-2))
        :effect (and (not (K_not_need-post-for-feel-breeze_p3-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p3-2)))
    (:action feel-breeze_p3-1
        :precondition (and (K_normal-execution) (K_at_p3-1))
        :effect (and (not (K_not_need-post-for-feel-breeze_p3-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p3-1)))
    (:action feel-breeze_p2-7
        :precondition (and (K_normal-execution) (K_at_p2-7))
        :effect (and (not (K_not_need-post-for-feel-breeze_p2-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p2-7)))
    (:action feel-breeze_p2-6
        :precondition (and (K_normal-execution) (K_at_p2-6))
        :effect (and (not (K_not_need-post-for-feel-breeze_p2-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p2-6)))
    (:action feel-breeze_p2-5
        :precondition (and (K_normal-execution) (K_at_p2-5))
        :effect (and (not (K_not_need-post-for-feel-breeze_p2-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p2-5)))
    (:action feel-breeze_p2-4
        :precondition (and (K_normal-execution) (K_at_p2-4))
        :effect (and (not (K_not_need-post-for-feel-breeze_p2-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p2-4)))
    (:action feel-breeze_p2-3
        :precondition (and (K_normal-execution) (K_at_p2-3))
        :effect (and (not (K_not_need-post-for-feel-breeze_p2-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p2-3)))
    (:action feel-breeze_p2-2
        :precondition (and (K_normal-execution) (K_at_p2-2))
        :effect (and (not (K_not_need-post-for-feel-breeze_p2-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p2-2)))
    (:action feel-breeze_p2-1
        :precondition (and (K_normal-execution) (K_at_p2-1))
        :effect (and (not (K_not_need-post-for-feel-breeze_p2-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p2-1)))
    (:action feel-breeze_p1-7
        :precondition (and (K_normal-execution) (K_at_p1-7))
        :effect (and (not (K_not_need-post-for-feel-breeze_p1-7)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p1-7)))
    (:action feel-breeze_p1-6
        :precondition (and (K_normal-execution) (K_at_p1-6))
        :effect (and (not (K_not_need-post-for-feel-breeze_p1-6)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p1-6)))
    (:action feel-breeze_p1-5
        :precondition (and (K_normal-execution) (K_at_p1-5))
        :effect (and (not (K_not_need-post-for-feel-breeze_p1-5)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p1-5)))
    (:action feel-breeze_p1-4
        :precondition (and (K_normal-execution) (K_at_p1-4))
        :effect (and (not (K_not_need-post-for-feel-breeze_p1-4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p1-4)))
    (:action feel-breeze_p1-3
        :precondition (and (K_normal-execution) (K_at_p1-3))
        :effect (and (not (K_not_need-post-for-feel-breeze_p1-3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p1-3)))
    (:action feel-breeze_p1-2
        :precondition (and (K_normal-execution) (K_at_p1-2))
        :effect (and (not (K_not_need-post-for-feel-breeze_p1-2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p1-2)))
    (:action feel-breeze_p1-1
        :precondition (and (K_normal-execution) (K_at_p1-1))
        :effect (and (not (K_not_need-post-for-feel-breeze_p1-1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-feel-breeze_p1-1)))
    (:action feel-breeze_p7-7__post__
        :precondition (K_need-post-for-feel-breeze_p7-7)
        :effect (and (not (K_need-post-for-feel-breeze_p7-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p7-7)))
    (:action feel-breeze_p7-6__post__
        :precondition (K_need-post-for-feel-breeze_p7-6)
        :effect (and (not (K_need-post-for-feel-breeze_p7-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p7-6)))
    (:action feel-breeze_p7-5__post__
        :precondition (K_need-post-for-feel-breeze_p7-5)
        :effect (and (not (K_need-post-for-feel-breeze_p7-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p7-5)))
    (:action feel-breeze_p7-4__post__
        :precondition (K_need-post-for-feel-breeze_p7-4)
        :effect (and (not (K_need-post-for-feel-breeze_p7-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p7-4)))
    (:action feel-breeze_p7-3__post__
        :precondition (K_need-post-for-feel-breeze_p7-3)
        :effect (and (not (K_need-post-for-feel-breeze_p7-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p7-3)))
    (:action feel-breeze_p7-2__post__
        :precondition (K_need-post-for-feel-breeze_p7-2)
        :effect (and (not (K_need-post-for-feel-breeze_p7-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p7-2)))
    (:action feel-breeze_p7-1__post__
        :precondition (K_need-post-for-feel-breeze_p7-1)
        :effect (and (not (K_need-post-for-feel-breeze_p7-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p7-1)))
    (:action feel-breeze_p6-7__post__
        :precondition (K_need-post-for-feel-breeze_p6-7)
        :effect (and (not (K_need-post-for-feel-breeze_p6-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p6-7)))
    (:action feel-breeze_p6-6__post__
        :precondition (K_need-post-for-feel-breeze_p6-6)
        :effect (and (not (K_need-post-for-feel-breeze_p6-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p6-6)))
    (:action feel-breeze_p6-5__post__
        :precondition (K_need-post-for-feel-breeze_p6-5)
        :effect (and (not (K_need-post-for-feel-breeze_p6-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p6-5)))
    (:action feel-breeze_p6-4__post__
        :precondition (K_need-post-for-feel-breeze_p6-4)
        :effect (and (not (K_need-post-for-feel-breeze_p6-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p6-4)))
    (:action feel-breeze_p6-3__post__
        :precondition (K_need-post-for-feel-breeze_p6-3)
        :effect (and (not (K_need-post-for-feel-breeze_p6-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p6-3)))
    (:action feel-breeze_p6-2__post__
        :precondition (K_need-post-for-feel-breeze_p6-2)
        :effect (and (not (K_need-post-for-feel-breeze_p6-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p6-2)))
    (:action feel-breeze_p6-1__post__
        :precondition (K_need-post-for-feel-breeze_p6-1)
        :effect (and (not (K_need-post-for-feel-breeze_p6-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p6-1)))
    (:action feel-breeze_p5-7__post__
        :precondition (K_need-post-for-feel-breeze_p5-7)
        :effect (and (not (K_need-post-for-feel-breeze_p5-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p5-7)))
    (:action feel-breeze_p5-6__post__
        :precondition (K_need-post-for-feel-breeze_p5-6)
        :effect (and (not (K_need-post-for-feel-breeze_p5-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p5-6)))
    (:action feel-breeze_p5-5__post__
        :precondition (K_need-post-for-feel-breeze_p5-5)
        :effect (and (not (K_need-post-for-feel-breeze_p5-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p5-5)))
    (:action feel-breeze_p5-4__post__
        :precondition (K_need-post-for-feel-breeze_p5-4)
        :effect (and (not (K_need-post-for-feel-breeze_p5-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p5-4)))
    (:action feel-breeze_p5-3__post__
        :precondition (K_need-post-for-feel-breeze_p5-3)
        :effect (and (not (K_need-post-for-feel-breeze_p5-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p5-3)))
    (:action feel-breeze_p5-2__post__
        :precondition (K_need-post-for-feel-breeze_p5-2)
        :effect (and (not (K_need-post-for-feel-breeze_p5-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p5-2)))
    (:action feel-breeze_p5-1__post__
        :precondition (K_need-post-for-feel-breeze_p5-1)
        :effect (and (not (K_need-post-for-feel-breeze_p5-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p5-1)))
    (:action feel-breeze_p4-7__post__
        :precondition (K_need-post-for-feel-breeze_p4-7)
        :effect (and (not (K_need-post-for-feel-breeze_p4-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p4-7)))
    (:action feel-breeze_p4-6__post__
        :precondition (K_need-post-for-feel-breeze_p4-6)
        :effect (and (not (K_need-post-for-feel-breeze_p4-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p4-6)))
    (:action feel-breeze_p4-5__post__
        :precondition (K_need-post-for-feel-breeze_p4-5)
        :effect (and (not (K_need-post-for-feel-breeze_p4-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p4-5)))
    (:action feel-breeze_p4-4__post__
        :precondition (K_need-post-for-feel-breeze_p4-4)
        :effect (and (not (K_need-post-for-feel-breeze_p4-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p4-4)))
    (:action feel-breeze_p4-3__post__
        :precondition (K_need-post-for-feel-breeze_p4-3)
        :effect (and (not (K_need-post-for-feel-breeze_p4-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p4-3)))
    (:action feel-breeze_p4-2__post__
        :precondition (K_need-post-for-feel-breeze_p4-2)
        :effect (and (not (K_need-post-for-feel-breeze_p4-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p4-2)))
    (:action feel-breeze_p4-1__post__
        :precondition (K_need-post-for-feel-breeze_p4-1)
        :effect (and (not (K_need-post-for-feel-breeze_p4-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p4-1)))
    (:action feel-breeze_p3-7__post__
        :precondition (K_need-post-for-feel-breeze_p3-7)
        :effect (and (not (K_need-post-for-feel-breeze_p3-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p3-7)))
    (:action feel-breeze_p3-6__post__
        :precondition (K_need-post-for-feel-breeze_p3-6)
        :effect (and (not (K_need-post-for-feel-breeze_p3-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p3-6)))
    (:action feel-breeze_p3-5__post__
        :precondition (K_need-post-for-feel-breeze_p3-5)
        :effect (and (not (K_need-post-for-feel-breeze_p3-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p3-5)))
    (:action feel-breeze_p3-4__post__
        :precondition (K_need-post-for-feel-breeze_p3-4)
        :effect (and (not (K_need-post-for-feel-breeze_p3-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p3-4)))
    (:action feel-breeze_p3-3__post__
        :precondition (K_need-post-for-feel-breeze_p3-3)
        :effect (and (not (K_need-post-for-feel-breeze_p3-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p3-3)))
    (:action feel-breeze_p3-2__post__
        :precondition (K_need-post-for-feel-breeze_p3-2)
        :effect (and (not (K_need-post-for-feel-breeze_p3-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p3-2)))
    (:action feel-breeze_p3-1__post__
        :precondition (K_need-post-for-feel-breeze_p3-1)
        :effect (and (not (K_need-post-for-feel-breeze_p3-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p3-1)))
    (:action feel-breeze_p2-7__post__
        :precondition (K_need-post-for-feel-breeze_p2-7)
        :effect (and (not (K_need-post-for-feel-breeze_p2-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p2-7)))
    (:action feel-breeze_p2-6__post__
        :precondition (K_need-post-for-feel-breeze_p2-6)
        :effect (and (not (K_need-post-for-feel-breeze_p2-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p2-6)))
    (:action feel-breeze_p2-5__post__
        :precondition (K_need-post-for-feel-breeze_p2-5)
        :effect (and (not (K_need-post-for-feel-breeze_p2-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p2-5)))
    (:action feel-breeze_p2-4__post__
        :precondition (K_need-post-for-feel-breeze_p2-4)
        :effect (and (not (K_need-post-for-feel-breeze_p2-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p2-4)))
    (:action feel-breeze_p2-3__post__
        :precondition (K_need-post-for-feel-breeze_p2-3)
        :effect (and (not (K_need-post-for-feel-breeze_p2-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p2-3)))
    (:action feel-breeze_p2-2__post__
        :precondition (K_need-post-for-feel-breeze_p2-2)
        :effect (and (not (K_need-post-for-feel-breeze_p2-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p2-2)))
    (:action feel-breeze_p2-1__post__
        :precondition (K_need-post-for-feel-breeze_p2-1)
        :effect (and (not (K_need-post-for-feel-breeze_p2-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p2-1)))
    (:action feel-breeze_p1-7__post__
        :precondition (K_need-post-for-feel-breeze_p1-7)
        :effect (and (not (K_need-post-for-feel-breeze_p1-7)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p1-7)))
    (:action feel-breeze_p1-6__post__
        :precondition (K_need-post-for-feel-breeze_p1-6)
        :effect (and (not (K_need-post-for-feel-breeze_p1-6)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p1-6)))
    (:action feel-breeze_p1-5__post__
        :precondition (K_need-post-for-feel-breeze_p1-5)
        :effect (and (not (K_need-post-for-feel-breeze_p1-5)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p1-5)))
    (:action feel-breeze_p1-4__post__
        :precondition (K_need-post-for-feel-breeze_p1-4)
        :effect (and (not (K_need-post-for-feel-breeze_p1-4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p1-4)))
    (:action feel-breeze_p1-3__post__
        :precondition (K_need-post-for-feel-breeze_p1-3)
        :effect (and (not (K_need-post-for-feel-breeze_p1-3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p1-3)))
    (:action feel-breeze_p1-2__post__
        :precondition (K_need-post-for-feel-breeze_p1-2)
        :effect (and (not (K_need-post-for-feel-breeze_p1-2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p1-2)))
    (:action feel-breeze_p1-1__post__
        :precondition (K_need-post-for-feel-breeze_p1-1)
        :effect (and (not (K_need-post-for-feel-breeze_p1-1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-feel-breeze_p1-1)))


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

    (:action sensor-feel-breeze_p7-7__sensor__-obs0-ver0
        :effect (when (and (not (K_not_breeze_p7-7)) (not (K_breeze_p7-7)) (K_need-post-for-feel-breeze_p7-7)) (K_breeze_p7-7)))
    (:action sensor-feel-breeze_p7-7__sensor__-obs0-ver1
        :effect (when (and (not (K_not_breeze_p7-7)) (not (K_breeze_p7-7)) (K_need-post-for-feel-breeze_p7-7)) (K_not_breeze_p7-7)))
    (:action sensor-feel-breeze_p7-5__sensor__-obs0-ver0
        :effect (when (and (not (K_not_breeze_p7-5)) (not (K_breeze_p7-5)) (K_need-post-for-feel-breeze_p7-5)) (K_breeze_p7-5)))
    (:action sensor-feel-breeze_p7-5__sensor__-obs0-ver1
        :effect (when (and (not (K_not_breeze_p7-5)) (not (K_breeze_p7-5)) (K_need-post-for-feel-breeze_p7-5)) (K_not_breeze_p7-5)))
    (:action sensor-feel-breeze_p6-6__sensor__-obs0-ver0
        :effect (when (and (not (K_not_breeze_p6-6)) (not (K_breeze_p6-6)) (K_need-post-for-feel-breeze_p6-6)) (K_breeze_p6-6)))
    (:action sensor-feel-breeze_p6-6__sensor__-obs0-ver1
        :effect (when (and (not (K_not_breeze_p6-6)) (not (K_breeze_p6-6)) (K_need-post-for-feel-breeze_p6-6)) (K_not_breeze_p6-6)))
    (:action sensor-feel-breeze_p6-4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_breeze_p6-4)) (not (K_breeze_p6-4)) (K_need-post-for-feel-breeze_p6-4)) (K_breeze_p6-4)))
    (:action sensor-feel-breeze_p6-4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_breeze_p6-4)) (not (K_breeze_p6-4)) (K_need-post-for-feel-breeze_p6-4)) (K_not_breeze_p6-4)))
    (:action sensor-feel-breeze_p5-7__sensor__-obs0-ver0
        :effect (when (and (not (K_not_breeze_p5-7)) (not (K_breeze_p5-7)) (K_need-post-for-feel-breeze_p5-7)) (K_breeze_p5-7)))
    (:action sensor-feel-breeze_p5-7__sensor__-obs0-ver1
        :effect (when (and (not (K_not_breeze_p5-7)) (not (K_breeze_p5-7)) (K_need-post-for-feel-breeze_p5-7)) (K_not_breeze_p5-7)))
    (:action sensor-feel-breeze_p5-5__sensor__-obs0-ver0
        :effect (when (and (not (K_not_breeze_p5-5)) (not (K_breeze_p5-5)) (K_need-post-for-feel-breeze_p5-5)) (K_breeze_p5-5)))
    (:action sensor-feel-breeze_p5-5__sensor__-obs0-ver1
        :effect (when (and (not (K_not_breeze_p5-5)) (not (K_breeze_p5-5)) (K_need-post-for-feel-breeze_p5-5)) (K_not_breeze_p5-5)))
    (:action sensor-feel-breeze_p5-3__sensor__-obs0-ver0
        :effect (when (and (not (K_not_breeze_p5-3)) (not (K_breeze_p5-3)) (K_need-post-for-feel-breeze_p5-3)) (K_breeze_p5-3)))
    (:action sensor-feel-breeze_p5-3__sensor__-obs0-ver1
        :effect (when (and (not (K_not_breeze_p5-3)) (not (K_breeze_p5-3)) (K_need-post-for-feel-breeze_p5-3)) (K_not_breeze_p5-3)))
    (:action sensor-feel-breeze_p4-6__sensor__-obs0-ver0
        :effect (when (and (not (K_not_breeze_p4-6)) (not (K_breeze_p4-6)) (K_need-post-for-feel-breeze_p4-6)) (K_breeze_p4-6)))
    (:action sensor-feel-breeze_p4-6__sensor__-obs0-ver1
        :effect (when (and (not (K_not_breeze_p4-6)) (not (K_breeze_p4-6)) (K_need-post-for-feel-breeze_p4-6)) (K_not_breeze_p4-6)))
    (:action sensor-feel-breeze_p4-4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_breeze_p4-4)) (not (K_breeze_p4-4)) (K_need-post-for-feel-breeze_p4-4)) (K_breeze_p4-4)))
    (:action sensor-feel-breeze_p4-4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_breeze_p4-4)) (not (K_breeze_p4-4)) (K_need-post-for-feel-breeze_p4-4)) (K_not_breeze_p4-4)))
    (:action sensor-feel-breeze_p4-2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_breeze_p4-2)) (not (K_breeze_p4-2)) (K_need-post-for-feel-breeze_p4-2)) (K_breeze_p4-2)))
    (:action sensor-feel-breeze_p4-2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_breeze_p4-2)) (not (K_breeze_p4-2)) (K_need-post-for-feel-breeze_p4-2)) (K_not_breeze_p4-2)))
    (:action sensor-feel-breeze_p3-5__sensor__-obs0-ver0
        :effect (when (and (not (K_not_breeze_p3-5)) (not (K_breeze_p3-5)) (K_need-post-for-feel-breeze_p3-5)) (K_breeze_p3-5)))
    (:action sensor-feel-breeze_p3-5__sensor__-obs0-ver1
        :effect (when (and (not (K_not_breeze_p3-5)) (not (K_breeze_p3-5)) (K_need-post-for-feel-breeze_p3-5)) (K_not_breeze_p3-5)))
    (:action sensor-feel-breeze_p3-3__sensor__-obs0-ver0
        :effect (when (and (not (K_not_breeze_p3-3)) (not (K_breeze_p3-3)) (K_need-post-for-feel-breeze_p3-3)) (K_breeze_p3-3)))
    (:action sensor-feel-breeze_p3-3__sensor__-obs0-ver1
        :effect (when (and (not (K_not_breeze_p3-3)) (not (K_breeze_p3-3)) (K_need-post-for-feel-breeze_p3-3)) (K_not_breeze_p3-3)))
    (:action sensor-feel-breeze_p3-1__sensor__-obs0-ver0
        :effect (when (and (not (K_not_breeze_p3-1)) (not (K_breeze_p3-1)) (K_need-post-for-feel-breeze_p3-1)) (K_breeze_p3-1)))
    (:action sensor-feel-breeze_p3-1__sensor__-obs0-ver1
        :effect (when (and (not (K_not_breeze_p3-1)) (not (K_breeze_p3-1)) (K_need-post-for-feel-breeze_p3-1)) (K_not_breeze_p3-1)))
    (:action sensor-feel-breeze_p2-4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_breeze_p2-4)) (not (K_breeze_p2-4)) (K_need-post-for-feel-breeze_p2-4)) (K_breeze_p2-4)))
    (:action sensor-feel-breeze_p2-4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_breeze_p2-4)) (not (K_breeze_p2-4)) (K_need-post-for-feel-breeze_p2-4)) (K_not_breeze_p2-4)))
    (:action sensor-feel-breeze_p2-2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_breeze_p2-2)) (not (K_breeze_p2-2)) (K_need-post-for-feel-breeze_p2-2)) (K_breeze_p2-2)))
    (:action sensor-feel-breeze_p2-2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_breeze_p2-2)) (not (K_breeze_p2-2)) (K_need-post-for-feel-breeze_p2-2)) (K_not_breeze_p2-2)))
    (:action sensor-feel-breeze_p1-3__sensor__-obs0-ver0
        :effect (when (and (not (K_not_breeze_p1-3)) (not (K_breeze_p1-3)) (K_need-post-for-feel-breeze_p1-3)) (K_breeze_p1-3)))
    (:action sensor-feel-breeze_p1-3__sensor__-obs0-ver1
        :effect (when (and (not (K_not_breeze_p1-3)) (not (K_breeze_p1-3)) (K_need-post-for-feel-breeze_p1-3)) (K_not_breeze_p1-3)))


    (:action invariant-90
        :effect (when (and (not (K_not_stench_p1-3)) (K_wumpus-at_p2-3)) (K_stench_p1-3)))
    (:action invariant-91
        :effect (when (and (not (K_wumpus-at_p2-3)) (K_not_stench_p1-3)) (K_not_wumpus-at_p2-3)))
    (:action invariant-92
        :effect (when (and (not (K_stench_p1-3)) (K_not_wumpus-at_p2-3)) (K_not_stench_p1-3)))
    (:action invariant-93
        :effect (when (and (not (K_not_wumpus-at_p2-3)) (K_stench_p1-3)) (K_wumpus-at_p2-3)))
    (:action invariant-94
        :effect (when (and (not (K_not_stench_p3-1)) (K_wumpus-at_p3-2)) (K_stench_p3-1)))
    (:action invariant-95
        :effect (when (and (not (K_wumpus-at_p3-2)) (K_not_stench_p3-1)) (K_not_wumpus-at_p3-2)))
    (:action invariant-96
        :effect (when (and (not (K_stench_p3-1)) (K_not_wumpus-at_p3-2)) (K_not_stench_p3-1)))
    (:action invariant-97
        :effect (when (and (not (K_not_wumpus-at_p3-2)) (K_stench_p3-1)) (K_wumpus-at_p3-2)))

    (:action invariant-98
        :effect (when (and (not (K_stench_p2-2)) (K_not_wumpus-at_p2-3) (K_not_wumpus-at_p3-2)) (K_not_stench_p2-2)))
    (:action invariant-99
        :effect (when (and (not (K_not_wumpus-at_p3-2)) (K_not_wumpus-at_p2-3) (K_stench_p2-2)) (K_wumpus-at_p3-2)))
    (:action invariant-100
        :effect (when (and (not (K_not_wumpus-at_p2-3)) (K_not_wumpus-at_p3-2) (K_stench_p2-2)) (K_wumpus-at_p2-3)))
    (:action invariant-101
        :effect (when (and (not (K_not_stench_p2-2)) (K_wumpus-at_p3-2)) (K_stench_p2-2)))
    (:action invariant-102
        :effect (when (and (not (K_wumpus-at_p3-2)) (K_not_stench_p2-2)) (K_not_wumpus-at_p3-2)))
    (:action invariant-103
        :effect (when (and (not (K_not_stench_p2-2)) (K_wumpus-at_p2-3)) (K_stench_p2-2)))
    (:action invariant-104
        :effect (when (and (not (K_wumpus-at_p2-3)) (K_not_stench_p2-2)) (K_not_wumpus-at_p2-3)))

    (:action invariant-105
        :effect (when (and (not (K_stench_p3-3)) (K_not_wumpus-at_p2-3) (K_not_wumpus-at_p3-2) (K_not_wumpus-at_p3-4) (K_not_wumpus-at_p4-3)) (K_not_stench_p3-3)))
    (:action invariant-106
        :effect (when (and (not (K_not_wumpus-at_p3-2)) (K_not_wumpus-at_p2-3) (K_not_wumpus-at_p3-4) (K_not_wumpus-at_p4-3) (K_stench_p3-3)) (K_wumpus-at_p3-2)))
    (:action invariant-107
        :effect (when (and (not (K_not_wumpus-at_p2-3)) (K_not_wumpus-at_p3-2) (K_not_wumpus-at_p3-4) (K_not_wumpus-at_p4-3) (K_stench_p3-3)) (K_wumpus-at_p2-3)))
    (:action invariant-108
        :effect (when (and (not (K_not_wumpus-at_p3-4)) (K_not_wumpus-at_p2-3) (K_not_wumpus-at_p3-2) (K_not_wumpus-at_p4-3) (K_stench_p3-3)) (K_wumpus-at_p3-4)))
    (:action invariant-109
        :effect (when (and (not (K_not_wumpus-at_p4-3)) (K_not_wumpus-at_p2-3) (K_not_wumpus-at_p3-2) (K_not_wumpus-at_p3-4) (K_stench_p3-3)) (K_wumpus-at_p4-3)))
    (:action invariant-110
        :effect (when (and (not (K_not_stench_p3-3)) (K_wumpus-at_p3-2)) (K_stench_p3-3)))
    (:action invariant-111
        :effect (when (and (not (K_wumpus-at_p3-2)) (K_not_stench_p3-3)) (K_not_wumpus-at_p3-2)))
    (:action invariant-112
        :effect (when (and (not (K_not_stench_p3-3)) (K_wumpus-at_p2-3)) (K_stench_p3-3)))
    (:action invariant-113
        :effect (when (and (not (K_wumpus-at_p2-3)) (K_not_stench_p3-3)) (K_not_wumpus-at_p2-3)))
    (:action invariant-114
        :effect (when (and (not (K_not_stench_p3-3)) (K_wumpus-at_p3-4)) (K_stench_p3-3)))
    (:action invariant-115
        :effect (when (and (not (K_wumpus-at_p3-4)) (K_not_stench_p3-3)) (K_not_wumpus-at_p3-4)))
    (:action invariant-116
        :effect (when (and (not (K_not_stench_p3-3)) (K_wumpus-at_p4-3)) (K_stench_p3-3)))
    (:action invariant-117
        :effect (when (and (not (K_wumpus-at_p4-3)) (K_not_stench_p3-3)) (K_not_wumpus-at_p4-3)))

    (:action invariant-118
        :effect (when (and (not (K_stench_p2-4)) (K_not_wumpus-at_p2-3) (K_not_wumpus-at_p3-4)) (K_not_stench_p2-4)))
    (:action invariant-119
        :effect (when (and (not (K_not_wumpus-at_p2-3)) (K_not_wumpus-at_p3-4) (K_stench_p2-4)) (K_wumpus-at_p2-3)))
    (:action invariant-120
        :effect (when (and (not (K_not_wumpus-at_p3-4)) (K_not_wumpus-at_p2-3) (K_stench_p2-4)) (K_wumpus-at_p3-4)))
    (:action invariant-121
        :effect (when (and (not (K_not_stench_p2-4)) (K_wumpus-at_p2-3)) (K_stench_p2-4)))
    (:action invariant-122
        :effect (when (and (not (K_wumpus-at_p2-3)) (K_not_stench_p2-4)) (K_not_wumpus-at_p2-3)))
    (:action invariant-123
        :effect (when (and (not (K_not_stench_p2-4)) (K_wumpus-at_p3-4)) (K_stench_p2-4)))
    (:action invariant-124
        :effect (when (and (not (K_wumpus-at_p3-4)) (K_not_stench_p2-4)) (K_not_wumpus-at_p3-4)))

    (:action invariant-125
        :effect (when (and (not (K_stench_p4-2)) (K_not_wumpus-at_p3-2) (K_not_wumpus-at_p4-3)) (K_not_stench_p4-2)))
    (:action invariant-126
        :effect (when (and (not (K_not_wumpus-at_p4-3)) (K_not_wumpus-at_p3-2) (K_stench_p4-2)) (K_wumpus-at_p4-3)))
    (:action invariant-127
        :effect (when (and (not (K_not_wumpus-at_p3-2)) (K_not_wumpus-at_p4-3) (K_stench_p4-2)) (K_wumpus-at_p3-2)))
    (:action invariant-128
        :effect (when (and (not (K_not_stench_p4-2)) (K_wumpus-at_p4-3)) (K_stench_p4-2)))
    (:action invariant-129
        :effect (when (and (not (K_wumpus-at_p4-3)) (K_not_stench_p4-2)) (K_not_wumpus-at_p4-3)))
    (:action invariant-130
        :effect (when (and (not (K_not_stench_p4-2)) (K_wumpus-at_p3-2)) (K_stench_p4-2)))
    (:action invariant-131
        :effect (when (and (not (K_wumpus-at_p3-2)) (K_not_stench_p4-2)) (K_not_wumpus-at_p3-2)))

    (:action invariant-132
        :effect (when (and (not (K_stench_p4-4)) (K_not_wumpus-at_p3-4) (K_not_wumpus-at_p4-3) (K_not_wumpus-at_p5-4) (K_not_wumpus-at_p4-5)) (K_not_stench_p4-4)))
    (:action invariant-133
        :effect (when (and (not (K_not_wumpus-at_p4-5)) (K_not_wumpus-at_p3-4) (K_not_wumpus-at_p4-3) (K_not_wumpus-at_p5-4) (K_stench_p4-4)) (K_wumpus-at_p4-5)))
    (:action invariant-134
        :effect (when (and (not (K_not_wumpus-at_p5-4)) (K_not_wumpus-at_p3-4) (K_not_wumpus-at_p4-3) (K_not_wumpus-at_p4-5) (K_stench_p4-4)) (K_wumpus-at_p5-4)))
    (:action invariant-135
        :effect (when (and (not (K_not_wumpus-at_p3-4)) (K_not_wumpus-at_p4-3) (K_not_wumpus-at_p5-4) (K_not_wumpus-at_p4-5) (K_stench_p4-4)) (K_wumpus-at_p3-4)))
    (:action invariant-136
        :effect (when (and (not (K_not_wumpus-at_p4-3)) (K_not_wumpus-at_p3-4) (K_not_wumpus-at_p5-4) (K_not_wumpus-at_p4-5) (K_stench_p4-4)) (K_wumpus-at_p4-3)))
    (:action invariant-137
        :effect (when (and (not (K_not_stench_p4-4)) (K_wumpus-at_p4-5)) (K_stench_p4-4)))
    (:action invariant-138
        :effect (when (and (not (K_wumpus-at_p4-5)) (K_not_stench_p4-4)) (K_not_wumpus-at_p4-5)))
    (:action invariant-139
        :effect (when (and (not (K_not_stench_p4-4)) (K_wumpus-at_p5-4)) (K_stench_p4-4)))
    (:action invariant-140
        :effect (when (and (not (K_wumpus-at_p5-4)) (K_not_stench_p4-4)) (K_not_wumpus-at_p5-4)))
    (:action invariant-141
        :effect (when (and (not (K_not_stench_p4-4)) (K_wumpus-at_p3-4)) (K_stench_p4-4)))
    (:action invariant-142
        :effect (when (and (not (K_wumpus-at_p3-4)) (K_not_stench_p4-4)) (K_not_wumpus-at_p3-4)))
    (:action invariant-143
        :effect (when (and (not (K_not_stench_p4-4)) (K_wumpus-at_p4-3)) (K_stench_p4-4)))
    (:action invariant-144
        :effect (when (and (not (K_wumpus-at_p4-3)) (K_not_stench_p4-4)) (K_not_wumpus-at_p4-3)))

    (:action invariant-145
        :effect (when (and (not (K_stench_p3-5)) (K_not_wumpus-at_p3-4) (K_not_wumpus-at_p4-5)) (K_not_stench_p3-5)))
    (:action invariant-146
        :effect (when (and (not (K_not_wumpus-at_p4-5)) (K_not_wumpus-at_p3-4) (K_stench_p3-5)) (K_wumpus-at_p4-5)))
    (:action invariant-147
        :effect (when (and (not (K_not_wumpus-at_p3-4)) (K_not_wumpus-at_p4-5) (K_stench_p3-5)) (K_wumpus-at_p3-4)))
    (:action invariant-148
        :effect (when (and (not (K_not_stench_p3-5)) (K_wumpus-at_p4-5)) (K_stench_p3-5)))
    (:action invariant-149
        :effect (when (and (not (K_wumpus-at_p4-5)) (K_not_stench_p3-5)) (K_not_wumpus-at_p4-5)))
    (:action invariant-150
        :effect (when (and (not (K_not_stench_p3-5)) (K_wumpus-at_p3-4)) (K_stench_p3-5)))
    (:action invariant-151
        :effect (when (and (not (K_wumpus-at_p3-4)) (K_not_stench_p3-5)) (K_not_wumpus-at_p3-4)))

    (:action invariant-152
        :effect (when (and (not (K_stench_p5-3)) (K_not_wumpus-at_p4-3) (K_not_wumpus-at_p5-4)) (K_not_stench_p5-3)))
    (:action invariant-153
        :effect (when (and (not (K_not_wumpus-at_p4-3)) (K_not_wumpus-at_p5-4) (K_stench_p5-3)) (K_wumpus-at_p4-3)))
    (:action invariant-154
        :effect (when (and (not (K_not_wumpus-at_p5-4)) (K_not_wumpus-at_p4-3) (K_stench_p5-3)) (K_wumpus-at_p5-4)))
    (:action invariant-155
        :effect (when (and (not (K_not_stench_p5-3)) (K_wumpus-at_p4-3)) (K_stench_p5-3)))
    (:action invariant-156
        :effect (when (and (not (K_wumpus-at_p4-3)) (K_not_stench_p5-3)) (K_not_wumpus-at_p4-3)))
    (:action invariant-157
        :effect (when (and (not (K_not_stench_p5-3)) (K_wumpus-at_p5-4)) (K_stench_p5-3)))
    (:action invariant-158
        :effect (when (and (not (K_wumpus-at_p5-4)) (K_not_stench_p5-3)) (K_not_wumpus-at_p5-4)))

    (:action invariant-159
        :effect (when (and (not (K_stench_p5-5)) (K_not_wumpus-at_p5-4) (K_not_wumpus-at_p4-5) (K_not_wumpus-at_p6-5) (K_not_wumpus-at_p5-6)) (K_not_stench_p5-5)))
    (:action invariant-160
        :effect (when (and (not (K_not_wumpus-at_p4-5)) (K_not_wumpus-at_p5-4) (K_not_wumpus-at_p6-5) (K_not_wumpus-at_p5-6) (K_stench_p5-5)) (K_wumpus-at_p4-5)))
    (:action invariant-161
        :effect (when (and (not (K_not_wumpus-at_p5-4)) (K_not_wumpus-at_p4-5) (K_not_wumpus-at_p6-5) (K_not_wumpus-at_p5-6) (K_stench_p5-5)) (K_wumpus-at_p5-4)))
    (:action invariant-162
        :effect (when (and (not (K_not_wumpus-at_p5-6)) (K_not_wumpus-at_p5-4) (K_not_wumpus-at_p4-5) (K_not_wumpus-at_p6-5) (K_stench_p5-5)) (K_wumpus-at_p5-6)))
    (:action invariant-163
        :effect (when (and (not (K_not_wumpus-at_p6-5)) (K_not_wumpus-at_p5-4) (K_not_wumpus-at_p4-5) (K_not_wumpus-at_p5-6) (K_stench_p5-5)) (K_wumpus-at_p6-5)))
    (:action invariant-164
        :effect (when (and (not (K_not_stench_p5-5)) (K_wumpus-at_p4-5)) (K_stench_p5-5)))
    (:action invariant-165
        :effect (when (and (not (K_wumpus-at_p4-5)) (K_not_stench_p5-5)) (K_not_wumpus-at_p4-5)))
    (:action invariant-166
        :effect (when (and (not (K_not_stench_p5-5)) (K_wumpus-at_p5-4)) (K_stench_p5-5)))
    (:action invariant-167
        :effect (when (and (not (K_wumpus-at_p5-4)) (K_not_stench_p5-5)) (K_not_wumpus-at_p5-4)))
    (:action invariant-168
        :effect (when (and (not (K_not_stench_p5-5)) (K_wumpus-at_p6-5)) (K_stench_p5-5)))
    (:action invariant-169
        :effect (when (and (not (K_wumpus-at_p6-5)) (K_not_stench_p5-5)) (K_not_wumpus-at_p6-5)))
    (:action invariant-170
        :effect (when (and (not (K_not_stench_p5-5)) (K_wumpus-at_p5-6)) (K_stench_p5-5)))
    (:action invariant-171
        :effect (when (and (not (K_wumpus-at_p5-6)) (K_not_stench_p5-5)) (K_not_wumpus-at_p5-6)))

    (:action invariant-172
        :effect (when (and (not (K_stench_p4-6)) (K_not_wumpus-at_p4-5) (K_not_wumpus-at_p5-6)) (K_not_stench_p4-6)))
    (:action invariant-173
        :effect (when (and (not (K_not_wumpus-at_p5-6)) (K_not_wumpus-at_p4-5) (K_stench_p4-6)) (K_wumpus-at_p5-6)))
    (:action invariant-174
        :effect (when (and (not (K_not_wumpus-at_p4-5)) (K_not_wumpus-at_p5-6) (K_stench_p4-6)) (K_wumpus-at_p4-5)))
    (:action invariant-175
        :effect (when (and (not (K_not_stench_p4-6)) (K_wumpus-at_p5-6)) (K_stench_p4-6)))
    (:action invariant-176
        :effect (when (and (not (K_wumpus-at_p5-6)) (K_not_stench_p4-6)) (K_not_wumpus-at_p5-6)))
    (:action invariant-177
        :effect (when (and (not (K_not_stench_p4-6)) (K_wumpus-at_p4-5)) (K_stench_p4-6)))
    (:action invariant-178
        :effect (when (and (not (K_wumpus-at_p4-5)) (K_not_stench_p4-6)) (K_not_wumpus-at_p4-5)))

    (:action invariant-179
        :effect (when (and (not (K_stench_p6-4)) (K_not_wumpus-at_p5-4) (K_not_wumpus-at_p6-5)) (K_not_stench_p6-4)))
    (:action invariant-180
        :effect (when (and (not (K_not_wumpus-at_p6-5)) (K_not_wumpus-at_p5-4) (K_stench_p6-4)) (K_wumpus-at_p6-5)))
    (:action invariant-181
        :effect (when (and (not (K_not_wumpus-at_p5-4)) (K_not_wumpus-at_p6-5) (K_stench_p6-4)) (K_wumpus-at_p5-4)))
    (:action invariant-182
        :effect (when (and (not (K_not_stench_p6-4)) (K_wumpus-at_p5-4)) (K_stench_p6-4)))
    (:action invariant-183
        :effect (when (and (not (K_wumpus-at_p5-4)) (K_not_stench_p6-4)) (K_not_wumpus-at_p5-4)))
    (:action invariant-184
        :effect (when (and (not (K_not_stench_p6-4)) (K_wumpus-at_p6-5)) (K_stench_p6-4)))
    (:action invariant-185
        :effect (when (and (not (K_wumpus-at_p6-5)) (K_not_stench_p6-4)) (K_not_wumpus-at_p6-5)))

    (:action invariant-186
        :effect (when (and (not (K_stench_p6-6)) (K_not_wumpus-at_p6-5) (K_not_wumpus-at_p5-6) (K_not_wumpus-at_p6-7) (K_not_wumpus-at_p7-6)) (K_not_stench_p6-6)))
    (:action invariant-187
        :effect (when (and (not (K_not_wumpus-at_p5-6)) (K_not_wumpus-at_p6-5) (K_not_wumpus-at_p6-7) (K_not_wumpus-at_p7-6) (K_stench_p6-6)) (K_wumpus-at_p5-6)))
    (:action invariant-188
        :effect (when (and (not (K_not_wumpus-at_p6-5)) (K_not_wumpus-at_p5-6) (K_not_wumpus-at_p6-7) (K_not_wumpus-at_p7-6) (K_stench_p6-6)) (K_wumpus-at_p6-5)))
    (:action invariant-189
        :effect (when (and (not (K_not_wumpus-at_p6-7)) (K_not_wumpus-at_p6-5) (K_not_wumpus-at_p5-6) (K_not_wumpus-at_p7-6) (K_stench_p6-6)) (K_wumpus-at_p6-7)))
    (:action invariant-190
        :effect (when (and (not (K_not_wumpus-at_p7-6)) (K_not_wumpus-at_p6-5) (K_not_wumpus-at_p5-6) (K_not_wumpus-at_p6-7) (K_stench_p6-6)) (K_wumpus-at_p7-6)))
    (:action invariant-191
        :effect (when (and (not (K_not_stench_p6-6)) (K_wumpus-at_p5-6)) (K_stench_p6-6)))
    (:action invariant-192
        :effect (when (and (not (K_wumpus-at_p5-6)) (K_not_stench_p6-6)) (K_not_wumpus-at_p5-6)))
    (:action invariant-193
        :effect (when (and (not (K_not_stench_p6-6)) (K_wumpus-at_p6-5)) (K_stench_p6-6)))
    (:action invariant-194
        :effect (when (and (not (K_wumpus-at_p6-5)) (K_not_stench_p6-6)) (K_not_wumpus-at_p6-5)))
    (:action invariant-195
        :effect (when (and (not (K_not_stench_p6-6)) (K_wumpus-at_p6-7)) (K_stench_p6-6)))
    (:action invariant-196
        :effect (when (and (not (K_wumpus-at_p6-7)) (K_not_stench_p6-6)) (K_not_wumpus-at_p6-7)))
    (:action invariant-197
        :effect (when (and (not (K_not_stench_p6-6)) (K_wumpus-at_p7-6)) (K_stench_p6-6)))
    (:action invariant-198
        :effect (when (and (not (K_wumpus-at_p7-6)) (K_not_stench_p6-6)) (K_not_wumpus-at_p7-6)))

    (:action invariant-199
        :effect (when (and (not (K_stench_p5-7)) (K_not_wumpus-at_p5-6) (K_not_wumpus-at_p6-7)) (K_not_stench_p5-7)))
    (:action invariant-200
        :effect (when (and (not (K_not_wumpus-at_p5-6)) (K_not_wumpus-at_p6-7) (K_stench_p5-7)) (K_wumpus-at_p5-6)))
    (:action invariant-201
        :effect (when (and (not (K_not_wumpus-at_p6-7)) (K_not_wumpus-at_p5-6) (K_stench_p5-7)) (K_wumpus-at_p6-7)))
    (:action invariant-202
        :effect (when (and (not (K_not_stench_p5-7)) (K_wumpus-at_p5-6)) (K_stench_p5-7)))
    (:action invariant-203
        :effect (when (and (not (K_wumpus-at_p5-6)) (K_not_stench_p5-7)) (K_not_wumpus-at_p5-6)))
    (:action invariant-204
        :effect (when (and (not (K_not_stench_p5-7)) (K_wumpus-at_p6-7)) (K_stench_p5-7)))
    (:action invariant-205
        :effect (when (and (not (K_wumpus-at_p6-7)) (K_not_stench_p5-7)) (K_not_wumpus-at_p6-7)))

    (:action invariant-206
        :effect (when (and (not (K_stench_p7-5)) (K_not_wumpus-at_p6-5) (K_not_wumpus-at_p7-6)) (K_not_stench_p7-5)))
    (:action invariant-207
        :effect (when (and (not (K_not_wumpus-at_p7-6)) (K_not_wumpus-at_p6-5) (K_stench_p7-5)) (K_wumpus-at_p7-6)))
    (:action invariant-208
        :effect (when (and (not (K_not_wumpus-at_p6-5)) (K_not_wumpus-at_p7-6) (K_stench_p7-5)) (K_wumpus-at_p6-5)))
    (:action invariant-209
        :effect (when (and (not (K_not_stench_p7-5)) (K_wumpus-at_p6-5)) (K_stench_p7-5)))
    (:action invariant-210
        :effect (when (and (not (K_wumpus-at_p6-5)) (K_not_stench_p7-5)) (K_not_wumpus-at_p6-5)))
    (:action invariant-211
        :effect (when (and (not (K_not_stench_p7-5)) (K_wumpus-at_p7-6)) (K_stench_p7-5)))
    (:action invariant-212
        :effect (when (and (not (K_wumpus-at_p7-6)) (K_not_stench_p7-5)) (K_not_wumpus-at_p7-6)))

    (:action invariant-213
        :effect (when (and (not (K_stench_p7-7)) (K_not_wumpus-at_p6-7) (K_not_wumpus-at_p7-6)) (K_not_stench_p7-7)))
    (:action invariant-214
        :effect (when (and (not (K_not_wumpus-at_p6-7)) (K_not_wumpus-at_p7-6) (K_stench_p7-7)) (K_wumpus-at_p6-7)))
    (:action invariant-215
        :effect (when (and (not (K_not_wumpus-at_p7-6)) (K_not_wumpus-at_p6-7) (K_stench_p7-7)) (K_wumpus-at_p7-6)))
    (:action invariant-216
        :effect (when (and (not (K_not_stench_p7-7)) (K_wumpus-at_p6-7)) (K_stench_p7-7)))
    (:action invariant-217
        :effect (when (and (not (K_wumpus-at_p6-7)) (K_not_stench_p7-7)) (K_not_wumpus-at_p6-7)))
    (:action invariant-218
        :effect (when (and (not (K_not_stench_p7-7)) (K_wumpus-at_p7-6)) (K_stench_p7-7)))
    (:action invariant-219
        :effect (when (and (not (K_wumpus-at_p7-6)) (K_not_stench_p7-7)) (K_not_wumpus-at_p7-6)))






    (:action invariant-0
        :effect (when (and (not (K_safe_p2-3)) (K_safe_p3-2)) (K_not_safe_p2-3)))
    (:action invariant-1
        :effect (when (and (not (K_safe_p3-2)) (K_safe_p2-3)) (K_not_safe_p3-2)))
    (:action invariant-2
        :effect (when (and (not (K_not_safe_p2-3)) (K_not_safe_p3-2)) (K_safe_p2-3)))
    (:action invariant-3
        :effect (when (and (not (K_not_safe_p3-2)) (K_not_safe_p2-3)) (K_safe_p3-2)))
    (:action invariant-4
        :effect (when (and (not (K_safe_p3-4)) (K_safe_p4-3)) (K_not_safe_p3-4)))
    (:action invariant-5
        :effect (when (and (not (K_safe_p4-3)) (K_safe_p3-4)) (K_not_safe_p4-3)))
    (:action invariant-6
        :effect (when (and (not (K_not_safe_p3-4)) (K_not_safe_p4-3)) (K_safe_p3-4)))
    (:action invariant-7
        :effect (when (and (not (K_not_safe_p4-3)) (K_not_safe_p3-4)) (K_safe_p4-3)))
    (:action invariant-8
        :effect (when (and (not (K_safe_p5-4)) (K_safe_p4-5)) (K_not_safe_p5-4)))
    (:action invariant-9
        :effect (when (and (not (K_safe_p4-5)) (K_safe_p5-4)) (K_not_safe_p4-5)))
    (:action invariant-10
        :effect (when (and (not (K_not_safe_p5-4)) (K_not_safe_p4-5)) (K_safe_p5-4)))
    (:action invariant-11
        :effect (when (and (not (K_not_safe_p4-5)) (K_not_safe_p5-4)) (K_safe_p4-5)))
    (:action invariant-12
        :effect (when (and (not (K_safe_p6-5)) (K_safe_p5-6)) (K_not_safe_p6-5)))
    (:action invariant-13
        :effect (when (and (not (K_safe_p5-6)) (K_safe_p6-5)) (K_not_safe_p5-6)))
    (:action invariant-14
        :effect (when (and (not (K_not_safe_p6-5)) (K_not_safe_p5-6)) (K_safe_p6-5)))
    (:action invariant-15
        :effect (when (and (not (K_not_safe_p5-6)) (K_not_safe_p6-5)) (K_safe_p5-6)))
    (:action invariant-16
        :effect (when (and (not (K_safe_p6-7)) (K_safe_p7-6)) (K_not_safe_p6-7)))
    (:action invariant-17
        :effect (when (and (not (K_safe_p7-6)) (K_safe_p6-7)) (K_not_safe_p7-6)))
    (:action invariant-18
        :effect (when (and (not (K_not_safe_p6-7)) (K_not_safe_p7-6)) (K_safe_p6-7)))
    (:action invariant-19
        :effect (when (and (not (K_not_safe_p7-6)) (K_not_safe_p6-7)) (K_safe_p7-6)))
    (:action invariant-20
        :effect (when (and (not (K_safe_p2-3)) (K_wumpus-at_p2-3)) (K_not_safe_p2-3)))
    (:action invariant-21
        :effect (when (and (not (K_wumpus-at_p2-3)) (K_safe_p2-3)) (K_not_wumpus-at_p2-3)))
    (:action invariant-22
        :effect (when (and (not (K_safe_p2-3)) (K_pit-at_p2-3)) (K_not_safe_p2-3)))
    (:action invariant-23
        :effect (when (and (not (K_pit-at_p2-3)) (K_safe_p2-3)) (K_not_pit-at_p2-3)))
    (:action invariant-24
        :effect (when (and (not (K_not_safe_p2-3)) (K_not_wumpus-at_p2-3) (K_not_pit-at_p2-3)) (K_safe_p2-3)))
    (:action invariant-25
        :effect (when (and (not (K_not_wumpus-at_p2-3)) (K_not_safe_p2-3) (K_not_pit-at_p2-3)) (K_wumpus-at_p2-3)))
    (:action invariant-26
        :effect (when (and (not (K_not_pit-at_p2-3)) (K_not_safe_p2-3) (K_not_wumpus-at_p2-3)) (K_pit-at_p2-3)))
    (:action invariant-27
        :effect (when (and (not (K_safe_p3-2)) (K_wumpus-at_p3-2)) (K_not_safe_p3-2)))
    (:action invariant-28
        :effect (when (and (not (K_wumpus-at_p3-2)) (K_safe_p3-2)) (K_not_wumpus-at_p3-2)))
    (:action invariant-29
        :effect (when (and (not (K_safe_p3-2)) (K_pit-at_p3-2)) (K_not_safe_p3-2)))
    (:action invariant-30
        :effect (when (and (not (K_pit-at_p3-2)) (K_safe_p3-2)) (K_not_pit-at_p3-2)))
    (:action invariant-31
        :effect (when (and (not (K_not_safe_p3-2)) (K_not_wumpus-at_p3-2) (K_not_pit-at_p3-2)) (K_safe_p3-2)))
    (:action invariant-32
        :effect (when (and (not (K_not_wumpus-at_p3-2)) (K_not_safe_p3-2) (K_not_pit-at_p3-2)) (K_wumpus-at_p3-2)))
    (:action invariant-33
        :effect (when (and (not (K_not_pit-at_p3-2)) (K_not_safe_p3-2) (K_not_wumpus-at_p3-2)) (K_pit-at_p3-2)))
    (:action invariant-34
        :effect (when (and (not (K_safe_p3-4)) (K_wumpus-at_p3-4)) (K_not_safe_p3-4)))
    (:action invariant-35
        :effect (when (and (not (K_wumpus-at_p3-4)) (K_safe_p3-4)) (K_not_wumpus-at_p3-4)))
    (:action invariant-36
        :effect (when (and (not (K_safe_p3-4)) (K_pit-at_p3-4)) (K_not_safe_p3-4)))
    (:action invariant-37
        :effect (when (and (not (K_pit-at_p3-4)) (K_safe_p3-4)) (K_not_pit-at_p3-4)))
    (:action invariant-38
        :effect (when (and (not (K_not_safe_p3-4)) (K_not_wumpus-at_p3-4) (K_not_pit-at_p3-4)) (K_safe_p3-4)))
    (:action invariant-39
        :effect (when (and (not (K_not_wumpus-at_p3-4)) (K_not_safe_p3-4) (K_not_pit-at_p3-4)) (K_wumpus-at_p3-4)))
    (:action invariant-40
        :effect (when (and (not (K_not_pit-at_p3-4)) (K_not_safe_p3-4) (K_not_wumpus-at_p3-4)) (K_pit-at_p3-4)))
    (:action invariant-41
        :effect (when (and (not (K_safe_p4-3)) (K_wumpus-at_p4-3)) (K_not_safe_p4-3)))
    (:action invariant-42
        :effect (when (and (not (K_wumpus-at_p4-3)) (K_safe_p4-3)) (K_not_wumpus-at_p4-3)))
    (:action invariant-43
        :effect (when (and (not (K_safe_p4-3)) (K_pit-at_p4-3)) (K_not_safe_p4-3)))
    (:action invariant-44
        :effect (when (and (not (K_pit-at_p4-3)) (K_safe_p4-3)) (K_not_pit-at_p4-3)))
    (:action invariant-45
        :effect (when (and (not (K_not_safe_p4-3)) (K_not_wumpus-at_p4-3) (K_not_pit-at_p4-3)) (K_safe_p4-3)))
    (:action invariant-46
        :effect (when (and (not (K_not_wumpus-at_p4-3)) (K_not_safe_p4-3) (K_not_pit-at_p4-3)) (K_wumpus-at_p4-3)))
    (:action invariant-47
        :effect (when (and (not (K_not_pit-at_p4-3)) (K_not_safe_p4-3) (K_not_wumpus-at_p4-3)) (K_pit-at_p4-3)))
    (:action invariant-48
        :effect (when (and (not (K_safe_p5-4)) (K_wumpus-at_p5-4)) (K_not_safe_p5-4)))
    (:action invariant-49
        :effect (when (and (not (K_wumpus-at_p5-4)) (K_safe_p5-4)) (K_not_wumpus-at_p5-4)))
    (:action invariant-50
        :effect (when (and (not (K_safe_p5-4)) (K_pit-at_p5-4)) (K_not_safe_p5-4)))
    (:action invariant-51
        :effect (when (and (not (K_pit-at_p5-4)) (K_safe_p5-4)) (K_not_pit-at_p5-4)))
    (:action invariant-52
        :effect (when (and (not (K_not_safe_p5-4)) (K_not_wumpus-at_p5-4) (K_not_pit-at_p5-4)) (K_safe_p5-4)))
    (:action invariant-53
        :effect (when (and (not (K_not_wumpus-at_p5-4)) (K_not_safe_p5-4) (K_not_pit-at_p5-4)) (K_wumpus-at_p5-4)))
    (:action invariant-54
        :effect (when (and (not (K_not_pit-at_p5-4)) (K_not_safe_p5-4) (K_not_wumpus-at_p5-4)) (K_pit-at_p5-4)))
    (:action invariant-55
        :effect (when (and (not (K_safe_p4-5)) (K_wumpus-at_p4-5)) (K_not_safe_p4-5)))
    (:action invariant-56
        :effect (when (and (not (K_wumpus-at_p4-5)) (K_safe_p4-5)) (K_not_wumpus-at_p4-5)))
    (:action invariant-57
        :effect (when (and (not (K_safe_p4-5)) (K_pit-at_p4-5)) (K_not_safe_p4-5)))
    (:action invariant-58
        :effect (when (and (not (K_pit-at_p4-5)) (K_safe_p4-5)) (K_not_pit-at_p4-5)))
    (:action invariant-59
        :effect (when (and (not (K_not_safe_p4-5)) (K_not_wumpus-at_p4-5) (K_not_pit-at_p4-5)) (K_safe_p4-5)))
    (:action invariant-60
        :effect (when (and (not (K_not_wumpus-at_p4-5)) (K_not_safe_p4-5) (K_not_pit-at_p4-5)) (K_wumpus-at_p4-5)))
    (:action invariant-61
        :effect (when (and (not (K_not_pit-at_p4-5)) (K_not_safe_p4-5) (K_not_wumpus-at_p4-5)) (K_pit-at_p4-5)))
    (:action invariant-62
        :effect (when (and (not (K_safe_p6-5)) (K_wumpus-at_p6-5)) (K_not_safe_p6-5)))
    (:action invariant-63
        :effect (when (and (not (K_wumpus-at_p6-5)) (K_safe_p6-5)) (K_not_wumpus-at_p6-5)))
    (:action invariant-64
        :effect (when (and (not (K_safe_p6-5)) (K_pit-at_p6-5)) (K_not_safe_p6-5)))
    (:action invariant-65
        :effect (when (and (not (K_pit-at_p6-5)) (K_safe_p6-5)) (K_not_pit-at_p6-5)))
    (:action invariant-66
        :effect (when (and (not (K_not_safe_p6-5)) (K_not_wumpus-at_p6-5) (K_not_pit-at_p6-5)) (K_safe_p6-5)))
    (:action invariant-67
        :effect (when (and (not (K_not_wumpus-at_p6-5)) (K_not_safe_p6-5) (K_not_pit-at_p6-5)) (K_wumpus-at_p6-5)))
    (:action invariant-68
        :effect (when (and (not (K_not_pit-at_p6-5)) (K_not_safe_p6-5) (K_not_wumpus-at_p6-5)) (K_pit-at_p6-5)))
    (:action invariant-69
        :effect (when (and (not (K_safe_p5-6)) (K_wumpus-at_p5-6)) (K_not_safe_p5-6)))
    (:action invariant-70
        :effect (when (and (not (K_wumpus-at_p5-6)) (K_safe_p5-6)) (K_not_wumpus-at_p5-6)))
    (:action invariant-71
        :effect (when (and (not (K_safe_p5-6)) (K_pit-at_p5-6)) (K_not_safe_p5-6)))
    (:action invariant-72
        :effect (when (and (not (K_pit-at_p5-6)) (K_safe_p5-6)) (K_not_pit-at_p5-6)))
    (:action invariant-73
        :effect (when (and (not (K_not_safe_p5-6)) (K_not_wumpus-at_p5-6) (K_not_pit-at_p5-6)) (K_safe_p5-6)))
    (:action invariant-74
        :effect (when (and (not (K_not_wumpus-at_p5-6)) (K_not_safe_p5-6) (K_not_pit-at_p5-6)) (K_wumpus-at_p5-6)))
    (:action invariant-75
        :effect (when (and (not (K_not_pit-at_p5-6)) (K_not_safe_p5-6) (K_not_wumpus-at_p5-6)) (K_pit-at_p5-6)))
    (:action invariant-76
        :effect (when (and (not (K_safe_p6-7)) (K_wumpus-at_p6-7)) (K_not_safe_p6-7)))
    (:action invariant-77
        :effect (when (and (not (K_wumpus-at_p6-7)) (K_safe_p6-7)) (K_not_wumpus-at_p6-7)))
    (:action invariant-78
        :effect (when (and (not (K_safe_p6-7)) (K_pit-at_p6-7)) (K_not_safe_p6-7)))
    (:action invariant-79
        :effect (when (and (not (K_pit-at_p6-7)) (K_safe_p6-7)) (K_not_pit-at_p6-7)))
    (:action invariant-80
        :effect (when (and (not (K_not_safe_p6-7)) (K_not_wumpus-at_p6-7) (K_not_pit-at_p6-7)) (K_safe_p6-7)))
    (:action invariant-81
        :effect (when (and (not (K_not_wumpus-at_p6-7)) (K_not_safe_p6-7) (K_not_pit-at_p6-7)) (K_wumpus-at_p6-7)))
    (:action invariant-82
        :effect (when (and (not (K_not_pit-at_p6-7)) (K_not_safe_p6-7) (K_not_wumpus-at_p6-7)) (K_pit-at_p6-7)))
    (:action invariant-83
        :effect (when (and (not (K_safe_p7-6)) (K_wumpus-at_p7-6)) (K_not_safe_p7-6)))
    (:action invariant-84
        :effect (when (and (not (K_wumpus-at_p7-6)) (K_safe_p7-6)) (K_not_wumpus-at_p7-6)))
    (:action invariant-85
        :effect (when (and (not (K_safe_p7-6)) (K_pit-at_p7-6)) (K_not_safe_p7-6)))
    (:action invariant-86
        :effect (when (and (not (K_pit-at_p7-6)) (K_safe_p7-6)) (K_not_pit-at_p7-6)))
    (:action invariant-87
        :effect (when (and (not (K_not_safe_p7-6)) (K_not_wumpus-at_p7-6) (K_not_pit-at_p7-6)) (K_safe_p7-6)))
    (:action invariant-88
        :effect (when (and (not (K_not_wumpus-at_p7-6)) (K_not_safe_p7-6) (K_not_pit-at_p7-6)) (K_wumpus-at_p7-6)))
    (:action invariant-89
        :effect (when (and (not (K_not_pit-at_p7-6)) (K_not_safe_p7-6) (K_not_wumpus-at_p7-6)) (K_pit-at_p7-6)))



    (:action invariant-220
        :effect (when (and (not (K_not_breeze_p1-3)) (K_pit-at_p2-3)) (K_breeze_p1-3)))
    (:action invariant-221
        :effect (when (and (not (K_pit-at_p2-3)) (K_not_breeze_p1-3)) (K_not_pit-at_p2-3)))
    (:action invariant-222
        :effect (when (and (not (K_breeze_p1-3)) (K_not_pit-at_p2-3)) (K_not_breeze_p1-3)))
    (:action invariant-223
        :effect (when (and (not (K_not_pit-at_p2-3)) (K_breeze_p1-3)) (K_pit-at_p2-3)))
    (:action invariant-224
        :effect (when (and (not (K_not_breeze_p3-1)) (K_pit-at_p3-2)) (K_breeze_p3-1)))
    (:action invariant-225
        :effect (when (and (not (K_pit-at_p3-2)) (K_not_breeze_p3-1)) (K_not_pit-at_p3-2)))
    (:action invariant-226
        :effect (when (and (not (K_breeze_p3-1)) (K_not_pit-at_p3-2)) (K_not_breeze_p3-1)))
    (:action invariant-227
        :effect (when (and (not (K_not_pit-at_p3-2)) (K_breeze_p3-1)) (K_pit-at_p3-2)))
    (:action invariant-228
        :effect (when (and (not (K_breeze_p2-2)) (K_not_pit-at_p2-3) (K_not_pit-at_p3-2)) (K_not_breeze_p2-2)))
    (:action invariant-229
        :effect (when (and (not (K_not_pit-at_p3-2)) (K_not_pit-at_p2-3) (K_breeze_p2-2)) (K_pit-at_p3-2)))
    (:action invariant-230
        :effect (when (and (not (K_not_pit-at_p2-3)) (K_not_pit-at_p3-2) (K_breeze_p2-2)) (K_pit-at_p2-3)))
    (:action invariant-231
        :effect (when (and (not (K_not_breeze_p2-2)) (K_pit-at_p3-2)) (K_breeze_p2-2)))
    (:action invariant-232
        :effect (when (and (not (K_pit-at_p3-2)) (K_not_breeze_p2-2)) (K_not_pit-at_p3-2)))
    (:action invariant-233
        :effect (when (and (not (K_not_breeze_p2-2)) (K_pit-at_p2-3)) (K_breeze_p2-2)))
    (:action invariant-234
        :effect (when (and (not (K_pit-at_p2-3)) (K_not_breeze_p2-2)) (K_not_pit-at_p2-3)))
    (:action invariant-235
        :effect (when (and (not (K_breeze_p3-3)) (K_not_pit-at_p2-3) (K_not_pit-at_p3-2)) (K_not_breeze_p3-3)))
    (:action invariant-236
        :effect (when (and (not (K_not_pit-at_p3-2)) (K_not_pit-at_p2-3) (K_breeze_p3-3)) (K_pit-at_p3-2)))
    (:action invariant-237
        :effect (when (and (not (K_not_pit-at_p2-3)) (K_not_pit-at_p3-2) (K_breeze_p3-3)) (K_pit-at_p2-3)))
    (:action invariant-238
        :effect (when (and (not (K_not_breeze_p3-3)) (K_pit-at_p3-2)) (K_breeze_p3-3)))
    (:action invariant-239
        :effect (when (and (not (K_pit-at_p3-2)) (K_not_breeze_p3-3)) (K_not_pit-at_p3-2)))
    (:action invariant-240
        :effect (when (and (not (K_not_breeze_p3-3)) (K_pit-at_p2-3)) (K_breeze_p3-3)))
    (:action invariant-241
        :effect (when (and (not (K_pit-at_p2-3)) (K_not_breeze_p3-3)) (K_not_pit-at_p2-3)))
    (:action invariant-242
        :effect (when (and (not (K_breeze_p3-3)) (K_not_pit-at_p2-3) (K_not_pit-at_p3-2) (K_not_pit-at_p3-4) (K_not_pit-at_p4-3)) (K_not_breeze_p3-3)))
    (:action invariant-243
        :effect (when (and (not (K_not_pit-at_p3-2)) (K_not_pit-at_p2-3) (K_not_pit-at_p3-4) (K_not_pit-at_p4-3) (K_breeze_p3-3)) (K_pit-at_p3-2)))
    (:action invariant-244
        :effect (when (and (not (K_not_pit-at_p2-3)) (K_not_pit-at_p3-2) (K_not_pit-at_p3-4) (K_not_pit-at_p4-3) (K_breeze_p3-3)) (K_pit-at_p2-3)))
    (:action invariant-245
        :effect (when (and (not (K_not_pit-at_p3-4)) (K_not_pit-at_p2-3) (K_not_pit-at_p3-2) (K_not_pit-at_p4-3) (K_breeze_p3-3)) (K_pit-at_p3-4)))
    (:action invariant-246
        :effect (when (and (not (K_not_pit-at_p4-3)) (K_not_pit-at_p2-3) (K_not_pit-at_p3-2) (K_not_pit-at_p3-4) (K_breeze_p3-3)) (K_pit-at_p4-3)))
    (:action invariant-247
        :effect (when (and (not (K_not_breeze_p3-3)) (K_pit-at_p3-2)) (K_breeze_p3-3)))
    (:action invariant-248
        :effect (when (and (not (K_pit-at_p3-2)) (K_not_breeze_p3-3)) (K_not_pit-at_p3-2)))
    (:action invariant-249
        :effect (when (and (not (K_not_breeze_p3-3)) (K_pit-at_p2-3)) (K_breeze_p3-3)))
    (:action invariant-250
        :effect (when (and (not (K_pit-at_p2-3)) (K_not_breeze_p3-3)) (K_not_pit-at_p2-3)))
    (:action invariant-251
        :effect (when (and (not (K_not_breeze_p3-3)) (K_pit-at_p3-4)) (K_breeze_p3-3)))
    (:action invariant-252
        :effect (when (and (not (K_pit-at_p3-4)) (K_not_breeze_p3-3)) (K_not_pit-at_p3-4)))
    (:action invariant-253
        :effect (when (and (not (K_not_breeze_p3-3)) (K_pit-at_p4-3)) (K_breeze_p3-3)))
    (:action invariant-254
        :effect (when (and (not (K_pit-at_p4-3)) (K_not_breeze_p3-3)) (K_not_pit-at_p4-3)))
    (:action invariant-255
        :effect (when (and (not (K_breeze_p2-4)) (K_not_pit-at_p2-3) (K_not_pit-at_p3-4)) (K_not_breeze_p2-4)))
    (:action invariant-256
        :effect (when (and (not (K_not_pit-at_p2-3)) (K_not_pit-at_p3-4) (K_breeze_p2-4)) (K_pit-at_p2-3)))
    (:action invariant-257
        :effect (when (and (not (K_not_pit-at_p3-4)) (K_not_pit-at_p2-3) (K_breeze_p2-4)) (K_pit-at_p3-4)))
    (:action invariant-258
        :effect (when (and (not (K_not_breeze_p2-4)) (K_pit-at_p2-3)) (K_breeze_p2-4)))
    (:action invariant-259
        :effect (when (and (not (K_pit-at_p2-3)) (K_not_breeze_p2-4)) (K_not_pit-at_p2-3)))
    (:action invariant-260
        :effect (when (and (not (K_not_breeze_p2-4)) (K_pit-at_p3-4)) (K_breeze_p2-4)))
    (:action invariant-261
        :effect (when (and (not (K_pit-at_p3-4)) (K_not_breeze_p2-4)) (K_not_pit-at_p3-4)))
    (:action invariant-262
        :effect (when (and (not (K_breeze_p4-2)) (K_not_pit-at_p3-2) (K_not_pit-at_p4-3)) (K_not_breeze_p4-2)))
    (:action invariant-263
        :effect (when (and (not (K_not_pit-at_p4-3)) (K_not_pit-at_p3-2) (K_breeze_p4-2)) (K_pit-at_p4-3)))
    (:action invariant-264
        :effect (when (and (not (K_not_pit-at_p3-2)) (K_not_pit-at_p4-3) (K_breeze_p4-2)) (K_pit-at_p3-2)))
    (:action invariant-265
        :effect (when (and (not (K_not_breeze_p4-2)) (K_pit-at_p4-3)) (K_breeze_p4-2)))
    (:action invariant-266
        :effect (when (and (not (K_pit-at_p4-3)) (K_not_breeze_p4-2)) (K_not_pit-at_p4-3)))
    (:action invariant-267
        :effect (when (and (not (K_not_breeze_p4-2)) (K_pit-at_p3-2)) (K_breeze_p4-2)))
    (:action invariant-268
        :effect (when (and (not (K_pit-at_p3-2)) (K_not_breeze_p4-2)) (K_not_pit-at_p3-2)))
    (:action invariant-269
        :effect (when (and (not (K_breeze_p4-4)) (K_not_pit-at_p3-4) (K_not_pit-at_p4-3) (K_not_pit-at_p5-4) (K_not_pit-at_p4-5)) (K_not_breeze_p4-4)))
    (:action invariant-270
        :effect (when (and (not (K_not_pit-at_p4-5)) (K_not_pit-at_p3-4) (K_not_pit-at_p4-3) (K_not_pit-at_p5-4) (K_breeze_p4-4)) (K_pit-at_p4-5)))
    (:action invariant-271
        :effect (when (and (not (K_not_pit-at_p5-4)) (K_not_pit-at_p3-4) (K_not_pit-at_p4-3) (K_not_pit-at_p4-5) (K_breeze_p4-4)) (K_pit-at_p5-4)))
    (:action invariant-272
        :effect (when (and (not (K_not_pit-at_p3-4)) (K_not_pit-at_p4-3) (K_not_pit-at_p5-4) (K_not_pit-at_p4-5) (K_breeze_p4-4)) (K_pit-at_p3-4)))
    (:action invariant-273
        :effect (when (and (not (K_not_pit-at_p4-3)) (K_not_pit-at_p3-4) (K_not_pit-at_p5-4) (K_not_pit-at_p4-5) (K_breeze_p4-4)) (K_pit-at_p4-3)))
    (:action invariant-274
        :effect (when (and (not (K_not_breeze_p4-4)) (K_pit-at_p4-5)) (K_breeze_p4-4)))
    (:action invariant-275
        :effect (when (and (not (K_pit-at_p4-5)) (K_not_breeze_p4-4)) (K_not_pit-at_p4-5)))
    (:action invariant-276
        :effect (when (and (not (K_not_breeze_p4-4)) (K_pit-at_p5-4)) (K_breeze_p4-4)))
    (:action invariant-277
        :effect (when (and (not (K_pit-at_p5-4)) (K_not_breeze_p4-4)) (K_not_pit-at_p5-4)))
    (:action invariant-278
        :effect (when (and (not (K_not_breeze_p4-4)) (K_pit-at_p3-4)) (K_breeze_p4-4)))
    (:action invariant-279
        :effect (when (and (not (K_pit-at_p3-4)) (K_not_breeze_p4-4)) (K_not_pit-at_p3-4)))
    (:action invariant-280
        :effect (when (and (not (K_not_breeze_p4-4)) (K_pit-at_p4-3)) (K_breeze_p4-4)))
    (:action invariant-281
        :effect (when (and (not (K_pit-at_p4-3)) (K_not_breeze_p4-4)) (K_not_pit-at_p4-3)))
    (:action invariant-282
        :effect (when (and (not (K_breeze_p3-5)) (K_not_pit-at_p3-4) (K_not_pit-at_p4-5)) (K_not_breeze_p3-5)))
    (:action invariant-283
        :effect (when (and (not (K_not_pit-at_p4-5)) (K_not_pit-at_p3-4) (K_breeze_p3-5)) (K_pit-at_p4-5)))
    (:action invariant-284
        :effect (when (and (not (K_not_pit-at_p3-4)) (K_not_pit-at_p4-5) (K_breeze_p3-5)) (K_pit-at_p3-4)))
    (:action invariant-285
        :effect (when (and (not (K_not_breeze_p3-5)) (K_pit-at_p4-5)) (K_breeze_p3-5)))
    (:action invariant-286
        :effect (when (and (not (K_pit-at_p4-5)) (K_not_breeze_p3-5)) (K_not_pit-at_p4-5)))
    (:action invariant-287
        :effect (when (and (not (K_not_breeze_p3-5)) (K_pit-at_p3-4)) (K_breeze_p3-5)))
    (:action invariant-288
        :effect (when (and (not (K_pit-at_p3-4)) (K_not_breeze_p3-5)) (K_not_pit-at_p3-4)))
    (:action invariant-289
        :effect (when (and (not (K_breeze_p5-3)) (K_not_pit-at_p4-3) (K_not_pit-at_p5-4)) (K_not_breeze_p5-3)))
    (:action invariant-290
        :effect (when (and (not (K_not_pit-at_p4-3)) (K_not_pit-at_p5-4) (K_breeze_p5-3)) (K_pit-at_p4-3)))
    (:action invariant-291
        :effect (when (and (not (K_not_pit-at_p5-4)) (K_not_pit-at_p4-3) (K_breeze_p5-3)) (K_pit-at_p5-4)))
    (:action invariant-292
        :effect (when (and (not (K_not_breeze_p5-3)) (K_pit-at_p4-3)) (K_breeze_p5-3)))
    (:action invariant-293
        :effect (when (and (not (K_pit-at_p4-3)) (K_not_breeze_p5-3)) (K_not_pit-at_p4-3)))
    (:action invariant-294
        :effect (when (and (not (K_not_breeze_p5-3)) (K_pit-at_p5-4)) (K_breeze_p5-3)))
    (:action invariant-295
        :effect (when (and (not (K_pit-at_p5-4)) (K_not_breeze_p5-3)) (K_not_pit-at_p5-4)))
    (:action invariant-296
        :effect (when (and (not (K_breeze_p5-5)) (K_not_pit-at_p5-4) (K_not_pit-at_p4-5) (K_not_pit-at_p6-5) (K_not_pit-at_p5-6)) (K_not_breeze_p5-5)))
    (:action invariant-297
        :effect (when (and (not (K_not_pit-at_p4-5)) (K_not_pit-at_p5-4) (K_not_pit-at_p6-5) (K_not_pit-at_p5-6) (K_breeze_p5-5)) (K_pit-at_p4-5)))
    (:action invariant-298
        :effect (when (and (not (K_not_pit-at_p5-4)) (K_not_pit-at_p4-5) (K_not_pit-at_p6-5) (K_not_pit-at_p5-6) (K_breeze_p5-5)) (K_pit-at_p5-4)))
    (:action invariant-299
        :effect (when (and (not (K_not_pit-at_p5-6)) (K_not_pit-at_p5-4) (K_not_pit-at_p4-5) (K_not_pit-at_p6-5) (K_breeze_p5-5)) (K_pit-at_p5-6)))
    (:action invariant-300
        :effect (when (and (not (K_not_pit-at_p6-5)) (K_not_pit-at_p5-4) (K_not_pit-at_p4-5) (K_not_pit-at_p5-6) (K_breeze_p5-5)) (K_pit-at_p6-5)))
    (:action invariant-301
        :effect (when (and (not (K_not_breeze_p5-5)) (K_pit-at_p4-5)) (K_breeze_p5-5)))
    (:action invariant-302
        :effect (when (and (not (K_pit-at_p4-5)) (K_not_breeze_p5-5)) (K_not_pit-at_p4-5)))
    (:action invariant-303
        :effect (when (and (not (K_not_breeze_p5-5)) (K_pit-at_p5-4)) (K_breeze_p5-5)))
    (:action invariant-304
        :effect (when (and (not (K_pit-at_p5-4)) (K_not_breeze_p5-5)) (K_not_pit-at_p5-4)))
    (:action invariant-305
        :effect (when (and (not (K_not_breeze_p5-5)) (K_pit-at_p6-5)) (K_breeze_p5-5)))
    (:action invariant-306
        :effect (when (and (not (K_pit-at_p6-5)) (K_not_breeze_p5-5)) (K_not_pit-at_p6-5)))
    (:action invariant-307
        :effect (when (and (not (K_not_breeze_p5-5)) (K_pit-at_p5-6)) (K_breeze_p5-5)))
    (:action invariant-308
        :effect (when (and (not (K_pit-at_p5-6)) (K_not_breeze_p5-5)) (K_not_pit-at_p5-6)))
    (:action invariant-309
        :effect (when (and (not (K_breeze_p4-6)) (K_not_pit-at_p4-5) (K_not_pit-at_p5-6)) (K_not_breeze_p4-6)))
    (:action invariant-310
        :effect (when (and (not (K_not_pit-at_p5-6)) (K_not_pit-at_p4-5) (K_breeze_p4-6)) (K_pit-at_p5-6)))
    (:action invariant-311
        :effect (when (and (not (K_not_pit-at_p4-5)) (K_not_pit-at_p5-6) (K_breeze_p4-6)) (K_pit-at_p4-5)))
    (:action invariant-312
        :effect (when (and (not (K_not_breeze_p4-6)) (K_pit-at_p5-6)) (K_breeze_p4-6)))
    (:action invariant-313
        :effect (when (and (not (K_pit-at_p5-6)) (K_not_breeze_p4-6)) (K_not_pit-at_p5-6)))
    (:action invariant-314
        :effect (when (and (not (K_not_breeze_p4-6)) (K_pit-at_p4-5)) (K_breeze_p4-6)))
    (:action invariant-315
        :effect (when (and (not (K_pit-at_p4-5)) (K_not_breeze_p4-6)) (K_not_pit-at_p4-5)))
    (:action invariant-316
        :effect (when (and (not (K_breeze_p6-4)) (K_not_pit-at_p5-4) (K_not_pit-at_p6-5)) (K_not_breeze_p6-4)))
    (:action invariant-317
        :effect (when (and (not (K_not_pit-at_p6-5)) (K_not_pit-at_p5-4) (K_breeze_p6-4)) (K_pit-at_p6-5)))
    (:action invariant-318
        :effect (when (and (not (K_not_pit-at_p5-4)) (K_not_pit-at_p6-5) (K_breeze_p6-4)) (K_pit-at_p5-4)))
    (:action invariant-319
        :effect (when (and (not (K_not_breeze_p6-4)) (K_pit-at_p5-4)) (K_breeze_p6-4)))
    (:action invariant-320
        :effect (when (and (not (K_pit-at_p5-4)) (K_not_breeze_p6-4)) (K_not_pit-at_p5-4)))
    (:action invariant-321
        :effect (when (and (not (K_not_breeze_p6-4)) (K_pit-at_p6-5)) (K_breeze_p6-4)))
    (:action invariant-322
        :effect (when (and (not (K_pit-at_p6-5)) (K_not_breeze_p6-4)) (K_not_pit-at_p6-5)))
    (:action invariant-323
        :effect (when (and (not (K_breeze_p6-6)) (K_not_pit-at_p6-5) (K_not_pit-at_p5-6) (K_not_pit-at_p6-7) (K_not_pit-at_p7-6)) (K_not_breeze_p6-6)))
    (:action invariant-324
        :effect (when (and (not (K_not_pit-at_p5-6)) (K_not_pit-at_p6-5) (K_not_pit-at_p6-7) (K_not_pit-at_p7-6) (K_breeze_p6-6)) (K_pit-at_p5-6)))
    (:action invariant-325
        :effect (when (and (not (K_not_pit-at_p6-5)) (K_not_pit-at_p5-6) (K_not_pit-at_p6-7) (K_not_pit-at_p7-6) (K_breeze_p6-6)) (K_pit-at_p6-5)))
    (:action invariant-326
        :effect (when (and (not (K_not_pit-at_p6-7)) (K_not_pit-at_p6-5) (K_not_pit-at_p5-6) (K_not_pit-at_p7-6) (K_breeze_p6-6)) (K_pit-at_p6-7)))
    (:action invariant-327
        :effect (when (and (not (K_not_pit-at_p7-6)) (K_not_pit-at_p6-5) (K_not_pit-at_p5-6) (K_not_pit-at_p6-7) (K_breeze_p6-6)) (K_pit-at_p7-6)))
    (:action invariant-328
        :effect (when (and (not (K_not_breeze_p6-6)) (K_pit-at_p5-6)) (K_breeze_p6-6)))
    (:action invariant-329
        :effect (when (and (not (K_pit-at_p5-6)) (K_not_breeze_p6-6)) (K_not_pit-at_p5-6)))
    (:action invariant-330
        :effect (when (and (not (K_not_breeze_p6-6)) (K_pit-at_p6-5)) (K_breeze_p6-6)))
    (:action invariant-331
        :effect (when (and (not (K_pit-at_p6-5)) (K_not_breeze_p6-6)) (K_not_pit-at_p6-5)))
    (:action invariant-332
        :effect (when (and (not (K_not_breeze_p6-6)) (K_pit-at_p6-7)) (K_breeze_p6-6)))
    (:action invariant-333
        :effect (when (and (not (K_pit-at_p6-7)) (K_not_breeze_p6-6)) (K_not_pit-at_p6-7)))
    (:action invariant-334
        :effect (when (and (not (K_not_breeze_p6-6)) (K_pit-at_p7-6)) (K_breeze_p6-6)))
    (:action invariant-335
        :effect (when (and (not (K_pit-at_p7-6)) (K_not_breeze_p6-6)) (K_not_pit-at_p7-6)))
    (:action invariant-336
        :effect (when (and (not (K_breeze_p5-7)) (K_not_pit-at_p5-6) (K_not_pit-at_p6-7)) (K_not_breeze_p5-7)))
    (:action invariant-337
        :effect (when (and (not (K_not_pit-at_p5-6)) (K_not_pit-at_p6-7) (K_breeze_p5-7)) (K_pit-at_p5-6)))
    (:action invariant-338
        :effect (when (and (not (K_not_pit-at_p6-7)) (K_not_pit-at_p5-6) (K_breeze_p5-7)) (K_pit-at_p6-7)))
    (:action invariant-339
        :effect (when (and (not (K_not_breeze_p5-7)) (K_pit-at_p5-6)) (K_breeze_p5-7)))
    (:action invariant-340
        :effect (when (and (not (K_pit-at_p5-6)) (K_not_breeze_p5-7)) (K_not_pit-at_p5-6)))
    (:action invariant-341
        :effect (when (and (not (K_not_breeze_p5-7)) (K_pit-at_p6-7)) (K_breeze_p5-7)))
    (:action invariant-342
        :effect (when (and (not (K_pit-at_p6-7)) (K_not_breeze_p5-7)) (K_not_pit-at_p6-7)))
    (:action invariant-343
        :effect (when (and (not (K_breeze_p7-5)) (K_not_pit-at_p6-5) (K_not_pit-at_p7-6)) (K_not_breeze_p7-5)))
    (:action invariant-344
        :effect (when (and (not (K_not_pit-at_p7-6)) (K_not_pit-at_p6-5) (K_breeze_p7-5)) (K_pit-at_p7-6)))
    (:action invariant-345
        :effect (when (and (not (K_not_pit-at_p6-5)) (K_not_pit-at_p7-6) (K_breeze_p7-5)) (K_pit-at_p6-5)))
    (:action invariant-346
        :effect (when (and (not (K_not_breeze_p7-5)) (K_pit-at_p6-5)) (K_breeze_p7-5)))
    (:action invariant-347
        :effect (when (and (not (K_pit-at_p6-5)) (K_not_breeze_p7-5)) (K_not_pit-at_p6-5)))
    (:action invariant-348
        :effect (when (and (not (K_not_breeze_p7-5)) (K_pit-at_p7-6)) (K_breeze_p7-5)))
    (:action invariant-349
        :effect (when (and (not (K_pit-at_p7-6)) (K_not_breeze_p7-5)) (K_not_pit-at_p7-6)))
    (:action invariant-350
        :effect (when (and (not (K_breeze_p7-7)) (K_not_pit-at_p6-7) (K_not_pit-at_p7-6)) (K_not_breeze_p7-7)))
    (:action invariant-351
        :effect (when (and (not (K_not_pit-at_p6-7)) (K_not_pit-at_p7-6) (K_breeze_p7-7)) (K_pit-at_p6-7)))
    (:action invariant-352
        :effect (when (and (not (K_not_pit-at_p7-6)) (K_not_pit-at_p6-7) (K_breeze_p7-7)) (K_pit-at_p7-6)))
    (:action invariant-353
        :effect (when (and (not (K_not_breeze_p7-7)) (K_pit-at_p6-7)) (K_breeze_p7-7)))
    (:action invariant-354
        :effect (when (and (not (K_pit-at_p6-7)) (K_not_breeze_p7-7)) (K_not_pit-at_p6-7)))
    (:action invariant-355
        :effect (when (and (not (K_not_breeze_p7-7)) (K_pit-at_p7-6)) (K_breeze_p7-7)))
    (:action invariant-356
        :effect (when (and (not (K_pit-at_p7-6)) (K_not_breeze_p7-7)) (K_not_pit-at_p7-6)))
)
