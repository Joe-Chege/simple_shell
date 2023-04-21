#include "main.h"
/**
 * print_path_directories - Print directories in PATH environment variable
 */
/* void print_path_directories(void)
{
    char *path = getenv("PATH");
    char *dir = strtok(path, ":");

    if (path == NULL)
    {
        perror("getenv");
        return;
    }

    while (dir != NULL)
    {
        printf("%s\n", dir);
        dir = strtok(NULL, ":");
    }
} */

int main_printpath(void)
{
    unsigned int i;
    struct stat st;
    char *av[] = {"main", "file_path", NULL};

    if (av[1] == NULL)
    {
        printf("Usage: %s path_to_file ...\n", av[0]);
        return (1);
    }
    i = 1;
    while (av[i])
    {
        printf("%s:", av[i]);
        if (stat(av[i], &st) == 0)
        {
            printf(" FOUND\n");
        }
        else
        {
            printf(" NOT FOUND\n");
        }
        i++;
    }
    return (0);
}
