#include <stdio.h>
#include <unistd.h>
#include "main.h"
/**
 * main_pid - Print the current process ID (PID)
 *
 * Return: Always 0.
 */

int main_pid(void)
{
    pid_t my_pid;

    my_pid = getpid();
    printf("%u\n", my_pid);
    return (0);
}
