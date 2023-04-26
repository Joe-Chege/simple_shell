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


/**
* make_env - make the shell environment from the environment passed to main
* @env: environment passed to main
*
* Return: pointer to the new environment
*/
char **make_env(char **env)
{
char **newenv = NULL;
size_t i;

for (i = 0; env[i] != NULL; i++)
;
newenv = malloc(sizeof(char *) * (i + 1));
if (newenv == NULL)
{
perror("Fatal Error");
exit(1);
}
for (i = 0; env[i] != NULL; i++)
newenv[i] = _strdup(env[i]);
newenv[i] = NULL;
return (newenv);
}

/**
* free_env - free the shell's environment
* @env: shell's environment
*
* Return: void
*/
void free_env(char **env)
{
unsigned int i;

for (i = 0; env[i] != NULL; i++)
free(env[i]);
free(env);
}