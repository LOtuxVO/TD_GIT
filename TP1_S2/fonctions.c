#include "pointH.h"

int nombreRangee() {
    int rangee;

    printf("Combien de rangee voulez vous ? : ");
    scanf("%d", &rangee);

    return rangee;
}

int nombrePlace() {
    int place;

    printf("Combien de place voulez vous par rangee ? : ");
    scanf("%d", &place);

    return place;
}

void nomListe(char *nom_liste) {

    printf("Quel est le nom de la liste ? : ");
    scanf("%49s", nom_liste);
    
}

void lireFichierEleves(const char *nom_fichier) {
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return;
    }

    Eleve eleve;
    printf("\n--- Lecture du fichier ---\n");
    while (fscanf(fichier, "%49s %49s", eleve.prenom, eleve.nom) == 2) {
        printf("Eleve lu : %s %s\n", eleve.prenom, eleve.nom);
    }

    fclose(fichier);
}

void initTab(char tableau[50][50], int rangee, int place) {
    int x = rangee;
    int y = place;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            tableau[i][j] = '0';
        }
    }
}
