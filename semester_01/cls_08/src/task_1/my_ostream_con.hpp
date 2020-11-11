#include "my_ostream.hpp"


namespace cls_08 {
    struct my_ostream_con : public my_ostream {
        my_ostream &operator<<(const int &val) override {
            std::cout << val;
            return *this;
        }

        my_ostream &operator<<(const std::string &val) override {
            std::cout << val;
            return *this;
        }

        my_ostream &operator<<(const double &val) override {
            std::cout << val;
            return *this;
        }
    };
}