#include "../include/quick.h"
#include <iostream>

QuickSort::QuickSort(int* array, const int arraySize) : arr(array), size(arraySize) {}

void QuickSort::swap(int* a, int* b) {
  const int temp = *a;
  *a = *b;
  *b = temp;
}

int QuickSort::partition(const int low, const int high) const {
  const int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

void QuickSort::quickSort(const int low, const int high) const {
  if (low < high) {
    const int pivotIndex = partition(low, high);
    quickSort(low, pivotIndex - 1);
    quickSort(pivotIndex + 1, high);
  }
}

void QuickSort::sort() const {
  if (size <= 1) return;
  quickSort(0, size - 1);
}

void QuickSort::sortAndPrint() const {
  sort();
  std::cout << "Отсортированный массив: ";
  printArray();
}

void QuickSort::printArray() const {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
