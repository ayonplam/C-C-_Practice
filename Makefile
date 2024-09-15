PROG_NAME   = test_Prog01
INCLUDE_DIR = $(PROG_NAME)/include
SOURCE_DIR  = $(PROG_NAME)/src
OUTPUT_DIR  = ../output

EXECUTABLE_NAME = program

CC = gcc

C_WARNINGS = -g -Wall -Wextra -Wpedantic
CFLAGS = -I $(INCLUDE_DIR)
C_COMPILER_CALL = $(CC) $(C_WARNINGS) $(CFLAGS)

C_SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
C_OBJECTS = $(patsubst $(SOURCE_DIR)/%.c, $(OUTPUT_DIR)/%.o, $(C_SOURCES))

#############
## TARGETS ##
#############
build: $(C_OBJECTS)
	$(C_COMPILER_CALL) $(C_OBJECTS) -o $(OUTPUT_DIR)/$(EXECUTABLE_NAME)

execute:
	./$(OUTPUT_DIR)/$(EXECUTABLE_NAME)

clean:
	rm -f $(OUTPUT_DIR)/*.o
	rm -f $(OUTPUT_DIR)/$(EXECUTABLE_NAME)

##############
## PATTERNS ##
##############
$(OUTPUT_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(C_COMPILER_CALL) -c $< -o $@

###########
## PHONY ##
###########
.PHONY: build execute clean