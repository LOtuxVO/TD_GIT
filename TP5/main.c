#include "fichier.h"

#include <stdio.h>
#include <windows.h>

int main() {
    int consommations[7] = {0};

    int choixUtilisateur = 0;

    while (choixUtilisateur != 3) {
        afficherMenu();

        choixUtilisateur = lireChoix();

        switch (choixUtilisateur) {
            case 1:
                ajouterConsommation(consommations);
                break;
            case 2:
                afficheResume(consommations);
                break;
            case 3:
                printf("\n-> Action : Sauvegarde et fermeture du programme.\n");
                break;
            default:
                printf("\n-> Choix invalide, veuillez réessayer.\n\n");
                break;
        }

    }

    return 0;
}
