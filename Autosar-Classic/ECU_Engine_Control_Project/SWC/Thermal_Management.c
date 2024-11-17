#include "Thermal_Management.h"
#include "Rte_ThermalManagement.h"
#include <stdio.h>

void ThermalManagement_Init(void) {
    Std_ReturnType nReturnValue = E_NOT_OK;

    printf("Khởi tạo hệ thống Thermal Management...\n");

    nReturnValue = Rte_Call_RpTemperatureSensor_Init();

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

    // Đọc dữ liệu từ cảm biến tải trọng
    if (Rte_Read_RpTemperatureSensor_ActualTemperature(&temperature_motor, &temperature_cooler) == E_OK) {
        printf("Nhiệt độ hiện tại at Motor: %.2f *C\n", temperature_motor);
        printf("Nhiệt độ hiện tại at Cooler: %.2f *C\n", temperature_cooler);
    } else {
        printf("Lỗi khi đọc cảm biến nhiệt độ!\n");
    }
}


