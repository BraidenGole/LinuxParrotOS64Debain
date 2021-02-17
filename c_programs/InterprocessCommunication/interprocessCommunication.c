/**
 * @file interprocessCommunication.c
 * @author Braiden Gole
 * @brief This is a demonstration on interprocess communication
 *        in the C programming language.
 * --------------------------------------------------------------------------
 * [SOURCE/BOOK]: AL KELLY, IRA POHL ["A Book on C"] Fourth edition page 561.
 * --------------------------------------------------------------------------
 * We will be using a function called pipe(), pipe() assumse once a "descriptor"
 * is created is a requirement that we have two other concurrent processes using
 * fork() that are ongoing and that we use the index of the pipe descriptor as a
 * was of either a) pd[0] = "Read permissions", pd[1] = "Write permissions".
 *
 * The concurrent data should be written and/or read from the file descriptor.
 *
 * This demonstrates how to write into a file descriptor writting data concurrently to
 * the descriptor. We must make sure that we close one end if we are not using such as if
 * we are writting we do not need to read at this moment so close your resources for now.
 * 
 * @version 0.1
 * @date 2021-02-16
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define KSIZEOFDESCRIPTOR 2
#define SOMETHINGWENTWRONG "\nSomething went wrong !\n"
#define NOCHARACTERS "\nNo characters !\n"
#define PROMPT "Enter in a number: "

#define ZERO 0
#define ERROR -1
#define ONE 1

// Permissions.
#define READ 0
#define WRITE 1

int main(void)
{   
    int pipeDescriptor[KSIZEOFDESCRIPTOR] = { ZERO };

    int descriptorWasCreated = pipe(pipeDescriptor);
    if (descriptorWasCreated == ERROR)
    {
        fprintf(stderr, "\nDescriptor was not created !\n");
        return ERROR;
    }
    else
    {   
        int number = 0;
        int processId = fork();
        if (processId == ZERO)
        {
            printf(PROMPT);
            if ((fscanf(stdin, "%i", &number)) == ZERO)
            {
                fprintf(stderr, NOCHARACTERS);
                fflush(stdin);
            }
            else
            {   
                // Close read permission becuase it is not active at this moment.
                close(pipeDescriptor[READ]);
                if ((write(pipeDescriptor[WRITE], &number, sizeof(int))) == ERROR)
                {
                    fprintf(stderr, SOMETHINGWENTWRONG);
                    return ERROR;
                }

                // We are finished with writting to the descriptor, close resources.
                close(pipeDescriptor[WRITE]);
            }
        }
        else
        {   
            // Read in the value that was written in [1] = [WRITE].
            int readInValue = ZERO;
            if ((read(pipeDescriptor[READ], &readInValue, sizeof(int))) == ERROR)
            {
                fprintf(stderr, SOMETHINGWENTWRONG);
                return ERROR;
            }

            // Display the value read into the variable from the descriptor.
            printf("\nValue entered: %i\n", readInValue);
        }
    }
    return ZERO;
}