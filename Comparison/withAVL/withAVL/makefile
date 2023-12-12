# Compiler settings - Can be customized.
CC=g++
CFLAGS=-I. -Wall -std=c++11
TARGET=main

# Define your source files here.
SRC = main.cpp
# Add any additional source files here. If they are in a subdirectory, include the path.
SRC = main.cpp TreeStruct/RNG.h TreeStruct/AVL.h 

# Object files corresponding to source files.
OBJ = $(SRC:.cpp=.o)

# Default target.
$(TARGET): $(OBJ)
	$(CC) -o $@ $^

# Generic rule for compiling .cpp to .o
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

# Clean up
.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)
