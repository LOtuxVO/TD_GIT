#include    <stdio.h>

int main() {

    int secondes = 0;

    printf("Entrez un nombre de secondes : ");
    scanf("%d", &secondes);

    int heures = secondes / 3600;
    int minutes = (secondes % 3600) / 60;
    int sec = secondes % 60;

    printf("%d secondes correspondent a %d heures, %d minutes et %d secondes.\n", secondes, heures, minutes, sec);
    
    return 0;
}