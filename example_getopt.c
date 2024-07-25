#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int opt;
    int i = 0;
    printf("Initial optind is %d, argc is %d.\n", optind, argc);
    while ((opt = getopt(argc, argv, "ab:")) != -1)
    {
        printf("Iteration %d.\n Calling getopt makes optind %d\n",
                i++, optind);
        switch (opt)
        {
            case 'a':
                printf("Option a\n");
                break;

            case 'b':
                printf("Option b with value '%s'\n", optarg);
                break;

            default:
                fprintf(stderr, "Usage: %s [-a] [-b value]\n", argv[0]);
                return 1;
        }
    }

    printf("optind is now %d\n", optind);

    for (int i = optind; i < argc; i++)
    {
        printf("Non-option argument: %s\n", argv[i]);
    }

    return 0;
}


