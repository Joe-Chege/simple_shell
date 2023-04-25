#include "shell.h"

/**
 * print_path_directories - Prints each directory in PATH environment variable
 */
void print_path_directories(void)
{
    
    char *path = getenv("PATH");
    char *path_copy = strdup(path);

    char *dir = strtok(path_copy, ":");
    
    if (path == NULL)
    {
        perror("Error: PATH environment variable not set");
        return;
    }

    
    
    while (dir != NULL)
    {
        printf("%s\n", dir);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
}

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int printdir(void)
{
    print_path_directories();

    return 0;
}
