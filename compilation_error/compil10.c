#include <stdio.h>

int main() {
    int abc = 5; // error: invalid suffix "abc" on integer constant printf("%d\n", 1abc);
    printf("%d\n", abc); 
    return 0;
}
