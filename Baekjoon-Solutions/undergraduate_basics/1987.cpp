// https://www.acmicpc.net/problem/1987
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0,-1, 0, 1};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int R, C;
    cin >> R >> C;
    char alphabets[R][C];
    memset(alphabets, 0, sizeof alphabets);

    // get the table.
    string curString;
    for (int i = 0; i < R; i++) {
        cin >> curString;
        for (int j = 0; j < C; j++) {
            alphabets[i][j] = curString[j];
        }
    }

    queue<tuple<int, int, string>> q;
    q.emplace(0, 0, string(1, alphabets[0][0]));
    int qSize;
    int curX, curY, nextX, nextY;
    int maxLength = 0;

    while (!q.empty()) {
        for (int i = 0; i < qSize; i++) {
            std::tie(curX, curY, curString) = q.front(); q.pop();
            if (curString.length() > maxLength) maxLength = curString.length();
            for (int j = 0; j < 4; j++) {
                nextX = curX + dx[j];
                nextY = curY + dy[j];
                if (nextX >= 0 && nextX < R
                && nextY >= 0 && nextY < C
                && curString.find(alphabets[nextX][nextY]) == string::npos) {
                    q.emplace(nextX, nextY, curString + alphabets[nextX][nextY]);
                }
            }
        }
    }
    cout << maxLength << '\n';
}