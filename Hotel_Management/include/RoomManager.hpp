/**
*   @file    RoomManager.hpp
*   @version 1.0.0
*
*   @brief   RoomManager - API header
*   @details Contains declarations of the RoomManager API functions.
*
*   @author  Lam Nguyen Phu
*
*   @{
*/
/*==================================================================================================
*
==================================================================================================*/
#ifndef Room_MANAGER_HPP
#define Room_MANAGER_HPP

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Room.hpp"
#include <vector>
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
class RoomManager {
public:
    RoomManager() {
        rooms_.emplace_back(101);
        rooms_.emplace_back(102);
        rooms_.emplace_back(103);
        rooms_.emplace_back(104);
        rooms_.emplace_back(105);
        rooms_.emplace_back(201);
        rooms_.emplace_back(202);
        rooms_.emplace_back(203);
        rooms_.emplace_back(204);
        rooms_.emplace_back(205);
        rooms_.emplace_back(301);
        rooms_.emplace_back(302);
        rooms_.emplace_back(303);
        rooms_.emplace_back(304);
        rooms_.emplace_back(305);
    };

    void addCustomerToRoom(const std::string RoomNumber, const std::string customerName, const std::string customerPhone, const std::string checkIn);

    void moveCustomerFromRoom(const std::string RoomNumber, const std::string checkOut);

    void checkRoom(const std::string RoomNumber);

private:
    std::vector<Room> rooms_;

    // Find Room by Room number
    Room* findRoomByNumber(const std::string RoomNumber);
};

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#endif /* Room_MANAGER_HPP */

/** @} */
