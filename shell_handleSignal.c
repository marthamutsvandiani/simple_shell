#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 * handle_signal - Handles signals
 *
 * @signalID: The signal identifier to handle
 *
 * Description: This function handles a given signal identifier by writing a
 * prompt to standard output.
 *
 * Return: void
 */
void handle_signal(int signalID)
{
if (signalID == SIGINT)
write(STDOUT_FILENO, "\n($) ", 5);
}
