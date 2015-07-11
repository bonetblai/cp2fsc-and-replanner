(define (problem h8x8)
    ; minefield: 0 0 0 0 0 0 0 0 0 1 2 2 1 0 0 0 0 1 * * 2 1 0 0 1 2 3 3 * 1 0 0 1 * 2 2 1 1 1 1 1 2 * 3 2 1 1 * 1 2 2 * * 1 2 2 * 1 1 2 2 1 1 *
    (:hidden (first-move p1-1) (mine-at p3-3) (mine-at p4-3) (mine-at p5-4) (mine-at p2-5) (mine-at p3-6) (mine-at p8-6) (mine-at p4-7) (mine-at p5-7) (mine-at p1-8) (mine-at p8-8))
    ; minefield: 0 1 * 3 * 2 0 0 0 1 1 3 * 2 0 0 1 1 1 1 1 1 1 1 2 * 2 0 0 0 1 * 2 * 2 0 0 0 1 1 1 1 2 1 1 1 1 1 0 0 2 * 3 2 * 1 0 0 2 * 3 * 2 1
    (:hidden (first-move p7-2) (mine-at p3-1) (mine-at p5-1) (mine-at p5-2) (mine-at p2-4) (mine-at p8-4) (mine-at p2-5) (mine-at p4-7) (mine-at p7-7) (mine-at p4-8) (mine-at p6-8))
    ; minefield: * 1 1 1 1 1 1 1 1 1 1 * 2 2 * 1 0 0 1 2 * 2 1 1 0 0 0 2 3 3 1 0 1 1 1 1 * * 1 0 2 * 2 1 3 3 2 0 2 * 3 1 2 * 1 0 1 1 2 * 2 1 1 0
    (:hidden (first-move p2-3) (mine-at p1-1) (mine-at p4-2) (mine-at p7-2) (mine-at p5-3) (mine-at p5-5) (mine-at p6-5) (mine-at p2-6) (mine-at p2-7) (mine-at p6-7) (mine-at p4-8))
    ; minefield: 0 1 * * 1 1 1 1 0 1 2 2 1 1 * 1 1 1 1 0 0 1 1 1 1 * 1 0 1 1 2 1 2 2 2 0 1 * 3 * 2 * 2 0 1 1 3 * 2 * 2 0 0 1 2 2 1 1 1 0 0 1 * 1
    (:hidden (first-move p5-3) (mine-at p3-1) (mine-at p4-1) (mine-at p7-2) (mine-at p2-4) (mine-at p6-5) (mine-at p8-5) (mine-at p2-6) (mine-at p8-6) (mine-at p2-7) (mine-at p7-8))
    ; minefield: 0 0 0 0 0 1 1 1 0 0 0 0 0 1 * 2 0 0 0 1 1 3 3 * 0 0 0 1 * 2 * 2 1 1 0 1 1 3 2 2 * 1 0 0 1 2 * 1 1 1 1 2 4 * 3 1 0 0 1 * * * 2 0
    (:hidden (first-move p2-3) (mine-at p7-2) (mine-at p8-3) (mine-at p5-4) (mine-at p7-4) (mine-at p1-6) (mine-at p7-6) (mine-at p6-7) (mine-at p4-8) (mine-at p5-8) (mine-at p6-8))
    ; minefield: 0 1 * 1 1 1 1 0 0 1 1 2 2 * 1 0 1 1 2 2 * 2 1 0 2 * 2 * 2 1 0 0 * 3 3 1 1 0 0 0 3 * 2 1 0 1 1 1 * 3 * 1 0 1 * 1 1 2 1 1 0 1 1 1
    (:hidden (first-move p5-7) (mine-at p3-1) (mine-at p6-2) (mine-at p5-3) (mine-at p2-4) (mine-at p4-4) (mine-at p1-5) (mine-at p2-6) (mine-at p1-7) (mine-at p3-7) (mine-at p7-7))
    ; minefield: 0 0 0 0 0 0 1 * 1 1 0 0 0 0 1 1 * 3 2 1 0 0 0 0 2 * * 1 1 1 2 1 1 2 2 2 2 * 2 * 1 1 0 1 * 2 2 1 * 1 0 1 2 2 2 1 1 1 0 0 1 * 2 *
    (:hidden (first-move p4-1) (mine-at p8-1) (mine-at p1-3) (mine-at p2-4) (mine-at p3-4) (mine-at p6-5) (mine-at p8-5) (mine-at p5-6) (mine-at p1-7) (mine-at p6-8) (mine-at p8-8))
    ; minefield: * 1 0 0 0 0 1 * 1 1 0 0 0 0 1 1 1 2 2 1 1 1 1 0 1 * * 1 2 * 3 1 1 2 2 1 2 * 3 * 0 0 1 1 2 1 2 1 0 0 2 * 3 1 0 0 0 0 2 * * 1 0 0
    (:hidden (first-move p2-7) (mine-at p1-1) (mine-at p8-1) (mine-at p2-4) (mine-at p3-4) (mine-at p6-4) (mine-at p6-5) (mine-at p8-5) (mine-at p4-7) (mine-at p4-8) (mine-at p5-8))
    ; minefield: 1 1 2 * 1 0 0 0 2 * 2 1 1 0 0 0 * 2 1 0 0 1 2 2 1 1 0 1 1 2 * * 2 2 1 1 * 2 3 * * * 1 1 1 1 1 1 2 2 1 1 1 1 0 0 0 0 0 1 * 1 0 0
    (:hidden (first-move p6-2) (mine-at p4-1) (mine-at p2-2) (mine-at p1-3) (mine-at p7-4) (mine-at p8-4) (mine-at p5-5) (mine-at p8-5) (mine-at p1-6) (mine-at p2-6) (mine-at p5-8))
    ; minefield: 1 * 2 * 1 0 0 0 1 1 3 2 2 0 0 0 0 0 1 * 2 1 0 0 0 1 2 3 * 1 0 0 0 1 * 2 1 1 0 0 1 2 2 1 0 0 1 1 1 * 2 1 1 1 3 * 1 2 * 1 1 * 3 *
    (:hidden (first-move p8-5) (mine-at p2-1) (mine-at p4-1) (mine-at p4-3) (mine-at p5-4) (mine-at p3-5) (mine-at p2-7) (mine-at p8-7) (mine-at p3-8) (mine-at p6-8) (mine-at p8-8))
    ; minefield: 0 0 0 2 * 3 * * 0 0 1 3 * 3 2 2 0 0 1 * 2 2 1 1 0 1 2 2 1 1 * 1 0 1 * 1 0 1 1 1 0 1 1 1 0 0 1 1 0 0 0 1 1 2 2 * 0 0 0 1 * 2 * 2
    (:hidden (first-move p1-3) (mine-at p5-1) (mine-at p7-1) (mine-at p8-1) (mine-at p5-2) (mine-at p4-3) (mine-at p7-4) (mine-at p3-5) (mine-at p8-7) (mine-at p5-8) (mine-at p7-8))
    ; minefield: 0 0 0 2 * 3 2 * 0 0 0 2 * 3 * 3 1 1 1 1 1 3 3 * 1 * 1 0 0 1 * 2 1 1 1 1 1 2 2 2 0 0 1 2 * 1 1 * 0 0 1 * 2 1 1 1 0 0 1 1 1 0 0 0
    (:hidden (first-move p7-8) (mine-at p5-1) (mine-at p8-1) (mine-at p5-2) (mine-at p7-2) (mine-at p8-3) (mine-at p2-4) (mine-at p7-4) (mine-at p5-6) (mine-at p8-6) (mine-at p4-7))
    ; minefield: 1 1 0 1 * * * 1 * 1 0 1 2 3 2 1 2 2 1 0 0 0 0 0 1 * 1 0 0 0 0 0 2 2 2 0 0 0 1 1 2 * 1 0 0 0 1 * * 2 1 0 0 1 3 3 1 1 0 0 0 1 * *
    (:hidden (first-move p3-2) (mine-at p5-1) (mine-at p6-1) (mine-at p7-1) (mine-at p1-2) (mine-at p2-4) (mine-at p2-6) (mine-at p8-6) (mine-at p1-7) (mine-at p7-8) (mine-at p8-8))
    ; minefield: 0 0 1 1 2 2 * 1 0 0 1 * 2 * 2 1 0 0 1 1 2 1 1 0 2 2 1 0 0 0 0 0 * * 1 0 0 0 1 1 2 2 1 1 2 2 2 * 0 1 1 2 * * 3 1 0 1 * 2 3 * 2 0
    (:hidden (first-move p1-8) (mine-at p7-1) (mine-at p4-2) (mine-at p6-2) (mine-at p1-5) (mine-at p2-5) (mine-at p8-6) (mine-at p5-7) (mine-at p6-7) (mine-at p3-8) (mine-at p6-8))
    ; minefield: 0 2 * 3 1 0 0 0 0 2 * * 1 0 0 0 1 2 2 2 1 0 0 0 * 1 0 0 1 2 2 1 1 1 0 0 1 * * 1 1 1 1 1 2 4 3 2 2 * 1 1 * 2 * 1 * 2 1 1 1 2 1 1
    (:hidden (first-move p6-1) (mine-at p3-1) (mine-at p3-2) (mine-at p4-2) (mine-at p1-4) (mine-at p6-5) (mine-at p7-5) (mine-at p2-7) (mine-at p5-7) (mine-at p7-7) (mine-at p1-8))
    ; minefield: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 0 0 1 * 2 2 * 1 0 0 1 2 * 2 1 1 1 1 1 3 3 2 0 0 1 * 3 * * 1 1 2 3 2 * * 3 1 1 * * 1
    (:hidden (first-move p7-3) (mine-at p2-4) (mine-at p5-4) (mine-at p3-5) (mine-at p8-6) (mine-at p2-7) (mine-at p3-7) (mine-at p1-8) (mine-at p2-8) (mine-at p6-8) (mine-at p7-8))
    ; minefield: 0 0 0 1 * * 1 0 1 1 0 2 3 3 1 0 * 2 1 2 * 1 0 0 1 3 * 3 1 1 0 0 0 2 * 2 0 0 0 0 1 2 1 2 1 2 1 1 * 1 0 1 * 2 * 2 1 1 0 1 1 2 2 *
    (:hidden (first-move p6-5) (mine-at p5-1) (mine-at p6-1) (mine-at p1-3) (mine-at p5-3) (mine-at p3-4) (mine-at p3-5) (mine-at p1-7) (mine-at p5-7) (mine-at p7-7) (mine-at p8-8))
    ; minefield: 1 * 2 1 1 2 * 2 1 1 2 * 2 4 * 3 0 0 1 2 * 3 * 3 0 0 0 1 1 2 2 * 0 0 0 0 1 1 2 1 0 0 0 0 1 * 1 0 0 0 0 1 3 3 2 0 0 0 0 1 * * 1 0
    (:hidden (first-move p2-7) (mine-at p2-1) (mine-at p7-1) (mine-at p4-2) (mine-at p7-2) (mine-at p5-3) (mine-at p7-3) (mine-at p8-4) (mine-at p6-6) (mine-at p5-8) (mine-at p6-8))
    ; minefield: 1 1 1 * * 2 * 1 * 1 1 2 2 3 2 2 1 1 0 0 0 1 * 1 0 0 0 0 0 1 2 2 0 0 0 0 0 0 1 * 1 1 0 0 0 1 2 2 * 2 1 0 0 2 * 2 2 * 1 0 0 2 * 2
    (:hidden (first-move p1-5) (mine-at p4-1) (mine-at p5-1) (mine-at p7-1) (mine-at p1-2) (mine-at p7-3) (mine-at p8-5) (mine-at p1-7) (mine-at p7-7) (mine-at p2-8) (mine-at p7-8))
    ; minefield: 0 1 * 2 * 2 * 1 0 1 1 2 1 2 1 1 0 0 0 0 0 0 1 1 0 0 0 1 1 2 3 * 0 0 0 2 * 4 * * 1 1 0 2 * 4 * 3 * 1 0 1 1 2 1 1 1 1 0 0 0 0 0 0
    (:hidden (first-move p1-2) (mine-at p3-1) (mine-at p5-1) (mine-at p7-1) (mine-at p8-4) (mine-at p5-5) (mine-at p7-5) (mine-at p8-5) (mine-at p5-6) (mine-at p7-6) (mine-at p1-7))
    ; minefield: 0 1 * 3 * 2 0 0 0 1 1 4 * 3 0 0 0 0 0 3 * 3 0 0 0 1 2 4 * 2 0 0 1 2 * * 2 1 0 0 * 3 3 3 1 0 1 1 1 2 * 1 0 0 1 * 0 1 1 1 0 0 1 1
    (:hidden (first-move p7-1) (mine-at p3-1) (mine-at p5-1) (mine-at p5-2) (mine-at p5-3) (mine-at p5-4) (mine-at p3-5) (mine-at p4-5) (mine-at p1-6) (mine-at p3-7) (mine-at p8-7))
    ; minefield: * 1 0 0 1 * 2 * 2 3 1 1 1 2 3 2 * 2 * 1 0 1 * 1 1 2 1 1 0 1 1 1 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 1 2 2 * 1 1 1 1 * 2 * 2 1 1 * 1
    (:hidden (first-move p7-6) (mine-at p1-1) (mine-at p6-1) (mine-at p8-1) (mine-at p1-3) (mine-at p3-3) (mine-at p7-3) (mine-at p4-7) (mine-at p1-8) (mine-at p3-8) (mine-at p7-8))
    ; minefield: 1 1 1 0 0 0 1 * 1 * 1 0 0 0 1 1 2 2 1 1 1 1 1 1 * 2 1 1 * 1 1 * 3 * 2 1 1 1 1 1 2 * 2 1 1 1 0 0 1 2 3 3 * 1 0 0 0 1 * * 2 1 0 0
    (:hidden (first-move p4-2) (mine-at p8-1) (mine-at p2-2) (mine-at p1-4) (mine-at p5-4) (mine-at p8-4) (mine-at p2-5) (mine-at p2-6) (mine-at p5-7) (mine-at p3-8) (mine-at p4-8))
    ; minefield: 0 1 2 * 1 0 1 * 0 2 * 3 1 0 1 1 1 3 * 2 1 1 1 0 * 3 1 1 1 * 1 0 * 2 0 0 1 1 1 0 1 1 0 0 0 0 0 0 0 0 0 1 1 2 2 2 0 0 0 1 * 2 * *
    (:hidden (first-move p6-2) (mine-at p4-1) (mine-at p8-1) (mine-at p3-2) (mine-at p3-3) (mine-at p1-4) (mine-at p6-4) (mine-at p1-5) (mine-at p5-8) (mine-at p7-8) (mine-at p8-8))
    ; minefield: 0 0 1 1 2 * 1 0 0 0 1 * 2 2 2 1 0 0 2 3 4 3 * 1 0 0 1 * * * 2 1 1 2 3 3 3 2 1 0 1 * * 1 0 0 0 0 2 3 3 1 0 1 1 1 1 * 1 0 0 1 * 1
    (:hidden (first-move p2-3) (mine-at p6-1) (mine-at p4-2) (mine-at p7-3) (mine-at p4-4) (mine-at p5-4) (mine-at p6-4) (mine-at p2-6) (mine-at p3-6) (mine-at p2-8) (mine-at p7-8))
    ; minefield: 2 * 1 0 0 0 0 0 * 2 1 0 0 1 1 1 1 1 1 1 1 1 * 1 1 1 3 * 2 1 1 1 1 * 4 * 3 0 0 0 1 1 3 * 2 0 0 0 1 1 2 3 3 1 0 0 * 1 1 * * 1 0 0
    (:hidden (first-move p5-1) (mine-at p2-1) (mine-at p1-2) (mine-at p7-3) (mine-at p4-4) (mine-at p2-5) (mine-at p4-5) (mine-at p4-6) (mine-at p1-8) (mine-at p4-8) (mine-at p5-8))
    ; minefield: 0 0 1 1 1 0 0 0 0 0 1 * 1 1 1 1 0 0 1 2 2 2 * 1 0 0 0 2 * 3 1 1 0 0 1 3 * 3 1 0 1 2 4 * 4 * 1 0 1 * * * 4 2 1 0 1 2 3 3 * 1 0 0
    (:hidden (first-move p2-2) (mine-at p4-2) (mine-at p7-3) (mine-at p5-4) (mine-at p5-5) (mine-at p4-6) (mine-at p6-6) (mine-at p2-7) (mine-at p3-7) (mine-at p4-7) (mine-at p5-8))
    ; minefield: 2 3 2 2 * 1 0 0 * * * 2 1 1 0 0 2 3 2 2 1 1 0 0 0 1 2 3 * 1 0 0 1 2 * * 2 1 1 1 * 2 2 2 1 0 1 * 1 1 0 0 1 1 2 1 0 0 0 0 1 * 1 0
    (:hidden (first-move p3-7) (mine-at p5-1) (mine-at p1-2) (mine-at p2-2) (mine-at p3-2) (mine-at p5-4) (mine-at p3-5) (mine-at p4-5) (mine-at p1-6) (mine-at p8-6) (mine-at p6-8))
    ; minefield: 1 1 2 1 1 0 0 0 1 * 2 * 1 0 1 1 1 1 2 1 1 0 1 * 0 0 1 1 1 0 1 1 1 2 2 * 1 0 1 1 * 2 * 2 1 0 2 * 2 3 1 1 0 1 3 * * 1 0 0 0 1 * 2
    (:hidden (first-move p4-8) (mine-at p2-2) (mine-at p4-2) (mine-at p8-3) (mine-at p4-5) (mine-at p1-6) (mine-at p3-6) (mine-at p8-6) (mine-at p8-7) (mine-at p1-8) (mine-at p7-8))
    ; minefield: 0 1 * 2 1 2 * * 0 1 1 2 * 2 3 3 0 0 0 1 1 1 1 * 0 0 0 0 0 1 2 2 1 1 1 0 0 1 * 1 2 * 3 1 1 2 2 1 2 * * 1 1 * 1 0 1 2 2 1 1 1 1 0
    (:hidden (first-move p3-3) (mine-at p3-1) (mine-at p7-1) (mine-at p8-1) (mine-at p5-2) (mine-at p8-3) (mine-at p7-5) (mine-at p2-6) (mine-at p2-7) (mine-at p3-7) (mine-at p6-7))
    ; minefield: 0 0 0 0 0 0 2 * 0 1 1 1 0 0 2 * 1 2 * 1 0 0 2 2 * 4 3 2 0 0 1 * 3 * * 2 1 1 1 1 * 3 2 2 * 1 0 0 1 1 1 2 2 1 0 0 0 0 1 * 1 0 0 0
    (:hidden (first-move p7-7) (mine-at p8-1) (mine-at p8-2) (mine-at p3-3) (mine-at p1-4) (mine-at p8-4) (mine-at p2-5) (mine-at p3-5) (mine-at p1-6) (mine-at p5-6) (mine-at p4-8))
    ; minefield: 0 0 0 0 0 0 0 0 1 1 2 1 1 0 0 0 1 * 2 * 1 0 0 0 2 2 2 1 2 2 2 1 * 2 0 0 1 * * 1 * 3 1 1 2 2 3 2 * 3 1 * 1 0 1 * * 2 1 1 1 0 1 1
    (:hidden (first-move p3-5) (mine-at p2-3) (mine-at p4-3) (mine-at p1-5) (mine-at p6-5) (mine-at p7-5) (mine-at p1-6) (mine-at p1-7) (mine-at p4-7) (mine-at p8-7) (mine-at p1-8))
    ; minefield: 0 0 0 1 1 1 1 1 0 0 0 1 * 1 1 * 1 1 0 1 1 1 1 1 * 3 2 1 1 0 0 0 * * 2 * 1 0 0 0 3 4 4 2 1 0 0 0 2 * * 2 1 0 0 0 2 * 4 * 1 0 0 0
    (:hidden (first-move p7-5) (mine-at p5-2) (mine-at p8-2) (mine-at p1-4) (mine-at p1-5) (mine-at p2-5) (mine-at p4-5) (mine-at p2-7) (mine-at p3-7) (mine-at p2-8) (mine-at p4-8))
    ; minefield: * 1 0 0 0 0 1 1 2 2 1 0 0 0 1 * 1 * 1 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 * 1 2 * 1 * 1 2 2 2 2 * 1 1 1 1 * 3 3 2 0 0 0 1 2 * * 1
    (:hidden (first-move p5-3) (mine-at p1-1) (mine-at p8-2) (mine-at p2-3) (mine-at p5-5) (mine-at p8-5) (mine-at p2-6) (mine-at p8-6) (mine-at p5-7) (mine-at p6-8) (mine-at p7-8))
    ; minefield: 0 1 2 3 2 1 0 0 0 1 * * * 1 0 0 0 1 2 3 3 2 1 0 0 0 1 1 2 * 1 0 0 0 1 * 2 1 1 0 0 0 2 2 2 1 1 1 1 1 3 * 3 2 * 1 1 * 3 * 3 * 2 1
    (:hidden (first-move p2-6) (mine-at p3-2) (mine-at p4-2) (mine-at p5-2) (mine-at p6-4) (mine-at p4-5) (mine-at p4-7) (mine-at p7-7) (mine-at p2-8) (mine-at p4-8) (mine-at p6-8))
    ; minefield: 1 1 1 * 1 1 1 1 * 1 1 1 1 1 * 1 1 1 0 0 0 1 1 1 0 0 0 0 0 1 1 1 0 0 0 0 1 2 * 2 1 1 0 1 2 * 3 * * 2 2 2 * 2 2 1 2 * 2 * 2 1 0 0
    (:hidden (first-move p2-4) (mine-at p4-1) (mine-at p1-2) (mine-at p7-2) (mine-at p7-5) (mine-at p6-6) (mine-at p8-6) (mine-at p1-7) (mine-at p5-7) (mine-at p2-8) (mine-at p4-8))
    ; minefield: 0 1 1 1 0 0 0 0 0 1 * 3 3 2 2 1 0 1 2 * * * 2 * 0 1 2 3 3 2 3 2 0 1 * 1 0 0 1 * 1 2 1 1 0 0 1 1 * 1 0 0 0 1 2 2 1 1 0 0 0 1 * *
    (:hidden (first-move p1-2) (mine-at p3-2) (mine-at p4-3) (mine-at p5-3) (mine-at p6-3) (mine-at p8-3) (mine-at p3-5) (mine-at p8-5) (mine-at p1-7) (mine-at p7-8) (mine-at p8-8))
    ; minefield: 0 1 1 2 * 1 1 1 0 1 * 3 3 2 2 * 1 2 2 * 2 * 3 2 * 2 2 2 2 1 2 * 2 3 * 1 0 0 1 1 1 * 2 1 1 1 1 0 1 1 1 0 1 * 1 0 0 0 0 0 1 1 1 0
    (:hidden (first-move p8-8) (mine-at p5-1) (mine-at p3-2) (mine-at p8-2) (mine-at p4-3) (mine-at p6-3) (mine-at p1-4) (mine-at p8-4) (mine-at p3-5) (mine-at p2-6) (mine-at p6-7))
    ; minefield: 1 * 2 1 1 0 1 1 2 2 3 * 2 0 1 * * 2 4 * 3 1 3 3 1 2 * * 2 1 * * 0 1 2 2 1 1 2 2 0 0 0 0 1 1 1 0 0 0 0 0 1 * 1 0 0 0 0 0 1 1 1 0
    (:hidden (first-move p4-7) (mine-at p2-1) (mine-at p4-2) (mine-at p8-2) (mine-at p1-3) (mine-at p4-3) (mine-at p3-4) (mine-at p4-4) (mine-at p7-4) (mine-at p8-4) (mine-at p6-7))
    ; minefield: 0 0 0 0 0 0 0 0 1 1 1 1 2 3 2 1 1 * 1 1 * * * 1 1 1 1 1 4 * 4 1 0 0 0 0 3 * 4 1 0 0 0 0 2 * 3 * 1 2 2 1 1 1 2 1 1 * * 1 0 0 0 0
    (:hidden (first-move p7-1) (mine-at p2-3) (mine-at p5-3) (mine-at p6-3) (mine-at p7-3) (mine-at p6-4) (mine-at p6-5) (mine-at p6-6) (mine-at p8-6) (mine-at p2-8) (mine-at p3-8))
    ; minefield: 0 0 1 * * 2 0 0 0 0 1 3 * 3 1 0 0 0 1 2 3 * 1 0 0 0 2 * 3 1 1 0 2 3 4 * 2 0 0 0 * * * 2 1 0 0 0 2 4 3 2 0 0 0 0 0 1 * 1 0 0 0 0
    (:hidden (first-move p2-3) (mine-at p4-1) (mine-at p5-1) (mine-at p5-2) (mine-at p6-3) (mine-at p4-4) (mine-at p4-5) (mine-at p1-6) (mine-at p2-6) (mine-at p3-6) (mine-at p3-8))
    ; minefield: * 3 1 1 0 1 * 1 * 3 * 1 0 1 2 2 1 2 1 1 0 0 1 * 0 0 0 0 0 0 1 1 1 1 2 2 2 1 0 0 1 * 2 * * 1 0 0 2 2 3 3 3 1 0 0 * 1 1 * 1 0 0 0
    (:hidden (first-move p3-4) (mine-at p1-1) (mine-at p7-1) (mine-at p1-2) (mine-at p3-2) (mine-at p8-3) (mine-at p2-6) (mine-at p4-6) (mine-at p5-6) (mine-at p1-8) (mine-at p4-8))
    ; minefield: 0 0 1 2 * 2 1 1 0 0 1 * 2 2 * 2 0 0 1 1 1 1 3 * 0 0 0 0 0 0 3 * 0 0 0 0 0 0 3 * 1 1 0 0 0 0 3 * * 2 1 0 0 0 2 * 2 * 1 0 0 0 1 1
    (:hidden (first-move p4-5) (mine-at p5-1) (mine-at p4-2) (mine-at p7-2) (mine-at p8-3) (mine-at p8-4) (mine-at p8-5) (mine-at p8-6) (mine-at p1-7) (mine-at p8-7) (mine-at p2-8))
    ; minefield: 2 2 1 0 1 * 1 0 * * 1 0 2 2 2 0 * 3 1 0 1 * 3 2 2 2 0 0 1 2 * * * 2 0 0 0 1 2 2 * 2 0 0 1 1 1 0 1 1 0 0 1 * 1 0 0 0 0 0 1 1 1 0
    (:hidden (first-move p4-4) (mine-at p6-1) (mine-at p1-2) (mine-at p2-2) (mine-at p1-3) (mine-at p6-3) (mine-at p7-4) (mine-at p8-4) (mine-at p1-5) (mine-at p1-6) (mine-at p6-7))
    ; minefield: 1 2 * 2 1 0 1 * 2 * 3 * 1 0 2 2 * 3 3 1 1 0 1 * 3 * 2 0 0 0 1 1 3 * 2 0 0 0 0 0 * 2 1 0 0 0 0 0 1 1 1 1 1 0 0 0 0 0 1 * 1 0 0 0
    (:hidden (first-move p7-6) (mine-at p3-1) (mine-at p8-1) (mine-at p2-2) (mine-at p4-2) (mine-at p1-3) (mine-at p8-3) (mine-at p2-4) (mine-at p2-5) (mine-at p1-6) (mine-at p4-8))
    ; minefield: 0 0 0 0 1 * * * 0 0 0 0 1 2 3 2 1 1 2 1 1 0 0 0 1 * 2 * 1 0 0 0 1 1 2 2 2 1 0 0 0 0 0 2 * 2 0 0 0 1 2 4 * 2 1 1 0 1 * * 2 1 1 *
    (:hidden (first-move p2-1) (mine-at p6-1) (mine-at p7-1) (mine-at p8-1) (mine-at p2-4) (mine-at p4-4) (mine-at p5-6) (mine-at p5-7) (mine-at p3-8) (mine-at p4-8) (mine-at p8-8))
    ; minefield: 0 2 * 2 1 * 1 0 1 3 * 3 2 1 1 0 * 3 2 * 1 0 0 0 * 3 3 3 2 0 0 0 1 3 * * 1 0 0 0 0 2 * 4 2 0 0 0 0 1 2 * 1 0 0 0 0 0 1 1 1 0 0 0
    (:hidden (first-move p8-6) (mine-at p3-1) (mine-at p6-1) (mine-at p3-2) (mine-at p1-3) (mine-at p4-3) (mine-at p1-4) (mine-at p3-5) (mine-at p4-5) (mine-at p3-6) (mine-at p4-7))
    ; minefield: 1 * 1 0 0 0 1 * 1 1 2 1 1 0 1 1 0 0 1 * 1 0 0 0 0 1 2 2 1 0 0 0 0 1 * 1 0 0 0 0 0 2 2 3 1 1 0 0 1 2 * 4 * 3 1 0 1 * 3 * * * 1 0
    (:hidden (first-move p6-3) (mine-at p2-1) (mine-at p8-1) (mine-at p4-3) (mine-at p3-5) (mine-at p3-7) (mine-at p5-7) (mine-at p2-8) (mine-at p4-8) (mine-at p5-8) (mine-at p6-8))
    ; minefield: 0 0 0 1 * * * 1 0 0 0 1 3 4 3 1 0 0 1 1 2 * 1 0 1 1 1 * 3 2 2 0 * 1 2 2 3 * 1 0 2 2 1 * 2 1 1 0 * 1 1 1 1 0 1 1 1 1 0 0 0 0 1 *
    (:hidden (first-move p3-1) (mine-at p5-1) (mine-at p6-1) (mine-at p7-1) (mine-at p6-3) (mine-at p4-4) (mine-at p1-5) (mine-at p6-5) (mine-at p4-6) (mine-at p1-7) (mine-at p8-8))
    ; minefield: 0 0 0 1 * 2 * 2 0 0 0 1 1 2 2 * 1 1 1 0 0 0 2 2 1 * 1 1 1 1 1 * 1 1 1 2 * 2 1 1 1 1 0 2 * 2 0 0 * 1 1 3 3 2 0 0 1 1 1 * * 1 0 0
    (:hidden (first-move p8-6) (mine-at p5-1) (mine-at p7-1) (mine-at p8-2) (mine-at p2-4) (mine-at p8-4) (mine-at p5-5) (mine-at p5-6) (mine-at p1-7) (mine-at p4-8) (mine-at p5-8))
    ; minefield: * 2 0 0 0 0 1 * * 3 1 0 0 0 2 2 2 * 1 0 0 0 2 * 2 2 2 0 0 0 2 * 2 * 4 2 1 0 1 1 2 * * * 1 0 0 0 1 2 3 2 1 0 0 0 0 0 0 0 0 0 0 0
    (:hidden (first-move p6-7) (mine-at p1-1) (mine-at p8-1) (mine-at p1-2) (mine-at p2-3) (mine-at p8-3) (mine-at p8-4) (mine-at p2-5) (mine-at p2-6) (mine-at p3-6) (mine-at p4-6))
    ; minefield: 0 0 0 1 1 1 0 0 0 0 1 2 * 1 0 0 1 1 1 * 2 2 1 1 * 1 1 1 1 1 * 1 2 2 0 0 0 1 2 2 * 1 1 2 2 1 1 * 2 2 1 * * 2 2 1 * 1 1 2 3 * 1 0
    (:hidden (first-move p5-5) (mine-at p5-2) (mine-at p4-3) (mine-at p1-4) (mine-at p7-4) (mine-at p1-6) (mine-at p8-6) (mine-at p4-7) (mine-at p5-7) (mine-at p1-8) (mine-at p6-8))
    ; minefield: 1 1 0 0 1 * 2 1 * 2 0 0 1 2 * 1 * 3 0 0 0 1 1 1 * 2 0 1 1 1 0 0 1 1 1 2 * 1 0 0 1 1 2 * 3 1 0 0 * 1 2 * 2 1 1 1 1 1 1 1 1 1 * 1
    (:hidden (first-move p7-6) (mine-at p6-1) (mine-at p1-2) (mine-at p7-2) (mine-at p1-3) (mine-at p1-4) (mine-at p5-5) (mine-at p4-6) (mine-at p1-7) (mine-at p4-7) (mine-at p7-8))
    ; minefield: 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 0 1 1 1 1 2 * 1 0 * 1 1 * 2 1 1 0 2 2 1 2 3 2 1 0 * 2 1 1 * * 2 1 2 * 1 1 2 4 * 3 1 1 1 0 0 2 * *
    (:hidden (first-move p8-4) (mine-at p6-3) (mine-at p1-4) (mine-at p4-4) (mine-at p1-6) (mine-at p5-6) (mine-at p6-6) (mine-at p2-7) (mine-at p7-7) (mine-at p7-8) (mine-at p8-8))
    ; minefield: 0 0 1 1 1 1 1 1 0 0 2 * 2 1 * 1 1 1 3 * 2 2 2 2 1 * 2 1 1 1 * 1 1 1 2 1 1 1 1 1 2 3 4 * 2 0 0 0 * * * * 2 0 0 0 2 3 3 2 1 0 0 0
    (:hidden (first-move p8-7) (mine-at p4-2) (mine-at p7-2) (mine-at p4-3) (mine-at p2-4) (mine-at p7-4) (mine-at p4-6) (mine-at p1-7) (mine-at p2-7) (mine-at p3-7) (mine-at p4-7))
    ; minefield: * * 1 0 0 0 0 0 2 2 1 1 1 1 0 0 0 0 0 1 * 1 0 0 0 1 1 3 2 2 0 0 1 2 * 3 * 3 1 1 * 2 1 3 * 4 * 1 1 1 0 1 2 * 3 2 0 0 0 0 1 1 2 *
    (:hidden (first-move p3-8) (mine-at p1-1) (mine-at p2-1) (mine-at p5-3) (mine-at p3-5) (mine-at p5-5) (mine-at p1-6) (mine-at p5-6) (mine-at p7-6) (mine-at p6-7) (mine-at p8-8))
    ; minefield: * 1 0 0 0 0 0 0 1 1 0 0 1 1 1 0 1 1 1 0 1 * 2 1 1 * 1 0 1 2 * 2 1 1 2 1 1 1 2 * 1 1 2 * 1 0 2 2 3 * 3 1 1 0 1 * * * 2 0 0 0 1 1
    (:hidden (first-move p4-4) (mine-at p1-1) (mine-at p6-3) (mine-at p2-4) (mine-at p7-4) (mine-at p8-5) (mine-at p4-6) (mine-at p2-7) (mine-at p8-7) (mine-at p1-8) (mine-at p2-8))
    ; minefield: 2 2 1 0 0 0 0 0 * * 1 0 0 0 0 0 3 4 2 1 0 0 0 0 * 3 * 1 0 0 0 0 * 4 1 1 0 0 0 0 * 3 0 0 0 0 0 0 * 3 1 2 1 2 1 1 1 2 * 2 * 2 * 1
    (:hidden (first-move p5-2) (mine-at p1-2) (mine-at p2-2) (mine-at p1-4) (mine-at p3-4) (mine-at p1-5) (mine-at p1-6) (mine-at p1-7) (mine-at p3-8) (mine-at p5-8) (mine-at p7-8))
    ; minefield: 0 0 0 1 1 1 0 0 0 0 0 2 * 4 2 1 2 2 1 2 * * * 2 * * 1 1 2 3 3 * * 3 1 0 0 0 2 2 1 1 1 1 1 0 1 * 0 0 1 * 1 0 1 1 0 0 1 1 1 0 0 0
    (:hidden (first-move p6-6) (mine-at p5-2) (mine-at p5-3) (mine-at p6-3) (mine-at p7-3) (mine-at p1-4) (mine-at p2-4) (mine-at p8-4) (mine-at p1-5) (mine-at p8-6) (mine-at p4-7))
    ; minefield: 0 0 0 0 0 0 1 * 0 0 0 1 1 1 1 1 0 0 0 2 * 3 1 0 0 0 0 2 * * 1 0 1 1 0 2 3 3 1 0 * 2 2 3 * 2 0 0 2 * 2 * * 3 1 0 1 1 2 2 3 * 1 0
    (:hidden (first-move p1-4) (mine-at p8-1) (mine-at p5-3) (mine-at p5-4) (mine-at p6-4) (mine-at p1-6) (mine-at p5-6) (mine-at p2-7) (mine-at p4-7) (mine-at p5-7) (mine-at p6-8))
    ; minefield: * * 2 * 1 0 0 0 * 3 2 1 2 1 2 1 1 1 0 1 2 * 2 * 1 1 1 1 * 2 2 1 1 * 1 1 1 1 0 0 1 1 2 1 1 0 0 0 0 0 1 * 2 1 1 0 0 0 1 1 2 * 1 0
    (:hidden (first-move p7-1) (mine-at p1-1) (mine-at p2-1) (mine-at p4-1) (mine-at p1-2) (mine-at p6-3) (mine-at p8-3) (mine-at p5-4) (mine-at p2-5) (mine-at p4-7) (mine-at p6-8))
    ; minefield: 0 0 0 0 1 * 2 1 0 0 0 0 1 2 * 1 0 0 0 1 1 2 1 1 1 1 2 2 * 1 0 0 1 * 3 * 4 2 0 0 3 3 4 * * 1 0 0 * * 2 2 2 1 1 1 2 2 1 0 0 0 1 *
    (:hidden (first-move p4-8) (mine-at p6-1) (mine-at p7-2) (mine-at p5-4) (mine-at p2-5) (mine-at p4-5) (mine-at p4-6) (mine-at p5-6) (mine-at p1-7) (mine-at p2-7) (mine-at p8-8))
    ; minefield: 0 1 2 2 1 0 0 0 0 1 * * 1 0 0 0 0 1 3 4 3 1 1 1 0 0 2 * * 1 1 * 0 1 3 * 3 1 1 1 1 2 * 2 1 0 1 1 * 2 1 1 0 0 2 * 1 1 0 0 0 0 2 *
    (:hidden (first-move p2-4) (mine-at p3-2) (mine-at p4-2) (mine-at p4-4) (mine-at p5-4) (mine-at p8-4) (mine-at p4-5) (mine-at p3-6) (mine-at p1-7) (mine-at p8-7) (mine-at p8-8))
    ; minefield: 0 0 1 * 2 2 3 * 0 0 1 1 2 * * 2 0 0 0 0 1 3 3 2 0 0 0 0 0 1 * 2 1 1 0 0 0 1 2 * * 1 0 0 0 1 2 2 2 2 0 1 1 2 * 1 * 1 0 1 * 2 1 1
    (:hidden (first-move p1-3) (mine-at p4-1) (mine-at p8-1) (mine-at p6-2) (mine-at p7-2) (mine-at p7-4) (mine-at p8-5) (mine-at p1-6) (mine-at p7-7) (mine-at p1-8) (mine-at p5-8))
    ; minefield: 1 1 0 0 0 1 2 * * 1 0 0 0 1 * 3 1 2 1 1 0 1 2 * 1 3 * 2 0 0 1 1 2 * * 2 0 0 0 0 * 3 2 2 1 1 0 0 2 2 0 1 * 1 0 0 * 1 0 1 1 1 0 0
    (:hidden (first-move p6-4) (mine-at p8-1) (mine-at p1-2) (mine-at p7-2) (mine-at p8-3) (mine-at p3-4) (mine-at p2-5) (mine-at p3-5) (mine-at p1-6) (mine-at p5-7) (mine-at p1-8))
    ; minefield: * 1 0 0 0 0 2 * 1 1 1 1 1 0 2 * 0 0 1 * 3 2 2 1 0 0 1 2 * * 2 1 0 0 0 1 3 4 * 1 0 0 0 0 1 * 2 1 0 0 0 1 2 3 2 1 0 0 0 1 * 2 * 1
    (:hidden (first-move p4-6) (mine-at p1-1) (mine-at p8-1) (mine-at p8-2) (mine-at p4-3) (mine-at p5-4) (mine-at p6-4) (mine-at p7-5) (mine-at p6-6) (mine-at p5-8) (mine-at p7-8))
    ; minefield: * 1 1 2 2 1 2 * 1 1 1 * * 1 2 * 1 1 1 2 2 1 1 1 * 1 0 0 0 0 0 0 1 1 0 0 0 1 1 1 1 1 2 1 1 1 * 1 1 * 2 * 1 1 2 2 1 1 2 1 1 0 1 *
    (:hidden (first-move p3-5) (mine-at p1-1) (mine-at p8-1) (mine-at p4-2) (mine-at p5-2) (mine-at p8-2) (mine-at p1-4) (mine-at p7-6) (mine-at p2-7) (mine-at p4-7) (mine-at p8-8))
    ; minefield: * 2 1 0 1 * 1 0 2 * 1 0 1 2 2 1 1 2 2 1 1 3 * 2 0 1 * 1 1 * * 2 0 1 1 1 1 2 2 1 0 0 0 0 0 0 1 1 0 0 0 0 1 1 3 * 0 0 0 0 1 * 3 *
    (:hidden (first-move p2-6) (mine-at p1-1) (mine-at p6-1) (mine-at p2-2) (mine-at p7-3) (mine-at p3-4) (mine-at p6-4) (mine-at p7-4) (mine-at p8-7) (mine-at p6-8) (mine-at p8-8))
    ; minefield: 1 * 2 1 1 1 2 * 1 1 3 * 2 1 * 2 0 0 2 * 2 1 1 1 1 1 1 2 3 2 1 0 * 1 0 1 * * 1 0 1 1 0 1 2 2 2 1 0 0 0 0 0 0 2 * 0 0 0 0 0 0 2 *
    (:hidden (first-move p6-7) (mine-at p2-1) (mine-at p8-1) (mine-at p4-2) (mine-at p7-2) (mine-at p4-3) (mine-at p1-5) (mine-at p5-5) (mine-at p6-5) (mine-at p8-7) (mine-at p8-8))
    ; minefield: 0 1 * 1 1 * 1 0 1 2 1 2 2 2 1 0 * 1 0 1 * 1 0 0 1 1 1 2 2 1 1 1 0 0 1 * 1 0 1 * 1 1 1 1 2 1 2 1 * 2 1 0 2 * 2 0 2 * 1 0 2 * 2 0
    (:hidden (first-move p8-3) (mine-at p3-1) (mine-at p6-1) (mine-at p1-3) (mine-at p5-3) (mine-at p4-5) (mine-at p8-5) (mine-at p1-7) (mine-at p6-7) (mine-at p2-8) (mine-at p6-8))
    ; minefield: 1 1 1 0 0 0 1 1 2 * 1 0 0 0 1 * * 3 2 1 0 1 2 2 1 2 * 1 0 1 * 1 1 3 2 2 0 1 1 1 * 2 * 1 1 1 2 1 1 2 1 2 2 * 2 * 0 0 0 1 * 2 2 1
    (:hidden (first-move p5-4) (mine-at p2-2) (mine-at p8-2) (mine-at p1-3) (mine-at p3-4) (mine-at p7-4) (mine-at p1-6) (mine-at p3-6) (mine-at p6-7) (mine-at p8-7) (mine-at p5-8))
    ; minefield: 0 0 0 0 0 0 1 * 1 1 0 0 0 0 1 1 * 3 2 1 0 0 0 0 2 * * 2 1 1 0 0 2 3 2 2 * 1 0 0 * 1 0 1 2 3 2 1 1 1 1 1 3 * * 1 0 0 1 * 3 * 3 1
    (:hidden (first-move p4-2) (mine-at p8-1) (mine-at p1-3) (mine-at p2-4) (mine-at p3-4) (mine-at p5-5) (mine-at p1-6) (mine-at p6-7) (mine-at p7-7) (mine-at p4-8) (mine-at p6-8))
    ; minefield: 1 * 1 0 0 1 3 * 2 2 1 0 1 2 * * * 1 0 0 1 * 4 3 1 1 0 0 1 1 2 * 1 1 0 0 0 1 2 2 * 1 0 0 0 1 * 1 1 1 0 0 0 1 2 2 0 0 0 0 0 0 1 *
    (:hidden (first-move p4-2) (mine-at p2-1) (mine-at p8-1) (mine-at p7-2) (mine-at p8-2) (mine-at p1-3) (mine-at p6-3) (mine-at p8-4) (mine-at p1-6) (mine-at p7-6) (mine-at p8-8))
    ; minefield: 0 0 0 1 * 2 1 1 0 1 1 2 1 2 * 2 0 1 * 1 1 2 3 * 2 3 2 1 1 * 2 1 * * 2 1 1 1 1 0 2 3 * 2 1 0 0 0 0 1 2 * 2 1 0 0 0 0 1 2 * 1 0 0
    (:hidden (first-move p7-7) (mine-at p5-1) (mine-at p7-2) (mine-at p3-3) (mine-at p8-3) (mine-at p6-4) (mine-at p1-5) (mine-at p2-5) (mine-at p3-6) (mine-at p4-7) (mine-at p5-8))
    ; minefield: 0 0 1 * 1 0 1 1 0 0 1 1 1 0 1 * 0 0 0 1 2 2 3 2 0 0 0 1 * * 3 * 1 1 2 2 4 4 5 * 1 * 2 * 2 * * 2 1 1 2 1 2 2 2 1 0 0 0 0 0 0 0 0
    (:hidden (first-move p7-8) (mine-at p4-1) (mine-at p8-2) (mine-at p5-4) (mine-at p6-4) (mine-at p8-4) (mine-at p8-5) (mine-at p2-6) (mine-at p4-6) (mine-at p6-6) (mine-at p7-6))
    ; minefield: * 1 1 * 1 0 0 0 1 1 1 1 1 0 0 0 0 1 1 1 0 0 0 0 0 1 * 1 0 0 0 0 0 1 1 1 0 1 2 2 1 1 0 1 1 3 * * * 3 2 2 * 3 * 3 2 * * 2 1 2 1 1
    (:hidden (first-move p5-4) (mine-at p1-1) (mine-at p4-1) (mine-at p3-4) (mine-at p7-6) (mine-at p8-6) (mine-at p1-7) (mine-at p5-7) (mine-at p7-7) (mine-at p2-8) (mine-at p3-8))
    ; minefield: 1 * 1 1 * 3 * 2 1 1 2 2 2 3 * 2 1 1 3 * 2 1 2 2 1 * 3 * 2 0 1 * 1 1 2 1 1 0 1 1 0 0 0 0 0 1 1 1 0 0 0 0 0 2 * 2 0 0 0 0 0 2 * 2
    (:hidden (first-move p3-6) (mine-at p2-1) (mine-at p5-1) (mine-at p7-1) (mine-at p7-2) (mine-at p4-3) (mine-at p2-4) (mine-at p4-4) (mine-at p8-4) (mine-at p7-7) (mine-at p7-8))
    ; minefield: 0 0 0 1 * 1 1 1 1 1 1 2 2 2 1 * 2 * 4 3 * 1 1 1 2 * * * 3 2 0 0 1 2 3 3 * 2 1 1 0 0 0 1 2 3 * 1 0 0 0 0 1 * 2 1 0 0 0 0 1 1 1 0
    (:hidden (first-move p7-4) (mine-at p5-1) (mine-at p8-2) (mine-at p2-3) (mine-at p5-3) (mine-at p2-4) (mine-at p3-4) (mine-at p4-4) (mine-at p5-5) (mine-at p7-6) (mine-at p6-7))
    ; minefield: * 1 0 1 * 1 0 0 2 2 0 1 1 1 0 0 * 1 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 1 1 0 0 0 0 0 2 * 2 2 2 1 1 1 * 4 3 * * 1 1 * * 3 * 3 2 1 1 1
    (:hidden (first-move p8-4) (mine-at p1-1) (mine-at p5-1) (mine-at p1-3) (mine-at p2-6) (mine-at p1-7) (mine-at p4-7) (mine-at p5-7) (mine-at p8-7) (mine-at p1-8) (mine-at p3-8))
    ; minefield: * 1 0 1 1 1 0 0 1 1 0 1 * 2 1 1 0 0 0 1 1 3 * 2 1 1 1 0 1 3 * 2 2 * 1 0 1 * 2 1 * 2 1 1 3 3 2 0 1 1 0 2 * * 1 0 0 0 0 2 * 3 1 0
    (:hidden (first-move p2-8) (mine-at p1-1) (mine-at p5-2) (mine-at p7-3) (mine-at p7-4) (mine-at p2-5) (mine-at p6-5) (mine-at p1-6) (mine-at p5-7) (mine-at p6-7) (mine-at p5-8))
    ; minefield: 1 1 1 0 0 1 1 1 1 * 2 1 1 1 * 1 2 2 3 * 2 3 2 2 1 * 2 2 * 2 * 1 1 1 1 2 2 3 1 1 0 0 0 1 * 1 1 1 1 1 0 1 2 2 2 * * 1 0 0 1 * 2 1
    (:hidden (first-move p3-7) (mine-at p2-2) (mine-at p7-2) (mine-at p4-3) (mine-at p2-4) (mine-at p5-4) (mine-at p7-4) (mine-at p5-6) (mine-at p8-7) (mine-at p1-8) (mine-at p6-8))
    ; minefield: 1 * 2 1 2 * 2 * 1 1 3 * 3 1 2 1 0 0 2 * 2 0 0 0 0 1 2 2 1 0 0 0 0 2 * 3 1 0 1 1 0 2 * * 2 1 2 * 0 1 2 2 2 * 2 1 0 0 0 0 1 1 1 0
    (:hidden (first-move p8-3) (mine-at p2-1) (mine-at p6-1) (mine-at p8-1) (mine-at p4-2) (mine-at p4-3) (mine-at p3-5) (mine-at p3-6) (mine-at p4-6) (mine-at p8-6) (mine-at p6-7))
    ; minefield: 0 0 0 0 0 1 * 1 0 0 0 1 1 3 2 2 0 0 0 1 * 2 * 1 0 0 0 1 1 2 2 2 1 1 1 0 1 2 3 * 1 * 1 0 1 * * 2 2 2 1 0 1 3 4 3 * 1 0 0 0 1 * *
    (:hidden (first-move p4-8) (mine-at p7-1) (mine-at p5-3) (mine-at p7-3) (mine-at p8-5) (mine-at p2-6) (mine-at p6-6) (mine-at p7-6) (mine-at p1-8) (mine-at p7-8) (mine-at p8-8))
    ; minefield: 0 1 * 2 * 1 0 0 0 2 2 3 2 2 2 1 0 1 * 2 2 * 2 * 0 1 2 * 2 1 3 2 0 0 2 2 2 0 1 * 0 1 2 * 1 0 1 1 0 1 * 2 1 1 1 1 0 1 1 1 0 1 * 1
    (:hidden (first-move p1-5) (mine-at p3-1) (mine-at p5-1) (mine-at p3-3) (mine-at p6-3) (mine-at p8-3) (mine-at p4-4) (mine-at p8-5) (mine-at p4-6) (mine-at p3-7) (mine-at p7-8))
    ; minefield: 0 0 0 0 1 * 2 1 0 0 0 0 1 2 * 1 1 2 1 1 0 1 1 1 * 3 * 1 0 0 0 0 2 * 2 1 1 2 2 1 1 1 1 1 2 * * 1 1 1 0 2 * 4 2 1 * 1 0 2 * 2 0 0
    (:hidden (first-move p4-2) (mine-at p6-1) (mine-at p7-2) (mine-at p1-4) (mine-at p3-4) (mine-at p2-5) (mine-at p6-6) (mine-at p7-6) (mine-at p5-7) (mine-at p1-8) (mine-at p5-8))
    ; minefield: 0 0 0 0 1 * 3 * 0 0 0 1 2 2 3 * 1 1 0 1 * 1 1 1 * 2 1 2 2 2 0 0 2 * 1 1 * 3 2 1 1 1 1 2 3 * * 1 0 0 0 1 * 3 2 1 0 0 0 1 1 1 0 0
    (:hidden (first-move p3-3) (mine-at p6-1) (mine-at p8-1) (mine-at p8-2) (mine-at p5-3) (mine-at p1-4) (mine-at p2-5) (mine-at p5-5) (mine-at p6-6) (mine-at p7-6) (mine-at p5-7))
    ; minefield: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 2 2 2 * 1 0 0 0 * * 3 1 1 0 1 1 3 * 2 1 2 2 2 * 1 1 2 3 * * 3 2 0 0 1 * * 3 2 *
    (:hidden (first-move p5-2) (mine-at p4-4) (mine-at p1-5) (mine-at p2-5) (mine-at p2-6) (mine-at p8-6) (mine-at p5-7) (mine-at p6-7) (mine-at p4-8) (mine-at p5-8) (mine-at p8-8))
    ; minefield: 0 0 0 0 0 1 1 1 0 1 1 1 0 2 * 2 2 3 * 1 0 2 * 3 * * 2 1 0 1 2 * 2 3 2 1 0 0 2 2 1 3 * 2 0 0 1 * * 3 * 2 0 0 1 1 1 2 1 1 0 0 0 0
    (:hidden (first-move p2-1) (mine-at p7-2) (mine-at p3-3) (mine-at p7-3) (mine-at p1-4) (mine-at p2-4) (mine-at p8-4) (mine-at p3-6) (mine-at p8-6) (mine-at p1-7) (mine-at p3-7))
    ; minefield: 2 2 1 1 * * 3 1 * * 2 2 4 * * 1 3 3 3 * 3 3 3 1 1 * 2 1 2 * 2 1 1 1 1 0 1 1 2 * 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    (:hidden (first-move p1-6) (mine-at p5-1) (mine-at p6-1) (mine-at p1-2) (mine-at p2-2) (mine-at p6-2) (mine-at p7-2) (mine-at p4-3) (mine-at p2-4) (mine-at p6-4) (mine-at p8-5))
    ; minefield: * 2 * 1 0 0 0 0 1 2 2 2 1 0 1 1 0 0 2 * 2 0 2 * 1 2 3 * 3 1 3 * * 2 * 3 * 1 2 * 1 2 1 2 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    (:hidden (first-move p2-7) (mine-at p1-1) (mine-at p3-1) (mine-at p4-3) (mine-at p8-3) (mine-at p4-4) (mine-at p8-4) (mine-at p1-5) (mine-at p3-5) (mine-at p5-5) (mine-at p8-5))
    ; minefield: 0 0 0 0 1 * * 2 1 1 0 0 1 2 3 * * 1 0 0 0 0 1 1 1 2 1 1 0 0 0 0 0 1 * 1 0 0 0 0 1 2 2 2 2 2 1 0 1 * 2 2 * * 2 1 1 1 2 * 3 3 * 1
    (:hidden (first-move p3-2) (mine-at p6-1) (mine-at p7-1) (mine-at p8-2) (mine-at p1-3) (mine-at p3-5) (mine-at p2-7) (mine-at p5-7) (mine-at p6-7) (mine-at p4-8) (mine-at p7-8))
    ; minefield: 2 3 * 1 0 1 * 1 * * 2 1 0 1 1 1 2 2 1 0 1 1 1 0 0 0 0 0 1 * 2 1 0 0 0 0 1 2 * 1 1 2 2 1 1 2 2 1 1 * * 1 2 * 2 0 1 2 2 1 2 * 2 0
    (:hidden (first-move p3-4) (mine-at p3-1) (mine-at p7-1) (mine-at p1-2) (mine-at p2-2) (mine-at p6-4) (mine-at p7-5) (mine-at p2-7) (mine-at p3-7) (mine-at p6-7) (mine-at p6-8))
    ; minefield: 0 0 0 0 0 1 2 * 1 1 0 0 0 2 * 3 * 2 0 0 0 2 * 2 * 2 0 0 0 2 2 2 1 2 1 1 0 1 * 1 0 1 * 2 1 1 1 1 0 1 3 * 3 1 0 0 0 0 2 * * 1 0 0
    (:hidden (first-move p3-2) (mine-at p8-1) (mine-at p7-2) (mine-at p1-3) (mine-at p7-3) (mine-at p1-4) (mine-at p7-5) (mine-at p3-6) (mine-at p4-7) (mine-at p4-8) (mine-at p5-8))
    ; minefield: 0 0 0 1 1 1 0 0 0 1 1 2 * 1 0 0 0 1 * 2 1 1 0 0 0 2 2 2 0 0 1 1 0 1 * 2 1 0 2 * 1 2 2 * 2 1 2 * * 1 1 2 * 2 3 3 1 1 0 1 1 2 * *
    (:hidden (first-move p7-3) (mine-at p5-2) (mine-at p3-3) (mine-at p3-5) (mine-at p8-5) (mine-at p4-6) (mine-at p8-6) (mine-at p1-7) (mine-at p5-7) (mine-at p7-8) (mine-at p8-8))
    ; minefield: 0 0 0 0 0 1 2 * 0 0 0 1 1 2 * 2 0 0 0 1 * 2 2 2 1 1 0 1 1 1 2 * * 2 1 1 0 1 3 * 1 2 * 2 1 3 * 3 0 1 1 2 * 3 * 2 0 0 0 1 1 2 1 1
    (:hidden (first-move p5-1) (mine-at p8-1) (mine-at p7-2) (mine-at p5-3) (mine-at p8-4) (mine-at p1-5) (mine-at p8-5) (mine-at p3-6) (mine-at p7-6) (mine-at p5-7) (mine-at p7-7))
    ; minefield: 0 2 * 2 1 * 1 0 0 2 * 3 2 2 1 0 0 1 1 2 * 2 1 1 0 0 0 2 2 4 * 3 0 0 0 1 * 4 * * 0 0 0 1 2 * 3 2 0 1 1 1 1 1 1 0 0 1 * 1 0 0 0 0
    (:hidden (first-move p2-4) (mine-at p3-1) (mine-at p6-1) (mine-at p3-2) (mine-at p5-3) (mine-at p7-4) (mine-at p5-5) (mine-at p7-5) (mine-at p8-5) (mine-at p6-6) (mine-at p3-8))
    ; minefield: * 3 * 1 0 1 * 1 * 3 1 1 0 1 1 1 1 1 1 1 2 2 2 1 1 1 2 * 3 * * 1 1 * 2 3 * 4 2 1 1 1 1 2 * 2 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0
    (:hidden (first-move p2-7) (mine-at p1-1) (mine-at p3-1) (mine-at p7-1) (mine-at p1-2) (mine-at p4-4) (mine-at p6-4) (mine-at p7-4) (mine-at p2-5) (mine-at p5-5) (mine-at p5-6))
    ; minefield: * 1 0 0 1 1 1 0 1 2 1 2 2 * 1 0 0 1 * 2 * 2 1 0 0 1 1 2 1 1 0 0 0 0 1 2 2 2 1 1 0 0 1 * * 3 * 2 0 0 2 3 3 4 * 3 0 0 1 * 1 2 * 2
    (:hidden (first-move p2-6) (mine-at p1-1) (mine-at p6-2) (mine-at p3-3) (mine-at p5-3) (mine-at p4-6) (mine-at p5-6) (mine-at p7-6) (mine-at p7-7) (mine-at p4-8) (mine-at p7-8))
    ; minefield: 1 1 0 0 0 1 1 1 * 2 2 2 1 1 * 1 1 2 * * 1 2 2 2 1 2 2 3 2 2 * 2 * 1 0 1 * 2 2 * 2 2 1 1 1 1 1 1 1 * 2 1 0 0 0 0 1 2 * 1 0 0 0 0
    (:hidden (first-move p6-8) (mine-at p1-2) (mine-at p7-2) (mine-at p3-3) (mine-at p4-3) (mine-at p7-4) (mine-at p1-5) (mine-at p5-5) (mine-at p8-5) (mine-at p2-7) (mine-at p3-8))
    ; minefield: 1 * 1 1 2 3 * 1 1 1 1 1 * * 3 2 0 0 0 1 2 3 * 2 0 0 0 0 0 2 3 * 0 0 0 0 0 2 * 3 1 1 1 0 0 2 * 2 1 * 2 1 0 1 1 1 1 2 * 1 0 0 0 0
    (:hidden (first-move p3-4) (mine-at p2-1) (mine-at p7-1) (mine-at p5-2) (mine-at p6-2) (mine-at p7-3) (mine-at p8-4) (mine-at p7-5) (mine-at p7-6) (mine-at p2-7) (mine-at p3-8))
)

