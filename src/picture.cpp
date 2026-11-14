#include "picture.hpp"
#include <iostream>
#include <utility>

using namespace std;

Picture::Picture()
    : head(nullptr), tail(nullptr) {
}

Picture::Picture(const Picture& other)
    : head(nullptr), tail(nullptr) {

    for (ListNode* p = other.head; p != nullptr; p = p->next) {
        add(*p->shape);
    }
}

Picture::Picture(Picture&& other)
    : head(other.head), tail(other.tail) {

    other.head = nullptr;
    other.tail = nullptr;
}

void Picture::swap(Picture& other) {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
}

Picture& Picture::operator=(const Picture& other) {
    if (this != &other) {
        Picture temp(other);
        swap(temp);
    }
    return *this;

