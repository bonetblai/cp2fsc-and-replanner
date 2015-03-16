(define (problem h16x16)
    ; minefield: 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 1 1 1 0 1 1 2 1 1 1 * 2 1 1 1 0 1 * 1 0 2 * 4 * 3 2 3 * 1 1 * 0 1 1 1 0 3 * 5 * 3 * 3 2 2 2 2 0 0 0 1 1 3 * 3 1 2 1 2 * 2 2 * 0 0 1 2 * 4 4 3 1 0 0 1 2 * 2 1 0 0 1 * 4 * * * 1 0 0 0 1 1 2 1 0 0 1 3 * 5 * 3 1 0 0 0 1 2 3 * 0 0 0 2 * 4 2 1 0 0 0 0 1 * * 2 0 0 0 2 3 * 2 1 0 0 1 1 2 3 3 2 1 1 1 1 * 4 * 2 1 1 1 * 2 2 * 2 2 * 1 1 2 * 2 2 * 1 1 2 * 2 2 * * 3 2 0 2 2 2 1 1 1 0 1 1 1 1 1 2 * 1 0 1 * 1 0 0 0 1 1 2 1 1 0 1 1 1 0 1 1 1 0 0 1 2 * 2 * 1 0 0 0 0 0 0 0 0 0 0 1 * 2 2 1 1 0
    (:hidden (first-move p1-1) (mine-at p12-2) (mine-at p3-3) (mine-at p7-3) (mine-at p9-3) (mine-at p13-3) (mine-at p16-3) (mine-at p7-4) (mine-at p9-4) (mine-at p11-4) (mine-at p7-5) (mine-at p13-5) (mine-at p16-5) (mine-at p5-6) (mine-at p14-6) (mine-at p4-7) (mine-at p6-7) (mine-at p7-7) (mine-at p8-7) (mine-at p5-8) (mine-at p7-8) (mine-at p16-8) (mine-at p5-9) (mine-at p14-9) (mine-at p15-9) (mine-at p6-10) (mine-at p5-11) (mine-at p7-11) (mine-at p12-11) (mine-at p15-11) (mine-at p2-12) (mine-at p6-12) (mine-at p9-12) (mine-at p13-12) (mine-at p16-12) (mine-at p1-13) (mine-at p2-14) (mine-at p6-14) (mine-at p12-15) (mine-at p14-15) (mine-at p11-16))
    ; minefield: 0 1 * 1 2 * 3 1 1 0 2 * 2 1 * 2 1 2 2 1 3 * 4 * 1 1 3 * 2 1 3 * 3 * 3 1 3 * 3 1 1 2 * 5 3 1 2 * * * 4 * 3 2 2 1 1 3 * * * 2 3 2 2 2 3 * 2 1 * 1 1 * 3 3 3 * 3 * 0 0 1 1 1 1 1 1 1 1 1 0 1 2 * 2 0 0 0 0 0 0 1 1 1 0 1 1 1 1 1 1 0 0 0 1 2 2 2 * 1 0 1 * 1 0 0 0 0 0 0 1 * * 2 1 1 0 1 1 1 0 0 0 0 1 1 2 2 2 1 0 0 0 1 2 2 1 0 0 0 1 * 1 0 0 0 0 0 0 1 * * 1 0 0 0 1 1 1 0 0 0 1 1 1 1 2 2 1 0 0 2 3 2 1 0 1 1 2 * 1 0 0 0 0 0 0 * * * 1 0 1 * 2 2 3 2 1 0 0 0 0 2 3 2 1 0 1 1 1 1 * * 3 2 1 0 0 0 0 0 0 0 0 0 0 1 2 3 * * 1 0 0
    (:hidden (first-move p16-15) (mine-at p3-1) (mine-at p6-1) (mine-at p12-1) (mine-at p15-1) (mine-at p6-2) (mine-at p8-2) (mine-at p12-2) (mine-at p16-2) (mine-at p2-3) (mine-at p6-3) (mine-at p11-3) (mine-at p16-3) (mine-at p1-4) (mine-at p2-4) (mine-at p4-4) (mine-at p11-4) (mine-at p12-4) (mine-at p13-4) (mine-at p4-5) (mine-at p7-5) (mine-at p10-5) (mine-at p14-5) (mine-at p16-5) (mine-at p15-6) (mine-at p8-8) (mine-at p12-8) (mine-at p5-9) (mine-at p6-9) (mine-at p3-11) (mine-at p12-11) (mine-at p13-11) (mine-at p9-13) (mine-at p1-14) (mine-at p2-14) (mine-at p3-14) (mine-at p7-14) (mine-at p10-15) (mine-at p11-15) (mine-at p12-16) (mine-at p13-16))
    ; minefield: 0 1 * 1 1 * 2 1 0 1 * * * 1 0 0 1 2 3 2 2 2 * 1 0 2 3 5 3 2 0 0 1 * 2 * 1 1 1 1 0 1 * 2 * 1 1 1 1 2 3 3 2 1 0 0 1 3 3 3 1 2 3 * 0 1 * 2 * 2 1 0 1 * * 3 2 2 * * 1 2 2 2 2 * 1 0 1 2 3 * * 3 2 2 3 * 2 0 1 1 1 0 0 0 1 3 * 2 1 1 * * 2 0 0 0 0 0 0 0 0 1 1 1 1 * * 3 1 0 0 0 0 0 0 1 1 1 1 1 2 1 1 1 0 0 0 0 0 0 0 1 * 2 2 * 1 0 0 0 0 0 0 0 0 0 1 2 3 * 3 2 2 1 0 0 1 2 2 1 0 0 1 * 2 3 * 2 1 * 0 0 2 * * 1 0 0 1 1 1 2 * 4 3 2 0 0 2 * 3 1 0 0 0 0 0 1 2 * * 1 0 0 1 2 2 2 1 1 0 0 0 0 1 2 2 1 0 0 0 1 * 2 * 1 0 0 0 0 0 0 0 0
    (:hidden (first-move p8-11) (mine-at p3-1) (mine-at p6-1) (mine-at p11-1) (mine-at p12-1) (mine-at p13-1) (mine-at p7-2) (mine-at p2-3) (mine-at p4-3) (mine-at p11-3) (mine-at p13-3) (mine-at p16-4) (mine-at p3-5) (mine-at p5-5) (mine-at p10-5) (mine-at p11-5) (mine-at p15-5) (mine-at p16-5) (mine-at p6-6) (mine-at p12-6) (mine-at p13-6) (mine-at p2-7) (mine-at p13-7) (mine-at p1-8) (mine-at p2-8) (mine-at p16-8) (mine-at p1-9) (mine-at p11-10) (mine-at p14-10) (mine-at p12-11) (mine-at p10-12) (mine-at p13-12) (mine-at p16-12) (mine-at p4-13) (mine-at p5-13) (mine-at p13-13) (mine-at p4-14) (mine-at p14-14) (mine-at p15-14) (mine-at p5-16) (mine-at p7-16))
    ; minefield: 1 1 0 0 0 0 0 0 1 1 1 0 0 1 1 1 * 1 0 0 0 0 0 0 1 * 1 0 0 1 * 2 1 1 1 1 1 0 0 1 3 4 3 1 0 1 2 * 1 2 3 * 3 1 0 1 * * * 1 1 1 2 1 * 3 * * * 3 1 2 2 3 2 1 1 * 2 1 2 4 * * * 3 * 2 1 0 0 0 1 1 2 * 1 * 4 * 3 3 4 * 2 0 0 0 1 1 2 1 2 2 4 2 2 1 * * 3 1 2 1 2 * 1 0 1 * 2 * 2 2 3 2 2 * 2 * 2 2 2 1 1 1 2 2 3 * 1 0 1 1 3 2 2 1 * 1 0 0 0 1 * 2 1 0 1 1 3 * 2 1 1 1 0 0 0 1 1 1 0 0 1 * 3 * 2 0 0 0 0 0 0 1 2 2 2 1 2 1 2 2 2 1 0 0 0 0 1 2 * * 2 * 1 0 0 1 * 1 0 0 0 0 1 * 3 2 2 1 1 0 0 1 2 2 1 0 0 0 1 1 1 0 0 0 0 0 0 0 1 * 1 0
    (:hidden (first-move p2-15) (mine-at p1-2) (mine-at p10-2) (mine-at p15-2) (mine-at p16-3) (mine-at p4-4) (mine-at p9-4) (mine-at p10-4) (mine-at p11-4) (mine-at p1-5) (mine-at p3-5) (mine-at p4-5) (mine-at p5-5) (mine-at p14-5) (mine-at p3-6) (mine-at p4-6) (mine-at p5-6) (mine-at p7-6) (mine-at p16-6) (mine-at p2-7) (mine-at p4-7) (mine-at p8-7) (mine-at p7-8) (mine-at p8-8) (mine-at p14-8) (mine-at p2-9) (mine-at p4-9) (mine-at p10-9) (mine-at p12-9) (mine-at p6-10) (mine-at p15-10) (mine-at p5-11) (mine-at p12-11) (mine-at p10-12) (mine-at p12-12) (mine-at p5-14) (mine-at p6-14) (mine-at p8-14) (mine-at p13-14) (mine-at p4-15) (mine-at p14-16))
    ; minefield: 0 0 0 0 0 0 0 1 1 1 0 1 1 2 * 1 0 0 0 0 0 0 0 2 * 2 0 1 * 2 2 2 0 0 0 0 0 0 1 3 * 2 1 2 3 2 3 * 0 0 0 0 0 0 1 * 2 1 1 * 3 * 5 * 1 1 1 0 0 0 1 1 1 0 2 2 4 * * 2 2 * 1 0 0 0 0 0 1 2 3 * 2 3 3 2 * 2 1 0 1 1 1 0 1 * * 2 1 1 * 1 1 1 0 0 1 * 1 0 1 2 2 1 0 1 1 1 0 0 0 0 2 3 3 1 0 0 0 1 1 1 0 0 0 0 1 1 2 * * 2 1 2 3 3 * 1 0 0 0 1 2 * 3 4 * 3 2 * * * 2 1 0 0 0 1 * 3 * 2 3 * 4 5 * 4 1 0 0 0 0 1 1 2 1 1 2 * * 3 * 2 0 0 0 0 1 1 0 0 0 0 1 2 2 2 1 1 0 0 0 0 * 4 2 1 0 1 1 2 1 1 1 1 1 0 0 0 * * * 1 0 1 * 2 * 1 1 * 1 0 0 0
    (:hidden (first-move p4-14) (mine-at p15-1) (mine-at p9-2) (mine-at p13-2) (mine-at p9-3) (mine-at p16-3) (mine-at p8-4) (mine-at p12-4) (mine-at p14-4) (mine-at p16-4) (mine-at p14-5) (mine-at p15-5) (mine-at p2-6) (mine-at p12-6) (mine-at p1-7) (mine-at p10-7) (mine-at p11-7) (mine-at p15-7) (mine-at p6-8) (mine-at p6-10) (mine-at p7-10) (mine-at p13-10) (mine-at p4-11) (mine-at p7-11) (mine-at p10-11) (mine-at p11-11) (mine-at p12-11) (mine-at p3-12) (mine-at p5-12) (mine-at p8-12) (mine-at p11-12) (mine-at p8-13) (mine-at p9-13) (mine-at p11-13) (mine-at p1-15) (mine-at p1-16) (mine-at p2-16) (mine-at p3-16) (mine-at p7-16) (mine-at p9-16) (mine-at p12-16))
    ; minefield: 0 1 1 1 1 1 1 1 1 2 * 1 0 0 0 0 0 1 * 1 1 * 2 2 * 2 1 1 0 0 0 0 1 2 1 2 2 2 3 * 3 1 0 0 1 1 1 0 * 2 1 3 * 3 3 * 2 0 1 1 2 * 1 0 1 2 * 3 * 3 * 2 1 0 1 * 3 2 2 0 0 1 2 3 2 2 1 1 0 0 1 1 2 * 1 0 0 0 1 * 2 1 0 0 0 0 0 0 2 3 3 1 0 0 1 2 * 1 0 0 0 1 1 1 2 * * 1 0 1 2 3 2 1 0 0 0 1 * 1 2 * 3 1 0 1 * * 2 0 0 0 0 2 2 2 1 2 3 2 1 2 5 * 3 0 0 0 1 2 * 1 1 3 * * 1 * 3 * 2 0 0 0 1 * 2 1 1 * * 4 2 2 3 2 3 2 1 0 1 2 2 1 1 2 3 * 1 * 2 2 * * 2 0 0 1 * 1 0 1 2 2 1 2 * 2 3 * 2 0 1 2 2 1 0 1 * 1 0 1 1 1 1 1 1 0 1 * 1 0 0 1 1 1
    (:hidden (first-move p11-3) (mine-at p11-1) (mine-at p3-2) (mine-at p6-2) (mine-at p9-2) (mine-at p8-3) (mine-at p1-4) (mine-at p5-4) (mine-at p8-4) (mine-at p14-4) (mine-at p3-5) (mine-at p5-5) (mine-at p7-5) (mine-at p12-5) (mine-at p14-6) (mine-at p4-7) (mine-at p5-8) (mine-at p14-8) (mine-at p15-8) (mine-at p11-9) (mine-at p14-9) (mine-at p3-10) (mine-at p4-10) (mine-at p4-11) (mine-at p11-11) (mine-at p15-11) (mine-at p16-11) (mine-at p2-12) (mine-at p4-12) (mine-at p10-12) (mine-at p14-12) (mine-at p15-12) (mine-at p16-13) (mine-at p2-14) (mine-at p5-14) (mine-at p6-14) (mine-at p11-14) (mine-at p3-15) (mine-at p6-15) (mine-at p15-15) (mine-at p10-16))
    ; minefield: * 1 0 0 1 1 1 1 * 1 0 1 1 2 * 2 1 1 0 0 1 * 1 2 2 2 0 1 * 3 3 * 1 1 0 1 3 3 2 1 * 1 0 1 1 3 * 3 * 1 1 2 * * 1 2 2 2 0 0 0 2 * 2 1 1 1 * 3 2 1 1 * 2 2 2 1 1 1 1 0 0 2 2 2 0 0 1 2 3 * * 2 1 1 1 0 0 1 * 1 0 0 0 1 * 3 3 * 1 1 * 0 1 2 2 1 1 1 1 1 1 2 3 3 2 1 1 0 1 * 1 0 1 * 1 1 1 2 * * 1 0 0 1 2 1 1 0 2 2 2 1 * 3 3 3 1 0 0 * 1 1 1 1 1 * 2 2 1 2 * 1 0 1 1 1 2 2 * 2 2 2 * 2 1 2 1 1 0 1 * 0 1 * 4 * 2 1 1 3 * 3 1 1 0 1 1 1 2 1 3 * 2 0 0 3 * 4 * 2 1 1 0 * 1 0 1 1 1 0 0 2 * 3 1 2 * 1 0 1 1 0 0 0 0 0 0 1 1 1 0 1 1 1 0
    (:hidden (first-move p14-12) (mine-at p1-1) (mine-at p9-1) (mine-at p15-1) (mine-at p6-2) (mine-at p13-2) (mine-at p16-2) (mine-at p9-3) (mine-at p15-3) (mine-at p1-4) (mine-at p5-4) (mine-at p6-4) (mine-at p15-4) (mine-at p4-5) (mine-at p9-5) (mine-at p11-6) (mine-at p12-6) (mine-at p4-7) (mine-at p10-7) (mine-at p13-7) (mine-at p16-7) (mine-at p3-9) (mine-at p7-9) (mine-at p12-9) (mine-at p13-9) (mine-at p10-10) (mine-at p1-11) (mine-at p7-11) (mine-at p12-11) (mine-at p4-12) (mine-at p8-12) (mine-at p16-12) (mine-at p3-13) (mine-at p5-13) (mine-at p10-13) (mine-at p5-14) (mine-at p10-14) (mine-at p12-14) (mine-at p1-15) (mine-at p10-15) (mine-at p14-15))
    ; minefield: 2 * 2 0 0 0 1 * 3 2 2 * 1 0 0 0 2 * 2 0 0 1 2 3 * * 2 1 1 0 0 0 1 2 3 3 3 4 * 3 2 2 1 0 0 0 1 1 0 2 * * * * * 3 2 2 1 0 0 0 1 * 0 2 * 6 * * 3 2 * * 1 0 0 0 1 1 0 1 2 * 4 3 2 1 2 3 2 2 1 1 0 0 0 0 1 1 2 * 1 1 1 2 * 3 * 3 1 0 0 0 0 0 2 2 2 1 * 2 1 3 * * 1 0 0 0 0 0 1 * 1 1 1 1 0 1 2 2 1 0 0 0 0 1 3 3 2 0 0 0 1 1 1 0 0 0 1 1 1 1 * * 2 1 1 0 1 * 2 2 2 2 1 * 1 1 3 3 3 * 1 0 1 2 * 3 * * 1 1 1 0 1 * 2 1 1 0 0 1 2 * 4 * 1 1 0 0 1 2 2 1 0 0 1 1 2 1 2 1 * 1 0 0 0 1 * 1 0 0 1 * 1 0 0 0 1 1 0 0 0 1 1 1 0 0 1 1 1 0 0 0
    (:hidden (first-move p2-9) (mine-at p2-1) (mine-at p8-1) (mine-at p12-1) (mine-at p2-2) (mine-at p9-2) (mine-at p10-2) (mine-at p7-3) (mine-at p3-4) (mine-at p4-4) (mine-at p5-4) (mine-at p6-4) (mine-at p7-4) (mine-at p16-4) (mine-at p3-5) (mine-at p5-5) (mine-at p6-5) (mine-at p9-5) (mine-at p10-5) (mine-at p4-6) (mine-at p6-7) (mine-at p11-7) (mine-at p13-7) (mine-at p9-8) (mine-at p13-8) (mine-at p14-8) (mine-at p6-9) (mine-at p5-11) (mine-at p6-11) (mine-at p12-11) (mine-at p2-12) (mine-at p8-12) (mine-at p13-12) (mine-at p15-12) (mine-at p16-12) (mine-at p6-13) (mine-at p14-13) (mine-at p16-13) (mine-at p1-15) (mine-at p7-15) (mine-at p12-15))
    ; minefield: 0 1 2 3 2 2 1 2 1 1 0 0 1 * 1 0 0 1 * * * 2 * 2 * 2 2 1 2 1 2 1 0 1 2 3 2 2 1 3 3 * 2 * 1 0 2 * 0 0 0 0 0 0 0 1 * 2 2 1 1 1 3 * 1 1 0 1 1 1 0 2 2 2 1 1 1 1 * 2 * 1 0 2 * 2 0 1 * 1 1 * 3 3 3 2 1 1 0 2 * 2 0 1 1 1 1 2 * * 2 * 1 2 1 2 1 1 0 0 0 1 2 3 4 3 3 1 * 2 * 1 0 1 1 1 0 2 * * 2 * 2 1 1 2 1 1 1 2 * 1 0 2 * 4 3 2 3 * 0 1 2 2 2 * 2 2 1 2 1 2 * 1 2 * 0 2 * * 3 2 2 1 * 1 1 2 2 1 1 1 0 2 * 3 2 * 1 1 1 1 1 * 1 0 0 0 0 1 1 2 2 2 1 1 1 1 1 2 2 1 0 0 0 0 0 1 * 1 0 1 * 1 0 1 * 1 0 0 0 0 0 1 1 1 0 1 1 1 0 1 1 1 0 0
    (:hidden (first-move p9-8) (mine-at p14-1) (mine-at p3-2) (mine-at p4-2) (mine-at p5-2) (mine-at p7-2) (mine-at p9-2) (mine-at p10-3) (mine-at p12-3) (mine-at p16-3) (mine-at p9-4) (mine-at p16-4) (mine-at p15-5) (mine-at p1-6) (mine-at p5-6) (mine-at p9-6) (mine-at p12-6) (mine-at p5-7) (mine-at p13-7) (mine-at p14-7) (mine-at p16-7) (mine-at p1-9) (mine-at p3-9) (mine-at p11-9) (mine-at p12-9) (mine-at p14-9) (mine-at p7-10) (mine-at p11-10) (mine-at p16-10) (mine-at p6-11) (mine-at p13-11) (mine-at p16-11) (mine-at p3-12) (mine-at p4-12) (mine-at p9-12) (mine-at p3-13) (mine-at p6-13) (mine-at p12-13) (mine-at p5-15) (mine-at p9-15) (mine-at p13-15))
    ; minefield: 0 2 * 2 0 0 0 1 * 1 1 1 1 0 1 * 0 2 * 2 0 0 1 2 3 2 3 * 2 1 2 2 0 1 1 1 0 0 1 * 2 * 3 * 2 1 * 1 1 1 0 0 1 1 2 1 3 2 3 1 1 1 1 1 * 1 0 0 1 * 1 0 1 * 1 0 0 0 0 0 1 1 0 0 1 2 3 3 3 2 1 0 1 1 1 0 1 1 1 1 1 2 * * * 2 1 2 2 * 1 0 1 * 1 1 * 2 3 4 3 2 * 3 * 3 1 0 2 2 1 1 1 1 1 * 2 2 2 4 * 4 2 1 * 1 0 0 0 0 1 2 * 1 1 * 3 * * 1 1 1 0 1 1 1 0 2 2 2 1 1 2 3 3 2 1 1 0 1 * 1 0 2 * 2 0 1 2 3 * 1 * 1 0 1 1 1 1 3 * 2 0 1 * * 2 1 1 1 0 0 0 0 2 * 3 1 1 2 3 2 1 0 0 1 1 2 1 1 2 * 3 1 2 * 1 0 0 0 0 1 * 2 * 1 1 1 2 * 2 1 1 0 0 0
    (:hidden (first-move p7-1) (mine-at p3-1) (mine-at p9-1) (mine-at p16-1) (mine-at p3-2) (mine-at p12-2) (mine-at p8-3) (mine-at p10-3) (mine-at p12-3) (mine-at p15-3) (mine-at p1-5) (mine-at p6-5) (mine-at p10-5) (mine-at p7-7) (mine-at p8-7) (mine-at p9-7) (mine-at p14-7) (mine-at p2-8) (mine-at p5-8) (mine-at p11-8) (mine-at p13-8) (mine-at p8-9) (mine-at p13-9) (mine-at p1-10) (mine-at p9-10) (mine-at p12-10) (mine-at p14-10) (mine-at p15-10) (mine-at p5-12) (mine-at p9-12) (mine-at p15-12) (mine-at p1-13) (mine-at p9-13) (mine-at p13-13) (mine-at p14-13) (mine-at p8-14) (mine-at p8-15) (mine-at p12-15) (mine-at p3-16) (mine-at p5-16) (mine-at p10-16))
    ; minefield: 0 1 * 2 1 1 0 0 1 1 2 1 1 0 0 0 0 1 1 2 * 1 0 0 1 * 2 * 2 2 1 1 1 1 2 2 2 1 0 0 1 1 2 3 * 4 * 1 1 * 2 * 1 0 0 0 0 0 0 2 * * 2 1 1 1 2 1 1 0 1 1 1 1 1 2 2 2 1 0 1 1 1 0 0 0 1 * 1 2 * 2 0 1 1 1 1 * 1 0 0 0 1 1 1 2 * 4 2 2 * 2 1 1 1 1 1 1 0 0 0 1 3 * * 4 3 * 0 1 1 2 * 1 1 1 1 0 2 * * 3 * 2 1 2 * 2 1 1 1 * 1 0 1 2 2 2 1 1 * 3 2 1 1 1 3 2 2 0 0 0 0 0 0 0 2 * 1 0 1 * 3 * 3 2 1 1 0 0 0 0 2 2 2 0 1 1 3 * * 2 * 1 1 1 1 0 1 * 2 1 2 1 3 4 4 3 1 1 1 * 1 0 2 3 4 * 2 * 2 * * 2 0 0 1 1 1 0 1 * * 2 2 1 2 3 * 2 0 0 0 0 0 0
    (:hidden (first-move p12-16) (mine-at p3-1) (mine-at p5-2) (mine-at p10-2) (mine-at p12-2) (mine-at p13-3) (mine-at p15-3) (mine-at p2-4) (mine-at p4-4) (mine-at p13-4) (mine-at p14-4) (mine-at p8-6) (mine-at p11-6) (mine-at p2-7) (mine-at p11-7) (mine-at p15-7) (mine-at p12-8) (mine-at p13-8) (mine-at p16-8) (mine-at p5-9) (mine-at p12-9) (mine-at p13-9) (mine-at p15-9) (mine-at p3-10) (mine-at p8-10) (mine-at p1-11) (mine-at p2-12) (mine-at p6-12) (mine-at p8-12) (mine-at p8-13) (mine-at p9-13) (mine-at p11-13) (mine-at p2-14) (mine-at p14-14) (mine-at p4-15) (mine-at p6-15) (mine-at p8-15) (mine-at p9-15) (mine-at p2-16) (mine-at p3-16) (mine-at p9-16))
    ; minefield: 0 1 1 1 0 0 0 2 * 2 1 1 1 0 0 0 0 1 * 1 1 1 1 2 * 2 1 * 2 2 1 1 0 1 1 1 1 * 1 1 1 1 1 2 * 2 * 2 0 0 1 1 2 1 2 1 1 0 0 1 1 2 2 * 0 0 1 * 2 1 1 * 1 1 1 1 0 0 1 1 0 1 2 3 * 2 3 3 2 2 * 2 0 1 1 1 0 1 * 2 2 3 * * 1 2 * 2 1 2 * 1 0 2 2 2 1 * 3 3 3 3 2 1 1 * 3 2 1 2 * 1 1 1 1 1 * * 1 0 1 2 * 1 * 2 1 1 0 1 1 2 2 2 1 0 1 2 2 1 1 1 0 0 0 1 * 2 1 0 0 0 2 * 2 0 0 0 1 1 1 1 2 * 2 1 1 0 2 * 3 1 1 1 2 * 1 0 1 1 3 * 2 0 1 1 2 * 1 * 3 2 3 1 1 0 2 * 2 0 0 0 1 1 2 3 4 * 3 * 1 0 1 1 2 1 2 1 1 0 * 2 * * 3 1 1 0 0 0 1 * 2 * 1 0
    (:hidden (first-move p12-14) (mine-at p9-1) (mine-at p3-2) (mine-at p9-2) (mine-at p12-2) (mine-at p6-3) (mine-at p13-3) (mine-at p15-3) (mine-at p16-4) (mine-at p4-5) (mine-at p8-5) (mine-at p5-6) (mine-at p11-6) (mine-at p3-7) (mine-at p7-7) (mine-at p8-7) (mine-at p11-7) (mine-at p15-7) (mine-at p6-8) (mine-at p14-8) (mine-at p3-9) (mine-at p9-9) (mine-at p10-9) (mine-at p15-9) (mine-at p1-10) (mine-at p7-11) (mine-at p14-11) (mine-at p8-12) (mine-at p14-12) (mine-at p4-13) (mine-at p10-13) (mine-at p16-13) (mine-at p2-14) (mine-at p10-14) (mine-at p4-15) (mine-at p6-15) (mine-at p1-16) (mine-at p3-16) (mine-at p4-16) (mine-at p12-16) (mine-at p14-16))
    ; minefield: 1 1 1 * 2 1 0 0 0 0 1 * 1 1 * 2 * 1 1 2 * 1 0 0 0 0 1 1 1 1 2 * 2 2 0 1 1 2 1 1 1 1 1 0 1 1 2 1 * 1 0 0 0 2 * 2 1 * 2 1 2 * 3 1 1 1 0 0 0 2 * 2 1 2 * 1 2 * 3 * 0 0 0 0 0 1 1 1 0 1 1 1 2 2 3 1 2 2 1 1 2 2 2 2 2 1 0 0 1 * 2 1 * * 1 1 * * 3 * * 1 0 0 1 3 * 2 2 2 1 1 2 2 3 * 3 1 0 0 0 2 * 2 2 2 1 1 2 2 2 1 1 0 0 0 0 1 1 1 * * 1 1 * * 2 2 1 1 0 1 2 2 1 0 2 2 1 1 2 3 * 2 * 1 0 1 * * 1 0 0 0 0 0 0 1 2 3 2 1 0 2 3 3 1 0 1 1 0 1 1 1 1 * 1 0 1 2 * 2 2 1 * 1 0 1 * 1 1 1 1 0 1 * 4 * 3 * 1 1 0 1 1 1 0 0 0 0 1 1 3 * 3 1
    (:hidden (first-move p4-13) (mine-at p4-1) (mine-at p12-1) (mine-at p15-1) (mine-at p1-2) (mine-at p5-2) (mine-at p16-2) (mine-at p1-4) (mine-at p7-4) (mine-at p10-4) (mine-at p14-4) (mine-at p7-5) (mine-at p11-5) (mine-at p14-5) (mine-at p16-5) (mine-at p14-7) (mine-at p1-8) (mine-at p2-8) (mine-at p5-8) (mine-at p6-8) (mine-at p8-8) (mine-at p9-8) (mine-at p15-8) (mine-at p8-9) (mine-at p15-9) (mine-at p1-11) (mine-at p2-11) (mine-at p5-11) (mine-at p6-11) (mine-at p7-12) (mine-at p9-12) (mine-at p13-12) (mine-at p14-12) (mine-at p8-14) (mine-at p13-14) (mine-at p1-15) (mine-at p5-15) (mine-at p12-15) (mine-at p14-15) (mine-at p16-15) (mine-at p14-16))
    ; minefield: 1 1 1 2 * * 2 0 0 1 * 2 * 2 1 0 3 * 2 3 * * 2 0 0 2 2 3 2 * 1 0 * * 2 3 * 4 1 0 0 1 * 2 2 1 1 0 3 3 2 2 * 2 0 0 0 1 3 * 2 0 1 1 1 * 1 1 1 1 0 0 0 0 2 * 2 0 1 * 2 2 3 1 1 0 0 0 0 1 2 2 1 1 2 2 1 * 2 * 1 0 0 0 1 2 * 1 0 2 * 2 1 2 3 3 2 2 1 1 2 * 3 2 1 4 * 3 1 2 * 3 * 2 * 1 2 * 2 2 * 4 * 2 * 3 3 * 2 2 1 1 1 1 1 2 * 3 1 1 2 * 2 1 1 0 0 0 1 1 1 1 1 1 0 0 2 2 1 1 1 1 0 0 1 * 1 0 0 0 0 0 * 2 1 2 * 1 0 0 1 1 1 0 0 0 0 0 1 2 * 2 1 1 0 0 0 0 0 0 1 1 1 0 0 1 2 2 1 0 0 1 1 1 0 0 1 * 1 0 0 0 1 * 1 0 0 1 * 1 0 0 1 1 1 0
    (:hidden (first-move p11-16) (mine-at p5-1) (mine-at p6-1) (mine-at p11-1) (mine-at p13-1) (mine-at p2-2) (mine-at p5-2) (mine-at p6-2) (mine-at p14-2) (mine-at p1-3) (mine-at p2-3) (mine-at p5-3) (mine-at p11-3) (mine-at p5-4) (mine-at p12-4) (mine-at p2-5) (mine-at p12-5) (mine-at p16-5) (mine-at p2-7) (mine-at p4-7) (mine-at p11-7) (mine-at p15-7) (mine-at p10-8) (mine-at p15-8) (mine-at p3-9) (mine-at p5-9) (mine-at p7-9) (mine-at p10-9) (mine-at p13-9) (mine-at p15-9) (mine-at p1-10) (mine-at p4-10) (mine-at p13-10) (mine-at p2-11) (mine-at p10-12) (mine-at p1-13) (mine-at p5-13) (mine-at p3-14) (mine-at p14-15) (mine-at p4-16) (mine-at p9-16))
    ; minefield: 1 * * 1 0 0 0 0 0 0 0 0 0 0 0 0 1 2 2 1 1 1 1 0 0 0 0 0 0 0 1 1 0 0 0 0 1 * 1 0 1 1 1 0 0 0 2 * 1 1 0 0 1 1 1 0 2 * 2 0 0 0 2 * * 3 2 2 1 0 1 1 3 * 2 0 0 0 1 1 * 4 * * 1 0 2 * 5 4 3 1 0 0 0 0 3 * 3 2 1 0 3 * * * * 2 2 2 1 0 * 2 1 0 0 0 2 * 4 3 2 3 * * 1 0 1 2 1 1 0 0 2 2 2 0 0 2 * 3 1 0 0 1 * 2 1 1 1 * 2 2 2 2 2 3 2 1 0 1 1 2 * 1 2 2 4 * * 1 1 * * 2 0 0 0 1 1 1 1 * 4 * 4 2 2 3 3 * 0 0 0 0 0 0 2 3 5 * 2 1 * 1 1 1 0 0 0 1 1 1 1 * * 3 2 1 1 1 0 0 0 0 0 1 * 1 1 2 3 * 1 0 0 1 2 2 0 0 0 1 1 1 0 0 1 1 1 0 0 1 * *
    (:hidden (first-move p15-6) (mine-at p2-1) (mine-at p3-1) (mine-at p6-3) (mine-at p16-3) (mine-at p10-4) (mine-at p16-4) (mine-at p1-5) (mine-at p10-5) (mine-at p1-6) (mine-at p3-6) (mine-at p4-6) (mine-at p8-6) (mine-at p2-7) (mine-at p8-7) (mine-at p9-7) (mine-at p10-7) (mine-at p11-7) (mine-at p1-8) (mine-at p8-8) (mine-at p13-8) (mine-at p14-8) (mine-at p13-9) (mine-at p3-10) (mine-at p8-10) (mine-at p5-11) (mine-at p10-11) (mine-at p11-11) (mine-at p14-11) (mine-at p15-11) (mine-at p8-12) (mine-at p10-12) (mine-at p16-12) (mine-at p10-13) (mine-at p13-13) (mine-at p8-14) (mine-at p9-14) (mine-at p5-15) (mine-at p10-15) (mine-at p15-16) (mine-at p16-16))
    ; minefield: 0 1 * 2 2 * 2 2 * 1 2 * 3 2 1 1 0 1 2 * 3 3 * 2 1 1 2 * * 3 * 1 0 0 1 1 2 * 2 1 0 0 1 3 * 3 1 1 0 0 0 0 1 1 1 1 1 1 0 1 1 1 0 0 1 1 1 0 0 0 0 2 * 2 0 0 1 1 1 0 1 * 1 0 0 1 1 4 * 3 0 0 1 * 1 0 1 1 1 0 0 1 * 3 * 2 0 0 1 1 1 0 0 0 0 0 1 2 2 2 1 1 0 0 0 0 0 0 1 1 0 0 2 * 3 1 1 1 1 0 0 1 1 1 * 1 0 1 3 * * 2 2 * 1 1 1 2 * 1 2 2 1 1 * 3 3 * 2 2 3 3 * 2 2 2 1 * 3 3 2 1 1 1 1 1 * * 3 3 2 * 1 2 * * 1 0 0 1 1 2 3 4 * 2 * 3 0 1 2 3 2 1 0 1 * 1 1 * 2 2 2 * 0 0 0 1 * 1 0 1 2 2 2 1 1 1 2 2 0 0 0 1 1 1 0 0 1 * 1 0 0 1 * 1
    (:hidden (first-move p2-15) (mine-at p3-1) (mine-at p6-1) (mine-at p9-1) (mine-at p12-1) (mine-at p4-2) (mine-at p7-2) (mine-at p12-2) (mine-at p13-2) (mine-at p15-2) (mine-at p6-3) (mine-at p13-3) (mine-at p9-5) (mine-at p2-6) (mine-at p9-6) (mine-at p14-6) (mine-at p7-7) (mine-at p9-7) (mine-at p6-9) (mine-at p1-10) (mine-at p6-10) (mine-at p7-10) (mine-at p10-10) (mine-at p15-10) (mine-at p5-11) (mine-at p8-11) (mine-at p13-11) (mine-at p2-12) (mine-at p11-12) (mine-at p12-12) (mine-at p16-12) (mine-at p3-13) (mine-at p4-13) (mine-at p13-13) (mine-at p15-13) (mine-at p9-14) (mine-at p12-14) (mine-at p16-14) (mine-at p5-15) (mine-at p10-16) (mine-at p15-16))
    ; minefield: * * 2 2 2 2 * 2 * * 2 1 1 * 1 0 2 2 3 * * 2 1 2 2 3 * 2 2 2 1 0 1 1 2 * 3 1 0 0 0 1 1 2 * 1 0 0 * 3 2 2 1 0 0 0 0 0 1 2 2 1 1 1 * 3 * 1 0 0 0 0 0 0 2 * 2 1 2 * 2 3 2 1 0 1 1 1 0 0 2 * 3 2 * 2 1 * 1 0 0 1 * 2 1 1 1 1 2 * 2 1 1 1 1 0 1 2 2 2 * 1 1 1 2 1 1 0 0 0 0 1 2 * 1 1 1 1 1 * 1 0 1 1 0 0 0 1 * 2 1 0 0 0 1 1 1 0 2 * 1 1 0 1 1 1 0 0 0 1 1 1 0 1 3 * * 1 0 1 1 2 1 1 0 2 * 2 0 1 * 2 2 2 0 1 * 2 * 1 0 2 * 2 1 2 2 1 * 2 1 2 3 3 3 2 1 1 1 1 1 * 1 0 * 2 1 * 2 * 2 * 1 1 1 1 1 1 1 0 1 1 1 1 2 1 2 1 1 1 * 1 0 0 0 0
    (:hidden (first-move p6-5) (mine-at p1-1) (mine-at p2-1) (mine-at p7-1) (mine-at p9-1) (mine-at p10-1) (mine-at p14-1) (mine-at p4-2) (mine-at p5-2) (mine-at p11-2) (mine-at p4-3) (mine-at p13-3) (mine-at p1-4) (mine-at p1-5) (mine-at p3-5) (mine-at p12-5) (mine-at p16-5) (mine-at p12-6) (mine-at p15-6) (mine-at p2-7) (mine-at p7-7) (mine-at p14-7) (mine-at p9-8) (mine-at p6-9) (mine-at p12-9) (mine-at p5-10) (mine-at p16-10) (mine-at p16-11) (mine-at p1-12) (mine-at p11-12) (mine-at p15-12) (mine-at p5-13) (mine-at p7-13) (mine-at p11-13) (mine-at p1-14) (mine-at p14-14) (mine-at p1-15) (mine-at p4-15) (mine-at p6-15) (mine-at p8-15) (mine-at p11-16))
    ; minefield: 0 0 0 2 * * 2 2 2 2 * 1 1 * 1 0 0 1 1 4 * 4 2 * * 2 1 1 2 3 3 1 0 1 * 3 * 2 2 3 3 2 1 2 2 * * 1 0 1 2 3 2 1 1 * 1 2 * 3 * 3 3 2 0 1 2 * 1 0 2 2 3 3 * 4 2 2 1 * 0 1 * 3 2 0 2 * 3 * 2 2 * 1 1 1 1 2 2 * 2 1 3 * 3 1 1 1 1 1 0 0 * 1 1 1 2 * 2 1 1 0 0 0 0 0 0 0 2 2 1 0 1 1 2 1 1 0 1 2 2 1 0 0 2 * 1 1 1 1 1 * 2 1 3 * * 1 0 0 * 2 1 1 * 3 3 2 2 * 3 * 4 2 1 0 1 1 0 1 2 * * 1 1 1 2 1 2 * 2 1 0 0 0 0 1 2 2 2 1 1 1 1 2 1 2 * 0 0 0 0 0 0 0 1 * 1 1 * 1 0 1 1 0 0 0 0 0 0 0 1 1 1 1 1 1 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 *
    (:hidden (first-move p4-16) (mine-at p5-1) (mine-at p6-1) (mine-at p11-1) (mine-at p14-1) (mine-at p5-2) (mine-at p8-2) (mine-at p9-2) (mine-at p3-3) (mine-at p5-3) (mine-at p14-3) (mine-at p15-3) (mine-at p8-4) (mine-at p11-4) (mine-at p13-4) (mine-at p4-5) (mine-at p11-5) (mine-at p16-5) (mine-at p3-6) (mine-at p8-6) (mine-at p10-6) (mine-at p13-6) (mine-at p4-7) (mine-at p8-7) (mine-at p1-8) (mine-at p6-8) (mine-at p2-10) (mine-at p8-10) (mine-at p12-10) (mine-at p13-10) (mine-at p1-11) (mine-at p5-11) (mine-at p10-11) (mine-at p12-11) (mine-at p6-12) (mine-at p7-12) (mine-at p14-12) (mine-at p16-13) (mine-at p9-14) (mine-at p12-14) (mine-at p16-16))
    ; minefield: 0 0 1 * 2 1 1 1 1 0 0 0 0 0 1 * 0 0 1 2 * 1 1 * 2 1 1 0 0 0 1 1 1 1 1 1 1 1 1 2 3 * 1 0 0 1 1 1 1 * 1 0 1 1 2 3 * 3 2 1 1 1 * 2 1 1 1 0 1 * 2 * * 2 1 * 1 1 2 * 0 0 0 0 1 1 2 3 3 2 2 2 2 0 2 2 0 0 0 0 1 1 2 3 * 2 1 * 1 0 2 * 0 1 1 2 2 * 2 * * 3 1 2 2 1 3 * 0 1 * 2 * 3 3 4 * 3 0 1 * 2 3 * 0 1 1 2 2 * 1 2 * 2 0 1 2 * 3 2 0 0 1 1 2 2 2 2 2 2 1 1 2 3 3 * 0 0 2 * 3 2 * 1 2 * 2 1 * 2 * 2 0 0 2 * 3 * 2 1 2 * 3 2 2 2 1 1 0 0 1 1 2 1 1 0 1 1 2 * 2 1 1 0 0 0 0 0 0 0 0 0 0 0 1 1 2 * 2 1 0 0 0 0 0 0 0 0 0 0 0 0 1 1 2 *
    (:hidden (first-move p9-15) (mine-at p4-1) (mine-at p16-1) (mine-at p5-2) (mine-at p8-2) (mine-at p10-3) (mine-at p2-4) (mine-at p9-4) (mine-at p15-4) (mine-at p6-5) (mine-at p8-5) (mine-at p9-5) (mine-at p12-5) (mine-at p16-5) (mine-at p9-7) (mine-at p12-7) (mine-at p16-7) (mine-at p6-8) (mine-at p8-8) (mine-at p9-8) (mine-at p16-8) (mine-at p3-9) (mine-at p5-9) (mine-at p9-9) (mine-at p13-9) (mine-at p16-9) (mine-at p6-10) (mine-at p9-10) (mine-at p14-10) (mine-at p16-11) (mine-at p4-12) (mine-at p7-12) (mine-at p10-12) (mine-at p13-12) (mine-at p15-12) (mine-at p4-13) (mine-at p6-13) (mine-at p10-13) (mine-at p12-14) (mine-at p14-15) (mine-at p16-16))
    ; minefield: 0 2 * 2 1 * 2 * 1 1 1 1 0 0 0 0 0 2 * 2 1 1 2 2 3 3 * 1 0 0 1 1 0 1 1 1 0 0 0 1 * * 3 3 1 1 1 * 1 1 1 0 0 0 0 2 3 4 * 2 * 1 1 1 1 * 2 1 1 0 0 1 * 2 1 2 1 1 0 0 2 2 3 * 1 0 0 1 1 1 0 0 0 0 0 0 2 * 4 3 2 0 0 0 0 0 0 1 1 1 0 0 * 4 * * 3 1 1 0 0 0 1 2 * 1 0 0 * 4 4 * 3 * 2 1 1 0 1 * 2 1 0 0 3 * 3 1 2 1 2 * 1 0 1 2 2 2 1 1 2 * 2 0 0 0 2 2 2 0 0 1 * 2 * 1 2 2 2 1 1 2 2 * 1 0 0 2 3 4 2 1 1 * 2 2 * 3 * 3 1 0 0 1 * * 2 1 1 1 3 * 3 3 * 2 0 0 0 1 2 3 * 2 0 1 3 * 2 1 1 1 0 0 1 1 1 1 2 * 0 1 * 2 1 0 0 0 0 0 1 * 1 0 1 1
    (:hidden (first-move p11-14) (mine-at p3-1) (mine-at p6-1) (mine-at p8-1) (mine-at p3-2) (mine-at p11-2) (mine-at p9-3) (mine-at p10-3) (mine-at p16-3) (mine-at p11-4) (mine-at p13-4) (mine-at p2-5) (mine-at p9-5) (mine-at p4-6) (mine-at p2-7) (mine-at p1-8) (mine-at p3-8) (mine-at p4-8) (mine-at p13-8) (mine-at p1-9) (mine-at p4-9) (mine-at p6-9) (mine-at p12-9) (mine-at p2-10) (mine-at p8-10) (mine-at p2-11) (mine-at p13-11) (mine-at p15-11) (mine-at p8-12) (mine-at p2-13) (mine-at p5-13) (mine-at p7-13) (mine-at p13-13) (mine-at p14-13) (mine-at p4-14) (mine-at p7-14) (mine-at p15-14) (mine-at p4-15) (mine-at p16-15) (mine-at p3-16) (mine-at p12-16))
)

