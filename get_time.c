#define __STDC_WANT_LIB_EXT1__ 1
#define _XOPEN_SOURCE // for putenv
#include <stdio.h>    // printf
#include <time.h>     // localtime_r, asctime, time, gmtime, localtime
#include <stdlib.h>   // putenv

static int get_time(time_t *now)
{
#ifdef __STDC_LIB_EXT1__
    struct tm result;
    char str[26];

    time_t now = time(0);
    asctime_s(str, sizeof str, localtime_s(&now, result));
    printf("UTC:  %s", str);
#endif
    return 0;
}

int main()
{
    time_t now = time(NULL);
    printf("UTC:   %s", asctime(gmtime(&now)));
    printf("Local: %s", asctime(localtime(&now)));

    // POSIX-specific
    putenv("TZ=Asia/Tokyo");
    printf("Tokyo: %s", asctime(localtime(&now)));
    return 0;
}

