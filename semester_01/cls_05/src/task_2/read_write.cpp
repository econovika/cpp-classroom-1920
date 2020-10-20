//
// Created by ksenia on 18.10.2020.
//
#include "read_write.hpp"


char* write(char* const data, int in) {
    *(reinterpret_cast<int*>(data)) = in;
    return data + sizeof(in);
}

const char* read(const char* data, int& out) {
    out = *reinterpret_cast<int*>(const_cast<char*>(data));
    return data + sizeof(out);
}

char* write(char* data, size_t in) {
    *(reinterpret_cast<size_t*>(data)) = in;
    return data + sizeof(in);
}

const char* read(const char* data, size_t& out) {
    out = *reinterpret_cast<size_t*>(const_cast<char*>(data));
    return data + sizeof(out);
}

const char* read(const char* data, char*& out) {
    size_t size = 0;
    while (*data != '\0') {
        size += 1; data += 1;
    }
    out = new char[size + 1];
    for (size_t i = 0; i <= size + 1; i++)
        out[i] = data[i - size];
    return data + 1;
}

char* write(char* data, char const* in) {
    while ((*data++ = *in++));
    return data;
}

const char* read(const char* input, std::vector<int>& vec) {
    while (*input != '\0') {
        vec.push_back(*(reinterpret_cast<int *>(const_cast<char *>(input))));
        input += sizeof(vec.begin());
    }
    return input;
}

char* write(char* input, const std::vector<int>& vec) {
    for (int const & elem: vec) {
        *(reinterpret_cast<int*>(input)) = elem;
        input += sizeof(vec.begin());
    }
    return input;
}
