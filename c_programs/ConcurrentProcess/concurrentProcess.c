/**
 * @file concurrentProcess.c
 * @author Braiden Gole
 * @brief This is a program about "concurrent processes" in C.
 *        The idea is from a "Book on C." Otherwise known as fork().
 *
 *        [IMPORTANT]: A parent has the ability to instantiate a child process
 *                     which will run separately this kind of functionality should be
 *                     used if you need to handle something in the background like maybe
 *                     a URL request, handling database operations, or a lookup for example
 *                     anything that takes time but we can continue with something else.
 *
 *        [NOTE]: (Developing on Linux) [Parrot 64 Bit OS / Debian]
 *        --------------------------------------------------------------------------
 *        [SOURCE/BOOK]: AL KELLY, IRA POHL ["A Book on C"] Fourth edition page 555.
 *        --------------------------------------------------------------------------
 *
 * [IMPORTANT]: In order to run files on the linux platform we compile them roughly
 *              the same way but to run them we have to have a "./executable"
 *              I made an executable called "test" so to run my program it will be:
 * 
 *              ./test
 *
 * Using GCC to compile my program: gcc -o test cloneProcess.c -Wall
 *
 * [INFORMATION]: fork() will created separate processes at the rate of 2^(calls to fork())
 *                so an example of this would be if you call fork() [4] times then we will
 *                have 2^4 = 16 Child processes created.
 * @version 0.1
 * @date 2021-01-26
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ACTIVEPROCESSES "ps -aux | more"
#define PROCESSCREATED "\n\tProcess created !\n"
#define REJECTEDPROCESS "\n\t> The process has been rejected !\n"
#define PROMPT "\n\tWould you like to create more processes y/n: "
#define ZERO 0
#define K100BYTES 100

#define _STRING_FORMAT "%s"

// Function prototypes.
void cloneProcess();

// Global variable.
int processStarted;

int main(void)
{   
    // Check the status of active processes.
    system(ACTIVEPROCESSES);
    
    // If we return 0 then the child process has been succesfully created.
    // This will create 16 processes but that does not mean that all of them will be
    // created each time the program is ran the amount of successfully created children
    // can vary in range depending on conditions of the operating system.
    putchar('\n');
    const int CALLSTOFORK = 4;
    int numberOfCalls = 0;

    while (numberOfCalls < CALLSTOFORK) {
        processStarted = fork();
        if (processStarted == ZERO)
        {
            fprintf(stdout, _STRING_FORMAT, PROCESSCREATED);
            cloneProcess();
        }
        else
        {   
            // Creation of a child process was unfortunately rejected.
            fprintf(stderr, _STRING_FORMAT, REJECTEDPROCESS);
        }
        ++numberOfCalls;
    }
    return ZERO;
}

/**     -- Function header comment
 *  FUNCTION        :   cloneProcess
 *  DESCRIPTION     :   This function contains what should happen when fork
 *                      gets called.
 *  PARAMETERS      :   None
 *  RETURNS         :   None
 */
void cloneProcess()
{   
    printf("\t[CLONED]\n\n");
}
