#ifndef THERMAL_MANAGEMENT_H
#define THERMAL_MANAGEMENT_H

#define MAX_TEMPERATURE 110.0f
#define MIN_TEMPERATURE 0.0f

void ThermalManagement_Init(void);

void ThermalManagement_Update(void);

#endif /* THERMAL_MANAGEMENT_H */