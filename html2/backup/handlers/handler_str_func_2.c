#include "../include/shell.h"

/**
 * _strcpy - Copies a string from source to destination.
 *
 * @dest: The destination buffer.
 * @src: The source string.
 *
 * Return: A pointer to the destination buffer 'dest'.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	/* Copy each character from src to dest */
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - Concatenates two strings by appending the content of 'src' to 'dest'.
 *
 * @dest: The destination buffer (resulting string).
 * @src: The source string to be appended.
 *
 * Return: A pointer to the resulting string in 'dest'.
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	/* Move to the end of the destination buffer */
	while (*dest != '\0')
	{
		dest++;
	}

	/* Append the characters of src to dest */
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (s);
}

/**
 * _strchr - Locates the first occurrence of a character 'c' in the string 's'.
 *
 * @s: The string to be searched.
 * @c: The character to be located.
 *
 * Return: A pointer to the character 'c' in the string 's' or NULL if not found.
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			break;
		}
	} while (*s++);

	return (s);
}

/**
 * _strncmp - Compares up to 'n' characters of two strings 's1' and 's2'.
 *
 * @s1: The first string.
 * @s2: The second string.
 * @n: The number of characters to compare.
 *
 * Return: 0 if the strings match up to 'n' characters, otherwise 1.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);

	/* Compare up to 'n' characters of s1 and s2 */
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _strdup - Duplicates a string by allocating memory and copying the content.
 *
 * @str: The string to be duplicated.
 *
 * Return: A pointer to the duplicated string or NULL if allocation fails.
 */
char *_strdup(char *str)
{
	size_t len, i;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));

	/* Check for allocation failure */
	if (!str2)
	{
		return (NULL);
	}

	/* Copy each character from str to str2 */
	for (i = 0; i <= len; i++)
	{
		str2[i] = str[i];
	}

	return (str2);
}
