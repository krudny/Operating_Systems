#include <stdio.h>

#ifndef DYNAMIC
    #include "library/library_header.h"
#endif

#ifdef DYNAMIC
    #include "dlfcn.h"
    int (*calc_sum)(int *tab, int n);
    double (*calc_avg)(int *tab, int n);
#endif

int main() {
    int tab[10] = {1,2,3,4,5,6,7,8,9,15};

    #ifdef DYNAMIC
        void* handle = dlopen("library/build/liblibrary_shared.so", RTLD_LAZY);
        if (!handle) {
            fprintf(stderr, "Error: %s\n", dlerror());
            return 1;
        }

        calc_sum = dlsym(handle, "calc_sum");
        calc_avg = dlsym(handle, "calc_avg");
    #endif

    printf("Suma: %d\n", calc_sum(tab, 10));
    printf("Średnia: %f\n", calc_avg(tab, 10));
}