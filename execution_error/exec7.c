#include <stdio.h>

int main() {
    int distance_km = 100;
    int vitesse_kmh = 50;
    int temps = distance_km / vitesse_kmh; 
    int minutes = temps * 60;
    printf("minutes = %d\n", minutes); 
    return 0;
}
