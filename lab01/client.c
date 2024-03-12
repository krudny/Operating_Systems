#include <stdio.h>

#ifndef DYNAMIC_DLOPEN
#include "collatzlib/collatz.h"
#endif

#ifdef DYNAMIC_DLOPEN
#include "dlfcn.h"

    int (*collatz_conjecture)(int input);
    int (*test_collatz_convergence)(int input, int max_iter);
#endif

int main() {
    #ifdef DYNAMIC_DLOPEN
        void* dll_handle = dlopen("collatzlib/build/libcollatz_shared.so", RTLD_LAZY);
        if (!dll_handle) {
            printf("Nie udało sie otworzyć biblioteki");
            return 1;
        }
    
        collatz_conjecture = dlsym(dll_handle, "collatz_conjecture");
        test_collatz_convergence = dlsym(dll_handle, "test_collatz_convergence");
    #endif

    printf("%d\n", collatz_conjecture(10));
    printf("%d\n", test_collatz_convergence(10, 100));
}