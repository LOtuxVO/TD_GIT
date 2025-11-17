#include <stdio.h>

int main() {
    int taille;

    printf("Entrez une taille (entre 5 et 10) : ");
    scanf("%d", &taille);

    while(taille < 5 || taille > 10) {
        printf("Erreur : la taille doit etre entre 5 et 10 :\n");
        scanf("%d", &taille);
    }

    char etoile[31][123];
    int width = taille * taille;
    int max_height = 3 * taille - 1;

    for (int i = 0; i < max_height; i++) {
        for (int j = 0; j < width; j++) {
            etoile[i][j] = ' ';
        }
    }

    int midle = width / 2;

    int gauche = midle;
    int droite = midle;

    for (int i = 0; i < taille; i++) {

        for (int j = 0; j < width; j++) {

            if (j == gauche || j == droite) {
                etoile[i][j] = 'A';
            }
            else if (j > gauche && j < droite) {
                etoile[i][j] = 'S';
            }
        }

        gauche--;
        droite++;
    }

    for (int k = gauche + 1; k < droite; k++) {
        etoile[taille][k] = '_';
    }

        printf("\nEtoile de taille %d x %d.\n", taille, taille);
    for (int i = 0; i < max_height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", etoile[i][j]);
        }
        printf("\n");
    }


    return 0;
}