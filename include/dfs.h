#ifndef DFS_H
#define DFS_H

#include <vector>

class GraphDfs {
  int vertices;
  std::vector<std::vector<int>> adjList;

public:
  explicit GraphDfs(int v);

  void addEdge(int u, int v);
  void DFS(int start, int goal);
  void displayEdges() const;

private:
  static void printPath(int goal, const std::vector<int>& parent);
};

#endif
