#include <stdio.h>

int main() {
    int taille;

    int width = taille * taille;
    int max_height = 3 * taille - 1;

    char etoile[31][123];

    printf("Entrez une taille (entre 5 et 10) : ");
    scanf("%d", &taille);

    while(taille < 5 || taille > 10) {
        printf("Erreur : la taille doit etre entre 5 et 10 :\n");
        scanf("%d", &taille);
    }

    for (int i = 0; i < max_height; i++) {
        for (int j = 0; j < width; j++) {
            etoile[i][j] = ' ';
        }
    }

    printf("\nEtoile de taille %d x %d.\n", taille, taille);
    for (int i = 0; i < max_height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c",etoile[i][j]);
        }
        printf("\n");
    }

    return 0;
}

