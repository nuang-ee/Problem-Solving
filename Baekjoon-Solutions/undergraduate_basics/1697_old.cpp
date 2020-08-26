// https://www.acmicpc.net/problem/1697
// less-elegant solution.
// find minimum time of reaching given position.
#include <iostream>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

bool visited[100001];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int start, goal, cur, gen, time = 0;
    cin >> start >> goal;

    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    visited[start] = true;

    while (true) {
        std::tie(cur, gen) = q.front(); q.pop();
        
        if (cur == goal) {
            time = gen;
            break;
        }

        // do BFS.
        if (cur - 1 >= 0 && !visited[cur - 1]) {
            visited[cur - 1] = true;
            q.push(make_pair(cur - 1, gen + 1));
        }
        if (cur + 1 <= 100000 && !visited[cur + 1]) {
            visited[cur + 1] = true;
            q.push(make_pair(cur + 1, gen + 1));
        }
        if (cur * 2 <= 100000 && !visited[cur * 2]) {
            visited[cur * 2] = true;
            q.push(make_pair(cur * 2, gen + 1));
        }
    }
    cout << time << '\n';
}