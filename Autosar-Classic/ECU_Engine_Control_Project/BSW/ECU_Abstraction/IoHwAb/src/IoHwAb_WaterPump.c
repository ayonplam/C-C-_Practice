#include "IoHwAb_WaterPump.h"
#include "Pwm.h"
#include <stdio.h>
#include <stdlib.h>

static WaterPump_ConfigType WaterPump_CurrentConfig;

Std_ReturnType IoHwAb_WaterPump_Init(const WaterPump_ConfigType* ConfigPtr) {
    Std_ReturnType nReturnValue = E_NOT_OK;

    if (ConfigPtr == NULL) {
        printf("Error: Null configuration pointer passed to IoHwAb_WaterPump_Init.\n");
        nReturnValue = E_NOT_OK;
    } else {
        WaterPump_CurrentConfig.WaterPump_Channel = ConfigPtr->WaterPump_Channel;
        WaterPump_CurrentConfig.WaterPump_MaxFlowRate = ConfigPtr->WaterPump_MaxFlowRate;

        /* Call API from MCAL */
        Pwm_ConfigType pwmConfig = {
            .Pwm_Channel = WaterPump_CurrentConfig.WaterPump_Channel,
            .Pwm_Period = 1000, /* 1000ms */
            .Pwm_DutyCycle = 30
        };

        Pwm_Init(&pwmConfig);

        printf("Water Pump Initialized with Configuration:\n");
        printf(" - Water Pump Channel: %d\n", WaterPump_CurrentConfig.WaterPump_Channel);
        printf(" - Max Flow Rate: %d Nm\n", WaterPump_CurrentConfig.WaterPump_MaxFlowRate);

        nReturnValue = E_OK;
    }

    return nReturnValue;
}

Std_ReturnType IoHwAb_WaterPump_SetFlowRate(float FlowRateValue) {
    Std_ReturnType nReturnValue = E_NOT_OK;
    if (FlowRateValue < 0.0f || FlowRateValue > WaterPump_CurrentConfig.WaterPump_MaxFlowRate) {
        printf("Error: Flow Rate value %.2f out of range (Max: %d).\n", FlowRateValue, WaterPump_CurrentConfig.WaterPump_MaxFlowRate);
        nReturnValue = E_NOT_OK;
    } else {
        uint16_t dutyCycle = (uint16_t)((FlowRateValue / WaterPump_CurrentConfig.WaterPump_MaxFlowRate) * 100);

        Pwm_SetDutyCycle(WaterPump_CurrentConfig.WaterPump_Channel, dutyCycle);

        printf("Setting Water Pump to %.2f on Channel %d\n", FlowRateValue, WaterPump_CurrentConfig.WaterPump_Channel);

        nReturnValue = E_OK;
    }

    return nReturnValue;
}