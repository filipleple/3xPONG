# Compiler
CXX = g++

# Base compiler flags
CXXFLAGS = -Wall -Wextra -I./src/include -std=c++17

# SDL2 flags
SDL2_CFLAGS := $(shell sdl2-config --cflags)
SDL2_LDFLAGS := $(shell sdl2-config --libs)

# Debug and Release flags
DEBUG_FLAGS = -DDEBUG -g
RELEASE_FLAGS = -O2

# Source and Object files
SRC_DIR = src
OBJ_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Executable name
TARGET = pong

# Make sure build directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(SDL2_CFLAGS) -c $< -o $@

# Link everything into final executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(SDL2_LDFLAGS) -lSDL2_ttf -o $(TARGET)

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Run the game
run: $(TARGET)
	./$(TARGET)

# Debug build (includes debug prints and symbols)
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET)

# Release build (optimized, no debug prints)
release: CXXFLAGS += $(RELEASE_FLAGS)
release: $(TARGET)
