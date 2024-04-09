#include "library_header.h"

int calc_sum(int *tab, int n) {
    int res = 0;

    for(int i = 0; i < n; i++) {
        res += tab[i];
    }

    return res;
}

double calc_avg(int *tab, int n) {
    double res = 0;

    for(int i = 0; i < n; i++) {
        res += tab[i];
    }

    return res/n;
}