#include "../include/shell.h"

/**
 * _strcmp - Compares two strings lexicographically.
 *
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: 0 if strings are identical, otherwise the difference between
 * the ASCII values of the first differing characters in s1 and s2.
 */
int _strcmp(char *s1, char *s2)
{
	/* Initialize variables for string lengths and character comparison */
	int cmp = 0, i, len1, len2;

	/* Calculate lengths of input strings */
	len1 = _strlen(s1);
	len2 = _strlen(s2);

	/* Check for NULL strings or different lengths */
	if (s1 == NULL || s2 == NULL)
		return (1);

	if (len1 != len2)
		return (1);

	/* Compare each character of s1 and s2 */
	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}

/**
 * _isalpha - Checks if the given character is an alphabet letter.
 *
 * @c: The character to check.
 *
 * Return: 1 if 'c' is an alphabet letter, 0 otherwise.
 */
int _isalpha(int c)
{
	/* Check if the character is within the ASCII range for alphabets */
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1); /* Return 1 if the character is an alphabet letter */
	}
	else
	{
		return (0); /* Return 0 if the character is not an alphabet letter */
	}
}

/**
 * _itoa - Converts an unsigned integer to a string.
 *
 * @n: The integer to convert.
 *
 * Return: A pointer to the resulting string representation of 'n'.
 */
char *_itoa(unsigned int n)
{
	/* Initialize variables for string length, index, and string pointer */
	int len = 0, i = 0;
	char *s;

	/* Calculate the length of the integer 'n' */
	len = intlen(n);

	/* Allocate memory for the string representation of 'n' */
	s = malloc(len + 2);

	/* Check for allocation failure */
	if (!s)
	{
		free(s);
		return (NULL);
	}
	*s = '\0'; /* Set the first character of the string to null terminator */

	/* Convert the integer to a string */
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}

	/* Handle the last digit of the integer */
	s[i] = (n % 10) + '0';

	/* Reverse the string to obtain the correct representation */
	array_rev(s, len);
	s[i + 1] = '\0'; /* Set the last character of the string to null terminator */

	return (s); /* Return the pointer to the string representation of 'n' */
}

/**
 * array_rev - Reverses the elements of an array.
 *
 * @arr: The array to reverse.
 * @len: The length of the array.
 */
void array_rev(char *arr, int len)
{
	/* Initialize variables for array reversal */
	int i;
	char tmp;

	/* Iterate over the first half of the array and swap elements */
	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}

/**
 * intlen - Determines the number of digits in an integer.
 *
 * @num: The given integer.
 *
 * Return: The length of the integer in terms of digits.
 */
int intlen(int num)
{
	/* Initialize variables for counting the number of digits */
	int len = 0;

	/* Count the number of digits in the integer */
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len); /* Return the length of the integer */
}
