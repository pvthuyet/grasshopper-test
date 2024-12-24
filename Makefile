# Compiler settings
CXX = g++               # C++ compiler
CXXFLAGS = -std=gnu++2b -Wall   # Compiler flags (e.g., C++23 and all warnings)
LDFLAGS =                # Linker flags (if needed)

# Files
SRC = main.cpp           # Source file
OBJ = main.o             # Object file
EXEC = main              # Executable

# Default target
all: $(EXEC)

# Rule to link object file into executable
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC) $(LDFLAGS)

# Rule to compile source file into object file
$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC) -o $(OBJ)

# Rule to run the program
run: $(EXEC)
	./$(EXEC)

# Clean up object files and the executable
.PHONY: clean
clean:
	rm -f $(OBJ) $(EXEC)
