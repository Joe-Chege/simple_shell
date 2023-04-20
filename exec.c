#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/**
 * my_execve - Custom implementation of execve system call.
 * @filename: Name of the executable file to be executed.
 * @argv: Array of arguments to be passed to the new program.
 * @envp: Array of environment variables to be passed to the new program.
 *
 * Return: On success, this function does not return. On failure, -1 is returned
 *         and errno is set appropriately.
 */
int my_execve(const char *filename, char *const argv[], char *const envp[])
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		/* Child process */

		/* Replace the current process image with a new program */
		if (execve(filename, argv, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */

		/* Exit without waiting for child process to terminate */
		exit(EXIT_SUCCESS);
	}

	return 0;
}

int main(void)
{
	/* Example usage of my_execve function */

	const char *filename = "/bin/ls";
	char *const argv[] = {"ls", "-l", NULL};
	char *const envp[] = {NULL};

	my_execve(filename, argv, envp);

	return 0;
}
