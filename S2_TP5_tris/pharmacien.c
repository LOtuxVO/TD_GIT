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

typedef struct Element {
    Medicament m;
    struct Element *suivant;
} Element, *Liste;

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

void rechercherParacetamol(Medicament Tab[80]) {
    int bas = 0;
    int haut = 80 - 1;
    int milieu;
    int trouve = -1;

    while (bas <= haut && trouve == -1) {
        milieu = (bas + haut) / 2;

        if (strcmp(Tab[milieu].nom, "paracetamol") == 0) {
            trouve = milieu; 
        }
        else if (strcmp(Tab[milieu].nom, "paracetamol") < 0) {
            bas = milieu + 1;
        }
        else {
            haut = milieu - 1;
        }
    }

    if (trouve != -1) {
        printf("\nLe medicament 'paracetamol' a ete trouve a l'indice %d.\n", trouve);
    } else {
        printf("\nLe medicament 'paracetamol' n'est pas dans le tableau.\n");
    }
}

void afficherLePlusCher(Medicament Tab[80]) {
    int i;
    int maxIdx = 0;

    for (i = 1; i < 80; i++) {
        if (Tab[i].prix_unitaire > Tab[maxIdx].prix_unitaire) {
            maxIdx = i;
        }
    }

    printf("\n--- Medicament le plus cher ---\n");
    printf("Nom : %s\n", Tab[maxIdx].nom);
    printf("Prix : %.2f $\n", Tab[maxIdx].prix_unitaire);
}

float calculerTauxVentes(Medicament Tab[80]) {
    int i;
    int totalVendus = 0;
    int totalRestant = 0;
    float taux;

    for (i = 0; i < 80; i++) {
        totalVendus += Tab[i].unites_vendues;
        totalRestant += Tab[i].stock_restant;
    }

    if ((totalVendus + totalRestant) == 0) return 0.0;

    taux = ((float)totalVendus / (totalVendus + totalRestant)) * 100.0;
    return taux;
}

void trierListeParCode(Liste L) {
    if (L == NULL) return;

    Element *i, *j;
    Medicament temp;

    for (i = L; i != NULL; i = i->suivant) {
        for (j = i->suivant; j != NULL; j = j->suivant) {
            if (strcmp(i->m.code, j->m.code) > 0) {
                temp = i->m;
                i->m = j->m;
                j->m = temp;
            }
        }
    }
}

int main() {
    Medicament pharmacie[80];

    gererStock(pharmacie);
    afficherLePlusCher(pharmacie);
    rechercherParacetamol(pharmacie);
    printf("\nTaux global de medicaments vendus : %.2f%%\n", calculerTauxVentes(pharmacie));
    trierListeParCode(NULL);


    return 0;
}
