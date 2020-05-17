// https://www.acmicpc.net/problem/10039
#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int score, sum = 0;
    for (int i = 0; i < 5; i++) {
        cin >> score;
        if (score < 40) score = 40;
        sum += score;
    }
    cout << sum / 5 << '\n';
}