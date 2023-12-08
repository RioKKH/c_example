#include <stdio.h>
#include <string.h>

int write(char *a, size_t size) {
  const char *src = "Hello, world!";

  if (strlen(src) >= size) {
    fprintf(stderr, "error: buffer overflow detected!: %ld:%ld\n", size,
            sizeof(a));
    return -1;
  }

  strncpy(a, "Hello,world!", size - 1);
  a[size - 1] = '\0'; // null-terminate the string

  return 0;
}

void print(const char *a) {
  printf("%s\n", a);
  return;
}

int main() {
  char a[32] = {0};
  write(a, sizeof(a));
  print(a);
  return 0;
}
