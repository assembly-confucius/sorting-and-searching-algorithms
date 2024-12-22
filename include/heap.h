#ifndef HEAP_H
#define HEAP_H

class HeapSort {
  int* arr;
  int size;

  void heapify(int n, int i) const;
  void buildHeap() const;
  void heapSort() const;
  static void swap(int* a, int* b);

public:
  HeapSort(int* array, int arraySize);
  void sort() const;
  void sortAndPrint() const;

private:
  void printArray() const;
};

#endif
