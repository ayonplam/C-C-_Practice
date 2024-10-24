**1.** Text Segment (Code Segment) read and execute, no write
    1.1.
    - Lưu hằng số, con trỏ kiểu char
    - char *str = "Hello World" là chuỗi hằng, được lưu trữ trong một vùng bộ nhớ bất biến (read only) hoặc code segment. nhưng str được lưu ở data.

**2.** Data Segment
    2.1.
    - Lưu biến toàn cục hoặc biến static được khởi tạp. Được thu hồi khi chương trình kết thúc

**3.** BSS Segment
    3.1
    - Lưu biến toàn cục hoặc biến static chưa được gán giá trị. Được thu hồi khi chương trình kết thúc

**4.** Stack
    4.1
    - Lưu các giá trị cục bộ, kể cả biến const cục bộ và giá trị của một số thanh ghi trong quá trình function call

**5.** Heap Segment
    5.1
    - Cấp phát động bộ nhớ trong quá trình chạy chương trình

    5.2 malloc(size)
    - malloc sẽ trả về con trỏ kiểu void, phải ép kiểu về kiểu muốn dùng khi sử dụng. Trả về NULL nếu ko thể cấp phát. Không khởi tạo giá trị khi cấp phát vùng nhớ (chứa giá trị rác).
    - free(con trỏ trỏ tới vùng nhớ đã được cấp phát động) thu hồi vùng nhớ. Nên gán con trỏ bằng NULL sau khi giải phóng vùng nhớ.

    5.3 calloc(number_of_items, size_of_item)
    - giống malloc, chỉ khác là vùng nhớ được cấp phát được khởi tạo toàn bộ về 0

    5.4 realloc(con trỏ trỏ tới vùng nhớ đã được cấp phát động, size)
    - Thay đổi kích thước vùng nhớ đã được cấp phát. Trả về NULL nếu ko thể cấp phát.
    - Nếu kích thước mới lớn hơn, dữ liệu sẽ được chuyển sang vùng nhớ mới.
    - Nếu kích thước mới nhỏ hơn, phần bộ nhớ thừa được giải phóng.
    - Khi sử dụng realloc nên lưu tạm con trỏ để tránh trường hợp realloc ko cấp phát được, trả về NULL và con trỏ sẽ được gán bằng NULL


    **Note: Không thể sử dụng malloc globally (bên ngoài hàm main). Vì on global chỉ có thể khai báo, ko thể call function.
            Vì thế khi gọi malloc và dùng con trỏ gán vào thì con trỏ đó lưu ở stack.




