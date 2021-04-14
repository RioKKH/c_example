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

PROGRAM = vector2

all : $(PROGRAM)

# $@ file name of the target
# $< file name of the most-left predefined
# $^ all file name of predefined

vector2.o : vector2.cpp vector2.h
	$(CC) $(GCC_OPTIONS) -c $< -o $@
	#$(CC) $(GCC_OPTIONS) -c $<

vector2 : main.cpp vector2.o
	$(CC) $(GCC_OPTIONS) $^ -o $@

run :
	./vector2

clean :
	rm -f $(PROGRAM)
	rm -f *.o

.PHONY : run clean
