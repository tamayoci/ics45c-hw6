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
}

Picture& Picture::operator=(Picture&& other) {
    if (this != &other) {
        swap(other);
    }
    return *this;
}

void Picture::add(const Shape& shape) {
    ListNode* node = new ListNode{shape.clone(), nullptr};

    if (head == nullptr) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void Picture::print_all(std::ostream& out) const {
    for (ListNode* p = head; p != nullptr; p = p->next) {
        p->shape->print(out);
        p->shape->draw(out);
    }
}

void Picture::draw_all(std::ostream& out) const {
    for (ListNode* p = head; p != nullptr; p = p->next) {
        p->shape->draw(out);
    }
}

double Picture::total_area() const {
    double total = 0;

    for (ListNode* p = head; p != nullptr; p = p->next) {
        total += p->shape->area();
    }

    return total;
}

Picture::~Picture() {
    while (head != nullptr) {
        ListNode* temp = head;

        head = head->next;

        delete temp->shape;
        delete temp;
    }
}