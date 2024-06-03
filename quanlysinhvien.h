/**
 * @file quanlysinhvien.h
 * @brief This file contains the declarations of the functions and structures used in the program.
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
#include <stdint.h>         /* Include standard integer types library for fixed-width integers like int8_t, uint64_t, etc. */
#include <stdio.h>          /* Include standard input and output library for printf, printf, ... */
#include <string.h>         /* For funtions such as strcpy(), strcmp(), NULL character */
#include <stdlib.h>         /* For malloc() functions*/

#ifndef QUANLYSINHVIEN_H
#define	QUANLYSINHVIEN_H

/*******************************************************************************
 * Declarations
 ******************************************************************************/
/**
 * @brief Enumeration for status types.
 *
 * This enumeration defines the different status types that can be returned by the program.
 */
typedef enum _statetype
{
    CORRECT,            /* The account is correct. */
    CHAR_INVALID,       /* The account contains invalid characters. */
    LENGHT_INVALID      /* The length of the account is invalid. */
} status_enum_t;

/**
 * @brief Structure for a node in the linked list.
 *
 * This structure defines a node in the linked list.
 */
typedef struct Node
{
    int8_t account[10];     /* The account stored in the node. */
    struct Node* next;      /* Pointer to the next node in the list. */
} Node_t;

/**
 * @brief Typedef for a function pointer.
 *
 * This typedef is used to define a function pointer that takes a status_enum_t
 * as an argument and returns void.
 */
typedef void (*func)(status_enum_t);

/*******************************************************************************
 * Prototype
 ******************************************************************************/
/**
 * @brief Register a callback function.
 *
 * This function is used to register a callback function.
 *
 * @param func_add The function to be registered as a callback.
 */
void RegisterCallback(func func_add);

/**
 * @brief Check the validity of an account.
 *
 * This function is used to check the validity of an account.
 *
 * @param ptr The pointer to the account.
 * @param length The length of the account.
 */
void Check_Account(int8_t* ptr, uint8_t length);

/**
 * @brief Display error message based on the status.
 *
 * This function is used to display an error message based on the status.
 *
 * @param status The status of the account.
 */
void Show_Error(status_enum_t status);

/**
 * @brief Get the current status.
 *
 * This function is used to get the current status.
 *
 * @return The current status.
 */
status_enum_t Get_Status(void);

/**
 * @brief Check if the account exists in the list.
 *
 * This function is used to check if the account exists in the list.
 *
 * @param account The account to be checked.
 * @return 1 if the account exists, 0 if not.
 */
int32_t Is_Account_Exist(int8_t* account);

/**
 * @brief Add an account to the list.
 *
 * This function is used to add an account to the list.
 *
 * @param new_account The new account to be added.
 */
void Add_Account(int8_t* new_account);

/**
 * @brief Remove an account from the list.
 *
 * This function is used to remove an account from the linked list of accounts
 * It iterates through the linked list of accounts and if the account is found, it is removed.
 *
 * @param account The account to be removed.
 * @return 1 if the account is removed, 0 if not. -1 if the list is empty
 */
int32_t Remove_Account(int8_t* account);

/**
 * @brief Displays the list of accounts.
 *
 * This function iterates through the linked list of accounts and displays each account.
 * If the list is empty, it prints a message indicating that there are no accounts to show.
 */
void Display_ListAccounts(void);

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
int32_t Search_Account(int8_t* account);

/**
 * @brief Clears the console screen.
 *
 * This function prompting the user to press any key to continue.
 * It then clears the input buffer, waits for a key press, and clears the console screen.
 */
void clear_console(void);

#endif /* QUANLYSINHVIEN_H */

