#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


typedef struct song {
    char file[256];
    char titre[256];
    char artiste[256];
} Song;


void trim_newline(char *s);

void normalize_string(char *dest, const char *src);

int string_equals_normalized(const char *a, const char *b);

int charger_chansons(const char *filename, Song songs[], int max_songs);

void melanger_chansons(Song songs[], int count);

void choixPseudo(char *playerName);


#endif
