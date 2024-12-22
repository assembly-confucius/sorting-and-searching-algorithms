#ifndef MERGE_H
#define MERGE_H

class MergeSort {
  int* arr;
  int size;

  static void merge(int *array, int left, int mid, int right);
  static void mergeSort(int* array, int left, int right);

public:
  MergeSort(int* array, int arraySize);
  void sort() const;
  void sortAndPrint() const;

private:
  void printArray() const;
};

#endif
