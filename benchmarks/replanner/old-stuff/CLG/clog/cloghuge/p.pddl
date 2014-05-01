


(define (problem logistics-c5-s5-p5-a1)
(:domain logistics_conf)
(:objects a0 
 - AIRPLANE
          c0 c1 c2 c3 c4 
 - CITY
          t0 t1 t2 t3 t4 
 - TRUCK
          l01 l02 l03 l04 l11 l12 l13 l14 l21 l22 l23 l24 l31 l32 l33 l34 l41 l42 l43 l44 
 - LOCATION
          l00 l10 l20 l30 l40 
 - AIRPORT
          p0 p1 p2 p3 p4 
 - OBJ
)
(:init
(in_city_a  l00 c0)
(in_city_l  l01 c0)
(in_city_l  l02 c0)
(in_city_l  l03 c0)
(in_city_l  l04 c0)
(in_city_a  l10 c1)
(in_city_l  l11 c1)
(in_city_l  l12 c1)
(in_city_l  l13 c1)
(in_city_l  l14 c1)
(in_city_a  l20 c2)
(in_city_l  l21 c2)
(in_city_l  l22 c2)
(in_city_l  l23 c2)
(in_city_l  l24 c2)
(in_city_a  l30 c3)
(in_city_l  l31 c3)
(in_city_l  l32 c3)
(in_city_l  l33 c3)
(in_city_l  l34 c3)
(in_city_a  l40 c4)
(in_city_l  l41 c4)
(in_city_l  l42 c4)
(in_city_l  l43 c4)
(in_city_l  l44 c4)
(in_city_t t0 c0)
(at_tl t0 l03)
(in_city_t t1 c1)
(at_tl t1 l11)
(in_city_t t2 c2)
(at_tl t2 l22)
(in_city_t t3 c3)
(at_ta t3 l30)
(in_city_t t4 c4)
(at_tl t4 l43)
(at_aa a0 l00)

(unknown (at_oa p0 l00))
(unknown (at_ol p0 l01))
(unknown (at_ol p0 l02))
(unknown (at_ol p0 l03))
(unknown (at_ol p0 l04))
(oneof
   (at_oa p0 l00)
   (at_ol p0 l01)
   (at_ol p0 l02)
   (at_ol p0 l03)
   (at_ol p0 l04)
)

(unknown (at_oa p1 l20))
(unknown (at_ol p1 l21))
(unknown (at_ol p1 l22))
(unknown (at_ol p1 l23))
(unknown (at_ol p1 l24))
(oneof
   (at_oa p1 l20)
   (at_ol p1 l21)
   (at_ol p1 l22)
   (at_ol p1 l23)
   (at_ol p1 l24)
)

(unknown (at_oa p2 l10))
(unknown (at_ol p2 l11))
(unknown (at_ol p2 l12))
(unknown (at_ol p2 l13))
(unknown (at_ol p2 l14))
(oneof
   (at_oa p2 l10)
   (at_ol p2 l11)
   (at_ol p2 l12)
   (at_ol p2 l13)
   (at_ol p2 l14)
)

(unknown (at_oa p3 l20))
(unknown (at_ol p3 l21))
(unknown (at_ol p3 l22))
(unknown (at_ol p3 l23))
(unknown (at_ol p3 l24))
(oneof
   (at_oa p3 l20)
   (at_ol p3 l21)
   (at_ol p3 l22)
   (at_ol p3 l23)
   (at_ol p3 l24)
)

(unknown (at_oa p4 l40))
(unknown (at_ol p4 l41))
(unknown (at_ol p4 l42))
(unknown (at_ol p4 l43))
(unknown (at_ol p4 l44))
(oneof
   (at_oa p4 l40)
   (at_ol p4 l41)
   (at_ol p4 l42)
   (at_ol p4 l43)
   (at_ol p4 l44)
)
)
(:goal
(and
(at_oa p0 l10)
(at_ol p1 l12)
(at_ol p2 l11)
(at_ol p3 l32)
(at_ol p4 l42)
)
)
)


