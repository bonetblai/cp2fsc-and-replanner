(define (problem med-10)
    (:domain medical)
    (:constants i1 i2 i3 i4 i5 i6 i7 i8 i9 i10 - ILLNESS)
    (:init (not (dead)))
    (:hidden (ill i7))
    (:goal (cured))
)

