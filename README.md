# check-account-fault

### Write a program that allows users to enter accounts from the keyboard. Use char array arr[10] to store this account variable.

### Check for errors in the 'account' variable:
* If account > 10 characters --> LENGTH_INVALID error
* If you enter an account with characters other than letters and numbers --> CHAR_INVALID error   
* Thư viện sẽ gọi đến function tầng application (hàm main) để thông báo lỗi thông qua function pointer. 
* Sử dụng enum để định nghĩa các mã lỗi.
  
      typedef enum _statetype 
      { 
          CORRECT, 
          CHAR_INVALID, 
          LENGHT_INVALID 
      }status_enum_t; 

* Hàm void RegisterCallback(func func_add) cho phép ứng dụng đăng ký function.
* Hàm void Check_Account(char* ptr, uint8_t lenght) kiểm tra chuỗi người dùng vừa nhập. 
* Function của người dùng được gọi thông qua function pointer phải có các tham số truyền vào là mã lỗi. 
* Người dùng được phép nhập nhiều lần.
