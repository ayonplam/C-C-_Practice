#ifndef RTE_THERMAL_MANAGEMENT_H
#define RTE_THERMAL_MANAGEMENT_H

#include "Std_Types.h"
#include <stddef.h>

Std_ReturnType Rte_Read_RpTemperatureSensor_ActualTemperature(float* Temperature_Motor, float* Temperature_Cooler);

Std_ReturnType Rte_Write_RpWaterPump_SetFlowRate(float FLowRateValue);

Std_ReturnType Rte_Call_RpTemperatureSensor_Init(void);

Std_ReturnType Rte_Call_RpWaterPump_Init(void);

#endif /* RTE_THERMAL_MANAGEMENT_H */