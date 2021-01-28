/**
 * @file overlayingProcess.c
 * @author Braiden Gole
 * @brief This is a sample on overlaying a process in the C programming language.
 *
 * [IMPROVED:] Circular doubly linked list implementation !
 * --------------------------------------------------------------------------------
 * (Overlaying a process: the exec...() Family)
 * [SOURCE/BOOK]: AL KELLY, IRA POHL ["A Book on C"] Fourth edition page 558 & 682.
 * ---------------------------------------------------------------------------------
 * This pre-processor directive is used to call other programs from a source or
 * main program driver.
 *
 * [NOTE:] "test" = CircularDoublyLinkedList
 *         "test2" = DoublyLinkedList
 * 
 * [IMPORTANT:] Preferably do not press CRTL + C in the command line to stop the
 *              programs. Please use the quit option listed !
 *
 * [NOTE:] The linux console renders differently when it comes to displaying text
 *         you may have to look at the selection menu displayed above from last selection 
 *         in order to add a new record to either the "process one" or "process two".
 * @version 0.1
 * @date 2021-01-27
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

#define SELECTA 'A'
#define SELECTB 'B'
#define QUIT 'C'

// Define some constants for the function calls.
#define PROCESSONE "test"
#define PROCESSTWO "test2"

int main(void)
{   
    char letterSelection = ' ';
    bool executeOrNot = true;

    do
    {   
        fprintf(stdout, "\n -- Process selection --\n");
        fprintf(stdout, "\tA. Process One.\n");
        fprintf(stdout, "\tB. Process Two.\n");
        fprintf(stdout, "\tC. Quit.\n\n");
        fprintf(stdout, "Select a process: ");

        letterSelection = getchar();
        letterSelection = toupper(letterSelection);

        // Catch the new-line character !
        getchar();
        if (letterSelection == QUIT)
        {
            break;
        }

        // Circular doubly linked list structure Or Doubly linked list.
        if (letterSelection == SELECTA)
        {   
            execl(PROCESSONE, PROCESSONE, NULL);
        }
        else if (letterSelection == SELECTB)
        {
            execl(PROCESSTWO, PROCESSTWO, NULL);
        }
    } while (executeOrNot);
    return 0;
}