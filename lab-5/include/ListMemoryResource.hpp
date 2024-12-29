#pragma once

#include <memory_resource>
#include <list>
#include <algorithm>
#include <iostream>

class ListMemoryResource : public std::pmr::memory_resource 
{
    private:
        struct Block {
            void* ptr;
            size_t size;
        };

        std::list<Block> allocated_blocks;

        void* do_allocate(size_t bytes, size_t alignment) override;
        void do_deallocate(void* ptr, size_t bytes, size_t alignment) override;
        bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;

    public:
        ListMemoryResource() = default;
        ~ListMemoryResource();
};