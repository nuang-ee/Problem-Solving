// https://www.acmicpc.net/problem/2583
// find area of divided regions of 2d array.
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool visited[100][100];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int m, n, k;
    int numRegions = 0;
    vector<int> sizesOfRegion;

    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        for (int x = lx; x < rx; x++) {
            for (int y = ly; y < ry; y++)
                visited[x][y] = true;
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            // do DFS on one cell.
            if (!visited[x][y]) {
                int regionSize = 0;
                queue<pair<int, int>> q;
                visited[x][y] = true;
                q.push(make_pair(x, y));
                while (!q.empty()) {
                    pair<int, int> cell = q.front(); q.pop(); regionSize++;
                    int cellX = cell.first, cellY = cell.second;
                    if (cellX + 1 < n && !visited[cellX + 1][cellY]) {
                        visited[cellX + 1][cellY] = true;
                        q.push(make_pair(cellX + 1, cellY));
                    }
                    if (cellY + 1 < m && !visited[cellX][cellY + 1]) {
                        visited[cellX][cellY + 1] = true;
                        q.push(make_pair(cellX, cellY + 1));
                    }
                    if (cellX - 1 >= 0 && !visited[cellX - 1][cellY]) {
                        visited[cellX - 1][cellY] = true;
                        q.push(make_pair(cellX - 1, cellY));
                    }
                    if (cellY - 1 >= 0 && !visited[cellX][cellY - 1]) {
                        visited[cellX][cellY - 1] = true;
                        q.push(make_pair(cellX, cellY - 1));
                    }
                }
                numRegions++;
                sizesOfRegion.emplace_back(regionSize);
            }
        }
    }

    cout << numRegions << '\n';
    sort(sizesOfRegion.begin(), sizesOfRegion.end());
    for (auto size = sizesOfRegion.begin(); size != sizesOfRegion.end(); size++) {
        cout << *size;
        if (size != sizesOfRegion.end() - 1) cout << ' ';
    }
    cout << '\n';
}