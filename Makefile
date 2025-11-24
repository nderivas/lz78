SRC_DIR   := src
BUILD_DIR := build
BIN_DIR   := bin
TARGET    := $(BIN_DIR)/lz78
CXX       := g++
CXXFLAGS  := -Wall -Wextra -std=c++17 -o3 -otime
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	@echo "Linking $(TARGET)..."
	$(CXX) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR) $(BUILD_DIR):
	mkdir -p $@

-include $(OBJS:.o=.d)

clean:
	@echo "Cleaning..."
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean
