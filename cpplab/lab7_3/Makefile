# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -I/usr/include/qt5 -I/usr/include/qt5/QtCore -fPIC

# Linker flags
LDFLAGS = -lQt5Core

# Target executable
TARGET = main

# Source files
SOURCES = main.cpp

# Build target without generating .o files
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)

# Run the program
.PHONY: run
run: $(TARGET)
	./$(TARGET)

# Clean target
.PHONY: clean
clean:
	$(RM) $(TARGET)
