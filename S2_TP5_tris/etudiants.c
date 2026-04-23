#include <stdio.h>
#include <string.h>

#define N 100

typedef struct {
    char nom[50];
    char prenom[50];
    char matricule[20];
    float moyenne;
} Etudiant;

void permuter(Etudiant *e1, Etudiant *e2) {
    Etudiant provisoire = *e1;
    *e1 = *e2;
    *e2 = provisoire;
}

int separer(Etudiant T[], int debut, int fin) {
    float pivot = T[fin].moyenne;
    int i = debut;

    for (int j = debut; j < fin; j++) {
        if (T[j].moyenne > pivot) {
            permuter(&T[i], &T[j]);
            i++;
        }
    }
    permuter(&T[i], &T[fin]);
    return i;
}

void triRapide(Etudiant T[], int debut, int fin) {
    if (debut < fin) {
        int positionPivot = separer(T, debut, fin);

        triRapide(T, debut, positionPivot - 1);
        triRapide(T, positionPivot + 1, fin);
    }
}

int main() {
    Etudiant liste[N];
    
    strcpy(liste[0].nom, "Dupont");
    liste[0].moyenne = 12.5;

    strcpy(liste[1].nom, "Durand");
    liste[1].moyenne = 18.0;

    strcpy(liste[2].nom, "Martin");
    liste[2].moyenne = 14.5;

    triRapide(liste, 0, 2);

    printf("Classement par merite :\n");
    for(int i = 0; i < 3; i++) {
        printf("%d. %s - Moyenne : %.2f\n", i+1, liste[i].nom, liste[i].moyenne);
    }

    return 0;
}
