#include "fonctions.h"

/* -------------------------------------------------- */
/* PROGRAMME PRINCIPAL                                */
/* -------------------------------------------------- */

int main() {
    srand(time(NULL));

    printf("--- Bienvenue au Blind Test ---\n\n");

    Song songs[50];
    int song_count = charger_chansons("songs.txt", songs, 50);

    if (song_count <= 0) {
        fprintf(stderr, "Aucune chanson n'a pu etre chargee. Le programme va s'arreter.\n");
        return 1;
    }

    printf("%d chanson(s) chargee(s) avec succes :\n", song_count);
    for (int i = 0; i < song_count; i++) {
        printf("  - Titre: %s, Artiste: %s, Fichier: %s\n", songs[i].title, songs[i].artist, songs[i].file);
    }
    printf("\n");

    return 0;
}