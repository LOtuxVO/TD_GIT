#ifndef POINTH
#define POINTH

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct Eleve {
    char prenom[50];
    char nom[50];

} Eleve;

typedef struct Place {
    int rangee;
    int table;
    int occupe;

} Place;


int nombreRangee();

int nombrePlace();

void nomListe(char *nom_liste);

void lireFichierEleves(const char *nom_fichier);

void initTab(char tableau[50][50], int rangee, int place);



#endif