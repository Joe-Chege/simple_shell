#include "main.h"

/**
 * _strtok - Splits a string into an array of words.
 * @str: The string to be split.
 * @delim: The delimiter used to split the string.
 *
 * Return: A pointer to the first token found in the string.
 */
char *_strtok(char *str, const char *delim)
{
    static char *last_token = NULL;
    char *token = NULL;

    if (str != NULL)
        last_token = str;

    if (last_token == NULL)
        return NULL;

    token = strtok(last_token, delim);
    last_token = (token != NULL) ? token + strlen(token) : NULL;

    return token;
}

int main(void)
{
    int i;
    char str[] = "Hello world! How are you?";
    const char delim[] = " !?";
    char *token = NULL;

    printf("Original string: %s\n", str);
    printf("Words:\n");

    while ((token = _strtok(token == NULL ? str : NULL, delim)) != NULL)
    {
        printf("%s\n", token);
    }

    return 0;
}
