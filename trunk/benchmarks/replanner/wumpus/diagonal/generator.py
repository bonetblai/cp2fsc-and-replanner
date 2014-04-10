#!/usr/bin/env python

#  Copyright (C) 2012 Blai Bonet
#
#  Permission is hereby granted to distribute this software for
#  non-commercial research purposes, provided that this copyright
#  notice is included with any such distribution.
#
#  THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
#  EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE
#  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
#  PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE
#  SOFTWARE IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU
#  ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.

import sys
import os
import random


name = "wumpus"

if (len(sys.argv) <> 4) :
    print """
    usage: %s <dim> <seed> <n>

    generates <n> random instances of diagonal wumpus for dimension <dim>
    into file problems/wumpus_<dim>_<seed>.pddl.
    """ % sys.argv[0]
    sys.exit(1)

dim = int(sys.argv[1])
seed = int(sys.argv[2])
num = int(sys.argv[3])
random.seed(seed)


def calculate_cells():
    cells = []
    for x in range(1, dim):
        for y in range(1, dim):
            cells.append((x, y))
    return cells

def is_target_cell(cell):
    return (cell[0] != 1) & (cell[1] != 1) & ((cell[1] == 1 + cell[0]) | (cell[0] == 1 + cell[1]))

def calculate_cells_adj_to_diagonal():
    cells = []
    for x in range(2, dim-1):
        pair = ((x, x+1), (x+1, x))
        cells.append(pair)
    return cells

def calculate_adj(pos, adj_list):
    for dx in (-1,0,1):
        for dy in (-1,0,1):
            if (dx == 0) & (dy == 0):
                continue
            if (pos[0] + dx > 0) & (pos[0] + dx < dim) & (pos[1] + dy > 0) & (pos[1] + dy < dim) & ((dx == 0) | (dy == 0)):
                adj_list.append((pos[0] + dx, pos[1] + dy))
    return adj_list


pname = "%s_%d_%d" % (name, dim, seed)
pfile  = file("problems/" + pname + ".pddl", "w")
dim += 1
cells = calculate_cells()
target_cells = calculate_cells_adj_to_diagonal()

header = "(define (problem %s)\n" % pname + "  (:domain diagonal-%s)\n" % name 

objs = "  (:objects"
for cell in cells:
    objs += " p_%d_%d" % cell
objs += " - pos\n  )\n"

knowns = """
    ;; Known
    (at p_1_1)
    (alive)
    (gold p_%d_%d)
""" % (dim - 1, dim - 1)

knowns += "   "
for cell in cells:
    if not is_target_cell(cell):
        knowns += " (safe p_%d_%d)" % cell

adjs = "    ;; Adjacencies\n"
for cell in cells:
    adj_list = calculate_adj(cell, [])
    for pos in adj_list:
        adjs += " (adj p_%d_%d p_%d_%d)" % (cell + pos)

unknowns = "    ;; Unknows\n"
for cp in target_cells:
    unknowns += "    (at-least-one (wumpus p_%d_%d) (wumpus p_%d_%d))\n" % (cp[0] + cp[1])
    unknowns += "    (at-least-one (not (wumpus p_%d_%d)) (not (wumpus p_%d_%d)))\n" % (cp[0] + cp[1])

for cell in cells:
    unknowns += "    (at-least-one (stench p_%d_%d) (not (stench p_%d_%d)))\n" % (cell + cell)
    if is_target_cell(cell):
        unknowns += "    (at-least-one (safe p_%d_%d) (not (safe p_%d_%d)))\n" % (cell + cell)

infs = "    ;; Inference rules\n"
for cp in target_cells:
    for cell in cp:
        adj_list = calculate_adj(cell, [])
        for pos in adj_list:
            infs += "    (at-least-one (not (wumpus p_%d_%d)) (stench p_%d_%d))\n" % (cell + pos)
        infs += "    (at-least-one (not (wumpus p_%d_%d)) (not (at p_%d_%d)) (not (alive)))\n" % (cell + cell)
        infs += "    (at-least-one (wumpus p_%d_%d) (safe p_%d_%d))\n" % (cell + cell)

infs += "\n"
for cell in cells:
    inf = "    (at-least-one (not (stench p_%d_%d))" % cell
    good_inf = False
    adj_list = calculate_adj(cell, [])
    for pos in adj_list:
        if is_target_cell(pos):
            inf += " (wumpus p_%d_%d)" % pos
            good_inf = True
    inf += ")\n"
    if good_inf:
        infs += inf

init = "  (:init" + knowns + "\n" + adjs + "\n\n" + unknowns + "\n" + infs + "  )\n"

m = 2 ** (dim - 3)
hidden = ""
for k in range(0, num):
    n = random.randrange(0, m)
    bits = []
    for i in range(0, dim - 3):
        bits.append(n % 2)
        n /= 2

    hidden += "  (:hidden"
    for i in range(0, dim - 3):
        cp = target_cells[i]
        cell = cp[bits[i]]
        adj_list = calculate_adj(cell, [])
        hidden += " (wumpus p_%d_%d)" % cell
        for pos in adj_list:
            hidden += " (stench p_%d_%d)" % pos
        #hidden += "\n"
        hidden += " (safe p_%d_%d)" % cp[1 - bits[i]]
    hidden += ")\n"

goal = "  (:goal (have-gold))"

print >> pfile, header + objs + init + hidden + goal + "\n)"

