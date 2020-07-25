// https://www.acmicpc.net/problem/2439
#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        cout << string(n - i, ' ') << string(i, '*') << '\n';
    }
}