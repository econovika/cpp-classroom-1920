//
// Created by ksenia on 31.10.2020.
//

#pragma once

#include <vector>
#include "../task_1/shared_buffer.hpp"


struct lazy_string {
    // Constructor default
    lazy_string() {
        shared_str = new shared_buffer(nullptr);
    };

    // Constructor 1
    lazy_string(char const* string) {
        shared_str = new shared_buffer(string);
    };

    // Constructor 2
    lazy_string(const shared_buffer& buf) {
        *shared_str = buf;
    };

    // Copy constructor
    lazy_string(lazy_string const& other)= default;

    lazy_string& operator=(const lazy_string& other) {
        if (this != &other)
            shared_str = other.shared_str;
        return *this;
    };

    [[nodiscard]] size_t get_size() const;

    [[nodiscard]] char at(size_t i) const;

    [[nodiscard]] char * c_str() const;

    friend lazy_string concat(lazy_string const& lhs, lazy_string const& rhs);

private:
    shared_buffer* shared_str;
};
