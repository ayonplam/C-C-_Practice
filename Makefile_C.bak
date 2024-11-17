ifeq ($(PROG_NAME),)
    $(error "Pls export PROG_NAME")
endif

INCLUDE_DIR = $(PROG_NAME)/include
SOURCE_DIR  = $(PROG_NAME)/src
OUTPUT_DIR  = ../output/$(PROG_NAME)
LAUNCH_FILE = .vscode/launch.json

EXECUTABLE_NAME = program

CC = gcc

C_WARNINGS = -g -Wall -Wextra -Wpedantic
CFLAGS = -I $(INCLUDE_DIR)
C_COMPILER_CALL = $(CC) $(C_WARNINGS) $(CFLAGS)

C_SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
C_OBJECTS = $(patsubst $(SOURCE_DIR)/%.c, $(OUTPUT_DIR)/%.o, $(C_SOURCES))

$(info $(C_SOURCES))

#############
## TARGETS ##
#############
$(OUTPUT_DIR):
	mkdir -p $@

build: ./$(OUTPUT_DIR)/$(EXECUTABLE_NAME).exe

./$(OUTPUT_DIR)/$(EXECUTABLE_NAME).exe: $(C_OBJECTS)
	$(C_COMPILER_CALL) $(C_OBJECTS) -o $(OUTPUT_DIR)/$(EXECUTABLE_NAME)

execute:
	./$(OUTPUT_DIR)/$(EXECUTABLE_NAME)

clean:
	rm -f $(OUTPUT_DIR)/*.o
	rm -f $(OUTPUT_DIR)/$(EXECUTABLE_NAME)

SET_LAUNCH_JSON:
	sed -i 's/output\\\\.*\\\\program/output\\\\\\\\$(PROG_NAME)\\\\\\\\program/g' $(LAUNCH_FILE)

##############
## PATTERNS ##
##############
$(OUTPUT_DIR)/%.o: $(SOURCE_DIR)/%.c $(OUTPUT_DIR)
	$(C_COMPILER_CALL) -c $< -o $@

###########
## PHONY ##
###########
.PHONY: build execute clean