#include <stdio.h>
#include <math.h>

int main() {
   
    double montant_pret;
    double taux_annuel;
    int duree_annees;
    double mensualite;

    printf("Veuillez entrer le montant du pret (C) : ");
    scanf("%lf", &montant_pret);

    printf("Veuillez entrer le taux d'interet annuel (t, en pourcentage, ex: 4.5) : ");
    scanf("%lf", &taux_annuel);

    printf("Veuillez entrer la durée du pret en annees (n) : ");
    scanf("%d", &duree_annees);

    double taux_mensuel = (taux_annuel / 100.0) / 12.0;

    int nombre_de_paiements = duree_annees * 12;

    if (taux_mensuel == 0) {
        mensualite = montant_pret / nombre_de_paiements;
    } else {
        double numerateur = montant_pret * taux_mensuel;
        double denominateur = 1 - pow(1 + taux_mensuel, -nombre_de_paiements);
        mensualite = numerateur / denominateur;
    }

    printf("\nLa mensualite du pret est de : %.2f\n", mensualite);

    return 0;
}
