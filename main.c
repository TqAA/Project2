/*
Author: Boev Maxim
 Calculator with 6 basic functions
 The user must select one of the allowable operations and 2 numbers, then the calculator will make calculations and prompt the user to continue or stop working
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main (void)
{
    printf (" Hello!\n");
    printf (" This program performs the selected operation between two numbers \n" );
    printf (" To be successful, you must first enter the operation and then the 2 numbers [ 1 in the case of the factorial] \n" );
    printf (" Available operations :addition(+), subtraction(-), multiplication(*), division(/ ), exponentiation(^), factorial(!), vector(v) \n" );
    
    // Entering variables
    double num1, num2; // Numbers entered by the user from the keyboard
    double res; // The result of the operation
    char operation; // Type of operation
    char operationv;
    char consent; // Reset to resume operation after the end of the program (if the user wishes)
    double *A, *B; //
    int size; 
    double resv; //
    do // Cycle for resuming work after the end of the program
    {
        setvbuf (stdout, NULL, _IONBF, 0);
        setvbuf (stderr, NULL, _IONBF, 0);
        // Choice of operation
        printf ("\n Select an operation ( +, -, *, /, ^, !):");
        scanf (" %c", &operation);
        
        // operation
        switch (operation)
        {
        case 'v': // Operations with vectors
            printf("Enter the size of the vectors: ");
            scanf("%i", &size);
            A = malloc(size * sizeof(int));
            B = malloc(size * sizeof(int));
            printf("Enter the coordinates of the first vector: ");
            for (int i = 0; i < size; i++) scanf("%lf", &A[i]);
            printf("Enter the coordinates of the second vector: ");
            for (int i = 0; i < size; i++) scanf("%lf", &B[i]);
            printf("Enter one of the provided operations for vectors: (+),(-),(*): ");
            scanf(" %c", &operationv);
            switch (operationv)
            {
            case '+': // Addition operation with vectors
                printf("Addition of vectors: ");
                for (int i = 0; i < size; i++) printf("%lf ", A[i] + B[i]);
                printf("\n");
                break;
            case '-': // Subtraction operation with vectors
                printf("Subtracting vectors: ");
                for (int i = 0; i < size; i++) printf("%lf ", A[i] - B[i]);
                printf("\n");
                break;
            case '*': // Scalar product operation with vectors
                printf("Scalar product of vectors: ");
                for (int i = 0; i < size; i++) printf("%lf ", A[i] * B[i]);
                printf("\n");
                break;
            default: // In the case of an incorrectly selected operation
                printf("Error 404!");
            }
            free(A); // Releasing used memory
            free(B);
            break;
            // Function for adding numbers
        case '+':
            printf ("\nEnter the first number:");
            scanf (" %lf", &num1);
            printf ("\nEnter the second number:");
            scanf (" %lf", &num2);
            res = num1 + num2;
            printf ("\n%lf + %lf = %lf", num1, num2, res);
            break;

            // Function for subtracting numbers
        case '-':
            printf ("\nEnter the first number:");
            scanf (" %lf", &num1);
            printf ("\nEnter the second number:");
            scanf (" %lf", &num2);
            res = num1 - num2;
            printf ("\n%lf - %lf = %lf", num1, num2, res);
            break;

            // Function for multiplying numbers
        case '*':
            printf ("\nEnter the first number:");
            scanf (" %lf", &num1);
            printf ("\nEnter the second number:");
            scanf (" %lf", &num2);
            res = num1 * num2;
            printf ("\n%lf * %lf = %lf", num1, num2, res);
            break;

            // Function for dividing numbers
        case '/':
            printf ("\nEnter the first number:");
            scanf (" %lf", &num1);
            printf ("\nEnter the second number  :");
            scanf (" %lf", &num2);
            res = num1 / num2;
            if (num2 == 0) printf ("Делить на ноль нельзя!");
            else printf ("\n%lf / %lf = %lf", num1, num2, res);
            break;

            // A function for the exponentiation of a number
        case '^':
            printf ("\nEnter the first number:");
            scanf (" %lf", &num1);
            printf ("\nEnter the second number:");
            scanf (" %lf", &num2);
            double numb1 = num1;
            if (num2 == 0) {
                printf ("\n %lf^%lf= 1", num1, num2);
            }
            else if (num2 == 1) {
                printf ("\n %lf^%lf= %lf", num1, num2, num1);
            }
            else if (num2 == -1) {
                res = 1 / num1;
                printf ("\n %lf^%lf=%lf", num1, num2, res);
            }
            else if (num2 < 0) {
                num2 *= -1;
                for (int i = 1; i < num2; i++)
                {
                    num1 = num1 * numb1;
                    res = 1/num1;
                }
                printf ("\n%lf ^ %lf = %lf", numb1, num2, res);
            }
            else if (num2>0) {

                for (int i = 1; i < num2; i++)
                {
                    num1 = num1 * numb1;
                    res = num1;
                }
                printf ("\n%lf ^ %lf = %lf", numb1, num2, res);
            }
            
            break;

            // Function for finding the factorial of a number 
        case '!':
            printf ("\nEnter the number:");
            scanf (" %lf", &num1);
            double numv1 = num1;
            if (num1 > 0) for (int i = 1; i < numv1; i++)
            {
                num1 = num1 * (numv1 - i);
            }
            if (num1 == 0) printf ("0! = 1");
            else if (num1 < 0) printf ("Undefined");
            else printf ("\n%lf! = %lf", numv1, num1);
            break; 
         // In the case of an incorrectly selected operation
        default:
            printf("\nOperation selection error");
        }
        // Consent/refusal to continue working with the program
        printf ("\nWould you like to continue? Yes=y,No=n:");
        scanf (" %c", &consent);
        // Continuation condition
    } while (consent == 'y');
    // Condition of completion
    if (consent == 'n') printf("\nGoodbye!");
    else printf ("\nOperation selection error");
    return 0;
}