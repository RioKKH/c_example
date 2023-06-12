#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[])
{
	FILE *fin, *fout;
	char filename[100] = "";
	char ch;
	time_t t;
	struct tm tm;

	fin = fopen(argv[1], "r");
	if (fin == NULL)
	{
		printf("Error\n");
		exit(1);
	}

	t = time(&t);
	localtime_r(&t, &tm);
	strftime(filename, sizeof(filename), "./test%y%m%d%H%M.dat", &tm);

    fout = fopen(filename, "w");
    // fout = fopen(argv[2], "w");
	if (fout == NULL)
	{
		printf("Error\n");
		exit(1);
	}

	while ((ch = fgetc(fin)) != EOF)
	{
		fputc(ch, fout);
	}

	fclose(fin);
	fclose(fout);

	return 0;
}
