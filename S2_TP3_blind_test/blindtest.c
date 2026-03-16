#include "fonctions.h"

/* -------------------------------------------------- */
/* PROGRAMME PRINCIPAL                                */
/* -------------------------------------------------- */

int main() {
    srand(time(NULL));

    printf("--- Blind Test ---\n\n");

    Song songs[150];
    int song_count = charger_chansons("songs.txt", songs, 150   );

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
 /* for (int i = 0; i < song_count; i++) {
        printf("  - Titre: %s, Artiste: %s, Fichier: %s\n", songs[i].titre, songs[i].artiste, songs[i].file);
    }
    printf("\n");
 */

    // choix du pseudo en 3 caractere a la retro gaming
    char playerName[4];
    choixPseudo(playerName);

    printf("\nBienvenue, %s ! Le blind-test va commencer.\n\n", playerName);

    // a voir pour mettre sauvegarde des meilleurs score avec les pseudo dans un txt
    return 0;
}