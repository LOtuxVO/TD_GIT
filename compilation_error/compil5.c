#include <stdio.h>

int main() {
    char c = 'A';
    printf("c = %c\n", c); // error : format incompatible pour char : %s n'est pas le bon mais %c est le bon
    return 0;
}
