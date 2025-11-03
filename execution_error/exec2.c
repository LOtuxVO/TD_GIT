#include <stdio.h>

int main() {
    int tab[5];
    
    for (int i = 0; i < 10; i++) { // deuxieme boucle for inutile
        tab[i] = i;  
        printf("%d\n",tab[i]);  
    }
    printf("fait\n");
    return 0;
}
