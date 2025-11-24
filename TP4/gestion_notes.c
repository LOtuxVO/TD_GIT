#include <stdio.h>

void afficherMenu(void) {
    printf("\n--- Gestion des notes de la classe ---\n");
    printf("1. Saisir les notes des eleves\n");
    printf("2. Afficher les notes de tous les eleves\n");
    printf("3. Calculer la moyenne d'un eleve\n");
    printf("4. Calculer la moyenne de la classe\n");
    printf("5. Afficher la note la plus haute et la plus basse\n");
    printf("6. Quitter\n");
    printf("--------------------------------------\n");
    printf("Votre choix : ");
}

int main() {
    
    afficherMenu();
    
    return 0;
}
