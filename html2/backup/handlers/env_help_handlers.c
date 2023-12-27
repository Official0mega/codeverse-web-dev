#include "../include/shell.h"

/**
 * env_help( - Displays information on the shell by builtin command 'env'
 */
void env_help(void)
{
    char *msg = "env: env\n\tPrints the current environment.\n";

    /*  Write the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * setenv_help - Displays information on the shell by builtin command 'setenv'
 */
void setenv_help(void)
{
    char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

    /*  Write the first part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "environment variable, or modifies an existing one.\n\n";
    /*  Write the second part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "\tUpon failure, prints a message to stderr.\n";
    /*  Write the third part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * unsetenv_help - Displays information on the shell by builtin command 'unsetenv'
 */
void unsetenv_help(void)
{
    char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

    /*  Write the first part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "environmental variable.\n\n\tUpon failure, prints a ";
    /*  Write the second part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "message to stderr.\n";
    /*  Write the third part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * display_help - Display help for builtin commands
 * @cmd: Parsed command
 * @st: Status of last command executed
 * Return: 0 Success
 */
int display_help(char **cmd, __attribute__((unused))int st)
{
    /*  Check for each specific help command and call the corresponding function */
    if (!cmd[1])
        all_help();
    else if (_strcmp(cmd[1], "alias") == 0)
        alias_help();
    else if (_strcmp(cmd[1], "cd") == 0)
        cd_help();
    else if (_strcmp(cmd[1], "exit") == 0)
        exit_help();
    else if (_strcmp(cmd[1], "env") == 0)
        env_help();
    else if (_strcmp(cmd[1], "setenv") == 0)
        setenv_help();
    else if (_strcmp(cmd[1], "unsetenv") == 0)
        unsetenv_help();
    else if (_strcmp(cmd[1], "help") == 0)
        helpers();
    return (0);
}
