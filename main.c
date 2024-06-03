/**
 * @file main.c
 * @brief This file contains the main function of the program.
 *
 * The program is designed to manage a list of student accounts. It includes functions for adding,
 * removing, and searching for accounts.
 * The program also includes a callback function to handle errors and a function
 * to clear the console screen.
 *
 * @author Viet Ha Nguyen
 * @date 4/10/2024
 */

/*******************************************************************************
 * Include
 ******************************************************************************/
#include <stdio.h>             /* Include standard input and output library for printf, printf, ... */
#include <string.h>            /* For funtions such as strcpy(), strcmp(), NULL character */
#include "account_manage.h"    /* Include header file for managing a list of student accounts */

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
 * @brief The main function of the program.
 *
 * This function is the entry point of the program. It initializes the program and
 * starts the main loop.
 *
 * @return 0 if the program exits successfully.
 */
int main(void)
{
    int32_t choice = 0;         /* Initialize the choice variable to 0 */
    int8_t account[10];         /* Initialize the account variable to an array of 10 characters */
    status_enum_t status;       /* Initialize the status variable to a status_enum_t type */

    /* Set the status to CORRECT */
    status = CORRECT;
    /* Register the Show_Error function as a callback */
    RegisterCallback(Show_Error);

    /* Start a do-while loop */
    do
    {
        printf("\n");
        printf("*----------PROGRAM TO MANAGE LIST OF STUDENTS----------*\n");
        printf("|                                                      |\n");
        printf("| 1. Add an account to list                            |\n");
        printf("| 2. Remove an account from list                       |\n");
        printf("| 3. Display list of accounts                          |\n");
        printf("| 4. Find an account in list                           |\n");
        printf("| 5. Exit program                                      |\n");
        printf("|______________________________________________________|\n");
        printf("\n");

        printf("Please select your desired function: ");
        /* Flush the input buffer */
        fflush(stdin);
        /* Read the user's choice */
        scanf("%d", &choice);

        /* Start a switch statement based on the user's choice */
        switch (choice)
        {
            case 1:
            {
                do
                {
                    printf("\nEnter account to add: ");
                    /* Flush the input buffer */
                    fflush(stdin);
                    /* Read the user's account */
                    scanf("%s", account);

                    /* Check the validity of the user's account */
                    Check_Account(account, strlen(account));

                    /* Get the status of the user's account */
                    status = Get_Status();

                } /* Continue the loop until the account is correct */
                while (status != CORRECT);

                /* If the account does not exist in the list */
                if (!Is_Account_Exist(account))
                {
                    /* Add the account to the list */
                    Add_Account(account);
                    printf("\nAdded account '%s' to your list . . .\n", account);
                }
                /* If the account already exists in the list */
                else
                {
                    printf("\nError: Account is already exists. Please enter another account!!!\n");
                }
                /* Clear the console screen */
                clear_console();
                /* Exit the switch statement */
                break;
            }
            case 2:
            {
                printf("\nEnter account to remove: ");
                /* Flush the input buffer */
                fflush(stdin);
                /* Read the user's account */
                scanf("%s", account);
                /* If the account is successfully removed */
                if (Remove_Account(account) == 1)
                {
                    printf("\nDeleted account '%s' from your list . . .\n", account);
                }
                /* If the account is not found in the list */
                else if (Remove_Account(account) == 0)
                {
                    printf("\nError: Account '%s' not found in your list!!!\n", account);
                }
                /* If the user has not created any account yet */
                else
                {
                    printf("\nYou have not created any account yet!!!\n");
                    printf("Please enter account first.\n");
                }
                /* Clear the console screen */
                clear_console();
                /* Exit the switch statement */
                break;
            }
            case 3:
            {
                /* Display the list of accounts */
                Display_ListAccounts();
                /* Clear the console screen */
                clear_console();
                /* Exit the switch statement */
                break;
            }
            case 4:
            {
                printf("\nEnter account that you want to search: ");
                /* Flush the input buffer */
                fflush(stdin);
                /* Read the user's account */
                scanf("%s", account);
                /* If the account is found in the list */
                if (Search_Account(account) == 1)
                {
                    printf("\nAccount '%s' is found in list . . .\n", account);
                }
                /* If the account is not found in the list */
                else if (Search_Account(account) == 0)
                {
                    printf("\nAccount '%s' is not in list . . .\n", account);
                }
                /* If the user has not created any account yet */
                else
                {
                    printf("\nYou have not created any account yet!!!\n");
                    printf("Please enter account first.\n");
                }
                /* Clear the console screen */
                clear_console();
                /* Exit the switch statement */
                break;
            }
            case 5:
            {
                printf("\nExit program . . .\n");
                /* Exit the switch statement */
                break;
            }
            /* If the user's choice is not 1, 2, 3, 4, or 5 */
            default:
            {
                printf("\nYour input is not valid!!!\n\n");
                printf("Please enter again . . .\n");
                /* Clear the console screen */
                clear_console();
                break;
            }
        }
    } /* Continue the loop until the user chooses to exit */
    while (choice != 5);

    /* Return 0 to indicate successful execution */
    return 0;
} /* EOF */

