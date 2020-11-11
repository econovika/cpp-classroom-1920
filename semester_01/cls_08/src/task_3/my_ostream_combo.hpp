//
// Created by ksenia on 11.11.2020.
//

#pragma once

#include "../task_1/my_ostream.hpp"

namespace cls_08 {
    struct my_ostream_combo : public my_ostream {
    private:
        my_ostream* stream1;
        my_ostream* stream2;
    public:
        // Конструктор
        my_ostream_combo(my_ostream* fst, my_ostream* snd):
                stream1(fst), stream2(snd)
        {}
        // Деструктор
        ~my_ostream_combo() override {
            delete stream1;
            delete stream2;
        }
        my_ostream_combo &operator<<(const int& val) override{
            *stream1 << val;
            *stream2 << val;
            return *this;
        };

        my_ostream_combo &operator<<(const double& val) override{
            *stream1 << val;
            *stream2 << val;
            return *this;
        };

        my_ostream_combo &operator<<(const std::string& val) override{
            *stream1 << val;
            *stream2 << val;
            return *this;
        };
    };
}
