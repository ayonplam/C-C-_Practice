/**
*   @file    EmployeeManager.cpp
*   @version 1.0.0
*
*   @brief   EmployeeManager - API source
*   @details This file implement the EmployeeManager API functions.
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
#include "EmployeeManager.hpp"
#include "UI.hpp"
#include <windows.h>
#include <sstream>
#include <iomanip>
#include <algorithm>

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
// Tạo ID tự động cho nhân viên mới
std::string EmployeeManager::generateEmployeeId(const std::string& position) {
    employeeCounter_++;
    std::stringstream ss;

    // Tạo tiền tố ID theo chức vụ
    if (position == "TV") {
        ss << "TV";
    } else if (position == "Bảo vệ") {
        ss << "BV";
    } else if (position == "Đầu bếp") {
        ss << "DV";
    } else if (position == "Lễ Tân") {
        ss << "LT";
    } else {
        ss << "NV";  // Mặc định nếu không có chức vụ đặc biệt
    }

    // Tạo số thứ tự cho ID và đảm bảo có 3 chữ số
    ss << std::setw(3) << std::setfill('0') << employeeCounter_;

    return ss.str();
}

// Thêm nhân viên mới với ID tự động và tự động đăng ký tài khoản
void EmployeeManager::addEmployee(std::vector<Account>& accountList, const std::string& name, const std::string& phoneNumber, const std::string& position) {
    // Kiểm tra nếu số điện thoại đã tồn tại trong hệ thống tài khoản
    if (Account::accountExists(accountList, phoneNumber)) {
        UI::showMessage("Số điện thoại này đã được đăng ký.");
        Sleep(3000);//3000ms
        return;
    }

    // Tạo ID tự động cho nhân viên mới
    std::string id = generateEmployeeId(position);

    // Thêm nhân viên mới vào danh sách
    employees_.emplace_back(id, name, phoneNumber, position);
    UI::showMessage("Nhân viên " + name + " với ID " + id + " đã được thêm thành công.");

    // Tự động đăng ký tài khoản cho nhân viên với mật khẩu mặc định
    Account::registerAccount(accountList, phoneNumber, "123456");
    UI::showMessage("Tài khoản cho nhân viên đã được đăng ký với mật khẩu mặc định '123456'.");
    Sleep(3000);//3000ms
}

// Sửa thông tin nhân viên dựa trên Id
void EmployeeManager::editEmployeeById(const std::string& id, const std::string& newName, const std::string& newPosition) {
    Employee* employee = findEmployeeById(id);
    if (employee) {
        employee->setName(newName);
        employee->setPosition(newPosition);
        UI::showMessage("Thông tin nhân viên đã được cập nhật.");
    } else {
        UI::showMessage("Không tìm thấy nhân viên với ID này.");
    }
    Sleep(3000);//3000ms
}

// Tìm nhân viên theo id
Employee* EmployeeManager::findEmployeeById(const std::string& id) {
    for (auto& employee : employees_) {
        if (employee.getId() == id ) {
            return &employee;
        }
    }
    return nullptr;
}

// Xóa nhân viên dựa trên ID
void EmployeeManager::deleteEmployeeById(const std::string& id) {
    auto it = std::remove_if(employees_.begin(), employees_.end(), [&id](const Employee& emp) {
        return emp.getId() == id;
    });

    if (it != employees_.end()) {
        employees_.erase(it, employees_.end());
        UI::showMessage("Nhân viên với ID " + id + " đã được xóa.");
    } else {
        UI::showMessage("Không tìm thấy nhân viên với ID này.");
    }
    Sleep(3000);//3000ms
}

// Đặt ca làm việc cho nhân viên
void EmployeeManager::setWorkShift(const std::string& id, const std::string& shift) {
    Employee* employee = findEmployeeById(id);
    if (employee == nullptr) {
        UI::showMessage("Không tìm thấy nhân viên với ID: " + id);
        Sleep(3000);//3000ms
        return;
    }

    employee->setWorkShift(shift);
    UI::showMessage("Ca làm việc của nhân viên " + employee->getName() + " đã được cập nhật thành công thành: " + shift);
    Sleep(3000);//3000ms
}


// Xem danh sách thông tin của tất cả nhân viên
void EmployeeManager::listEmployees() const {
    if (employees_.empty()) {
        UI::showMessage("Không có nhân viên nào.");
    } else {
        for (const auto& employee : employees_) {
            UI::showMessage("ID: " + employee.getId() +
                            ", Tên: " + employee.getName() +
                            ", Số điện thoại: " + employee.getPhoneNumber() +
                            ", Chức vụ: " + employee.getPosition() +
                            ", Ca làm: " + employee.getWorkShift());
        }
    }
}

/** @} */
