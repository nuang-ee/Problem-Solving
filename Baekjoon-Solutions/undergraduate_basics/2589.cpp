// https://www.acmicpc.net/problem/2589
// find length of maximum distance in a 2d array graph.
#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

bool map[50][50];
int dist[50][50];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    vector<int> maxDists;
    cin >> n >> m;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = (s[j] == 'L');
        }
    }

    memset(dist, -1, sizeof dist);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!map[i][j] || dist[i][j] != -1) continue;

            queue<pair<int, int>> q;
            vector<pair<int, int>> maxDistCells;
            int qSize, time = 1;
            q.emplace(i, j);
            dist[i][j] = 0;

            int x, y, curX, curY;
            // find farthest cell from the starting cell, using BFS.
            while (!q.empty()) {
                qSize = q.size();
                maxDistCells.clear();
                for (int k = 0; k < qSize; k++) {
                    std::tie(x, y) = q.front(); q.pop();
                    maxDistCells.emplace_back(x, y);
                    // do BFS.
                    for (int l = 0; l < 4; l++) {
                        curX = x + dx[l];
                        curY = y + dy[l];
                        if (curX >= 0 && curX < n && curY >= 0 && curY < m
                        && map[curX][curY] && dist[curX][curY] == -1) {
                            dist[curX][curY] = 0;
                            q.emplace(curX, curY);
                        }
                    }
                }
                time++;
            }
            // do BFS again starting from the farthest cell.
            // Farthest cell may be not unique??
            int iter = 0;
            for (auto cell : maxDistCells) {
                std::tie(x, y) = cell;
                q.emplace(x, y);
                time = 1;
                dist[x][y] = 1;
                while (!q.empty()) {
                    qSize = q.size();
                    for (int k = 0; k < qSize; k++) {
                        std::tie(x, y) = q.front(); q.pop();
                        for (int l = 0; l < 4; l++) {
                            curX = x + dx[l];
                            curY = y + dy[l];
                            if (curX >= 0 && curX < n && curY >= 0 && curY < m
                            && map[curX][curY] && dist[curX][curY] == iter) {
                                dist[curX][curY] = iter + 1;
                                q.emplace(curX, curY);
                            }
                        }
                    }
                    if (q.empty()) break;
                    time++;
                }
                maxDists.emplace_back(time - 1);
                iter++;
            }
        }
    }
    cout << *max_element(maxDists.begin(), maxDists.end()) << '\n';
}