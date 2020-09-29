#include "deque.hpp"

#include <memory>
#include <cassert>
#include <variant>
#include <array>
#include <vector>

namespace ns = control_04;

//#define TASK_1
//#define TASK_2
//#define TASK_3

static void test_constructors() {
#ifdef TASK_1
    {
        ns::deque<int> buf{10};

        assert(buf.empty());
        assert(buf.size() == 0);
        assert(buf.capacity() == 10);
    }

    {
        ns::deque<int> buf{0};

        assert(buf.empty());
        assert(buf.size() == 0);
        assert(buf.capacity() == 0);
    }

    // copy ctor
    {
        ns::deque<int> buf{10};

        for (auto a : {1, 2, 3}) {
            buf.emplace_back(a);
        }

        assert(buf.size() == 3);

        ns::deque<int> buf_copy{buf};

        assert(!buf_copy.empty());
        assert(buf_copy.size() == 3);
        assert(buf_copy.capacity() == 10);

        assert(buf_copy[0] == 1);
        assert(buf_copy[1] == 2);
        assert(buf_copy[2] == 3);
    }

    // assignment op
    {
        ns::deque<int> buf{10};

        for (auto a : {1, 2, 3}) {
            buf.emplace_back(a);
        }

        ns::deque<int> buf_copy{0};
        buf_copy = static_cast<decltype(buf) const &>(buf);

        assert(!buf_copy.empty());
        assert(buf_copy.size() == 3);
        assert(buf_copy.capacity() == 10);

        assert(buf_copy[0] == 1);
        assert(buf_copy[1] == 2);
        assert(buf_copy[2] == 3);
    }

    // move ctor
    {
        ns::deque<int> buf{10};

        for (auto a : {1, 2, 3}) {
            buf.emplace_back(a);
        }

        ns::deque<int> buf_copy{std::move(buf)};

        // move leaves buffer unusable, with zero capacity
        assert(buf.empty());
        assert(buf.size() == 0);
        assert(buf.capacity() == 0);

        assert(!buf_copy.empty());
        assert(buf_copy.size() == 3);
        assert(buf_copy.capacity() == 10);

        assert(buf_copy[0] == 1);
        assert(buf_copy[1] == 2);
        assert(buf_copy[2] == 3);
    }

    // move op
    {
        ns::deque<int> buf{10};

        for (auto a : {1, 2, 3}) {
            buf.emplace_back(a);
        }

        ns::deque<int> buf_copy{5};

        buf_copy = std::move(buf);

        // move leaves buffer unusable, with zero capacity
        assert(buf.empty());
        assert(buf.size() == 0);
        assert(buf.capacity() == 0);

        assert(!buf_copy.empty());
        assert(buf_copy.size() == 3);
        assert(buf_copy.capacity() == 10);

        assert(buf_copy[0] == 1);
        assert(buf_copy[1] == 2);
        assert(buf_copy[2] == 3);
    }

    {
        struct Data {
            int i;

            explicit Data(int i) : i(i) {}
        };

        ns::deque<Data> buf{1};

        buf.emplace_back(Data{10});

        assert(buf[0].i == 10);

        buf.emplace_back(Data{20});

        assert(buf[0].i == 20);
    }
#endif
}

static void test_simple_emplace_back() {
#ifdef TASK_1
    {
        ns::deque<int> buf{1};

        assert(buf.empty());
        assert(buf.size() == 0);
        assert(buf.capacity() == 1);

        buf.emplace_back(1);

        assert(!buf.empty());
        assert(buf.size() == 1);
        assert(buf.capacity() == 1);

        assert(buf[0] == 1);

        buf.emplace_back(2);

        assert(!buf.empty());
        assert(buf.size() == 1);
        assert(buf.capacity() == 1);

        assert(buf[0] == 2);
    }

    {
        ns::deque<int> buf{4};

        assert(buf.empty());
        assert(buf.size() == 0);
        assert(buf.capacity() == 4);

        buf.emplace_back(1);
        buf.emplace_back(2);
        buf.emplace_back(3);

        assert(!buf.empty());
        assert(buf.size() == 3);
        assert(buf.capacity() == 4);

        assert(buf[0] == 1);
        assert(buf[1] == 2);
        assert(buf[2] == 3);

        buf.emplace_back(4);
        buf.emplace_back(5);
        buf.emplace_back(6);

        assert(!buf.empty());
        assert(buf.size() == 4);
        assert(buf.capacity() == 4);

        assert(buf[0] == 3);
        assert(buf[1] == 4);
        assert(buf[2] == 5);
        assert(buf[3] == 6);
    }

    {
        ns::deque<std::vector<int>> buf{1};

        buf.emplace_back(size_t(10), 42);

        assert(buf[0] == (std::vector<int>(10, 42)));

        buf.emplace_back(10); // calls vector<int>(10)
        assert(buf[0] == std::vector<int>(10, 0));
    }
#endif
}

static void test_destructors_of_elements() {
#ifdef TASK_1
    {
        ns::deque<std::shared_ptr<int>> buf{1};

        buf.emplace_back(std::make_shared<int>(10));
        assert(buf.size() == 1);

        std::weak_ptr weak_ptr{buf[0]};
        assert(*weak_ptr.lock() == 10);

        buf.emplace_back(std::make_shared<int>(20));

        assert(!weak_ptr.lock());
    }
#endif
}

static void test_pop_back() {
#ifdef TASK_2
    {
        ns::deque<int> buf{3};

        buf.emplace_back(1);
        buf.emplace_back(2);
        buf.emplace_back(3);

        assert(buf.size() == 3);

        assert(buf[0] == 1);
        assert(buf[1] == 2);
        assert(buf[2] == 3);


        buf.pop_back();

        assert(buf.size() == 2);

        assert(buf[0] == 1);
        assert(buf[1] == 2);


        buf.pop_back();

        assert(buf.size() == 1);

        assert(buf[0] == 1);


        buf.pop_back();

        assert(buf.size() == 0);
    }

    {
        ns::deque<int> buf{3};

        buf.emplace_back(1);
        buf.emplace_back(2);
        buf.emplace_back(3);
        buf.emplace_back(4);
        buf.emplace_back(5);

        assert(buf.size() == 3);

        assert(buf[0] == 3);
        assert(buf[1] == 4);
        assert(buf[2] == 5);

        buf.pop_back();

        assert(buf.size() == 2);

        assert(buf[0] == 3);
        assert(buf[1] == 4);


        buf.pop_back();

        assert(buf.size() == 1);

        assert(buf[0] == 3);


        buf.pop_back();

        assert(buf.size() == 0);
    }
#endif
}

[[maybe_unused]]
constexpr auto deque_content_equals = [](auto const &deq, auto const &content) {
    if (deq.size() != content.size()) {
        return false;
    }

    for (size_t i = 0; i < deq.size(); ++i) {
        auto val = deq[i];
        auto expected = content[i];

        if (val != expected) {
            return false;
        }
    }

    return true;
};


static void test_front_and_back_inserts() {
#ifdef TASK_2
    {
        ns::deque<int> d{5}; // capacity == 5

        d.emplace_back(1);
        d.emplace_back(2);
        d.emplace_back(3);

        assert(deque_content_equals(d, std::array{1, 2, 3}));

        d.emplace_front(4);
        d.emplace_front(5);

        assert(deque_content_equals(d, std::array{5, 4, 1, 2, 3}));

        d.emplace_back(6);
        d.emplace_back(7);
        d.emplace_front(8);

        assert(deque_content_equals(d, std::array{8, 1, 2, 3, 6}));
    }

    {
        ns::deque<int> buf{5}; // capacity == 5

        buf.emplace_back(1);
        buf.emplace_back(2);
        buf.emplace_back(3);

        buf.pop_front();
        buf.pop_front();

        assert(deque_content_equals(buf, std::array{3}));

        buf.emplace_front(1);
        buf.emplace_front(2);
        buf.emplace_front(3);

        assert(deque_content_equals(buf, std::array{3, 2, 1, 3}));

        buf.pop_back();
        buf.pop_back();

        assert(deque_content_equals(buf, std::array{3, 2}));
    }
#endif
}

static void test_reverse() {
#ifdef TASK_3
    {
        ns::deque<int> buf{1};

        buf.emplace_back(1);
        assert(buf[0] == 1);

        buf.reverse();
        assert(buf[0] == 1);

        buf.emplace_back(10);
        assert(buf[0] == 10);

        buf.reverse();
        assert(buf[0] == 10);

        buf.emplace_front(30);
        assert(buf[0] == 30);

        buf.reverse();
        assert(buf[0] == 30);
    }

    {
        ns::deque<int> buf{10};

        for (auto i : {1, 2, 3}) {
            buf.emplace_back(i);
        }

        assert(deque_content_equals(buf, std::array{1, 2, 3}));

        buf.reverse();

        assert(deque_content_equals(buf, std::array{3, 2, 1}));
    }
#endif
}

void showcase() {
#ifdef TASK_3
    using deque_type = ns::deque<int>;

    struct PushBack {
        int i;

        void operator()(deque_type &deque) const {
            deque.emplace_back(i);
        }
    };

    struct PopBack {
        void operator()(deque_type &deque) const {
            deque.pop_back();
        }
    };

    struct PushFront {
        int i;

        void operator()(deque_type &deque) const {
            deque.emplace_front(i);
        }
    };

    struct PopFront {
        void operator()(deque_type &deque) const {
            deque.pop_front();
        }
    };

    struct Reverse {
        void operator()(deque_type &deque) const {
            deque.reverse();
        }
    };

    using Op = std::variant<PushBack, PopBack, PushFront, PopFront, Reverse>;

    // This is some random order of operations
    Op operations[]{
            PushBack{10},
            PushBack{20},
            PushBack{30},
            Reverse{},
            PushFront{40},
            PushFront{50},
            Reverse{},
            PopFront{},
            Reverse{},
            PushFront{60},
            PushBack{70},
            Reverse{},
            PopBack{},
            PopFront{},
            PushFront{80},
            PushFront{90},
            PushBack{100},
    };

    deque_type deque {4};

    for (auto op : operations) {
        std::visit([&deque](auto op) { op(deque); }, op);
    }

    assert(deque_content_equals(deque, std::array{80, 30, 40, 100}));
#endif
}

int main() {
    test_constructors();
    test_simple_emplace_back();
    test_destructors_of_elements();

    test_pop_back();
    test_front_and_back_inserts();

    test_reverse();
    showcase();
}