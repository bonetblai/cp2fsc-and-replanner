(define (problem unix-3)
   (:domain unix)
   (:objects root sub1 sub2 sub11 sub12 sub21 sub22 sub111 sub112 sub121 sub122 sub211 sub212 
        sub221 sub222 sub1111 sub1121 sub1211 sub1221 sub2111 sub2121 
        sub2211 sub2221 sub1112 sub1122 sub1212 sub1222 sub2112 sub2122 
        sub2212 sub2222 - DIR my_file - FILE)
   
   (:init
     (sub_dir root sub1)
     (sub_dir root sub2)
     (sub_dir sub1 sub11)
     (sub_dir sub1 sub12)
     (sub_dir sub2 sub21)
     (sub_dir sub2 sub22)
     (sub_dir sub11 sub111)
     (sub_dir sub11 sub112)
     (sub_dir sub21 sub211)
     (sub_dir sub21 sub212)
     (sub_dir sub12 sub121)
     (sub_dir sub12 sub122)
     (sub_dir sub22 sub221)
     (sub_dir sub22 sub222)
     (sub_dir sub111 sub1111)
     (sub_dir sub111 sub1112)
     (sub_dir sub211 sub2111)
     (sub_dir sub211 sub2112)
     (sub_dir sub121 sub1211)
     (sub_dir sub121 sub1212)
     (sub_dir sub221 sub2211)
     (sub_dir sub221 sub2212)
     (sub_dir sub112 sub1121)
     (sub_dir sub112 sub1122)
     (sub_dir sub212 sub2121)
     (sub_dir sub212 sub2122)
     (sub_dir sub122 sub1221)
     (sub_dir sub122 sub1222)
     (sub_dir sub222 sub2221)
     (sub_dir sub222 sub2222)
     (is_cur_dir root)
     ;(unknown (file_in_dir my_file sub11))
     ;(unknown (file_in_dir my_file sub21))
     ;(unknown (file_in_dir my_file sub12))
     ;(unknown (file_in_dir my_file sub22))
     ;(unknown (file_in_dir my_file sub111))
     ;(unknown (file_in_dir my_file sub211))
     ;(unknown (file_in_dir my_file sub121))
     ;(unknown (file_in_dir my_file sub221))
     ;(unknown (file_in_dir my_file sub112))
     ;(unknown (file_in_dir my_file sub212))
     ;(unknown (file_in_dir my_file sub122))
     ;(unknown (file_in_dir my_file sub222))
     ;(unknown (file_in_dir my_file sub1111))
     ;(unknown (file_in_dir my_file sub2111))
     ;(unknown (file_in_dir my_file sub1211))
     ;(unknown (file_in_dir my_file sub2211))
     ;(unknown (file_in_dir my_file sub1121))
     ;(unknown (file_in_dir my_file sub2121))
     ;(unknown (file_in_dir my_file sub1221))
     ;(unknown (file_in_dir my_file sub2221))
     ;(unknown (file_in_dir my_file sub1112))
     ;(unknown (file_in_dir my_file sub2112))
     ;(unknown (file_in_dir my_file sub1212))
     ;(unknown (file_in_dir my_file sub2212))
     ;(unknown (file_in_dir my_file sub1122))
     ;(unknown (file_in_dir my_file sub2122))
     ;(unknown (file_in_dir my_file sub1222))
     ;(unknown (file_in_dir my_file sub2222))
     (oneof
        (file_in_dir my_file sub11)
        (file_in_dir my_file sub21)
        (file_in_dir my_file sub12)
        (file_in_dir my_file sub22)
        (file_in_dir my_file sub111)
        (file_in_dir my_file sub211)
        (file_in_dir my_file sub121)
        (file_in_dir my_file sub221)
        (file_in_dir my_file sub112)
        (file_in_dir my_file sub212)
        (file_in_dir my_file sub122)
        (file_in_dir my_file sub222)
        (file_in_dir my_file sub1111)
        (file_in_dir my_file sub2111)
        (file_in_dir my_file sub1211)
        (file_in_dir my_file sub2211)
        (file_in_dir my_file sub1121)
        (file_in_dir my_file sub2121)
        (file_in_dir my_file sub1221)
        (file_in_dir my_file sub2221)
        (file_in_dir my_file sub1112)
        (file_in_dir my_file sub2112)
        (file_in_dir my_file sub1212)
        (file_in_dir my_file sub2212)
        (file_in_dir my_file sub1122)
        (file_in_dir my_file sub2122)
        (file_in_dir my_file sub1222)
        (file_in_dir my_file sub2222)
        )
     )
   (:goal (file_in_dir my_file root))
)
