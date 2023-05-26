#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 * handle_signal - Handles signals
 *
 * @signal_ID: The signal identifier to handle
 *
 * Description: This function handles a given signal identifier by writing a
 * prompt to standard output.
 *
 * Return: void
 */
void handle_signal(int signal_ID)
{
if (signal_ID == SIGINT)
write(STDOUT_FILENO, "\n($) ", 5);
}
