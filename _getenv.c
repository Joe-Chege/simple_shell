#include "main.h"

/**
 * _getenv - Get the value of an environment variable
 * @name: The name of the environment variable
 *
 * Return: Pointer to the value of the environment variable, or NULL if not found
 */
char *_getenv(const char *name)
{
    

    extern char **environ;
    char **env = environ;


    if (name == NULL || *name == '\0')
        return NULL;

    
    
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

int main_getenv(void)
{
    char *value = _getenv("MY_VARIABLE");
    if (value != NULL)
        printf("MY_VARIABLE=%s\n", value);
    else
        printf("MY_VARIABLE not found\n");

    return 0;
}
