#ifndef CUSTOM_LIST_H
#define CUSTOM_LIST_H

#include <memory_resource>
#include <iterator>

template <typename T>
class CustomList {
public:
    struct Node {
        T value;
        Node* prev;
        Node* next;
    };

    explicit CustomList(std::pmr::memory_resource* resource = std::pmr::get_default_resource())
        : allocator_(resource) {}

    void push_back(const T& value) {
        Node* newNode = allocator_.allocate(1);
        new (newNode) Node{value, tail_, nullptr};
        if (tail_) tail_->next = newNode;
        else head_ = newNode;
        tail_ = newNode;
    }

    struct Iterator {
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        explicit Iterator(Node* node) : node_(node) {}
        reference operator*() const { return node_->value; }
        pointer operator->() { return &(node_->value); }
        Iterator& operator++() {
            node_ = node_->next;
            return *this;
        }
        bool operator==(const Iterator& other) const { return node_ == other.node_; }
        bool operator!=(const Iterator& other) const { return node_ != other.node_; }

    private:
        Node* node_;
    };

    Iterator begin() { return Iterator(head_); }
    Iterator end() { return Iterator(nullptr); }

private:
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    std::pmr::polymorphic_allocator<Node> allocator_;
};

#endif // CUSTOM_LIST_H
