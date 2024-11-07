**Example.**

1. Duyệt vector list accountList:
   for (const auto& acc : accountList)
    - const: đảm bảo elements trong container ko bị modify
    - auto&: tự động tham chiếu và suy ra type của elements trong accountList, tránh việc sao chép gây tốn bộ nhớ.
    - acc: biểu diễn cho phần tử tương ứng ở mỗi vòng lặp

2. vectorList.pushback()
    - Thêm một phần tử vào cuối vectorList

