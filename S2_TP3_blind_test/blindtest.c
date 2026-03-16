
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/*--------------------------------------------------- */
/* STRUCT                                             */
/*--------------------------------------------------- */

typedef struct {
    char file[100];
    char title[100];
    char artist[100];
} Song;

/* -------------------------------------------------- */
/* OUTILS SUR LES CHAINES                             */
/* -------------------------------------------------- */

/* Supprime les caractères de fin de ligne (\n ou \r) d'une chaîne */
void trim_newline(char *s) {
    size_t len = strlen(s);

    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r')) {
        s[len - 1] = '\0';
        len--;
    }
}

/* 
Normalise une chaîne :
- supprime les espaces inutiles
- convertit en minuscules
Permet de comparer deux réponses sans tenir compte
des majuscules et des espaces.
*/
void normalize_string(char *dest, const char *src) {
    int i = 0;
    int j = 0;
    int prev_space = 0;

    while (src[i] != '\0' && isspace((unsigned char)src[i])) {
        i++;
    }

    while (src[i] != '\0') {
        unsigned char c = (unsigned char)src[i];

        if (isspace(c)) {
            prev_space = 1;
        } else {
            if (prev_space && j > 0) {
                dest[j++] = ' ';
            }
            dest[j++] = (char)tolower(c);
            prev_space = 0;
        }

        i++;
    }

    dest[j] = '\0';
}

/* 
Compare deux chaînes après normalisation.
Retourne 1 si elles sont équivalentes, sinon 0.
*/
int string_equals_normalized(const char *a, const char *b) {
    char na[100];
    char nb[100];

    normalize_string(na, a);
    normalize_string(nb, b);

    return strcmp(na, nb) == 0;
}

/* -------------------------------------------------- */
/* GESTION AUDIO                                      */
/* -------------------------------------------------- */

/*
Lance la lecture d'un extrait audio avec ffplay.
start = instant de départ
seconds = durée de l'extrait
*/
void play_song_excerpt_at(const char *filename, int start, int seconds) {
    char command[1024];

    snprintf(command, sizeof(command),
             "ffplay -nodisp -autoexit -loglevel quiet -ss %d -t %d \"%s\"",
             start, seconds, filename);

    system(command);
}




/* -------------------------------------------------- */
/* PROGRAMME PRINCIPAL                                */
/* -------------------------------------------------- */

int main() {



    return 0;
}