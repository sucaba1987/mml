PROJECT_NAME := multi_power_point

CC := g++ -std=c++14 -O3
SRCEXT := cpp
CFLAGS := -g -Wall

SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
APP_DIR := appliance
MPP_DIR := mpp

SOURCES := $(shell find $(SRC_DIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

APP_SRC := $(shell find $(APP_DIR) -type f -name *.$(SRCEXT))
APP_OBJ := $(patsubst $(APP_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(APP_SRC))

MPP_SRC := $(shell find $(MPP_DIR) -type f -name *.$(SRCEXT))
MPP_OBJ := $(patsubst $(MPP_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(MPP_SRC))

INC := -I$(APP_DIR) -I$(MPP_DIR)

TARGET := $(BIN_DIR)/$(PROJECT_NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRCEXT)
	@mkdir -p $(BUILD_DIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(BUILD_DIR)/%.o: $(MPP_DIR)/%.$(SRCEXT)
	@mkdir -p $(BUILD_DIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(BUILD_DIR)/%.o: $(APP_DIR)/%.$(SRCEXT)
	@mkdir -p $(BUILD_DIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<


$(TARGET) : $(APP_OBJ) $(MPP_OBJ) $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) "; $(CC) $^ -o $(TARGET)

nuke:
	@echo " Nuking..."
	@echo " $(RM) -fr $(BUILD_DIR) $(BIN_DIR)"; $(RM) -fr $(BUILD_DIR) $(BIN_DIR)

.PHONY: nuke
