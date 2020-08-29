// https://www.acmicpc.net/problem/7562
// find minimum time for reaching given position by knight move.
#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
#include <cstring>

using namespace std;

bool visited[300][300];

int dx[8] = {-2,-2, 2, 2,-1,-1, 1, 1};
int dy[8] = {-1, 1,-1, 1,-2, 2,-2, 2};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    int l, startX, startY, goalX, goalY, goaltime;
    cin >> n;

    for (int i = 0; i < n; i++) {
        goaltime = 0;

        cin >> l;
        cin >> startX >> startY;
        cin >> goalX >> goalY;

        memset(visited, 0, sizeof visited);
        queue<pair<int, int>> q;
        int qSize;
        q.emplace(startX, startY);
        visited[startX][startY] = true;

        int x, y, curX, curY;
        bool done = false;
        while (!q.empty()) {
            qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                std::tie(x, y) = q.front(); q.pop();
                if (x == goalX && y == goalY) {
                    done = true;
                    break;
                }
                
                // do BFS.
                for (int i = 0; i < 8; i++) {
                    curX = x + dx[i];
                    curY = y + dy[i];
                    if (curX >= 0 && curX < l && curY >= 0 && curY < l
                    && !visited[curX][curY]) {
                        visited[curX][curY] = true;
                        q.emplace(curX, curY);
                    }
                }
            }
            if (done) break;
            goaltime++;
        }
        cout << goaltime << '\n';
    }
}