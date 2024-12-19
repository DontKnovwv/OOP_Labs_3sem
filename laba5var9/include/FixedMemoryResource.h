#ifndef FIXED_MEMORY_RESOURCE_H
#define FIXED_MEMORY_RESOURCE_H

#include <memory_resource>
#include <map>
#include <vector>

class FixedMemoryResource : public std::pmr::memory_resource {
public:
    explicit FixedMemoryResource(size_t blockSize);
    ~FixedMemoryResource();

protected:
    void* do_allocate(size_t bytes, size_t alignment) override;
    void do_deallocate(void* p, size_t bytes, size_t alignment) override;
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;

private:
    size_t blockSize_;
    std::vector<char> buffer_;
    std::map<void*, size_t> allocations_;
};

#endif // FIXED_MEMORY_RESOURCE_H
