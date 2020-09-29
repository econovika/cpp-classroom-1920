#include "serialization.hpp"

#include <vector>
#include <string>
#include <list>

#include <sstream>
#include <cassert>

template<class Container>
bool eq_container(Container const& lhs, Container const& rhs) {
    if (lhs.size() != rhs.size())
        return false;

    for (auto it = lhs.begin(), jt = rhs.begin(); it != lhs.end(); ++it, ++jt)
        if (!(*it == *jt))
            return false;

    return true;
}

static void test_pod_vector_serialize() {

    std::stringstream stream;
    std::ostream& os = stream;
    std::istream& is = stream;

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    cls_05::serialize(os, v);

    std::vector<int> v2;
    cls_05::deserialize(is, v2);

    assert(eq_container(v, v2));
}

static void test_nonpod_vector_serialize() {
    std::stringstream stream;
    std::ostream& os = stream;
    std::istream& is = stream;

    std::vector<std::string> v;
    v.emplace_back("1");
    v.emplace_back("2");
    v.emplace_back("3");
    v.emplace_back("4");
    cls_05::serialize(os, v);

    std::vector<std::string> v2;
    cls_05::deserialize(is, v2);

    assert(eq_container(v, v2));
}

int main() {
    test_pod_vector_serialize();
    test_nonpod_vector_serialize();

    return 0;
}