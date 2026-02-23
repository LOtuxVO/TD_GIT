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

int lireFichierEleves(const char *nom_fichier, Eleve liste_eleves[], int max_eleves);

void melangerEleves(Eleve liste_eleves[], int nb_eleves);

void initTab(int rangee, int place, int tableau[rangee][place]);

void placerEleve(int rangee, int place, int tableau[rangee][place], Eleve liste_eleves[], int nb_eleves);

void afficherPlanDeClasse(int rangee, int place, int plan[rangee][place], Eleve liste_eleves[]);

void enregistrerPlanDeClasse(const char *nom_fichier, int rangee, int place, int plan[rangee][place], Eleve liste_eleves[], int nb_eleves);

#endif