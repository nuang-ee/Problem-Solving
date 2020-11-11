// https://www.acmicpc.net/problem/1205
// DJMAX ranking
#include <iostream>
#include <vector>
using namespace std;


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, score, P, rank, tmp;
    cin >> N >> score >> P;

    vector<int> scoreboard;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        scoreboard.push_back(tmp);
    }

    if (N == P && scoreboard[N - 1] >= score) {
        rank = -1;
    }
    else {
        rank = 1;
        for (int i = 0; i < N; i++)
        {
            if (scoreboard[i] > score)
                rank++;
        }
    }

    cout << rank << '\n';

    return 0;
}