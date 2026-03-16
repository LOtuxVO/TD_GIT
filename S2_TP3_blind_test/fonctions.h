#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


typedef struct {
    char file[256];
    char title[256];
    char artist[256];
} Song;

// --- Prototypes des fonctions ---

// Outils sur les chaînes
void trim_newline(char *s);
void normalize_string(char *dest, const char *src);
int string_equals_normalized(const char *a, const char *b);

// Gestion des chansons
int charger_chansons(const char *filename, Song songs[], int max_songs);


#endif // FONCTIONS_H
