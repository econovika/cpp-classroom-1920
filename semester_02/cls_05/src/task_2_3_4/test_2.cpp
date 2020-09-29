#include "serialization.hpp"

#include <string>
#include <list>

#include <sstream>
#include <cassert>

static void test_pod_serialization() {
    std::stringstream stream;
    std::ostream& os = stream;
    std::istream& is = stream;

    struct mypod_t {
        size_t a;
        size_t b;
        unsigned bit:1;
    };

    mypod_t mypod = {1, 2, 0};
    cls_05::serialize(os, mypod);

    mypod_t mypod2{};
    cls_05::deserialize(is, mypod2);

    assert((mypod.a == mypod2.a)
           && (mypod.b == mypod2.b)
           && (mypod.bit == mypod2.bit));
}

int main() {
    test_pod_serialization();

    return 0;
}