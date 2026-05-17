#include "constants.h"
#include "pi.h"
#include <stdlib.h>

int step(long long *goal, long long *angle, long long *vector, int n) {
    double new_vector[2];
    if (*angle < *goal) {
        *angle += angles[n];
        new_vector[0] = vector[0] - (vector[1] >> n);
        new_vector[1] = vector[1] + (vector[0] >> n);
        vector[0] = new_vector[0];
        vector[1] = new_vector[1];
        return 0;
    } else if (*angle > *goal) {
        *angle -= angles[n];
        new_vector[0] = vector[0] + (vector[1] >> n);
        new_vector[1] = vector[1] - (vector[0] >> n);
        vector[0] = new_vector[0];
        vector[1] = new_vector[1];
        return 0;
    } else if (*angle == *goal) {
        return 1;
    }
    return -1;
}

// angles and sin/cos are stored as long long fixnums to make use of bitshifts
double *cordic(double angle) {
    if (angle < -MY_PI / 2. || angle >= 3 * MY_PI / 2.) {
        if (angle < -MY_PI / 2.) {
            return cordic(angle + 2 * MY_PI);
        } else {
            return cordic(angle - 2 * MY_PI);
        }
    }
    long long fixnum_goal;
    long long vector[2] = {1e14, 0};
    long long current_angle = 0;
    int code;
    int k_val = 0;
    int sgn = 1;
    if (angle > MY_PI / 2. && angle < 3 * MY_PI / 2.) {
        sgn = -1;
        fixnum_goal = (angle - MY_PI) * 1e14;
    } else {
        fixnum_goal = angle * 1e14;
    }
    for (k_val = 0; k_val < 47; k_val++) {
        code = step(&fixnum_goal, &current_angle, vector, k_val);
        if (code != 0) {
            break;
        }
    }
    if (k_val > 0) {
        vector[0] *= k[k_val - 1];
        vector[1] *= k[k_val - 1];
    }
    double *result = (double *)malloc(2 * sizeof(int));
    result[0] = sgn * vector[0] / 1.e14;
    result[1] = sgn * vector[1] / 1.e14;
    return result;
}

double my_sin(double angle) {
    double *sin_cos = cordic(angle);
    double result = sin_cos[1];
    free(sin_cos);
    return result;
}

double my_cos(double angle) {
    double *sin_cos = cordic(angle);
    double result = sin_cos[0];
    free(sin_cos);
    return result;
}
