#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include<iostream>
using namespace std;
void hierholzer(vector<vector<int>>& graph, vector<int>& path, int node) {
  while (!graph[node].empty()) {
    int neighbor = graph[node].back();
    graph[node].pop_back();
    hierholzer(graph, path, neighbor);
  }
  path.push_back(node);
}

vector<int> findEulerianPath(vector<vector<int>>& graph) {
  vector<int> path;
  // Pick any starting node
  int start = 0;
  hierholzer(graph, path, start);
  // Reverse the path to get a correct Eulerian path (optional)
  reverse(path.begin(), path.end());
  return path;
}

int main() {
  // Create a sample graph
  vector<vector<int>> graph = {
    {1,6},
    {2},
    {0, 3},
    {4},
    {2,5},
    {0},
    {4},
    {}
  };

  vector<int> eulerianPath = findEulerianPath(graph);

  // Print the Eulerian path
  for (int node : eulerianPath) {
    cout << node << " ";
  }
  cout << endl;

  return 0;
}
