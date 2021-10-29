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
    if len(coins) == 1 and total in coins:
        return 1

    sorted_coins = sorted(coins, reverse=True)
    while total >= 0:

        for coin in sorted_coins:
            if coin > total:
                sorted_coins.pop(0)

                return makeChange(sorted_coins, total)
            if total - coin >= 0:
                total -= coin

                if coin > total:
                    sorted_coins.pop(0)
                return 1 + makeChange(sorted_coins, total)
    return -1
