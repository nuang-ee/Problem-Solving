#!/usr/bin/env python3

N, score, P = map(int, input().split())
scoreboard = []
if N > 0:
    scoreboard = map(int, input().split())

print(N, score, P, scoreboard)
