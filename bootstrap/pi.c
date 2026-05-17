#include "atan.h"
#include <stdio.h>

// calculate pi for use with CORDIC, get double precision
int main(void) {
    double pi = 16 * my_atan(1. / 5) - 4 * my_atan(1. / 239);
    long long ll_pi = pi * 1e14;
    FILE *fp = fopen("pi.h", "w");
    fprintf(fp, "//pi constant calculated in pi.c\n#define MY_PI %.14f\n", pi);
    fprintf(fp, "#define MY_FIXNUMPI %Li", ll_pi);
    fclose(fp);
    return 0;
}
