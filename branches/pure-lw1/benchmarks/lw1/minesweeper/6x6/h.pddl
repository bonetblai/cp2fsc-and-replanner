(define (problem h6x6)
    ; minefield: 0 0 1 * * 1 0 0 1 2 2 1 1 1 0 0 1 1 * 1 0 0 1 * 1 2 1 1 2 2 0 1 * 1 1 *
    (:hidden (first-move p2-1) (mine-at p4-1) (mine-at p5-1) (mine-at p1-4) (mine-at p6-4) (mine-at p3-6) (mine-at p6-6))
    ; minefield: * 1 0 1 * 1 1 1 0 1 1 1 1 1 1 1 1 0 * 1 1 * 1 0 2 2 2 2 2 0 * 1 1 * 1 0
    (:hidden (first-move p3-2) (mine-at p1-1) (mine-at p5-1) (mine-at p1-4) (mine-at p4-4) (mine-at p1-6) (mine-at p4-6))
    ; minefield: 0 0 1 * 1 0 0 0 1 1 1 0 1 1 1 0 0 0 2 * 2 1 1 0 * 3 3 * 2 1 2 * 2 2 * 1
    (:hidden (first-move p2-2) (mine-at p4-1) (mine-at p2-4) (mine-at p1-5) (mine-at p4-5) (mine-at p2-6) (mine-at p5-6))
    ; minefield: * 1 2 * 2 0 1 1 2 * 2 0 0 0 1 1 2 1 1 1 0 0 2 * * 1 0 0 2 * 1 1 0 0 1 1
    (:hidden (first-move p3-6) (mine-at p1-1) (mine-at p4-1) (mine-at p4-2) (mine-at p6-4) (mine-at p1-5) (mine-at p6-5))
    ; minefield: * * 1 0 0 0 2 2 2 1 1 0 0 0 1 * 1 0 1 1 2 1 1 0 2 * 3 1 0 0 2 * * 1 0 0
    (:hidden (first-move p6-4) (mine-at p1-1) (mine-at p2-1) (mine-at p4-3) (mine-at p2-5) (mine-at p2-6) (mine-at p3-6))
    ; minefield: 0 1 * 1 0 0 0 2 2 2 1 1 0 2 * 2 1 * 0 2 * 2 1 1 0 2 2 3 1 1 0 1 * 2 * 1
    (:hidden (first-move p1-1) (mine-at p3-1) (mine-at p3-3) (mine-at p6-3) (mine-at p3-4) (mine-at p3-6) (mine-at p5-6))
    ; minefield: 1 * 1 0 1 * 1 1 1 0 1 1 1 1 1 0 0 0 1 * 1 0 1 1 1 2 2 2 2 * 0 1 * 2 * 2
    (:hidden (first-move p4-1) (mine-at p2-1) (mine-at p6-1) (mine-at p2-4) (mine-at p6-5) (mine-at p3-6) (mine-at p5-6))
    ; minefield: 1 1 0 1 2 2 * 1 0 1 * * 2 2 1 3 4 3 * 1 1 * * 1 1 1 1 2 2 1 0 0 0 0 0 0
    (:hidden (first-move p3-1) (mine-at p1-2) (mine-at p5-2) (mine-at p6-2) (mine-at p1-4) (mine-at p4-4) (mine-at p5-4))
    ; minefield: * * 1 0 0 0 2 2 1 0 0 0 1 1 0 1 1 1 * 1 0 2 * 3 1 1 0 2 * * 0 0 0 1 2 2
    (:hidden (first-move p1-6) (mine-at p1-1) (mine-at p2-1) (mine-at p1-4) (mine-at p5-4) (mine-at p5-5) (mine-at p6-5))
    ; minefield: 1 1 1 1 1 1 1 * 1 2 * 2 1 1 1 3 * 3 0 0 0 2 * 2 0 1 1 2 2 2 0 1 * 1 1 *
    (:hidden (first-move p2-4) (mine-at p2-2) (mine-at p5-2) (mine-at p5-3) (mine-at p5-4) (mine-at p3-6) (mine-at p6-6))
    ; minefield: 1 * 2 * 1 0 1 1 2 1 1 0 2 2 2 1 1 0 * * 2 * 1 0 3 3 3 1 1 0 1 * 1 0 0 0
    (:hidden (first-move p5-6) (mine-at p2-1) (mine-at p4-1) (mine-at p1-4) (mine-at p2-4) (mine-at p4-4) (mine-at p2-6))
    ; minefield: * 1 0 1 * 1 1 1 0 1 1 1 0 1 2 3 2 1 0 1 * * * 1 0 1 2 3 3 2 0 0 0 0 1 *
    (:hidden (first-move p3-2) (mine-at p1-1) (mine-at p5-1) (mine-at p3-4) (mine-at p4-4) (mine-at p5-4) (mine-at p6-6))
    ; minefield: 0 0 0 1 * 2 1 1 1 1 2 * 2 * 2 0 1 1 2 * 2 0 0 0 1 1 2 1 2 1 0 0 1 * 2 *
    (:hidden (first-move p4-3) (mine-at p5-1) (mine-at p6-2) (mine-at p2-3) (mine-at p2-4) (mine-at p4-6) (mine-at p6-6))
    ; minefield: 0 2 * 2 0 0 0 2 * 2 0 0 2 3 3 2 1 0 * * 2 * 1 0 2 2 2 1 2 1 0 0 0 0 1 *
    (:hidden (first-move p5-2) (mine-at p3-1) (mine-at p3-2) (mine-at p1-4) (mine-at p2-4) (mine-at p4-4) (mine-at p6-6))
    ; minefield: 1 1 1 0 0 0 1 * 2 1 1 0 1 1 2 * 1 0 1 1 1 1 2 1 * 2 1 0 2 * 2 * 1 0 2 *
    (:hidden (first-move p6-3) (mine-at p2-2) (mine-at p4-3) (mine-at p1-5) (mine-at p6-5) (mine-at p2-6) (mine-at p6-6))
    ; minefield: * * 3 * 1 0 4 * 4 1 1 0 2 * 2 0 0 0 1 1 1 0 1 1 0 0 0 0 1 * 0 0 0 0 1 1
    (:hidden (first-move p4-3) (mine-at p1-1) (mine-at p2-1) (mine-at p4-1) (mine-at p2-2) (mine-at p2-3) (mine-at p6-5))
    ; minefield: 1 2 2 2 * * 1 * * 2 4 * 1 2 2 1 2 * 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0
    (:hidden (first-move p2-5) (mine-at p5-1) (mine-at p6-1) (mine-at p2-2) (mine-at p3-2) (mine-at p6-2) (mine-at p6-3))
    ; minefield: * 1 0 0 0 0 1 1 0 0 1 1 0 0 0 0 2 * 0 0 1 2 5 * 0 0 1 * * * 0 0 1 2 3 2
    (:hidden (first-move p2-5) (mine-at p1-1) (mine-at p6-3) (mine-at p6-4) (mine-at p4-5) (mine-at p5-5) (mine-at p6-5))
    ; minefield: 1 1 2 1 1 0 1 * 2 * 1 0 1 2 3 2 2 1 0 1 * 2 3 * 0 1 1 2 * * 0 0 0 1 2 2
    (:hidden (first-move p1-5) (mine-at p2-2) (mine-at p4-2) (mine-at p3-4) (mine-at p6-4) (mine-at p5-5) (mine-at p6-5))
    ; minefield: 0 0 0 1 1 1 0 0 0 1 * 1 0 1 2 3 2 1 1 2 * * 3 2 * 2 2 3 * * 1 1 0 1 2 2
    (:hidden (first-move p3-1) (mine-at p5-2) (mine-at p3-4) (mine-at p4-4) (mine-at p1-5) (mine-at p5-5) (mine-at p6-5))
)

