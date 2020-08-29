// https://www.acmicpc.net/problem/2178
// find minimum length to the goal in a maze.
#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
#include <string>

using namespace std;

bool visited[100][100];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, time = 1;
    string s;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            visited[i][j] = (s[j] == '0') ? true : false;
        }
    }

    queue<pair<int, int>> q;
    int qSize;
    q.emplace(0, 0);
    visited[0][0] = true;

    int x, y, curX, curY;
    while (true) {
        qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            std::tie(x, y) = q.front(); q.pop();
            if (x == n-1 && y == m-1) goto end;
            
            // do BFS.
            for (int i = 0; i < 4; i++) {
                curX = x + dx[i];
                curY = y + dy[i];
                if (curX >= 0 && curX < n && curY >= 0 && curY < m
                && !visited[curX][curY]) {
                    visited[curX][curY] = true;
                    q.emplace(curX, curY);
                }
            }
        }
        time++;
    }
end:
    cout << time << '\n';
}