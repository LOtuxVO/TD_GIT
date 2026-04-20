#include <stdio.h>
#include <string.h>

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    char nom[50];
    char code[20];
    Date date_fabrication;
    Date date_peremption;
    float prix_unitaire;
    int unites_vendues;
    int stock_restant;
} Medicament;

int estApres(Date d1, Date d2) {
    if (d1.annee > d2.annee) return 1;
    if (d1.annee < d2.annee) return 0;
    if (d1.mois > d2.mois) return 1;
    if (d1.mois < d2.mois) return 0;
    return d1.jour > d2.jour;
}

void gererStock(Medicament Tab[80]) {
    int i, j;
    Medicament temp;

    printf("--- Saisie des 80 medicaments ---\n");
    for (i = 0; i < 80; i++) {
        printf("\nMedicament n %d :\n", i + 1);
        printf("Nom : ");
        scanf("%s", Tab[i].nom);
        printf("Code : ");
        scanf("%s", Tab[i].code);
        printf("Date fabrication (JJ MM AAAA) : ");
        scanf("%d %d %d", &Tab[i].date_fabrication.jour, &Tab[i].date_fabrication.mois, &Tab[i].date_fabrication.annee);
        printf("Date peremption (JJ MM AAAA) : ");
        scanf("%d %d %d", &Tab[i].date_peremption.jour, &Tab[i].date_peremption.mois, &Tab[i].date_peremption.annee);
        printf("Prix unitaire ($) : ");
        scanf("%f", &Tab[i].prix_unitaire);
        printf("Nombre d'unites vendues : ");
        scanf("%d", &Tab[i].unites_vendues);
        printf("Nombre restant en stock : ");
        scanf("%d", &Tab[i].stock_restant);
    }

    for (i = 0; i < 80 - 1; i++) {
        for (j = 0; j < 80 - i - 1; j++) {
            if (estApres(Tab[j].date_peremption, Tab[j+1].date_peremption)) {
                temp = Tab[j];
                Tab[j] = Tab[j + 1];
                Tab[j + 1] = temp;
            }
        }
    }
    
    printf("\nSaisie terminee et tableau trie par date de peremption.\n");
}

int main() {
    Medicament pharmacie[80];
    
    gererStock(pharmacie);

    return 0;
}
