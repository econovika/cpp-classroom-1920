//
// Created by ksenia on 04.10.2020.
//
#include <cassert>
#include "matrices.hpp"

int64_t * const * const create_matrix(size_t height, size_t width) {
    assert(height > 0 && width > 0);
    int64_t **matrix = new int64_t *[height];
    matrix[0] = new int64_t[height * width];
    for (size_t i = 0; i < width; i++)
        matrix[i + 1] = matrix[i] + width;
    return matrix;
}

void release_matrix(int64_t const* const* matrix) {
    delete [] matrix[0];
    delete [] matrix;
};