#include "fichier.h"

void afficherMenu() {
    printf("===========================\n");
    printf("  Suivi de consommation\n");
    printf("===========================\n");
    printf("1. Ajout de consommation\n");
    printf("2. Afficher le résumé du jour\n");
    printf("3. Afficher le score de santé\n");
    printf("4. Afficher l'historique\n");
    printf("5. Sauvegarder et quitter\n");
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

    printf("\n==== Quelle categorie voulez vous modifier ====\n");
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
    const char* emojisFruits[] = {"😢", "🙂", "😄"};

    int scoreBonbons = humeurBonbons(consommations[2]);
    int scoreLegumes = humeurLegumes(consommations[4]);
    int scoreFruits = humeurFruits(consommations[5]);

    int max[] = {8, 4, 10, 3, 5, 5, 4};

    printf("Eau       : %d 💧", consommations[0]);
    afficherBarre(consommations[0], max[0]);
    printf("\n");

    printf("Café      : %d ☕", consommations[1]);
    afficherBarre(consommations[1], max[1]);
    printf("\n");

    printf("Bonbons   : %d 🍬 %s", consommations[2], emojisBonbons[scoreBonbons]);
    afficherBarre(consommations[2], max[2]);
    printf("\n");

    printf("Gâteau    : %d 🍰", consommations[3]);
    afficherBarre(consommations[3], max[3]);
    printf("\n");

    printf("Légumes   : %d 🥦 %s", consommations[4], emojisLegumes[scoreLegumes]);
    afficherBarre(consommations[4], max[4]);
    printf("\n");

    printf("Fruits    : %d 🍎 %s", consommations[5], emojisFruits[scoreFruits]);
    afficherBarre(consommations[5], max[5]);
    printf("\n");

    printf("Protéïnes : %d 🍗", consommations[6]);
    afficherBarre(consommations[6], max[6]);
    printf("\n");

    printf("\n");
    Sleep(3000);
}

int charger(int consommations[]) {
    FILE *fichier = fopen("consommation.txt", "r");
    if (fichier == NULL) {
        return 0;
    }

    char date_buffer[11];
    int temp_consommations[7];
    int lignes_lues = 0;

    while (fscanf(fichier, "%10s %d %d %d %d %d %d %d",
                  date_buffer, &temp_consommations[0], &temp_consommations[1],
                  &temp_consommations[2], &temp_consommations[3], &temp_consommations[4],
                  &temp_consommations[5], &temp_consommations[6]) == 8)
    {
        for (int i = 0; i < 7; i++) {
            consommations[i] = temp_consommations[i];
        }
        lignes_lues++;
    }

    fclose(fichier);
    return lignes_lues > 0;
}

int sauvegarder(int consommations[]) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char date_aujourdhui[11];
    strftime(date_aujourdhui, sizeof(date_aujourdhui), "%Y-%m-%d", tm);

    FILE *fichier_orig = fopen("consommation.txt", "r");
    FILE *fichier_temp = fopen("temp.txt", "w");

    if (fichier_temp == NULL) {
        return 0;
    }

    if (fichier_orig != NULL) {
        char date_lue[11];
        int consos_lues[7];
        while (fscanf(fichier_orig, "%10s %d %d %d %d %d %d %d",
                      date_lue, &consos_lues[0], &consos_lues[1], &consos_lues[2],
                      &consos_lues[3], &consos_lues[4], &consos_lues[5], &consos_lues[6]) == 8)
        {
            if (strcmp(date_lue, date_aujourdhui) != 0) {
                fprintf(fichier_temp, "%s %d %d %d %d %d %d %d\n",
                        date_lue, consos_lues[0], consos_lues[1], consos_lues[2],
                        consos_lues[3], consos_lues[4], consos_lues[5], consos_lues[6]);
            }
        }
        fclose(fichier_orig);
    }

    fprintf(fichier_temp, "%s ", date_aujourdhui);
    for (int i = 0; i < 7; i++) {
        fprintf(fichier_temp, "%d ", consommations[i]);
    }
    fprintf(fichier_temp, "\n");

    fclose(fichier_temp);

    remove("consommation.txt");
    rename("temp.txt", "consommation.txt");

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

void afficherBarre(int valeur, int max) {
    if (max <= 0) {
        max = 1;
    }

    if (valeur > max) {
        valeur = max;
    }
    if (valeur < 0) {
        valeur = 0;
    }

    int casesPleines = (valeur * 10) / max;

    printf(" [");
    for (int i = 0; i < 10; i++) {
        if (i < casesPleines) {
            printf("█");
        } else {
            printf("░");
        }
    }
    printf("]");
}

void afficherScoreEtObjectifs(int consommations[], int objectifs[]) {
    printf("\n===== Objectifs du jour =====n\n");

    const char* categories[] = {
        "Eau", "Café", "Bonbons", "Gâteau", "Légumes", "Fruits", "Protéïnes"
    };

    int score = 0;
    
    printf("%-12s | %-12s | %s\n", "Catégorie", "Progrès", "Atteint ?");
    printf("=================================\n");

    for (int i = 0; i < 7; i++) {
        if (objectifs[i] > 0) {
            char progres[15];
            sprintf(progres, "%d / %d", consommations[i], objectifs[i]);
            printf("%-12s | %-12s | %s\n", categories[i], progres, (consommations[i] >= objectifs[i]) ? "✅" : "❌");
            if (consommations[i] >= objectifs[i]) {
                score += 25;
            }
        } else {
            printf("%-12s | %-12s | %s\n", categories[i], "Pas d'objectif", " ");
        }
    }

    score = calculerScoreSante(consommations, objectifs);

    printf("\nScore de santé du jour : %d / 100\n\n", score);
    printf("=================================\n");
    Sleep(4000);
}

int calculerScoreSante(int consommations[], int objectifs[]) {
    int score = 50;

    if (consommations[0] >= objectifs[0]) score += 10;
    if (consommations[4] >= objectifs[4]) score += 10;
    if (consommations[5] >= objectifs[5]) score += 10;
    if (consommations[6] >= objectifs[6]) score += 10;

    if (consommations[2] > 5) {
        int malusBonbons = (consommations[2] - 5);
        if (malusBonbons > 15) {
            malusBonbons = 15;
        }
        score -= malusBonbons;
    }

    if (consommations[1] > 3) {
        int malusCafe = (consommations[1] - 3) * 2;
        if (malusCafe > 20) {
            malusCafe = 20;
        }
        score -= malusCafe;
    }

    if (score < 0) {
        score = 0;
    }
    if (score > 100) {
        score = 100;
    }
    
    return score;
}

void afficherHistorique() {
    FILE *fichier = fopen("consommation.txt", "r");
    if (fichier == NULL) {
        printf("\nAucun historique de sauvegarde trouvé.\n\n");
        Sleep(2000);
        return;
    }

    printf("\n--- Historique complet des consommations ---\n\n");
    printf("%-12s | %-4s | %-5s | %-8s | %-7s | %-8s | %-7s | %s\n",
           "Date", "Eau", "Café", "Bonbons", "Gâteau", "Légumes", "Fruits", "Protéïnes");
    printf("--------------------------------------------------------------------------------------\n");

    char date_str[11];
    int consos[7];

    while (fscanf(fichier, "%10s %d %d %d %d %d %d %d",
                  date_str, &consos[0], &consos[1], &consos[2], &consos[3], &consos[4], &consos[5], &consos[6]) == 8)
    {
        printf("%-12s | %-4d | %-5d | %-8d | %-7d | %-8d | %-7d | %d\n",
               date_str, consos[0], consos[1], consos[2], consos[3], consos[4], consos[5], consos[6]);
    }

    fclose(fichier);
    printf("\n");
    Sleep(4000);

}