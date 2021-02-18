/**
 * @file signalHandling.c
 * @author Braiden Gole
 * @brief This is a sample on signals in the C programming language.
 * --------------------------------------------------------------------------
 * [SOURCE/BOOK]: AL KELLY, IRA POHL ["A Book on C"] Fourth edition page 650.
 * --------------------------------------------------------------------------
 * This is a demonstration of signals in C. Signals are used as a form of exception
 * handling as well as a form of communication between the user and the console application.
 * With signals we are able to detect and handle when the user types a CTRL + C characters to
 * abruptly end a program during execution. We can also handle many other situations it all
 * depends on the conditions that the program is in a signal can happen anywhere in a program.
 *
 * Comment out the "CODE BLOCKS" to print out different signals.
 * @version 0.1
 * @date 2021-02-17
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>

#define UNSUCCESSFUL "\nUnsuccessful !"
#define ZERO 0
#define ERROR -1

// Function prototypes.
void typeOfSignalHandler(int signalCode);
void signalCtrlCTerminationHandler(int signalCode);
const int setSignals(void);
void divisionByZero(int signalCode);

// Global variable.
bool ctrlCstatus = true;

int main(void)
{   
    setSignals();

    int pid = fork();
    printf("\tPID: %i\n", pid);

    // Check the value of the processID.
    if (pid > ZERO)
    {   
        // [CODE BLOCK #1]
        bool infiniteLoop = true;
        while (infiniteLoop)
        {   
            // Sleep for one second to reduce system load.
            printf("\nRepeated message !\n");
            sleep(1);
        }
        // [END CODE BLOCK #1]

        // [CODE BLOCK #2]
        double amount = 19.99;
        int result = amount / ZERO;
        raise(SIGFPE);
        // [END CODE BLOCK]
    }

    return ZERO;
}

/**     -- Function header comment
 *  FUNCTION        :   typeOfSignalHandler
 *  DESCRIPTION     :   This function will tell you the specific type
 *                      of signal read from a event.
 *  PARAMETERS      :   signalCode
 *  RETURNS         :   None
 */
void typeOfSignalHandler(int signalCode)
{
    switch (signalCode)
    {
        case 2:
            printf("INTERRUPT");
            break;
        case 4:
            printf("ILLEGAL INSTRUCTION");
            break;
        case 8:
            printf("FLOATING-POINT EXCEPTION");
            break;
        case 11:
            printf("SEGMENT VIOLATION");
            break;
        case 15:
            printf("ASYNCHRONOUS");
            break;
        case 22:
            printf("ABORT");
            break;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   signalCtrlCTerminationHandler
 *  DESCRIPTION     :   This function will handle a interrupt signal for
 *                      when the user presses CTRL + C in the console.
 *  PARAMETERS      :   None
 *  RETURNS         :   None
 */
void signalCtrlCTerminationHandler(int signalCode)
{
    ctrlCstatus = false;
    printf("\n\tCTRL + C was pressed !\n");
    exit(ZERO);
}

/**     -- Function header comment
 *  FUNCTION        :   divisionByZero
 *  DESCRIPTION     :   This is a function to show a floating-point
 *                      exception signal.
 *  PARAMETERS      :   signalCode
 *  RETURNS         :   None
 */
void divisionByZero(int signalCode)
{
    printf("\n\tDivisionByZero Exception !\n");
    exit(ZERO);
}

/**     -- Function header comment
 *  FUNCTION        :   setSignals
 *  DESCRIPTION     :   This function is made as a code block to keep the sanity
 *                      checks for each signal nice at neat in the main function.
 *  PARAMETERS      :   None
 *  RETURNS         :   None
 */
const int setSignals(void)
{
    // Set the signals.
    if ((signal(SIGINT, typeOfSignalHandler)) == SIG_ERR)
    {
        fprintf(stderr, "The signal handler was not set !\n");
        return ERROR;
    }

    if ((signal(SIGINT, signalCtrlCTerminationHandler)) == SIG_ERR)
    {
        fprintf(stderr, "The signal handler was not set !\n");
        return ERROR;
    }

    if ((signal(SIGFPE, divisionByZero)) == SIG_ERR)
    {
        fprintf(stderr, "The signal handler was not set !\n");
        return ERROR;
    }
    return ZERO;
}