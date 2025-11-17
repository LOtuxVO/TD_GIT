#include <stdio.h>

int main() {
    int taille;

    printf("Entrez une taille (entre 5 et 10) : ");
    scanf("%d", &taille);

    while(taille < 5 || taille > 10) {
        printf("Erreur : la taille doit etre entre 5 et 10 : ");
        scanf("%d", &taille);
    }

    int width = taille * taille;
    int max_height = 3 * taille - 1;
    char etoile[max_height][width];

    for (int i = 0; i < max_height; i++) {
        for (int j = 0; j < width; j++) {
            etoile[i][j] = ' ';
        }
    }

    int mid = width / 2;
    int left = mid;
    int right = mid;

    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < width; j++) {
            if (j == left || j == right) {
                etoile[i][j] = 'A';
            }
            else if (j > left && j < right) {
                etoile[i][j] = 'S';
            }
        }
        left--;
        right++;
    }

    int base_left = mid - (taille - 1);
    int base_right = mid + (taille - 1);
    for (int k = base_left; k <= base_right; k++) {
        etoile[taille][k] = '_';
    }

    int ligne = taille + 1;
    int left_body = base_left;
    int right_body = base_right;

    etoile[ligne][left_body] = '.';
    etoile[ligne][right_body] = '.';
    for (int j = left_body + 1; j < right_body; j++) {
        etoile[ligne][j] = 'S';
    }
    ligne++;

    while (left_body < right_body) {
        left_body++;
        right_body--;
        if (left_body >= right_body)
            break;

        etoile[ligne][left_body] = '.';
        etoile[ligne][right_body] = '.';
        for (int j = left_body + 1; j < right_body; j++) {
            etoile[ligne][j] = 'S';
        }
        ligne++;
    }

    printf("\nÉtoile dessinee :\n");
    for (int i = 0; i < max_height; i++) {
        for (int j = 0; j < width; j++) {
            putchar(etoile[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
