#include <stdio.h>

int main() {
    int taille;

    printf("Entrez une taille (entre 5 et 10) : ");
    scanf("%d", &taille);

    if (taille < 5) {
        printf("Erreur : la taille doit être entre 5 et 10.\n");
        printf("Entrez une taille valide : ");
        scanf("%d", &taille);
    }
    else if (taille > 10) {
        printf("Erreur : la taille doit être entre 5 et 10.\n");
        printf("Entrez une taille valide : ");
        scanf("%d", &taille);
    }
    

    return 0;
}


