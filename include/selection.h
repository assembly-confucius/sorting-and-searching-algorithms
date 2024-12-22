#ifndef SELECTION_H
#define SELECTION_H

class SelectSort {
  int* arr;
  int size;

  static void swap(int* a, int* b);

public:
  SelectSort(int* array, int arraySize);
  void sort() const;
  void sortAndPrint() const;

private:
  void printArray() const;
};

#endif
