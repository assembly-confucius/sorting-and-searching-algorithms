#include "../include/binary_insertion.h"
#include <iostream>

// Конструктор
BinaryInsertionSort::BinaryInsertionSort(int* array, int arraySize) : arr(array), size(arraySize) {}

// Алгоритм сортировки
void BinaryInsertionSort::sort() const {
  if (size <= 1) return;

  for (int i = 1; i < size; i++) {
    const int key = arr[i];
    int left = 0;
    int right = i;

    while (left < right) {
      if (const int mid = left + (right - left) / 2; arr[mid] <= key) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    for (int j = i; j > left; j--) {
      arr[j] = arr[j - 1];
    }
    arr[left] = key;
  }
}

// Сортировка и вывод массива
void BinaryInsertionSort::sortAndPrint() const {
  sort();
  std::cout << "Отсортированный массив: ";
  printArray();
}

// Вывод массива
void BinaryInsertionSort::printArray() const {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
