#include <stdio.h>
#include "fichier.h"

void afficherMenu() {
    printf("===========================\n");
    printf("  Suivi de consommation\n");
    printf("===========================\n");
    printf("1. Ajout de consommation\n");
    printf("2. Afficher le resume du jour\n");
    printf("3. Sauvegarder et quitter\n");
}

int lireChoix() {
    int choix = 0;
    printf("Votre choix : ");
    scanf("%d", &choix);
    return choix;
}

void initialiserConsommation(int consommations[], int taille) {
    for (int i = 0; i < taille; i++) {
        consommations[i] = 0;
    }
}

void ajouterConsommation(int consommations[]) {
    int choixCategorie = 0;
    int quantite = 0;

    printf("\n--- Quelle categorie voulez vous modifier ---\n");
    printf("1. Eau      💧\n");
    printf("2. Cafe     ☕\n");
    printf("3. Bonbons  🍬\n");
    printf("4. Gateau   🍰\n");
    printf("5. Legumes  🥦\n");
    printf("6. Fruits   🍎\n");
    printf("7. Proteines 🍗\n");

    printf("Votre choix : ");
    scanf("%d", &choixCategorie);

    if (choixCategorie >= 1 && choixCategorie <= 7) {
        printf("Combien d'unites ajouter ? : ");
        scanf("%d", &quantite);
        consommations[choixCategorie - 1] += quantite;
        printf("Consommation mise a jour.\n\n");
    } else {
        printf("Choix invalide.\n\n");
    }
}