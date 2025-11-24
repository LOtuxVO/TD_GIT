#include <stdio.h>

#define MAX_LARGEUR 80
#define MAX_HAUTEUR 80

int main() {
    int taille;

    printf("Entrez une taille (5 à 10) : ");
    while (scanf("%d", &taille) != 1 || taille < 5 || taille > 10) {
        printf("Erreur. Reessayez : ");
        int c; while ((c = getchar()) != '\n' && c != EOF);
    }

    char etoile[MAX_HAUTEUR][MAX_LARGEUR];

    for (int i = 0; i < MAX_HAUTEUR; i++)
        for (int j = 0; j < MAX_LARGEUR; j++)
            etoile[i][j] = ' ';

    int mid = MAX_LARGEUR / 2;

    for (int i = 0; i < taille; i++) {
        int left  = mid - i;
        int right = mid + i;
        etoile[i][left]  = 'A';
        etoile[i][right] = 'A';
        for (int j = left + 1; j < right; j++)
            etoile[i][j] = 'S';
    }

    int ligne_corps_debut = taille;
    int largeur_corps = taille + 2;

    int hauteur_corps = taille;
    for (int i = 0; i < hauteur_corps; i++) {
        int y = ligne_corps_debut + i;
        int left  = mid - largeur_corps + i / 2;
        int right = mid + largeur_corps - i / 2;
        etoile[y][left]  = (i < 2 ? '"' : '.');
        etoile[y][right] = (i < 2 ? '"' : '.');
        for (int j = left + 1; j < right; j++)
            etoile[y][j] = 'S';
    }

    int ligne_bras_haut = ligne_corps_debut;
    int hauteur_bras = taille;
    for (int i = 0; i < hauteur_bras; i++) {
        int y = ligne_bras_haut + i;

        int xg1 = mid - 1 - i*3;
        int xg2 = mid - 1;
        etoile[y][xg1] = '.';
        etoile[y][xg2] = '"';
        for (int j = xg1 + 1; j < xg2; j++)
            etoile[y-1 >= 0 ? y-1 : y][j] = 'S';

        int xd1 = mid + 1;
        int xd2 = mid + 1 + i*3;
        etoile[y][xd1] = '"';
        etoile[y][xd2] = '.';
        for (int j = xd1 + 1; j < xd2; j++)
            etoile[y-1 >= 0 ? y-1 : y][j] = 'S';
    }

    int ligne_jambes = ligne_corps_debut + hauteur_corps - 1;
    int hauteur_jambes = taille;
    for (int i = 0; i < hauteur_jambes; i++) {
        int y = ligne_jambes + i;

        int lg = mid - 1 - i;
        int rg = mid - 1;
        etoile[y][lg] = '.';
        etoile[y][rg] = '"';
        for (int j = lg + 1; j < rg; j++)
            etoile[y][j] = 'S';

        int ld = mid + 1;
        int rd = mid + 1 + i;
        etoile[y][ld] = '"';
        etoile[y][rd] = '.';
        for (int j = ld + 1; j < rd; j++)
            etoile[y][j] = 'S';
    }

    int h_max = ligne_jambes + hauteur_jambes;
    for (int i = 0; i <= h_max; i++) {
        int last = 0;
        for (int j = 0; j < MAX_LARGEUR; j++)
            if (etoile[i][j] != ' ') last = j;
        for (int j = 0; j <= last; j++)
            putchar(etoile[i][j]);
        putchar('\n');
    }

    return 0;
}
