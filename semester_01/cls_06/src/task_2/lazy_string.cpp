//
// Created by ksenia on 31.10.2020.
//

#include "lazy_string.hpp"


size_t lazy_string::get_size() const {
    return shared_str->get_size();
};

char lazy_string::at(size_t i) const {
    return shared_str->get_data()[i];
};

char * lazy_string::c_str() const {
    return shared_str->get_data();
}

lazy_string concat(lazy_string const& lhs, lazy_string const& rhs) {
    shared_buffer buf = shared_buffer(lhs.get_size() + rhs.get_size() + 1);
    for (size_t i = 0; i < lhs.get_size(); i++) {
        if (lhs.at(i) != '\0')
            buf.get_data()[i] = lhs.at(i);
    }
    for (size_t i = 0; i < rhs.get_size(); i++)
        buf.get_data()[i + lhs.get_size()] = rhs.at(i);
    return lazy_string(buf);
}