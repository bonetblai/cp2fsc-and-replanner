(define (problem logistics-c5-s5-p5-a1)
    (:domain logistics_conf)
    ;(:requirements :strips :equality :typing :conditional-effects :disjunctive-preconditions)			
    (:objects
        p0 p1 p2 p3 p4 - OBJ
        t0 t1 t2 t3 t4 - TRUCK
        a0 - AIRPLANE
        l01 l02 l03 l04
        l11 l12 l13 l14
        l21 l22 l23 l24
        l31 l32 l33 l34
        l41 l42 l43 l44 - LOCATION
        l00 l10 l20 l30 l40 - AIRPORT
        c0 c1 c2 c3 c4 - CITY
    )
    (:init 
        (in_city_a l00 c0)
        (in_city_l l01 c0)
        (in_city_l l02 c0)
        (in_city_l l03 c0)
        (in_city_l l04 c0)
        (in_city_a l10 c1)
        (in_city_l l11 c1)
        (in_city_l l12 c1)
        (in_city_l l13 c1)
        (in_city_l l14 c1)
        (in_city_a l20 c2)
        (in_city_l l21 c2)
        (in_city_l l22 c2)
        (in_city_l l23 c2)
        (in_city_l l24 c2)
        (in_city_a l30 c3)
        (in_city_l l31 c3)
        (in_city_l l32 c3)
        (in_city_l l33 c3)
        (in_city_l l34 c3)
        (in_city_a l40 c4)
        (in_city_l l41 c4)
        (in_city_l l42 c4)
        (in_city_l l43 c4)
        (in_city_l l44 c4)

        (in_city_t t0 c0)
        (in_city_t t1 c1)
        (in_city_t t2 c2)
        (in_city_t t3 c3)
        (in_city_t t4 c4)

        (at_tl t0 l03)
        (at_tl t1 l11)
        (at_tl t2 l22)
        (at_ta t3 l30)
        (at_tl t4 l43)
        (at_aa a0 l00)

        (not (at_oa p0 l10))
        (not (at_ol p0 l11))
        (not (at_ol p0 l12))
        (not (at_ol p0 l13))
        (not (at_ol p0 l14))
        (not (at_oa p0 l20))
        (not (at_ol p0 l21))
        (not (at_ol p0 l22))
        (not (at_ol p0 l23))
        (not (at_ol p0 l24))
        (not (at_oa p0 l30))
        (not (at_ol p0 l31))
        (not (at_ol p0 l32))
        (not (at_ol p0 l33))
        (not (at_ol p0 l34))
        (not (at_oa p0 l40))
        (not (at_ol p0 l41))
        (not (at_ol p0 l42))
        (not (at_ol p0 l43))
        (not (at_ol p0 l44))
        (not (in_ot p0 t0))
        (not (in_ot p0 t1))
        (not (in_ot p0 t2))
        (not (in_ot p0 t3))
        (not (in_ot p0 t4))
        (not (in_oa p0 a0))

        (not (at_oa p1 l00))
        (not (at_ol p1 l01))
        (not (at_ol p1 l02))
        (not (at_ol p1 l03))
        (not (at_ol p1 l04))
        (not (at_oa p1 l10))
        (not (at_ol p1 l11))
        (not (at_ol p1 l12))
        (not (at_ol p1 l13))
        (not (at_ol p1 l14))
        (not (at_oa p1 l30))
        (not (at_ol p1 l31))
        (not (at_ol p1 l32))
        (not (at_ol p1 l33))
        (not (at_ol p1 l34))
        (not (at_oa p1 l40))
        (not (at_ol p1 l41))
        (not (at_ol p1 l42))
        (not (at_ol p1 l43))
        (not (at_ol p1 l44))
        (not (in_ot p1 t0))
        (not (in_ot p1 t1))
        (not (in_ot p1 t2))
        (not (in_ot p1 t3))
        (not (in_ot p1 t4))
        (not (in_oa p1 a0))

        (not (at_oa p2 l00))
        (not (at_ol p2 l01))
        (not (at_ol p2 l02))
        (not (at_ol p2 l03))
        (not (at_ol p2 l04))
        (not (at_oa p2 l20))
        (not (at_ol p2 l21))
        (not (at_ol p2 l22))
        (not (at_ol p2 l23))
        (not (at_ol p2 l24))
        (not (at_oa p2 l30))
        (not (at_ol p2 l31))
        (not (at_ol p2 l32))
        (not (at_ol p2 l33))
        (not (at_ol p2 l34))
        (not (at_oa p2 l40))
        (not (at_ol p2 l41))
        (not (at_ol p2 l42))
        (not (at_ol p2 l43))
        (not (at_ol p2 l44))
        (not (in_ot p2 t0))
        (not (in_ot p2 t1))
        (not (in_ot p2 t2))
        (not (in_ot p2 t3))
        (not (in_ot p2 t4))
        (not (in_oa p2 a0))

        (not (at_oa p3 l00))
        (not (at_ol p3 l01))
        (not (at_ol p3 l02))
        (not (at_ol p3 l03))
        (not (at_ol p3 l04))
        (not (at_oa p3 l10))
        (not (at_ol p3 l11))
        (not (at_ol p3 l12))
        (not (at_ol p3 l13))
        (not (at_ol p3 l14))
        (not (at_oa p3 l30))
        (not (at_ol p3 l31))
        (not (at_ol p3 l32))
        (not (at_ol p3 l33))
        (not (at_ol p3 l34))
        (not (at_oa p3 l40))
        (not (at_ol p3 l41))
        (not (at_ol p3 l42))
        (not (at_ol p3 l43))
        (not (at_ol p3 l44))
        (not (in_ot p3 t0))
        (not (in_ot p3 t1))
        (not (in_ot p3 t2))
        (not (in_ot p3 t3))
        (not (in_ot p3 t4))
        (not (in_oa p3 a0))

        (not (at_oa p4 l00))
        (not (at_ol p4 l01))
        (not (at_ol p4 l02))
        (not (at_ol p4 l03))
        (not (at_ol p4 l04))
        (not (at_oa p4 l10))
        (not (at_ol p4 l11))
        (not (at_ol p4 l12))
        (not (at_ol p4 l13))
        (not (at_ol p4 l14))
        (not (at_oa p4 l20))
        (not (at_ol p4 l21))
        (not (at_ol p4 l22))
        (not (at_ol p4 l23))
        (not (at_ol p4 l24))
        (not (at_oa p4 l30))
        (not (at_ol p4 l31))
        (not (at_ol p4 l32))
        (not (at_ol p4 l33))
        (not (at_ol p4 l34))
        (not (in_ot p4 t0))
        (not (in_ot p4 t1))
        (not (in_ot p4 t2))
        (not (in_ot p4 t3))
        (not (in_ot p4 t4))
        (not (in_oa p4 a0))
    )
    (:goal (and (at_oa p0 l10) (at_ol p1 l12) (at_ol p2 l11) (at_ol p3 l32) (at_ol p4 l42)))
)

