#ifndef THERMAL_MANAGEMENT_H
#define THERMAL_MANAGEMENT_H

#define MAX_TEMPERATURE 150.0f
#define TEMPERATURE_WARNING_0 110.0f /* Decrease momen level */
#define TEMPERATURE_WARNING_1 120.0f /* Limp-Mode */
#define MIN_TEMPERATURE 0.0f
#define GOOD_TEMPERATURE 70.0f
#define BASE_FLOW_RATE 30.0f

void ThermalManagement_Init(void);

void ThermalManagement_Update(void);

#endif /* THERMAL_MANAGEMENT_H */