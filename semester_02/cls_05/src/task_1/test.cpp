#include "distance.hpp"

#include <vector>
#include <list>
#include <forward_list>
#include <set>
#include <array>
#include <cassert>

int main() {
    using std::begin;
    using std::end;

    {
        std::array<int, 4> a{1, 2, 3, 4};

        assert(cls_05::distance(begin(a), end(a)) == 4);
        assert(cls_05::distance(std::next(begin(a), 4), end(a)) == 0);
        assert(cls_05::distance(end(a), begin(a)) == -4);

        assert(cls_05::distance(std::make_reverse_iterator(end(a)), std::make_reverse_iterator(begin(a))) == 4);
    }

    {
        std::vector<int> a{1, 2, 3, 4};

        assert(cls_05::distance(begin(a), end(a)) == 4);
        assert(cls_05::distance(end(a), begin(a)) == -4);

        assert(cls_05::distance(std::make_reverse_iterator(end(a)), std::make_reverse_iterator(begin(a))) == 4);
    }

    {
        std::list<int> a{1, 2, 3, 4};

        assert(cls_05::distance(begin(a), end(a)) == 4);

        assert(cls_05::distance(std::make_reverse_iterator(end(a)), std::make_reverse_iterator(begin(a))) == 4);
    }

    {
        std::forward_list<int> a{1, 2, 3, 4};

        assert(cls_05::distance(begin(a), end(a)) == 4);
        assert(cls_05::distance(std::next(begin(a), 4), end(a)) == 0);
    }
}