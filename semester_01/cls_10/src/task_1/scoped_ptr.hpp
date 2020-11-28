#pragma once

namespace cls_10 {
    template <class T>
    struct scoped_ptr {
        T *object;

        scoped_ptr & operator=(scoped_ptr const &) = delete;

        scoped_ptr(scoped_ptr const &) = delete;

        explicit scoped_ptr(T *obj = nullptr) : object(obj) {};

        explicit operator bool() const noexcept {
            return object != nullptr;
        };

        T* release() {
            T* tmp = object;
            object = nullptr;
            return tmp;
        }

        typedef T element_type;

        ~scoped_ptr() {
            delete object;
        }

        T* operator->() const {
            return object;
        }

        T& operator* () const {
            return *object;
        }

        void reset(T *obj = nullptr) {
            delete object;
            object = obj;
        }

        T* get() const {
            return object;
        }
    };
}