#include <stdio.h>
#include <windows.h>

void afficher_menu() {
    printf("\n===== DISTRIBUTEUR AUTOMATIQUE DE BILLETS =====\n");
    printf("1 - Retirer de l'argent\n");
    printf("0 - Quitter\n");
}

int saisir_montant() {
    int montant;
    do {
        printf("\nEntrez le montant a retirer (max 1000 EUR, multiple de 5) : ");
        if (scanf("%d", &montant) != 1) {
            printf("Erreur : Saisie invalide. Veuillez entrer un nombre.\n");
            while (getchar() != '\n');
            montant = -1;
            continue;
        }

        if (montant <= 0) {
            printf("Erreur : Le montant doit etre positif.\n");
        } else if (montant > 1000) {
            printf("Erreur : Le montant ne peut pas depasser 1000 EUR.\n");
        }else if (montant < 5){
            printf("Erreur : Le montant ne peut pas etre inferieur a 5 EUR.\n");
        }else if (montant % 5 != 0) {
            printf("Erreur : Le montant doit etre un multiple de 5.\n");
        }

    } while (montant <= 0 || montant > 1000 || montant % 5 != 0);

    return montant;
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
                
                printf("Vous avez choisis de retirer de l'argent\n");
                int montant_retrait = saisir_montant();
                printf("\nDemande de retrait de %d EUR\n", montant_retrait);
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
