#include "../include/bubble.h"
#include <iostream>

// Конструктор
BubbleSort::BubbleSort(int* array, const int arraySize) : arr(array), size(arraySize) {}

// Вспомогательная функция для обмена элементов
void BubbleSort::swap(int* a, int* b) {
  const int temp = *a;
  *a = *b;
  *b = temp;
}

// Алгоритм пузырьковой сортировки
void BubbleSort::sort() const {
  if (size <= 1) return;

  for (int i = 0; i < size - 1; i++) {
    bool swapped = false;
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}

// Сортировка и вывод массива
void BubbleSort::sortAndPrint() const {
  sort();
  std::cout << "Отсортированный массив: ";
  printArray();
}

// Вывод массива
void BubbleSort::printArray() const {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
