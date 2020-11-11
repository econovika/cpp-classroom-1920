//
// Created by ksenia on 11.11.2020.
//

#pragma once

#include <fstream>
#include "../task_1/my_ostream.hpp"


namespace cls_08 {
    struct my_ostream_file : public my_ostream {
    private:
        std::ofstream fout;

    public:
        // Конструктор
        explicit my_ostream_file(const std::string& name) :
                fout(name) {}

        my_ostream_file(const my_ostream_file&) = delete;
        my_ostream_file& operator=(const my_ostream_file &) = delete;

        my_ostream_file &operator<<(const int& val) override {
            fout << val;
            return *this;
        }

        my_ostream_file &operator<<(const double& val) override {
            fout << val;
            return *this;
        }

        my_ostream_file &operator<<(const std::string& val) override {
            fout << val;
            return *this;
        }
    };
}