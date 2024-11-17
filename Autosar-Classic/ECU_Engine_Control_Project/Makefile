# Compiler and flags
CC = gcc
CFLAGS = -Wall -g\
-I.\BSW\ECU_Abstraction\IoHwAb\include\
-I.\BSW\MCAL\include\
-I.\BSW\Services\include\
-I.\RTE\
-I.\SWC
# Object directory
OBJDIR = bin
# Executable
TARGET = $(OBJDIR)/ecu

SRC = .\BSW\ECU_Abstraction\IoHwAb\src\IoHwAb_LoadSensor.c \
.\BSW\ECU_Abstraction\IoHwAb\src\IoHwAb_MotorDriver.c \
.\BSW\ECU_Abstraction\IoHwAb\src\IoHwAb_SpeedSensor.c \
.\BSW\ECU_Abstraction\IoHwAb\src\IoHwAb_TemperatureSensor.c \
.\BSW\ECU_Abstraction\IoHwAb\src\IoHwAb_ThrottleSensor.c \
.\BSW\ECU_Abstraction\IoHwAb\src\IoHwAb_TorqueSensor.c \
.\BSW\MCAL\src\Adc.c \
.\BSW\MCAL\src\Can.c \
.\BSW\MCAL\src\Dio.c \
.\BSW\MCAL\src\Pwm.c \
.\BSW\Services\src\Dcm.c \
.\BSW\Services\src\Dem.c \
.\BSW\Services\src\Mem.c \
.\BSW\Services\src\Os.c \
.\BSW\Services\src\Pdu_Router.c \
.\Main.c \
.\RTE\Rte_ThermalManagement.c \
.\RTE\Rte_TorqueControl.c \
.\SWC\Thermal_Management.c \
.\SWC\Torque_Control.c 

# Object files
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

# Build executable
$(TARGET): $(OBJ)
	@echo "Linking all objects to create $(TARGET)..."
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
	@echo "Build successful!"

# Compile object files
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

# Clean up
.PHONY: clean
clean:
	@echo "Cleaning up..."
	rm -rf $(OBJDIR)
	@echo "Clean done!"

# Run program
.PHONY: run
run: $(TARGET)
	@echo "Running program..."
	$(TARGET)
