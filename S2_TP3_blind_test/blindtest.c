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

    // On garde que 5 chansons pour la partie
    if (song_count > 5) {
        song_count = 5;
    }

    printf("%d chansons chargees et melangees avec succes :\n", song_count);
    for (int i = 0; i < song_count; i++) {
        printf("  - Titre: %s, Artiste: %s, Fichier: %s\n", songs[i].titre, songs[i].artiste, songs[i].file);
    }
    printf("\n");

    return 0;
}