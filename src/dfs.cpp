#include "../include/dfs.h"
#include <algorithm>
#include <stack>
#include <iostream>
#include <vector>

GraphDfs::GraphDfs(const int v) : vertices(v) {
  adjList.resize(v);
}

void GraphDfs::addEdge(const int u, const int v) {
  adjList[u].push_back(v);
  adjList[v].push_back(u);
}

void GraphDfs::DFS(const int start, const int goal) {
  std::vector<bool> visited(vertices, false);
  std::vector<int> parent(vertices, -1);
  std::stack<int> s;

  visited[start] = true;
  s.push(start);

  while (!s.empty()) {
    const int node = s.top();
    s.pop();

    if (node == goal) {
      printPath(goal, parent);
      return;
    }

    for (int neighbor : adjList[node]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        parent[neighbor] = node;
        s.push(neighbor);
      }
    }
  }

  std::cout << "Нет пути от " << start << " до " << goal << std::endl;
}

void GraphDfs::displayEdges() const {
  std::cout << "Список рёбер графа:" << std::endl;
  for (int u = 0; u < vertices; ++u) {
    for (const int v : adjList[u]) {
      if (u < v) {
        std::cout << u << " - " << v << std::endl;
      }
    }
  }
}

void GraphDfs::printPath(const int goal, const std::vector<int>& parent) {
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
    if (i < path.size() - 1) std::cout << " -> ";
  }
  std::cout << std::endl;
}
