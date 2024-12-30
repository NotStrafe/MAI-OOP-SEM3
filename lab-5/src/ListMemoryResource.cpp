#include "ListMemoryResource.hpp"

void* ListMemoryResource::do_allocate(size_t bytes, size_t alignment) {
    void* ptr = ::operator new(bytes, std::align_val_t(alignment));
    allocated_blocks.push_back({ptr, bytes});
    return ptr;
}

void ListMemoryResource::do_deallocate(void* ptr, size_t bytes, size_t alignment) {
    auto it = std::find_if(allocated_blocks.begin(), allocated_blocks.end(), [ptr](const Block& block) { return block.ptr == ptr; });
    if (it != allocated_blocks.end()) {
        ::operator delete(ptr, std::align_val_t(alignment));
        allocated_blocks.erase(it);
    }
}

bool ListMemoryResource::do_is_equal(const std::pmr::memory_resource& other) const noexcept {
    return this == &other;
}

ListMemoryResource::~ListMemoryResource() {
    for (auto& block : allocated_blocks) {
        ::operator delete(block.ptr, std::align_val_t(alignof(std::max_align_t)));
    }
    allocated_blocks.clear();
}