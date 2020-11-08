//
// Created by ksenia on 31.10.2020.
//

#pragma once

#include <vector>
#include "../task_1/shared_buffer.hpp"
#include <limits>


namespace cls_07 {
    struct lazy_string {
        static const size_t npos = std::numeric_limits<size_t>::max();

        // Constructor default
        lazy_string() {
            shared_str = new shared_buffer(nullptr);
        };

        // Constructor 1
        lazy_string(char const *string) {
            shared_str = new shared_buffer(string);
        };

        // Constructor 2
        lazy_string(const shared_buffer &buf) {
            *shared_str = buf;
        };

        // Copy constructor
        lazy_string(lazy_string const &other) = default;

        lazy_string &operator=(const lazy_string &other) {
            if (this != &other)
                shared_str = other.shared_str;
            return *this;
        };

        char operator[](size_t idx) const {
            return this->at(idx);
        }

        [[nodiscard]] size_t get_size() const;

        [[nodiscard]] char at(size_t i) const;

        [[nodiscard]] char *c_str() const;

        friend lazy_string concat(lazy_string const &lhs, lazy_string const &rhs);

    public:
        shared_buffer *shared_str;
    };
}

size_t find(cls_07::lazy_string const &s, const char *what, size_t start_ix = 0);

bool operator<(const cls_07::lazy_string &lhs, const cls_07::lazy_string &rhs);

std::ostream &operator<<(std::ostream &os, cls_07::lazy_string const &ls);

cls_07::lazy_string operator+(cls_07::lazy_string const &lhs, cls_07::lazy_string const &rhs);

void operator+=(cls_07::lazy_string &lhs, cls_07::lazy_string const &rhs);
