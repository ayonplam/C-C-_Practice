#include <stdio.h>
#include "IoHwAb_TemperatureSensor.h"
#include "Adc.h"

// Giả lập cấu hình của cảm biến nhiệt độ
static TemperatureSensor_ConfigType TemperatureSensor_Motor_CurrentConfig;
static TemperatureSensor_ConfigType TemperatureSensor_Cooler_CurrentConfig;

// Hàm khởi tạo cảm biến nhiệt độ at Motor
Std_ReturnType IoHwAb_TemperatureSensor_Motor_Init(const TemperatureSensor_ConfigType* ConfigPtr) {
    Std_ReturnType nReturnValue = E_NOT_OK;

    if (ConfigPtr == NULL) {
        printf("Error: Null configuration pointer passed to IoHwAb_TemperatureSensor_Motor_Init.\n");
        nReturnValue = E_NOT_OK;
    }
    else
    {
        // Lưu cấu hình cảm biến nhiệt độ vào biến toàn cục
        TemperatureSensor_Motor_CurrentConfig.TemperatureSensor_Channel = ConfigPtr->TemperatureSensor_Channel;
        TemperatureSensor_Motor_CurrentConfig.TemperatureSensor_MaxValue = ConfigPtr->TemperatureSensor_MaxValue;

        // Gọi API từ MCAL để khởi tạo ADC
        Adc_ConfigType adcConfig;
        adcConfig.Adc_Channel = ConfigPtr->TemperatureSensor_Channel;
        Adc_Init(&adcConfig);

        // In ra thông tin cấu hình cảm biến nhiệt độ
        printf("Temperature Sensor at Motor Initialized with Configuration:\n");
        printf(" - ADC Channel: %d\n", TemperatureSensor_Motor_CurrentConfig.TemperatureSensor_Channel);
        printf(" - Max Temperature Value: %d *C\n", TemperatureSensor_Motor_CurrentConfig.TemperatureSensor_MaxValue);

        nReturnValue = E_OK;
    }

    return nReturnValue;
}

// Hàm khởi tạo cảm biến nhiệt độ at Cooler
Std_ReturnType IoHwAb_TemperatureSensor_Cooler_Init(const TemperatureSensor_ConfigType* ConfigPtr) {
    Std_ReturnType nReturnValue = E_NOT_OK;

    if (ConfigPtr == NULL) {
        printf("Error: Null configuration pointer passed to IoHwAb_TemperatureSensor_Cooler_Init.\n");
        nReturnValue = E_NOT_OK;
    }
    else
    {
        // Lưu cấu hình cảm biến nhiệt độ vào biến toàn cục
        TemperatureSensor_Cooler_CurrentConfig.TemperatureSensor_Channel = ConfigPtr->TemperatureSensor_Channel;
        TemperatureSensor_Cooler_CurrentConfig.TemperatureSensor_MaxValue = ConfigPtr->TemperatureSensor_MaxValue;

        // Gọi API từ MCAL để khởi tạo ADC
        Adc_ConfigType adcConfig;
        adcConfig.Adc_Channel = ConfigPtr->TemperatureSensor_Channel;
        Adc_Init(&adcConfig);

        // In ra thông tin cấu hình cảm biến nhiệt độ
        printf("Temperature Sensor at Cooler Initialized with Configuration:\n");
        printf(" - ADC Channel: %d\n", TemperatureSensor_Cooler_CurrentConfig.TemperatureSensor_Channel);
        printf(" - Max Temperature Value: %d *C\n", TemperatureSensor_Cooler_CurrentConfig.TemperatureSensor_MaxValue);

        nReturnValue = E_OK;
    }

    return nReturnValue;
}

// Hàm đọc giá trị từ cảm biến nhiệt độ at Motor
Std_ReturnType IoHwAb_TemperatureSensor_Motor_Read(float* TemperatureValue) {
    Std_ReturnType nReturnValue = E_NOT_OK;

    if (TemperatureValue) {
        // Đọc giá trị ADC từ MCAL
        uint16_t adcValue = 0;
        if (Adc_ReadChannel(TemperatureSensor_Motor_CurrentConfig.TemperatureSensor_Channel, &adcValue) != E_OK) {
            printf("Error: Failed to read ADC value.\n");
            nReturnValue = E_NOT_OK;
        }

        // Chuyển đổi giá trị ADC sang giá trị nhiệt độ (*c)
        *TemperatureValue = ((float)adcValue / 1023.0f) * TemperatureSensor_Motor_CurrentConfig.TemperatureSensor_MaxValue;

        // In ra giá trị nhiệt độ
        printf("temperature Sensor at Motor(ADC Channel %d): Temperature = %.2f *C\n",
                TemperatureSensor_Motor_CurrentConfig.TemperatureSensor_Channel, *TemperatureValue);

        nReturnValue = E_OK;
    }

    return nReturnValue;
}

// Hàm đọc giá trị từ cảm biến nhiệt độ at Cooler
Std_ReturnType IoHwAb_TemperatureSensor_Cooler_Read(float* TemperatureValue) {
    Std_ReturnType nReturnValue = E_NOT_OK;

    if (TemperatureValue) {
        // Đọc giá trị ADC từ MCAL
        uint16_t adcValue = 0;
        if (Adc_ReadChannel(TemperatureSensor_Cooler_CurrentConfig.TemperatureSensor_Channel, &adcValue) != E_OK) {
            printf("Error: Failed to read ADC value.\n");
            nReturnValue = E_NOT_OK;
        }

        // Chuyển đổi giá trị ADC sang giá trị nhiệt độ (*c)
        *TemperatureValue = ((float)adcValue / 1023.0f) * TemperatureSensor_Cooler_CurrentConfig.TemperatureSensor_MaxValue;

        // In ra giá trị nhiệt độ
        printf("temperature Sensor at Cooler(ADC Channel %d): Temperature = %.2f *C\n",
                TemperatureSensor_Cooler_CurrentConfig.TemperatureSensor_Channel, *TemperatureValue);

        nReturnValue = E_OK;
    }

    return nReturnValue;
}