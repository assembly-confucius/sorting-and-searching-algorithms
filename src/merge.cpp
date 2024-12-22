#include "../include/merge.h"
#include <iostream>

MergeSort::MergeSort(int* array, const int arraySize) : arr(array), size(arraySize) {}

void MergeSort::merge(int* array, const int left, const int mid,
                      const int right) {
  const int n1 = mid - left + 1;
  const int n2 = right - mid;

  const auto leftArray = new int[n1];
  const auto rightArray = new int[n2];

  for (int i = 0; i < n1; i++) {
    leftArray[i] = array[left + i];
  }
  for (int j = 0; j < n2; j++) {
    rightArray[j] = array[mid + 1 + j];
  }

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (leftArray[i] <= rightArray[j]) {
      array[k] = leftArray[i];
      i++;
    } else {
      array[k] = rightArray[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    array[k] = leftArray[i];
    i++;
    k++;
  }

  while (j < n2) {
    array[k] = rightArray[j];
    j++;
    k++;
  }

  delete[] leftArray;
  delete[] rightArray;
}

void MergeSort::mergeSort(int* array, const int left, const int right) {
  if (left < right) {
    const int mid = left + (right - left) / 2;

    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);

    merge(array, left, mid, right);
  }
}

void MergeSort::sort() const {
  if (size <= 1) return;
  mergeSort(arr, 0, size - 1);
}

void MergeSort::sortAndPrint() const {
  sort();
  std::cout << "Отсортированный массив: ";
  printArray();
}

void MergeSort::printArray() const {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
