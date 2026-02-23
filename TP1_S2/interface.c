#include "pointH.h"

#define ID_BTN_FILE 101
#define ID_EDIT_ROWS 102
#define ID_EDIT_SEATS 103
#define ID_BTN_GEN 104
#define ID_LBL_FILE 105

HWND hEditRows, hEditSeats, hLabelFile;
char szFileName[MAX_PATH] = "";

void OnGenerate(HWND hwnd) {
    char buffer[256];
    
    GetWindowText(hEditRows, buffer, 256);
    int rangee = atoi(buffer);
    
    GetWindowText(hEditSeats, buffer, 256);
    int place = atoi(buffer);

    if (rangee <= 0 || place <= 0) {
        MessageBox(hwnd, "Veuillez entrer des dimensions valides (nombres entiers positifs).", "Erreur", MB_ICONERROR);
        return;
    }
    
    if (strlen(szFileName) == 0) {
        MessageBox(hwnd, "Veuillez selectionner un fichier liste (.txt).", "Erreur", MB_ICONERROR);
        return;
    }

    
    srand((unsigned int)time(NULL));
    int MAX_ELEVES = rangee * place;

    Eleve *liste_eleves = (Eleve *)malloc(sizeof(Eleve) * MAX_ELEVES);
    if (!liste_eleves) {
        MessageBox(hwnd, "Erreur d'allocation memoire.", "Erreur", MB_ICONERROR);
        return;
    }

    int nb_eleves = lireFichierEleves(szFileName, liste_eleves, MAX_ELEVES);

    if (nb_eleves == 0) {
        MessageBox(hwnd, "Aucun eleve lu ou erreur lors de l'ouverture du fichier.", "Erreur", MB_ICONERROR);
        free(liste_eleves);
        return;
    }

    melangerEleves(liste_eleves, nb_eleves);

    int tableau[rangee][place];

    initTab(rangee, place, tableau);
    placerEleve(rangee, place, tableau, liste_eleves, nb_eleves);
    
    enregistrerPlanDeClasse("sortie.txt", rangee, place, tableau, liste_eleves, nb_eleves);
    
    free(liste_eleves);
    
    MessageBox(hwnd, "Le plan de classe a ete genere avec succes dans 'sortie.txt' !", "Succes", MB_ICONINFORMATION);
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch(msg) {
        case WM_CREATE:

            CreateWindow("STATIC", "Fichier liste :", WS_VISIBLE | WS_CHILD, 20, 20, 100, 20, hwnd, NULL, NULL, NULL);
            hLabelFile = CreateWindow("STATIC", "Aucun fichier selectionne", WS_VISIBLE | WS_CHILD, 120, 20, 250, 20, hwnd, (HMENU)ID_LBL_FILE, NULL, NULL);
            CreateWindow("BUTTON", "...", WS_VISIBLE | WS_CHILD, 380, 15, 30, 30, hwnd, (HMENU)ID_BTN_FILE, NULL, NULL);

            CreateWindow("STATIC", "Rangees :", WS_VISIBLE | WS_CHILD, 20, 60, 80, 20, hwnd, NULL, NULL, NULL);
            hEditRows = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 100, 60, 50, 20, hwnd, (HMENU)ID_EDIT_ROWS, NULL, NULL);

            CreateWindow("STATIC", "Places/R :", WS_VISIBLE | WS_CHILD, 170, 60, 80, 20, hwnd, NULL, NULL, NULL);
            hEditSeats = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 250, 60, 50, 20, hwnd, (HMENU)ID_EDIT_SEATS, NULL, NULL);

            CreateWindow("BUTTON", "Generer le plan d'examen", WS_VISIBLE | WS_CHILD, 20, 100, 390, 40, hwnd, (HMENU)ID_BTN_GEN, NULL, NULL);
            break;

        case WM_COMMAND:
            if (LOWORD(wParam) == ID_BTN_FILE) {
                OPENFILENAME ofn;
                char szFile[260];
                
                ZeroMemory(&ofn, sizeof(ofn));
                ofn.lStructSize = sizeof(ofn);
                ofn.hwndOwner = hwnd;
                ofn.lpstrFile = szFile;
                ofn.lpstrFile[0] = '\0';
                ofn.nMaxFile = sizeof(szFile);
                ofn.lpstrFilter = "Fichiers Texte (*.txt)\0*.txt\0Tous les fichiers (*.*)\0*.*\0";
                ofn.nFilterIndex = 1;
                ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

                if (GetOpenFileName(&ofn) == TRUE) {
                    strcpy(szFileName, ofn.lpstrFile);
                    SetWindowText(hLabelFile, szFileName);
                }
            }
            else if (LOWORD(wParam) == ID_BTN_GEN) {
                OnGenerate(hwnd);
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASS wc = {0};
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = "InterfaceApp";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClass(&wc)) return -1;

    CreateWindow("InterfaceApp", "Generateur Plan de Classe", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 450, 200, NULL, NULL, hInst, NULL);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
