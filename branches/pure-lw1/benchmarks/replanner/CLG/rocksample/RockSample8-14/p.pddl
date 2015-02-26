(define (problem RockSample8-14)
    (:domain RockSample8-14)
    (:init
        (adj p1-1 p1-2) (adj p1-2 p1-1)
        (adj p1-1 p2-1) (adj p2-1 p1-1)
        (adj p1-2 p1-3) (adj p1-3 p1-2)
        (adj p1-2 p2-2) (adj p2-2 p1-2)
        (adj p1-3 p1-4) (adj p1-4 p1-3)
        (adj p1-3 p2-3) (adj p2-3 p1-3)
        (adj p1-4 p1-5) (adj p1-5 p1-4)
        (adj p1-4 p2-4) (adj p2-4 p1-4)
        (adj p1-5 p1-6) (adj p1-6 p1-5)
        (adj p1-5 p2-5) (adj p2-5 p1-5)
        (adj p1-6 p1-7) (adj p1-7 p1-6)
        (adj p1-6 p2-6) (adj p2-6 p1-6)
        (adj p1-7 p1-8) (adj p1-8 p1-7)
        (adj p1-7 p2-7) (adj p2-7 p1-7)
        (adj p1-8 p2-8) (adj p2-8 p1-8)

        (adj p2-1 p2-2) (adj p2-2 p2-1)
        (adj p2-1 p3-1) (adj p3-1 p2-1)
        (adj p2-2 p2-3) (adj p2-3 p2-2)
        (adj p2-2 p3-2) (adj p3-2 p2-2)
        (adj p2-3 p2-4) (adj p2-4 p2-3)
        (adj p2-3 p3-3) (adj p3-3 p2-3)
        (adj p2-4 p2-5) (adj p2-5 p2-4)
        (adj p2-4 p3-4) (adj p3-4 p2-4)
        (adj p2-5 p2-6) (adj p2-6 p2-5)
        (adj p2-5 p3-5) (adj p3-5 p2-5)
        (adj p2-6 p2-7) (adj p2-7 p2-6)
        (adj p2-6 p3-6) (adj p3-6 p2-6)
        (adj p2-7 p2-8) (adj p2-8 p2-7)
        (adj p2-7 p3-7) (adj p3-7 p2-7)
        (adj p2-8 p3-8) (adj p3-8 p2-8)

        (adj p3-1 p3-2) (adj p3-2 p3-1)
        (adj p3-1 p4-1) (adj p4-1 p3-1)
        (adj p3-2 p3-3) (adj p3-3 p3-2)
        (adj p3-2 p4-2) (adj p4-2 p3-2)
        (adj p3-3 p3-4) (adj p3-4 p3-3)
        (adj p3-3 p4-3) (adj p4-3 p3-3)
        (adj p3-4 p3-5) (adj p3-5 p3-4)
        (adj p3-4 p4-4) (adj p4-4 p3-4)
        (adj p3-5 p3-6) (adj p3-6 p3-5)
        (adj p3-5 p4-5) (adj p4-5 p3-5)
        (adj p3-6 p3-7) (adj p3-7 p3-6)
        (adj p3-6 p4-6) (adj p4-6 p3-6)
        (adj p3-7 p3-8) (adj p3-8 p3-7)
        (adj p3-7 p4-7) (adj p4-7 p3-7)
        (adj p3-8 p4-8) (adj p4-8 p3-8)

        (adj p4-1 p4-2) (adj p4-2 p4-1)
        (adj p4-1 p5-1) (adj p5-1 p4-1)
        (adj p4-2 p4-3) (adj p4-3 p4-2)
        (adj p4-2 p5-2) (adj p5-2 p4-2)
        (adj p4-3 p4-4) (adj p4-4 p4-3)
        (adj p4-3 p5-3) (adj p5-3 p4-3)
        (adj p4-4 p4-5) (adj p4-5 p4-4)
        (adj p4-4 p5-4) (adj p5-4 p4-4)
        (adj p4-5 p4-6) (adj p4-6 p4-5)
        (adj p4-5 p5-5) (adj p5-5 p4-5)
        (adj p4-6 p4-7) (adj p4-7 p4-6)
        (adj p4-6 p5-6) (adj p5-6 p4-6)
        (adj p4-7 p4-8) (adj p4-8 p4-7)
        (adj p4-7 p5-7) (adj p5-7 p4-7)
        (adj p4-8 p5-8) (adj p5-8 p4-8)

        (adj p5-1 p5-2) (adj p5-2 p5-1)
        (adj p5-1 p6-1) (adj p6-1 p5-1)
        (adj p5-2 p5-3) (adj p5-3 p5-2)
        (adj p5-2 p6-2) (adj p6-2 p5-2)
        (adj p5-3 p5-4) (adj p5-4 p5-3)
        (adj p5-3 p6-3) (adj p6-3 p5-3)
        (adj p5-4 p5-5) (adj p5-5 p5-4)
        (adj p5-4 p6-4) (adj p6-4 p5-4)
        (adj p5-5 p5-6) (adj p5-6 p5-5)
        (adj p5-5 p6-5) (adj p6-5 p5-5)
        (adj p5-6 p5-7) (adj p5-7 p5-6)
        (adj p5-6 p6-6) (adj p6-6 p5-6)
        (adj p5-7 p5-8) (adj p5-8 p5-7)
        (adj p5-7 p6-7) (adj p6-7 p5-7)
        (adj p5-8 p6-8) (adj p6-8 p5-8)

        (adj p6-1 p6-2) (adj p6-2 p6-1)
        (adj p6-1 p7-1) (adj p7-1 p6-1)
        (adj p6-2 p6-3) (adj p6-3 p6-2)
        (adj p6-2 p7-2) (adj p7-2 p6-2)
        (adj p6-3 p6-4) (adj p6-4 p6-3)
        (adj p6-3 p7-3) (adj p7-3 p6-3)
        (adj p6-4 p6-5) (adj p6-5 p6-4)
        (adj p6-4 p7-4) (adj p7-4 p6-4)
        (adj p6-5 p6-6) (adj p6-6 p6-5)
        (adj p6-5 p7-5) (adj p7-5 p6-5)
        (adj p6-6 p6-7) (adj p6-7 p6-6)
        (adj p6-6 p7-6) (adj p7-6 p6-6)
        (adj p6-7 p6-8) (adj p6-8 p6-7)
        (adj p6-7 p7-7) (adj p7-7 p6-7)
        (adj p6-8 p7-8) (adj p7-8 p6-8)

        (adj p7-1 p7-2) (adj p7-2 p7-1)
        (adj p7-1 p8-1) (adj p8-1 p7-1)
        (adj p7-2 p7-3) (adj p7-3 p7-2)
        (adj p7-2 p8-2) (adj p8-2 p7-2)
        (adj p7-3 p7-4) (adj p7-4 p7-3)
        (adj p7-3 p8-3) (adj p8-3 p7-3)
        (adj p7-4 p7-5) (adj p7-5 p7-4)
        (adj p7-4 p8-4) (adj p8-4 p7-4)
        (adj p7-5 p7-6) (adj p7-6 p7-5)
        (adj p7-5 p8-5) (adj p8-5 p7-5)
        (adj p7-6 p7-7) (adj p7-7 p7-6)
        (adj p7-6 p8-6) (adj p8-6 p7-6)
        (adj p7-7 p7-8) (adj p7-8 p7-7)
        (adj p7-7 p8-7) (adj p8-7 p7-7)
        (adj p7-8 p8-8) (adj p8-8 p7-8)

        (adj p8-1 p8-2) (adj p8-2 p8-1)
        (adj p8-2 p8-3) (adj p8-3 p8-2)
        (adj p8-3 p8-4) (adj p8-4 p8-3)
        (adj p8-4 p8-5) (adj p8-5 p8-4)
        (adj p8-5 p8-6) (adj p8-6 p8-5)
        (adj p8-6 p8-7) (adj p8-7 p8-6)
        (adj p8-7 p8-8) (adj p8-8 p8-7)

        (agent-at p5-5)
        (antena-height h0)

        (rock-at r0 p7-4)
        (oneof (good r0) (not (good r0)))
        (rock-at r1 p2-8)
        (oneof (good r1) (not (good r1)))
        (rock-at r2 p1-3)
        (oneof (good r2) (not (good r2)))
        (rock-at r3 p2-1)
        (oneof (good r3) (not (good r3)))
        (rock-at r4 p7-1)
        (oneof (good r4) (not (good r4)))
        (rock-at r5 p1-5)
        (oneof (good r5) (not (good r5)))
        (rock-at r6 p4-3)
        (oneof (good r6) (not (good r6)))
        (rock-at r7 p6-2)
        (oneof (good r7) (not (good r7)))
        (rock-at r8 p6-1)
        (oneof (good r8) (not (good r8)))
        (rock-at r9 p3-6)
        (oneof (good r9) (not (good r9)))
        (rock-at r10 p8-7)
        (oneof (good r10) (not (good r10)))
        (rock-at r11 p6-8)
        (oneof (good r11) (not (good r11)))
        (rock-at r12 p1-6)
        (oneof (good r12) (not (good r12)))
        (rock-at r13 p8-8)
        (oneof (good r13) (not (good r13)))
    )
    (:goal (and (not (good r0)) (not (good r1)) (not (good r2)) (not (good r3)) (not (good r4)) (not (good r5)) (not (good r6)) (not (good r7)) (not (good r8)) (not (good r9)) (not (good r10)) (not (good r11)) (not (good r12)) (not (good r13))))
)

