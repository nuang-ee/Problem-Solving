// https://www.acmicpc.net/problem/1697
// find minimum time of reaching given position.
#include <iostream>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

bool visited[100001];

inline vector<int> getChildren(int cur) {
    return {cur + 1, cur - 1, cur * 2};
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int start, goal, cur, time = 0;
    cin >> start >> goal;

    queue<int> q;
    int qSize;
    q.push(start);
    visited[start] = true;

    while (true) {
        qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            cur = q.front(); q.pop();
            if (cur == goal) goto end;
            
            // do BFS.
            for (auto child : getChildren(cur)) {
                if (child >= 0 && child <= 100000 && !visited[child]) {
                    visited[child] = true;
                    q.push(child);
                }
            }
        }
        time++;
    }
end:
    cout << time << '\n';
}