#include "../include/shell.h"

/**
 * all_help - Displays all possible builtin Shellby commands
 */
void all_help(void)
{
    /*  Define the help message for all builtin commands */
    char *msg = "Shellby\nThese shell commands are defined internally.\n";

    /*  Write the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "Type 'help' to see this list.\nType 'help name' to find ";
    /*  Write the second part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "out more about the function 'name'.\n\n  alias   \t";
    /*  Write the third part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "alias [NAME[='VALUE'] ...]\n  cd    \tcd   ";
    /*  Write the fourth part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
    /*  Write the fifth part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
    /*  Write the sixth part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "unsetenv [VARIABLE]\n";
    /*  Write the seventh part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * alias_help - Displays information on the shell by builtin command 'alias'
 */
void alias_help(void)
{
    /*  Define the help message for the 'alias' command */
    char *msg = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";

    /*  Write the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "\n\talias: Prints a list of all aliases, one per line, in ";
    /*  Write the second part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "the format NAME='VALUE'.\n\talias name [name2 ...]:prints";
    /*  Write the third part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = " the aliases name, name2, etc. one per line, in the ";
    /*  Write the fourth part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: Defines";
    /*  Write the fifth part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = " an alias for each NAME whose VALUE is given. If NAME ";
    /*  Write the sixth part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "is already an alias, replace its value with VALUE.\n";
    /*  Write the seventh part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_cd - Displays information on the shell by builtin command 'cd'
 */
void cd_help(void)
{
    /*  Define the help message for the 'cd' command */
    char *msg = "cd: cd [DIRECTORY]\n\tChanges the current directory of the";

    /*  Write the first part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = " process to DIRECTORY.\n\n\tIf no argument is given, the ";
    /*  Write the second part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "command is interpreted as cd $HOME. If the argument '-' is";
    /*  Write the third part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = " given, the command is interpreted as cd $OLDPWD.\n\n";
    /*  Write the fourth part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "\tThe environment variables PWD and OLDPWD are updated ";
    /*  Write the fifth part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "after a change of directory.\n";
    /*  Write the sixth part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_exit - Displays information on the shell by builtin command 'exit'
 */
void exit_help(void)
{
    /*  Define the help message for the 'exit' command */
    char *msg = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";

    /*  Write the first part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "STATUS argument is the integer used to exit the shell.";
    /*  Write the second part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = " If no argument is given, the command is interpreted as";
    /*  Write the third part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = " exit 0.\n";
    /*  Write the fourth part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_help - Displays information on the shell by builtin command 'help'
 */
void helpers(void)
{
    /*  Define the help message for the 'help' command */
    char *msg = "help: help\n\tSee all possible Shellby builtin commands.\n";

    /*  Write the first part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "\n      help [BUILTIN NAME]\n\tSee specific information on each ";
    /*  Write the second part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
    msg = "builtin command.\n";
    /*  Write the third part of the help message to STDOUT */
    write(STDOUT_FILENO, msg, _strlen(msg));
}