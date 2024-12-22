#ifndef COUNTING_H
#define COUNTING_H

class CountingSort {
  int* arr;
  int size;

public:
  CountingSort(int* array, int arraySize);

  void sort() const;
  void sortAndPrint() const;

private:
  void printArray() const;
};

#endif
