#ifndef TOINCLUDE_H
#define TOINCLUDE_H

#include <iostream>
#include <windows.h>
#include <random>
#include <iomanip>

#include "bubble.h"
#include "bfs.h"
#include "binary_insertion.h"
#include "comb.h"
#include "counting.h"
#include "dfs.h"
#include "heap.h"
#include "insertion.h"
#include "merge.h"
#include "quick.h"
#include "selection.h"
#include "shaker.h"

inline void setup() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

inline void manualOrRandomInput(int*& arr, int& size) {
    int choice;
    std::cout << "Выберите способ ввода массива:\n1. Ввод вручную\n2. Случайный ввод" << std::endl;
    std::cin >> choice;

    std::cout << "Введите размер массива: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Размер массива должен быть положительным!" << std::endl;
        return;
    }

    arr = new int[size];

    switch (choice) {
        case 1:
            std::cout << "Введите элементы массива: ";
            for (int i = 0; i < size; ++i) {
                std::cin >> arr[i];
            }
            break;
        case 2: {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(-999, 999);

            for (int i = 0; i < size; ++i) {
                arr[i] = dis(gen);
            }
            std::cout << "Случайно сгенерированный массив: ";
            for (int i = 0; i < size; ++i) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
            break;
        }
        default:
            std::cout << "Неверный выбор!" << std::endl;
            delete[] arr;
            arr = nullptr;
    }
}

template <typename GraphType>
GraphType generateConnectedGraph(int vertices) {
    GraphType graph(vertices);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, vertices - 1);

    for (int i = 1; i < vertices; ++i) {
        graph.addEdge(i - 1, i);
    }

    const int extraEdges = vertices;
    for (int i = 0; i < extraEdges; ++i) {
        int u = dist(gen);
        if (int v = dist(gen); u != v) {
            graph.addEdge(u, v);
        }
    }

    return graph;
}

inline void executeSort(int* arr, const int size, const int choice) {
  switch (choice) {
  case 1: {
    const BubbleSort sort(arr, size);
    sort.sortAndPrint();
    break;
  }
  case 2: {
    const ShakerSort sort(arr, size);
    sort.sortAndPrint();
    break;
  }
  case 3: {
    const CombSort sort(arr, size);
    sort.sortAndPrint();
    break;
  }
  case 4: {
    const InsertionSort sort(arr, size);
    sort.sortAndPrint();
    break;
  }
  case 5: {
    const MergeSort sort(arr, size);
    sort.sortAndPrint();
    break;
  }
  case 6: {
    const SelectSort sort(arr, size);
    sort.sortAndPrint();
    break;
  }
  case 7: {
    const CountingSort sort(arr, size);
    sort.sortAndPrint();
    break;
  }
  case 8: {
    const QuickSort sort(arr, size);
    sort.sortAndPrint();
    break;
  }
  case 9: {
    const HeapSort sort(arr, size);
    sort.sortAndPrint();
    break;
  }
  case 10: {
    const BinaryInsertionSort sort(arr, size);
    sort.sortAndPrint();
    break;
  }
  default:
    std::cout << "Неверный выбор сортировки!" << std::endl;
    break;
  }
}

inline void menu() {
    int choice;
    int* arr = nullptr;
    int size = 0;

    do {
        std::cout << "\nВыберите способ сортировки" << std::endl;
        std::cout << "1. Bubble" << std::endl;
        std::cout << "2. Shaker" << std::endl;
        std::cout << "3. Comb" << std::endl;
        std::cout << "4. Insertion" << std::endl;
        std::cout << "5. Merge" << std::endl;
        std::cout << "6. Selection" << std::endl;
        std::cout << "7. Counting" << std::endl;
        std::cout << "8. Quick" << std::endl;
        std::cout << "9. Heap" << std::endl;
        std::cout << "10. Binary Insertion" << std::endl;
        std::cout << "\nЛибо поиск кратчайшего пути в графе" << std::endl;
        std::cout << "11. BFS" << std::endl;
        std::cout << "12. DFS" << std::endl;
        std::cout << "13. Выход из программы" << std::endl;

        std::cin >> choice;

        if (choice >= 1 && choice <= 10) {
            manualOrRandomInput(arr, size);
            if (arr != nullptr) {
                executeSort(arr, size, choice);
                delete[] arr;
                arr = nullptr;
            }
        }
        else if (choice == 11 || choice == 12) {
            int vertices;
            std::cout << "Введите количество вершин в графе: ";
            std::cin >> vertices;
            if (vertices <= 0) {
                std::cout << "Количество вершин должно быть больше нуля!" << std::endl;
                continue;
            }

            if (choice == 11) {
                auto graph = generateConnectedGraph<GraphBfs>(vertices);

                std::cout << "Сгенерированные рёбра графа (BFS):" << std::endl;
                graph.displayEdges();

                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dist(0, vertices - 1);

                const int start = dist(gen);
                int goal = dist(gen);
                while (goal == start) {
                    goal = dist(gen);
                }

                std::cout << "Поиск пути от вершины " << start << " до вершины " << goal << ":" << std::endl;
                graph.BFS(start, goal);
            } else {
                auto graph = generateConnectedGraph<GraphDfs>(vertices);

                std::cout << "Сгенерированные рёбра графа (DFS):" << std::endl;
                graph.displayEdges();

                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dist(0, vertices - 1);

                const int start = dist(gen);
                int goal = dist(gen);
                while (goal == start) {
                    goal = dist(gen);
                }

                std::cout << "Поиск пути от вершины " << start << " до вершины " << goal << ":" << std::endl;
                graph.DFS(start, goal);
            }
        }
        else if (choice == 13) {
            std::cout << "Выход из программы." << std::endl;
        } else {
            std::cout << "Неверный выбор! Пожалуйста, выберите снова." << std::endl;
        }

    } while (choice != 13);
}

inline void start() {
    setup();
    menu();
}

#endif
