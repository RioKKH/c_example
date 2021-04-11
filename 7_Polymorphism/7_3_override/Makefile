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

PROGRAM = supsub

all : $(PROGRAM)

# $@ file name of the target
# $< file name of the most-left predefined
# $^ all file name of predefined

sub.o : sub1.cpp sub1.h
	$(CC) $(GCC_OPTIONS) -c $< -o $@
	#$(CC) $(GCC_OPTIONS) -c $<

sup.o : sup1.cpp sup1.o
	$(CC) $(GCC_OPTIONS) -c $< -o $@

supsub : main.cpp sub.o sup.o
	$(CC) $(GCC_OPTIONS) $^ -o $@

run :
	./supsub

clean :
	rm -f $(PROGRAM)
	rm -f *.o

.PHONY : run clean
