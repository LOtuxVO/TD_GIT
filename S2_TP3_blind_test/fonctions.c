#include "fonctions.h"

/* -------------------------------------------------- */
/* OUTILS SUR LES CHAINES                             */
/* -------------------------------------------------- */

void trim_newline(char *s) {
    size_t len = strlen(s);
    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r')) {
        s[len - 1] = '\0';
        len--;
    }
}

void normalize_string(char *dest, const char *src) {
    int i = 0, j = 0, prev_space = 1;
    while (src[i] != '\0' && isspace((unsigned char)src[i])) i++;
    while (src[i] != '\0') {
        unsigned char c = (unsigned char)src[i];
        if (isspace(c)) {
            prev_space = 1;
        } else {
            if (prev_space && j > 0) dest[j++] = ' ';
            dest[j++] = (char)tolower(c);
            prev_space = 0;
        }
        i++;
    }
    dest[j] = '\0';
}

int string_equals_normalized(const char *a, const char *b) {
    char na[256];
    char nb[256];
    normalize_string(na, a);
    normalize_string(nb, b);
    return strcmp(na, nb) == 0;
}

/* -------------------------------------------------- */
/* GESTION DES CHANSONS                               */
/* -------------------------------------------------- */

int charger_chansons(const char *filename, Song songs[], int max_songs) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier de chansons");
        return -1;
    }

    char line[256 * 3];
    int count = 0;

    while (fgets(line, sizeof(line), f) != NULL && count < max_songs) {
        trim_newline(line);
        if (strlen(line) == 0) {
            continue;
        }

        char *file_token = strtok(line, ";");
        char *title_token = strtok(NULL, ";");
        char *artist_token = strtok(NULL, ";");

        if (file_token == NULL || title_token == NULL || artist_token == NULL) {
            fprintf(stderr, "Ligne mal formatee ignoree dans %s\n", filename);
            continue;
        }

        strncpy(songs[count].file, file_token, 256 - 1);
        strncpy(songs[count].title, title_token, 256 - 1);
        strncpy(songs[count].artist, artist_token, 256 - 1);
        count++;
    }

    fclose(f);
    return count;
}
