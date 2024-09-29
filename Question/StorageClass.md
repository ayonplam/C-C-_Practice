**1.** Static
	1.1.
	- Static Variable: Thời gian tồn tại trong suốt thời gian chạy chương trình. Scope của biến là local.
        - Static Function: Chỉ có thể được gọi trong cùng một file .c
	- Những hàm nào giới hạn sử dụng trong file .c phải khai báo trong local function prototype của file .c là static.
          Những hàm khác thì khai báo prototype trong file header (thực chất việc khai báo này giống extern)

**2.** Extern
	2.1.
	- Khi lập trình C/C++ cần gọi hàm extern C... dùng để thông báo cho compiler rằng những hàm trong đó sử dụng liên
	  kết C tránh các vẫn đề tên hàm bị thay đổi trong quá trình biên dịch
**3.** Inline
	3.1
	- Compiler có thể quyết định việc có "inline" hay không.
	- Tại sao có một số hàm trong header file lại dùng static inline.?
	  Hữu ích cho các hàm nhỏ. (các hàm static inline sẽ không có vòng for trong đó).
	  Tối ưu hóa hiệu suất với inline.
	  Mỗi file .c include file header đó sẽ có một bản sao riêng của hàm đó.

**4.** Volatile
	4.1
	- Luôn đọc giá trị của biến đó từ bộ nhớ thay vì đọc trong thanh ghi
	- Sử dụng cho biến được chia sẻ giữa các luồng, biến được thay đổi bởi ngắt.
	- sử dụng với const: volatile const. Sử dụng để đảm bảo biến đó chỉ được thay đổi bởi phần cứng,
	  chương trình không thể thay đổi được.