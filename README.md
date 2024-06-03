# check-account-fault

### Write a program that allows users to enter accounts from the keyboard. Use char array arr[10] to store this account variable.

### Check for errors in the 'account' variable:
* If account > 10 characters --> LENGTH_INVALID error
* If you enter an account with characters other than letters and numbers --> CHAR_INVALID error   
* The library will call the application layer (main function) to report errors through the function pointer.
* Use enum to define error codes.
  
      typedef enum _statetype 
      { 
          CORRECT, 
          CHAR_INVALID, 
          LENGHT_INVALID 
      }status_enum_t; 

* Function 'void RegisterCallback(func func_add)' allows the application to register functions.
* Function 'void Check_Account(char* ptr, uint8_t lenght)' check the string the user just entered.
* User functions called through function pointers must have parameters passed as error codes. 
* Users are allowed to enter multiple times.
