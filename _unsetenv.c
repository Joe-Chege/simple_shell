#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * _unsetenv - Deletes an environment variable
 * @name: Name of the environment variable to delete
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
    if (name == NULL)
        return -1;

    size_t name_len = strlen(name);
    char **env = environ;

    
    while (*env != NULL)
    {
        if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
        {
            
            char **ptr = env;
            while (*ptr != NULL)
            {
                *ptr = *(ptr + 1);
                ptr++;
            }
            return 0;
        }
        env++;
    }

    return 0;
}
