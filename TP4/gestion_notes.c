#include <stdio.h>

void afficherMenu() {
    printf("\n===== GESTION DE NOTES =====\n");
    printf("1. Saisir le nombre d'eleves\n");
    printf("2. Saisir les notes des eleves\n");
    printf("3. Afficher toutes les notes\n");
    printf("4. Afficher la moyenne d'un eleve\n");
    printf("5. Afficher la moyenne generale\n");
    printf("6. Afficher la meilleure note de chaque controle\n");
    printf("0. Quitter\n");
}

int lireChoix() {
    int choix;
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        choix = 1 ;
        break;
    
    case 2:
        choix = 2 ;
        break;
    
    case 3:
        choix = 3 ;
        break;
    
    case 4:
        choix = 4 ;
        break;
    
    case 5:
        choix = 5 ;
        break;
    
    case 6:
        choix = 6 ;
        break;
    
    case 0:
        choix = 0 ;
        break;
    
    default:
        break;
    }

    return choix;
}

int saisirNombreEleves() {
    int nombreEleves;

    do {
        printf("Combien d'eleves dans la classe ? (entre 1 et 30) : ");
        scanf("%d", &nombreEleves);
        if (nombreEleves < 1 || nombreEleves > 30) {
            printf("Erreur : le nombre doit etre compris entre 1 et 30.\n");
        }
    } while (nombreEleves < 1 || nombreEleves > 30);

    return nombreEleves;
}

int main() {
    int choixUtilisateur;
    int nombreEleves = 0;
    
    afficherMenu();
    printf("Votre choix : ");
    choixUtilisateur = lireChoix();

    if (choixUtilisateur == 1) {
        nombreEleves = saisirNombreEleves();
        printf("\nIl y a : %d eleves dans la classe\n", nombreEleves);
    }
    
    return 0;
}
