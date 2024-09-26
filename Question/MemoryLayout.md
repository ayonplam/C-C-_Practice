**1.** Text Segment (Code Segment) read and execute, no write
    1.1.
    - Lưu hằng số, con trỏ kiểu char
    - char *str = "Hello World" là chuỗi hằng, được lưu trữ trong một vùng bộ nhớ bất biến (read only) hoặc code segment

**2.** Data Segment
    2.1.
    - Lưu biến toàn cục hoặc biến static được khởi tạp. Được thu hồi khi chương trình kết thúc

**3.** BSS Segment
    3.1
    - Lưu biến toàn cục hoặc biến static chưa được gán giá trị. Được thu hồi khi chương trình kết thúc

**4.** Stack
    4.1
    -