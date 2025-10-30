#include    <stdio.h>
int main() {
    
    int secondes = 0;

    printf("Entrez un nombre de secondes : ");
    scanf("%d", &secondes);

    int annees = secondes / (3600 * 24 * 365);
    int jours = secondes / (3600 * 24);
    int heures = secondes / 3600;
    int minutes = (secondes % 3600) / 60;
    int sec = secondes % 60;

    printf("%d secondes correspondent a %d annees, %d jours, %d heures, %d minutes et %d secondes.\n",secondes, annees, jours, heures, minutes, sec);

    return 0;
}