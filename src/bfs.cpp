#include "../include/bfs.h"
#include <algorithm>
#include <queue>
#include <iostream>

GraphBfs::GraphBfs(const int v) : vertices(v) {
  adjList.resize(v);
}

// Добавление ребра
void GraphBfs::addEdge(const int u, const int v) {
  adjList[u].push_back(v);
  adjList[v].push_back(u);
}

// Алгоритм BFS
void GraphBfs::BFS(const int start, const int goal) {
  std::vector visited(vertices, false);
  std::vector parent(vertices, -1);
  std::queue<int> q;

  visited[start] = true;
  q.push(start);

  while (!q.empty()) {
    const int node = q.front();
    q.pop();

    if (node == goal) {
      printPath(goal, parent);
      return;
    }

    for (int neighbor : adjList[node]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        parent[neighbor] = node;
        q.push(neighbor);
      }
    }
  }

  std::cout << "Нет пути от " << start << " до " << goal << std::endl;
}

// Отображение рёбер
void GraphBfs::displayEdges() const {
  std::cout << "Список рёбер графа:" << std::endl;
  for (int u = 0; u < vertices; ++u) {
    for (const int v : adjList[u]) {
      if (u < v) {
        std::cout << u << " - " << v << std::endl;
      }
    }
  }
}

// Печать пути
void GraphBfs::printPath(const int goal, const std::vector<int> &parent) {
  std::vector<int> path;
  int current = goal;

  while (current != -1) {
    path.push_back(current);
    current = parent[current];
  }

  std::ranges::reverse(path);

  std::cout << "Длина пути: " << path.size() - 1 << std::endl;
  std::cout << "Путь: ";
  for (size_t i = 0; i < path.size(); ++i) {
    std::cout << path[i];
    if (i < path.size() - 1) {
      std::cout << " -> ";
    }
  }
  std::cout << std::endl;
}
