#include "../include/shell.h"

/**
 * check_builtins - Checks if parsed command is built-in
 * @cmd: Parsed command to be checked
 * Return: 0 Success, -1 Failure
 */
int check_builtins(char **cmd)
{
    builtin fun[] = {
        {"cd", NULL},
        {"help", NULL},
        {"echo", NULL},
        {"env", NULL},
        {"history", NULL},
        {NULL, NULL}
    };
    int i = 0;

    if (*cmd == NULL)
    {
        return (-1);
    }
    /*  Loop through the array of built-in commands */
    while ((fun + i)->command)
    {
        /*  Check if the parsed command matches any built-in command */
        if (_strcmp(cmd[0], (fun + i)->command) == 0)
            return (0);  /*  Return 0 if found */
        i++;
    }
    return (-1);  /*  Return -1 if not found */
}

/**
 * builtins_handlers - Handles predefined built-in commands
 * @cmd: Array of parsed command strings
 * @st: Status of the last execution
 * Return: -1 Failure, 0 Success
 */
int builtins_handlers(char **cmd, int st)
{
    builtin built_in[] = {
        {"cd", change_directory},
        {"env", dis_env},
        {"help", display_help},
        {"echo", echo_cases},
        {"history", history_dis},
        {NULL, NULL}
    };
    int i = 0;

    /*  Loop through the array of built-in commands */
    while ((built_in + i)->command)
    {
        /*  Check if the parsed command matches any built-in command */
        if (_strcmp(cmd[0], (built_in + i)->command) == 0)
        {
            return ((built_in + i)->function(cmd, st));  /*  Execute the corresponding function */
        }
        i++;
    }
    return (-1);  /*  Return -1 if not found */
}

/**
 * exit_builtins - Exit Status for built-in commands
 * @cmd: Array of parsed command strings
 * @input: Input received from user (to be freed)
 * @argv: Arguments before program starts (argv[0] == Shell Program Name)
 * @c: Shell execution count
 * @stat: Exit status
 */
void exit_builtins(char **cmd, char *input, char **argv, int c, int stat)
{
    int status, i = 0;

    /*  Check if the second argument of the exit command is not provided */
    if (cmd[1] == NULL)
    {
        free(input);
        free(cmd);
        exit(stat);  /*  Exit with the specified status */
    }

    /*  Loop through characters in the second argument */
    while (cmd[1][i])
    {
        /*  Check if the character is alphabetic */
        if (_isalpha(cmd[1][i++]) != 0)
        {
            _prerror(argv, c, cmd);  /*  Print an error message */
            free(input);
            free(cmd);
            exit(2);  /*  Exit with status 2 */
        }
        else
        {
            status = _atoi(cmd[1]);  /*  Convert the argument to an integer */
            if (status == 2)
            {
                _prerror(argv, c, cmd);  /*  Print an error message */
                free(input);
                free(cmd);
                exit(status);  /*  Exit with the specified status */
            }
            free(input);
            free(cmd);
            exit(status);  /*  Exit with the specified status */
        }
    }
}
