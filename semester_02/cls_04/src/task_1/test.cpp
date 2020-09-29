#include <string_view>
#include <string>
#include <cassert>
#include <chrono>
#include <iostream>
#include <variant>
#include <cstring>

//#define BENCHMARK

void basic_test() {
    {
        assert(cls_04::strcat().empty());
    }

    {
        // char*

        assert(cls_04::strcat("hello") == "hello");

        assert(cls_04::strcat("hello", ", ", "hello") == "hello, hello");
    }

    {
        assert(cls_04::strcat(1) == "1");
        assert(cls_04::strcat(2l) == "2");
        assert(cls_04::strcat(3u) == "3");
        assert(cls_04::strcat(4lu) == "4");

        // six signs by default
        std::string string = cls_04::strcat(2, 3);
        assert(string == "23");
        assert(cls_04::strcat(2.3) == "2.300000");
    }

    {
        // std::string
        std::string string1 = "hello";
        std::string string2 = "world";

        assert(cls_04::strcat(string1, std::string{", "}, string2) == "hello, world");
    }

    {
        // string_view
        std::string_view view1 = "hello";
        std::string_view view2 = "world";

        assert(cls_04::strcat(view1, std::string_view{", "}, view2) == "hello, world");
    }

    {
        std::string first_name = "Johan";
        std::string_view second_name = std::string_view{"My name is Israel"}.substr(3, 10);
        // all together
        assert(
            cls_04::strcat("First of my ", 29.34, " daughters is named " + first_name, ", second is named ", second_name)

            ==

            "First of my 29.340000 daughters is named Johan, second is named name is Is"
        );
    }
}

void benchmark() {
#ifdef BENCHMARK
    using namespace std::chrono;

    std::string foo = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut "
                      "labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco "
                      "laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in "
                      "voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat "
                      "non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

    std::string bar = foo + "1";
    std::string baz = bar + "2";

    size_t N = 1000000;
    size_t R = 10;

    {
        std::cout << "test #1" << std::endl;
        for (uint32_t i{0}; i < R; ++i) {
            size_t size = 0; // to prevent compiler from optimizing away
            nanoseconds total{0};

            for (size_t a = 0; a < N - 1; ++a) {
                auto const start = high_resolution_clock::now();
                std::string foobar_plus = foo + bar + baz + foo + foo + bar + baz + foo;
                auto const end = high_resolution_clock::now();

                total += end - start;

                size += foobar_plus.size();
            }

            std::cout << total.count() / N << "ns per cin, size is " << size << std::endl;
        }
    }

    {
        std::cout << "test #2" << std::endl;
        for (uint32_t i{0}; i < R; ++i) {
            size_t size = 0; // to prevent compiler from optimizing away
            nanoseconds total{0};

            for (size_t a = 0; a < N - 1; ++a) {
                auto const start = high_resolution_clock::now();
                std::string foobar_plus = cls_04::strcat(foo, bar, baz, foo, foo, bar, baz, foo);
                auto const end = high_resolution_clock::now();

                total += end - start;

                size += foobar_plus.size();
            }

            std::cout << total.count() / N << "ns per cin, size is " << size << std::endl;
        }
    }

#endif
}

int main() {
    basic_test();
    benchmark();

    return 0;
}