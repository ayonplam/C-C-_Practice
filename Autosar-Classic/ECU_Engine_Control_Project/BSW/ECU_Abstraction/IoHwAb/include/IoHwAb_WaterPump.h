#ifndef IOHWWAB_WATER_PUMP_H
#define IOHWWAB_WATER_PUMP_H

#include "Std_Types.h"

typedef struct {
    uint8_t WaterPump_Channel;      /* PWM channel */
    uint16_t WaterPump_MaxFlowRate; /* Flow Rate max */
} WaterPump_ConfigType;

Std_ReturnType IoHwAb_WaterPump_Init(const WaterPump_ConfigType* ConfigPtr);

Std_ReturnType IoHwAb_WaterPump_SetFlowRate(float FlowRateValue);

#endif /* IOHWWAB_WATER_PUMP_H */