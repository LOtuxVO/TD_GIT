#include <stdio.h>

int main() {
    int t[3] = {10, 20, 30};
    int i = 1; // -1 n'est pas un indice valide pour le tableau t
    printf("%d\n", t[i]); 
    return 0;
}
