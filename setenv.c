#include "shell.h"

/**
 * _setenv - Changes or adds an environment variable
 * @name: Name of the environment variable
 * @value: Value to set for the environment variable
 * @overwrite: Flag to indicate if existing variable should be overwritten
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
    char *new_env_var;

    size_t name_len = strlen(name);
    size_t value_len = strlen(value);
    char *env_var = getenv(name);

    if (name == NULL || value == NULL)
        return -1;

    

   
    if (env_var != NULL && overwrite == 0)
        return 0;

    
    new_env_var = malloc(name_len + value_len + 2);
    if (new_env_var == NULL)
    {
        perror("malloc");
        return -1;
    }
    snprintf(new_env_var, name_len + value_len + 2, "%s=%s", name, value);

    
    if (overwrite != 0)
        return putenv(new_env_var);

    return 0;
}
int set_env(void)
{
    int result;

    result = _setenv("MY_VARIABLE", "my_value", 1);
    if (result == -1)
    {
        printf("Failed to set environment variable.\n");
        return 1;
    }

    printf("Environment variable set successfully.\n");

    return 0;
}
