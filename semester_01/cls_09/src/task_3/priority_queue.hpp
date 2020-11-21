#pragma once
#include <vector>


namespace cls_09 {
    template<class T>
    struct priority_queue {
        void sift_up(size_t idx) {
            while (items[idx] > items[(idx - 1) / 2]) {
                if (idx == 0)
                    break;
                T tmp = items[idx];
                items[idx] = items[(idx - 1) / 2];
                items[(idx - 1) / 2] = tmp;
                idx = (idx - 1) / 2;
            }
        }

        void sift_down(size_t idx) {
            while (2 * idx + 1 < priority_queue_size) {
                size_t left = 2 * idx + 1;
                size_t right = 2 * idx + 2;
                size_t i = left;
                if (right < priority_queue_size && items[right] > items[left])
                    i = right;
                if (items[idx] >= items[i])
                    break;
                T tmp = items[idx];
                items[idx] = items[i];
                items[i] = tmp;
                idx = i;
            }
        }

        [[nodiscard]] size_t size() const {
            return priority_queue_size;
        }

        void pop() {
            items[0] = items[priority_queue_size - 1];
            items.pop_back();
            priority_queue_size -= 1;
            sift_down(0);
        }

        void push(const T& key) {
            priority_queue_size += 1;
            items.push_back(key);
            sift_up(priority_queue_size - 1);
        }

        const T& front() {
            return items[0];
        }

    private:
        size_t priority_queue_size = 0;
        std::vector<T> items;
    };
}