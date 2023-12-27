#include "../include/shell.h"

/**
 * parse_cmd - Parses the command received from stdin.
 *
 * @input: String gathered from stdin containing the command.
 *
 * Return: Parsed strings to be used as arguments in an array of strings.
 */
char **parse_cmd(char *input)
{
	/* Declare variables for storing parsed arguments and tokens */
	char **arguments;
	char *argument;
	int i;
	int buffsize = BUFSIZE;

	/* Check for leading and trailing spaces, exit if both exist */
	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);

	/* Check for NULL input, return NULL if true */
	if (input == NULL)
		return (NULL);

	/* Allocate memory for the array of arguments */
	arguments = malloc(sizeof(char *) * buffsize);
	if (!arguments)
	{
		free(arguments);
		perror("hsh");
		return (NULL);
	}

	/* Tokenize the input string using whitespace characters as delimiters */
	argument = _strtok(input, "\n\t\r\a ");

	/* Loop through the tokens and store them in the arguments array */
	for (i = 0; argument; i++)
	{
		arguments[i] = argument;
		argument = _strtok(NULL, "\n\t\r\a ");
	}

	/* Set the last element of the arguments array to NULL */
	arguments[i] = NULL;

	return (arguments); /* Return the array of parsed arguments */
}
