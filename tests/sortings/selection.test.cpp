#include "gtest/gtest.h"
#include "../../include/selection.h"

TEST(SelectSortTest, HandlesEmptyArray) {
  int arr[] = {};
  constexpr int size = 0;

  const SelectSort sorter(arr, size);
  sorter.sort();

  EXPECT_EQ(size, 0); // Проверяем, что массив остался пустым
}

TEST(SelectSortTest, HandlesSingleElementArray) {
  int arr[] = {42};
  constexpr int size = 1;

  const SelectSort sorter(arr, size);
  sorter.sort();

  EXPECT_EQ(arr[0], 42); // Проверяем, что единственный элемент остался без изменений
}

TEST(SelectSortTest, HandlesSortedArray) {
  int arr[] = {1, 2, 3, 4, 5};
  constexpr int size = 5;

  const SelectSort sorter(arr, size);
  sorter.sort();

  const int expected[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < size; ++i) {
    EXPECT_EQ(arr[i], expected[i]);
  }
}

TEST(SelectSortTest, HandlesReversedArray) {
  int arr[] = {5, 4, 3, 2, 1};
  constexpr int size = 5;

  const SelectSort sorter(arr, size);
  sorter.sort();

  const int expected[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < size; ++i) {
    EXPECT_EQ(arr[i], expected[i]);
  }
}

TEST(SelectSortTest, HandlesUnsortedArray) {
  int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
  constexpr int size = 10;

  const SelectSort sorter(arr, size);
  sorter.sort();

  const int expected[] = {1, 1, 2, 3, 3, 4, 5, 5, 6, 9};
  for (int i = 0; i < size; ++i) {
    EXPECT_EQ(arr[i], expected[i]);
  }
}

TEST(SelectSortTest, HandlesArrayWithDuplicates) {
  int arr[] = {4, 2, 2, 8, 3, 3, 1};
  constexpr int size = 7;

  const SelectSort sorter(arr, size);
  sorter.sort();

  const int expected[] = {1, 2, 2, 3, 3, 4, 8};
  for (int i = 0; i < size; ++i) {
    EXPECT_EQ(arr[i], expected[i]);
  }
}

TEST(SelectSortTest, HandlesArrayWithNegativeNumbers) {
  int arr[] = {-5, -10, 0, -3, 8, 5, -1, 10};
  constexpr int size = 8;

  const SelectSort sorter(arr, size);
  sorter.sort();

  constexpr int expected[] = {-10, -5, -3, -1, 0, 5, 8, 10};
  for (int i = 0; i < size; ++i) {
    EXPECT_EQ(arr[i], expected[i]);
  }
}
