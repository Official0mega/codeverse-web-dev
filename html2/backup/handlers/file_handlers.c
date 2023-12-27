#include "../include/shell.h"

/**
 * read_file - Reads commands from the specified file and executes them.
 *
 * @file: File containing commands.
 * @argv: Command line arguments.
 */
void read_file(char *file, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int count = 0;

	/*  Open the file for reading */
	fp = fopen(file, "r");
	if (fp == NULL)
	{
		/*  Handle file opening error */
		error_file(argv, count);
		exit(127);
	}

	/*  Read lines from the file and process them */
	while ((getline(&line, &len, fp)) != -1)
	{
		count++;
		/*  Process each line from the file */
		treat_file(line, count, fp, argv);
	}

	/*  Free allocated memory and close the file */
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}

/**
 * execute_file - Parse commands and handle their execution for file input.
 *
 * @line: Line from the file.
 * @count: Error counter.
 * @fp: File descriptor.
 * @argv: Command line arguments.
 */
void execute_file(char *line, int count, FILE *fp, char **argv)
{
	char **cmd;
	int stat = 0;

	/*  Parse the command from the line */
	cmd = parse_cmd(line);

	/*  Check if the command is an exit command */
	if (_strncmp(cmd[0], "exit", 4) == 0)
		exit_bul_for_file(cmd, line, fp);
	else if (check_builtin(cmd) == 0)
	{
		/*  Handle built-in commands */
		stat = handle_builtin(cmd, stat);
		free(cmd);
	}
	else
	{
		/*  Check and execute external commands */
		stat = check_cmd(cmd, line, count, argv);
		free(cmd);
	}
}

/**
 * exit_status_file - Exit status handler for file input.
 *
 * @cmd: Parsed command.
 * @line: Line from a file.
 * @fd: File Descriptor.
 */
void exit_status_file(char **cmd, char *line, FILE *fd)
{
	int status;
	int i = 0;

	/*  Check if the command has an argument */
	if (cmd[i] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}

	/*  Validate the argument for exit command */
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
			perror("Illegal number");
	}

	/*  Convert the argument to an integer for exit status */
	status = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(status);
}
