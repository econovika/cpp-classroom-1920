//
// Created by ksenia on 29.09.2020.
//
#include <iostream>

int add(int a, int b);
int multiply(int a, int b);

int main() {
    std::cout << multiply(add(1, 2), 4) << std::endl;
}