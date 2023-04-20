#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * print_path_directories - Prints each directory in PATH environment variable
 */
void print_path_directories(void)
{
    
    char *path = getenv("PATH");

    
    if (path == NULL)
    {
        perror("Error: PATH environment variable not set");
        return;
    }

    
    char *path_copy = strdup(path);

    // Use strtok to tokenize the directories in PATH based on ':' delimiter
    char *dir = strtok(path_copy, ":");
    while (dir != NULL)
    {
        printf("%s\n", dir);
        dir = strtok(NULL, ":");
    }

    // Free the dynamically allocated memory
    free(path_copy);
}

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
    // Call the function to print directories in PATH
    print_path_directories();

    return 0;
}
