/**
*   @file    Account.hpp
*   @version 1.0.0
*
*   @brief   Account Management - API header
*   @details Contains declarations of the Account Management API functions.
*
*   @author  Lam Nguyen Phu
*
*   @{
*/
/*==================================================================================================
*
==================================================================================================*/
#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <string>
#include <vector>
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                        CLASS PROTOTYPES
==================================================================================================*/
class Account {
private:
    std::string username;
    std::string password;

public:
    // Constructor mặc định và constructor có tham số
    Account();
    Account(const std::string& username, const std::string& password);

    // Getter và Setter cho các thuộc tính
    std::string getUsername() const;
    std::string getPassword() const;

    void setPassword(const std::string& password);

    // Kiểm tra nếu tài khoản đã tồn tại trong danh sách
    static bool accountExists(const std::vector<Account>& accountList, const std::string& username);

    // Phương thức static để đăng ký và đăng nhập
    static bool registerAccount(std::vector<Account>& accountList, const std::string& username, const std::string& password);
    static bool login(const std::vector<Account>& accountList, const std::string& username, const std::string& password);

};

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
extern std::vector<Account> accountList;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#endif /* ACCOUNT_H */

/** @} */
