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
        char *titre_token = strtok(NULL, ";");
        char *artiste_token = strtok(NULL, ";");

        if (file_token == NULL || titre_token == NULL || artiste_token == NULL) {
            fprintf(stderr, "Ligne mal formatee ignoree dans %s\n", filename);
            continue;
        }

        strncpy(songs[count].file, file_token, 256 - 1);
        strncpy(songs[count].titre, titre_token, 256 - 1);
        strncpy(songs[count].artiste, artiste_token, 256 - 1);
        count++;
    }

    fclose(f);
    return count;
}

void melanger_chansons(Song songs[], int count) {
    for (int i = count - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Song temp = songs[i];
        songs[i] = songs[j];
        songs[j] = temp;
    }
}

/* -------------------------------------------------- */
/* GESTION DU JOUEUR                                  */
/* -------------------------------------------------- */

void choixPseudo(char *playerName) {
    char input[256];
    int isValid = 0;

    do {
        printf("Entrez votre pseudo (3 lettres, ex: ABC) : ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            trim_newline(input);

            if (strlen(input) != 3) {
                printf("erreur -> Le pseudo doit faire exactement 3 caracteres.\n\n");
                continue;
            }

            isValid = 1;
            for (int i = 0; i < 3; i++) {
                if (!isalpha((unsigned char)input[i])) {
                    printf("erreur -> Le pseudo ne doit contenir que des lettres.\n\n");
                    isValid = 0;
                    break;
                }
                playerName[i] = toupper((unsigned char)input[i]);
            }
            playerName[3] = '\0';
        }
    } while (!isValid);
}

void jouer_extrait(const char *filename) {
    char command[512];
    // debut musique entre 20 et 60 secondes pour changer
    int start = rand() % 40 + 20; 
    int duration = 8; // Duree de l'extrait

    // commande pour lancer la musica
    snprintf(command, sizeof(command), "ffplay -nodisp -autoexit -loglevel quiet -ss %d -t %d \"%s\"", start, duration, filename);
    system(command);
}

/* -------------------------------------------------- */
/* GESTION DES SCORES                                 */
/* -------------------------------------------------- */

Score* charger_scores(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) return NULL;

    Score *head = NULL;
    char line[512];

    while (fgets(line, sizeof(line), f) != NULL) {
        trim_newline(line);
        if (strlen(line) == 0) continue;

        char *name_token = strtok(line, ";");
        char *score_token = strtok(NULL, ";");
        char *total_songs_token = strtok(NULL, ";");

        if (name_token && score_token && total_songs_token) {
            Score *new_node = malloc(sizeof(Score));
            strncpy(new_node->name, name_token, 255);
            new_node->name[255] = '\0';
            new_node->score = atoi(score_token);
            new_node->total_songs = atoi(total_songs_token);
            new_node->next = head;
            head = new_node;
        }
    }
    fclose(f);
    return head;
}

void update_score(Score **head, const char *player, int current_score, int total_songs) {
    Score *current = *head;
    while (current != NULL) {
        if (strcmp(current->name, player) == 0 && current->total_songs == total_songs) {
            if (current_score > current->score) {
                current->score = current_score;
            }
            return;
        }
        current = current->next;
    }

    // Joueur non trouvé pour ce nombre de titres, ajout en tête
    Score *new_node = malloc(sizeof(Score));
    strncpy(new_node->name, player, 255);
    new_node->name[255] = '\0';
    new_node->score = current_score;
    new_node->total_songs = total_songs;
    new_node->next = *head;
    *head = new_node;
}

void sauver_scores(const char *filename, Score *head) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) return;

    while (head != NULL) {
        fprintf(f, "%s;%d;%d\n", head->name, head->score, head->total_songs);
        Score *temp = head;
        head = head->next;
        free(temp); // libérer la mémoire
    }
    fclose(f);
}

void free_scores(Score *head) {
    while (head != NULL) {
        Score *temp = head;
        head = head->next;
        free(temp);
    }
}
