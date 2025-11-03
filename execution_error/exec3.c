#include <stdio.h>

int main() {
    int x = 0;  // x est declare mais pas initialise
    int y = x + 5;  
    printf("%d\n", y);
    return 0;
}
