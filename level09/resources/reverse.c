#include <stdio.h>
#include <ctype.h>

int main (int ac, char ** av) {
    FILE* ptr;

    ptr = fopen(av[1], "r");

    if (NULL == ptr) {
        printf("file can't be opened \n");
        return (0);
    }
    int c;
    int i = 0;
    while ((c = fgetc(ptr)) != EOF) {
        if (isprint(c - i))
            printf("%c", c - i);
        i++;
    }
    printf("\n");

    return 0;
}
