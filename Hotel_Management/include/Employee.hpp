/**
*   @file    Employee.hpp
*   @version 1.0.0
*
*   @brief   Employee - Employee header
*   @details Contains declarations of the Employee API functions.
*
*   @author  Lam Nguyen Phu
*
*   @{
*/
/*==================================================================================================
*
==================================================================================================*/
#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <string>

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                        CLASS PROTOTYPES
==================================================================================================*/
class Employee {
public:
    Employee(const std::string& id, const std::string& name, const std::string& phoneNumber, const std::string& position)
        : id_(id), name_(name), phoneNumber_(phoneNumber), position_(position), workShift_("Chưa được set") {}

    // Getters và setters
    std::string getId() const { return id_; }
    std::string getName() const { return name_; }
    std::string getPhoneNumber() const { return phoneNumber_; }
    std::string getPosition() const { return position_; }
    std::string getWorkShift() const { return workShift_; }
    std::string getWorkingHours() const { return workingHours_; }

    void setName(const std::string& name) { name_ = name; }
    void setPhoneNumber(const std::string& phone) { phoneNumber_ = phone; }
    void setPosition(const std::string& position) { position_ = position; }
    void setWorkShift(const std::string& shift) { workShift_ = shift; }
    void setWorkingHours(const std::string& hours) { workingHours_ = hours; }

private:
    std::string id_;  // ID tự động
    std::string name_;
    std::string phoneNumber_;
    std::string position_;
    std::string workShift_;
    std::string workingHours_;
};

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#endif /* EMPLOYEE_HPP */

/** @} */
