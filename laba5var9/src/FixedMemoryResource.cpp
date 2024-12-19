#include "../include/FixedMemoryResource.h"
#include <cassert>
#include <cstdlib>

FixedMemoryResource::FixedMemoryResource(size_t blockSize)
    : blockSize_(blockSize), buffer_(blockSize) {}

FixedMemoryResource::~FixedMemoryResource() {
    for (auto& [ptr, size] : allocations_) {
        std::free(ptr);
    }
}

void* FixedMemoryResource::do_allocate(size_t bytes, size_t alignment) {
    if (bytes > blockSize_) {
        throw std::bad_alloc();
    }
    void* ptr = std::aligned_alloc(alignment, bytes);
    if (!ptr) throw std::bad_alloc();
    allocations_[ptr] = bytes;
    return ptr;
}

void FixedMemoryResource::do_deallocate(void* p, size_t, size_t) {
    auto it = allocations_.find(p);
    if (it != allocations_.end()) {
        std::free(p);
        allocations_.erase(it);
    }
}

bool FixedMemoryResource::do_is_equal(const std::pmr::memory_resource& other) const noexcept {
    return this == &other;
}
