#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: string to check
 * @pattern: pattern to check agains
 *
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */
int regex_match(char const *str, char const *pattern)
{
	int dot_flag = 0, wild_flag = 0;

	if (!str || !pattern)
		return (0);

	dot_flag = *str && (*str == *pattern || *pattern == '.');
	wild_flag = *(pattern + 1) == '*';

	if (!*str && !wild_flag)
	{
		if (!*pattern)
			return (1);
		return (0);
	}

	if (dot_flag && wild_flag)
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
	else if (dot_flag && !wild_flag)
		return (regex_match(str + 1, pattern + 1));
	else if (wild_flag)
		return (regex_match(str, pattern + 2));

	return (0);
}
