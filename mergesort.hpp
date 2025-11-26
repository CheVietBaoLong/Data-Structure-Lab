#ifndef __1KLIES_MERGESORT_HPP
#define __1KLIES_MERGESORT_HPP

#include <1klies/sort.hpp>
#include <1klies/utilities.hpp>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <cstddef>

template <typename Type> class Mergesorter : public Sorter<Type> {
public:
  Mergesorter(bool debug = false) : m_debug(debug) {}

  void operator()(std::vector<Type>& tosort) override {
	  merge_sort(tosort, 0, tosort.size() - 1);

  };

private:
  bool m_debug;

  void merge(std::vector<Type>& arr, int left, int mid, int right) {
	  int n1 = mid - left + 1;
	  int n2 = right - mid;

	  std::vector<Type> L(n1);
	  std::vector<Type> R(n2);

	  for (int i = 0; i < n1; i++)
		  L[i] = arr[left + i];
	  for (int j = 0; j < n2; j++)
		  R[j] = arr[mid + 1 + j];

	  int i = 0;
	  int j = 0;
	  int k = left;

	  while (i < n1 && j < n2) {
		  if (L[i] <= R[j]) {
			  arr[k++] = L[i++];
		  } else {
			  arr[k++] = R[j++];
		  }
	  }

	  while (i < n1) {
		  arr[k++] = L[i++];
	  }

	  while (j < n2) {
		  arr[k++] = R[j++];
	  }
  }

  void merge_sort(std::vector<Type>& arr, int left, int right) {
	  if (left < right) {
		  int mid = left + (right - left) / 2;
		  merge_sort(arr, left, mid);
		  merge_sort(arr, mid + 1, right);
		  merge(arr, left, mid, right);
	  }
  }
};

#endif