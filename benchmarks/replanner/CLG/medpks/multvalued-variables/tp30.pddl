(define (problem med-30)
    (:domain medical)
    (:constants i1 i2 i3 i4 i5 i6 i7 i8 i9 i10 i11 i12 i13 i14 i15 i16 i17 i18 i19 i20 i21 i22 i23 i24 i25 i26 i27 i28 i29 i30 - ILLNESS)
    (:init (not (dead)))
    (:hidden (ill i20))
    (:goal (cured))
)

