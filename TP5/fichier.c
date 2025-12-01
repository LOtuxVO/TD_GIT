#include "fichier.h"

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
    
    printf("\n--- Résumé du jour ---\n");

    const char* emojisBonbons[] = {"😇", "🙂", "😕", "😈"};
    const char* emojisLegumes[] = {"😭", "🙂", "😎"};
    const char* emojisFruits[] = {"😥", "🙂", "😄"};

    int scoreBonbons = humeurBonbons(consommations[2]);
    int scoreLegumes = humeurLegumes(consommations[4]);
    int scoreFruits = humeurFruits(consommations[5]);

    printf("Eau       : %d 💧\n", consommations[0]);
    printf("Café      : %d ☕\n", consommations[1]);
    printf("Bonbons   : %d 🍬 %s\n", consommations[2], emojisBonbons[scoreBonbons]);
    printf("Gâteau    : %d 🍰\n", consommations[3]);
    printf("Légumes   : %d 🥦 %s\n", consommations[4], emojisLegumes[scoreLegumes]);
    printf("Fruits    : %d 🍎 %s\n", consommations[5], emojisFruits[scoreFruits]);
    printf("Protéïnes : %d 🍗\n", consommations[6]);
    printf("\n");
    Sleep(3000);
}

int charger(int consommations[]) {
    FILE * fichier = fopen("consommation.txt", "r");

    if (fichier == NULL) {
        return 0;
    }

    for (int i = 0; i < 7; i++) {
        if (fscanf(fichier, "%d", &consommations[i]) != 1) {
            fclose(fichier);
            return 0;
        }
    }

    fclose(fichier);
    return 1;
}

int sauvegarder(int consommations[]) {
    FILE * fichier = fopen("consommation.txt", "w");

    if (fichier == NULL) {
        return 0;
    }

    for (int i = 0; i < 7; i++) {
        fprintf(fichier, "%d ", consommations[i]);
    }
    fprintf(fichier, "\n");

    fclose(fichier);
    return 1;
}

int humeurBonbons(int nbBonbons) {
    if (nbBonbons <= 3) return 0;
    if (nbBonbons <= 7) return 1;
    if (nbBonbons <= 12) return 2;
    return 3;
}

int humeurLegumes(int nbLegumes) {
    if (nbLegumes == 0) return 0;
    if (nbLegumes <= 2) return 1;
    return 2;
}

int humeurFruits(int nbFruits) {
    if (nbFruits == 0) return 0;
    if (nbFruits <= 2) return 1;
    return 2;
}