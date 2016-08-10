#!/usr/bin/python
import sys

x = int(sys.argv[1])
y = int(sys.argv[2])
nx = [1, -1, 0,  0]
ny = [0, 0,  1, -1]

for i in range(x, y + 1):
    for j in range(x, y + 1):
        for k in range(0, 4):
            if i + nx[k] < x or j + ny[k] < x or i + nx[k] > y or j + ny[k] > y:
                continue
            n1 = "p{0}-{1}".format(i, j)
            n2 = "p{0}-{1}".format(i + nx[k], j + ny[k])
            print("        (neighborhood {0} {1})".format(n1, n2))

