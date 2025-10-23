#ifndef ORDERSHEWROTE_CANCOURIERTAKE_HPP
#define ORDERSHEWROTE_CANCOURIERTAKE_HPP

#include <ordershewrote/order.hpp>


inline bool canCourierTake(const Order& order, int capacity) {
    return capacity >= order.size();
}

#endif

