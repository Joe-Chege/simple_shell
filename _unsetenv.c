#include "shell.h"

/**
 * _unsetenv - Delete a variable from the environment
 * @name: The name of the variable to delete
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
    extern char **environ;
    char **env = environ;
    char **p;
    if (name == NULL || *name == '\0')
        return -1;

    
    
    while (*env != NULL)
    {
        
        if (strncmp(*env, name, strlen(name)) == 0 && (*env)[strlen(name)] == '=')
        {
            
            for (p = env; *p != NULL; p++)
                *p = *(p + 1);
            return 0;
        }
        env++;
    }

    
    return -1;
}

int main_unsetenv (void)
{
    printf("Before unset:\n");
    printf("MY_VARIABLE1=%s\n", getenv("MY_VARIABLE1"));
    printf("MY_VARIABLE2=%s\n", getenv("MY_VARIABLE2"));

    _unsetenv("MY_VARIABLE1");

    printf("After unset:\n");
    printf("MY_VARIABLE1=%s\n", getenv("MY_VARIABLE1"));
    printf("MY_VARIABLE2=%s\n", getenv("MY_VARIABLE2"));

    return 0;
}
