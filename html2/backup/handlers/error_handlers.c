#include "../include/shell.h"

/**
 * error_not_found - Displays an error message for a command not found
 * @input: User input for the command
 * @counter: Count of shell loop
 * @argv: Arguments before the program starts (argv[0] == Shell Program Name)
 */
void error_not_found(char *input, int counter, char **argv)
{
    char *er;

    /* Print the program name and error message */
    PRINT(argv[0]);
    PRINT(": ");
    er = _itoa(counter);
    PRINT(er);
    free(er);
    PRINT(": ");
    PRINT(input);
    PRINT(": not found\n");
}

/**
 * _perror - Prints a custom error message for an illegal number
 * @argv: Arguments before the program starts (argv[0] == Shell Program Name)
 * @c: Error Count
 * @cmd: Array of parsed command strings
 */
void _perror(char **argv, int c, char **cmd);
{
    char *er = _itoa(c);

    /* Print the program name, error message, and illegal number details */
    PRINT(argv[0]);
    PRINT(": ");
    PRINT(er);
    free(er);
    PRINT(": ");
    PRINT(cmd[0]);
    PRINT(": Illegal number: ");
    PRINT(cmd[1]);
    PRINT("\n");
}

/**
 * error_opening - Prints a custom error message for failure to open a file
 * @argv: Arguments before the program starts (argv[0] == Shell Program Name)
 * @c: Error Count
 */
void error_opening(char **argv, int c)
{
    char *er = _itoa(c);

    /* Print the program name and error message for file opening failure */
    PRINT(argv[0]);
    PRINT(": ");
    PRINT(er);
    free(er);
    PRINT(": Can't open ");
    PRINT(argv[1]);
    PRINT("\n");
}
