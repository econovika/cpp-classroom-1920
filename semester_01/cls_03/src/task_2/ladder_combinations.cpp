//
// Created by ksenia on 03.10.2020.
//
#include "ladder_combinations.hpp"
#include <iostream>

uint64_t ladder_combinations(uint8_t steps){
    uint64_t array[21] = {1, 1};
    for (size_t i = 2; i < 21; i++){
        array[i] = array[i - 1] + array[i - 2];
    }
    return array[steps];
}