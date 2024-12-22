#ifndef BFS_H
#define BFS_H

#include <vector>

class GraphBfs {
  int vertices;
  std::vector<std::vector<int>> adjList;

public:
  explicit GraphBfs(int v);
  void addEdge(int u, int v);
  void BFS(int start, int goal);
  void displayEdges() const;

private:
  static void printPath(int goal, const std::vector<int> &parent);
};

#endif
