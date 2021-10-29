#!/usr/bin/python3
"""
makeChange module
"""


def makeChange(coins, total):
    """
    makeChange function
    """
    if total == 0:
        return 0
    if total < 0:
        return -1
    if len(coins) == 0:
        return -1
    if len(coins) == 1:
        if total in coins:
            return 1
        else:
            return -1

    sorted_coins = sorted(coins, reverse=True)
    # print(sorted_coins)
    # while total >= 0:
    #     for coin in sorted_coins:
    #         if total - coin >= 0:
    #             total -= coin
    #             return 1 + makeChange(coins, total)
    # return -1


