#ifndef MAIN_H
#define MAIN_H


#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>




/* Function prototypes */
int main_getenv(void);
int main_fork(void); /* Updated function name */
int main_pathdir(void);
int main_pid(void);
int main_ppid(void);
int printac(int argc, char *argv[]);
int printdir(void);
void print_path_directories(void);
int main_printpath(void);
int set_env(void);
char *_strtok(char *str, const char *delim);
int _unsetenv(const char *name);
int main_unsetenv (void);
int main_strok(void);

typedef int pid_t;







#endif