#include "main.h"

/**
 * check_length - check the length of the string
 * @s: String to check
 * Return: int string length
 */

int check_length(char *s)
{

	if (*s == '\0')
	{
		return (0);
	}
	else
	{
		return (1 + check_length(s + 1));
	}
}

/**
 * palindrome_helper - helper function to is_palindrome
 * @s: String of palindrome
 * @start: Beginning of the string
 * @end: End of the string
 * Return: int
 */

int palindrome_helper(char *s, int start, int end)
{
	if (start >= end)
	{
		return (1);
	}
	if (s[start] != s[end])
	{
		return (0);
	}

	return (palindrome_helper(s, start + 1, end - 1));
}

/**
 * is_palindrome - check if a string is a palindrome
 * @s: String to check
 * Return: 1 if palindrome, 0 if not
 */

int is_palindrome(char *s)
{
	int len = check_length(s);

	if (len == 0)
	{
		return (1);
	}

	return (palindrome_helper(s, 0, len - 1));
}
