#!/usr/bin/python3
"""Module pascal_triangle with pascal_triangle function that returns a list of
lists of integers representing the Pascal’s triangle of n"""


def pascal_triangle(n):
    """Function that returns a list of lists of integers representing the
    Pascal’s triangle of n
    Args:
        n (int): number of length of triangle
    """
    if n <= 0:
        return []
    if n == 1:
        return [[1]]
    if n == 2:
        return [[1], [1, 1]]
    if n > 2:
        pascal_t = [[1], [1, 1]]
        curr_l = 1
        for h in range(n - 2):
            num = 0
            new_list = []
            new_list.append(1)
            lists_pas = pascal_t[curr_l]
            for i in range(len(lists_pas)):
                try:
                    num = lists_pas[i] + lists_pas[i + 1]
                    new_list.append(num)
                except:
                    break
            new_list.append(1)
            curr_l += 1
            pascal_t.append(new_list)
    return pascal_t
