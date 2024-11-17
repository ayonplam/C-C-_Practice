/**
*   @file    Manager.cpp
*   @version 1.0.0
*
*   @brief   Manager - API source
*   @details This file implement the Manager API functions.
*
*   @author  Lam Nguyen Phu
*
*   @{
*/
/*==================================================================================================
*
==================================================================================================*/


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Manager.hpp"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
// Hiển thị menu quản lý chính
void Manager::showManagementMenu() {
    Menu mainMenu("Quản lý khách sạn", {
        {1, "Quản lý nhân viên", [this]() { manageEmployees(); }},
        {2, "Quản lý phòng", [this]() { manageRooms(); }},
        {3, "Dịch vụ", [this]() { manageServices(); }},
        {0, "Exit", []() { UI::showMessage("Exit..."); }}
    });

    mainMenu.showMenu();  // Hiển thị menu quản lý chính
}

// Quản lý nhân viên
void Manager::manageEmployees() {
    Menu employeeMenu("Quản lý nhân viên", {
        {1, "Thêm nhân viên", [this]() { addEmployee(); }},
        {2, "Sửa thông tin nhân viên", [this]() { editEmployee(); }},
        {3, "Xóa nhân viên", [this]() { deleteEmployee(); }},
        {4, "Xem danh sách nhân viên", [this]() { listEmployees(); }},
        {5, "Cập nhật giờ làm cho nhân viên", [this]() { updateShift(); }},
        {0, "Quay lại Menu quản lý khách sạn", []() { UI::showMessage("Exit"); }}
    });

    employeeMenu.showMenu();  // Hiển thị menu quản lý nhân viên
}

void Manager::addEmployee() {

    while (true) {
        UI::showMessage("=== Thêm Nhân Viên ===");

        // Nhập thông tin từ người dùng
        std::string name = UI::getInputString("Nhập tên nhân viên: ");
        std::string phoneNumber = UI::getInputString("Nhập số điện thoại (ID): ");
        std::string position = UI::getInputString("Nhập vị trí công việc (Tạp vụ/Bảo vệ/Đầu bếp/Lễ Tân): ");

        // Thêm nhân viên mới vào danh sách
        employeeManager.addEmployee(accountList, name, phoneNumber, position);

        // Thêm nhân viên mới vào danh sách
        UI::showMessage("Thêm thành công nhân viên " + name);

        // Tự động đăng ký tài khoản cho nhân viên với mật khẩu mặc định
        UI::showMessage("Tài khoản cho nhân viên đã được đăng ký với mật khẩu mặc định '123456'.");

        // Hiển thị tùy chọn để thêm nhân viên khác
        int choice = UI::getUserChoice("Thêm nhân viên khác (1) hoặc quay lại (0): ");

        if (choice == 0) {
            break;  // Quay lại nếu người dùng chọn 0
        }
    }

}

void Manager::editEmployee() {
    UI::showMessage("Sửa thông tin nhân viên...");
    // Danh sách nhân viên
    employeeManager.listEmployees();

    UI::showMessage("Vui lòng nhập ID của nhân viên muốn sửa thông tin:");
    std::string id = UI::getInputString("Nhập ID: ");

    UI::showMessage("Vui lòng nhập tên mới");
    std::string name = UI::getInputString("Nhập tên: ");

    UI::showMessage("Vui lòng nhập vị trí mới:");
    std::string position = UI::getInputString("Nhập vị trí: ");

    employeeManager.editEmployeeById(id, name, position);
}

void Manager::deleteEmployee() {
    UI::showMessage("Xóa nhân viên...");

    // Danh sách nhân viên
    employeeManager.listEmployees();

    UI::showMessage("Vui lòng nhập ID của nhân viên muốn xóa:");

    std::string id = UI::getInputString("Nhập ID: ");

    employeeManager.deleteEmployeeById(id);
}

void Manager::updateShift() {
    UI::showMessage("Cập nhật giờ làm...");

    // Danh sách nhân viên
    employeeManager.listEmployees();

    UI::showMessage("Vui lòng nhập ID của nhân viên muốn cập nhật giờ làm:");

    std::string id = UI::getInputString("Nhập ID: ");

    UI::showMessage("Vui lòng nhập giờ làm:");

    std::string shiftHour = UI::getInputString("Nhập giờ làm: ");

    employeeManager.setWorkShift(id, shiftHour);
}

void Manager::listEmployees() {
    UI::showMessage("=== Danh Sách Nhân Viên ===");

    int choice = 0;
    employeeManager.listEmployees();
    UI::showMessage("------------------");
    do {
        choice = UI::getUserChoice("Press 0 to exit...");
    } while(choice);
}

// Quản lý phòng
void Manager::manageRooms() {
    Menu roomMenu("Quản lý phòng", {
        {1, "Thêm phòng", [this]() { addRoom(); }},
        {2, "Xóa phòng", [this]() { deleteRoom(); }},
        {3, "Xem danh sách phòng", [this]() { listRooms(); }},
        {0, "Quay lại", []() { UI::showMessage("Quay lại menu quản lý..."); }}
    });

    roomMenu.showMenu();  // Hiển thị menu quản lý phòng
}

void Manager::addRoom() {
    UI::showMessage("Thêm phòng...");
    // Thêm logic thêm phòng ở đây
}

void Manager::editRoom() {
    UI::showMessage("Sửa thông tin phòng...");
    // Thêm logic sửa phòng ở đây
}

void Manager::deleteRoom() {
    UI::showMessage("Xóa phòng...");
    // Thêm logic xóa phòng ở đây
}

void Manager::listRooms() {
    UI::showMessage("Danh sách phòng...");
    // Thêm logic liệt kê phòng ở đây
}

// Quản lý dịch vụ
void Manager::manageServices() {
    Menu serviceMenu("Quản lý dịch vụ", {
        {1, "Thêm dịch vụ", [this]() { addService(); }},
        {2, "Sửa thông tin dịch vụ", [this]() { editService(); }},
        {3, "Xóa dịch vụ", [this]() { deleteService(); }},
        {4, "Xem danh sách dịch vụ", [this]() { listServices(); }},
        {0, "Quay lại", []() { UI::showMessage("Quay lại menu quản lý..."); }}
    });

    serviceMenu.showMenu();  // Hiển thị menu quản lý dịch vụ
}

void Manager::addService() {
    UI::showMessage("Thêm dịch vụ...");
    // Thêm logic thêm dịch vụ ở đây
}

void Manager::editService() {
    UI::showMessage("Sửa thông tin dịch vụ...");
    // Thêm logic sửa dịch vụ ở đây
}

void Manager::deleteService() {
    UI::showMessage("Xóa dịch vụ...");
    // Thêm logic xóa dịch vụ ở đây
}

void Manager::listServices() {
    UI::showMessage("Danh sách dịch vụ...");
    // Thêm logic liệt kê dịch vụ ở đây
}

/** @} */
