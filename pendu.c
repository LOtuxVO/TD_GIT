#include <stdio.h>
#include <string.h> 
#include <ctype.h> 

void vider_tampon() {
    int c = 0;
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

int main() {
    const char* etats_pendu[] = {
        "\n\n\n\n\n\n\n-------\n",
        "\n |\n |\n |\n |\n |\n |\n-------\n",
        " -------\n |     |\n |\n |\n |\n |\n-------\n",
        " -------\n |     |\n |     O\n |\n |\n |\n-------\n",
        " -------\n |     |\n |     O\n |     |\n |\n |\n-------\n",
        " -------\n |     |\n |     O\n |    /|\\\n |\n |\n-------\n",
        " -------\n |     |\n |     O\n |    /|\\\n |    / \\\n |\n-------\n"
    };
    const int MAX_ERREURS = 6;

    char mot_secret[100];
    char mot_cache[100];
    char lettre;
    int nombre_erreurs = 0;
    int mot_trouve = 0;

    printf("Bienvenue dans le jeu du pendu !\n");
    printf("Le maitre du jeu entre un mot secret : ");
    scanf("%99s", mot_secret); 
    vider_tampon();

    for (int i = 0; mot_secret[i] != '\0'; i++) {
        mot_secret[i] = tolower(mot_secret[i]);
    }

    int longueur_mot = strlen(mot_secret);

    for (int i = 0; i < longueur_mot; i++) {
        mot_cache[i] = '*';
    }
    mot_cache[longueur_mot] = '\0'; 

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Le mot a ete cache. Que le jeu commence !\n");

    while (nombre_erreurs <= MAX_ERREURS && !mot_trouve) {
        printf("\nMot a deviner : %s\n", mot_cache);
        printf("Entrez une lettre : ");
        lettre = getchar();
        vider_tampon();

        if (!isalpha(lettre)) {
            printf("Veuillez entrer une lettre valide.\n");
            continue;
        }
        lettre = tolower(lettre);

        int lettre_trouvee = 0;
        for (int i = 0; i < longueur_mot; i++) {
            if (mot_secret[i] == lettre) {
                mot_cache[i] = lettre;
                lettre_trouvee = 1;
            }
        }

        if (!lettre_trouvee) {
            nombre_erreurs++;
            printf("Faux ! La lettre '%c' n'est pas dans le mot.\n", lettre);

            if (nombre_erreurs > 0 && nombre_erreurs <= MAX_ERREURS + 1) {
                printf("%s", etats_pendu[nombre_erreurs - 1]);
            }
        } else {
            printf("Bien joue ! La lettre '%c' est dans le mot.\n", lettre);
        }

        if (strcmp(mot_secret, mot_cache) == 0) {
            mot_trouve = 1;
        }
    }

    if (mot_trouve) {
        printf("\nFelicitations ! Vous avez trouve le mot : %s\n", mot_secret);
    } else {
        printf("\nDommage, vous avez perdu ! Le mot etait : %s\n", mot_secret);
    }

    return 0;
}