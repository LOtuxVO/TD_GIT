#include <stdio.h>

int main() {
    int x = 42; //warning: initialization makes integer from pointer without a cast [-Wint-conversion] int x ="42";
    printf("%d\n", x);
    return 0;
}
