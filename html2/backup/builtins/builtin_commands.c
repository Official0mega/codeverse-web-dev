#include "../include/shell.h"

/**
 * change_dir - Changes directory
 * @cmd: Parsed command
 * @st: Status of the last command executed
 * Return: 0 on success, 1 if failed (For OLDPWD Always 0 in case of no OLDPWD)
 */
int change_dir(char **cmd, __attribute__((unused)) int st)
{
    int value = -1;  /*  Variable to store the return value of chdir */
    char cwd[PATH_MAX];  /*  Buffer to store the current working directory */

    /*  Check if the second argument is NULL, representing the home directory */
    if (cmd[1] == NULL)
        value = chdir(getenv("HOME"));
    /*  Check if the second argument is "-", representing the previous directory */
    else if (_strcmp(cmd[1], "-") == 0)
    {
        value = chdir(getenv("OLDPWD"));
    }
    /*  Change to the specified directory */
    else
        value = chdir(cmd[1]);

    /*  Handle errors in changing the directory */
    if (value == -1)
    {
        _perror("hsh");  /*  Print error message */
        return (-1);
    }
    /*  Update the environment variables (OLDPWD and PWD) after successful directory change */
    else if (value != -1)
    {
        getcwd(cwd, sizeof(cwd));  /*  Get the current working directory */
        setenv("OLDPWD", getenv("PWD"), 1);  /*  Update OLDPWD */
        setenv("PWD", cwd, 1);  /*  Update PWD */
    }
    return (0);
}

/**
 * dis_env - Display environment variable
 * @cmd: Parsed command
 * @st: Status of the last command executed
 * Return: Always 0
 */
int dis_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int st)
{
    size_t i;  /*  Loop variable */
    int len;  /*  Variable to store the length of the environment variable string */

    /*  Loop through the environment variables and print each one */
    for (i = 0; environ[i] != NULL; i++)
    {
        len = __strlen(environ[i]);  /*  Get the length of the environment variable string */
        write(1, environ[i], len);  /*  Write the environment variable to standard output */
        write(STDOUT_FILENO, "\n", 1);  /*  Write a newline character */
    }
    return (0);
}

/**
 * echo_bul - Execute echo cases
 * @st: Status of the last command executed
 * @cmd: Parsed command
 * Return: Always 1 Or execute normal echo
 */
int echo_bul(char **cmd, int st)
{
    char *path;  /*  Variable to store the value of the PATH environment variable */
    unsigned int pid = getppid();  /*  Get the parent process ID */

    /*  Check if the argument is "$?", representing the exit status of the last command */
    if (strncmp(cmd[1], "$?", 2) == 0)
    {
        prnt_num_int(st);  /*  Print the exit status as an integer */
        PRINT("\n");
    }
    /*  Check if the argument is "$$", representing the process ID of the shell */
    else if (strncmp(cmd[1], "$$", 2) == 0)
    {
        prnt_num(pid);  /*  Print the process ID of the shell */
        PRINT("\n");
    }
    /*  Check if the argument is "$PATH", representing the value of the PATH environment variable */
    else if (strncmp(cmd[1], "$PATH", 5) == 0)
    {
        path = getenv("PATH");  /*  Get the value of the PATH environment variable */
        PRINT(path);  /*  Print the value of PATH */
        PRINT("\n");
        free(path);  /*  Free the allocated memory for the path */
    }
    /*  If none of the special cases, execute the normal echo */
    else
        return (prnt_echo(cmd));

    return (1);
}

/**
 * history_dis - Display history of user input on the simple_shell
 * @c: Parsed command
 * @st: Status of the last command executed
 * Return: 0 success or -1 if fail
 */
int history_dis(__attribute__((unused)) char **c, __attribute__((unused)) int st)
{
    char *filename = ".simple_shell_history";  /*  Name of the history file */
    FILE *fp;  /*  File pointer for reading the history file */
    char *line = NULL;  /*  Buffer for storing each line from the history file */
    size_t len = 0;  /*  Variable to store the length of the line */
    int counter = 0;  /*  Counter for numbering the history entries */
    char *er;  /*  String representation of the counter */

    /*  Open the history file for reading */
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return (-1);  /*  Return -1 if opening the file fails */
    }
    /*  Read each line from the history file */
    while ((_getline(&line, &len, fp)) != -1)
    {
        counter++;  /*  Increment the counter for each history entry */
        er = itoa(counter);  /*  Convert the counter to a string */
        PRINT(er);  /*  Print the counter */
        free(er);  /*  Free the allocated memory for the counter string */
        PRINT(" ");
        PRINT(line);  /*  Print the history entry */
    }
    /*  Free the memory allocated for the line buffer */
    if (line)
        free(line);
    fclose(fp);  /*  Close the history file */
    return (0);
}
