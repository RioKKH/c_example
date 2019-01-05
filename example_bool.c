#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define OPT "hrR"

typedef enum {
	TRUE=1,
	FALSE=0
} BOOL;

static int enable_flip(BOOL, BOOL);

int main(int argc, char **argv) {
	int i, opt;
	static BOOL flip = FALSE;
	static BOOL file_mode = FALSE;

	for (i = 1; i < argc; i++) {
		opt = getopt(argc, argv, OPT);
		switch(opt) {
			case 'r':
				flip = TRUE;
				break;
			case 'R':
				flip = TRUE;
				file_mode = TRUE;
				break;
			case 'h':
				exit(1);
		}
	}

	enable_flip(flip, file_mode);

}

int enable_flip(BOOL flip, BOOL file_mode) {
	if (flip) {
		printf("FLIP\n");
		if (file_mode) {
			printf("FILE MODE\n");
		}
	}
}
