#include <stdio.h>

int main() {
    int taille = 0;

    printf("Entrez une taille (recommandee 5 a 10) : ");
    
    while (scanf("%d", &taille) != 1 || taille < 5 || taille > 10) {
        if (scanf("%d", &taille) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
        printf("Erreur : la taille doit etre un nombre entier entre 5 et 10. Reessayez : ");
    }
    
    const int MAX_LARGEUR = 45; 
    const int MAX_HAUTEUR = 32;

    char etoile[MAX_HAUTEUR][MAX_LARGEUR];
    
    int largeur_utilisee = 4 * taille + 5;
    int hauteur_utilisee = 3 * taille + 2;


    for (int i = 0; i < MAX_HAUTEUR; i++) {
        for (int j = 0; j < MAX_LARGEUR; j++) {
            etoile[i][j] = ' ';
        }
    }

    int mid = MAX_LARGEUR / 2;

    for (int i = 0; i < taille; i++) {
        int left = mid - i;
        int right = mid + i;
        
        etoile[i][left] = 'A';
        etoile[i][right] = 'A';
        
        for (int j = left + 1; j < right; j++) {
            etoile[i][j] = 'S';
        }
    }
    etoile[0][mid] = 'A';

    int ligne_separation = taille;
    int base_pointe_left = mid - (taille - 1);
    int base_pointe_right = mid + (taille - 1);

    for (int k = base_pointe_left; k <= base_pointe_right; k++) {
        etoile[ligne_separation][k] = '_';
    }

    int ligne_corps_debut = ligne_separation + 1;
    int hauteur_corps = taille;
    int left_corps = base_pointe_left - 1;
    int right_corps = base_pointe_right + 1;

    for (int i = 0; i < hauteur_corps; i++) {
        int ligne = ligne_corps_debut + i;
        
        if (i == 0) {
            etoile[ligne][left_corps] = '"';
            etoile[ligne][right_corps] = '"';
            for (int j = left_corps + 1; j < right_corps; j++) {
                etoile[ligne][j] = 'S';
            }
        } else if (i == 1 || i == 2) {
            etoile[ligne][left_corps] = '\'';
            etoile[ligne][right_corps] = '\'';
            
            int inner_left = left_corps + 1 + (i - 1);
            int inner_right = right_corps - 1 - (i - 1);
            
            etoile[ligne][inner_left] = 'V';
            etoile[ligne][inner_right] = 'V';
            
            for (int j = inner_left + 1; j < inner_right; j++) {
                etoile[ligne][j] = 'S';
            }
        } else if (i >= 3) {
            int current_left = mid - (taille - 1 - (i - 3));
            int current_right = mid + (taille - 1 - (i - 3));
            
            etoile[ligne][current_left] = '.';
            etoile[ligne][current_right] = '.';
            
            for (int j = current_left + 1; j < current_right; j++) {
                etoile[ligne][j] = 'S';
            }
        }
    }

    int ligne_jambes_debut = ligne_corps_debut + hauteur_corps;
    int hauteur_jambes = taille;
    int debut_centre_gauche = mid - 1;
    int debut_centre_droit = mid + 1;

    for (int i = 0; i < hauteur_jambes; i++) {
        int ligne = ligne_jambes_debut + i;

        int left_leg_g = debut_centre_gauche - i;
        int right_leg_g = debut_centre_gauche;
        if (left_leg_g >= 0) {
            etoile[ligne][left_leg_g] = '.';
            etoile[ligne][right_leg_g + 1] = '"';
            for (int j = left_leg_g + 1; j <= right_leg_g; j++) {
                etoile[ligne][j] = 'S';
            }
        }

        int left_leg_d = debut_centre_droit;
        int right_leg_d = debut_centre_droit + i;
        if (right_leg_d < MAX_LARGEUR) {
            etoile[ligne][left_leg_d - 1] = '"';
            etoile[ligne][right_leg_d] = '.';
            for (int j = left_leg_d; j < right_leg_d; j++) {
                etoile[ligne][j] = 'S';
            }
        }

        if (i < 2) {
             etoile[ligne][mid - 1] = ' ';
             etoile[ligne][mid] = ' ';
             etoile[ligne][mid + 1] = ' ';
        } else {
             etoile[ligne][mid] = ' ';
        }
    }

    printf("\nEtoile finale (Taille %d) :\n", taille);

    int hauteur_finale = 0;
    for (int i = 0; i < hauteur_utilisee; i++) {
        int ligne_vide = 1;
        for (int j = 0; j < largeur_utilisee; j++) { 
            if (etoile[i][j] != ' ') {
                ligne_vide = 0;
                break;
            }
        }
        if (!ligne_vide) {
            hauteur_finale = i + 1;
        }
    }

    for (int i = 0; i < hauteur_finale; i++) {
        int max_j = 0;
        for (int j = 0; j < largeur_utilisee; j++) {
            if (etoile[i][j] != ' ') {
                max_j = j;
            }
        }
        for (int j = 0; j <= max_j; j++) {
            printf("%c", etoile[i][j]);
        }
        printf("\n");
    }

    return 0;
}