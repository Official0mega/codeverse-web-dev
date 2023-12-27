#include "../include/shell.h"

/**
 * prnt_num - Recursively prints unsigned integers using _putchar function
 * @n: Unsigned integer to be printed
 */
void prnt_num(unsigned int n)
{
    unsigned int x = n;

    /* Recursively print digits */
    if ((x / 10) > 0)
        print_number(x / 10);

    putchar(x % 10 + '0');
}

/**
 * prnt_num_int - Recursively prints integers using _putchar function
 * @n: Integer to be printed
 */
void prnt_num_int(int n)
{
    unsigned int x = (n < 0) ? -n : n;

    /* Print '-' for negative numbers and recursively print digits */
    if (n < 0)
        _putchar('-');

    if ((x / 10) > 0)
        print_number(x / 10);

    _putchar(x % 10 + '0');
}

/**
 * prnt_echo - Executes the built-in echo function
 * @cmd: Parsed Command
 * Return: 0 Upon Success, -1 Upon Failure
 */
int prnt_echo(char **cmd)
{
    pid_t pid;
    int status;

    /* Fork a child process to execute echo */
    pid = fork();
    if (pid == 0)
    {
        /* Execute echo in the child process */
        if (execve("/bin/echo", cmd, environ) == -1)
        {
            return (-1);
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        return (-1);  /* Forking error */
    }
    else
    {
        /* Wait for the child process to complete */
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return (1);
}
