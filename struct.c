#include <stdio.h>

typedef struct PERSON {
    char name[20];
    int  age;
} PERSON;

void showPerson(PERSON* person)
{
    printf("name: %s, age: %d\n", person->name, person->age);
    return ;
}

int main(int argc, char *argv[])
{
    PERSON person = {"John", 20};
    showPerson(person); // これはエラーになる
    // showPerson(&person); // これはOK
    return 0;
}
