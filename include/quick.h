#ifndef QUICK_H
#define QUICK_H

class QuickSort {
  int* arr;
  int size;

  static void swap(int* a, int* b);
  [[nodiscard]] int partition( int low,  int high) const;
  void quickSort( int low,  int high) const;

public:
  QuickSort(int* array,  int arraySize);
  void sort() const;
  void sortAndPrint() const;

private:
  void printArray() const;
};

#endif
