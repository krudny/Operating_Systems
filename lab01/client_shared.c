#include <stdio.h>
#include "collatz_lib/collatz.h"

int main(void) {
    printf("%d\n", test_collatz_convergence(12,50));
}