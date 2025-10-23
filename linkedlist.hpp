#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "item.hpp"
#include <string>

class LinkedList {
private:
    struct Node {
        Item data;
        Node* next;
        Node(const Item& item) : data(item), next(nullptr) {}
    };
    Node* head;
    int count;

public:
    LinkedList() : head(nullptr), count(0) {}
    ~LinkedList() { clear(); }

    void add(const Item& item) {
        if (contains(item)) return; // prevent duplicates for FlexibleOrder
        Node* newNode = new Node(item);
        newNode->next = head;
        head = newNode;
        count++;
    }

    void remove(const std::string& name) {
        Node* curr = head;
        Node* prev = nullptr;
        while (curr) {
            if (curr->data.getItemName() == name) {
                if (prev) prev->next = curr->next;
                else head = curr->next;
                delete curr;
                count--;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    bool contains(const Item& item) const {
        Node* curr = head;
        while (curr) {
            if (curr->data.getItemName() == item.getItemName())
                return true;
            curr = curr->next;
        }
        return false;
    }

    int size() const { return count; }

    void clear() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        head = nullptr;
        count = 0;
    }
};

#endif
