#include <stdio.h>
#include <windows.h>

void afficher_menu() {
    printf("\n===== DISTRIBUTEUR AUTOMATIQUE DE BILLETS =====\n");
    printf("1 - Retirer de l'argent\n");
    printf("0 - Quitter\n");
}

int main() {
    int choix = -1;

    while (choix != 0) {
        afficher_menu();
        printf("Votre choix : ");

        if (scanf("%d", &choix) != 1) {
            while (getchar() != '\n'); 
            choix = -1;
        }

        switch (choix) {
            case 1:
                printf("\nVous avez choisi de retirer de l'argent.\n");
                break;
            case 0:
                printf("\nAu revoir !\n");
                break;
            default:
                printf("\nChoix invalide. Veuillez reessayer.\n");
                break;
        }

    }

    return 0;
}
