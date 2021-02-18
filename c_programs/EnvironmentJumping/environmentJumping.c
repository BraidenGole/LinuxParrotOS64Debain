/**
 * @file environmentJumping.c
 * @author Braiden Gole
 * @brief This is a sample on how to use setjmp() and longjmp() in
 *        the C programming language.
 *
 *        The setjmp() function is used like a reference point to
 *        revert to after longjmp() has been called. When longjmp()
 *        gets called we write the corresponding data and then revert
 *        back to a specific line of code to where setjmp() was initially called.
 * @version 0.1
 * @date 2021-02-18
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <setjmp.h>

#define MAXJUMPLIMIT 4096
#define ZERO 0
#define __EQ__ ==
#define __NEQ__ !=

// Function prototypes.
void revertToReferencePoint(jmp_buf environmentSpace, int referenceValue);

int main(void)
{   
    // Store the enviroment buffer in a type that is suitable
    // for storing data involving an environment restore point.
    jmp_buf environmentBuffer;

    int environmentValue = ZERO;
    int changeValueTo = ZERO;

    // Mark the point of reference here.
    environmentValue = setjmp(environmentBuffer);
    if (environmentValue __EQ__ ZERO)
    {
        fprintf(stdout, "\n\tStarting value is: %i", environmentValue);
    }
    else if (environmentValue __NEQ__ ZERO)
    {
        fprintf(stdout, "\n\tReference point value: %i\n", environmentValue);
        return ZERO;
    }

    // Write to the "point of reference" and then revert back to that point.
    fprintf(stdout, "\n\n\tChange (starting value) to: ");
    if ((fscanf(stdin, "%i", &changeValueTo)) == ZERO)
    {
        fprintf(stdout, "\n\tNo characters allowed for the value to change !\n");
        fflush(stdin);
    }

    // Call the jump here.
    revertToReferencePoint(environmentBuffer, changeValueTo);
    return ZERO;
}

/**     -- Function header comment
 *  FUNCTION        :   revertToReferencePoint
 *  DESCRIPTION     :   This is our setjmp() function that will be 
 *                      to fill the buffer at the time of reference.
 *  PARAMETERS      :   environmentSpace, referenceValue
 *  RETURNS         :   None
 */
void revertToReferencePoint(jmp_buf environmentSpace, int referenceValue)
{
    longjmp(environmentSpace, referenceValue);
}