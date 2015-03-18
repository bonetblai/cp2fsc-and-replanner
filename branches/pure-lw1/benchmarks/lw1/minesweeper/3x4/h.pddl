(define (problem h3x4)
    ; minefield: 0 0 0 2 2 1 * * 1 2 2 1
    (:hidden (first-move p1-1) (mine-at p1-3) (mine-at p2-3))
    ; minefield: 0 0 0 0 0 0 1 2 1 * 2 *
    (:hidden (first-move p2-2) (mine-at p1-4) (mine-at p3-4))
    ; minefield: 0 0 0 0 1 1 1 2 * 1 * 2
    (:hidden (first-move p1-2) (mine-at p3-3) (mine-at p2-4))
    ; minefield: 0 0 0 0 0 0 1 2 1 * 2 *
    (:hidden (first-move p2-2) (mine-at p1-4) (mine-at p3-4))
    ; minefield: 0 1 * 1 2 1 * 1 0 1 1 0
    (:hidden (first-move p3-3) (mine-at p3-1) (mine-at p1-3))
    ; minefield: 0 0 0 0 0 0 1 2 2 1 * *
    (:hidden (first-move p3-2) (mine-at p2-4) (mine-at p3-4))
    ; minefield: 0 0 0 0 1 1 0 2 * 0 2 *
    (:hidden (first-move p2-1) (mine-at p3-3) (mine-at p3-4))
    ; minefield: * 2 1 1 2 * 0 1 1 0 0 0
    (:hidden (first-move p1-3) (mine-at p1-1) (mine-at p3-2))
    ; minefield: 1 * * 1 2 2 0 0 0 0 0 0
    (:hidden (first-move p2-3) (mine-at p2-1) (mine-at p3-1))
    ; minefield: 0 0 0 2 2 1 * * 1 2 2 1
    (:hidden (first-move p2-1) (mine-at p1-3) (mine-at p2-3))
    ; minefield: * * 1 2 2 1 0 0 0 0 0 0
    (:hidden (first-move p2-3) (mine-at p1-1) (mine-at p2-1))
    ; minefield: * 2 * 1 2 1 0 0 0 0 0 0
    (:hidden (first-move p2-3) (mine-at p1-1) (mine-at p3-1))
    ; minefield: * 2 0 * 2 0 1 1 0 0 0 0
    (:hidden (first-move p3-3) (mine-at p1-1) (mine-at p1-2))
    ; minefield: 0 1 * 0 1 1 1 1 1 1 * 1
    (:hidden (first-move p1-2) (mine-at p3-1) (mine-at p2-4))
    ; minefield: 1 * * 1 2 2 0 0 0 0 0 0
    (:hidden (first-move p2-3) (mine-at p2-1) (mine-at p3-1))
    ; minefield: 1 2 * * 2 1 1 1 0 0 0 0
    (:hidden (first-move p3-3) (mine-at p3-1) (mine-at p1-2))
    ; minefield: 0 0 0 1 2 1 * 2 * 1 2 1
    (:hidden (first-move p1-1) (mine-at p1-3) (mine-at p3-3))
    ; minefield: 0 0 0 1 1 0 * 2 0 * 2 0
    (:hidden (first-move p2-1) (mine-at p1-3) (mine-at p1-4))
    ; minefield: * 1 0 1 1 0 0 1 1 0 1 *
    (:hidden (first-move p3-2) (mine-at p1-1) (mine-at p3-4))
    ; minefield: * 1 0 1 1 0 1 1 0 * 1 0
    (:hidden (first-move p3-3) (mine-at p1-1) (mine-at p1-4))
)

