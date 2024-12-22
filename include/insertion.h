#ifndef INSERTION_H
#define INSERTION_H

class InsertionSort {
  int* arr;
  int size;

public:
  InsertionSort(int* array, int arraySize);
  void sort() const;
  void sortAndPrint() const;

private:
  void printArray() const;
};

#endif
