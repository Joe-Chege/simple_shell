#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _unsetenv - Delete a variable from the environment
 * @name: The name of the variable to delete
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
    
    if (name == NULL || *name == '\0')
        return -1;

    
    extern char **environ;
    char **env = environ;
    while (*env != NULL)
    {
        
        if (strncmp(*env, name, strlen(name)) == 0 && (*env)[strlen(name)] == '=')
        {
            
            for (char **p = env; *p != NULL; p++)
                *p = *(p + 1);
            return 0;
        }
        env++;
    }

    
    return -1;
}

int main(void)
{
    // Example usage of _unsetenv function
    printf("Before unset:\n");
    printf("MY_VARIABLE1=%s\n", getenv("MY_VARIABLE1"));
    printf("MY_VARIABLE2=%s\n", getenv("MY_VARIABLE2"));

    // Delete a variable from the environment
    _unsetenv("MY_VARIABLE1");

    printf("After unset:\n");
    printf("MY_VARIABLE1=%s\n", getenv("MY_VARIABLE1"));
    printf("MY_VARIABLE2=%s\n", getenv("MY_VARIABLE2"));

    return 0;
}
