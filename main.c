#include "shell.h"

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t characters;

    printf("$ ");

    characters = getline(&line, &bufsize, stdin);

    if (characters == -1)
    {
        perror("getline");
        exit(EXIT_FAILURE);
    }

    printf("You entered: %s", line);

    free(line);

    return 0;
}
