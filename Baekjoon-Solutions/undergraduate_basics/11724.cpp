// https://www.acmicpc.net/problem/11724

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    int v_cnt;

public:
    Graph(int v_cnt);
    vector<vector<int>> edges;

    void addEdge(int u, int v);
    int findNumOfCC();
    void DFSUtil(int u, bool visited[]);
};

Graph::Graph(int v_cnt) {
    this->v_cnt = v_cnt;
    this->edges = vector<vector<int>> (v_cnt+1);
}

void Graph::addEdge(int u, int v) {
    this->edges[u].emplace_back(v);
    this->edges[v].emplace_back(u);
}

int Graph::findNumOfCC() {
    int numCC = 0;
    bool visited[this->v_cnt + 1];
    for (int i = 0; i <= v_cnt; i++) visited[i] = false;
    for (int i = 1; i <= v_cnt; i++) {
        // 0 is invalid node.
        if (visited[i] == false) {
            numCC++;
            DFSUtil(i, visited);
        }
    }
    return numCC;
}

void Graph::DFSUtil(int u, bool visited[]) {
    visited[u] = true;
    for (auto v : this->edges[u]) {
        if (!visited[v])
            DFSUtil(v, visited);
    }
}

int main() {
    int v_cnt, e, u, v;
    cin >> v_cnt >> e;
    Graph g(v_cnt);

    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << g.findNumOfCC() << '\n';
}