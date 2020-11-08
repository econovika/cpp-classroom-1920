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
    char *ptr = std::strstr(s.c_str() + start_ix, what);
    size_t size = s.get_size();
    if (size - start_ix > size || ptr == nullptr)
        return cls_07::lazy_string::npos;
    return ptr - s.c_str();
};

bool operator<(const cls_07::lazy_string &lhs, const cls_07::lazy_string &rhs) {
    size_t match = 0;
    size_t j = 0;
    for (size_t i = 0; i < lhs.get_size(); i++) {
        if (j >= rhs.get_size())
            break;
        if (lhs.at(i) > rhs.at(j))
            return false;
        if (lhs.at(i) == rhs.at(j))
            match++;
        j++;
    }
    if ((match == rhs.get_size() && match == lhs.get_size()) || !rhs.get_size())
        return false;
    return true;
};

cls_07::lazy_string operator+(cls_07::lazy_string const &lhs, cls_07::lazy_string const &rhs) {
    char *content = new char[lhs.get_size() + rhs.get_size() + 1];
    for (size_t i = 0; i < lhs.get_size(); i++)
        content[i] = lhs.at(i);
    for (size_t i = 0; i < rhs.get_size(); i++)
        content[i + lhs.get_size()] = rhs.at(i);
    content[rhs.get_size() + lhs.get_size()] = '\0';
    cls_07::lazy_string ls = content;
    delete [] content;
    return ls;
}

void operator+=(cls_07::lazy_string &lhs, cls_07::lazy_string const &rhs) {
    lhs = lhs + rhs;
}

std::ostream &operator<<(std::ostream &os, cls_07::lazy_string const &ls) {
    for (size_t i = 0; i < ls.get_size(); i++)
        os << ls.at(i);
    return os;
};
