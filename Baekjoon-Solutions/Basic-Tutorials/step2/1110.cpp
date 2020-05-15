// https://www.acmicpc.net/problem/1110
#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, cycle_len = 0;
    int a = 0, b = 0;
    cin >> n;
    int next = n;
    while (true) {
        cycle_len++;
        a = next / 10;
        b = next % 10;
        next = b * 10 + (a + b) % 10;
        if (next == n) break;
    }
    cout << cycle_len << '\n';
}