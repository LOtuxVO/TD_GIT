#include <stdio.h>

void afficherMenu(void) {
    printf("\n===== GESTION DE NOTES =====\n");
    printf("1. Saisir le nombre d'eleves\n");
    printf("2. Saisir les notes des eleves\n");
    printf("3. Afficher toutes les notes\n");
    printf("4. Afficher la moyenne d'un eleve\n");
    printf("5. Afficher la moyenne generale\n");
    printf("6. Afficher la meilleure note de chaque controle\n");
    printf("0. Quitter\n");
}

int lireChoix(void) {
    int choix;
    scanf("%d", &choix);
    return choix;
}

int main() {
    int choixUtilisateur;
    
    afficherMenu();
    choixUtilisateur = lireChoix();

    printf("\nVotre choix : %d\n", choixUtilisateur);
    
    return 0;
}
