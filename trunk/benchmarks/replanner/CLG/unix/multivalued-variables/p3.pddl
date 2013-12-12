(define (problem unix-3)
    (:domain unix)
    (:objects
        root
        sub1 sub2
        sub11 sub12 sub21 sub22
        sub111 sub112 sub121 sub122 sub211 sub212 sub221 sub222
        sub1111 sub1121 sub1211 sub1221 sub2111 sub2121 sub2211 sub2221 sub1112 sub1122 sub1212 sub1222 sub2112 sub2122 sub2212 sub2222 - DIR
        my-file - FILE
    )
    (:init
        (sub-dir root sub1)
        (sub-dir root sub2)
        (sub-dir sub1 sub11)
        (sub-dir sub1 sub12)
        (sub-dir sub2 sub21)
        (sub-dir sub2 sub22)
        (sub-dir sub11 sub111)
        (sub-dir sub11 sub112)
        (sub-dir sub21 sub211)
        (sub-dir sub21 sub212)
        (sub-dir sub12 sub121)
        (sub-dir sub12 sub122)
        (sub-dir sub22 sub221)
        (sub-dir sub22 sub222)
        (sub-dir sub111 sub1111)
        (sub-dir sub111 sub1112)
        (sub-dir sub211 sub2111)
        (sub-dir sub211 sub2112)
        (sub-dir sub121 sub1211)
        (sub-dir sub121 sub1212)
        (sub-dir sub221 sub2211)
        (sub-dir sub221 sub2212)
        (sub-dir sub112 sub1121)
        (sub-dir sub112 sub1122)
        (sub-dir sub212 sub2121)
        (sub-dir sub212 sub2122)
        (sub-dir sub122 sub1221)
        (sub-dir sub122 sub1222)
        (sub-dir sub222 sub2221)
        (sub-dir sub222 sub2222)
        (is-cur-dir root)
    )
    (:goal (file-in-dir my-file root))
)

