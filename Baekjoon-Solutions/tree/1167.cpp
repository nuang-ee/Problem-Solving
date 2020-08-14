// https://www.acmicpc.net/problem/1167

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    // index 0 is unused.
    vector<pair<int, int>> *adj_list = new vector<pair<int, int>> [n+1];

    int cur, connected_to, weight, temp;
    for (int i = 0; i < n; i++) {
        cin >> cur >> connected_to;
        while (connected_to != -1) {
            cin >> weight >> temp;
            adj_list[cur].emplace_back(make_pair(connected_to, weight));
            connected_to = temp;
        }
    }
    int root = 1;
    bool visited[n+1];
    queue<int> q;
    int dist_from_root[n+1];

    //initiate.
    memset(visited, 0, sizeof(visited));
    memset(dist_from_root, 0, sizeof(dist_from_root));
    visited[root] = true;
    q.push(root);

    // mark nodes with their distance from root.
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto adj_node : adj_list[cur]) {
            int node_num = adj_node.first;
            int edge_weight = adj_node.second; 

            if (!visited[node_num] || (dist_from_root[cur] + edge_weight < dist_from_root[node_num])) {
                dist_from_root[node_num] = dist_from_root[cur] + edge_weight;
            }

            if (!visited[node_num]) {
                visited[node_num] = true;
                q.push(node_num);
            }
        }
    }

    // get max distance node.
    int max_dist_node = 0, max_dist = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) continue;
        if (max_dist < dist_from_root[i]) {
            max_dist_node = i;
            max_dist = dist_from_root[i];
        }
    }

    //initiate second operation, starts from max_dist_node.
    root = max_dist_node;

    memset(visited, 0, sizeof(visited));
    memset(dist_from_root, 0, sizeof(dist_from_root));
    visited[root] = true;
    q.push(root);
    // mark nodes with their distance from root.
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto adj_node : adj_list[cur]) {
            int node_num = adj_node.first;
            int edge_weight = adj_node.second; 

            if (!visited[node_num] || (dist_from_root[cur] + edge_weight < dist_from_root[node_num])) {
                dist_from_root[node_num] = dist_from_root[cur] + edge_weight;
            }

            if (!visited[node_num]) {
                visited[node_num] = true;
                q.push(node_num);
            }
        }
    }
    // get max distance node.
    max_dist_node = 0, max_dist = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) continue;
        if (max_dist < dist_from_root[i]) {
            max_dist_node = i;
            max_dist = dist_from_root[i];
        }
    }

    cout << max_dist << '\n';
}