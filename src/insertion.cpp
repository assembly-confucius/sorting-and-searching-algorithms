#include "../include/insertion.h"
#include <iostream>

InsertionSort::InsertionSort(int* array, const int arraySize) : arr(array), size(arraySize) {}

void InsertionSort::sort() const {
  if (size <= 1) return;

  for (int i = 1; i < size; i++) {
    const int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void InsertionSort::sortAndPrint() const {
  sort();
  std::cout << "Отсортированный массив: ";
  printArray();
}

void InsertionSort::printArray() const {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
