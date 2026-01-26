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

int lireFichierEleves(const char *nom_fichier, Eleve liste_eleves[], int max_eleves) {
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 0;
    }

    int nb_eleves = 0;
    printf("\n--- Liste des eleves ---\n");
    while (nb_eleves < max_eleves && fscanf(fichier, "%49s %49s", liste_eleves[nb_eleves].prenom, liste_eleves[nb_eleves].nom) == 2) {
        printf("- %s %s\n", liste_eleves[nb_eleves].prenom, liste_eleves[nb_eleves].nom);
        nb_eleves++;
    }

    fclose(fichier);
    return nb_eleves;
}

void initTab(int rangee, int place, char tableau[rangee][place]) {
    for (int i = 0; i < rangee; i++) {
        for (int j = 0; j < place; j++) {
            tableau[i][j] = '0';
        }
    }
}

void placerEleve(int rangee, int place, char tableau[rangee][place], Eleve liste_eleves[], int nb_eleves) {
    if (nb_eleves > rangee * place) {
        printf("\nAttention : il n'y a pas assez de places pour tous les eleves.\n");
        printf("%d eleves pour %d places.\n", nb_eleves, rangee * place);
    }

    int eleve_actuel = 0;
    printf("\n--- Placement des eleves ---\n");
    for (int i = 0; i < rangee; i++) {
        for (int j = 0; j < place; j++) {
            if (eleve_actuel < nb_eleves) {
                tableau[i][j] = '1';
                printf("Eleve : %s %s - rangee : %d - siege : %d\n", liste_eleves[eleve_actuel].prenom, liste_eleves[eleve_actuel].nom, i + 1, j + 1);
                eleve_actuel++;
            }
        }
    }
}

void afficherPlanDeClasse(int rangee, int place, Eleve liste_eleves[], int nb_eleves) {
    printf("\n\n--- Plan de Classe ---\n");
    for (int i = 0; i < rangee; i++) {
        for (int k = 0; k < place; k++) {
            printf("+--------------------");
        }
        printf("+\n");

        for (int j = 0; j < place; j++) {
            int eleve_index = i * place + j;
            if (eleve_index < nb_eleves) {
                char nom_complet[150];
                snprintf(nom_complet, sizeof(nom_complet), "%s %s", liste_eleves[eleve_index].prenom, liste_eleves[eleve_index].nom);
                printf("| %-18.18s ", nom_complet);
            } else {
                printf("| %-18s ", "Vide");
            }
        }
        printf("|\n");
    }
    for (int k = 0; k < place; k++) {
        printf("+--------------------");
    }
    printf("+\n");
}
