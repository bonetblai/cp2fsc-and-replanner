(define (problem att-log0) 
    (:domain logistics-conf)
    ;(:requirements :strips :equality :typing :conditional-effects :disjunctive-preconditions)			
    (:objects
        package1 package2 package3 - OBJ
        pgh-truck bos-truck phx-truck - TRUCK
        airplane1 - AIRPLANE
        bos-po pgh-po phx-po - LOCATION
        bos-airport pgh-airport phx-airport - AIRPORT
        pgh bos phx - CITY
    )
    (:init 
        (in-city-l bos-po bos)
        (in-city-a bos-airport bos)
        (in-city-l phx-po phx)
        (in-city-a phx-airport phx)
        (in-city-l pgh-po pgh)
        (in-city-a pgh-airport pgh)
        (in-city-t pgh-truck pgh)
        (in-city-t bos-truck bos)
        (in-city-t phx-truck phx)

        (at-tl pgh-truck pgh-po)
        (at-tl bos-truck bos-po)
        (at-tl phx-truck phx-po)
        (at-aa airplane1 pgh-airport)

        (not (at-oa package1 bos-airport))
        (not (at-oa package1 pgh-airport))
        (not (at-oa package1 phx-airport))
        (not (in-ot package1 pgh-truck))
        (not (in-ot package1 bos-truck))
        (not (in-ot package1 phx-truck))
        (not (in-oa package1 airplane1))

        (not (at-ol package2 phx-po))
        (not (at-oa package2 bos-airport))
        (not (at-oa package2 pgh-airport))
        (not (at-oa package2 phx-airport))
        (not (in-ot package2 pgh-truck))
        (not (in-ot package2 bos-truck))
        (not (in-ot package2 phx-truck))
        (not (in-oa package2 airplane1))

        (not (at-ol package3 pgh-po))
        (not (at-oa package3 bos-airport))
        (not (at-oa package3 pgh-airport))
        (not (at-oa package3 phx-airport))
        (not (in-ot package3 pgh-truck))
        (not (in-ot package3 bos-truck))
        (not (in-ot package3 phx-truck))
        (not (in-oa package3 airplane1))
    )
    (:goal (and (at-oa package1 bos-airport) (at-oa package2 phx-airport) (at-oa package3 pgh-airport))	)
)

