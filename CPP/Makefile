# Masukan semua file cpp ANda
OBJS = oop.cpp main.cpp code\Coordinate\Coordinate.cpp

CC = g++
COMPILER_FLAGS = -Imingw_dev_lib\include -std=c++11 -Wall -O2
LINKER_FLAGS = -Lmingw_dev_lib\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = oopquarium
all :
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
