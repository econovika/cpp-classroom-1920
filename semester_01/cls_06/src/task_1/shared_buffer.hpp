#pragma once
#include <iostream>
#include <cstring>


struct shared_buffer {
    // task_2
    shared_buffer(char const* string)
    {
        counter_ = new size_t(1);
        if (string != nullptr) {
            size_ = std::strlen(string);
            data_ = new char[size_]();
            data_ = std::strcpy(data_, string);
        }
        else {
            size_ = 0;
            data_ = new char[1]();
        }
    }

    // Constructor
    shared_buffer(size_t size)
            : data_(new char[size]())
            , size_(size_t(size - 1))
            , counter_(new size_t(1))
    {}

    // Destructor
    ~shared_buffer() {
        if (--(*counter_) == 0) {
            delete[] data_;
            delete counter_;
        }
    }

    // Copy constructor
    shared_buffer(shared_buffer const& other)
            : data_(other.data_)
            , size_(other.size_)
            , counter_(other.counter_)
    {
        *counter_ += 1;
    }

    // Operator =
    shared_buffer& operator=(shared_buffer other) {
        this->~shared_buffer();

        data_ = new char[other.size_]();
        size_ = other.size_;
        counter_ = new size_t(1);

        std::swap(data_, other.data_);
        std::swap(size_, other.size_);
        std::swap(counter_, other.counter_);
        return *this;
    }

    [[nodiscard]] size_t get_size() const;

    [[nodiscard]] char* get_data() const;

public:
    char* data_;
    size_t size_;
    size_t* counter_;
};