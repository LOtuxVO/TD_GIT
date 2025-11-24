#include <stdio.h>
#include <windows.h>

void afficherMenu() {
    printf("\n===== GESTION DE NOTES =====\n");
    printf("1. Saisir le nombre d'eleves\n");
    printf("2. Saisir les notes des eleves\n");
    printf("3. Afficher toutes les notes\n");
    printf("4. Afficher la moyenne d'un eleve\n");
    printf("5. Afficher la moyenne generale\n");
    printf("6. Afficher la meilleure note de chaque controle\n");
    printf("0. Quitter\n");
}

int lireChoix() {
    int choix;
    scanf("%d", &choix);

    return choix;
}

int saisirNombreEleves() {
    int nombreEleves = 0;

    while (nombreEleves < 1 || nombreEleves > 30) {
        printf("Combien d'eleves dans la classe ? (entre 1 et 30) : ");
        scanf("%d", &nombreEleves);
        if (nombreEleves < 1 || nombreEleves > 30) {
            printf("Erreur : le nombre doit etre compris entre 1 et 30.\n");
        }
    }

    return nombreEleves;
}

void saisirNotes(float notes[30][3], int nombreEleves) {
    for (int i = 0; i < nombreEleves; i++) {
        printf("\n--- Saisie des notes pour l'eleve %d ---\n", i + 1);
        for (int j = 0; j < 3; j++) {
            notes[i][j] = -1.0f;
            while (notes[i][j] < 0.0f || notes[i][j] > 20.0f) {
                printf("Note du controle %d : ", j + 1);
                scanf("%f", &notes[i][j]);
                if (notes[i][j] < 0 || notes[i][j] > 20) {
                    printf("Erreur : la note doit etre comprise entre 0 et 20.\n");
                }
            }
        }
    }
}


void afficherNotes(float notes[30][3], int nombreEleves) {
    printf("\n--- Tableau des notes ---\n");
    printf("Eleve\tC1\tC2\tC3\n");
    printf("--------------------------\n");
    for (int i = 0; i < nombreEleves; i++) {
        printf("%d\t", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%.2f\t", notes[i][j]); 
        }
        printf("\n"); 
    }
}

float calculerMoyenneEleve(float notesEleve[3]) {
    float somme = 0.0f;
    for (int i = 0; i < 3; i++) {
        somme += notesEleve[i];
    }
    return somme / 3.0f;
}
float calculerMoyenneGenerale(float notes[30][3], int nombreEleves) {
    float sommeDesMoyennes = 0.0f;
    for (int i = 0; i < nombreEleves; i++) {
        sommeDesMoyennes += calculerMoyenneEleve(notes[i]);
    }
    return sommeDesMoyennes / nombreEleves;
}
float trouverMeilleureNoteControle(float notes[30][3], int nombreEleves, int indiceControle) {
    float meilleureNote = notes[0][indiceControle];
    for (int i = 1; i < nombreEleves; i++) {
        if (notes[i][indiceControle] > meilleureNote) {
            meilleureNote = notes[i][indiceControle];
        }
    }
    return meilleureNote;
}

int main() {
    int choixUtilisateur;
    int nombreEleves = 0;
    int max_eleves = 30;
    int max_notes = 3;
    float notes[max_eleves][max_notes];
    choixUtilisateur = -1; 

    while (choixUtilisateur != 0) {
        afficherMenu();
        printf("\nVotre choix : ");
        choixUtilisateur = lireChoix();

        switch (choixUtilisateur) {
            case 1:
                nombreEleves = saisirNombreEleves();
                printf("\nLe nombre d'eleves est maintenant de : %d\n", nombreEleves);
                Sleep(3000);
                break;
            
            case 2:
                if (nombreEleves == 0) {
                    printf("\nErreur : Vous devez d'abord saisir le nombre d'eleves (Option 1).\n");
                } else {
                    saisirNotes(notes, nombreEleves);
                    printf("\nSaisie des notes terminee.\n");
                }
                Sleep(3000);
                break;

            case 3:
                if (nombreEleves == 0) {
                    printf("\nErreur : Aucune note a afficher. Saisissez d'abord le nombre d'eleves et les notes.\n");
                } else {
                    afficherNotes(notes, nombreEleves);
                }
                Sleep(5000);
                break;

            case 4:
                if (nombreEleves == 0) {
                    printf("\nErreur : Vous devez d'abord saisir les eleves et les notes.\n");
                } else {
                    int eleveChoisi;
                    while (eleveChoisi < 1 || eleveChoisi > nombreEleves) {
                        printf("\nCalculer la moyenne de quel eleve ? (1 a %d) : ", nombreEleves);
                        scanf("%d", &eleveChoisi);
                        if (eleveChoisi < 1 || eleveChoisi > nombreEleves) {
                            printf("Numero d'eleve invalide.\n");
                        }
                    } while (eleveChoisi < 1 || eleveChoisi > nombreEleves);
                    float moyenne = calculerMoyenneEleve(notes[eleveChoisi - 1]);
                    printf("La moyenne de l'eleve %d est : %.2f\n", eleveChoisi, moyenne);
                }
                Sleep(3000);
                break;
            
            case 5:
                if (nombreEleves == 0) {
                    printf("\nErreur : Vous devez d'abord saisir les eleves et les notes.\n");
                } else {
                    float moyenneGenerale = calculerMoyenneGenerale(notes, nombreEleves);
                    printf("\nLa moyenne generale de la classe est : %.2f\n", moyenneGenerale);
                }
                Sleep(3000);
                break;

            case 6:
                if (nombreEleves == 0) {
                    printf("\nErreur : Vous devez d'abord saisir les eleves et les notes.\n");
                } else {
                    printf("\n--- Meilleures notes par controle ---\n");
                    float meilleureC1 = trouverMeilleureNoteControle(notes, nombreEleves, 0);
                    printf("Meilleure note du Controle 1 : %.2f\n", meilleureC1);
                    float meilleureC2 = trouverMeilleureNoteControle(notes, nombreEleves, 1);
                    printf("Meilleure note du Controle 2 : %.2f\n", meilleureC2);
                    float meilleureC3 = trouverMeilleureNoteControle(notes, nombreEleves, 2);
                    printf("Meilleure note du Controle 3 : %.2f\n", meilleureC3);
                }
                Sleep(4000);
                break;
            case 0:
                printf("\nAu revoir !\n");
                break;
            
            default:
                printf("\nChoix invalide. Veuillez reessayer.\n");
                break;
        }
    }
    
    return 0;
}
