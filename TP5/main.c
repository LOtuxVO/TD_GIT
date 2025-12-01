#include "fichier.h"

// met potentiellement beaucoup de temps a ce lancer a cause de la lecture du fichier de sauvegarde

int main() {
    int consommations[7] = {0};

    if (charger(consommations)) {
        printf("Données chargées avec succès.\n\n");
    } else {
        printf("Pas de fichier trouvé.\n\n");
    }

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
