#include "Rte_ThermalManagement.h"
#include "IoHwAb_TemperatureSensor.h"
#include "IoHwAb_WaterPump.h"

Std_ReturnType Rte_Read_RpTemperatureSensor_ActualTemperature(float* Temperature_Motor, float* Temperature_Cooler) {
    Std_ReturnType nReturnValue = E_NOT_OK;

    if (Temperature_Motor) {
        nReturnValue = IoHwAb_TemperatureSensor_Motor_Read(Temperature_Motor);
        nReturnValue = E_OK;
    }

    if (Temperature_Cooler) {
        nReturnValue = IoHwAb_TemperatureSensor_Cooler_Read(Temperature_Cooler);
        nReturnValue = E_OK;
    }

    return nReturnValue;
}

Std_ReturnType Rte_Write_RpWaterPump_SetFlowRate(float FLowRateValue) {
    Std_ReturnType nReturnValue = E_NOT_OK;

    nReturnValue = IoHwAb_WaterPump_SetFlowRate(FLowRateValue);

    return nReturnValue;
}

Std_ReturnType Rte_Call_RpTemperatureSensor_Init(void) {
    Std_ReturnType nReturnValue = E_NOT_OK;

    TemperatureSensor_ConfigType temperatureSensor_Motor_Config = {
        .TemperatureSensor_Channel = 5,
        .TemperatureSensor_MaxValue = 100
    };

        TemperatureSensor_ConfigType temperatureSensor_Cooler_Config = {
        .TemperatureSensor_Channel = 6,
        .TemperatureSensor_MaxValue = 100
    };

    nReturnValue = IoHwAb_TemperatureSensor_Motor_Init(&temperatureSensor_Motor_Config);
    nReturnValue = IoHwAb_TemperatureSensor_Cooler_Init(&temperatureSensor_Cooler_Config);

    return nReturnValue;
}

Std_ReturnType Rte_Call_RpWaterPump_Init(void) {
    Std_ReturnType nReturnValue = E_NOT_OK;

    WaterPump_ConfigType WaterPump_Config = {
        .WaterPump_Channel = 9,
        .WaterPump_MaxFlowRate = 100
    };

    nReturnValue = IoHwAb_WaterPump_Init(&WaterPump_Config);

    return nReturnValue;
}