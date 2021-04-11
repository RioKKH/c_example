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

PROGRAM = planes
#PROGRAM = position

all : $(PROGRAM)

# $@ file name of the target
# $< file name of the most-left predefined
# $^ all file name of predefined

airplane.o : airplane.cpp airplane.h
	$(CC) $(GCC_OPTIONS) -c $< -o $@
	#$(CC) $(GCC_OPTIONS) -c $^ -o $@

fighter.o : fighter.cpp fighter.h
	$(CC) $(GCC_OPTIONS) -c $< -o $@
	#$(CC) $(GCC_OPTIONS) -c $^ -o $@

planes : main.cpp airplane.o fighter.o
#position : main.cpp Position2D.o Vector2D.o
	$(CC) $(GCC_OPTIONS) $^ -o $@

run :
	./position

clean :
	rm -f $(PROGRAM)
	rm -f *.o

.PHONY : run clean
