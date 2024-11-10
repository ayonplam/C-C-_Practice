**1.** Duyệt vector list accountList:
   for (const auto& acc : accountList)
    - const: đảm bảo elements trong container ko bị modify
    - auto&: tự động tham chiếu và suy ra type của elements trong accountList, tránh việc sao chép gây tốn bộ nhớ.
    - acc: biểu diễn cho phần tử tương ứng ở mỗi vòng lặp

**2.** vectorList.pushback()
    - Thêm một phần tử vào cuối vectorList

**3.** std::function<ReturnType(ParamType1, ParamType2, ...)> func;
    - lưu trữ và gọi các hàm hoặc callable objects (các đối tượng có thể gọi được, chẳng hạn như hàm, lambda, hoặc các functor)

    - Example:
    Truyền std::function làm tham số

void applyFunction(int x, const std::function<void(int)>& func) {
    func(x);
}

int main() {
    std::function<void(int)> print = [](int n) {
        std::cout << "Called with value: " << n << std::endl;
    };
    applyFunction(10, print);
    return 0;
}

**4.** std::initializer_list<type> name;
    - Dùng để khởi tạo các container hoặc các đối tượng khác với một danh sách cố định các giá trị.
    - Example: Class có một container là vector, muốn viết hàm constructor khởi tạo cho container đó.
               thì tham số truyền vào hàm constructor sẽ là std::initializer_list<type> name


