#pragma once

#include <vector>
// write for_each signature yourself, see tests

void for_each(std::vector<int> const &vec, void (*fun)(int));