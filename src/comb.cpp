#include "../include/comb.h"
#include <iostream>
#include <cmath>

// Конструктор
CombSort::CombSort(int* array, const int arraySize) : arr(array), size(arraySize) {}

// Вспомогательная функция для обмена элементов
void CombSort::swap(int* a, int* b) {
  const int temp = *a;
  *a = *b;
  *b = temp;
}

// Алгоритм сортировки расческой
void CombSort::sort() const {
  if (size <= 1) return;

  int gap = size;
  bool swapped = true;

  while (gap > 1 || swapped) {
    constexpr float shrinkFactor = 1.3f;
    gap = static_cast<int>(std::floor(static_cast<float>(gap) / shrinkFactor));
    if (gap < 1) {
      gap = 1;
    }

    swapped = false;

    for (int i = 0; i < size - gap; i++) {
      if (arr[i] > arr[i + gap]) {
        swap(&arr[i], &arr[i + gap]);
        swapped = true;
      }
    }
  }
}

// Сортировка и вывод массива
void CombSort::sortAndPrint() const {
  sort();
  std::cout << "Отсортированный массив: ";
  printArray();
}

// Вывод массива
void CombSort::printArray() const {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
