#pragma once
#include <iostream>

namespace cls_09 {
    template<class T>
    struct node {
        explicit node(const T& val) {
            item = val;
        }

    public:
        node* next = nullptr;
        T item;
    };

    template<class T>
    struct queue {
        ~queue() {
            while (head != tail) {
                node<T>* next_node = (*head).next;
                delete head;
                head = next_node;
            }
        }

        void push(const T& val) {
            node<T>* new_node = new node(val);
            if (head == nullptr)
                head = new_node;
            else
                (*tail).next = new_node;
            tail = new_node;
            queue_size += 1;
        }

        void pop() {
            node<T>* next_node = (*head).next;
            delete head;
            head = next_node;
            queue_size -= 1;
        }

        const T& front() const {
            return (*head).item;
        }

        [[nodiscard]] size_t size() const {
            return queue_size;
        }

    private:
        node<T>* head = nullptr;
        node<T>* tail = nullptr;
        size_t queue_size = 0;
    };
}
