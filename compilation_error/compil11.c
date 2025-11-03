#include <stdio.h>

int main() {
    if (1) {
        printf("ok\n");
    } else { // accolade manquante
        printf("nope\n");
        }
    return 0;
}
