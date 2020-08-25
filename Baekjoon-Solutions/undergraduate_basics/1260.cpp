// https://www.acmicpc.net/problem/1260
// do dfs & bfs on given graph.
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int apt[25][25];
vector<int> adjVect[1001];
bool visited[1001];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int numV, numE, root;
    cin >> numV >> numE >> root;

    int u, v;
    for (int i = 0; i < numE; i++) {
        cin >> u >> v;
        adjVect[u].emplace_back(v);
        adjVect[v].emplace_back(u);
    }
    for (int i = 0; i < numV; i++) sort(adjVect[i].begin(), adjVect[i].end());

    int cur;
    // DFS.
    stack<int> s; s.push(root);
    while (!s.empty()) {
        cur = s.top(); s.pop();
        if (!visited[cur]) {
            cout << cur << ' ';
            visited[cur] = true;
        }
        for (auto iter = adjVect[cur].rbegin(); iter != adjVect[cur].rend(); iter++) {
            if (!visited[*iter]) {
                s.push(*iter);
            }
        }
    }
    cout << '\n';

    memset(visited, 0, sizeof visited);
    // BFS.
    queue<int> q; q.push(root); visited[root] = true;
    while (!q.empty()) {
        cur = q.front(); q.pop();
        cout << cur << ' ';
        for (auto u : adjVect[cur]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
    cout << '\n';
}