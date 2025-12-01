#include "fichier.h"

// met potentiellement beaucoup de temps a ce lancer a cause de la lecture du fichier de sauvegarde

int main() {
    int consommations[7] = {0};

    if (charger(consommations)) {
        printf("Données chargées avec succès.\n\n");
    } else {
        printf("Pas de sauvegarde trouvée.\n\n");
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
                if (sauvegarder(consommations)) {
                    printf("\nDonnées sauvegardées avec succès.\n");
                } else {
                    printf("\nErreur lors de la sauvegarde des données.\n");
                }
                break;
            default:
                printf("\nChoix invalide, veuillez réessayer.\n\n");
                break;
        }

    }

    return 0;
}
