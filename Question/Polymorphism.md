**1.** Runtime Polymorphism in C++
    - Mỗi một class sẽ có một bảng VTABLE chứa các con trỏ hàm trỏ tới các function của class đó
    - vptr: A pointer trỏ tới VTABLE. Compiler sẽ chèn mã ở những chỗ sử dụng đa hình để gán vptr của một đối tượng trỏ tới VTABLE thích hợp

**2.** Compile Time Function Overriding (không sử dụng Virtual Function)
    - Nếu không sử dụng Virtual Function, function được gọi sẽ được compiler xác định từ trước xem thuộc class nào dựa vào việc đối tượng gọi function đó được definition là class nào.

**3.** Run Time Function Overriding use Virtual Function
    - Run Time Polymorphism chỉ thể hiện qua việc sử dụng con trỏ (hoặc tham chiếu) từ BaseClass trỏ tới một đối tượng thuộc DerivateClass
    - Syntax chuẩn: sử dụng override để double check, make sure là function đó được ghi đè vào hàm ảo ở lớp cha, nếu ko có hàm virtual ở lớp cha, compiler sẽ báo lỗi khi biên dịch

    class Base {
    public:
        virtual func()
        {
            // definition
        }
    };

    class Derived : public Base {
    public:
        func() override
        {
            // new definition
        }
    };

    - Các lệnh gọi hàm ảo thường chậm hơn các lệnh gọi hàm không ảo do sự gián tiếp liên quan đến tra cứu bảng ảo. Bảng ảo và con trỏ ảo làm tăng thêm chi phí bộ nhớ, đặc biệt là trong các hệ thống lớn có nhiều lớp.

**4.** Note
    - Virtual Function cannot be static: static function thuộc về lớp và duy nhất, ko thể ghi đè
    - Virtual functions should be accessed using a pointer or reference of base class type to achieve runtime polymorphism.
    - A class may have a virtual destructor but it cannot have a virtual constructor:
    constructor khởi tạo VTABLE nên ko thể có VTABLE trước constructor
    nếu ko sd virtual destructor, khi thực hiện Run Time Polymorphism và destructor một object, chỉ hàm destructor của BaseClass được gọi. (ko gọi được destructor của Derivate Class)

    - Pure Virtual Function: virtual void display() = 0;
      Hàm chứa Pure Virtual Function là class trừu tượng, ko thể definition một cách bình thường, phải sử dụng Run Time Polymorphism để định nghĩa một object.

    - Kế thừa ảo giúp giải quyết vấn đề kim cương trong C++. Kế thừa ảo giúp các lớp dẫn xuất chia sẻ một bản sao duy nhất của lớp cơ sở, Nó tránh được vấn đề trùng lặp dữ liệu và các mâu thuẫn liên quan khi sử dụng đa kế thừa.