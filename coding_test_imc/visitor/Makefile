PROJECT_NAME := visitor

CC := g++ -std=c++14 -O3
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
TARGET := $(BIN_DIR)/$(PROJECT_NAME)

SRCEXT := cpp
SOURCES := $(shell find $(SRC_DIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall
INC := -I include

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRCEXT)
	@mkdir -p $(BUILD_DIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(TARGET) : $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) "; $(CC) $^ -o $(TARGET)

nuke:
	@echo " Nuking..."
	@echo " $(RM) -fr $(BUILD_DIR) $(BIN_DIR)"; $(RM) -fr $(BUILD_DIR) $(BIN_DIR)

.PHONY: nuke
