/**
*   @file    Account.cpp
*   @version 1.0.0
*
*   @brief   Account Management - API source
*   @details This file implement the Account Management API functions.
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
#include "Account.hpp"

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
std::vector<Account> accountList;

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

// Constructor mặc định
Account::Account() : username(""), password("") {}

// Constructor có tham số
Account::Account(const std::string& username, const std::string& password)
    : username(username), password(password) {}

// Getter cho từng thuộc tính
std::string Account::getUsername() const {
    return username;
}

std::string Account::getPassword() const {
    return password;
}

// Setter cho từng thuộc tính
void Account::setPassword(const std::string& password) {
    this->password = password;
}

// Kiểm tra nếu tài khoản đã tồn tại trong danh sách
bool Account::accountExists(const std::vector<Account>& accountList, const std::string& username) {
        for (const auto& account : accountList) {
            if (account.getUsername() == username) {
                return true;
            }
        }
        return false;
    }

// Đăng ký tài khoản mới
bool Account::registerAccount(std::vector<Account>& accountList, const std::string& username, const std::string& password) {
    for (const auto& acc : accountList) {
        if (acc.getUsername() == username) {
            return false; // Tên tài khoản đã tồn tại
        }
    }
    Account newAccount(username, password);
    accountList.push_back(newAccount);
    return true; // Đăng ký thành công
}

// Đăng nhập
bool Account::login(const std::vector<Account>& accountList, const std::string& username, const std::string& password) {
    for (const auto& acc : accountList) {
        if (acc.getUsername() == username && acc.getPassword() == password) {
            return true; // Đăng nhập thành công
        }
    }
    return false; // Đăng nhập thất bại
}

/** @} */
