#include "palindrome.h"

/**
 * is_palindrome - calculate if a number is palindrome or not.
 * @n: input number.
 * Return: 1 if a string is a palindrome and 0 if not.
 */
int is_palindrome(unsigned long n)
{
	unsigned long temp, rem, rev = 0;

	temp = n;

	while (n != 0)
	{
		rem = n % 10;
		rev = rev * 10 + rem;
		n /= 10;
	}

	if (rev == temp)
	{
		return (1);
	}

	return (0);
}
