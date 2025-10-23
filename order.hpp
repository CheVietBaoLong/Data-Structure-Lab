#ifndef ORDERSHEWROTE_ORDER_HPP
#define ORDERSHEWROTE_ORDER_HPP

#include <iostream>
#include <ordershewrote/item.hpp>
#include <ordershewrote/linkedlist.hpp>

class Order {
public:
    virtual int size() const = 0;
    virtual ~Order() {}
};

class Bogo : public Order {
private:
    LinkedList items;
public:
    Bogo(const Item& paid, const Item& free);
    int size() const override;
};

class FlexibleOrder : public Order {
private:
    LinkedList items;
public:
    void add(const Item& item);
    void remove(const Item& item);
    int size() const override;
};

#endif
