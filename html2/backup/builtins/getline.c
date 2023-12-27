#include "../include/shell.h"

/**
 * _getline - Read input from standard input by the user.
 * Return: The input on a buffer.
 */
char *_getline()
{
	/*  Declare variables */
	int i, rd, buffsize = BUFSIZE;
	char c = 0, *buffer, *buf;

	/*  Allocate memory for the buffer */
	buffer = malloc(buffsize);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}

	/*  Read input character by character until EOF or newline */
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		/*  Clear stdin */
		fflush(stdin);
		/*  Read a character from stdin */
		rd = read(STDIN_FILENO, &c, 1);

		/*  Handle case where no input is read (EOF) */
		if (rd == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}

		/*  Store the character in the buffer */
		buffer[i] = c;

		/*  Check	 if the buffer starts with a newline */
		if (buffer[0] == '\n')
			return (enter(buffer));

		/*  Check if buffer size is exceeded and reallocate memory if necessary */
		if (i >= buffsize)
		{
			buffer = realloc(buffer, (buffsize + 2));
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
	}

	/*  Null-terminate the buffer */
	buffer[i] = '\0';

	/*  Process the buffer, removing leading whitespaces */
	buf = space(buffer);

	/*  Free the original buffer */
	free(buffer);

	/*  Handle hashtags in the buffer */
	hashtag_handlers(buf);

	/*  Return the processed buffer */
	return (buf);
}

/**
 * enter - Handles newline character input.
 * @string: String to be handled.
 * Return: Empty string.
 */
char *enter_key(char *string)
{
	/*  Free the input string and return an empty string */
	free(string);
	return ("\0");
}

/**
 * space - Modifies the input string to remove preceding whitespaces.
 * @str: Input to be modified.
 * Return: Returns the modified string.
 */
char *space_key(char *str)
{
	/*  Declare variables */
	int i, j = 0;
	char *buff;

	/*  Allocate memory for the modified string */
	buff = malloc(sizeof(char) * (__strlen(str) + 1));
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	/*  Skip leading spaces in the input string */
	for (i = 0; str[i] == ' '; i++)
		;

	/*  Copy the non-space characters to the modified string */
	for (; str[i + 1] != '\0'; i++)
	{
		buff[j] = str[i];
		j++;
	}

	/*  Null-terminate the modified string */
	buff[j] = '\0';

	/*  Check if the modified string is empty or contains only a hashtag */
	if (buff[0] == '\0' || buff[0] == '#')
	{
		free(buff);
		return ("\0");
	}

	/*  Return the modified string */
	return (buff);
}

/**
 * hashtag_handler - Removes everything after '#'.
 * @buff: Input buffer.
 * Return: Nothing.
 */
void hashtag_handlers(char *buff)
{
	/*  Declare variable */
	int i;

	/*  Iterate through the buffer to find and remove content after '#' preceded and succeeded by spaces */
	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#' && buff[i - 1] == ' ' && buff[i + 1] == ' ')
		{
			buff[i] = '\0';
		}
	}
}
