#include <iostream>
#include "fizzbuzz.hpp"

void print(uint64_t i) {
    if (i == 0)
        std::cout << "" << std::endl;
    else if (i % 5 == 0 && i % 3 == 0)
        std::cout << "FizzBuzz" << std::endl;
    else if (i % 5 == 0)
        std::cout << "Buzz" << std::endl;
    else if (i % 3 == 0)
        std::cout << "Fizz" << std::endl;
    else
        std::cout << i << std::endl;
}

void fizzbuzz(uint64_t n) {
    for (uint64_t i = 1; i < n; i++)
        print(i);
    print(n);
}