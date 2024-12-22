#include "../include/heap.h"
#include <iostream>

HeapSort::HeapSort(int* array, const int arraySize) : arr(array), size(arraySize) {}

void HeapSort::heapify(const int n, const int i) const {
  int largest = i;
  const int left = 2 * i + 1;
  const int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }

  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(n, largest);
  }
}

void HeapSort::buildHeap() const {
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(size, i);
  }
}

void HeapSort::heapSort() const {
  buildHeap();

  for (int i = size - 1; i > 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(i, 0);
  }
}

void HeapSort::swap(int* a, int* b) {
  const int temp = *a;
  *a = *b;
  *b = temp;
}

void HeapSort::sort() const {
  if (size <= 1) return;
  heapSort();
}

void HeapSort::sortAndPrint() const {
  sort();
  std::cout << "Отсортированный массив: ";
  printArray();
}

void HeapSort::printArray() const {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
