// https://www.acmicpc.net/problem/2446
#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << string(i-1, ' ') << string(2*(n-i) + 1, '*') << '\n';
    }

    for (int i = n-1; i >= 1; i--) {
        cout << string(i-1, ' ') << string(2*(n-i) + 1, '*') << '\n';
    }
}