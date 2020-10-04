//
// Created by ksenia on 03.10.2020.
//
#include "concat.hpp"

char const* concat(
        char const a[],
        size_t a_size,
        char const b[],
        size_t b_size,
        size_t& concat_size
) {
    char * c = new char[a_size + b_size];
    for (size_t i = 0; i < a_size; i++)
        c[i] = a[i];
    for (size_t i = 0; i < b_size; i++)
        c[i + a_size] = b[i];
    concat_size = (a_size + b_size) * sizeof(c[0]);
    return c;
}