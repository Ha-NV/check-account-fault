# check-account-fault

## Viết chương trình cho phép người dùng nhập account từ bàn phím. Sử dụng mảng char arr[10] để lưu trữ biến account này.

    Kiểm tra lỗi của biến account:
    
      Nếu account > 10 ký tự --> Lỗi LENGHT_INVALID 
      Nếu nhập account có ký tự khác chữ và số --> Lỗi CHAR_INVALID 
      
      Thư viện sẽ gọi đến function tầng application (hàm main) để thông báo lỗi thông qua function pointer. 
      
      Sử dụng enum để định nghĩa các mã lỗi.
      
      typedef enum _statetype 
      { 
          CORRECT, 
          CHAR_INVALID, 
          LENGHT_INVALID 
      }status_enum_t; 
  
      void RegisterCallback(func func_add);  
      void Check_Account(char* ptr, uint8_t lenght); 
      
      Hàm RegisterCallback cho phép ứng dụng đăng ký function. 
      Hàm Check_Account kiểm tra chuỗi người dùng vừa nhập. 
      Function của người dùng được gọi thông qua function pointer phải có các tham số truyền vào là mã lỗi. 
      Người dùng được phép nhập nhiều lần.
