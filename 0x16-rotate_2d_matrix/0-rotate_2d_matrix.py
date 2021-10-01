#!/usr/bin/python3
"""
Moduel rotate_2d_matrix method
"""


def rotate_2d_matrix(matrix):
    """Method that rotate it 90 degrees clockwise of a n x n matrix"""
    temp1 = matrix[0][0]
    temp2 = matrix[0][-1]
    temp3 = matrix[-1][-1]
    temp4 = matrix[-1][0]

    matrix[0][-1] = temp1
    matrix[-1][-1] = temp2
    matrix[-1][0] = temp3
    matrix[0][0] = temp4

    temp5 = matrix[0][1]
    temp6 = matrix[1][-1]
    temp7 = matrix[-1][1]
    temp8 = matrix[1][0]

    matrix[1][-1] = temp5
    matrix[-1][1] = temp6
    matrix[1][0] = temp7
    matrix[0][1] = temp8
