#include "gtest/gtest.h"
#include "../../include/comb.h"

TEST(CombSortTest, HandlesEmptyArray) {
  int arr[] = {};
  constexpr int size = 0;

  const CombSort sorter(arr, size);
  sorter.sort();

  EXPECT_EQ(size, 0); // Проверяем, что размер массива остался равным 0
}

TEST(CombSortTest, HandlesSingleElementArray) {
  int arr[] = {42};
  constexpr int size = 1;

  const CombSort sorter(arr, size);
  sorter.sort();

  EXPECT_EQ(arr[0], 42); // Проверяем, что единственный элемент остался без изменений
}

TEST(CombSortTest, HandlesSortedArray) {
  int arr[] = {1, 2, 3, 4, 5};
  constexpr int size = 5;

  const CombSort sorter(arr, size);
  sorter.sort();

  const int expected[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < size; ++i) {
    EXPECT_EQ(arr[i], expected[i]);
  }
}

TEST(CombSortTest, HandlesReversedArray) {
  int arr[] = {5, 4, 3, 2, 1};
  constexpr int size = 5;

  const CombSort sorter(arr, size);
  sorter.sort();

  const int expected[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < size; ++i) {
    EXPECT_EQ(arr[i], expected[i]);
  }
}

TEST(CombSortTest, HandlesUnsortedArray) {
  int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
  constexpr int size = 10;

  const CombSort sorter(arr, size);
  sorter.sort();

  const int expected[] = {1, 1, 2, 3, 3, 4, 5, 5, 6, 9};
  for (int i = 0; i < size; ++i) {
    EXPECT_EQ(arr[i], expected[i]);
  }
}
