#ifndef FICHIER
#define FICHIER

#include <stdio.h>
#include <windows.h>
#include <locale.h>

void afficherMenu();

int lireChoix();

void ajouterConsommation(int consommations[]);

void afficheResume(int consommations[]);

int charger(int consommations[]);

int sauvegarder(int consommations[]);

int humeurBonbons(int nbBonbons);

int humeurLegumes(int nbLegumes);

int humeurFruits(int nbFruits);

#endif
