# Makefile

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Source files
SRCS = src/main.cpp src/buffer.cpp src/disk_writer.cpp

# Header files (not used in compilation but can be useful for dependencies)
HEADERS = src/buffer.h src/disk_writer.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Output executable
TARGET = my_program

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(TARGET) $(OBJS)
	rm -f output.txt

# Phony targets
.PHONY: all clean
