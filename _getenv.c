#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _getenv - Get the value of an environment variable
 * @name: The name of the environment variable
 *
 * Return: Pointer to the value of the environment variable, or NULL if not found
 */
char *_getenv(const char *name)
{
    
    if (name == NULL || *name == '\0')
        return NULL;

    
    extern char **environ;
    char **env = environ;
    while (*env != NULL)
    {
        
        if (strncmp(*env, name, strlen(name)) == 0 && (*env)[strlen(name)] == '=')
        {
            
            return *env + strlen(name) + 1;
        }
        env++;
    }

    
    return NULL;
}

int main(void)
{
    // Example usage of _getenv function
    char *value = _getenv("MY_VARIABLE");
    if (value != NULL)
        printf("MY_VARIABLE=%s\n", value);
    else
        printf("MY_VARIABLE not found\n");

    return 0;
}
