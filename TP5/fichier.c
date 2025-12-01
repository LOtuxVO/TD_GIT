#include "fichier.h"

#include <stdio.h>
#include <windows.h>

void afficherMenu() {
    printf("===========================\n");
    printf("  Suivi de consommation\n");
    printf("===========================\n");
    printf("1. Ajout de consommation\n");
    printf("2. Afficher le résumé du jour\n");
    printf("3. Sauvegarder et quitter\n");
}

int lireChoix() {
    int choix = 0;
    printf("Votre choix : ");
    scanf("%d", &choix);
    return choix;
}

void ajouterConsommation(int consommations[]) {
    int choixCategorie = 0;
    int quantite = 0;

    printf("\n--- Quelle categorie voulez vous modifier ---\n");
    printf("1. Eau      💧\n");
    printf("2. Café     ☕\n");
    printf("3. Bonbons  🍬\n");
    printf("4. Gâteau   🍰\n");
    printf("5. Légumes  🥦\n");
    printf("6. Fruits   🍎\n");
    printf("7. Protéïnes 🍗\n");

    printf("Votre choix : ");
    scanf("%d", &choixCategorie);

    if (choixCategorie >= 1 && choixCategorie <= 7) {
        printf("Combien d'unitées ajouter ? : ");
        scanf("%d", &quantite);
        consommations[choixCategorie - 1] += quantite;
        printf("Consommation mise à jour.\n\n");
    } else {
        printf("Choix invalide.\n\n");
    }
}

void afficheResume(int consommations[]) {
    
    printf("\n--- Résumeé du jour ---\n");

    printf("Eau       : %d unités\n", consommations[0]);
    printf("Café      : %d unités\n", consommations[1]);
    printf("Bonbons   : %d unités\n", consommations[2]);
    printf("Gâteau    : %d unités\n", consommations[3]);
    printf("Légumes   : %d unités\n", consommations[4]);
    printf("Fruits    : %d unités\n", consommations[5]);
    printf("Protéïnes : %d unités\n", consommations[6]);
    printf("\n");
    Sleep(3000);
}