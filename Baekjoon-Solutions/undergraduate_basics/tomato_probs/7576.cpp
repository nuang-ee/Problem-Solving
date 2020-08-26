// https://www.acmicpc.net/problem/1697
// find minimum time of reaching given position.
#include <iostream>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

int box[1000][1000];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int m, n, time = 0;
    cin >> n >> m;

    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) q.push(make_pair(i, j));
        }
    }

    int qSize, x, y;
    while (!q.empty()) {
        qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            std::tie(x, y) = q.front(); q.pop();
            
            // do BFS.
            for (int k = 0; k < 4; k++) {
                int curX = x + dx[k], curY = y + dy[k];
                if (curX >= 0 && curX < m && curY >= 0 && curY < n && box[curX][curY] == 0) {
                    box[curX][curY] = 1;
                    q.push(make_pair(curX, curY));
                }
            }
        }
        if (q.empty()) break;
        time++;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (box[i][j] == 0) time = -1;
        }
    }

    cout << time << '\n';
}