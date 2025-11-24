void afficherMenu();

int lireChoix();

int saisirNombreEleves();

void saisirNotes(float notes[30][3], int nombreEleves);

void afficherNotes(float notes[30][3], int nombreEleves);

float calculerMoyenneEleve(float notesEleve[3]);

float calculerMoyenneGenerale(float notes[30][3], int nombreEleves);

float trouverMeilleureNoteControle(float notes[30][3], int nombreEleves, int indiceControle);