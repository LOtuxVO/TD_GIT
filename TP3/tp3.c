#include <stdio.h>

int main() {
    int taille;

    int width = taille * taille;
    int max_height = 3 * taille - 1;

    printf("Entrez une taille (entre 5 et 10) : ");
    scanf("%d", &taille);

    if (taille < 5 || taille > 10) {
        printf("Erreur : la taille doit être entre 5 et 10.\n");
        printf("Entrez une taille valide : ");
        scanf("%d", &taille);
    }
    

    return 0;
}


