#include "../include/shell.h"

/**
 * separators - Separates a string of commands using ';'
 * @input: Input string containing commands
 * Return: Array of parsed strings representing commands
 */
char **separators(char *input)
{
    /* Array to store parsed commands */
    char **commands;

    /* Temporary variable to store each individual command */
    char *command;

    /* Loop counter variable */
    int i;

    /* Buffer size for dynamic memory allocation */
    int buffsize = BUFSIZE;

    /* Check for empty or null input */
    if (input[0] == ' ' && input[__strlen(input)] == ' ')
        exit(0);
    if (input == NULL)
        return (NULL);

    /* Allocate memory for the commands array */
    commands = malloc(sizeof(char *) * buffsize);
    if (!commands)
    {
        /* Handle memory allocation failure */
        free(commands);
        perror("hsh");
        return (NULL);
    }

    /* Tokenize the input string using ';', '&', and '\n' as delimiters */
    command = _strtok(input, ";&");
    for (i = 0; command; i++)
    {
        /* Store each command in the array */
        commands[i] = command;
        command = _strtok(NULL, ";&");
    }

    /* Set the last element of the array to NULL */
    commands[i] = NULL;

    /* Return the array of commands */
    return (commands);
}
