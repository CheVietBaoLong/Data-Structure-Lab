#ifndef ORDERSHEWROTE_ORDER_HPP
#define ORDERSHEWROTE_ORDER_HPP

#include <iostream>
#include <ordershewrote/item.hpp>

class Order {
public:
    virtual int size() const = 0;

    virtual ~Order() = default;
};

class Bogo : public Order {
private:
    Item paidItem;
    Item freeItem;

public:
    Bogo(const Item& paid, const Item& free) : paidItem(paid), freeItem(free) {}

    int size() const override {
        return 2;
    }
};

class FlexibleOrder : public Order {
private:
    Item* items;     // dynamically allocated array
    int capacity;    // max capacity
    int count;       // current number of items

    void resize() {
        int newCapacity = capacity * 2;
        Item* newArr = new Item[newCapacity];
        for (int i = 0; i < count; ++i)
            newArr[i] = items[i];
        delete[] items;
        items = newArr;
        capacity = newCapacity;
    }

public:
    FlexibleOrder(int initialCapacity = 5)
        : capacity(initialCapacity), count(0) {
        items = new Item[capacity];
    }

    // Copy constructor
    FlexibleOrder(const FlexibleOrder& other)
        : capacity(other.capacity), count(other.count) {
        items = new Item[capacity];
        for (int i = 0; i < count; ++i)
            items[i] = other.items[i];
    }

    // Destructor
    ~FlexibleOrder() {
        delete[] items;
    }

    // Add item if not already present
    void add(const Item& newItem) {
        for (int i = 0; i < count; ++i)
            if (items[i] == newItem)
                return; // already exists
        if (count == capacity)
            resize();
        items[count++] = newItem;
    }

    // Remove item if present
    void remove(const Item& target) {
        for (int i = 0; i < count; ++i) {
            if (items[i] == target) {
                // shift elements left
                for (int j = i; j < count - 1; ++j)
                    items[j] = items[j + 1];
                count--;
                return;
            }
        }
        // do nothing if not found
    }

    // Implement pure virtual function
    int size() const override {
        return count;
    }
};


#endif
