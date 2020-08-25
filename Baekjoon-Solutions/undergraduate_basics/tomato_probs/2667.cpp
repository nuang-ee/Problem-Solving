// https://www.acmicpc.net/problem/2667
// find connected apartments & their number of households in non-descending order.
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int apt[25][25];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    string s;
    vector<int> numHouseholds;

    cin >> n;
    for (int i = 0; i < n; i++) {    
        cin >> s;
        for (int j = 0; j < n; j++) {
            apt[i][j] = (s[j] == '1') ? 1 : 0;
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            // do DFS on one cell.
            if (apt[x][y]) {
                queue<pair<int, int>> q;
                apt[x][y] = 0;
                int household = 0;
                q.push(make_pair(x, y));
                while (!q.empty()) {
                    pair<int, int> cell = q.front(); q.pop(); household++;
                    int cellX = cell.first, cellY = cell.second;
                    for (int i = 0; i < 4; i++) {
                        int curX = cellX + dx[i], curY = cellY + dy[i];
                        if (curX >= 0 && curX < n && curY >= 0 && curY < n && apt[curX][curY]) {
                            apt[curX][curY] = 0;
                            q.push(make_pair(curX, curY));
                        }
                    }
                }
                numHouseholds.emplace_back(household);
            }
        }
    }

    cout << numHouseholds.size() << '\n';
    sort(numHouseholds.begin(), numHouseholds.end());
    for (auto e : numHouseholds) cout << e << '\n';
}