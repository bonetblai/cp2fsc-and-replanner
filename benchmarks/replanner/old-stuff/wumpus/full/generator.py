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

if (len(sys.argv) <> 6) :
    print """
    usage: %s <dim> <nwumpus> <npits> <seed> <n>

    generates <n> random instances of a wumpus of dimension <dim>
    with <nwumpus> wumpus and <npits> pits. The output is placed
    in file problems/wumpus_<dim>_<nwumpus>_<npits>_<seed>.pddl.
    """ % sys.argv[0]
    sys.exit(1)

dim = int(sys.argv[1])
nwumpus = int(sys.argv[2])
npits = int(sys.argv[3])
seed = int(sys.argv[4])
num = int(sys.argv[5])
random.seed(seed)


def calculate_cells():
    cells = []
    for x in range(1, dim):
        for y in range(1, dim):
            cells.append((x, y))
    return cells

def calculate_adj(pos, adj_list):
    for dx in (-1,0,1):
        for dy in (-1,0,1):
            if (dx == 0) & (dy == 0):
                continue
            if (pos[0] + dx > 0) & (pos[0] + dx < dim) & (pos[1] + dy > 0) & (pos[1] + dy < dim) & ((dx == 0) | (dy == 0)):
                adj_list.append((pos[0] + dx, pos[1] + dy))
    return adj_list


pname = "%s_%d_%d_%d_%d" % (name, dim, nwumpus, npits, seed)
pfile  = file("problems/" + pname + ".pddl", "w")
dim += 1
cells = calculate_cells()

header = "(define (problem %s)\n" % pname + "  (:domain %s)\n" % name 

objs = "  (:objects"
for cell in cells:
    objs += " p_%d_%d" % cell
objs += " - pos\n  )\n"

knowns = """
    ;; Known
    (at p_1_1)
    (alive)
"""

adjs = "    ;; Adjacencies\n"
for cell in cells:
    adj_list = calculate_adj(cell, [])
    for pos in adj_list:
        adjs += " (adj p_%d_%d p_%d_%d)" % (cell + pos)

unknowns = "    ;; Unknows\n"
for cell in cells:
    unknowns += "    (at-least-one (wumpus p_%d_%d) (not (wumpus p_%d_%d)))\n" % (cell + cell)
    unknowns += "    (at-least-one (stench p_%d_%d) (not (stench p_%d_%d)))\n" % (cell + cell)
    unknowns += "    (at-least-one (pit p_%d_%d) (not (pit p_%d_%d)))\n" % (cell + cell)
    unknowns += "    (at-least-one (breeze p_%d_%d) (not (breeze p_%d_%d)))\n" % (cell + cell)
    unknowns += "    (at-least-one (glitter p_%d_%d) (not (glitter p_%d_%d)))\n" % (cell + cell)
    unknowns += "    (at-least-one (safe p_%d_%d) (not (safe p_%d_%d)))\n" % (cell + cell)

infs = "    ;; Inference rules\n"
for cell in cells:
    adj_list = calculate_adj(cell, [])
    for pos in adj_list:
        infs += "    (at-least-one (not (wumpus p_%d_%d)) (stench p_%d_%d))\n" % (cell + pos)
        infs += "    (at-least-one (not (pit p_%d_%d)) (breeze p_%d_%d))\n" % (cell + pos)
    infs += "    (at-least-one (not (wumpus p_%d_%d)) (not (at p_%d_%d)) (not (alive)))\n" % (cell + cell)
    infs += "    (at-least-one (not (pit p_%d_%d)) (not (at p_%d_%d)) (not (alive)))\n" % (cell + cell)
    infs += "    (at-least-one (wumpus p_%d_%d) (pit p_%d_%d) (safe p_%d_%d))\n" % (cell + cell + cell)
    infs += "    (at-least-one (not (glitter p_%d_%d)) (gold p_%d_%d))\n" % (cell + cell)

infs += "\n"
for cell in cells:
    inf1 = "    (at-least-one (not (stench p_%d_%d))" % cell
    inf2 = "    (at-least-one (not (breeze p_%d_%d))" % cell
    adj_list = calculate_adj(cell, [])
    for pos in adj_list:
        inf1 += " (wumpus p_%d_%d)" % pos
        inf2 += " (pit p_%d_%d)" % pos
    inf1 += ")\n"
    inf2 += ")\n"
    infs += inf1 + inf2

init = "  (:init" + knowns + "\n" + adjs + "\n\n" + unknowns + "\n" + infs + "  )\n"

def available(pos):
    if (pos == (1,1)) | (pos == (1,2)) | (pos == (2,1)) | (pos == (2,2)):
        return False
    if pos == gold:
        return False
    for p in wumpus:
        if pos == p:
            return False
    for p in pits:
        if pos == p:
            return False
    return True

def safe(pos):
    for p in wumpus:
        if pos == p:
            return False
    for p in pits:
        if pos == p:
            return False
    return True


hidden = ""
for k in range(0, num):
    gold = [-1, -1]
    wumpus = []
    stench = []
    pits = []
    breeze = []

    pos = (-1, -1)
    while (pos[0] == -1) | (not available(pos)):
        pos = (random.randrange(1, dim), random.randrange(1, dim))
    gold = pos

    for i in range(0, nwumpus):
        pos = (-1, -1)
        while (pos[0] == -1) | (not available(pos)):
            pos = (random.randrange(1, dim), random.randrange(1, dim))
        wumpus.append(pos)
        stench.append([])
        calculate_adj(pos, stench[i])

    for i in range(0, npits):
        pos = (-1, -1)
        while (pos[0] == -1) | (not available(pos)):
            pos = (random.randrange(1, dim), random.randrange(1, dim))
        pits.append(pos)
        breeze.append([])
        calculate_adj(pos, breeze[i])

    hidden += "  (:hidden (gold p_%d_%d)" % gold + " (glitter p_%d_%d)" % gold

    for i in range(0, nwumpus):
        hidden += " (wumpus p_%d_%d)" % wumpus[i]
        for pos in stench[i]:
            hidden += " (stench p_%d_%d)" % pos
        #hidden += "\n"

    for i in range(0, npits):
        hidden += " (pit p_%d_%d)" % pits[i]
        for pos in breeze[i]:
            hidden += " (breeze p_%d_%d)" % pos
        #hidden += "\n"

    hidden += "   "
    for cell in cells:
        if safe(cell):
            hidden += " (safe p_%d_%d)" % cell

    hidden += ")\n"

goal = "  (:goal (have-gold))"

print >> pfile, header + objs + init + hidden + goal + "\n)"

