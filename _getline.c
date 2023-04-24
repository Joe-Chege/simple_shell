#include "shell.h"

/**
 * _getline - Reads a line of input from the user
 *
 * Return: Pointer to the line of input, or NULL on failure
 */
char *_getline(void)
{
    char *line = NULL;
    ssize_t bufsize = 0;
    ssize_t characters;

    printf("$ "); 

    characters = getline(&line, &bufsize, stdin);

    if (characters == -1)
    {
        perror("getline");
        return NULL;
    }

    return line;
}
