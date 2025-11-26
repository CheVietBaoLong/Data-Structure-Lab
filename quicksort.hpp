#ifndef __1KLIES_QUICKSORT_HPP
#define __1KLIES_QUICKSORT_HPP

#include <1klies/sort.hpp>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <cstddef>

template <typename Type> class Quicksorter : public Sorter<Type> {
public:
  Quicksorter(bool debug = false) : m_debug(debug) {}

  void operator()(std::vector<Type>& tosort) override {
	  if (!tosort.empty())
		  quicksort(tosort, 0, tosort.size() - 1);
  };

private:
  bool m_debug;

  int partition(std::vector<Type>& arr, int low, int high) {
	  Type pivot = arr[high];
	  int i = low - 1;
	  for (int j = low; j < high; j++) {
		  if (arr[j] < pivot) {
			  i++;
			  std::swap(arr[i], arr[j]);
		  }
	  }
	  std::swap(arr[i + 1], arr[high]);
	  return i + 1;
  }

  void quicksort(std::vector<Type>& arr, int low, int high) {
	  if (low < high) {
		  int pi = partition(arr, low, high);
		  quicksort(arr, low, pi - 1);
		  quicksort(arr, pi + 1, high);
	  }
  }
};

#endif
