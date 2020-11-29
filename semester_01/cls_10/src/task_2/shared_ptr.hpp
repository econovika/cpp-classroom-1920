#pragma once

#include <iostream>


namespace cls_10 {
    struct counter {
        counter() : cnt(1) {}

        size_t get() const {
            return cnt;
        }

        // Prefix operator
        counter &operator++() {
            cnt++;
            return *this;
        }

        // Postfix operator
        counter operator++(int) {
            counter tmp = *this;
            ++(*this).cnt;
            return tmp;
        }

        // Prefix operator
        counter &operator--() {
            cnt--;
            return *this;
        }

        // Postfix operator
        counter operator--(int) {
            counter tmp = (*this);
            --(*this).cnt;
            return tmp;
        }

    private:
        size_t cnt;
    };


    template<class T>
    struct shared_ptr {
        typedef T element_type;

        shared_ptr& operator=(shared_ptr const & other) {
            if (this != &other) {
                ptr = other.ptr;
                cnt = other.cnt;
                (*cnt)++;
            }
            return *this;
        };

        shared_ptr(shared_ptr const & other) {
            ptr = other.ptr;
            cnt = other.cnt;
            (*cnt)++;
        };

        explicit shared_ptr(T *other = nullptr) {
            ptr = other;
            cnt = new counter();
        };

        ~shared_ptr() {
            if (cnt->get() == 0) {
                delete cnt;
                delete ptr;
            }
        }

        explicit operator bool() const noexcept {
            return ptr != nullptr;
        };

        T const* get() const {
            return ptr;
        }

        T const* operator->() const {
            return ptr;
        }

        T const& operator* () const {
            return *ptr;
        }

        void reset(T *obj = nullptr) {
            (*cnt)--;
            ptr = obj;
            cnt = new counter();
        }

    public:
        T *ptr;
        counter *cnt;
    };
}
