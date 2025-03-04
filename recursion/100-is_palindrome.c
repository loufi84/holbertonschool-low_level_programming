#include "main.h"

/**
 *
 *
 *
 */

int check_length(char *s)
{
	int len = 0;

	if (s[0] == '\0')
	{
		return (0);
	}
	else
	{
		return (1 + check_length(s + 1));
	}
}

/**
 * is_palindrome - check if a string is a palindrome
 * @s: String to check
 * Return: 1 if palindrome, 0 if not
 */

int is_palindrome(char *s)
{
	int len = 0;

	len = check_length(s);

	if (len == 0 || len == 1)
	{
		return (1);
	}

	if (s[0] == s[len - 1])
	{
		return (is_palindrome(s + 1, len - 2);
	}
	else
	{
		return (0);
	}
