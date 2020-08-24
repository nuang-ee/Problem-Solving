// https://www.acmicpc.net/problem/10026
// find area of different color, both for normal and color-blind.
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int paint[100][100]; // RGB = 012
bool visited[100][100];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    string s;
    int numRegions = 0;
    int numRegionsBlind = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {    
        cin >> s;
        for (int j = 0; j < n; j++) {
            switch (s[j]) {
                case 'R':
                    paint[i][j] = 0;
                    break;
                case 'G':
                    paint[i][j] = 1;
                    break;
                case 'B':
                    paint[i][j] = 2;
                    break;
            }
        }
    }

    // for not color-blinded.
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            // do DFS on one cell.
            if (!visited[x][y]) {
                queue<pair<int, int>> q;
                visited[x][y] = true;
                int curColor = paint[x][y];
                q.push(make_pair(x, y));
                while (!q.empty()) {
                    pair<int, int> cell = q.front(); q.pop();
                    int cellX = cell.first, cellY = cell.second;
                    if (cellX + 1 < n && paint[cellX + 1][cellY] == curColor && !visited[cellX + 1][cellY]) {
                        visited[cellX + 1][cellY] = true;
                        q.push(make_pair(cellX + 1, cellY));
                    }
                    if (cellY + 1 < n && paint[cellX][cellY + 1] == curColor && !visited[cellX][cellY + 1]) {
                        visited[cellX][cellY + 1] = true;
                        q.push(make_pair(cellX, cellY + 1));
                    }
                    if (cellX - 1 >= 0 && paint[cellX - 1][cellY] == curColor && !visited[cellX - 1][cellY]) {
                        visited[cellX - 1][cellY] = true;
                        q.push(make_pair(cellX - 1, cellY));
                    }
                    if (cellY - 1 >= 0 && paint[cellX][cellY - 1] == curColor && !visited[cellX][cellY - 1]) {
                        visited[cellX][cellY - 1] = true;
                        q.push(make_pair(cellX, cellY - 1));
                    }
                }
                numRegions++;
            }
        }
    }

    memset(visited, 0, sizeof visited);
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            // do DFS on one cell.
            if (!visited[x][y]) {
                queue<pair<int, int>> q;
                visited[x][y] = true;
                int curColor = paint[x][y];
                q.push(make_pair(x, y));
                while (!q.empty()) {
                    pair<int, int> cell = q.front(); q.pop();
                    int cellX = cell.first, cellY = cell.second;
                    if (cellX + 1 < n && !visited[cellX + 1][cellY]
                    && (paint[cellX + 1][cellY] == curColor || paint[cellX + 1][cellY] + curColor == 1)) {
                        visited[cellX + 1][cellY] = true;
                        q.push(make_pair(cellX + 1, cellY));
                    }
                    if (cellY + 1 < n && !visited[cellX][cellY + 1]
                    && (paint[cellX][cellY + 1] == curColor || paint[cellX][cellY + 1] + curColor == 1)) {
                        visited[cellX][cellY + 1] = true;
                        q.push(make_pair(cellX, cellY + 1));
                    }
                    if (cellX - 1 >= 0 && !visited[cellX - 1][cellY]
                    && (paint[cellX - 1][cellY] == curColor || paint[cellX - 1][cellY] + curColor == 1)) {
                        visited[cellX - 1][cellY] = true;
                        q.push(make_pair(cellX - 1, cellY));
                    }
                    if (cellY - 1 >= 0 && !visited[cellX][cellY - 1]
                    && (paint[cellX][cellY - 1] == curColor || paint[cellX][cellY - 1] + curColor == 1)) {
                        visited[cellX][cellY - 1] = true;
                        q.push(make_pair(cellX, cellY - 1));
                    }
                }
                numRegionsBlind++;
            }
        }
    }

    cout << numRegions << ' ' << numRegionsBlind << '\n';
}