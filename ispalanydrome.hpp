#ifndef PALANYDROME_ISPALANYDROME_HPP
#define PALANYDROME_ISPALANYDROME_HPP

#include <vector>

template <typename ElementType>
bool isPalanydrome(const std::vector<ElementType>& vec, int left = 0, int right = -1) {
    if (right == -1) {
        right = static_cast<int>(vec.size()) - 1; // initialize on first call
    }

    // Base case: empty or single element is trivially a palindrome
    if (left >= right) {
        return true;
    }

    // Check first and last elements
    if (vec[left] != vec[right]) {
        return false;
    }

    // Recursive step: move inward
    return isPalanydrome(vec, left + 1, right - 1);
}

#endif