//
// Created by ksenia on 31.10.2020.
//

#include "lazy_string.hpp"


size_t cls_07::lazy_string::get_size() const {
    return shared_str->get_size();
};

char cls_07::lazy_string::at(size_t i) const {
    return shared_str->get_data()[i];
};

char * cls_07::lazy_string::c_str() const {
    return shared_str->get_data();
};

cls_07::lazy_string cls_07::concat(cls_07::lazy_string const& lhs, cls_07::lazy_string const& rhs) {
    shared_buffer buf = shared_buffer(lhs.get_size() + rhs.get_size() + 1);
    for (size_t i = 0; i < lhs.get_size(); i++) {
        if (lhs.at(i) != '\0')
            buf.get_data()[i] = lhs.at(i);
    }
    for (size_t i = 0; i < rhs.get_size(); i++)
        buf.get_data()[i + lhs.get_size()] = rhs.at(i);
    return cls_07::lazy_string(buf);
};

size_t find(cls_07::lazy_string const &s, const char *what, size_t start_ix) {
    char *ptr = std::strstr(s.shared_str->get_data() + start_ix, what);
    size_t size = s.shared_str->get_size();
    if (size - start_ix > size || ptr == nullptr)
        return cls_07::lazy_string::npos;
    return ptr - s.shared_str->get_data();
};
