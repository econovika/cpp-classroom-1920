#pragma once

#include <cstddef>
#include <cstdint>

// missing consts
int64_t * const * const create_matrix(size_t height, size_t width);

// missing consts
void release_matrix(int64_t const* const* matrix);