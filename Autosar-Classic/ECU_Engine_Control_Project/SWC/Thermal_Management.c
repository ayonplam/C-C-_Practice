#include "Thermal_Management.h"
#include "Rte_ThermalManagement.h"
#include "Torque_Control.h"
#include <stdio.h>

void ThermalManagement_Init(void) {
    Std_ReturnType nReturnValue = E_NOT_OK;

    printf("Khởi tạo hệ thống Thermal Management...\n");

    nReturnValue = (Std_ReturnType)(Rte_Call_RpTemperatureSensor_Init() | Rte_Call_RpWaterPump_Init());

    if (nReturnValue == E_OK) {
        printf("Cảm biến nhiệt độ đã khởi tạo thành công.\n");
    } else {
        printf("Lỗi khi khởi tạo cảm biến nhiệt độ.\n");
        return;
    }

    printf("Hệ thống Thermal Management đã sẵn sàng.\n");
}


void ThermalManagement_Update(void) {
    float temperature_motor = 0.0f;
    float temperature_cooler = 0.0f;
    float cooler_boost = 0.0f;
    float actual_torque = 0.0f;

    // Đọc dữ liệu từ cảm biến tải trọng
    if (Rte_Read_RpTemperatureSensor_ActualTemperature(&temperature_motor, &temperature_cooler) == E_OK) {
        printf("Nhiệt độ hiện tại at Motor: %.2f *C\n", temperature_motor);
        printf("Nhiệt độ hiện tại at Cooler: %.2f *C\n", temperature_cooler);
    } else {
        printf("Lỗi khi đọc cảm biến nhiệt độ!\n");
    }

    if ((temperature_motor > TEMPERATURE_WARNING_1) || (temperature_cooler > TEMPERATURE_WARNING_1)) {
        Rte_Write_RpWaterPump_SetFlowRate(100);

        printf("Limp-home mode !!!!!!!!!!!!!!!!");
    }
    else if ((temperature_motor > TEMPERATURE_WARNING_0) || (temperature_cooler > TEMPERATURE_WARNING_0)) {
        Rte_Write_RpWaterPump_SetFlowRate(100);

        actual_torque *= 0.7f;  // Giảm mô-men xoắn
        if (Rte_Write_PpMotorDriver_SetTorque(actual_torque) == E_OK) {
            printf("WARNING TEMPERATURE Đã gửi mô-men xoắn yêu cầu tới động cơ.\n");
        } else {
            printf("WARNING TEMPERATURE Lỗi khi gửi mô-men xoắn tới động cơ!\n");
        }
    }
    else {
        cooler_boost = (temperature_cooler - GOOD_TEMPERATURE) * 70.0f / 40.0f;

        if (cooler_boost > 0.0f) {
            if (Rte_Write_RpWaterPump_SetFlowRate(BASE_FLOW_RATE + cooler_boost) == E_OK) {
                printf("Set water pump flow rate success.\n");
            } else {
                printf("Error when ser water pump flow rate!\n");
            }
        }
    }

    if (((temperature_motor - temperature_cooler) > 3) || ((temperature_cooler - temperature_motor) > 3)) {
        printf("Hệ thống cảm biến nhiệt độ lỗi!\n");
    }
}


