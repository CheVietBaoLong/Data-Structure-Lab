#include <ordershewrote/item.hpp>
#include <ordershewrote/order.hpp>


// --- BOGO IMPLEMENTATION ---
Bogo::Bogo(const Item& paid, const Item& free) {
    items.add(paid);
    items.add(free);
}

int Bogo::size() const {
    return items.size(); // should always be 2
}

// --- FLEXIBLE ORDER IMPLEMENTATION ---
void FlexibleOrder::add(const Item& item) {
    items.add(item);
}

void FlexibleOrder::remove(const Item& item) {
    items.remove(item.getItemName());
}

int FlexibleOrder::size() const {
    return items.size();
}
