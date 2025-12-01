#include "fichier.h"

// met potentiellement beaucoup de temps a ce lancer a cause de la lecture du fichier de sauvegarde

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");
    
    int consommations[7] = {0};
    int objectifs[7] = {8, 0, 0, 0, 5, 3, 2};

    if (charger(consommations)) {
        printf("Données chargées avec succès.\n\n");
    } else {
        printf("Pas de sauvegarde trouvée.\n\n");
    }

    int choixUtilisateur = 0;

    while (choixUtilisateur != 4) {
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
                afficherScoreEtObjectifs(consommations, objectifs);
                break;
            case 4:
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
