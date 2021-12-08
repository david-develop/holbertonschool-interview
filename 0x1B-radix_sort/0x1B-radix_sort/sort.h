#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
#endif
