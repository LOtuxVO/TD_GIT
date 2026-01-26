#include "pointH.h"

int main() {
    
    int rangee = nombreRangee();
    int place = nombrePlace();

    char nom_liste[50];
    nomListe(nom_liste);

    printf("Le nom de la liste est : %s\n", nom_liste);
    int MAX_ELEVES = rangee * place;

    Eleve liste_eleves[MAX_ELEVES];
    int nb_eleves = lireFichierEleves(nom_liste, liste_eleves, MAX_ELEVES);

    if (nb_eleves == 0) {
        printf("Aucun eleve lu depuis le fichier. Le programme va se terminer.\n");
        return 1;
    }

    int tableau[rangee][place];

    initTab(rangee, place, tableau);

    placerEleve(rangee, place, tableau, liste_eleves, nb_eleves);
    
    afficherPlanDeClasse(rangee, place, tableau, liste_eleves);
    
    return 0;
}
