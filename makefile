# My makefile
 
# Name of the project
PROJ_NAME=printy
 
# .c files
C_SOURCE=$(wildcard ./*.cpp)
 
# .h files
H_SOURCE=$(wildcard ./*.h)
 
# Object files
OBJ=$(subst .cpp,.o,$(subst source,objects,$(C_SOURCE)))

# Compiler and linker
CC=g++
 
# Flags for compiler
CC_FLAGS=-c         \
         -W         \
         -Wall      \
         -ansi      \
         -pedantic  
 
# Command used at clean target
RM = rm -rf

# Compilation and linking
#
all: objFolder $(PROJ_NAME)
 
$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using GCC linker: $@'
	$(CC) $^ -o $@
	@ echo 'Finished building binary: $@'
	@ echo ' '
 
./objects/%.o: ./%.cpp ./%.h
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '
 
./objects/Simulador.o: ./Simulador.cpp $(H_SOURCE)
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '
 
objFolder:
	@ mkdir -p objects
 
clean:
	@ $(RM) ./*.o $(PROJ_NAME) *~
	@ $(RM) ./*.gcno $(PROJ_NAME) *~
	@ rmdir objects
 
.PHONY: all clean