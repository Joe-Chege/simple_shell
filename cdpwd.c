#include "shell.h"
#include <unistd.h>

/**
 * chdir_func - Changes the current working directory and prints it
 * @path: The path of the directory to change to
 *
 * Return: 0 on success, 1 on error
 */

int chdir_func(const char *path)
{
    if (chdir(path) == -1)
    {
        perror("chdir");
        return (1);
    }

    printf("Changed current working directory to: %s\n", path);
    return (0);
}

/**
 * get_cwd - Prints the current working directory
 *
 * Return: 0 on success, 1 on error
 */

int get_cwd(void)
{
    char buf[1024];
    char *cwd;

    if (getcwd(buf, sizeof(buf)) == NULL)
    {
        perror("getcwd");
        return (1);
    }

    printf("Current working directory: %s\n", buf);

    
    {
        perror("get_current_dir_name");
        return (1);
    }

    printf("Current working directory: %s\n", cwd);

    free(cwd);
    return (0);
}
