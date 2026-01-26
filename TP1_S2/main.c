#include "pointH.h"

int main() {
    
    int rangee = nombreRangee();
    int place = nombrePlace();
    printf("Le nombre de rangee est : %d\n", rangee);
    printf("Le nombre de place par rangee est : %d\n", place);


    char nom_liste[50];
    nomListe(nom_liste);

    printf("Le nom de la liste est : %s\n", nom_liste);

    lireFichierEleves(nom_liste);

    char tableau[rangee][place];

    initTab(tableau, rangee, place);
    printf("tableau initialise\n");

    
    
    return 0;
}
