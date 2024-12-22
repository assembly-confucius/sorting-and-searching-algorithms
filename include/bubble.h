#ifndef BUBBLE_H
#define BUBBLE_H

class BubbleSort {
  int* arr;
  int size;

  static void swap(int* a, int* b);

public:
  BubbleSort(int* array, int arraySize);

  void sort() const;
  void sortAndPrint() const;

private:
  void printArray() const;
};

#endif
