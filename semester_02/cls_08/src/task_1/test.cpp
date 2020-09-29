#include "serialization_concepts.hpp"

#include <string>
#include <vector>

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

    mypod_t mypod{1, 2, 0};
    cls_08::serialize(os, mypod);

    mypod_t mypod2{};
    cls_08::deserialize(is, mypod2);

    assert((mypod.a == mypod2.a)
           && (mypod.b == mypod2.b)
           && (mypod.bit == mypod2.bit));
}

static void test_collection_serialization() {
    {
        std::stringstream ss;

        std::vector<int> const source{1, 2, 3};
        cls_08::serialize(ss, source);

        std::vector<int> not_empty{3, 4, 5};
        cls_08::deserialize(ss, not_empty);

        assert(source == not_empty);
    }

    {
        std::stringstream ss;

        std::vector<std::string> const source{"a", "b", "3"};
        cls_08::serialize(ss, source);

        std::vector<std::string> not_empty{"other"};
        cls_08::deserialize(ss, not_empty);

        assert(source == not_empty);
    }

}

void test_custom_serialization() {
    struct custom {
        std::string s;

        void serialize(std::ostream& o) const {
            cls_08::serialize(o, s);
        };

        void deserialize(std::istream& i) {
            cls_08::deserialize(i, s);
        };
    };

    std::stringstream ss;

    custom const from{"hello"};
    custom to{"something"};

    cls_08::serialize(ss, from);

    cls_08::deserialize(ss, to);

    assert(from.s == to.s);
}

int main() {
    test_pod_serialization();
    test_collection_serialization();
    test_custom_serialization();

    return 0;
}