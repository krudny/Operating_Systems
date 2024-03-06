#include "collatz.h"

int collatz_conjecture(int input) {
    if (input % 2 == 0) {
        return input / 2;
    } else {
        return 3 * input + 1;
    }
}

int test_collatz_convergence(int input, int max_iter) {
    int cnt = 1;
    int result = collatz_conjecture(input);

    while (result != 1 && cnt <= max_iter) {
        result = collatz_conjecture(result);
        cnt += 1;
    }

    return (cnt <= max_iter) ? cnt : -1;
}