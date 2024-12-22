#ifndef BINARY_INSERTION_H
#define BINARY_INSERTION_H

class BinaryInsertionSort {
  int* arr;
  int size;

public:
  BinaryInsertionSort(int* array, int arraySize);

  void sort() const;
  void sortAndPrint() const;

private:
  void printArray() const;
};

#endif
