#include "DynamicArray.hpp"
#include <new>

template <typename T>
void DynamicArray<T>::resize() {
    size_t new_capacity = capacity == 0 ? 1 : capacity * 2;
    T* new_data = allocator.allocate(new_capacity);

    for (size_t i = 0; i < size; ++i) {
        new (new_data + i) T(std::move(data[i]));
        data[i].~T();
    }

    allocator.deallocate(data, capacity);
    data = new_data;
    capacity = new_capacity;
}

template <typename T>
DynamicArray<T>::DynamicArray(const allocator_type& alloc) : allocator(alloc) {}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    clear();
    allocator.deallocate(data, capacity);
}

template <typename T>
void DynamicArray<T>::push_back(const T& value) {
    if (size == capacity) {
        resize();
    }
    new (data + size) T(value);
    ++size;
}

template <typename T>
void DynamicArray<T>::push_back(T&& value) {
    if (size == capacity) {
        resize();
    }
    new (data + size) T(std::move(value));
    ++size;
}

template <typename T>
void DynamicArray<T>::clear() {
    for (size_t i = 0; i < size; ++i) {
        data[i].~T();
    }
    size = 0;
}