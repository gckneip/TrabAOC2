CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

SRC_DIR = src
BUILD_DIR = build

SRC = $(SRC_DIR)/cache.cpp $(SRC_DIR)/block.cpp $(SRC_DIR)/address.cpp $(SRC_DIR)/main.cpp
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

EXEC = cache_simulator

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o $(EXEC)

rebuild: clean all

.PHONY: all clean rebuild
