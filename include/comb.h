#ifndef COMB_H
#define COMB_H

class CombSort {
  int* arr;
  int size;

  static void swap(int* a, int* b);

public:
  CombSort(int* array, int arraySize);

  void sort() const;
  void sortAndPrint() const;

private:
  void printArray() const;
};

#endif
