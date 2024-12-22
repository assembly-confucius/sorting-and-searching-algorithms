#include "../include/counting.h"
#include <iostream>

CountingSort::CountingSort(int* array, const int arraySize) : arr(array), size(arraySize) {}

void CountingSort::sort() const {
  if (size <= 1) return;

  int maxVal = arr[0];
  int minVal = arr[0];

  // Поиск максимального и минимального значений в массиве
  for (int i = 1; i < size; i++) {
    if (arr[i] > maxVal) {
      maxVal = arr[i];
    }
    if (arr[i] < minVal) {
      minVal = arr[i];
    }
  }

  // Диапазон значений
  const int range = maxVal - minVal + 1;

  // Массив для подсчёта вхождений элементов и вспомогательный массив для отсортированных значений
  const auto count = new int[range]();
  const auto output = new int[size];

  // Подсчёт вхождений каждого элемента в массив
  for (int i = 0; i < size; i++) {
    count[arr[i] - minVal]++;
  }

  // Накопление значений в массиве count для упорядочивания элементов
  for (int i = 1; i < range; i++) {
    count[i] += count[i - 1];
  }

  // Размещение элементов в правильные позиции в массиве output
  for (int i = size - 1; i >= 0; i--) {
    output[count[arr[i] - minVal] - 1] = arr[i];
    count[arr[i] - minVal]--;
  }

  // Копирование отсортированных значений обратно в оригинальный массив
  for (int i = 0; i < size; i++) {
    arr[i] = output[i];
  }

  delete[] count;
  delete[] output;
}

void CountingSort::sortAndPrint() const {
  sort();
  std::cout << "Отсортированный массив: ";
  printArray();
}

void CountingSort::printArray() const {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
