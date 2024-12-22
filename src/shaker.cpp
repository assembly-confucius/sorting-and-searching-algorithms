#include "../include/shaker.h"
#include <iostream>

ShakerSort::ShakerSort(int* array, const int arraySize) : arr(array), size(arraySize) {}

void ShakerSort::swap(int* a, int* b) {
  const int temp = *a;
  *a = *b;
  *b = temp;
}

void ShakerSort::sort() const {
  if (size <= 1) return;

  int* left = arr;
  int* right = arr + size - 1;
  bool swapped;

  do {
    swapped = false;

    for (int* ptr = left; ptr < right; ptr++) {
      if (*ptr > *(ptr + 1)) {
        swap(ptr, ptr + 1);
        swapped = true;
      }
    }

    right--;

    for (int* ptr = right; ptr > left; ptr--) {
      if (*ptr < *(ptr - 1)) {
        swap(ptr, ptr - 1);
        swapped = true;
      }
    }

    left++;

  } while (swapped);
}

void ShakerSort::sortAndPrint() const {
  sort();
  std::cout << "Отсортированный массив: ";
  printArray();
}

void ShakerSort::printArray() const {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
