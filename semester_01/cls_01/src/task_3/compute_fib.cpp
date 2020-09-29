#include <fstream>
#include "compute_fib.hpp"

std::pair<int64_t, int64_t> next_fib(int64_t f1, int64_t f2) {
    int64_t tmp;
    tmp = f1 + f2;
    f1 = f2;
    f2 = tmp;
    return std::make_pair(f1, f2);
}

int64_t compute_fib() {
    std::ifstream file;
    file.open("input.txt");
    uint16_t n;
    file >> n;

    std::pair<int64_t, int64_t> pair;
    int64_t f1 = 0, f2 = 1;
    if (n == 0)
        return f1;
    for (uint16_t i = 2; i < n; i++) {
        pair = next_fib(f1, f2);
        f1 = pair.first;
        f2 = pair.second;
    }
    pair = next_fib(f1, f2);
    f2 = pair.second;
    return f2;
};