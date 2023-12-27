#include "../include/shell.h"

/**
 * _putchar - Writes a character to the standard output.
 *
 * @c: The character to print.
 *
 * Return: The character written to the standard output.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * _puts - Prints a string to the standard output followed by a newline.
 *
 * @str: A pointer to the string to be printed.
 *
 * Description: This function prints each character in the input string
 * to the standard output using a loop, and then adds a newline character.
 */
void _puts(char *str)
{
    int i;

    /* Loop through each character in the string */
    for (i = 0; str[i] != '\0'; i++)
    {
        _putchar(str[i]); /* Print each character */
    }

    _putchar('\n'); /* Print a newline character at the end */
}

/**
 * _strncpy - Copies up to 'n' characters from source to destination.
 *
 * @dest: The destination buffer.
 * @src: The source string.
 * @n: The number of characters to copy.
 *
 * Return: A pointer to the destination buffer 'dest'.
 */
char *_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    /* Copy up to n characters from src to dest */
    while (i < n && *(src + i))
    {
        *(dest + i) = *(src + i);
        i++;
    }

    /* Fill the remaining characters in dest with null characters */
    while (i < n)
    {
        *(dest + i) = '\0';
        i++;
    }

    return (dest);
}

/**
 * _strlen - Computes the length of a string.
 *
 * @s: The input string.
 *
 * Return: The length of the string 's'.
 */
int _strlen(char *s)
{
    int i;

    /* Loop through each character in the string and count */
    for (i = 0; s[i] != '\0'; i++)
    {
        continue;
    }

    return (i);
}

/**
 * _atoi - Converts a string to an integer.
 *
 * @s: The input string.
 *
 * Return: The converted integer from the input string 's'.
 */
int _atoi(char *s)
{
    int i = 0, j = 1, k;
    unsigned int l = 0;

    /* Loop through each character in the string */
    while (s[i] != '\0')
    {
        if (s[i] == '-')
        {
            return (2); /* Return 2 if a negative sign is encountered */
        }

        k = s[i] - '0'; /* Convert character to integer */

        /* Break if a non-digit character is encountered after a valid integer */
        if (l > 0 && !(k >= 0 && k <= 9))
            break;

        /* Add digit to the integer value */
        if (k >= 0 && k <= 9)
            l = l * 10 + k;

        i++;
    }

    l *= j; /* Apply sign to the integer value */
    return (l);
}
