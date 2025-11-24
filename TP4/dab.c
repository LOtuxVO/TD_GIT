#include <stdio.h>
#include <windows.h>

void afficher_menu() {
    printf("\n===== DISTRIBUTEUR AUTOMATIQUE DE BILLETS =====\n");
    printf("1 - Retirer de l'argent\n");
    printf("0 - Quitter\n");
}

// j'ai mis la verification de validite dans la meme fonction que saisir_montant
int saisir_montant() {
    int montant = 0;

    while (montant <= 0 || montant > 1000 || montant % 5 != 0) {
        printf("\nEntrez le montant a retirer (max 1000 EUR, multiple de 5) : ");
        if (scanf("%d", &montant) != 1) {
            printf("Erreur : Saisie invalide. Veuillez entrer un nombre.\n");
            while (getchar() != '\n');
            montant = -1;
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
    }

    return montant;
}


void calcul_distribution(int montant) {
    int nb200 = 0, nb100 = 0, nb50 = 0, nb20 = 0, nb10 = 0, nb5 = 0;

    printf("\nDistribution de votre retrait de %d EUR :\n", montant);

    nb200 = montant / 200;
    montant %= 200;

    nb100 = montant / 100;
    montant %= 100;

    nb50 = montant / 50;
    montant %= 50;

    nb20 = montant / 20;
    montant %= 20;

    nb10 = montant / 10;
    montant %= 10;

    nb5 = montant / 5;

    printf("- %d billet(s) de 200 EUR\n- %d billet(s) de 100 EUR\n- %d billet(s) de 50 EUR\n- %d billet(s) de 20 EUR\n- %d billet(s) de 10 EUR\n- %d billet(s) de 5 EUR\n",nb200, nb100, nb50, nb20, nb10, nb5);
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
                calcul_distribution(montant_retrait);
                Sleep(4000);
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
