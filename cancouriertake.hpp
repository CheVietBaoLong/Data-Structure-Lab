#ifndef ORDERSHEWROTE_CANCOURIERTAKE_HPP
#define ORDERSHEWROTE_CANCOURIERTAKE_HPP

#include <ordershewrote/order.hpp>

bool canCourierTake(const Order& order, int max_capacity) {
	return order.size() <= max_capacity;
};

#endif
