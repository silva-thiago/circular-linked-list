# Makefile for "store"
# Created by Thiago Silva 05/28/2018
#
# Complete Makefile separating the different elements of the application as a code (src),
# headers (include), executables (build), libraries (lib), etc.
# Each element is allocated in a specific folder, better organizing the source code.
#
# Some variables are used with special meaning:
#
# $@ target name.
# $^ list with names of all prerequisites without duplicates.
# $< name of the first prerequisite.

# Operating system commands
# Linux: rm -rf 
# Windows: cmd //C del 
RM = rm -rf 

# Compiler.
CC = g++

# Variables for subdirectories.
SRC = ./src
INC = ./include
BIN = ./bin
OBJ = ./build
DOC = ./doc

# Sets the name of the final binary/executable.
PROG = $(BIN)/store

# Ensures that the targets in this list are not confused with files of the same name.
.PHONY: all clean debug doxy doc

# Compilation options.
CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)

# List of object files (.o) that make up the final binary/executable.
OBJS = $(OBJ)/clothes.o $(OBJ)/drink.o $(OBJ)/fruit.o $(OBJ)/product.o $(OBJ)/main.o

all : $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

# Target for compilation with debug information.
# Change the flag CFLAGS, including the -g -O0 options, and recompile the entire project.
debug: CFLAGS += -g -O0 
debug: all

# Target for constructing the build/main.o object.
# Defines the object files of which main.o depends.
$(OBJ)/main.o : $(OBJ)/product.o $(OBJ)/clothes.o $(OBJ)/drink.o $(OBJ)/fruit.o
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@

$(OBJ)/product.o : $(INC)/product.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/product.cpp -o $@

$(OBJ)/clothes.o : $(INC)/clothes.hpp $(OBJ)/product.o
	$(CC) $(CPPFLAGS) -c $(SRC)/clothes.cpp -o $@

$(OBJ)/drink.o : $(INC)/drink.hpp $(OBJ)/product.o
	$(CC) $(CPPFLAGS) -c $(SRC)/drink.cpp -o $@

$(OBJ)/fruit.o : $(INC)/fruit.hpp $(OBJ)/product.o
	$(CC) $(CPPFLAGS) -c $(SRC)/fruit.cpp -o $@

# Target for Doxyfile file creation.
doxy:
	doxygen -g

# Target (target) for the automatic generation of documentation using Doxygen.
# Always removes the previous documentation (if it exists) and generates a new one.
doc:
	$(RM) $(DOC)/*
	doxygen ./Doxyfile

# Target (target) used to clear temporary files (object)
# generated during compilation, as well as binary/executable files.
clean:
	$(RM) $(PROG) $(OBJS)
