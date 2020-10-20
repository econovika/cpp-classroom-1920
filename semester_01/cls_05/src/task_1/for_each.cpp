//
// Created by ksenia on 18.10.2020.
//
#include "for_each.hpp"

void for_each(std::vector<int> const &vec, void (*fun)(int)) {
    for (int const &elem: vec)
        fun(elem);
}