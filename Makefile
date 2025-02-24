# Define compiler and flags
CXX = g++
CXXFLAGS = -I$(CURDIR) -I$(CURDIR) -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_net -lSDL2_ttf

# Define directories
SRC_DIR = src
BIN_DIR = bin

# Define the output file
OUTPUT = $(BIN_DIR)/output.exe

# Gather all .cpp files in the src directory
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Generate object files from source files
OBJECTS = $(SOURCES:.cpp=.o)

# Rule to build the output file
$(OUTPUT): $(OBJECTS)
	@$(CXX) $(OBJECTS) -o $(OUTPUT) $(CXXFLAGS)

# Rule to compile .cpp to .o
%.o: %.cpp
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

# Clean up build artifacts
clean:
	@rm -f $(OBJECTS) $(OUTPUT)

# Run the output file
run: $(OUTPUT)
	@$(OUTPUT)