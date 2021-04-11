CC		= g++
NVCC		= nvcc
GCC_OPTIONS	= -std=c++17 -Wall --pedantic-error

LDFLAGS		= # 動的リンクファイル *.so
LIBS		= # 静的リンクファイル *.a
#INCLUDE		= -I. -I./include -I../../include
INCLUDE		= -I../../include
#INCLUDE		= -I/home/kakehi/github/c_example/include
#INCLUDE		= -I. -I../../include
#INCLUDE		= -I.

PROGRAM = vector.o position.o position
#PROGRAM = position

all : $(PROGRAM)

# $@ file name of the target
# $< file name of the most-left predefined
# $^ all file name of predefined

vector.o : Vector2D.cpp Vector2D.h
	$(CC) $(GCC_OPTIONS) -c $< -o $@
	#$(CC) $(GCC_OPTIONS) -c $^ -o $@

position.o : Position2D.cpp Position2D.h Vector2D.h
	$(CC) $(GCC_OPTIONS) -c $< -o $@
	#$(CC) $(GCC_OPTIONS) -c $^ -o $@

position : main.cpp position.o vector.o
#position : main.cpp Position2D.o Vector2D.o
	$(CC) $(GCC_OPTIONS) $^ -o $@

run :
	./position

clean :
	rm -f $(PROGRAM)
	rm -f *.o

.PHONY : run clean
