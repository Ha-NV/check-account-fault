/**
 * @file account_manage.c
 * @brief This file contains the implementation of the functions for managing student accounts.
 *
 * It includes the definition of the status_enum_t, Node_t, func types, as well as functions.
 * The file also contains the implementation of the RegisterCallback, Check_Account, and Show_Error functions.
 * Additionally, it includes the implementation of the Add_Account, Remove_Account, Is_Account_Exist,
 * Display_ListAccounts, and Search_Account functions.
 *
 * @author Viet Ha Nguyen
 * @date 4/10/2024
 */

/*******************************************************************************
 * Include
 ******************************************************************************/
#include "account_manage.h"     /* Include header file of this function file */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/**
 * @brief The callback function.
 *
 * This function is used to register a callback function.
 */
func callback_function;

/*******************************************************************************
 * Variables
 ******************************************************************************/
status_enum_t current_status = CORRECT; /* This variable is used to store the current status of the account. */
Node_t* head = NULL;                    /* This variable is used to store the head of the linked list. */

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
 * @brief Register a callback function.
 *
 * This function is used to register a callback function.
 *
 * @param func_add The function to be registered as a callback.
 */
void RegisterCallback(func func_add)
{
    /* Assign the function to the callback variable. */
    callback_function = func_add;
}

/**
 * @brief Check the validity of an account.
 *
 * This function is used to check the validity of an account.
 *
 * @param ptr The pointer to the account.
 * @param length The length of the account.
 */
void Check_Account(int8_t* ptr, uint8_t length)
{
    int16_t i = 0;                      /* Initialize the counter variable. */
    current_status = CORRECT;           /* Set the current status to CORRECT. */

    /* Check if the length of the account is more than 10. */
    if (length > 10)
    {
        /* Set the current status to LENGHT_INVALID. */
        current_status = LENGHT_INVALID;
    }
    else
    {
        /* Iterate through each character in the account. */
        for (i = 0; i < length; i++)
        {
            /* Check if the character is not a letter or a number. */
            if (!((ptr[i] >= 'a' && ptr[i] <= 'z') || (ptr[i] >= 'A' && ptr[i] <= 'Z') || (ptr[i] >= '1' && ptr[i] <= '9')))
            {
                /* Set the current status to CHAR_INVALID. */
                current_status = CHAR_INVALID;
                /* Exit the loop. */
                i = length;
            }
        }
    }

    /* Check if a callback function is registered and the current status is not CORRECT. */
    if (callback_function != NULL && current_status != CORRECT)
    {
        /* Call the callback function with the current status. */
        callback_function(current_status);
    }
}

/**
 * @brief Display error message based on the status.
 *
 * This function is used to display an error message based on the status.
 *
 * @param status The status of the account.
 */
void Show_Error(status_enum_t status)
{
    /* Switch statement to check the status and display the appropriate error message. */
    switch (status)
    {
        case CORRECT:
        {
            /* If the status is CORRECT, do nothing. */
            break;
        }
        /* If the status is LENGHT_INVALID, display an error message about the length of the account. */
        case LENGHT_INVALID:
        {
            printf("\nError: Length of account is more than 10.\n\n");
            printf("Please enter again . . .\n");
            break;
        }
        /* If the status is CHAR_INVALID, display an error message about the invalid characters
        in the account. */
        case CHAR_INVALID:
        {
            printf("\nError: Account has invalid characters.\n\n");
            printf("Please enter again . . .\n");
            break;
        }
    }
}

/**
 * @brief Get the current status.
 *
 * This function is used to get the current status.
 *
 * @return The current status.
 */
status_enum_t Get_Status(void)
{
    return current_status;
}

/**
 * @brief Check if the account exists in the list.
 *
 * This function is used to check if the account exists in the list.
 *
 * @param account The account to be checked.
 * @return 1 if the account exists, 0 if not.
 */
int32_t Is_Account_Exist(int8_t* account)
{
    int32_t found = 0;          /* Initialize the variable to store the result of the search */
    Node_t* current = head;     /* Initialize the current node to the head of the list */

    /* Iterate through the list until the end is reached */
    while(current != NULL)
    {
        /* If the account in the current node matches the given account, set the found flag to 1 */
        if (strcmp(current->account, account) == 0)
        {
            found = 1;
        }
        /* Move to the next node in the list */
        current = current->next;
    }
    /* Return the result of the search */
    return found;
}

/**
 * @brief Add an account to the list.
 *
 * This function is used to add an account to the list.
 *
 * @param new_account The new account to be added.
 */
void Add_Account(int8_t* new_account)
{
    /* Allocate memory for the new node */
    Node_t* newNode;
    newNode = (Node_t *)malloc(sizeof(Node_t));

    /* Check if memory allocation is successful */
    if (newNode == NULL)
    {
        /* If memory allocation failed, display an error message */
        printf("Error: Memory allocation failed.\n");
    }
    else
    {
        /* If memory allocation is successful, copy the new account to the new node */
        strcpy(newNode->account, new_account);
        /* Set the next pointer of the new node to the current head of the list */
        newNode->next = head;
        /* Set the head of the list to the new node */
        head = newNode;
    }
}

/**
 * @brief Remove an account from the list.
 *
 * This function is used to remove an account from the linked list of accounts
 * It iterates through the linked list of accounts and if the account is found, it is removed.
 *
 * @param account The account to be removed.
 * @return 1 if the account is removed, 0 if not. -1 if the list is empty
 */
int32_t Remove_Account(int8_t* account)
{
    Node_t* current = head;     /* Initialize the current node to the head of the list */
    Node_t* pre = NULL;         /* Initialize the previous node to NULL */
    int8_t is_Removed = 0;      /* Initialize the variable to store the result of the removal */

    /* If the list is empty, set the is_Removed flag to -1 */
    if (current == NULL)
    {
        is_Removed = -1;
    }
    else
    {
        /* Iterate through the list until the end is reached */
        while (current != NULL)
        {
            /* If the account in the current node matches the given account, set the is_Removed flag to 1 */
            if (strcmp(current->account, account) == 0)
            {
                is_Removed = 1;
                /* If the previous node is NULL, set the head of the list to the next node */
                if (pre == NULL)
                {
                    head = current->next;
                }
                else
                {
                    /* If the previous node is not NULL, set the next pointer of the previous node
                    to the next node of the current node */
                    pre->next = current->next;
                }
                /* Set the current node to NULL to exit loop */
                current = NULL;
            }
            else
            {
                /* If the account in the current node does not match the given account,
                move to the next node in the list */
                pre = current;
                current = current->next;
            }
        }
    }
    /* Return the result of the removal */
    return is_Removed;
}

/**
 * @brief Displays the list of accounts.
 *
 * This function iterates through the linked list of accounts and displays each account.
 * If the list is empty, it prints a message indicating that there are no accounts to show.
 */
void Display_ListAccounts(void)
{
    Node_t* current = head;     /* Initialize the current node to the head of the list */
    int32_t i = 1;              /* Counter for the number of accounts */

    /* If the list is empty */
    if (current == NULL)
    {
        /* Print a message indicating that there are no accounts to show */
        printf("\nNo accounts to show!!!\n");
    }
    else
    {
        /* Print a message indicating that the list of accounts is about to be displayed */
        printf("\nLIST OF ACCOUNTS: \n");
        /* Iterate through the list until the end is reached */
        while (current != NULL)
        {
            /* Print the account number and the account name */
            printf("%d. %s\n", i, current->account);
            /* Increment the account counter */
            i++;
            /* Move to the next node in the list */
            current = current->next;
        }
    }
}

/**
 * @brief Searches for an account in the list.
 *
 * This function iterates through the linked list of accounts and compares each account with the given account.
 * If a match is found, it sets the found flag to 1 and stops the search.
 * If the list is empty, it sets the found flag to -1.
 *
 * @param account The account to search for.
 * @return The result of the search. -1 if the list is empty, 0 if the account is not found,
 * 1 if the account is found.
 */
int32_t Search_Account(int8_t* account)
{
    Node_t* current = head;     /* Initialize the current node to the head of the list */
    int32_t found = 0;          /* Flag to indicate if the account is found */

    /* If the list is empty */
    if (current == NULL)
    {
        /* Set the found flag to -1 */
        found = -1;
    }
    else
    {
        /* Iterate through the list until the end is reached */
        while (current != NULL)
        {
            /* If the account in the current node matches the given account */
            if (strcmp(current->account, account) == 0)
            {
                /* Set the found flag to 1 */
                found = 1;
                /* Exit loop */
                current = NULL;
            }
            else
            {
                /* Move to the next node in the list */
                current = current->next;
            }
        }
    }
    /* Return the result of the search */
    return found;
}

/**
 * @brief Clears the console screen.
 *
 * This function prompting the user to press any key to continue.
 * It then clears the input buffer, waits for a key press, and clears the console screen.
 */
void clear_console(void)
{
    printf("\n-------------------------------------------");
    printf("\nPress ANY key to Continue. . .");
    fflush(stdin);
    getch();
    system("cls");
} /* EOF */

