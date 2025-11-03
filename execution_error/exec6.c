#include <stdio.h>

int main() {
    char nom[10] = " "; // pas assez pour beaucoup de noms
    printf("Nom ? avec 10 caracteres max"); // preciser la limite de caracteres
    scanf("%s", nom); 
    printf("Bonjour %s\n", nom);
    return 0;
}
