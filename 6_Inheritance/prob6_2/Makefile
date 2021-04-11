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

PROGRAM = new
#PROGRAM = position

all : $(PROGRAM)

# $@ file name of the target
# $< file name of the most-left predefined
# $^ all file name of predefined

fundcalc.o : fundcalc.cpp fundcalc.h
	$(CC) $(GCC_OPTIONS) -c $< -o $@
	#$(CC) $(GCC_OPTIONS) -c $^ -o $@

newcalc.o : newcalc.cpp newcalc.h
	$(CC) $(GCC_OPTIONS) -c $< -o $@
	#$(CC) $(GCC_OPTIONS) -c $^ -o $@

new : main.cpp fundcalc.o newcalc.o
#position : main.cpp Position2D.o Vector2D.o
	$(CC) $(GCC_OPTIONS) $^ -o $@

run :
	./new

clean :
	rm -f $(PROGRAM)
	rm -f *.o

.PHONY : run clean
