#pragma once

#include <memory_resource>
#include <iterator>
#include <utility>
#include <cstddef>

template <typename T>
class DynamicArrayIterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

    private:
        T* current;

    public:
        explicit DynamicArrayIterator(T* ptr = nullptr) : current(ptr) {}

        T& operator*() const { return *current; }
        T* operator->() const { return current; }

        DynamicArrayIterator& operator++() {
            ++current;
            return *this;
        }

        DynamicArrayIterator operator++(int) {
            DynamicArrayIterator temp = *this;
            ++current;
            return temp;
        }

        bool operator==(const DynamicArrayIterator& other) const {
            return current == other.current;
        }

        bool operator!=(const DynamicArrayIterator& other) const {
            return current != other.current;
        }
};

template <typename T>
class DynamicArray {
    public:
        using allocator_type = std::pmr::polymorphic_allocator<T>;
        using iterator = DynamicArrayIterator<T>;
        using const_iterator = DynamicArrayIterator<const T>;

    private:
        T* data = nullptr;
        size_t capacity = 0;
        size_t size = 0;
        allocator_type allocator;

        void resize();

    public:
        explicit DynamicArray(const allocator_type& alloc = {});
        ~DynamicArray();

        void push_back(const T& value);
        void push_back(T&& value);

        size_t get_size() const { return size; }
        size_t get_capacity() const { return capacity; }

        T& operator[](size_t index) { return data[index]; }
        const T& operator[](size_t index) const { return data[index]; }

        iterator begin() { return iterator(data); }
        iterator end() { return iterator(data + size); }

        const_iterator begin() const { return const_iterator(data); }
        const_iterator end() const { return const_iterator(data + size); }

        void clear();
};

#include "../src/DynamicArray.cpp"