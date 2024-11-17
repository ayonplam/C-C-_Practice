/**
*   @file    Room.hpp
*   @version 1.0.0
*
*   @brief   Room - API header
*   @details Contains declarations of the Room API functions.
*
*   @author  Lam Nguyen Phu
*
*   @{
*/
/*==================================================================================================
*
==================================================================================================*/
#ifndef Room_HPP
#define Room_HPP

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
class Room {
public:
    Room(const std::string& RoomNumber, const std::string& customerName, const std::string& customerPhone, const std::string& checkIn, const std::string& checkOut)
        : RoomNumber_(RoomNumber), customerName_(customerName), customerPhone_(customerPhone), checkIn_(checkIn), checkOut_(checkOut) { roomAvailable_ = false; }

    // Getter and Setter
    // Getter and Setter for RoomNumber_
    std::string getRoomNumber() const {
        return RoomNumber_;
    }

    void setRoomNumber(const std::string& RoomNumber) {
        RoomNumber_ = RoomNumber;
    }

    // Getter and Setter for customerName_
    std::string getCustomerName() const {
        return customerName_;
    }

    void setCustomerName(const std::string& customerName) {
        customerName_ = customerName;
    }

    // Getter and Setter for customerPhone_
    std::string getCustomerPhone() const {
        return customerPhone_;
    }

    void setCustomerPhone(const std::string& customerPhone) {
        customerPhone_ = customerPhone;
    }

    // Getter and Setter for checkIn_
    std::string getCheckIn() const {
        return checkIn_;
    }

    void setCheckIn(const std::string& checkIn) {
        checkIn_ = checkIn;
    }

    // Getter and Setter for checkOut_
    std::string getCheckOut() const {
        return checkOut_;
    }

    void setCheckOut(const std::string& checkOut) {
        checkOut_ = checkOut;
    }

    // Getter and Setter for checkOut_
    bool getRoomState() const {
        return roomAvailable_;
    }

    void setRoomState(const bool& roomState) {
        roomAvailable_ = roomState;
    }

private:
    std::string RoomNumber_;
    std::string customerName_;
    std::string customerPhone_;
    std::string checkIn_;
    std::string checkOut_;
    bool roomAvailable_;
};

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#endif /* Room_HPP */

/** @} */
