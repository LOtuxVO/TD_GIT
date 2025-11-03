#include <stdio.h>

int main() {
    int a = 2;
    int b = 0; // division par zero
    if (b == 0) {
        printf("Erreur : division par zero\n");
        return 0;
    }
    else {
    int c = a / b;  // crash / comportement indéfini
    printf("%d\n", c);
    }
    return 0;
}
