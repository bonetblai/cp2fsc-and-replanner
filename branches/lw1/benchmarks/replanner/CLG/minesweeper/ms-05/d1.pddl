(define (domain mines-3x4)
    (:predicates
        (K_normal-execution)
        (K_not_normal-execution)
        (K_need-start)
        (K_not_need-start)
        (K_mine-at_p2_1)
        (K_not_mine-at_p2_1)
        (K_mine-at_p3_1)
        (K_not_mine-at_p3_1)
        (K_mine-at_p1_2)
        (K_not_mine-at_p1_2)
        (K_mine-at_p2_2)
        (K_not_mine-at_p2_2)
        (K_mine-at_p3_2)
        (K_not_mine-at_p3_2)
        (K_mine-at_p1_3)
        (K_not_mine-at_p1_3)
        (K_mine-at_p2_3)
        (K_not_mine-at_p2_3)
        (K_mine-at_p3_3)
        (K_not_mine-at_p3_3)
        (K_mine-at_p1_4)
        (K_not_mine-at_p1_4)
        (K_mine-at_p2_4)
        (K_not_mine-at_p2_4)
        (K_mine-at_p3_4)
        (K_not_mine-at_p3_4)
        (K_obs0-at_p1_1)
        (K_not_obs0-at_p1_1)
        (K_obs1-at_p1_1)
        (K_not_obs1-at_p1_1)
        (K_obs2-at_p1_1)
        (K_not_obs2-at_p1_1)
        (K_obs3-at_p1_1)
        (K_not_obs3-at_p1_1)
        (K_obs4-at_p1_1)
        (K_not_obs4-at_p1_1)
        (K_obs5-at_p1_1)
        (K_not_obs5-at_p1_1)
        (K_obs6-at_p1_1)
        (K_not_obs6-at_p1_1)
        (K_obs7-at_p1_1)
        (K_not_obs7-at_p1_1)
        (K_obs8-at_p1_1)
        (K_not_obs8-at_p1_1)
        (K_obs2-at_p2_2)
        (K_not_obs2-at_p2_2)
        (K_mine-at_p1_1)
        (K_not_mine-at_p1_1)
        (K_obs0-at_p2_2)
        (K_not_obs0-at_p2_2)
        (K_obs1-at_p2_2)
        (K_not_obs1-at_p2_2)
        (K_obs3-at_p2_2)
        (K_not_obs3-at_p2_2)
        (K_obs4-at_p2_2)
        (K_not_obs4-at_p2_2)
        (K_obs5-at_p2_2)
        (K_not_obs5-at_p2_2)
        (K_obs6-at_p2_2)
        (K_not_obs6-at_p2_2)
        (K_obs7-at_p2_2)
        (K_not_obs7-at_p2_2)
        (K_obs8-at_p2_2)
        (K_not_obs8-at_p2_2)
        (K_obs0-at_p2_1)
        (K_not_obs0-at_p2_1)
        (K_obs1-at_p2_1)
        (K_not_obs1-at_p2_1)
        (K_obs2-at_p2_1)
        (K_not_obs2-at_p2_1)
        (K_obs3-at_p2_1)
        (K_not_obs3-at_p2_1)
        (K_obs4-at_p2_1)
        (K_not_obs4-at_p2_1)
        (K_obs5-at_p2_1)
        (K_not_obs5-at_p2_1)
        (K_obs6-at_p2_1)
        (K_not_obs6-at_p2_1)
        (K_obs7-at_p2_1)
        (K_not_obs7-at_p2_1)
        (K_obs8-at_p2_1)
        (K_not_obs8-at_p2_1)
        (K_obs0-at_p3_2)
        (K_not_obs0-at_p3_2)
        (K_obs1-at_p3_2)
        (K_not_obs1-at_p3_2)
        (K_obs2-at_p3_2)
        (K_not_obs2-at_p3_2)
        (K_obs3-at_p3_2)
        (K_not_obs3-at_p3_2)
        (K_obs4-at_p3_2)
        (K_not_obs4-at_p3_2)
        (K_obs5-at_p3_2)
        (K_not_obs5-at_p3_2)
        (K_obs6-at_p3_2)
        (K_not_obs6-at_p3_2)
        (K_obs7-at_p3_2)
        (K_not_obs7-at_p3_2)
        (K_obs8-at_p3_2)
        (K_not_obs8-at_p3_2)
        (K_obs0-at_p3_1)
        (K_not_obs0-at_p3_1)
        (K_obs1-at_p3_1)
        (K_not_obs1-at_p3_1)
        (K_obs2-at_p3_1)
        (K_not_obs2-at_p3_1)
        (K_obs3-at_p3_1)
        (K_not_obs3-at_p3_1)
        (K_obs4-at_p3_1)
        (K_not_obs4-at_p3_1)
        (K_obs5-at_p3_1)
        (K_not_obs5-at_p3_1)
        (K_obs6-at_p3_1)
        (K_not_obs6-at_p3_1)
        (K_obs7-at_p3_1)
        (K_not_obs7-at_p3_1)
        (K_obs8-at_p3_1)
        (K_not_obs8-at_p3_1)
        (K_obs0-at_p1_2)
        (K_not_obs0-at_p1_2)
        (K_obs1-at_p1_2)
        (K_not_obs1-at_p1_2)
        (K_obs2-at_p1_2)
        (K_not_obs2-at_p1_2)
        (K_obs3-at_p1_2)
        (K_not_obs3-at_p1_2)
        (K_obs4-at_p1_2)
        (K_not_obs4-at_p1_2)
        (K_obs5-at_p1_2)
        (K_not_obs5-at_p1_2)
        (K_obs6-at_p1_2)
        (K_not_obs6-at_p1_2)
        (K_obs7-at_p1_2)
        (K_not_obs7-at_p1_2)
        (K_obs8-at_p1_2)
        (K_not_obs8-at_p1_2)
        (K_obs0-at_p3_3)
        (K_not_obs0-at_p3_3)
        (K_obs1-at_p3_3)
        (K_not_obs1-at_p3_3)
        (K_obs2-at_p3_3)
        (K_not_obs2-at_p3_3)
        (K_obs3-at_p3_3)
        (K_not_obs3-at_p3_3)
        (K_obs4-at_p3_3)
        (K_not_obs4-at_p3_3)
        (K_obs5-at_p3_3)
        (K_not_obs5-at_p3_3)
        (K_obs6-at_p3_3)
        (K_not_obs6-at_p3_3)
        (K_obs7-at_p3_3)
        (K_not_obs7-at_p3_3)
        (K_obs8-at_p3_3)
        (K_not_obs8-at_p3_3)
        (K_obs0-at_p3_4)
        (K_not_obs0-at_p3_4)
        (K_obs1-at_p3_4)
        (K_not_obs1-at_p3_4)
        (K_obs2-at_p3_4)
        (K_not_obs2-at_p3_4)
        (K_obs3-at_p3_4)
        (K_not_obs3-at_p3_4)
        (K_obs4-at_p3_4)
        (K_not_obs4-at_p3_4)
        (K_obs5-at_p3_4)
        (K_not_obs5-at_p3_4)
        (K_obs6-at_p3_4)
        (K_not_obs6-at_p3_4)
        (K_obs7-at_p3_4)
        (K_not_obs7-at_p3_4)
        (K_obs8-at_p3_4)
        (K_not_obs8-at_p3_4)
        (K_obs0-at_p2_4)
        (K_not_obs0-at_p2_4)
        (K_obs1-at_p2_4)
        (K_not_obs1-at_p2_4)
        (K_obs2-at_p2_4)
        (K_not_obs2-at_p2_4)
        (K_obs3-at_p2_4)
        (K_not_obs3-at_p2_4)
        (K_obs4-at_p2_4)
        (K_not_obs4-at_p2_4)
        (K_obs5-at_p2_4)
        (K_not_obs5-at_p2_4)
        (K_obs6-at_p2_4)
        (K_not_obs6-at_p2_4)
        (K_obs7-at_p2_4)
        (K_not_obs7-at_p2_4)
        (K_obs8-at_p2_4)
        (K_not_obs8-at_p2_4)
        (K_obs0-at_p1_4)
        (K_not_obs0-at_p1_4)
        (K_obs1-at_p1_4)
        (K_not_obs1-at_p1_4)
        (K_obs2-at_p1_4)
        (K_not_obs2-at_p1_4)
        (K_obs3-at_p1_4)
        (K_not_obs3-at_p1_4)
        (K_obs4-at_p1_4)
        (K_not_obs4-at_p1_4)
        (K_obs5-at_p1_4)
        (K_not_obs5-at_p1_4)
        (K_obs6-at_p1_4)
        (K_not_obs6-at_p1_4)
        (K_obs7-at_p1_4)
        (K_not_obs7-at_p1_4)
        (K_obs8-at_p1_4)
        (K_not_obs8-at_p1_4)
        (K_done-with_p1_1)
        (K_not_done-with_p1_1)
        (K_done-with_p2_1)
        (K_not_done-with_p2_1)
        (K_done-with_p3_1)
        (K_not_done-with_p3_1)
        (K_done-with_p1_2)
        (K_not_done-with_p1_2)
        (K_done-with_p2_2)
        (K_not_done-with_p2_2)
        (K_done-with_p3_2)
        (K_not_done-with_p3_2)
        (K_done-with_p1_3)
        (K_not_done-with_p1_3)
        (K_done-with_p2_3)
        (K_not_done-with_p2_3)
        (K_done-with_p3_3)
        (K_not_done-with_p3_3)
        (K_done-with_p1_4)
        (K_not_done-with_p1_4)
        (K_done-with_p2_4)
        (K_not_done-with_p2_4)
        (K_done-with_p3_4)
        (K_not_done-with_p3_4)
        (K_need-advance-step)
        (K_not_need-advance-step)
        (K_ok)
        (K_not_ok)
        (K_at-step_n0)
        (K_not_at-step_n0)
        (K_at-step_n1)
        (K_not_at-step_n1)
        (K_at-step_n2)
        (K_not_at-step_n2)
        (K_at-step_n3)
        (K_not_at-step_n3)
        (K_at-step_n4)
        (K_not_at-step_n4)
        (K_at-step_n5)
        (K_not_at-step_n5)
        (K_at-step_n6)
        (K_not_at-step_n6)
        (K_at-step_n7)
        (K_not_at-step_n7)
        (K_at-step_n8)
        (K_not_at-step_n8)
        (K_at-step_n9)
        (K_not_at-step_n9)
        (K_at-step_n10)
        (K_not_at-step_n10)
        (K_at-step_n11)
        (K_not_at-step_n11)
        (K_need-gather-obs0-at_p3_4)
        (K_not_need-gather-obs0-at_p3_4)
        (K_need-post-for-gather-obs0_p3_4)
        (K_not_need-post-for-gather-obs0_p3_4)
        (K_need-gather-obs0-at_p2_4)
        (K_not_need-gather-obs0-at_p2_4)
        (K_need-post-for-gather-obs0_p2_4)
        (K_not_need-post-for-gather-obs0_p2_4)
        (K_need-gather-obs0-at_p1_4)
        (K_not_need-gather-obs0-at_p1_4)
        (K_need-post-for-gather-obs0_p1_4)
        (K_not_need-post-for-gather-obs0_p1_4)
        (K_need-gather-obs0-at_p3_3)
        (K_not_need-gather-obs0-at_p3_3)
        (K_need-post-for-gather-obs0_p3_3)
        (K_not_need-post-for-gather-obs0_p3_3)
        (K_need-gather-obs0-at_p3_2)
        (K_not_need-gather-obs0-at_p3_2)
        (K_need-post-for-gather-obs0_p3_2)
        (K_not_need-post-for-gather-obs0_p3_2)
        (K_need-gather-obs0-at_p2_2)
        (K_not_need-gather-obs0-at_p2_2)
        (K_need-post-for-gather-obs0_p2_2)
        (K_not_need-post-for-gather-obs0_p2_2)
        (K_need-gather-obs0-at_p1_2)
        (K_not_need-gather-obs0-at_p1_2)
        (K_need-post-for-gather-obs0_p1_2)
        (K_not_need-post-for-gather-obs0_p1_2)
        (K_need-gather-obs0-at_p3_1)
        (K_not_need-gather-obs0-at_p3_1)
        (K_need-post-for-gather-obs0_p3_1)
        (K_not_need-post-for-gather-obs0_p3_1)
        (K_need-gather-obs0-at_p2_1)
        (K_not_need-gather-obs0-at_p2_1)
        (K_need-post-for-gather-obs0_p2_1)
        (K_not_need-post-for-gather-obs0_p2_1)
        (K_need-gather-obs0-at_p1_1)
        (K_not_need-gather-obs0-at_p1_1)
        (K_need-post-for-gather-obs0_p1_1)
        (K_not_need-post-for-gather-obs0_p1_1)
        (K_need-gather-obs1-at_p3_4)
        (K_not_need-gather-obs1-at_p3_4)
        (K_need-post-for-gather-obs1_p3_4)
        (K_not_need-post-for-gather-obs1_p3_4)
        (K_need-gather-obs1-at_p2_4)
        (K_not_need-gather-obs1-at_p2_4)
        (K_need-post-for-gather-obs1_p2_4)
        (K_not_need-post-for-gather-obs1_p2_4)
        (K_need-gather-obs1-at_p1_4)
        (K_not_need-gather-obs1-at_p1_4)
        (K_need-post-for-gather-obs1_p1_4)
        (K_not_need-post-for-gather-obs1_p1_4)
        (K_need-gather-obs1-at_p3_3)
        (K_not_need-gather-obs1-at_p3_3)
        (K_need-post-for-gather-obs1_p3_3)
        (K_not_need-post-for-gather-obs1_p3_3)
        (K_need-gather-obs1-at_p3_2)
        (K_not_need-gather-obs1-at_p3_2)
        (K_need-post-for-gather-obs1_p3_2)
        (K_not_need-post-for-gather-obs1_p3_2)
        (K_need-gather-obs1-at_p2_2)
        (K_not_need-gather-obs1-at_p2_2)
        (K_need-post-for-gather-obs1_p2_2)
        (K_not_need-post-for-gather-obs1_p2_2)
        (K_need-gather-obs1-at_p1_2)
        (K_not_need-gather-obs1-at_p1_2)
        (K_need-post-for-gather-obs1_p1_2)
        (K_not_need-post-for-gather-obs1_p1_2)
        (K_need-gather-obs1-at_p3_1)
        (K_not_need-gather-obs1-at_p3_1)
        (K_need-post-for-gather-obs1_p3_1)
        (K_not_need-post-for-gather-obs1_p3_1)
        (K_need-gather-obs1-at_p2_1)
        (K_not_need-gather-obs1-at_p2_1)
        (K_need-post-for-gather-obs1_p2_1)
        (K_not_need-post-for-gather-obs1_p2_1)
        (K_need-gather-obs1-at_p1_1)
        (K_not_need-gather-obs1-at_p1_1)
        (K_need-post-for-gather-obs1_p1_1)
        (K_not_need-post-for-gather-obs1_p1_1)
        (K_need-gather-obs2-at_p3_4)
        (K_not_need-gather-obs2-at_p3_4)
        (K_need-post-for-gather-obs2_p3_4)
        (K_not_need-post-for-gather-obs2_p3_4)
        (K_need-gather-obs2-at_p2_4)
        (K_not_need-gather-obs2-at_p2_4)
        (K_need-post-for-gather-obs2_p2_4)
        (K_not_need-post-for-gather-obs2_p2_4)
        (K_need-gather-obs2-at_p1_4)
        (K_not_need-gather-obs2-at_p1_4)
        (K_need-post-for-gather-obs2_p1_4)
        (K_not_need-post-for-gather-obs2_p1_4)
        (K_need-gather-obs2-at_p3_3)
        (K_not_need-gather-obs2-at_p3_3)
        (K_need-post-for-gather-obs2_p3_3)
        (K_not_need-post-for-gather-obs2_p3_3)
        (K_need-gather-obs2-at_p3_2)
        (K_not_need-gather-obs2-at_p3_2)
        (K_need-post-for-gather-obs2_p3_2)
        (K_not_need-post-for-gather-obs2_p3_2)
        (K_need-gather-obs2-at_p2_2)
        (K_not_need-gather-obs2-at_p2_2)
        (K_need-post-for-gather-obs2_p2_2)
        (K_not_need-post-for-gather-obs2_p2_2)
        (K_need-gather-obs2-at_p1_2)
        (K_not_need-gather-obs2-at_p1_2)
        (K_need-post-for-gather-obs2_p1_2)
        (K_not_need-post-for-gather-obs2_p1_2)
        (K_need-gather-obs2-at_p3_1)
        (K_not_need-gather-obs2-at_p3_1)
        (K_need-post-for-gather-obs2_p3_1)
        (K_not_need-post-for-gather-obs2_p3_1)
        (K_need-gather-obs2-at_p2_1)
        (K_not_need-gather-obs2-at_p2_1)
        (K_need-post-for-gather-obs2_p2_1)
        (K_not_need-post-for-gather-obs2_p2_1)
        (K_need-gather-obs2-at_p1_1)
        (K_not_need-gather-obs2-at_p1_1)
        (K_need-post-for-gather-obs2_p1_1)
        (K_not_need-post-for-gather-obs2_p1_1)
        (K_need-gather-obs3-at_p3_4)
        (K_not_need-gather-obs3-at_p3_4)
        (K_need-post-for-gather-obs3_p3_4)
        (K_not_need-post-for-gather-obs3_p3_4)
        (K_need-gather-obs3-at_p2_4)
        (K_not_need-gather-obs3-at_p2_4)
        (K_need-post-for-gather-obs3_p2_4)
        (K_not_need-post-for-gather-obs3_p2_4)
        (K_need-gather-obs3-at_p1_4)
        (K_not_need-gather-obs3-at_p1_4)
        (K_need-post-for-gather-obs3_p1_4)
        (K_not_need-post-for-gather-obs3_p1_4)
        (K_need-gather-obs3-at_p3_3)
        (K_not_need-gather-obs3-at_p3_3)
        (K_need-post-for-gather-obs3_p3_3)
        (K_not_need-post-for-gather-obs3_p3_3)
        (K_need-gather-obs3-at_p3_2)
        (K_not_need-gather-obs3-at_p3_2)
        (K_need-post-for-gather-obs3_p3_2)
        (K_not_need-post-for-gather-obs3_p3_2)
        (K_need-gather-obs3-at_p2_2)
        (K_not_need-gather-obs3-at_p2_2)
        (K_need-post-for-gather-obs3_p2_2)
        (K_not_need-post-for-gather-obs3_p2_2)
        (K_need-gather-obs3-at_p1_2)
        (K_not_need-gather-obs3-at_p1_2)
        (K_need-post-for-gather-obs3_p1_2)
        (K_not_need-post-for-gather-obs3_p1_2)
        (K_need-gather-obs3-at_p3_1)
        (K_not_need-gather-obs3-at_p3_1)
        (K_need-post-for-gather-obs3_p3_1)
        (K_not_need-post-for-gather-obs3_p3_1)
        (K_need-gather-obs3-at_p2_1)
        (K_not_need-gather-obs3-at_p2_1)
        (K_need-post-for-gather-obs3_p2_1)
        (K_not_need-post-for-gather-obs3_p2_1)
        (K_need-gather-obs3-at_p1_1)
        (K_not_need-gather-obs3-at_p1_1)
        (K_need-post-for-gather-obs3_p1_1)
        (K_not_need-post-for-gather-obs3_p1_1)
        (K_need-gather-obs4-at_p3_4)
        (K_not_need-gather-obs4-at_p3_4)
        (K_need-post-for-gather-obs4_p3_4)
        (K_not_need-post-for-gather-obs4_p3_4)
        (K_need-gather-obs4-at_p2_4)
        (K_not_need-gather-obs4-at_p2_4)
        (K_need-post-for-gather-obs4_p2_4)
        (K_not_need-post-for-gather-obs4_p2_4)
        (K_need-gather-obs4-at_p1_4)
        (K_not_need-gather-obs4-at_p1_4)
        (K_need-post-for-gather-obs4_p1_4)
        (K_not_need-post-for-gather-obs4_p1_4)
        (K_need-gather-obs4-at_p3_3)
        (K_not_need-gather-obs4-at_p3_3)
        (K_need-post-for-gather-obs4_p3_3)
        (K_not_need-post-for-gather-obs4_p3_3)
        (K_need-gather-obs4-at_p3_2)
        (K_not_need-gather-obs4-at_p3_2)
        (K_need-post-for-gather-obs4_p3_2)
        (K_not_need-post-for-gather-obs4_p3_2)
        (K_need-gather-obs4-at_p2_2)
        (K_not_need-gather-obs4-at_p2_2)
        (K_need-post-for-gather-obs4_p2_2)
        (K_not_need-post-for-gather-obs4_p2_2)
        (K_need-gather-obs4-at_p1_2)
        (K_not_need-gather-obs4-at_p1_2)
        (K_need-post-for-gather-obs4_p1_2)
        (K_not_need-post-for-gather-obs4_p1_2)
        (K_need-gather-obs4-at_p3_1)
        (K_not_need-gather-obs4-at_p3_1)
        (K_need-post-for-gather-obs4_p3_1)
        (K_not_need-post-for-gather-obs4_p3_1)
        (K_need-gather-obs4-at_p2_1)
        (K_not_need-gather-obs4-at_p2_1)
        (K_need-post-for-gather-obs4_p2_1)
        (K_not_need-post-for-gather-obs4_p2_1)
        (K_need-gather-obs4-at_p1_1)
        (K_not_need-gather-obs4-at_p1_1)
        (K_need-post-for-gather-obs4_p1_1)
        (K_not_need-post-for-gather-obs4_p1_1)
        (K_need-gather-obs5-at_p3_4)
        (K_not_need-gather-obs5-at_p3_4)
        (K_need-post-for-gather-obs5_p3_4)
        (K_not_need-post-for-gather-obs5_p3_4)
        (K_need-gather-obs5-at_p2_4)
        (K_not_need-gather-obs5-at_p2_4)
        (K_need-post-for-gather-obs5_p2_4)
        (K_not_need-post-for-gather-obs5_p2_4)
        (K_need-gather-obs5-at_p1_4)
        (K_not_need-gather-obs5-at_p1_4)
        (K_need-post-for-gather-obs5_p1_4)
        (K_not_need-post-for-gather-obs5_p1_4)
        (K_need-gather-obs5-at_p3_3)
        (K_not_need-gather-obs5-at_p3_3)
        (K_need-post-for-gather-obs5_p3_3)
        (K_not_need-post-for-gather-obs5_p3_3)
        (K_need-gather-obs5-at_p3_2)
        (K_not_need-gather-obs5-at_p3_2)
        (K_need-post-for-gather-obs5_p3_2)
        (K_not_need-post-for-gather-obs5_p3_2)
        (K_need-gather-obs5-at_p2_2)
        (K_not_need-gather-obs5-at_p2_2)
        (K_need-post-for-gather-obs5_p2_2)
        (K_not_need-post-for-gather-obs5_p2_2)
        (K_need-gather-obs5-at_p1_2)
        (K_not_need-gather-obs5-at_p1_2)
        (K_need-post-for-gather-obs5_p1_2)
        (K_not_need-post-for-gather-obs5_p1_2)
        (K_need-gather-obs5-at_p3_1)
        (K_not_need-gather-obs5-at_p3_1)
        (K_need-post-for-gather-obs5_p3_1)
        (K_not_need-post-for-gather-obs5_p3_1)
        (K_need-gather-obs5-at_p2_1)
        (K_not_need-gather-obs5-at_p2_1)
        (K_need-post-for-gather-obs5_p2_1)
        (K_not_need-post-for-gather-obs5_p2_1)
        (K_need-gather-obs5-at_p1_1)
        (K_not_need-gather-obs5-at_p1_1)
        (K_need-post-for-gather-obs5_p1_1)
        (K_not_need-post-for-gather-obs5_p1_1)
        (K_need-gather-obs6-at_p3_4)
        (K_not_need-gather-obs6-at_p3_4)
        (K_need-post-for-gather-obs6_p3_4)
        (K_not_need-post-for-gather-obs6_p3_4)
        (K_need-gather-obs6-at_p2_4)
        (K_not_need-gather-obs6-at_p2_4)
        (K_need-post-for-gather-obs6_p2_4)
        (K_not_need-post-for-gather-obs6_p2_4)
        (K_need-gather-obs6-at_p1_4)
        (K_not_need-gather-obs6-at_p1_4)
        (K_need-post-for-gather-obs6_p1_4)
        (K_not_need-post-for-gather-obs6_p1_4)
        (K_need-gather-obs6-at_p3_3)
        (K_not_need-gather-obs6-at_p3_3)
        (K_need-post-for-gather-obs6_p3_3)
        (K_not_need-post-for-gather-obs6_p3_3)
        (K_need-gather-obs6-at_p3_2)
        (K_not_need-gather-obs6-at_p3_2)
        (K_need-post-for-gather-obs6_p3_2)
        (K_not_need-post-for-gather-obs6_p3_2)
        (K_need-gather-obs6-at_p2_2)
        (K_not_need-gather-obs6-at_p2_2)
        (K_need-post-for-gather-obs6_p2_2)
        (K_not_need-post-for-gather-obs6_p2_2)
        (K_need-gather-obs6-at_p1_2)
        (K_not_need-gather-obs6-at_p1_2)
        (K_need-post-for-gather-obs6_p1_2)
        (K_not_need-post-for-gather-obs6_p1_2)
        (K_need-gather-obs6-at_p3_1)
        (K_not_need-gather-obs6-at_p3_1)
        (K_need-post-for-gather-obs6_p3_1)
        (K_not_need-post-for-gather-obs6_p3_1)
        (K_need-gather-obs6-at_p2_1)
        (K_not_need-gather-obs6-at_p2_1)
        (K_need-post-for-gather-obs6_p2_1)
        (K_not_need-post-for-gather-obs6_p2_1)
        (K_need-gather-obs6-at_p1_1)
        (K_not_need-gather-obs6-at_p1_1)
        (K_need-post-for-gather-obs6_p1_1)
        (K_not_need-post-for-gather-obs6_p1_1)
        (K_need-gather-obs7-at_p3_4)
        (K_not_need-gather-obs7-at_p3_4)
        (K_need-post-for-gather-obs7_p3_4)
        (K_not_need-post-for-gather-obs7_p3_4)
        (K_need-gather-obs7-at_p2_4)
        (K_not_need-gather-obs7-at_p2_4)
        (K_need-post-for-gather-obs7_p2_4)
        (K_not_need-post-for-gather-obs7_p2_4)
        (K_need-gather-obs7-at_p1_4)
        (K_not_need-gather-obs7-at_p1_4)
        (K_need-post-for-gather-obs7_p1_4)
        (K_not_need-post-for-gather-obs7_p1_4)
        (K_need-gather-obs7-at_p3_3)
        (K_not_need-gather-obs7-at_p3_3)
        (K_need-post-for-gather-obs7_p3_3)
        (K_not_need-post-for-gather-obs7_p3_3)
        (K_need-gather-obs7-at_p3_2)
        (K_not_need-gather-obs7-at_p3_2)
        (K_need-post-for-gather-obs7_p3_2)
        (K_not_need-post-for-gather-obs7_p3_2)
        (K_need-gather-obs7-at_p2_2)
        (K_not_need-gather-obs7-at_p2_2)
        (K_need-post-for-gather-obs7_p2_2)
        (K_not_need-post-for-gather-obs7_p2_2)
        (K_need-gather-obs7-at_p1_2)
        (K_not_need-gather-obs7-at_p1_2)
        (K_need-post-for-gather-obs7_p1_2)
        (K_not_need-post-for-gather-obs7_p1_2)
        (K_need-gather-obs7-at_p3_1)
        (K_not_need-gather-obs7-at_p3_1)
        (K_need-post-for-gather-obs7_p3_1)
        (K_not_need-post-for-gather-obs7_p3_1)
        (K_need-gather-obs7-at_p2_1)
        (K_not_need-gather-obs7-at_p2_1)
        (K_need-post-for-gather-obs7_p2_1)
        (K_not_need-post-for-gather-obs7_p2_1)
        (K_need-gather-obs7-at_p1_1)
        (K_not_need-gather-obs7-at_p1_1)
        (K_need-post-for-gather-obs7_p1_1)
        (K_not_need-post-for-gather-obs7_p1_1)
        (K_need-gather-obs8-at_p3_4)
        (K_not_need-gather-obs8-at_p3_4)
        (K_need-post-for-gather-obs8_p3_4)
        (K_not_need-post-for-gather-obs8_p3_4)
        (K_need-gather-obs8-at_p2_4)
        (K_not_need-gather-obs8-at_p2_4)
        (K_need-post-for-gather-obs8_p2_4)
        (K_not_need-post-for-gather-obs8_p2_4)
        (K_need-gather-obs8-at_p1_4)
        (K_not_need-gather-obs8-at_p1_4)
        (K_need-post-for-gather-obs8_p1_4)
        (K_not_need-post-for-gather-obs8_p1_4)
        (K_need-gather-obs8-at_p3_3)
        (K_not_need-gather-obs8-at_p3_3)
        (K_need-post-for-gather-obs8_p3_3)
        (K_not_need-post-for-gather-obs8_p3_3)
        (K_need-gather-obs8-at_p3_2)
        (K_not_need-gather-obs8-at_p3_2)
        (K_need-post-for-gather-obs8_p3_2)
        (K_not_need-post-for-gather-obs8_p3_2)
        (K_need-gather-obs8-at_p2_2)
        (K_not_need-gather-obs8-at_p2_2)
        (K_need-post-for-gather-obs8_p2_2)
        (K_not_need-post-for-gather-obs8_p2_2)
        (K_need-gather-obs8-at_p1_2)
        (K_not_need-gather-obs8-at_p1_2)
        (K_need-post-for-gather-obs8_p1_2)
        (K_not_need-post-for-gather-obs8_p1_2)
        (K_need-gather-obs8-at_p3_1)
        (K_not_need-gather-obs8-at_p3_1)
        (K_need-post-for-gather-obs8_p3_1)
        (K_not_need-post-for-gather-obs8_p3_1)
        (K_need-gather-obs8-at_p2_1)
        (K_not_need-gather-obs8-at_p2_1)
        (K_need-post-for-gather-obs8_p2_1)
        (K_not_need-post-for-gather-obs8_p2_1)
        (K_need-gather-obs8-at_p1_1)
        (K_not_need-gather-obs8-at_p1_1)
        (K_need-post-for-gather-obs8_p1_1)
        (K_not_need-post-for-gather-obs8_p1_1)
        (new-goal)
    )
    (:action advance-step
        :precondition (and (K_normal-execution) (K_need-advance-step))
        :effect (and (not (K_at-step_n0)) (not (K_not_ok)) (not (K_need-advance-step)) (K_not_need-advance-step) (K_ok) (K_not_at-step_n0)
                     (when (K_at-step_n0) (and (K_not_at-step_n0) (K_at-step_n1)))
                     (when (not (K_not_at-step_n0)) (and (not (K_not_at-step_n1)) (not (K_at-step_n0))))
                     (when (K_at-step_n1) (and (K_not_at-step_n1) (K_at-step_n2)))
                     (when (not (K_not_at-step_n1)) (and (not (K_not_at-step_n2)) (not (K_at-step_n1))))
                     (when (K_at-step_n2) (and (K_not_at-step_n2) (K_at-step_n3)))
                     (when (not (K_not_at-step_n2)) (and (not (K_not_at-step_n3)) (not (K_at-step_n2))))
                     (when (K_at-step_n3) (and (K_not_at-step_n3) (K_at-step_n4)))
                     (when (not (K_not_at-step_n3)) (and (not (K_not_at-step_n4)) (not (K_at-step_n3))))
                     (when (K_at-step_n4) (and (K_not_at-step_n4) (K_at-step_n5)))
                     (when (not (K_not_at-step_n4)) (and (not (K_not_at-step_n5)) (not (K_at-step_n4))))
                     (when (K_at-step_n5) (and (K_not_at-step_n5) (K_at-step_n6)))
                     (when (not (K_not_at-step_n5)) (and (not (K_not_at-step_n6)) (not (K_at-step_n5))))
                     (when (K_at-step_n6) (and (K_not_at-step_n6) (K_at-step_n7)))
                     (when (not (K_not_at-step_n6)) (and (not (K_not_at-step_n7)) (not (K_at-step_n6))))
                     (when (K_at-step_n7) (and (K_not_at-step_n7) (K_at-step_n8)))
                     (when (not (K_not_at-step_n7)) (and (not (K_not_at-step_n8)) (not (K_at-step_n7))))
                     (when (K_at-step_n8) (and (K_not_at-step_n8) (K_at-step_n9)))
                     (when (not (K_not_at-step_n8)) (and (not (K_not_at-step_n9)) (not (K_at-step_n8))))
                     (when (K_at-step_n9) (and (K_not_at-step_n9) (K_at-step_n10)))
                     (when (not (K_not_at-step_n9)) (and (not (K_not_at-step_n10)) (not (K_at-step_n9))))
                     (when (K_at-step_n10) (and (K_not_at-step_n10) (K_at-step_n11)))
                     (when (not (K_not_at-step_n10)) (and (not (K_not_at-step_n11)) (not (K_at-step_n10))))
                     (when (K_not_at-step_n0) (K_not_at-step_n1))
                     (when (not (K_at-step_n0)) (not (K_at-step_n1)))
                     (when (K_not_at-step_n1) (K_not_at-step_n2))
                     (when (not (K_at-step_n1)) (not (K_at-step_n2)))
                     (when (K_not_at-step_n2) (K_not_at-step_n3))
                     (when (not (K_at-step_n2)) (not (K_at-step_n3)))
                     (when (K_not_at-step_n3) (K_not_at-step_n4))
                     (when (not (K_at-step_n3)) (not (K_at-step_n4)))
                     (when (K_not_at-step_n4) (K_not_at-step_n5))
                     (when (not (K_at-step_n4)) (not (K_at-step_n5)))
                     (when (K_not_at-step_n5) (K_not_at-step_n6))
                     (when (not (K_at-step_n5)) (not (K_at-step_n6)))
                     (when (K_not_at-step_n6) (K_not_at-step_n7))
                     (when (not (K_at-step_n6)) (not (K_at-step_n7)))
                     (when (K_not_at-step_n7) (K_not_at-step_n8))
                     (when (not (K_at-step_n7)) (not (K_at-step_n8)))
                     (when (K_not_at-step_n8) (K_not_at-step_n9))
                     (when (not (K_at-step_n8)) (not (K_at-step_n9)))
                     (when (K_not_at-step_n9) (K_not_at-step_n10))
                     (when (not (K_at-step_n9)) (not (K_at-step_n10)))))
    (:action gather-obs0_p3_4
        :precondition (and (K_normal-execution) (K_need-gather-obs0-at_p3_4))
        :effect (and (not (K_not_need-post-for-gather-obs0_p3_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs0_p3_4)))
    (:action gather-obs0_p2_4
        :precondition (and (K_normal-execution) (K_need-gather-obs0-at_p2_4))
        :effect (and (not (K_not_need-post-for-gather-obs0_p2_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs0_p2_4)))
    (:action gather-obs0_p1_4
        :precondition (and (K_normal-execution) (K_need-gather-obs0-at_p1_4))
        :effect (and (not (K_not_need-post-for-gather-obs0_p1_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs0_p1_4)))
    (:action gather-obs0_p3_3
        :precondition (and (K_normal-execution) (K_need-gather-obs0-at_p3_3))
        :effect (and (not (K_not_need-post-for-gather-obs0_p3_3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs0_p3_3)))
    (:action gather-obs0_p3_2
        :precondition (and (K_normal-execution) (K_need-gather-obs0-at_p3_2))
        :effect (and (not (K_not_need-post-for-gather-obs0_p3_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs0_p3_2)))
    (:action gather-obs0_p2_2
        :precondition (and (K_normal-execution) (K_need-gather-obs0-at_p2_2))
        :effect (and (not (K_not_need-post-for-gather-obs0_p2_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs0_p2_2)))
    (:action gather-obs0_p1_2
        :precondition (and (K_normal-execution) (K_need-gather-obs0-at_p1_2))
        :effect (and (not (K_not_need-post-for-gather-obs0_p1_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs0_p1_2)))
    (:action gather-obs0_p3_1
        :precondition (and (K_normal-execution) (K_need-gather-obs0-at_p3_1))
        :effect (and (not (K_not_need-post-for-gather-obs0_p3_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs0_p3_1)))
    (:action gather-obs0_p2_1
        :precondition (and (K_normal-execution) (K_need-gather-obs0-at_p2_1))
        :effect (and (not (K_not_need-post-for-gather-obs0_p2_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs0_p2_1)))
    (:action gather-obs0_p1_1
        :precondition (and (K_normal-execution) (K_need-gather-obs0-at_p1_1))
        :effect (and (not (K_not_need-post-for-gather-obs0_p1_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs0_p1_1)))
    (:action gather-obs1_p3_4
        :precondition (and (K_normal-execution) (K_need-gather-obs1-at_p3_4))
        :effect (and (not (K_not_need-post-for-gather-obs1_p3_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs1_p3_4)))
    (:action gather-obs1_p2_4
        :precondition (and (K_normal-execution) (K_need-gather-obs1-at_p2_4))
        :effect (and (not (K_not_need-post-for-gather-obs1_p2_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs1_p2_4)))
    (:action gather-obs1_p1_4
        :precondition (and (K_normal-execution) (K_need-gather-obs1-at_p1_4))
        :effect (and (not (K_not_need-post-for-gather-obs1_p1_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs1_p1_4)))
    (:action gather-obs1_p3_3
        :precondition (and (K_normal-execution) (K_need-gather-obs1-at_p3_3))
        :effect (and (not (K_not_need-post-for-gather-obs1_p3_3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs1_p3_3)))
    (:action gather-obs1_p3_2
        :precondition (and (K_normal-execution) (K_need-gather-obs1-at_p3_2))
        :effect (and (not (K_not_need-post-for-gather-obs1_p3_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs1_p3_2)))
    (:action gather-obs1_p2_2
        :precondition (and (K_normal-execution) (K_need-gather-obs1-at_p2_2))
        :effect (and (not (K_not_need-post-for-gather-obs1_p2_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs1_p2_2)))
    (:action gather-obs1_p1_2
        :precondition (and (K_normal-execution) (K_need-gather-obs1-at_p1_2))
        :effect (and (not (K_not_need-post-for-gather-obs1_p1_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs1_p1_2)))
    (:action gather-obs1_p3_1
        :precondition (and (K_normal-execution) (K_need-gather-obs1-at_p3_1))
        :effect (and (not (K_not_need-post-for-gather-obs1_p3_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs1_p3_1)))
    (:action gather-obs1_p2_1
        :precondition (and (K_normal-execution) (K_need-gather-obs1-at_p2_1))
        :effect (and (not (K_not_need-post-for-gather-obs1_p2_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs1_p2_1)))
    (:action gather-obs1_p1_1
        :precondition (and (K_normal-execution) (K_need-gather-obs1-at_p1_1))
        :effect (and (not (K_not_need-post-for-gather-obs1_p1_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs1_p1_1)))
    (:action gather-obs2_p3_4
        :precondition (and (K_normal-execution) (K_need-gather-obs2-at_p3_4))
        :effect (and (not (K_not_need-post-for-gather-obs2_p3_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs2_p3_4)))
    (:action gather-obs2_p2_4
        :precondition (and (K_normal-execution) (K_need-gather-obs2-at_p2_4))
        :effect (and (not (K_not_need-post-for-gather-obs2_p2_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs2_p2_4)))
    (:action gather-obs2_p1_4
        :precondition (and (K_normal-execution) (K_need-gather-obs2-at_p1_4))
        :effect (and (not (K_not_need-post-for-gather-obs2_p1_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs2_p1_4)))
    (:action gather-obs2_p3_3
        :precondition (and (K_normal-execution) (K_need-gather-obs2-at_p3_3))
        :effect (and (not (K_not_need-post-for-gather-obs2_p3_3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs2_p3_3)))
    (:action gather-obs2_p3_2
        :precondition (and (K_normal-execution) (K_need-gather-obs2-at_p3_2))
        :effect (and (not (K_not_need-post-for-gather-obs2_p3_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs2_p3_2)))
    (:action gather-obs2_p2_2
        :precondition (and (K_normal-execution) (K_need-gather-obs2-at_p2_2))
        :effect (and (not (K_not_need-post-for-gather-obs2_p2_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs2_p2_2)))
    (:action gather-obs2_p1_2
        :precondition (and (K_normal-execution) (K_need-gather-obs2-at_p1_2))
        :effect (and (not (K_not_need-post-for-gather-obs2_p1_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs2_p1_2)))
    (:action gather-obs2_p3_1
        :precondition (and (K_normal-execution) (K_need-gather-obs2-at_p3_1))
        :effect (and (not (K_not_need-post-for-gather-obs2_p3_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs2_p3_1)))
    (:action gather-obs2_p2_1
        :precondition (and (K_normal-execution) (K_need-gather-obs2-at_p2_1))
        :effect (and (not (K_not_need-post-for-gather-obs2_p2_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs2_p2_1)))
    (:action gather-obs2_p1_1
        :precondition (and (K_normal-execution) (K_need-gather-obs2-at_p1_1))
        :effect (and (not (K_not_need-post-for-gather-obs2_p1_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs2_p1_1)))
    (:action gather-obs3_p3_4
        :precondition (and (K_normal-execution) (K_need-gather-obs3-at_p3_4))
        :effect (and (not (K_not_need-post-for-gather-obs3_p3_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs3_p3_4)))
    (:action gather-obs3_p2_4
        :precondition (and (K_normal-execution) (K_need-gather-obs3-at_p2_4))
        :effect (and (not (K_not_need-post-for-gather-obs3_p2_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs3_p2_4)))
    (:action gather-obs3_p1_4
        :precondition (and (K_normal-execution) (K_need-gather-obs3-at_p1_4))
        :effect (and (not (K_not_need-post-for-gather-obs3_p1_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs3_p1_4)))
    (:action gather-obs3_p3_3
        :precondition (and (K_normal-execution) (K_need-gather-obs3-at_p3_3))
        :effect (and (not (K_not_need-post-for-gather-obs3_p3_3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs3_p3_3)))
    (:action gather-obs3_p3_2
        :precondition (and (K_normal-execution) (K_need-gather-obs3-at_p3_2))
        :effect (and (not (K_not_need-post-for-gather-obs3_p3_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs3_p3_2)))
    (:action gather-obs3_p2_2
        :precondition (and (K_normal-execution) (K_need-gather-obs3-at_p2_2))
        :effect (and (not (K_not_need-post-for-gather-obs3_p2_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs3_p2_2)))
    (:action gather-obs3_p1_2
        :precondition (and (K_normal-execution) (K_need-gather-obs3-at_p1_2))
        :effect (and (not (K_not_need-post-for-gather-obs3_p1_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs3_p1_2)))
    (:action gather-obs3_p3_1
        :precondition (and (K_normal-execution) (K_need-gather-obs3-at_p3_1))
        :effect (and (not (K_not_need-post-for-gather-obs3_p3_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs3_p3_1)))
    (:action gather-obs3_p2_1
        :precondition (and (K_normal-execution) (K_need-gather-obs3-at_p2_1))
        :effect (and (not (K_not_need-post-for-gather-obs3_p2_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs3_p2_1)))
    (:action gather-obs3_p1_1
        :precondition (and (K_normal-execution) (K_need-gather-obs3-at_p1_1))
        :effect (and (not (K_not_need-post-for-gather-obs3_p1_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs3_p1_1)))
    (:action gather-obs4_p3_4
        :precondition (and (K_normal-execution) (K_need-gather-obs4-at_p3_4))
        :effect (and (not (K_not_need-post-for-gather-obs4_p3_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs4_p3_4)))
    (:action gather-obs4_p2_4
        :precondition (and (K_normal-execution) (K_need-gather-obs4-at_p2_4))
        :effect (and (not (K_not_need-post-for-gather-obs4_p2_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs4_p2_4)))
    (:action gather-obs4_p1_4
        :precondition (and (K_normal-execution) (K_need-gather-obs4-at_p1_4))
        :effect (and (not (K_not_need-post-for-gather-obs4_p1_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs4_p1_4)))
    (:action gather-obs4_p3_3
        :precondition (and (K_normal-execution) (K_need-gather-obs4-at_p3_3))
        :effect (and (not (K_not_need-post-for-gather-obs4_p3_3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs4_p3_3)))
    (:action gather-obs4_p3_2
        :precondition (and (K_normal-execution) (K_need-gather-obs4-at_p3_2))
        :effect (and (not (K_not_need-post-for-gather-obs4_p3_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs4_p3_2)))
    (:action gather-obs4_p2_2
        :precondition (and (K_normal-execution) (K_need-gather-obs4-at_p2_2))
        :effect (and (not (K_not_need-post-for-gather-obs4_p2_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs4_p2_2)))
    (:action gather-obs4_p1_2
        :precondition (and (K_normal-execution) (K_need-gather-obs4-at_p1_2))
        :effect (and (not (K_not_need-post-for-gather-obs4_p1_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs4_p1_2)))
    (:action gather-obs4_p3_1
        :precondition (and (K_normal-execution) (K_need-gather-obs4-at_p3_1))
        :effect (and (not (K_not_need-post-for-gather-obs4_p3_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs4_p3_1)))
    (:action gather-obs4_p2_1
        :precondition (and (K_normal-execution) (K_need-gather-obs4-at_p2_1))
        :effect (and (not (K_not_need-post-for-gather-obs4_p2_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs4_p2_1)))
    (:action gather-obs4_p1_1
        :precondition (and (K_normal-execution) (K_need-gather-obs4-at_p1_1))
        :effect (and (not (K_not_need-post-for-gather-obs4_p1_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs4_p1_1)))
    (:action gather-obs5_p3_4
        :precondition (and (K_normal-execution) (K_need-gather-obs5-at_p3_4))
        :effect (and (not (K_not_need-post-for-gather-obs5_p3_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs5_p3_4)))
    (:action gather-obs5_p2_4
        :precondition (and (K_normal-execution) (K_need-gather-obs5-at_p2_4))
        :effect (and (not (K_not_need-post-for-gather-obs5_p2_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs5_p2_4)))
    (:action gather-obs5_p1_4
        :precondition (and (K_normal-execution) (K_need-gather-obs5-at_p1_4))
        :effect (and (not (K_not_need-post-for-gather-obs5_p1_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs5_p1_4)))
    (:action gather-obs5_p3_3
        :precondition (and (K_normal-execution) (K_need-gather-obs5-at_p3_3))
        :effect (and (not (K_not_need-post-for-gather-obs5_p3_3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs5_p3_3)))
    (:action gather-obs5_p3_2
        :precondition (and (K_normal-execution) (K_need-gather-obs5-at_p3_2))
        :effect (and (not (K_not_need-post-for-gather-obs5_p3_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs5_p3_2)))
    (:action gather-obs5_p2_2
        :precondition (and (K_normal-execution) (K_need-gather-obs5-at_p2_2))
        :effect (and (not (K_not_need-post-for-gather-obs5_p2_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs5_p2_2)))
    (:action gather-obs5_p1_2
        :precondition (and (K_normal-execution) (K_need-gather-obs5-at_p1_2))
        :effect (and (not (K_not_need-post-for-gather-obs5_p1_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs5_p1_2)))
    (:action gather-obs5_p3_1
        :precondition (and (K_normal-execution) (K_need-gather-obs5-at_p3_1))
        :effect (and (not (K_not_need-post-for-gather-obs5_p3_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs5_p3_1)))
    (:action gather-obs5_p2_1
        :precondition (and (K_normal-execution) (K_need-gather-obs5-at_p2_1))
        :effect (and (not (K_not_need-post-for-gather-obs5_p2_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs5_p2_1)))
    (:action gather-obs5_p1_1
        :precondition (and (K_normal-execution) (K_need-gather-obs5-at_p1_1))
        :effect (and (not (K_not_need-post-for-gather-obs5_p1_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs5_p1_1)))
    (:action gather-obs6_p3_4
        :precondition (and (K_normal-execution) (K_need-gather-obs6-at_p3_4))
        :effect (and (not (K_not_need-post-for-gather-obs6_p3_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs6_p3_4)))
    (:action gather-obs6_p2_4
        :precondition (and (K_normal-execution) (K_need-gather-obs6-at_p2_4))
        :effect (and (not (K_not_need-post-for-gather-obs6_p2_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs6_p2_4)))
    (:action gather-obs6_p1_4
        :precondition (and (K_normal-execution) (K_need-gather-obs6-at_p1_4))
        :effect (and (not (K_not_need-post-for-gather-obs6_p1_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs6_p1_4)))
    (:action gather-obs6_p3_3
        :precondition (and (K_normal-execution) (K_need-gather-obs6-at_p3_3))
        :effect (and (not (K_not_need-post-for-gather-obs6_p3_3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs6_p3_3)))
    (:action gather-obs6_p3_2
        :precondition (and (K_normal-execution) (K_need-gather-obs6-at_p3_2))
        :effect (and (not (K_not_need-post-for-gather-obs6_p3_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs6_p3_2)))
    (:action gather-obs6_p2_2
        :precondition (and (K_normal-execution) (K_need-gather-obs6-at_p2_2))
        :effect (and (not (K_not_need-post-for-gather-obs6_p2_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs6_p2_2)))
    (:action gather-obs6_p1_2
        :precondition (and (K_normal-execution) (K_need-gather-obs6-at_p1_2))
        :effect (and (not (K_not_need-post-for-gather-obs6_p1_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs6_p1_2)))
    (:action gather-obs6_p3_1
        :precondition (and (K_normal-execution) (K_need-gather-obs6-at_p3_1))
        :effect (and (not (K_not_need-post-for-gather-obs6_p3_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs6_p3_1)))
    (:action gather-obs6_p2_1
        :precondition (and (K_normal-execution) (K_need-gather-obs6-at_p2_1))
        :effect (and (not (K_not_need-post-for-gather-obs6_p2_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs6_p2_1)))
    (:action gather-obs6_p1_1
        :precondition (and (K_normal-execution) (K_need-gather-obs6-at_p1_1))
        :effect (and (not (K_not_need-post-for-gather-obs6_p1_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs6_p1_1)))
    (:action gather-obs7_p3_4
        :precondition (and (K_normal-execution) (K_need-gather-obs7-at_p3_4))
        :effect (and (not (K_not_need-post-for-gather-obs7_p3_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs7_p3_4)))
    (:action gather-obs7_p2_4
        :precondition (and (K_normal-execution) (K_need-gather-obs7-at_p2_4))
        :effect (and (not (K_not_need-post-for-gather-obs7_p2_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs7_p2_4)))
    (:action gather-obs7_p1_4
        :precondition (and (K_normal-execution) (K_need-gather-obs7-at_p1_4))
        :effect (and (not (K_not_need-post-for-gather-obs7_p1_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs7_p1_4)))
    (:action gather-obs7_p3_3
        :precondition (and (K_normal-execution) (K_need-gather-obs7-at_p3_3))
        :effect (and (not (K_not_need-post-for-gather-obs7_p3_3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs7_p3_3)))
    (:action gather-obs7_p3_2
        :precondition (and (K_normal-execution) (K_need-gather-obs7-at_p3_2))
        :effect (and (not (K_not_need-post-for-gather-obs7_p3_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs7_p3_2)))
    (:action gather-obs7_p2_2
        :precondition (and (K_normal-execution) (K_need-gather-obs7-at_p2_2))
        :effect (and (not (K_not_need-post-for-gather-obs7_p2_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs7_p2_2)))
    (:action gather-obs7_p1_2
        :precondition (and (K_normal-execution) (K_need-gather-obs7-at_p1_2))
        :effect (and (not (K_not_need-post-for-gather-obs7_p1_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs7_p1_2)))
    (:action gather-obs7_p3_1
        :precondition (and (K_normal-execution) (K_need-gather-obs7-at_p3_1))
        :effect (and (not (K_not_need-post-for-gather-obs7_p3_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs7_p3_1)))
    (:action gather-obs7_p2_1
        :precondition (and (K_normal-execution) (K_need-gather-obs7-at_p2_1))
        :effect (and (not (K_not_need-post-for-gather-obs7_p2_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs7_p2_1)))
    (:action gather-obs7_p1_1
        :precondition (and (K_normal-execution) (K_need-gather-obs7-at_p1_1))
        :effect (and (not (K_not_need-post-for-gather-obs7_p1_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs7_p1_1)))
    (:action gather-obs8_p3_4
        :precondition (and (K_normal-execution) (K_need-gather-obs8-at_p3_4))
        :effect (and (not (K_not_need-post-for-gather-obs8_p3_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs8_p3_4)))
    (:action gather-obs8_p2_4
        :precondition (and (K_normal-execution) (K_need-gather-obs8-at_p2_4))
        :effect (and (not (K_not_need-post-for-gather-obs8_p2_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs8_p2_4)))
    (:action gather-obs8_p1_4
        :precondition (and (K_normal-execution) (K_need-gather-obs8-at_p1_4))
        :effect (and (not (K_not_need-post-for-gather-obs8_p1_4)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs8_p1_4)))
    (:action gather-obs8_p3_3
        :precondition (and (K_normal-execution) (K_need-gather-obs8-at_p3_3))
        :effect (and (not (K_not_need-post-for-gather-obs8_p3_3)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs8_p3_3)))
    (:action gather-obs8_p3_2
        :precondition (and (K_normal-execution) (K_need-gather-obs8-at_p3_2))
        :effect (and (not (K_not_need-post-for-gather-obs8_p3_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs8_p3_2)))
    (:action gather-obs8_p2_2
        :precondition (and (K_normal-execution) (K_need-gather-obs8-at_p2_2))
        :effect (and (not (K_not_need-post-for-gather-obs8_p2_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs8_p2_2)))
    (:action gather-obs8_p1_2
        :precondition (and (K_normal-execution) (K_need-gather-obs8-at_p1_2))
        :effect (and (not (K_not_need-post-for-gather-obs8_p1_2)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs8_p1_2)))
    (:action gather-obs8_p3_1
        :precondition (and (K_normal-execution) (K_need-gather-obs8-at_p3_1))
        :effect (and (not (K_not_need-post-for-gather-obs8_p3_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs8_p3_1)))
    (:action gather-obs8_p2_1
        :precondition (and (K_normal-execution) (K_need-gather-obs8-at_p2_1))
        :effect (and (not (K_not_need-post-for-gather-obs8_p2_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs8_p2_1)))
    (:action gather-obs8_p1_1
        :precondition (and (K_normal-execution) (K_need-gather-obs8-at_p1_1))
        :effect (and (not (K_not_need-post-for-gather-obs8_p1_1)) (not (K_normal-execution)) (K_not_normal-execution) (K_need-post-for-gather-obs8_p1_1)))
    (:action advance-gather-counter_p3_4
        :precondition (K_normal-execution)
        :effect (and (not (K_need-gather-obs0-at_p3_4)) (K_not_need-gather-obs0-at_p3_4)
                     (when (K_need-gather-obs0-at_p3_4) (and (K_not_need-gather-obs0-at_p3_4) (K_need-gather-obs1-at_p3_4)))
                     (when (not (K_not_need-gather-obs0-at_p3_4)) (and (not (K_not_need-gather-obs1-at_p3_4)) (not (K_need-gather-obs0-at_p3_4))))
                     (when (K_need-gather-obs1-at_p3_4) (and (K_not_need-gather-obs1-at_p3_4) (K_need-gather-obs2-at_p3_4)))
                     (when (not (K_not_need-gather-obs1-at_p3_4)) (and (not (K_not_need-gather-obs2-at_p3_4)) (not (K_need-gather-obs1-at_p3_4))))
                     (when (K_need-gather-obs2-at_p3_4) (and (K_not_need-gather-obs2-at_p3_4) (K_need-gather-obs3-at_p3_4)))
                     (when (not (K_not_need-gather-obs2-at_p3_4)) (and (not (K_not_need-gather-obs3-at_p3_4)) (not (K_need-gather-obs2-at_p3_4))))
                     (when (K_need-gather-obs3-at_p3_4) (and (K_not_need-gather-obs3-at_p3_4) (K_need-gather-obs4-at_p3_4)))
                     (when (not (K_not_need-gather-obs3-at_p3_4)) (and (not (K_not_need-gather-obs4-at_p3_4)) (not (K_need-gather-obs3-at_p3_4))))
                     (when (K_need-gather-obs4-at_p3_4) (and (K_not_need-gather-obs4-at_p3_4) (K_need-gather-obs5-at_p3_4)))
                     (when (not (K_not_need-gather-obs4-at_p3_4)) (and (not (K_not_need-gather-obs5-at_p3_4)) (not (K_need-gather-obs4-at_p3_4))))
                     (when (K_need-gather-obs5-at_p3_4) (and (K_not_need-gather-obs5-at_p3_4) (K_need-gather-obs6-at_p3_4)))
                     (when (not (K_not_need-gather-obs5-at_p3_4)) (and (not (K_not_need-gather-obs6-at_p3_4)) (not (K_need-gather-obs5-at_p3_4))))
                     (when (K_need-gather-obs6-at_p3_4) (and (K_not_need-gather-obs6-at_p3_4) (K_need-gather-obs7-at_p3_4)))
                     (when (not (K_not_need-gather-obs6-at_p3_4)) (and (not (K_not_need-gather-obs7-at_p3_4)) (not (K_need-gather-obs6-at_p3_4))))
                     (when (K_need-gather-obs7-at_p3_4) (and (K_not_need-gather-obs7-at_p3_4) (K_need-gather-obs8-at_p3_4)))
                     (when (not (K_not_need-gather-obs7-at_p3_4)) (and (not (K_not_need-gather-obs8-at_p3_4)) (not (K_need-gather-obs7-at_p3_4))))
                     (when (K_need-gather-obs8-at_p3_4) (and (K_need-advance-step) (K_not_need-gather-obs8-at_p3_4)))
                     (when (not (K_not_need-gather-obs8-at_p3_4)) (and (not (K_need-gather-obs8-at_p3_4)) (not (K_not_need-advance-step))))
                     (when (K_not_need-gather-obs0-at_p3_4) (K_not_need-gather-obs1-at_p3_4))
                     (when (not (K_need-gather-obs0-at_p3_4)) (not (K_need-gather-obs1-at_p3_4)))
                     (when (K_not_need-gather-obs1-at_p3_4) (K_not_need-gather-obs2-at_p3_4))
                     (when (not (K_need-gather-obs1-at_p3_4)) (not (K_need-gather-obs2-at_p3_4)))
                     (when (K_not_need-gather-obs2-at_p3_4) (K_not_need-gather-obs3-at_p3_4))
                     (when (not (K_need-gather-obs2-at_p3_4)) (not (K_need-gather-obs3-at_p3_4)))
                     (when (K_not_need-gather-obs3-at_p3_4) (K_not_need-gather-obs4-at_p3_4))
                     (when (not (K_need-gather-obs3-at_p3_4)) (not (K_need-gather-obs4-at_p3_4)))
                     (when (K_not_need-gather-obs4-at_p3_4) (K_not_need-gather-obs5-at_p3_4))
                     (when (not (K_need-gather-obs4-at_p3_4)) (not (K_need-gather-obs5-at_p3_4)))
                     (when (K_not_need-gather-obs5-at_p3_4) (K_not_need-gather-obs6-at_p3_4))
                     (when (not (K_need-gather-obs5-at_p3_4)) (not (K_need-gather-obs6-at_p3_4)))
                     (when (K_not_need-gather-obs6-at_p3_4) (K_not_need-gather-obs7-at_p3_4))
                     (when (not (K_need-gather-obs6-at_p3_4)) (not (K_need-gather-obs7-at_p3_4)))
                     (when (K_not_need-gather-obs7-at_p3_4) (K_not_need-gather-obs8-at_p3_4))
                     (when (not (K_need-gather-obs7-at_p3_4)) (not (K_need-gather-obs8-at_p3_4)))))
    (:action advance-gather-counter_p2_4
        :precondition (K_normal-execution)
        :effect (and (not (K_need-gather-obs0-at_p2_4)) (K_not_need-gather-obs0-at_p2_4)
                     (when (K_need-gather-obs0-at_p2_4) (and (K_not_need-gather-obs0-at_p2_4) (K_need-gather-obs1-at_p2_4)))
                     (when (not (K_not_need-gather-obs0-at_p2_4)) (and (not (K_not_need-gather-obs1-at_p2_4)) (not (K_need-gather-obs0-at_p2_4))))
                     (when (K_need-gather-obs1-at_p2_4) (and (K_not_need-gather-obs1-at_p2_4) (K_need-gather-obs2-at_p2_4)))
                     (when (not (K_not_need-gather-obs1-at_p2_4)) (and (not (K_not_need-gather-obs2-at_p2_4)) (not (K_need-gather-obs1-at_p2_4))))
                     (when (K_need-gather-obs2-at_p2_4) (and (K_not_need-gather-obs2-at_p2_4) (K_need-gather-obs3-at_p2_4)))
                     (when (not (K_not_need-gather-obs2-at_p2_4)) (and (not (K_not_need-gather-obs3-at_p2_4)) (not (K_need-gather-obs2-at_p2_4))))
                     (when (K_need-gather-obs3-at_p2_4) (and (K_not_need-gather-obs3-at_p2_4) (K_need-gather-obs4-at_p2_4)))
                     (when (not (K_not_need-gather-obs3-at_p2_4)) (and (not (K_not_need-gather-obs4-at_p2_4)) (not (K_need-gather-obs3-at_p2_4))))
                     (when (K_need-gather-obs4-at_p2_4) (and (K_not_need-gather-obs4-at_p2_4) (K_need-gather-obs5-at_p2_4)))
                     (when (not (K_not_need-gather-obs4-at_p2_4)) (and (not (K_not_need-gather-obs5-at_p2_4)) (not (K_need-gather-obs4-at_p2_4))))
                     (when (K_need-gather-obs5-at_p2_4) (and (K_not_need-gather-obs5-at_p2_4) (K_need-gather-obs6-at_p2_4)))
                     (when (not (K_not_need-gather-obs5-at_p2_4)) (and (not (K_not_need-gather-obs6-at_p2_4)) (not (K_need-gather-obs5-at_p2_4))))
                     (when (K_need-gather-obs6-at_p2_4) (and (K_not_need-gather-obs6-at_p2_4) (K_need-gather-obs7-at_p2_4)))
                     (when (not (K_not_need-gather-obs6-at_p2_4)) (and (not (K_not_need-gather-obs7-at_p2_4)) (not (K_need-gather-obs6-at_p2_4))))
                     (when (K_need-gather-obs7-at_p2_4) (and (K_not_need-gather-obs7-at_p2_4) (K_need-gather-obs8-at_p2_4)))
                     (when (not (K_not_need-gather-obs7-at_p2_4)) (and (not (K_not_need-gather-obs8-at_p2_4)) (not (K_need-gather-obs7-at_p2_4))))
                     (when (K_need-gather-obs8-at_p2_4) (and (K_need-advance-step) (K_not_need-gather-obs8-at_p2_4)))
                     (when (not (K_not_need-gather-obs8-at_p2_4)) (and (not (K_need-gather-obs8-at_p2_4)) (not (K_not_need-advance-step))))
                     (when (K_not_need-gather-obs0-at_p2_4) (K_not_need-gather-obs1-at_p2_4))
                     (when (not (K_need-gather-obs0-at_p2_4)) (not (K_need-gather-obs1-at_p2_4)))
                     (when (K_not_need-gather-obs1-at_p2_4) (K_not_need-gather-obs2-at_p2_4))
                     (when (not (K_need-gather-obs1-at_p2_4)) (not (K_need-gather-obs2-at_p2_4)))
                     (when (K_not_need-gather-obs2-at_p2_4) (K_not_need-gather-obs3-at_p2_4))
                     (when (not (K_need-gather-obs2-at_p2_4)) (not (K_need-gather-obs3-at_p2_4)))
                     (when (K_not_need-gather-obs3-at_p2_4) (K_not_need-gather-obs4-at_p2_4))
                     (when (not (K_need-gather-obs3-at_p2_4)) (not (K_need-gather-obs4-at_p2_4)))
                     (when (K_not_need-gather-obs4-at_p2_4) (K_not_need-gather-obs5-at_p2_4))
                     (when (not (K_need-gather-obs4-at_p2_4)) (not (K_need-gather-obs5-at_p2_4)))
                     (when (K_not_need-gather-obs5-at_p2_4) (K_not_need-gather-obs6-at_p2_4))
                     (when (not (K_need-gather-obs5-at_p2_4)) (not (K_need-gather-obs6-at_p2_4)))
                     (when (K_not_need-gather-obs6-at_p2_4) (K_not_need-gather-obs7-at_p2_4))
                     (when (not (K_need-gather-obs6-at_p2_4)) (not (K_need-gather-obs7-at_p2_4)))
                     (when (K_not_need-gather-obs7-at_p2_4) (K_not_need-gather-obs8-at_p2_4))
                     (when (not (K_need-gather-obs7-at_p2_4)) (not (K_need-gather-obs8-at_p2_4)))))
    (:action advance-gather-counter_p1_4
        :precondition (K_normal-execution)
        :effect (and (not (K_need-gather-obs0-at_p1_4)) (K_not_need-gather-obs0-at_p1_4)
                     (when (K_need-gather-obs0-at_p1_4) (and (K_not_need-gather-obs0-at_p1_4) (K_need-gather-obs1-at_p1_4)))
                     (when (not (K_not_need-gather-obs0-at_p1_4)) (and (not (K_not_need-gather-obs1-at_p1_4)) (not (K_need-gather-obs0-at_p1_4))))
                     (when (K_need-gather-obs1-at_p1_4) (and (K_not_need-gather-obs1-at_p1_4) (K_need-gather-obs2-at_p1_4)))
                     (when (not (K_not_need-gather-obs1-at_p1_4)) (and (not (K_not_need-gather-obs2-at_p1_4)) (not (K_need-gather-obs1-at_p1_4))))
                     (when (K_need-gather-obs2-at_p1_4) (and (K_not_need-gather-obs2-at_p1_4) (K_need-gather-obs3-at_p1_4)))
                     (when (not (K_not_need-gather-obs2-at_p1_4)) (and (not (K_not_need-gather-obs3-at_p1_4)) (not (K_need-gather-obs2-at_p1_4))))
                     (when (K_need-gather-obs3-at_p1_4) (and (K_not_need-gather-obs3-at_p1_4) (K_need-gather-obs4-at_p1_4)))
                     (when (not (K_not_need-gather-obs3-at_p1_4)) (and (not (K_not_need-gather-obs4-at_p1_4)) (not (K_need-gather-obs3-at_p1_4))))
                     (when (K_need-gather-obs4-at_p1_4) (and (K_not_need-gather-obs4-at_p1_4) (K_need-gather-obs5-at_p1_4)))
                     (when (not (K_not_need-gather-obs4-at_p1_4)) (and (not (K_not_need-gather-obs5-at_p1_4)) (not (K_need-gather-obs4-at_p1_4))))
                     (when (K_need-gather-obs5-at_p1_4) (and (K_not_need-gather-obs5-at_p1_4) (K_need-gather-obs6-at_p1_4)))
                     (when (not (K_not_need-gather-obs5-at_p1_4)) (and (not (K_not_need-gather-obs6-at_p1_4)) (not (K_need-gather-obs5-at_p1_4))))
                     (when (K_need-gather-obs6-at_p1_4) (and (K_not_need-gather-obs6-at_p1_4) (K_need-gather-obs7-at_p1_4)))
                     (when (not (K_not_need-gather-obs6-at_p1_4)) (and (not (K_not_need-gather-obs7-at_p1_4)) (not (K_need-gather-obs6-at_p1_4))))
                     (when (K_need-gather-obs7-at_p1_4) (and (K_not_need-gather-obs7-at_p1_4) (K_need-gather-obs8-at_p1_4)))
                     (when (not (K_not_need-gather-obs7-at_p1_4)) (and (not (K_not_need-gather-obs8-at_p1_4)) (not (K_need-gather-obs7-at_p1_4))))
                     (when (K_need-gather-obs8-at_p1_4) (and (K_need-advance-step) (K_not_need-gather-obs8-at_p1_4)))
                     (when (not (K_not_need-gather-obs8-at_p1_4)) (and (not (K_need-gather-obs8-at_p1_4)) (not (K_not_need-advance-step))))
                     (when (K_not_need-gather-obs0-at_p1_4) (K_not_need-gather-obs1-at_p1_4))
                     (when (not (K_need-gather-obs0-at_p1_4)) (not (K_need-gather-obs1-at_p1_4)))
                     (when (K_not_need-gather-obs1-at_p1_4) (K_not_need-gather-obs2-at_p1_4))
                     (when (not (K_need-gather-obs1-at_p1_4)) (not (K_need-gather-obs2-at_p1_4)))
                     (when (K_not_need-gather-obs2-at_p1_4) (K_not_need-gather-obs3-at_p1_4))
                     (when (not (K_need-gather-obs2-at_p1_4)) (not (K_need-gather-obs3-at_p1_4)))
                     (when (K_not_need-gather-obs3-at_p1_4) (K_not_need-gather-obs4-at_p1_4))
                     (when (not (K_need-gather-obs3-at_p1_4)) (not (K_need-gather-obs4-at_p1_4)))
                     (when (K_not_need-gather-obs4-at_p1_4) (K_not_need-gather-obs5-at_p1_4))
                     (when (not (K_need-gather-obs4-at_p1_4)) (not (K_need-gather-obs5-at_p1_4)))
                     (when (K_not_need-gather-obs5-at_p1_4) (K_not_need-gather-obs6-at_p1_4))
                     (when (not (K_need-gather-obs5-at_p1_4)) (not (K_need-gather-obs6-at_p1_4)))
                     (when (K_not_need-gather-obs6-at_p1_4) (K_not_need-gather-obs7-at_p1_4))
                     (when (not (K_need-gather-obs6-at_p1_4)) (not (K_need-gather-obs7-at_p1_4)))
                     (when (K_not_need-gather-obs7-at_p1_4) (K_not_need-gather-obs8-at_p1_4))
                     (when (not (K_need-gather-obs7-at_p1_4)) (not (K_need-gather-obs8-at_p1_4)))))
    (:action advance-gather-counter_p3_3
        :precondition (K_normal-execution)
        :effect (and (not (K_need-gather-obs0-at_p3_3)) (K_not_need-gather-obs0-at_p3_3)
                     (when (K_need-gather-obs0-at_p3_3) (and (K_not_need-gather-obs0-at_p3_3) (K_need-gather-obs1-at_p3_3)))
                     (when (not (K_not_need-gather-obs0-at_p3_3)) (and (not (K_not_need-gather-obs1-at_p3_3)) (not (K_need-gather-obs0-at_p3_3))))
                     (when (K_need-gather-obs1-at_p3_3) (and (K_not_need-gather-obs1-at_p3_3) (K_need-gather-obs2-at_p3_3)))
                     (when (not (K_not_need-gather-obs1-at_p3_3)) (and (not (K_not_need-gather-obs2-at_p3_3)) (not (K_need-gather-obs1-at_p3_3))))
                     (when (K_need-gather-obs2-at_p3_3) (and (K_not_need-gather-obs2-at_p3_3) (K_need-gather-obs3-at_p3_3)))
                     (when (not (K_not_need-gather-obs2-at_p3_3)) (and (not (K_not_need-gather-obs3-at_p3_3)) (not (K_need-gather-obs2-at_p3_3))))
                     (when (K_need-gather-obs3-at_p3_3) (and (K_not_need-gather-obs3-at_p3_3) (K_need-gather-obs4-at_p3_3)))
                     (when (not (K_not_need-gather-obs3-at_p3_3)) (and (not (K_not_need-gather-obs4-at_p3_3)) (not (K_need-gather-obs3-at_p3_3))))
                     (when (K_need-gather-obs4-at_p3_3) (and (K_not_need-gather-obs4-at_p3_3) (K_need-gather-obs5-at_p3_3)))
                     (when (not (K_not_need-gather-obs4-at_p3_3)) (and (not (K_not_need-gather-obs5-at_p3_3)) (not (K_need-gather-obs4-at_p3_3))))
                     (when (K_need-gather-obs5-at_p3_3) (and (K_not_need-gather-obs5-at_p3_3) (K_need-gather-obs6-at_p3_3)))
                     (when (not (K_not_need-gather-obs5-at_p3_3)) (and (not (K_not_need-gather-obs6-at_p3_3)) (not (K_need-gather-obs5-at_p3_3))))
                     (when (K_need-gather-obs6-at_p3_3) (and (K_not_need-gather-obs6-at_p3_3) (K_need-gather-obs7-at_p3_3)))
                     (when (not (K_not_need-gather-obs6-at_p3_3)) (and (not (K_not_need-gather-obs7-at_p3_3)) (not (K_need-gather-obs6-at_p3_3))))
                     (when (K_need-gather-obs7-at_p3_3) (and (K_not_need-gather-obs7-at_p3_3) (K_need-gather-obs8-at_p3_3)))
                     (when (not (K_not_need-gather-obs7-at_p3_3)) (and (not (K_not_need-gather-obs8-at_p3_3)) (not (K_need-gather-obs7-at_p3_3))))
                     (when (K_need-gather-obs8-at_p3_3) (and (K_need-advance-step) (K_not_need-gather-obs8-at_p3_3)))
                     (when (not (K_not_need-gather-obs8-at_p3_3)) (and (not (K_need-gather-obs8-at_p3_3)) (not (K_not_need-advance-step))))
                     (when (K_not_need-gather-obs0-at_p3_3) (K_not_need-gather-obs1-at_p3_3))
                     (when (not (K_need-gather-obs0-at_p3_3)) (not (K_need-gather-obs1-at_p3_3)))
                     (when (K_not_need-gather-obs1-at_p3_3) (K_not_need-gather-obs2-at_p3_3))
                     (when (not (K_need-gather-obs1-at_p3_3)) (not (K_need-gather-obs2-at_p3_3)))
                     (when (K_not_need-gather-obs2-at_p3_3) (K_not_need-gather-obs3-at_p3_3))
                     (when (not (K_need-gather-obs2-at_p3_3)) (not (K_need-gather-obs3-at_p3_3)))
                     (when (K_not_need-gather-obs3-at_p3_3) (K_not_need-gather-obs4-at_p3_3))
                     (when (not (K_need-gather-obs3-at_p3_3)) (not (K_need-gather-obs4-at_p3_3)))
                     (when (K_not_need-gather-obs4-at_p3_3) (K_not_need-gather-obs5-at_p3_3))
                     (when (not (K_need-gather-obs4-at_p3_3)) (not (K_need-gather-obs5-at_p3_3)))
                     (when (K_not_need-gather-obs5-at_p3_3) (K_not_need-gather-obs6-at_p3_3))
                     (when (not (K_need-gather-obs5-at_p3_3)) (not (K_need-gather-obs6-at_p3_3)))
                     (when (K_not_need-gather-obs6-at_p3_3) (K_not_need-gather-obs7-at_p3_3))
                     (when (not (K_need-gather-obs6-at_p3_3)) (not (K_need-gather-obs7-at_p3_3)))
                     (when (K_not_need-gather-obs7-at_p3_3) (K_not_need-gather-obs8-at_p3_3))
                     (when (not (K_need-gather-obs7-at_p3_3)) (not (K_need-gather-obs8-at_p3_3)))))
    (:action advance-gather-counter_p3_2
        :precondition (K_normal-execution)
        :effect (and (not (K_need-gather-obs0-at_p3_2)) (K_not_need-gather-obs0-at_p3_2)
                     (when (K_need-gather-obs0-at_p3_2) (and (K_not_need-gather-obs0-at_p3_2) (K_need-gather-obs1-at_p3_2)))
                     (when (not (K_not_need-gather-obs0-at_p3_2)) (and (not (K_not_need-gather-obs1-at_p3_2)) (not (K_need-gather-obs0-at_p3_2))))
                     (when (K_need-gather-obs1-at_p3_2) (and (K_not_need-gather-obs1-at_p3_2) (K_need-gather-obs2-at_p3_2)))
                     (when (not (K_not_need-gather-obs1-at_p3_2)) (and (not (K_not_need-gather-obs2-at_p3_2)) (not (K_need-gather-obs1-at_p3_2))))
                     (when (K_need-gather-obs2-at_p3_2) (and (K_not_need-gather-obs2-at_p3_2) (K_need-gather-obs3-at_p3_2)))
                     (when (not (K_not_need-gather-obs2-at_p3_2)) (and (not (K_not_need-gather-obs3-at_p3_2)) (not (K_need-gather-obs2-at_p3_2))))
                     (when (K_need-gather-obs3-at_p3_2) (and (K_not_need-gather-obs3-at_p3_2) (K_need-gather-obs4-at_p3_2)))
                     (when (not (K_not_need-gather-obs3-at_p3_2)) (and (not (K_not_need-gather-obs4-at_p3_2)) (not (K_need-gather-obs3-at_p3_2))))
                     (when (K_need-gather-obs4-at_p3_2) (and (K_not_need-gather-obs4-at_p3_2) (K_need-gather-obs5-at_p3_2)))
                     (when (not (K_not_need-gather-obs4-at_p3_2)) (and (not (K_not_need-gather-obs5-at_p3_2)) (not (K_need-gather-obs4-at_p3_2))))
                     (when (K_need-gather-obs5-at_p3_2) (and (K_not_need-gather-obs5-at_p3_2) (K_need-gather-obs6-at_p3_2)))
                     (when (not (K_not_need-gather-obs5-at_p3_2)) (and (not (K_not_need-gather-obs6-at_p3_2)) (not (K_need-gather-obs5-at_p3_2))))
                     (when (K_need-gather-obs6-at_p3_2) (and (K_not_need-gather-obs6-at_p3_2) (K_need-gather-obs7-at_p3_2)))
                     (when (not (K_not_need-gather-obs6-at_p3_2)) (and (not (K_not_need-gather-obs7-at_p3_2)) (not (K_need-gather-obs6-at_p3_2))))
                     (when (K_need-gather-obs7-at_p3_2) (and (K_not_need-gather-obs7-at_p3_2) (K_need-gather-obs8-at_p3_2)))
                     (when (not (K_not_need-gather-obs7-at_p3_2)) (and (not (K_not_need-gather-obs8-at_p3_2)) (not (K_need-gather-obs7-at_p3_2))))
                     (when (K_need-gather-obs8-at_p3_2) (and (K_need-advance-step) (K_not_need-gather-obs8-at_p3_2)))
                     (when (not (K_not_need-gather-obs8-at_p3_2)) (and (not (K_need-gather-obs8-at_p3_2)) (not (K_not_need-advance-step))))
                     (when (K_not_need-gather-obs0-at_p3_2) (K_not_need-gather-obs1-at_p3_2))
                     (when (not (K_need-gather-obs0-at_p3_2)) (not (K_need-gather-obs1-at_p3_2)))
                     (when (K_not_need-gather-obs1-at_p3_2) (K_not_need-gather-obs2-at_p3_2))
                     (when (not (K_need-gather-obs1-at_p3_2)) (not (K_need-gather-obs2-at_p3_2)))
                     (when (K_not_need-gather-obs2-at_p3_2) (K_not_need-gather-obs3-at_p3_2))
                     (when (not (K_need-gather-obs2-at_p3_2)) (not (K_need-gather-obs3-at_p3_2)))
                     (when (K_not_need-gather-obs3-at_p3_2) (K_not_need-gather-obs4-at_p3_2))
                     (when (not (K_need-gather-obs3-at_p3_2)) (not (K_need-gather-obs4-at_p3_2)))
                     (when (K_not_need-gather-obs4-at_p3_2) (K_not_need-gather-obs5-at_p3_2))
                     (when (not (K_need-gather-obs4-at_p3_2)) (not (K_need-gather-obs5-at_p3_2)))
                     (when (K_not_need-gather-obs5-at_p3_2) (K_not_need-gather-obs6-at_p3_2))
                     (when (not (K_need-gather-obs5-at_p3_2)) (not (K_need-gather-obs6-at_p3_2)))
                     (when (K_not_need-gather-obs6-at_p3_2) (K_not_need-gather-obs7-at_p3_2))
                     (when (not (K_need-gather-obs6-at_p3_2)) (not (K_need-gather-obs7-at_p3_2)))
                     (when (K_not_need-gather-obs7-at_p3_2) (K_not_need-gather-obs8-at_p3_2))
                     (when (not (K_need-gather-obs7-at_p3_2)) (not (K_need-gather-obs8-at_p3_2)))))
    (:action advance-gather-counter_p2_2
        :precondition (K_normal-execution)
        :effect (and (not (K_need-gather-obs0-at_p2_2)) (K_not_need-gather-obs0-at_p2_2)
                     (when (K_need-gather-obs0-at_p2_2) (and (K_not_need-gather-obs0-at_p2_2) (K_need-gather-obs1-at_p2_2)))
                     (when (not (K_not_need-gather-obs0-at_p2_2)) (and (not (K_not_need-gather-obs1-at_p2_2)) (not (K_need-gather-obs0-at_p2_2))))
                     (when (K_need-gather-obs1-at_p2_2) (and (K_not_need-gather-obs1-at_p2_2) (K_need-gather-obs2-at_p2_2)))
                     (when (not (K_not_need-gather-obs1-at_p2_2)) (and (not (K_not_need-gather-obs2-at_p2_2)) (not (K_need-gather-obs1-at_p2_2))))
                     (when (K_need-gather-obs2-at_p2_2) (and (K_not_need-gather-obs2-at_p2_2) (K_need-gather-obs3-at_p2_2)))
                     (when (not (K_not_need-gather-obs2-at_p2_2)) (and (not (K_not_need-gather-obs3-at_p2_2)) (not (K_need-gather-obs2-at_p2_2))))
                     (when (K_need-gather-obs3-at_p2_2) (and (K_not_need-gather-obs3-at_p2_2) (K_need-gather-obs4-at_p2_2)))
                     (when (not (K_not_need-gather-obs3-at_p2_2)) (and (not (K_not_need-gather-obs4-at_p2_2)) (not (K_need-gather-obs3-at_p2_2))))
                     (when (K_need-gather-obs4-at_p2_2) (and (K_not_need-gather-obs4-at_p2_2) (K_need-gather-obs5-at_p2_2)))
                     (when (not (K_not_need-gather-obs4-at_p2_2)) (and (not (K_not_need-gather-obs5-at_p2_2)) (not (K_need-gather-obs4-at_p2_2))))
                     (when (K_need-gather-obs5-at_p2_2) (and (K_not_need-gather-obs5-at_p2_2) (K_need-gather-obs6-at_p2_2)))
                     (when (not (K_not_need-gather-obs5-at_p2_2)) (and (not (K_not_need-gather-obs6-at_p2_2)) (not (K_need-gather-obs5-at_p2_2))))
                     (when (K_need-gather-obs6-at_p2_2) (and (K_not_need-gather-obs6-at_p2_2) (K_need-gather-obs7-at_p2_2)))
                     (when (not (K_not_need-gather-obs6-at_p2_2)) (and (not (K_not_need-gather-obs7-at_p2_2)) (not (K_need-gather-obs6-at_p2_2))))
                     (when (K_need-gather-obs7-at_p2_2) (and (K_not_need-gather-obs7-at_p2_2) (K_need-gather-obs8-at_p2_2)))
                     (when (not (K_not_need-gather-obs7-at_p2_2)) (and (not (K_not_need-gather-obs8-at_p2_2)) (not (K_need-gather-obs7-at_p2_2))))
                     (when (K_need-gather-obs8-at_p2_2) (and (K_need-advance-step) (K_not_need-gather-obs8-at_p2_2)))
                     (when (not (K_not_need-gather-obs8-at_p2_2)) (and (not (K_need-gather-obs8-at_p2_2)) (not (K_not_need-advance-step))))
                     (when (K_not_need-gather-obs0-at_p2_2) (K_not_need-gather-obs1-at_p2_2))
                     (when (not (K_need-gather-obs0-at_p2_2)) (not (K_need-gather-obs1-at_p2_2)))
                     (when (K_not_need-gather-obs1-at_p2_2) (K_not_need-gather-obs2-at_p2_2))
                     (when (not (K_need-gather-obs1-at_p2_2)) (not (K_need-gather-obs2-at_p2_2)))
                     (when (K_not_need-gather-obs2-at_p2_2) (K_not_need-gather-obs3-at_p2_2))
                     (when (not (K_need-gather-obs2-at_p2_2)) (not (K_need-gather-obs3-at_p2_2)))
                     (when (K_not_need-gather-obs3-at_p2_2) (K_not_need-gather-obs4-at_p2_2))
                     (when (not (K_need-gather-obs3-at_p2_2)) (not (K_need-gather-obs4-at_p2_2)))
                     (when (K_not_need-gather-obs4-at_p2_2) (K_not_need-gather-obs5-at_p2_2))
                     (when (not (K_need-gather-obs4-at_p2_2)) (not (K_need-gather-obs5-at_p2_2)))
                     (when (K_not_need-gather-obs5-at_p2_2) (K_not_need-gather-obs6-at_p2_2))
                     (when (not (K_need-gather-obs5-at_p2_2)) (not (K_need-gather-obs6-at_p2_2)))
                     (when (K_not_need-gather-obs6-at_p2_2) (K_not_need-gather-obs7-at_p2_2))
                     (when (not (K_need-gather-obs6-at_p2_2)) (not (K_need-gather-obs7-at_p2_2)))
                     (when (K_not_need-gather-obs7-at_p2_2) (K_not_need-gather-obs8-at_p2_2))
                     (when (not (K_need-gather-obs7-at_p2_2)) (not (K_need-gather-obs8-at_p2_2)))))
    (:action advance-gather-counter_p1_2
        :precondition (K_normal-execution)
        :effect (and (not (K_need-gather-obs0-at_p1_2)) (K_not_need-gather-obs0-at_p1_2)
                     (when (K_need-gather-obs0-at_p1_2) (and (K_not_need-gather-obs0-at_p1_2) (K_need-gather-obs1-at_p1_2)))
                     (when (not (K_not_need-gather-obs0-at_p1_2)) (and (not (K_not_need-gather-obs1-at_p1_2)) (not (K_need-gather-obs0-at_p1_2))))
                     (when (K_need-gather-obs1-at_p1_2) (and (K_not_need-gather-obs1-at_p1_2) (K_need-gather-obs2-at_p1_2)))
                     (when (not (K_not_need-gather-obs1-at_p1_2)) (and (not (K_not_need-gather-obs2-at_p1_2)) (not (K_need-gather-obs1-at_p1_2))))
                     (when (K_need-gather-obs2-at_p1_2) (and (K_not_need-gather-obs2-at_p1_2) (K_need-gather-obs3-at_p1_2)))
                     (when (not (K_not_need-gather-obs2-at_p1_2)) (and (not (K_not_need-gather-obs3-at_p1_2)) (not (K_need-gather-obs2-at_p1_2))))
                     (when (K_need-gather-obs3-at_p1_2) (and (K_not_need-gather-obs3-at_p1_2) (K_need-gather-obs4-at_p1_2)))
                     (when (not (K_not_need-gather-obs3-at_p1_2)) (and (not (K_not_need-gather-obs4-at_p1_2)) (not (K_need-gather-obs3-at_p1_2))))
                     (when (K_need-gather-obs4-at_p1_2) (and (K_not_need-gather-obs4-at_p1_2) (K_need-gather-obs5-at_p1_2)))
                     (when (not (K_not_need-gather-obs4-at_p1_2)) (and (not (K_not_need-gather-obs5-at_p1_2)) (not (K_need-gather-obs4-at_p1_2))))
                     (when (K_need-gather-obs5-at_p1_2) (and (K_not_need-gather-obs5-at_p1_2) (K_need-gather-obs6-at_p1_2)))
                     (when (not (K_not_need-gather-obs5-at_p1_2)) (and (not (K_not_need-gather-obs6-at_p1_2)) (not (K_need-gather-obs5-at_p1_2))))
                     (when (K_need-gather-obs6-at_p1_2) (and (K_not_need-gather-obs6-at_p1_2) (K_need-gather-obs7-at_p1_2)))
                     (when (not (K_not_need-gather-obs6-at_p1_2)) (and (not (K_not_need-gather-obs7-at_p1_2)) (not (K_need-gather-obs6-at_p1_2))))
                     (when (K_need-gather-obs7-at_p1_2) (and (K_not_need-gather-obs7-at_p1_2) (K_need-gather-obs8-at_p1_2)))
                     (when (not (K_not_need-gather-obs7-at_p1_2)) (and (not (K_not_need-gather-obs8-at_p1_2)) (not (K_need-gather-obs7-at_p1_2))))
                     (when (K_need-gather-obs8-at_p1_2) (and (K_need-advance-step) (K_not_need-gather-obs8-at_p1_2)))
                     (when (not (K_not_need-gather-obs8-at_p1_2)) (and (not (K_need-gather-obs8-at_p1_2)) (not (K_not_need-advance-step))))
                     (when (K_not_need-gather-obs0-at_p1_2) (K_not_need-gather-obs1-at_p1_2))
                     (when (not (K_need-gather-obs0-at_p1_2)) (not (K_need-gather-obs1-at_p1_2)))
                     (when (K_not_need-gather-obs1-at_p1_2) (K_not_need-gather-obs2-at_p1_2))
                     (when (not (K_need-gather-obs1-at_p1_2)) (not (K_need-gather-obs2-at_p1_2)))
                     (when (K_not_need-gather-obs2-at_p1_2) (K_not_need-gather-obs3-at_p1_2))
                     (when (not (K_need-gather-obs2-at_p1_2)) (not (K_need-gather-obs3-at_p1_2)))
                     (when (K_not_need-gather-obs3-at_p1_2) (K_not_need-gather-obs4-at_p1_2))
                     (when (not (K_need-gather-obs3-at_p1_2)) (not (K_need-gather-obs4-at_p1_2)))
                     (when (K_not_need-gather-obs4-at_p1_2) (K_not_need-gather-obs5-at_p1_2))
                     (when (not (K_need-gather-obs4-at_p1_2)) (not (K_need-gather-obs5-at_p1_2)))
                     (when (K_not_need-gather-obs5-at_p1_2) (K_not_need-gather-obs6-at_p1_2))
                     (when (not (K_need-gather-obs5-at_p1_2)) (not (K_need-gather-obs6-at_p1_2)))
                     (when (K_not_need-gather-obs6-at_p1_2) (K_not_need-gather-obs7-at_p1_2))
                     (when (not (K_need-gather-obs6-at_p1_2)) (not (K_need-gather-obs7-at_p1_2)))
                     (when (K_not_need-gather-obs7-at_p1_2) (K_not_need-gather-obs8-at_p1_2))
                     (when (not (K_need-gather-obs7-at_p1_2)) (not (K_need-gather-obs8-at_p1_2)))))
    (:action advance-gather-counter_p3_1
        :precondition (K_normal-execution)
        :effect (and (not (K_need-gather-obs0-at_p3_1)) (K_not_need-gather-obs0-at_p3_1)
                     (when (K_need-gather-obs0-at_p3_1) (and (K_not_need-gather-obs0-at_p3_1) (K_need-gather-obs1-at_p3_1)))
                     (when (not (K_not_need-gather-obs0-at_p3_1)) (and (not (K_not_need-gather-obs1-at_p3_1)) (not (K_need-gather-obs0-at_p3_1))))
                     (when (K_need-gather-obs1-at_p3_1) (and (K_not_need-gather-obs1-at_p3_1) (K_need-gather-obs2-at_p3_1)))
                     (when (not (K_not_need-gather-obs1-at_p3_1)) (and (not (K_not_need-gather-obs2-at_p3_1)) (not (K_need-gather-obs1-at_p3_1))))
                     (when (K_need-gather-obs2-at_p3_1) (and (K_not_need-gather-obs2-at_p3_1) (K_need-gather-obs3-at_p3_1)))
                     (when (not (K_not_need-gather-obs2-at_p3_1)) (and (not (K_not_need-gather-obs3-at_p3_1)) (not (K_need-gather-obs2-at_p3_1))))
                     (when (K_need-gather-obs3-at_p3_1) (and (K_not_need-gather-obs3-at_p3_1) (K_need-gather-obs4-at_p3_1)))
                     (when (not (K_not_need-gather-obs3-at_p3_1)) (and (not (K_not_need-gather-obs4-at_p3_1)) (not (K_need-gather-obs3-at_p3_1))))
                     (when (K_need-gather-obs4-at_p3_1) (and (K_not_need-gather-obs4-at_p3_1) (K_need-gather-obs5-at_p3_1)))
                     (when (not (K_not_need-gather-obs4-at_p3_1)) (and (not (K_not_need-gather-obs5-at_p3_1)) (not (K_need-gather-obs4-at_p3_1))))
                     (when (K_need-gather-obs5-at_p3_1) (and (K_not_need-gather-obs5-at_p3_1) (K_need-gather-obs6-at_p3_1)))
                     (when (not (K_not_need-gather-obs5-at_p3_1)) (and (not (K_not_need-gather-obs6-at_p3_1)) (not (K_need-gather-obs5-at_p3_1))))
                     (when (K_need-gather-obs6-at_p3_1) (and (K_not_need-gather-obs6-at_p3_1) (K_need-gather-obs7-at_p3_1)))
                     (when (not (K_not_need-gather-obs6-at_p3_1)) (and (not (K_not_need-gather-obs7-at_p3_1)) (not (K_need-gather-obs6-at_p3_1))))
                     (when (K_need-gather-obs7-at_p3_1) (and (K_not_need-gather-obs7-at_p3_1) (K_need-gather-obs8-at_p3_1)))
                     (when (not (K_not_need-gather-obs7-at_p3_1)) (and (not (K_not_need-gather-obs8-at_p3_1)) (not (K_need-gather-obs7-at_p3_1))))
                     (when (K_need-gather-obs8-at_p3_1) (and (K_need-advance-step) (K_not_need-gather-obs8-at_p3_1)))
                     (when (not (K_not_need-gather-obs8-at_p3_1)) (and (not (K_need-gather-obs8-at_p3_1)) (not (K_not_need-advance-step))))
                     (when (K_not_need-gather-obs0-at_p3_1) (K_not_need-gather-obs1-at_p3_1))
                     (when (not (K_need-gather-obs0-at_p3_1)) (not (K_need-gather-obs1-at_p3_1)))
                     (when (K_not_need-gather-obs1-at_p3_1) (K_not_need-gather-obs2-at_p3_1))
                     (when (not (K_need-gather-obs1-at_p3_1)) (not (K_need-gather-obs2-at_p3_1)))
                     (when (K_not_need-gather-obs2-at_p3_1) (K_not_need-gather-obs3-at_p3_1))
                     (when (not (K_need-gather-obs2-at_p3_1)) (not (K_need-gather-obs3-at_p3_1)))
                     (when (K_not_need-gather-obs3-at_p3_1) (K_not_need-gather-obs4-at_p3_1))
                     (when (not (K_need-gather-obs3-at_p3_1)) (not (K_need-gather-obs4-at_p3_1)))
                     (when (K_not_need-gather-obs4-at_p3_1) (K_not_need-gather-obs5-at_p3_1))
                     (when (not (K_need-gather-obs4-at_p3_1)) (not (K_need-gather-obs5-at_p3_1)))
                     (when (K_not_need-gather-obs5-at_p3_1) (K_not_need-gather-obs6-at_p3_1))
                     (when (not (K_need-gather-obs5-at_p3_1)) (not (K_need-gather-obs6-at_p3_1)))
                     (when (K_not_need-gather-obs6-at_p3_1) (K_not_need-gather-obs7-at_p3_1))
                     (when (not (K_need-gather-obs6-at_p3_1)) (not (K_need-gather-obs7-at_p3_1)))
                     (when (K_not_need-gather-obs7-at_p3_1) (K_not_need-gather-obs8-at_p3_1))
                     (when (not (K_need-gather-obs7-at_p3_1)) (not (K_need-gather-obs8-at_p3_1)))))
    (:action advance-gather-counter_p2_1
        :precondition (K_normal-execution)
        :effect (and (not (K_need-gather-obs0-at_p2_1)) (K_not_need-gather-obs0-at_p2_1)
                     (when (K_need-gather-obs0-at_p2_1) (and (K_not_need-gather-obs0-at_p2_1) (K_need-gather-obs1-at_p2_1)))
                     (when (not (K_not_need-gather-obs0-at_p2_1)) (and (not (K_not_need-gather-obs1-at_p2_1)) (not (K_need-gather-obs0-at_p2_1))))
                     (when (K_need-gather-obs1-at_p2_1) (and (K_not_need-gather-obs1-at_p2_1) (K_need-gather-obs2-at_p2_1)))
                     (when (not (K_not_need-gather-obs1-at_p2_1)) (and (not (K_not_need-gather-obs2-at_p2_1)) (not (K_need-gather-obs1-at_p2_1))))
                     (when (K_need-gather-obs2-at_p2_1) (and (K_not_need-gather-obs2-at_p2_1) (K_need-gather-obs3-at_p2_1)))
                     (when (not (K_not_need-gather-obs2-at_p2_1)) (and (not (K_not_need-gather-obs3-at_p2_1)) (not (K_need-gather-obs2-at_p2_1))))
                     (when (K_need-gather-obs3-at_p2_1) (and (K_not_need-gather-obs3-at_p2_1) (K_need-gather-obs4-at_p2_1)))
                     (when (not (K_not_need-gather-obs3-at_p2_1)) (and (not (K_not_need-gather-obs4-at_p2_1)) (not (K_need-gather-obs3-at_p2_1))))
                     (when (K_need-gather-obs4-at_p2_1) (and (K_not_need-gather-obs4-at_p2_1) (K_need-gather-obs5-at_p2_1)))
                     (when (not (K_not_need-gather-obs4-at_p2_1)) (and (not (K_not_need-gather-obs5-at_p2_1)) (not (K_need-gather-obs4-at_p2_1))))
                     (when (K_need-gather-obs5-at_p2_1) (and (K_not_need-gather-obs5-at_p2_1) (K_need-gather-obs6-at_p2_1)))
                     (when (not (K_not_need-gather-obs5-at_p2_1)) (and (not (K_not_need-gather-obs6-at_p2_1)) (not (K_need-gather-obs5-at_p2_1))))
                     (when (K_need-gather-obs6-at_p2_1) (and (K_not_need-gather-obs6-at_p2_1) (K_need-gather-obs7-at_p2_1)))
                     (when (not (K_not_need-gather-obs6-at_p2_1)) (and (not (K_not_need-gather-obs7-at_p2_1)) (not (K_need-gather-obs6-at_p2_1))))
                     (when (K_need-gather-obs7-at_p2_1) (and (K_not_need-gather-obs7-at_p2_1) (K_need-gather-obs8-at_p2_1)))
                     (when (not (K_not_need-gather-obs7-at_p2_1)) (and (not (K_not_need-gather-obs8-at_p2_1)) (not (K_need-gather-obs7-at_p2_1))))
                     (when (K_need-gather-obs8-at_p2_1) (and (K_need-advance-step) (K_not_need-gather-obs8-at_p2_1)))
                     (when (not (K_not_need-gather-obs8-at_p2_1)) (and (not (K_need-gather-obs8-at_p2_1)) (not (K_not_need-advance-step))))
                     (when (K_not_need-gather-obs0-at_p2_1) (K_not_need-gather-obs1-at_p2_1))
                     (when (not (K_need-gather-obs0-at_p2_1)) (not (K_need-gather-obs1-at_p2_1)))
                     (when (K_not_need-gather-obs1-at_p2_1) (K_not_need-gather-obs2-at_p2_1))
                     (when (not (K_need-gather-obs1-at_p2_1)) (not (K_need-gather-obs2-at_p2_1)))
                     (when (K_not_need-gather-obs2-at_p2_1) (K_not_need-gather-obs3-at_p2_1))
                     (when (not (K_need-gather-obs2-at_p2_1)) (not (K_need-gather-obs3-at_p2_1)))
                     (when (K_not_need-gather-obs3-at_p2_1) (K_not_need-gather-obs4-at_p2_1))
                     (when (not (K_need-gather-obs3-at_p2_1)) (not (K_need-gather-obs4-at_p2_1)))
                     (when (K_not_need-gather-obs4-at_p2_1) (K_not_need-gather-obs5-at_p2_1))
                     (when (not (K_need-gather-obs4-at_p2_1)) (not (K_need-gather-obs5-at_p2_1)))
                     (when (K_not_need-gather-obs5-at_p2_1) (K_not_need-gather-obs6-at_p2_1))
                     (when (not (K_need-gather-obs5-at_p2_1)) (not (K_need-gather-obs6-at_p2_1)))
                     (when (K_not_need-gather-obs6-at_p2_1) (K_not_need-gather-obs7-at_p2_1))
                     (when (not (K_need-gather-obs6-at_p2_1)) (not (K_need-gather-obs7-at_p2_1)))
                     (when (K_not_need-gather-obs7-at_p2_1) (K_not_need-gather-obs8-at_p2_1))
                     (when (not (K_need-gather-obs7-at_p2_1)) (not (K_need-gather-obs8-at_p2_1)))))
    (:action advance-gather-counter_p1_1
        :precondition (K_normal-execution)
        :effect (and (not (K_need-gather-obs0-at_p1_1)) (K_not_need-gather-obs0-at_p1_1)
                     (when (K_need-gather-obs0-at_p1_1) (and (K_not_need-gather-obs0-at_p1_1) (K_need-gather-obs1-at_p1_1)))
                     (when (not (K_not_need-gather-obs0-at_p1_1)) (and (not (K_not_need-gather-obs1-at_p1_1)) (not (K_need-gather-obs0-at_p1_1))))
                     (when (K_need-gather-obs1-at_p1_1) (and (K_not_need-gather-obs1-at_p1_1) (K_need-gather-obs2-at_p1_1)))
                     (when (not (K_not_need-gather-obs1-at_p1_1)) (and (not (K_not_need-gather-obs2-at_p1_1)) (not (K_need-gather-obs1-at_p1_1))))
                     (when (K_need-gather-obs2-at_p1_1) (and (K_not_need-gather-obs2-at_p1_1) (K_need-gather-obs3-at_p1_1)))
                     (when (not (K_not_need-gather-obs2-at_p1_1)) (and (not (K_not_need-gather-obs3-at_p1_1)) (not (K_need-gather-obs2-at_p1_1))))
                     (when (K_need-gather-obs3-at_p1_1) (and (K_not_need-gather-obs3-at_p1_1) (K_need-gather-obs4-at_p1_1)))
                     (when (not (K_not_need-gather-obs3-at_p1_1)) (and (not (K_not_need-gather-obs4-at_p1_1)) (not (K_need-gather-obs3-at_p1_1))))
                     (when (K_need-gather-obs4-at_p1_1) (and (K_not_need-gather-obs4-at_p1_1) (K_need-gather-obs5-at_p1_1)))
                     (when (not (K_not_need-gather-obs4-at_p1_1)) (and (not (K_not_need-gather-obs5-at_p1_1)) (not (K_need-gather-obs4-at_p1_1))))
                     (when (K_need-gather-obs5-at_p1_1) (and (K_not_need-gather-obs5-at_p1_1) (K_need-gather-obs6-at_p1_1)))
                     (when (not (K_not_need-gather-obs5-at_p1_1)) (and (not (K_not_need-gather-obs6-at_p1_1)) (not (K_need-gather-obs5-at_p1_1))))
                     (when (K_need-gather-obs6-at_p1_1) (and (K_not_need-gather-obs6-at_p1_1) (K_need-gather-obs7-at_p1_1)))
                     (when (not (K_not_need-gather-obs6-at_p1_1)) (and (not (K_not_need-gather-obs7-at_p1_1)) (not (K_need-gather-obs6-at_p1_1))))
                     (when (K_need-gather-obs7-at_p1_1) (and (K_not_need-gather-obs7-at_p1_1) (K_need-gather-obs8-at_p1_1)))
                     (when (not (K_not_need-gather-obs7-at_p1_1)) (and (not (K_not_need-gather-obs8-at_p1_1)) (not (K_need-gather-obs7-at_p1_1))))
                     (when (K_need-gather-obs8-at_p1_1) (and (K_need-advance-step) (K_not_need-gather-obs8-at_p1_1)))
                     (when (not (K_not_need-gather-obs8-at_p1_1)) (and (not (K_need-gather-obs8-at_p1_1)) (not (K_not_need-advance-step))))
                     (when (K_not_need-gather-obs0-at_p1_1) (K_not_need-gather-obs1-at_p1_1))
                     (when (not (K_need-gather-obs0-at_p1_1)) (not (K_need-gather-obs1-at_p1_1)))
                     (when (K_not_need-gather-obs1-at_p1_1) (K_not_need-gather-obs2-at_p1_1))
                     (when (not (K_need-gather-obs1-at_p1_1)) (not (K_need-gather-obs2-at_p1_1)))
                     (when (K_not_need-gather-obs2-at_p1_1) (K_not_need-gather-obs3-at_p1_1))
                     (when (not (K_need-gather-obs2-at_p1_1)) (not (K_need-gather-obs3-at_p1_1)))
                     (when (K_not_need-gather-obs3-at_p1_1) (K_not_need-gather-obs4-at_p1_1))
                     (when (not (K_need-gather-obs3-at_p1_1)) (not (K_need-gather-obs4-at_p1_1)))
                     (when (K_not_need-gather-obs4-at_p1_1) (K_not_need-gather-obs5-at_p1_1))
                     (when (not (K_need-gather-obs4-at_p1_1)) (not (K_need-gather-obs5-at_p1_1)))
                     (when (K_not_need-gather-obs5-at_p1_1) (K_not_need-gather-obs6-at_p1_1))
                     (when (not (K_need-gather-obs5-at_p1_1)) (not (K_need-gather-obs6-at_p1_1)))
                     (when (K_not_need-gather-obs6-at_p1_1) (K_not_need-gather-obs7-at_p1_1))
                     (when (not (K_need-gather-obs6-at_p1_1)) (not (K_need-gather-obs7-at_p1_1)))
                     (when (K_not_need-gather-obs7-at_p1_1) (K_not_need-gather-obs8-at_p1_1))
                     (when (not (K_need-gather-obs7-at_p1_1)) (not (K_need-gather-obs8-at_p1_1)))))
    (:action start-action
        :precondition (and (K_normal-execution) (K_need-start))
        :effect (and (not (K_not_at-step_n0)) (not (K_not_ok)) (not (K_mine-at_p1_1)) (not (K_need-start)) (K_not_need-start) (K_not_mine-at_p1_1) (K_ok) (K_at-step_n0)))
    (:action open-cell-at-step0
        :precondition (and (K_normal-execution) (K_not_mine-at_p1_1) (K_ok) (K_at-step_n0))
        :effect (and (not (K_not_need-gather-obs0-at_p1_1)) (not (K_ok)) (not (K_not_done-with_p1_1)) (K_done-with_p1_1) (K_not_ok) (K_need-gather-obs0-at_p1_1)))
    (:action open-cell-at-step1
        :precondition (and (K_normal-execution) (K_not_mine-at_p2_2) (K_ok) (K_at-step_n1))
        :effect (and (not (K_not_need-gather-obs0-at_p2_2)) (not (K_ok)) (not (K_not_done-with_p2_2)) (K_done-with_p2_2) (K_not_ok) (K_need-gather-obs0-at_p2_2)))
    (:action open-cell-at-step2
        :precondition (and (K_normal-execution) (K_not_mine-at_p2_1) (K_ok) (K_at-step_n2))
        :effect (and (not (K_not_need-gather-obs0-at_p2_1)) (not (K_ok)) (not (K_not_done-with_p2_1)) (K_done-with_p2_1) (K_not_ok) (K_need-gather-obs0-at_p2_1)))
    (:action open-cell-at-step3
        :precondition (and (K_normal-execution) (K_not_mine-at_p3_2) (K_ok) (K_at-step_n3))
        :effect (and (not (K_not_need-gather-obs0-at_p3_2)) (not (K_ok)) (not (K_not_done-with_p3_2)) (K_done-with_p3_2) (K_not_ok) (K_need-gather-obs0-at_p3_2)))
    (:action put-flag-at-step4
        :precondition (and (K_normal-execution) (K_mine-at_p1_3) (K_ok) (K_at-step_n4))
        :effect (and (not (K_ok)) (not (K_not_need-advance-step)) (not (K_not_done-with_p1_3)) (K_done-with_p1_3) (K_need-advance-step) (K_not_ok)))
    (:action open-cell-at-step5
        :precondition (and (K_normal-execution) (K_not_mine-at_p3_1) (K_ok) (K_at-step_n5))
        :effect (and (not (K_not_need-gather-obs0-at_p3_1)) (not (K_ok)) (not (K_not_done-with_p3_1)) (K_done-with_p3_1) (K_not_ok) (K_need-gather-obs0-at_p3_1)))
    (:action open-cell-at-step6
        :precondition (and (K_normal-execution) (K_not_mine-at_p1_2) (K_ok) (K_at-step_n6))
        :effect (and (not (K_not_need-gather-obs0-at_p1_2)) (not (K_ok)) (not (K_not_done-with_p1_2)) (K_done-with_p1_2) (K_not_ok) (K_need-gather-obs0-at_p1_2)))
    (:action put-flag-at-step7
        :precondition (and (K_normal-execution) (K_mine-at_p2_3) (K_ok) (K_at-step_n7))
        :effect (and (not (K_ok)) (not (K_not_need-advance-step)) (not (K_not_done-with_p2_3)) (K_done-with_p2_3) (K_need-advance-step) (K_not_ok)))
    (:action open-cell-at-step8
        :precondition (and (K_normal-execution) (K_ok) (K_at-step_n8))
        :effect (and (not (K_not_need-gather-obs0-at_p3_3)) (not (K_ok)) (not (K_not_done-with_p3_3)) (K_done-with_p3_3) (K_not_ok) (K_need-gather-obs0-at_p3_3)))
    (:action open-cell-at-step9
        :precondition (and (K_normal-execution) (K_not_mine-at_p3_4) (K_ok) (K_at-step_n9))
        :effect (and (not (K_not_need-gather-obs0-at_p3_4)) (not (K_ok)) (not (K_not_done-with_p3_4)) (K_done-with_p3_4) (K_not_ok) (K_need-gather-obs0-at_p3_4)))
    (:action open-cell-at-step10
        :precondition (and (K_normal-execution) (K_not_mine-at_p2_4) (K_ok) (K_at-step_n10))
        :effect (and (not (K_not_need-gather-obs0-at_p2_4)) (not (K_ok)) (not (K_not_done-with_p2_4)) (K_done-with_p2_4) (K_not_ok) (K_need-gather-obs0-at_p2_4)))
    (:action open-cell-at-step11
        :precondition (and (K_normal-execution) (K_not_mine-at_p1_4) (K_ok) (K_at-step_n11))
        :effect (and (not (K_not_need-gather-obs0-at_p1_4)) (not (K_ok)) (not (K_not_done-with_p1_4)) (K_done-with_p1_4) (K_not_ok) (K_need-gather-obs0-at_p1_4)))
    (:action gather-obs0_p3_4__post__
        :precondition (K_need-post-for-gather-obs0_p3_4)
        :effect (and (not (K_need-post-for-gather-obs0_p3_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs0_p3_4)))
    (:action gather-obs0_p2_4__post__
        :precondition (K_need-post-for-gather-obs0_p2_4)
        :effect (and (not (K_need-post-for-gather-obs0_p2_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs0_p2_4)))
    (:action gather-obs0_p1_4__post__
        :precondition (K_need-post-for-gather-obs0_p1_4)
        :effect (and (not (K_need-post-for-gather-obs0_p1_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs0_p1_4)))
    (:action gather-obs0_p3_3__post__
        :precondition (K_need-post-for-gather-obs0_p3_3)
        :effect (and (not (K_need-post-for-gather-obs0_p3_3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs0_p3_3)))
    (:action gather-obs0_p3_2__post__
        :precondition (K_need-post-for-gather-obs0_p3_2)
        :effect (and (not (K_need-post-for-gather-obs0_p3_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs0_p3_2)))
    (:action gather-obs0_p2_2__post__
        :precondition (K_need-post-for-gather-obs0_p2_2)
        :effect (and (not (K_need-post-for-gather-obs0_p2_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs0_p2_2)))
    (:action gather-obs0_p1_2__post__
        :precondition (K_need-post-for-gather-obs0_p1_2)
        :effect (and (not (K_need-post-for-gather-obs0_p1_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs0_p1_2)))
    (:action gather-obs0_p3_1__post__
        :precondition (K_need-post-for-gather-obs0_p3_1)
        :effect (and (not (K_need-post-for-gather-obs0_p3_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs0_p3_1)))
    (:action gather-obs0_p2_1__post__
        :precondition (K_need-post-for-gather-obs0_p2_1)
        :effect (and (not (K_need-post-for-gather-obs0_p2_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs0_p2_1)))
    (:action gather-obs0_p1_1__post__
        :precondition (K_need-post-for-gather-obs0_p1_1)
        :effect (and (not (K_need-post-for-gather-obs0_p1_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs0_p1_1)))
    (:action gather-obs1_p3_4__post__
        :precondition (K_need-post-for-gather-obs1_p3_4)
        :effect (and (not (K_need-post-for-gather-obs1_p3_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs1_p3_4)))
    (:action gather-obs1_p2_4__post__
        :precondition (K_need-post-for-gather-obs1_p2_4)
        :effect (and (not (K_need-post-for-gather-obs1_p2_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs1_p2_4)))
    (:action gather-obs1_p1_4__post__
        :precondition (K_need-post-for-gather-obs1_p1_4)
        :effect (and (not (K_need-post-for-gather-obs1_p1_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs1_p1_4)))
    (:action gather-obs1_p3_3__post__
        :precondition (K_need-post-for-gather-obs1_p3_3)
        :effect (and (not (K_need-post-for-gather-obs1_p3_3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs1_p3_3)))
    (:action gather-obs1_p3_2__post__
        :precondition (K_need-post-for-gather-obs1_p3_2)
        :effect (and (not (K_need-post-for-gather-obs1_p3_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs1_p3_2)))
    (:action gather-obs1_p2_2__post__
        :precondition (K_need-post-for-gather-obs1_p2_2)
        :effect (and (not (K_need-post-for-gather-obs1_p2_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs1_p2_2)))
    (:action gather-obs1_p1_2__post__
        :precondition (K_need-post-for-gather-obs1_p1_2)
        :effect (and (not (K_need-post-for-gather-obs1_p1_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs1_p1_2)))
    (:action gather-obs1_p3_1__post__
        :precondition (K_need-post-for-gather-obs1_p3_1)
        :effect (and (not (K_need-post-for-gather-obs1_p3_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs1_p3_1)))
    (:action gather-obs1_p2_1__post__
        :precondition (K_need-post-for-gather-obs1_p2_1)
        :effect (and (not (K_need-post-for-gather-obs1_p2_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs1_p2_1)))
    (:action gather-obs1_p1_1__post__
        :precondition (K_need-post-for-gather-obs1_p1_1)
        :effect (and (not (K_need-post-for-gather-obs1_p1_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs1_p1_1)))
    (:action gather-obs2_p3_4__post__
        :precondition (K_need-post-for-gather-obs2_p3_4)
        :effect (and (not (K_need-post-for-gather-obs2_p3_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs2_p3_4)))
    (:action gather-obs2_p2_4__post__
        :precondition (K_need-post-for-gather-obs2_p2_4)
        :effect (and (not (K_need-post-for-gather-obs2_p2_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs2_p2_4)))
    (:action gather-obs2_p1_4__post__
        :precondition (K_need-post-for-gather-obs2_p1_4)
        :effect (and (not (K_need-post-for-gather-obs2_p1_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs2_p1_4)))
    (:action gather-obs2_p3_3__post__
        :precondition (K_need-post-for-gather-obs2_p3_3)
        :effect (and (not (K_need-post-for-gather-obs2_p3_3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs2_p3_3)))
    (:action gather-obs2_p3_2__post__
        :precondition (K_need-post-for-gather-obs2_p3_2)
        :effect (and (not (K_need-post-for-gather-obs2_p3_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs2_p3_2)))
    (:action gather-obs2_p2_2__post__
        :precondition (K_need-post-for-gather-obs2_p2_2)
        :effect (and (not (K_need-post-for-gather-obs2_p2_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs2_p2_2)))
    (:action gather-obs2_p1_2__post__
        :precondition (K_need-post-for-gather-obs2_p1_2)
        :effect (and (not (K_need-post-for-gather-obs2_p1_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs2_p1_2)))
    (:action gather-obs2_p3_1__post__
        :precondition (K_need-post-for-gather-obs2_p3_1)
        :effect (and (not (K_need-post-for-gather-obs2_p3_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs2_p3_1)))
    (:action gather-obs2_p2_1__post__
        :precondition (K_need-post-for-gather-obs2_p2_1)
        :effect (and (not (K_need-post-for-gather-obs2_p2_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs2_p2_1)))
    (:action gather-obs2_p1_1__post__
        :precondition (K_need-post-for-gather-obs2_p1_1)
        :effect (and (not (K_need-post-for-gather-obs2_p1_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs2_p1_1)))
    (:action gather-obs3_p3_4__post__
        :precondition (K_need-post-for-gather-obs3_p3_4)
        :effect (and (not (K_need-post-for-gather-obs3_p3_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs3_p3_4)))
    (:action gather-obs3_p2_4__post__
        :precondition (K_need-post-for-gather-obs3_p2_4)
        :effect (and (not (K_need-post-for-gather-obs3_p2_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs3_p2_4)))
    (:action gather-obs3_p1_4__post__
        :precondition (K_need-post-for-gather-obs3_p1_4)
        :effect (and (not (K_need-post-for-gather-obs3_p1_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs3_p1_4)))
    (:action gather-obs3_p3_3__post__
        :precondition (K_need-post-for-gather-obs3_p3_3)
        :effect (and (not (K_need-post-for-gather-obs3_p3_3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs3_p3_3)))
    (:action gather-obs3_p3_2__post__
        :precondition (K_need-post-for-gather-obs3_p3_2)
        :effect (and (not (K_need-post-for-gather-obs3_p3_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs3_p3_2)))
    (:action gather-obs3_p2_2__post__
        :precondition (K_need-post-for-gather-obs3_p2_2)
        :effect (and (not (K_need-post-for-gather-obs3_p2_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs3_p2_2)))
    (:action gather-obs3_p1_2__post__
        :precondition (K_need-post-for-gather-obs3_p1_2)
        :effect (and (not (K_need-post-for-gather-obs3_p1_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs3_p1_2)))
    (:action gather-obs3_p3_1__post__
        :precondition (K_need-post-for-gather-obs3_p3_1)
        :effect (and (not (K_need-post-for-gather-obs3_p3_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs3_p3_1)))
    (:action gather-obs3_p2_1__post__
        :precondition (K_need-post-for-gather-obs3_p2_1)
        :effect (and (not (K_need-post-for-gather-obs3_p2_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs3_p2_1)))
    (:action gather-obs3_p1_1__post__
        :precondition (K_need-post-for-gather-obs3_p1_1)
        :effect (and (not (K_need-post-for-gather-obs3_p1_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs3_p1_1)))
    (:action gather-obs4_p3_4__post__
        :precondition (K_need-post-for-gather-obs4_p3_4)
        :effect (and (not (K_need-post-for-gather-obs4_p3_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs4_p3_4)))
    (:action gather-obs4_p2_4__post__
        :precondition (K_need-post-for-gather-obs4_p2_4)
        :effect (and (not (K_need-post-for-gather-obs4_p2_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs4_p2_4)))
    (:action gather-obs4_p1_4__post__
        :precondition (K_need-post-for-gather-obs4_p1_4)
        :effect (and (not (K_need-post-for-gather-obs4_p1_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs4_p1_4)))
    (:action gather-obs4_p3_3__post__
        :precondition (K_need-post-for-gather-obs4_p3_3)
        :effect (and (not (K_need-post-for-gather-obs4_p3_3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs4_p3_3)))
    (:action gather-obs4_p3_2__post__
        :precondition (K_need-post-for-gather-obs4_p3_2)
        :effect (and (not (K_need-post-for-gather-obs4_p3_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs4_p3_2)))
    (:action gather-obs4_p2_2__post__
        :precondition (K_need-post-for-gather-obs4_p2_2)
        :effect (and (not (K_need-post-for-gather-obs4_p2_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs4_p2_2)))
    (:action gather-obs4_p1_2__post__
        :precondition (K_need-post-for-gather-obs4_p1_2)
        :effect (and (not (K_need-post-for-gather-obs4_p1_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs4_p1_2)))
    (:action gather-obs4_p3_1__post__
        :precondition (K_need-post-for-gather-obs4_p3_1)
        :effect (and (not (K_need-post-for-gather-obs4_p3_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs4_p3_1)))
    (:action gather-obs4_p2_1__post__
        :precondition (K_need-post-for-gather-obs4_p2_1)
        :effect (and (not (K_need-post-for-gather-obs4_p2_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs4_p2_1)))
    (:action gather-obs4_p1_1__post__
        :precondition (K_need-post-for-gather-obs4_p1_1)
        :effect (and (not (K_need-post-for-gather-obs4_p1_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs4_p1_1)))
    (:action gather-obs5_p3_4__post__
        :precondition (K_need-post-for-gather-obs5_p3_4)
        :effect (and (not (K_need-post-for-gather-obs5_p3_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs5_p3_4)))
    (:action gather-obs5_p2_4__post__
        :precondition (K_need-post-for-gather-obs5_p2_4)
        :effect (and (not (K_need-post-for-gather-obs5_p2_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs5_p2_4)))
    (:action gather-obs5_p1_4__post__
        :precondition (K_need-post-for-gather-obs5_p1_4)
        :effect (and (not (K_need-post-for-gather-obs5_p1_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs5_p1_4)))
    (:action gather-obs5_p3_3__post__
        :precondition (K_need-post-for-gather-obs5_p3_3)
        :effect (and (not (K_need-post-for-gather-obs5_p3_3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs5_p3_3)))
    (:action gather-obs5_p3_2__post__
        :precondition (K_need-post-for-gather-obs5_p3_2)
        :effect (and (not (K_need-post-for-gather-obs5_p3_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs5_p3_2)))
    (:action gather-obs5_p2_2__post__
        :precondition (K_need-post-for-gather-obs5_p2_2)
        :effect (and (not (K_need-post-for-gather-obs5_p2_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs5_p2_2)))
    (:action gather-obs5_p1_2__post__
        :precondition (K_need-post-for-gather-obs5_p1_2)
        :effect (and (not (K_need-post-for-gather-obs5_p1_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs5_p1_2)))
    (:action gather-obs5_p3_1__post__
        :precondition (K_need-post-for-gather-obs5_p3_1)
        :effect (and (not (K_need-post-for-gather-obs5_p3_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs5_p3_1)))
    (:action gather-obs5_p2_1__post__
        :precondition (K_need-post-for-gather-obs5_p2_1)
        :effect (and (not (K_need-post-for-gather-obs5_p2_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs5_p2_1)))
    (:action gather-obs5_p1_1__post__
        :precondition (K_need-post-for-gather-obs5_p1_1)
        :effect (and (not (K_need-post-for-gather-obs5_p1_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs5_p1_1)))
    (:action gather-obs6_p3_4__post__
        :precondition (K_need-post-for-gather-obs6_p3_4)
        :effect (and (not (K_need-post-for-gather-obs6_p3_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs6_p3_4)))
    (:action gather-obs6_p2_4__post__
        :precondition (K_need-post-for-gather-obs6_p2_4)
        :effect (and (not (K_need-post-for-gather-obs6_p2_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs6_p2_4)))
    (:action gather-obs6_p1_4__post__
        :precondition (K_need-post-for-gather-obs6_p1_4)
        :effect (and (not (K_need-post-for-gather-obs6_p1_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs6_p1_4)))
    (:action gather-obs6_p3_3__post__
        :precondition (K_need-post-for-gather-obs6_p3_3)
        :effect (and (not (K_need-post-for-gather-obs6_p3_3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs6_p3_3)))
    (:action gather-obs6_p3_2__post__
        :precondition (K_need-post-for-gather-obs6_p3_2)
        :effect (and (not (K_need-post-for-gather-obs6_p3_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs6_p3_2)))
    (:action gather-obs6_p2_2__post__
        :precondition (K_need-post-for-gather-obs6_p2_2)
        :effect (and (not (K_need-post-for-gather-obs6_p2_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs6_p2_2)))
    (:action gather-obs6_p1_2__post__
        :precondition (K_need-post-for-gather-obs6_p1_2)
        :effect (and (not (K_need-post-for-gather-obs6_p1_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs6_p1_2)))
    (:action gather-obs6_p3_1__post__
        :precondition (K_need-post-for-gather-obs6_p3_1)
        :effect (and (not (K_need-post-for-gather-obs6_p3_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs6_p3_1)))
    (:action gather-obs6_p2_1__post__
        :precondition (K_need-post-for-gather-obs6_p2_1)
        :effect (and (not (K_need-post-for-gather-obs6_p2_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs6_p2_1)))
    (:action gather-obs6_p1_1__post__
        :precondition (K_need-post-for-gather-obs6_p1_1)
        :effect (and (not (K_need-post-for-gather-obs6_p1_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs6_p1_1)))
    (:action gather-obs7_p3_4__post__
        :precondition (K_need-post-for-gather-obs7_p3_4)
        :effect (and (not (K_need-post-for-gather-obs7_p3_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs7_p3_4)))
    (:action gather-obs7_p2_4__post__
        :precondition (K_need-post-for-gather-obs7_p2_4)
        :effect (and (not (K_need-post-for-gather-obs7_p2_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs7_p2_4)))
    (:action gather-obs7_p1_4__post__
        :precondition (K_need-post-for-gather-obs7_p1_4)
        :effect (and (not (K_need-post-for-gather-obs7_p1_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs7_p1_4)))
    (:action gather-obs7_p3_3__post__
        :precondition (K_need-post-for-gather-obs7_p3_3)
        :effect (and (not (K_need-post-for-gather-obs7_p3_3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs7_p3_3)))
    (:action gather-obs7_p3_2__post__
        :precondition (K_need-post-for-gather-obs7_p3_2)
        :effect (and (not (K_need-post-for-gather-obs7_p3_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs7_p3_2)))
    (:action gather-obs7_p2_2__post__
        :precondition (K_need-post-for-gather-obs7_p2_2)
        :effect (and (not (K_need-post-for-gather-obs7_p2_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs7_p2_2)))
    (:action gather-obs7_p1_2__post__
        :precondition (K_need-post-for-gather-obs7_p1_2)
        :effect (and (not (K_need-post-for-gather-obs7_p1_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs7_p1_2)))
    (:action gather-obs7_p3_1__post__
        :precondition (K_need-post-for-gather-obs7_p3_1)
        :effect (and (not (K_need-post-for-gather-obs7_p3_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs7_p3_1)))
    (:action gather-obs7_p2_1__post__
        :precondition (K_need-post-for-gather-obs7_p2_1)
        :effect (and (not (K_need-post-for-gather-obs7_p2_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs7_p2_1)))
    (:action gather-obs7_p1_1__post__
        :precondition (K_need-post-for-gather-obs7_p1_1)
        :effect (and (not (K_need-post-for-gather-obs7_p1_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs7_p1_1)))
    (:action gather-obs8_p3_4__post__
        :precondition (K_need-post-for-gather-obs8_p3_4)
        :effect (and (not (K_need-post-for-gather-obs8_p3_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs8_p3_4)))
    (:action gather-obs8_p2_4__post__
        :precondition (K_need-post-for-gather-obs8_p2_4)
        :effect (and (not (K_need-post-for-gather-obs8_p2_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs8_p2_4)))
    (:action gather-obs8_p1_4__post__
        :precondition (K_need-post-for-gather-obs8_p1_4)
        :effect (and (not (K_need-post-for-gather-obs8_p1_4)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs8_p1_4)))
    (:action gather-obs8_p3_3__post__
        :precondition (K_need-post-for-gather-obs8_p3_3)
        :effect (and (not (K_need-post-for-gather-obs8_p3_3)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs8_p3_3)))
    (:action gather-obs8_p3_2__post__
        :precondition (K_need-post-for-gather-obs8_p3_2)
        :effect (and (not (K_need-post-for-gather-obs8_p3_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs8_p3_2)))
    (:action gather-obs8_p2_2__post__
        :precondition (K_need-post-for-gather-obs8_p2_2)
        :effect (and (not (K_need-post-for-gather-obs8_p2_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs8_p2_2)))
    (:action gather-obs8_p1_2__post__
        :precondition (K_need-post-for-gather-obs8_p1_2)
        :effect (and (not (K_need-post-for-gather-obs8_p1_2)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs8_p1_2)))
    (:action gather-obs8_p3_1__post__
        :precondition (K_need-post-for-gather-obs8_p3_1)
        :effect (and (not (K_need-post-for-gather-obs8_p3_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs8_p3_1)))
    (:action gather-obs8_p2_1__post__
        :precondition (K_need-post-for-gather-obs8_p2_1)
        :effect (and (not (K_need-post-for-gather-obs8_p2_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs8_p2_1)))
    (:action gather-obs8_p1_1__post__
        :precondition (K_need-post-for-gather-obs8_p1_1)
        :effect (and (not (K_need-post-for-gather-obs8_p1_1)) (not (K_not_normal-execution)) (K_normal-execution) (K_not_need-post-for-gather-obs8_p1_1)))
    (:action sensor-gather-obs0_p3_4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs0-at_p3_4)) (not (K_obs0-at_p3_4)) (K_need-post-for-gather-obs0_p3_4)) (K_obs0-at_p3_4)))
    (:action sensor-gather-obs0_p3_4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs0-at_p3_4)) (not (K_obs0-at_p3_4)) (K_need-post-for-gather-obs0_p3_4)) (K_not_obs0-at_p3_4)))
    (:action sensor-gather-obs0_p2_4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs0-at_p2_4)) (not (K_obs0-at_p2_4)) (K_need-post-for-gather-obs0_p2_4)) (K_obs0-at_p2_4)))
    (:action sensor-gather-obs0_p2_4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs0-at_p2_4)) (not (K_obs0-at_p2_4)) (K_need-post-for-gather-obs0_p2_4)) (K_not_obs0-at_p2_4)))
    (:action sensor-gather-obs0_p1_4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs0-at_p1_4)) (not (K_obs0-at_p1_4)) (K_need-post-for-gather-obs0_p1_4)) (K_obs0-at_p1_4)))
    (:action sensor-gather-obs0_p1_4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs0-at_p1_4)) (not (K_obs0-at_p1_4)) (K_need-post-for-gather-obs0_p1_4)) (K_not_obs0-at_p1_4)))
    (:action sensor-gather-obs0_p3_3__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs0-at_p3_3)) (not (K_obs0-at_p3_3)) (K_need-post-for-gather-obs0_p3_3)) (K_obs0-at_p3_3)))
    (:action sensor-gather-obs0_p3_3__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs0-at_p3_3)) (not (K_obs0-at_p3_3)) (K_need-post-for-gather-obs0_p3_3)) (K_not_obs0-at_p3_3)))
    (:action sensor-gather-obs0_p3_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs0-at_p3_2)) (not (K_obs0-at_p3_2)) (K_need-post-for-gather-obs0_p3_2)) (K_obs0-at_p3_2)))
    (:action sensor-gather-obs0_p3_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs0-at_p3_2)) (not (K_obs0-at_p3_2)) (K_need-post-for-gather-obs0_p3_2)) (K_not_obs0-at_p3_2)))
    (:action sensor-gather-obs0_p2_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs0-at_p2_2)) (not (K_obs0-at_p2_2)) (K_need-post-for-gather-obs0_p2_2)) (K_obs0-at_p2_2)))
    (:action sensor-gather-obs0_p2_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs0-at_p2_2)) (not (K_obs0-at_p2_2)) (K_need-post-for-gather-obs0_p2_2)) (K_not_obs0-at_p2_2)))
    (:action sensor-gather-obs0_p1_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs0-at_p1_2)) (not (K_obs0-at_p1_2)) (K_need-post-for-gather-obs0_p1_2)) (K_obs0-at_p1_2)))
    (:action sensor-gather-obs0_p1_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs0-at_p1_2)) (not (K_obs0-at_p1_2)) (K_need-post-for-gather-obs0_p1_2)) (K_not_obs0-at_p1_2)))
    (:action sensor-gather-obs0_p3_1__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs0-at_p3_1)) (not (K_obs0-at_p3_1)) (K_need-post-for-gather-obs0_p3_1)) (K_obs0-at_p3_1)))
    (:action sensor-gather-obs0_p3_1__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs0-at_p3_1)) (not (K_obs0-at_p3_1)) (K_need-post-for-gather-obs0_p3_1)) (K_not_obs0-at_p3_1)))
    (:action sensor-gather-obs0_p2_1__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs0-at_p2_1)) (not (K_obs0-at_p2_1)) (K_need-post-for-gather-obs0_p2_1)) (K_obs0-at_p2_1)))
    (:action sensor-gather-obs0_p2_1__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs0-at_p2_1)) (not (K_obs0-at_p2_1)) (K_need-post-for-gather-obs0_p2_1)) (K_not_obs0-at_p2_1)))
    (:action sensor-gather-obs0_p1_1__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs0-at_p1_1)) (not (K_obs0-at_p1_1)) (K_need-post-for-gather-obs0_p1_1)) (K_obs0-at_p1_1)))
    (:action sensor-gather-obs0_p1_1__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs0-at_p1_1)) (not (K_obs0-at_p1_1)) (K_need-post-for-gather-obs0_p1_1)) (K_not_obs0-at_p1_1)))
    (:action sensor-gather-obs1_p3_4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs1-at_p3_4)) (not (K_obs1-at_p3_4)) (K_need-post-for-gather-obs1_p3_4)) (K_obs1-at_p3_4)))
    (:action sensor-gather-obs1_p3_4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs1-at_p3_4)) (not (K_obs1-at_p3_4)) (K_need-post-for-gather-obs1_p3_4)) (K_not_obs1-at_p3_4)))
    (:action sensor-gather-obs1_p2_4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs1-at_p2_4)) (not (K_obs1-at_p2_4)) (K_need-post-for-gather-obs1_p2_4)) (K_obs1-at_p2_4)))
    (:action sensor-gather-obs1_p2_4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs1-at_p2_4)) (not (K_obs1-at_p2_4)) (K_need-post-for-gather-obs1_p2_4)) (K_not_obs1-at_p2_4)))
    (:action sensor-gather-obs1_p1_4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs1-at_p1_4)) (not (K_obs1-at_p1_4)) (K_need-post-for-gather-obs1_p1_4)) (K_obs1-at_p1_4)))
    (:action sensor-gather-obs1_p1_4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs1-at_p1_4)) (not (K_obs1-at_p1_4)) (K_need-post-for-gather-obs1_p1_4)) (K_not_obs1-at_p1_4)))
    (:action sensor-gather-obs1_p3_3__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs1-at_p3_3)) (not (K_obs1-at_p3_3)) (K_need-post-for-gather-obs1_p3_3)) (K_obs1-at_p3_3)))
    (:action sensor-gather-obs1_p3_3__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs1-at_p3_3)) (not (K_obs1-at_p3_3)) (K_need-post-for-gather-obs1_p3_3)) (K_not_obs1-at_p3_3)))
    (:action sensor-gather-obs1_p3_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs1-at_p3_2)) (not (K_obs1-at_p3_2)) (K_need-post-for-gather-obs1_p3_2)) (K_obs1-at_p3_2)))
    (:action sensor-gather-obs1_p3_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs1-at_p3_2)) (not (K_obs1-at_p3_2)) (K_need-post-for-gather-obs1_p3_2)) (K_not_obs1-at_p3_2)))
    (:action sensor-gather-obs1_p2_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs1-at_p2_2)) (not (K_obs1-at_p2_2)) (K_need-post-for-gather-obs1_p2_2)) (K_obs1-at_p2_2)))
    (:action sensor-gather-obs1_p2_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs1-at_p2_2)) (not (K_obs1-at_p2_2)) (K_need-post-for-gather-obs1_p2_2)) (K_not_obs1-at_p2_2)))
    (:action sensor-gather-obs1_p1_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs1-at_p1_2)) (not (K_obs1-at_p1_2)) (K_need-post-for-gather-obs1_p1_2)) (K_obs1-at_p1_2)))
    (:action sensor-gather-obs1_p1_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs1-at_p1_2)) (not (K_obs1-at_p1_2)) (K_need-post-for-gather-obs1_p1_2)) (K_not_obs1-at_p1_2)))
    (:action sensor-gather-obs1_p3_1__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs1-at_p3_1)) (not (K_obs1-at_p3_1)) (K_need-post-for-gather-obs1_p3_1)) (K_obs1-at_p3_1)))
    (:action sensor-gather-obs1_p3_1__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs1-at_p3_1)) (not (K_obs1-at_p3_1)) (K_need-post-for-gather-obs1_p3_1)) (K_not_obs1-at_p3_1)))
    (:action sensor-gather-obs1_p2_1__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs1-at_p2_1)) (not (K_obs1-at_p2_1)) (K_need-post-for-gather-obs1_p2_1)) (K_obs1-at_p2_1)))
    (:action sensor-gather-obs1_p2_1__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs1-at_p2_1)) (not (K_obs1-at_p2_1)) (K_need-post-for-gather-obs1_p2_1)) (K_not_obs1-at_p2_1)))
    (:action sensor-gather-obs1_p1_1__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs1-at_p1_1)) (not (K_obs1-at_p1_1)) (K_need-post-for-gather-obs1_p1_1)) (K_obs1-at_p1_1)))
    (:action sensor-gather-obs1_p1_1__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs1-at_p1_1)) (not (K_obs1-at_p1_1)) (K_need-post-for-gather-obs1_p1_1)) (K_not_obs1-at_p1_1)))
    (:action sensor-gather-obs2_p3_4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs2-at_p3_4)) (not (K_obs2-at_p3_4)) (K_need-post-for-gather-obs2_p3_4)) (K_obs2-at_p3_4)))
    (:action sensor-gather-obs2_p3_4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs2-at_p3_4)) (not (K_obs2-at_p3_4)) (K_need-post-for-gather-obs2_p3_4)) (K_not_obs2-at_p3_4)))
    (:action sensor-gather-obs2_p2_4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs2-at_p2_4)) (not (K_obs2-at_p2_4)) (K_need-post-for-gather-obs2_p2_4)) (K_obs2-at_p2_4)))
    (:action sensor-gather-obs2_p2_4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs2-at_p2_4)) (not (K_obs2-at_p2_4)) (K_need-post-for-gather-obs2_p2_4)) (K_not_obs2-at_p2_4)))
    (:action sensor-gather-obs2_p1_4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs2-at_p1_4)) (not (K_obs2-at_p1_4)) (K_need-post-for-gather-obs2_p1_4)) (K_obs2-at_p1_4)))
    (:action sensor-gather-obs2_p1_4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs2-at_p1_4)) (not (K_obs2-at_p1_4)) (K_need-post-for-gather-obs2_p1_4)) (K_not_obs2-at_p1_4)))
    (:action sensor-gather-obs2_p3_3__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs2-at_p3_3)) (not (K_obs2-at_p3_3)) (K_need-post-for-gather-obs2_p3_3)) (K_obs2-at_p3_3)))
    (:action sensor-gather-obs2_p3_3__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs2-at_p3_3)) (not (K_obs2-at_p3_3)) (K_need-post-for-gather-obs2_p3_3)) (K_not_obs2-at_p3_3)))
    (:action sensor-gather-obs8_p2_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs8-at_p2_2)) (not (K_obs8-at_p2_2)) (K_need-post-for-gather-obs8_p2_2)) (K_obs8-at_p2_2)))
    (:action sensor-gather-obs8_p2_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs8-at_p2_2)) (not (K_obs8-at_p2_2)) (K_need-post-for-gather-obs8_p2_2)) (K_not_obs8-at_p2_2)))
    (:action sensor-gather-obs2_p3_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs2-at_p3_2)) (not (K_obs2-at_p3_2)) (K_need-post-for-gather-obs2_p3_2)) (K_obs2-at_p3_2)))
    (:action sensor-gather-obs2_p3_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs2-at_p3_2)) (not (K_obs2-at_p3_2)) (K_need-post-for-gather-obs2_p3_2)) (K_not_obs2-at_p3_2)))
    (:action sensor-gather-obs2_p2_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs2-at_p2_2)) (not (K_obs2-at_p2_2)) (K_need-post-for-gather-obs2_p2_2)) (K_obs2-at_p2_2)))
    (:action sensor-gather-obs2_p2_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs2-at_p2_2)) (not (K_obs2-at_p2_2)) (K_need-post-for-gather-obs2_p2_2)) (K_not_obs2-at_p2_2)))
    (:action sensor-gather-obs2_p1_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs2-at_p1_2)) (not (K_obs2-at_p1_2)) (K_need-post-for-gather-obs2_p1_2)) (K_obs2-at_p1_2)))
    (:action sensor-gather-obs2_p1_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs2-at_p1_2)) (not (K_obs2-at_p1_2)) (K_need-post-for-gather-obs2_p1_2)) (K_not_obs2-at_p1_2)))
    (:action sensor-gather-obs2_p3_1__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs2-at_p3_1)) (not (K_obs2-at_p3_1)) (K_need-post-for-gather-obs2_p3_1)) (K_obs2-at_p3_1)))
    (:action sensor-gather-obs2_p3_1__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs2-at_p3_1)) (not (K_obs2-at_p3_1)) (K_need-post-for-gather-obs2_p3_1)) (K_not_obs2-at_p3_1)))
    (:action sensor-gather-obs2_p2_1__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs2-at_p2_1)) (not (K_obs2-at_p2_1)) (K_need-post-for-gather-obs2_p2_1)) (K_obs2-at_p2_1)))
    (:action sensor-gather-obs2_p2_1__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs2-at_p2_1)) (not (K_obs2-at_p2_1)) (K_need-post-for-gather-obs2_p2_1)) (K_not_obs2-at_p2_1)))
    (:action sensor-gather-obs2_p1_1__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs2-at_p1_1)) (not (K_obs2-at_p1_1)) (K_need-post-for-gather-obs2_p1_1)) (K_obs2-at_p1_1)))
    (:action sensor-gather-obs2_p1_1__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs2-at_p1_1)) (not (K_obs2-at_p1_1)) (K_need-post-for-gather-obs2_p1_1)) (K_not_obs2-at_p1_1)))
    (:action sensor-gather-obs3_p3_4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs3-at_p3_4)) (not (K_obs3-at_p3_4)) (K_need-post-for-gather-obs3_p3_4)) (K_obs3-at_p3_4)))
    (:action sensor-gather-obs3_p3_4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs3-at_p3_4)) (not (K_obs3-at_p3_4)) (K_need-post-for-gather-obs3_p3_4)) (K_not_obs3-at_p3_4)))
    (:action sensor-gather-obs3_p2_4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs3-at_p2_4)) (not (K_obs3-at_p2_4)) (K_need-post-for-gather-obs3_p2_4)) (K_obs3-at_p2_4)))
    (:action sensor-gather-obs3_p2_4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs3-at_p2_4)) (not (K_obs3-at_p2_4)) (K_need-post-for-gather-obs3_p2_4)) (K_not_obs3-at_p2_4)))
    (:action sensor-gather-obs3_p1_4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs3-at_p1_4)) (not (K_obs3-at_p1_4)) (K_need-post-for-gather-obs3_p1_4)) (K_obs3-at_p1_4)))
    (:action sensor-gather-obs3_p1_4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs3-at_p1_4)) (not (K_obs3-at_p1_4)) (K_need-post-for-gather-obs3_p1_4)) (K_not_obs3-at_p1_4)))
    (:action sensor-gather-obs3_p3_3__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs3-at_p3_3)) (not (K_obs3-at_p3_3)) (K_need-post-for-gather-obs3_p3_3)) (K_obs3-at_p3_3)))
    (:action sensor-gather-obs3_p3_3__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs3-at_p3_3)) (not (K_obs3-at_p3_3)) (K_need-post-for-gather-obs3_p3_3)) (K_not_obs3-at_p3_3)))
    (:action sensor-gather-obs3_p3_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs3-at_p3_2)) (not (K_obs3-at_p3_2)) (K_need-post-for-gather-obs3_p3_2)) (K_obs3-at_p3_2)))
    (:action sensor-gather-obs3_p3_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs3-at_p3_2)) (not (K_obs3-at_p3_2)) (K_need-post-for-gather-obs3_p3_2)) (K_not_obs3-at_p3_2)))
    (:action sensor-gather-obs3_p2_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs3-at_p2_2)) (not (K_obs3-at_p2_2)) (K_need-post-for-gather-obs3_p2_2)) (K_obs3-at_p2_2)))
    (:action sensor-gather-obs3_p2_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs3-at_p2_2)) (not (K_obs3-at_p2_2)) (K_need-post-for-gather-obs3_p2_2)) (K_not_obs3-at_p2_2)))
    (:action sensor-gather-obs3_p1_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs3-at_p1_2)) (not (K_obs3-at_p1_2)) (K_need-post-for-gather-obs3_p1_2)) (K_obs3-at_p1_2)))
    (:action sensor-gather-obs3_p1_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs3-at_p1_2)) (not (K_obs3-at_p1_2)) (K_need-post-for-gather-obs3_p1_2)) (K_not_obs3-at_p1_2)))
    (:action sensor-gather-obs3_p3_1__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs3-at_p3_1)) (not (K_obs3-at_p3_1)) (K_need-post-for-gather-obs3_p3_1)) (K_obs3-at_p3_1)))
    (:action sensor-gather-obs3_p3_1__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs3-at_p3_1)) (not (K_obs3-at_p3_1)) (K_need-post-for-gather-obs3_p3_1)) (K_not_obs3-at_p3_1)))
    (:action sensor-gather-obs3_p2_1__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs3-at_p2_1)) (not (K_obs3-at_p2_1)) (K_need-post-for-gather-obs3_p2_1)) (K_obs3-at_p2_1)))
    (:action sensor-gather-obs3_p2_1__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs3-at_p2_1)) (not (K_obs3-at_p2_1)) (K_need-post-for-gather-obs3_p2_1)) (K_not_obs3-at_p2_1)))
    (:action sensor-gather-obs3_p1_1__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs3-at_p1_1)) (not (K_obs3-at_p1_1)) (K_need-post-for-gather-obs3_p1_1)) (K_obs3-at_p1_1)))
    (:action sensor-gather-obs3_p1_1__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs3-at_p1_1)) (not (K_obs3-at_p1_1)) (K_need-post-for-gather-obs3_p1_1)) (K_not_obs3-at_p1_1)))
    (:action sensor-gather-obs4_p2_4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs4-at_p2_4)) (not (K_obs4-at_p2_4)) (K_need-post-for-gather-obs4_p2_4)) (K_obs4-at_p2_4)))
    (:action sensor-gather-obs4_p2_4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs4-at_p2_4)) (not (K_obs4-at_p2_4)) (K_need-post-for-gather-obs4_p2_4)) (K_not_obs4-at_p2_4)))
    (:action sensor-gather-obs4_p3_3__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs4-at_p3_3)) (not (K_obs4-at_p3_3)) (K_need-post-for-gather-obs4_p3_3)) (K_obs4-at_p3_3)))
    (:action sensor-gather-obs4_p3_3__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs4-at_p3_3)) (not (K_obs4-at_p3_3)) (K_need-post-for-gather-obs4_p3_3)) (K_not_obs4-at_p3_3)))
    (:action sensor-gather-obs4_p3_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs4-at_p3_2)) (not (K_obs4-at_p3_2)) (K_need-post-for-gather-obs4_p3_2)) (K_obs4-at_p3_2)))
    (:action sensor-gather-obs4_p3_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs4-at_p3_2)) (not (K_obs4-at_p3_2)) (K_need-post-for-gather-obs4_p3_2)) (K_not_obs4-at_p3_2)))
    (:action sensor-gather-obs4_p2_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs4-at_p2_2)) (not (K_obs4-at_p2_2)) (K_need-post-for-gather-obs4_p2_2)) (K_obs4-at_p2_2)))
    (:action sensor-gather-obs4_p2_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs4-at_p2_2)) (not (K_obs4-at_p2_2)) (K_need-post-for-gather-obs4_p2_2)) (K_not_obs4-at_p2_2)))
    (:action sensor-gather-obs4_p1_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs4-at_p1_2)) (not (K_obs4-at_p1_2)) (K_need-post-for-gather-obs4_p1_2)) (K_obs4-at_p1_2)))
    (:action sensor-gather-obs4_p1_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs4-at_p1_2)) (not (K_obs4-at_p1_2)) (K_need-post-for-gather-obs4_p1_2)) (K_not_obs4-at_p1_2)))
    (:action sensor-gather-obs4_p2_1__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs4-at_p2_1)) (not (K_obs4-at_p2_1)) (K_need-post-for-gather-obs4_p2_1)) (K_obs4-at_p2_1)))
    (:action sensor-gather-obs4_p2_1__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs4-at_p2_1)) (not (K_obs4-at_p2_1)) (K_need-post-for-gather-obs4_p2_1)) (K_not_obs4-at_p2_1)))
    (:action sensor-gather-obs5_p2_4__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs5-at_p2_4)) (not (K_obs5-at_p2_4)) (K_need-post-for-gather-obs5_p2_4)) (K_obs5-at_p2_4)))
    (:action sensor-gather-obs5_p2_4__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs5-at_p2_4)) (not (K_obs5-at_p2_4)) (K_need-post-for-gather-obs5_p2_4)) (K_not_obs5-at_p2_4)))
    (:action sensor-gather-obs5_p3_3__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs5-at_p3_3)) (not (K_obs5-at_p3_3)) (K_need-post-for-gather-obs5_p3_3)) (K_obs5-at_p3_3)))
    (:action sensor-gather-obs5_p3_3__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs5-at_p3_3)) (not (K_obs5-at_p3_3)) (K_need-post-for-gather-obs5_p3_3)) (K_not_obs5-at_p3_3)))
    (:action sensor-gather-obs5_p3_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs5-at_p3_2)) (not (K_obs5-at_p3_2)) (K_need-post-for-gather-obs5_p3_2)) (K_obs5-at_p3_2)))
    (:action sensor-gather-obs5_p3_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs5-at_p3_2)) (not (K_obs5-at_p3_2)) (K_need-post-for-gather-obs5_p3_2)) (K_not_obs5-at_p3_2)))
    (:action sensor-gather-obs5_p2_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs5-at_p2_2)) (not (K_obs5-at_p2_2)) (K_need-post-for-gather-obs5_p2_2)) (K_obs5-at_p2_2)))
    (:action sensor-gather-obs5_p2_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs5-at_p2_2)) (not (K_obs5-at_p2_2)) (K_need-post-for-gather-obs5_p2_2)) (K_not_obs5-at_p2_2)))
    (:action sensor-gather-obs5_p1_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs5-at_p1_2)) (not (K_obs5-at_p1_2)) (K_need-post-for-gather-obs5_p1_2)) (K_obs5-at_p1_2)))
    (:action sensor-gather-obs5_p1_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs5-at_p1_2)) (not (K_obs5-at_p1_2)) (K_need-post-for-gather-obs5_p1_2)) (K_not_obs5-at_p1_2)))
    (:action sensor-gather-obs5_p2_1__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs5-at_p2_1)) (not (K_obs5-at_p2_1)) (K_need-post-for-gather-obs5_p2_1)) (K_obs5-at_p2_1)))
    (:action sensor-gather-obs5_p2_1__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs5-at_p2_1)) (not (K_obs5-at_p2_1)) (K_need-post-for-gather-obs5_p2_1)) (K_not_obs5-at_p2_1)))
    (:action sensor-gather-obs6_p2_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs6-at_p2_2)) (not (K_obs6-at_p2_2)) (K_need-post-for-gather-obs6_p2_2)) (K_obs6-at_p2_2)))
    (:action sensor-gather-obs6_p2_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs6-at_p2_2)) (not (K_obs6-at_p2_2)) (K_need-post-for-gather-obs6_p2_2)) (K_not_obs6-at_p2_2)))
    (:action sensor-gather-obs7_p2_2__sensor__-obs0-ver0
        :effect (when (and (not (K_not_obs7-at_p2_2)) (not (K_obs7-at_p2_2)) (K_need-post-for-gather-obs7_p2_2)) (K_obs7-at_p2_2)))
    (:action sensor-gather-obs7_p2_2__sensor__-obs0-ver1
        :effect (when (and (not (K_not_obs7-at_p2_2)) (not (K_obs7-at_p2_2)) (K_need-post-for-gather-obs7_p2_2)) (K_not_obs7-at_p2_2)))
    (:action invariant-44
        :effect (when (and (not (K_obs0-at_p1_1)) (K_mine-at_p2_1)) (K_not_obs0-at_p1_1)))
    (:action invariant-45
        :effect (when (and (not (K_mine-at_p2_1)) (K_obs0-at_p1_1)) (K_not_mine-at_p2_1)))
    (:action invariant-46
        :effect (when (and (not (K_obs0-at_p1_1)) (K_mine-at_p1_2)) (K_not_obs0-at_p1_1)))
    (:action invariant-47
        :effect (when (and (not (K_mine-at_p1_2)) (K_obs0-at_p1_1)) (K_not_mine-at_p1_2)))
    (:action invariant-48
        :effect (when (and (not (K_obs0-at_p1_1)) (K_mine-at_p2_2)) (K_not_obs0-at_p1_1)))
    (:action invariant-49
        :effect (when (and (not (K_mine-at_p2_2)) (K_obs0-at_p1_1)) (K_not_mine-at_p2_2)))
    (:action invariant-50
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_obs0-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-51
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_obs0-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-52
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_obs0-at_p1_1)) (K_mine-at_p2_2)))
    (:action invariant-53
        :effect (when (and (not (K_not_obs0-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2)) (K_obs0-at_p1_1)))
    (:action invariant-54
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_obs1-at_p1_1)) (K_not_mine-at_p2_1)))
    (:action invariant-55
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_obs1-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-56
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_obs1-at_p1_1)) (K_mine-at_p2_2)))
    (:action invariant-57
        :effect (when (and (not (K_not_obs1-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2)) (K_obs1-at_p1_1)))
    (:action invariant-58
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_obs1-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-59
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_obs1-at_p1_1)) (K_not_mine-at_p1_2)))
    (:action invariant-60
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_obs1-at_p1_1)) (K_mine-at_p2_2)))
    (:action invariant-61
        :effect (when (and (not (K_not_obs1-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2)) (K_obs1-at_p1_1)))
    (:action invariant-62
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_obs2-at_p1_1)) (K_not_mine-at_p2_1)))
    (:action invariant-63
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_obs2-at_p1_1)) (K_not_mine-at_p1_2)))
    (:action invariant-64
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_obs2-at_p1_1)) (K_mine-at_p2_2)))
    (:action invariant-65
        :effect (when (and (not (K_not_obs2-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2)) (K_obs2-at_p1_1)))
    (:action invariant-66
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_not_obs1-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-67
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_obs1-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-68
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_obs1-at_p1_1)) (K_not_mine-at_p2_2)))
    (:action invariant-69
        :effect (when (and (not (K_not_obs1-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2)) (K_obs1-at_p1_1)))
    (:action invariant-70
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_not_obs2-at_p1_1)) (K_not_mine-at_p2_1)))
    (:action invariant-71
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_obs2-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-72
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_obs2-at_p1_1)) (K_not_mine-at_p2_2)))
    (:action invariant-73
        :effect (when (and (not (K_not_obs2-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2)) (K_obs2-at_p1_1)))
    (:action invariant-74
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_not_obs2-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-75
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_obs2-at_p1_1)) (K_not_mine-at_p1_2)))
    (:action invariant-76
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_obs2-at_p1_1)) (K_not_mine-at_p2_2)))
    (:action invariant-77
        :effect (when (and (not (K_not_obs2-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p2_2)) (K_obs2-at_p1_1)))
    (:action invariant-78
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_not_obs3-at_p1_1)) (K_not_mine-at_p2_1)))
    (:action invariant-79
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_obs3-at_p1_1)) (K_not_mine-at_p1_2)))
    (:action invariant-80
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_obs3-at_p1_1)) (K_not_mine-at_p2_2)))
    (:action invariant-81
        :effect (when (and (not (K_not_obs3-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p2_2)) (K_obs3-at_p1_1)))
    (:action invariant-82
        :effect (when (and (not (K_obs0-at_p1_1)) (K_obs1-at_p1_1)) (K_not_obs0-at_p1_1)))
    (:action invariant-83
        :effect (when (and (not (K_obs1-at_p1_1)) (K_obs0-at_p1_1)) (K_not_obs1-at_p1_1)))
    (:action invariant-84
        :effect (when (and (not (K_obs0-at_p1_1)) (K_obs2-at_p1_1)) (K_not_obs0-at_p1_1)))
    (:action invariant-85
        :effect (when (and (not (K_obs2-at_p1_1)) (K_obs0-at_p1_1)) (K_not_obs2-at_p1_1)))
    (:action invariant-86
        :effect (when (and (not (K_obs0-at_p1_1)) (K_obs3-at_p1_1)) (K_not_obs0-at_p1_1)))
    (:action invariant-87
        :effect (when (and (not (K_obs3-at_p1_1)) (K_obs0-at_p1_1)) (K_not_obs3-at_p1_1)))
    (:action invariant-89
        :effect (when (K_obs0-at_p1_1) (K_not_obs4-at_p1_1)))
    (:action invariant-91
        :effect (when (K_obs0-at_p1_1) (K_not_obs5-at_p1_1)))
    (:action invariant-93
        :effect (when (K_obs0-at_p1_1) (K_not_obs6-at_p1_1)))
    (:action invariant-95
        :effect (when (K_obs0-at_p1_1) (K_not_obs7-at_p1_1)))
    (:action invariant-97
        :effect (when (K_obs0-at_p1_1) (K_not_obs8-at_p1_1)))
    (:action invariant-98
        :effect (when (and (not (K_obs1-at_p1_1)) (K_obs2-at_p1_1)) (K_not_obs1-at_p1_1)))
    (:action invariant-99
        :effect (when (and (not (K_obs2-at_p1_1)) (K_obs1-at_p1_1)) (K_not_obs2-at_p1_1)))
    (:action invariant-100
        :effect (when (and (not (K_obs1-at_p1_1)) (K_obs3-at_p1_1)) (K_not_obs1-at_p1_1)))
    (:action invariant-101
        :effect (when (and (not (K_obs3-at_p1_1)) (K_obs1-at_p1_1)) (K_not_obs3-at_p1_1)))
    (:action invariant-103
        :effect (when (K_obs1-at_p1_1) (K_not_obs4-at_p1_1)))
    (:action invariant-105
        :effect (when (K_obs1-at_p1_1) (K_not_obs5-at_p1_1)))
    (:action invariant-107
        :effect (when (K_obs1-at_p1_1) (K_not_obs6-at_p1_1)))
    (:action invariant-109
        :effect (when (K_obs1-at_p1_1) (K_not_obs7-at_p1_1)))
    (:action invariant-111
        :effect (when (K_obs1-at_p1_1) (K_not_obs8-at_p1_1)))
    (:action invariant-112
        :effect (when (and (not (K_obs2-at_p1_1)) (K_obs3-at_p1_1)) (K_not_obs2-at_p1_1)))
    (:action invariant-113
        :effect (when (and (not (K_obs3-at_p1_1)) (K_obs2-at_p1_1)) (K_not_obs3-at_p1_1)))
    (:action invariant-115
        :effect (when (K_obs2-at_p1_1) (K_not_obs4-at_p1_1)))
    (:action invariant-117
        :effect (when (K_obs2-at_p1_1) (K_not_obs5-at_p1_1)))
    (:action invariant-119
        :effect (when (K_obs2-at_p1_1) (K_not_obs6-at_p1_1)))
    (:action invariant-121
        :effect (when (K_obs2-at_p1_1) (K_not_obs7-at_p1_1)))
    (:action invariant-123
        :effect (when (K_obs2-at_p1_1) (K_not_obs8-at_p1_1)))
    (:action invariant-125
        :effect (when (K_obs3-at_p1_1) (K_not_obs4-at_p1_1)))
    (:action invariant-127
        :effect (when (K_obs3-at_p1_1) (K_not_obs5-at_p1_1)))
    (:action invariant-129
        :effect (when (K_obs3-at_p1_1) (K_not_obs6-at_p1_1)))
    (:action invariant-131
        :effect (when (K_obs3-at_p1_1) (K_not_obs7-at_p1_1)))
    (:action invariant-133
        :effect (when (K_obs3-at_p1_1) (K_not_obs8-at_p1_1)))
    (:action invariant-154
        :effect (when (and (not (K_obs2-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1)) (K_not_obs2-at_p2_2)))
    (:action invariant-155
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_obs2-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-156
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-157
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_1)))
    (:action invariant-158
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-159
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_2)))
    (:action invariant-161
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_3)))
    (:action invariant-162
        :effect (when (and (not (K_obs2-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_not_obs2-at_p2_2)))
    (:action invariant-163
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_obs2-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-164
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-165
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_1)))
    (:action invariant-166
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-167
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_3) (K_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_2)))
    (:action invariant-169
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_3)))
    (:action invariant-170
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs0-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-171
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs0-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-172
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs0-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-173
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs0-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-174
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs0-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-175
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs0-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-176
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs0-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-178
        :effect (when (and (not (K_not_obs0-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs0-at_p2_2)))
    (:action invariant-179
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs1-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-180
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-181
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-182
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-183
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-184
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-185
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-187
        :effect (when (and (not (K_not_obs1-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs1-at_p2_2)))
    (:action invariant-188
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs1-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-189
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-190
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-191
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-192
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-193
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-194
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-196
        :effect (when (and (not (K_not_obs1-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs1-at_p2_2)))
    (:action invariant-197
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-198
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_not_mine-at_p2_1)))
    (:action invariant-199
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p3_1)))
    (:action invariant-200
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-201
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p3_2)))
    (:action invariant-202
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p1_3)))
    (:action invariant-203
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p2_3)))
    (:action invariant-205
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-206
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs1-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-207
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-208
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-209
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-210
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-211
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-212
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-214
        :effect (when (and (not (K_not_obs1-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs1-at_p2_2)))
    (:action invariant-215
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-216
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-217
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_not_mine-at_p3_1)))
    (:action invariant-218
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-219
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p3_2)))
    (:action invariant-220
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p1_3)))
    (:action invariant-221
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p2_3)))
    (:action invariant-223
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-224
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-225
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1)))
    (:action invariant-226
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p3_1)))
    (:action invariant-227
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-228
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_2)))
    (:action invariant-229
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_3)))
    (:action invariant-230
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_3)))
    (:action invariant-232
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-233
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-234
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-235
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-236
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-237
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-238
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-239
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-241
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-242
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs1-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-243
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-244
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-245
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-246
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-247
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-248
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-250
        :effect (when (and (not (K_not_obs1-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs1-at_p2_2)))
    (:action invariant-251
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-252
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-253
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p3_1)))
    (:action invariant-254
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_not_mine-at_p1_2)))
    (:action invariant-255
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p3_2)))
    (:action invariant-256
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p1_3)))
    (:action invariant-257
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p2_3)))
    (:action invariant-259
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-260
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-261
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1)))
    (:action invariant-262
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_1)))
    (:action invariant-263
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p1_2)))
    (:action invariant-264
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_2)))
    (:action invariant-265
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_3)))
    (:action invariant-266
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_3)))
    (:action invariant-268
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-269
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-270
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-271
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-272
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-273
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-274
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-275
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-277
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-278
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-279
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-280
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p3_1)))
    (:action invariant-281
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p1_2)))
    (:action invariant-282
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_2)))
    (:action invariant-283
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_3)))
    (:action invariant-284
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_3)))
    (:action invariant-286
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-287
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-288
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-289
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-290
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-291
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-292
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-293
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-295
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-296
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-297
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-298
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-299
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-300
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-301
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-302
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-304
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-305
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-306
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-307
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-308
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-309
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-310
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-311
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-313
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-314
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs1-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-315
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-316
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-317
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-318
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-319
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-320
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-322
        :effect (when (and (not (K_not_obs1-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs1-at_p2_2)))
    (:action invariant-323
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-324
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-325
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p3_1)))
    (:action invariant-326
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-327
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_not_mine-at_p3_2)))
    (:action invariant-328
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p1_3)))
    (:action invariant-329
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p2_3)))
    (:action invariant-331
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-332
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-333
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1)))
    (:action invariant-334
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_1)))
    (:action invariant-335
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-336
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p3_2)))
    (:action invariant-337
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_3)))
    (:action invariant-338
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_3)))
    (:action invariant-340
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-341
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-342
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-343
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-344
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-345
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-346
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-347
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-349
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-350
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-351
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-352
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p3_1)))
    (:action invariant-353
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-354
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p3_2)))
    (:action invariant-355
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_3)))
    (:action invariant-356
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_3)))
    (:action invariant-358
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-359
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-360
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-361
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-362
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-363
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-364
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-365
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-367
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-368
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-369
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-370
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-371
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-372
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-373
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-374
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-376
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-377
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-378
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-379
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-380
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-381
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-382
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-383
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-385
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-386
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-387
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-388
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_1)))
    (:action invariant-389
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p1_2)))
    (:action invariant-390
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p3_2)))
    (:action invariant-391
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_3)))
    (:action invariant-392
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_3)))
    (:action invariant-394
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-395
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-396
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-397
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-398
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-399
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-400
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-401
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-403
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-404
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-405
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-406
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-407
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-408
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-409
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-410
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-412
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-413
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-414
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-415
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-416
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-417
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-418
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-419
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-421
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-422
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-423
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-424
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-425
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-426
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-427
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-428
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-430
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-431
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-432
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-433
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-434
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-435
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-436
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-437
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-439
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-440
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-441
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-442
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-443
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-444
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-445
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-446
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-448
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-449
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-450
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-451
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-452
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-453
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-454
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-455
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-457
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-458
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs1-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-459
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-460
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-461
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-462
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-463
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-464
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-466
        :effect (when (and (not (K_not_obs1-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs1-at_p2_2)))
    (:action invariant-467
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-468
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-469
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p3_1)))
    (:action invariant-470
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-471
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p3_2)))
    (:action invariant-472
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_not_mine-at_p1_3)))
    (:action invariant-473
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p2_3)))
    (:action invariant-475
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-476
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-477
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1)))
    (:action invariant-478
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_1)))
    (:action invariant-479
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-480
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_2)))
    (:action invariant-481
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p1_3)))
    (:action invariant-482
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_3)))
    (:action invariant-484
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-485
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-486
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-487
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-488
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-489
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-490
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-491
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-493
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-494
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-495
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-496
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p3_1)))
    (:action invariant-497
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-498
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_2)))
    (:action invariant-499
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p1_3)))
    (:action invariant-500
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_3)))
    (:action invariant-502
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-503
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-504
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-505
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-506
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-507
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-508
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-509
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-511
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-512
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-513
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-514
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-515
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-516
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-517
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-518
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-520
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-521
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-522
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-523
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-524
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-525
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-526
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-527
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-529
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-530
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-531
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-532
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_1)))
    (:action invariant-533
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p1_2)))
    (:action invariant-534
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_2)))
    (:action invariant-535
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p1_3)))
    (:action invariant-536
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_3)))
    (:action invariant-538
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-539
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-540
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-541
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-542
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-543
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-544
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-545
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-547
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-548
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-549
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-550
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-551
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-552
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-553
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-554
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-556
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-557
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-558
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-559
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-560
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-561
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-562
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-563
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-565
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-566
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-567
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-568
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-569
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-570
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-571
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-572
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-574
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-575
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-576
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-577
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-578
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-579
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-580
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-581
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-583
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-584
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-585
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-586
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-587
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-588
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-589
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-590
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-592
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-593
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-594
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-595
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-596
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-597
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-598
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-599
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-601
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-602
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-603
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-604
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_1)))
    (:action invariant-605
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-606
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p3_2)))
    (:action invariant-607
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p1_3)))
    (:action invariant-608
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_3)))
    (:action invariant-610
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-611
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-612
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-613
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-614
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-615
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-616
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-617
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-619
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-620
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-621
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-622
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-623
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-624
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-625
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-626
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-628
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-629
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-630
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-631
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-632
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-633
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-634
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-635
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-637
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-638
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-639
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-640
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-641
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-642
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-643
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-644
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-646
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-647
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-648
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-649
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-650
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-651
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-652
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-653
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-655
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-656
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-657
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-658
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-659
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-660
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-661
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-662
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-664
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-665
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-666
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-667
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-668
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-669
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-670
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-671
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-673
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-674
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-675
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-676
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-677
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-678
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-679
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-680
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-682
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-683
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-684
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-685
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-686
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-687
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-688
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-689
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-691
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-692
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-693
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-694
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-695
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-696
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-697
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-698
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-700
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-701
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-702
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-703
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-704
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-705
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-706
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-707
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-709
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-710
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-711
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-712
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-713
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-714
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-715
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-716
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-718
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-719
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-720
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-721
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-722
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-723
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-724
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-725
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-727
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-728
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-729
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-730
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-731
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-732
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-733
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-734
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-736
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-737
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs6-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-738
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-739
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-740
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-741
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-742
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-743
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_mine-at_p2_3)))
    (:action invariant-745
        :effect (when (and (not (K_not_obs6-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs6-at_p2_2)))
    (:action invariant-746
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs1-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-747
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-748
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-749
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-750
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-751
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-752
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-754
        :effect (when (and (not (K_not_obs1-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs1-at_p2_2)))
    (:action invariant-755
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-756
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-757
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p3_1)))
    (:action invariant-758
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-759
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p3_2)))
    (:action invariant-760
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_mine-at_p1_3)))
    (:action invariant-761
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_not_mine-at_p2_3)))
    (:action invariant-763
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-764
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-765
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1)))
    (:action invariant-766
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_1)))
    (:action invariant-767
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-768
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_2)))
    (:action invariant-769
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_3)))
    (:action invariant-770
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p2_3)))
    (:action invariant-772
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-773
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-774
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-775
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-776
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-777
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-778
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-779
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-781
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-782
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-783
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-784
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p3_1)))
    (:action invariant-785
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-786
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_2)))
    (:action invariant-787
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_3)))
    (:action invariant-788
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p2_3)))
    (:action invariant-790
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-791
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-792
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-793
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-794
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-795
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-796
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-797
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-799
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-800
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-801
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-802
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-803
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-804
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-805
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-806
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-808
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-809
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-810
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-811
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-812
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-813
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-814
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-815
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-817
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-818
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-819
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-820
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_1)))
    (:action invariant-821
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p1_2)))
    (:action invariant-822
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_2)))
    (:action invariant-823
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_3)))
    (:action invariant-824
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p2_3)))
    (:action invariant-826
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-827
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-828
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-829
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-830
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-831
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-832
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-833
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-835
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-836
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-837
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-838
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-839
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-840
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-841
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-842
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-844
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-845
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-846
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-847
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-848
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-849
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-850
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-851
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-853
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-854
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-855
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-856
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-857
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-858
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-859
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-860
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-862
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-863
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-864
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-865
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-866
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-867
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-868
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-869
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-871
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-872
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-873
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-874
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-875
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-876
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-877
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-878
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-880
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-881
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-882
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-883
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-884
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-885
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-886
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-887
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-889
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-890
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-891
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-892
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_1)))
    (:action invariant-893
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-894
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p3_2)))
    (:action invariant-895
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_3)))
    (:action invariant-896
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p2_3)))
    (:action invariant-898
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-899
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-900
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-901
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-902
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-903
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-904
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-905
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-907
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-908
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-909
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-910
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-911
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-912
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-913
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-914
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-916
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-917
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-918
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-919
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-920
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-921
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-922
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-923
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-925
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-926
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-927
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-928
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-929
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-930
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-931
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-932
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-934
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-935
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-936
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-937
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-938
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-939
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-940
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-941
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-943
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-944
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-945
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-946
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-947
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-948
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-949
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-950
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-952
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-953
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-954
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-955
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-956
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-957
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-958
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-959
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-961
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-962
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-963
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-964
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-965
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-966
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-967
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-968
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-970
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-971
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-972
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-973
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-974
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-975
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-976
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-977
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-979
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-980
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-981
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-982
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-983
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-984
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-985
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-986
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-988
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-989
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-990
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-991
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-992
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-993
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-994
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-995
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-997
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-998
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-999
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-1000
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1001
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1002
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1003
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-1004
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1006
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-1007
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-1008
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-1009
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1010
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1011
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1012
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-1013
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1015
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-1016
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-1017
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-1018
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1019
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1020
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1021
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-1022
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1024
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-1025
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs6-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-1026
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-1027
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1028
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1029
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1030
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_mine-at_p1_3)))
    (:action invariant-1031
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1033
        :effect (when (and (not (K_not_obs6-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs6-at_p2_2)))
    (:action invariant-1034
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-1035
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p2_1)))
    (:action invariant-1036
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_1)))
    (:action invariant-1037
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p1_2)))
    (:action invariant-1038
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_mine-at_p3_2)))
    (:action invariant-1039
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p1_3)))
    (:action invariant-1040
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p2_3)))
    (:action invariant-1042
        :effect (when (and (not (K_not_obs2-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p2_2)))
    (:action invariant-1043
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-1044
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-1045
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-1046
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-1047
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-1048
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1049
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1051
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-1052
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-1053
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-1054
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-1055
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-1056
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-1057
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1058
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1060
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-1061
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-1062
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-1063
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-1064
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-1065
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-1066
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1067
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1069
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-1070
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-1071
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-1072
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1073
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-1074
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-1075
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1076
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1078
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-1079
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-1080
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-1081
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1082
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-1083
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-1084
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1085
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1087
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-1088
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-1089
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-1090
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1091
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-1092
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-1093
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1094
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1096
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-1097
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-1098
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-1099
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1100
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-1101
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-1102
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1103
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1105
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-1106
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-1107
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-1108
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-1109
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1110
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-1111
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1112
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1114
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-1115
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-1116
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-1117
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-1118
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1119
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-1120
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1121
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1123
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-1124
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-1125
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-1126
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-1127
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1128
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-1129
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1130
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1132
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-1133
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-1134
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-1135
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-1136
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1137
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-1138
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1139
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1141
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-1142
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-1143
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-1144
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1145
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1146
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-1147
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1148
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1150
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-1151
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-1152
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-1153
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1154
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1155
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-1156
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1157
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1159
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-1160
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-1161
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-1162
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1163
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1164
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-1165
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1166
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1168
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-1169
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs6-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-1170
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-1171
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1172
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1173
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_mine-at_p3_2)))
    (:action invariant-1174
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1175
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1177
        :effect (when (and (not (K_not_obs6-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs6-at_p2_2)))
    (:action invariant-1178
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-1179
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-1180
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-1181
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-1182
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1183
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1184
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1186
        :effect (when (and (not (K_not_obs3-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p2_2)))
    (:action invariant-1187
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-1188
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-1189
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-1190
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-1191
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1192
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1193
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1195
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-1196
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-1197
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-1198
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-1199
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-1200
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1201
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1202
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1204
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-1205
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-1206
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-1207
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-1208
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-1209
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1210
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1211
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1213
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-1214
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-1215
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-1216
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1217
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-1218
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1219
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1220
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1222
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-1223
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-1224
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-1225
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1226
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-1227
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1228
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1229
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1231
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-1232
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-1233
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-1234
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1235
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-1236
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1237
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1238
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1240
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-1241
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs6-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-1242
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-1243
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1244
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_mine-at_p1_2)))
    (:action invariant-1245
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1246
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1247
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1249
        :effect (when (and (not (K_not_obs6-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs6-at_p2_2)))
    (:action invariant-1250
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-1251
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-1252
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-1253
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1254
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1255
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1256
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1258
        :effect (when (and (not (K_not_obs4-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs4-at_p2_2)))
    (:action invariant-1259
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-1260
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-1261
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-1262
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1263
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1264
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1265
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1267
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-1268
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-1269
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-1270
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-1271
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1272
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1273
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1274
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1276
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-1277
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs6-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-1278
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-1279
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_mine-at_p3_1)))
    (:action invariant-1280
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1281
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1282
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1283
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1285
        :effect (when (and (not (K_not_obs6-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs6-at_p2_2)))
    (:action invariant-1286
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs5-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-1287
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-1288
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1289
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1290
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1291
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1292
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1294
        :effect (when (and (not (K_not_obs5-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs5-at_p2_2)))
    (:action invariant-1295
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs6-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-1296
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_mine-at_p2_1)))
    (:action invariant-1297
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1298
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1299
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1300
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1301
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1303
        :effect (when (and (not (K_not_obs6-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs6-at_p2_2)))
    (:action invariant-1304
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs6-at_p2_2)) (K_mine-at_p1_1)))
    (:action invariant-1305
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-1306
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1307
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1308
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1309
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1310
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1312
        :effect (when (and (not (K_not_obs6-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs6-at_p2_2)))
    (:action invariant-1313
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs7-at_p2_2)) (K_not_mine-at_p1_1)))
    (:action invariant-1314
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs7-at_p2_2)) (K_not_mine-at_p2_1)))
    (:action invariant-1315
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs7-at_p2_2)) (K_not_mine-at_p3_1)))
    (:action invariant-1316
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs7-at_p2_2)) (K_not_mine-at_p1_2)))
    (:action invariant-1317
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs7-at_p2_2)) (K_not_mine-at_p3_2)))
    (:action invariant-1318
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs7-at_p2_2)) (K_not_mine-at_p1_3)))
    (:action invariant-1319
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs7-at_p2_2)) (K_not_mine-at_p2_3)))
    (:action invariant-1321
        :effect (when (and (not (K_not_obs7-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs7-at_p2_2)))
    (:action invariant-1329
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1338
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_mine-at_p1_1)) (K_not_mine-at_p3_3)))
    (:action invariant-1347
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p3_3)))
    (:action invariant-1356
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1365
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p3_3)))
    (:action invariant-1374
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1383
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1392
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1401
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p3_3)))
    (:action invariant-1410
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1419
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1428
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1437
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1446
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1455
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1464
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1473
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p3_3)))
    (:action invariant-1482
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1491
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1500
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1509
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1518
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1527
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1536
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1545
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1554
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1563
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1572
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1581
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1590
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1599
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1608
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1617
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p3_3)))
    (:action invariant-1626
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1635
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1644
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1653
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1662
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1671
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1680
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1689
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1698
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1707
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1716
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1725
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1734
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1743
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1752
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1761
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1770
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1779
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1788
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1797
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1806
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1815
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1824
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1833
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1842
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1851
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1860
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1869
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1878
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1887
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1896
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs7-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1905
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p2_2) (K_not_mine-at_p1_1)) (K_not_mine-at_p3_3)))
    (:action invariant-1914
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1923
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1932
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1941
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1950
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1959
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1968
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1977
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1986
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-1995
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2004
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2013
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2022
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2031
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2040
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2049
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2058
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2067
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2076
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2085
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2094
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2103
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2112
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2121
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2130
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2139
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2148
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2157
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2166
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2175
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2184
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs7-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2193
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2202
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2211
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2220
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2229
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2238
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2247
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2256
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2265
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2274
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2283
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2292
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2301
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2310
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2319
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2328
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs7-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2337
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2346
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2355
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2364
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2373
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2382
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2391
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2400
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs7-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2409
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs5-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2418
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2427
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2436
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs7-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2445
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs6-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2454
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs7-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2463
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs7-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2472
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs8-at_p2_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2474
        :effect (when (and (not (K_obs0-at_p2_2)) (K_obs1-at_p2_2)) (K_not_obs0-at_p2_2)))
    (:action invariant-2475
        :effect (when (and (not (K_obs1-at_p2_2)) (K_obs0-at_p2_2)) (K_not_obs1-at_p2_2)))
    (:action invariant-2476
        :effect (when (and (not (K_obs0-at_p2_2)) (K_obs2-at_p2_2)) (K_not_obs0-at_p2_2)))
    (:action invariant-2477
        :effect (when (and (not (K_obs2-at_p2_2)) (K_obs0-at_p2_2)) (K_not_obs2-at_p2_2)))
    (:action invariant-2478
        :effect (when (and (not (K_obs0-at_p2_2)) (K_obs3-at_p2_2)) (K_not_obs0-at_p2_2)))
    (:action invariant-2479
        :effect (when (and (not (K_obs3-at_p2_2)) (K_obs0-at_p2_2)) (K_not_obs3-at_p2_2)))
    (:action invariant-2480
        :effect (when (and (not (K_obs0-at_p2_2)) (K_obs4-at_p2_2)) (K_not_obs0-at_p2_2)))
    (:action invariant-2481
        :effect (when (and (not (K_obs4-at_p2_2)) (K_obs0-at_p2_2)) (K_not_obs4-at_p2_2)))
    (:action invariant-2482
        :effect (when (and (not (K_obs0-at_p2_2)) (K_obs5-at_p2_2)) (K_not_obs0-at_p2_2)))
    (:action invariant-2483
        :effect (when (and (not (K_obs5-at_p2_2)) (K_obs0-at_p2_2)) (K_not_obs5-at_p2_2)))
    (:action invariant-2484
        :effect (when (and (not (K_obs0-at_p2_2)) (K_obs6-at_p2_2)) (K_not_obs0-at_p2_2)))
    (:action invariant-2485
        :effect (when (and (not (K_obs6-at_p2_2)) (K_obs0-at_p2_2)) (K_not_obs6-at_p2_2)))
    (:action invariant-2486
        :effect (when (and (not (K_obs0-at_p2_2)) (K_obs7-at_p2_2)) (K_not_obs0-at_p2_2)))
    (:action invariant-2487
        :effect (when (and (not (K_obs7-at_p2_2)) (K_obs0-at_p2_2)) (K_not_obs7-at_p2_2)))
    (:action invariant-2488
        :effect (when (and (not (K_obs0-at_p2_2)) (K_obs8-at_p2_2)) (K_not_obs0-at_p2_2)))
    (:action invariant-2489
        :effect (when (and (not (K_obs8-at_p2_2)) (K_obs0-at_p2_2)) (K_not_obs8-at_p2_2)))
    (:action invariant-2490
        :effect (when (and (not (K_obs1-at_p2_2)) (K_obs2-at_p2_2)) (K_not_obs1-at_p2_2)))
    (:action invariant-2491
        :effect (when (and (not (K_obs2-at_p2_2)) (K_obs1-at_p2_2)) (K_not_obs2-at_p2_2)))
    (:action invariant-2492
        :effect (when (and (not (K_obs1-at_p2_2)) (K_obs3-at_p2_2)) (K_not_obs1-at_p2_2)))
    (:action invariant-2493
        :effect (when (and (not (K_obs3-at_p2_2)) (K_obs1-at_p2_2)) (K_not_obs3-at_p2_2)))
    (:action invariant-2494
        :effect (when (and (not (K_obs1-at_p2_2)) (K_obs4-at_p2_2)) (K_not_obs1-at_p2_2)))
    (:action invariant-2495
        :effect (when (and (not (K_obs4-at_p2_2)) (K_obs1-at_p2_2)) (K_not_obs4-at_p2_2)))
    (:action invariant-2496
        :effect (when (and (not (K_obs1-at_p2_2)) (K_obs5-at_p2_2)) (K_not_obs1-at_p2_2)))
    (:action invariant-2497
        :effect (when (and (not (K_obs5-at_p2_2)) (K_obs1-at_p2_2)) (K_not_obs5-at_p2_2)))
    (:action invariant-2498
        :effect (when (and (not (K_obs1-at_p2_2)) (K_obs6-at_p2_2)) (K_not_obs1-at_p2_2)))
    (:action invariant-2499
        :effect (when (and (not (K_obs6-at_p2_2)) (K_obs1-at_p2_2)) (K_not_obs6-at_p2_2)))
    (:action invariant-2500
        :effect (when (and (not (K_obs1-at_p2_2)) (K_obs7-at_p2_2)) (K_not_obs1-at_p2_2)))
    (:action invariant-2501
        :effect (when (and (not (K_obs7-at_p2_2)) (K_obs1-at_p2_2)) (K_not_obs7-at_p2_2)))
    (:action invariant-2502
        :effect (when (and (not (K_obs1-at_p2_2)) (K_obs8-at_p2_2)) (K_not_obs1-at_p2_2)))
    (:action invariant-2503
        :effect (when (and (not (K_obs8-at_p2_2)) (K_obs1-at_p2_2)) (K_not_obs8-at_p2_2)))
    (:action invariant-2504
        :effect (when (and (not (K_obs2-at_p2_2)) (K_obs3-at_p2_2)) (K_not_obs2-at_p2_2)))
    (:action invariant-2505
        :effect (when (and (not (K_obs3-at_p2_2)) (K_obs2-at_p2_2)) (K_not_obs3-at_p2_2)))
    (:action invariant-2506
        :effect (when (and (not (K_obs2-at_p2_2)) (K_obs4-at_p2_2)) (K_not_obs2-at_p2_2)))
    (:action invariant-2507
        :effect (when (and (not (K_obs4-at_p2_2)) (K_obs2-at_p2_2)) (K_not_obs4-at_p2_2)))
    (:action invariant-2508
        :effect (when (and (not (K_obs2-at_p2_2)) (K_obs5-at_p2_2)) (K_not_obs2-at_p2_2)))
    (:action invariant-2509
        :effect (when (and (not (K_obs5-at_p2_2)) (K_obs2-at_p2_2)) (K_not_obs5-at_p2_2)))
    (:action invariant-2510
        :effect (when (and (not (K_obs2-at_p2_2)) (K_obs6-at_p2_2)) (K_not_obs2-at_p2_2)))
    (:action invariant-2511
        :effect (when (and (not (K_obs6-at_p2_2)) (K_obs2-at_p2_2)) (K_not_obs6-at_p2_2)))
    (:action invariant-2512
        :effect (when (and (not (K_obs2-at_p2_2)) (K_obs7-at_p2_2)) (K_not_obs2-at_p2_2)))
    (:action invariant-2513
        :effect (when (and (not (K_obs7-at_p2_2)) (K_obs2-at_p2_2)) (K_not_obs7-at_p2_2)))
    (:action invariant-2514
        :effect (when (and (not (K_obs2-at_p2_2)) (K_obs8-at_p2_2)) (K_not_obs2-at_p2_2)))
    (:action invariant-2515
        :effect (when (and (not (K_obs8-at_p2_2)) (K_obs2-at_p2_2)) (K_not_obs8-at_p2_2)))
    (:action invariant-2516
        :effect (when (and (not (K_obs3-at_p2_2)) (K_obs4-at_p2_2)) (K_not_obs3-at_p2_2)))
    (:action invariant-2517
        :effect (when (and (not (K_obs4-at_p2_2)) (K_obs3-at_p2_2)) (K_not_obs4-at_p2_2)))
    (:action invariant-2518
        :effect (when (and (not (K_obs3-at_p2_2)) (K_obs5-at_p2_2)) (K_not_obs3-at_p2_2)))
    (:action invariant-2519
        :effect (when (and (not (K_obs5-at_p2_2)) (K_obs3-at_p2_2)) (K_not_obs5-at_p2_2)))
    (:action invariant-2520
        :effect (when (and (not (K_obs3-at_p2_2)) (K_obs6-at_p2_2)) (K_not_obs3-at_p2_2)))
    (:action invariant-2521
        :effect (when (and (not (K_obs6-at_p2_2)) (K_obs3-at_p2_2)) (K_not_obs6-at_p2_2)))
    (:action invariant-2522
        :effect (when (and (not (K_obs3-at_p2_2)) (K_obs7-at_p2_2)) (K_not_obs3-at_p2_2)))
    (:action invariant-2523
        :effect (when (and (not (K_obs7-at_p2_2)) (K_obs3-at_p2_2)) (K_not_obs7-at_p2_2)))
    (:action invariant-2524
        :effect (when (and (not (K_obs3-at_p2_2)) (K_obs8-at_p2_2)) (K_not_obs3-at_p2_2)))
    (:action invariant-2525
        :effect (when (and (not (K_obs8-at_p2_2)) (K_obs3-at_p2_2)) (K_not_obs8-at_p2_2)))
    (:action invariant-2526
        :effect (when (and (not (K_obs4-at_p2_2)) (K_obs5-at_p2_2)) (K_not_obs4-at_p2_2)))
    (:action invariant-2527
        :effect (when (and (not (K_obs5-at_p2_2)) (K_obs4-at_p2_2)) (K_not_obs5-at_p2_2)))
    (:action invariant-2528
        :effect (when (and (not (K_obs4-at_p2_2)) (K_obs6-at_p2_2)) (K_not_obs4-at_p2_2)))
    (:action invariant-2529
        :effect (when (and (not (K_obs6-at_p2_2)) (K_obs4-at_p2_2)) (K_not_obs6-at_p2_2)))
    (:action invariant-2530
        :effect (when (and (not (K_obs4-at_p2_2)) (K_obs7-at_p2_2)) (K_not_obs4-at_p2_2)))
    (:action invariant-2531
        :effect (when (and (not (K_obs7-at_p2_2)) (K_obs4-at_p2_2)) (K_not_obs7-at_p2_2)))
    (:action invariant-2532
        :effect (when (and (not (K_obs4-at_p2_2)) (K_obs8-at_p2_2)) (K_not_obs4-at_p2_2)))
    (:action invariant-2533
        :effect (when (and (not (K_obs8-at_p2_2)) (K_obs4-at_p2_2)) (K_not_obs8-at_p2_2)))
    (:action invariant-2534
        :effect (when (and (not (K_obs5-at_p2_2)) (K_obs6-at_p2_2)) (K_not_obs5-at_p2_2)))
    (:action invariant-2535
        :effect (when (and (not (K_obs6-at_p2_2)) (K_obs5-at_p2_2)) (K_not_obs6-at_p2_2)))
    (:action invariant-2536
        :effect (when (and (not (K_obs5-at_p2_2)) (K_obs7-at_p2_2)) (K_not_obs5-at_p2_2)))
    (:action invariant-2537
        :effect (when (and (not (K_obs7-at_p2_2)) (K_obs5-at_p2_2)) (K_not_obs7-at_p2_2)))
    (:action invariant-2538
        :effect (when (and (not (K_obs5-at_p2_2)) (K_obs8-at_p2_2)) (K_not_obs5-at_p2_2)))
    (:action invariant-2539
        :effect (when (and (not (K_obs8-at_p2_2)) (K_obs5-at_p2_2)) (K_not_obs8-at_p2_2)))
    (:action invariant-2540
        :effect (when (and (not (K_obs6-at_p2_2)) (K_obs7-at_p2_2)) (K_not_obs6-at_p2_2)))
    (:action invariant-2541
        :effect (when (and (not (K_obs7-at_p2_2)) (K_obs6-at_p2_2)) (K_not_obs7-at_p2_2)))
    (:action invariant-2542
        :effect (when (and (not (K_obs6-at_p2_2)) (K_obs8-at_p2_2)) (K_not_obs6-at_p2_2)))
    (:action invariant-2543
        :effect (when (and (not (K_obs8-at_p2_2)) (K_obs6-at_p2_2)) (K_not_obs8-at_p2_2)))
    (:action invariant-2544
        :effect (when (and (not (K_obs7-at_p2_2)) (K_obs8-at_p2_2)) (K_not_obs7-at_p2_2)))
    (:action invariant-2545
        :effect (when (and (not (K_obs8-at_p2_2)) (K_obs7-at_p2_2)) (K_not_obs8-at_p2_2)))
    (:action invariant-2546
        :effect (when (and (not (K_obs0-at_p2_1)) (K_mine-at_p1_1)) (K_not_obs0-at_p2_1)))
    (:action invariant-2547
        :effect (when (and (not (K_mine-at_p1_1)) (K_obs0-at_p2_1)) (K_not_mine-at_p1_1)))
    (:action invariant-2548
        :effect (when (and (not (K_obs0-at_p2_1)) (K_mine-at_p3_1)) (K_not_obs0-at_p2_1)))
    (:action invariant-2549
        :effect (when (and (not (K_mine-at_p3_1)) (K_obs0-at_p2_1)) (K_not_mine-at_p3_1)))
    (:action invariant-2550
        :effect (when (and (not (K_obs0-at_p2_1)) (K_mine-at_p1_2)) (K_not_obs0-at_p2_1)))
    (:action invariant-2551
        :effect (when (and (not (K_mine-at_p1_2)) (K_obs0-at_p2_1)) (K_not_mine-at_p1_2)))
    (:action invariant-2552
        :effect (when (and (not (K_obs0-at_p2_1)) (K_mine-at_p2_2)) (K_not_obs0-at_p2_1)))
    (:action invariant-2553
        :effect (when (and (not (K_mine-at_p2_2)) (K_obs0-at_p2_1)) (K_not_mine-at_p2_2)))
    (:action invariant-2554
        :effect (when (and (not (K_obs0-at_p2_1)) (K_mine-at_p3_2)) (K_not_obs0-at_p2_1)))
    (:action invariant-2555
        :effect (when (and (not (K_mine-at_p3_2)) (K_obs0-at_p2_1)) (K_not_mine-at_p3_2)))
    (:action invariant-2556
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs0-at_p2_1)) (K_mine-at_p1_1)))
    (:action invariant-2557
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs0-at_p2_1)) (K_mine-at_p3_1)))
    (:action invariant-2558
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs0-at_p2_1)) (K_mine-at_p1_2)))
    (:action invariant-2559
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs0-at_p2_1)) (K_mine-at_p2_2)))
    (:action invariant-2560
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p1_1) (K_not_obs0-at_p2_1)) (K_mine-at_p3_2)))
    (:action invariant-2561
        :effect (when (and (not (K_not_obs0-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1)) (K_obs0-at_p2_1)))
    (:action invariant-2562
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs1-at_p2_1)) (K_not_mine-at_p1_1)))
    (:action invariant-2563
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_mine-at_p3_1)))
    (:action invariant-2564
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_mine-at_p1_2)))
    (:action invariant-2565
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_mine-at_p2_2)))
    (:action invariant-2566
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_mine-at_p3_2)))
    (:action invariant-2567
        :effect (when (and (not (K_not_obs1-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1)) (K_obs1-at_p2_1)))
    (:action invariant-2568
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs1-at_p2_1)) (K_mine-at_p1_1)))
    (:action invariant-2569
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_not_mine-at_p3_1)))
    (:action invariant-2570
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_mine-at_p1_2)))
    (:action invariant-2571
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_mine-at_p2_2)))
    (:action invariant-2572
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_mine-at_p3_2)))
    (:action invariant-2573
        :effect (when (and (not (K_not_obs1-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1)) (K_obs1-at_p2_1)))
    (:action invariant-2574
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs2-at_p2_1)) (K_not_mine-at_p1_1)))
    (:action invariant-2575
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_not_mine-at_p3_1)))
    (:action invariant-2576
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p1_2)))
    (:action invariant-2577
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p2_2)))
    (:action invariant-2578
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p3_2)))
    (:action invariant-2579
        :effect (when (and (not (K_not_obs2-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1)) (K_obs2-at_p2_1)))
    (:action invariant-2580
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs1-at_p2_1)) (K_mine-at_p1_1)))
    (:action invariant-2581
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_mine-at_p3_1)))
    (:action invariant-2582
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_not_mine-at_p1_2)))
    (:action invariant-2583
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_mine-at_p2_2)))
    (:action invariant-2584
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_mine-at_p3_2)))
    (:action invariant-2585
        :effect (when (and (not (K_not_obs1-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1)) (K_obs1-at_p2_1)))
    (:action invariant-2586
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs2-at_p2_1)) (K_not_mine-at_p1_1)))
    (:action invariant-2587
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p3_1)))
    (:action invariant-2588
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_not_mine-at_p1_2)))
    (:action invariant-2589
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p2_2)))
    (:action invariant-2590
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p3_2)))
    (:action invariant-2591
        :effect (when (and (not (K_not_obs2-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1)) (K_obs2-at_p2_1)))
    (:action invariant-2592
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs2-at_p2_1)) (K_mine-at_p1_1)))
    (:action invariant-2593
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_not_mine-at_p3_1)))
    (:action invariant-2594
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_not_mine-at_p1_2)))
    (:action invariant-2595
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p2_2)))
    (:action invariant-2596
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p3_2)))
    (:action invariant-2597
        :effect (when (and (not (K_not_obs2-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1)) (K_obs2-at_p2_1)))
    (:action invariant-2598
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs3-at_p2_1)) (K_not_mine-at_p1_1)))
    (:action invariant-2599
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p3_1)))
    (:action invariant-2600
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p1_2)))
    (:action invariant-2601
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_mine-at_p2_2)))
    (:action invariant-2602
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_mine-at_p3_2)))
    (:action invariant-2603
        :effect (when (and (not (K_not_obs3-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1)) (K_obs3-at_p2_1)))
    (:action invariant-2604
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs1-at_p2_1)) (K_mine-at_p1_1)))
    (:action invariant-2605
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_mine-at_p3_1)))
    (:action invariant-2606
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_mine-at_p1_2)))
    (:action invariant-2607
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_not_mine-at_p2_2)))
    (:action invariant-2608
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_mine-at_p3_2)))
    (:action invariant-2609
        :effect (when (and (not (K_not_obs1-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1)) (K_obs1-at_p2_1)))
    (:action invariant-2610
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs2-at_p2_1)) (K_not_mine-at_p1_1)))
    (:action invariant-2611
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p3_1)))
    (:action invariant-2612
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p1_2)))
    (:action invariant-2613
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_not_mine-at_p2_2)))
    (:action invariant-2614
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p3_2)))
    (:action invariant-2615
        :effect (when (and (not (K_not_obs2-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1)) (K_obs2-at_p2_1)))
    (:action invariant-2616
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs2-at_p2_1)) (K_mine-at_p1_1)))
    (:action invariant-2617
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_not_mine-at_p3_1)))
    (:action invariant-2618
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p1_2)))
    (:action invariant-2619
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_not_mine-at_p2_2)))
    (:action invariant-2620
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p3_2)))
    (:action invariant-2621
        :effect (when (and (not (K_not_obs2-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1)) (K_obs2-at_p2_1)))
    (:action invariant-2622
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs3-at_p2_1)) (K_not_mine-at_p1_1)))
    (:action invariant-2623
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p3_1)))
    (:action invariant-2624
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_mine-at_p1_2)))
    (:action invariant-2625
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p2_2)))
    (:action invariant-2626
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_mine-at_p3_2)))
    (:action invariant-2627
        :effect (when (and (not (K_not_obs3-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1)) (K_obs3-at_p2_1)))
    (:action invariant-2628
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs2-at_p2_1)) (K_mine-at_p1_1)))
    (:action invariant-2629
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p3_1)))
    (:action invariant-2630
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_not_mine-at_p1_2)))
    (:action invariant-2631
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_not_mine-at_p2_2)))
    (:action invariant-2632
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p3_2)))
    (:action invariant-2633
        :effect (when (and (not (K_not_obs2-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1)) (K_obs2-at_p2_1)))
    (:action invariant-2634
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs3-at_p2_1)) (K_not_mine-at_p1_1)))
    (:action invariant-2635
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_mine-at_p3_1)))
    (:action invariant-2636
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p1_2)))
    (:action invariant-2637
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p2_2)))
    (:action invariant-2638
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_mine-at_p3_2)))
    (:action invariant-2639
        :effect (when (and (not (K_not_obs3-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1)) (K_obs3-at_p2_1)))
    (:action invariant-2640
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs3-at_p2_1)) (K_mine-at_p1_1)))
    (:action invariant-2641
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p3_1)))
    (:action invariant-2642
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p1_2)))
    (:action invariant-2643
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p2_2)))
    (:action invariant-2644
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_mine-at_p3_2)))
    (:action invariant-2645
        :effect (when (and (not (K_not_obs3-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p1_1)) (K_obs3-at_p2_1)))
    (:action invariant-2646
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs4-at_p2_1)) (K_not_mine-at_p1_1)))
    (:action invariant-2647
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_not_mine-at_p3_1)))
    (:action invariant-2648
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_not_mine-at_p1_2)))
    (:action invariant-2649
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_not_mine-at_p2_2)))
    (:action invariant-2650
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_mine-at_p3_2)))
    (:action invariant-2651
        :effect (when (and (not (K_not_obs4-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p1_1)) (K_obs4-at_p2_1)))
    (:action invariant-2652
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs1-at_p2_1)) (K_mine-at_p1_1)))
    (:action invariant-2653
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_mine-at_p3_1)))
    (:action invariant-2654
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_mine-at_p1_2)))
    (:action invariant-2655
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_mine-at_p2_2)))
    (:action invariant-2656
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p1_1) (K_not_obs1-at_p2_1)) (K_not_mine-at_p3_2)))
    (:action invariant-2657
        :effect (when (and (not (K_not_obs1-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1)) (K_obs1-at_p2_1)))
    (:action invariant-2658
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs2-at_p2_1)) (K_not_mine-at_p1_1)))
    (:action invariant-2659
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p3_1)))
    (:action invariant-2660
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p1_2)))
    (:action invariant-2661
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p2_2)))
    (:action invariant-2662
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_not_mine-at_p3_2)))
    (:action invariant-2663
        :effect (when (and (not (K_not_obs2-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1)) (K_obs2-at_p2_1)))
    (:action invariant-2664
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs2-at_p2_1)) (K_mine-at_p1_1)))
    (:action invariant-2665
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_not_mine-at_p3_1)))
    (:action invariant-2666
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p1_2)))
    (:action invariant-2667
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p2_2)))
    (:action invariant-2668
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_not_mine-at_p3_2)))
    (:action invariant-2669
        :effect (when (and (not (K_not_obs2-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1)) (K_obs2-at_p2_1)))
    (:action invariant-2670
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs3-at_p2_1)) (K_not_mine-at_p1_1)))
    (:action invariant-2671
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p3_1)))
    (:action invariant-2672
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_mine-at_p1_2)))
    (:action invariant-2673
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_mine-at_p2_2)))
    (:action invariant-2674
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p3_2)))
    (:action invariant-2675
        :effect (when (and (not (K_not_obs3-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1)) (K_obs3-at_p2_1)))
    (:action invariant-2676
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs2-at_p2_1)) (K_mine-at_p1_1)))
    (:action invariant-2677
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p3_1)))
    (:action invariant-2678
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_not_mine-at_p1_2)))
    (:action invariant-2679
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p2_2)))
    (:action invariant-2680
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_not_mine-at_p3_2)))
    (:action invariant-2681
        :effect (when (and (not (K_not_obs2-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1)) (K_obs2-at_p2_1)))
    (:action invariant-2682
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs3-at_p2_1)) (K_not_mine-at_p1_1)))
    (:action invariant-2683
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_mine-at_p3_1)))
    (:action invariant-2684
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p1_2)))
    (:action invariant-2685
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_mine-at_p2_2)))
    (:action invariant-2686
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p3_2)))
    (:action invariant-2687
        :effect (when (and (not (K_not_obs3-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1)) (K_obs3-at_p2_1)))
    (:action invariant-2688
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs3-at_p2_1)) (K_mine-at_p1_1)))
    (:action invariant-2689
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p3_1)))
    (:action invariant-2690
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p1_2)))
    (:action invariant-2691
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_mine-at_p2_2)))
    (:action invariant-2692
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p3_2)))
    (:action invariant-2693
        :effect (when (and (not (K_not_obs3-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1)) (K_obs3-at_p2_1)))
    (:action invariant-2694
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs4-at_p2_1)) (K_not_mine-at_p1_1)))
    (:action invariant-2695
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_not_mine-at_p3_1)))
    (:action invariant-2696
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_not_mine-at_p1_2)))
    (:action invariant-2697
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_mine-at_p2_2)))
    (:action invariant-2698
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_not_mine-at_p3_2)))
    (:action invariant-2699
        :effect (when (and (not (K_not_obs4-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1)) (K_obs4-at_p2_1)))
    (:action invariant-2700
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs2-at_p2_1)) (K_mine-at_p1_1)))
    (:action invariant-2701
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p3_1)))
    (:action invariant-2702
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_mine-at_p1_2)))
    (:action invariant-2703
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_not_mine-at_p2_2)))
    (:action invariant-2704
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p1_1) (K_not_obs2-at_p2_1)) (K_not_mine-at_p3_2)))
    (:action invariant-2705
        :effect (when (and (not (K_not_obs2-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1)) (K_obs2-at_p2_1)))
    (:action invariant-2706
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs3-at_p2_1)) (K_not_mine-at_p1_1)))
    (:action invariant-2707
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_mine-at_p3_1)))
    (:action invariant-2708
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_mine-at_p1_2)))
    (:action invariant-2709
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p2_2)))
    (:action invariant-2710
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p3_2)))
    (:action invariant-2711
        :effect (when (and (not (K_not_obs3-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1)) (K_obs3-at_p2_1)))
    (:action invariant-2712
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs3-at_p2_1)) (K_mine-at_p1_1)))
    (:action invariant-2713
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p3_1)))
    (:action invariant-2714
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_mine-at_p1_2)))
    (:action invariant-2715
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p2_2)))
    (:action invariant-2716
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p3_2)))
    (:action invariant-2717
        :effect (when (and (not (K_not_obs3-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1)) (K_obs3-at_p2_1)))
    (:action invariant-2718
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs4-at_p2_1)) (K_not_mine-at_p1_1)))
    (:action invariant-2719
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_not_mine-at_p3_1)))
    (:action invariant-2720
        :effect (when (and (not (K_not_mine-at_p1_2)) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_mine-at_p1_2)))
    (:action invariant-2721
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_not_mine-at_p2_2)))
    (:action invariant-2722
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_not_mine-at_p3_2)))
    (:action invariant-2723
        :effect (when (and (not (K_not_obs4-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1)) (K_obs4-at_p2_1)))
    (:action invariant-2724
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs3-at_p2_1)) (K_mine-at_p1_1)))
    (:action invariant-2725
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_mine-at_p3_1)))
    (:action invariant-2726
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p1_2)))
    (:action invariant-2727
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p2_2)))
    (:action invariant-2728
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p1_1) (K_not_obs3-at_p2_1)) (K_not_mine-at_p3_2)))
    (:action invariant-2729
        :effect (when (and (not (K_not_obs3-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1)) (K_obs3-at_p2_1)))
    (:action invariant-2730
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs4-at_p2_1)) (K_not_mine-at_p1_1)))
    (:action invariant-2731
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_mine-at_p3_1)))
    (:action invariant-2732
        :effect (when (and (not (K_mine-at_p1_2)) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_not_mine-at_p1_2)))
    (:action invariant-2733
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_not_mine-at_p2_2)))
    (:action invariant-2734
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_not_mine-at_p3_2)))
    (:action invariant-2735
        :effect (when (and (not (K_not_obs4-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1)) (K_obs4-at_p2_1)))
    (:action invariant-2736
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs4-at_p2_1)) (K_mine-at_p1_1)))
    (:action invariant-2737
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_not_mine-at_p3_1)))
    (:action invariant-2738
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_not_mine-at_p1_2)))
    (:action invariant-2739
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_not_mine-at_p2_2)))
    (:action invariant-2740
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_not_mine-at_p1_1) (K_not_obs4-at_p2_1)) (K_not_mine-at_p3_2)))
    (:action invariant-2741
        :effect (when (and (not (K_not_obs4-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p1_1)) (K_obs4-at_p2_1)))
    (:action invariant-2742
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs5-at_p2_1)) (K_not_mine-at_p1_1)))
    (:action invariant-2743
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs5-at_p2_1)) (K_not_mine-at_p3_1)))
    (:action invariant-2744
        :effect (when (and (not (K_mine-at_p1_2)) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs5-at_p2_1)) (K_not_mine-at_p1_2)))
    (:action invariant-2745
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p3_2) (K_mine-at_p1_1) (K_not_obs5-at_p2_1)) (K_not_mine-at_p2_2)))
    (:action invariant-2746
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p1_1) (K_not_obs5-at_p2_1)) (K_not_mine-at_p3_2)))
    (:action invariant-2747
        :effect (when (and (not (K_not_obs5-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p1_2) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p1_1)) (K_obs5-at_p2_1)))
    (:action invariant-2748
        :effect (when (and (not (K_obs0-at_p2_1)) (K_obs1-at_p2_1)) (K_not_obs0-at_p2_1)))
    (:action invariant-2749
        :effect (when (and (not (K_obs1-at_p2_1)) (K_obs0-at_p2_1)) (K_not_obs1-at_p2_1)))
    (:action invariant-2750
        :effect (when (and (not (K_obs0-at_p2_1)) (K_obs2-at_p2_1)) (K_not_obs0-at_p2_1)))
    (:action invariant-2751
        :effect (when (and (not (K_obs2-at_p2_1)) (K_obs0-at_p2_1)) (K_not_obs2-at_p2_1)))
    (:action invariant-2752
        :effect (when (and (not (K_obs0-at_p2_1)) (K_obs3-at_p2_1)) (K_not_obs0-at_p2_1)))
    (:action invariant-2753
        :effect (when (and (not (K_obs3-at_p2_1)) (K_obs0-at_p2_1)) (K_not_obs3-at_p2_1)))
    (:action invariant-2754
        :effect (when (and (not (K_obs0-at_p2_1)) (K_obs4-at_p2_1)) (K_not_obs0-at_p2_1)))
    (:action invariant-2755
        :effect (when (and (not (K_obs4-at_p2_1)) (K_obs0-at_p2_1)) (K_not_obs4-at_p2_1)))
    (:action invariant-2756
        :effect (when (and (not (K_obs0-at_p2_1)) (K_obs5-at_p2_1)) (K_not_obs0-at_p2_1)))
    (:action invariant-2757
        :effect (when (and (not (K_obs5-at_p2_1)) (K_obs0-at_p2_1)) (K_not_obs5-at_p2_1)))
    (:action invariant-2759
        :effect (when (K_obs0-at_p2_1) (K_not_obs6-at_p2_1)))
    (:action invariant-2761
        :effect (when (K_obs0-at_p2_1) (K_not_obs7-at_p2_1)))
    (:action invariant-2763
        :effect (when (K_obs0-at_p2_1) (K_not_obs8-at_p2_1)))
    (:action invariant-2764
        :effect (when (and (not (K_obs1-at_p2_1)) (K_obs2-at_p2_1)) (K_not_obs1-at_p2_1)))
    (:action invariant-2765
        :effect (when (and (not (K_obs2-at_p2_1)) (K_obs1-at_p2_1)) (K_not_obs2-at_p2_1)))
    (:action invariant-2766
        :effect (when (and (not (K_obs1-at_p2_1)) (K_obs3-at_p2_1)) (K_not_obs1-at_p2_1)))
    (:action invariant-2767
        :effect (when (and (not (K_obs3-at_p2_1)) (K_obs1-at_p2_1)) (K_not_obs3-at_p2_1)))
    (:action invariant-2768
        :effect (when (and (not (K_obs1-at_p2_1)) (K_obs4-at_p2_1)) (K_not_obs1-at_p2_1)))
    (:action invariant-2769
        :effect (when (and (not (K_obs4-at_p2_1)) (K_obs1-at_p2_1)) (K_not_obs4-at_p2_1)))
    (:action invariant-2770
        :effect (when (and (not (K_obs1-at_p2_1)) (K_obs5-at_p2_1)) (K_not_obs1-at_p2_1)))
    (:action invariant-2771
        :effect (when (and (not (K_obs5-at_p2_1)) (K_obs1-at_p2_1)) (K_not_obs5-at_p2_1)))
    (:action invariant-2773
        :effect (when (K_obs1-at_p2_1) (K_not_obs6-at_p2_1)))
    (:action invariant-2775
        :effect (when (K_obs1-at_p2_1) (K_not_obs7-at_p2_1)))
    (:action invariant-2777
        :effect (when (K_obs1-at_p2_1) (K_not_obs8-at_p2_1)))
    (:action invariant-2778
        :effect (when (and (not (K_obs2-at_p2_1)) (K_obs3-at_p2_1)) (K_not_obs2-at_p2_1)))
    (:action invariant-2779
        :effect (when (and (not (K_obs3-at_p2_1)) (K_obs2-at_p2_1)) (K_not_obs3-at_p2_1)))
    (:action invariant-2780
        :effect (when (and (not (K_obs2-at_p2_1)) (K_obs4-at_p2_1)) (K_not_obs2-at_p2_1)))
    (:action invariant-2781
        :effect (when (and (not (K_obs4-at_p2_1)) (K_obs2-at_p2_1)) (K_not_obs4-at_p2_1)))
    (:action invariant-2782
        :effect (when (and (not (K_obs2-at_p2_1)) (K_obs5-at_p2_1)) (K_not_obs2-at_p2_1)))
    (:action invariant-2783
        :effect (when (and (not (K_obs5-at_p2_1)) (K_obs2-at_p2_1)) (K_not_obs5-at_p2_1)))
    (:action invariant-2785
        :effect (when (K_obs2-at_p2_1) (K_not_obs6-at_p2_1)))
    (:action invariant-2787
        :effect (when (K_obs2-at_p2_1) (K_not_obs7-at_p2_1)))
    (:action invariant-2789
        :effect (when (K_obs2-at_p2_1) (K_not_obs8-at_p2_1)))
    (:action invariant-2790
        :effect (when (and (not (K_obs3-at_p2_1)) (K_obs4-at_p2_1)) (K_not_obs3-at_p2_1)))
    (:action invariant-2791
        :effect (when (and (not (K_obs4-at_p2_1)) (K_obs3-at_p2_1)) (K_not_obs4-at_p2_1)))
    (:action invariant-2792
        :effect (when (and (not (K_obs3-at_p2_1)) (K_obs5-at_p2_1)) (K_not_obs3-at_p2_1)))
    (:action invariant-2793
        :effect (when (and (not (K_obs5-at_p2_1)) (K_obs3-at_p2_1)) (K_not_obs5-at_p2_1)))
    (:action invariant-2795
        :effect (when (K_obs3-at_p2_1) (K_not_obs6-at_p2_1)))
    (:action invariant-2797
        :effect (when (K_obs3-at_p2_1) (K_not_obs7-at_p2_1)))
    (:action invariant-2799
        :effect (when (K_obs3-at_p2_1) (K_not_obs8-at_p2_1)))
    (:action invariant-2800
        :effect (when (and (not (K_obs4-at_p2_1)) (K_obs5-at_p2_1)) (K_not_obs4-at_p2_1)))
    (:action invariant-2801
        :effect (when (and (not (K_obs5-at_p2_1)) (K_obs4-at_p2_1)) (K_not_obs5-at_p2_1)))
    (:action invariant-2803
        :effect (when (K_obs4-at_p2_1) (K_not_obs6-at_p2_1)))
    (:action invariant-2805
        :effect (when (K_obs4-at_p2_1) (K_not_obs7-at_p2_1)))
    (:action invariant-2807
        :effect (when (K_obs4-at_p2_1) (K_not_obs8-at_p2_1)))
    (:action invariant-2809
        :effect (when (K_obs5-at_p2_1) (K_not_obs6-at_p2_1)))
    (:action invariant-2811
        :effect (when (K_obs5-at_p2_1) (K_not_obs7-at_p2_1)))
    (:action invariant-2813
        :effect (when (K_obs5-at_p2_1) (K_not_obs8-at_p2_1)))
    (:action invariant-2820
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs0-at_p3_2)) (K_mine-at_p2_1)))
    (:action invariant-2821
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs0-at_p3_2)) (K_mine-at_p3_1)))
    (:action invariant-2822
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p2_3) (K_not_obs0-at_p3_2)) (K_mine-at_p2_2)))
    (:action invariant-2823
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_obs0-at_p3_2)) (K_mine-at_p2_3)))
    (:action invariant-2825
        :effect (when (and (not (K_not_obs0-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3)) (K_obs0-at_p3_2)))
    (:action invariant-2826
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs1-at_p3_2)) (K_not_mine-at_p2_1)))
    (:action invariant-2827
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs1-at_p3_2)) (K_mine-at_p3_1)))
    (:action invariant-2828
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p2_3) (K_not_obs1-at_p3_2)) (K_mine-at_p2_2)))
    (:action invariant-2829
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_obs1-at_p3_2)) (K_mine-at_p2_3)))
    (:action invariant-2831
        :effect (when (and (not (K_not_obs1-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3)) (K_obs1-at_p3_2)))
    (:action invariant-2832
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs1-at_p3_2)) (K_mine-at_p2_1)))
    (:action invariant-2833
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs1-at_p3_2)) (K_not_mine-at_p3_1)))
    (:action invariant-2834
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p2_3) (K_not_obs1-at_p3_2)) (K_mine-at_p2_2)))
    (:action invariant-2835
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_obs1-at_p3_2)) (K_mine-at_p2_3)))
    (:action invariant-2837
        :effect (when (and (not (K_not_obs1-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3)) (K_obs1-at_p3_2)))
    (:action invariant-2838
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_not_mine-at_p2_1)))
    (:action invariant-2839
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_not_mine-at_p3_1)))
    (:action invariant-2840
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_mine-at_p2_2)))
    (:action invariant-2841
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_obs2-at_p3_2)) (K_mine-at_p2_3)))
    (:action invariant-2843
        :effect (when (and (not (K_not_obs2-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3)) (K_obs2-at_p3_2)))
    (:action invariant-2844
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs1-at_p3_2)) (K_mine-at_p2_1)))
    (:action invariant-2845
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs1-at_p3_2)) (K_mine-at_p3_1)))
    (:action invariant-2846
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p2_3) (K_not_obs1-at_p3_2)) (K_not_mine-at_p2_2)))
    (:action invariant-2847
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_not_obs1-at_p3_2)) (K_mine-at_p2_3)))
    (:action invariant-2849
        :effect (when (and (not (K_not_obs1-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3)) (K_obs1-at_p3_2)))
    (:action invariant-2850
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_not_mine-at_p2_1)))
    (:action invariant-2851
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_mine-at_p3_1)))
    (:action invariant-2852
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_not_mine-at_p2_2)))
    (:action invariant-2853
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_not_obs2-at_p3_2)) (K_mine-at_p2_3)))
    (:action invariant-2855
        :effect (when (and (not (K_not_obs2-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3)) (K_obs2-at_p3_2)))
    (:action invariant-2856
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_mine-at_p2_1)))
    (:action invariant-2857
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_not_mine-at_p3_1)))
    (:action invariant-2858
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_not_mine-at_p2_2)))
    (:action invariant-2859
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_not_obs2-at_p3_2)) (K_mine-at_p2_3)))
    (:action invariant-2861
        :effect (when (and (not (K_not_obs2-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3)) (K_obs2-at_p3_2)))
    (:action invariant-2862
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs3-at_p3_2)) (K_not_mine-at_p2_1)))
    (:action invariant-2863
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs3-at_p3_2)) (K_not_mine-at_p3_1)))
    (:action invariant-2864
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p2_3) (K_not_obs3-at_p3_2)) (K_not_mine-at_p2_2)))
    (:action invariant-2865
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_not_obs3-at_p3_2)) (K_mine-at_p2_3)))
    (:action invariant-2867
        :effect (when (and (not (K_not_obs3-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3)) (K_obs3-at_p3_2)))
    (:action invariant-2868
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs1-at_p3_2)) (K_mine-at_p2_1)))
    (:action invariant-2869
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs1-at_p3_2)) (K_mine-at_p3_1)))
    (:action invariant-2870
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p2_3) (K_not_obs1-at_p3_2)) (K_mine-at_p2_2)))
    (:action invariant-2871
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_obs1-at_p3_2)) (K_not_mine-at_p2_3)))
    (:action invariant-2873
        :effect (when (and (not (K_not_obs1-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3)) (K_obs1-at_p3_2)))
    (:action invariant-2874
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_not_mine-at_p2_1)))
    (:action invariant-2875
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_mine-at_p3_1)))
    (:action invariant-2876
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_mine-at_p2_2)))
    (:action invariant-2877
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_obs2-at_p3_2)) (K_not_mine-at_p2_3)))
    (:action invariant-2879
        :effect (when (and (not (K_not_obs2-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3)) (K_obs2-at_p3_2)))
    (:action invariant-2880
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_mine-at_p2_1)))
    (:action invariant-2881
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_not_mine-at_p3_1)))
    (:action invariant-2882
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_mine-at_p2_2)))
    (:action invariant-2883
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_obs2-at_p3_2)) (K_not_mine-at_p2_3)))
    (:action invariant-2885
        :effect (when (and (not (K_not_obs2-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3)) (K_obs2-at_p3_2)))
    (:action invariant-2886
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs3-at_p3_2)) (K_not_mine-at_p2_1)))
    (:action invariant-2887
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs3-at_p3_2)) (K_not_mine-at_p3_1)))
    (:action invariant-2888
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p2_3) (K_not_obs3-at_p3_2)) (K_mine-at_p2_2)))
    (:action invariant-2889
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_obs3-at_p3_2)) (K_not_mine-at_p2_3)))
    (:action invariant-2891
        :effect (when (and (not (K_not_obs3-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3)) (K_obs3-at_p3_2)))
    (:action invariant-2892
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_mine-at_p2_1)))
    (:action invariant-2893
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_mine-at_p3_1)))
    (:action invariant-2894
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_not_mine-at_p2_2)))
    (:action invariant-2895
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_not_obs2-at_p3_2)) (K_not_mine-at_p2_3)))
    (:action invariant-2897
        :effect (when (and (not (K_not_obs2-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p2_3)) (K_obs2-at_p3_2)))
    (:action invariant-2898
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs3-at_p3_2)) (K_not_mine-at_p2_1)))
    (:action invariant-2899
        :effect (when (and (not (K_not_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs3-at_p3_2)) (K_mine-at_p3_1)))
    (:action invariant-2900
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p2_3) (K_not_obs3-at_p3_2)) (K_not_mine-at_p2_2)))
    (:action invariant-2901
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_not_obs3-at_p3_2)) (K_not_mine-at_p2_3)))
    (:action invariant-2903
        :effect (when (and (not (K_not_obs3-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p2_3)) (K_obs3-at_p3_2)))
    (:action invariant-2904
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs3-at_p3_2)) (K_mine-at_p2_1)))
    (:action invariant-2905
        :effect (when (and (not (K_mine-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs3-at_p3_2)) (K_not_mine-at_p3_1)))
    (:action invariant-2906
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p2_3) (K_not_obs3-at_p3_2)) (K_not_mine-at_p2_2)))
    (:action invariant-2907
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_not_obs3-at_p3_2)) (K_not_mine-at_p2_3)))
    (:action invariant-2909
        :effect (when (and (not (K_not_obs3-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p2_3)) (K_obs3-at_p3_2)))
    (:action invariant-2910
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs4-at_p3_2)) (K_not_mine-at_p2_1)))
    (:action invariant-2911
        :effect (when (and (not (K_mine-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs4-at_p3_2)) (K_not_mine-at_p3_1)))
    (:action invariant-2912
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p2_3) (K_not_obs4-at_p3_2)) (K_not_mine-at_p2_2)))
    (:action invariant-2913
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_not_obs4-at_p3_2)) (K_not_mine-at_p2_3)))
    (:action invariant-2915
        :effect (when (and (not (K_not_obs4-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p2_3)) (K_obs4-at_p3_2)))
    (:action invariant-2920
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs1-at_p3_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2926
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2932
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2938
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs3-at_p3_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2944
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2950
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs3-at_p3_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2956
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs3-at_p3_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2962
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_obs4-at_p3_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2968
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs2-at_p3_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2974
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs3-at_p3_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2980
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs3-at_p3_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2986
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs4-at_p3_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2992
        :effect (when (and (K_not_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs3-at_p3_2)) (K_not_mine-at_p3_3)))
    (:action invariant-2998
        :effect (when (and (K_mine-at_p2_1) (K_not_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs4-at_p3_2)) (K_not_mine-at_p3_3)))
    (:action invariant-3004
        :effect (when (and (K_not_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs4-at_p3_2)) (K_not_mine-at_p3_3)))
    (:action invariant-3010
        :effect (when (and (K_mine-at_p2_1) (K_mine-at_p3_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_obs5-at_p3_2)) (K_not_mine-at_p3_3)))
    (:action invariant-3012
        :effect (when (and (not (K_obs0-at_p3_2)) (K_obs1-at_p3_2)) (K_not_obs0-at_p3_2)))
    (:action invariant-3013
        :effect (when (and (not (K_obs1-at_p3_2)) (K_obs0-at_p3_2)) (K_not_obs1-at_p3_2)))
    (:action invariant-3014
        :effect (when (and (not (K_obs0-at_p3_2)) (K_obs2-at_p3_2)) (K_not_obs0-at_p3_2)))
    (:action invariant-3015
        :effect (when (and (not (K_obs2-at_p3_2)) (K_obs0-at_p3_2)) (K_not_obs2-at_p3_2)))
    (:action invariant-3016
        :effect (when (and (not (K_obs0-at_p3_2)) (K_obs3-at_p3_2)) (K_not_obs0-at_p3_2)))
    (:action invariant-3017
        :effect (when (and (not (K_obs3-at_p3_2)) (K_obs0-at_p3_2)) (K_not_obs3-at_p3_2)))
    (:action invariant-3018
        :effect (when (and (not (K_obs0-at_p3_2)) (K_obs4-at_p3_2)) (K_not_obs0-at_p3_2)))
    (:action invariant-3019
        :effect (when (and (not (K_obs4-at_p3_2)) (K_obs0-at_p3_2)) (K_not_obs4-at_p3_2)))
    (:action invariant-3020
        :effect (when (and (not (K_obs0-at_p3_2)) (K_obs5-at_p3_2)) (K_not_obs0-at_p3_2)))
    (:action invariant-3021
        :effect (when (and (not (K_obs5-at_p3_2)) (K_obs0-at_p3_2)) (K_not_obs5-at_p3_2)))
    (:action invariant-3023
        :effect (when (K_obs0-at_p3_2) (K_not_obs6-at_p3_2)))
    (:action invariant-3025
        :effect (when (K_obs0-at_p3_2) (K_not_obs7-at_p3_2)))
    (:action invariant-3027
        :effect (when (K_obs0-at_p3_2) (K_not_obs8-at_p3_2)))
    (:action invariant-3028
        :effect (when (and (not (K_obs1-at_p3_2)) (K_obs2-at_p3_2)) (K_not_obs1-at_p3_2)))
    (:action invariant-3029
        :effect (when (and (not (K_obs2-at_p3_2)) (K_obs1-at_p3_2)) (K_not_obs2-at_p3_2)))
    (:action invariant-3030
        :effect (when (and (not (K_obs1-at_p3_2)) (K_obs3-at_p3_2)) (K_not_obs1-at_p3_2)))
    (:action invariant-3031
        :effect (when (and (not (K_obs3-at_p3_2)) (K_obs1-at_p3_2)) (K_not_obs3-at_p3_2)))
    (:action invariant-3032
        :effect (when (and (not (K_obs1-at_p3_2)) (K_obs4-at_p3_2)) (K_not_obs1-at_p3_2)))
    (:action invariant-3033
        :effect (when (and (not (K_obs4-at_p3_2)) (K_obs1-at_p3_2)) (K_not_obs4-at_p3_2)))
    (:action invariant-3034
        :effect (when (and (not (K_obs1-at_p3_2)) (K_obs5-at_p3_2)) (K_not_obs1-at_p3_2)))
    (:action invariant-3035
        :effect (when (and (not (K_obs5-at_p3_2)) (K_obs1-at_p3_2)) (K_not_obs5-at_p3_2)))
    (:action invariant-3037
        :effect (when (K_obs1-at_p3_2) (K_not_obs6-at_p3_2)))
    (:action invariant-3039
        :effect (when (K_obs1-at_p3_2) (K_not_obs7-at_p3_2)))
    (:action invariant-3041
        :effect (when (K_obs1-at_p3_2) (K_not_obs8-at_p3_2)))
    (:action invariant-3042
        :effect (when (and (not (K_obs2-at_p3_2)) (K_obs3-at_p3_2)) (K_not_obs2-at_p3_2)))
    (:action invariant-3043
        :effect (when (and (not (K_obs3-at_p3_2)) (K_obs2-at_p3_2)) (K_not_obs3-at_p3_2)))
    (:action invariant-3044
        :effect (when (and (not (K_obs2-at_p3_2)) (K_obs4-at_p3_2)) (K_not_obs2-at_p3_2)))
    (:action invariant-3045
        :effect (when (and (not (K_obs4-at_p3_2)) (K_obs2-at_p3_2)) (K_not_obs4-at_p3_2)))
    (:action invariant-3046
        :effect (when (and (not (K_obs2-at_p3_2)) (K_obs5-at_p3_2)) (K_not_obs2-at_p3_2)))
    (:action invariant-3047
        :effect (when (and (not (K_obs5-at_p3_2)) (K_obs2-at_p3_2)) (K_not_obs5-at_p3_2)))
    (:action invariant-3049
        :effect (when (K_obs2-at_p3_2) (K_not_obs6-at_p3_2)))
    (:action invariant-3051
        :effect (when (K_obs2-at_p3_2) (K_not_obs7-at_p3_2)))
    (:action invariant-3053
        :effect (when (K_obs2-at_p3_2) (K_not_obs8-at_p3_2)))
    (:action invariant-3054
        :effect (when (and (not (K_obs3-at_p3_2)) (K_obs4-at_p3_2)) (K_not_obs3-at_p3_2)))
    (:action invariant-3055
        :effect (when (and (not (K_obs4-at_p3_2)) (K_obs3-at_p3_2)) (K_not_obs4-at_p3_2)))
    (:action invariant-3056
        :effect (when (and (not (K_obs3-at_p3_2)) (K_obs5-at_p3_2)) (K_not_obs3-at_p3_2)))
    (:action invariant-3057
        :effect (when (and (not (K_obs5-at_p3_2)) (K_obs3-at_p3_2)) (K_not_obs5-at_p3_2)))
    (:action invariant-3059
        :effect (when (K_obs3-at_p3_2) (K_not_obs6-at_p3_2)))
    (:action invariant-3061
        :effect (when (K_obs3-at_p3_2) (K_not_obs7-at_p3_2)))
    (:action invariant-3063
        :effect (when (K_obs3-at_p3_2) (K_not_obs8-at_p3_2)))
    (:action invariant-3064
        :effect (when (and (not (K_obs4-at_p3_2)) (K_obs5-at_p3_2)) (K_not_obs4-at_p3_2)))
    (:action invariant-3065
        :effect (when (and (not (K_obs5-at_p3_2)) (K_obs4-at_p3_2)) (K_not_obs5-at_p3_2)))
    (:action invariant-3067
        :effect (when (K_obs4-at_p3_2) (K_not_obs6-at_p3_2)))
    (:action invariant-3069
        :effect (when (K_obs4-at_p3_2) (K_not_obs7-at_p3_2)))
    (:action invariant-3071
        :effect (when (K_obs4-at_p3_2) (K_not_obs8-at_p3_2)))
    (:action invariant-3073
        :effect (when (K_obs5-at_p3_2) (K_not_obs6-at_p3_2)))
    (:action invariant-3075
        :effect (when (K_obs5-at_p3_2) (K_not_obs7-at_p3_2)))
    (:action invariant-3077
        :effect (when (K_obs5-at_p3_2) (K_not_obs8-at_p3_2)))
    (:action invariant-3084
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs0-at_p3_1)) (K_mine-at_p2_1)))
    (:action invariant-3085
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_2) (K_not_obs0-at_p3_1)) (K_mine-at_p2_2)))
    (:action invariant-3086
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_obs0-at_p3_1)) (K_mine-at_p3_2)))
    (:action invariant-3087
        :effect (when (and (not (K_not_obs0-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2)) (K_obs0-at_p3_1)))
    (:action invariant-3088
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs1-at_p3_1)) (K_not_mine-at_p2_1)))
    (:action invariant-3089
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_2) (K_not_obs1-at_p3_1)) (K_mine-at_p2_2)))
    (:action invariant-3090
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_obs1-at_p3_1)) (K_mine-at_p3_2)))
    (:action invariant-3091
        :effect (when (and (not (K_not_obs1-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2)) (K_obs1-at_p3_1)))
    (:action invariant-3092
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs1-at_p3_1)) (K_mine-at_p2_1)))
    (:action invariant-3093
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p3_2) (K_not_obs1-at_p3_1)) (K_not_mine-at_p2_2)))
    (:action invariant-3094
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_obs1-at_p3_1)) (K_mine-at_p3_2)))
    (:action invariant-3095
        :effect (when (and (not (K_not_obs1-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p3_2)) (K_obs1-at_p3_1)))
    (:action invariant-3096
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_obs2-at_p3_1)) (K_not_mine-at_p2_1)))
    (:action invariant-3097
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p3_2) (K_not_obs2-at_p3_1)) (K_not_mine-at_p2_2)))
    (:action invariant-3098
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_obs2-at_p3_1)) (K_mine-at_p3_2)))
    (:action invariant-3099
        :effect (when (and (not (K_not_obs2-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p3_2)) (K_obs2-at_p3_1)))
    (:action invariant-3100
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs1-at_p3_1)) (K_mine-at_p2_1)))
    (:action invariant-3101
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_2) (K_not_obs1-at_p3_1)) (K_mine-at_p2_2)))
    (:action invariant-3102
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_obs1-at_p3_1)) (K_not_mine-at_p3_2)))
    (:action invariant-3103
        :effect (when (and (not (K_not_obs1-at_p3_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p3_2)) (K_obs1-at_p3_1)))
    (:action invariant-3104
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs2-at_p3_1)) (K_not_mine-at_p2_1)))
    (:action invariant-3105
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_2) (K_not_obs2-at_p3_1)) (K_mine-at_p2_2)))
    (:action invariant-3106
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_obs2-at_p3_1)) (K_not_mine-at_p3_2)))
    (:action invariant-3107
        :effect (when (and (not (K_not_obs2-at_p3_1)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p3_2)) (K_obs2-at_p3_1)))
    (:action invariant-3108
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs2-at_p3_1)) (K_mine-at_p2_1)))
    (:action invariant-3109
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p3_2) (K_not_obs2-at_p3_1)) (K_not_mine-at_p2_2)))
    (:action invariant-3110
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_obs2-at_p3_1)) (K_not_mine-at_p3_2)))
    (:action invariant-3111
        :effect (when (and (not (K_not_obs2-at_p3_1)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p3_2)) (K_obs2-at_p3_1)))
    (:action invariant-3112
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_obs3-at_p3_1)) (K_not_mine-at_p2_1)))
    (:action invariant-3113
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p3_2) (K_not_obs3-at_p3_1)) (K_not_mine-at_p2_2)))
    (:action invariant-3114
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_obs3-at_p3_1)) (K_not_mine-at_p3_2)))
    (:action invariant-3115
        :effect (when (and (not (K_not_obs3-at_p3_1)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p3_2)) (K_obs3-at_p3_1)))
    (:action invariant-3116
        :effect (when (and (not (K_obs0-at_p3_1)) (K_obs1-at_p3_1)) (K_not_obs0-at_p3_1)))
    (:action invariant-3117
        :effect (when (and (not (K_obs1-at_p3_1)) (K_obs0-at_p3_1)) (K_not_obs1-at_p3_1)))
    (:action invariant-3118
        :effect (when (and (not (K_obs0-at_p3_1)) (K_obs2-at_p3_1)) (K_not_obs0-at_p3_1)))
    (:action invariant-3119
        :effect (when (and (not (K_obs2-at_p3_1)) (K_obs0-at_p3_1)) (K_not_obs2-at_p3_1)))
    (:action invariant-3120
        :effect (when (and (not (K_obs0-at_p3_1)) (K_obs3-at_p3_1)) (K_not_obs0-at_p3_1)))
    (:action invariant-3121
        :effect (when (and (not (K_obs3-at_p3_1)) (K_obs0-at_p3_1)) (K_not_obs3-at_p3_1)))
    (:action invariant-3123
        :effect (when (K_obs0-at_p3_1) (K_not_obs4-at_p3_1)))
    (:action invariant-3125
        :effect (when (K_obs0-at_p3_1) (K_not_obs5-at_p3_1)))
    (:action invariant-3127
        :effect (when (K_obs0-at_p3_1) (K_not_obs6-at_p3_1)))
    (:action invariant-3129
        :effect (when (K_obs0-at_p3_1) (K_not_obs7-at_p3_1)))
    (:action invariant-3131
        :effect (when (K_obs0-at_p3_1) (K_not_obs8-at_p3_1)))
    (:action invariant-3132
        :effect (when (and (not (K_obs1-at_p3_1)) (K_obs2-at_p3_1)) (K_not_obs1-at_p3_1)))
    (:action invariant-3133
        :effect (when (and (not (K_obs2-at_p3_1)) (K_obs1-at_p3_1)) (K_not_obs2-at_p3_1)))
    (:action invariant-3134
        :effect (when (and (not (K_obs1-at_p3_1)) (K_obs3-at_p3_1)) (K_not_obs1-at_p3_1)))
    (:action invariant-3135
        :effect (when (and (not (K_obs3-at_p3_1)) (K_obs1-at_p3_1)) (K_not_obs3-at_p3_1)))
    (:action invariant-3137
        :effect (when (K_obs1-at_p3_1) (K_not_obs4-at_p3_1)))
    (:action invariant-3139
        :effect (when (K_obs1-at_p3_1) (K_not_obs5-at_p3_1)))
    (:action invariant-3141
        :effect (when (K_obs1-at_p3_1) (K_not_obs6-at_p3_1)))
    (:action invariant-3143
        :effect (when (K_obs1-at_p3_1) (K_not_obs7-at_p3_1)))
    (:action invariant-3145
        :effect (when (K_obs1-at_p3_1) (K_not_obs8-at_p3_1)))
    (:action invariant-3146
        :effect (when (and (not (K_obs2-at_p3_1)) (K_obs3-at_p3_1)) (K_not_obs2-at_p3_1)))
    (:action invariant-3147
        :effect (when (and (not (K_obs3-at_p3_1)) (K_obs2-at_p3_1)) (K_not_obs3-at_p3_1)))
    (:action invariant-3149
        :effect (when (K_obs2-at_p3_1) (K_not_obs4-at_p3_1)))
    (:action invariant-3151
        :effect (when (K_obs2-at_p3_1) (K_not_obs5-at_p3_1)))
    (:action invariant-3153
        :effect (when (K_obs2-at_p3_1) (K_not_obs6-at_p3_1)))
    (:action invariant-3155
        :effect (when (K_obs2-at_p3_1) (K_not_obs7-at_p3_1)))
    (:action invariant-3157
        :effect (when (K_obs2-at_p3_1) (K_not_obs8-at_p3_1)))
    (:action invariant-3159
        :effect (when (K_obs3-at_p3_1) (K_not_obs4-at_p3_1)))
    (:action invariant-3161
        :effect (when (K_obs3-at_p3_1) (K_not_obs5-at_p3_1)))
    (:action invariant-3163
        :effect (when (K_obs3-at_p3_1) (K_not_obs6-at_p3_1)))
    (:action invariant-3165
        :effect (when (K_obs3-at_p3_1) (K_not_obs7-at_p3_1)))
    (:action invariant-3167
        :effect (when (K_obs3-at_p3_1) (K_not_obs8-at_p3_1)))
    (:action invariant-3188
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs0-at_p1_2)) (K_mine-at_p1_1)))
    (:action invariant-3189
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs0-at_p1_2)) (K_mine-at_p2_1)))
    (:action invariant-3190
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs0-at_p1_2)) (K_mine-at_p2_2)))
    (:action invariant-3191
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs0-at_p1_2)) (K_mine-at_p1_3)))
    (:action invariant-3192
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs0-at_p1_2)) (K_mine-at_p2_3)))
    (:action invariant-3193
        :effect (when (and (not (K_not_obs0-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs0-at_p1_2)))
    (:action invariant-3194
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs1-at_p1_2)) (K_not_mine-at_p1_1)))
    (:action invariant-3195
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_mine-at_p2_1)))
    (:action invariant-3196
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_mine-at_p2_2)))
    (:action invariant-3197
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_mine-at_p1_3)))
    (:action invariant-3198
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_mine-at_p2_3)))
    (:action invariant-3199
        :effect (when (and (not (K_not_obs1-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs1-at_p1_2)))
    (:action invariant-3200
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs1-at_p1_2)) (K_mine-at_p1_1)))
    (:action invariant-3201
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_not_mine-at_p2_1)))
    (:action invariant-3202
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_mine-at_p2_2)))
    (:action invariant-3203
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_mine-at_p1_3)))
    (:action invariant-3204
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_mine-at_p2_3)))
    (:action invariant-3205
        :effect (when (and (not (K_not_obs1-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs1-at_p1_2)))
    (:action invariant-3206
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p1_2)) (K_not_mine-at_p1_1)))
    (:action invariant-3207
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_not_mine-at_p2_1)))
    (:action invariant-3208
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p2_2)))
    (:action invariant-3209
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p1_3)))
    (:action invariant-3210
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p2_3)))
    (:action invariant-3211
        :effect (when (and (not (K_not_obs2-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs2-at_p1_2)))
    (:action invariant-3212
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs1-at_p1_2)) (K_mine-at_p1_1)))
    (:action invariant-3213
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_mine-at_p2_1)))
    (:action invariant-3214
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_not_mine-at_p2_2)))
    (:action invariant-3215
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_mine-at_p1_3)))
    (:action invariant-3216
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_mine-at_p2_3)))
    (:action invariant-3217
        :effect (when (and (not (K_not_obs1-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs1-at_p1_2)))
    (:action invariant-3218
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p1_2)) (K_not_mine-at_p1_1)))
    (:action invariant-3219
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p2_1)))
    (:action invariant-3220
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_not_mine-at_p2_2)))
    (:action invariant-3221
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p1_3)))
    (:action invariant-3222
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p2_3)))
    (:action invariant-3223
        :effect (when (and (not (K_not_obs2-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs2-at_p1_2)))
    (:action invariant-3224
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p1_2)) (K_mine-at_p1_1)))
    (:action invariant-3225
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_not_mine-at_p2_1)))
    (:action invariant-3226
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_not_mine-at_p2_2)))
    (:action invariant-3227
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p1_3)))
    (:action invariant-3228
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p2_3)))
    (:action invariant-3229
        :effect (when (and (not (K_not_obs2-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p1_2)))
    (:action invariant-3230
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p1_2)) (K_not_mine-at_p1_1)))
    (:action invariant-3231
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_1)))
    (:action invariant-3232
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_2)))
    (:action invariant-3233
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_mine-at_p1_3)))
    (:action invariant-3234
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_mine-at_p2_3)))
    (:action invariant-3235
        :effect (when (and (not (K_not_obs3-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p1_2)))
    (:action invariant-3236
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs1-at_p1_2)) (K_mine-at_p1_1)))
    (:action invariant-3237
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_mine-at_p2_1)))
    (:action invariant-3238
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_mine-at_p2_2)))
    (:action invariant-3239
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_not_mine-at_p1_3)))
    (:action invariant-3240
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_mine-at_p2_3)))
    (:action invariant-3241
        :effect (when (and (not (K_not_obs1-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs1-at_p1_2)))
    (:action invariant-3242
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p1_2)) (K_not_mine-at_p1_1)))
    (:action invariant-3243
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p2_1)))
    (:action invariant-3244
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p2_2)))
    (:action invariant-3245
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_not_mine-at_p1_3)))
    (:action invariant-3246
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p2_3)))
    (:action invariant-3247
        :effect (when (and (not (K_not_obs2-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs2-at_p1_2)))
    (:action invariant-3248
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p1_2)) (K_mine-at_p1_1)))
    (:action invariant-3249
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_not_mine-at_p2_1)))
    (:action invariant-3250
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p2_2)))
    (:action invariant-3251
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_not_mine-at_p1_3)))
    (:action invariant-3252
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p2_3)))
    (:action invariant-3253
        :effect (when (and (not (K_not_obs2-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p1_2)))
    (:action invariant-3254
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p1_2)) (K_not_mine-at_p1_1)))
    (:action invariant-3255
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_1)))
    (:action invariant-3256
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_mine-at_p2_2)))
    (:action invariant-3257
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p1_3)))
    (:action invariant-3258
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_mine-at_p2_3)))
    (:action invariant-3259
        :effect (when (and (not (K_not_obs3-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p1_2)))
    (:action invariant-3260
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p1_2)) (K_mine-at_p1_1)))
    (:action invariant-3261
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p2_1)))
    (:action invariant-3262
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_not_mine-at_p2_2)))
    (:action invariant-3263
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_not_mine-at_p1_3)))
    (:action invariant-3264
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p2_3)))
    (:action invariant-3265
        :effect (when (and (not (K_not_obs2-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p1_2)))
    (:action invariant-3266
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p1_2)) (K_not_mine-at_p1_1)))
    (:action invariant-3267
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_mine-at_p2_1)))
    (:action invariant-3268
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_2)))
    (:action invariant-3269
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p1_3)))
    (:action invariant-3270
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_mine-at_p2_3)))
    (:action invariant-3271
        :effect (when (and (not (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p1_2)))
    (:action invariant-3272
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs3-at_p1_2)) (K_mine-at_p1_1)))
    (:action invariant-3273
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_1)))
    (:action invariant-3274
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_2)))
    (:action invariant-3275
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p1_3)))
    (:action invariant-3276
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_mine-at_p2_3)))
    (:action invariant-3277
        :effect (when (and (not (K_not_obs3-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p1_2)))
    (:action invariant-3278
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs4-at_p1_2)) (K_not_mine-at_p1_1)))
    (:action invariant-3279
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_not_mine-at_p2_1)))
    (:action invariant-3280
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_not_mine-at_p2_2)))
    (:action invariant-3281
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_not_mine-at_p1_3)))
    (:action invariant-3282
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_mine-at_p2_3)))
    (:action invariant-3283
        :effect (when (and (not (K_not_obs4-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p1_2)))
    (:action invariant-3284
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs1-at_p1_2)) (K_mine-at_p1_1)))
    (:action invariant-3285
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_mine-at_p2_1)))
    (:action invariant-3286
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_mine-at_p2_2)))
    (:action invariant-3287
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_mine-at_p1_3)))
    (:action invariant-3288
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs1-at_p1_2)) (K_not_mine-at_p2_3)))
    (:action invariant-3289
        :effect (when (and (not (K_not_obs1-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs1-at_p1_2)))
    (:action invariant-3290
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p1_2)) (K_not_mine-at_p1_1)))
    (:action invariant-3291
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p2_1)))
    (:action invariant-3292
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p2_2)))
    (:action invariant-3293
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p1_3)))
    (:action invariant-3294
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_not_mine-at_p2_3)))
    (:action invariant-3295
        :effect (when (and (not (K_not_obs2-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs2-at_p1_2)))
    (:action invariant-3296
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p1_2)) (K_mine-at_p1_1)))
    (:action invariant-3297
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_not_mine-at_p2_1)))
    (:action invariant-3298
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p2_2)))
    (:action invariant-3299
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p1_3)))
    (:action invariant-3300
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_not_mine-at_p2_3)))
    (:action invariant-3301
        :effect (when (and (not (K_not_obs2-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p1_2)))
    (:action invariant-3302
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p1_2)) (K_not_mine-at_p1_1)))
    (:action invariant-3303
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_1)))
    (:action invariant-3304
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_mine-at_p2_2)))
    (:action invariant-3305
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_mine-at_p1_3)))
    (:action invariant-3306
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_3)))
    (:action invariant-3307
        :effect (when (and (not (K_not_obs3-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p1_2)))
    (:action invariant-3308
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p1_2)) (K_mine-at_p1_1)))
    (:action invariant-3309
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p2_1)))
    (:action invariant-3310
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_not_mine-at_p2_2)))
    (:action invariant-3311
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p1_3)))
    (:action invariant-3312
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_not_mine-at_p2_3)))
    (:action invariant-3313
        :effect (when (and (not (K_not_obs2-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p1_2)))
    (:action invariant-3314
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p1_2)) (K_not_mine-at_p1_1)))
    (:action invariant-3315
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_mine-at_p2_1)))
    (:action invariant-3316
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_2)))
    (:action invariant-3317
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_mine-at_p1_3)))
    (:action invariant-3318
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_3)))
    (:action invariant-3319
        :effect (when (and (not (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p1_2)))
    (:action invariant-3320
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p1_2)) (K_mine-at_p1_1)))
    (:action invariant-3321
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_1)))
    (:action invariant-3322
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_2)))
    (:action invariant-3323
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_mine-at_p1_3)))
    (:action invariant-3324
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_3)))
    (:action invariant-3325
        :effect (when (and (not (K_not_obs3-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p1_2)))
    (:action invariant-3326
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p1_2)) (K_not_mine-at_p1_1)))
    (:action invariant-3327
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_not_mine-at_p2_1)))
    (:action invariant-3328
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p2_1) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_not_mine-at_p2_2)))
    (:action invariant-3329
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_mine-at_p1_3)))
    (:action invariant-3330
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_not_mine-at_p2_3)))
    (:action invariant-3331
        :effect (when (and (not (K_not_obs4-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p1_2)))
    (:action invariant-3332
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p1_2)) (K_mine-at_p1_1)))
    (:action invariant-3333
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p2_1)))
    (:action invariant-3334
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_mine-at_p2_2)))
    (:action invariant-3335
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_not_mine-at_p1_3)))
    (:action invariant-3336
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs2-at_p1_2)) (K_not_mine-at_p2_3)))
    (:action invariant-3337
        :effect (when (and (not (K_not_obs2-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs2-at_p1_2)))
    (:action invariant-3338
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p1_2)) (K_not_mine-at_p1_1)))
    (:action invariant-3339
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_mine-at_p2_1)))
    (:action invariant-3340
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_mine-at_p2_2)))
    (:action invariant-3341
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p1_3)))
    (:action invariant-3342
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_3)))
    (:action invariant-3343
        :effect (when (and (not (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs3-at_p1_2)))
    (:action invariant-3344
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p1_2)) (K_mine-at_p1_1)))
    (:action invariant-3345
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_1)))
    (:action invariant-3346
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_mine-at_p2_2)))
    (:action invariant-3347
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p1_3)))
    (:action invariant-3348
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_3)))
    (:action invariant-3349
        :effect (when (and (not (K_not_obs3-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p1_2)))
    (:action invariant-3350
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p1_2)) (K_not_mine-at_p1_1)))
    (:action invariant-3351
        :effect (when (and (not (K_mine-at_p2_1)) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_not_mine-at_p2_1)))
    (:action invariant-3352
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_mine-at_p2_2)))
    (:action invariant-3353
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_not_mine-at_p1_3)))
    (:action invariant-3354
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_not_mine-at_p2_3)))
    (:action invariant-3355
        :effect (when (and (not (K_not_obs4-at_p1_2)) (K_mine-at_p2_1) (K_not_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p1_2)))
    (:action invariant-3356
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p1_2)) (K_mine-at_p1_1)))
    (:action invariant-3357
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_mine-at_p2_1)))
    (:action invariant-3358
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_2)))
    (:action invariant-3359
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p1_3)))
    (:action invariant-3360
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_3)))
    (:action invariant-3361
        :effect (when (and (not (K_not_obs3-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs3-at_p1_2)))
    (:action invariant-3362
        :effect (when (and (not (K_mine-at_p1_1)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p1_2)) (K_not_mine-at_p1_1)))
    (:action invariant-3363
        :effect (when (and (not (K_not_mine-at_p2_1)) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_mine-at_p2_1)))
    (:action invariant-3364
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p2_1) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_not_mine-at_p2_2)))
    (:action invariant-3365
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_not_mine-at_p1_3)))
    (:action invariant-3366
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_not_mine-at_p2_3)))
    (:action invariant-3367
        :effect (when (and (not (K_not_obs4-at_p1_2)) (K_not_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs4-at_p1_2)))
    (:action invariant-3368
        :effect (when (and (not (K_not_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs4-at_p1_2)) (K_mine-at_p1_1)))
    (:action invariant-3369
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_not_mine-at_p2_1)))
    (:action invariant-3370
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_not_mine-at_p2_2)))
    (:action invariant-3371
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_not_mine-at_p1_3)))
    (:action invariant-3372
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_not_mine-at_p1_1) (K_not_obs4-at_p1_2)) (K_not_mine-at_p2_3)))
    (:action invariant-3373
        :effect (when (and (not (K_not_obs4-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_1)) (K_obs4-at_p1_2)))
    (:action invariant-3374
        :effect (when (and (not (K_mine-at_p1_1)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs5-at_p1_2)) (K_not_mine-at_p1_1)))
    (:action invariant-3375
        :effect (when (and (not (K_mine-at_p2_1)) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p1_2)) (K_not_mine-at_p2_1)))
    (:action invariant-3376
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p2_1) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p1_2)) (K_not_mine-at_p2_2)))
    (:action invariant-3377
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_mine-at_p1_1) (K_not_obs5-at_p1_2)) (K_not_mine-at_p1_3)))
    (:action invariant-3378
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p1_1) (K_not_obs5-at_p1_2)) (K_not_mine-at_p2_3)))
    (:action invariant-3379
        :effect (when (and (not (K_not_obs5-at_p1_2)) (K_mine-at_p2_1) (K_mine-at_p2_2) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_1)) (K_obs5-at_p1_2)))
    (:action invariant-3380
        :effect (when (and (not (K_obs0-at_p1_2)) (K_obs1-at_p1_2)) (K_not_obs0-at_p1_2)))
    (:action invariant-3381
        :effect (when (and (not (K_obs1-at_p1_2)) (K_obs0-at_p1_2)) (K_not_obs1-at_p1_2)))
    (:action invariant-3382
        :effect (when (and (not (K_obs0-at_p1_2)) (K_obs2-at_p1_2)) (K_not_obs0-at_p1_2)))
    (:action invariant-3383
        :effect (when (and (not (K_obs2-at_p1_2)) (K_obs0-at_p1_2)) (K_not_obs2-at_p1_2)))
    (:action invariant-3384
        :effect (when (and (not (K_obs0-at_p1_2)) (K_obs3-at_p1_2)) (K_not_obs0-at_p1_2)))
    (:action invariant-3385
        :effect (when (and (not (K_obs3-at_p1_2)) (K_obs0-at_p1_2)) (K_not_obs3-at_p1_2)))
    (:action invariant-3386
        :effect (when (and (not (K_obs0-at_p1_2)) (K_obs4-at_p1_2)) (K_not_obs0-at_p1_2)))
    (:action invariant-3387
        :effect (when (and (not (K_obs4-at_p1_2)) (K_obs0-at_p1_2)) (K_not_obs4-at_p1_2)))
    (:action invariant-3388
        :effect (when (and (not (K_obs0-at_p1_2)) (K_obs5-at_p1_2)) (K_not_obs0-at_p1_2)))
    (:action invariant-3389
        :effect (when (and (not (K_obs5-at_p1_2)) (K_obs0-at_p1_2)) (K_not_obs5-at_p1_2)))
    (:action invariant-3391
        :effect (when (K_obs0-at_p1_2) (K_not_obs6-at_p1_2)))
    (:action invariant-3393
        :effect (when (K_obs0-at_p1_2) (K_not_obs7-at_p1_2)))
    (:action invariant-3395
        :effect (when (K_obs0-at_p1_2) (K_not_obs8-at_p1_2)))
    (:action invariant-3396
        :effect (when (and (not (K_obs1-at_p1_2)) (K_obs2-at_p1_2)) (K_not_obs1-at_p1_2)))
    (:action invariant-3397
        :effect (when (and (not (K_obs2-at_p1_2)) (K_obs1-at_p1_2)) (K_not_obs2-at_p1_2)))
    (:action invariant-3398
        :effect (when (and (not (K_obs1-at_p1_2)) (K_obs3-at_p1_2)) (K_not_obs1-at_p1_2)))
    (:action invariant-3399
        :effect (when (and (not (K_obs3-at_p1_2)) (K_obs1-at_p1_2)) (K_not_obs3-at_p1_2)))
    (:action invariant-3400
        :effect (when (and (not (K_obs1-at_p1_2)) (K_obs4-at_p1_2)) (K_not_obs1-at_p1_2)))
    (:action invariant-3401
        :effect (when (and (not (K_obs4-at_p1_2)) (K_obs1-at_p1_2)) (K_not_obs4-at_p1_2)))
    (:action invariant-3402
        :effect (when (and (not (K_obs1-at_p1_2)) (K_obs5-at_p1_2)) (K_not_obs1-at_p1_2)))
    (:action invariant-3403
        :effect (when (and (not (K_obs5-at_p1_2)) (K_obs1-at_p1_2)) (K_not_obs5-at_p1_2)))
    (:action invariant-3405
        :effect (when (K_obs1-at_p1_2) (K_not_obs6-at_p1_2)))
    (:action invariant-3407
        :effect (when (K_obs1-at_p1_2) (K_not_obs7-at_p1_2)))
    (:action invariant-3409
        :effect (when (K_obs1-at_p1_2) (K_not_obs8-at_p1_2)))
    (:action invariant-3410
        :effect (when (and (not (K_obs2-at_p1_2)) (K_obs3-at_p1_2)) (K_not_obs2-at_p1_2)))
    (:action invariant-3411
        :effect (when (and (not (K_obs3-at_p1_2)) (K_obs2-at_p1_2)) (K_not_obs3-at_p1_2)))
    (:action invariant-3412
        :effect (when (and (not (K_obs2-at_p1_2)) (K_obs4-at_p1_2)) (K_not_obs2-at_p1_2)))
    (:action invariant-3413
        :effect (when (and (not (K_obs4-at_p1_2)) (K_obs2-at_p1_2)) (K_not_obs4-at_p1_2)))
    (:action invariant-3414
        :effect (when (and (not (K_obs2-at_p1_2)) (K_obs5-at_p1_2)) (K_not_obs2-at_p1_2)))
    (:action invariant-3415
        :effect (when (and (not (K_obs5-at_p1_2)) (K_obs2-at_p1_2)) (K_not_obs5-at_p1_2)))
    (:action invariant-3417
        :effect (when (K_obs2-at_p1_2) (K_not_obs6-at_p1_2)))
    (:action invariant-3419
        :effect (when (K_obs2-at_p1_2) (K_not_obs7-at_p1_2)))
    (:action invariant-3421
        :effect (when (K_obs2-at_p1_2) (K_not_obs8-at_p1_2)))
    (:action invariant-3422
        :effect (when (and (not (K_obs3-at_p1_2)) (K_obs4-at_p1_2)) (K_not_obs3-at_p1_2)))
    (:action invariant-3423
        :effect (when (and (not (K_obs4-at_p1_2)) (K_obs3-at_p1_2)) (K_not_obs4-at_p1_2)))
    (:action invariant-3424
        :effect (when (and (not (K_obs3-at_p1_2)) (K_obs5-at_p1_2)) (K_not_obs3-at_p1_2)))
    (:action invariant-3425
        :effect (when (and (not (K_obs5-at_p1_2)) (K_obs3-at_p1_2)) (K_not_obs5-at_p1_2)))
    (:action invariant-3427
        :effect (when (K_obs3-at_p1_2) (K_not_obs6-at_p1_2)))
    (:action invariant-3429
        :effect (when (K_obs3-at_p1_2) (K_not_obs7-at_p1_2)))
    (:action invariant-3431
        :effect (when (K_obs3-at_p1_2) (K_not_obs8-at_p1_2)))
    (:action invariant-3432
        :effect (when (and (not (K_obs4-at_p1_2)) (K_obs5-at_p1_2)) (K_not_obs4-at_p1_2)))
    (:action invariant-3433
        :effect (when (and (not (K_obs5-at_p1_2)) (K_obs4-at_p1_2)) (K_not_obs5-at_p1_2)))
    (:action invariant-3435
        :effect (when (K_obs4-at_p1_2) (K_not_obs6-at_p1_2)))
    (:action invariant-3437
        :effect (when (K_obs4-at_p1_2) (K_not_obs7-at_p1_2)))
    (:action invariant-3439
        :effect (when (K_obs4-at_p1_2) (K_not_obs8-at_p1_2)))
    (:action invariant-3441
        :effect (when (K_obs5-at_p1_2) (K_not_obs6-at_p1_2)))
    (:action invariant-3443
        :effect (when (K_obs5-at_p1_2) (K_not_obs7-at_p1_2)))
    (:action invariant-3445
        :effect (when (K_obs5-at_p1_2) (K_not_obs8-at_p1_2)))
    (:action invariant-3452
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs0-at_p3_3)) (K_mine-at_p2_2)))
    (:action invariant-3453
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs0-at_p3_3)) (K_mine-at_p3_2)))
    (:action invariant-3454
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs0-at_p3_3)) (K_mine-at_p2_3)))
    (:action invariant-3455
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs0-at_p3_3)) (K_mine-at_p2_4)))
    (:action invariant-3456
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs0-at_p3_3)) (K_mine-at_p3_4)))
    (:action invariant-3457
        :effect (when (and (not (K_not_obs0-at_p3_3)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4)) (K_obs0-at_p3_3)))
    (:action invariant-3458
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_not_mine-at_p2_2)))
    (:action invariant-3459
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_mine-at_p3_2)))
    (:action invariant-3460
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_mine-at_p2_3)))
    (:action invariant-3461
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_mine-at_p2_4)))
    (:action invariant-3462
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs1-at_p3_3)) (K_mine-at_p3_4)))
    (:action invariant-3463
        :effect (when (and (not (K_not_obs1-at_p3_3)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4)) (K_obs1-at_p3_3)))
    (:action invariant-3464
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_mine-at_p2_2)))
    (:action invariant-3465
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_not_mine-at_p3_2)))
    (:action invariant-3466
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_mine-at_p2_3)))
    (:action invariant-3467
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_mine-at_p2_4)))
    (:action invariant-3468
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs1-at_p3_3)) (K_mine-at_p3_4)))
    (:action invariant-3469
        :effect (when (and (not (K_not_obs1-at_p3_3)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4)) (K_obs1-at_p3_3)))
    (:action invariant-3470
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p2_2)))
    (:action invariant-3471
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p3_2)))
    (:action invariant-3472
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p2_3)))
    (:action invariant-3473
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p2_4)))
    (:action invariant-3474
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs2-at_p3_3)) (K_mine-at_p3_4)))
    (:action invariant-3475
        :effect (when (and (not (K_not_obs2-at_p3_3)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4)) (K_obs2-at_p3_3)))
    (:action invariant-3476
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_mine-at_p2_2)))
    (:action invariant-3477
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_mine-at_p3_2)))
    (:action invariant-3478
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3479
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_mine-at_p2_4)))
    (:action invariant-3480
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs1-at_p3_3)) (K_mine-at_p3_4)))
    (:action invariant-3481
        :effect (when (and (not (K_not_obs1-at_p3_3)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4)) (K_obs1-at_p3_3)))
    (:action invariant-3482
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p2_2)))
    (:action invariant-3483
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p3_2)))
    (:action invariant-3484
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3485
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p2_4)))
    (:action invariant-3486
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs2-at_p3_3)) (K_mine-at_p3_4)))
    (:action invariant-3487
        :effect (when (and (not (K_not_obs2-at_p3_3)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4)) (K_obs2-at_p3_3)))
    (:action invariant-3488
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p2_2)))
    (:action invariant-3489
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p3_2)))
    (:action invariant-3490
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3491
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p2_4)))
    (:action invariant-3492
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs2-at_p3_3)) (K_mine-at_p3_4)))
    (:action invariant-3493
        :effect (when (and (not (K_not_obs2-at_p3_3)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4)) (K_obs2-at_p3_3)))
    (:action invariant-3494
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_2)))
    (:action invariant-3495
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p3_2)))
    (:action invariant-3496
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3497
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_mine-at_p2_4)))
    (:action invariant-3498
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs3-at_p3_3)) (K_mine-at_p3_4)))
    (:action invariant-3499
        :effect (when (and (not (K_not_obs3-at_p3_3)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_mine-at_p3_4)) (K_obs3-at_p3_3)))
    (:action invariant-3500
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_mine-at_p2_2)))
    (:action invariant-3501
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_mine-at_p3_2)))
    (:action invariant-3502
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_mine-at_p2_3)))
    (:action invariant-3503
        :effect (when (and (not (K_mine-at_p2_4)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_not_mine-at_p2_4)))
    (:action invariant-3504
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs1-at_p3_3)) (K_mine-at_p3_4)))
    (:action invariant-3505
        :effect (when (and (not (K_not_obs1-at_p3_3)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4)) (K_obs1-at_p3_3)))
    (:action invariant-3506
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p2_2)))
    (:action invariant-3507
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p3_2)))
    (:action invariant-3508
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p2_3)))
    (:action invariant-3509
        :effect (when (and (not (K_mine-at_p2_4)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p2_4)))
    (:action invariant-3510
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs2-at_p3_3)) (K_mine-at_p3_4)))
    (:action invariant-3511
        :effect (when (and (not (K_not_obs2-at_p3_3)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4)) (K_obs2-at_p3_3)))
    (:action invariant-3512
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p2_2)))
    (:action invariant-3513
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p3_2)))
    (:action invariant-3514
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p2_3)))
    (:action invariant-3515
        :effect (when (and (not (K_mine-at_p2_4)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p2_4)))
    (:action invariant-3516
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs2-at_p3_3)) (K_mine-at_p3_4)))
    (:action invariant-3517
        :effect (when (and (not (K_not_obs2-at_p3_3)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4)) (K_obs2-at_p3_3)))
    (:action invariant-3518
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_2)))
    (:action invariant-3519
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p3_2)))
    (:action invariant-3520
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_mine-at_p2_3)))
    (:action invariant-3521
        :effect (when (and (not (K_mine-at_p2_4)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_4)))
    (:action invariant-3522
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs3-at_p3_3)) (K_mine-at_p3_4)))
    (:action invariant-3523
        :effect (when (and (not (K_not_obs3-at_p3_3)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4)) (K_obs3-at_p3_3)))
    (:action invariant-3524
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p2_2)))
    (:action invariant-3525
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p3_2)))
    (:action invariant-3526
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3527
        :effect (when (and (not (K_mine-at_p2_4)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p2_4)))
    (:action invariant-3528
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs2-at_p3_3)) (K_mine-at_p3_4)))
    (:action invariant-3529
        :effect (when (and (not (K_not_obs2-at_p3_3)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4)) (K_obs2-at_p3_3)))
    (:action invariant-3530
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_2)))
    (:action invariant-3531
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_mine-at_p3_2)))
    (:action invariant-3532
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3533
        :effect (when (and (not (K_mine-at_p2_4)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_4)))
    (:action invariant-3534
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs3-at_p3_3)) (K_mine-at_p3_4)))
    (:action invariant-3535
        :effect (when (and (not (K_not_obs3-at_p3_3)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4)) (K_obs3-at_p3_3)))
    (:action invariant-3536
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_mine-at_p2_2)))
    (:action invariant-3537
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p3_2)))
    (:action invariant-3538
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3539
        :effect (when (and (not (K_mine-at_p2_4)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_4)))
    (:action invariant-3540
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs3-at_p3_3)) (K_mine-at_p3_4)))
    (:action invariant-3541
        :effect (when (and (not (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4)) (K_obs3-at_p3_3)))
    (:action invariant-3542
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p2_2)))
    (:action invariant-3543
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p3_2)))
    (:action invariant-3544
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_4) (K_not_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3545
        :effect (when (and (not (K_mine-at_p2_4)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p2_4)))
    (:action invariant-3546
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs4-at_p3_3)) (K_mine-at_p3_4)))
    (:action invariant-3547
        :effect (when (and (not (K_not_obs4-at_p3_3)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_mine-at_p3_4)) (K_obs4-at_p3_3)))
    (:action invariant-3548
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_mine-at_p2_2)))
    (:action invariant-3549
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_mine-at_p3_2)))
    (:action invariant-3550
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_mine-at_p2_3)))
    (:action invariant-3551
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs1-at_p3_3)) (K_mine-at_p2_4)))
    (:action invariant-3552
        :effect (when (and (not (K_mine-at_p3_4)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs1-at_p3_3)) (K_not_mine-at_p3_4)))
    (:action invariant-3553
        :effect (when (and (not (K_not_obs1-at_p3_3)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4)) (K_obs1-at_p3_3)))
    (:action invariant-3554
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p2_2)))
    (:action invariant-3555
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p3_2)))
    (:action invariant-3556
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p2_3)))
    (:action invariant-3557
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p2_4)))
    (:action invariant-3558
        :effect (when (and (not (K_mine-at_p3_4)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p3_4)))
    (:action invariant-3559
        :effect (when (and (not (K_not_obs2-at_p3_3)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4)) (K_obs2-at_p3_3)))
    (:action invariant-3560
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p2_2)))
    (:action invariant-3561
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p3_2)))
    (:action invariant-3562
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p2_3)))
    (:action invariant-3563
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p2_4)))
    (:action invariant-3564
        :effect (when (and (not (K_mine-at_p3_4)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p3_4)))
    (:action invariant-3565
        :effect (when (and (not (K_not_obs2-at_p3_3)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4)) (K_obs2-at_p3_3)))
    (:action invariant-3566
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_2)))
    (:action invariant-3567
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p3_2)))
    (:action invariant-3568
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_mine-at_p2_3)))
    (:action invariant-3569
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_mine-at_p2_4)))
    (:action invariant-3570
        :effect (when (and (not (K_mine-at_p3_4)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p3_4)))
    (:action invariant-3571
        :effect (when (and (not (K_not_obs3-at_p3_3)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4)) (K_obs3-at_p3_3)))
    (:action invariant-3572
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p2_2)))
    (:action invariant-3573
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p3_2)))
    (:action invariant-3574
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3575
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p2_4)))
    (:action invariant-3576
        :effect (when (and (not (K_mine-at_p3_4)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p3_4)))
    (:action invariant-3577
        :effect (when (and (not (K_not_obs2-at_p3_3)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4)) (K_obs2-at_p3_3)))
    (:action invariant-3578
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_2)))
    (:action invariant-3579
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_mine-at_p3_2)))
    (:action invariant-3580
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3581
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_mine-at_p2_4)))
    (:action invariant-3582
        :effect (when (and (not (K_mine-at_p3_4)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p3_4)))
    (:action invariant-3583
        :effect (when (and (not (K_not_obs3-at_p3_3)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4)) (K_obs3-at_p3_3)))
    (:action invariant-3584
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_mine-at_p2_2)))
    (:action invariant-3585
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p3_2)))
    (:action invariant-3586
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3587
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_mine-at_p2_4)))
    (:action invariant-3588
        :effect (when (and (not (K_mine-at_p3_4)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p3_4)))
    (:action invariant-3589
        :effect (when (and (not (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4)) (K_obs3-at_p3_3)))
    (:action invariant-3590
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p2_2)))
    (:action invariant-3591
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p3_2)))
    (:action invariant-3592
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3593
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_mine-at_p2_4)))
    (:action invariant-3594
        :effect (when (and (not (K_mine-at_p3_4)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p3_4)))
    (:action invariant-3595
        :effect (when (and (not (K_not_obs4-at_p3_3)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_mine-at_p3_4)) (K_obs4-at_p3_3)))
    (:action invariant-3596
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p2_2)))
    (:action invariant-3597
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p3_2)))
    (:action invariant-3598
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_mine-at_p2_3)))
    (:action invariant-3599
        :effect (when (and (not (K_mine-at_p2_4)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p2_4)))
    (:action invariant-3600
        :effect (when (and (not (K_mine-at_p3_4)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs2-at_p3_3)) (K_not_mine-at_p3_4)))
    (:action invariant-3601
        :effect (when (and (not (K_not_obs2-at_p3_3)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4)) (K_obs2-at_p3_3)))
    (:action invariant-3602
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_2)))
    (:action invariant-3603
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_mine-at_p3_2)))
    (:action invariant-3604
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_mine-at_p2_3)))
    (:action invariant-3605
        :effect (when (and (not (K_mine-at_p2_4)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_4)))
    (:action invariant-3606
        :effect (when (and (not (K_mine-at_p3_4)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p3_4)))
    (:action invariant-3607
        :effect (when (and (not (K_not_obs3-at_p3_3)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4)) (K_obs3-at_p3_3)))
    (:action invariant-3608
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_mine-at_p2_2)))
    (:action invariant-3609
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p3_2)))
    (:action invariant-3610
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_mine-at_p2_3)))
    (:action invariant-3611
        :effect (when (and (not (K_mine-at_p2_4)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_4)))
    (:action invariant-3612
        :effect (when (and (not (K_mine-at_p3_4)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p3_4)))
    (:action invariant-3613
        :effect (when (and (not (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4)) (K_obs3-at_p3_3)))
    (:action invariant-3614
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p2_2)))
    (:action invariant-3615
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p3_2)))
    (:action invariant-3616
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_mine-at_p2_3)))
    (:action invariant-3617
        :effect (when (and (not (K_mine-at_p2_4)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p2_4)))
    (:action invariant-3618
        :effect (when (and (not (K_mine-at_p3_4)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p3_4)))
    (:action invariant-3619
        :effect (when (and (not (K_not_obs4-at_p3_3)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4)) (K_obs4-at_p3_3)))
    (:action invariant-3620
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_mine-at_p2_2)))
    (:action invariant-3621
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_mine-at_p3_2)))
    (:action invariant-3622
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3623
        :effect (when (and (not (K_mine-at_p2_4)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_4)))
    (:action invariant-3624
        :effect (when (and (not (K_mine-at_p3_4)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs3-at_p3_3)) (K_not_mine-at_p3_4)))
    (:action invariant-3625
        :effect (when (and (not (K_not_obs3-at_p3_3)) (K_not_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4)) (K_obs3-at_p3_3)))
    (:action invariant-3626
        :effect (when (and (not (K_mine-at_p2_2)) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p2_2)))
    (:action invariant-3627
        :effect (when (and (not (K_not_mine-at_p3_2)) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_mine-at_p3_2)))
    (:action invariant-3628
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3629
        :effect (when (and (not (K_mine-at_p2_4)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p2_4)))
    (:action invariant-3630
        :effect (when (and (not (K_mine-at_p3_4)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p3_4)))
    (:action invariant-3631
        :effect (when (and (not (K_not_obs4-at_p3_3)) (K_mine-at_p2_2) (K_not_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4)) (K_obs4-at_p3_3)))
    (:action invariant-3632
        :effect (when (and (not (K_not_mine-at_p2_2)) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_mine-at_p2_2)))
    (:action invariant-3633
        :effect (when (and (not (K_mine-at_p3_2)) (K_not_mine-at_p2_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p3_2)))
    (:action invariant-3634
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3635
        :effect (when (and (not (K_mine-at_p2_4)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p2_4)))
    (:action invariant-3636
        :effect (when (and (not (K_mine-at_p3_4)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs4-at_p3_3)) (K_not_mine-at_p3_4)))
    (:action invariant-3637
        :effect (when (and (not (K_not_obs4-at_p3_3)) (K_not_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4)) (K_obs4-at_p3_3)))
    (:action invariant-3638
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs5-at_p3_3)) (K_not_mine-at_p2_2)))
    (:action invariant-3639
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs5-at_p3_3)) (K_not_mine-at_p3_2)))
    (:action invariant-3640
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_4) (K_mine-at_p3_4) (K_not_obs5-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3641
        :effect (when (and (not (K_mine-at_p2_4)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs5-at_p3_3)) (K_not_mine-at_p2_4)))
    (:action invariant-3642
        :effect (when (and (not (K_mine-at_p3_4)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs5-at_p3_3)) (K_not_mine-at_p3_4)))
    (:action invariant-3643
        :effect (when (and (not (K_not_obs5-at_p3_3)) (K_mine-at_p2_2) (K_mine-at_p3_2) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_mine-at_p3_4)) (K_obs5-at_p3_3)))
    (:action invariant-3644
        :effect (when (and (not (K_obs0-at_p3_3)) (K_obs1-at_p3_3)) (K_not_obs0-at_p3_3)))
    (:action invariant-3645
        :effect (when (and (not (K_obs1-at_p3_3)) (K_obs0-at_p3_3)) (K_not_obs1-at_p3_3)))
    (:action invariant-3646
        :effect (when (and (not (K_obs0-at_p3_3)) (K_obs2-at_p3_3)) (K_not_obs0-at_p3_3)))
    (:action invariant-3647
        :effect (when (and (not (K_obs2-at_p3_3)) (K_obs0-at_p3_3)) (K_not_obs2-at_p3_3)))
    (:action invariant-3648
        :effect (when (and (not (K_obs0-at_p3_3)) (K_obs3-at_p3_3)) (K_not_obs0-at_p3_3)))
    (:action invariant-3649
        :effect (when (and (not (K_obs3-at_p3_3)) (K_obs0-at_p3_3)) (K_not_obs3-at_p3_3)))
    (:action invariant-3650
        :effect (when (and (not (K_obs0-at_p3_3)) (K_obs4-at_p3_3)) (K_not_obs0-at_p3_3)))
    (:action invariant-3651
        :effect (when (and (not (K_obs4-at_p3_3)) (K_obs0-at_p3_3)) (K_not_obs4-at_p3_3)))
    (:action invariant-3652
        :effect (when (and (not (K_obs0-at_p3_3)) (K_obs5-at_p3_3)) (K_not_obs0-at_p3_3)))
    (:action invariant-3653
        :effect (when (and (not (K_obs5-at_p3_3)) (K_obs0-at_p3_3)) (K_not_obs5-at_p3_3)))
    (:action invariant-3655
        :effect (when (K_obs0-at_p3_3) (K_not_obs6-at_p3_3)))
    (:action invariant-3657
        :effect (when (K_obs0-at_p3_3) (K_not_obs7-at_p3_3)))
    (:action invariant-3659
        :effect (when (K_obs0-at_p3_3) (K_not_obs8-at_p3_3)))
    (:action invariant-3660
        :effect (when (and (not (K_obs1-at_p3_3)) (K_obs2-at_p3_3)) (K_not_obs1-at_p3_3)))
    (:action invariant-3661
        :effect (when (and (not (K_obs2-at_p3_3)) (K_obs1-at_p3_3)) (K_not_obs2-at_p3_3)))
    (:action invariant-3662
        :effect (when (and (not (K_obs1-at_p3_3)) (K_obs3-at_p3_3)) (K_not_obs1-at_p3_3)))
    (:action invariant-3663
        :effect (when (and (not (K_obs3-at_p3_3)) (K_obs1-at_p3_3)) (K_not_obs3-at_p3_3)))
    (:action invariant-3664
        :effect (when (and (not (K_obs1-at_p3_3)) (K_obs4-at_p3_3)) (K_not_obs1-at_p3_3)))
    (:action invariant-3665
        :effect (when (and (not (K_obs4-at_p3_3)) (K_obs1-at_p3_3)) (K_not_obs4-at_p3_3)))
    (:action invariant-3666
        :effect (when (and (not (K_obs1-at_p3_3)) (K_obs5-at_p3_3)) (K_not_obs1-at_p3_3)))
    (:action invariant-3667
        :effect (when (and (not (K_obs5-at_p3_3)) (K_obs1-at_p3_3)) (K_not_obs5-at_p3_3)))
    (:action invariant-3669
        :effect (when (K_obs1-at_p3_3) (K_not_obs6-at_p3_3)))
    (:action invariant-3671
        :effect (when (K_obs1-at_p3_3) (K_not_obs7-at_p3_3)))
    (:action invariant-3673
        :effect (when (K_obs1-at_p3_3) (K_not_obs8-at_p3_3)))
    (:action invariant-3674
        :effect (when (and (not (K_obs2-at_p3_3)) (K_obs3-at_p3_3)) (K_not_obs2-at_p3_3)))
    (:action invariant-3675
        :effect (when (and (not (K_obs3-at_p3_3)) (K_obs2-at_p3_3)) (K_not_obs3-at_p3_3)))
    (:action invariant-3676
        :effect (when (and (not (K_obs2-at_p3_3)) (K_obs4-at_p3_3)) (K_not_obs2-at_p3_3)))
    (:action invariant-3677
        :effect (when (and (not (K_obs4-at_p3_3)) (K_obs2-at_p3_3)) (K_not_obs4-at_p3_3)))
    (:action invariant-3678
        :effect (when (and (not (K_obs2-at_p3_3)) (K_obs5-at_p3_3)) (K_not_obs2-at_p3_3)))
    (:action invariant-3679
        :effect (when (and (not (K_obs5-at_p3_3)) (K_obs2-at_p3_3)) (K_not_obs5-at_p3_3)))
    (:action invariant-3681
        :effect (when (K_obs2-at_p3_3) (K_not_obs6-at_p3_3)))
    (:action invariant-3683
        :effect (when (K_obs2-at_p3_3) (K_not_obs7-at_p3_3)))
    (:action invariant-3685
        :effect (when (K_obs2-at_p3_3) (K_not_obs8-at_p3_3)))
    (:action invariant-3686
        :effect (when (and (not (K_obs3-at_p3_3)) (K_obs4-at_p3_3)) (K_not_obs3-at_p3_3)))
    (:action invariant-3687
        :effect (when (and (not (K_obs4-at_p3_3)) (K_obs3-at_p3_3)) (K_not_obs4-at_p3_3)))
    (:action invariant-3688
        :effect (when (and (not (K_obs3-at_p3_3)) (K_obs5-at_p3_3)) (K_not_obs3-at_p3_3)))
    (:action invariant-3689
        :effect (when (and (not (K_obs5-at_p3_3)) (K_obs3-at_p3_3)) (K_not_obs5-at_p3_3)))
    (:action invariant-3691
        :effect (when (K_obs3-at_p3_3) (K_not_obs6-at_p3_3)))
    (:action invariant-3693
        :effect (when (K_obs3-at_p3_3) (K_not_obs7-at_p3_3)))
    (:action invariant-3695
        :effect (when (K_obs3-at_p3_3) (K_not_obs8-at_p3_3)))
    (:action invariant-3696
        :effect (when (and (not (K_obs4-at_p3_3)) (K_obs5-at_p3_3)) (K_not_obs4-at_p3_3)))
    (:action invariant-3697
        :effect (when (and (not (K_obs5-at_p3_3)) (K_obs4-at_p3_3)) (K_not_obs5-at_p3_3)))
    (:action invariant-3699
        :effect (when (K_obs4-at_p3_3) (K_not_obs6-at_p3_3)))
    (:action invariant-3701
        :effect (when (K_obs4-at_p3_3) (K_not_obs7-at_p3_3)))
    (:action invariant-3703
        :effect (when (K_obs4-at_p3_3) (K_not_obs8-at_p3_3)))
    (:action invariant-3705
        :effect (when (K_obs5-at_p3_3) (K_not_obs6-at_p3_3)))
    (:action invariant-3707
        :effect (when (K_obs5-at_p3_3) (K_not_obs7-at_p3_3)))
    (:action invariant-3709
        :effect (when (K_obs5-at_p3_3) (K_not_obs8-at_p3_3)))
    (:action invariant-3716
        :effect (when (and (not (K_obs1-at_p3_3)) (K_mine-at_p2_2) (K_mine-at_p2_3)) (K_not_obs1-at_p3_3)))
    (:action invariant-3717
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_2) (K_obs1-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3718
        :effect (when (and (not (K_mine-at_p2_2)) (K_mine-at_p2_3) (K_obs1-at_p3_3)) (K_not_mine-at_p2_2)))
    (:action invariant-3719
        :effect (when (and (not (K_obs1-at_p3_3)) (K_mine-at_p3_2) (K_mine-at_p2_3)) (K_not_obs1-at_p3_3)))
    (:action invariant-3720
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p3_2) (K_obs1-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3721
        :effect (when (and (not (K_mine-at_p3_2)) (K_mine-at_p2_3) (K_obs1-at_p3_3)) (K_not_mine-at_p3_2)))
    (:action invariant-3722
        :effect (when (and (not (K_obs1-at_p3_3)) (K_mine-at_p2_3) (K_mine-at_p2_4)) (K_not_obs1-at_p3_3)))
    (:action invariant-3723
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_4) (K_obs1-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3724
        :effect (when (and (not (K_mine-at_p2_4)) (K_mine-at_p2_3) (K_obs1-at_p3_3)) (K_not_mine-at_p2_4)))
    (:action invariant-3725
        :effect (when (and (not (K_obs1-at_p3_3)) (K_mine-at_p2_3) (K_mine-at_p3_4)) (K_not_obs1-at_p3_3)))
    (:action invariant-3726
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p3_4) (K_obs1-at_p3_3)) (K_not_mine-at_p2_3)))
    (:action invariant-3727
        :effect (when (and (not (K_mine-at_p3_4)) (K_mine-at_p2_3) (K_obs1-at_p3_3)) (K_not_mine-at_p3_4)))
    (:action invariant-3728
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p2_4) (K_not_obs0-at_p3_4)) (K_mine-at_p2_3)))
    (:action invariant-3730
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_not_mine-at_p2_3) (K_not_obs0-at_p3_4)) (K_mine-at_p2_4)))
    (:action invariant-3731
        :effect (when (and (not (K_not_obs0-at_p3_4)) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4)) (K_obs0-at_p3_4)))
    (:action invariant-3732
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p2_4) (K_not_obs1-at_p3_4)) (K_not_mine-at_p2_3)))
    (:action invariant-3734
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_mine-at_p2_3) (K_not_obs1-at_p3_4)) (K_mine-at_p2_4)))
    (:action invariant-3735
        :effect (when (and (not (K_not_obs1-at_p3_4)) (K_mine-at_p2_3) (K_not_mine-at_p2_4)) (K_obs1-at_p3_4)))
    (:action invariant-3737
        :effect (when (and (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs1-at_p3_4)) (K_not_mine-at_p3_3)))
    (:action invariant-3741
        :effect (when (and (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs2-at_p3_4)) (K_not_mine-at_p3_3)))
    (:action invariant-3744
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p2_4) (K_not_obs1-at_p3_4)) (K_mine-at_p2_3)))
    (:action invariant-3746
        :effect (when (and (not (K_mine-at_p2_4)) (K_not_mine-at_p2_3) (K_not_obs1-at_p3_4)) (K_not_mine-at_p2_4)))
    (:action invariant-3747
        :effect (when (and (not (K_not_obs1-at_p3_4)) (K_not_mine-at_p2_3) (K_mine-at_p2_4)) (K_obs1-at_p3_4)))
    (:action invariant-3748
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p2_4) (K_not_obs2-at_p3_4)) (K_not_mine-at_p2_3)))
    (:action invariant-3750
        :effect (when (and (not (K_mine-at_p2_4)) (K_mine-at_p2_3) (K_not_obs2-at_p3_4)) (K_not_mine-at_p2_4)))
    (:action invariant-3751
        :effect (when (and (not (K_not_obs2-at_p3_4)) (K_mine-at_p2_3) (K_mine-at_p2_4)) (K_obs2-at_p3_4)))
    (:action invariant-3753
        :effect (when (and (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs2-at_p3_4)) (K_not_mine-at_p3_3)))
    (:action invariant-3757
        :effect (when (and (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs3-at_p3_4)) (K_not_mine-at_p3_3)))
    (:action invariant-3760
        :effect (when (and (not (K_obs0-at_p3_4)) (K_obs1-at_p3_4)) (K_not_obs0-at_p3_4)))
    (:action invariant-3761
        :effect (when (and (not (K_obs1-at_p3_4)) (K_obs0-at_p3_4)) (K_not_obs1-at_p3_4)))
    (:action invariant-3762
        :effect (when (and (not (K_obs0-at_p3_4)) (K_obs2-at_p3_4)) (K_not_obs0-at_p3_4)))
    (:action invariant-3763
        :effect (when (and (not (K_obs2-at_p3_4)) (K_obs0-at_p3_4)) (K_not_obs2-at_p3_4)))
    (:action invariant-3764
        :effect (when (and (not (K_obs0-at_p3_4)) (K_obs3-at_p3_4)) (K_not_obs0-at_p3_4)))
    (:action invariant-3765
        :effect (when (and (not (K_obs3-at_p3_4)) (K_obs0-at_p3_4)) (K_not_obs3-at_p3_4)))
    (:action invariant-3767
        :effect (when (K_obs0-at_p3_4) (K_not_obs4-at_p3_4)))
    (:action invariant-3769
        :effect (when (K_obs0-at_p3_4) (K_not_obs5-at_p3_4)))
    (:action invariant-3771
        :effect (when (K_obs0-at_p3_4) (K_not_obs6-at_p3_4)))
    (:action invariant-3773
        :effect (when (K_obs0-at_p3_4) (K_not_obs7-at_p3_4)))
    (:action invariant-3775
        :effect (when (K_obs0-at_p3_4) (K_not_obs8-at_p3_4)))
    (:action invariant-3776
        :effect (when (and (not (K_obs1-at_p3_4)) (K_obs2-at_p3_4)) (K_not_obs1-at_p3_4)))
    (:action invariant-3777
        :effect (when (and (not (K_obs2-at_p3_4)) (K_obs1-at_p3_4)) (K_not_obs2-at_p3_4)))
    (:action invariant-3778
        :effect (when (and (not (K_obs1-at_p3_4)) (K_obs3-at_p3_4)) (K_not_obs1-at_p3_4)))
    (:action invariant-3779
        :effect (when (and (not (K_obs3-at_p3_4)) (K_obs1-at_p3_4)) (K_not_obs3-at_p3_4)))
    (:action invariant-3781
        :effect (when (K_obs1-at_p3_4) (K_not_obs4-at_p3_4)))
    (:action invariant-3783
        :effect (when (K_obs1-at_p3_4) (K_not_obs5-at_p3_4)))
    (:action invariant-3785
        :effect (when (K_obs1-at_p3_4) (K_not_obs6-at_p3_4)))
    (:action invariant-3787
        :effect (when (K_obs1-at_p3_4) (K_not_obs7-at_p3_4)))
    (:action invariant-3789
        :effect (when (K_obs1-at_p3_4) (K_not_obs8-at_p3_4)))
    (:action invariant-3790
        :effect (when (and (not (K_obs2-at_p3_4)) (K_obs3-at_p3_4)) (K_not_obs2-at_p3_4)))
    (:action invariant-3791
        :effect (when (and (not (K_obs3-at_p3_4)) (K_obs2-at_p3_4)) (K_not_obs3-at_p3_4)))
    (:action invariant-3793
        :effect (when (K_obs2-at_p3_4) (K_not_obs4-at_p3_4)))
    (:action invariant-3795
        :effect (when (K_obs2-at_p3_4) (K_not_obs5-at_p3_4)))
    (:action invariant-3797
        :effect (when (K_obs2-at_p3_4) (K_not_obs6-at_p3_4)))
    (:action invariant-3799
        :effect (when (K_obs2-at_p3_4) (K_not_obs7-at_p3_4)))
    (:action invariant-3801
        :effect (when (K_obs2-at_p3_4) (K_not_obs8-at_p3_4)))
    (:action invariant-3803
        :effect (when (K_obs3-at_p3_4) (K_not_obs4-at_p3_4)))
    (:action invariant-3805
        :effect (when (K_obs3-at_p3_4) (K_not_obs5-at_p3_4)))
    (:action invariant-3807
        :effect (when (K_obs3-at_p3_4) (K_not_obs6-at_p3_4)))
    (:action invariant-3809
        :effect (when (K_obs3-at_p3_4) (K_not_obs7-at_p3_4)))
    (:action invariant-3811
        :effect (when (K_obs3-at_p3_4) (K_not_obs8-at_p3_4)))
    (:action invariant-3832
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs0-at_p2_4)) (K_mine-at_p1_3)))
    (:action invariant-3833
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p1_3) (K_not_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs0-at_p2_4)) (K_mine-at_p2_3)))
    (:action invariant-3835
        :effect (when (and (not (K_not_mine-at_p1_4)) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs0-at_p2_4)) (K_mine-at_p1_4)))
    (:action invariant-3836
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_obs0-at_p2_4)) (K_mine-at_p3_4)))
    (:action invariant-3837
        :effect (when (and (not (K_not_obs0-at_p2_4)) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_mine-at_p3_4)) (K_obs0-at_p2_4)))
    (:action invariant-3838
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p2_4)) (K_not_mine-at_p1_3)))
    (:action invariant-3839
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p1_3) (K_not_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p2_4)) (K_mine-at_p2_3)))
    (:action invariant-3841
        :effect (when (and (not (K_not_mine-at_p1_4)) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs1-at_p2_4)) (K_mine-at_p1_4)))
    (:action invariant-3842
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_obs1-at_p2_4)) (K_mine-at_p3_4)))
    (:action invariant-3843
        :effect (when (and (not (K_not_obs1-at_p2_4)) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_mine-at_p3_4)) (K_obs1-at_p2_4)))
    (:action invariant-3844
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p2_4)) (K_mine-at_p1_3)))
    (:action invariant-3845
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p1_3) (K_not_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p2_4)) (K_not_mine-at_p2_3)))
    (:action invariant-3847
        :effect (when (and (not (K_not_mine-at_p1_4)) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs1-at_p2_4)) (K_mine-at_p1_4)))
    (:action invariant-3848
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_obs1-at_p2_4)) (K_mine-at_p3_4)))
    (:action invariant-3849
        :effect (when (and (not (K_not_obs1-at_p2_4)) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_mine-at_p3_4)) (K_obs1-at_p2_4)))
    (:action invariant-3850
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_not_mine-at_p1_3)))
    (:action invariant-3851
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p1_3) (K_not_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_not_mine-at_p2_3)))
    (:action invariant-3853
        :effect (when (and (not (K_not_mine-at_p1_4)) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_mine-at_p1_4)))
    (:action invariant-3854
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_obs2-at_p2_4)) (K_mine-at_p3_4)))
    (:action invariant-3855
        :effect (when (and (not (K_not_obs2-at_p2_4)) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_mine-at_p3_4)) (K_obs2-at_p2_4)))
    (:action invariant-3858
        :effect (when (and (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p2_4)) (K_not_mine-at_p3_3)))
    (:action invariant-3864
        :effect (when (and (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_not_mine-at_p3_3)))
    (:action invariant-3870
        :effect (when (and (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_not_mine-at_p3_3)))
    (:action invariant-3876
        :effect (when (and (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs3-at_p2_4)) (K_not_mine-at_p3_3)))
    (:action invariant-3880
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_3) (K_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p2_4)) (K_mine-at_p1_3)))
    (:action invariant-3881
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p1_3) (K_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs1-at_p2_4)) (K_mine-at_p2_3)))
    (:action invariant-3883
        :effect (when (and (not (K_mine-at_p1_4)) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs1-at_p2_4)) (K_not_mine-at_p1_4)))
    (:action invariant-3884
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_4) (K_not_obs1-at_p2_4)) (K_mine-at_p3_4)))
    (:action invariant-3885
        :effect (when (and (not (K_not_obs1-at_p2_4)) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_4) (K_not_mine-at_p3_4)) (K_obs1-at_p2_4)))
    (:action invariant-3886
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_3) (K_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_not_mine-at_p1_3)))
    (:action invariant-3887
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p1_3) (K_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_mine-at_p2_3)))
    (:action invariant-3889
        :effect (when (and (not (K_mine-at_p1_4)) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_not_mine-at_p1_4)))
    (:action invariant-3890
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_4) (K_not_obs2-at_p2_4)) (K_mine-at_p3_4)))
    (:action invariant-3891
        :effect (when (and (not (K_not_obs2-at_p2_4)) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_4) (K_not_mine-at_p3_4)) (K_obs2-at_p2_4)))
    (:action invariant-3892
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_3) (K_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_mine-at_p1_3)))
    (:action invariant-3893
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p1_3) (K_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_not_mine-at_p2_3)))
    (:action invariant-3895
        :effect (when (and (not (K_mine-at_p1_4)) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_not_mine-at_p1_4)))
    (:action invariant-3896
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_4) (K_not_obs2-at_p2_4)) (K_mine-at_p3_4)))
    (:action invariant-3897
        :effect (when (and (not (K_not_obs2-at_p2_4)) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_4) (K_not_mine-at_p3_4)) (K_obs2-at_p2_4)))
    (:action invariant-3898
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_3) (K_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs3-at_p2_4)) (K_not_mine-at_p1_3)))
    (:action invariant-3899
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p1_3) (K_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs3-at_p2_4)) (K_not_mine-at_p2_3)))
    (:action invariant-3901
        :effect (when (and (not (K_mine-at_p1_4)) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p3_4) (K_not_obs3-at_p2_4)) (K_not_mine-at_p1_4)))
    (:action invariant-3902
        :effect (when (and (not (K_not_mine-at_p3_4)) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_4) (K_not_obs3-at_p2_4)) (K_mine-at_p3_4)))
    (:action invariant-3903
        :effect (when (and (not (K_not_obs3-at_p2_4)) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_4) (K_not_mine-at_p3_4)) (K_obs3-at_p2_4)))
    (:action invariant-3906
        :effect (when (and (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_not_mine-at_p3_3)))
    (:action invariant-3912
        :effect (when (and (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs3-at_p2_4)) (K_not_mine-at_p3_3)))
    (:action invariant-3918
        :effect (when (and (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs3-at_p2_4)) (K_not_mine-at_p3_3)))
    (:action invariant-3924
        :effect (when (and (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_4) (K_not_mine-at_p3_4) (K_not_obs4-at_p2_4)) (K_not_mine-at_p3_3)))
    (:action invariant-3928
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_3) (K_not_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs1-at_p2_4)) (K_mine-at_p1_3)))
    (:action invariant-3929
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p1_3) (K_not_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs1-at_p2_4)) (K_mine-at_p2_3)))
    (:action invariant-3931
        :effect (when (and (not (K_not_mine-at_p1_4)) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs1-at_p2_4)) (K_mine-at_p1_4)))
    (:action invariant-3932
        :effect (when (and (not (K_mine-at_p3_4)) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_obs1-at_p2_4)) (K_not_mine-at_p3_4)))
    (:action invariant-3933
        :effect (when (and (not (K_not_obs1-at_p2_4)) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_4) (K_mine-at_p3_4)) (K_obs1-at_p2_4)))
    (:action invariant-3934
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_3) (K_not_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_not_mine-at_p1_3)))
    (:action invariant-3935
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p1_3) (K_not_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_mine-at_p2_3)))
    (:action invariant-3937
        :effect (when (and (not (K_not_mine-at_p1_4)) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_mine-at_p1_4)))
    (:action invariant-3938
        :effect (when (and (not (K_mine-at_p3_4)) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_obs2-at_p2_4)) (K_not_mine-at_p3_4)))
    (:action invariant-3939
        :effect (when (and (not (K_not_obs2-at_p2_4)) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_4) (K_mine-at_p3_4)) (K_obs2-at_p2_4)))
    (:action invariant-3940
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_3) (K_not_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_mine-at_p1_3)))
    (:action invariant-3941
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p1_3) (K_not_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_not_mine-at_p2_3)))
    (:action invariant-3943
        :effect (when (and (not (K_not_mine-at_p1_4)) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_mine-at_p1_4)))
    (:action invariant-3944
        :effect (when (and (not (K_mine-at_p3_4)) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_obs2-at_p2_4)) (K_not_mine-at_p3_4)))
    (:action invariant-3945
        :effect (when (and (not (K_not_obs2-at_p2_4)) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_4) (K_mine-at_p3_4)) (K_obs2-at_p2_4)))
    (:action invariant-3946
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_3) (K_not_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs3-at_p2_4)) (K_not_mine-at_p1_3)))
    (:action invariant-3947
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p1_3) (K_not_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs3-at_p2_4)) (K_not_mine-at_p2_3)))
    (:action invariant-3949
        :effect (when (and (not (K_not_mine-at_p1_4)) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs3-at_p2_4)) (K_mine-at_p1_4)))
    (:action invariant-3950
        :effect (when (and (not (K_mine-at_p3_4)) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_4) (K_not_obs3-at_p2_4)) (K_not_mine-at_p3_4)))
    (:action invariant-3951
        :effect (when (and (not (K_not_obs3-at_p2_4)) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_4) (K_mine-at_p3_4)) (K_obs3-at_p2_4)))
    (:action invariant-3954
        :effect (when (and (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_not_mine-at_p3_3)))
    (:action invariant-3960
        :effect (when (and (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs3-at_p2_4)) (K_not_mine-at_p3_3)))
    (:action invariant-3966
        :effect (when (and (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs3-at_p2_4)) (K_not_mine-at_p3_3)))
    (:action invariant-3972
        :effect (when (and (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs4-at_p2_4)) (K_not_mine-at_p3_3)))
    (:action invariant-3976
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_3) (K_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_mine-at_p1_3)))
    (:action invariant-3977
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p1_3) (K_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_mine-at_p2_3)))
    (:action invariant-3979
        :effect (when (and (not (K_mine-at_p1_4)) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs2-at_p2_4)) (K_not_mine-at_p1_4)))
    (:action invariant-3980
        :effect (when (and (not (K_mine-at_p3_4)) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_4) (K_not_obs2-at_p2_4)) (K_not_mine-at_p3_4)))
    (:action invariant-3981
        :effect (when (and (not (K_not_obs2-at_p2_4)) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_4) (K_mine-at_p3_4)) (K_obs2-at_p2_4)))
    (:action invariant-3982
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_3) (K_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs3-at_p2_4)) (K_not_mine-at_p1_3)))
    (:action invariant-3983
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p1_3) (K_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs3-at_p2_4)) (K_mine-at_p2_3)))
    (:action invariant-3985
        :effect (when (and (not (K_mine-at_p1_4)) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs3-at_p2_4)) (K_not_mine-at_p1_4)))
    (:action invariant-3986
        :effect (when (and (not (K_mine-at_p3_4)) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_4) (K_not_obs3-at_p2_4)) (K_not_mine-at_p3_4)))
    (:action invariant-3987
        :effect (when (and (not (K_not_obs3-at_p2_4)) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_4) (K_mine-at_p3_4)) (K_obs3-at_p2_4)))
    (:action invariant-3988
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_3) (K_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs3-at_p2_4)) (K_mine-at_p1_3)))
    (:action invariant-3989
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p1_3) (K_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs3-at_p2_4)) (K_not_mine-at_p2_3)))
    (:action invariant-3991
        :effect (when (and (not (K_mine-at_p1_4)) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs3-at_p2_4)) (K_not_mine-at_p1_4)))
    (:action invariant-3992
        :effect (when (and (not (K_mine-at_p3_4)) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_4) (K_not_obs3-at_p2_4)) (K_not_mine-at_p3_4)))
    (:action invariant-3993
        :effect (when (and (not (K_not_obs3-at_p2_4)) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_4) (K_mine-at_p3_4)) (K_obs3-at_p2_4)))
    (:action invariant-3994
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_3) (K_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs4-at_p2_4)) (K_not_mine-at_p1_3)))
    (:action invariant-3995
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p1_3) (K_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs4-at_p2_4)) (K_not_mine-at_p2_3)))
    (:action invariant-3997
        :effect (when (and (not (K_mine-at_p1_4)) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p3_4) (K_not_obs4-at_p2_4)) (K_not_mine-at_p1_4)))
    (:action invariant-3998
        :effect (when (and (not (K_mine-at_p3_4)) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_4) (K_not_obs4-at_p2_4)) (K_not_mine-at_p3_4)))
    (:action invariant-3999
        :effect (when (and (not (K_not_obs4-at_p2_4)) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_4) (K_mine-at_p3_4)) (K_obs4-at_p2_4)))
    (:action invariant-4002
        :effect (when (and (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs3-at_p2_4)) (K_not_mine-at_p3_3)))
    (:action invariant-4008
        :effect (when (and (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs4-at_p2_4)) (K_not_mine-at_p3_3)))
    (:action invariant-4014
        :effect (when (and (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs4-at_p2_4)) (K_not_mine-at_p3_3)))
    (:action invariant-4020
        :effect (when (and (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p1_4) (K_mine-at_p3_4) (K_not_obs5-at_p2_4)) (K_not_mine-at_p3_3)))
    (:action invariant-4024
        :effect (when (and (not (K_obs0-at_p2_4)) (K_obs1-at_p2_4)) (K_not_obs0-at_p2_4)))
    (:action invariant-4025
        :effect (when (and (not (K_obs1-at_p2_4)) (K_obs0-at_p2_4)) (K_not_obs1-at_p2_4)))
    (:action invariant-4026
        :effect (when (and (not (K_obs0-at_p2_4)) (K_obs2-at_p2_4)) (K_not_obs0-at_p2_4)))
    (:action invariant-4027
        :effect (when (and (not (K_obs2-at_p2_4)) (K_obs0-at_p2_4)) (K_not_obs2-at_p2_4)))
    (:action invariant-4028
        :effect (when (and (not (K_obs0-at_p2_4)) (K_obs3-at_p2_4)) (K_not_obs0-at_p2_4)))
    (:action invariant-4029
        :effect (when (and (not (K_obs3-at_p2_4)) (K_obs0-at_p2_4)) (K_not_obs3-at_p2_4)))
    (:action invariant-4030
        :effect (when (and (not (K_obs0-at_p2_4)) (K_obs4-at_p2_4)) (K_not_obs0-at_p2_4)))
    (:action invariant-4031
        :effect (when (and (not (K_obs4-at_p2_4)) (K_obs0-at_p2_4)) (K_not_obs4-at_p2_4)))
    (:action invariant-4032
        :effect (when (and (not (K_obs0-at_p2_4)) (K_obs5-at_p2_4)) (K_not_obs0-at_p2_4)))
    (:action invariant-4033
        :effect (when (and (not (K_obs5-at_p2_4)) (K_obs0-at_p2_4)) (K_not_obs5-at_p2_4)))
    (:action invariant-4035
        :effect (when (K_obs0-at_p2_4) (K_not_obs6-at_p2_4)))
    (:action invariant-4037
        :effect (when (K_obs0-at_p2_4) (K_not_obs7-at_p2_4)))
    (:action invariant-4039
        :effect (when (K_obs0-at_p2_4) (K_not_obs8-at_p2_4)))
    (:action invariant-4040
        :effect (when (and (not (K_obs1-at_p2_4)) (K_obs2-at_p2_4)) (K_not_obs1-at_p2_4)))
    (:action invariant-4041
        :effect (when (and (not (K_obs2-at_p2_4)) (K_obs1-at_p2_4)) (K_not_obs2-at_p2_4)))
    (:action invariant-4042
        :effect (when (and (not (K_obs1-at_p2_4)) (K_obs3-at_p2_4)) (K_not_obs1-at_p2_4)))
    (:action invariant-4043
        :effect (when (and (not (K_obs3-at_p2_4)) (K_obs1-at_p2_4)) (K_not_obs3-at_p2_4)))
    (:action invariant-4044
        :effect (when (and (not (K_obs1-at_p2_4)) (K_obs4-at_p2_4)) (K_not_obs1-at_p2_4)))
    (:action invariant-4045
        :effect (when (and (not (K_obs4-at_p2_4)) (K_obs1-at_p2_4)) (K_not_obs4-at_p2_4)))
    (:action invariant-4046
        :effect (when (and (not (K_obs1-at_p2_4)) (K_obs5-at_p2_4)) (K_not_obs1-at_p2_4)))
    (:action invariant-4047
        :effect (when (and (not (K_obs5-at_p2_4)) (K_obs1-at_p2_4)) (K_not_obs5-at_p2_4)))
    (:action invariant-4049
        :effect (when (K_obs1-at_p2_4) (K_not_obs6-at_p2_4)))
    (:action invariant-4051
        :effect (when (K_obs1-at_p2_4) (K_not_obs7-at_p2_4)))
    (:action invariant-4053
        :effect (when (K_obs1-at_p2_4) (K_not_obs8-at_p2_4)))
    (:action invariant-4054
        :effect (when (and (not (K_obs2-at_p2_4)) (K_obs3-at_p2_4)) (K_not_obs2-at_p2_4)))
    (:action invariant-4055
        :effect (when (and (not (K_obs3-at_p2_4)) (K_obs2-at_p2_4)) (K_not_obs3-at_p2_4)))
    (:action invariant-4056
        :effect (when (and (not (K_obs2-at_p2_4)) (K_obs4-at_p2_4)) (K_not_obs2-at_p2_4)))
    (:action invariant-4057
        :effect (when (and (not (K_obs4-at_p2_4)) (K_obs2-at_p2_4)) (K_not_obs4-at_p2_4)))
    (:action invariant-4058
        :effect (when (and (not (K_obs2-at_p2_4)) (K_obs5-at_p2_4)) (K_not_obs2-at_p2_4)))
    (:action invariant-4059
        :effect (when (and (not (K_obs5-at_p2_4)) (K_obs2-at_p2_4)) (K_not_obs5-at_p2_4)))
    (:action invariant-4061
        :effect (when (K_obs2-at_p2_4) (K_not_obs6-at_p2_4)))
    (:action invariant-4063
        :effect (when (K_obs2-at_p2_4) (K_not_obs7-at_p2_4)))
    (:action invariant-4065
        :effect (when (K_obs2-at_p2_4) (K_not_obs8-at_p2_4)))
    (:action invariant-4066
        :effect (when (and (not (K_obs3-at_p2_4)) (K_obs4-at_p2_4)) (K_not_obs3-at_p2_4)))
    (:action invariant-4067
        :effect (when (and (not (K_obs4-at_p2_4)) (K_obs3-at_p2_4)) (K_not_obs4-at_p2_4)))
    (:action invariant-4068
        :effect (when (and (not (K_obs3-at_p2_4)) (K_obs5-at_p2_4)) (K_not_obs3-at_p2_4)))
    (:action invariant-4069
        :effect (when (and (not (K_obs5-at_p2_4)) (K_obs3-at_p2_4)) (K_not_obs5-at_p2_4)))
    (:action invariant-4071
        :effect (when (K_obs3-at_p2_4) (K_not_obs6-at_p2_4)))
    (:action invariant-4073
        :effect (when (K_obs3-at_p2_4) (K_not_obs7-at_p2_4)))
    (:action invariant-4075
        :effect (when (K_obs3-at_p2_4) (K_not_obs8-at_p2_4)))
    (:action invariant-4076
        :effect (when (and (not (K_obs4-at_p2_4)) (K_obs5-at_p2_4)) (K_not_obs4-at_p2_4)))
    (:action invariant-4077
        :effect (when (and (not (K_obs5-at_p2_4)) (K_obs4-at_p2_4)) (K_not_obs5-at_p2_4)))
    (:action invariant-4079
        :effect (when (K_obs4-at_p2_4) (K_not_obs6-at_p2_4)))
    (:action invariant-4081
        :effect (when (K_obs4-at_p2_4) (K_not_obs7-at_p2_4)))
    (:action invariant-4083
        :effect (when (K_obs4-at_p2_4) (K_not_obs8-at_p2_4)))
    (:action invariant-4085
        :effect (when (K_obs5-at_p2_4) (K_not_obs6-at_p2_4)))
    (:action invariant-4087
        :effect (when (K_obs5-at_p2_4) (K_not_obs7-at_p2_4)))
    (:action invariant-4089
        :effect (when (K_obs5-at_p2_4) (K_not_obs8-at_p2_4)))
    (:action invariant-4096
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs0-at_p1_4)) (K_mine-at_p1_3)))
    (:action invariant-4097
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p1_3) (K_not_mine-at_p2_4) (K_not_obs0-at_p1_4)) (K_mine-at_p2_3)))
    (:action invariant-4098
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs0-at_p1_4)) (K_mine-at_p2_4)))
    (:action invariant-4099
        :effect (when (and (not (K_not_obs0-at_p1_4)) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4)) (K_obs0-at_p1_4)))
    (:action invariant-4100
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs1-at_p1_4)) (K_not_mine-at_p1_3)))
    (:action invariant-4101
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p1_3) (K_not_mine-at_p2_4) (K_not_obs1-at_p1_4)) (K_mine-at_p2_3)))
    (:action invariant-4102
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs1-at_p1_4)) (K_mine-at_p2_4)))
    (:action invariant-4103
        :effect (when (and (not (K_not_obs1-at_p1_4)) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_mine-at_p2_4)) (K_obs1-at_p1_4)))
    (:action invariant-4104
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs1-at_p1_4)) (K_mine-at_p1_3)))
    (:action invariant-4105
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p1_3) (K_not_mine-at_p2_4) (K_not_obs1-at_p1_4)) (K_not_mine-at_p2_3)))
    (:action invariant-4106
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs1-at_p1_4)) (K_mine-at_p2_4)))
    (:action invariant-4107
        :effect (when (and (not (K_not_obs1-at_p1_4)) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p2_4)) (K_obs1-at_p1_4)))
    (:action invariant-4108
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_3) (K_not_mine-at_p2_4) (K_not_obs2-at_p1_4)) (K_not_mine-at_p1_3)))
    (:action invariant-4109
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p1_3) (K_not_mine-at_p2_4) (K_not_obs2-at_p1_4)) (K_not_mine-at_p2_3)))
    (:action invariant-4110
        :effect (when (and (not (K_not_mine-at_p2_4)) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p1_4)) (K_mine-at_p2_4)))
    (:action invariant-4111
        :effect (when (and (not (K_not_obs2-at_p1_4)) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_mine-at_p2_4)) (K_obs2-at_p1_4)))
    (:action invariant-4112
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs1-at_p1_4)) (K_mine-at_p1_3)))
    (:action invariant-4113
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_not_mine-at_p1_3) (K_mine-at_p2_4) (K_not_obs1-at_p1_4)) (K_mine-at_p2_3)))
    (:action invariant-4114
        :effect (when (and (not (K_mine-at_p2_4)) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs1-at_p1_4)) (K_not_mine-at_p2_4)))
    (:action invariant-4115
        :effect (when (and (not (K_not_obs1-at_p1_4)) (K_not_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p2_4)) (K_obs1-at_p1_4)))
    (:action invariant-4116
        :effect (when (and (not (K_mine-at_p1_3)) (K_not_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs2-at_p1_4)) (K_not_mine-at_p1_3)))
    (:action invariant-4117
        :effect (when (and (not (K_not_mine-at_p2_3)) (K_mine-at_p1_3) (K_mine-at_p2_4) (K_not_obs2-at_p1_4)) (K_mine-at_p2_3)))
    (:action invariant-4118
        :effect (when (and (not (K_mine-at_p2_4)) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_not_obs2-at_p1_4)) (K_not_mine-at_p2_4)))
    (:action invariant-4119
        :effect (when (and (not (K_not_obs2-at_p1_4)) (K_mine-at_p1_3) (K_not_mine-at_p2_3) (K_mine-at_p2_4)) (K_obs2-at_p1_4)))
    (:action invariant-4120
        :effect (when (and (not (K_not_mine-at_p1_3)) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs2-at_p1_4)) (K_mine-at_p1_3)))
    (:action invariant-4121
        :effect (when (and (not (K_mine-at_p2_3)) (K_not_mine-at_p1_3) (K_mine-at_p2_4) (K_not_obs2-at_p1_4)) (K_not_mine-at_p2_3)))
    (:action invariant-4122
        :effect (when (and (not (K_mine-at_p2_4)) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs2-at_p1_4)) (K_not_mine-at_p2_4)))
    (:action invariant-4123
        :effect (when (and (not (K_not_obs2-at_p1_4)) (K_not_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p2_4)) (K_obs2-at_p1_4)))
    (:action invariant-4124
        :effect (when (and (not (K_mine-at_p1_3)) (K_mine-at_p2_3) (K_mine-at_p2_4) (K_not_obs3-at_p1_4)) (K_not_mine-at_p1_3)))
    (:action invariant-4125
        :effect (when (and (not (K_mine-at_p2_3)) (K_mine-at_p1_3) (K_mine-at_p2_4) (K_not_obs3-at_p1_4)) (K_not_mine-at_p2_3)))
    (:action invariant-4126
        :effect (when (and (not (K_mine-at_p2_4)) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_not_obs3-at_p1_4)) (K_not_mine-at_p2_4)))
    (:action invariant-4127
        :effect (when (and (not (K_not_obs3-at_p1_4)) (K_mine-at_p1_3) (K_mine-at_p2_3) (K_mine-at_p2_4)) (K_obs3-at_p1_4)))
    (:action invariant-4128
        :effect (when (and (not (K_obs0-at_p1_4)) (K_obs1-at_p1_4)) (K_not_obs0-at_p1_4)))
    (:action invariant-4129
        :effect (when (and (not (K_obs1-at_p1_4)) (K_obs0-at_p1_4)) (K_not_obs1-at_p1_4)))
    (:action invariant-4130
        :effect (when (and (not (K_obs0-at_p1_4)) (K_obs2-at_p1_4)) (K_not_obs0-at_p1_4)))
    (:action invariant-4131
        :effect (when (and (not (K_obs2-at_p1_4)) (K_obs0-at_p1_4)) (K_not_obs2-at_p1_4)))
    (:action invariant-4132
        :effect (when (and (not (K_obs0-at_p1_4)) (K_obs3-at_p1_4)) (K_not_obs0-at_p1_4)))
    (:action invariant-4133
        :effect (when (and (not (K_obs3-at_p1_4)) (K_obs0-at_p1_4)) (K_not_obs3-at_p1_4)))
    (:action invariant-4135
        :effect (when (K_obs0-at_p1_4) (K_not_obs4-at_p1_4)))
    (:action invariant-4137
        :effect (when (K_obs0-at_p1_4) (K_not_obs5-at_p1_4)))
    (:action invariant-4139
        :effect (when (K_obs0-at_p1_4) (K_not_obs6-at_p1_4)))
    (:action invariant-4141
        :effect (when (K_obs0-at_p1_4) (K_not_obs7-at_p1_4)))
    (:action invariant-4143
        :effect (when (K_obs0-at_p1_4) (K_not_obs8-at_p1_4)))
    (:action invariant-4144
        :effect (when (and (not (K_obs1-at_p1_4)) (K_obs2-at_p1_4)) (K_not_obs1-at_p1_4)))
    (:action invariant-4145
        :effect (when (and (not (K_obs2-at_p1_4)) (K_obs1-at_p1_4)) (K_not_obs2-at_p1_4)))
    (:action invariant-4146
        :effect (when (and (not (K_obs1-at_p1_4)) (K_obs3-at_p1_4)) (K_not_obs1-at_p1_4)))
    (:action invariant-4147
        :effect (when (and (not (K_obs3-at_p1_4)) (K_obs1-at_p1_4)) (K_not_obs3-at_p1_4)))
    (:action invariant-4149
        :effect (when (K_obs1-at_p1_4) (K_not_obs4-at_p1_4)))
    (:action invariant-4151
        :effect (when (K_obs1-at_p1_4) (K_not_obs5-at_p1_4)))
    (:action invariant-4153
        :effect (when (K_obs1-at_p1_4) (K_not_obs6-at_p1_4)))
    (:action invariant-4155
        :effect (when (K_obs1-at_p1_4) (K_not_obs7-at_p1_4)))
    (:action invariant-4157
        :effect (when (K_obs1-at_p1_4) (K_not_obs8-at_p1_4)))
    (:action invariant-4158
        :effect (when (and (not (K_obs2-at_p1_4)) (K_obs3-at_p1_4)) (K_not_obs2-at_p1_4)))
    (:action invariant-4159
        :effect (when (and (not (K_obs3-at_p1_4)) (K_obs2-at_p1_4)) (K_not_obs3-at_p1_4)))
    (:action invariant-4161
        :effect (when (K_obs2-at_p1_4) (K_not_obs4-at_p1_4)))
    (:action invariant-4163
        :effect (when (K_obs2-at_p1_4) (K_not_obs5-at_p1_4)))
    (:action invariant-4165
        :effect (when (K_obs2-at_p1_4) (K_not_obs6-at_p1_4)))
    (:action invariant-4167
        :effect (when (K_obs2-at_p1_4) (K_not_obs7-at_p1_4)))
    (:action invariant-4169
        :effect (when (K_obs2-at_p1_4) (K_not_obs8-at_p1_4)))
    (:action invariant-4171
        :effect (when (K_obs3-at_p1_4) (K_not_obs4-at_p1_4)))
    (:action invariant-4173
        :effect (when (K_obs3-at_p1_4) (K_not_obs5-at_p1_4)))
    (:action invariant-4175
        :effect (when (K_obs3-at_p1_4) (K_not_obs6-at_p1_4)))
    (:action invariant-4177
        :effect (when (K_obs3-at_p1_4) (K_not_obs7-at_p1_4)))
    (:action invariant-4179
        :effect (when (K_obs3-at_p1_4) (K_not_obs8-at_p1_4)))
    (:action reach_new_goal_through_original_goal__
        :precondition (and (K_normal-execution) (K_done-with_p1_1) (K_done-with_p2_1) (K_done-with_p3_1) (K_done-with_p1_2) (K_done-with_p2_2) (K_done-with_p3_2) (K_done-with_p1_3) (K_done-with_p2_3) (K_done-with_p3_3) (K_done-with_p1_4) (K_done-with_p2_4) (K_done-with_p3_4))
        :effect (new-goal))
)
