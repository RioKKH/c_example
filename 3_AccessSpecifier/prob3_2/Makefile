CC = g++
NVCC = nvcc
GCC_OPTIONS = -std=c++17 -Wall --pedantic-error

PROGRAM = twostrings

all : $(PROGRAM)

# $@ file name of the target
# $< file name of the most-left predefined
# $^ all file name of predefined

#all.h.gch : all.h
#	$(CC) $(GCC_OPTIONS) -x c++-header -o $@ $<

twostrings.o : twostrings.cpp twostrings.hpp #all.h.gch  
	$(CC) $(GCC_OPTIONS) -c $< -o $@
	#$(CC) $(GCC_OPTIONS) ${INCLUDE} -c $< -o $@

twostrings : main.cpp twostrings.o 
	$(CC) $(GCC_OPTIONS) $^ -o $@
	#$(CC) $(GCC_OPTIONS) ${INCLUDE} -c $^ -o $@

clean : 
	rm -f {PROGRAM}
	rm -f *.o
