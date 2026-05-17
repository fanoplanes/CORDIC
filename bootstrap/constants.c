#include <stdio.h>
#include "atan.h"
#include "sqrt.h"

long long angles[47];
double k[47];

void gen_angles(void) {
    for(int i=0; i < 47; i++) {
        angles[i] = my_atan(1/power(2, i)) * 1e14;
    }
}

void gen_k(void) {
    for(int i=0; i < 47; i++) {
        double _k = 1;
        for(int j=0; j <= i; j++) {
            _k *= 1./my_sqrt(1. + (1. / power(2, 2*j)));
        }
        k[i] = _k;
    }
}

int main(void) {
    FILE* fp = fopen("constants.h", "w");
    gen_angles();
    fprintf(fp, "//constants computed in constants.c\n");
    fprintf(fp, "const double angles[] = {\n");
    for (int i = 0; i < 47; i++) {
        if(i == 46) {
            fprintf(fp, "\t%Li", angles[i]);
        }else{
            fprintf(fp, "\t%Li,", angles[i]);
        }
        if(i%4 == 3) fprintf(fp, "\n");
    }
    fprintf(fp, "};\n\n");
    gen_k();
    fprintf(fp, "const double k[] = {\n");
    for (int i = 0; i < 47; i++) {
        if(i == 46) {
            fprintf(fp, "\t%.14f", k[i]);
        }else{
            fprintf(fp, "\t%.14f,", k[i]);
        }
        if(i%4 == 3) fprintf(fp, "\n");
    }
    fprintf(fp, "};");
    fclose(fp);
    return 0;
}
