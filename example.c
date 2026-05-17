#include "cordic.h"
#include "pi.h"
#include <math.h>
#include <stdio.h>

#define rad(angle) MY_PI *angle / 180.

int main(void) {
    for (double x = 0; x < 90; x += 0.1) {
        if((int)(10*x)%10==0) {
        printf("----------------------------------------------------------------------------------------\n");
        printf("Angle\t\t  cos\t\t\t\t  cos error\t\t\t  sin\t\t\t\t  sin error\n");
        printf("----------------------------------------------------------------------------------------\n");
        }
        printf("%f\t%16.12f\t%16.12f\t%16.12f\t%16.12f\n", x, my_sin(rad(x)),
               my_sin(rad(x)) - sin(rad(x)), my_cos(rad(x)),
               my_cos(rad(x)) - cos(rad(x)));
    }
}
