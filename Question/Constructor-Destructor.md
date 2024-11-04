**1.** Constructor: được gọi bởi compiler khi một object được khởi tạo, ko có return.
    - Default constructor: không đối số. Khi kế thừa thì constructor của class cha sẽ được gọi trước, sau đó mới đến class con.
    - Constructor với default argument: ClassName(int a, int x = 0).
      Khi truyền một đối số thì nó sẽ được assign cho a. Khi truyền hai đối số thì x sẽ được ghi đè
      với đối số thứ 2
    - Copy constructor: copy từ đối tượng khác cùng class

class student {
    int rno;
    string name;
    double fee;
public:
    // Parameterized constructor
    student(int, string, double);

    // Copy constructor
    student(student& t)
    {
        rno = t.rno;
        name = t.name;
        fee = t.fee;
        cout << "Copy Constructor Called" << endl;
    }

    // Function to display student details
    void display();
};

**2.** Destructor:
	- Được gọi tự động khi biến đó out of scope (function end, program end, block end, toán tử delete được sử dụng)
    - Chỉ có 1 hàm hủy duy nhất trong class
