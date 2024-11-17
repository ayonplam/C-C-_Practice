#ifndef IOHWAB_TEMPERATURE_H
#define IOHWAB_TEMPERATURE_H

#include "Std_Types.h"

// Cấu hình cho cảm biến nhiệt độ (Temperature Sensor)
typedef struct {
    uint8_t TemperatureSensor_Channel;   // Kênh ADC để đọc giá trị từ cảm biến
    uint16_t TemperatureSensor_MaxValue; // Giá trị nhiệt độ tối đa mà cảm biến có thể đọc
} TemperatureSensor_ConfigType;

// Khởi tạo cảm biến nhiệt độ
Std_ReturnType IoHwAb_TemperatureSensor_Motor_Init(const TemperatureSensor_ConfigType* ConfigPtr);

Std_ReturnType IoHwAb_TemperatureSensor_Cooler_Init(const TemperatureSensor_ConfigType* ConfigPtr);

// Đọc giá trị từ cảm biến nhiệt độ
Std_ReturnType IoHwAb_TemperatureSensor_Motor_Read(float* TemperatureValue);

Std_ReturnType IoHwAb_TemperatureSensor_Cooler_Read(float* TemperatureValue);

#endif /* IOHWAB_TEMPERATURE_H */