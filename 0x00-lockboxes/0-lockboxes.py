#!/usr/bin/python3
"""Lockboxes method """



def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""

    boxes_number = [x for x in range(1, len(boxes))]
    for i in range(len(boxes)):
        for key in boxes[i]:
            if key != i and key in boxes_number:
                boxes_number.remove(key)

    return len(boxes_number) == 0
