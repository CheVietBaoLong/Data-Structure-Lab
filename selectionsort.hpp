#ifndef __1KLIES_INSERTIONSORT_HPP
#define __1KLIES_INSERTIONSORT_HPP

#include <1klies/sort.hpp>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

template <typename Type> class Selectionsorter : public Sorter<Type> {
public:
  Selectionsorter(bool debug = false) : m_debug(debug) {
  }

  void operator()(std::vector<Type> &tosort) override {
    size_t n = tosort.size();
    for (size_t i = 0; i < n; i++) {
        size_t min_index = i;

        // Find the smallest element in remaining part
        for (size_t j = i + 1; j < n; j++) {
            if (tosort[j] < tosort[min_index]) {
                min_index = j;
            }
        }

        // Swap into sorted position
        std::swap(tosort[i], tosort[min_index]);
    }
  };

private:
  bool m_debug;
};

#endif