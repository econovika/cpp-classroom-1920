//
// Created by ksenia on 11.11.2020.
//

#pragma once

#include <iostream>

namespace cls_08 {
    struct my_ostream {
        virtual ~my_ostream(){};

        virtual my_ostream &operator<<(const int &val) = 0;

        virtual my_ostream &operator<<(const std::string &val) = 0;

        virtual my_ostream &operator<<(const double &val) = 0;
    };
}