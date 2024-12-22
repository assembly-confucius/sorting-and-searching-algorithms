#ifndef SHAKER_H
#define SHAKER_H

class ShakerSort {
  int* arr;
  int size;

  static void swap(int* a, int* b);

public:
  ShakerSort(int* array,  int arraySize);
  void sort() const;
  void sortAndPrint() const;

private:
  void printArray() const;
};

#endif
