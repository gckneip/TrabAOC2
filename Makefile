# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Directories (if applicable)
SRC_DIR = src
BUILD_DIR = build

# Source and object files
SRC = $(SRC_DIR)/cache.cpp $(SRC_DIR)/block.cpp $(SRC_DIR)/address.cpp $(SRC_DIR)/main.cpp
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Output executable
EXEC = my_program

# Default target: build everything
all: $(EXEC)

# Build the executable
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Rule to compile .cpp files to .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR)/*.o $(EXEC)

# Rebuild everything
rebuild: clean all

# Phony targets (these are not actual files)
.PHONY: all clean rebuild
