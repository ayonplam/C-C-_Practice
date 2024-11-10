/**
*   @file    Menu.hpp
*   @version 1.0.0
*
*   @brief   Menu - API header
*   @details Contains declarations of the Menu API functions.
*
*   @author  Lam Nguyen Phu
*
*   @{
*/
/*==================================================================================================
*
==================================================================================================*/
#ifndef MENU_HPP
#define MENU_HPP

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "MenuItem.hpp"
#include "UI.hpp"
#include <vector>
#include <string>
#include <initializer_list>

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                            CLASS
==================================================================================================*/
class Menu {
private:
    std::string title_;
    std::vector<MenuItem> items_;

public:
    // Constructor khởi tạo menu với tiêu đề và danh sách mục
    Menu(const std::string& title, std::initializer_list<MenuItem> items)
        : title_(title), items_(items) {}

    // Hiển thị menu và xử lý lựa chọn
    void showMenu() {
        int choice;

        do {
            system ("cls");
            // Hiển thị tiêu đề của menu
            UI::showMessage("\n===== " + title_ + " =====");

            // Hiển thị từng mục menu
            for (const auto& item : items_) {
                UI::showMessage(std::to_string(item.getChoice()) + ". " + item.getDescription());
            }

            // Lấy lựa chọn từ người dùng
            choice = UI::getUserChoice("Vui lòng chọn tính năng: ");

            // Thực hiện hành động cho lựa chọn
            bool validChoice = false;
            for (const auto& item : items_) {
                if (item.getChoice() == choice) {
                    item.executeAction(); // Thực hiện hành động
                    validChoice = true;
                    break;
                }
            }

             // Thông báo nếu lựa chọn không hợp lệ
            if (!validChoice) {
                UI::showMessage("Lựa chọn không hợp lệ, vui lòng chọn lại.");
            }

        } while (choice != 0);
    }

};

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#endif /* MENU_HPP */

/** @} */
