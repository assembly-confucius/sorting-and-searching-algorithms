#include "gtest/gtest.h"
#include "../../include/bfs.h"
#include <iostream>
#include <sstream>

// Тестирование BFS на графе без рёбер
TEST(GraphBfsTest, NoPathBetweenVertices) {
  GraphBfs graph(5); // Граф с 5 вершинами

  // Пытаемся найти путь между вершинами 0 и 4, но рёбер нет
  testing::internal::CaptureStdout();
  graph.BFS(0, 4);
  const std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "Нет пути от 0 до 4\n");
}

// Тестирование BFS на графе с рёбрами
TEST(GraphBfsTest, PathExists) {
  GraphBfs graph(6);

  // Добавляем рёбра
  graph.addEdge(0, 1);
  graph.addEdge(1, 2);
  graph.addEdge(2, 3);
  graph.addEdge(3, 4);
  graph.addEdge(4, 5);

  // Пытаемся найти путь между вершинами 0 и 5
  testing::internal::CaptureStdout();
  graph.BFS(0, 5);
  const std::string output = testing::internal::GetCapturedStdout();

  EXPECT_TRUE(output.find("Длина пути: 5") != std::string::npos); // Проверка длины пути
  EXPECT_TRUE(output.find("Путь: 0 -> 1 -> 2 -> 3 -> 4 -> 5") != std::string::npos); // Проверка правильности пути
}

// Тестирование вывода рёбер
TEST(GraphBfsTest, DisplayEdges) {
  GraphBfs graph(4);

  // Добавляем рёбра
  graph.addEdge(0, 1);
  graph.addEdge(1, 2);
  graph.addEdge(2, 3);

  testing::internal::CaptureStdout();
  graph.displayEdges();
  const std::string output = testing::internal::GetCapturedStdout();

  EXPECT_TRUE(output.find("Список рёбер графа:") != std::string::npos);
  EXPECT_TRUE(output.find("0 - 1") != std::string::npos);
  EXPECT_TRUE(output.find("1 - 2") != std::string::npos);
  EXPECT_TRUE(output.find("2 - 3") != std::string::npos);
}

// Тестирование случая с несуществующим путём
TEST(GraphBfsTest, NoPathFound) {
  GraphBfs graph(6);

  // Добавляем рёбра
  graph.addEdge(0, 1);
  graph.addEdge(1, 2);
  graph.addEdge(3, 4);
  graph.addEdge(4, 5);

  // Пытаемся найти путь между вершинами 0 и 5 (они не соединены)
  testing::internal::CaptureStdout();
  graph.BFS(0, 5);
  const std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "Нет пути от 0 до 5\n");
}

