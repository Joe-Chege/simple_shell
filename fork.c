#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    int i;
    pid_t child_pid;

    for (i = 0; i < 5; i++)
    {
        child_pid = fork(); 

        if (child_pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0)
        {
           
            printf("Child process %d executing ls -l /tmp\n", getpid());

            
            execl("/bin/ls", "ls", "-l", "/tmp", NULL);

            
            perror("execl");
            exit(EXIT_FAILURE);
        }
        else
        {
            
            printf("Parent process %d created child process %d\n", getpid(), child_pid);

            
            wait(NULL);
        }
    }

    return 0;
}
