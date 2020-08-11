// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int v_cnt;

public:
    Graph(int v_cnt);
    vector<int> *edges;

    void addEdge(int u, int v);
    int findNumOfVictims();
    int DFSUtil(int u, bool visited[]);
};

Graph::Graph(int v_cnt) {
    this->v_cnt = v_cnt;
    this->edges = new vector<int> [v_cnt+1];
}

void Graph::addEdge(int u, int v) {
    this->edges[u].emplace_back(v);
    this->edges[v].emplace_back(u);
}

int Graph::findNumOfVictims() {
    int numCC = 0;
    bool visited[this->v_cnt + 1];
    for (int i = 0; i <= v_cnt; i++) visited[i] = false;
    return DFSUtil(1, visited);
}

int Graph::DFSUtil(int u, bool visited[]) {
    int numNodes = 0;
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto v : this->edges[cur]) {
            if (visited[v]) continue;
            q.push(v);
            numNodes++;
            visited[v] = true;
        }
    }
    return numNodes;
}

int main() {
    int v_cnt, e, u, v;
    cin >> v_cnt;
    cin >> e;
    Graph g(v_cnt);

    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << g.findNumOfVictims() << '\n';
}