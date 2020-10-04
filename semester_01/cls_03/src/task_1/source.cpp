//
// Created by ksenia on 02.10.2020.
//
#include "source.hpp"


long sum(const int *arr, size_t size) {
    long s = 0;
    for (size_t i = 0; i < size; i++) {
        s += arr[i];
    }
    return s;
}

long count_numbers(const int *arr, size_t size) {
    bool occ_arr[10] = {};
    long cnt = 0;
    int e;
    for (size_t i = 0; i < size; i++) {
        e = arr[i];
        if (!occ_arr[e]) {
            cnt += 1;
            occ_arr[e] = true;
        }
    }
    return cnt;
}

const int **sort(const int *arr, size_t size) {
    const int **sorted = new const int*[size];
    if (size == 0)
        return sorted;
    // copy arr to sorted
    for (size_t i = 0; i < size; i++) {
        sorted[i] = &arr[i];
    }
    // do sorting
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = 0; j < size - i - 1; j++)
            if (*sorted[j] > *sorted[j + 1])
                std::swap(sorted[j], sorted[j + 1]);
    return sorted;
}