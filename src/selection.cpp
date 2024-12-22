#include "../include/selection.h"
#include <iostream>
SelectSort::SelectSort(int* array, const int arraySize) : arr(array), size(arraySize) {}

void SelectSort::swap(int* a, int* b) {
  const int temp = *a;
  *a = *b;
  *b = temp;
}

void SelectSort::sort() const {
  if (size <= 1) return;

  for (int i = 0; i < size - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      swap(&arr[i], &arr[minIndex]);
    }
  }
}

void SelectSort::sortAndPrint() const {
  sort();
  std::cout << "Отсортированный массив: ";
  printArray();
}

void SelectSort::printArray() const {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
