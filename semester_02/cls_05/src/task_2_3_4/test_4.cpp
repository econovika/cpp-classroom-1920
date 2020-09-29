#include "serialization.hpp"

#include <vector>
#include <string>
#include <map>
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

static void test_nonpod_map_serialize() {
    std::stringstream stream;
    std::ostream& os = stream;
    std::istream& is = stream;

    std::map<std::string, int> v;
    v["1"] = 1;
    v["2"] = 2;
    v["3"] = 3;
    v["4"] = 4;

    cls_05::serialize(os, v);

    std::map<std::string, int> v2;
    cls_05::deserialize(is, v2);

    assert(eq_container(v, v2));
}

struct custom_record {
    custom_record()
        : number(0) {}

    custom_record(std::string const& t, int n)
        : text(t), number(n), texts(n, t) {}

    friend void serialize(std::ostream& s, custom_record const& r);

    friend void deserialize(std::istream& s, custom_record& r);

    friend bool operator==(custom_record const& lhs,
                           custom_record const& rhs);

private:
    std::string text;
    int number;
    std::vector<std::string> texts;
};

void serialize(std::ostream& s, custom_record const& r) {
    cls_05::serialize(s, r.text);
    cls_05::serialize(s, r.number);
    cls_05::serialize(s, r.texts);
}

void deserialize(std::istream& s, custom_record& r) {
    cls_05::deserialize(s, r.text);
    cls_05::deserialize(s, r.number);
    cls_05::deserialize(s, r.texts);
}

bool operator==(custom_record const& lhs, custom_record const& rhs) {
    return lhs.text == rhs.text
           && lhs.number == rhs.number
           && eq_container(lhs.texts, rhs.texts);
}

static void test_custom_struct_serialize() {
    std::stringstream stream;
    std::ostream& os = stream;
    std::istream& is = stream;

    std::list<custom_record> v;
    v.emplace_back("1", 1);
    v.emplace_back("2", 2);
    v.emplace_back("3", 3);
    v.emplace_back("4", 4);
    cls_05::serialize(os, v);

    std::list<custom_record> v2;
    cls_05::deserialize(is, v2);

    assert(eq_container(v, v2));
}

int main() {
    test_nonpod_map_serialize();
    test_custom_struct_serialize();


    return 0;
}