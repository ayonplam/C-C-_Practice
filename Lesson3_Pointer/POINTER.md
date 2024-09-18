**1.** Pointer là biến chứa địa chỉ của biến khác: (Data_Type) *(Pointer_Name);
	- Truyền tham số cho function, tiết kiệm thời gian và bộ nhớ do ko cần phải copy dữ liệu khi thực hiện function call

**2.** Con trỏ kiểu void:
	- Có thể trỏ tới bất kỳ kiểu dữ liệu nào.
	- Không thể truy cập trực tiếp. Trước khi truy cập phải ép kiểu về con trỏ của kiểu dữ liệu tương ứng.

**3.** Con trỏ hằng: const (Data_Type)* (Pointer_Name)
	- Bảo vệ dữ liệu mà con trỏ trỏ tới.
	- Truyền tham số chỉ đọc cho function, tránh việc dữ liệu bị sửa đổi trong quá trình thực hiện function.

**4.** Hằng con trỏ: (Data_Type)* const (Pointer_Name)
	- Con trỏ luôn trỏ đến một vị trí bộ nhớ nhất định
	- Sử dụng khi tạo một con trỏ trỏ tới địa chỉ của register: volatile (register_typedef) * const (register_name) = (register_address)

**5.** Con trỏ hàm: (Return_Type) (*(Function_Name))((Data_Type),(Data_Type))

**6.** Con trỏ mảng:
    - Tên mảng chính là địa chỉ phần tử đầu tiên của mảng. Có thể gán tên mảng vào con trỏ rồi sử dụng con trỏ đó truy cập các phần tử của mảng.
    (Data_Type) (Array_Name)[] = {1,2,3,4,5};
    (Data_Type) *(Pointer_Name) = (Array_Name);
     ->: *(Pointer_Name) = 1, *(Pointer_Name + 1) = 2, *(Pointer_Name + 2) = 3, ...
