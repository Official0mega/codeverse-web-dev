#include "../include/shell.h"

/**
 * main - Entry point of the custom shell program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: Returns the exit status of the shell program
 */

int main(__attribute__((unused)) int argc, char **argv)
{
    char *input, **cmd, **commands;
    int count = 0, i, condition = 1, stat = 0;

    /*  Check if a file is provided as an argument, and read it if present */
    if (argv[1] != NULL)
        read_file(argv[1], argv);

    /*  Register the signal handler for Ctrl+C (SIGINT) */
    signal(SIGINT, signal_to_handle);

    /*  Main shell loop */
    while (condition)
    {
        count++; /*  Increment the command count */

        /*  Display the shell prompt if the input is from a terminal */
        if (isatty(STDIN_FILENO))
            prompt();

        /*  Read user input */
        input = getline();

        /*  Skip empty lines */
        if (input[0] == '\0')
            continue;

        /*  Save command to history */
        history(input);

        /*  Split multiple commands separated by semicolons */
        commands = separators(input);

        /*  Loop through each command */
        for (i = 0; commands[i] != NULL; i++)
        {
            /*  Parse the command into an array of arguments */
            cmd = parse_cmd(commands[i]);

            /*  Check if the command is 'exit' */
            if (_strcmp(cmd[0], "exit") == 0)
            {
                free(commands);
                /*  Handle 'exit' built-in command */
                exit_bul(cmd, input, argv, count, stat);
            }
            /*  Check if the command is a built-in command */
            else if (check_builtin(cmd) == 0)
            {
                /*  Handle built-in commands */
                stat = handle_builtin(cmd, stat);
                free(cmd);
                continue;
            }
            /*  If not a built-in, execute the external command */
            else
            {
                stat = check_cmd(cmd, input, count, argv);
            }
            free(cmd);
        }

        free(input);
        free(commands);

        /*  Wait for child processes to finish */
        wait(&stat);
    }

    return (stat); /*  Return the exit status */
}