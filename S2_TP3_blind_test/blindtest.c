#include "fonctions.h"

/* -------------------------------------------------- */
/* PROGRAMME PRINCIPAL                                */
/* -------------------------------------------------- */

int main() {
    srand(time(NULL));

    printf("--- Blind Test ---\n\n");

    Song songs[50];
    int song_count = charger_chansons("songs.txt", songs, 50);

    if (song_count <= 0) {
        fprintf(stderr, "Aucune chanson n'a pu etre chargee. Le programme va s'arreter.\n");
        return 1;
    }

    // Melange les musique
    melanger_chansons(songs, song_count);

    // parametre pour avoir un nombre defini de musique par partie
    int nombre_musique_par_partie = 5;
    if (song_count > nombre_musique_par_partie) {
        song_count = nombre_musique_par_partie;
    }

    printf("%d chansons chargees et melangees avec succes !\n", song_count);
    // mis en commentaire pour pas tricher et avoir les solutions
 /* for (int i = 0; i < song_count; i++) {
        printf("  - Titre: %s, Artiste: %s, Fichier: %s\n", songs[i].titre, songs[i].artiste, songs[i].file);
    }
    printf("\n");
 */

    // choix du pseudo en 3 caractere a la retro gaming
    char playerName[4];
    choixPseudo(playerName);

    printf("\nBienvenue, %s ! Le blind-test va commencer.\n\n", playerName);

    int score = 0;

    for (int i = 0; i < song_count; i++) {
        printf("Question %d/%d : Ecoutez la musique...\n", i + 1, song_count);
        jouer_extrait(songs[i].file);
        printf("Fin de l'extrait.\n");

        char reponse[256];
        printf("Quel est le titre ? ");
        if (fgets(reponse, sizeof(reponse), stdin) != NULL) {
            trim_newline(reponse);
            if (string_equals_normalized(reponse, songs[i].titre)) {
                printf("Bravo ! Bonne reponse.\n\n");
                score++;
            } else {
                printf("Dommage. La reponse etait : %s\n\n", songs[i].titre);
            }
        }
    }

    printf("Partie terminee ! Votre score : %d / %d\n", score, song_count);

    
    Score *listeScores = charger_scores("scores.txt");
    update_score(&listeScores, playerName, score);
    sauver_scores("scores.txt", listeScores);

    return 0;
}