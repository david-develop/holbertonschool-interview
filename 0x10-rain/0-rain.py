#!/usr/bin/python3
"""
Rain Module
"""


def rain(walls):
    """Method that calc the retained water"""
    f = 0
    s = 0
    water = 0
    if not walls:
        return 0
    len_wall = len(walls)
    while s < len_wall - 1 and f < len_wall:
        if walls[f] != 0:
            s = f
            while s < len_wall - 1:
                s += 1
                if walls[s] != 0 and f < s:
                    lower = min(walls[f], walls[s])
                    water += (s - f - 1) * lower
                    break
        f += 1

    return water
