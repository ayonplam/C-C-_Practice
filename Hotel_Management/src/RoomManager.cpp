/**
*   @file    RoomManager.cpp
*   @version 1.0.0
*
*   @brief   RoomManager - API source
*   @details This file implement the RoomManager API functions.
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
#include "RoomManager.hpp"
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
void RoomManager::addCustomerToRoom(const std::string roomNumber, const std::string customerName, const std::string customerPhone, const std::string checkIn) {
    Room* pRoom = findRoomByNumber(roomNumber);

    if (pRoom) {
        if (pRoom->getRoomState() != false) {
            pRoom->setCustomerName(customerName);
            pRoom->setCustomerPhone(customerPhone);
            pRoom->setCheckIn(checkIn);
            pRoom->setRoomState(false);
        } else {
            UI::showMessage("Room not available");
            Sleep(3000);//3000ms
            return;
        }
    } else {
        UI::showMessage("Wrong Room Number");
        Sleep(3000);//3000ms
        return;
    }

}

void RoomManager::moveCustomerFromRoom(const std::string roomNumber, const std::string checkOut) {
    Room* pRoom = findRoomByNumber(roomNumber);

    if (pRoom) {
        pRoom->setCustomerName("Empty");
        pRoom->setCustomerPhone("Empty");
        pRoom->setCheckOut(checkOut);
        pRoom->setRoomState(true);
    } else {
        UI::showMessage("Wrong Room Number");
        Sleep(3000);//3000ms
        return;
    }
}

void RoomManager::checkRoom(const std::string roomNumber) {
    for (const auto& room : rooms_) {
        UI::showMessage(room.getRoomNumber() + ": " +
                        ", Tên: " + room.getCustomerName() +
                        ", Số điện thoại: " + room.getCustomerPhone());
    }
}

Room* RoomManager::findRoomByNumber(const std::string roomNumber) {
    for (auto& room : rooms_) {
        if (room.getRoomNumber() == roomNumber) {
            return &room;
        }
    }
    return nullptr;
}

/** @} */
