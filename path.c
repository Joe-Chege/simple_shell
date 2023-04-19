#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

/**
 * print_path_directories - Print directories in PATH environment variable
 */
void print_path_directories(void)
{
    char *path = getenv("PATH");
    if (path == NULL)
    {
        perror("getenv");
        return;
    }

    char *dir = strtok(path, ":");
    while (dir != NULL)
    {
        printf("%s\n", dir);
        dir = strtok(NULL, ":");
    }
}
