
# Compiler #
CC = gcc

# Source files destination #
SRC_DIR = ./src

# Include files destination # 
INC_DIR = ./include/

# Build directory #
BUILD_DIR = ./build

# Binnary destination #
BIN_DIR = ./bin

# Setting src files search directories # 
vpath %.c ./src : ./src/GameBoy

$(BUILD_DIR)/%.o : %.c
	$(CC) -c -I $(INC_DIR) -o $@ $^

$(BIN_DIR)/% : $(wildcard $(BUILD_DIR)/*.o)
	$(CC) -g -o $@ $^

% : 
	$(BIN_DIR)/$@



