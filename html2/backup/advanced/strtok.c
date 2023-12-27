#include "../include/shell.h"

/**
 * delimeter - Function that checks if a character matches any character in a string.
 *
 * @c: Character to check.
 * @str: String of delimiters.
 * Return: 1 on success (character is a delimiter), 0 on failure.
 */
unsigned int delimeter(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		/*  Check if the character matches any delimiter
 */
		if (c == str[i])
			return (1);
	}
	/*  Character is not a delimiter
 */
	return (0);
}

/**
 * _strtok - Function that extracts tokens from a string using a specified delimiter.
 *
 * @str: String to tokenize.
 * @delim: Delimiter.
 * Return: Pointer to the next token or NULL if no more tokens.
 */
char *_strtok(char *str, const char *delim)
{
	static char *tokens;
	static char *new_token;
	unsigned int i;

	/*  If the input string is provided, update the new_token
 */
	if (str != NULL)
		new_token = str;

	/*  Initialize the tokens pointer to the new_token
 */
	tokens = new_token;

	/*  If tokens pointer is NULL, return NULL (no more tokens)
 */
	if (tokens == NULL)
		return (NULL);

	/*  Find the start of the next token by skipping leading delimiters
 */
	for (i = 0; tokens[i] != '\0'; i++)
	{
		if (delimeters(tokens[i], delim) == 0)
			break;
	}

	/*  If the next token is '#' or end of string, return NULL
 */
	if (new_token[i] == '\0' || new_token[i] == '#')
	{
		new_token = NULL;
		return (NULL);
	}

	/*  Update the tokens pointer to the start of the next token
 */
	tokens = new_token + i;

	/*  Find the end of the current token by looking for delimiters
 */
	for (i = 0; new_token[i] != '\0'; i++)
	{
		if (delimeters(new_token[i], delim) == 1)
			break;
	}

	/*  If end of string is reached, set new_token to NULL
 */
	if (new_token[i] == '\0')
		new_token = NULL;
	else
	{
		/*  Replace the delimiter with NULL character and update new_token
 */
		new_token[i] = '\0';
		new_token = new_token + i + 1;

		/*  If the next character is end of string, set new_token to NULL
 */
		if (*new_token == '\0')
			new_token = NULL;
	}

	/*  Return the pointer to the current token
 */
	return (tokens);
}
