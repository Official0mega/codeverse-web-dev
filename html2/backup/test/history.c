#include "../include/shell.h"

/**
 * history - Writes user inputs to a history file
 * @input: User input to be written
 * Return: 1 on success, -1 if failed
 */
int history(char *input)
{
    /* File name for the history file */
    char *filename = ".simple_shell_history";

    /* File descriptor, bytes written, and input length variables */
    ssize_t fd, w;
    int len = 0;

    /* Check if the filename is valid */
    if (!filename)
        return (-1);

    /* Open the history file with create, read/write, and append flags, and set permissions to 600 */
    fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
    if (fd < 0)
        return (-1);

    /* Check if input is provided */
    if (input)
    {
        /* Calculate the length of the input */
        while (input[len])
            len++;

        /* Write the input to the history file */
        w = write(fd, input, len);
        if (w < 0)
            return (-1);
    }

    /* Return success status */
    return (1);
}
