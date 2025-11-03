#include <stdio.h>

int main() {
    char s[5]=" "; // n'etait pas vide au debut
    s[0] = 'H';
    s[1] = 'e';
    s[2] = 'y';
    s[3] = '!';
    printf("%s\n", s); 
    return 0;
}
