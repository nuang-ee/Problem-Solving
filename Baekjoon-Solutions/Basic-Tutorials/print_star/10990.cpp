// https://www.acmicpc.net/problem/10953
// adding n pairs of numbers.
#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << string(n-i-1, ' ');
        if (i == 0) {
            cout << '*';
        }
        else {
            cout << '*' << string(2*i - 1, ' ') << '*';
        }
        cout << '\n';
    }
}