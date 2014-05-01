;; Minefield:
;; 0 0 0     row=1
;; 2 2 1     row=2
;; * * 1     row=3
;; 2 2 1     row=4

(define (domain mines-3x4)
    (:requirements :strips :typing)
    (:types pos num)
    (:predicates
        (need-start)                           ; for very first action
        (ok)                                   ; ready for next action
        (need-advance-step)                    ; need to advance step counter
        (mine-at ?p - pos)                     ; location of mines (hidden)
        (done-with ?p - pos)                   ; this is set by (put-flag ?p) and (open-cell ?p)
        (obs0-at ?p - pos) (obs1-at ?p - pos) (obs2-at ?p - pos)
        (obs3-at ?p - pos) (obs4-at ?p - pos) (obs5-at ?p - pos)
        (obs6-at ?p - pos) (obs7-at ?p - pos) (obs8-at ?p - pos)
        (at-step ?n - num)                     ; sequencing of steps
        (need-gather-obs0-at ?p - pos)         ; sequencing of observation
        (need-gather-obs1-at ?p - pos)         ; sequencing of observation
        (need-gather-obs2-at ?p - pos)         ; sequencing of observation
        (need-gather-obs3-at ?p - pos)         ; sequencing of observation
        (need-gather-obs4-at ?p - pos)         ; sequencing of observation
        (need-gather-obs5-at ?p - pos)         ; sequencing of observation
        (need-gather-obs6-at ?p - pos)         ; sequencing of observation
        (need-gather-obs7-at ?p - pos)         ; sequencing of observation
        (need-gather-obs8-at ?p - pos)         ; sequencing of observation
    )
    (:constants
        p1_1 p2_1 p3_1 p1_2 p2_2 p3_2 p1_3 p2_3 p3_3 p1_4 p2_4 p3_4 - pos
        n0 n1 n2 n3 n4 n5 n6 n7 n8 n9 n10 n11 - num
    )

    ;; Advance step counter
    (:action advance-step
        :precondition (need-advance-step)
        :effect
            (and (not (need-advance-step)) (ok)
                 (when (at-step n0) (and (not (at-step n0)) (at-step n1)))
                 (when (at-step n1) (and (not (at-step n1)) (at-step n2)))
                 (when (at-step n2) (and (not (at-step n2)) (at-step n3)))
                 (when (at-step n3) (and (not (at-step n3)) (at-step n4)))
                 (when (at-step n4) (and (not (at-step n4)) (at-step n5)))
                 (when (at-step n5) (and (not (at-step n5)) (at-step n6)))
                 (when (at-step n6) (and (not (at-step n6)) (at-step n7)))
                 (when (at-step n7) (and (not (at-step n7)) (at-step n8)))
                 (when (at-step n8) (and (not (at-step n8)) (at-step n9)))
                 (when (at-step n9) (and (not (at-step n9)) (at-step n10)))
                 (when (at-step n10) (and (not (at-step n10)) (at-step n11)))
            )
    )

    ;; Gather observations
    (:action gather-obs0
        :parameters (?p - pos)
        :precondition (need-gather-obs0-at ?p)
        :observe (obs0-at ?p)
    )
    (:action gather-obs1
        :parameters (?p - pos)
        :precondition (need-gather-obs1-at ?p)
        :observe (obs1-at ?p)
    )
    (:action gather-obs2
        :parameters (?p - pos)
        :precondition (need-gather-obs2-at ?p)
        :observe (obs2-at ?p)
    )
    (:action gather-obs3
        :parameters (?p - pos)
        :precondition (need-gather-obs3-at ?p)
        :observe (obs3-at ?p)
    )
    (:action gather-obs4
        :parameters (?p - pos)
        :precondition (need-gather-obs4-at ?p)
        :observe (obs4-at ?p)
    )
    (:action gather-obs5
        :parameters (?p - pos)
        :precondition (need-gather-obs5-at ?p)
        :observe (obs5-at ?p)
    )
    (:action gather-obs6
        :parameters (?p - pos)
        :precondition (need-gather-obs6-at ?p)
        :observe (obs6-at ?p)
    )
    (:action gather-obs7
        :parameters (?p - pos)
        :precondition (need-gather-obs7-at ?p)
        :observe (obs7-at ?p)
    )
    (:action gather-obs8
        :parameters (?p - pos)
        :precondition (need-gather-obs8-at ?p)
        :observe (obs8-at ?p)
    )

    (:action advance-gather-counter
        :parameters (?p - pos)
        :effect (and (when (need-gather-obs0-at ?p) (and (not (need-gather-obs0-at ?p)) (need-gather-obs1-at ?p)))
                     (when (need-gather-obs1-at ?p) (and (not (need-gather-obs1-at ?p)) (need-gather-obs2-at ?p)))
                     (when (need-gather-obs2-at ?p) (and (not (need-gather-obs2-at ?p)) (need-gather-obs3-at ?p)))
                     (when (need-gather-obs3-at ?p) (and (not (need-gather-obs3-at ?p)) (need-gather-obs4-at ?p)))
                     (when (need-gather-obs4-at ?p) (and (not (need-gather-obs4-at ?p)) (need-gather-obs5-at ?p)))
                     (when (need-gather-obs5-at ?p) (and (not (need-gather-obs5-at ?p)) (need-gather-obs6-at ?p)))
                     (when (need-gather-obs6-at ?p) (and (not (need-gather-obs6-at ?p)) (need-gather-obs7-at ?p)))
                     (when (need-gather-obs7-at ?p) (and (not (need-gather-obs7-at ?p)) (need-gather-obs8-at ?p)))
                     (when (need-gather-obs8-at ?p) (and (not (need-gather-obs8-at ?p)) (need-advance-step)))
                )
    )

    ;; Actions at each step
    (:action start-action
        :precondition (need-start)
        :effect (and (not (need-start)) (ok) (at-step n0) (not (mine-at p1_1)))
    )
    (:action open-cell-at-step0     ; cell=(1,1)
        :precondition (and (ok) (at-step n0) (not (mine-at p1_1)))
        :effect (and (not (ok)) (need-gather-obs0-at p1_1) (done-with p1_1))
    )
    (:action open-cell-at-step1     ; cell=(2,2)
        :precondition (and (ok) (at-step n1) (not (mine-at p2_2)))
        :effect (and (not (ok)) (need-gather-obs0-at p2_2) (done-with p2_2))
    )
    (:action open-cell-at-step2     ; cell=(2,1)
        :precondition (and (ok) (at-step n2) (not (mine-at p2_1)))
        :effect (and (not (ok)) (need-gather-obs0-at p2_1) (done-with p2_1))
    )
    (:action open-cell-at-step3     ; cell=(3,2)
        :precondition (and (ok) (at-step n3) (not (mine-at p3_2)))
        :effect (and (not (ok)) (need-gather-obs0-at p3_2) (done-with p3_2))
    )
    (:action put-flag-at-step4      ; cell=(1,3)
        :precondition (and (ok) (at-step n4) (mine-at p1_3))
        :effect (and (not (ok)) (need-advance-step) (done-with p1_3))
    )
    (:action open-cell-at-step5     ; cell=(3,1)
        :precondition (and (ok) (at-step n5) (not (mine-at p3_1)))
        :effect (and (not (ok)) (need-gather-obs0-at p3_1) (done-with p3_1))
    )
    (:action open-cell-at-step6     ; cell=(1,2)
        :precondition (and (ok) (at-step n6) (not (mine-at p1_2)))
        :effect (and (not (ok)) (need-gather-obs0-at p1_2) (done-with p1_2))
    )
    (:action put-flag-at-step7      ; cell=(2,3)
        :precondition (and (ok) (at-step n7) (mine-at p2_3))
        :effect (and (not (ok)) (need-advance-step) (done-with p2_3))
    )
    (:action open-cell-at-step8     ; cell=(3,3)
        :precondition (and (ok) (at-step n8) (not (mine-at p3_3)))
        :effect (and (not (ok)) (need-gather-obs0-at p3_3) (done-with p3_3))
    )
    (:action open-cell-at-step9     ; cell=(3,4)
        :precondition (and (ok) (at-step n9) (not (mine-at p3_4)))
        :effect (and (not (ok)) (need-gather-obs0-at p3_4) (done-with p3_4))
    )
    (:action open-cell-at-step10     ; cell=(2,4)
        :precondition (and (ok) (at-step n10) (not (mine-at p2_4)))
        :effect (and (not (ok)) (need-gather-obs0-at p2_4) (done-with p2_4))
    )
    (:action open-cell-at-step11     ; cell=(1,4)
        :precondition (and (ok) (at-step n11) (not (mine-at p1_4)))
        :effect (and (not (ok)) (need-gather-obs0-at p1_4) (done-with p1_4))
    )
)

