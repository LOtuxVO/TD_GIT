#include <stdio.h>

int main() {
    int distance_km = 100;
    int vitesse_kmh = 50;
    int temps = 0; // initialisation de la variable temps
    int minutes = 0; // initialisation de la variable minutes
    temps = distance_km / vitesse_kmh; // calcul du temps en heures
    minutes = temps * 60; // conversion du temps en minutes
    printf("minutes = %i\n", minutes); 
    return 0;
}
