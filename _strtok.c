#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * split_string - Splits a string into an array of words.
 * @str: The string to be split.
 * @delim: The delimiter used to split the string.
 *
 * Return: An array of words (tokens) obtained from the string. The last element
 *         in the array is NULL.
 */
char **split_string(char *str, const char *delim)
{
    char **tokens = NULL;
    char *word = NULL;
    int num_tokens = 0;
    int i = 0;

    
    if (str == NULL || delim == NULL)
        return NULL;

    
    for (i = 0; str[i] != '\0'; i++)
    {
        if (strchr(delim, str[i]) != NULL && (i == 0 || strchr(delim, str[i - 1]) == NULL))
            num_tokens++;
    }

    
    tokens = malloc((num_tokens + 1) * sizeof(char *));
    if (tokens == NULL)
        return NULL;

    
    word = strtok(str, delim);
    i = 0;
    while (word != NULL)
    {
        tokens[i] = word;
        i++;
        word = strtok(NULL, delim);
    }

    
    tokens[i] = NULL;

    return tokens;
}

int main(void)
{
    char str[] = "Hello world! How are you?";
    const char delim[] = " !?";
    char **words = split_string(str, delim);

    printf("Original string: %s\n", str);
    printf("Words:\n");
    for (int i = 0; words[i] != NULL; i++)
    {
        printf("%s\n", words[i]);
        free(words[i]); 
    }
    free(words); 

    return 0;
}
