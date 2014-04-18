(define (domain blocks)
  (:types block)
  (:predicates (on ?x ?y - block)
               (ontable ?x - block)
               (clear ?x - block)
               (hold ?x - block)
               (green ?x - block)
               (have ?x - block)
               (empty)
               (table-exposed)
               (finished)
               (holding) (not-holding)
               (greenish) (not-greenish)
               (empty-tower)
               (got-it)
  )

  (:action unstack
    :effect
      (forall (?x ?y - block)
        (and (when (and (not (finished)) (clear ?x) (on ?x ?y) (empty))
               (and (hold ?x) (clear ?y) (not (clear ?x))
                    (not (on ?x ?y)) (not (empty)))
             )
             (when (and (not (finished)) (clear ?x) (ontable ?x) (empty))
               (and (hold ?x) (table-exposed) (not (clear ?x))
                    (not (ontable ?x)) (not (empty)))
             )
        )
      )
  )
  (:action drop
    :effect
      (forall (?x - block)
        (when (and (not (finished)) (hold ?x))
          (and (empty) (not (hold ?x))))
      )
  )
  (:action collect
    :effect
      (forall (?x - block)
        (when (and (not (finished)) (hold ?x))
          (and (have ?x) (empty) (finished) (not (hold ?x))))
      )
  )

  (:axiom set-holding0
    :parameters (?x - block)
    :body (hold ?x)
    :head (holding))
  (:axiom set-holding1
    :body (empty)
    :head (not-holding))
  (:axiom set-green0
    :parameters (?x - block)
    :body (and (clear ?x) (green ?x))
    :head (greenish))
  (:axiom set-green1
    :parameters (?x - block)
    :body (and (clear ?x) (not (green ?x)))
    :head (not-greenish))
  (:axiom set-table
    :body (table-exposed)
    :head (empty-tower))
  (:axiom set-goal
    :parameters (?x - block)
    :body (and (have ?x) (green ?x))
    :head (got-it))

  (:observable (holding) (not-holding) (greenish) (not-greenish) (empty-tower))
)

