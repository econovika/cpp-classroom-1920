//
// Created by ksenia on 24.10.2020.
//


#include "shared_buffer.hpp"

size_t shared_buffer::get_size() const {
    return size_;
};

char* shared_buffer::get_data() const {
    return data_;
};
