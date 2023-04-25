#include "globals.h"
#include "shell.h"

/**
 * sig_handler - handles the interrupt signal caused by pressing ^C
 * @uuv: unused variable (required for signal function prototype)
 *
 * Return: void
 */
void sig_handler(int uuv)
{
        (void) uuv;
        if (sig_flag == 0)
                _puts("\n$ ");
        else
                _puts("\n");
}
