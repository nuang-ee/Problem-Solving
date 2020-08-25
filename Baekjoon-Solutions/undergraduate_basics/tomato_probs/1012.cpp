// https://www.acmicpc.net/problem/1012
// find connected group of cells in 2-d table.
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T, m, n, k;
    int numWorms;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> m >> n >> k;
        numWorms = 0;
        bool field[m][n];
        bool visited[m][n];
        memset(field, false, sizeof field);
        memset(visited, false, sizeof visited);
        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            field[x][y] = true;
        }

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                // do DFS on one cell.
                if (field[x][y] && !visited[x][y]) {
                    queue<pair<int, int>> q;
                    visited[x][y] = true;
                    q.push(make_pair(x, y));
                    while (!q.empty()) {
                        pair<int, int> cell = q.front(); q.pop();
                        int cellX = cell.first, cellY = cell.second;
                        if (cellX + 1 < m && field[cellX + 1][cellY] && !visited[cellX+1][cellY]) {
                            visited[cellX + 1][cellY] = true;
                            q.push(make_pair(cellX+1, cellY));
                        }
                        if (cellY + 1 < n && field[cellX][cellY + 1] && !visited[cellX][cellY + 1]) {
                            visited[cellX][cellY + 1] = true;
                            q.push(make_pair(cellX, cellY + 1));
                        }
                        if (cellX - 1 >= 0 && field[cellX - 1][cellY] && !visited[cellX-1][cellY]) {
                            visited[cellX - 1][cellY] = true;
                            q.push(make_pair(cellX - 1, cellY));
                        }
                        if (cellY - 1 >= 0 && field[cellX][cellY - 1] && !visited[cellX][cellY - 1]) {
                            visited[cellX][cellY - 1] = true;
                            q.push(make_pair(cellX, cellY - 1));
                        }
                    }
                    numWorms++;
                }
            }
        }
        cout << numWorms << '\n';
    }
}