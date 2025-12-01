#include <stdio.h>
#include "fichier.h"

int main() {
    int consommations[7] = {0};

    int choixUtilisateur = 0;

    while (choixUtilisateur != 3) {
        afficherMenu();

        choixUtilisateur = lireChoix();

        switch (choixUtilisateur) {
            case 1:
                printf("\n-> Action : Ajouter une consommation.\n\n");
                break;
            case 2:
                printf("\n-> Action : Afficher le resume.\n\n");
                break;
            case 3:
                printf("\n-> Action : Sauvegarde et fermeture du programme.\n");
                break;
            default:
                printf("\n-> Choix invalide, veuillez reessayer.\n\n");
                break;
        }

    }

    return 0;
}
