#include "main.h"

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success
 */
int printac_main(int argc, char *argv[])
{
	int i = 0;

	(void)argc; 

	while (argv[i] != NULL)
	{
		printf("Argument %d: %s\n", i + 1, argv[i]);
		i++;
	}

	return 0;
}
