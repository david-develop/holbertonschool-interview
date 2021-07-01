#include "slide_line.h"
#include <stdio.h>

/**
 * validate -  Check if an array of integers needs to be slided
 *
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @line
 * @direction: Direction representation
 *
 * Return: 1 if need slide else 0
 */
int validate(int *line, size_t size, int direction)
{
	size_t i;
	int res = 0;

	if (direction == SLIDE_RIGHT)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (line[i] != 0 && line[i + 1] == 0)
			{
				res = 1;
			}
		}
	}
	if (direction == SLIDE_LEFT)
	{
		for (i = size - 1; i > 0; i--)
		{
			if (line[i] != 0 && line[i - 1] == 0)
			{
				res = 1;
			}
		}
	}

	return (res);
}

/**
 * merge -  Merge an array of integers
 *
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @line
 * @direction: Direction representation
 *
 */
static void merge(int *line, size_t size, int direction)
{
	size_t i;

	if (direction == SLIDE_RIGHT)
	{
		for (i = size - 1; i > 0; i--)
		{
			if (line[i] == line[i - 1])
			{

				line[i] = line[i] * 2;
				line[i - 1] = 0;
				if (i > 1)
					i--;
			}
		}
	}
	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (line[i] == line[i + 1])
			{

				line[i + 1] = line[i] * 2;
				line[i] = 0;
				if (i < size - 1)
					i++;
			}
		}
	}
}

/**
 * slide -  Slides an array of integers
 *
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @line
 * @direction: Direction representation
 *
 */
static void slide(int *line, size_t size, int direction)
{
	size_t i;
	int flag = 1;

	if (direction == SLIDE_RIGHT)
	{
		while (flag)
		{
			for (i = 0; i < size - 1; i++)
			{
				if (line[i] != 0 && line[i + 1] == 0)
				{
					line[i + 1] = line[i];
					line[i] = 0;
				}
			}
			flag = validate(line, size, SLIDE_RIGHT);
		}
	}
	if (direction == SLIDE_LEFT)
	{
		while (flag)
		{
			for (i = size - 1; i > 0; i--)
			{
				if (line[i] != 0 && line[i - 1] == 0)
				{
					line[i - 1] = line[i];
					line[i] = 0;
				}
			}
			flag = validate(line, size, SLIDE_LEFT);
		}
	}
}

/**
 * slide_line -  Slides and merges an array of integers
 *
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @line
 * @direction: Direction representation
 *
 * Return: 1 if success or 0 if failure
 */
int slide_line(int *line, size_t size, int direction)
{

	if (direction == SLIDE_RIGHT)
	{
		slide(line, size, SLIDE_RIGHT);
		merge(line, size, SLIDE_RIGHT);
		slide(line, size, SLIDE_RIGHT);
	}
	else if (direction == SLIDE_LEFT)
	{
		slide(line, size, SLIDE_LEFT);
		merge(line, size, SLIDE_LEFT);
		slide(line, size, SLIDE_LEFT);
	}
	else
	{
		return (0);
	}

	return (1);
}
