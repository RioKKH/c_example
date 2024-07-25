#include <stdio.h>
#include <stdint.h>   // for int8_t
#include <stdbool.h>  // for bool

void print_data_type_sizes() {

    printf("char:        %zu bytes\n", sizeof(char));
    printf("short:       %zu bytes\n", sizeof(short));
    printf("int:         %zu bytes\n", sizeof(int));
    printf("long:        %zu bytes\n", sizeof(long));
    printf("long long:   %zu bytes\n", sizeof(long long));
    printf("float:       %zu bytes\n", sizeof(float));
    printf("double:      %zu bytes\n", sizeof(double));
    printf("long double: %zu bytes\n", sizeof(long double));
    printf("bool:        %zu bytes\n", sizeof(bool));
    printf("size_t:      %zu bytes\n", sizeof(size_t));
    printf("int8_t:      %zu bytes\n", sizeof(int8_t));
}

int main() {
    print_data_type_sizes();
    return 0;
}
